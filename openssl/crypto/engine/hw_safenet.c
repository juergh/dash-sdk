/* crypto/engine/hw_safenet.c */

/* written by LB at Safenet B.V. Vught The Netherlands (2004).
 *
 * derived from hw_atalla_c. written by Geoff Thorpe (geoff@geoffthorpe.net) 
 * for the OpenSSL project 2000.
 *
 * Also portions derived from hw_cryptodev.c 
 * Copyright (c) 2002 Bob Beck <beck@openbsd.org>
 * Copyright (c) 2002 Theo de Raadt
 * Copyright (c) 2002 Markus Friedl
 *
 * This version uses a kernel module instead of a shared library.
 */
/* ====================================================================
 * Copyright (c) 1999-2001 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

/* Support for the SafeNet SafeXcel 1840/1841/1842 and 1141/1741 devices.
   First support modular exponentiation and public key functions related to it.
   That's why we used the atalla driver as a baseline.

   Added crypto and digest operations as well, borrowed much from the 
   hw_cryptodev device.

   Now moving to a kernel module instead of a shared library.
*/

#include <stdio.h>
#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <openssl/crypto.h>
#include "cryptlib.h"
#include <fcntl.h>
#include <errno.h>
#if !defined(_WIN32)
#include <sys/ioctl.h>
#endif
#include <openssl/dso.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <openssl/md5.h>

#ifndef OPENSSL_NO_HW
#ifndef OPENSSL_NO_HW_SAFENET

#define FAIL_TO_SW 2

#define SAFENET_LIB_NAME "safenet engine"
#include "hw_safenet_err.c"
#include "safenetssl.h"

static int safenet_destroy(ENGINE *e);
static int safenet_init(ENGINE *e);
static int safenet_finish(ENGINE *e);
static int safenet_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)());

/* BIGNUM stuff */
static int safenet_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
		const BIGNUM *m, BN_CTX *ctx);
static int safenet_ecmod(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                         const BIGNUM *q, const BIGNUM *dp,
                         const BIGNUM *dq, const BIGNUM *u, BN_CTX *ctx);

/* RAND stuff */
static int safenet_get_random_bytes(unsigned char* buf, int num);
static int safenet_random_status(void);

/* Cipher methods */
static int safenet_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
    const unsigned char *in, unsigned int inl);
static int safenet_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
    const unsigned char *iv, int enc);
static int safenet_cleanup(EVP_CIPHER_CTX *ctx);

/* Digest methods */
static int safenet_init_digest(EVP_MD_CTX *ctx);
static int safenet_update_digest(EVP_MD_CTX *ctx,const void *data,unsigned long count);
static int safenet_final_digest(EVP_MD_CTX *ctx,unsigned char *md);
static int safenet_copy_digest(EVP_MD_CTX *to, const EVP_MD_CTX *from);
static int safenet_cleanup_digest(EVP_MD_CTX *ctx);


#ifndef OPENSSL_NO_RSA
/* RSA stuff */
static int safenet_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx);
#endif
/* This function is aliased to mod_exp (with the mont stuff dropped). */
static int safenet_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
		const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);

#ifndef OPENSSL_NO_DSA
/* DSA stuff */
static int safenet_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
		BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
		BN_CTX *ctx, BN_MONT_CTX *in_mont);
static int safenet_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
		const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
		BN_MONT_CTX *m_ctx);
#endif

#ifndef OPENSSL_NO_DH
/* DH stuff */
/* This function is alised to mod_exp (with the DH and mont dropped). */
static int safenet_mod_exp_dh(const DH *dh, BIGNUM *r,
		const BIGNUM *a, const BIGNUM *p,
		const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx);
#endif

/* The definitions for control commands specific to this engine, none */
#define SAFENET_CMD_SO_PATH		ENGINE_CMD_BASE
static const ENGINE_CMD_DEFN safenet_cmd_defns[] = {
	{0, NULL, NULL, 0}
	};

