// Linked unit 0x0029af20-0x0029b698.
#include "../common/types.h"

// 0029af20 (was whole asm in src/anon/batch_w3941.s)
namespace n0029af20 {
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32* D_0035f5ac asm("D_0035f5ac");
extern u8 D_0035f5b4 asm("D_0035f5b4");
struct Lay { u8 pad[40]; s32 img; };
struct Obj { u8 pad[408]; s32 x198; u8 pad2[8]; u32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; void* x1b4; };
struct Cur { u8 pad[408]; };
void setOffsetPos(void*, s32, s32) asm("func_00138c68");
void reset_alpha(void*) asm("func_001395f8");
void obj_xyoff(void*) asm("func_00139620");
s32 yi_img(s32, s32) asm("func_00236ca8");
s32 yi_cr(void*) asm("func_0023aa78");
s32 yi_unit(void*, s32) asm("func_0023c4b8");
Lay* lay_get(s32) asm("func_0023f1b0");
u8* jm_parent() asm("func_00276348");
s8* jm_sel() asm("func_00276568");
s32 jm_curpos(s32) asm("func_00276608");
s32 jm_curtop(s32) asm("func_00276620");
u8* jm_scrbar() asm("func_00276678");
void jm_hide(s32) asm("func_002766b0");
u8* jm_seqtbl() asm("func_002766d0");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
s32 mb_mode() asm("func_00287bc0");
void sel_set(s32) asm("func_00287cc0");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
Obj* sel_item(s32, s32) asm("func_002891b8");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void mc_as(void*, void*) asm("func_0028dcc0");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0029c958(void) asm("func_0029c958");
void func_0029cdf8(void) asm("func_0029cdf8");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void Tz__JmDic__UpdateHelpMess(void) asm("Tz__JmDic__UpdateHelpMess");
void func_0029af20(void) asm("func_0029af20");
void func_0029af20(void) {
    s16 tab[2][4];
    s32 step;
    u8* w2;
    s32 id;
    s32 n;
    s32 i;

    u8* cam = jm_parent();
    u8* w = jm_seqtbl();
    if (func_0028f930(0) == 0) {
        func_0028f4d8(0, -1, 0);
    }
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) {
            tab[i][j] = 2;
        }
    }
    s16* r1 = tab[1];
    w2 = w + 0x4C8;
    id = D_0035f3d4 - 1;
    Tz__Jiminy__CreateCover();
    pz_cfo(w, id, D_0035f14c, D_0035f148, D_0035f210, 90, -1, 0);
    obj_xyoff(w);
    mc_as(w, cam);
    pz_cfo(w2, id, D_0035f14c, D_0035f148, D_0035f210, 95, -1, 0);
    obj_xyoff(w2);
    mc_as(w2, cam);
    step = yi_cr(w + 0x18);
    id = D_0035f3d4;
    for (i = 0; i < 10; i++) {
        Tz__Select__SetItem(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, tab[0], r1);
        Obj* o = sel_item(D_0035f200, i);
        obj_xyoff(o);
        mc_as(o, w);
        setOffsetPos(o, 0, i * step);
        o->x1ac = 3;
        u32 bf = 3u << 29;
        bf |= 8;
        o->x1a4 = bf;
        reset_alpha(o);
        Cur* c = (Cur*)(w + 0xA998) + i;
        pz_cfo(c, id + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        mc_as(c, o);
    }
    func_0029c958();
    s32 cnt = 0;
    s32 sel = 0;
    for (i = 0; i < 19; i++) {
        if ((u8)((*D_0035f5ac >> i) & 1)) {
            if (*jm_sel() >= 0 && *jm_sel() != 15 && i != 0) {
                if (i - 1 == *jm_sel()) sel = cnt;
            }
            cnt++;
        }
    }
    s32 top;
    if (D_0035f5b4 != 0) {
        s32 v = cnt - 10;
        if (sel < v) {
            top = sel;
            n = 0;
        } else {
            top = v < 0 ? 0 : v;
            n = sel - top;
        }
        D_0035f5b4 = 0;
    } else {
        s32 m = mb_mode();
        n = jm_curpos(m);
        top = jm_curtop(m);
    }
    Tz__Select__SetSelectMax(D_0035f200, cnt);
    Tz__Select__SetCurrent(D_0035f200, n, 0, -1, -1);
    func_0028afd0(D_0035f200, top);
    Tz__Select__SetPageMode(D_0035f200, 1);
    func_0028b248(D_0035f200, 10);
    id = D_0035f3d4;
    if (cnt > 10) n = cnt; else n = 10;
    s32 a = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 b = yi_img(lay_get(D_0035f210)->img, D_0035f148);
    func_0028bae0(D_0035f214, id, a, b, jm_scrbar(), n, 10, w2, 0);
    Tz__ScrollBar__SetPos(D_0035f214, top);
    func_0029cdf8();
    Tz__JmDic__UpdateHelpMess();
    jm_hide(1);
    sel_set(0);
}
}  // namespace n0029af20

// 0029b378 (was src/anon/batch_w120.cpp)
namespace n0029b378 {
// 00180f28: moved to src/yasui/libys/progress.cpp


extern u32 D_0035f200 asm("D_0035f200");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
s32 func_00292630(void) asm("func_00292630");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(u32, s32) asm("func_0028af18");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0028b038(u32) asm("func_0028b038");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002766b0(s32) asm("func_002766b0");
struct SelState { u32 f0; s8 cur; };
extern SelState* D_0035f5ac asm("D_0035f5ac");
s32 func_00287c10(void) asm("func_00287c10");
void func_0029aac0(s32) asm("func_0029aac0");
void func_0029b698(void) asm("func_0029b698");
void func_0029ecf0(void) asm("func_0029ecf0");
void func_0029aa30(void) asm("func_0029aa30");
s8 Tz__JmDic__GetCur2World(s32) asm("Tz__JmDic__GetCur2World");
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32) asm("Tz__JmWorldSel__GetId2WorldName");
void func_0028fb28(s32, s32) asm("func_0028fb28");
/*TARGET 0029b378*/
void func_0029b378(void) asm("func_0029b378");
void func_0029b378(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_0029aac0(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_0029aac0(func_00287c10());
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (k == 13) {
            Tz__Jiminy__LoadData(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
            return;
        }
        if (k == 15) func_0029b698();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_0029ecf0, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            break;
        case -2:
            Tz__SelHist__FadeOut(0);  // record884_refresh_by_index
            func_0029aa30();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            break;
        default: {
            D_0035f5ac->cur = Tz__JmDic__GetCur2World(-1);
            func_0028fb28(1, Tz__JmWorldSel__GetId2WorldName(D_0035f5ac->cur, 0));
            func_0029aa30();
            Tz__Jiminy__FadeOutHelp();
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_002765e8(15, 0, 0);
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_00287c00(15);
            func_00287cc0(2);
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029b378

