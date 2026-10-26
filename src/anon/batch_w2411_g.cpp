#include "../common/types.h"
extern "C" {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_00276e78(void);
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32);
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f214;
struct Lay77 { u8 pad[40]; void* img; };

void func_002a7dc8(void);
void func_002a7f58(void);
void func_002a7d10(void);
void func_002a8768(void);
void func_002a8330(void);
void func_002a8748(void);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
void* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void func_0028af90(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void jm_hide(s32) asm("_ZN2Tz6Jiminy13SetHideCursorEb");
void sel_dis(s32, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
extern s32 D_0035f200;
extern s32* D_0035f600;
static inline s32 GetImg77(s32 i, void* self) { return yi_img(self, i); }
void func_002a77a0(void) {
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    func_002a7dc8();
    s32 n = D_0035f3d4 - 1;
    func_00276e78();
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 101, -1, 0);
    u8* seq2 = seq + 1224;
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 109, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, h, h);
    void* it = sel_item(D_0035f200, 0);
    obj_xyoff(it);
    mc_as(it, seq);
    func_002a7f58();
    s32 n2 = D_0035f3d4;
    s32 pg = *D_0035f600 - 10;
    if (pg > 0) pg = pg + 1; else pg = 1;
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    Lay77* lay = (Lay77*)lay_get(D_0035f210);
    s32 im = GetImg77(D_0035f148, lay->img);
    func_0028bae0(D_0035f214, n2, u, im, jm_scrbar(), *D_0035f600, 10, seq2, 0);
    func_0028af90(D_0035f200, pg);
    func_002891f0(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, 0);
    jm_hide(1);
    sel_dis(D_0035f200, 16);
    if (pg >= 2) {
        func_0028b218(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    func_002a7d10();
    func_002a8768();
    func_002a8330();
    func_002a8748();
    sel_set(0);
}
}
