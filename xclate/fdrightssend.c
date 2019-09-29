/* $Id: fdrights.c,v 3.6 2009/10/16 15:41:17 ksb Exp $
 * $Compile: ${cc-cc} ${cc_debug--O} -DTEST %f -o %F
 * $Compile: ${cc-cc} ${cc_debug--O} -DTEST %f -o %F -lsocket
 * $Test: date > /tmp/test && ./%F
 */
#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "fdrights.h"

#if !defined(USE_STRINGS)
#define USE_STRINGS	(defined(bsd))
#endif

#include "machine.h"
/* Send an array of descriptors through a unix domain socket.		(bj)
 * return -1 on error, 0 on success
 */
int
RightsSendFd(s, piFds, iFdCount, pcText)
int s;
int *piFds;
unsigned iFdCount;
char *pcText;
{
	int error;
	struct msghdr msg;
	struct iovec iov;
#if HAVE_SCM_RIGHTS
	struct cmsghdr *pcmsg;
	int iLen;

	iLen = sizeof(struct cmsghdr) + sizeof(int)*iFdCount;
	if ((struct cmsghdr *)0 == (pcmsg = (struct cmsghdr *) malloc(iLen))) {
		errno = ENOMEM;
		return -1;
	}
	pcmsg->cmsg_len = iLen;
	pcmsg->cmsg_level = SOL_SOCKET;
	pcmsg->cmsg_type = SCM_RIGHTS;
#if USE_STRINGS
	bcopy(piFds, pcmsg+1, sizeof(int)*iFdCount);
#else
	memcpy(pcmsg+1, piFds, sizeof(int)*iFdCount);
#endif
	msg.msg_control = (caddr_t) pcmsg;
	msg.msg_controllen = pcmsg->cmsg_len;
#else
	msg.msg_accrights = (caddr_t) piFds;
	msg.msg_accrightslen = sizeof(int) * iFdCount;
#endif /* HAVE_SCM_RIGHTS */

	/* no name (assume socket is connected */
	if ((char *)0 == pcText) {
		pcText = "ok";
	}
	msg.msg_name = (char *)0;
	msg.msg_namelen = 0;
	/* some sync data data and our file descriptors */
	iov.iov_base = pcText;
	iov.iov_len = strlen(pcText)+1;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	error = sendmsg(s, &msg, 0);

#if HAVE_SCM_RIGHTS
	{
		int e = errno;
		free((char *) pcmsg);
		errno = e;
	}
#endif /* HAVE_SCM_RIGHTS */

	return error;
}

