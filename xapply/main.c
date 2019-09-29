/* mkcmd generated user interface
 * built by mkcmd version 8.17 Rel
 *  $Compile: ${cc-gcc} -g %f -o %F
 */

#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sysexits.h>
#include "machine.h"
#include "fdrights.h"
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
extern int errno;

/* from getopt.m */
/* from getopt_key.m */
/* from xapply.m */
#line 40 "xapply.m"
static char rcsid[] =
	"$Id: xapply.m,v 3.55 2010/05/03 14:42:12 ksb Exp $";
extern char **environ;
extern int errno;
static void Tasks(int, unsigned int);
static const char acEmpty[] = "";
static char acXCL_D[] = "xcl_d";
static char acPtbwLink[] = "ptbw_link";
/* from std_help.m */
/* from std_version.m */
/* from std_control.m */
/* from util_pipefit.m */
/* from util_cache.m */
/* from util_divconnect.m */
#line 10 "util_divconnect.m"
void *(*divNextLevel)(void *pvThisLevel) = (void *(*)(void *))0;
int (*divConnHook)(int fd, void *pvLevel) = (int (*)(int, void *))0;
/* from ../ptbw/ptbc.m */
#line 22 "../ptbw/ptbc.m"
static char PTBacVersion[] =
	"0.4\n";
#line 27 "../ptbw/ptbc.m"
extern int PTBPidRecv(int, char *, size_t);
#line 68 "../ptbw/ptbc.m"
static unsigned int uOurCount, uOurSize;
#line 71 "../ptbw/ptbc.m"
extern int PTBClientPort(const char *pcDirect), PTBPidSend(int s, char *pcSrc);
#line 169 "../ptbw/ptbc.m"
extern char *PTBReadTokenList(int sMaster, unsigned int uNeed, unsigned int **ppuList);
#line 253 "../ptbw/ptbc.m"
extern unsigned int PTBFreeTokenList(int sMaster, unsigned int uHold, unsigned int *puList);
#line 303 "../ptbw/ptbc.m"
extern int PTBCmdInt(int sMaster, int cCmd);
#line 358 "../ptbw/ptbc.m"
extern int PTBIsSocket(char *);
#line 375 "../ptbw/ptbc.m"
extern int PTBReqSource(int sMaster, char *pcSource, size_t iMax, char **ppcMeta);
#line 413 "../ptbw/ptbc.m"
extern char *PTBIota(unsigned int uMax, unsigned int *puWidth);
#line 452 "../ptbw/ptbc.m"
extern int PTBQuit(int sMaster, char *pcReply, unsigned uLen);
#line 475 "../ptbw/ptbc.m"
extern int PTBReadPid(int sMaster, pid_t *pwMaster);
/* from util_errno.m */
#line 8 "util_errno.m"
extern int errno;
/* from argv.m */
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
#line 1 "util_pipefit.mi"
/* $Id: util_pipefit.mi,v 1.1 2007/09/16 20:34:59 ksb Exp $
 */
static pid_t PipeFit(const char *pcExec, char **ppcArgv, char **ppcEnv, int iFd);
#line 1 "util_cache.mi"
/* $Id: util_cache.mi,v 8.32 2008/09/05 16:24:54 ksb Exp $
 * forward declaration of file caching code				(ksb)
 */
extern char *cache_file(int u_iFd, unsigned int *u_puLines);
extern char **cache_vector(char *pcCache, unsigned int u_uLines);
extern int cache_dispose(char **u_ppcVector);
#line 1 "util_divconnect.mi"
/* $Id: util_divconnect.mi,v 1.1 2008/08/25 14:16:40 ksb Exp $
 */
extern int divConnect(const char *pcSocket, int (*pfiIndir)(int fd, char *pcCookie, void *pvData, char *pcType), void *pvLevel);
char
	*progname = "$Id$",
	*au_terse[] = {
		" [-Adgmnsuvx] [-count] [-a c] [-e var=dicer] [-i input] [-J tokens] [-N else] [-Pjobs] [-R req] [-S shell] [-t tags] cmd [args]",
		" -f [-Adgmnsuvxz] [-count] [-a c] [-e var=dicer] [-i input] [-J tokens] [-N else] [-p pad] [-Pjobs] [-R req] [-S shell] [-t tags] cmd [files]",
		" -h",
		" -V",
		(char *)0
	},
	*u_help[] = {
		"-count      number of arguments passed to each command",
		"a c         change the escape character",
		"A           append the tokens as shell parameters",
		"d           keep any xclate usage out of the published chain",
		"e var=dicer set var to the expansion of dicer for each process",
		"f           arguments are read indirectly one per line from files",
		"cmd         template command to control each task",
		"files       files of arguments to distribute to tasks",
		"g           use gtfw for unique sequential numbers",
		"h           print this help message",
		"i input     change stdin for the child processes",
		"J tokens    number of task instances expected, start a ptbw",
		"m           use xclate to manage output streams",
		"n           do not execute commands, trace only",
		"N else      a command to run when no tasks were otherwise launched",
		"p pad       fill short files with this token",
		"Pjobs       number of tasks to run in parallel",
		"R req       number of resource allocated to each task, start a ptbw",
		"s           pass the squeeze option down to all xclate output filters",
		"S shell     the shell to run tasks under",
		"t tags      list of target resources for %t, connect to (start) a ptbw",
		"u           force the xclate xid to be the expansion of %u",
		"v           be verbose",
		"V           show version information",
		"x           trace actions on stderr",
		"z           read find-print0 output as input files",
		"args        list of arguments to distribute to tasks",
		(char *)0
	},
	**ppcNames = (char **)0,
	*pcIn = (char *)0,
	*pcPtbw = (char *)0,
	*pcXclate = (char *)0;
int
	iPass = 1,
	fGaveJ = 0,
	u_gave_m = 0,
	fGaveR = 0,
	fGavet = 0,
	cEoln = '\n',
	cEsc = '%',
	fAddEnv = 0,
	fPublish = 1;
struct PPMnode /* void */
	*pPPMAddEnv = (void *)0;
int
	fpIn = 0,
	fGtfw = 0;
char
	*pcRedir = (char *)0,
	*pcCmd = (char *)0;
int
	iCopies = 0,
	fManage = 0,
	fExec = 1;
char
	*pcElse = (char *)0,
	*pcPad = "";
unsigned
	iParallel = 1,
	uReq = 1;
int
	fSqueeze = 0;
char
	*pcShell = (char *)0,
	*pcTags = (char *)0;
int
	fUniq = 0,
	fVerbose = 0,
	fTrace = 0;
FILE
	**pfpIn = (FILE **)0;

