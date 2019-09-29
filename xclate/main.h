/* mkcmd generated declarations for options and buffers
 */

extern char *progname, *au_terse[5], *u_help[28];
#ifndef u_terse
#define u_terse	(au_terse[0])
#endif
extern int main(), fReplaceOrigIn, fGaveL;
extern char *pcHorizRule, *pcForcedIn, *pcLimit, *pcNotify, *pcPriv, *pcInterp, *pcTitle, *pcMaster, *pcWidows, *pcTmpdir;
extern int iDevDepth, cEsc, fStartup, fPublish, fAskPWD, fAskStderr, fAskStdin, fMaster, fExec, wElected, fAllowQuick, fTerminate, fExit2, fSqueeze, fVerbose, fWeeping, fNewTTY, Z_opt;
extern long uiLimit;
/* from getopt.m */
/* from getopt_key.m */
/* from xclate.m */
/* from std_help.m */
/* from std_version.m */
/* from util_divstack.m */
/* from util_divconnect.m */
/* from util_errno.m */
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

#line 1 "util_fsearch.mh"
/* $Id: util_fsearch.mh,v 8.10 1998/09/16 13:37:42 ksb Exp $
 */
extern char *util_fsearch();
#line 1 "hosttype.mh"
/* $Id: hosttype.mh,v 8.3 2004/12/15 22:20:18 ksb Exp $
 */
#if !defined(HOSTTYPE)
#define LINUX	1
#line 10 "hosttype.mh"
#line 15 "hosttype.mh"
#line 20 "hosttype.mh"
#endif

#if (defined(V386) || defined(ETA10)) && !defined(SYSV)
#define SYSV	1
#endif
#line 1 "util_home.mh"
/* $Id: util_home.mh,v 8.3 2004/12/15 22:20:18 ksb Exp $
 */
extern char *util_home();
