/*
 * Copyright (c) 2004-2005 Sergey Lyubka <valenok@gmail.com>
 * All rights reserved
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Sergey Lyubka wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.
 */

#include "shttpd_defs.h"
#ifdef SHTTPD_GSS
void do_gss(struct conn *c);
#endif

#if !defined(NO_AUTH)
/*
 * Stringify binary data. Output buffer must be twice as big as input,
 * because each byte takes 2 bytes in string representation
 */
static void
bin2str(char *to, const unsigned char *p, size_t len)
{
	const char	*hex = "0123456789abcdef";

	for (;len--; p++) {
		*to++ = hex[p[0] >> 4];
		*to++ = hex[p[0] & 0x0f];
	}
}

/*
 * Return stringified MD5 hash for list of vectors.
 * buf must point to at least 32-bytes long buffer
 */
static void
md5(char *buf, ...)
{
	unsigned char	hash[16];
	const struct vec *v;
	va_list		ap;
	MD5_CTX	ctx;
	int		i;

	MD5Init(&ctx);

	va_start(ap, buf);
	for (i = 0; (v = va_arg(ap, const struct vec *)) != NULL; i++) {
		assert(v->len >= 0);
		if (v->len == 0)
			continue;
		if (i > 0)
			MD5Update(&ctx, (unsigned char *) ":", 1);
		MD5Update(&ctx,(unsigned char *)v->ptr,(unsigned int)v->len);
	}
	va_end(ap);

	MD5Final(hash, &ctx);
	bin2str(buf, hash, sizeof(hash));
}

/*
 * Compare to vectors. Return 1 if they are equal
 */
static int
vcmp(const struct vec *v1, const struct vec *v2)
{
	return (v1->len == v2->len && !memcmp(v1->ptr, v2->ptr, v1->len));
}

struct digest {
	struct vec	user;
	struct vec	uri;
	struct vec	nonce;
	struct vec	cnonce;
	struct vec	resp;
	struct vec	qop;
	struct vec	nc;
};

static const struct auth_keyword {
	size_t		offset;
	struct vec	vec;
} known_auth_keywords[] = {
	{offsetof(struct digest, user),		{"username=",	9}},
	{offsetof(struct digest, cnonce),	{"cnonce=",	7}},
	{offsetof(struct digest, resp),		{"response=",	9}},
	{offsetof(struct digest, uri),		{"uri=",	4}},
	{offsetof(struct digest, qop),		{"qop=",	4}},
	{offsetof(struct digest, nc),		{"nc=",		3}},
	{offsetof(struct digest, nonce),	{"nonce=",	6}},
	{0,					{NULL,		0}}
};

static void
parse_authorization_header(const struct vec *h, struct digest *dig)
{
	const unsigned char	*p, *e, *s;
	struct vec		*v, vec;
	const struct auth_keyword *kw;

	(void) memset(dig, 0, sizeof(*dig));
	p = (unsigned char *) h->ptr + 7;
	e = (unsigned char *) h->ptr + h->len;

	while (p < e) {

		/* Skip spaces */
		while (p < e && (*p == ' ' || *p == ','))
			p++;

		/* Skip to "=" */
		for (s = p; s < e && *s != '='; )
			s++;
		s++;

		/* Is it known keyword ? */
		for (kw = known_auth_keywords; kw->vec.len > 0; kw++)
			if (kw->vec.len <= s - p &&
			    !memcmp(p, kw->vec.ptr, kw->vec.len))
				break;

		if (kw->vec.len == 0)
			v = &vec;		/* Dummy placeholder	*/
		else
			v = (struct vec *) ((char *) dig + kw->offset);

		if (*s == '"') {
			p = ++s;
			while (p < e && *p != '"')
				p++;
		} else {
			p = s;
			while (p < e && *p != ' ' && *p != ',')
				p++;
		}

		v->ptr = (char *) s;
		v->len = p - s;

		if (*p == '"')
			p++;

		DBG(("auth field [%.*s]", v->len, v->ptr));
	}
}

/*
 * Check the user's password, return 1 if OK
 */
static int
check_password(int method, const struct vec *ha1, const struct digest *digest)
{
	char		a2[32], resp[32];
	struct vec	vec_a2;

	/* XXX  Due to a bug in MSIE, we do not compare the URI	 */
	/* Also, we do not check for authentication timeout */
	if (/*strcmp(dig->uri, c->ouri) != 0 || */
	    digest->resp.len != 32 /*||
	    now - strtoul(dig->nonce, NULL, 10) > 3600 */)
		return (0);

	md5(a2, &known_http_methods[method], &digest->uri, NULL);
	vec_a2.ptr = a2;
	vec_a2.len = sizeof(a2);
	md5(resp, ha1, &digest->nonce, &digest->nc,
	    &digest->cnonce, &digest->qop, &vec_a2, NULL);

	return (!memcmp(resp, digest->resp.ptr, 32));
}