#ifndef OPENSSL_NO_RSA
/* Our internal RSA_METHOD that we provide pointers to */
static RSA_METHOD safenet_rsa =
	{
	"SafeNet RSA method",
	NULL,
	NULL,
	NULL,
	NULL,
	safenet_rsa_mod_exp,
	safenet_mod_exp_mont,
	NULL,
	NULL,
	0,
	NULL,
	NULL,
	NULL
	};
#endif

#ifndef OPENSSL_NO_DSA
/* Our internal DSA_METHOD that we provide pointers to */
static DSA_METHOD safenet_dsa =
	{
	"SafeNet DSA method",
	NULL, /* dsa_do_sign */
	NULL, /* dsa_sign_setup */
	NULL, /* dsa_do_verify */
	safenet_dsa_mod_exp, /* dsa_mod_exp */
	safenet_mod_exp_dsa, /* bn_mod_exp */
	NULL, /* init */
	NULL, /* finish */
	0, /* flags */
	NULL /* app_data */
	};
#endif

#ifndef OPENSSL_NO_DH
/* Our internal DH_METHOD that we provide pointers to */
static DH_METHOD safenet_dh =
	{
	"SafeNet DH method",
	NULL,
	NULL,
	safenet_mod_exp_dh,
	NULL,
	NULL,
	0,
	NULL
	};
#endif

static RAND_METHOD safenet_rand =
	{
	/* "SafeNet RAND method", */
	NULL, /* seed */
	safenet_get_random_bytes, /* get random bytes from the card */
	NULL, /* cleanup */
	NULL, /* add */
	safenet_get_random_bytes, /* pseudo rand */
	safenet_random_status, /* status */
	};

static int safenet_engine_ciphers(ENGINE *e, const EVP_CIPHER **cipher,
    const int **nids, int nid);
static int safenet_engine_digests(ENGINE *e, const EVP_MD **digest,
    const int **nids, int nid);


/* Constants used when creating the ENGINE */
static const char *engine_safenet_id = "safenet";
static const char *engine_safenet_name = "SafeNet SafeXcel 1141/1741/184x support";

/* This internal function is used by ENGINE_safenet() and possibly by the
 * "dynamic" ENGINE support too */
static int bind_helper(ENGINE *e)
	{
#ifndef OPENSSL_NO_RSA
	const RSA_METHOD *meth1;
#endif
#ifndef OPENSSL_NO_DSA
	const DSA_METHOD *meth2;
#endif
#ifndef OPENSSL_NO_DH
	const DH_METHOD *meth3;
#endif
	if(!ENGINE_set_id(e, engine_safenet_id) ||
			!ENGINE_set_name(e, engine_safenet_name) ||
#ifndef OPENSSL_NO_RSA
			!ENGINE_set_RSA(e, &safenet_rsa) ||
#endif
#ifndef OPENSSL_NO_DSA
			!ENGINE_set_DSA(e, &safenet_dsa) ||
#endif
#ifndef OPENSSL_NO_DH
			!ENGINE_set_DH(e, &safenet_dh) ||
#endif
	                !ENGINE_set_RAND(e, &safenet_rand) ||
			!ENGINE_set_destroy_function(e, safenet_destroy) ||
			!ENGINE_set_init_function(e, safenet_init) ||
			!ENGINE_set_finish_function(e, safenet_finish) ||
			!ENGINE_set_ctrl_function(e, safenet_ctrl) ||
	                !ENGINE_set_cmd_defns(e, safenet_cmd_defns) ||
	                !ENGINE_set_ciphers(e, safenet_engine_ciphers) ||
	                !ENGINE_set_digests(e, safenet_engine_digests))
		return 0;

#ifndef OPENSSL_NO_RSA
	/* We know that the "PKCS1_SSLeay()" functions hook properly
	 * to the safenet-specific mod_exp and mod_exp_crt so we use
	 * those functions. NB: We don't use ENGINE_openssl() or
	 * anything "more generic" because something like the RSAref
	 * code may not hook properly, and if you own one of these
	 * cards then you have the right to do RSA operations on it
	 * anyway! */ 
	meth1 = RSA_PKCS1_SSLeay();
	safenet_rsa.rsa_pub_enc = meth1->rsa_pub_enc;
	safenet_rsa.rsa_pub_dec = meth1->rsa_pub_dec;
	safenet_rsa.rsa_priv_enc = meth1->rsa_priv_enc;
	safenet_rsa.rsa_priv_dec = meth1->rsa_priv_dec;
#endif

#ifndef OPENSSL_NO_DSA
	/* Use the DSA_OpenSSL() method and just hook the mod_exp-ish
	 * bits. */
	meth2 = DSA_OpenSSL();
	safenet_dsa.dsa_do_sign = meth2->dsa_do_sign;
	safenet_dsa.dsa_sign_setup = meth2->dsa_sign_setup;
	safenet_dsa.dsa_do_verify = meth2->dsa_do_verify;
#endif

#ifndef OPENSSL_NO_DH
	/* Much the same for Diffie-Hellman */
	meth3 = DH_OpenSSL();
	safenet_dh.generate_key = meth3->generate_key;
	safenet_dh.compute_key = meth3->compute_key;
#endif

	/* Ensure the safenet error handling is set up */
	ERR_load_SAFENET_strings();
	
	return 1;
	}

