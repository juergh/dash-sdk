/**
 * dashping.c
 */

#ifdef WIN32_PORT
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma warning( disable: 4127)
#else
typedef int SOCKET;
typedef struct timeval TIMEVAL;
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>
#include <string.h>
#include <unistd.h>
#define closesocket close
#define SOCKET_ERROR -1
#endif
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <wsman/dashping.h>
#include <wsman/wsmanidentify.h>

#define uint32	unsigned long
#define uint8	unsigned char

/*------------ Local Definitions -----------------------*/
#define ASF_RMCP_IANA		0x000011be
#define ASF_TYPE_PING		0x80
#define ASF_TYPE_PONG		0x40
#define RMCP_VERSION_1		0x06
#define RMCP_UDP_PORT		0x26f		/* port 623 */
#define RMCP_UDP_SECURE_PORT	0x298	/* port 664 */
#define RMCP_TYPE_MASK		0x80
#define RMCP_TYPE_NORM		0x00
#define RMCP_TYPE_ACK		0x01
#define RMCP_CLASS_MASK		0x1f
#define RMCP_CLASS_ASF		0x06
#define RMCP_CLASS_IPMI		0x07
#define RMCP_CLASS_OEM		0x08



#ifdef WIN32_PORT
#pragma pack (push, 1)
#define __PACKED__	
#else
#define __PACKED__	__attribute__((packed))
#endif 

/**
 * ASF Header
 */
typedef struct
{
	uint32		iana;
	uint8		type;
	uint8		tag;
	uint8		reserved;
	uint8		len;

} __PACKED__ ASFHdr;

/**
 * RMCP header
 */
typedef struct
{
	uint8	version;
	uint8	reserved;
	uint8	seqNum;
	uint8	rmcpClass;

} __PACKED__ RMCPHdr;

/**
 * RMCP Ping 
 */
typedef struct
{
	RMCPHdr	rmcp;
	ASFHdr	asf;

} __PACKED__ RMCPPing;

/**
 * RMCP Pong 
 */
typedef struct
{
	RMCPHdr		rmcp;
	ASFHdr		asf;
	uint32		iana;
	uint32		oem;
	uint8		supEntities;
	uint8		supInteract;
	uint8		reserver [6];

} __PACKED__ RMCPPong;

#ifdef WIN32_PORT
#pragma pack (pop)
#endif

#ifdef WIN32_PORT
int
inet_pton (int af, const char* src, void* dest)
{
	int					destSize;
	int					rc;
	int					ret;
	struct sockaddr_in	sockAddr;

	destSize = sizeof (sockAddr);
	rc = WSAStringToAddressA ((char*)src, 
							 af, 
							 0, 
							 (LPSOCKADDR)&sockAddr,
							 &destSize);
	if (0 != rc)
	{
		if (WSAGetLastError () == WSAEINVAL) { ret = -1; }
		else { ret = 0; }
	}
	else
	{
		memcpy (dest, &sockAddr.sin_addr, sizeof (sockAddr.sin_addr)); 
		ret = 1;
	}

	return ret;
}
#endif

#ifdef ENABLE_RMCP_PING
/**
 * Initialize the LAN interface for RMCP.
 * @param hostname	The address of the host.
 * @param port		The RMCP port 
 * @param pSocket	Pointer to the socket.
 * @return	0 on success.
 *			DLAPI_E_INVALID_ARG					Invalid argument supplied.
 *			DLAPI_E_SOCKET_FAILED				Unable to create socket.
 *			DLAPI_E_INVALID_HOSTNAME			Invalid host name specified.
 *			DLAPI_E_UNABLE_TO_OPEN_RMCP_PORT	Unable to open RMCP port.
 *			DLAPI_E_CONNECTION_FAILED			Connection failed.
 */