#if 0
static FILE *
open_auth_file(struct shttpd_ctx *ctx, const char *path)
{
	char 		name[FILENAME_MAX];
	const char	*p, *e;
	FILE		*fp = NULL;
	int		fd;

	if (ctx->global_passwd_file) {
		/* Use global passwords file */
		snprintf(name, sizeof(name), "%s", ctx->global_passwd_file);
	} else {
		/* Try to find .htpasswd in requested directory */
		for (p = path, e = p + strlen(p) - 1; e > p; e--)
			if (IS_DIRSEP_CHAR(*e))
				break;

		assert(IS_DIRSEP_CHAR(*e));
		(void) snprintf(name, sizeof(name), "%.*s/%s",
		    (int) (e - p), p, HTPASSWD);
	}

	if ((fd = my_open(name, O_RDONLY, 0)) == -1) {
		DBG(("open_auth_file: open(%s)", name));
	} else if ((fp = fdopen(fd, "r")) == NULL) {
		DBG(("open_auth_file: fdopen(%s)", name));
		(void) close(fd);
	}

	return (fp);
}
#endif

/*
 * Parse the line from htpasswd file. Line should be in form of
 * "user:domain:ha1". Fill in the vector values. Return 1 if successful.
 */
static int
parse_htpasswd_line(const char *s, struct vec *user,
				struct vec *domain, struct vec *ha1)
{
	user->len = domain->len = ha1->len = 0;

	for (user->ptr = s; *s != '\0' && *s != ':'; s++, user->len++);
	if (*s++ != ':')
		return (0);

	for (domain->ptr = s; *s != '\0' && *s != ':'; s++, domain->len++);
	if (*s++ != ':')
		return (0);

	for (ha1->ptr = s; *s != '\0' && !isspace(* (unsigned char *) s);
	    s++, ha1->len++);

	DBG(("parse_htpasswd_line: [%.*s] [%.*s] [%.*s]", user->len, user->ptr,
	    domain->len, domain->ptr, ha1->len, ha1->ptr));

	return (user->len > 0 && domain->len > 0 && ha1->len > 0);
}

/*
 * Authorize against the opened passwords file. Return 1 if authorized.
 */
static int
authorize_digest(struct conn *c, FILE *fp)
{
	struct vec 	*auth_vec = &c->ch.auth.v_vec;
	struct vec	*user_vec = &c->ch.user.v_vec;
	struct vec	user, domain, ha1;
	struct digest	digest;
	int		ok = 0;
	char		line[256];

	parse_authorization_header(auth_vec, &digest);
	*user_vec = digest.user;

	while (fgets(line, sizeof(line), fp) != NULL) {

		if (!parse_htpasswd_line(line, &user, &domain, &ha1))
			continue;

		DBG(("[%.*s] [%.*s] [%.*s]", user.len, user.ptr,
		    domain.len, domain.ptr, ha1.len, ha1.ptr));

		if (vcmp(user_vec, &user) && !memcmp(c->ctx->auth_realm,
		    domain.ptr, domain.len)) {
			ok = check_password(c->method, &ha1, &digest);
			break;
		}
	}

	return (ok);
}

int
check_authorization(struct conn *c, const char *path)
{
	FILE			*fp = NULL;
	int			authorized = 0;
	struct vec 	*auth_vec = &c->ch.auth.v_vec;

#ifdef EMBEDDED
	struct llhead	*lp;
	struct uri_auth	*auth;
	int digest = 0, basic = 0;
#ifdef SHTTPD_GSS
    int kerberos = 0;
#endif

	basic_auth_callback cb = NULL;
	char *p, *pp;
	/* Check, is this URL protected by shttpd_protect_url() */
#ifdef SHTTPD_GSS
    /* already authenticated */
	if(c->gss_ctx != GSS_C_NO_CONTEXT)
		return 1;
#endif

	LL_FOREACH(&c->ctx->uri_auths, lp) {
		auth = LL_ENTRY(lp, struct uri_auth, link);
		if (!strncmp(c->uri, auth->uri, strlen(c->uri))) {
#ifdef SHTTPD_GSS
			if (!strncasecmp(auth_vec->ptr, "Kerberos ", 9))
			{
				kerberos = 1;
            }
#endif
			if (auth->type == DIGEST_AUTH &&
			    auth_vec->len > 20 &&
			    !strncasecmp(auth_vec->ptr, "Digest ", 7)) {
				fp = fopen(auth->file_name, "r");
				digest = 1;
			}
			if (auth->type == BASIC_AUTH &&
			    auth_vec->len > 10 &&
			    !strncasecmp(auth_vec->ptr, "Basic ", 6)) {
				cb = (int (*)(char *, char *)) auth->callback.v_func;
				basic = 1;
			}
			break;
		}
	}
	if (lp == &c->ctx->uri_auths) //not a protected uri
		return 1;
#ifdef SHTTPD_GSS
    if(kerberos == 1)
    {
        do_gss(c);
        return 2;
    }
#endif
	if (digest == 1) {
		if (fp != NULL) {
				authorized = authorize_digest(c, fp);
				(void) fclose(fp);
				return (authorized);
		} else
			return (0);
	}

	if (basic == 1) {
		char buf[4096];
		int l;

		p = (char *) auth_vec->ptr + 5;
		while ((*p == ' ') || (*p == '\t')) {
			p++;
		}
		pp = p;
		while ((*p != ' ') && (*p != '\t') && (*p != '\r')
				&& (*p != '\n') && (*p != 0)) {
			p++;
		}

		if (pp == p) {
			return 0;
		}
		*p = 0;

		l = ws_base64_decode(pp, p - pp, buf, 4095);
		if (l <= 0) {
			return 0;
		}

		buf[l] = 0;
		p = buf;
		pp = p;
		p = strchr(p, ':');
		if (p == NULL) {
			return 0;
		}
		*p++ = 0;
		authorized = cb(pp, p);
	} else {
		return 0;
	}

#endif /* EMBEDDED */

	return (authorized);
}

