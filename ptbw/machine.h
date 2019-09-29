/* $Id: machine.h,v 1.9 2008/09/02 18:05:36 ksb Exp $
 *
 * we don't love autoconfig as much as we should			(ksb)
 */

/* efficient accept logic in kernel
 */
#if !defined(HAVE_ACCEPT_FILTER)
#define HAVE_ACCEPT_FILTER (defined(FREEBSD))
#endif

/* find name of peer process with /proc/$PID/file symblic link
 */
#if !defined(HAVE_PROCFS)
#define HAVE_PROCFS	(defined(FREEBSD) || defined(LINUX))
#endif

/* have SCM_RIGHTS
 */
#if !defined(HAVE_SCM_RIGHTS)
#if SUN5
#define HAVE_SCM_RIGHTS       0
#else
#define HAVE_SCM_RIGHTS       (defined(SCM_RIGHTS) || defined(LINUX))
#endif
#endif

/* sys/pipe.h, strangely only found on some *BSD systems
 */
#if !defined(HAVE_SYS_PIPE_H)
#define HAVE_SYS_PIPE_H		(defined(FREEBSD))
#endif

/* We just this, but I hate the kludge
 */
#if !defined(EMU_SOCKUN_LEN)
#define EMU_SOCKUN_LEN(Mpc)	(strlen(Mpc)+2)
#endif

/* If we have arc4random we are special, really most people don't
 */
#if !defined(EMU_ARC4RANDOM)
#define EMU_ARC4RANDOM	!(defined(FREEBSD)||defined(OPENBSD))
#endif

/* I like snprintf as much as the next guy, but this is hard to
 * justify.  I need a better emulation for it.
 */
#if !defined(HAVE_SNPRINTF)
#define HAVE_SNPRINTF		!(defined(HPUX9)||defined(HPUX8)||defined(HPUX7))
#endif

/* we still want to try to work on old-school systems, a little
 */
#if defined(FREEBSD) && HOSTOS < 40000
typedef int socklen_t;
#define HAVE_SIGACTION		0
#endif

#if !defined(HAVE_SIGACTION)
#define HAVE_SIGACTION		1
#endif

/* HPUX is missing 2 sysexits
 */
#if !defined(EX_CONFIG)
#define EX_CONFIG		78	/* Linux, BSD, Solaris have this */
#endif
#if !defined(EX_NOTFOUND)
#define EX_NOTFOUND		79	/* Solaris, and others have this */
#endif
