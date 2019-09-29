/* mkcmd generated user interface
 * built by mkcmd version 8.17 Rel
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <netdb.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sysexits.h>
#include "fdrights.h"
#include "machine.h"
#include <errno.h>
#include <sys/uio.h>
/* from getopt.m */
/* from getopt_key.m */
/* from ptbw.m */
#line 36 "ptbw.m"
static const char rcsid[] =
	"$Id: ptbw.m,v 1.76 2010/05/03 13:28:13 ksb Exp $",
	acPtbwName[] = "ptbw",		/* this name doesn't change argv[0] */
	acMySuffix[] = "/ptbdXXXXXX";	/* mkdtemp suffix in $TMPDIR	*/
static char
	cSourceType = '-',		/* the source type (file,func,err)*/
	acTheSource[MAXPATHLEN+4],	/* the original data source	*/
	*pcComments = "",		/* comments from token source	*/
	*pcMyTemp = (char *)0,		/* if we had to build one	*/
	*pcMySpace = (char *)0,		/* where we hide to work	*/
	*pcMySocket = (char *)0;	/* my UNIX domain socket	*/
#if HAVE_ACCEPT_FILTER && defined(SO_ACCEPTFILTER)
static const char
	acAcceptFilter[] = "dataready";
#endif

static char *BorrowTarget(char *pcDirect, unsigned int iMin, unsigned int *piCount, char *pcSource);
/* from util_errno.m */
#line 8 "util_errno.m"
extern int errno;
/* from util_tmp.m */
/* from util_cache.m */
/* from util_nproc.m */
/* from util_divstack.m */
/* from util_divconnect.m */
#line 10 "util_divconnect.m"
void *(*divNextLevel)(void *pvThisLevel) = (void *(*)(void *))0;
int (*divConnHook)(int fd, void *pvLevel) = (int (*)(int, void *))0;
/* from std_help.m */
/* from std_version.m */
/* from ptbc.m */
#line 22 "ptbc.m"
static char PTBacVersion[] =
	"0.4\n";
#line 27 "ptbc.m"
extern int PTBPidRecv(int, char *, size_t);
#line 68 "ptbc.m"
static unsigned int uOurCount, uOurSize;
#line 71 "ptbc.m"
extern int PTBClientPort(const char *pcDirect), PTBPidSend(int s, char *pcSrc);
#line 169 "ptbc.m"
extern char *PTBReadTokenList(int sMaster, unsigned int uNeed, unsigned int **ppuList);
#line 253 "ptbc.m"
extern unsigned int PTBFreeTokenList(int sMaster, unsigned int uHold, unsigned int *puList);
#line 303 "ptbc.m"
extern int PTBCmdInt(int sMaster, int cCmd);
#line 358 "ptbc.m"
extern int PTBIsSocket(char *);
#line 375 "ptbc.m"
extern int PTBReqSource(int sMaster, char *pcSource, size_t iMax, char **ppcMeta);
#line 413 "ptbc.m"
extern char *PTBIota(unsigned int uMax, unsigned int *puWidth);
#line 452 "ptbc.m"
extern int PTBQuit(int sMaster, char *pcReply, unsigned uLen);
#line 475 "ptbc.m"
extern int PTBReadPid(int sMaster, pid_t *pwMaster);
/* from hosttype.m */
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
#line 1 "util_cache.mi"
/* $Id: util_cache.mi,v 8.32 2008/09/05 16:24:54 ksb Exp $
 * forward declaration of file caching code				(ksb)
 */
extern char *cache_file(int u_iFd, unsigned int *u_puLines);
extern char **cache_vector(char *pcCache, unsigned int u_uLines);
extern int cache_dispose(char **u_ppcVector);
#line 1 "util_nproc.mi"
/* $Id: util_nproc.mi,v 1.1 2006/08/18 23:06:42 ksb Exp $
 * forward declaration for util_nproc -- ksb
 */
extern unsigned long util_nproc(void);

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
char
	*progname = "$Id$",
	*au_terse[] = {
		" [-AqQ] [-depth] [-R req] [-t tags] [client]",
		" -h",
		" -V",
		" -m [-dqQ] [-depth] [-J jobs] [-N path] [-R req] [-t tags] [utility]",
		(char *)0
	},
	*u_help[] = {
		"-depth  select an outer diversion, depth steps away",
		"A       append resources to the client argument list",
		"d       do not publish this level in the linked environment",
		"h       print this help message",
		"J jobs  number of parallel tasks expected",
		"m       manage output for descendant processes",
		"utility control process for task coordination",
		"N path  force a UNIX domain name for this service",
		"q       be quiet, do not complain about constrained resources",
		"Q       tell the enclosing persistent instance to finish",
		"R req   allocate req tags for this instance",
		"t tags  source which contains controlled resource tags",
		"V       show version information",
		"client  client command",
		(char *)0
	},
	*pcTmpdir = (char *)0;
int
	iDevDepth = 0,
	fGaveJ = 0,
	u_gave_m = 0,
	fGaveReq = 0,
	fAppend = 0,
	fPublish = 1;
unsigned
	iTaskMin = 1,
	iIotaMin = 0;
int
	fMaster = 0;
char
	*pcBindHere = (char *)0;
int
	wElected = 0,
	fQuiet = 0,
	fQuit = 0;
unsigned
	uReq = 1;
char
	*pcTags = (char *)0;

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
	static int sbiOnly['m'-'#'+1];
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

/* from getopt.m */
/* from getopt_key.m */
/* from ptbw.m */
#line 136 "ptbw.m"
/* Build a temp directory for my space					(ksb)
 */
