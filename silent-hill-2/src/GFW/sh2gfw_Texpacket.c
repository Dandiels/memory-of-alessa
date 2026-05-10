#include "common.h"
#include "GFW/sh2gfw_alltexman.h"
#include "GFW/sh2gfw_blockman.h"
#include "GFW/sh2gfw_Texpacket.h"
#include "Multi_thr/dma/dma1tscmd.h"
#include "Multi_thr/dma/dma2tscmd.h"

static sh2gfw_TexMAN* sh2gfw_get_newMANID(sh2gfw_ALLTEXSYNC_MAN* pATSM);
static void sh2gfw_init_SyncTexTag(sh2gfw_TexMAN* sTM, sh2gfw_TEX_HEAD* pTexHead, sh2gfw_CLUTS_HEAD* pClutHead, void* pMAN, u_short mode);
static int Fake_SetTexSlot(int sid, void* pk);
// static void SetTexture2table(TexTable_List* pTL, void* pTexMan, int mark);
static int GetTexList_MinMark(void);

extern /* static */ Q_WORDDATA fake_kick; // size: 0x10, address: 0x2AB740

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_allinit_TexMANlist);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_clear_TexMAN_TransParm);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_set_TexToTrasMan);

static sh2gfw_TexMAN* sh2gfw_get_newMANID(sh2gfw_ALLTEXSYNC_MAN* pATSM) {
    sh2gfw_TexMAN* plc = &pATSM->Empty_Head; // r3 v1
    sh2gfw_TexMAN* pUs = &pATSM->Used_Head; // r5 a1
    sh2gfw_TexMAN* pTp;

    if (plc != plc->pNext && plc->pNext != plc) {
        pTp = plc->pNext; // r2 v0
        pTp->pPrev->pNext = pTp->pNext;
        pTp->pNext->pPrev = pTp->pPrev;
        pTp->pNext = pUs->pNext;
        pTp->pPrev = pUs;
        pUs->pNext->pPrev = pTp;
        pUs->pNext = pTp;
    }

    return pTp;
}

sh2gfw_TexMAN* sh2gfw_del_TexMAN(sh2gfw_ALLTEXSYNC_MAN* pATSM, sh2gfw_TexMAN* pDel) {
    sh2gfw_TexMAN* plc = &pATSM->Empty_Head; // r6
    sh2gfw_TexMAN* pUs; // r2 @todo present in dwarf, but unused here
    sh2gfw_TexMAN* pTp; // r2 @todo present in dwarf, but unused here

    pDel->pPrev->pNext = pDel->pNext;
    pDel->pNext->pPrev = pDel->pPrev;
    
    pDel->pPrev = plc;
    pDel->pNext = plc->pNext;
    plc->pNext->pPrev = pDel;
    plc->pNext = pDel;
    
    if (pDel->mode != 0xFFFF) pATSM->alltexnum--;
    
    switch (pDel->mode & 0xF000) {
        case 0x5000:
        case 0x6000:
        case 0x7000:
            if (pDel->mode >= 0x7000) {
                pATSM->g_BG--;
            } else if ((pDel->mode < 0x1B58) && (pDel->mode >= 0x1770)) {
                pATSM->st_BG--;
            } else {
                pATSM->l_BG--;
            }
            pATSM->alltex_BG--;
            break;
        
        case 0xD000:
            pATSM->fonttex--;
            break;
        
        case 0xE000:
            pATSM->alltex_EFF--;
            break;
        
        case 0xF000:
            break;

        default:
            // @todo: add macros for these
            if (pDel->mode >= 0x100 && pDel->mode < 0x12E) {
                pATSM->human_CHR--, pATSM->alltex_CHR--; // player models
            } else if (pDel->mode >= 0x200 && pDel->mode < 0x212) {
                pATSM->en_CHR--, pATSM->alltex_CHR--; // enemy models
            } else if (pDel->mode >= 0x300 && pDel->mode < 0x314) {
                pATSM->ura_CHR--, pATSM->alltex_CHR--;
            } else if (pDel->mode >= 0x700 && pDel->mode < 0x748) {
                pATSM->x_CHR--, pATSM->alltex_CHR--; // `x_` models (such as `x_redrelig.mdl`)
            } else if (pDel->mode >= 0x800 && pDel->mode < 0x82B) {
                pATSM->wp_CHR--, pATSM->alltex_CHR--; // weapon models
            } else if (pDel->mode >= 0x500 && pDel->mode < 0x562) {
                pATSM->oS_CHR--, pATSM->alltex_CHR--;
            } else if (pDel->mode >= 0x400 && pDel->mode < 0x446) {
                pATSM->oA_CHR--, pATSM->alltex_CHR--;
            } else {
                pATSM->bg_CHR--, pATSM->alltex_CHR--; // maps
            }
            break;
    }
    
    pDel->mode = 0xFFFF;
    
    return pDel;
}

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_init_SyncTexTag);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_Change_TexBody);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_Reset_TexBody);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_Get_RegTEX0);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_Get_TFX);

int sh2gfw_Thr_d2TextureSend(void* ptm, int mode, int* cid, int* slotid) {
    sh2gfw_TexMAN* pTM = ptm; // r16
    int slot = sh2gfw_EnQue_TexSlot(pTM); // r17
    int comid; // r2

    sh2gfw_SetSlot2Tex(pTM, slot, mode);
    d2tscBeginToUseSlot(slot);

    comid = d2tscSend(slot, (int) pTM, &pTM->DMACNT);

    *cid = comid;
    *slotid = slot;

    pTM->commandid = comid;
    pTM->slotid = slot;

    return comid;
}

int sh2gfw_Thr_d1d2SyncKick(void* pkaddr, int cid, int slotid) {
    int d1cid;
    d1tscSync(cid);
    d1cid = d1cSend(pkaddr);
    d1tscFinishToUseSlot(slotid);
    return d1cid;
}

static int Fake_SetTexSlot(int sid, void* pk) {
    d2tscBeginToUseSlot(sid);
    return d2tscSend(sid, (u_int) pk + sid, pk);
}

void sh2gfw_Lock_AllTexSlot_For_Shadow(void) {
    int i;
    for (i = 1; i < 5; i++) {
        fake_cid[i] = Fake_SetTexSlot(i, &fake_kick);
    }
}

void sh2gfw_UnLock_AllTexSlot_For_Shadow(void) {
    int i;
    for (i = 1; i < 5; i++) {
        sh2gfw_Thr_d1d2SyncKick(&fake_kick, fake_cid[i], i);
    }
}

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_init_TexTrans_Manage_Table);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_EnQue_TexSlot);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", SetTexture2table);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", sh2gfw_SetSlot2Tex);

INCLUDE_ASM("asm/nonmatchings/GFW/sh2gfw_Texpacket", GetTexList_MinMark);
