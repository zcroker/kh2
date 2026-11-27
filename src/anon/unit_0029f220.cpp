// Linked unit 0x0029f220-0x0029f938.
#include "../common/types.h"

// 0029f220 (was src/anon/batch_w1611.cpp)
namespace n0029f220 {
extern void* D_0035f200 asm("D_0035f200");
s32 func_00242848(s32) asm("func_00242848");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
void func_00275b60() asm("func_00275b60");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
s32 func_00276358() asm("func_00276358");
s32 func_00276368() asm("func_00276368");
s32 func_00276398() asm("func_00276398");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002766b0(s32) asm("func_002766b0");
s32 func_00276888() asm("func_00276888");
void Tz__Jiminy__FadeOutHelp() asm("Tz__Jiminy__FadeOutHelp");
s32 func_00287bc0() asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30() asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0() asm("func_00287cd0");
void func_00287da0() asm("func_00287da0");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018() asm("func_00288018");
s32 func_00288040() asm("func_00288040");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_00289310(void*) asm("func_00289310");
s32 func_00289380(void*) asm("func_00289380");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028af18(void*, s32) asm("func_0028af18");
s32 func_0028b038(void*) asm("func_0028b038");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void func_002925c0() asm("func_002925c0");
s32 func_00292630() asm("func_00292630");
void func_002995e8() asm("func_002995e8");
void func_0029ee30() asm("func_0029ee30");
void Tz__JmAnsem__LeaveAll() asm("Tz__JmAnsem__LeaveAll");
void func_0029f520() asm("func_0029f520");
extern char D_002a0518[] asm("D_002a0518");
/*TARGET 0029f220*/
void Tz__JmAnsem__CtrlTop(void) asm("Tz__JmAnsem__CtrlTop");
void Tz__JmAnsem__CtrlTop(void) {
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                Tz__JmAnsem__LeaveAll();
            }
            return;
        }
        if (func_00292630()) return;
        Tz__JmAnsem__LeaveAll();
        func_00287c30();
        s32 mode = func_00287bc0();
        func_0028af18(D_0035f200, 0x73);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (mode == 13) {
            Tz__Jiminy__LoadData(13);
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
        } else if (mode == 25) {
            func_0029f520();
        }
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) {
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, D_002a0518, 1))) {
        switch (sel) {
        default:
            func_0029ee30();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_00287c00(25);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        case -4:
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            Tz__SelHist__FadeOut(0);
            func_0029ee30();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029f220

// 0029f520 (was whole asm in src/anon/batch_w3907.s): builds the pause-menu Jiminy page (two fade objects, one
// list item, the selector cursor, scroll bar). The item and the cursor are each set up in a one-iteration loop.
namespace n0029f520 {
u8* jm_parent(void) asm("func_00276348");
u8* jm_seqtbl(void) asm("func_002766d0");
u8* jm_scrbar(void) asm("func_00276678");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void obj_xyoff(void*) asm("func_00139620");
void mc_as(void*, void*) asm("func_0028dcc0");
void* lay_get(s32) asm("func_0023f1b0");
s32 yi_unit(void*, s32) asm("func_0023c4b8");
s32 yi_img(void*, s32) asm("func_00236ca8");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void sel_set(s32) asm("func_00287cc0");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
struct Lay { u8 pad[40]; void* img; };
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
struct Obj { u8 pad[408]; s32 x198; u8 pad2[8]; u32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; void* x1b4; };
Obj* sel_item(s32, s32) asm("func_002891b8");
void reset_alpha(Obj*) asm("func_001395f8");
void mc_create(Obj*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void Tz__JmAnsem__DrawMess(void) asm("Tz__JmAnsem__DrawMess");
struct Ent2 { u8 pad[2]; u16 x2; u16 x4; };
Ent2* func_002a01c8(s32) asm("func_002a01c8");
s32 jm_selpos(s32) asm("func_00276638");
struct RD { s8 x0; s8 x1; s8 x2; s8 x3; u16 x4; s8 items[1]; };
extern RD* D_0035f5d0 asm("D_0035f5d0");
s32 yi_cr(void*) asm("func_0023aa78");
s32 func_00192048(u32) asm("func_00192048");
s32 func_00192b80(s32) asm("func_00192b80");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void jm_hide(s32) asm("func_00276690");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
u32 sel_gen(s32) asm("func_0028af88");
void sel_sen(s32, u32) asm("func_0028af18");
s32 func_002a00f0(void) asm("func_002a00f0");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void sel_loop(s32, s32) asm("func_0028b1e8");
void func_002a03a0(void) asm("func_002a03a0");
extern s32 D_0035f200 asm("D_0035f200");
void func_0029f520(void) asm("func_0029f520");
void func_0029f520(void) {
    s32 i; s32 pg; u8* seq2; Obj* c; s32 m; s32 n;
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    jm_hide(1);
    s16 h[2][4];
    for (i = 0; i < 2; i++)
        for (s32 j = 0; j < 4; j++) h[i][j] = 2;
    n = D_0035f3d4;
    m = n - 1;
    Tz__Jiminy__CreateCover();
    pz_cfo(seq, m, D_0035f14c, D_0035f148, D_0035f210, 97, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    seq2 = seq + 1224;
    pz_cfo(seq2, m, D_0035f14c, D_0035f148, D_0035f210, 100, -1, 0);
    c = (Obj*)(seq + 3376);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    for (i = 0; i < 1; i++) {
    Tz__Select__SetItem(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, h[0], h[1]);
    obj_xyoff(sel_item(D_0035f200, i));
    mc_as(sel_item(D_0035f200, i), seq);
    sel_item(D_0035f200, i)->x1ac = 3;
    sel_item(D_0035f200, i)->x1a4 = 0x60000008;
    reset_alpha(sel_item(D_0035f200, i));
    }
    sel_item(D_0035f200, 0)->x1b4 = (void*)Tz__JmAnsem__DrawMess;
    pg = 1;
    for (i = 0; i < 1; i++) {
    mc_create(c, n, D_0035f14c, D_0035f148, D_0035f210, 98, -1, -1, 0);
    obj_xyoff(c);
    mc_as(c, par);
    c->x1a4 = 0x60000008;
    c->x1ac = 3;
    reset_alpha(c);
    c->x1b0 = 2;
    }
    s32 sp = jm_selpos(24);
    Ent2* e = func_002a01c8(D_0035f5d0->items[sp]);
    D_0035f5d0->x4 = e->x4;
    D_0035f5d0->x2 = yi_cr(seq + 24);
    D_0035f5d0->x1 = func_00192b80(func_00192048(e->x4));
    c->x198 = func_00192048(e->x2);
    s8 v = D_0035f5d0->x1;
    if (v >= 10) pg = v - 8;
    Tz__Select__SetSelectMax(D_0035f200, pg);
    Tz__Select__SetCurrent(D_0035f200, 0, 0, -1, -1);
    func_0028afd0(D_0035f200, 0);
    m = D_0035f3d4;
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, m, u, im, jm_scrbar(), D_0035f5d0->x1, 9, seq2, 0);
    Tz__ScrollBar__SetPos(D_0035f214, 0);
    u32 en = sel_gen(D_0035f200);
    en = func_002a00f0() < 2 ? en : en | 0xc000;
    sel_sen(D_0035f200, en & ~0x10);
    if (pg >= 2) {
        Tz__Select__SetPageMode(D_0035f200, 1);
        func_0028b248(D_0035f200, 9);
    }
    sel_loop(D_0035f200, 0);
    func_002a03a0();
    sel_set(0);
}
}  // namespace n0029f520
