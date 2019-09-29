/*@Header@*/
/*@Version $Revision: 6.9 $@*/
/* $Id: dicer.h,v 6.9 2010/02/26 21:30:39 ksb Exp $
 */

/* Dice the control from the template, into dest using data as the
 * string to process.
 */
#if !defined(DICER_START)
#define DICER_START	'['
#endif

#if !defined(DICER_END)
#define DICER_END	']'
#endif

#if !defined(MIXER_RECURSE)
#define MIXER_RECURSE	'('
#endif

#if !defined(MIXER_END)
#define MIXER_END	')'
#endif

/*@Explode dicer@*/
extern char DicerVersion[];

extern char *Dicer(char *pcDest, unsigned *puMax, char *pcTemplate, char *pcData);
/*@Explode slicer@*/
extern char *Slicer(char *pcDest, unsigned *puMax, char *pcTemplate, char **ppcList);
/*@Explode mixer@*/
extern char *Mixer(char *pcInplace, unsigned *puMax, char *pcExpr, int cExit);