#ifndef ENGINE_DYNAMIC_SUPPORT
static ENGINE *engine_safenet(void)
	{
	ENGINE *ret = ENGINE_new();
	if(!ret)
		return NULL;
	if(!bind_helper(ret))
		{
		ENGINE_free(ret);
		return NULL;
		}
	return ret;
	}

void ENGINE_load_safenet(void)
	{
	/* Copied from eng_[openssl|dyn].c */
	ENGINE *toadd = engine_safenet();
	if(!toadd) return;
	ENGINE_add(toadd);
	ENGINE_free(toadd);
	ERR_clear_error();
	}
#endif

int safenet_fd = -1;

/* Destructor (complements the "ENGINE_safenet()" constructor) */
static int safenet_destroy(ENGINE *e)
	{
	  /*close(safenet_fd);
	  safenet_fd=-1;*/
	/* Unload the safenet error strings so any error state including our
	 * functs or reasons won't lead to a segfault (they simply get displayed
	 * without corresponding string data because none will be found). */
	ERR_unload_SAFENET_strings();
	return 1;
	}

/* (de)initialisation functions. */
static int safenet_init(ENGINE *e)
	{

	if(safenet_fd != -1)
		{
		SAFENETerr(SAFENET_F_SAFENET_INIT,SAFENET_R_ALREADY_LOADED);
		goto err;
		}

	safenet_fd = open("/dev/safenetssl",O_RDWR);
	if(safenet_fd  < 0)
		{
		SAFENETerr(SAFENET_F_SAFENET_INIT,SAFENET_R_NOT_LOADED);
		goto err;

		}
	return 1;

err:
	if(safenet_fd != -1)
		close(safenet_fd);
	safenet_fd=-1;
	return 0;
	}

static int safenet_finish(ENGINE *e)
	{
	  
	if(safenet_fd == -1)
		{
		SAFENETerr(SAFENET_F_SAFENET_FINISH,SAFENET_R_NOT_LOADED);
		return 0;
		}
	if(close(safenet_fd) < 0)
		{
		SAFENETerr(SAFENET_F_SAFENET_FINISH,SAFENET_R_UNIT_FAILURE);
		return 0;
		}
	safenet_fd = -1;
	return 1;
	}

static int safenet_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)())
	{
	SAFENETerr(SAFENET_F_SAFENET_CTRL,SAFENET_R_CTRL_COMMAND_NOT_IMPLEMENTED);
	return 0;
	}