static char *
MyPlace()
{
	register char *pcRet;
	extern char *mkdtemp(char *);

	if ((char *)0 == (pcRet = malloc(((strlen(pcTmpdir)+sizeof(acMySuffix))|7)+1))) {
		fprintf(stderr, "%s: malloc: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	(void)strcat(strcpy(pcRet, pcTmpdir), acMySuffix);
	return mkdtemp(pcRet);
}

/* When we are nested inside an xclate we can use the temp directory	(ksb)
 * it built to hide our service socket.  Otherwise we must build one
 * to hide us from the cold cruel world (eval dirname \$xcl_${xcl_link}).
 */
static void
SafePlace(const char *pcInside)
{
	register char *pcEnv, *pcTail;
	static const char acXclGuess[] = "xcl_%s";
	auto char acIndex[(sizeof(acXclGuess)|7)+(32+1)];

	pcMyTemp = (char *)0;
	snprintf(acIndex, sizeof(acIndex), acXclGuess, "link");
	if ((char *)0 != (pcEnv = divCurrent((char *)0))) {
		/* try to buddy with an enclosing instance */
	} else if ((char *)0 != (pcEnv = getenv(acIndex)) && strlen(pcEnv) <= 32 && (isdigit(*pcEnv) || 'd' == *pcEnv)) {
		snprintf(acIndex, sizeof(acIndex), acXclGuess, pcEnv);
		pcEnv = getenv(acIndex);
	}
	if ((char *)0 == pcEnv || (char *)0 == (pcTail = strrchr(pcEnv, '/')) || pcEnv == pcTail) {
		pcMySpace = pcMyTemp = MyPlace();
		return;
	}
	*pcTail = '\000';
	pcMySpace = strdup(pcEnv);
	*pcTail = '/';
}

/* Make the server port for this server to listen on			(ksb)
 * stolen from ptyd, xclate, and others I've coded.
 */
static int
MakeServerPort(pcName)
char *pcName;
{
	register int sCtl, iRet, iListen;
	auto struct sockaddr_un run;
#if HAVE_ACCEPT_FILTER && defined(SO_ACCEPTFILTER)
	auto struct accept_filter_arg FA;
#endif

	if ((sCtl = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		fprintf(stderr, "%s: socket: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	run.sun_family = AF_UNIX;
	(void) strcpy(run.sun_path, pcName);
	if (-1 == bind(sCtl, (struct sockaddr *)&run, EMU_SOCKUN_LEN(pcName))) {
		return -1;
	}
	/* On some UNIX-like systems we need a sockopt set first -- sigh
	 */
	iRet = -1;
	for (iListen = 20*64; iListen > 5 && -1 == (iRet = listen(sCtl, iListen)) ; iListen >>= 1) {
		/* try less */
	}
	if (-1 == iRet) {
		fprintf(stderr, "%s: listen: %d: %s\n", progname, iListen, strerror(errno));
		exit(EX_OSERR);
	}
#if HAVE_ACCEPT_FILTER && defined(SO_ACCEPTFILTER)
	(void)memset(&FA, '\000', sizeof(FA));
	(void)strcpy(FA.af_name, acAcceptFilter);
	setsockopt(sCtl, SOL_SOCKET, SO_ACCEPTFILTER, &FA, sizeof(FA));
#endif
	(void)fcntl(sCtl, F_SETFD, 1);
	return sCtl;
}

/* We don't want to leave trash around the filesystem			(ksb)
 * Should be install with atexit before we call SafePlace or Bindings.
 */
static void
CleanUp(void)
{
	if ((char *)0 != pcMySocket) {
		(void)unlink(pcMySocket);
		pcMySocket = (char *)0;
	}
	if ((char *)0 != pcMyTemp) {
		(void)rmdir(pcMyTemp);
		pcMyTemp = (char *)0;
	}
}

/* Message passed as the (void *) target in calls to DiVersion		(ksb)
 */
struct _WMnode {
	int iwidth;			/* used as an int for printf width */
	const char *pcnote;
	int fsawactive;
	const char *pcdirect;
};

/* Format the into about a stacked (or diconnected) diversion		(ksb)
 * (if we get to level 0 return true).
 */
static int
DiVersion(const char *pcName, const char *pcTag, int fActive, void *pvMark)
{
	auto struct stat stSock;
	register struct _WMnode *pWM = pvMark;
	register char *pcTail;

	if ((const char *)0 == pcName) {
		pcName = "--";
	}
	if ((const char *)0 == pcTag) {
		printf("%s:%*s: missing from our environment", progname, pWM->iwidth, pcName);
	} else if (-1 != lstat(pcTag, & stSock)) {
		printf("%s:%*s: %s", progname, pWM->iwidth, pcName, pcTag);
	} else if (ENOTDIR != errno || (char *)0 == (pcTail = strrchr(pcTag, '/'))) {
		printf("%s:%*s: stat: %s: %s", progname, pWM->iwidth, pcName, pcTag, strerror(errno));
	} else {
		*pcTail = '\000';
		if (-1 == lstat(pcTag, & stSock) || S_IFSOCK != (S_IFMT & stSock.st_mode)) {
			printf("%s:%*s: lstat: %s: %s", progname, pWM->iwidth, pcName, pcTag, strerror(errno));
		} else {
			printf("%s:%*s: %s/%s", progname, pWM->iwidth, pcName, pcTag, pcTail+1);
		}
		*pcTail = '/';
	}
	if (fActive) {
		pWM->fsawactive = 1;
		printf("%s", pWM->pcnote);
	}
	if ((const char *)0 != pWM->pcdirect && 0 == strcmp(pcTag, pWM->pcdirect)) {
		pWM->pcdirect = (const char *)0;
		printf(" [-t]");
	}
	printf("\n");
	if (fActive && !isdigit(*pcName)) {
		return 1;
	}
	return '0' == pcName[0] && '\000' == pcName[1];
}

/* We output more than you'd want to know, good for debugging		(ksb)
 */
static void
Version()
{
	register const char *pcLevel;
	auto unsigned uOuter;
	auto struct _WMnode WMParam;

	(void)divNumber(& uOuter);
	printf("%s: default number of tokens: %u\n", progname, iIotaMin);
	divVersion(stdout);
	printf("%s: protocol version %.*s\n", progname, (int)strlen(PTBacVersion)-1, PTBacVersion);
#if HAVE_ACCEPT_FILTER && defined(SO_ACCEPTFILTER)
	printf("%s: accept filter: %s\n", progname, acAcceptFilter);
#endif
	printf("%s: safe directory template: %s\n", progname, acMySuffix+1);
	pcLevel = divCurrent((char *)0);
	WMParam.iwidth = (char *)0 == pcLevel ? 3 : strlen(pcLevel)+2;
	WMParam.pcnote = " [target]";
	WMParam.fsawactive = 0;
	WMParam.pcdirect = pcTags;
	if (0 == divSearch(DiVersion, (void *)& WMParam) && iDevDepth >= uOuter) {
		if ((const char *)0 != WMParam.pcdirect) {
			DiVersion("-t", WMParam.pcdirect, !WMParam.fsawactive, (void *)&WMParam);
		} else if (0 == iDevDepth) {
			printf("%s: no current diversions\n", progname);
		} else {
			printf("%s: depth -%d is too great for current stack of %u\n", progname, iDevDepth, uOuter);
		}
	} else if ((const char *)0 != WMParam.pcdirect) {
		DiVersion("-t", WMParam.pcdirect, !WMParam.fsawactive, (void *)&WMParam);
	} else if (!WMParam.fsawactive) {
		printf("%s: never saw the active diversion\n", progname);
	}
}

/* Keep up with -t targets.  We know that 127 is a big list,		(ksb)
 * so we don't have to make up clever code to search them.
 */
typedef struct TEnode {
	char *pctoken;
	pid_t wlock;
	struct TEnode *pTEnext;		/* link to next token, same pid */
} TARGET_ENV;
static TARGET_ENV *pTEList = (TARGET_ENV *)0;
static unsigned uTargetMax = 0, uTargetSize = 0;
static unsigned uTargetSpace = 0;
static unsigned uTargetCursor = 0, uTargetFree = 0;
static unsigned uTargetWidth = 0;

/* Read the targets list, or generate a default one.			(ksb)
 * The default is `-1 @ iota' {"0", "1", ..., uReq*iTaskMin-1}.
 */
static void
SetTargets(char *pcName)
{
	register char *pcBuffer, *pcStart;
	auto unsigned int uLines;
	register TARGET_ENV *pTE;
	register unsigned int i;
	register size_t iL, iC;

	/* -J must be > 0, iota == -J * -R || iota > -R
	 */
	if (iTaskMin < 1) {
		iTaskMin = 1;
	}
	if (fGaveJ && fGaveReq) {
		iIotaMin = iTaskMin * uReq;
	} else if (fGaveJ) {
		iIotaMin = iTaskMin;
	} else if (fGaveReq) {
		iIotaMin = uReq;
	}

	uLines = iIotaMin;
	pcBuffer = (char *)0;
	(void)strncpy(acTheSource, "null", sizeof(acTheSource));
	if ((char *)0 == pcName || '\000' == pcName[0]) {
		/* use iota defalt below */
	} else if ('-' == pcName[0] && '\000' == pcName[1]) {
		pcBuffer = BorrowTarget((char *)0, iIotaMin, & uLines, acTheSource);
	} else if (PTBIsSocket(pcName)) {
		pcBuffer = BorrowTarget(pcName, iIotaMin, & uLines, acTheSource);
	} else {
		register int fdTemp;
		if (-1 == (fdTemp = open(pcName, O_RDONLY, 0444))) {
			fprintf(stderr, "%s: open: %s: %s\n", progname, pcName, strerror(errno));
			exit(EX_NOINPUT);
		}
		pcBuffer = cache_file(fdTemp, & uLines);
		close(fdTemp);
		if (0 == uLines) {
			fprintf(stderr, "%s: %s: contains no lines\n", progname, pcName);
			exit(EX_DATAERR);
		}
		(void)strncpy(acTheSource, pcName, sizeof(acTheSource));
		cSourceType = '+';
	}
	if (uLines < uReq) {
		fprintf(stderr, "%s: token count of %u is less than required to run any task (%u)\n", progname, uLines, uReq);
		exit(EX_DATAERR);
	}
	if (!fQuiet && (fGaveReq || fGaveJ) && uLines < iIotaMin) {
		fprintf(stderr, "%s: token count %u less than suggested (%u)\n", progname, uLines, iIotaMin);
		fflush(stderr);
	}
	if ((char *)0 == pcBuffer && 0 < uLines) {
		pcBuffer = PTBIota(uLines, & uTargetSize);
		cSourceType = '=';
		(void)strncpy(acTheSource, "iota", sizeof(acTheSource));
	}
	if ((char *)0 == pcBuffer || 0 == uLines) {
		fprintf(stderr, "%s: no tokens generated\n", progname);
		exit(EX_DATAERR);
	}
	pcStart = pcBuffer;
	pTEList = (TARGET_ENV *)calloc(uLines, sizeof(TARGET_ENV));
	if ((TARGET_ENV *)0 == pTEList) {
		fprintf(stderr, "%s: calloc: %u,%u: %s\n", progname, uLines, (unsigned)sizeof(TARGET_ENV), strerror(errno));
		exit(EX_OSERR);
	}
	/* Put only the non-comment lines in the tableau, then means we also
	 * strip comments from up-stream data sockets.  Clever?
	 */
	uTargetWidth = 0;
	iC = 1;
	for (i = uLines, pTE = pTEList; 0 < i--; pcBuffer += iL+1) {
		iL = strlen(pcBuffer);
		if ('#' == *pcBuffer) {
			iC += iL+1;
			--uLines;
			continue;
		}
		if (iL > uTargetWidth) {
			uTargetWidth = iL;
		}
		pTE->pctoken = pcBuffer;
		pTE->wlock = 0;
		pTE->pTEnext = (TARGET_ENV *)0;
		++pTE;
	}
	if (0 == uLines) {
		fprintf(stderr, "%s: no tokens, only comments generated\n", progname);
		exit(EX_DATAERR);
	}

	/* Save the comments for the 'C' command, terminate each with '\n'
	 */
	if ((char *)0 == (pcBuffer = calloc((iC|7)+1, sizeof(char)))) {
		fprintf(stderr, "%s: calloc: %u: %s\n", progname, (unsigned)iC, strerror(errno));
		exit(EX_OSERR);
	}
	for (pcComments = pcBuffer; iC > 1; pcStart += iL+1) {
		iL = strlen(pcStart);
		if ('#' != *pcStart) {
			continue;
		}
		(void)memmove(pcBuffer, pcStart, iL);
		pcBuffer += iL;
		iC -= iL+1;
		*pcBuffer++ = '\n';
	}
	*pcBuffer = '\000';

	/* Put the token strings in a contiguous block, for the T command
	 */
	uTargetFree = uTargetMax = uLines;
	for (i = uLines, pTE = pTEList; 1 < i; --i, ++pTE) {
		iL = strlen(pTE[0].pctoken)+1;
		if (pTE[0].pctoken+iL == pTE[1].pctoken)
			continue;
		pTE[1].pctoken = (char *)memmove(pTE[0].pctoken+iL, pTE[1].pctoken, strlen(pTE[1].pctoken)+1);
	}
	uTargetSpace = pTEList[uLines-1].pctoken+strlen(pTEList[uLines-1].pctoken)+1 - pTEList[0].pctoken;
}

/* Manage client <> token interactions					(ksb)
 */
typedef struct PTnode {
#define PB_IDLE		0
#define PB_NOCRED	1
#define PB_ONLINE	2
#define PB_BLOCK	3	/* wating for a token */
#define PB_CTL		9
	unsigned int ustate;	/* from above			*/
	unsigned int uweight;	/* unimplemented fair share idea */
	unsigned int unumber;	/* partial prefix number	*/
	unsigned int iheld;	/* how many held by pid		*/
	pid_t wpid;		/* clients pid			*/
	struct PTnode *pPTnext;	/* next waiting client		*/
	char acfrom[MAXHOSTNAMELEN+4]; /* where we came from	*/
} PT_BOOK;

/* Figure out whose turn it is to be get a token set.			(ksb)
 * Service the largest weight that is > the number requested, or
 * just the largest request.  Return the one selected, and leave
 * the list of the rest complete.
 */
static PT_BOOK *
DeQueue(PT_BOOK **ppPTList)
{
	register PT_BOOK *pPTScan, *pPTMax;
	register PT_BOOK **ppPTSnip = (PT_BOOK **)0;

	if ((PT_BOOK **)0 == ppPTList || 0 == uTargetFree) {
		return (PT_BOOK *)0;
	}
	for (pPTMax = (PT_BOOK *)0; (PT_BOOK *)0 != (pPTScan = *ppPTList); ppPTList = & pPTScan->pPTnext) {
		if (pPTScan->unumber > uTargetFree) {
			continue;
		}
		pPTScan->uweight += 1;
		if ((PT_BOOK *)0 == pPTMax || pPTMax->unumber < pPTScan->unumber || (pPTMax->unumber == pPTScan->unumber && pPTMax->uweight < pPTScan->uweight)) {
			ppPTSnip = ppPTList;
			pPTMax = pPTScan;
		}
	}
	if ((PT_BOOK *)0 == pPTMax) {
		return (PT_BOOK *)0;
	}
	*ppPTSnip = pPTMax->pPTnext;
	pPTMax->pPTnext = (PT_BOOK *)0;
	return pPTMax;
}

/* Free all that a process holds					(ksb)
 */
static int
TokFree(unsigned *puTarget, PT_BOOK *pPTOwner)
{
	register int i, iRet;
	register pid_t wRelease;

	if ((unsigned *)0 != puTarget && *puTarget > uTargetMax) {
		return 0;
	}
	wRelease = pPTOwner->wpid;
	iRet = 0;
	for (i = 0; i < uTargetMax; ++i) {
		if (wRelease != pTEList[i].wlock)
			continue;
		if ((unsigned *)0 != puTarget && *puTarget != i)
			continue;
		pTEList[i].wlock = 0;
		++iRet;
	}
	pPTOwner->iheld -= iRet;
	uTargetFree += iRet;
	return iRet;
}

/* See if a token is available						(ksb)
 * return -1 for no such luck, else index
 */
static int
TokAlloc(PT_BOOK *pPT)
{
	register int i, iRet;

	iRet = 0;
	for (;;) {
		for (i = uTargetMax; 0 < i; --i, ++uTargetCursor) {
			if (uTargetMax <= uTargetCursor)
				uTargetCursor = 0;
			if (0 != pTEList[uTargetCursor].wlock)
				continue;
			pTEList[uTargetCursor].wlock = pPT->wpid;
			--uTargetFree;
			pPT->iheld += 1;
			return uTargetCursor++;
		}
	}
	return -1;
}

/* Allocate a long list of resources, fail if we can't get all		(ksb)
 */
static TARGET_ENV *
TokGroup(unsigned uNeed, PT_BOOK *pPT)
{
	register TARGET_ENV **ppTEChain;
	register int i, iTok;
	auto TARGET_ENV *pTERet;

	/* caller checked max/client for us, we just check to over max
	 */
	if (uNeed > uTargetFree) {
		return (TARGET_ENV *)0;
	}
	ppTEChain = & pTERet;
	for (i = 0; i < uNeed; ++i) {
		if (-1 == (iTok = TokAlloc(pPT))) {
			fprintf(stderr, "%s: %d: internal invarient snark\n", progname, __LINE__);
			break;
		}
		if (pPT->wpid != pTEList[iTok].wlock) {
			fprintf(stderr, "%s: %d: lock invarient snark!\n", progname, __LINE__);
		}
		*ppTEChain = & pTEList[iTok];
		ppTEChain = & pTEList[iTok].pTEnext;
	}
	*ppTEChain = (TARGET_ENV *)0;
	return pTERet;
}

static volatile pid_t wInferior = -1;
static volatile int wInfExits = EX_PROTOCOL;
static volatile int fInfOpts = WNOHANG|WUNTRACED;

/* When a signal for a child arrives we burry the dead.			(ksb)
 * If he is "our boy", then forget he's alive.
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
		if (wInferior == wReap) {
			wInferior = 0;
			wInfExits = WEXITSTATUS(wStatus);
		}
	}
}

/* signal handler to remove our socket when we are signaled		(ksb)
 */
static void
DeadMan(int _dummy)	/*ARGSUSED*/
{
	exit(0);
}

/* Build the service socket, put the mame in the environment		(ksb)
 */
static int
Bindings(unsigned uMake)
{
	static const char acEnvRead[] = "PTBW";
	register char *pcTail;
	register unsigned int i;
	register int sRet;
	auto struct stat stLook;
	auto char acLevel[(sizeof(acEnvRead)|15)+(32+1)];
	auto struct sigaction saWant;

	/* Accepting a -HUP signal to re-load the token data adds
	 * uncertianty for no gain here, just install -TERM -- ksb
	 */
	(void)memset((void *)& saWant, '\000', sizeof(saWant));
	saWant.sa_handler = (void *)DeadMan;
#if HAVE_SIGACTION
	saWant.sa_sigaction = (void *)DeadMan;
#endif
	saWant.sa_flags = SA_RESTART;
	if (-1 == sigaction(SIGINT, & saWant, (struct sigaction *)0)) {
		fprintf(stderr, "%s: sigaction: INT: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	(void)sigaction(SIGTERM, & saWant, (struct sigaction *)0);

	if ((char *)0 != pcBindHere) {
		if ('/' == *pcBindHere) {
			pcMySocket = pcBindHere;
		} else {
			register int iGuess;
			iGuess = (15|(strlen(pcMySpace)+strlen(pcBindHere)))+9;
			pcMySocket = malloc(iGuess);
			snprintf(pcMySocket, iGuess, "%s/%s", pcMySpace, pcBindHere);
		}
		if (-1 == (sRet = MakeServerPort(pcMySocket))) {
			fprintf(stderr, "%s: bind: %s: %s\n", progname, pcMySocket, strerror(errno));
			exit(EX_OSERR);
		}
	} else {
		pcMySocket = malloc((strlen(pcMySpace)|63)+65);
		pcTail = strchr(strcpy(pcMySocket, pcMySpace), '\000');
		if (pcTail > pcMySocket && '/' != pcTail[-1]) {
			*pcTail++ = '/';
		}
		for (i = 0; 1; ++i) {
			snprintf(pcTail, 64, "sta%u", i);
			if (-1 != lstat(pcMySocket, & stLook))
				continue;
			if (-1 != (sRet = MakeServerPort(pcMySocket)))
				break;

			/* We failed to get a bind in pcMySpace, if we
			 * didn't make a space we still can, once. -- ksb
			 * (Someone chmod'd our super-space ugo-w, sigh.)
			 */
			if ((char *)0 != pcMyTemp) {
				fprintf(stderr, "%s: bind: %s: %s\n", progname, pcMySocket, strerror(errno));
				exit(EX_OSERR);
			}
			pcMySpace = pcMyTemp = MyPlace();
			return Bindings(uMake);
		}
	}

	/* Notify the inferior processes of our IPC location
	 */
	if (fPublish) {
		divPush(pcMySocket);
	} else {
		divDetach(pcMySocket, (const char *)0);
	}

	/* Diddle the options variable $PTBW_$level -> $PTBW, I'm a wrapper
	 */
	(void)snprintf(acLevel, sizeof(acLevel), "%s_%u", acEnvRead, uMake);
	if ((char *)0 != (pcTail = getenv(acLevel))) {
		(void)setenv(acEnvRead, pcTail, 1);
	} else {
		(void)unsetenv(acEnvRead);
	}

	return sRet;
}

/* Send a list of token indexes sep with ',', end with '\n'		(ksb)
 */
static void
SendTokList(int sClient, int uCount, TARGET_ENV *pTENext)
{
	register TARGET_ENV *pTE;
	auto char acSend[64];

	while ((TARGET_ENV *)0 != (pTE = pTENext)) {
		pTENext = pTE->pTEnext;
		snprintf(acSend, sizeof(acSend), "%u%c", (unsigned)(pTE-pTEList), (TARGET_ENV *)0 != pTENext ? ',' : '\n');
		write(sClient, acSend, strlen(acSend));
	}
}

/* Now lead the band, from backstage, kinda.				(ksb)
 * we ignore 0, 1, 2 which we believe can't be clients
 *
 * We are a local service (only) -- since we are protected by a mode 0700
 * directory, a UNIX domain socket, and a fairly private parameter pass
 * down (in the environment).  We try to protect against an accidental
 * hang (^Z in the wrong place), but not against a malicious attack.
 * The code to do an async rights exchange is not so easy.
 * [Yes, I know ps and /proc can show the environment, mode 0700 still works.]
 */
static void
FiniteStates(sCtl)
{
	register int iClients, i, iTok;
	register PT_BOOK *pPTCur;
	register TARGET_ENV *pTEFound;
	auto PT_BOOK *pPTQueue;
	auto int iMaxPoll;
	auto fd_set fdsTemp, fdsReading;
	auto struct PTnode aPTBook[FD_SETSIZE];
	auto char acSend[8192];	/* short reply strings */
	auto struct sigaction saWant;
	auto struct timeval stStall;

	/* setup books, token table too
	 */
	for (i = 0; i < FD_SETSIZE; ++i) {
		aPTBook[i].ustate = i < 3 ? PB_CTL : PB_IDLE;
		aPTBook[i].uweight = 0;
		aPTBook[i].unumber = 0;
		aPTBook[i].iheld = 0;
		aPTBook[i].pPTnext = (PT_BOOK *)0;
	}
	pPTQueue = (PT_BOOK *)0;
	iClients = 0;
	iMaxPoll = sCtl;
	FD_ZERO(& fdsReading);
	FD_SET(sCtl, & fdsReading);
	aPTBook[sCtl].ustate = PB_CTL;
	aPTBook[sCtl].uweight = 0xf00;

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
	Death('M');

	/* We could exit the master process while we are coping the
	 * fd set, so we must timeout the select to avoid the race.
	 * As a ptbw can wait a while after the last client to exit
	 * we only poll 17 times a miniute, after the first 8 seconds.
	 */
	stStall.tv_sec = 8;
	stStall.tv_usec = 32040;
	while (0 != wInferior || 0 != iClients) {
		register int iGot;

		fdsTemp = fdsReading;
		if (-1 == (iGot = select(iMaxPoll+1, &fdsTemp, (fd_set *)0, (fd_set *)0, 0 == iClients ? & stStall : (struct timeval *)0))) {
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

		if (0 < iGot && FD_ISSET(sCtl, & fdsTemp)) {
			register int sClient;

			if (-1 == (sClient = accept(sCtl, (struct sockaddr *)0, (void *)0))) {
				if (EINTR == errno)
					continue;
				/* Someone broke our listening socket.
				 */
				FD_CLR(sCtl, & fdsReading);
				close(sCtl);
				continue;
			}
			if (sClient >= iMaxPoll) {
				iMaxPoll = sClient;
			}
			++iClients;
			FD_SET(sClient, & fdsReading);
			aPTBook[sClient].ustate = PB_NOCRED;
			aPTBook[sClient].uweight = 10;
			aPTBook[sClient].unumber = 0;
			--iGot;
		}

		/* Start at stderr+1, don't scan 0, 1, 2 every time -- ksb
		 */
		for (i = 3; 0 != iGot && i <= iMaxPoll; ++i) {
			register int iLen;
			auto char acCmd[4];

			if (!FD_ISSET(i, & fdsTemp) || sCtl == i) {
				continue;
			}
			--iGot;
			/* The first message must be a cred send --ksb
			 * A client can block us here, we should timeout,
			 * but who would do that?
			 */
			if (PB_NOCRED == aPTBook[i].ustate) {
				if (-1 == (aPTBook[i].wpid = PTBPidRecv(i, aPTBook[i].acfrom, sizeof(aPTBook[i].acfrom)))) {
					close(i);
					aPTBook[i].ustate = PB_IDLE;
					aPTBook[i].uweight = 0;
					continue;
				}
				aPTBook[i].ustate = PB_ONLINE;
				aPTBook[i].uweight = uReq;
				aPTBook[i].pPTnext = (void *)0;
				continue;
			}
			/* All commands are a single letter to avoid live locks
			 */
			iLen = read(i, acCmd, 1);
			if (1 != iLen || '.' == acCmd[0]) {
				close(i);
				aPTBook[i].ustate = PB_IDLE;
				aPTBook[i].uweight = 0;
				(void)TokFree((unsigned *)0, &aPTBook[i]);
				FD_CLR(i, & fdsReading);
				--iClients;
				continue;
			}
			/* send iTok as the reply via a break, continue doesn't
			 */
			switch (acCmd[0]) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				aPTBook[i].unumber *= 10;
				aPTBook[i].unumber += acCmd[0]-'0';
				continue;
			case 'C':	/* token comments */
				iTok = strlen(pcComments);
				snprintf(acSend, sizeof(acSend), "%u\n", (unsigned)iTok);
				write(i, acSend, strlen(acSend));
				write(i, pcComments, iTok);
				continue;
			case 'V':	/* version reply /[0-9]+[.][0-9]+\n/ */
				write(i, PTBacVersion, strlen(PTBacVersion));
				continue;
			case 'M':	/* reply with master process id */
				if (0 == (iTok = wInferior)) {
					write(i, "-No\n", 4);
					continue;
				}
				break;
			case 'Q':	/* is in : mode quit after this */
				if (getpid() == wInferior) {
					wInferior = 0;
				}
				if (0 == wInferior) {
					iTok = iClients;
					break;
				}
				write(i, "-No\n", 4);
				continue;
			case 'S':	/* status "Count,size\n" */
				snprintf(acSend, sizeof(acSend), "%u,%u\n", uTargetMax, uTargetSpace);
				write(i, acSend, strlen(acSend));
				continue;
			case 'U':	/* token source name\000 */
				write(i, & cSourceType, 1);
				write(i, acTheSource, strlen(acTheSource)+1);
				continue;
			case 'T':	/* token list inline */
				write(i, pTEList[0].pctoken, uTargetSpace);
				continue;
			case 'P':	/* poll for a single token */
				iTok = TokAlloc(& aPTBook[i]);
				break;
			case 'G':	/* allocate a group of N tokens */
				/* if we don't make it happen, we block them
				 */
				iTok = 0 == aPTBook[i].unumber ? 1 : (int)aPTBook[i].unumber;
				if (iTok > uTargetMax) {
					iTok = -1;
					break;
				}
				/* with -R 3 and -J 100, we stall req 40
				 * forever, I think
				 */
				if (iTok > aPTBook[i].uweight || (TARGET_ENV *)0 == (pTEFound = TokGroup(iTok, & aPTBook[i]))) {
					register PT_BOOK *pPT;
					/* Advance those in-line first
					 */
					for (pPT = pPTQueue; (PT_BOOK *)0 != pPT; pPT = pPT->pPTnext) {
						pPT->uweight += 1;
					}
					aPTBook[i].pPTnext = pPTQueue;
					pPTQueue = & aPTBook[i];
					aPTBook[i].unumber = iTok;
					aPTBook[i].ustate = PB_BLOCK;
					FD_CLR(i, & fdsReading);
					continue;
				}
				aPTBook[i].unumber = 0;
				aPTBook[i].uweight -= iTok;
				SendTokList(i, iTok, pTEFound);
				continue;
			case 'F':	/* free all we hold */
				aPTBook[i].unumber = 0;
				iTok = TokFree((unsigned *)0, &aPTBook[i]);
				break;
			case 'D':	/* release token in number buffer */
				iTok = TokFree(& aPTBook[i].unumber, &aPTBook[i]);
				aPTBook[i].unumber = 0;
				break;
			case 'N':	/* what name for this token? */
				iTok = aPTBook[i].unumber;
				aPTBook[i].unumber = 0;
				if (0 > iTok || iTok > uTargetMax) {
					write(i, "-No\n", 4);
					continue;
				}
				write(i, "+", 1);
				write(i, pTEList[iTok].pctoken, strlen(pTEList[iTok].pctoken));
				write(i, "\n", 1);
				continue;
			case 'O':	/* pid owner of this token numbner? */
				/* zero means "no lock", -1 mean no token */
				iTok = aPTBook[i].unumber;
				aPTBook[i].unumber = 0;
				if (0 > iTok || iTok > uTargetMax) {
					iTok = -1;
				} else {
					iTok = pTEList[iTok].wlock;
				}
				break;
			case 'H':	/* later, host that pid lives on */
				/* ZZZ implement by changing wlock's meaning */
				write(i, "-Not yet\n", 9);
				continue;
			case 'J':	/* justification token width	*/
				iTok = uTargetWidth;
				break;
			case 'R':	/* -R uReq I was given */
				iTok = uReq;
				break;
			default:	/* unknonw command */
				write(i, "-No\n", 4);
			case '\n':	/* silent sync */
				aPTBook[i].unumber = 0;
				continue;
			}
			snprintf(acSend, sizeof(acSend), "%d\n", iTok);
			write(i, acSend, strlen(acSend));
		}
		while (iMaxPoll > sCtl && PB_IDLE == aPTBook[iMaxPoll].ustate) {
			--iMaxPoll;
		}

		/* We have a token for some client, wake them up.
		 */
		while ((PT_BOOK *)0 != (pPTCur = DeQueue(& pPTQueue))) {
			i = pPTCur-aPTBook;
			iTok = aPTBook[i].unumber;
			if ((TARGET_ENV *)0 == (pTEFound = TokGroup(iTok, pPTCur))) {
				write(i, "-No\n", 4);
			} else {
				SendTokList(i, iTok, pTEFound);
			}
			aPTBook[i].unumber = 0;
			aPTBook[i].uweight -= iTok;
			aPTBook[i].ustate = PB_ONLINE;
			FD_SET(i, & fdsReading);
		}
	}
}

/* Setup the toll booth and run the state machine above			(ksb)
 */
static void
TollBooth(int argc, char **argv)
{
	register const char *pcArgv0, *pcOuterLevel;
	register unsigned uBoothLevel;
	auto int sCtl;
	static char *apcDefArgv[2];

	if (0 == argc || (char **)0 == argv || (char *)0 == argv[0]) {
		argc = 1;
		argv = apcDefArgv;
		if ((char *)0 == (apcDefArgv[0] = getenv("SHELL"))) {
			apcDefArgv[0] = "sh";
		}
		apcDefArgv[1] = (char *)0;
	}
	if ((char *)0 == (pcOuterLevel = divCurrent((char *)0))) {
		uBoothLevel = 1;
	} else {
		uBoothLevel = atoi(pcOuterLevel)+1;
	}

	atexit(CleanUp);
	SafePlace(pcOuterLevel);
	SetTargets(pcTags);
	sCtl = Bindings(uBoothLevel);
	if (':' == argv[0][0] && '\000' == argv[0][1] && (char *)0 == argv[1]) {
		if (-1 == wInferior)
			wInferior = getpid();
	} else switch (wInferior = fork()) {
	case -1:
		fprintf(stderr, "%s: fork: %s\n", progname, strerror(errno));
		(void)chdir("/");
		exit(EX_OSERR);
	case 0:
		(void)close(sCtl);
		pcArgv0 = argv[0];
		if (0 != strcmp(acPtbwName, progname)) {
			argv[0] = progname;
		}
		(void)execvp(pcArgv0, argv);
		fprintf(stderr, "%s: execvp: %s: %s\n", progname, argv[0], strerror(errno));
		exit(EX_OSERR);
	default:
		break;
	}

	/* We are not really a daemon, but we don't want to be in the way,
	 * so free us from stdin, stdout, and the current working dir.
	 * We keep stderr for messages, but shouldn't spew any.
	 */
	(void)close(0);
	(void)open("/dev/null", O_RDONLY, 0666);
	(void)close(1);
	(void)open("/dev/null", O_WRONLY, 0666);
	(void)chdir(pcMySpace);
	FiniteStates(sCtl);
	close(sCtl);
	(void)chdir("/");
	fInfOpts = 0;
	Death('T');
	exit(wInfExits);
}

/* Support for the client side, first the "status report"		(ksb)
 * This is poor form: put with scanf, and get with write.  We use the
 * "\n" on the end of the previous message to stop fscanf.  Be warned,
 * and don't do this w/o an Understanding -- ksb
 */
static int
JustStats(int sMaster)
{
	register FILE *fpFrom;
	register char *pcTokTable, *pcCursor;
	register int i, c;
	auto char acCvt[MAXPATHLEN+4];
	auto unsigned int uMasterR, uMasterL;

	if ((FILE *)0 == (fpFrom = fdopen(sMaster, "rb+"))) {
		fprintf(stderr, "%s: fdopen: %d: %s\n", progname, sMaster, strerror(errno));
		return 32;
	}
	if ((char *)0 == (pcTokTable = malloc((uOurSize|7)+1))) {
		return 35;
	}
	if (1 != write(sMaster, "T", 1)) {
		return 36;
	}
	if (uOurSize != fread((void *)pcTokTable, sizeof(char), uOurSize, fpFrom)) {
		return 38;
	}
	if (3 != write(sMaster, "RJU", 3)) {
		return 39;
	}
	fscanf(fpFrom, " %u", & uMasterR);
	if ('\n' != (c = fgetc(fpFrom))) {
		return 40;
	}
	fscanf(fpFrom, " %u", & uMasterL);
	if ('\n' != (c = fgetc(fpFrom))) {
		return 41;
	}
	printf("%s: master has %d tokens, max length %u (total space %d)\n", progname, uOurCount, uMasterL, uOurSize);
	printf(" Master tokens from ");
	c = fgetc(fpFrom);
	switch (c) {
	case '=':
		printf("the internal function: ");
		break;
	case '+':
		printf("file: ");
		break;
	case '-':
		printf("error: ");
		break;
	default:
		printf("key %c: ", c);
		break;
	}
	while ('\000' != (c = fgetc(fpFrom))) {
		putchar(c);
	}
	printf("\n Index\tLock\tTokens (request in groups of %u)\n", uMasterR);
	pcCursor = pcTokTable;
	for (i = 0; i < uOurCount; ++i) {
		snprintf(acCvt, sizeof(acCvt), "%dO", i);
		write(sMaster, acCvt, strlen(acCvt));
		printf("%6d\t", i);
		while ('\n' != (c = fgetc(fpFrom)) && EOF != c)
			putchar(c);
		printf("\t%s\n", pcCursor);
		pcCursor += strlen(pcCursor)+1;
	}
	fclose(fpFrom);
	return 0;
}

/* Add the resource to the old argv, return the new one, only		(ksb)
 * copy the strings we must (not the last, or the old argv).
 */
static char **
Extender(char **ppcOld, char *pcList)
{
	register char **ppcRet, *pcNl, *pcNext;
	register int i;

	/* Count the length of the existing argument vector;
	 * add one for the last one, add one for each \n separator,
	 * round up and allocate one for the sentinal (char *)0.
	 */
	for (i = 0; (char *)0 != ppcOld[i]; ++i) {
		/*  count'em */
	}
	++i;
	for (pcNl = pcList; (char *)0 != (pcNext = strchr(pcNl, '\n')); pcNl = pcNext+1) {
		++i;	/* add'em */
	}
	i |= 3;
	ppcRet = calloc(i+1, sizeof(char *));

	/* Copy exactly what we counted
	 */
	for (i = 0; (char *)0 != ppcOld[i]; ++i) {
		ppcRet[i] = ppcOld[i];
	}
	for (pcNl = pcList; (char *)0 != (pcNext = strchr(pcNl, '\n')); pcNl = pcNext+1) {
		*pcNext = '\000';
		ppcRet[i++] = strdup(pcNl);
		*pcNext = '\n';
	}
	ppcRet[i++] = pcNl;
	ppcRet[i] = (char *)0;
	return ppcRet;
}

/* We are the client side, like xclate we include a client wrapper.	(ksb)
 * Block for a resource and run the given command with $ptbw_list
 * set to the one we locked.
 */
static void
Client(int argc, char **argv)
{
	register int sHandle;
	register char *pcToken, *pcArgv0;
	register const char *pcOuter;

	pcOuter = divSelect();
	if (-1 == (sHandle = PTBClientPort(pcOuter))) {
		fprintf(stderr, "%s: %s: cannot establish client connection\n", progname, pcOuter);
		exit(EX_DATAERR);
	}
	if (0 == argc || ('-' == argv[0][0] && '\000' == argv[0][1])) {
		exit(JustStats(sHandle));
	}
	if (0 == uReq) {
		divResults((const char *)0);
		pcToken = (char *)0;
	} else if ((char *)0 == (pcToken = PTBReadTokenList(sHandle, uReq, (unsigned int **)0))) {
		fprintf(stderr, "%s: -R %u: cannot allocate resources: %s\n", progname, uReq, strerror(errno));
		exit(EX_CANTCREAT);
	} else {
		divResults(pcToken);
	}
	switch (wInferior = fork()) {
	case -1:
		fprintf(stderr, "%s: fork: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	case 0:
		close(sHandle);
		if (fAppend && (char *)0 != pcToken) {
			argv = Extender(argv, pcToken);
		}
		pcArgv0 = argv[0];
		if (0 != strcmp(acPtbwName, progname)) {
			argv[0] = progname;
		}
		(void)execvp(pcArgv0, argv);
		fprintf(stderr, "%s: execvp: %s: %s\n", progname, argv[0], strerror(errno));
		exit(EX_OSERR);
	default:
		break;
	}
	/* cleanup from our inferiour process and any step-children
	 */
	fInfOpts = 0;
	Death('C');

	/* Tell the master to abandon forever (:) mode, we get back the
	 * number of client connected (ourself included) which we ignore.
	 * If we got back "-No\n", then the master was not in : mode -- ksb
	 */
	if (fQuit) {
		PTBQuit(sHandle, (char *)0, 0);
	}
	close(sHandle);
	exit(wInfExits);
}

/* Get a subset of our masters tokens to distribute to our clients	(ksb)
 * N.B. our return must be a pointer to malloc/calloc'd memory, or (char *)0
 */
static char *
BorrowTarget(char *pcDirect, unsigned int iGoal, unsigned int *puOut, char *pcSource)
{
	register int sParent;
	register unsigned int iTry;
	register char *pcRet, *pcNl;

	*puOut = 0;
	pcRet = (char *)0;
	if ((char *)0 == pcDirect) {
		pcDirect = divSelect();
	}
	if (-1 == (sParent = PTBClientPort(pcDirect))) {
		fprintf(stderr, "%s: %s: %s\n", progname, pcDirect, strerror(errno));
		exit(EX_DATAERR);
	}
	if ((char *)0 != pcSource) {
		cSourceType = PTBReqSource(sParent, pcSource, MAXPATHLEN, &pcComments);
	}
	if (uOurCount < uReq) {
		fprintf(stderr, "%s: not enough tokens from our master to make even a single %u group (only %u)\n", progname, uReq, uOurCount);
		exit(EX_DATAERR);
	}
	for (iTry = (iGoal < uReq) ? uReq : iGoal; uReq <= iTry; iTry -= uReq) {
		if (uOurCount < iTry) {
			continue;
		}
		if ((char *)0 == (pcRet = PTBReadTokenList(sParent, iTry, (unsigned int **)0))) {
			continue;
		}
		break;
	}
	if (fQuit) {
		PTBQuit(sParent, (char *)0, 0);
	}
	if ((char *)0 == pcRet) {
		return pcRet;
	}
	/* convert to internal format from protocol \n format
	 */
	for (pcNl = strchr(pcRet, '\n'); (char *)0 != pcNl; pcNl = strchr(pcNl, '\n')) {
		*pcNl++ = '\000';
	}
	*puOut = iTry;
	return pcRet;
}
/* from util_errno.m */
/* from util_tmp.m */
/* from util_cache.m */
/* from util_nproc.m */
/* from util_divstack.m */
/* from util_divconnect.m */
/* from std_help.m */
/* from std_version.m */
/* from ptbc.m */
#line 30 "ptbc.m"
/* given a socket, and that the peer is calling "PTBPidSend" at this	(ksb)
 * point in the protocol, we return the pid of the peer.  Gross on
 * some versions of UNIX (for sure).  We can recv pid@host for wrapw,
 * but we toss the @host part still.
 */
int
PTBPidRecv(int s, char *pcRemember, size_t wMax)
{
	register int i, fNeg;
	register char *pcFrom;
	auto char acPid[1024];

	pcFrom = (char *)0;
	fNeg = 0;
	for (i = 0; i < sizeof(acPid); ++i) {
		if (1 != read(s, acPid+i, 1))
			return -1;
		if ('-' == acPid[i])
			fNeg = 1, --i;
		if (isspace(acPid[i]))
			break;
		if ('@' != acPid[i])
			continue;
		pcFrom = & acPid[i+1];
		acPid[i] = '\000';
	}
	acPid[i] = '\000';
	if ((char *)0 != pcRemember) {
		if ((char *)0 == pcFrom) {
			pcFrom = "localhost";
		}
		strncpy(pcRemember, pcFrom, wMax);
	}
	return fNeg ? -1 : atoi(acPid);
}
#line 74 "ptbc.m"
/* send our pid to the other process, somehow				(ksb)
 */
int
PTBPidSend(int s, char *pcSrc)
{
	register int iLen;
	auto char acPid[64+MAXHOSTNAMELEN+4];

	if ((char *)0 != pcSrc && strlen(pcSrc) < MAXHOSTNAMELEN) {
		snprintf(acPid, sizeof(acPid), "%ld@\n", (long)getpid());
	} else {
		snprintf(acPid, sizeof(acPid), "%ld\n", (long)getpid());
	}
	iLen = strlen(acPid);
	return iLen == write(s, acPid, iLen) ? 0 : -1;
}

/* The divConnect code has a hook to finish the connection;		(ksb)
 * this is how we finish a ptbw diversion connection.
 * send our pid, as for an 'S' command, read for "iCount,iSize\n"
 */
int
PTBConnHook(int s, void *pvLevel)
{
	register int iFailed, e;
	register unsigned int *pu;
	auto char acMaster[64];

	if ((void *)0 == pvLevel || -1 == s) {
		return s;
	}
	uOurCount = uOurSize = 0;
	pu = & uOurCount;
	iFailed = -1 == PTBPidSend(s, (char *)0) || 1 != write(s, "S", 1);
	if (!iFailed) while (1 == read(s, acMaster, 1)) {
		if ('\000' == acMaster[0] || '\n' == acMaster[0]) {
			break;
		}
		if (',' == acMaster[0]) {
			pu = & uOurSize;
			continue;
		}
		if (!isdigit(acMaster[0])) {
			iFailed = 1;
			continue;
		}
		*pu *= 10;
		*pu += acMaster[0]-'0';
	}
	if (!iFailed) {
		return s;
	}
	e = errno;
	(void)close(s);
	errno = e;
	return -1;
}

/* Make the client port, connect it to the parent server		(ksb)
 * stolen from ptyd, also protected from being passed to a child.
 * Pass pcDirect = /tmp-dir/socket-name to contact
 * a ptbw-like service.
 *
 * We want to keep the hook above from diddling the wrapw socket. So
 * we force the divNextLevel to be a NULL pointer, the divconnect.mc
 * code uses that as a queue to pass a (void *)0 for pvLevel. If you
 * wanted to deference or map it you'd have to code a functor.
 *
 * "But nobody wants to hear this tail, the plot is cliche, the
 *  jokes are stale.  And maybe we've all heard it all before."
 *				Amiee Mann _invisible_ink_
 */
int
PTBClientPort(const char *pcDirect)
{
	register int s;
	auto void *(*pfpvKeep)(void *);
	auto int (*pfiKeep)(int, void *);
	auto char acNotVoid[4];

	pfiKeep = divConnHook;
	divConnHook = PTBConnHook;
	pfpvKeep = divNextLevel;
	divNextLevel = (void *(*)(void *))0;
	/* Now we sent the creds over after we connect, but any
	 * wrapw pvLevel is forced be a (void *)0.
	 */
	s = divConnect(pcDirect, RightsWrap, acNotVoid);
	divConnHook = pfiKeep;
	divNextLevel = pfpvKeep;
	return s;
}
#line 172 "ptbc.m"
/* Allocate as many tokens as we ask for from the master.		(ksb)
 * We over allocate the memory, but I don't care so much.  We _must_
 * return a valid malloc/free/realloc pointer.
 */
char *
PTBReadTokenList(int sMaster, unsigned int uNeed, unsigned int **ppuList)
{
	register unsigned *puList;
	register unsigned int i, iFailed;
	register char *pcMem, *pcRet;
	auto char acCvt[64];

	if ((unsigned int **)0 != ppuList) {
		*ppuList = (unsigned int *)0;
	}
	if (0 == uNeed) {
		return (char *)0;
	}
	if ((unsigned int *)0 == (puList = calloc(uNeed, sizeof(unsigned int)))) {
		errno = ENOSPC;
		return (char *)0;
	}
	snprintf(acCvt, sizeof(acCvt), "%uG", uNeed);
	write(sMaster, acCvt, strlen(acCvt));
	iFailed = i = 0;
	while (1 == read(sMaster, acCvt, 1)) {
		if ('\n' == acCvt[0]) {
			break;
		}
		if (',' == acCvt[0]) {
			++i;
			continue;
		}
		if ('-' == acCvt[0]) {
			iFailed = 1;
			continue;
		}
		if (isdigit(acCvt[0])) {
			puList[i] *= 10;
			puList[i] += acCvt[0]-'0';
			continue;
		}
#if PTBC_ECHO
		/* stderr for strings that don't look like what we expect
		 */
		(void)write(2, acCvt, 1);
#endif
	}
	if (iFailed || i+1 != uNeed) {
		errno = ENETRESET;
		return (char *)0;
	}

	/* Worst case is we get back the whole token table
	 */
	pcMem = pcRet = malloc((uOurSize|7)+1);
	if ((unsigned int **)0 != ppuList) {
		*ppuList = puList;
	}
	for (i = 0; i < uNeed; ++i) {
		if (0 != i) {
			*pcMem++ = '\n';
		}
		snprintf(acCvt, sizeof(acCvt), "%uN", puList[i]);
		write(sMaster, acCvt, strlen(acCvt));
		if (1 != read(sMaster, pcMem, 1) || '+' != *pcMem) {
			errno = EPROTOTYPE;
			return (char *)0;
		}
		for (; 1 == read(sMaster, pcMem, 1); ++pcMem) {
			if ('\n' == *pcMem) {
				break;
			}
		}
		*pcMem = '\000';
	}
	return pcRet;
}
#line 256 "ptbc.m"
/* Return these tokens back to the master's tablea			(ksb)
 * reply with the number of tokens we still hold (from this list), 0 is Good
 * XXX we could make fewer calls to write(2) here, by a lot. -- ksb
 */
unsigned int
PTBFreeTokenList(int sMaster, unsigned int uHold, unsigned int *puList)
{
	register int uScan, uFailed;
	register int i, iLen, fPanic;
	auto char acCvt[64];

	if ((unsigned int *)0 == puList) {
		return uHold;
	}
	fPanic = 0;
	for (uFailed = uScan = 0; uScan < uHold; ++uScan) {
		if (fPanic)  {
			puList[uFailed++] = puList[uScan];
			continue;
		}
		snprintf(acCvt, sizeof(acCvt), "%uD", puList[uScan]);
		iLen = strlen(acCvt);
		if (iLen != write(sMaster, acCvt, iLen)) {
			fPanic = 1;
			puList[uFailed++] = puList[uScan];
			continue;
		}
		for (i = 0; i < sizeof(acCvt); ++i) {
			if (1 != read(sMaster, acCvt+i, 1)) {
				fPanic = 1;
				puList[uFailed++] = puList[uScan];
				continue;
			}
			if (isspace(acCvt[i])) {
				break;
			}
		}
		acCvt[i] = '\000';
		if (1 != atoi(acCvt)) {
			puList[uFailed++] = puList[uScan];
		}
	}
	return uFailed;
}
#line 306 "ptbc.m"
/* Send the master a command, get back an int, or -No, or -1		(ksb)
 */
int
PTBCmdInt(int sMaster, int cCmd)
{
	register int i, c;
	auto char acBuffer[64];

	errno = 0;
	if (sMaster < 0) {
		errno = ENETDOWN;
		return -1;
	}
	if (cCmd < 1 || cCmd > 255) {
		errno = ERANGE;
		return -1;
	}
	acBuffer[0] = cCmd;
	if (1 != write(sMaster, acBuffer, 1)) {
		/* errno from write */
		return -1;
	}
	c = ' ';
	for (i = 0; '\n' != c && i < sizeof(acBuffer); ++i) {
		if (1 != read(sMaster, acBuffer+i, 1)) {
			/* errno from read */
			return -1;
		}
		c = acBuffer[i];
		if (isspace(c)) {
			break;
		}
	}
	if (i == 3 && '-' == acBuffer[0] && 'N' == acBuffer[1] && 'o' == acBuffer[2]) {
		errno = EINVAL;
		return -1;
	}
#if defined(ENOTSUP)
	errno = ENOTSUP;	/* show remote protocol failed as status */
#else
#if defined(EPROTONOSUPPORT)
	errno = EPROTONOSUPPORT;
#else
	errno = ENOPROTOOPT;
#endif
#endif
	acBuffer[i] = '\000';
	return atoi(acBuffer);
}
#line 361 "ptbc.m"
/* Is the name maybe a PTBW (or the like) socket			(ksb)
 */
int
PTBIsSocket(char *pcName)
{
	auto struct stat stThis;

	if (-1 == stat(pcName, &stThis))
		return 0;
	return 0 != (S_IFSOCK == (S_IFMT & stThis.st_mode));
}
#line 378 "ptbc.m"
/* Request the source file for the tokens we are using			(ksb)
 * send "U", get "+path\000" or "-No\000"
 * request the meta information (token comments) in *ppcMeta, when non NULL
 */
int
PTBReqSource(int sMaster, char *pcSource, size_t iMax, char **ppcMeta)
{
	auto char acCheck[2];

	if (1 != write(sMaster, "U", 1)) {
		return -1;
	}
	if (1 != read(sMaster, acCheck, 1)) {
		return -1;
	}
	while (1 == read(sMaster, pcSource, 1) && '\000' != *pcSource++) {
		if (iMax-- < 1)
			break;
	}
	if ((char **)0 != ppcMeta) {
		register int iC = 0;

		*ppcMeta = (char *)0;
		if (-1 != (iC = PTBCmdInt(sMaster, 'C'))) {
			*ppcMeta = calloc((iC|7)+1, sizeof(char));
		}
		if ((char *)0 != *ppcMeta) {
			(void)read(sMaster, *ppcMeta, iC);
		}
	}
	return acCheck[0];
}
#line 416 "ptbc.m"
/* Build the iota (-1) vector						(ksb)
 */
char *
PTBIota(unsigned int uMax, unsigned int *puWidth)
{
	register char *pcCur, *pcMem;
	register unsigned uSize, uCur, uWide, uRem, uBase, uDone;

	uSize = uDone = 0;
	uRem = uMax;
	uBase = 10;
	for (uWide = 1, uCur = 10; uCur < uRem; ++uWide, uCur = uBase-uDone) {
		uSize += uCur*uWide;
		uDone += uCur;
		/* next cycle */
		uRem -= uCur;
		uBase *= 10;
	}
	/* add residual + \000's for string terminators
	 */
	uSize += uRem*uWide + uMax;
	if ((unsigned int *)0 != puWidth) {
		*puWidth = uWide;
	}
	pcCur = pcMem = malloc((uSize|7)+1);
	*pcMem = '\000';
	++uWide;	/* include the '\000' for snprintf below */
	for (uCur = 0; uCur < uMax; ++uCur) {
		snprintf(pcCur, uWide, "%u", uCur);
		pcCur += strlen(pcCur)+1;
	}
	return pcMem;
}
#line 455 "ptbc.m"
/* Tell a persistand instance to end					(ksb)
 * When we return -1 we couldn't send it, 0 for not persistant, 1 for OK
 */
int
PTBQuit(int sMaster, char *pcReply, unsigned uLen)
{
	auto char acCvt[256];

	if ((char *)0 == pcReply || 0 == uLen) {
		pcReply = acCvt, uLen = sizeof(acCvt);
	}
	if (1 != write(sMaster, "Q", 1))
		return -1;
	if (0 >= read(sMaster, pcReply, uLen))
		return -1;
	return '-' == pcReply[0] ? 0 : 1;
}
#line 478 "ptbc.m"
/* Tell us the pid of the master, via the 'M' command			(ksb)
 * When we return 0 we couldn't get it.
 */
int
PTBReadPid(int sMaster, pid_t *pwMaster)
{
	auto char acCvt[64];

	if (1 != write(sMaster, "M", 1))
		return 0;
	if (0 >= read(sMaster, acCvt, sizeof(acCvt)) || !isdigit(acCvt[0]))
		return 0;
	if ((pid_t *)0 != pwMaster)
		*pwMaster = atoi(acCvt);
	return 1;
}
/* from hosttype.m */

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
#line 1 "util_cache.mc"
/* $Id: util_cache.mc,v 8.35 2008/12/30 17:04:38 ksb Exp $
 * Cache a file into a mallloc'd space count and break the lines	(ksb)
 * into C strings, we'll read a pipe, but none-to-fast.  We require
 * string.h to get size_t. You can join seq lines by replacing the '\000's.
 * Return a pointer to the first line: calling free(3) on that return
 * value frees _all_ the lines for easy cleanup.  Growing file races used
 * to be a problem, now they are just slow (as we read 512 bytes/race).
 */
char *
cache_file(int u_iFd, unsigned int *u_puLines)
{
	register char *pc, *pcMem;
	register int iCc;
	register size_t uCur, uMax, uFetch;
	register unsigned int uLines;
	auto struct stat stFd;

	if (-1 == fstat(u_iFd, & stFd)) {
		fprintf(stderr, "%s: fstat: %d: %s\n", progname, u_iFd, strerror(errno));
		return (char *)0;
	}
	uFetch = stFd.st_size;
	uMax = (uFetch|1023)+1;
	if ((void *)0 == (pcMem = (char *)malloc(uMax))) {
		fprintf(stderr, "%s: malloc: %lu: %s\n", progname, (unsigned long)uMax, strerror(errno));
		return (char *)0;
	}
	if (uFetch < 1) {
		uFetch = uMax/2;
	}
	for (uCur = 0; 0 < (iCc = read(u_iFd, pcMem+uCur, uFetch)); /*nada*/) {
		uCur += iCc, uFetch -= iCc;
		if (uFetch < 1024) {
			uFetch = 512;
		}
		if (uCur+uFetch > uMax) {
			uMax += 4096;
			pcMem = realloc((void *)pcMem, uMax);
		}
	}
	if (-1 == iCc) {
		fprintf(stderr, "%s: read: %d: %s\n", progname, u_iFd, strerror(errno));
		free((void *)pcMem);
		return (char *)0;
	}

	/* zip though the space, count and replace the '\n's
	 */
	pc = & pcMem[uCur];
	if (pc > pcMem && '\n' == pc[-1]) {
		--pc;
	}
	uLines = 0;
	while (pc > pcMem) {
		++uLines;
		*pc = '\000';
		while (pc > pcMem && '\n' != *pc)
			--pc;
	}

	if (pc != pcMem) {
		fprintf(stderr, "%s: cache_file: invarient broken\n", progname);
		pc = pcMem;
	}
	if ('\n' == *pc) {
		++uLines;
		*pc = '\000';
	}
	if ((unsigned *)0 != u_puLines) {
		*u_puLines = uLines;
	}
	return pcMem;
}

/* Convert the cached file to an argv vector				(ksb)
 * Using a cached file from above build a (char **) index into the lines.
 * Later we can unload the file to reclaim the space with the following func.
 * Return a (char **)0 when we can't allocate space.
 */
char **
cache_vector(char *pcMem, unsigned int uLines)
{
	register char **ppcRet, **ppcArgv;

	if ((char *)0 == pcMem) {
		return (char **)0;
	}
	if ((char **)0 == (ppcRet = (char **)calloc(uLines+2, sizeof(char *)))) {
		return (char **)0;
	}
	*ppcRet++ = pcMem;
	ppcArgv = ppcRet;
	while (0 < uLines) {
		*ppcArgv++ = pcMem;
		pcMem = strchr(pcMem, '\000')+1;
		--uLines;
	}
	*ppcArgv = (char *)0;
	return ppcRet;
}

/* Dispose of the cached file, give me back the pointer you got		(ksb)
 * from the call to cache_vector, above.  You can mess with the vector
 * (qsort it, etc) but don't go beyond the ends (ppc[-1] is mine, dude).
 * Return 0 always.
 */
int
cache_dispose(char **u_ppcVector)
{
	if ((char **)0 == u_ppcVector || (char *)0 == u_ppcVector[-1]) {
		return 0;
	}
	--u_ppcVector;
	free((void *)u_ppcVector[0]);
	u_ppcVector[0] = (char *)0;
	free((void *)u_ppcVector);
	return 0;
}
#line 1 "util_nproc.mc"
/* $Id: util_nproc.mc,v 1.2 2006/09/05 14:26:15 ksb Exp $
 */
#line 8 "util_nproc.mc"

unsigned long
util_nproc()
{
	/* AS/LINUX uses Posix, as far as I can tell
	 */
	return (unsigned long)sysconf(_SC_NPROCESSORS_ONLN);
#line 46 "util_nproc.mc"
}
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
	fprintf(fpOut, "%s: environment prefix \"%s\"\n", progname, acPtbwName);
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

	pcRet = pcTags;
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
			fprintf(stderr, ", do you mean to specify option `-t' as \"%s\"?", pcOuter);
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
		sbOpt[] = "#:AdhJ:mN:p:qQR:t:V",
		*u_pch = (char *)0;
	static int
		u_loop = 0;
	register int u_curopt;
	register char *u_pcEnv;
	extern char *getenv();
	extern int atoi();
	extern int atoi();
	extern int atoi();

	if ((char *)0 == argv[0]) {
		progname = "ptbw";
	} else if ((char *)0 == (progname = strrchr(argv[0], '/'))) {
		progname = argv[0];
	} else {
		++progname;
	}
	divInit(acPtbwName, "option `-t'");
	if ((char *)0 != (u_pcEnv = getenv("PTBW"))) {
		u_envopt(u_pcEnv, & argc, & argv);
	}
	/* "ptbw" forces no options */
	if ((char *)0 != (u_pcEnv = getenv("TMPDIR"))) {
		pcTmpdir = u_pcEnv;
	}
	iIotaMin = 1+(7*util_nproc())/4;
	if ((char *)0 == pcTmpdir || '\000' == *pcTmpdir) {
		pcTmpdir = "/tmp";
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
		case 'A':
			u_chkonly('A', u_curopt, "m");
			fAppend = ! 0;
			continue;
		case 'd':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-d' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fPublish = ! 1;
			continue;
		case 'h':
			u_chkonly('h', u_curopt, "m");
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
		case 'J':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-J' may only be given after option `-m'\n", progname);
				exit(1);
			}
			fGaveJ = 1;
			iTaskMin = atoi(u_optarg);
			continue;
		case 'm':
			u_chkonly('m', u_curopt, "AVhm");
			u_gave_m = 1;
			fMaster = ! 0;
			continue;
		case 'N':
			if (0 == u_gave_m) {
				fprintf(stderr, "%s: option `-N' may only be given after option `-m'\n", progname);
				exit(1);
			}
			pcBindHere = u_optarg;
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
			fQuiet = ! 0;
			continue;
		case 'Q':
			fQuit = ! 0;
			continue;
		case 'R':
			fGaveReq = 1;
			uReq = atoi(u_optarg);
			continue;
		case 't':
			pcTags = u_optarg;
			continue;
		case 'V':
			u_chkonly('V', u_curopt, "m");
			printf("%s: %s\n", progname, rcsid);
			Version();
			exit(0);
		}
		break;
	}
	/* alternate for option m */
	if (u_gave_m) {
		TollBooth((argc-u_optInd), & argv[u_optInd]);
		exit(0);
		/*NOTREACHED*/
	}
	Client((argc-u_optInd), & argv[u_optInd]);
	exit(0);
	/*NOTREACHED*/
}
