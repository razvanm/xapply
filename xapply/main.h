/* mkcmd generated declarations for options and buffers
 */

extern char *progname, *au_terse[5], *u_help[28];
#ifndef u_terse
#define u_terse	(au_terse[0])
#endif
extern int main(), fGaveJ, u_gave_m, fGaveR, fGavet;
extern char **ppcNames, *pcIn, *pcRedir, *pcElse, *pcPad, *pcShell, *pcTags, *pcPtbw, *pcXclate, *pcCmd;
extern int iPass, cEsc, fAddEnv, fPublish, fpIn, fGtfw, iCopies, fManage, fExec, fSqueeze, fUniq, fVerbose, fTrace, cEoln;
extern unsigned iParallel, uReq;
extern FILE **pfpIn;
extern struct PPMnode *pPPMAddEnv;
/* from getopt.m */
/* from getopt_key.m */
/* from xapply.m */
/* from std_help.m */
/* from std_version.m */
/* from std_control.m */
/* from util_pipefit.m */
/* from util_cache.m */
/* from util_divconnect.m */
/* from ../ptbw/ptbc.m */
#line 27 "../ptbw/ptbc.m"
extern int PTBPidRecv(int, char *, size_t);
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
#line 452 "../ptbw/ptbc.m"
extern int PTBQuit(int sMaster, char *pcReply, unsigned uLen);
#line 475 "../ptbw/ptbc.m"
extern int PTBReadPid(int sMaster, pid_t *pwMaster);
/* from util_errno.m */
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

#line 1 "util_cache.mh"
/* $Id: util_cache.mh,v 8.32 2008/09/05 16:26:19 ksb Exp $
 * cache a file into a mallloc'd space and build a (char **) index	(ksb)
 */
extern char *cache_file(int u_iFd, unsigned int *u_puLines);
extern char **cache_vector(char *pcCache, unsigned int u_uLines);
extern int cache_dispose(char **u_ppcVector);