#ifndef u_terse
#define u_terse	(au_terse[0])
#endif
static void
u_chkonly(chSlot, chOpt, pcList)
int chSlot, chOpt;
char *pcList;
{
	register int chWas;
	static int sbiOnly['f'-'#'+1];

	chWas = sbiOnly[chSlot-'#'];
	if (chOpt == chWas) {
		fprintf(stderr, "%s: option `-%c\' cannot be given more than once\n", progname, chWas);
		exit(1);
	} else if (0 != chWas) {
		fprintf(stderr, "%s: option `-%c\' forbidden by `-%c\'\n", progname, chOpt, chWas);
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
/* from xapply.m */
#line 1 "dicer.c"
/*@Version $Revision: 6.19 $@*/
/*@Header@*/
/* $Id: dicer.c,v 6.19 2009/10/16 15:38:39 ksb Exp $
 * Most of the code to implement %[dicer separator field] and %(dicer,mixer)
 * $Compile: ${cc-cc} -DDICER_TEST -g -Wall -o %F %f
 */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#if DEBUG
#include <stdio.h>
#endif

/*@Shell %echo ${MACHINE_H+"$MACHINE_H"}%@*/
#include "dicer.h"

/*@Explode dicer@*/
char DicerVersion[] =
	"$Id: dicer.c,v 6.19 2009/10/16 15:38:39 ksb Exp $";

/* Select a substring from the parameter we just found			(ksb)
 * this allows us to get params from the password/group file
 * We can recurse to get subfields...
 * We can split on any single character, or "white space".
 * If you want more, use an RE, or try Mixer as a turbo.
 *
 * The field number can be a base 10 number, or "$" for the last
 * in the record.  The empty count is taken as 1.
 * If we need memory and can't malloc it we return (char *)0.
 * Max is the length left in the buffer (in) and the size we wrote (out),
 * we '\000' terminate the string if we have room.
 */
char *
Dicer(char *pcDest, unsigned *puMax, char *pcTemplate, char *pcData)
{
	register int cSep, iCount, iNeg;
	auto char cKeep;
	auto char *pcEnd, *pcOrig, *pcAt;
	static char acEos[] = "\000";
	auto unsigned uMaxDown = 0;
	auto char *pcMem = (char *)0;

	if ((unsigned *)0 == puMax) {
		uMaxDown = strlen(pcData)+1;
		puMax = &uMaxDown;
	}
	switch (*pcTemplate) {
	case DICER_END:	/* we have it */
		++pcTemplate;
	case '\000':	/* we lost the closing bracket. humph */
		(void)strncpy(pcDest, pcData, *puMax);
		*puMax = strlen(pcDest);
		return pcTemplate;
	case '\\':
		++pcTemplate;
		cSep = *pcTemplate++;
		break;
	case ' ':
		cSep = -1;
		++pcTemplate;
		break;
	default:
		cSep = *pcTemplate++;
		break;
	}
	/* %[n sep @ _...] build the loop, return the cat of the results
	 */
	pcAt = (char *)0;
	if ('@' == *pcTemplate) {
		register char *pcCur, *pcEos;
		auto unsigned uSize, uLimit;

		pcAt = ++pcTemplate;
		if ((char *)0 == (pcMem = strdup(pcData))) {
			return (char *)0;
		}
		pcData = pcMem;
		uLimit = *puMax;

		pcEos = (char *)0;
		while ((char *)0 != pcData && '\000' != *pcData && uLimit > 1) {
			if ((char *)0 != pcEos) {
				*pcDest++ = (-1 == cSep) ? ' ' : cSep;
				--uLimit;
			}
			pcCur = pcData;
			if (-1 == cSep) {
				while ('\000' != *pcData && !isspace(*pcData)) {
					++pcData;
				}
				pcEos = pcData;
				while (isspace(*pcData)) {
					++pcData;
				}
				*pcEos = '\000';
			} else if ((char *)0 == (pcEos = strchr(pcData, cSep))) {
				pcData = acEos;
			} else {
				*pcEos++ = '\000';
				pcData = pcEos;
			}
			uSize = uLimit;
			pcTemplate = Dicer(pcDest, &uSize, pcAt, pcCur);
			if ((char *)0 == pcTemplate) {
				free((void *)pcMem);
				return (char *)0;
			}
			uLimit -= uSize;
			pcDest += uSize;
		}
		free((void *)pcMem);
		if ('\000' != *pcData) {
			return (char *)0;
		}
		if (0 != (*puMax -= uLimit)) {
			*pcDest = '\000';
		}
		return pcTemplate;
	}
	/* %[1 -$] and %[1 -1] are unshift, and pop
	 */
	if ((iNeg = ('-' == *pcTemplate))) {
		++pcTemplate;
	}
	if ('$' == *pcTemplate) {
		iCount = -1;
		++pcTemplate;
	} else if (! isdigit(*pcTemplate)) {
		iCount = 1;
	} else {
		iCount = 0;
		do {
			iCount *= 10;
			iCount += *pcTemplate++ - '0';
		} while (isdigit(*pcTemplate));
	}
	/* locate the field they want
	 */
	pcOrig = pcData;
	while ((-1 == iCount || --iCount > 0) && '\000' != *pcData) {
		register char *pcDollar;

		pcDollar = pcData;
		if (-1 == cSep) {
			while ('\000' != *pcData && !isspace(*pcData)) {
				++pcData;
			}
			while (isspace(*pcData)) {
				++pcData;
			}
			if ('\000' == *pcData) {
				if (-1 == iCount)
					pcData = pcDollar;
				break;
			}
			continue;
		}
		pcData = strchr(pcData, cSep);
		if ((char *)0 == pcData) {
			pcData = (-1 == iCount) ? pcDollar : acEos;
			break;
		}
		++pcData;
	}
	/* find end of field
	 * pcOrig ... pcData ... pcEnd ... \000
	 */
	if (-1 == cSep) {
		pcEnd = pcData;
		while ('\000' != *pcEnd && !isspace(*pcEnd))
			++pcEnd;
		if ('\000' == *pcEnd)
			pcEnd = (char *)0;
	} else {
		pcEnd = strchr(pcData, cSep);
	}
	/* put an EOS ('\000') at the end of the field and call down,
	 * then put it back and return to caller
	 */
	if ((char *)0 != pcEnd) {
		cKeep = *pcEnd;
		*pcEnd = '\000';
	}
	/* Worse, we want to remove the named field, leaving the others,
	 * so build what they asked for.  pcMem is init'd to (char *)0
	 * at the declaration to prevent free'd a junk pointer.
	 */
	if (iNeg && (char *)0 == pcEnd) {
		pcEnd = iCount > 0 ? acEos : pcData-1;
		cKeep = *pcEnd;
		*pcEnd = '\000';
		pcData = pcOrig;
	} else if (iNeg) {
		register int iCursor;
		register unsigned uNeedDown;

		iCursor = *pcData;
		*pcData = '\000';
		uNeedDown = ((strlen(pcOrig)+strlen(pcEnd+1))|255)+1;
		if ((char *)0 == (pcMem = malloc(uNeedDown*sizeof(char)))) {
			return (char *)0;
		}
		(void)strcpy(pcMem, pcOrig);
		(void)strcat(pcMem, pcEnd+1);
		*pcData = iCursor;
		pcData = pcMem;
	}
	pcTemplate = Dicer(pcDest, puMax, pcTemplate, pcData);
	if ((char *)0 != pcEnd) {
		*pcEnd = cKeep;
	}
	if ((char *)0 != pcMem) {
		free((void *)pcMem);
	}
	return pcTemplate;
}

/*@Explode mixer@*/

/* Allow the selection of a charcter range from a string.		(ksb)
 * expr ::= pos [, pos] ;
 * pos ::= <expr> pos | [~](number|$|*) [- (number|$)] | {empty} | "txt";
 * > don't touch the string
 * 1-$> the whole string;  $-1> reverse the string;
 * 1> first character; $> (or ~1) last character; 1,$> first&last character;
 * <$-2><$-2>> all but the first and last characters (Whoa)
 * <$-2><$-2><1,$>,1,$> characters 2 and $-1, 1, and $
 * ~1-4> the last four characters ($ is just shorthand for ~1).
 * We let you output more characters than you sent us.
 * We also let position 0 == 1.
 */
char *
Mixer(char *pcInplace, unsigned *puMax, char *pcExpr, int cExit)
{
	register char *pcMem, *pcTop, *pcAdd;
	register int i, fQuote, iLevel = 0;
	register int iLeft, iRight, iLen, fTilde;
	auto unsigned uSize, uCall, uCurLen, uKeep;

	uKeep = strlen(pcInplace);
	uSize = ((unsigned *)0 == puMax) ? uKeep : *puMax;
	if ((char *)0 == (pcMem = strdup(pcInplace))) {
		return (char *)0;
	}
	iLen = strlen(pcMem);
	pcAdd = (char *)0, uCurLen = iLen;
	pcTop = pcMem;
	fQuote = '\000';
	i = *pcExpr++;
	while ('\000' != i && (cExit != i || '\000' != fQuote)) {
		if (fQuote) {
			if ('\"' == fQuote && '\"' == i) {
				fQuote = '\000';
			} else if ('`' == fQuote && '`' == i) {
				++iLevel;
				if (uSize > 0) {
					*pcInplace++ = i;
					--uSize;
				}
			} else if ('`' == fQuote && '\'' == i) {
				if (0 == --iLevel) {
					fQuote = '\000';
				} else if (0 != uSize) {
					*pcInplace++ = i;
					--uSize;
				}
			} else if (uSize > 0) {
				if (0 != uSize) {
					*pcInplace++ = i;
					--uSize;
				}
			}
			i = *pcExpr++;
			continue;
		}
		if ('\"' == i || '`' == i) {
			iLevel = 1;
			fQuote = i;
			i = *pcExpr++;
			uKeep = 0;
			continue;
		}
		if (',' == i || ' ' == i || '\t' == i) {
			i = *pcExpr++;
			if (pcMem != pcTop) {
				free((char *)pcTop);
				pcTop = pcMem;
			}
			pcAdd = (char *)0, uCurLen = iLen;
			continue;
		}
		if (MIXER_RECURSE == i) {
			if (pcMem == pcTop) {
				pcTop = malloc((uSize|7)+1);
				(void)strcpy(pcTop, pcMem);
			}
			uCall = uSize;
			if ((char *)0 == (pcExpr = Mixer(pcTop, &uCall, pcExpr, MIXER_END)))
				break;
			pcAdd = pcTop, uCurLen = uCall;
			i = *pcExpr++;
			continue;
		}
		if ((char *)0 == pcAdd) {
			pcAdd = pcTop, uCurLen = iLen;
		}
		if ((fTilde = ('~' == i))) {
			i = *pcExpr++;
		}
		if ('*' == i) {
			i = *pcExpr++;
			(void)strncpy(pcInplace, pcAdd, uSize);
			uCall = strlen(pcInplace);
			uSize -= uCall;
			pcInplace += uCall;
			uKeep = 0;
			continue;
		}
		iLeft = iRight = -1;
		if ('$' == i) {
			i = *pcExpr++;
			if (fTilde) {
				iLeft = 0, iRight = 1;
			} else {
				iLeft = uCurLen-1, iRight = uCurLen;
			}
		} else if (isdigit(i)) {
			iLeft = 0;
			do {
				iLeft *= 10;
				iLeft += i - '0';
				i = *pcExpr++;
			} while (isdigit(i));
			if (fTilde) {
				if (1 > (iLeft = uCurLen+1-iLeft))
					iLeft = 1;
			}
			if (iLeft > 0) {
				--iLeft;
			}
		} else {
			/* syntax error, left side */
			return (char *)0;
		}
		if ('-' == i) {
			i = *pcExpr++;
			if ((fTilde = ('~' == i))) {
				i = *pcExpr++;
			}
			if ('$' == i || '*' == i) {
				i = *pcExpr++;
				iRight = fTilde ? 1 : uCurLen;
			} else if (isdigit(i)) {
				iRight = 0;
				do {
					iRight *= 10;
					iRight += i - '0';
					i = *pcExpr++;
				} while (isdigit(i));
				if (fTilde && 1 > (iRight = uCurLen+1-iRight)) {
					iRight = 1;
				}
				if (0 == iRight) {
					iRight = 1;
				}
			} else {
				/* syntax, missing right side */
				return (char *)0;
			}
			if (iLeft >= uCurLen && iRight <= uCurLen) {
				iLeft = uCurLen-1;
			}
		}
		if (iLeft >= uCurLen) {
			/* empty request */
		} else {
			if (-1 == iRight) {
				iRight = iLeft+1;
			} else if (iRight > uCurLen) {
				iRight = uCurLen;
			}
			if (iRight <= iLeft ) {
				++iLeft, --iRight;
				while (iLeft > iRight && uSize > 0) {
					*pcInplace++ = pcAdd[--iLeft];
					--uSize;
				}
			} else {
				while (iLeft < iRight && uSize > 0) {
					*pcInplace++ = pcAdd[iLeft++];
					--uSize;
				}
			}
		}
		uKeep = 0;
		*pcInplace = '\000';
		pcAdd = (char *)0, uCurLen = iLen;
	}
	if ((char *)0 != pcAdd && 0 != uKeep) {
		(void)strncpy(pcInplace, pcAdd, uSize);
		uKeep = strlen(pcInplace);
	}
	if (pcMem != pcTop) {
		free((void *)pcTop);
	}
	free((void *)pcMem);
	if ((unsigned *)0 != puMax) {
		*puMax -= uSize-uKeep;
	}
	return pcExpr;
}

/*@Explode slicer@*/
static char acOffEnd[] = "*too*big*";
static char *pcOffEnd = acOffEnd;

/* Like the generic xapply %1, %2, ... %n dicer loop,			(ksb)
 * most programs with just a vector of elements should use this.
 * Copy characters as-is, except %N, %{N} and %[N...] (last calls the dicer),
 * allow %% to stand for %, of course.
 * Max is the max to output (in), and the size we wrote (out)
 */
char *
Slicer(char *pcTo, unsigned *puMax, char *pcDicer, char **ppcList)
{
	register int i, iIndex, fDice, fGroup, fMixer;
	register char **ppcDatum, *pcError;
	auto unsigned uSize, uCall;

	uSize = ((unsigned *)0 == puMax) ? strlen(pcTo) : *puMax;
	fGroup = '\000';
	while ('\000' != (*pcTo = *pcDicer)) {
		if (1 > uSize) {
			break;
		}
		--uSize;
		if ('%' != *pcTo) {
			++pcTo, ++pcDicer;
			continue;
		}
		if ('%' == (i = *++pcDicer)) {
			++pcTo;
			++pcDicer;
			continue;
		}
		if ((fMixer = (MIXER_RECURSE == i))) {	/* enable the mixer */
			i = *++pcDicer;
		}
		if (0 != (fDice = (DICER_START == i))) {
			fGroup = ']';
			i = *++pcDicer;
		} else if ('{'/*}*/ == i) {
			fGroup = /*{*/ '}';
			i = *++pcDicer;
		} else {
			fGroup = '\000';
		}
		/* This is where you'd expand your own markup, else
		 * we need a digit to select an input word. -- ksb
		 */
		if (!isdigit(i)) {
			return (char *)0;	/* syntax error		*/
		}
		pcError = pcDicer-1;
		iIndex = 0;
		do {
			iIndex *= 10;
			iIndex += i - '0';
			i = *++pcDicer;
			if ('\000' == fGroup)
				break;
			if (fGroup == i)
				break;
		} while (isdigit(i));

		/* find the one in the data list we need
		 */
		for (ppcDatum = ppcList; iIndex-- > 1; ++ppcDatum) {
			if ((char *)0 == *ppcDatum)
				break;
		}
		if ((char *)0 == *ppcDatum) {
			if ((char *)0 == pcOffEnd)
				return pcError;		/* beyond vector end */
			ppcDatum = & pcOffEnd;
		}
		if (fDice) {
			uCall = uSize;
			pcDicer = Dicer(pcTo, &uCall, pcDicer, *ppcDatum);
			if ((char *)0 != pcDicer && fGroup == *pcDicer)
				++pcDicer;
		} else {
			uCall = strlen(*ppcDatum);
			if (uCall >= uSize) {
				/* we could break here -- ksb? */
				return (char *)0;	/* too big	*/
			}
			(void)strcpy(pcTo, *ppcDatum);
			if ('\000' == fGroup) {
				/* don't look */;
			} else if (fGroup != *pcDicer) {
				return (char *)0; /* error: missing close */
			} else {
				++pcDicer;
			}
		}
		if ((char *)0 != pcDicer && fMixer) {
			uCall = uSize;
			pcDicer = Mixer(pcTo, &uCall, pcDicer, MIXER_END);
		}
#if DEBUG
		if (strlen(pcTo) != uCall) {
			fprintf(stderr, "debug mixer: insane length (%u != %u) [dicer source line %d]\n", strlen(pcTo), uCall, __LINE__);
			uCall = strlen(pcTo);
		}
#endif
		if ((char *)0 == pcDicer) {
			break;
		}
		pcTo += uCall;
		uSize -= uCall;
	}
	*pcTo = '\000';
	if ((unsigned *)0 != puMax) {
		*puMax -= uSize;
	}
	/* Unless we filled buffer, this is the empty string
	 */
	return pcDicer;
}

/*@Remove@*/

#if defined(DICER_TEST)
/*@Explode main@*/
#include <stdio.h>
#include <string.h>

/* test driver								(ksb)
 */
typedef struct TDnode {
	char *pctemplate;
	char *pcdata;
	char *pccorrect;
	char *pcremainder;
} TEST_DICER;

static char acWord[] = "word";
static char acEmpty[] = "";
static char acX[] = "x";

TEST_DICER aTDOK[] = {
	{" @]", "1.2.3.4   A.B.C.D  I.II.III.IV", "1.2.3.4 A.B.C.D I.II.III.IV", ""},
	{      "", acWord, acWord, acEmpty},		/* super liberal */
	{     "1", acWord, acWord, acEmpty},		/* oops case */
	{     "1", acWord, acWord, acEmpty},		/* be liberal here */
	{    "1]", acWord, acWord, acEmpty},	/* normal case */
	{   "1]x", acWord, acWord, acX},		/* have a tail */
	{  "1 2]", "remove word", acWord, acEmpty},
	{  "1 1]", "word remove", acWord, acEmpty},
	{ "1 -1]", "clip word", acWord, acEmpty},
	{ "1 -2]", "word clip", acWord, acEmpty},
	{ "1 2]x", "remove word", acWord, acX},
	{ "1 1]x", "word remove", acWord, acX},
	{"1 -1]x", "clip word", acWord, acX},
	{"1 -2]x", "word clip", acWord, acX},
	{"\\13]", "131word1wrong1", acWord, acEmpty},
	{"\\13]", "131word1wrong1", acWord, acEmpty},
	{"1.-3]",    "aa.bb.cc.dd", "aa.bb.dd", acEmpty},
	{"1.-3.-2]", "aa.bb.cc.dd", "aa.dd", acEmpty},
	{"1.-2.-2]", "aa.bb.cc.dd", "aa.dd", acEmpty},
	{"1.-2.-2", "word.bar.foo", acWord, acEmpty},
	{"1.-2.-2]x", "aa.bb.cc.dd", "aa.dd", acX},
	{"1.-3.-2]x", "aa.bb.cc.dd", "aa.dd", acX},
	{".-$].0", "128.210.11.11", "128.210.11", ".0"},
	{".-2]z", "a..c", "a.c", "z"},
	{".-4]x", "imp.npcguild.org.", "imp.npcguild.org",  "x"},
	{".-$]z", "imp.npcguild.org.", "imp.npcguild.org",  "z"},
	{"/@.2]", "1.2.3.4/A.B.C.D/I.II.III.IV", "2/B/II", ""},
	{"/@.-2]", "1.2.3.4/A.B.C.D/I.II.III.IV", "1.3.4/A.C.D/I.III.IV", ""},
	{"/@.-$].four", "1.2.3.4/A.B.C/I.II", "1.2.3/A.B/I", ".four"},
	{" @.2]", "1.2.3.4   A.B.C.D  I.II.III.IV", "2 B II", ""},
	{" @]", "1.2.3.4   A.B.C.D  I.II.III.IV", "1.2.3.4 A.B.C.D I.II.III.IV", ""},
	{" -2]", "1234", "1234", ""},
	{" -2]", "1234  ", "1234  ", ""},
	{"\\ -2]", "1234  ", "1234 ", ""},
	/* insert more above */
	{acEmpty, acEmpty, acEmpty, acEmpty}
};

static char _ac1[] = "home.example.com",
	_ac2[] =  "100",
	_ac3[] =  "%3";
static char *apcData[] = { _ac1, _ac2, _ac3, (char *)0};
TEST_DICER aTDSlice[] = {
	{     "%([1]\"\")", acEmpty, acEmpty, acEmpty},
	{     "%([1]`\')", acEmpty, acEmpty, acEmpty},
	{     "%([1])", acEmpty, _ac1, acEmpty},
	{     "%([1])", acEmpty, _ac1, acEmpty},
	{    "%([2]*)", acEmpty, "100", acEmpty},
	{   "%([2],*)", acEmpty, "100", acEmpty},
	{ "%([1],1-$)", acEmpty, _ac1, acEmpty},
	{"%([1],~100-100)", acEmpty, _ac1, acEmpty},
	{    "%([1],)", acEmpty, _ac1, acEmpty},
	{"%([1](1-$))", acEmpty, _ac1, acEmpty},
	{    "%([1]1)", acEmpty, "h", acEmpty},
	{    "%([1]$)", acEmpty, "m", acEmpty},
	{   "%([1]~1)", acEmpty, "m", acEmpty},
	{   "%([1]~$)", acEmpty, "h", acEmpty},
	{   "%([1],1)", acEmpty, "h", acEmpty},
	{   "%([1],2)", acEmpty, "o", acEmpty},
	{"%([1.1],1-$)", acEmpty, "home", acEmpty},
	{"%([1.1],1-~1)", acEmpty, "home", acEmpty},
	{ "%([1.1],$-1)", acEmpty, "emoh", acEmpty},
	{  "%([1.1],~1)", acEmpty, "e", acEmpty},
	{"%([1.1](~1-2))", acEmpty, "emo", acEmpty},
	{"%([1.1](~2-1))", acEmpty, "moh", acEmpty},
	{"%(2,2-~2)", acEmpty, "0", acEmpty},
	{"%(2,($-2)($-2))", acEmpty, "0", acEmpty},
	{"%([1.1]$)%([1.2](1,$))", acEmpty, "eee", acEmpty},
	{ "%([1.1]3,3)", acEmpty, "mm", acEmpty},
	{"%([1.2](1-4)($$))", acEmpty, "mm", acEmpty},
	{ "%([1.3],$,$)", acEmpty, "mm", acEmpty},
	{"%([1.1]3,3)%([1.2](1-4)($$))%([1.3],$,$)", acEmpty, "mmmmmm", acEmpty},
	{"(%([1.1],*,*))", acEmpty, "(homehome)", ""},
	{"(%([1.1]**))", acEmpty, "(homehome)", ""},
	{"%([2\01]1\"'\"`_\"')", acEmpty, "1'_\"", ""},
	{"%([2]1,\"-\",2-3,`-\',$)", acEmpty, "1-00-0", ""},
	{"%([2](\"'\",*,\"`\"))", acEmpty, "'100`", ""},
	{"%([2](\"'\",*,\"`\")($-1))", acEmpty, "`001'", ""},
	{"%([2](\"'\",*,\"`\")($-1))", acEmpty, "`001'", ""},
	{"%([2](`\"',*,`\"'))", acEmpty, "\"100\"", ""},
	{"%([2](`(\',*,`)\'))", acEmpty, "(100)", ""},
	{"(%([2](*,`)\'))", acEmpty, "(100)", ""},
	{"%([2](*,\"-\",*))", acEmpty, "100-100", ""},
	{"%([2](1-$,`-',$-1))", acEmpty, "100-001", ""},
	{"%([2]($-2,`1',2-$))", acEmpty, "00100", ""},
	{"%(2,0-0)", "", "1", ""},	/* this is a little liberal */
	{"%(2,8-0)", "", "001", ""},
	{"%(2,3-0)", "", "001", ""},
	{"%(2,2-0)", "", "01", ""},
	{"%(2,2-1)", "", "01", ""},
	{"%(2,4)", "", "", ""},
	{"%(2,4-5)", "", "", ""},
	{"%(2,5-3)", "", "0", ""},
	/* insert more Mixer checks above */
	{      "", acEmpty, acEmpty, acEmpty},
	{    "1964", acEmpty, "1964", acEmpty},
	{      "%1", acEmpty, _ac1, acEmpty},
	{    "%[1]", acEmpty, _ac1, acEmpty},
	{    "%{1}", acEmpty, _ac1, acEmpty},
	{    "%{2}", acEmpty, _ac2, acEmpty},
	{    "%[3]", acEmpty, _ac3, acEmpty},
	{  "%[1.1]", acEmpty, "home", acEmpty},
	{"%[1.1] %[2 $]", acEmpty, "home 100", acEmpty},
	{      "%%", acEmpty, "%", acEmpty},
	{      "%9", acEmpty, acOffEnd, ""},
	/* insert more Dicer checks above */
};

int
main(int argc, char **argv)
{
	register char *pcRes, *pcBufWrong, *pcRemWrong;
	register int i, iExit;
	auto unsigned uSize;
	auto char acWriteMe[8192];
	auto char acBuffer[8192];
	static char acFailed[] = " [failed]";

	iExit = 0;
	for (i = 0; i < sizeof(aTDOK)/sizeof(aTDOK[0]); ++i) {
		pcRemWrong = pcBufWrong = acEmpty;
		uSize = sizeof(acBuffer);
		(void)strcpy(acWriteMe, aTDOK[i].pcdata);
		pcRes = Dicer(acBuffer, &uSize, aTDOK[i].pctemplate, acWriteMe);
		if (0 != strcmp(acBuffer, aTDOK[i].pccorrect)) {
			pcBufWrong = acFailed;
		}
		if (0 != strcmp(pcRes, aTDOK[i].pcremainder)) {
			pcRemWrong = acFailed;
		}
		if (acEmpty == pcBufWrong && acEmpty == pcRemWrong) {
			continue;
		}
		printf("\"%s\" \"%%[%s\" -> \"%s\".\"%s\"\n\t\"%s\"%s\n\t\"%s\"%s\n", aTDOK[i].pcdata, aTDOK[i].pctemplate, aTDOK[i].pccorrect, aTDOK[i].pcremainder, acBuffer, pcBufWrong, pcRes, pcRemWrong);
		++iExit;
	}
	for (i = 0; i < sizeof(aTDSlice)/sizeof(aTDSlice[0]); ++i) {
		pcRemWrong = pcBufWrong = acEmpty;
		uSize = sizeof(acBuffer);
		pcRes = Slicer(acBuffer, &uSize, aTDSlice[i].pctemplate, apcData);
		if ((char *)0 == pcRes) {
			printf("slice failed for \"%s\"\n", aTDSlice[i].pctemplate);
			continue;
		}
		if (0 != strcmp(acBuffer, aTDSlice[i].pccorrect)) {
			pcBufWrong = acFailed;
		}
		if (0 != strcmp(pcRes, aTDSlice[i].pcremainder)) {
			pcRemWrong = acFailed;
		}
		if (acEmpty == pcBufWrong && acEmpty == pcRemWrong) {
			continue;
		}
		printf("Slice \"%s\" {list} -> \"%s\".\"%s\"\n got \"%s\"%s\n\t\"%s\"%s\n", aTDSlice[i].pctemplate, aTDSlice[i].pccorrect, aTDSlice[i].pcremainder, acBuffer, pcBufWrong, pcRes, pcRemWrong);
		++iExit;
	}

	/* Check for full buffer return, just once -- ksb
	 * There are other cases here, but I don't want to code the tests.
	 */
	pcRemWrong = pcBufWrong = acEmpty;
	uSize = 10;
	/* 11003322<overflow> (which leaves the "%" on the end) -- ksb
	 */
	if ((char *)0 != (pcRes = Slicer(acBuffer, &uSize, "1%23322%1", apcData)) || 0 != strcmp("11003322%", acBuffer)) {
		printf("Slicer failed the overflow test: %s %s\n", acBuffer, pcRes);
		++iExit;
	}
	exit(0 != iExit);
}
/*@Remove@*/
#endif
#line 213 "xapply.m"
/* if we do not have NCARGS in <sys/param.h> try posix or guess		(ksb)
 */
#if !defined(NCARGS)
#include <limits.h>
#if defined(ARG_MAX)
#define NCARGS	ARG_MAX
#else
#define NCARGS	4000
#endif
#endif

#if !defined(MAX_XID_LEN)
#define MAX_XID_LEN	64		/* xclate'd xid limit, or so	*/
#endif

/* These all are nice to know						(ksb)
 */
static void
Version()
{
	printf("%s:  %s\n", progname, DicerVersion);
	printf("%s: shell: %s\n", progname, pcShell);
	printf("%s: xclate as %s\n", progname, pcXclate);
	printf("%s: xclate xid length limit %d\n", progname, MAX_XID_LEN);
	printf("%s: xclate -d environment \"%s\"\n", progname, acXCL_D);
	printf("%s: ptbw as %s, protocol %.*s\n", progname, pcPtbw, (int)strlen(PTBacVersion)-1, PTBacVersion);
	printf("%s: ptbw link environment \"%s\"\n", progname, acPtbwLink);
}

/* Keep up with -t targets -- ksb
 */
typedef struct TEnode {
	char **ppctokens;	/* uReq of them */
	unsigned int *publock;	/* uReq of these too */
	pid_t wlock;
} TARGET_ENV;
static TARGET_ENV *pTEList = (TARGET_ENV *)0;
static unsigned uTargetCursor = 0, uTargetMax = 0;

/* Take a list of tokens and put them in the local bookkeeping format	(ksb)
 * thay can be sep'd with '\n' or '\000', either.
 */
static void
LocalPool(char *pcList, unsigned int uCount, unsigned *puList, unsigned int uBlob)
{
	register TARGET_ENV *pTE;
	register unsigned int i, uFill;
	register char *pcNl, **ppcMem;

	if (0 == uBlob) {
		uBlob = 1;
	}
	ppcMem = (char **)calloc(uCount, sizeof(char *));
	pTEList = (TARGET_ENV *)calloc(iParallel, sizeof(TARGET_ENV));
	if ((TARGET_ENV *)0 == pTEList) {
		fprintf(stderr, "%s: calloc: %u,%u: %s\n", progname, uCount, (unsigned)sizeof(TARGET_ENV), strerror(errno));
		exit(EX_OSERR);
	}
	pTE = pTEList;
	for (i = 0, uFill = uBlob; i < uCount; ++i, ++uFill) {
		if ((char *)0 != (pcNl = strchr(pcList, '\n'))) {
			*pcNl = '\000';
		}
		if (uBlob == uFill) {
			pTE->ppctokens = ppcMem;
			pTE->publock = ((unsigned *)0 == puList) ? (unsigned *)0 : puList+i;
			pTE->wlock = 0;
			++pTE;
			uFill = 0;
		}
		*ppcMem++ = pcList;
		pcList += strlen(pcList)+1;
	}
	uTargetMax = pTE-pTEList;
}

static char **ppcManage, *pcSlaveXid;
/* We need an xclate in the process tree above us.			(ksb)
 * when we don't have one, we become it and make xapply our command.
 */
static void
XCLOverlay(argc, argv)
int argc;
char **argv;
{
	register char *pcXEnv = (char *)0, *pcTail;
	register char **ppcOver;
	register int i;

	if (fPublish ? ((char *)0 != getenv("xcl_link")) : (char *)0 != (pcXEnv = getenv(acXCL_D))) {
		/* 8 ~= xclate [-u $xcl_d] [-s] xid (char *)0 pad pad
		 */
		ppcManage = (char **)calloc(8, sizeof(char *));
		if ((char **)0 == ppcManage || (char *)0 == (pcSlaveXid = (char *)malloc((MAX_XID_LEN|7)+1))) {
			fprintf(stderr, "%s: building xclate argv: no memory\n", progname);
			exit(EX_OSERR);
		}
		i = 0;
		ppcManage[i++] = pcXclate;
		if (!fPublish) {
			ppcManage[i++] = "-u";
			ppcManage[i++] = strdup(pcXEnv);
			(void)unsetenv(acXCL_D);
		}
		if (fSqueeze) {
			ppcManage[i++] = "-s";
		}
		ppcManage[i++] = strcpy(pcSlaveXid, "~");
		ppcManage[i++] = (char *)0;
		return;
	}
	/* xclate -m[d] [-s] -- argv + (char *)0  =>  4+roundup(argc)
	 */
	ppcOver = (char **)calloc((argc|3)+5, sizeof(char *));
	if ((char **)0 == ppcOver) {
		fprintf(stderr, "%s: calloc: %d: cannot allocate argv for %s\n", progname, argc+4, pcXclate);
		exit(EX_OSERR);
	}
	i = 0;
	if ((char *)0 != (pcTail = strrchr(pcXclate, '/'))) {
		++pcTail;
	} else {
		pcTail = pcXclate;
	}
	ppcOver[i++] = pcTail;
	ppcOver[i++] = fPublish ? "-m" : "-md";
	if (fSqueeze) {
		ppcOver[i++] = "-s";
	}
	ppcOver[i++] = "--";
	while (argc-- > 0) {
		ppcOver[i++] = *argv++;
	}
	ppcOver[i] = (char *)0;
	(void)execvp(ppcOver[0], ppcOver);
	(void)execve(pcXclate, ppcOver, environ);
	fprintf(stderr, "%s: execve: %s: %s\n", progname, pcXclate, strerror(errno));
	exit(EX_UNAVAILABLE);
}

static int sMaster = -1;
static char *pcDyna = (char *)0;

/* Get tokens from our ptb-wrapped					(ksb)
 * send "T", get the list, ask for <iParallel*uReq>G, then
 * back off by 1's to just <uReq>
 */
static char *	/*ARGUSED*/
DynaTokens(char *pcDirect, unsigned int *puMine, unsigned int **ppuOut)
{
	register char *pcRet;
	register unsigned int i, uTry;
	auto char acSource[MAXPATHLEN+4];

	pcRet = (char *)0;
	if ((unsigned int *)0 != puMine) {
		*puMine = 0;
	}
	if ((char *)0 == pcDirect) {
		register char *pcEnv;

		if ((char *)0 == (pcEnv = getenv(acPtbwLink))) {
			fprintf(stderr, "%s: $%s: no enclosing ptbw\n", progname, acPtbwLink);
			exit(EX_DATAERR);
		}
#if HAVE_SNPRINTF
		snprintf(acSource, sizeof(acSource), "ptbw_%s", pcEnv);
#else
		sprintf(acSource, "ptbw_%s", pcEnv);
#endif
		if ((char *)0 == (pcDirect = getenv(acSource))) {
			fprintf(stderr, "%s: $%s: not found in the environment\n", progname, acSource);
			exit(EX_PROTOCOL);
		}
	}
	if (-1 == (sMaster = PTBClientPort(pcDirect))) {
		fprintf(stderr, "%s: %s: no connection: %s\n", progname, pcDirect, strerror(errno));
		exit(EX_NOINPUT);
	}
	if (-1 != PTBReqSource(sMaster, acSource, sizeof(acSource), (char **)0)) {
		pcDyna = strdup(acSource);
	}

	uTry = 0;
	for (i = iParallel; i > 0; --i) {
		uTry = uReq * i;
		if (uTry > uOurCount)
			continue;
		if ((char *)0 != (pcRet = PTBReadTokenList(sMaster, uTry, ppuOut)))
			break;
	}
	if (0 == i) {
		fprintf(stderr, "%s: ptbw cannot provide %u tokens (only %u available)\n", progname, uReq, uOurCount);
		exit(EX_DATAERR);
	}
	if ((unsigned int *)0 != puMine) {
		*puMine = uTry;
	}
	return pcRet;
}

/* If we need a ptb-wrapper around it make it so			(ksb)
 * then use it to get the targets we need, before any kids get them.
 * If we don't need a wrapper just fix up the options and return with
 * the internal target list inplace.
 * "-t -"	-> get tokens from existing ptbw
 * "-t file"	-> start a new ptbw, replace with -t -
 * -J N		-> start a new ptbw, pass down
 * -R rep	-> passed to new ptbw, only as given
 */
static void
PTBOverlay(int argc, char **argv, unsigned int uJobs)
{
	static char acMySelf[] = "XAPPLY_WRAP";
	auto char **ppcPTBArgv;
	auto char acCvt[128];
	auto unsigned uMine, *puList;
	register char *pcList, *pcBuffer;
	register unsigned int i;
	register int iCopy;
	register pid_t wCvt;

	pcList = (char *)acEmpty;
	puList = (unsigned int *)0;
	uMine = 0;
	wCvt = -1;	/* assume we can't be pid -1 */
	if ((char *)0 != (pcBuffer = getenv(acMySelf)) && '\000' != *pcBuffer) {
		wCvt = atoi(pcBuffer);
		(void)unsetenv(acMySelf);
	}

	/* We are the child of a ptbw we started, or told to look at one
	 * we didn't start then look to it for tokens.  Else we don't really
	 * need the passible transaction buster widgit [:-)].
	 */
	if (wCvt == getppid()) {
		if (0 == uReq) {
			uMine = uJobs;
			pcList = PTBIota((unsigned) uJobs, (unsigned int *)0);
		} else {
			pcTags = "-";
			pcList = DynaTokens((char *)0, & uMine, & puList);
		}
	} else if (fGavet) {
		if (PTBIsSocket(pcTags)) {
			pcList = DynaTokens(pcTags, & uMine, & puList);
		} else if ('-' == pcTags[0] && '\000' == pcTags[1]) {
			pcList = DynaTokens((char *)0, & uMine, & puList);
		} else {
			/* wrap it up, dude */
		}
	} else if (fGaveJ || (fGaveR && 0 != uReq)) {
		/* wrap me up in a default token list */
	} else {
		uMine = uJobs;
		pcList = PTBIota((unsigned) uJobs, (unsigned int *)0);
	}
	if (acEmpty == pcList) {
		/* fall into wrapper below */
	} else if ((char *)0 != pcList) {
		LocalPool(pcList, uMine, puList, uReq);
		return;
	} else {
		fprintf(stderr, "%s: cannot create resource pool\n", progname);
		exit(EX_SOFTWARE);
	}

	/* We need to wrap ourself in a ptbw, build the command line:
	 *	ptwb -m[q] [-Jjobs] [-Rreq] [-t file] -- argv (char *)0
	 *	   1+   1+       1+      1+        2+ 1+ original-argc  +1
	 */
	if ((char **)0 == (ppcPTBArgv = calloc(((1+1+2+2+2+1+argc+1)|3)+1, sizeof(char *)))) {
		fprintf(stderr, "%s: calloc(%d,%u): %s\n", progname, (1+1+1+2+1)+argc, (unsigned)sizeof(char *), strerror(errno));
		exit(EX_OSERR);
	}
	i = 0;
	/* mkcmd now searches for this, but that means it must be installed
	 * first and our build path matters.  Since msrc now depends on
	 * ptbw it is important to all.
	 */
	if ((char *)0 != (pcBuffer = strrchr(pcPtbw, '/'))) {
		++pcBuffer;
	} else {
		pcBuffer = pcPtbw;
	}
	ppcPTBArgv[i++] = pcBuffer;
	if (fGaveJ) {
		ppcPTBArgv[i++] = "-m";
	} else {
		ppcPTBArgv[i++] = "-mq";
		iCopies = iParallel;
	}
	if (0 != iCopies) {
#if HAVE_SNPRINTF
		snprintf(acCvt, sizeof(acCvt), "-J%d", iCopies);
#else
		sprintf(acCvt, "-J%d", iCopies);
#endif
		ppcPTBArgv[i++] = strdup(acCvt);
	}
	if (fGaveR && 0 != uReq) {
#if HAVE_SNPRINTF
		snprintf(acCvt, sizeof(acCvt), "-R%d", uReq);
#else
		sprintf(acCvt, "-R%u", uReq);
#endif
		ppcPTBArgv[i++] = strdup(acCvt);
	}
	if (fGavet) {
		ppcPTBArgv[i++] = "-t";
		ppcPTBArgv[i++] = pcTags;
	}
	ppcPTBArgv[i++] = "--";
	for (iCopy = 0; iCopy < argc; ++iCopy) {
		ppcPTBArgv[i++] = argv[iCopy];
	}
	ppcPTBArgv[i] = (char *)0;
#if HAVE_SNPRINTF
	snprintf(acCvt, sizeof(acCvt), "%d", (int)getpid());
#else
	sprintf(acCvt, "%d", (int)getpid());
#endif
	setenv(acMySelf, acCvt, 1);
	fflush(stdout);
	execvp(ppcPTBArgv[0], ppcPTBArgv);
	execve(pcPtbw, ppcPTBArgv, environ);
	fprintf(stderr, "%s: execve: %s: %s\n", progname, ppcPTBArgv[0], strerror(errno));
	exit(EX_UNAVAILABLE);
	/*NOTREACHED*/
}

/* Setup the -e option data we'll need in Launch			(ksb)
 */
static char **ppcAddEnv, **ppcAddDice, **ppcAddValue;
static void
SetEnvDriver(char **ppcVec, unsigned int uParams)
{
	register int i, iMax;
	register unsigned int uModuli;
	register char *pcEq;

	ppcAddValue = ppcAddDice = ppcAddEnv = (char **)0;
	if ((char **)0 == ppcVec || (char *)0 == *ppcVec) {
		return;
	}

	for (iMax = 0; (char *)0 != ppcVec[iMax]; ++iMax) {
		/* count them */
	}
	iMax = (iMax|3)+1;
	ppcAddEnv = ppcVec;
	ppcAddDice = (char **)calloc(iMax, sizeof(char *));
	ppcAddValue = (char **)calloc(iMax, sizeof(char *));
	if ((char **)0 == ppcAddValue || (char **)0 == ppcAddDice) {
		fprintf(stderr, "%s: calloc: %d: %s\n", progname, iMax, strerror(errno));
		exit(EX_OSERR);
	}
	uModuli = 0;
	for (i = 0; (char *)0 != ppcVec[i]; ++i) {
		auto char acTemp[64];
		if ((char *)0 == (pcEq = strchr(ppcVec[i], '='))) {
			++uModuli;
			sprintf(acTemp, "%c%u", cEsc, uModuli);
			if (uModuli >= uParams)
				uModuli = 0;
			ppcAddDice[i] = strdup(acTemp);
			continue;
		}
		*pcEq++ = '\000';
		ppcAddDice[i] = pcEq;
		ppcAddValue[i] = (char *)0;
	}
	ppcAddValue[i] = ppcAddDice[i] = (char *)0;
}

/* Put the values in the enviroment from the -e options			(ksb)
 */
static void
DoExportOpts()
{
	register char **ppc;
	register int i;

	if ((char **)0 == (ppc = ppcAddEnv)) {
		return;
	}
	for (i = 0; (char *)0 != ppc[i]; ++i) {
		setenv(ppc[i], ppcAddValue[i], 1);
	}
}

static pid_t *piOwn =	/* pid table we own, last is _our_pid_		*/
	(pid_t *)0;

/* build a list of processes we own, of course the list			(ksb)
 * starts out with just us in it.  We build one extra slot on the end
 * to keep our pid (and in case we get 0 tasks calloc is not NULL).
 * Also setup the environment passdowns, and the %t list.
 */
static void
Tasks(int iMax, unsigned int uParams)
{
	register int i;

	SetEnvDriver(util_ppm_size(pPPMAddEnv, 0), uParams);
	piOwn = (pid_t *)calloc(iMax+1, sizeof(pid_t));
	if ((pid_t *)0 == piOwn) {
		fprintf(stderr, "%s: calloc: pid table[%d]: %s\n", progname, iMax, strerror(errno));
		exit(EX_OSERR);
	}
	piOwn[0] = getpid();
	for (i = 0; i < iMax; ++i)
		piOwn[i+1] = piOwn[i];
}

/* remove the pid from the table, return 1 if it's in there		(ksb)
 * if fDone we also free the %t token allocated to it in the master
 */
static int
Stop(pid_t iPid, int fDone)
{
	register int i, iTok;

	for (i = 0; i < iParallel; ++i) {
		if (piOwn[i] != iPid)
			continue;
		for (iTok = 0; iTok < uTargetMax; ++iTok) {
			if (iPid != pTEList[iTok].wlock)
				continue;
			pTEList[iTok].wlock = 0;
			if (fDone && -1 != sMaster && (unsigned int *)0 != pTEList[iTok].publock) {
				(void)PTBFreeTokenList(sMaster, uReq, pTEList[iTok].publock);
				pTEList[iTok].publock = (unsigned int *)0;
			}
			break;
		}
		piOwn[i] = piOwn[iParallel];
		return 1;
	}
	return 0;
}

/* Get a token from the pool, wait for one if we must			(ksb)
 */
static int
GetToken(TARGET_ENV **ppTEFound)
{
	register int i, iRet;
	register pid_t w;
	auto int wExit;

	iRet = 0;
	*ppTEFound = (TARGET_ENV *)0;
	while (0 != uTargetMax) {
		for (i = uTargetMax; 0 < i; --i, ++uTargetCursor) {
			if (uTargetMax <= uTargetCursor)
				uTargetCursor = 0;
			if (0 != pTEList[uTargetCursor].wlock)
				continue;
			*ppTEFound = & pTEList[uTargetCursor];
			++uTargetCursor;
			return iRet;
		}

		if (0 < (w = wait3(& wExit, 0, (struct rusage *)0))) {
			if (Stop(w, 0))
				++iRet;
		}
	}
	return 0;
}

/* add a process to our list						(ksb)
 */
static void
Start(iPid, pTEThis)
pid_t iPid;
TARGET_ENV *pTEThis;
{
	static int iWrap = 0;

	while (piOwn[iWrap] != piOwn[iParallel]) {
		if (++iWrap == iParallel)
			iWrap = 0;
	}
	piOwn[iWrap] = iPid;
	pTEThis->wlock = iPid;
}

/* Send gtfw a version string so it knows we chat a like protocol	(ksb)
 */
static int
GtfwConnHook(int s, void *pv)
{
	register char *pcEos;
	auto char acReply[256];
	static const char acGtfwProto[] = "0.1";

	if (sizeof(acGtfwProto) != write(s, acGtfwProto, sizeof(acGtfwProto))) {
		fprintf(stderr, "%s: write: %d: %s\n", progname, s, strerror(errno));
		exit(EX_OSERR);
	}
	acReply[0] = '\000';
	if (-1 == read(s, acReply, sizeof(acReply))) {
		fprintf(stderr, "%s: read: %d: %s\n", progname, s, strerror(errno));
		exit(EX_PROTOCOL);
	}
	if (acReply != (pcEos = strchr(acReply, '\n'))) {
		*pcEos = '\000';
		fprintf(stderr, "%s: gtfw: %s\n", progname, acReply);
		exit(EX_PROTOCOL);
	}
	return s;
}

static int sGtfw = -1;			/* fd to chat with gtfw */
static const char *pcIota = ".";	/* %u counter source */

/* Chat up our enclosing gtfw instance for %u tokens			(ksb)
 */
static int
GtfwInit(char *pcLink)
{
	register char *pcDirect;
	auto char acSource[2*MAXPATHLEN+4];	/* host:/domain-socket */
	auto void *(*pfpvKeep)(void *);
	auto int (*pfiKeep)(int, void *);
	auto char acNotVoid[4];
	static const char acFetch[] = "U";

	if ((char *)0 == pcLink) {
		fprintf(stderr, "%s: no enclosing gtfw instance\n", progname);
		exit(EX_NOINPUT);
	}
	snprintf(acSource, sizeof(acSource), "gtfw_%s", pcLink);
	if ((char *)0 == (pcDirect = getenv(acSource))) {
		fprintf(stderr, "%s: gtfw instance mising environment link \"$%s\"\n", progname, acSource);
		exit(EX_PROTOCOL);
	}
	/* gtfw won't love us unless we send a version string
	 */
	pfiKeep = divConnHook;
	divConnHook = GtfwConnHook;
	pfpvKeep = divNextLevel;
	divNextLevel = (void *(*)(void *))0;
	sGtfw = divConnect(pcDirect, RightsWrap, acNotVoid);
	divConnHook = pfiKeep;
	divNextLevel = pfpvKeep;

	/* Ask for the token source, which could be off-host, we could
	 * remove the FQDN of our host if that's the prefix, but we don't.
	 */
	if (sizeof(acFetch)-1 != write(sGtfw, acFetch, sizeof(acFetch)-1) || (1 > read(sGtfw, acSource, sizeof(acSource)))) {
		fprintf(stderr, "%s: lost gtfw diversion\n", progname);
		exit(EX_SOFTWARE);
	}
	if ((char *)0 == (pcIota = strdup(acSource))) {
		fprintf(stderr, "%s: strdup: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	return sGtfw;
}

/* Get a unique integer from an enclosing gtfw				(ksb)
 */
static unsigned
FromGtfw()
{
	register unsigned uRet;
	auto char *pcEos;
	auto char acUniq[256];	/* "%d\n" */
	static const char acFetch[] = "u";
	static int uSeq = 0;

	if (!fGtfw) {
		return uSeq++;
	}
	if (sizeof(acFetch)-1 != write(sGtfw, acFetch, sizeof(acFetch)-1) || (1 > read(sGtfw, acUniq, sizeof(acUniq)))) {
		fprintf(stderr, "%s: lost gtfw diversion\n", progname);
		exit(EX_OSERR);
	}
	uRet = strtoul(acUniq, &pcEos, 0);
	/*  ('\n' != *pcEos) */
	return uRet;
}

static unsigned uSeqUniq = 0;	/* used to number the commands (%u)	*/
static unsigned uSeqInit = 0;	/* used to find zero -N else clause	*/
static char **ppcArgs;

/* Launch the command the User built.					(ksb)
 * If we've done something bad to the system back off by Fibonacci numbers:
 * (viz. 1 2 3 5 8 13 21 34 55 ...) up to a max sleep time of MAX_BACKOFF.
 * If we have no fork() by then we are at MAXPROCS and the caller will
 * wait() for a slot then call us again.  {It might not be us that is at
 * MAXPROCS so we will find no done kid in the wait and spin back here,
 * repeating until the system figures out who to kill.}
 */
#if !defined(MAX_BACKOFF)
#define MAX_BACKOFF	15
#endif
static pid_t
Launch(char *pcBuilt, char *pcXid, TARGET_ENV *pTECur)
{
	register int iPid, iD1, iD2, iTmp;
	register unsigned int u;
	register char *pcRun;
	auto int afdSync[2];
	auto char acNone[8];

	fflush(stdout);
	fflush(stderr);
	afdSync[0] = afdSync[1] = -1;
	if ((fVerbose || fTrace) && -1 == pipe(afdSync)) {
		fprintf(stderr, "%s: pipe: %s\n", progname, strerror(errno));
	}
	for (iD1 = iD2 = 1; iD1 < MAX_BACKOFF; iTmp = iD1, iD1 += iD2, iD2 = iTmp) {
		switch (iPid = fork()) {
		case -1:
			if (errno == EAGAIN || errno == ENOMEM) {
				sleep(iD1);
				continue;
			}
			fprintf(stderr, "%s: fork: %s\n", progname, strerror(errno));
			exit(EX_OSERR);
		case 0:
			DoExportOpts();
			ppcArgs[2] = pcBuilt;
			if (fAddEnv) {
				for (iTmp = 0; (char *)0 != ppcArgs[iTmp]; ++iTmp) {
					/* find the end */
				}
				for (u = 0; u < uReq; ++u) {
					ppcArgs[iTmp++] = pTECur->ppctokens[u];
				}
				ppcArgs[iTmp] = (char *)0;
			}
			/* wait for our parent to close a pipe to tell
			 * us he output the user notification.
			 */
			if (fVerbose || fTrace) {
				close(afdSync[1]);
				(void)read(afdSync[0], acNone, sizeof(acNone));
				close(afdSync[0]);
			}
			pcRun = ppcArgs[0];
			/* -m needs xclate to be our child, not a child of init
			 */
			if (fManage) {
				if ((char *)0 == pcXid || '\000' == *pcXid) {
#if HAVE_SNPRINTF
					snprintf(pcSlaveXid, MAX_XID_LEN, "%u", uSeqUniq);
#else
					sprintf(pcSlaveXid, "%u", uSeqUniq);
#endif
				} else {
					(void)strncpy(pcSlaveXid, pcXid, MAX_XID_LEN);
				}
				iPid = PipeFit(pcRun, ppcArgs, environ, 0);
				pcRun = pcXclate;
				ppcArgs = ppcManage;
				/* we have room for -p now, and iPid XXX */
			}
			execvp(pcRun, ppcArgs);
			execve(pcRun, ppcArgs, environ);
			fprintf(stderr, "%s: execve: %s: %s\n", progname, pcRun, strerror(errno));
			exit(EX_OSERR);
		default:
			if (fVerbose)
				printf("%s\n", pcBuilt);
			if (fTrace)
				fprintf(stderr, "%s\n", pcBuilt);
			/* make sure the customer knows what we're doing before
			 * the child process begins to execute
			 */
			if (fVerbose || fTrace) {
				close(afdSync[0]);
				fflush(stdout);
				close(afdSync[1]);
			}
			return iPid;
		}
	}
	if (fVerbose || fTrace) {
		close(afdSync[0]);
		close(afdSync[1]);
	}
	return -1;
}

/* Compute %* from a list (any of %*, %f*, or %t*)			(ksb)
 * call with ((char **)0, 0) to free space
 */
static char *
CatAlloc(char **ppcList, unsigned int iMax)
{
	register unsigned int i, uNeed;
	register char *pcCat;
	static char *pcMine = (char *)0;
	static unsigned int uMyMax = 0;

	uNeed = 0;
	if ((char **)0 == ppcList) {
		if ((char *)0 != pcMine) {
			free((void *)pcMine);
			pcMine = (char *)0;
		}
		uMyMax = 0;
		return (char *)0;
	}
	if (0 == iMax) {
		static char *apc_[2] = { "", (char *)0 };

		ppcList = apc_;
		iMax = 1;
	}
	for (i = 0; i < iMax; ++i) {
		uNeed += strlen(ppcList[i])+1;
	}
	if (uMyMax < uNeed) {
		if ((char *)0 != pcMine) {
			free((void *)pcMine);
		}
		uNeed |= 31;
		uMyMax = ++uNeed;
		pcMine = (char *)malloc(uNeed);
	}
	if ((char *)0 != pcMine) {
		pcCat = pcMine;
		for (i = 0; i < iMax; ++i) {
			if (0 != i) {
				*pcCat++ = ' ';
			}
			(void)strcpy(pcCat, ppcList[i]);
			pcCat += strlen(ppcList[i]);
		}
	}
	return pcMine;
}

/* Put a backslah quote behind any character that might get		(ksb)
 * expanded by a ksh/sh inside double quotes. viz \ " $ `
 */
static void
ReQuote(char *pcScan, unsigned *puCall, unsigned int uMax)
{
	static char *pcMem = (char *)0;
	static unsigned uMem;
	register char *pcCursor;
	register unsigned uLen;
	register int i;

	uLen = ((*puCall)|63)+1;
	if ((char *)0 == pcMem) {
		uMem = uLen;
		pcMem = (char *)malloc(uLen);
	} else if (uMem < uLen) {
		uMem = uLen;
		pcMem = (char *)realloc((void *)pcMem, uLen*sizeof(char));
	}
	if ((char *)0 == pcMem) {
		fprintf(stderr, "%s: out of memory\n", progname);
		exit(EX_OSERR);
	}

	/* We're clear, copy the source to a safe buffer and quote it back.
	 */
	pcCursor = pcMem;
	(void)memcpy(pcCursor, pcScan, *puCall);
	pcCursor[*puCall] = '\000';
	for (uLen = 0; '\000' != (i = *pcCursor++); ) {
		switch (i) {
		case '\\': case '\"': case '`': case '$':
			pcScan[uLen++] = '\\';
			/* fallthrough */
		default:
			pcScan[uLen++] = i;
			break;
		}
	}
	pcScan[uLen] = '\000';
	*puCall = uLen;
}

/* Build the command from the input data.				(ksb)
 * We know there are enough slots in argv for us to read.
 * We need to construct the command in a buffer and return it,
 * the caller passes in a buffer that is at least NCARGS big.
 * If we never see a parameter expand cat them on the end,
 * apply does this, I think it is brain dead.
 */
static char *
AFmt(pcBuffer, pcTemplate, iPass, argv, ppcNamev, pTEThis, pfTail)
char *pcBuffer, *pcTemplate;
int iPass, *pfTail;
char **argv, **ppcNamev;
TARGET_ENV *pTEThis;
{
	register char *pcScan;
	register int i, cCache, iParam, fSubPart, fGroup, iLimit, fMixer, fDQuote;
	register char **ppcExp, *pcTerm, *pcTidy;
	static unsigned uMax = NCARGS;
	auto unsigned uCall, uHold;
	auto char acNumber[64];

	pcScan = pcBuffer;
	cCache = cEsc;
	fSubPart = 0;
	uHold = 0;
	pcTidy = (char *)0;
	while ('\000' != *pcTemplate) {
		if (cCache != (*pcScan++ = *pcTemplate++)) {
			++uHold;
			continue;
		}
		if (cCache == (i = *pcTemplate++)) {
			continue;
		}
		--pcScan;
		/* %q... quote for doubles, after expanded
		 * %+ shift, %1 called as a template on %2...%$, for hxmd
		 * we used %1, so cancle the tail spell (after we call)
		 */
		if (0 != (fDQuote = ('q' == i))) {
			i = *pcTemplate++;
		}
		if ('+' == i) {
			auto unsigned uStash;
			if (0 == iPass || (char *)0 == argv[0])
				break;
			uStash = uMax;
			uMax -= uHold;
			if ((char *)0 == AFmt(pcScan, argv[0], iPass-1, argv+1, ppcNamev+1, pTEThis, pfTail))
				return (char *)0;
			uMax = uStash;
			*pfTail = 0;
			uCall = strlen(pcScan);
			if (fDQuote) {
				ReQuote(pcScan, & uCall, uMax);
			}
			uHold += uCall;
			pcScan += uCall;
			continue;
		}
		/* %f... for the filename under -f
		 * %t... for the tag-file tokens
		 * %{15} to get to bigger numbers
		 * %[5,1] for subfields (see dicer.c)
		 * %<dicer,mixer> for the mixer character snippr
		 */
		if (0 != (fMixer = MIXER_RECURSE == i)) {
			i = *pcTemplate++;
		}
		if ('f' == i) {
			i = *pcTemplate++;
			if ('t' == i || (('{' == i || '[' == i) && 't' == *pcTemplate)) /*]}*/ {
				/* allow %ft %f[t] and %f{t} w/o -f */
			} else if ('u' == i || (('{' == i || '[' == i) && 'u' == *pcTemplate)) /*]}*/ {
				/* allow %fu %f[u] and %f{u} w/o -f */
			} else if ((char **)0 == ppcNamev) {
				fprintf(stderr, "%s: %cf used without -f\n", progname, cEsc);
				exit(EX_DATAERR);
			}
			ppcExp = ppcNamev;
			iLimit = iPass;
		} else if ('t' == i) {
			static int fBugNTWarn = 1;

			if ('\000' == (i = *pcTemplate++)) {
				fprintf(stderr, "%s: %ct: requires a specification (number, f, )\n", progname, cEsc);
				exit(EX_DATAERR);
			}
			if (fExec || isatty(1)) {
				/* OK -- if they went to the trouble to put us
				 * on a tty they know "what they are doing".
				 */
			} else if (fBugNTWarn) {
				fprintf(stderr, "%s: %ct used with -n, possible locking issues\n", progname, cEsc);
				fBugNTWarn = 0;
			}
			ppcExp = pTEThis->ppctokens;
			iLimit = uReq;
		} else {
			ppcExp = argv;
			iLimit = iPass;
		}
		fGroup = 0;
		if ((fSubPart = '[' == i) || '{' == i) {
			fGroup = 1;
			i = *pcTemplate++;
		}
		/* %u  a uniq number sequence 0, 1, 2, ...
		 * %t  a lock tag, token, thread name, or target from the list
		 * %0-9 a param
		 */
		if ('u' == i || 'U' == i) {
			if (ppcExp == argv) {
				sprintf(acNumber, "%u", uSeqUniq);
				pcTerm = acNumber;
			} else if ((char *)0 == (pcTidy = strdup(pcIota))) {
				fprintf(stderr, "%s: strdup: %s\n", progname, strerror(errno));
				exit(EX_OSERR);
			} else {
				pcTerm = pcTidy;
			}
		} else if ('t' == i || 'T' == i) {
			/* %f[t...] -- provide -t's filename (ksb)
			 */
			if ((char *)0 == (pcTerm = pcDyna)) {
				fprintf(stderr, "%s: %cft: no -t option presented, filename expansion failed\n", progname, cEsc);
				exit(EX_DATAERR);
			}
		} else if (isdigit(i)) {	/* %0, %1 .. %9 */
			if (argv == ppcExp) {
				*pfTail = 0;
			}
			iParam = i - '0';
			while (fGroup) {
				i = *pcTemplate++;
				if (!isdigit(i))
					break;
				iParam *= 10;
				iParam += i - '0';
			}
			if (0 == iParam) {
				pcTerm = (char *)acEmpty;
			} else if (iParam < 1 || iParam > iLimit) {
				fprintf(stderr, "%s: %d: escape references an out of range parameter (%s limit %d)\n", progname, iParam, (argv == ppcExp ? "argument" : pTEThis->ppctokens == ppcExp ? "token" : "file"), iLimit);
				return (char *)0;
			} else {
				pcTerm = ppcExp[iParam-1];
			}
			if (fGroup) {
				--pcTemplate;
			}
		} else if ('$' == i) {	/* last param -- implied by %[1.$] */
			pcTerm = ppcExp[iPass-1];
			if (argv == ppcExp) {
				*pfTail = 0;
			}
		} else if ('*' == i) {
			pcTerm = CatAlloc(ppcExp, iLimit);
			if (argv == ppcExp) {
				*pfTail = 0;
			}
		} else {
			fprintf(stderr, "%s: %c%1.1s: unknown escape sequence\n", progname, cEsc, pcTemplate-1);
			return (char *)0;
		}
		if (fSubPart) {
			uCall = uMax-uHold;
			pcTemplate = Dicer(pcScan, &uCall, pcTemplate, pcTerm);
		} else {
			uCall = strlen(pcTerm);
			if (uHold+uCall < uMax) {
				(void)strcpy(pcScan, pcTerm);
			}
		}
		if (fMixer) {
			uCall = uMax-uHold;
			if ((char *)0 == (pcTemplate = Mixer(pcScan, &uCall, pcTemplate, MIXER_END))) {
				fprintf(stderr, "%s: mixer %c<..%s: syntax error expression\n", progname, cEsc, pcTemplate);
				return (char *)0;
			}
		}
		if (fDQuote) {
			ReQuote(pcScan, & uCall, uMax);
		}
		if ((char *)0 != pcTidy) {
			free((void *)pcTidy);
			pcTidy = (char *)0;
		}
		/* We might have already smacked the stack, but we try
		 * to catch it here --ksb
		 */
		if (uHold+uCall >= uMax) {
			fprintf(stderr, "%s: expansion is too large for NCARGS (%u)\n", progname, NCARGS);
			return (char *)0;
		}
		pcScan += uCall;
		uHold += uCall;
		if (fSubPart) {
			fSubPart = 0;
		} else if (fGroup) {
			if ('}' != *pcTemplate) {
				fprintf(stderr, "%s: %c{..%s: missing close culry (})\n", progname, cEsc, pcTemplate);
				return (char *)0;
			}
			++pcTemplate;
		}
	}
	/* implicit "%1 %2 %3 ..."
	 */
	if (0 != *pfTail) {
		if (pcScan > pcBuffer && !isspace(pcScan[-1])) {
			*pcScan++ = ' ';
		}
		for (i = 0; i < iPass; ++i) {
			if (0 != i) {
				*pcScan++ = ' ';
			}
			(void)strcpy(pcScan, argv[i]);
			pcScan += strlen(pcScan);
		}
		*pfTail = 0;
	}
	*pcScan = '\000';
	return pcBuffer;
}

/* format the command and any environment insertions,			(ksb)
 * N.B. side effect globals link us to Launch.
 */
static char *
DiceControl(pcBuffer, pcTemplate, iPass, argv, ppcNamev, pTEThis)
char *pcBuffer, *pcTemplate;
int iPass;
char **argv, **ppcNamev;
TARGET_ENV *pTEThis;
{
	register char **ppc, *pcRes;
	register int i;
	auto int fTail;
	auto char acTemp[NCARGS];

	fTail = 1;
	if ((char **)0 == (ppc = ppcAddEnv)) {
		return AFmt(pcBuffer, pcTemplate, iPass, argv, ppcNamev, pTEThis, &fTail);
	}
	for (i = 0; (char *)0 != ppc[i]; ++i) {
		if ((char *)0 == ppcAddValue[i])
			break;
		free((void *)ppcAddValue[i]);
		ppcAddValue[i] = (char *)0;
	}
	for (i = 0; (char *)0 != ppc[i]; ++i) {
		fTail = 0;
		pcRes = AFmt(acTemp, ppcAddDice[i], iPass, argv, ppcNamev, pTEThis, &fTail);
		if ((char *)0 == pcRes) {
			fprintf(stderr, "%s: $%s: failed to expand\n", progname, ppcAddEnv[i]);
			exit(EX_DATAERR);
		}
		ppcAddValue[i] = strdup(acTemp);
	}
	fTail = 1;
	return AFmt(pcBuffer, pcTemplate, iPass, argv, ppcNamev, pTEThis, &fTail);
}

/* Run any else command we need and dispose of any tokens held.		(ksb)
 * The "wait loop" seems silly, becasue we didn't start any processes,
 * but our same pid might have before we were execve'd.
 */
static void
FinishElse(char *pcSpace, int argc, char **argv)
{
	register int i, iExit;
	auto int wExit;

	iExit = EX_OK;
	if (uSeqInit == uSeqUniq && (char *)0 != pcElse) {
		register char *pcBuilt;
		auto char *pcNull;
		auto TARGET_ENV *pTEElse;

		(void)GetToken(& pTEElse);
		pcNull = (char *)0;
		pcBuilt = DiceControl(pcSpace, pcElse, argc, argv, (char **)0, pTEElse);
		if ((char *)0 == pcBuilt) {
			fprintf(stderr, "%s: -N: failed to expand \"%s\"\n", progname, pcElse);
			iExit = EX_DATAERR;
		} else if (!fExec) {
			if (fVerbose)
				printf("%s\n", pcBuilt);
			if (fTrace)
				fprintf(stderr, "%s\n", pcBuilt);
		} else {
			do {
				while (0 < (i = wait3(& wExit, WNOHANG, (struct rusage *)0))) {
					Stop(i, 1);
				}
			} while (-1 == (i = Launch(pcBuilt, fGtfw ? (char *)0 : "00", pTEElse)));
			Start(i, pTEElse);
		}
	}

	/* Release free tokens if we have a ptbw to chat up
	 */
	for (i = 0; -1 != sMaster && i < uTargetMax; ++i) {
		if (0 != pTEList[i].wlock || (unsigned int *)0 == pTEList[i].publock)
			continue;
		(void)PTBFreeTokenList(sMaster, uReq, pTEList[i].publock);
		pTEList[i].publock = (unsigned int *)0;
	}

	/* just wait for any out-standing tasks
	 */
	while (-1 != (i = wait((void *)0))) {
		Stop(i, 1);
	}
	exit(iExit);
}

/* do the work								(ksb)
 *	apply -P$iParallel -S$pcShell -c "$cmd" $argc
 */
static void
Apply(argc, argv)
int argc;
char **argv;
{
	register int i, iRunning, iAdvance;
	register char *pcBuilt;
	auto int wExit, iRedo;
	auto TARGET_ENV *pTECur;
	auto char acCmd[NCARGS+1];
	auto char acMyXid[MAX_XID_LEN];

	if (0 != (argc % iPass)) {
		fprintf(stderr, "%s: %d arguments is not a multiple of hunk size (%d)\n", progname, argc, iPass);
		exit(EX_DATAERR);
	}
	iRedo = argc;

	/* not very useful here, but we allow it
	 */
	if ((char *)0 != pcRedir) {
		close(0);
		if (0 != open(pcRedir, O_RDONLY, 0666)) {
			fprintf(stderr, "%s: open: %s: %s\n", progname, pcRedir, strerror(errno));
			exit(EX_NOINPUT);
		}
	}

	iAdvance = 0 == iPass ? 1 : iPass;
	uSeqInit = uSeqUniq = FromGtfw();
	for (iRunning = 0; 0 != argc; uSeqUniq = FromGtfw()) {
		iRunning -= GetToken(& pTECur);
		pcBuilt = DiceControl(acCmd, pcCmd, iPass, argv, (char **)0, pTECur);
		if ((char *)0 == pcBuilt) {
			break;
		}
		(void)strncpy(acMyXid, argv[0], sizeof(acMyXid));
		acMyXid[sizeof(acMyXid)-1] = '\000';
		argc -= iAdvance, argv += iAdvance;
		if (!fExec) {
			if (fVerbose)
				printf("%s\n", pcBuilt);
			if (fTrace)
				fprintf(stderr, "%s\n", pcBuilt);
			continue;
		}
		do {
			while (0 < (i = wait3(& wExit, (iRunning < iParallel) ? WNOHANG : 0, (struct rusage *)0))) {
				if (Stop(i, 0))
					--iRunning;
			}
		} while (-1 == (i = Launch(pcBuilt, fUniq ? (char *)0 : acMyXid, pTECur)));
		Start(i, pTECur);
		++iRunning;
	}
	FinishElse(acCmd, iRedo, argv-iRedo);
}

/* the User gave us a list of files on the command line,		(ksb)
 * parameters come from the files indirectly.
 */
static void
VApply(argc, pfpArgv, argv)
int argc;
FILE **pfpArgv;
char **argv;
{
	register char **ppcSlots, *pcBuilt;
	register int i, c, iMem, iEofs;
	register int iRunning, iAdvance, fd;
	register FILE *fpMove;
	auto char acBufs[NCARGS+1];
	auto char acCmd[NCARGS+1];
	auto int wExit, iRedo;
	auto TARGET_ENV *pTECur;
	auto char acMyFXid[MAX_XID_LEN];

	if (0 != (argc % iPass)) {
		fprintf(stderr, "%s: %d files: not divisable by hunk size (%d)\n", progname, argc, iPass);
		exit(EX_DATAERR);
	}
	iRedo = argc;
	if ((char **)0 == (ppcSlots = (char **)calloc(iPass+1, sizeof(char *)))) {
		fprintf(stderr, "%s: out of memory\n", progname);
		exit(EX_OSERR);
	}
	/* set close-on-exec to keep the kids from having lots of
	 * open files, if we can't set the close-on-exec we ignore it.
	 * Move a /dev/null fd on stdin if it is used as a stream of
	 * input files. (So the kids don't race for the input.)
	 * If two copies of stdin are put on the line we can read
	 * more than one token from that stream, the hack is clear. -- ksb
	 */
	fpMove = (FILE *)0;
	for (i = 0; i < argc; ++i) {
		fd = fileno(pfpArgv[i]);
		if (stdin == pfpArgv[i]) {
			if ((FILE *)0 == fpMove) {
				fd = dup(0);
				if (-1 == fd) {
					fprintf(stderr, "%s: dup: 0: %s\n", progname, strerror(errno));
					exit(EX_OSERR);
				}
				if ((FILE *)0 == (fpMove = fdopen(fd, "r"))) {
					fprintf(stderr, "%s: fdopen: %d: %s\n", progname, fd, strerror(errno));
					exit(EX_OSERR);
				}
			}
			pfpArgv[i] = fpMove;
			if (0 == fd) {
				continue;
			}
			/* fall into set close on exec for the stdin dup
			 */
		} else if (1 == fd || 2 == fd) {
			/* through /dev/fd/X I guess!, don't close them
			 */
			continue;
		}
		(void)fcntl(fd, F_SETFD, 1);
	}
	/* We moved the stdin references, now close the old
	 * stdin and open the redirect one.  Or the user gave
	 * the redirect option rather than a less than symbol (why?)
	 */
	if ((FILE *)0 != fpMove || (char *)0 != pcRedir) {
		close(0);
		if ((char *)0 == pcRedir) {
			pcRedir = "/dev/null";
		}
		if (0 != open(pcRedir, O_RDONLY, 0666)) {
			fprintf(stderr, "%s: open: %s: %s\n", progname, pcRedir, strerror(errno));
			exit(EX_NOINPUT);
		}
	}

	iAdvance = 0 == iPass ? 1 : iPass;
	uSeqInit = uSeqUniq = FromGtfw();
	for (iRunning = 0; argc > 0; ) {
		iRunning -= GetToken(& pTECur);
		c = iEofs = iMem = 0;
		for (i = 0; i < iAdvance && iMem < sizeof(acBufs); ++i) {
			ppcSlots[i] = acBufs+iMem;
			while (iMem < sizeof(acBufs)) {
				c = getc(pfpArgv[i]);
				if (EOF == c) {
					if (ppcSlots[i] == acBufs+iMem) {
						ppcSlots[i] = pcPad;
						++iEofs;
					}
					acBufs[iMem++] = '\000';
					break;
				}
				if (cEoln == c) {
					acBufs[iMem++] = '\000';
					break;
				}
				acBufs[iMem++] = c;
			}
		}
		if (i < iAdvance || (EOF != c && cEoln != c)) {
			fprintf(stderr, "%s: line length is too big for execve\n", progname);
			exit(EX_OSERR);
		}
		/* out of data on all inputs advance to next input group
		 */
		if (iAdvance == iEofs) {
			argc -= iAdvance, argv += iAdvance, pfpArgv += iAdvance;
			continue;
		}
		pcBuilt = DiceControl(acCmd, pcCmd, iPass, ppcSlots, argv, pTECur);
		if ((char *)0 == pcBuilt) {
			break;
		}
		strncpy(acMyFXid, ppcSlots[0], sizeof(acMyFXid));
		acMyFXid[sizeof(acMyFXid)-1] = '\000';
		if (!fExec) {
			if (fVerbose)
				printf("%s\n", pcBuilt);
			if (fTrace)
				fprintf(stderr, "%s\n", pcBuilt);
			uSeqUniq = FromGtfw();
			continue;
		}
		do {
			while (0 < (i = wait3(& wExit, (iRunning < iParallel) ? WNOHANG : 0, (struct rusage *)0))) {
				if (Stop(i, 0))
					--iRunning;
			}
		} while (-1 == (i = Launch(pcBuilt, fUniq ? (char *)0 : acMyFXid, pTECur)));
		Start(i, pTECur);
		uSeqUniq = FromGtfw();
		++iRunning;
	}
	FinishElse(acBufs, iRedo, argv-iRedo);
}

/* Do all the post work, we might get here three times			(ksb)
 * fix -P, -J, -R if we can, bomb on a bad -count.  Overlay any
 * wrapper processors we must have.  Build the task bookkeeping.
 */
static void
PostProc(int argc, char **argv)
{
	register char *pcTail;
	register unsigned int uJobs;

	if ((char *)0 == pcShell || '\000' == *pcShell) {
		fprintf(stderr, "%s: no shell available\n", progname);
		exit(EX_UNAVAILABLE);
	}
	if ('\000' == cEsc) {
		fprintf(stderr, "%s: -a: the NUL character forbidden\n", progname);
		exit(EX_CONFIG);
	}
	/* Bloody csh counts are differently on different hosts: in the
	 * tuning we can use    csh -c 'echo $1' 0 1 2
	 * to see if $1 is the 0 or the 1, if we get 1 we need to pad
	 * our -A parameters with a "0" or "_".
	 */
	if ((char **)0 == (ppcArgs = calloc(5+uReq, sizeof(char *)))) {
		fprintf(stderr, "%s: calloc: %s\n", progname, strerror(errno));
		exit(EX_OSERR);
	}
	ppcArgs[0] = pcShell;
	ppcArgs[1] = "-c";
	ppcArgs[2] = ":";
	ppcArgs[3] = (char *)0;
	ppcArgs[4] = (char *)0;
	if ((char *)0 == (pcTail = strrchr(pcShell, '/'))) {
		pcTail = pcShell;
	} else {
		++pcTail;
	}
	if ((char *)0 != strstr(pcTail, "perl")) {
		ppcArgs[1] = "-e";
		/* perl programmers expect $ARGV[0] to be the first arg */
	} else if ((char *)0 != strstr(pcTail, "tcsh")) {
		/* tcsh doesn't need the pad */
	} else if ((char *)0 != strstr(pcTail, "csh")) {
#if NEED_CSH_PAD
		ppcArgs[3] = "_";
#else
		/* csh is most likely a link to tsh */
#endif
	} else {
		/* the (1 true) shell needs the pad */
		ppcArgs[3] = "_";
	}

	if (0 >= iPass) {
		fprintf(stderr, "%s: count: %d: is not a possible value\n", progname, iPass);
		exit(EX_USAGE);
	}
	if (iParallel < 1) {
		iParallel = 1;
	}
#if defined(TUNE_MAX_PROC)
	if (TUME_MAX_PROC < iParallel) {
		fprintf(stderr, "%s: -P%u: too many parallel processes (TUNE_MAX_PROC)\n", progname, iParallel);
		exit(EX_USAGE);
	}
#endif
	if (0 == uReq || 0 == iCopies) {
		uJobs = iParallel;
	} else if (!fGaveJ || iCopies < 1) {
		uJobs = iParallel * uReq;
	} else {
		uJobs = iCopies * uReq;
	}
	if (fManage) {
		XCLOverlay(argc, argv);
	}
	PTBOverlay(argc, argv, uJobs);
	Tasks(iParallel, (unsigned int)argc);
}
/* from std_help.m */
/* from std_version.m */
/* from std_control.m */
/* from util_pipefit.m */
/* from util_cache.m */
/* from util_divconnect.m */
/* from ../ptbw/ptbc.m */
#line 30 "../ptbw/ptbc.m"
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
#line 74 "../ptbw/ptbc.m"
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
#line 172 "../ptbw/ptbc.m"
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
#line 256 "../ptbw/ptbc.m"
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
#line 306 "../ptbw/ptbc.m"
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
#line 361 "../ptbw/ptbc.m"
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
#line 378 "../ptbw/ptbc.m"
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
#line 416 "../ptbw/ptbc.m"
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
#line 455 "../ptbw/ptbc.m"
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
#line 478 "../ptbw/ptbc.m"
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
/* from util_errno.m */
/* from argv.m */
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

#line 1 "getopt.mc"
/* $Id: getopt.mc,v 8.13 2004/09/01 15:26:37 ksb Exp $
 * Based on Keith Bostic's getopt in comp.sources.unix volume1
 * modified for mkcmd use by ksb@fedex.com (Kevin S Braunsdorf).
 */

#if 0 || 0
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
	if (fVerbose && (FILE *)0 != stderr) {
		fprintf(stderr, "%s:%s", progname, iKeep ? " |" : "");
		for (i = 0; (char *)0 != ppcArgv[i]; ++i) {
			fprintf(stderr, " %s", ppcArgv[i]);
		}
		fprintf(stderr, "%s\n", iKeep ? "" : " |");
		fflush(stderr);
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
#line 1 "argv.mc"
/* $Id: argv.mc,v 8.10 2002/12/02 18:05:33 ksb Exp $
 * ksb's support for a list of words taken from mulitple options	(ksb)
 * which together form an argv (kinda).
 */

#if !defined(U_ARGV_BLOB)
#define U_ARGV_BLOB	16
#endif
#if 0 == U_ARGV_BLOB
#undef U_ARGV_BLOB
#define U_ARGV_BLOB	2
#endif

/* Add an element to the present vector, yeah we are N^2,		(ksb)
 * and we depend on the init below putting an initial (char *)0 in slot 0.
 */
static void
u_argv_add(pPPM, pcWord)
struct PPMnode *pPPM;
char *pcWord;
{
	register char **ppc;
	register int i;
	if ((struct PPMnode *)0 == pPPM || (char *)0 == pcWord)
		return;
	ppc = util_ppm_size(pPPM, U_ARGV_BLOB);
	for (i = 0; (char *)0 != ppc[i]; ++i)
		/* nada */;
	ppc = util_ppm_size(pPPM, ((i+1)/U_ARGV_BLOB)*U_ARGV_BLOB);
	ppc[i] = pcWord;
	ppc[i+1] = (char *)0;
}

/* Setup to process all the argv's the Implementor declared.		(ksb)
 * We allocate them all at once, then the initial vectors for each.
 */
static void
u_argv_init()
{
	register struct PPMnode *pPPMInit;
	register char **u_ppc;

	if ((struct PPMnode *)0 == (pPPMInit = (struct PPMnode *)calloc(1, sizeof(struct PPMnode)))) {
		fprintf(stderr, "%s: calloc: %d: no core\n", progname, 1);
		exit(60);
	}
	pPPMAddEnv = util_ppm_init(pPPMInit++, sizeof(char *), U_ARGV_BLOB);
	u_ppc = (char **)util_ppm_size(pPPMAddEnv, 2);
	u_ppc[0] = (char *)0;	/* sentinal value, do not remove */
#line 52 "argv.mc"
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
		sbOpt[] = "#:a:Ade:fghi:J:mnN:p:P::R:sS:t:uvVxz",
		*u_pch = (char *)0;
	static int
		u_loop = 0;
	int
		u_gave_f = 0;
	register int u_curopt;
	register char *u_pcEnv;
	extern char *getenv();
	extern int atoi();
	extern int atoi();
	extern int atoi();

	if ((char *)0 == argv[0]) {
		progname = "xapply";
	} else if ((char *)0 == (progname = strrchr(argv[0], '/'))) {
		progname = argv[0];
	} else {
		++progname;
	}
	u_argv_init();
	/* "xapply" forces no options */
	u_argv_add(pPPMAddEnv, (void *)0);
	if ((char *)0 != (u_pcEnv = getenv("SHELL"))) {
		pcShell = u_pcEnv;
	}
	pcPtbw = "ptbw";
	pcXclate = "xclate";
	if ((char *)0 == pcShell) {
		pcShell = "/bin/sh";
	}
	while (EOF != (u_curopt = u_getopt(argc, argv, sbOpt, (char *)0))) {
		switch (u_curopt) {
		case '#':
			iPass = atoi(u_optarg);
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
			fAddEnv = ! 0;
			continue;
		case 'd':
			fPublish = ! 1;
			continue;
		case 'e':
			u_argv_add(pPPMAddEnv, u_optarg);
			continue;
		case 'f':
			u_chkonly('f', u_curopt, "f");
			u_gave_f = 1;
			pcIn = (char *)0;
			fpIn = ! 0;
			continue;
		case 'g':
			fGtfw = ! 0;
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
		case 'i':
			pcRedir = u_optarg;
			continue;
		case 'J':
			fGaveJ = 1;
			iCopies = atoi(u_optarg);
			continue;
		case 'm':
			u_gave_m = 1;
			fManage = ! 0;
			continue;
		case 'n':
			fExec = !1;
			fVerbose = !0;
			continue;
		case 'N':
			pcElse = u_optarg;
			continue;
		case 'p':
			if (0 == u_gave_f) {
				fprintf(stderr, "%s: option `-p' may only be given after option `-f'\n", progname);
				exit(1);
			}
			pcPad = u_optarg;
			continue;
		case 'P':
			if ((char *)0 == u_optarg) {
				if ((char *)0 == (u_optarg = getenv("PARALLEL")) || '\000' == *u_optarg) {
					u_optarg = "3";
				}
			}
			iParallel = atoi(u_optarg);
			continue;
		case 'R':
			fGaveR = 1;
			uReq = atoi(u_optarg);
			continue;
		case 's':
			fSqueeze = ! 0;
			continue;
		case 'S':
			pcShell = u_optarg;
			continue;
		case 't':
			fGavet = 1;
			pcTags = u_optarg;
			continue;
		case 'u':
			fUniq = ! 0;
			continue;
		case 'v':
			fVerbose = ! 0;
			continue;
		case 'V':
			printf("%s: %s\n", progname, rcsid);
			Version();
			exit(0);
		case 'x':
			fTrace = ! 0;
			continue;
		case 'z':
			if (0 == u_gave_f) {
				fprintf(stderr, "%s: option `-z' may only be given after option `-f'\n", progname);
				exit(1);
			}
			cEoln = '\000';
			continue;
		}
		break;
	}
	PostProc(argc, argv);
	if (fGtfw) {
		GtfwInit(getenv("gtfw_link"));
	}
	/* alternate for option f */
	if (u_gave_f) {
		if (argc - u_optInd < 1) {
			fprintf(stderr, "%s: not enough arguments for left mandatory parameters\n", progname);
			exit(1);
		}
		pcCmd = argv[u_optInd];
		++u_optInd;
		ppcNames = & argv[u_optInd];
		{
			register int u_i;
			if ((FILE **)0 == (pfpIn = (FILE **)calloc((argc-u_optInd), sizeof(FILE *)))) {
				fprintf(stderr, "%s: out of memory\n", progname);
				exit(1);
			}
			for (u_i = 0; u_i < (argc-u_optInd); ++u_i) {
				if ((FILE *)0 != pfpIn[u_i] && stdin != pfpIn[u_i] && stdout != pfpIn[u_i]) {(void)fclose(pfpIn[u_i]);}if ('-' == ppcNames[u_i][0] && '\000' == ppcNames[u_i][1]) {pfpIn[u_i] = stdin;}else if ((FILE *)0 == (pfpIn[u_i] = fopen(ppcNames[u_i], "r"))) {fprintf(stderr, "%s: control `list': fopen: %s: %s\n", progname, ppcNames[u_i], strerror(errno));exit(1);}/*Yow*/
			}
		}
		VApply((argc-u_optInd), pfpIn, ppcNames);
		exit(0);
		/*NOTREACHED*/
	}
	if (argc - u_optInd < 1) {
		fprintf(stderr, "%s: not enough arguments for left mandatory parameters\n", progname);
		exit(1);
	}
	pcCmd = argv[u_optInd];
	++u_optInd;
	Apply((argc-u_optInd), & argv[u_optInd]);
	exit(0);
	/*NOTREACHED*/
}
