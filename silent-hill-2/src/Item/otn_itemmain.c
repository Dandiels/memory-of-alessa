#include "sh2_common.h"
#include "Event/item.h"
#include "SH2_common/pad.h"
#include "SH2_common/playing_info.h"
#include "FilesList/fileslist_bg.h"
#include "sound/sh_sound.h"
#include "Effect/screen_effect.h"
#include "Item/otn_itemmain.h"

/* @todo: why does objdiff display this symbol as `unsigned short`? */
static struct /* @anon8 */ {
    // total size: 0x2A0
    u_char main_step; // offset 0x0, size 0x1
    u_char step; // offset 0x1, size 0x1
    u_char examine_step; // offset 0x2, size 0x1
    u_char pad_3[1];
    short turn_speed; // offset 0x4, size 0x2
    short command_cur; // offset 0x6, size 0x2
    short command_abe; // offset 0x8, size 0x2
    u_char pad_a[2];
    float command_move; // offset 0xC, size 0x4
    short gosa; // offset 0x10, size 0x2
    short cur_max; // offset 0x12, size 0x2
    u_char command_volume; // offset 0x14, size 0x1
    u_char command_light; // offset 0x15, size 0x1
    u_char prs_btn; // offset 0x16, size 0x1
    u_char prs_btn2; // offset 0x17, size 0x1
    u_char pad_18[8];
    float box[4][4]; // offset 0x20, size 0x40
    float boxblur[7][4][4]; // offset 0x60, size 0x1C0
    short item_no; // offset 0x220, size 0x2
    short item_kind; // offset 0x222, size 0x2
    short item_count; // offset 0x224, size 0x2
    u_char pad_226[2];
    float turnf; // offset 0x228, size 0x4
    int volume_time; // offset 0x22C, size 0x4
    float hp_time1; // offset 0x230, size 0x4
    float hp_time2; // offset 0x234, size 0x4
    float hp_abe; // offset 0x238, size 0x4
    float hp_kodo; // offset 0x23C, size 0x4
    float hp_abe2; // offset 0x240, size 0x4
    short allay_time; // offset 0x244, size 0x2
    u_char pad_246[2];
    float allay_abe; // offset 0x248, size 0x4
    float sprite_time; // offset 0x24C, size 0x4
    u_char use_item; // offset 0x250, size 0x1
    u_char pad_251[3];
    float weapon_scale[8]; // offset 0x254, size 0x20
    short combine[3]; // offset 0x274, size 0x6
    u_char pad_27a[2];
    float combine_abe; // offset 0x27C, size 0x4
    u_char shelf; // offset 0x280, size 0x1
    u_char pad_281[1];
    short use_item_kind; // offset 0x282, size 0x2
    u_char analog[4]; // offset 0x284, size 0x4
    float fade; // offset 0x288, size 0x4
    u_char fade_flag; // offset 0x28C, size 0x1
    u_char fade_step0; // offset 0x28D, size 0x1
    u_char fade_step1; // offset 0x28E, size 0x1
    u_char pad_28f[1];
    short examine_msg; // offset 0x290, size 0x2
    u_char pad_292[2];
    int seed; // offset 0x294, size 0x4
} t; // size: 0x2A0, address: 0x116E3D0

extern struct /* @anon1 */ {
    // total size: 0x14
    unsigned char kind; // offset 0x0, size 0x1
    unsigned char count; // offset 0x1, size 0x1
    unsigned char del; // offset 0x2, size 0x1
    float pos[2]; // offset 0x4, size 0x8
    float rot; // offset 0xC, size 0x4
    float item_scale; // offset 0x10, size 0x4
} item_select[75]; // size: 0x5DC, address: 0x116DDF0

/* @todo find a place for these */
extern fsFileIndex data_pic_etc_p_laura_letter_tex[1];
extern fsFileIndex data_pic_etc_p_letterm_tex[1];
extern fsFileIndex data_pic_htl_p_redreling_tex[1];
extern fsFileIndex data_pic_out_p_lostmemory_tex[1];

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", itemmain);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", itemmainmain);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", cur_step);

