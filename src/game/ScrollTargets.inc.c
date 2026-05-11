#include <PR/ultratypes.h>
#include "sm64.h"
#include "types.h"

//Q. Why does this exist instead of just directly referencing VBs?
//A. Because gcc is dumb and will seg fault if you reference a VB by abstracting it through a bparam
//instead of directly refencing it, causing this horrible shit.
extern Vtx VB_jrb_1_0x0[];
extern Vtx VB_wf_1_0xe65faf0[];
extern Vtx VB_wf_1_0xe6606c0[];
extern Vtx VB_wf_1_0xe661e90[];
extern Vtx VB_wf_1_0xe6625e0[];
extern Vtx VB_wf_1_0xe6c84c0[];
extern Vtx VB_cotmc_1_0xe649a10[];
extern Vtx VB_totwc_1_0xe720e70[];
extern Vtx VB_totwc_1_0xe6de5d0[];
extern Vtx VB_totwc_1_0xe721a70[];
extern Vtx VB_totwc_1_0xe720270[];
Vtx *ScrollTargets[]={
 &VB_jrb_1_0x0[0],
 &VB_wf_1_0xe65faf0[255],
 &VB_wf_1_0xe6606c0[255],
 &VB_wf_1_0xe661e90[255],
 &VB_wf_1_0xe6625e0[255],
 &VB_wf_1_0xe6c84c0[255],
 &VB_cotmc_1_0xe649a10[255],
 &VB_totwc_1_0xe720e70[255],
 &VB_totwc_1_0xe6de5d0[255],
 &VB_totwc_1_0xe721a70[255],
 &VB_totwc_1_0xe720270[255],
};