static int safenet_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
			const BIGNUM *m, BN_CTX *ctx)
	{
	int to_return, rc;	
	expmod_param_blk pb;
	to_return = 0; /* expect failure */
        
	if(safenet_fd == -1)
		{
		SAFENETerr(SAFENET_F_SAFENET_MOD_EXP,SAFENET_R_NOT_LOADED);
		goto err;
		}
	/* Prepare the params */
	bn_wexpand(r, m->top+2);
	r->top=m->top+2;
	/* Perform the operation */
	pb.res = (unsigned int *)r->d;
	pb.ressize = m->top;
        pb.a = (unsigned int *)a->d;
        pb.asize = a->top;
	pb.p = (unsigned int *)p->d;
	pb.psize = p->top;
	pb.m = (unsigned int *)m->d;
	pb.msize = m->top;
	do {
	  rc = ioctl( safenet_fd, SAFENET_IOCEXPMOD, &pb);
	} while(rc<0 && errno == EINTR);
	if(rc == FAIL_TO_SW ) { /* fall back to software if out of range for hw*/
           BN_mod_exp(r,a,p,m,ctx); 
           rc=0;
	}
	if( rc!=0 ) {
		SAFENETerr(SAFENET_F_SAFENET_MOD_EXP,SAFENET_R_REQUEST_FAILED);
		goto err;
	}	
	/* Convert the response */
	bn_fix_top(r);
	to_return = 1;
err:
	return to_return;
	}


static int safenet_ecmod(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
                         const BIGNUM *q, const BIGNUM *dp,
                         const BIGNUM *dq, const BIGNUM *u, BN_CTX *ctx)
{
	int to_return;
	expcrtmod_param_blk pb;
	to_return = 0; /* expect failure */
	if(safenet_fd == -1)
		{
		SAFENETerr(SAFENET_F_SAFENET_MOD_EXP,SAFENET_R_NOT_LOADED);
		goto err;
		}
	/* Prepare the params */
	bn_wexpand(r, p->top+q->top+2);
	r->top=p->top+q->top+2;
	pb.res = (unsigned int *)r->d;
	pb.ressize = p->top + q->top;
	pb.a = (unsigned int *)a->d;
	pb.asize = a->top;
	pb.p = (unsigned int *)p->d;
	pb.psize = p->top;
	pb.q = (unsigned int *)q->d;
	pb.qsize = q->top;
	pb.dp = (unsigned int *)dp->d;
	pb.dpsize = dp->top;
	pb.dq = (unsigned int *)dq->d;
	pb.dqsize = dq->top;
	pb.u = (unsigned int *)u->d;
	pb.usize = u->top;
	do {
	  to_return = ioctl(safenet_fd, SAFENET_IOCEXPCRTMOD, &pb);
	} while(to_return<0 && errno==EINTR);
	if(to_return==FAIL_TO_SW) goto err;
	else if (to_return!=0) {
	  to_return=0;	
	  goto err;
	}
	bn_fix_top(r);
	to_return = 1;	
err:
	return to_return;		
} 



#ifndef OPENSSL_NO_RSA
static int safenet_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
	{
	int to_return = 0;

	if(safenet_fd == -1)
		{
		SAFENETerr(SAFENET_F_SAFENET_RSA_MOD_EXP,SAFENET_R_NOT_LOADED);
		goto err;
		}
	if((ctx = BN_CTX_new()) == NULL)
		goto err;
	if(!rsa->d || !rsa->n)
		{
		SAFENETerr(SAFENET_F_SAFENET_RSA_MOD_EXP,SAFENET_R_MISSING_KEY_COMPONENTS);
		goto err;
		}
	/* The following code was derived from the hw_aep driver */
	/*See if we have all the necessary bits for a crt*/
	if (rsa->q && rsa->dmp1 && rsa->dmq1 && rsa->iqmp)
		{
		to_return =  safenet_ecmod(r0,I,rsa->p,rsa->q, rsa->dmp1,rsa->dmq1,rsa->iqmp,ctx);
		if (to_return == FAIL_TO_SW) {
			const RSA_METHOD *meth = RSA_PKCS1_SSLeay();
			to_return = (*meth->rsa_mod_exp)(r0, I, rsa, ctx);
		}
	} else { /* No CRT possible */
	     to_return = safenet_mod_exp(r0, I, rsa->d, rsa->n, ctx);
	}
err:
	if(ctx)
		BN_CTX_free(ctx);
	return to_return;
	}
#endif