// 100% line number matching!
#line 796
void command_main(int command_step) {

    
    switch (command_step) {
    
        case 1:
            t.gosa = -143;
            t.cur_max = 1;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn)
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else {
                    if (t.command_cur == t.shelf) {
                        if (t.combine[0] == 0) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) && !t.combine[1]) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) || (t.item_kind == t.combine[1])) combine_item_use(0);
                        else combine_item_use(t.item_kind);

                        if (!t.use_item) t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    } else {
                        
                        if (t.combine[0] == 0) t.combine[0] = t.item_kind;
                        else if (!t.combine[1] && (short) t.combine[0] != t.item_kind) t.combine[1] = t.item_kind;
                        else if ((t.combine[1]) && (short) t.combine[0] != t.item_kind && (short) t.combine[1] != t.item_kind) t.combine[2] = t.item_kind;
                        else if (t.combine[1]) combine_item_use(0);
                        if (!t.use_item) t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    }
                }
            break;
        case 2:
            t.gosa = -133 - (t.shelf * 10);
            t.cur_max = t.shelf;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn)
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else {
                    
                    ItemMedicineUse(t.item_kind);
                    t.step = 8;
                    SeCall(10002, 1.0f, -30);
                }
            
            break;
        case 3:
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                if (t.shelf && !t.command_cur) {
                    if (t.item_kind == item.equip) item.equip = 0;
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else {
                    
                    if (item.equip != t.item_kind)
                        item.equip = t.item_kind;
                    else
                        item.equip = 0;
                    t.step = 9;
                    SeCall(10002, 1.0f, -30);
                }
            }
            t.gosa = -133 - (t.shelf * 10);
            t.cur_max = t.shelf;
            break;
        case 4:
            t.gosa = -143 - (t.shelf * 15);
            t.cur_max = t.shelf + 1;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                if (t.shelf && !t.command_cur) {
                    if (t.item_kind == item.equip) item.equip = 0;
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else
                    if (t.command_cur == t.shelf) {
                        if (item.equip != t.item_kind)
                            item.equip = t.item_kind;
                        else
                            item.equip = 0;
                        t.step = 9;
                    } else {
                        
                        ItemWeaponReload(t.item_kind, 1);
                        t.step = 1;
                    }
                SeCall(10002, 1.0f, -30);
            }
            break;
        case 5:
            t.gosa = -133 - (t.shelf * 10);
            t.cur_max = t.shelf;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else {
                    
                    if (GET_FLAG(item.flag, t.item_kind - 1)) ItemWeaponReload(t.item_kind, 1);
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                }
            }
            break;
        case 6:
            if (t.command_light == 0) {
                
                if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                    if (t.shelf && !t.command_cur) {
                        if (!t.use_item) t.use_item = 8;
                        item.event_use[0] = t.item_kind;
                        ItemPutForShelf();
                        item_select[kind_no(t.item_kind)].del = 1;
                        t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    } else {
                        
                        t.command_cur = 0;
                        t.command_light = 1;
                        SeCall(10002, 1.0f, -30);
                    }
                }
                t.gosa = -133 - (t.shelf * 10);
                t.cur_max = t.shelf;
            } else {

                
                if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                    if (t.command_cur == 0) item.light_switch = 1;
                    else item.light_switch = 0;
                    t.command_light = 0;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                }
                t.gosa = -135;
                t.cur_max = 1;
            }
            break;
        case 7:
            if (t.command_volume == 0) {
                if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                    if (t.shelf && !t.command_cur) {
                        if (!t.use_item) t.use_item = 8;
                        item.event_use[0] = t.item_kind;
                        ItemPutForShelf();
                        item_select[kind_no(t.item_kind)].del = 1;
                        t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    } else 
                        if (t.command_cur == t.shelf) {
                            t.command_cur = 0;
                            t.command_volume = 2;
                            SeCall(10002, 1.0f, -30);
                        } else {
                            
                            t.command_cur = 0;
                            t.command_volume = 1;
                            SeCall(10002, 1.0f, -30);
                        }
                }
            } else
                if (t.command_volume == 2) {
                    if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn) {
                        if (t.command_cur == 0) {
                            item.radio_switch = 1;
                            t.command_volume = 0;
                            t.step = 1;
                            SeCall(10002, 1.0f, -30);
                        } else {
                            
                            item.radio_switch = 0;
                            t.command_volume = 0;
                            t.step = 1;
                            SeCall(10002, 1.0f, -30);
                        }
                    }
                } else {
                    
                    if ((shPadPress(0, PAD_KEY_DPAD_RIGHT)) || (shPadPress(0, PAD_KEY_DPAD_LEFT)) || t.analog[1] || t.analog[2]) t.volume_time++;
                    else t.volume_time = 0;
                    
                    if (((shPadPress(0, PAD_KEY_DPAD_RIGHT)) || t.analog[2]) 
                        && ((((t.volume_time % 20) == 1) && (t.volume_time < 20)) || (((t.volume_time % 3) == 1) && (t.volume_time >= 20))))
                        if (item.radio_volume < 15) {
                            item.radio_volume++;
                            SeCall(19017, (4.0f + item.radio_volume) / 20.0f, -30);
                        }
                    
                    if (((shPadPress(0, PAD_KEY_DPAD_LEFT)) || t.analog[1]) 
                        && ((((t.volume_time % 20) == 1) && (t.volume_time < 20)) || (((t.volume_time % 3) == 1) && (t.volume_time >= 20))))
                        if ((item.radio_volume > 0)) {
                            item.radio_volume--;
                            SeCall(19017, (4.0f + item.radio_volume) / 20.0f, -30);
                        }
                    if ((shPadTrigger(0, key_config.enter)) && !t.volume_time) {
                        t.command_volume = 0;
                        t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    }
                    look_volume();
                }
            if (t.command_volume == 0) 
                t.gosa = -143 - (t.shelf * 15), t.cur_max = t.shelf + 1;
            else if (t.command_volume == 1) t.gosa = -135, t.cur_max = 0;
            else t.gosa = -135, t.cur_max = 1;
            break;
        
        case 8:
            t.gosa = -143 - (t.shelf * 15);
            t.cur_max = t.shelf + 1;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn && !t.use_item) {
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else
                    if (t.command_cur == t.shelf) {

                        
                        event_item_use(t.item_kind);
                        if (!t.use_item) t.step = 1;
                        SeCall(10002, 1.0f, -30);
                    } else {
                        
                        t.use_item = 4;
                        t.step = 11;
                        SeCall(10002, 1.0f, -30);
                    }
            }
            break;
        case 9:
            t.gosa = -143 - (t.shelf * 15);
            t.cur_max = t.shelf + 1;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn && !t.use_item) {
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else 
                    if (t.command_cur == t.shelf) {
                        
                        
                        event_item_use(t.item_kind);
                        SeCall(10002, 1.0f, -30);
                    } else {
                        
                        t.fade_flag = 2;
                        ScreenEffectFadeStart(1, 0.5f);
                        if (t.item_kind == 18) {
                                t.examine_msg = 184;
                                FcRead(data_pic_etc_p_letterm_tex, get_gp_data_buf_addr());
                        } else 
                            if (t.item_kind == 19) {
                                    t.examine_msg = 185;
                                    FcRead(data_pic_etc_p_laura_letter_tex, get_gp_data_buf_addr());
                            } else 
                                if (t.item_kind == 71) {
                                        t.examine_msg = 186;
                                        FcRead(data_pic_out_p_lostmemory_tex, get_gp_data_buf_addr());
                                } else 
                                    if (t.item_kind == 72) {
                                            t.examine_msg = 187;
                                            FcRead(data_pic_htl_p_redreling_tex, get_gp_data_buf_addr());
                                    }
                        SeCall(10002, 1.0f, -30);
                    }
            }
            break;
    
        case 10:
            t.gosa = -158;
            t.cur_max = 2;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn && !t.use_item) {
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else 
                    if (t.command_cur == t.shelf) {
                        if (t.combine[0] == 0) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) && !t.combine[1]) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) || (t.item_kind == t.combine[1])) combine_item_use(0);
                        else combine_item_use(t.item_kind);
                        SeCall(10002, 1.0f, -30);
                    } else 
                        if (!t.shelf && (t.command_cur == 1)) {
                            if (t.combine[0] == 0) t.combine[0] = t.item_kind;
                            else if (!t.combine[1] && ((short) t.combine[0] != t.item_kind)) t.combine[1] = t.item_kind;
                            else if ((t.combine[1]) && ((short) t.combine[0] != t.item_kind) && ((short) t.combine[1] != t.item_kind)) t.combine[2] = t.item_kind;
                            else if (t.combine[1]) combine_item_use(0);
                            if (!t.use_item) t.step = 1;
                            SeCall(10002, 1.0f, -30);
                        } else {
                            
                            t.step = 12;
                            SeCall(10002, 1.0f, -30);
                        }
            }
            break;
        case 11:
            t.gosa = -143 - (t.shelf * 15);
            t.cur_max = t.shelf + 1;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn && !t.use_item) {
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                } else 
                    if (t.command_cur == t.shelf) {
                        if (t.combine[0] == 0) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) && !t.combine[1]) event_item_use(t.item_kind);
                        else if ((t.item_kind == (short) t.combine[0]) || (t.item_kind == t.combine[1])) combine_item_use(0);
                        else combine_item_use(t.item_kind);
                        SeCall(10002, 1.0f, -30);
                    } else {
                        
                        t.step = 12;
                        SeCall(10002, 1.0f, -30);
                    }
            }
            break;


        
        default:
            t.gosa = -133;
            t.cur_max = 0;
            if ((shPadTrigger(0, key_config.enter)) && !t.prs_btn && !t.use_item)
                if (t.shelf && !t.command_cur) {
                    if (!t.use_item) t.use_item = 8;
                    item.event_use[0] = t.item_kind;
                    ItemPutForShelf();
                    item_select[kind_no(t.item_kind)].del = 1;
                    t.step = 1;
                    SeCall(10002, 1.0f, -30);
                }
            break;
        
        case 12:
            break;
    }
    if (((shPadTrigger(0, PAD_KEY_DPAD_DOWN)) || (t.analog[0] == 1)) && !t.use_item)
        if (t.command_cur < t.cur_max) {
            t.command_cur++;
            SeCall(10000, 1.0f, -30);                
        }
    if (((shPadTrigger(0, PAD_KEY_DPAD_UP)) || (t.analog[3] == 1)) && !t.use_item)
        if (t.command_cur > 0) {
            t.command_cur--;
            SeCall(10000, 1.0f, -30);
        }

    
}

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", weapon_command_main);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_main_setup);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", set_position);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_turn);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_position);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", move_near);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", command_kind);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", del_check);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", kind_no);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", event_item_use);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", combine_item_use);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", examine_main);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", examine_file_load);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", examine2_main);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", font_print);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", kage_font);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", lookline);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_allay);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", sprite);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_command);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_volume);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_hp);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", stock_line);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_combine);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_zanzo);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", look_blackscr);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_fade_in);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_fade_out);

INCLUDE_ASM("asm/nonmatchings/Item/otn_itemmain", item_examine_fade_out);
