#ifndef LENS_FLARE_H
#define LENS_FLARE_H

#include "eetypes.h"

typedef struct {
    // total size: 0x40
    u_char flare_inhibit_f; // offset 0x0, size 0x1
    u_char water_inhibit_f; // offset 0x1, size 0x1
    u_char lfl_sync_draw_func_exec_f; // offset 0x2, size 0x1
    u_char draw_center_f; // offset 0x3, size 0x1
    float tgt_l_eff_rate; // offset 0x4, size 0x4
    float now_l_eff_rate; // offset 0x8, size 0x4
    struct /* @anon1 */ {
        // total size: 0x10
        float x; // offset 0x0, size 0x4
        float y; // offset 0x4, size 0x4
        float z; // offset 0x8, size 0x4
        float w; // offset 0xC, size 0x4
    } scr_l_pos; // offset 0x10, size 0x10
    float scr_l_ang_xy; // offset 0x20, size 0x4
    float scr_l_ang_z; // offset 0x24, size 0x4
    struct /* @anon2 */ {
        // total size: 0x10
        int x; // offset 0x0, size 0x4
        int y; // offset 0x4, size 0x4
        int z; // offset 0x8, size 0x4
        int w; // offset 0xC, size 0x4
    } l_screen_pos; // offset 0x30, size 0x10
} LensFlareInfo;

int shLensFlareCameraIsSmooth(void);

int shLensFlareLightCenterIsVisible(LensFlareInfo* lf_info);

void shLensFlareInit(void);

void shLensFlareExec(struct SubCharacter* scp, float light_intensity, int type);

#endif // LENS_FLARE_H