#ifndef OPENSSL_NO_DSA
/* This code was liberated and adapted from the commented-out code in
 * dsa_ossl.c. */
static int safenet_dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1,
		BIGNUM *p1, BIGNUM *a2, BIGNUM *p2, BIGNUM *m,
		BN_CTX *ctx, BN_MONT_CTX *in_mont)
	{
	BIGNUM t;
	int to_return = 0;
 
	BN_init(&t);
	/* let rr = a1 ^ p1 mod m */
	if (!safenet_mod_exp(rr,a1,p1,m,ctx)) goto end;
	/* let t = a2 ^ p2 mod m */
	if (!safenet_mod_exp(&t,a2,p2,m,ctx)) goto end;
	/* let rr = rr * t mod m */
	if (!BN_mod_mul(rr,rr,&t,m,ctx)) goto end;
	to_return = 1;
end:
	BN_free(&t);
	return to_return;
	}

static int safenet_mod_exp_dsa(DSA *dsa, BIGNUM *r, BIGNUM *a,
		const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
		BN_MONT_CTX *m_ctx)
	{
	return safenet_mod_exp(r, a, p, m, ctx);
	}
#endif

/* This function is aliased to mod_exp (with the mont stuff dropped). */
static int safenet_mod_exp_mont(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
		const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
	{
	return safenet_mod_exp(r, a, p, m, ctx);
	}

#ifndef OPENSSL_NO_DH
/* This function is aliased to mod_exp (with the dh and mont dropped). */
static int safenet_mod_exp_dh(const DH *dh, BIGNUM *r,
		const BIGNUM *a, const BIGNUM *p,
		const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
	{
	return safenet_mod_exp(r, a, p, m, ctx);
	}
#endif

static int safenet_get_random_bytes(unsigned char* buf, int num)
{
  int rc;
  crypto_param_blk pb;
  pb.output = buf;
  pb.size = num;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCRANDOM, &pb);
  } while(rc<0 && errno==EINTR);
  return (rc>=0);
}

static int safenet_random_status(void)
{
  return 1;
}

#define SAFENET_CRYPTO_STATE_SIZE sizeof(int)
#define SAFENET_HASH_STATE_SIZE sizeof(int)

