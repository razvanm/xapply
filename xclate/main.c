/* mkcmd generated user interface
 * built by mkcmd version 8.17 Rel
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <time.h>
#include <assert.h>
#include <sysexits.h>
#include "machine.h"
#include "fdrights.h"
#include "mkdtemp.h"
#include <errno.h>
#include <sys/param.h>
#include <pwd.h>
/* from getopt.m */
/* from getopt_key.m */
/* from xclate.m */
#line 44 "xclate.m"
static char rcsid[] =
	"$Id: xclate.m,v 2.64 2010/01/08 14:29:12 ksb Exp $";
static const char acProto[] =
	"0.8";		/* the protocol version chat		*/
#if HAVE_SYS_PIPE_H && ! defined(FREEBSD)
#include <sys/pipe.h>
#endif

#if !defined(PIPE_SIZE)
#define PIPE_SIZE	16384
#endif

#if !defined(MAX_XID_LEN)
#define MAX_XID_LEN	64
#endif

#if !defined(MAX_PID_LEN)
#define MAX_PID_LEN	32
#endif

/* Broken pump of the master stdin -> widows we used to do, -I obviated this
 * For everyones safety never enable this (it breaks sshw and sapply). -- ksb
 */
static char
	acMySpace[] = "xclXXXXXX",
	acDevNull[] = "/dev/null",
	acEnvCmd[] = "XCLATE";
static FILE
	*fpVerbose;		/* -v output hook, std_control.m */
/* from std_help.m */
/* from std_version.m */
/* from util_divstack.m */
/* from util_divconnect.m */
#line 10 "util_divconnect.m"
void *(*divNextLevel)(void *pvThisLevel) = (void *(*)(void *))0;
int (*divConnHook)(int fd, void *pvLevel) = (int (*)(int, void *))0;
/* from util_errno.m */
#line 8 "util_errno.m"
extern int errno;
/* from util_sigret.m */
/* from util_ppm.m */
#line 11 "util_ppm.m"
#if !defined(UTIL_PPM_ONCE)
#define UTIL_PPM_ONCE	1
typedef struct PPMnode {
	void *pvbase;		/* present start			*/
	unsigned int uimax;	/* max we can hold now			*/
	unsigned int uiwide;	/* how wide is one element?		*/
	unsigned int uiblob;	/* how many elements do we grow by?	*/
} PPM_BUF;

extern PPM_BUF *util_ppm_init(PPM_BUF *, unsigned int, unsigned int);
extern void *util_ppm_size(PPM_BUF *, unsigned int);
extern void util_ppm_free(PPM_BUF *);
extern int util_ppm_print(PPM_BUF *, FILE *);
#endif
/* from util_tmp.m */
/* from util_pipefit.m */
/* from util_fsearch.m */
/* from hosttype.m */
/* from std_control.m */
/* from util_home.m */
/* from bytes.m */
/* from util_mult.m */
#line 22 "util_mult.m"
#if !defined(PM__TOKEN)
#define PM__TOKEN

typedef struct PMnode {		/* postfix multiplier		*/
	char ckey;		/* postfix letter		*/
	char *pctext;		/* for the help message		*/
	unsigned long umult;	/* mean times this		*/
	char *pcplural;		/* nil or plural for pctext	*/
} POST_MULT;
#endif	/* protection from multiple #includes */
#line 1 "getopt.mi"
/* $Id: getopt.mi,v 8.10 2000/05/31 13:16:24 ksb Exp $
 */

#if 1 || 0 || 0
/* IBMR2 (AIX in the real world) defines
 * optind and optarg in <stdlib.h> and confuses the heck out
 * of the C compiler.  So we use those externs.  I guess we will
 * have to stop using the old names. -- ksb
 */
static int
	u_optInd = 1;		/* index into parent argv vector	*/
static char
	*u_optarg;		/* argument associated with option	*/

#endif /* only if we use them */
#if 1
static int
	u_optopt;			/* character checked for validity	*/
#endif
#line 1 "util_divstack.mi"
/* $Id: util_divstack.mi,v 1.6 2008/08/25 14:18:37 ksb Exp $
 */
extern void divVersion(FILE *fpOut);
extern unsigned divInit(const char *pcName, const char *pcSpec);
extern char *divCurrent(char *pcForce), *divSelect(), *divIndex(unsigned uLevel);
extern int divNumber(unsigned *puFound), divSearch(int (*pfi)(const char *pcName, const char *pcDirect, int fActive, void *pvData), void *pvData), divResults(const char *pcValue), divPush(const char *pcNew), divDetach(const char *pcNew, const char *pcTag);
#line 1 "util_divconnect.mi"
/* $Id: util_divconnect.mi,v 1.1 2008/08/25 14:16:40 ksb Exp $
 */
extern int divConnect(const char *pcSocket, int (*pfiIndir)(int fd, char *pcCookie, void *pvData, char *pcType), void *pvLevel);
#line 1 "util_sigret.mi"
/* $Id: util_sigret.mi,v 8.24 2001/10/17 22:24:26 ksb Exp $
 */
#if !defined(SIGRET_T)
#if defined(FREEBSD) || defined(SUN5) || defined(HPUX9) || defined(HPUX10)
#define SIGRET_T	void
#else
#define SIGRET_T	int
#endif
#endif

#if !defined(HAVE_STICKY_SIGNALS)
/* It looks like some Solaris 2.X revs have sticky signals, but I
 * can't find a pattern.
 */
#if defined(SUN5)
#define HAVE_STICKY_SIGNALS	0
#else
#define HAVE_STICKY_SIGNALS	(!(defined(HPUX)))
#endif
#endif
#line 1 "util_pipefit.mi"
/* $Id: util_pipefit.mi,v 1.1 2007/09/16 20:34:59 ksb Exp $
 */
static pid_t PipeFit(const char *pcExec, char **ppcArgv, char **ppcEnv, int iFd);
#line 1 "util_fsearch.mi"
/* $Id: util_fsearch.mi,v 8.10 1998/09/16 13:37:42 ksb Exp $
 */
extern char *util_fsearch();
#line 1 "util_home.mi"
/* $Id: util_home.mi,v 8.3 2004/12/15 22:20:18 ksb Exp $
 */
extern char *util_home();
#line 1 "bytes.mi"
/* $Id: bytes.mi,v 8.20 1998/11/29 01:17:36 ksb Exp $
 * post mult byte (of course the k should be Ki, etc.)			(ksb)
 */
#define PMB_BYTE	{ '\000', "byte",	       1UL, (char *)0 }
#define PMB_WORD	{    'w', "word",	       2UL, (char *)0 }
#define PMB_LONG	{    'l', "long word",	       4UL, (char *)0 }
#define PMB_BLOCK	{    'b', "block",	     512UL, (char *)0 }
#define PMB_KB		{    'k', "kilobyte",	    1024UL, (char *)0 }
#define PMB_MB		{    'm', "megabyte",    1048576UL, (char *)0 }
#define PMB_GB		{    'g', "gigabyte", 1073741824UL, (char *)0 }

static POST_MULT aPMBytes[] = {
	PMB_BYTE, PMB_WORD, PMB_LONG, PMB_BLOCK, PMB_KB, PMB_MB, PMB_GB
};
#line 1 "util_mult.mi"
/* forward for scaled conversion --ksb
 * $Id: util_mult.mi,v 8.3 2004/12/15 22:20:18 ksb Exp $
 */
extern unsigned long pm_cvt(/* char *pcDo, POST_MULT *pPM, int iEntries */);
static unsigned long pm_expr();
char
	*progname = "$Id$",
	*au_terse[] = {
		" [-DEInqQsvwY] [-depth] [-H hr] [-L cap] [-T title] [-u unix] [xid] [client]",
		" -h",
		" -V",
		" -m [-AdnqQrsv] [-depth] [-H hr] [-i input] [-L cap] [-N notify] [-O output] [-T title] [-u unix] [-W widow] [utility]",
		(char *)0
	},
	*u_help[] = {
		"-depth   select an outer diversion, depth steps away",
		"A        add startup banner to nofity stream, for sshw",
		"d        do not publish this level in the linked environment",
		"D        use the current working directory of the selected instance",
		"E        use the stderr of the selected instance",
		"h        print this help message",
		"H hr     add a horizontal rule to end each output stream",
		"i input  replace the original stdin for the utility process",
		"I        use the stdin of the selected instance",
		"L cap    cap on memory based output buffer",
		"m        manage output for descendant processes",
		"utility  a command to produce output",
		"n        do not execute commands, trace only",
		"N notify message this file, process, or fd for each finished section (with each xid)",
		"O output redirect collated output to this file, process, or fd",
		"q        allow quicker processing of empty clients",
		"Q        tell the enclosing persistent instance to finish",
		"r        report exit codes in the notify stream (as code,xid)",
		"s        squeeze out header+footer from tasks with no other output",
		"T title  a title for each stream, replace %x with xid, %s with sequence",
		"u unix   specify a forced unix domain end-point name",
		"v        be verbose",
		"V        show version information",
		"w        redirect our output to the widow section, not the collated section",
		"W widow  redirect widowed output to this file, process, or fd",
		"Y        change the controlling terminal to the new stdin, stdout, or stderr",
		"xid      the identification for this stream, usually xapply's %1",
		(char *)0
	},
	*pcLimit = (char *)0,
	*pcTmpdir = (char *)0;
int
	iDevDepth = 0,
	fReplaceOrigIn = 0,
	fGaveL = 0,
	cEsc = '%',
	fStartup = 0,
	fPublish = 1,
	fAskPWD = 0,
	fAskStderr = 0;
char
	*pcHorizRule = (char *)0,
	*pcForcedIn = (char *)0;
int
	fAskStdin = 0;
long
	uiLimit = 0L;
int
	fMaster = 0,
	fExec = 1;
char
	*pcNotify = (char *)0,
	*pcPriv = (char *)0;
int
	wElected = 0,
	fAllowQuick = 0,
	fTerminate = 0,
	fExit2 = 0,
	fSqueeze = 0;
char
	*pcInterp = (char *)0,
	*pcTitle = (char *)0,
	*pcMaster = (char *)0;
int
	fVerbose = 0,
	fWeeping = 0;
char
	*pcWidows = (char *)0;
int
	fNewTTY = 0,
	Z_opt = 0;

#ifndef u_terse
#define u_terse	(au_terse[0])
#endif
static void
u_nameof(pcBuf, ch)
char *pcBuf, ch;
{
	if ('#' == ch) {
		(void)strcpy(pcBuf, "`-depth\'");
	} else {
		(void)strcpy(pcBuf, "option `-K\'");
		pcBuf[9] = ch;
	}
}
static void
u_chkonly(chSlot, chOpt, pcList)
int chSlot, chOpt;
char *pcList;
{
	register int chWas;
	static int sbiOnly['w'-'#'+1];
	auto char acOpt[12], acWas[12];

	chWas = sbiOnly[chSlot-'#'];
	u_nameof(acWas, chWas);
	if (chOpt == chWas) {
		fprintf(stderr, "%s: -%s cannot be given more than once\n", progname, acWas);
		exit(1);
	} else if (0 != chWas) {
		u_nameof(acOpt, chOpt);
		fprintf(stderr, "%s: %s forbidden by %s\n", progname, acOpt, acWas);
		exit(1);
	}
	for (/*parameter*/; '\000' !=  *pcList; ++pcList) {
		sbiOnly[*pcList-'#'] = chOpt;
	}
}

/* convert text to control chars, we take `cat -v' style		(ksb)
 * 	[\]octal
 *	^X (or ^x)		contro-x
 *	M-x			x plus 8th bit
 *	c			a plain character
 * return -1 -> no chars to convert
 * return -2 -> unknown control code
 * return -3 -> trailing junk on letter specification
 */
static int
cvtletter(pcScan)
char *pcScan;
{
	register int cvt, n, i;

	if ('\\' == pcScan[0]) {
		switch (*++pcScan) {
		case 'a':
			cvt = '\007';
			++pcScan;
			break;
		case '\n':	/* why would this happen? */
		case 'n':	/* newline */
			cvt = '\n';
			++pcScan;
			break;
		case 't':
			cvt = '\t';
			++pcScan;
			break;
		case 'b':
			cvt = '\b';
			++pcScan;
			break;
		case 'r':
			cvt = '\r';
			++pcScan;
			break;
		case 'f':
			cvt = '\f';
			++pcScan;
			break;
		case 'v':
			cvt = '\013';
			++pcScan;
			break;
		case '\\':
			++pcScan;
		case '\000':
			cvt = '\\';
			break;

		case '0': case '1': case '2': case '3':
		case '4': case '5': case '6': case '7':
			goto have_num;
		case '8': case '9':
			/* 8 & 9 are bogus octals,
			 * cc makes them literals
			 */
			/*fallthrough*/
		default:
			cvt = *pcScan++;
			break;
		}
	} else if ('0' <= *pcScan && *pcScan <= '7' && '\000' != pcScan[1]) {
have_num:
		cvt = *pcScan++ - '0';
		for (i = 0; i < 2; i++) {
			if (! isdigit(*pcScan)) {
				break;
			}
			cvt <<= 3;
			cvt += *pcScan++ - '0';
		}
	} else {
		if ('M' == pcScan[0] && '-' == pcScan[1] && '\000' != pcScan[2]) {
			cvt = 0x80;
			pcScan += 2;
		} else {
			cvt = 0;
		}

		if ('\000' == *pcScan) {
			return -1;
		}

		if ('^' == (n = *pcScan++) && '\000' != *pcScan) {
			n = *pcScan++;
			if (islower(n)) {
				n = toupper(n);
			}
			if ('@' <= n &&  n <= '_') {
				cvt |= n - '@';
			} else if ('?' == n) {
				cvt |= '\177';
			} else {
				return -2;
			}
		} else {
			cvt |= n;
		}
	}
	
	if ('\000' != *pcScan) {
		return -3;
	}
	return cvt;
}
/* from getopt.m */
/* from getopt_key.m */
/* from xclate.m */
#line 243 "xclate.m"
/* Prevent the deadlock that version 2.8 had with widows		(ksb)
 */
static void
WidowsWalk()
{
	if (fMaster) {
		return;
	}
	fprintf(stderr, "%s: recursive execution from the widow process leads to deadlock, becoming a cat\n", progname);
	execlp("cat", "cat", "-", (char *)0);
	execlp("/bin/cat", "cat", "-", (char *)0);
	exit(EX_USAGE);
}

/* Find a safe place to make a /tmp (or $TMPDIR) directory		(ksb)
 */
