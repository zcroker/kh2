// Linked unit 0x002a4e38-0x002a52b0 (Jiminy list menu set-up; was whole asm in src/anon/batch_w3942.s).
#include "../common/types.h"

namespace n002a4e38 {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
void func_002a5d30(void) asm("func_002a5d30");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_00276e78(void) asm("func_00276e78");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
s32 yi_cr(void*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 yi_x(void*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 yi_y(void*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 jm_curpos(s32) asm("_ZN2Tz6Jiminy9GetCurPosEi");
s32 jm_curtop(s32) asm("_ZN2Tz6Jiminy12GetCurTopPosEi");
void jm_hidel(s32) asm("_ZN2Tz6Jiminy18SetHideLightCursorEb");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
extern s32 D_0035f200 asm("D_0035f200");
struct Lay { u8 pad[40]; void* img; };
struct Obj { u8 pad[408]; void* x198; u8 pad2[8]; s32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; };
struct Fade { u8 pad[408]; };
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("func_00288d80");
Obj* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void reset_alpha(Obj*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
void set_off(Obj*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void mc_create(Obj*, s32, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz10MenuCursor6CreateEz");
void func_0028af90(s32, s32) asm("func_0028af90");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void func_0028b218(s32, s32) asm("func_0028b218");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_002a5df0(void) asm("func_002a5df0");
void func_002a65d0(void) asm("func_002a65d0");
void func_002a65a0(void) asm("func_002a65a0");
extern u8* D_0035f5ec asm("D_0035f5ec");
extern Obj* D_0035f5f0 asm("D_0035f5f0");
/*TARGET 002a4e38*/
// Builds the two frame objects, then one row per list entry (at most 10): the Select item, its MenuCursor and its
// fade object, each row `cr` lower than the one before; then the page and scroll bar set-up.
// Notes for matching: the draw priority is kept as `D_0035f3d4 - 1` and the rows use n + 1 and n + 2; the same
// variable takes the fresh value for the scroll bar at the end. The row offset is `i * cr` and the fade object
// `base + i` (the loop pass makes the stepping registers). The cursor address is taken at the top of the row
// and again after the item is done: the first one only fixes the order in which the stepping registers are set up.
void func_002a4e38(void) asm("func_002a4e38");
void func_002a4e38(void) {
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    func_002a5d30();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s16 h[2][4];
    s32 i;
    s32 cr, cnt, x, y;
    u8* seq2;
    for (i = 0; i < 2; i++)
        for (s32 j = 0; j < 4; j++) h[i][j] = 2;
    s32 n = D_0035f3d4 - 1;
    func_00276e78();
    seq2 = seq + 1224;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 110, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 111, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    cr = yi_cr(seq + 24);
    x = yi_x(seq + 24);
    y = yi_y(seq + 24);
    cnt = 10;
    s32 t = *(s8*)D_0035f5ec;
    if (t < 10) cnt = t;
    for (i = 0; i < cnt; i++) {
        Obj* p = &D_0035f5f0[i];
        func_00288d80(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, h[0], h[1]);
        Obj* it = sel_item(D_0035f200, i);
        obj_xyoff(it);
        mc_as(it, seq);
        set_off(it, 0, i * cr);
        it->x1ac = 3;
        it->x1a4 = 0x60000008;
        reset_alpha(it);
        p = &D_0035f5f0[i];
        mc_create(p, n + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, -1, 0);
        obj_xyoff(seq);
        mc_as(p, seq);
        set_off(p, x, y + i * cr);
        p->x1ac = 3;
        p->x1a4 = 0x60000008;
        p->x1b0 = 1;
        p->x198 = D_0035f5ec + i * 16 + 31;
        Fade* c = (Fade*)(seq + 0xa998) + i;
        pz_cfo(c, n + 2, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        mc_as(c, p);
    }
    s32 num = *(s8*)D_0035f5ec;
    func_002891f0(D_0035f200, jm_curpos(mb_mode()), 0, -1, -1);
    func_0028af90(D_0035f200, num);
    func_0028afd0(D_0035f200, jm_curtop(mb_mode()));
    if (num >= 2) {
        func_0028b218(D_0035f200, 1);
        func_0028b248(D_0035f200, 10);
    }
    n = D_0035f3d4;
    if (num > 10) cnt = num; else cnt = 10;
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, n, u, im, jm_scrbar(), cnt, 10, seq2, 0);
    func_002a5df0();
    func_002a65d0();
    func_002a65a0();
    jm_hidel(1);
    sel_set(0);
}
}  // namespace n002a4e38