static int 
initRMCP (const char* hostname, 
		  int  		  port,
		  SOCKET*	  pSocket)
{
	int					rc;
	struct sockaddr_in	addr;

	if ((NULL == hostname) || (strlen (hostname) == 0)) 
	{
		return DLAPI_E_INVALID_ARG;
	}

	memset (&addr, 0, sizeof (struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port 	= htons ((u_short) port);

	/* resolve the host address */
	rc = inet_pton (AF_INET, hostname, &addr.sin_addr);
	if (rc <= 0) 
	{
		struct hostent* host = gethostbyname ((const char *) hostname);
		if (NULL == host) { return DLAPI_E_INVALID_HOSTNAME; }

		addr.sin_family = host->h_addrtype;
		memcpy (&addr.sin_addr, host->h_addr, host->h_length);
	}
	
	/* Open the port */
	*pSocket = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (*pSocket < 0) { return DLAPI_E_UNABLE_TO_OPEN_RMCP_PORT; }

	/* connect to UDP socket so we get async errors */
	rc = connect (*pSocket, 
				  (struct sockaddr*) &addr,
		     	  sizeof(struct sockaddr_in));
	if (rc < 0) 
	{
		closesocket (*pSocket);
		return DLAPI_E_CONNECT_FAILED; 
	}
	
	return 0;
}

/**
 * Perform an RMCP ping verify the pong response.
 * @param sock		Socket to perform the ping at.
 * @param waitSec	Time to wait for the pong response.
 * @return	0	On success.
 *			-1	On failure.
 */
int
rmcpPing (const char* hostname, 
		  int  		  port,
		  int		  waitSec)
{
	int			rc;
	RMCPPing	ping;
	RMCPPong	pong;
	TIMEVAL		timeout;
	fd_set		fds;
	SOCKET 		sock;
	int			ret = -1;

#ifdef WIN32_PORT
	WORD				sockVer;
	WSADATA				wsaData;

	sockVer = MAKEWORD (2, 2);
	if (0 != WSAStartup (sockVer, &wsaData)) { return DLAPI_E_SOCKET_FAILED; }

	if (LOBYTE (wsaData.wVersion) != 2 ||
		HIBYTE (wsaData.wVersion) != 2) 
	{
		return DLAPI_E_SOCKET_FAILED;
	}
#endif


	/* Initialize the rmcp port */
	rc = initRMCP (hostname, port, &sock);
	if (0 != rc) 
	{ 
		if (g_lapi_verbose_level >= 2){ fprintf (stderr, "Initializing RMCP socket failed\n"); }
		return rc; 
	}
	
	/* Form the ping request */
	memset (&ping, 0, sizeof (ping));
	ping.asf.iana		= htonl (ASF_RMCP_IANA);
	ping.asf.type		= ASF_TYPE_PING;

	ping.rmcp.version	= RMCP_VERSION_1;
	ping.rmcp.rmcpClass = RMCP_CLASS_ASF;
	ping.rmcp.seqNum	= 0xff;

	/* Send the request */
	rc = send (sock, (const char*) &ping, sizeof (ping), 0);
	if (rc != sizeof (ping)) 
	{ 
		goto rmcp_error;
	}

	/* Wait for response */
	timeout.tv_sec 	= waitSec;
	timeout.tv_usec	= 0;

	FD_ZERO (&fds);
	FD_SET (sock, &fds);

	rc = select ((int)sock + 1, &fds, NULL, NULL, &timeout);
	switch (rc)
	{
	case 0: goto rmcp_error;	/* Timeout waiting for response */

	case SOCKET_ERROR:
		/* the first read may return ECONNREFUSED because the rmcp ping
		 * packet--sent to UDP port 623--will be processed by both the
		 * BMC and the OS.
		 *
		 * The problem with this is that the ECONNREFUSED takes
		 * priority over any other received datagram; that means that
		 * the Connection Refused shows up _before_ the response packet,
		 * regardless of the order they were sent out.  (unless the
		 * response is read before the connection refused is returned)
		 */

		rc = select ((int)sock + 1, &fds, NULL, NULL, &timeout);
		if ((SOCKET_ERROR == rc) || (0 == rc)) { goto rmcp_error;}

		rc = recv (sock, (char*) &pong, sizeof (pong), 0);
		break;

	default:
		rc = recv (sock, (char*) &pong, sizeof (pong), 0);
		break;
	}

	if (g_lapi_verbose_level >= 2) {fprintf (stdout, "Received RMCP Response\n"); }

	/* If we did not receive the full pong response then exit */
	if (rc != sizeof (pong)) {goto rmcp_error; }

	/* Make sure that we received a proper pong response */
	if (pong.rmcp.rmcpClass != RMCP_CLASS_ASF) { goto rmcp_error; }

	/* check the byte 10 for the bit 5, if its set then its dash capable target*/
	if ((pong.supInteract & 0x20)) 
	{ 
		if (g_lapi_verbose_level >= 2){  fprintf (stdout, "DASH bit set in RMCP\n"); }
		ret = 0; 
	}
	else
	{
		if (g_lapi_verbose_level >= 2){  fprintf (stdout, "DASH bit not set in RMCP\n"); }
		ret = DLAPI_E_NOT_DASH_MACHINE; 
	}

rmcp_error:
	closesocket (sock); 

	return ret;
}

#endif //ENABLE_RMCP_PING

/*
 * dashPing
 */
int
dashPing (const char*			hostname, 
		  const char*			username,
		  const char*			password,
		  const char*			auth,
		  const char*			scheme,  
		  int 					port,
		  unsigned long			timeout,
		  WSMANIdentifyInfo_T*	wsmaninfo)
{
	int		rc;

	
#ifdef ENABLE_RMCP_PING
	/* Perform an rmcp ping and check for Dash bit */
	rc = rmcpPing (hostname, port, timeout);
	if (rc == 0)
	{
		/* dash bit is set in RMCP response, this confirms target is dash capable */
		/* get the Identifyinfo using identify command*/
		rc = wsmanIdentify (hostname, username,password,auth,scheme, port,timeout, wsmaninfo);
		return 0;
	}
	/* Commented out as per Akash suggestion */ 
	//else if (rc == DLAPI_E_NOT_DASH_MACHINE)
	//{
	//	/* dash bit is not set in RMCP response, this confirms target is not dash capable */
	//	return rc;
	//}
#endif //#ifdef ENABLE_RMCP_PING

	/* else if RMCP ping failed for any other reason, Perform a WSMAN Identify command */
	if (g_lapi_verbose_level >= 2){fprintf (stdout, "No RMCP response, trying wsmand identify\n"); }

	rc = wsmanIdentify (hostname,username,password,auth,scheme, port, timeout, wsmaninfo);
	if (0 == rc) 
	{ 
		return 0;
	}
	else
	{
		return DLAPI_E_NO_WSMAN_RESPONSE; 
	}

}





