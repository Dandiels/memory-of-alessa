#ifndef SH3GFW_VIEWCLIP_H
#define SH3GFW_VIEWCLIP_H

#include "common.h"

/* ========= not from here ========= */
// likely loads Env_ctl camera params into arg0
extern void func_001B3F00(float* arg0);

// likely sets Env_ctl camera params from arg0
// this function seems to be a copy of vwGetViewPosition?
extern void func_001B3E80(float* arg0);

// likely gets VbScreenInfo.scr_z
extern float func_001B4100(void);

// gets an Env_ctl camera param
extern float func_001B4110(void);

// gets VbScreenInfo.nearz
extern float func_001B4130(void);

// gets VbScreenInfo.farz
extern float func_001B4110(void);

// gets clip_volume[2]
extern float func_001B4140(void);

extern float y_dirvec[4];

#endif // SH3GFW_VIEWCLIP_H
