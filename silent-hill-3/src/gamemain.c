#include "common.h"
#include "gamemain.h"
#include "Collision/cl_main.h"
#include "movie/movie_main.h"

/* @todo: find proper homes for these. */
extern int D_003616F8;
extern int D_01D87940;
extern u_int D_1D316AC; /* likely part of `game_flag`. */
extern void func_0012CFE0(int);
extern int func_0012D080(void);
extern void func_0012DCB0(int);
extern int func_00151150(int, int);
extern void func_0019B540(int);
extern int func_0019B580(int);
extern int func_002A6340(void);
extern int func_0012D080(void);
extern int func_001C2580(int);
extern int func_0012D080(void);
extern int func_0012D0A0(void);
extern int func_001C2580(int);
extern int func_0019B580(int);
extern int func_001C2580(int);
extern int func_0012D080(void);
extern int func_001C2580(int);
extern int func_0012D080(void);
extern int func_0019B580(int);
extern int func_001C2580(int);
extern void func_0019B4B0(int);
extern int func_0019B580(int);
extern void func_0019F820(void);
extern int func_001C2580(int);
extern int func_00151150(int, int);
extern void func_0018FE60(u_long128*);
extern int func_001C2580(int);
extern int func_001C2580(int);
extern void func_0019B4B0(int);
extern void func_0019B540(int);
extern int func_001C2580(int);
extern int func_001C2580(int);
extern int func_0019B580(int);
extern int func_001C2580(int);
extern int func_001C2580(int);
extern int func_001C2580(int);
extern int func_0012D080(void);
extern int func_00151150(int, int);
extern void func_0018FE60(u_long128*);
extern int func_0019B580(int);
extern int func_001C2580(int);
extern void func_0018FE60(u_long128*);
extern int func_001C2580(int);
extern int func_001C2580(int);
extern int func_00151150(int, int);
extern void func_001BF720(int);
extern int func_00151150(int, int);
extern void func_0018FE60(u_long128*);
extern int func_0019B580(int);
extern int func_001C2580(int);
extern int func_0012D080(void);
extern void func_0019B4B0(int);
extern int func_001C2580(int);
extern void func_0012CFE0(int);
extern int func_001C2580(int);
extern void func_001C2290(int, float);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00193F10);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00194130);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00194260);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001942D0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00194300);

