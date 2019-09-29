/*@Header@*/
/*@Version $Revision: 3.4 $@*/
/* $Id: fdrights.h,v 3.4 2010/02/26 21:30:39 ksb Exp $
 */

#if !defined(FDRIGHTS_H_)
#define FDRIGHTS_H_	0xcabfab

#if !defined(RIGHTS_TAG_LINE)
#define RIGHTS_TAG_LINE	64
#endif

extern char acRightsRecvBuf[RIGHTS_TAG_LINE];

#if 0 == HAVE_PROTO

extern int RightsSendFd(), RightsRecvFd(), RightsWrap(), RopenSplit(), ropen();
#else
extern int RightsSendFd(int, int *, unsigned, char *);
extern int RightsRecvFd(int, int *, unsigned, char *, size_t *);
extern int RopenSplit(void (*)());
extern int RightsWrap(int , char *, void *, char *);
extern int ropen(char *, int , int );
#endif
#endif /* ! FDRIGHTS_H_ */
