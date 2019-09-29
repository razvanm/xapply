/*@Header@*/
/* $Id: machine.c,v 1.9 2008/09/02 18:05:36 ksb Exp $
 * implementation of very machine dependent code for ptbw		(ksb)
 * Most of this is gross.
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

#include "machine.h"
extern char *progname;

/*@Explode unsetenv@*/
/* Some older systems have setenv but not unseten (or neither)		(ksb)
 */
#if !defined(unsetenv)
#if (defined(SUN5) && HOSTOS < 21000) || defined(HPUX11) || defined(IBMR2) || defined(AIX)
int
unsetenv(const char *pc)
{
	return setenv(pc, (char *)0, 1);
}
#endif
#endif