void GameMain(void) {
    u_long128 sp30;
    int sp4C;
    float var_f12;
    int temp_s0;
    int var_a0;
    int var_s0;
    int var_s0_2;
    int var_s1;
    int var_v0;
    u_int temp_v0;

    func_0012CFA0();
    switch (func_0012D080()) {
        case SH3_GAME_MAIN_INIT:
            func_00195920(0);
            func_00164940();
            ItemDataInit();
            func_0016D5C0();
            func_001691C0();
            func_0012D0A0();
            func_0027B430();
            func_0016F420();
            func_0019B540(7);
            func_0019B540(5);
            if (D_01D87940 == 0) {
                D_01D87940 = 1;
                func_0012CFE0(21);
                break;
            }

        /* fallthrough */
        case SH3_GAME_MAIN_MENU: {
            int var_v0;
            func_00195920(0);
            var_v0 = func_002A6340();
            if (var_v0 != 1) {
                func_0012CFE0(var_v0);
            }
            func_0012DCB0(1);
            func_001AB310();

            break;
        }

        case SH3_GAME_MAIN_LOADING_SCREEN:
            func_00195920(1);
            if (func_00193F10()) {
                func_0012D0A0();
                func_001BF720(0);
            }
            break;

        case 3:
            func_00195920(1);
            /* fallthrough */
        case 7:
            if (func_00194130()) {
                if (func_0012D080() == 3) {
                    func_001E4CC0();
                }
                func_0012D0A0();
                func_0019B4B0(18);
            }
            break;
        case 8:
            if (func_001C2580(0)) {
                if (func_001C2580(7)) {
                    func_001C2290(13, 0.8f);
                } else if (func_001C2580(6)) {
                    func_001C2290(9, 0.8f);
                } else {
                    func_001C2290(5, 0.8f);
                }
                fontClear();
                func_0012CFE0(4);
        case 4:
                    if (func_0027B400(2, 1) == 0) {
                        func_00195920(1);
                    } else {
                        func_0019B540(12);
                        func_0019B540(2);
                        func_0012D0A0();
        case SH3_GAME_MAIN_PLAYABLE:
                            if (func_0027B400(2, 0) == 0) {
                                do {

                                } while (func_0027B400(2, 1) == 0);
                            } else {
                                func_00195920(0);
                            }
                            func_001DE560(0);
                            if (func_0019B580(2) == 0) {
                                func_001AB560();
                                if (func_0019B580(5) == 0) {
                                    func_0018FE60(&sp30);
                                    func_0027F030(&sp30);
                                }
                                if (D_003616F8) {
                                    func_001AB5B0();
                                }
                                func_001D12F0();
                                func_001DE560(1);
                                func_0012DCB0(3);
                                func_0019F820();
                                func_001E22C0();
                                func_001C20E0();
                                func_0013AA00(0);
                                func_001CC220();
                                func_001EBF20();
                            }
                            func_0012DCB0(4);
                            func_0013AA00(1);
                            func_0019B460();
                            func_00337360();
                            temp_s0 = func_00164990();
                            if ((((u_char) func_0019A600()) != 1) || (func_0019B580(6)) || (func_0019B580(2))) {
                                func_003373D0();
                            }
                            if (temp_s0 != 5) {
                                func_0012CFE0(temp_s0);
                                func_0019F820();
                                switch (temp_s0) {
                                    case 19:
                                        func_001C2290(11, 2.4f);
                                        break;
                                    case 6:
                                        if (func_00151150(0, 1)) {
                                            var_f12 = 0.8f;
                                        } else {
                                            var_f12 = 1.2f;
                                        }
                                        func_001C2290(3, var_f12);
                                        func_001EE940();
                                        break;
                                }
                            } else {
                                if (func_0019B580(6) == 0) {
                                    if ((func_0019B580(18) == 0) && (func_00164860() == 0)) {
                                        func_00195410();
                                    }
                                }
                                if (func_0019B580(5) == 0) {
                                    if (func_0019B580(7) == 0) {
                                        func_00169580();
                                        func_001E22D0();
                                        func_001DD2F0();
                                        func_0022EA30();
                                        clCollectCharaPosition();
                                        shCharacterExecAnimeAll();
                                        func_001DD3B0();
                                        func_001E22E0();
                                        func_001A2AE0();
                                    } else {
                                        shCharacterExecAnimeAll();
                                    }
                                } else {
                                    func_001DD350();
                                    func_001DD1D0();
                                    func_001DD440();
                                }
                            }
                            func_0019B540(18);
                            if (func_0019B580(2) == 0) {
                                func_001AB4B0();
                                Kari_LensFlare_DrawExec();
                            } else {
                                func_001AB310();
                            }
                            func_0012DCB0(1);
                            func_0013AA00(2);
                            switch (temp_s0) {
                                case 2:
                                    func_00167AA0();
                                    break;
                                case 5:
                                    break;
                            }
                    }
            }
            break;

        case SH3_GAME_MAIN_INVENTORY:
            switch (func_00161BE0()) {
                case 0:
                    break;
                case 1:
                    func_0012CFE0(7);
                    break;
                case 2:
                    func_002D0AC0(1);
                    func_0012CFE0(9);
                    break;
                case 3:
                    func_0012CFE0(10);
                    break;
                case 4:
                    func_002EE750(1);
                    func_0012CFE0(14);
                    break;
            }
            func_001AB310();
            break;

        case SH3_GAME_MAIN_MAP:
            if (ChizuMain()) {
                if (func_002D0AD0() == 1) {
                    func_0012CFE0(6);
                } else {
                    func_0012CFE0(5);
                }
            }
            func_0012DCB0(1);
            func_001AB310();
            break;

        case 10:
            if (func_002EB1D0()) {
                func_0012CFE0(6);
            }
            func_0012DCB0(1);
            func_001AB310();
            break;

        case SH3_GAME_MAIN_OPTION:
            if (func_002EE510()) {
                if (func_002EE760() == 0) {
                    if (func_0019B580(14)) {
                        func_0019B540(14);
                        func_00316E90(3);
                        func_0012CFE0(19);
                    } else {
                        func_0012CFE0(1);
                    }
                } else if (func_002EE760() == 2) {
                    func_0012CFE0(5);
                } else if (func_0019B580(14)) {
                    func_0019B540(14);
                    func_00316E90(4);
                    func_0012CFE0(19);
                } else {
                    func_0012CFE0(6);
                }
            }
            func_0012DCB0(1);
            func_001AB310();
            break;

        case 11: {
            int var_v0;
            func_0019F820();
            var_v0 = func_00164990();
            if (var_v0 != 11) {
                func_0012CFE0(var_v0);
            }
            func_001AB310();
            break;
        }

        case 12:
            if (func_001C2580(5)) {
                func_001C2290(2, 0.0f);
            }
            if (func_001C2580(6)) {
                func_001C2290(6, 0.0f);
            }
            if (func_001C2580(7)) {
                func_001C2290(10, 0.0f);
            }
            if (func_0015F4F0(func_002B3A10())) {
                func_002D18B0();
                func_0012CFE0(13);
            }
            break;

        case 13:
            var_s0 = 0;
            func_0012CFA0();

            switch (func_0012D080()) {
                case 0:
                    if (func_00151150(0, 1)) {
                        var_f12 = 0.8f;
                    } else {
                        var_f12 = 1.2f;
                    }
                    func_001C2290(3, var_f12);
                    func_0027EFE0(99);
                    func_0012D0A0();
                    func_001D9200();
                    break;
                case 1:
                    if (func_0027B400(2, 0)) {
                        func_0012D0A0();
                        case 2:
                            if (func_0027B400(2, 1)) {
                                func_0027D210(2, &sp4C, 0);
                                if (sp4C) {
                                    func_002B3BD0(sp4C);
                                    func_0012D0A0();
                                    case 3:
                                        MovieMain();
                                        func_0012D0A0();
                                }
                            }
                    }
                    break;
                case 4:
                    func_0015FA90(1);
                    func_001C2290(3, 1.2f);
                    func_0012D0A0();
                    func_001D9220();
                    /* fallthrough */
                default:
                    var_a0 = func_002B3C40() == 0;
                    if (var_a0) {
                        var_a0 = !(((u_int) D_1D316AC >> 26) & 1);
                    }
                    if (func_00194300(var_a0)) {
                        var_s0 = 1;
                    }
                    break;
            }
            func_0012CFC0();
            if (var_s0) {
                func_001C2290(5, 0.8f);
                if (func_002B3C40() == 0) {
                    if (((u_int) D_1D316AC >> 26) & 1) {
                        func_001C2290(2, 0.0f);
                        func_00316970(19);
                        func_0012CFE0(22);
                    } else {
                        func_001C2290(2, 0.0f);
                        func_0019B4B0(18);
                        func_0012CFE0(4);
                    }
                } else {
                    func_0012CFE0(1);
                }
            }
            break;

        case 16:
            if (func_002F4510()) {
                if (func_0019B580(14)) {
                    func_0019B540(14);
                    func_00316E90(6);
                    func_0012CFE0(19);
                } else {
                    func_0019B4B0(10);
                }
            }
            func_001AB310();
            break;

        case 17:
            if (func_002F5180()) {
                func_0019B4B0(10);
            }
            func_001AB310();
            break;

        case 18:
            func_0019B4B0(1);
            switch (func_003257B0(0)) {
                case 0:
                    break;
                case 2:
                    if (func_001C2580(5) != 0 || func_001C2580(0)) {
                        if (func_00151150(0, 1)) {
                            var_f12 = 0.8f;
                        } else {
                            var_f12 = 1.2f;
                        }
                        func_001C2290(3, var_f12);
                        func_0019B540(1);
                        if (GET_BIT(D_1D316AC, 26)) {
                            func_00316970(func_0012D080());
                            func_0012CFE0(22);
                        } else {
                            func_0012CFE0(2);
                        }
                    }
                    break;
                default:
                case 1:
                    func_0019B540(1);
                    func_0012CFE0(24);
                    break;
            }
            func_001AB310();
            break;

        case 19:
        case 20:
        case 25: {
            var_s0_2 = -1;
            var_s1   = 3;
            func_0019B4B0(1);
            switch (func_00316EA0()) {
                case 5:
                default:
                    var_v0 = func_00325810(func_0012D080() == 25);
                    break;
                case 1:
                    var_v0   = func_003257E0(0);
                    var_s1   = 11;
                    var_s0_2 = 7;
                    break;
                case 3:
                    var_v0   = func_00325840(0);
                    var_s0_2 = 1;
                    break;
                case 2:
                    var_v0   = func_00325840(1);
                    var_s0_2 = 1;
                    break;
                case 4:
                    var_v0   = func_00325840(2);
                    var_s0_2 = 6;
                    break;
                case 6:
                    var_v0 = func_00325840(3);
                    break;
            }
            switch (var_v0) {
                case 0:
                    break;
                case 3:
                case 1:
                    /* fallthrough */
                default:
                case 2:
                    if (func_001C2580(0)) {
                        if (func_00151150(0, 1)) {
                            var_f12 = 0.8f;
                        } else {
                            var_f12 = 1.2f;
                        }
                        func_001C2290(var_s1, var_f12);
                        func_0019B540(1);
                        if (var_s0_2 < 0) {
                            func_0012CFE0(24);
                        } else {
                            func_0012CFE0(var_s0_2);
                        }
                    }
                    break;
                case 4:
                    if (func_001C2580(0)) {
                        func_0012CFE0(25);
                    }
                    break;
            }
            func_001AB310();
            break;
        }

        case 24:
            if (func_001C2580(0)) {
                func_0019B4B0(10);
            }
            func_001AB310();
            break;

        case 21:
            func_0019B4B0(1);
            switch (func_003257B0(1)) {
                case 0:
                    break;
                case 2:
                    /* fallthrough */
                case 1:
                    if (func_001C2580(0)) {
                        if (func_00151150(0, 1)) {
                            var_f12 = 0.8f;
                        } else {
                            var_f12 = 1.2f;
                        }
                        func_001C2290(3, var_f12);
                        func_0019B540(1);
                        func_0012CFE0(1);
                    }
                    break;
            }
            func_001AB310();
            break;

        case 22:
        case 23: {
            int var_v0;
            if (func_00316760()) {
                var_v0 = func_00316980();
                switch (var_v0) {
                    case 18:
                        /* fallthrough */
                    case 20:
                        func_0012CFE0(var_v0);
                        break;
                    default:
                        func_0012CFE0(var_v0);
                        break;
                }
            }
            func_001AB310();
            break;
        }
    }
    func_001E2C60();
    func_001C25C0();
    func_0016F3D0();
    func_0019A9E0();
    func_0019B4A0();
    func_0012CFC0();
}

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001953F0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195410);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195490);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195920);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195A30);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195A40);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195B90);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195CA0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195CB0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195CC0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195D70);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195DC0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195DF0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195E30);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195E80);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195F60);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00195FA0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001961D0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001961E0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001961F0);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196200);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196360);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196370);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196430);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196440);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196450);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196460);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196470);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196480);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_00196490);

INCLUDE_ASM("asm/nonmatchings/gamemain", func_001964C0);
