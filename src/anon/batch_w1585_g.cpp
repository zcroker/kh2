#include "../common/types.h"
extern "C" {
void* tz_lsys(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void* menu_alloc(void) asm("_ZN4MENU15GetObjAllocatorEv");
void* tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void func_00324448(void*);
void func_003241a0(void*);

/* 002a1f88 */
struct E8 { u32 a, b; };
struct Big { u8 pad[0x108c]; E8 e[10]; };
extern Big* D_0035f5e4;
extern void* D_0035f5e8;
void func_002a1f88(void) {
    Big* p = (Big*)tz_alloc(0x10dc, tz_lsys());
    E8* e = p->e;
    s32 n = 9;
    do { e->a = 0; e->b = 0; n--; e++; } while (n != -1);
    D_0035f5e4 = p;
    void* q = tz_alloc(0x984c, menu_alloc());
    func_003241a0(q);
    D_0035f5e8 = q;
}

/* 002a7678 */
extern void* D_0035f600;
extern void* D_0035f604;
void func_002a7678(void) {
    void* t;
    D_0035f600 = tz_alloc(0x104, tz_lsys());
    t = tz_alloc(0x2350, tz_lsys());
    func_00324448(t);
    D_0035f604 = t;
}

/* 002a21b0 */
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_002a43f0(void);
void func_002a2a80(void);
void func_002a2c40(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_00276e78(void);
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002a3ba8(void);
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32);
void func_002a4b78(void);
void func_002a3aa8(void);
void func_002a3910(void);
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s32 D_0035f214;
struct Lay { u8 pad[40]; void* img; };
struct BigV { u8 pad[0x1080]; s32 v; };
struct H2 { s16 v; H2() : v(2) {} };
void func_002a21b0(void) {
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    if (func_002a43f0()) func_002a2a80();
    else func_002a2c40();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    s32 n = D_0035f3d4;
    u8* seq2 = seq + 1224;
    func_00276e78();
    n--;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 59, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 69, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    func_002a3ba8();
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, n, u, im, jm_scrbar(), ((BigV*)D_0035f5e4)->v, 9, seq2, 0);
    func_002a4b78();
    func_002a3aa8();
    func_002a3910();
    sel_set(0);
}

/* 002a2600 */
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002a2de8(void);
s32 func_002b3b60(s32);
void func_002a2600(void) {
    s32 m = mb_mode();
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    func_002a2de8();
    if (m == 8 && !func_0028f930(0)) func_0028f4d8(0, -1, 0);
    if (m == 33 && !func_0028f930(1)) func_0028f4d8(1, func_002b3b60(1), 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    s32 n = D_0035f3d4;
    u8* seq2 = seq + 1224;
    func_00276e78();
    n--;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 59, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 69, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    func_002a3ba8();
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, n, u, im, jm_scrbar(), ((BigV*)D_0035f5e4)->v, 9, seq2, 0);
    func_002a4b78();
    func_002a3aa8();
    func_002a3910();
    sel_set(0);
}
}