static char *
LocalTmp(const char *pcBase)
{
	register char *pcMem;
	register int iLen;

	iLen = ((strlen(pcTmpdir)+1+strlen(pcBase)+2)|7)+1;
	if ((char *)0 == (pcMem = malloc(iLen))) {
		fprintf(stderr, "%s: malloc: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	snprintf(pcMem, iLen, "%s/%s/", pcTmpdir, pcBase);
	return pcMem;
}

struct _WXnode {	/* type for the pvBlob we expect	*/
	int fsawactive;
	const char *pcinfo;
	const char *pcdirect;
};
/* Show some version information for a socket in the stack		(ksb)
 */
static int
DiVersion(const char *pcId, const char *pcTag, int fActive, void *pvBlob)
{
	register int fdCheck;
	register struct _WXnode *pWX;
	register char *pcTail;
	auto struct stat stSock;
	auto char acVersion[1024];	/* realy about 6 chars */

	if ((const char *)0 == pcId) {
		pcId = "--";
	}

	/* When wrapw is playing tricks we see her socket as if it
	 * were a directory, don't paninc and nobody gets hurt.
	 */
	stSock.st_mode = 0;
	if ((char *)0 != (pcTail = strrchr(pcTag, '/'))) {
		*pcTail = '\000';
		(void)lstat(pcTag, & stSock);
		*pcTail = '/';
	}
	if ((const char *)0 == pcTag) {
		printf("%s: %2s: missing from our environment", progname, pcId);
	} else if (S_IFSOCK != (S_IFMT & stSock.st_mode) && -1 == lstat(pcTag, &stSock)) {
		printf("%s: %2s: stat: %s: %s", progname, pcId, pcTag, strerror(errno));
	} else if (!fVerbose) {
		printf("%s: %2s %s", progname, pcId, pcTag);
	} else if (-1 == (fdCheck = divConnect(pcTag, RightsWrap, (void *)0)) || 0 >= read(fdCheck, acVersion, sizeof(acVersion)-1)) {
		printf("%s: %2s %s: unresponsive", progname, pcId, pcTag);
	} else {
		close(fdCheck);
		printf("%s: %2s %s: version %s", progname, pcId, pcTag, acVersion);
	}
	if ((struct _WXnode *)0 != (pWX = pvBlob)) {
		if (fActive) {
			pWX->fsawactive = 1;
			printf("%s", pWX->pcinfo);
		}
		if ((const char *)0 != pcTag && (const char *)0 != pWX->pcdirect && 0 == strcmp(pWX->pcdirect, pcTag)) {
			pWX->pcdirect = (const char *)0;
			printf(" [-u]");
		}
	}
	printf("\n");
	if (fActive && !isdigit(*pcId)) {
		return 1;
	}
	return '0' == pcId[0] && '\000' == pcId[1];
}

/* output the standard ksb version details				(ksb)
*/
static void
Version()
{
	auto unsigned uOuter;
	auto struct _WXnode WXThis;

	(void)divNumber(&uOuter);
	divVersion(stdout);
	printf("%s: protocol version %s\n", progname, acProto);
	printf("%s: safe directory template: %s\n", progname, acMySpace);
	WXThis.pcinfo = " [target]";
	WXThis.fsawactive = 0;
	WXThis.pcdirect = pcMaster;
	if (0 == divSearch(DiVersion, (void *)&WXThis) && iDevDepth >= uOuter) {
		if ((const char *)0 != WXThis.pcdirect) {
			DiVersion("-u", WXThis.pcdirect, !WXThis.fsawactive, (void *)&WXThis);
		} else if (0 == iDevDepth) {
			printf("%s: no current diversions\n", progname);
		} else {
			printf("%s: depth -%d is too great for current stack of %d\n", progname, iDevDepth, uOuter);
		}
	} else if ((const char *)0 != WXThis.pcdirect) {
		DiVersion("-u", WXThis.pcdirect, !WXThis.fsawactive, (void *)&WXThis);
	} else if (!WXThis.fsawactive) {
		printf("%s: never saw the active diversion\n", progname);
	}
}

/* Make the server port for this server to listen on			(ksb)
 * stolen from ptyd
 */
static int
MakeServerPort(pcName)
char *pcName;
{
	register int sCtl, iListen, iRet;
	auto struct sockaddr_un run;

	if ((sCtl = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		fprintf(stderr, "%s: socket: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	run.sun_family = AF_UNIX;
	(void) strncpy(run.sun_path, pcName, sizeof(run.sun_path));
	if (-1 == bind(sCtl, (struct sockaddr *)&run, EMU_SOCKUN_LEN(pcName))) {
		return -1;
	}
	iRet = -1;
	for (iListen = 20*64; iListen > 5 && -1 == (iRet = listen(sCtl, iListen)) ; iListen >>= 1) {
		/* try less */
	}
	if (-1 == iRet) {
		fprintf(stderr, "%s: listen: %d: %s\n", progname, iListen, strerror(errno));
		exit(EX_OSERR);
	}
	return sCtl;
}

/* The sort for xid's is strange in that we look for a "number" in	(ksb)
 * the string to compare, as well as a lexical key.
 *	app10 <=> app2 (return -1)
 *	100 <=> 101 (return 1)
 *	10a <=> 10b (return 1)
 *	foo <=> foo1 (return 1)
 * N.B. the strings cannot be (const char), sigh.
 */
static int
XidCmp(pcLeft, pcRight)
char *pcLeft, *pcRight;
{
	register char *pcLNum, *pcRNum;
	auto char *pcLRem, *pcRRem;
	register int iRet;

	for (pcLNum = pcLeft; '\000' != *pcLNum; ++pcLNum) {
		if (isdigit(*pcLNum))
			break;
	}
	for (pcRNum = pcRight; '\000' != *pcRNum; ++pcRNum) {
		if (isdigit(*pcRNum))
			break;
	}
	iRet = (pcRNum - pcRight) - (pcLNum - pcLeft);
	if (0 != iRet) {
		return iRet;
	}
	iRet = strncmp(pcLeft, pcRight, pcRNum-pcRight);
	if (0 != iRet) {
		return iRet;
	}
	pcLRem = pcRRem = "";
	if (isdigit(*pcRNum)) {
		if (isdigit(*pcLNum)) {
			iRet = strtol(pcRight, &pcRRem, 10);
			iRet -= strtol(pcLeft, &pcLRem, 10);
		} else {
			return 1;
		}
	} else if (isdigit(*pcLNum)) {
		return -1;
	} else {
		iRet = 0;
	}
	if (0 != iRet) {
		return iRet;
	}
	return strcmp(pcLRem, pcRRem);
}

/* Repeatedly call write(2) to flush large data out a small pipe	(ksb)
 * most modern unix systems don't need this, except HPUX
 */
ssize_t
ReWrite(int fd, const char *pc, size_t nb)
{
	register ssize_t iRet, cc;

	iRet = 0;
	do {
		cc = write(fd, pc, nb);
		if (-1 == cc)
			return cc;
		if (0 == cc)
			break;
		pc += cc;
		iRet += cc;
		nb -= cc;
	} while (nb > 0);
	return iRet;
}

/* Let the mkcmd pipefit utility show our details better		(ksb)
 */
static pid_t
CredPipeFit(const char *pcCred, const char *pcInterp, char **ppcFilter, char **ppcEnviron, int fdPush)
{
	register pid_t wRet;
	register size_t iLen;
	auto char *pcSave;
	register void *pvMem;

	pcSave = progname;
	pvMem = (void *)0;
	if ((char *)0 != pcCred) {
		iLen = (3|(strlen(progname)+2+strlen(pcCred)))+1;
		if ((char *)0 == (progname = pvMem = malloc(iLen))) {
			progname = pcSave;
		} else {
			snprintf(progname, iLen, "%s: %s", pcSave, pcCred);
		}
	}
	wRet = PipeFit(pcInterp, ppcFilter, ppcEnviron, fdPush);
	progname = pcSave;
	if ((void *)0 != pvMem) {
		free(pvMem);
	}
	return wRet;
}
#line 495 "xclate.m"
/* use mkcmd's path search function to find programs for PipeFit	(ksb)
 * unless the program is spec'd as "/full/path" or "./prog" or "../prog"
 */
static char *
FindBin(char *pcProg)
{
	static char *apcList[2];
	register char *pcRet;

	if ('/' == pcProg[0] || ('.' == pcProg[0] && ('/' == pcProg[1] || ('.' == pcProg[1] && '/' == pcProg[2])))) {
		return pcProg;
	}
	apcList[1] = (char *)0;
	if ((char *)0 == (apcList[0] = pcProg)) {
		apcList[0] = pcInterp;
	}
	if ((char *)0 == apcList[0]) {
		apcList[0] = "/bin/sh";
	}
	if ((char *)0 != (pcRet = util_fsearch(apcList, getenv("PATH")))) {
		return pcRet;
	}
	fprintf(stderr, "%s: %s: not found in PATH\n", progname, apcList[0]);
	exit(EX_NOINPUT);
}

/* A file descriptor information entry for my use			(ksb)
 * N.B. now a bit set
 */
#define ACT_DEAD	0x0100		/* free slot			*/
#define ACT_UP		0x0200		/* special in,out,accept,widow,err*/
#define ACT_XID		0x0400		/* open, no xid yet		*/
#define ACT_QUICK	0x0800		/* done -> quick buffer		*/
#define ACT_OPEN	0x0000		/* open, no command pending	*/
#define ACT_INPUT	0x0001		/* asking for stdin		*/
#define ACT_OUTPUT	0x0002		/* asking for stdout		*/
#define ACT_ERROR	0x0004		/* asking for stderr		*/
#define ACT_WIDOW	0x0008		/* asking for widows (anyone)	*/
#define ACT_EXEC	0x0010		/* wants to fork unmanaged kid	*/
#define ACT_PEND	0x0020		/* claims to have output	*/
#define ACT_BMAX	0x0040		/* claims a full output buffer	*/
#define ACT_DONE	0x0080		/* claims quick, ready to flush	*/
#define ACT_MASK_PRIO	(ACT_EXEC|ACT_PEND|ACT_BMAX|ACT_DONE)
typedef struct PLMnode {
	int factive;			/* fd status from ACT_ above	*/
	int icode;			/* exit code from client	*/
	char acxid[MAX_XID_LEN];	/* name of stream		*/
} PUMPER;

/* Find a client stream to output					(ksb)
 * (the King is dead, long live the King)
 * We'll sort the xid's of all the eq eligables, we'll take a finished
 * stream over an active, we'll take a data stream over a pending one.
 */
static int
Elect(pPLM, iCount)
PUMPER *pPLM;
int iCount;
{
	register int i, iRet, fActive;
	register char *pcFound;

	fActive = 0;
	pcFound = (char *)0;
	iRet = -1;
	for (i = 0; i < iCount; ++i, ++pPLM) {
		if (0 == (ACT_OUTPUT & pPLM->factive)) {
			continue;
		}
		if (0 == (ACT_MASK_PRIO & pPLM->factive)) {
			continue;
		}
		if ((char *)0 == pcFound) {
			/* found one */;
		} else if ((ACT_MASK_PRIO&fActive) < (ACT_MASK_PRIO&pPLM->factive)) {
			/* better stream status */;
		} else if (XidCmp(pcFound, pPLM->acxid) < 0) {
			/* better order */;
		} else {
			/* stick with the one you know */
			continue;
		}
		/* take the new one */
		iRet = i;
		fActive = pPLM->factive;
		pcFound = pPLM->acxid;
	}
	return 0 == fActive ? -1 : iRet;
}

static volatile pid_t wInferior = -1;
static volatile int wInfExits = EX_PROTOCOL;
static volatile int fInfOpts = WNOHANG|WUNTRACED;
#if defined(DEBUG)
static volatile int wPidCount = 0;	/* only a gdb aid */
#endif

/* When a signal for a child arrives we burry the dead.			(ksb)
 * If he is "our boy", then forget he's alive.
 * N.B. Don't set the signal action up until you've set wInferior!
 */
static void
Death(int _dummy)	/*ARGSUSED*/
{
	register pid_t wReap;
	auto int wStatus;

	while (0 < (wReap = wait3(& wStatus, fInfOpts, (struct rusage *)0))) {
		if (WIFSTOPPED(wStatus)) {
			(void)kill(wReap, SIGCONT);
			continue;
		}
		if (-1 == wInferior || wInferior == wReap) {
			if (wInferior == wReap)
				wInferior = 0;
#if defined(DEBUG)
			++wPidCount;
#endif
			wInfExits = WEXITSTATUS(wStatus);
		}
	}
}

/* send an unsigned interger to the peer				(ksb)
 */
static void
TossWord(int fd, size_t wWord, int cSep)
{
	auto char acCvt[64];

	snprintf(acCvt, sizeof(acCvt), "%ld%c", (long)wWord, cSep);
	ReWrite(fd, acCvt, strlen(acCvt));
}

/* decode the word we just sent in TossWord				(ksb)
 * or "." for no value.
 */
static int
CatchWord(int fd, size_t *pwFound)
{
	auto char *pcEnd, acDecode[64];
	register int i;

	for (i = 0; i < sizeof(acDecode); ++i) {
		if (1 != read(fd, acDecode+i, 1)) {
			fprintf(stderr, "%s: read: %d: %s\n", progname, fd, strerror(errno));
			exit(EX_PROTOCOL);
		}
		if (isdigit(acDecode[i]))
			continue;
		if ('.' == acDecode[i]) {
			return 0;
		}
		/* must be a separator like : or \n
		 */
		acDecode[i] = '\000';
		break;
	}
	if (sizeof(acDecode) == i) {
		fprintf(stderr, "%s: string length too long\n", progname);
		exit(EX_PROTOCOL);
	}
	pcEnd = (char *)0;
	*pwFound = strtol(acDecode, &pcEnd, 10);
	if ((char *)0 != pcEnd && '\000' != *pcEnd) {
		fprintf(stderr, "%s: %s: length conversion failed\n", progname, acDecode);
		exit(EX_PROTOCOL);
	}
	return 1;
}

/* send a (potentially long) string over the diversion socket		(ksb)
 */
static void
TossString(int fd, char *pcDatum)
{
	register size_t uLen;
	if ((char *)0 == pcDatum) {
		ReWrite(fd, ".", 1);
		return;
	}
	uLen = ((unsigned long)strlen(pcDatum))+1;
	TossWord(fd, uLen, ':');
	ReWrite(fd, pcDatum, uLen);
}

/* decode what TossString sent us
 */
static char *
CatchString(int fd)
{
	auto char *pcRet;
	auto size_t wSize;

	if (0 == CatchWord(fd, &wSize)) {
		return (char *)0;
	}
	if ((char *)0 == (pcRet = malloc(wSize))) {
		fprintf(stderr, "%s: malloc: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	if (wSize == read(fd, pcRet, wSize)) {
		return pcRet;
	}
	fprintf(stderr, "%s: out of sync with peer\n", progname);
	exit(EX_SOFTWARE);
}

/* Tell any notification agent about this tasks exit status		(ksb)
 * (the iTty flag saves a lot of duplicate fcntl calls, that's all).
 */
static void
Notify(int fdTo, PUMPER *pPLM, int iTty)
{
	register int iLen;
	auto char acCvt[8];

	/* XXX do 'and' and 'or' options here from the todo
	 */
	if (-1 == fdTo) {
		return ;
	}
	iLen = strlen(pPLM->acxid);
	if (iTty) {
		pPLM->acxid[iLen] = '\n';
	}
	if (fExit2) {
		snprintf(acCvt, sizeof(acCvt), "%d,", pPLM->icode);
		ReWrite(fdTo, acCvt, strlen(acCvt));
	}
	ReWrite(fdTo, pPLM->acxid, iLen+1);
}

/* A client connects to our socket and give us an xid and some status	(ksb)
 * We send him back someplace to put his data, and a sequence number.
 * We copies his stream there, then closes the data channel, and the
 * control connection to tell us he's done.
 * We can notify an unrelated process of the termination of a client,
 * for hxmd's use mostly.
 *	while we still have an open connection (widow or client)
 *		select on the fd's we have active
 *		close any done clients (or the widow stream)
 *		look for new clients
 *			add control connection
 *		read commands from clients
 *			update status
 *		as needed elect a new output stream, input, and stderr
 */
static void
PumpLikeMad(fdSource, fdAccept, fdOut, fdWidows, fdNotify, fColonMode)
int fdSource, fdAccept, fdOut, fdWidows, fdNotify, fColonMode;
{
	register int cc;
	auto PUMPER aPLM[FD_SETSIZE];
	auto int iLeaseOut, iServing, iMaxPoll;
	auto char *pcQuick;
	auto fd_set fdsTemp, fdsReading;
	auto char acCounter[(MAX_XID_LEN|31)+1];
	auto int iConnections, iTty, fdSend, fdDrain, fdQuick;
	auto unsigned int uiCapture;
	auto struct sigaction saWant;
	auto struct timeval stStall;

	/* Build a (huge) list of clients to buffer.  We know that we
	 * need 2 fd's for each client, so allocated buffers to max_fd/2
	 * clients only (we know fdAccept takes 1 pair off as well).
	 */
	for (cc = 0; cc < FD_SETSIZE; ++cc) {
		aPLM[cc].factive = ACT_DEAD;
	}
	fdDrain = 0;
	aPLM[fdDrain].factive = ACT_UP;
	(void)strcpy(aPLM[0].acxid, "drain");
	aPLM[2].factive = ACT_UP;
	(void)strcpy(aPLM[2].acxid, "err");
	aPLM[fdWidows].factive = ACT_UP;
	(void)strcpy(aPLM[fdWidows].acxid, "widows");
	aPLM[fdOut].factive = ACT_UP;
	(void)strcpy(aPLM[fdOut].acxid, "out");
	aPLM[fdAccept].factive = ACT_UP;
	(void)strcpy(aPLM[fdAccept].acxid, "accept");
	if (-1 != fdNotify) {
		aPLM[fdNotify].factive = ACT_UP;
		(void)strcpy(aPLM[fdNotify].acxid, "notify");
		iTty = isatty(fdNotify);
	}
	if (-1 != fdSource) {
		aPLM[fdSource].factive = ACT_UP;
		(void)strcpy(aPLM[fdSource].acxid, "in");
	}
	(void)memset((void *)&saWant, '\000', sizeof(saWant));
	saWant.sa_handler = SIG_IGN;
	saWant.sa_flags = SA_RESTART;
	if (-1 == sigaction(SIGPIPE, &saWant, (struct sigaction *)0)) {
		fprintf(stderr, "%s: sigaction: restart: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	(void)memset((void *)& saWant, '\000', sizeof(saWant));
	saWant.sa_handler = (void *)Death;
#if HAVE_SIGACTION
	saWant.sa_sigaction = (void *)Death;
#endif
	saWant.sa_flags = SA_RESTART;
	if (-1 == sigaction(SIGCHLD, & saWant, (struct sigaction *)0)) {
		fprintf(stderr, "%s: sigaction: CHLD: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	Death('P');

	uiLimit |= 1023;
	++uiLimit;
	while (512 < uiLimit && (char *)0 == (pcQuick = malloc(uiLimit))) {
		uiLimit >>= 1;
	}
	if (512 > uiLimit) {
		fprintf(stderr, "%s: malloc: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	uiCapture = 0;
	fdQuick = iLeaseOut = -1;
	iMaxPoll = fdAccept;
	FD_ZERO(&fdsReading);
	FD_SET(fdAccept, &fdsReading);
	FD_SET(fdDrain, &fdsReading);
	iServing = 1;
	iConnections = 0;
	/* While we have a client or a process to manage we process events
	 * We used to race between the 0 != Inferior and the select setup, now
	 * we timeout ~17 times a minute to check again.  Cheap solution.
	 */
	stStall.tv_sec = 2;
	stStall.tv_usec = 178309;
	while (0 != iServing || 0 != wInferior) {
		register int iGot;

		fdsTemp = fdsReading;
		if (-1 == (iGot = select(iMaxPoll+1, &fdsTemp, (fd_set *)0, (fd_set *)0, 0 == iServing ? & stStall : (struct timeval *)0))) {
			if (EINTR == errno)
				continue;
			fprintf(stderr, "%s: select: %s\n", progname, strerror(errno));
			break;
		}
		if (0 == iGot) {
			stStall.tv_sec = 3;
			stStall.tv_usec = 524578;
			continue;
		}

		if (0 < iGot && FD_ISSET(fdAccept, &fdsTemp)) {
			register int fdClient;
			if (-1 == (fdClient = accept(fdAccept, (struct sockaddr *)0, (socklen_t *)0))) {
				if (EINTR == errno)
					continue;
				/* Someone broke our listening socket??
				 */
				FD_CLR(fdAccept, &fdsReading);
				close(fdAccept);
				continue;
			}
			aPLM[fdClient].factive = ACT_XID;
			aPLM[fdClient].icode = 0;
			(void)memset((void *)aPLM[fdClient].acxid, '\000', sizeof(aPLM[0].acxid));
			--iGot;
			FD_SET(fdClient, &fdsReading);
			if (fdClient > iMaxPoll) {
				iMaxPoll = fdClient;
			}
			++iServing;
			ReWrite(fdClient, acProto, sizeof(acProto));
			/* If we continue here we are a little more "fair"
			 */
			if (-1 == iLeaseOut) {
				continue;
			}
		}

		/* pump widows data if available
		 */
		if (-1 != fdDrain && FD_ISSET(fdDrain, &fdsTemp)) {
			register int iLen;
			auto char acW[PIPE_SIZE];

			iLen = read(fdDrain, acW, sizeof(acW));
			if (0 < iLen) {
				ReWrite(fdWidows, acW, iLen);
			} else {
				FD_CLR(fdDrain, &fdsReading);
				close(fdDrain);
				(void)open(acDevNull, O_RDONLY, 0666);
				aPLM[fdDrain].factive = ACT_DEAD;
				fdDrain = -1;
				--iServing;
				/* We close fdWidows in the caller, a client
				 * can still ask to write to that. --ksb
				 */
				aPLM[fdWidows].factive = ACT_DEAD;
			}
			--iGot;
		}

		/* Look for a client command and act on it.
		 * N.B. all commands are at least 4 chatacters on the socket
		 *	assert(sizeof(acCmd)>=MAX_XID_LEN&&MAX_XID_LEN>=4);
		 * the client must wait for the reply before sending cmds
		 */
		for (cc = 1; 0 != iGot && cc <= iMaxPoll; ++cc) {
			register int iLen;
			auto char acCmd[(MAX_XID_LEN|7)+1];

			if (!FD_ISSET(cc, &fdsTemp) || fdAccept == cc) {
				continue;
			}
			--iGot;
			if (0 != (ACT_QUICK & aPLM[cc].factive)) {
				iLen = read(cc, pcQuick+uiCapture, uiLimit-uiCapture);
				if (0 < iLen) {
					uiCapture += iLen;
					if (uiCapture == uiLimit) {
						FD_CLR(cc, &fdsReading);
					}
					continue;
				}
				goto drop;
			}
			/* In this version the client must send xid first
			 *  xid\n  ||  xid\r  ||  xid\000
			 * we send back a uniq sequence number
			 */
			if (ACT_XID == aPLM[cc].factive) {
				register int iCursor, c;
				register char *pcEos, *pcMax;

				iLen = read(cc, acCmd, MAX_XID_LEN+1);
				if (0 >= iLen) {
					goto drop;
				}
				pcEos = aPLM[cc].acxid;
				pcMax = pcEos+sizeof(aPLM[0].acxid)-1;
				pcEos += strlen(pcEos);
				for (iCursor = 0; iCursor < iLen; ++iCursor) {
					if ('\n' == (c = acCmd[iCursor]) || '\r' == c)
						c = '\000';
					if (pcEos < pcMax)
						*pcEos++ = c;
					if ('\000' == c) {
						aPLM[cc].factive = ACT_OPEN;
						snprintf(acCounter, sizeof(acCounter), "%d\n", iConnections++);
						ReWrite(cc, acCounter, strlen(acCounter));
						break;
					}
				}
				*pcEos = '\000';
				continue;
			}
			if (0 >= (iLen = read(cc, acCmd, 4))) {
				goto drop;
			}
			/* [0-9][0-9][0-9]\000 -- report exit code
			 */
			if (4 == iLen && isdigit(acCmd[0]) && isdigit(acCmd[1]) && isdigit(acCmd[2])) {
				aPLM[cc].icode = atoi(acCmd);
				continue;
			}
			/* cq \000	- channel abort (or just close socket)
			 */
			if (4 != iLen || ' ' != acCmd[2] || ('c' == acCmd[0] && 'q' == acCmd[1])) {
 drop:
				FD_CLR(cc, &fdsReading);
				close(cc);
				aPLM[cc].factive = ACT_DEAD;
				Notify(fdNotify, & aPLM[cc], iTty);
				--iServing;
				if (cc == fdQuick) {
					fdQuick = -1;
				}
				if (cc == iLeaseOut) {
					if (-1 != fdDrain && 0 != (aPLM[iLeaseOut].factive & ACT_INPUT))
						FD_SET(0, &fdsReading);
					iLeaseOut = -1;
				}
				continue;
			}
			/* -V \000	- show version of protocol
			 */
			if ('-' == acCmd[0] && 'V' == acCmd[1]) {
				(void)ReWrite(cc, acProto, sizeof(acProto));
				continue;
			}
			/* Q! \000	- channel wants us to exit when done
			 * (We'll exit after present clients finish.)
			 */
			if ('Q' == acCmd[0] && '!' == acCmd[1]) {
				iServing -= fColonMode;
				fColonMode = wInferior = 0;
				continue;
			}
			/* ex \000	- channel wants to execute
			 */
			if ('e' == acCmd[0] && 'x' == acCmd[1]) {
				if (0 == (ACT_DONE & aPLM[cc].factive))
					aPLM[cc].factive |= ACT_EXEC;
				continue;
			}
			/* hd \000	- channel has data (not complete)
			 */
			if ('h' == acCmd[0] && 'd' == acCmd[1]) {
				if (0 == (ACT_DONE & aPLM[cc].factive))
					aPLM[cc].factive |= ACT_PEND;
				continue;
			}
			/* bx \000	- channel buffer full
			 */
			if ('b' == acCmd[0] && 'x' == acCmd[1]) {
				if (0 == (ACT_DONE & aPLM[cc].factive))
					aPLM[cc].factive |= ACT_BMAX;
				continue;
			}
			/* rf \000	- channel complete (ready to flush)
			 */
			if ('r' == acCmd[0] && 'f' == acCmd[1]) {
				if (0 == (ACT_DONE & aPLM[cc].factive))
					aPLM[cc].factive |= ACT_BMAX;
				continue;
			}
			/* qm \000	- channel complete, quick mode
			 */
			if ('q' == acCmd[0] && 'm' == acCmd[1]) {
				aPLM[cc].factive |= ACT_DONE;
				continue;
			}
			/* od \000 open my current working directory, anyone
			 * can.  If I can't open it I'll return /.
			 */
			if ('o' == acCmd[0] && 'd' == acCmd[1]) {
				register char *pcDir = ".\n";

				if (-1 == (fdSend = open(".", O_RDONLY, 0))) {
					fdSend = open("/", O_RDONLY, 0);
					pcDir = "/\n";
				}
				if (-1 == RightsSendFd(cc, &fdSend, 1, pcDir)) {
					/* ouch, I don't know */
				}
				close(fdSend);
				continue;
			}

			/* o0 \000	- channel request for (widows|std)-in
			 * o1 \000	- channel request for stdout
			 * o2 \000	- channel request for stderr
			 * ow \000	- open widows out directly (no lock)
			 */
			if ('o' == acCmd[0] && '0' == acCmd[1]) {
				aPLM[cc].factive |= ACT_INPUT;
				continue;
			}
			if ('o' == acCmd[0] && '1' == acCmd[1]) {
				aPLM[cc].factive |= ACT_OUTPUT;
				continue;
			}
			if ('o' == acCmd[0] && '2' == acCmd[1]) {
				aPLM[cc].factive |= ACT_ERROR;
				continue;
			}
			if ('o' == acCmd[0] && 'w' == acCmd[1]) {
				if (-1 == RightsSendFd(cc, &fdWidows, 1, "widow\n")) {
					/* ouch, I don't know, maybe we can
					 * send /dev/null as consolation prize?
					 */
				}
				continue;
			}
			/* Return some options we might want client to know,
			 * all of these return a flag character and a '\000'.
			 */
			if ('?' == acCmd[0] && 'q' == acCmd[1]) {
				ReWrite(cc, fAllowQuick||fSqueeze ? "q" : "-", 2);
				continue;
			}
			if ('?' == acCmd[0] && 's' == acCmd[1]) {
				ReWrite(cc, fSqueeze ? "s" : "-", 2);
				continue;
			}
			if ('?' == acCmd[0] && 'd' == acCmd[1]) {
				ReWrite(cc, fPublish ? "d" : "-", 2);
				continue;
			}
			if ('?' == acCmd[0] && ':' == acCmd[1]) {
				ReWrite(cc, 0 == wInferior ? "Q" : fColonMode ? ":" : "-", 2);
				continue;
			}
			if ('?' == acCmd[0] && 'T' == acCmd[1]) {
				TossString(cc, pcTitle);
				continue;
			}
			if ('?' == acCmd[0] && 'H' == acCmd[1]) {
				TossString(cc, pcHorizRule);
				continue;
			}
			if ('?' == acCmd[0] && 'L' == acCmd[1]) {
				if (fGaveL)
					TossWord(cc, uiLimit, '\n');
				else
					ReWrite(cc, ".", 1);
				continue;
			}
			fprintf(stderr, "%s: %c%c: unknown command\n", progname, acCmd[0], acCmd[1]);
		}
		/* drop the quick data, if we have a break in the output
		 */
		if (-1 == iLeaseOut && 0 != uiCapture) {
			register int iLen;

			ReWrite(fdOut, pcQuick, uiCapture);
			uiCapture = 0;
			while (-1 != fdQuick) {
				iLen = read(fdQuick, pcQuick, uiLimit);
				if (0 <= iLen)
					break;
				ReWrite(fdOut, pcQuick, iLen);
			}
			if (-1 != fdQuick) {
				FD_CLR(fdQuick, &fdsReading);
				close(fdQuick);
				aPLM[fdQuick].factive = ACT_DEAD;
				Notify(fdNotify, & aPLM[fdQuick], iTty);
				--iServing;
				fdQuick = -1;
			}
		}
		/* When nobody is using the channel, find a worthy client.
		 * Tell the new shining one he's up, or we need another.
		 */
		while (-1 == iLeaseOut) {
			if (-1 == (iLeaseOut = Elect(aPLM, iMaxPoll+1))) {
				break;
			}
			/* We had to catch sigpipe here, the other end could
			 * have been killed before we serviced them.
			 */
			if (-1 != RightsSendFd(iLeaseOut, &fdOut, 1, "out")) {
				aPLM[iLeaseOut].factive	&= ~ACT_OUTPUT;
				break;
			}
			FD_CLR(iLeaseOut, &fdsReading);
			close(iLeaseOut);
			aPLM[iLeaseOut].factive = ACT_DEAD;
			--iServing;
		}
		/* Only the holder of stdout can get stdin/err (avoid deadlock).
		 */
		if (-1 == iLeaseOut) {
			continue;
		}
		if (0 != (aPLM[iLeaseOut].factive & ACT_ERROR)) {
			fdSend = 2;
			if (-1 != RightsSendFd(iLeaseOut, &fdSend, 1, "err\n"))
				aPLM[iLeaseOut].factive &= ~ACT_ERROR;
		}
		if (0 != (aPLM[iLeaseOut].factive & ACT_INPUT)) {
			fdSend = fdSource;
			if (-1 != RightsSendFd(iLeaseOut, &fdSend, 1, "in\n"))
				aPLM[iLeaseOut].factive &= ~ACT_INPUT;
		}
		/* If we have a client that's done, allocate the quick buffer
		 */
		if (fAllowQuick && -1 == fdQuick && uiCapture < uiLimit && -1 != (fdQuick = Elect(aPLM, iMaxPoll+1))) {
			fdSend = fdWidows;
			if (0 == (ACT_DONE & aPLM[fdQuick].factive) || -1 == RightsSendFd(fdQuick, &fdSend, 1, "quick\n")) {
				fdQuick = -1;
			} else {
				aPLM[fdQuick].factive &= ~ACT_MASK_PRIO;
				aPLM[fdQuick].factive |= ACT_QUICK;
			}
		}
	}
}

/* Install the option to prevent recursion under -W.			(ksb)
 * Build (and return) a new environ with the option added to acEnvCmd.
 */
char **
PreventRecursion(char **ppcEnv, char *pcOpt)
{
	register char **ppcRet, *pcOrig, **ppcFound;
	register int iNewLen, i;

	if ((char **)0 == ppcEnv) {
		auto char *apcNada[1];
		ppcEnv = apcNada;
		apcNada[0] = (char *)0;
	}
	for (i = 0; (char *)0 != ppcEnv[i]; ++i) {
		/* nada */
	}
	/* Allocate an extra slot incase we add XCLATE, and round up
	 * to a multiple of 4 for the memory allocator.  We never free
	 * this space, which is OK in xclate's work-flow. -- ksb
	 */
	iNewLen = ((i + 1)|3)+1;
	if ((char **)0 == (ppcRet = calloc(iNewLen, sizeof(char *)))) {
		return ppcEnv;
	}
	/* copy the environment, remember where $XCLATE lives
	 */
	ppcFound = (char **)0;
	for (i = 0; (char *)0 != ppcEnv[i]; ++i) {
		ppcRet[i] = ppcEnv[i];
		if (0 != strncmp(ppcRet[i], acEnvCmd, sizeof(acEnvCmd)-1) || '=' != ppcRet[i][sizeof(acEnvCmd)])
			continue;
		ppcFound = & ppcRet[i];
	}
	if ((char **)0 == ppcFound) {
		ppcFound = & ppcRet[i++];
		if (' ' == *pcOpt) {
			++pcOpt;	/* remove the whitespace	*/
		}
		pcOrig = "";
	} else {
		pcOrig = & ppcFound[0][sizeof(acEnvCmd)+1];
	}
	iNewLen = ((sizeof(acEnvCmd)+1+strlen(pcOrig)+strlen(pcOpt))|15)+1;
	if ((char *)0 == (ppcFound[0] = calloc(iNewLen, sizeof(char)))) {
		return ppcEnv;
	}
	snprintf(ppcFound[0], iNewLen, "%s=%s%s", acEnvCmd, pcOrig, pcOpt);
	ppcRet[i] = (char *)0;
	return ppcRet;
}

/* open a widow, or new output channel					(ksb)
 */
int
NewChannel(char *pcWhich, int fdDefault, char **ppcEnviron, const char *pcCredit)
{
	register int fdRet;
	auto char *pcEnd;
	auto char *apcFilter[8];
	auto struct sockaddr_un run;

	fdRet = fdDefault;
	if ((char *)0 == pcWhich || ('-' == pcWhich[0] && '\000' == pcWhich[1])) {
		return fdRet;
	}
	if ('|' == pcWhich[0]) {
		if ((char *)0 == (apcFilter[0] = strrchr(pcInterp, '/'))) {
			apcFilter[0] = pcInterp;
		} else {
			++(apcFilter[0]);
		}
		apcFilter[1] = 0 == strcmp(apcFilter[0], "perl") ? "-e" : "-c";
		if ('-' != pcWhich[1]) {
			apcFilter[2] = pcWhich+1;
			apcFilter[3] = (char *)0;
		} else {
			apcFilter[2] = "--";
			apcFilter[3] = pcWhich+1;
			apcFilter[4] = (char *)0;
		}
		CredPipeFit(pcCredit, pcInterp, apcFilter, ppcEnviron, fdRet);
		(void)fcntl(fdRet, F_SETFD, 1);
	} else if ('>' == pcWhich[0] && '&' == pcWhich[1]) {
		/* LLL we could recognize >&- to return -1 */
		pcEnd = (char *)0;
		fdRet = strtol(pcWhich+2, &pcEnd, 10);
		if ((char *)0 != pcEnd && '\000' != *pcEnd) {
			fprintf(stderr, "%s: unknown diversion expression `%s'?\n", progname, pcEnd);
			exit(EX_DATAERR);
		}
		if (2 < fdRet) {
			(void)fcntl(fdRet, F_SETFD, 1);
		}
		if (fVerbose && (const char *)0 != pcCredit) {
			fprintf(fpVerbose, "%s: %s: exec >&%d\n", progname, pcCredit, fdRet);
		}
	} else if ('>' == pcWhich[0] && '>' == pcWhich[1]) {
		pcWhich += 2;
		fdRet = open(pcWhich, O_WRONLY|O_CREAT|O_APPEND, 0666);
		if (-1 == fdRet) {
			fprintf(stderr, "%s: open: %s: %s\n", progname, pcWhich, strerror(errno));
			exit(EX_NOINPUT);
		}
		if (2 < fdRet) {
			(void)fcntl(fdRet, F_SETFD, 1);
		}
		if (fVerbose && (const char *)0 != pcCredit) {
			fprintf(fpVerbose, "%s: %s: exec %d>>%s\n", progname, pcCredit, fdRet, pcWhich);
		}
	} else {
		register int iOpenOpt;

		/* I wish we could set O_SHLOCK or O_EXLOCK here, at least
		 * we can connect to a socket, like dispd. -- ksb
		 */
		iOpenOpt = O_WRONLY|O_CREAT;
		if ('>' == pcWhich[0]) {
			iOpenOpt |= O_TRUNC;
			++pcWhich;
		}
		if (-1 == (fdRet = open(pcWhich, iOpenOpt, 0666))) {
			register int e;

			e = errno;
			run.sun_family = AF_UNIX;
			(void)strncpy(run.sun_path, pcWhich, sizeof(run.sun_path));
			if (-1 == (fdRet = socket(AF_UNIX, SOCK_STREAM, 0) || -1 == connect(fdRet, (struct sockaddr *)&run, EMU_SOCKUN_LEN(pcWhich)))) {
				if (ENOTSOCK == errno)
					fprintf(stderr, "%s: open: %s: %s\n", progname, pcWhich, strerror(e));
				else
					fprintf(stderr, "%s: connect: %s: %s\n", progname, pcWhich, strerror(errno));
				exit(EX_NOINPUT);
			}
			/* we don't chat anything, the utility must */
		}
		if (2 < fdRet) {
			(void)fcntl(fdRet, F_SETFD, 1);
		}
		if (fVerbose && (const char *)0 != pcCredit) {
			fprintf(fpVerbose, "%s: %s: exec %d>%s\n", progname, pcCredit, fdRet, pcWhich);
		}
	}
	if (-1 != fdRet) {
		return fdRet;
	}
	if (-1 == (fdRet = open(acDevNull, O_WRONLY, 0666))) {
		fprintf(stderr, "%s: open: %s: %s\n", progname, acDevNull, strerror(errno));
		exit(EX_NOINPUT);
	}
	if (2 < fdRet) {
		(void)fcntl(fdRet, F_SETFD, 1);
	}
	if (fVerbose && (const char *)0 != pcCredit) {
		fprintf(fpVerbose, "%s: %s: exec %d>%s\n", progname, pcCredit, fdRet, acDevNull);
	}
	return fdRet;
}

/* Like the above, but for the input express for stdin			(ksb)
 * Return non-zero for an OS error, or exit(EX_?).  Take '-' as /dev/null.
 */
static int
ResetInput(char *pcWhich, int fdDest, char **ppcEnviron, char *pcCredit)
{
	auto int fdTmp;
	auto char *pcEnd;
	auto char *apcFilter[8];
	auto struct sockaddr_un run;

	if ((char *)0 == pcWhich || '\000' == *pcWhich) {
		return 0;
	}
	if ('-' == pcWhich[0] && '\000' == pcWhich[1]) {
		pcWhich = acDevNull;
	}
	if ('|' == pcWhich[0]) {
		if ((char *)0 == (apcFilter[0] = strrchr(pcInterp, '/'))) {
			apcFilter[0] = pcInterp;
		} else {
			++(apcFilter[0]);
		}
		apcFilter[1] = 0 == strcmp(apcFilter[0], "perl") ? "-e" : "-c";
		if ('-' != pcWhich[1]) {
			apcFilter[2] = pcWhich+1;
			apcFilter[3] = (char *)0;
		} else {
			apcFilter[2] = "--";
			apcFilter[3] = pcWhich+1;
			apcFilter[4] = (char *)0;
		}
		if (-1 == CredPipeFit(pcCredit, pcInterp, apcFilter, ppcEnviron, 0)) {
			return 1;
		}
	} else if ('<' == pcWhich[0] && '&' == pcWhich[1]) {
		/* We recognize <&- for close stdin, why would you want to?
		 */
		if ('-' == pcWhich[2] && '\000' == pcWhich[3]) {
			close(0);
			return 0;
		}
		pcEnd = (char *)0;
		fdTmp = strtol(pcWhich+2, &pcEnd, 10);
		if ((char *)0 != pcEnd && '\000' != *pcEnd) {
			fprintf(stderr, "%s: unknown input expression `%s'?\n", progname, pcEnd);
			exit(EX_DATAERR);
		}
		if (fVerbose && (const char *)0 != pcCredit) {
			fprintf(fpVerbose, "%s: %s: exec 0<&%d\n", progname, pcCredit, fdTmp);
		}
		if (0 != fdTmp && -1 == dup2(fdTmp, 0)) {
			fprintf(stderr, "%s: dup2: %d, 0: %s\n", progname, fdTmp, strerror(errno));
			exit(EX_OSERR);
		}
	} else if ('<' == pcWhich[0] && '<' == pcWhich[1]) {
		fprintf(stderr, "%s: <<: here documents not supported (yet)\n", progname);
		exit(EX_UNAVAILABLE);
	} else if ('<' == pcWhich[0] && '>' == pcWhich[1]) {
		(void)close(0);
		if (0 != open(pcWhich+2, O_RDWR, 0666)) {
			fprintf(stderr, "%s: open: %s: %s\n", progname, pcWhich+2, strerror(errno));
			exit(EX_NOINPUT);
		}
	} else {
		if ('<' == *pcWhich)
			++pcWhich;
		(void)close(0);
		if (0 != open(pcWhich, O_RDONLY, 0666)) {
			register int e;

			e = errno;
			run.sun_family = AF_UNIX;
			(void)strncpy(run.sun_path, pcWhich, sizeof(run.sun_path));
			if (0 != socket(AF_UNIX, SOCK_STREAM, 0) || -1 == connect(0, (struct sockaddr *)&run, EMU_SOCKUN_LEN(pcWhich))) {
				if (ENOTSOCK == errno)
					fprintf(stderr, "%s: open: %s: %s\n", progname, pcWhich, strerror(e));
				else
					fprintf(stderr, "%s: connect: %s: %s\n", progname, pcWhich, strerror(errno));
				exit(EX_NOINPUT);
			}
			/* we don't chat anything, the utility must */
		}
	}
	return 0;
}

/* We are controlling an instance of xclate				(ksb)
 *	build a unix domain socket and bind to it
 *	set environment for kids (after we read it, as needed)
 *	setup widows fd (to our parent, by default)
 *	+ fork a child and execve her default "/bin/sh" {"-sh", (char *)0}
 *	PumpLikeMad
 *	wait for child (to cleanup zombie)
 *	exit with the above exit code
 */
static void
Master(argc, argv)
int argc;
char **argv;
{
	extern char **environ;
	register char *pcExec, *pc;
	register int i;
	auto unsigned uTop;
	auto char *apcDefShell[2], **ppcNoRecurse, *pcEncl;
	auto int fdListen, fdWidow, fdPriv, fdNotify, fdFeed, fdOrigIn;
	auto char acEnvName[512];
	auto char *pcWorkSpace, *pcSocket, *pcParent;

	/* Don't mess with my stdin, stdout, stderr.  If they are
	 * closed I'll just open /dev/null as I see fit.  Save the
	 * original stdin (or /dev/null) away for PumpLikeMad.
	 */
	if (-1 == fcntl(0, F_GETFD, 1) && 0 != open(acDevNull, O_RDONLY, 0666)) {
		fprintf(stderr, "%s: open: %s: %s\n", progname, acDevNull, strerror(errno));
		exit(EX_OSERR);
	}
	if (-1 == fcntl(1, F_GETFD, 1) && 1 != open(acDevNull, O_WRONLY, 0666)) {
		fprintf(stderr, "%s: open: %s: %s\n", progname, acDevNull, strerror(errno));
		exit(EX_OSERR);
	}
	if (-1 == fcntl(2, F_GETFD, 1) && 2 != open(acDevNull, O_WRONLY, 0666)) {
		fprintf(stderr, "%s: open: %s: %s\n", progname, acDevNull, strerror(errno));
		exit(EX_OSERR);
	}
	if (-1 == (fdOrigIn = dup(0))) {
		fprintf(stderr, "%s: dup: 0: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	(void)fcntl(fdOrigIn, F_SETFD, 1);

	if (argc == 0 || (char *)0 == (pcExec = argv[0])) {
		if ((char *)0 == (pcExec = pcInterp)) {
			pcExec = "/bin/sh";
		}
		if ((char *)0 != (pc = strrchr(pcExec, '/'))) {
			++pc;
		} else {
			pc = pcExec;
		}
		apcDefShell[0] = pc;
		apcDefShell[1] = (char *)0;
		argv = apcDefShell, argc = 1;
	}
	if (1 == argc && ':' == argv[0][0] && '\000' == argv[0][1]) {
		pcExec = (char *)0;
	} else {
		pcExec = FindBin(pcExec);
	}
	if (-1 == divNumber(& uTop )) {
		fprintf(stderr, "%s: divStack: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	++uTop;
	/* Allow xcl_0 to be set by the parent to force a wrapper home on us.
	 */
	pcParent = (0 == uTop) ? (char *)0 : divIndex(uTop-1);

	/* -O - open an enclosing diversion, find it before we publish ours
	 */
	pcEncl = (char *)0 != pcPriv && ('-' == pcPriv[0] && '\000' == pcPriv[1]) ? divSelect() : (char *)0;

	/* Build the socket if we have fixed name use that,
	 * else if we have a parent use his directory, or make our own.
	 */
	if ((char *)0 == pcMaster) {
		register int iScan;
		auto struct stat stDup;

		pcWorkSpace = (char *)0 != pcParent ? strdup(pcParent) : LocalTmp(acMySpace);
		if ((char *)0 == pcWorkSpace || (char *)0 == (pc = strrchr(pcWorkSpace, '/'))) {
			fprintf(stderr, "%s: workspace botch (%s)\n", progname, (char *)0 == pcWorkSpace ? "a NULL pointer" : "missing slash");
			exit(EX_SOFTWARE);
		}
		*pc = '\000';
		if ((char *)0 == pcParent) {
			mkdtemp(pcWorkSpace);
		}
		i = (7|strlen(pcWorkSpace))+MAX_XID_LEN+4+16;
		if ((char *)0 == (pcSocket = calloc(i, sizeof(char)))) {
			fprintf(stderr, "%s: calloc: %d*%u: %s\n", progname, i, (unsigned)sizeof(char), strerror(errno));
			exit(EX_TEMPFAIL);
		}

		/* We try to make a pattern that someone could follow,
		 * but the ice is too thin here to bet on any races -- ksb
		 */
		for (iScan = (fPublish ? uTop : 0); 1; ++iScan) {
			if (fPublish) {
				snprintf(pcSocket, i, "%s/%d", pcWorkSpace, iScan);
			} else {
				snprintf(pcSocket, i, "%s/%u_%d", pcWorkSpace, uTop, iScan);
			}
			if (-1 != stat(pcSocket, &stDup))
				continue;
			if (-1 != (fdListen = MakeServerPort(pcSocket)))
				break;
		}
	} else if (-1 == (fdListen = MakeServerPort(pcMaster))) {
		fprintf(stderr, "%s: bind: %s: %s\n", progname, pcMaster, strerror(errno));
		exit(EX_OSERR);
	} else {
		pcWorkSpace = (char *)0;
		pcSocket = pcMaster;
	}
	(void)fcntl(fdListen, F_SETFD, 1);
	if (fPublish) {
		i = divPush(pcSocket);
	} else {
		i = divDetach(pcSocket, (const char *)0);
	}
	if (0 != i) {
		fprintf(stderr, "%s: environment failure: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}

	/* If we can find XCLATE_$TOP in the environment rename it to XCLATE,
	 * else (we can't find a new one) at least unset the old one.
	 * Thus the xclate below us gets a different set of forced options.
	 */
	snprintf(acEnvName, sizeof(acEnvName), "%s_%u", acEnvCmd, uTop);
	if ((char *)0 != (pc = getenv(acEnvName))) {
		(void)setenv(acEnvCmd, pc, 1);
		if (fPublish) {
			(void)unsetenv(acEnvName);
		}
	} else if ((char *)0 != getenv(acEnvCmd)) {
		(void)unsetenv(acEnvCmd);
	}

	/* Accept the traffic from our child process(es)
	 */
	fdFeed = -1;

	/* We need to call NewChannel before the fork to set close-on-exec
	 * for any fd's the client process passed us, viz. -W ">&4"	(ksb)
	 */
	ppcNoRecurse = PreventRecursion(environ, " -Z");
	if ((char *)0 == pcNotify) {
		fdNotify = -1;
	} else if ('-' == pcNotify[0] && '\000' == pcNotify[1]) {
		fdNotify = open("/dev/tty", O_WRONLY, 0666);
		(void)fcntl(fdNotify, F_SETFD, 1);
	} else {
		register int fdTry;

		fdTry = dup(2);
		fdNotify = NewChannel(pcNotify, fdTry, ppcNoRecurse, "-N");
		if (fdNotify != fdTry)
			close(fdTry);
	}
	fdWidow = NewChannel(pcWidows, 2, ppcNoRecurse, "-W");
	if ((char *)0 == pcPriv) {
		fdPriv = 1;
	} else if ('-' == pcPriv[0] && '\000' == pcPriv[1]) {
		auto int iLen;

		/* -O - open an enclosing diversion, or fail, even support -Q
		 */
		if ((char *)0 == pcEncl) {
			fprintf(stderr, "%s: -O: -: no such diversion\n", progname);
			exit(EX_CONFIG);
		}
		if (-1 == (fdFeed = divConnect(pcEncl, RightsWrap, (void *)0)) || 1 > read(fdFeed, acEnvName, sizeof(acEnvName))) {
			fprintf(stderr, "%s: -O: %s: connect: %s\n", progname, pcEncl, strerror(errno));
			exit(EX_UNAVAILABLE);
		}
		(void)ReWrite(fdFeed, "o1 \000ex ", 8);
		iLen = sizeof(acEnvName);
		if (-1 == RightsRecvFd(fdFeed, &fdPriv, 1, acEnvName, &iLen)) {
			fprintf(stderr, "%s: -O: %s: failed to send rights\n", progname, pcEncl);
			exit(EX_TEMPFAIL);
		}
		if (fTerminate) {
			(void)ReWrite(fdFeed, "Q! ", 4);
		}
	} else {
		fdPriv = NewChannel(pcPriv, 1, environ, "-O");
	}
	/* Under (-r) and -v at least we carp here if there is no notify
	 * stream.  Might we should in any case, but for "be liberal".
	 */
	if (-1 == fdNotify && (fExit2 || fStartup)) {
		if (-1 == (fdNotify = open(acDevNull, O_WRONLY, 0666))) {
			fprintf(stderr, "%s: -N: open: %s: %s\n", progname, acDevNull, strerror(errno));
			exit(EX_USAGE);
		}
		(void)fcntl(fdNotify, F_SETFD, 1);
		if (fVerbose) {
			fprintf(fpVerbose, "%s: -r or -A set without -N, nofications sent to %s\n", progname, acDevNull);
		}
	} else if (fStartup) {
		i = strlen(pcSocket);
		if (isatty(fdNotify))
			pcSocket[i] = '\n';
		if (-1 == write(fdNotify, pcSocket, i+1))
			fprintf(stderr, "%s: write: %d: %s\n", progname, fdNotify, strerror(errno));
		pcSocket[i] = '\000';
	}
	if ((char *)0 == pcExec) {
		wInfExits = EX_OK;
		if (-1 == wInferior)
			wInferior = getpid();
		PumpLikeMad(fdOrigIn, fdListen, fdPriv, fdWidow, fdNotify, 1);
	} else if (fReplaceOrigIn && ResetInput(pcForcedIn, 0, environ, "-i")) {
		fprintf(stderr, "%s: -i: %s: %s\n", progname, pcForcedIn, strerror(errno));
		exit(EX_OSERR);
	} else if (-1 == (wInferior = CredPipeFit("cmd", pcExec, argv, environ, 0))) {
		exit(EX_OSERR);
	} else {
		PumpLikeMad(fdOrigIn, fdListen, fdPriv, fdWidow, fdNotify, 0);
	}
	if (-1 != fdNotify && -1 == close(fdNotify)) {
		fprintf(stderr, "%s: -N: close: %d: %s\n", progname, fdNotify, strerror(errno));
	}
	if (-1 == close(fdWidow)) {
		fprintf(stderr, "%s: -W close: %d: %s\n", progname, fdWidow, strerror(errno));
	}
	if (-1 == close(fdPriv)) {
		fprintf(stderr, "%s: -O: close: %d: %s\n", progname, fdPriv, strerror(errno));
	}
	if (-1 != fdFeed && -1 == close(fdFeed)) {
		fprintf(stderr, "%s: -O %s: close: %d: %s\n", progname, pcEncl, fdPriv, strerror(errno));
	}

	/* Cleanup, we must wait for all our kids, this does assume that any
	 * adopted children (fork'd before we execve'd) are really part of
	 * our same task.  That's not a big stretch, given my indiscretions.
	 */
	(void)unlink(pcSocket);
	fInfOpts = 0;		/* wait for all kids now */
	Death('M');
	if ((char *)0 == pcParent && (char *)0 != pcWorkSpace) {
		(void)rmdir(pcWorkSpace);
	}
	exit(wInfExits);
}

/* Output a nifty header above (rule below) the output stream		(ksb)
 * We could allow the command line passed to the client as %1, %2...
 * and %# for the count of arguments.  Then we'd have to add the mixer and
 * dicer and it would spin out of control.  Use xapply -e var=dicer to send
 * what you want in an environment variable, get that with %{var}.
 */
static int
Banner(fdOut, pcTemplate, pcWho, pcCount)
int fdOut;
char *pcTemplate, *pcWho, *pcCount;
{
	register char *pcMem, *pcEnv;
	register int iMax, i, iEscape, fNl, iRet;

	if ((char *)0 == pcTemplate || '\000' == *pcTemplate) {
		return 0;
	}
	if ((char *)0 == pcWho || '\000' == *pcWho) {
		pcWho = "?";
	}
	if ((char *)0 == pcCount || '\000' == *pcCount) {
		pcCount = "00";
	}

	/* The max expansion is max(len($Who), len($Count)) * number-of-%
	 * plus the lenght of the template string itself.
	 */
	i = strlen(pcWho);
	iMax = strlen(pcCount);
	if (iMax < i) {
		iMax = i;
	}
	for (iEscape = i = 0; '\000' != pcTemplate[i]; ++i) {
		if (cEsc == pcTemplate[i])
			++iEscape;
	}
	iMax *= iEscape;
	iMax += strlen(pcTemplate)+1; /* +1 for the '\n' we add */
	iMax |= 15;
	pcMem = calloc(iMax+1, sizeof(char));

	fNl = 1;
	iRet = 0;
	for (i = 0; '\000' != *pcTemplate; ++pcTemplate) {
		if (cEsc != (pcMem[i] = *pcTemplate)) {
			++i;
			continue;
		}
		if (cEsc == *++pcTemplate) {
			pcMem[i++] = cEsc;
			continue;
		}
		switch (*pcTemplate) {
		case 'x':	/* our xid */
			(void)strcpy(pcMem+i, pcWho);
			i += strlen(pcWho);
			continue;
		case 'u':	/* undocumented alias for %s		*/
		case 's':	/* our position in the sequence		*/
			(void)strcpy(pcMem+i, pcCount);
			i += strlen(pcCount);
			continue;
		case '{':	/*} %{ENV} adds $ENV to banner		*/
			iRet += ReWrite(fdOut, pcMem, i);
			i = 0; /*{*/
			while ('}' != pcTemplate[1] && '\000' != pcTemplate[1]) {
				pcMem[i++] = *++pcTemplate;
			} /*{*/
			if ('}' == pcTemplate[1]) {
				++pcTemplate;
			}
			pcMem[i] = '\000';
			if ((char *)0 == (pcEnv = getenv(pcMem))) {
				fprintf(stderr, "%s: %s: $%s: not in the environment\n", progname, pcWho, pcMem);
			} else {
				iRet += ReWrite(fdOut, pcEnv, strlen(pcEnv));
			}
			i = 0;
			continue;
		case '\000':	/* suppress trailing newline */
			fNl = 0;
			break;
		case '0':	/* "" (all expanders in xapply's chain do) */
			continue;
		default:
			++i;
			break;
		}
		break;
	}
	if (fNl) {
		pcMem[i++] = '\n';
	}
	return iRet + ReWrite(fdOut, pcMem, i);
}

/* Our stdin is a stream we want to send to a parent xclate's		(ksb)
 * managed stream.
 *	select a mode,  input-pump or no-pump
 *		input pump we buffer stdin for the process (1)
 *		no-pump we can't (2)
 *	find the master's divsrsion service and
 *	connect to the approriate xclate unix domain socket
 *	request a list of fd's from the master (honor -w, -E, -I)
 *	select for message from master or stdin
 *		read from stdin if we can and have buffer space
 *		read on the master fd to get our name, and new stdout
 *	pump buffered stdin to the locked stdout
 *	close the locked stdout
 *	report our child's exit code
 *	close the socket to the parrent to let the next stream go
 *	exit clean
 */
static void
Stream(pcWho, argc, argv)
char *pcWho;
int argc;
char **argv;
{
#define MODE_FILTER	1 /* inferior is pushed on stdin		 */
#define MODE_POPEN	2 /* push inferior on stdout pipe		 */
#define MODE_PROCESS	3 /* only parent the utility child process	 */
#define MODE_SQUEEZE	4 /* change to FITLER after req. fds aquired	 */
	extern char **environ;
	static char acUtility[] = "utility";
	register int cc;
	register char *pcBuffer, *pcNl;
	register unsigned int uiMax, uiHolding, uMode;
	auto char *pcUnix, *pcExec;
	auto size_t iNew;
	auto int fdFeed, fdMax;
	auto int fdNewIn, fdNewOut, fdNewErr, fdNewPWD;
	auto char acOurXid[MAX_XID_LEN+4];
	auto char acMessage[512 > MAX_XID_LEN+4 ? 512 : MAX_XID_LEN+4];
	auto char acServProt[32];	/* n.m\000 */
	auto PPM_BUF PPM;
	auto fd_set fdsTemp, fdsReading;
	auto pid_t wTemp;

	/* Make sure 0, 1, 2 are open :-(, don't mess with me, kid.
	 */
	while (-1 != (fdMax = open(acDevNull, O_RDWR, 0666))) {
		if (fdMax > 2)
			break;
	}
	if (-1 == fdMax) {
		fprintf(stderr, "%s: open: %s: %s\n", progname, acDevNull, strerror(errno));
		exit(EX_OSERR);
	}
	close(fdMax);

	pcExec = (char *)0;
	if (0 != argc && (char *)0 == (pcExec = FindBin(argv[0]))) {
		fprintf(stderr, "%s: %s: cannot locate in $PATH\n", progname, argv[0]);
		exit(EX_CONFIG);
	}

	uiHolding = 0;
	uiMax = PIPE_SIZE*2;
	(void)util_ppm_init(&PPM, sizeof(char), uiMax);
	if ((char *)0 == (pcUnix = pcMaster)) {
		pcUnix = divSelect();
	}
	if ((char *)0 == pcUnix) {
		if (0 != argc) {
			exit(EX_DATAERR);
		}
		pcBuffer = (char *)util_ppm_size(&PPM, uiMax);
		while (0 < (cc = read(0, pcBuffer, uiMax))) {
			ReWrite(1, pcBuffer, cc);
		}
		exit(EX_DATAERR);
	}

	if ((char *)0 == pcWho) {
		if ((char *)0 == (pcWho = calloc(MAX_PID_LEN, sizeof(char)))) {
			fprintf(stderr, "%s: calloc: %d: %s\n", progname, MAX_PID_LEN, strerror(errno));
			exit(EX_OSERR);
		}
		snprintf(pcWho, MAX_PID_LEN, "%ld", (long int)getpid());
	}
	if (MAX_XID_LEN <= strlen(pcWho)) {
		fprintf(stderr, "%s: xid: %s: too long, max length %d\n", progname, pcWho, MAX_XID_LEN-1);
		exit(EX_CANTCREAT);
	}
	if (-1 == (fdFeed = divConnect(pcUnix, RightsWrap, (void *)0))) {
		fprintf(stderr, "%s: %s: client: %s\n", progname, pcUnix, strerror(errno));
		exit(EX_NOINPUT);
	}
	if (1 > read(fdFeed, acServProt, sizeof(acServProt))) {
		fprintf(stderr, "%s: %s: dropped us\n", progname, pcUnix);
		exit(EX_NOINPUT);
	}
	if (0 != strcmp(acServProt, acProto) && fVerbose) {
		fprintf(fpVerbose, "%s: %s: protocol mismatched (local \"%s\", remote \"%s\")\n", progname, pcUnix, acProto, acServProt);
	}
	ReWrite(fdFeed, pcWho, strlen(pcWho)+1);
	if (0 >= read(fdFeed, acOurXid, sizeof(acOurXid))) {
		fprintf(stderr, "%s: %s: lost enclosing diversion (%s)\n", progname, pcUnix, strerror(errno));
		exit(EX_PROTOCOL);
	}
	if ((char *)0 != (pcNl = strchr(acOurXid, '\n'))) {
		*pcNl = '\000';
	}

	/* If we don't have -H, -T, or -L set ask the master diversion for them,
	 * but never overrule an explict empty string from our command-line.
	 */
	if ((char *)0 == pcTitle) {
		ReWrite(fdFeed, "?T ", 4);
		pcTitle = CatchString(fdFeed);
	}
	if ((char *)0 == pcHorizRule) {
		ReWrite(fdFeed, "?H ", 4);
		pcHorizRule = CatchString(fdFeed);
	}
	if (!fGaveL) {
		auto size_t wTmp;
		ReWrite(fdFeed, "?L ", 4);
		if (0 != CatchWord(fdFeed, &wTmp) && 0 < wTmp) {
			uiLimit = wTmp;
		}
	}
	/* If we don't have -s set, ask the master believe her if she does.
	 * Under -q & ~-s, set -s when no title or hr specified, as is common.
	 */
	if (!fSqueeze) {
		ReWrite(fdFeed, "?s ", 4);
		if (2 != read(fdFeed, acMessage, 2)) {
			fprintf(stderr, "%s: ?s: %s: short reply\n", progname, pcUnix);
			exit(EX_PROTOCOL);
		}
		fSqueeze = ('s' == acMessage[0]);
	}
	if (!fAllowQuick) {
		ReWrite(fdFeed, "?q ", 4);
		if (2 != read(fdFeed, acMessage, 2)) {
			fprintf(stderr, "%s: ?q: %s: short reply\n", progname, pcUnix);
			exit(EX_PROTOCOL);
		}
		fAllowQuick = ('q' == acMessage[0]);
	}
	if (fAllowQuick && !fSqueeze && ((char *)0 == pcHorizRule || '\000' == pcHorizRule[0]) && ((char *)0 == pcTitle || '\000' == pcTitle[0])) {
		fSqueeze = 1;
	} else {
		fAllowQuick = 0;
	}
	/* -s (SQUEEZE) forces a FILTER mode, as soon as we safely can {we
	 * may have to aquire a new stdin first, if we were to be a PROCESS}.
	 *
	 * With no utility:	utility | $progname [-sw] $xid
	 * tactic FILTER (in -> collated-output)
	 *	utility | $progname -> collated-output
	 *
	 * With -s:	source | $progname [-{I|E|D}][wY] $xid utility
	 * tactic SQUEEZE (locked-in -> child-utility -> collated-output)
	 *	utility | $progname -> collated-output
	 * with -IED we must wait for the lock to push the utility on stdin
	 *
	 * With no -IED:	source | $progname -{I|E|D}[wY] $xid utility
	 * tactic POPEN (in -> util -> collated-output)
	 *	* -> $progname | utility -> collated-output
	 *
	 * With -IED:		$progname $xid -{I|E|D}[wY] utility
	 * tactic PROCESS (aquire and fork)
	 *	$progname hold collated-output
	 *	locked-in -> child-utility -> collated-output
	 */
	if (0 == argc) {
		uMode = MODE_FILTER;
		if (fAskStdin || fAskStderr || fAskPWD) {
			fprintf(stderr, "%s: no %s given, turn off -I, -E, -D\n", progname, acUtility);
		}
		fAskStdin = fAskStderr = fAskPWD = 0;
	} else if (fSqueeze) {
		uMode = MODE_SQUEEZE;
	} else {
		uMode = fAskStdin ? MODE_PROCESS : MODE_POPEN;
	}

	/* negotiate for the rights we need
	 */
	if (fAskStdin) {
		ReWrite(fdFeed, "o0 ", 4);
	}
	if (fAskStderr) {
		ReWrite(fdFeed, "o2 ", 4);
	}
	if (fAskStderr || fAskStdin || !fWeeping) {
		ReWrite(fdFeed, "o1 ", 4);
	}
	if (fAskPWD) {
		auto int fdRecv;

		ReWrite(fdFeed, "od ", 4);
		iNew = sizeof(acMessage)-1;
		if (-1 == RightsRecvFd(fdFeed, &fdRecv, 1, acMessage, &iNew)) {
			exit(EX_OSERR);
		}
		fdNewPWD = fdRecv;
		(void)fcntl(fdNewPWD, F_SETFD, 1);
	} else {
		fdNewPWD = -1;
	}

	/* If we are in squeeze mode we might be able to _never_ block
	 * on the exclusive out (xapply does this a lot).
	 */
	FD_ZERO(& fdsReading);
	FD_SET(fdFeed, &fdsReading);
	if (MODE_SQUEEZE == uMode && !fAskStderr && !fAskStdin) {
		register int iGot;
		auto int fdBack = -1;

		if (fAskPWD) {
			if (-1 == (fdBack = open(".", O_RDONLY, 0))) {
				(void)fcntl(fdBack, F_SETFD, 1);
			}
			if (-1 == fchdir(fdNewPWD)) {
				fprintf(stderr, "%s: fchdir: %s\n", progname, strerror(errno));
				exit(EX_OSERR);
			}
			(void)close(fdNewPWD);
			fAskPWD = 0;
		}
		wInferior = CredPipeFit(acUtility, pcExec, argv, environ, 0);
		argc = 0;
		uMode = MODE_FILTER;
		if (-1 != fdBack) {
			(void)fchdir(fdBack);
			/* EACCESS is bad: we could have been started from
			 * a directory we can't get back to, but we keep on.
			 */
			(void)close(fdBack);
		}
		pcBuffer = (char *)util_ppm_size(&PPM, PIPE_SIZE);
		iGot = read(0, pcBuffer, PIPE_SIZE);
		/* If she exited w/o any output, just report her status,
		 * but wait for all our kids first.
		 */
		if (1 > iGot) {
			fInfOpts = 0;
			Death('S');
			goto squeezed;
		}
		uiHolding = iGot;
		(void)ReWrite(fdFeed, "hd ", 4);
		fSqueeze = 0;
	}
	switch (uMode) {
	case MODE_PROCESS:
	case MODE_SQUEEZE:
		(void)ReWrite(fdFeed, "ex ", 4);
		break;
	case MODE_FILTER:
	case MODE_POPEN:
		/* We'll the diversion more tell in the loop below
		 */
		if (uiHolding < uiLimit) {
			FD_SET(0, &fdsReading);
		}
		break;
	default:
		break;
	}
	fdMax = fdFeed;
	fdNewIn = fdNewErr = -1;
	for (fdNewOut = -1; (!fWeeping && -1 == fdNewOut) || (fAskStdin && -1 == fdNewIn) || (fAskStderr && -1 == fdNewErr); /*nada*/) {
		register int iGot;
		auto int fdRecv;

		fdsTemp = fdsReading;
		if (-1 == (iGot = select(fdMax+1, &fdsTemp, (fd_set *)0, (fd_set *)0, (struct timeval *)0))) {
			if (EINTR == errno)
				continue;
			fprintf(stderr, "%s: select: %s\n", progname, strerror(errno));
			break;
		}

		/* Unblock our data-source, if we can read from her. If she
		 * finishes first we might change things... if she never
		 * gives data and never closes we just wait forever.
		 */
		if (FD_ISSET(0, &fdsTemp)) {
			if (uiHolding+PIPE_SIZE > uiMax) {
				uiMax += PIPE_SIZE;
			}
			pcBuffer = (char *)util_ppm_size(&PPM, uiMax);
			iGot = read(0, pcBuffer+uiHolding, PIPE_SIZE);

			/* A filter ended with no output, don't get a lock,
			 * just fall out all the way to the wait.
			 */
			if (fSqueeze && MODE_FILTER == uMode && 0 >= iGot && 0 == uiHolding) {
				fWeeping = 0;
				fdNewPWD = fdNewOut = fdNewErr = -1;
				FD_CLR(0, &fdsReading);
				break;
			}
			/* A filter ended with some data, optimize if we can
			 * if we can find exit code go for the "quick" buffer
			 * in the parent process.
			 */
			if (0 >= iGot) {
				fInfOpts = 0;
				Death('?');
				if (0 == wInferior) {
					snprintf(acMessage, sizeof(acMessage), "%03d", (int)wInfExits);
					(void)ReWrite(fdFeed, acMessage, 4);
					(void)ReWrite(fdFeed, "qm ", 4);
				} else if (MODE_FILTER == uMode) {
					(void)ReWrite(fdFeed, "rf ", 4);
				} else if (MODE_POPEN == uMode) {
					(void)ReWrite(fdFeed, "ex ", 4);
				}
				FD_CLR(0, &fdsReading);
				if (MODE_FILTER == uMode) {
					fSqueeze = 0;
				}
				continue;
			}
			if (0 == uiHolding && MODE_FILTER == uMode) {
				fSqueeze = 0;
				(void)ReWrite(fdFeed, "hd ", 4);
			}
			uiHolding += iGot;
			/* When we fill the buffer, stop polling stdin
			 */
			if (uiHolding >= uiLimit) {
				FD_CLR(0, &fdsReading);
				(void)ReWrite(fdFeed, "bx ", 4);
			}
		}

		/* We have new mail, could be any of those we requested
		 */
		if (-1 == fdFeed || !FD_ISSET(fdFeed, &fdsTemp)) {
			continue;
		}
		iNew = sizeof(acMessage)-1;
		if (-1 == RightsRecvFd(fdFeed, &fdRecv, 1, acMessage, &iNew)) {
			/* We might recover -- output to our original
			 * stdout?  I think this is NOT good idea.
			 */
			exit(EX_PROTOCOL);
		}
		acMessage[sizeof(acMessage)-1] = '\000';
		if ((char *)0 != (pcNl = strchr(acMessage, '\n'))) {
			*pcNl = '\000';
		}
		/* When we want stderr, stdin, or widows we need to
		 * have more logic here;
		 *   /out/	collated stdout, our sequence # or
		 *   /in/	manager's stdin
		 *   /err/	manager's stderr
		 *   /quick/	send your output to the master
		 */
		if ('o' == acMessage[0]) {
			fdNewOut = fdRecv;
			continue;
		}
		if ('e' == acMessage[0]) {
			fdNewErr = fdRecv;
			continue;
		}
		if ('i' == acMessage[0]) {
			fdNewIn = fdRecv;
			continue;
		}
		if ('q' == acMessage[0]) {
			pcBuffer = (char *)util_ppm_size(&PPM, uiMax);
			Banner(fdFeed, pcTitle, pcWho, acOurXid);
			ReWrite(fdFeed, pcBuffer, uiHolding);
			Banner(fdFeed, pcHorizRule, pcWho, acOurXid);
			close(fdFeed);
			exit(EX_OK);
		}
		/* how did we get here?
		 */
		fprintf(stderr, "%s: %s: protocol error, v%s\n", progname, acMessage, acProto);
		exit(EX_PROTOCOL);
	}
	/* We don't need the collated stream, get the widows
	 */
	if (fWeeping) {
		if (-1 != fdNewOut) {
			close(fdNewOut);
			fdNewOut = -1;
		}
		ReWrite(fdFeed, "ow ", 4);
		iNew = sizeof(acMessage)-1;
		if (-1 == RightsRecvFd(fdFeed, &fdNewOut, 1, acMessage, &iNew)) {
			exit(EX_OSERR);
		}
		/* assert('w' != acMessage[0]); */
	}
	if (fTerminate) {
		(void)ReWrite(fdFeed, "Q! ", 4);
	}

	/* move the desciptors requests into place
	 */
	if (-1 != fdNewErr && 2 != fdNewErr) {
		fflush(stderr);
		close(2);
		dup(fdNewErr);
		close(fdNewErr);
		fdNewErr = -1;
	}
	if (-1 != fdNewOut && 1 != fdNewOut) {
		fflush(stdout);
		close(1);
		dup(fdNewOut);
		(void)fcntl(fdNewOut, F_SETFD, 1);
	}
	if (-1 != fdNewIn && 0 != fdNewIn) {
		close(0);
		dup(fdNewIn);
		close(fdNewIn);
		fdNewIn = -1;
	}
	if (-1 != fdNewPWD) {
		if (-1 == fchdir(fdNewPWD)) {
			fprintf(stderr, "%s: fchdir: %d: %s\n", progname, fdNewPWD, strerror(errno));
			exit(EX_OSERR);
		}
		(void)close(fdNewPWD);
		fdNewPWD = -1;
	}
	/* sshw wants this, I'm sure
	 */
	if (fNewTTY) {
		register int fdTty;
#if defined(TIOCNOTTY)
		register char *pcTty;
#endif

		fdTty = (-1 != fdNewIn && isatty(fdNewIn)) ? fdNewIn : (-1 != fdNewOut && isatty(fdNewOut)) ? fdNewOut : isatty(fdNewErr) ? fdNewErr : -1;
		if (-1 == fdTty) {
			/* nada, we don't have a new controlling tty */
		} else if (-1 == setsid()) {
			/* we can't get free of the old one, sigh */
#if defined(TIOCSCTTY)
		/* try the "new way" if we have it */
		} else if (-1 != ioctl(fdTty, TIOCSCTTY, (char *)0)) {
			/* we win, I guess */
#endif
#if defined(TIOCNOTTY)
		} else if ((char *)0 != (pcTty = ttyname(fdTty))) {
			register int i;

			if (-1 != (i = open("/dev/tty", O_RDWR, 0666))) {
				(void)ioctl(i, TIOCNOTTY, (char *)0);
				(void)close(i);
			}
			/* try to pick it up from an open, old school */
			(void)close(open(pcTty, O_RDWR, 0666));
#else
		} else {
			/* I don't know what else to try -- ksb */
#endif
		}
	}
	if (!fSqueeze) {
		Banner(fdNewOut, pcTitle, pcWho, acOurXid);
		pcTitle = (char *)0;
	}
	wTemp = -1;
	switch (uMode) {
	case MODE_FILTER:
		/* already running and humming, or exited */
		break;
	case MODE_PROCESS:
		if (fVerbose) {
			fprintf(fpVerbose, "%s: %s", progname, acUtility);
			for (cc = 0; (char *)0 != argv[cc]; ++cc) {
				fprintf(fpVerbose, " %s", argv[cc]);
			}
			fprintf(fpVerbose, "\n");
			fflush(fpVerbose);
		}
		for (;;) { switch (wTemp = fork()) {
		case -1:
			/* sadly we are in major trouble here, but
			 * we might continue here someday for fork again
			 */
			fprintf(stderr, "%s: fork: %s\n", progname, strerror(errno));
			exit(EX_OSERR);
		case 0:
			execvp(pcExec, argv);
			execve(pcExec, argv, environ);
			fprintf(stderr, "%s: execve: %s: %s\n", progname, pcExec, strerror(errno));
			exit(EX_CONFIG);
		default:
			break;
		} break; }
		break;
	case MODE_SQUEEZE:
		wTemp = CredPipeFit(acUtility, pcExec, argv, environ, 0);
		uMode = MODE_FILTER;
		break;
	case MODE_POPEN:
		wTemp = CredPipeFit(acUtility, pcExec, argv, environ, 1);
		break;
	}
	if ((pid_t)-1 != wInferior && (pid_t)-1 != wTemp) {
		wInferior = wTemp;
	}

	/* If we can't read at least 1 charactrer from stdin, squeeze it out
	 * (we are certian that we are in filter mode since fSqueeze is set).
	 */
	if (fSqueeze && 1 > uiHolding) {
		register int iGot;

		pcBuffer = (char *)util_ppm_size(&PPM, PIPE_SIZE);
		iGot = read(0, pcBuffer, PIPE_SIZE);
		if (0 < iGot) {
			uiHolding = iGot;
		}
		if (0 == uiHolding) {
			fInfOpts = 0;
			Death('s');
			goto squeezed;
		}
		Banner(fdNewOut, pcTitle, pcWho, acOurXid);
		pcTitle = (char *)0;
		fSqueeze = 0;
	}

	/* Resume stdin pump, even if we filled the buffer capacity.
	 */
	if (uiHolding > 0 || FD_ISSET(0, &fdsReading)) {
		pcBuffer = (char *)util_ppm_size(&PPM, PIPE_SIZE);
		cc = ReWrite(1, pcBuffer, uiHolding);
		if (-1 == cc) {
			exit(EX_OSERR);
		}
		/* I've seen us get hung here, how?
		 */
		while (0 < (cc = read(0, pcBuffer, uiMax))) {
			ReWrite(1, pcBuffer, cc);
		}
		close(0);
		(void)open(acDevNull, O_RDONLY, 0666);
	}
	close(1);
	(void)open(acDevNull, O_RDWR, 0666);
	fInfOpts = 0;		/* wait for all kids now */
	Death('b');
	if (!fSqueeze) {
		Banner(fdNewOut, pcHorizRule, pcWho, acOurXid);
		pcHorizRule = (char *)0;
	}
	close(fdNewOut);

	/* After the code (three digits and a \000) we might send
	 * "cq \000" here, but we don't need it, the close is enough.
	 */
 squeezed:
	if (0 != wInfExits) {
		snprintf(acMessage, sizeof(acMessage), "%03d", (int)wInfExits);
		(void)ReWrite(fdFeed, acMessage, 4);
	}
	close(fdFeed);
	exit(EX_OK);
}
/* from std_help.m */
/* from std_version.m */
/* from util_divstack.m */
/* from util_divconnect.m */
/* from util_errno.m */
/* from util_sigret.m */
/* from util_ppm.m */
#line 28 "util_ppm.m"
/* init a PPM, let me know how big each element is			(ksb)
 * and about how many to allocate when we run out, or pick 0 for
 * either and well guess at the other.
 */
PPM_BUF *
util_ppm_init(PPM_BUF *pPPM, unsigned int uiWidth, unsigned int uiBlob)
{
	register unsigned int iTemp;

	if ((PPM_BUF *)0 == pPPM)
		return (PPM_BUF *)0;
	pPPM->uimax = 0;
	pPPM->pvbase = (void *)0;

	pPPM->uiwide = uiWidth ? uiWidth : 1 ;
	iTemp = pPPM->uiwide < 2048 ? 8191-3*pPPM->uiwide : 1024*13-1;
	pPPM->uiblob = uiBlob ? uiBlob : (iTemp/pPPM->uiwide | 3)+1;
	return pPPM;
}

/* resize this buffer and return the new base address.			(ksb)
 * When we fail to resize we do NOT release the previous buffer.
 */
void *
util_ppm_size(PPM_BUF *pPPM, unsigned int uiCount)
{
	register unsigned int uiRound;
	register void *pvRet;

	if ((PPM_BUF *)0 == pPPM) {
		return (void *)0;
	}
	if (pPPM->uimax >= uiCount) {
		return pPPM->pvbase;
	}
	uiRound = uiCount / pPPM->uiblob;
	uiRound *= pPPM->uiblob;

	/* this could overflow, but we can't fix that
	 */
	if (uiRound < uiCount) {
		uiRound += pPPM->uiblob;
	}
	uiCount = uiRound;
	uiRound *= pPPM->uiwide;

	if ((void *)0 == pPPM->pvbase) {
		pvRet = (void *)malloc(uiRound);
	} else {
		pvRet = (void *)realloc(pPPM->pvbase, uiRound);
	}
	if ((void *)0 != pvRet) {
		pPPM->pvbase = pvRet;
		pPPM->uimax = uiCount;
	}
	return pvRet;
}

/* frees the present buffer, but doesn't forget the init		(ksb)
 */
void
util_ppm_free(PPM_BUF *pPPM)
{
	if ((PPM_BUF *)0 == pPPM) {
		return;
	}
	if (0 != pPPM->uimax && (void *)0 != pPPM->pvbase) {
		free(pPPM->pvbase);
		pPPM->pvbase = (void *)0;
	}
	pPPM->uimax = 0;
}

#if defined(DEBUG)
/* for debugging							(ksb)
 */
int
util_ppm_print(PPM_BUF *pPPM, FILE *fpOut)
{
	fprintf(fpOut, "ppm %p", (void *)pPPM);
	if ((PPM_BUF *)0 == pPPM) {
		fprintf(fpOut, " <is NULL>\n");
		return 0;
	}
	fprintf(fpOut, ": <max %u, width %u, blob %u> base %p\n", pPPM->uimax, pPPM->uiwide, pPPM->uiblob, pPPM->pvbase);
	return 1;
}
#endif
/* from util_tmp.m */
/* from util_pipefit.m */
/* from util_fsearch.m */
/* from hosttype.m */
/* from std_control.m */
/* from util_home.m */
/* from bytes.m */
/* from util_mult.m */

#line 1 "getopt.mc"
/* $Id: getopt.mc,v 8.13 2004/09/01 15:26:37 ksb Exp $
 * Based on Keith Bostic's getopt in comp.sources.unix volume1
 * modified for mkcmd use by ksb@fedex.com (Kevin S Braunsdorf).
 */

#if 1 || 0
/* breakargs - break a string into a string vector for execv.
 *
 * Note, when done with the vector, merely "free" the vector.
 * Written by Stephen Uitti, PUCC, Nov '85 for the new version
 * of "popen" - "nshpopen", that doesn't use a shell.
 * (used here for the as filters, a newer option).
 *
 * breakargs is copyright (C) Purdue University, 1985
 *
 * Permission is hereby given for its free reproduction and
 * modification for All purposes.
 * This notice and all embedded copyright notices be retained.
 */

/* this trys to emulate shell quoting, but I doubt it does a good job	(ksb)
 * [[ but not substitution -- that would be silly ]]
 */
#if 0
static char *u_mynext(register char *u_pcScan, char *u_pcDest)
#else
static char *
u_mynext(u_pcScan, u_pcDest)
register char *u_pcScan, *u_pcDest;
#endif
{
	register int u_fQuote;

	for (u_fQuote = 0; *u_pcScan != '\000' && (u_fQuote||(*u_pcScan != ' ' && *u_pcScan != '\t')); ++u_pcScan) {
		switch (u_fQuote) {
		default:
		case 0:
			if ('"' == *u_pcScan) {
				u_fQuote = 1;
				continue;
			} else if ('\'' == *u_pcScan) {
				u_fQuote = 2;
				continue;
			}
			break;
		case 1:
			if ('"' == *u_pcScan) {
				u_fQuote = 0;
				continue;
			}
			break;
		case 2:
			if ('\'' == *u_pcScan) {
				u_fQuote = 0;
				continue;
			}
			break;
		}
		if ((char*)0 != u_pcDest) {
			*u_pcDest++ = *u_pcScan;
		}
	}
	if ((char*)0 != u_pcDest) {
		*u_pcDest = '\000';
	}
	return u_pcScan;
}

/* given an envirionment variable insert it in the option list		(ksb)
 * (exploded with the above routine)
 */
#if 0
static int u_envopt(char *cmd, int *pargc, char *(**pargv))
#else
static int
u_envopt(cmd, pargc, pargv)
char *cmd, *(**pargv);
int *pargc;
#endif
{
	register char *p;		/* tmp				*/
	register char **v;		/* vector of commands returned	*/
	register unsigned sum;		/* bytes for malloc		*/
	register int i, j;		/* number of args		*/
	register char *s;		/* save old position		*/

	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	p = cmd;			/* no leading spaces		*/
	i = 1 + *pargc;
	sum = sizeof(char *) * i;
	while (*p != '\000') {		/* space for argv[];		*/
		++i;
		s = p;
		p = u_mynext(p, (char *)0);
		sum += sizeof(char *) + 1 + (unsigned)(p - s);
		while (*p == ' ' || *p == '\t')
			p++;
	}
	++i;
	/* vector starts at v, copy of string follows nil pointer
	 * the extra 7 bytes on the end allow use to be alligned
	 */
	v = (char **)malloc(sum+sizeof(char *)+7);
	if ((char **)0 == v)
		return 0;
	p = (char *)v + i * sizeof(char *); /* after nil pointer */
	i = 0;				/* word count, vector index */
	v[i++] = (*pargv)[0];
	while (*cmd != '\000') {
		v[i++] = p;
		cmd = u_mynext(cmd, p);
		p += strlen(p)+1;
		while (*cmd == ' ' || *cmd == '\t')
			++cmd;
	}
	for (j = 1; j < *pargc; ++j)
		v[i++] = (*pargv)[j];
	v[i] = (char *)0;
	*pargv = v;
	*pargc = i;
	return i;
}
#endif /* u_envopt called */

#if 0 || 0
/*
 * return each non-option argument one at a time, EOF for end of list
 */
#if 0
static int u_getarg(int nargc, char **nargv)
#else
static int
u_getarg(nargc, nargv)
int nargc;
char **nargv;
#endif
{
	if (nargc <= u_optInd) {
		u_optarg = (char *)0;
		return EOF;
	}
	u_optarg = nargv[u_optInd++];
	return 0;
}
#endif /* u_getarg called */


#if 1 || 0
/* get option letter from argument vector, also does -number correctly
 * for nice, xargs, and stuff (these extras by ksb)
 * does +arg if you give a last argument of "+", else give (char *)0
 * alos does xargs -e if spec'd as "e::" -- not sure I like that at all,
 * but it is the most often asked for extension (rcs's -t option also).
 */
#if 0
static int u_getopt(int nargc, char **nargv, char *ostr, char *estr)
#else
static int
u_getopt(nargc, nargv, ostr, estr)
int nargc;
char **nargv, *ostr, *estr;
#endif
{
	register char	*oli;		/* option letter list index	*/
	static char	EMSG[] = "";	/* just a null place		*/
	static char	*place = EMSG;	/* option letter processing	*/

	/* when we have no optlist, reset the option scan
	 */
	if ((char *)0 == ostr) {
		u_optInd = 1;
		place = EMSG;
		return EOF;
	}
	if ('\000' == *place) {		/* update scanning pointer */
		if (u_optInd >= nargc)
			return EOF;
		if (nargv[u_optInd][0] != '-') {
			register int iLen;
			if ((char *)0 != estr && 0 == strncmp(estr, nargv[u_optInd], iLen = strlen(estr))) {
				u_optarg = nargv[u_optInd++]+iLen;
				return '+';
			}
			return EOF;
		}
		place = nargv[u_optInd];
		if ('\000' == *++place)	/* "-" (stdin)		*/
			return EOF;
		if (*place == '-' && '\000' == place[1]) {
			/* found "--"		*/
			++u_optInd;
			return EOF;
		}
	}				/* option letter okay? */
	/* if we find the letter, (not a `:')
	 * or a digit to match a # in the list
	 */
	if ((u_optopt = *place++) == ':' ||
	 ((char *)0 == (oli = strchr(ostr, u_optopt)) &&
	  (!(isdigit(u_optopt)|| '-' == u_optopt) || (char *)0 == (oli = strchr(ostr, '#'))))) {
		if(!*place) ++u_optInd;
		return '?';
	}
	if ('#' == *oli) {		/* accept as -digits, not "-" alone */
		u_optarg = place-1;
		while (isdigit(*place)) {
			++place;
		}
		if(!*place) ++u_optInd;
		return isdigit(place[-1]) ? '#' : '?';
	}
	if (':' != *++oli) {		/* don't need argument */
		u_optarg = (char *)0;
		if ('\000' == *place)
			++u_optInd;
	} else {				/* need an argument */
		if ('\000' != *place || ':' == oli[1]) {
			u_optarg = place;
		} else if (nargc <= ++u_optInd) {	/* no arg!! */
			place = EMSG;
			return '*';
		} else {
			u_optarg = nargv[u_optInd];	/* skip white space */
		}
		place = EMSG;
		++u_optInd;
	}
	return u_optopt;			/* dump back option letter */
}
#endif /* u_getopt called */
#line 1 "util_divstack.mc"
/* $Id: util_divstack.mc,v 1.12 2008/08/25 14:18:18 ksb Exp $
 */
static struct u_dsData {
	unsigned ulen;		/* the lenght of the longest temp string */
	char *pcprefix;		/* from progname or a fixed prefix	*/
	char *pcdiropt;		/* from %qrtL or the like		*/
	char *pcret;		/* space to return any a name		*/
} u_dsData;

/* return -1 for not possible, internal use only			(ksb)
 */
static int
div_setKey(const char *pcKey)
{
	if (0 == u_dsData.ulen) {
		errno = ENXIO;
		return -1;
	}
	snprintf(u_dsData.pcret, u_dsData.ulen, "%s_%s", u_dsData.pcprefix, pcKey);
	return 1;
}

/* Output the std version (-V) banner for our module			(ksb)
 */
void
divVersion(FILE *fpOut)
{
	register const char *pcLevel;
	auto char *pcEos;

	if ((const char *)0 != (pcLevel = divCurrent((char *)0))) {
		(void)strtol(pcLevel, & pcEos, 10);
		if (0 != strcmp(pcLevel, "d") && (pcEos == pcLevel || '\000' != *pcEos)) {
			fprintf(fpOut, "%s: cannot parse level string \"%s\"\n", progname, pcLevel);
		}
	}
	fprintf(fpOut, "%s: environment prefix \"%s\"\n", progname, "xcl");
	fprintf(fpOut, "%s: environment tags: \"link\", \"list\", \"d\", \"%s\"\n", progname, (const char *)0 == pcLevel ? "1" : pcLevel);
}

/* We need to remember the prefix, and the option spelling of		(ksb)
 * the direct option name.  We don't allocate a struct for this dynamically
 * because we've never needed two of them in any application.
 */
unsigned
divInit(const char *pcName, const char *pcSpec)
{
	register unsigned uLen = sizeof("link")+sizeof("list")+sizeof("d")+sizeof("%u")+0;

	/* We might put on an integer, usually 1 or 2 digits, allow 31, or
	 * the sum of all the suffixes we might put on.  So any'll fit.
	 */
	if (uLen < 32) {
		uLen = 32;
	}
	if ((char *)0 != u_dsData.pcprefix)
		free((void *)u_dsData.pcprefix);
	if ((char *)0 != u_dsData.pcdiropt)
		free((void *)u_dsData.pcdiropt);
	if ((char *)0 != u_dsData.pcret)
		free((void *)u_dsData.pcret);
	if ((char *)0 == pcName || '\000' == *pcName) {
		fprintf(stderr, "%s: null prefix name is invalid\\n", progname);
		exit(EX_DATAERR);
	}
	u_dsData.pcprefix = strdup(pcName);
	u_dsData.pcdiropt = (char *)0 != pcSpec ? strdup(pcSpec) : (char *)0;
	uLen += strlen(pcName);
	if (u_dsData.ulen >= uLen)
		return u_dsData.ulen;
	uLen |= 7;
	if ((char *)0 == (u_dsData.pcret = malloc(++uLen))) {
		fprintf(stderr, "%s: malloc: %u: %s\\n", progname, uLen, strerror(errno));
		exit(EX_OSERR);
	}
	return u_dsData.ulen = uLen;
}

/* Return the current diversion as a string, might be "d"		(ksb)
 */
char *
divCurrent(char *pcForce)
{
	register char *pcEnv;

	if (-1 == div_setKey("link")) {
		errno = ENXIO;
		return pcForce;
	}
	if ((char *)0 == (pcEnv = getenv(u_dsData.pcret))) {
		errno = ENOENT;
		return pcForce;
	}
	return pcEnv;
}

/* Return the diversion forced to be a number, if there is one.		(ksb)
 * -1 error, 0 not one (imply 0) or can't parse it, 1 a good found one
 */
int
divNumber(unsigned *puFound)
{
	register char *pcDiv;
	auto char *pcEos;

	*puFound = 0;
	if (0 == u_dsData.ulen) {
		errno = ENXIO;
		return -1;
	}
	if ((char *)0 == (pcDiv = divCurrent((char *)0))) {
		return 0;
	}
	*puFound = strtol(pcDiv, &pcEos, 10);
	return pcEos != pcDiv && '\000' == *pcEos;
}

/* Update the link value to the next diversion, install that value	(ksb)
 * -1 for error/failure, 0 for success (you can push a null to unset)
 * $us_2=pcNew, $us_link=2
 */
int
divPush(const char *pcNew)
{
	auto unsigned uEncl;
	auto char acLevel[(sizeof("%u")|3)+(1+32)];

	if (0 == u_dsData.ulen) {
		errno = ENXIO;
		return -1;
	}
	if (1 != divNumber(& uEncl)) {
		uEncl = 0;
	}
	snprintf(acLevel, sizeof(acLevel), "%u", ++uEncl);
	(void)div_setKey(acLevel);
	if ((const char *)0 == pcNew) {
		unsetenv(u_dsData.pcret);
		return 0;
	}
	if (-1 == setenv(u_dsData.pcret, pcNew, 1)) {
		return -1;
	}
	(void)div_setKey("link");
	return setenv(u_dsData.pcret, acLevel, 1);
}

/* Env out the detached diversion for a direct child (we thinkg)	(ksb)
 * -1 for error/failure, 0 for success, pass (cons char *)0 for the default
 * detached name ("d" in my programs):  $us_d=pcNew
 */
int
divDetach(const char *pcNew, const char *pcTag)
{
	if ((char *)0 == pcTag) {
		pcTag = "d";
	}
	if (-1 == div_setKey(pcTag)) {
		errno = ENXIO;
		return -1;
	}
	if ((const char *)0 == pcNew) {
		unsetenv(u_dsData.pcret);
		return 0;
	}
	return setenv(u_dsData.pcret, pcNew, 1);
}

/* Iterate through the diversions apply a function to each		(ksb)
 * In the order "d", top, top-1, ... 1, 0.  Where 0 is optional.
 */
int
divSearch(int (*pfi)(const char *pcName, const char *pcDirect, int fActive, void *pvData), void *pvData)
{
	register char *pcVal;
	register int iRet;
	register unsigned uActive;
	register const char *pcCur;
	auto unsigned uTop;
	auto char acLevel[(sizeof("%u")|3)+(1+32)];
	static const char acOOD[] = "d";

	if (-1 == div_setKey("link")) {
		errno = ENXIO;
		return -1;
	}
	pcCur = getenv(u_dsData.pcret);
	if (-1 == div_setKey(acOOD)) {
		errno = ENXIO;
		return -1;
	}
	if ((char *)0 != (pcVal = getenv(u_dsData.pcret)) && 0 != (iRet = (*pfi)(acOOD, pcVal, (const char *)0 != pcCur && 0 == strcmp(acOOD, pcCur), pvData))) {
		return iRet;
	}
	if ((char *)0 == pcCur || 1 != divNumber(& uTop)) {
		errno = 0;
		return 0;
	}
	uActive = uTop >= iDevDepth ? uTop-iDevDepth : uTop+1;
	for ( ; uTop > 0; --uTop) {
		snprintf(acLevel, sizeof(acLevel), "%u", uTop);
		(void)div_setKey(acLevel);
		iRet = (*pfi)(acLevel, getenv(u_dsData.pcret), uTop == uActive, pvData);
		if (0 != iRet)
			return iRet;
	}
	snprintf(acLevel, sizeof(acLevel), "%u", 0);
	(void)div_setKey(acLevel);
	if ((char *)0 == (pcVal = getenv(u_dsData.pcret))) {
		return 0;
	}
	return (*pfi)(acLevel, pcVal, 0 == uActive, pvData);
}

/* Push a result token back into the envionment				(ksb)
 */
int
divResults(const char *pcValue)
{
	if (-1 == div_setKey("list")) {
		errno = ENXIO;
		return -1;
	}
	if ((const char *)0 == pcValue) {
		unsetenv(u_dsData.pcret);
		return 0;
	}
	return setenv(u_dsData.pcret, pcValue, 1);
}

/* The magic is here, find the diversion the Customer is looking for	(ksb)
 */
char *
divSelect()
{
	register char *pcOuter, *pcRet;
	register unsigned uOuter;
	auto char *pcEos;

	pcRet = pcMaster;
	if ((char *)0 != pcRet && '-' == pcRet[0] && '\000' == pcRet[1]) {
		pcRet = (char *)0;
	}
	if ((char *)0 != pcRet) {
		return pcRet;
	}

	uOuter = 1;
	if ((char *)0 == (pcOuter = divCurrent((char *)0))) {
		fprintf(stderr, "%s: no enclosing diversion", progname);
		if (-1 != div_setKey("d") && (char *)0 != (pcOuter = getenv(u_dsData.pcret))) {
			fprintf(stderr, ", do you mean to specify option `-u' as \"%s\"?", pcOuter);
		}
		fprintf(stderr, "\n");
		exit(EX_NOINPUT);
	}
 else if (0 != strcmp(pcOuter, "link")) {
		uOuter = strtol(pcOuter, &pcEos, 10);
		if (pcEos == pcOuter || '\000' != *pcEos) {
			fprintf(stderr, "%s: cannot parse %s \"%s\" as a number\n", progname, pcOuter, pcOuter);
			exit(EX_DATAERR);
		}
		/* yes we really want to try level 0 --ksb
		 */
		if (uOuter < iDevDepth) {
			fprintf(stderr, "%s: requested depth of -%d is too large for current stack of %u\n", progname, iDevDepth, uOuter);
			exit(EX_DATAERR);
		}
		uOuter -= iDevDepth;
		if ((char *)0 == (pcRet = divIndex(uOuter))) {
			fprintf(stderr, "%s: deversion %u: %s\n", progname, uOuter, strerror(errno));
			exit(EX_DATAERR);
		}
	}
 else if (-1 == div_setKey("d")) {
		fprintf(stderr, "%s: internal buffer snark\n", progname);
		exit(EX_SOFTWARE);
	}
 else if ((char *)0 == (pcRet = getenv(u_dsData.pcret))) {
		fprintf(stderr, "%s: $%s: no diversion set\n", progname, u_dsData.pcret);
		exit(EX_DATAERR);
	}
	return pcRet;
}

/* Get a specific diversion by number (0...N)				(ksb)
 */
char *
divIndex(unsigned uLevel)
{
	auto char acIndex[(sizeof("%u")|3)+(1+32)];

	snprintf(acIndex, sizeof(acIndex), "%u", uLevel);
	if (-1 == div_setKey(acIndex)) {
		errno = ENXIO;
		return (char *)0;
	}
	errno = ENOENT;
	return getenv(u_dsData.pcret);
}
#line 1 "util_divconnect.mc"
/* $Id: util_divconnect.mc,v 1.3 2008/09/01 17:35:13 ksb Exp $
 */

/* Open a client socket, but hook in the wrapw magic too.		(ksb)
 * Make the client port, connect it to the enclosing diversion.
 * Wrapw waits for the non-existant path tail to return the service rights,
 * so send the cookie part and wait for the three reply cases:
 *	-	we failed to find the instance, return -1
 *	+	just hand this one back (I'll proxy),
 *    <else>	accept access rights via the indirect pointer
 * Then protect it from being passed to a child, and hook into any
 * initial negotiation the client needs.
 *
 * If we must recurse use the divNextLevel functor to find the parameter
 * to pass back to this function, when not set pass (void *)0.
 */
int
divConnect(const char *pcSocket, int (*pfiIndir)(int fd, char *pcCookie, void *pvData, char *pcType), void *pvLevel)
{
	register int s, iTry, iCc;
	register char *pcName, *pcCookie, *pcSlash;
	auto struct sockaddr_un run;
	auto struct stat stExist;
	auto char acAnswer[4];

	s = -1;
	if (-1 == stat(pcSocket, & stExist)) {
		if (ENOTDIR != errno) {
			return -1;
		}
		pcName = strdup(pcSocket);
		if ((char *)0 == (pcCookie = strrchr(pcName, '/'))) {
			errno = EPIPE;
			free((void *)pcName);
			return -1;
		}
		/* Handle any user built $SOCKET///cookie
		 */
		pcSlash = pcCookie++;
		while (pcSlash > pcName && '/' == pcSlash[-1]) {
			--pcSlash;
		}
		*pcSlash = '\000';
		iCc = strlen(pcCookie)+1;
		if (-1 == (s = divConnect(pcName, pfiIndir, (void *(*)(void *))0 == divNextLevel ? (void *)0 : (*divNextLevel)(pvLevel)))) {
			return -1;
		} else if (iCc != write(s, pcCookie, iCc)) {
			close(s);
			return -1;
		} else if (1 != read(s, acAnswer, 1)) {
			close(s);
			return -1;
		} else if ('-' == acAnswer[0]) {	/* failed to find */
			close(s);
			return -1;
		} else if ('+' == acAnswer[0]) {	/* use this channel */
			/* ok, just take it */
		} else if ((int (*)())0 == pfiIndir) {	/* no accept rights */
			close(s);
			errno = ENOSYS;
			return -1;
		} else /* @ or something else in the future */ {
			/* Indirect case let them do the protocol and
			 * they have to close s if they don't return it.
			 */
			acAnswer[1] = '\000';
			s = (*pfiIndir)(s, pcCookie, pvLevel, acAnswer);
		}
		free((void *)pcName);
	}
	for (iTry = 0; -1 == s && iTry < 10; ++iTry) {
		if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
			return -1;
		}
		run.sun_family = AF_UNIX;
		(void)strcpy(run.sun_path, pcSocket);
		if (-1 != connect(s, (struct sockaddr *)&run, EMU_SOCKUN_LEN(pcSocket))) {
			break;
		}
		if (errno != ECONNREFUSED) {
			close(s);
			s = -1;
			break;
		}
		close(s);
		s = -1;
		sleep(iTry); /* wait up to 55 seconds */
	}
	if (-1 != s) {
		(void)fcntl(s, F_SETFD, 1);
	}
	if ((int (*)(int, void *))0 != divConnHook) {
		return (*divConnHook)(s, pvLevel);
	}
	return s;
}
#line 1 "util_pipefit.mc"
/* $Id: util_pipefit.mc,v 8.40 2007/09/17 18:59:54 ksb Exp $
 * open a process on 0 or 1 (or 2) close the old fd			(ksb)
 * replace it with a pipe to the new process in the correct dir.
 *
 * const char *pcExec, char **ppcArgv, char *ppcEnv, int iFd
 */
static pid_t
PipeFit(const char *pcExec, char **ppcArgv, char **ppcEnv, int iFd)
{
	extern char **environ;
	register int i, iKeep, iPid;
	auto int aiPipe[2];

	/* iKeep is the subscript in the pipe array to install at iFd,
	 * in this process, note iFd could be 2 (for stderr).
	 */
	iKeep = (0 == iFd ? 0 : 1);
	if (fVerbose && (FILE *)0 != fpVerbose) {
		fprintf(fpVerbose, "%s:%s", progname, iKeep ? " |" : "");
		for (i = 0; (char *)0 != ppcArgv[i]; ++i) {
			fprintf(fpVerbose, " %s", ppcArgv[i]);
		}
		fprintf(fpVerbose, "%s\n", iKeep ? "" : " |");
		fflush(fpVerbose);
	}
	if (-1 == iFd || 0 == fExec) {
		return 0;
	}
	if (-1 == pipe(aiPipe)) {
		fprintf(stderr, "%s: pipe: %s\n", progname, strerror(errno));
		return -1;
	}
	switch (iPid = fork()) {
	case -1:
		close(aiPipe[0]);
		close(aiPipe[1]);
		fprintf(stderr, "%s: fork: %s\n", progname, strerror(errno));
		return -1;
	default:	/* parent , close fd, teather kid up */
		break;
	case 0:
		/* child inverts the logic
		 */
		iFd = 0 == iFd ? 1 : 0;
		iKeep ^= 1;
		break;
	}
	if (iFd != aiPipe[iKeep]) {
		dup2(aiPipe[iKeep], iFd);
		close(aiPipe[iKeep]);
	}
	if (iFd != aiPipe[!iKeep]) {
		close(aiPipe[!iKeep]);
	}
	clearerr(0 == iFd ? stdin : 1 == iFd ? stdout : stderr);
	if (0 != iPid) {
		return iPid;
	}
	environ = ppcEnv;
	(void)execvp(pcExec, ppcArgv);
	(void)execve(pcExec, ppcArgv, ppcEnv);
	fprintf(stderr, "%s: execve: %s: %s\n", progname, pcExec, strerror(errno));
	exit(EX_UNAVAILABLE);
}
#line 1 "util_fsearch.mc"
/* $Id: util_fsearch.mc,v 8.10 1998/09/16 13:37:42 ksb Exp $
 */

/* we take a vector of possible lexicons and a $PATH mocking		(ksb)
 * list of places to search for them.  I'd rather not take the $PATH
 * compatible, but it is the most common use, so I used it.
 */
char *
util_fsearch(ppcScan, pcPath)
char **ppcScan;
char *pcPath;
{
	register char *pcThis, *pcCursor, *pcWrite;
	auto char acFull[MAXPATHLEN+4];
	auto struct stat stDummy;
	static char acDefPath[] = "/bin:/usr/bin:/usr/sbin";

	if ((char *)0 == pcPath) {
		pcPath = acDefPath;
	}

	/* search lexicons for full paths ref, or
	 * relatives with each prefix tried
	 */
	while ((char *)0 != (pcThis = *ppcScan++)) {
		acFull[0] = '\000';
		if ('$' == pcThis[0]) {
			if ((char *)0 == (pcThis = getenv(pcThis+1))) {
				continue;
			}
		}
		if ('~' == pcThis[0]) {
			pcThis = util_home(acFull, pcThis+1);
			if ((char *)0 == pcThis) {
				continue;
			}
			(void)strcat(acFull, pcThis);
		} else if ('/' == pcThis[0]) {
			(void)strcpy(acFull, pcThis);
		}
		if ('\000' != acFull[0]) {
			if (-1 != stat(acFull, & stDummy)) {
				return strdup(acFull);
			}
			continue;
		}

		/* search colon-separated prefix path
		 */
		pcWrite = (char *)0;
		for (pcCursor = pcPath; /**/; ++pcCursor) {
			if ((char *)0 == pcWrite) {
				if ('\000' == *pcCursor)
					break;
				pcWrite = acFull;
			}
			if (':' != *pcCursor && '\000' != *pcCursor) {
				*pcWrite++ = *pcCursor;
				continue;
			}
			if (acFull != pcWrite && pcWrite[-1] != '/') {
				*pcWrite++ = '/';
			}
			(void)strcpy(pcWrite, pcThis);
			if (-1 != stat(acFull, & stDummy)) {
				return strdup(acFull);
			}
			if ('\000' == *pcCursor) {
				break;
			}
			pcWrite = (char *)0;
		}
	}
	return (char *)0;
}
#line 1 "util_home.mc"
/* $Id: util_home.mc,v 8.8 1998/09/16 13:34:24 ksb Exp $
 */

/* find a home directory for ~usr style interface			(ksb)
 *	do ~login and ~
 * Input login names are terminated by '\000' or '/' or ':',
 * anything else you can do.  pcDest should have about MAXPATHLEN
 * characters available, more or less.
 *
 * We return the pointer after the consumed text, or (char *)0 for fail,
 * if the destination buffer is empty we could not find $HOME/getpwuid,
 * else we could not find the login name in the buffer.
 */
char *
util_home(pcDest, pcWho)
char *pcDest, *pcWho;
{
	extern char *getenv();
	register char *pcHome;
	register struct passwd *pwd;
	register char *pcTmp;

	pcHome = getenv("HOME");
	if ((char *)0 == pcHome) {
		pwd = getpwuid(getuid());
		/* only good for a short time... long enough
		 */
		if ((struct passwd *)0 != pwd) {
			pcHome = pwd->pw_dir;
		}
	}
	if ((char *)0 == pcWho || '/' == *pcWho || ':' == *pcWho || '\000' == *pcWho) {
		if ((char *)0 == pcHome) {
			*pcDest = '\000';
			return (char *)0;
		}
		(void)strcpy(pcDest, pcHome);
		return (char *)0 == pcWho || '\000' == *pcWho ? "" : pcWho;
	}

	pcTmp = pcDest;
	while ('/' != *pcWho && ':' != *pcWho && '\000' != *pcWho) {
		*pcTmp++ = *pcWho++;
	}
	*pcTmp = '\000';

	if ((struct passwd *)0 == (pwd = getpwnam(pcDest))) {
		return (char *)0;
	}
	(void)strcpy(pcDest, pwd->pw_dir);
	return pcWho;
}
#line 1 "util_mult.mc"
/* $Id: util_mult.mc,v 8.11 2008/09/05 16:30:05 ksb Exp $
 */

/* do the third prec level						(ksb)
 * ops: (), number, scales
 */
static unsigned long
pm_term(ppcIn, pPM, uiCount)
char **ppcIn;
struct PMnode *pPM;
unsigned int uiCount;
{
	register unsigned long ulTerm;
	register unsigned int u;
	auto char *pcOut;

	pcOut = *ppcIn;
	switch (*pcOut) {
	case '(':
		++pcOut;
		ulTerm = pm_expr(& pcOut, pPM, uiCount);
		if (')' != *pcOut) {
			/* missing close paren */
			*ppcIn = pcOut;
			return ulTerm;
		}
		++pcOut;
		break;
	case '0': case '1': case '2': case '3':
	case '4': case '5': case '6': case '7':
	case '8': case '9':
		ulTerm = strtoul(pcOut, & pcOut, 0);
		break;
	default:
		ulTerm = 1;
		break;
	}
	while ('\000' != *pcOut) {
		if (isspace(*pcOut)) {
			++pcOut;
			continue;
		}
		if (isdigit(*pcOut)) {
			ulTerm *= strtoul(pcOut, & pcOut, 0);
			continue;
		}
		if ((char *)0 != strchr("*/%+-)", *pcOut)) {
			break;
		}
		for (u = 0; u < uiCount; ++u) {
			if (*pcOut == pPM[u].ckey) {
				break;
			}
		}
		if (u != uiCount) {
			ulTerm *= pPM[u].umult;
			++pcOut;
			continue;
		}
		/* unknown scale letter */
		if (isalpha(*pcOut)) {
			fprintf(stderr, "%s: %s: malformed expression: %s\n", progname, "scale", "unknown unit");
			++pcOut;
		}
		break;
	}
	*ppcIn = pcOut;
	return ulTerm;
}

/* do the second prec level						(ksb)
 * ops: *, /, %
 */
static unsigned long
pm_factor(ppcIn, pPM, uiCount)
char **ppcIn;
struct PMnode *pPM;
unsigned int uiCount;
{
	register unsigned long ulProd, ulTmp;
	auto char *pcOut;

	ulProd = pm_term(ppcIn, pPM, uiCount);
	pcOut = *ppcIn;
	while ('\000' != *pcOut && ')' != *pcOut) {
		if (isspace(*pcOut)) {
			++pcOut;
			continue;
		}
		if ('*' == *pcOut) {
			++pcOut;
			ulProd *= pm_expr(& pcOut, pPM, uiCount);
			continue;
		}
		if ('(' == *pcOut) {
			ulProd *= pm_term(& pcOut,  pPM, uiCount);
			continue;
		}
		if ('/' == *pcOut) {
			ulTmp = pm_term(& pcOut,  pPM, uiCount);
			if (0L == ulTmp) {
				fprintf(stderr, "%s: %s: malformed expression: %s\n", progname, "expression", "modulo by zero");
				continue;
			}
			ulProd /= ulTmp;
			continue;
		}
		if ('%' == *pcOut) {
			ulTmp = pm_term(& pcOut,  pPM, uiCount);
			if (0L == ulTmp) {
				fprintf(stderr, "%s: %s: malformed expression: %s\n", progname, "expression", "modulo by zero");
				continue;
			}
			ulProd %= ulTmp;
			continue;
		}
		break;
	}
	*ppcIn = pcOut;
	return ulProd;
}

/* Do the conversion work						(ksb)
 * We even do (non-prec) 5 banger math, like: '(5+3)*2k'
 * (also handle the implicit multiplication "7(2+11)m")
 */
unsigned long
pm_expr(ppcIn, pPM, uiCount)
char **ppcIn;
struct PMnode *pPM;
unsigned int uiCount;
{
	register unsigned long ulRet, ulSign;
	auto char *pcOut;

	ulRet = pm_factor(ppcIn, pPM, uiCount);
	pcOut = *ppcIn;
	ulSign = 1;
	while ('\000' != *pcOut && ')' != *pcOut) {
		if (isspace(*pcOut)) {
			++pcOut;
			continue;
		}
		/* look sign of addition
		 */
		switch (*pcOut) {
		case '+':
			++pcOut;
			continue;
		case '-':
			ulSign *= -1;
			++pcOut;
			continue;
		default:
			break;
		}
		ulRet += ulSign * pm_factor(& pcOut, pPM, uiCount);
		ulSign = 1;
	}
	*ppcIn = pcOut;
	return ulRet;
}

/* clean call from mkcmd to do scaled units				(ksb)
 * also has a nice (kinda) builtin help facility
 */
unsigned long
pm_cvt(pcRaw, pPM, uiCount, pcCaller)
char *pcRaw, *pcCaller;
struct PMnode *pPM;
unsigned int uiCount;
{
	register unsigned long ulRet;
	register char *pcQuesty;
	register struct PMnode *pPMUnit;
	auto unsigned int uC1 = 1, uC2 = 1, uLen, u;
	auto char acGuess[132];

	if ((char *)0 == pcRaw) {
		return 0L;
	}
	if ((char *)0 == (pcQuesty = strchr(pcRaw, '?'))) {
		ulRet = pm_expr(& pcRaw, pPM, uiCount);
		if ('\000' != *pcRaw) {
			/* there was junk on the end? */
			fprintf(stderr, "%s: %s: malformed expression: %s\n", progname, pcCaller, pcRaw);
		}
		return ulRet;
	}

	/* help?
	 */
	if (pcQuesty == pcRaw) {
		++pcQuesty;
		ulRet = 0L;
	} else {
		*pcQuesty = '\000';
		ulRet = pm_expr(& pcRaw, pPM, uiCount);
		if ('\000' != *pcRaw) {
			/* there was junk on the end? */
			fprintf(stderr, "%s: %s: malformed expression: %s\n", progname, pcCaller, pcRaw);
		}
		*pcQuesty++ = '?';
	}

	/* xx?fmt
	 */
	if ('\000' == *pcQuesty) {
		pcQuesty = "%lu";
	}
	pPMUnit = (struct PMnode *)0;
	for (u = 0; u < uiCount; ++u) {
		if ('\000' == pPM[u].ckey) {
			pPMUnit = pPM+u;
		}
		uLen = strlen(pPM[u].pctext);
		if (uLen > uC1) {
			uC1 = uLen;
		}
		(void)sprintf(acGuess, pcQuesty, pPM[u].umult);
		uLen = strlen(acGuess);
		if (uLen > uC2) {
			uC2 = uLen;
		}
	}

	printf("%s: %s conversion table", progname, (struct PMnode *)0 == pPMUnit || (char *)0 == pPMUnit->pctext ? "unit" : pPMUnit->pctext);
	if (0 != ulRet) {
		printf(" for ");
		printf(pcQuesty, ulRet);
		printf(":\n");
	} else {
		printf("\n");
	}
	for (u = 0; u < uiCount; ++u) {
		register unsigned long ulTemp;

		if (pPMUnit == pPM+u) {
			continue;
		}
		(void)sprintf(acGuess, pcQuesty, pPM[u].umult);
		printf(" %c %*s %*s", pPM[u].ckey, uC1, pPM[u].pctext, uC2, acGuess);
		if (0 != ulRet && 0 != (ulTemp = ulRet/pPM[u].umult)) {
			(void)sprintf(acGuess, pcQuesty, ulTemp);
			printf(" %s%c", acGuess, pPM[u].ckey);
			if (0 != (ulTemp = (ulRet % pPM[u].umult))) {
				(void)sprintf(acGuess, pcQuesty, ulTemp);
				printf("+%s", acGuess);
			}
		}
		printf("\n");
	}
	return ulRet;
}
#line 1 "mkcmd_generated_main"
/*
 * parser
 */
int
main(argc, argv)
int argc;
char **argv;
{
	static char
		sbOpt[] = "#:a:AdDEhH:i:IL:mnN:O:p:qQrsS:T:u:vVwW:YZ",
		*u_pch = (char *)0;
	static int
		u_loop = 0;
	static char
		*pcXid = (char *)0;
	int
		u_gave_m = 0;
	register int u_curopt;
	register char *u_pcEnv;
	extern char *getenv();
	extern int atoi();
	extern int atoi();

	if ((char *)0 == argv[0]) {
		progname = "xclate";
	} else if ((char *)0 == (progname = strrchr(argv[0], '/'))) {
		progname = argv[0];
	} else {
		++progname;
	}
	if ((FILE *)0 == (fpVerbose = fdopen(dup(2), "w"))) {
		fpVerbose = stderr;
	}
	(void)fcntl(fileno(fpVerbose), F_SETFD, 1);
	setvbuf(fpVerbose, (char *)0, _IOLBF, (size_t)512);
	divInit("xcl", "option `-u'");
	if ((char *)0 != (u_pcEnv = getenv("XCLATE"))) {
		u_envopt(u_pcEnv, & argc, & argv);
	}
	/* "xclate" forces no options */
	pcLimit = "64k";
	uiLimit = pm_cvt(pcLimit, aPMBytes, sizeof(aPMBytes)/sizeof(POST_MULT), "option `-L'");
	if ((char *)0 != (u_pcEnv = getenv("SHELL"))) {
		pcInterp = u_pcEnv;
	}
	if ((char *)0 != (u_pcEnv = getenv("TMPDIR"))) {
		pcTmpdir = u_pcEnv;
	}
	if ((char *)0 == pcTmpdir || '\000' == *pcTmpdir) {
		pcTmpdir = "/tmp";
	}
	if ((char *)0 == pcInterp) {
		pcInterp = "/bin/sh";
	}
	while (EOF != (u_curopt = u_getopt(argc, argv, sbOpt, (char *)0))) {
		switch (u_curopt) {
		case '#':
			u_chkonly('#', u_curopt, "#");
			iDevDepth = atoi(u_optarg);
			continue;
		case '*':
			fprintf(stderr, "%s: option `-%c\' needs a parameter\n", progname, u_optopt);
			exit(1);
		case '?':
			fprintf(stderr, "%s: unknown option `-%c\', use `-h\' for help\n", progname, u_optopt);
			exit(1);
		case 'a':
			cEsc = cvtletter(u_optarg);
			continue;
		case 'A':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-A' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fStartup = ! 0;
			continue;
		case 'd':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-d' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fPublish = ! 1;
			continue;
		case 'D':
			u_chkonly('D', u_curopt, "m");
			fAskPWD = ! 0;
			continue;
		case 'E':
			u_chkonly('E', u_curopt, "m");
			fAskStderr = ! 0;
			continue;
		case 'h':
			for (u_loop = 0; (char *)0 != (u_pch = au_terse[u_loop]); ++u_loop) {
				if ('\000' == *u_pch) {
					printf("%s: with no parameters\n", progname);
					continue;
				}
				printf("%s: usage%s\n", progname, u_pch);
			}
			for (u_loop = 0; (char *)0 != (u_pch = u_help[u_loop]); ++u_loop) {
				printf("%s\n", u_pch);
			}
			exit(0);
		case 'H':
			pcHorizRule = u_optarg;
			continue;
		case 'i':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-i' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fReplaceOrigIn = 1;
			pcForcedIn = u_optarg;
			continue;
		case 'I':
			u_chkonly('I', u_curopt, "m");
			fAskStdin = ! 0;
			continue;
		case 'L':
			fGaveL = 1;
			pcLimit = u_optarg;
			uiLimit = pm_cvt(pcLimit, aPMBytes, sizeof(aPMBytes)/sizeof(POST_MULT), "option `-L'");
			continue;
		case 'm':
			u_chkonly('m', u_curopt, "DEISYmw");
			u_gave_m = 1;
			fMaster = ! 0;
			continue;
		case 'n':
			fExec = !1;
			fVerbose = !0;
			continue;
		case 'N':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-N' may only be given after option `-m'\n", progname);
				exit(1);
			}
			pcNotify = u_optarg;
			continue;
		case 'O':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-O' may only be given after option `-m'\n", progname);
				exit(1);
			}
			pcPriv = u_optarg;
			continue;
		case 'p':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-p' may only be given after option `-m'\n", progname);
				exit(1);
			}
			wElected = atoi(u_optarg);
			wInferior = (pid_t)wElected;
			continue;
		case 'q':
			fAllowQuick = ! 0;
			continue;
		case 'Q':
			fTerminate = ! 0;
			continue;
		case 'r':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-r' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fExit2 = ! 0;
			continue;
		case 's':
			fSqueeze = ! 0;
			continue;
		case 'S':
			u_chkonly('S', u_curopt, "m");
			pcInterp = u_optarg;
			continue;
		case 'T':
			pcTitle = u_optarg;
			continue;
		case 'u':
			pcMaster = u_optarg;
			continue;
		case 'v':
			fVerbose = ! 0;
			continue;
		case 'V':
			printf("%s: %s\n", progname, rcsid);
			Version();
			exit(0);
		case 'w':
			u_chkonly('w', u_curopt, "m");
			fWeeping = ! 0;
			continue;
		case 'W':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-W' may only be given after option `-m'\n", progname);
				exit(1);
			}
			pcWidows = u_optarg;
			continue;
		case 'Y':
			u_chkonly('Y', u_curopt, "m");
			fNewTTY = ! 0;
			continue;
		case 'Z':
			Z_opt = ! 0;
			continue;
		}
		break;
	}
	if (Z_opt) {
		WidowsWalk();
	}
	/* alternate for option m */
	if (u_gave_m) {
		Master((argc-u_optInd), & argv[u_optInd]);
		exit(EX_OK);
		exit(0);
		/*NOTREACHED*/
	}
	if (argc - u_optInd > 0 && '-' == argv[u_optInd][0] && '-' == argv[u_optInd][1] && '\000' == argv[u_optInd][2]) {
		++u_optInd;
		goto just_done;
	}
	if (argc - u_optInd < 1) {
		goto just_done;
	}
	pcXid = argv[u_optInd];
	++u_optInd;
	if (argc - u_optInd > 0 && '-' == argv[u_optInd][0] && '-' == argv[u_optInd][1] && '\000' == argv[u_optInd][2]) {
		++u_optInd;
	}
just_done: /* escape optional left arguments */;
	Stream(pcXid, (argc-u_optInd), (argv+u_optInd));
	exit(EX_OK);
	exit(0);
	/*NOTREACHED*/
}
