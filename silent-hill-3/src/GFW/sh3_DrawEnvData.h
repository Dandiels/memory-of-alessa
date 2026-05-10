#ifndef SH3_DRAWENVDATA_H
#define SH3_DRAWENVDATA_H

// @todo: shape and size not confirmed
typedef struct sh3gfw_Env_ctl {
    float camera_p[4]; // offset 0x0, size 0x10
    float camera_zd[4]; // offset 0x10, size 0x10
    float camera_yd[4]; // offset 0x20, size 0x10
    float camera_rot[4]; // offset 0x30, size 0x10
    float camera_ido[4]; // offset 0x40, size 0x10
    float camera_parms[4]; // offset 0x50, size 0x10
    float camera_parms2[4]; // offset 0x60, size 0x10
    float camera_mat[4][4]; // offset 0x70, size 0x40
    float objclip_mat[4][4]; // offset 0xB0, size 0x40
} sh3gfw_Env_ctl;

extern sh3gfw_Env_ctl Env_ctl;

#endif // SH3_DRAWENVDATA_H