int
is_authorized_for_put(struct conn *c)
{
	FILE	*fp;
	int	ret = 0;

	if ((fp = fopen(c->ctx->put_auth_file, "r")) != NULL) {
		ret = authorize_digest(c, fp);
		(void) fclose(fp);
	}

	return (ret);
}

void
send_authorization_request(struct conn *c)
{
	char	buf[512];
	int n = 0;
	int b = 0, d = 0;

	struct llhead	*lp;
	struct uri_auth	*auth;

	n = snprintf(buf, sizeof(buf), "Unauthorized\r\n");
	LL_FOREACH(&c->ctx->uri_auths, lp) {
		auth = LL_ENTRY(lp, struct uri_auth, link);
		if (auth->type == DIGEST_AUTH && d == 0) {
				if (b ) {
						n += snprintf(buf +n, sizeof(buf) - n, "\r\n");
				}
				n += snprintf(buf +n, sizeof(buf) - n,
	    		"WWW-Authenticate: Digest qop=\"auth\", realm=\"%s\", "
	    		"nonce=\"%lu\"", c->ctx->auth_realm, (unsigned long) current_time);
				d = 1;
		}
		if (auth->type == BASIC_AUTH && b == 0) {
				if (d) {
						n += snprintf(buf +n, sizeof(buf) - n, "\r\n");
				}
				n +=  snprintf(buf +n, sizeof(buf) - n,
	    		"WWW-Authenticate: Basic realm=\"%s\"", c->ctx->auth_realm);
				b = 1;
		}
	}

	send_server_error(c, 401, buf);
}

/*
 * Edit the passwords file.
 */
int
edit_passwords(const char *fname, const char *domain,
		const char *user, const char *pass)
{
	int		ret = EXIT_SUCCESS, found = 0;
	struct vec	u, d, p;
	char		line[512], tmp[FILENAME_MAX], ha1[32];
	FILE		*fp = NULL, *fp2 = NULL;

	(void) snprintf(tmp, sizeof(tmp), "%s.tmp", fname);

	/* Create the file if does not exist */
	if ((fp = fopen(fname, "a+")))
		(void) fclose(fp);

	/* Open the given file and temporary file */
	if ((fp = fopen(fname, "r")) == NULL)
		elog(E_FATAL, 0, "Cannot open %s: %s", fname, strerror(errno));
	else if ((fp2 = fopen(tmp, "w+")) == NULL)
		elog(E_FATAL, 0, "Cannot open %s: %s", tmp, strerror(errno));

	p.ptr = pass;
	p.len = strlen(pass);

	/* Copy the stuff to temporary file */
	while (fgets(line, sizeof(line), fp) != NULL) {
		u.ptr = line;
		if ((d.ptr = strchr(line, ':')) == NULL)
			continue;
		u.len = d.ptr - u.ptr;
		d.ptr++;
		if (strchr(d.ptr, ':') == NULL)
			continue;
		d.len = strchr(d.ptr, ':') - d.ptr;

		if ((int) strlen(user) == u.len &&
		    !memcmp(user, u.ptr, u.len) &&
		    (int) strlen(domain) == d.len &&
		    !memcmp(domain, d.ptr, d.len)) {
			found++;
			md5(ha1, &u, &d, &p, NULL);
			(void) fprintf(fp2, "%s:%s:%.32s\n", user, domain, ha1);
		} else {
			(void) fprintf(fp2, "%s", line);
		}
	}

	/* If new user, just add it */
	if (found == 0) {
		u.ptr = user; u.len = strlen(user);
		d.ptr = domain; d.len = strlen(domain);
		md5(ha1, &u, &d, &p, NULL);
		(void) fprintf(fp2, "%s:%s:%.32s\n", user, domain, ha1);
	}

	/* Close files */
	(void) fclose(fp);
	(void) fclose(fp2);

	/* Put the temp file in place of real file */
	(void) remove(fname);
	(void) rename(tmp, fname);

	return (ret);
}
#endif /* NO_AUTH */