/* DES CBC EVP */
const EVP_CIPHER safenet_des_cbc = {
	NID_des_cbc,
	8, 8, 8,
	EVP_CIPH_CBC_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

/* 3DES CBC EVP */
const EVP_CIPHER safenet_3des_cbc = {
	NID_des_ede3_cbc,
	8, 24, 8,
	EVP_CIPH_CBC_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

/* AES CBC EVP */
const EVP_CIPHER safenet_aes128_cbc = {
	NID_aes_128_cbc,
	16, 16, 16,
	EVP_CIPH_CBC_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

const EVP_CIPHER safenet_aes192_cbc = {
	NID_aes_192_cbc,
	16, 24, 16,
	EVP_CIPH_CBC_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

const EVP_CIPHER safenet_aes256_cbc = {
	NID_aes_256_cbc,
	16, 32, 16,
	EVP_CIPH_CBC_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

/* DES ECB EVP */
const EVP_CIPHER safenet_des_ecb = {
	NID_des_ecb,
	8, 8, 8,
	EVP_CIPH_ECB_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

/* 3DES ECB EVP */
const EVP_CIPHER safenet_3des_ecb = {
	NID_des_ede3_ecb,
	8, 24, 8,
	EVP_CIPH_ECB_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};


/* AES ECB EVP */
const EVP_CIPHER safenet_aes128_ecb = {
	NID_aes_128_ecb,
	16, 16, 16,
	EVP_CIPH_ECB_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

const EVP_CIPHER safenet_aes192_ecb = {
	NID_aes_192_ecb,
	16, 24, 16,
	EVP_CIPH_ECB_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};

const EVP_CIPHER safenet_aes256_ecb = {
	NID_aes_256_ecb,
	16, 32, 16,
	EVP_CIPH_ECB_MODE,
	safenet_init_key,
	safenet_cipher,
	safenet_cleanup,
	SAFENET_CRYPTO_STATE_SIZE,
	EVP_CIPHER_set_asn1_iv,
	EVP_CIPHER_get_asn1_iv,
	NULL
};


const EVP_MD safenet_md5 = {
	NID_md5,
	NID_md5WithRSAEncryption,
	MD5_DIGEST_LENGTH,
        0,
	safenet_init_digest,
	safenet_update_digest,
	safenet_final_digest,
	safenet_copy_digest,
	safenet_cleanup_digest,
	EVP_PKEY_RSA_method,
	MD5_CBLOCK,
	SAFENET_HASH_STATE_SIZE,  
};

const EVP_MD safenet_sha1 = {
	NID_sha1,
	NID_sha1WithRSAEncryption,
	SHA_DIGEST_LENGTH,
	0,
	safenet_init_digest,
	safenet_update_digest,
	safenet_final_digest,
	safenet_copy_digest,
	safenet_cleanup_digest,
	EVP_PKEY_RSA_method,
	SHA_CBLOCK,
	SAFENET_HASH_STATE_SIZE,  
};

static int safenet_engine_ciphers(ENGINE *e, const EVP_CIPHER **cipher,
    const int **nids, int nid)
{
  static int cnids[]={NID_des_cbc,NID_des_ede3_cbc,NID_aes_128_cbc,
		      NID_aes_192_cbc, NID_aes_256_cbc,
		      NID_des_ecb,NID_des_ede3_ecb,NID_aes_128_ecb,
		      NID_aes_192_ecb, NID_aes_256_ecb};
    if (!cipher) {
      *nids=cnids;
      return (sizeof(cnids)/sizeof(int));
    }
	switch (nid) {
	case NID_des_ede3_cbc:
		*cipher = &safenet_3des_cbc;
		break;
	case NID_des_cbc:
		*cipher = &safenet_des_cbc;
		break;
	case NID_aes_128_cbc:
		*cipher = &safenet_aes128_cbc;
		break;
	case NID_aes_192_cbc:
		*cipher = &safenet_aes192_cbc;
		break;
	case NID_aes_256_cbc:
		*cipher = &safenet_aes256_cbc;
		break;
	case NID_des_ede3_ecb:
		*cipher = &safenet_3des_ecb;
		break;
	case NID_des_ecb:
		*cipher = &safenet_des_ecb;
		break;
	case NID_aes_128_ecb:
		*cipher = &safenet_aes128_ecb;
		break;
	case NID_aes_192_ecb:
		*cipher = &safenet_aes192_ecb;
		break;
	case NID_aes_256_ecb:
		*cipher = &safenet_aes256_ecb;
		break;
	default:
		*cipher = NULL;
		break;
	}
	return (*cipher != NULL);
}

static int safenet_engine_digests(ENGINE *e, const EVP_MD **digest,
    const int **nids, int nid)
{
  static int cnids[2]={NID_md5, NID_sha1};
  if(!digest) {
    *nids=cnids;
    return (2);
  }
  switch(nid) {
  case NID_md5:
    *digest = &safenet_md5;
    break;
  case NID_sha1:
    *digest = &safenet_sha1;
    break;
  default:
    *digest = NULL;
    break;
  }
  return (*digest != NULL);
}

static int safenet_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
    const unsigned char *in, unsigned int inl)
{
  crypto_param_blk pb;
  int rc;
  pb.ctx = *((int*)ctx->cipher_data);
  pb.input = (unsigned char *)in;
  pb.output = out;
  pb.size = inl;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCCIPHER, &pb);
  } while(rc<0 && errno==EINTR) ;
  return (rc >= 0);
}

static int safenet_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
    const unsigned char *iv, int enc)
{
  initkey_param_blk pb;
  int algo,keylen,fmode,rc;
  if(ctx->cipher->nid == NID_des_cbc || ctx->cipher->nid == NID_des_ecb ) {
    algo = SA_CRYPTO_DES;
  } else if(ctx->cipher->nid == NID_des_ede3_cbc ||
	    ctx->cipher->nid == NID_des_ede3_ecb ) {
    algo = SA_CRYPTO_TDES;
  } else if(ctx->cipher->nid == NID_aes_128_cbc ||
	    ctx->cipher->nid == NID_aes_192_cbc ||
	    ctx->cipher->nid == NID_aes_256_cbc ||
	    ctx->cipher->nid == NID_aes_128_ecb ||
	    ctx->cipher->nid == NID_aes_192_ecb ||
	    ctx->cipher->nid == NID_aes_256_ecb ) {
    algo = SA_CRYPTO_AES;
  } else {
    return 0;
  }
  if( ctx->cipher->flags & EVP_CIPH_CBC_MODE) fmode=SA_CRYPTO_MODE_CBC;
  else fmode = SA_CRYPTO_MODE_ECB;
  keylen = ctx->cipher->key_len;
  pb.algo = algo;
  pb.fmode = fmode;
  pb.keylen = keylen;
  pb.key = (unsigned char *)key;
  pb.iv = (unsigned char *)iv;
  pb.dir = enc;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCINITKEY, &pb);
  } while( rc<0 && errno==EINTR);
  *((int*)ctx->cipher_data) = rc;
  return (rc >= 0);
}

static int safenet_cleanup(EVP_CIPHER_CTX *ctx)
{
  int rc;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCCLEANKEY, *((int*)ctx->cipher_data));
  } while( rc<0 && errno==EINTR);
  return (rc >= 0);
}

