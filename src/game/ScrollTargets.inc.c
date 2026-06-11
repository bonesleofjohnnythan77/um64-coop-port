#include <PR/ultratypes.h>
#include "sm64.h"
#include "types.h"

//Q. Why does this exist instead of just directly referencing VBs?
//A. Because gcc is dumb and will seg fault if you reference a VB by abstracting it through a bparam
//instead of directly refencing it, causing this horrible shit.

extern Vtx VB_cotmc_1_0xe019a10[];
extern Vtx VB_cotmc_1_0xe019b00[];
extern Vtx VB_cotmc_1_0xe019bf0[];
extern Vtx VB_cotmc_1_0xe019ce0[];
extern Vtx VB_cotmc_1_0xe019dd0[];
extern Vtx VB_cotmc_1_0xe019ec0[];
extern Vtx VB_cotmc_1_0xe019fb0[];
extern Vtx VB_cotmc_1_0xe01a0a0[];
extern Vtx VB_cotmc_1_0xe01a190[];
extern Vtx VB_cotmc_1_0xe01a280[];
extern Vtx VB_cotmc_1_0xe01a370[];
extern Vtx VB_cotmc_1_0xe01a460[];
extern Vtx VB_cotmc_1_0xe01a550[];
extern Vtx VB_cotmc_1_0xe01a640[];
extern Vtx VB_cotmc_1_0xe01a730[];

Vtx *ScrollTargets[]={

&VB_cotmc_1_0xe019a10[0],
&VB_cotmc_1_0xe019b00[0],
&VB_cotmc_1_0xe019bf0[0],
&VB_cotmc_1_0xe019ce0[0],
&VB_cotmc_1_0xe019dd0[0],
&VB_cotmc_1_0xe019ec0[0],
&VB_cotmc_1_0xe019fb0[0],
&VB_cotmc_1_0xe01a0a0[0],
&VB_cotmc_1_0xe01a190[0],
&VB_cotmc_1_0xe01a280[0],
&VB_cotmc_1_0xe01a370[0],
&VB_cotmc_1_0xe01a460[0],
&VB_cotmc_1_0xe01a550[0],
&VB_cotmc_1_0xe01a640[0],
&VB_cotmc_1_0xe01a730[0],

};