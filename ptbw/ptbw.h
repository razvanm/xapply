/* mkcmd generated declarations for options and buffers
 */

extern char *progname, *au_terse[5], *u_help[15];
#ifndef u_terse
#define u_terse	(au_terse[0])
#endif
extern int main(), fGaveJ, u_gave_m, fGaveReq;
extern char *pcBindHere, *pcTags, *pcTmpdir;
extern int iDevDepth, fAppend, fPublish, fMaster, wElected, fQuiet, fQuit;
extern unsigned iTaskMin, uReq, iIotaMin;
/* from getopt.m */
/* from getopt_key.m */
/* from ptbw.m */
/* from util_errno.m */
/* from util_tmp.m */
/* from util_cache.m */
/* from util_nproc.m */
/* from util_divstack.m */
/* from util_divconnect.m */
/* from std_help.m */
/* from std_version.m */
/* from ptbc.m */
#line 27 "ptbc.m"
extern int PTBPidRecv(int, char *, size_t);
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
#line 452 "ptbc.m"
extern int PTBQuit(int sMaster, char *pcReply, unsigned uLen);
#line 475 "ptbc.m"
extern int PTBReadPid(int sMaster, pid_t *pwMaster);
/* from hosttype.m */

#line 1 "util_cache.mh"
/* $Id: util_cache.mh,v 8.32 2008/09/05 16:26:19 ksb Exp $
 * cache a file into a mallloc'd space and build a (char **) index	(ksb)
 */
extern char *cache_file(int u_iFd, unsigned int *u_puLines);
extern char **cache_vector(char *pcCache, unsigned int u_uLines);
extern int cache_dispose(char **u_ppcVector);
#line 1 "util_nproc.mh"
/* $Id: util_nproc.mh,v 1.1 2006/08/18 23:06:42 ksb Exp $
 * external declaration for util_nproc()
 */
extern unsigned long util_nproc(void);

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