/* Digest methods */
static int safenet_init_digest(EVP_MD_CTX *ctx)
{
  int algo,rc;
  if(ctx->digest->type == NID_md5) {
    algo = SA_HASH_MD5;
  } else if(ctx->digest->type == NID_sha1) {
    algo = SA_HASH_SHA1;
  } else {
    return 0;
  }
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCINITDIGEST, algo);
  } while (rc<0 && errno == EINTR);
  *((int*)ctx->md_data) = rc;
  return (rc >= 0);
}

static int safenet_update_digest(EVP_MD_CTX *ctx,const void *data,unsigned long count)
{
  crypto_param_blk pb;
  int rc;
  pb.ctx = *((int*)ctx->md_data);
  pb.input = (unsigned char *)data;
  pb.size = count;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCUPDATEDIGEST, &pb);
  } while(rc<0 && errno==EINTR) ;
  return (rc >= 0);
}

static int safenet_final_digest(EVP_MD_CTX *ctx,unsigned char *md)
{
  crypto_param_blk pb;
  int rc;
  pb.ctx = *((int*)ctx->md_data);
  pb.output = md;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCFINALDIGEST, &pb);
  } while(rc<0 && errno==EINTR) ;
  return (rc >= 0);
}

static int safenet_copy_digest(EVP_MD_CTX *to, const EVP_MD_CTX *from)
{
  int rc;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCCOPYDIGEST, *((int*)from->md_data) );
  } while( rc<0 && errno==EINTR);
  *((int*)to->md_data) = rc;
  return (rc >= 0);
}

static int safenet_cleanup_digest(EVP_MD_CTX *ctx)
{
  int rc;
  do {
    rc = ioctl(safenet_fd, SAFENET_IOCCLEANDIGEST, *((int*)ctx->md_data));
  } while( rc<0 && errno==EINTR);
  return (rc >= 0);
}



/* This stuff is needed if this ENGINE is being compiled into a self-contained
 * shared-library. */
#ifdef ENGINE_DYNAMIC_SUPPORT
static int bind_fn(ENGINE *e, const char *id)
	{
	if(id && (strcmp(id, engine_safenet_id) != 0))
		return 0;
	if(!bind_helper(e))
		return 0;
	return 1;
	}
IMPLEMENT_DYNAMIC_CHECK_FN()
IMPLEMENT_DYNAMIC_BIND_FN(bind_fn)
#endif /* ENGINE_DYNAMIC_SUPPORT */

#endif /* !OPENSSL_NO_HW_SAFENET */
#endif /* !OPENSSL_NO_HW */
