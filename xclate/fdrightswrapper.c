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
/* We got back not a - (fail) or + (just use the open socket) from	(ksb)
 * a call to divConnect, so we accept access rights and use them (@).
 * This is the client turbo for wrapw, and you must have it to allow
 * all the magics wrapw provides to a wrapper.
 */
int
RightsWrap(int fdWrapw, char *pcCookie, void *pvData, char *pcType)
{
	auto int iLen, fdPriv;

	iLen = sizeof(acRightsRecvBuf);
	if (-1 == RightsRecvFd(fdWrapw, &fdPriv, 1, acRightsRecvBuf, &iLen)) {
		return -1;
	}
	close(fdWrapw);
	return fdPriv;
}

