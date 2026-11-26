// Linked unit 0x00297e68-0x00299920 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>
#include "../tozawa/jm_album.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/jm_collection.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00297e68 (album menu setup; was whole asm src/anon/batch_w3900.s)
namespace n00297e68 {
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void func_00288e88(s32) asm("func_00288e88");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
s32 yi_cr(void*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 jm_curpos(s32) asm("_ZN2Tz6Jiminy9GetCurPosEi");
void jm_savecur(s32, s32, s32) asm("_ZN2Tz6Jiminy10SaveCurPosEiii");
void jm_hidel(s32) asm("_ZN2Tz6Jiminy18SetHideLightCursorEb");
void jm_hide(s32) asm("_ZN2Tz6Jiminy13SetHideCursorEb");
s8* jm_info(void) asm("_ZN2Tz6Jiminy11GetMenuInfoEv");
u8* jmi_data(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
s32 jmi_album(void*) asm("_ZN2Tz6JmInfo13isEnableAlbumEPKNS_15JmAlbumDataInfoE");
void sel_dis(s32, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f200 asm("D_0035f200");
extern s8 D_0035f5a0 asm("D_0035f5a0");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern s8 D_0035f5a2 asm("D_0035f5a2");
extern s8 D_0035f5a3 asm("D_0035f5a3");
struct Fade { u8 pad[408]; };
struct Obj { u8 pad[408]; void* x198; u8 pad2[8]; s32 x1a4; u8 pad3[4]; s32 x1ac; s32 x1b0; u8 pad4[4]; };
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
Obj* sel_item(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void reset_alpha(Obj*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
void set_off(Obj*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void spr_num(Fade*, s32) asm("_ZN2dk6Sprite6setNumEi");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002982f0(void) asm("func_002982f0");
void func_00299260(void) asm("func_00299260");
void func_00299290(void) asm("func_00299290");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void* func_00192048(s32) asm("func_00192048");
void Tz__MenuUtil__MakeQuestionStr(s32, void*, s32) asm("Tz__MenuUtil__MakeQuestionStr");
s32 func_002983d8(s32) asm("func_002983d8");
s32 func_002aa668(s32, s32) asm("func_002aa668");
s32 func_002aa788(s32, s32) asm("func_002aa788");
struct Name { u8 b[64]; };
struct Seq { u8 pad[0x110a0]; Name names[10]; };
struct Album { u8 pad[8]; u16 msg; u8 pad2[2]; };
struct List { s32 count; s16 ids[1]; };
extern List* D_0035f598 asm("D_0035f598");
void msg_dup2(void*, void*) asm("_ZNK2YS7MESSAGE3dupEPc");
extern s32 D_003747c0 asm("D_003747c0");
extern s32 D_bc asm("D_003747bc");
void func_00297e68(void) asm("func_00297e68");
void func_00297e68(void) {
    u8* par = jm_parent();
    Seq* seq = (Seq*)jm_seqtbl();
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
    func_00288e88(D_0035f200);
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s32 pg;
    s16 h[2][4];
    s32 i;
    for (i = 0; i < 2; i++)
        for (s32 j = 0; j < 4; j++) h[i][j] = 2;
    s32 n = D_0035f3d4 - 1;
    Tz__Jiminy__CreateCover();
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 90, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    s32 cr = yi_cr((u8*)seq + 24);
    n = D_0035f3d4;
    for (i = 0; i < 8; i++) {
        Tz__Select__SetItem(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, h[0], h[1]);
        Obj* it = sel_item(D_0035f200, i);
        obj_xyoff(it);
        mc_as(it, seq);
        set_off(it, 0, i * cr);
        u32 bf = 3u << 29;
        bf |= 8;
        it->x1a4 = bf;
        it->x1ac = 3;
        reset_alpha(it);
        Fade* c = (Fade*)((u8*)seq + 0xa998) + i;
        pz_cfo(c, n + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        mc_as(c, it);
    }
    func_002982f0();
    func_002fde18(seq->names, 0, sizeof(seq->names));
    s32 cnt = D_0035f598->count;
    if (cnt == 0) {
        pg = 1;
        jm_hide(1);
        sel_item(D_0035f200, 0)->x198 = func_00192048(13021);
    } else {
        pg = cnt;
        Album* al = (Album*)(jmi_data(2) + 16);
        for (i = 0; i < cnt; i++) {
            s32 id = func_002983d8(D_0035f598->ids[i]);
            s32 en = jmi_album((void*)id);
            id = D_0035f598->ids[i];
            s32 m = al[id].msg;
            if (en == 0) Tz__MenuUtil__MakeQuestionStr(m, &seq->names[i], 64);
            else msg_dup2(func_00192048(m), &seq->names[i]);
            Obj* it = sel_item(D_0035f200, i);
            it->x198 = &seq->names[i];
            Fade* cc = (Fade*)((u8*)seq + 0xa998) + i;
            if (en && func_002aa668(*jm_info(), id))
                spr_num(cc, func_002aa788(*jm_info(), id) ? D_003747c0 : D_bc);
        }
    }
    Tz__Select__SetSelectMax(D_0035f200, pg);
    Tz__Select__SetCurrent(D_0035f200, jm_curpos(mb_mode()), 0, -1, -1);
    jm_savecur(mb_mode(), 0, 0);
    if (D_0035f598->count == 0) sel_dis(D_0035f200, 16);
    func_00299260();
    func_00299290();
    jm_hidel(1);
    sel_set(0);
}
}  // namespace n00297e68

// 002982f0 (was src/anon/batch_w8011_nsa.cpp)
namespace n002982f0 {
struct Ent12 { s8 id; s8 pad[11]; };
struct Tbl { s32 a; s32 b; s32 count; s32 c; Ent12 e[1]; };
struct IdList { s32 count; s16 ids[1]; };
extern IdList* D_0035f598 asm("D_0035f598");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
Tbl* func_00294000(s32) asm("func_00294000");
s8* func_00276568() asm("func_00276568");
s32 func_00294348(Ent12*) asm("func_00294348");
s32 func_00276c18() asm("func_00276c18");
/*TARGET 002982f0*/
void func_002982f0() asm("func_002982f0");
void func_002982f0() {
    s32 i;
    s32 n = 0;
    func_002fde18(D_0035f598, 0, 0x14);
    Tbl* t = func_00294000(2);
    s32 id = *func_00276568();
    Ent12* b = t->e;
    i = 0;
    if (t->count > 0) do {
        if (id == b[i].id) { if (func_00294348(&b[i]) || func_00276c18()) D_0035f598->ids[n++] = i; }
    } while (++i < t->count);
    D_0035f598->count = n;
}
}  // namespace n002982f0

// 002983d8 (was src/anon/tiny_auto80_solver.cpp)
namespace n002983d8 {
u32 func_00294000(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00294000jjjjjjjj");
/*TARGET 002983d8*/
u32 func_002983d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002983d8jjjjjjjj");
u32 func_002983d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (2));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00294000)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (12));
    r16 = (u32)(r16 * r15);
    r2 = (u32)((s32)r2 + (16));
    r2 = (u32)(r2 + r16);
    return r2;
}
}  // namespace n002983d8

// 00298410 (was src/anon/batch_w2412.cpp)
namespace n00298410 {
extern s32 D_0035f200 asm("D_0035f200");
extern u8 D_0035f5a0 asm("D_0035f5a0");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
s32 func_00287c10(void) asm("func_00287c10");
void Tz__JmAlbum__LeaveAll(s32) asm("Tz__JmAlbum__LeaveAll");
s32 func_00292630(void) asm("func_00292630");
void func_00276690(s32) asm("func_00276690");
void func_00287c30(void) asm("func_00287c30");
s32 func_0028af18(s32, s32) asm("func_0028af18");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__Jiminy__LoadData(s32) asm("Tz__Jiminy__LoadData");
void func_002925c0(void) asm("func_002925c0");
void func_002766b0(s32) asm("func_002766b0");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
void func_002986e0(void) asm("func_002986e0");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void func_00299408(void) asm("func_00299408");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00297df8(void) asm("func_00297df8");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00287da0(void) asm("func_00287da0");
void Tz__SelHist__FadeOut(s32) asm("Tz__SelHist__FadeOut");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 00298410*/
void Tz__JmAlbum__Control(void) asm("Tz__JmAlbum__Control");
void Tz__JmAlbum__Control(void)
{
    s32 r = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                Tz__JmAlbum__LeaveAll(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_00276690(0);
        Tz__JmAlbum__LeaveAll(func_00287c10());
        func_00287c30();
        s32 m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (m == st) {
            Tz__Jiminy__LoadData(2);
            func_002925c0();
            func_002766b0(0);
            Tz__JmReport__Setup();
        } else if (m == 5) {
            func_002986e0();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        Tz__Jiminy__SetParentSeqNum(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f200), 1, func_00299408, 1))) {
        switch (r) {
        case -2:
            Tz__SelHist__FadeOut(0);
            func_00297df8();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(2);
            func_00287cc0(2);
            break;
        case -4:
            func_00287da0();
            break;
        case -1: break;
        default:
            func_00297df8();
            D_0035f5a0 = r;
            Tz__Jiminy__FadeOutHelp();
            func_002765e8(func_00287bc0(), r, 0);
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_00287c00(5);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00298410

// 002986e0 (was src/anon/batch_w3915.cpp)
namespace n002986e0 {
struct Cnt { s32 n; s16 id[1]; };
u8* func_00276348(void) asm("func_00276348");
u8* func_002766d0(void) asm("func_002766d0");
void func_00288e88(s32) asm("func_00288e88");
void func_00276690(s32) asm("func_00276690");
void func_00298fe8(s32) asm("func_00298fe8");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_002983d8(s32) asm("func_002983d8");
void func_00294348(s32) asm("func_00294348");
s32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, s32) asm("func_0028af18");
void func_0028af28(s32, s32) asm("func_0028af28");
void Tz__JmAlbum__UpdateMess(void) asm("Tz__JmAlbum__UpdateMess");
void func_00299260(void) asm("func_00299260");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s8 D_0035f5a0 asm("D_0035f5a0");
extern Cnt* D_0035f598 asm("D_0035f598");
/*TARGET 002986e0*/
void func_002986e0(void) asm("func_002986e0");
void func_002986e0(void) {
    struct { s16 arr[2][4]; u32 attr; } L;
    register s32 i asm("$16");
    register u8* a asm("$23"); u8* b;
    a = func_00276348();
    b = func_002766d0();
    func_00288e88(D_0035f200);
    func_00276690(1);
    func_00298fe8(D_0035f5a0);
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) L.arr[i][j] = 87;
    }
    u8* c = b + 0xd30;
    i = D_0035f3d4 - 1; asm("" : "+r"(i));
    L.attr = 0x60000000;
    Tz__Jiminy__CreateCover();
    func_0028d8c0(b, i, D_0035f14c, D_0035f148, D_0035f210, 86, -1, 0);
    L.attr |= 8;
    func_00139620(b);
    func_0028dcc0(b, a);
    func_0028d980(c, i, D_0035f14c, D_0035f148, D_0035f210, 88, -1, -1, 0);
    func_00139620(c);
    func_0028dcc0(c, a);
    *(s32*)(c + 0x1ac) = 3;
    *(u32*)(c + 0x1a4) = L.attr;
    func_001395f8(c);
    Tz__Select__SetItem(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, L.arr[0], L.arr[1]);
    func_00139620(func_002891b8(D_0035f200, 0));
    func_0028dcc0(func_002891b8(D_0035f200, 0), b);
    *(s32*)(func_002891b8(D_0035f200, 0) + 0x1ac) = 3;
    *(u32*)(func_002891b8(D_0035f200, 0) + 0x1a4) = L.attr;
    func_001395f8(func_002891b8(D_0035f200, 0));
    for (i = 0; ({ register s32 n asm("$15") = D_0035f598->n; i < n; }); i++) func_00294348(func_002983d8(D_0035f598->id[i]));
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0xc000);
    func_0028af28(D_0035f200, 16);
    Tz__JmAlbum__UpdateMess();
    func_00299260();
    func_00287cc0(0);
}
}  // namespace n002986e0

// 00298988 (was src/anon/batch_wcx2.cpp)
namespace n00298988 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
extern s32 D_0035f200_298 asm("D_0035f200");
s32 func_00289380_x10684(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_00276368() asm("func_00276368");
s32 func_0028acc8_x10688(s32) asm("func_0028acc8");
s32 func_00276888() asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
s32 func_00287c10() asm("func_00287c10");
void Tz__JmAlbum__LeaveAll(s32) asm("Tz__JmAlbum__LeaveAll");
void func_00297e68() asm("func_00297e68");
void func_002986e0() asm("func_002986e0");
extern s8 D_0035f5a0 asm("D_0035f5a0");
void func_00299090() asm("func_00299090");
void Tz__JmAlbum__MovePage(s32) asm("Tz__JmAlbum__MovePage");
void func_00297df8() asm("func_00297df8");
void func_00287c30() asm("func_00287c30");
void func_0028af18_x10700(s32, s32) asm("func_0028af18");
s32 func_00276358() asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32, s32) asm("Tz__Jiminy__SetParentSeqNum");
void func_00276690(s32) asm("func_00276690");
void func_002766b0(s32) asm("func_002766b0");
s32 func_00289310_x10708(s32) asm("func_00289310");
s32 func_00276398() asm("func_00276398");
void func_00275b60() asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void func_00299408() asm("func_00299408");
s32 func_00287df0_298(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_00287da0() asm("func_00287da0");
void Tz__Jiminy__FadeOutHelp() asm("Tz__Jiminy__FadeOutHelp");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 00298988*/
void Tz__JmAlbum__PhotoControl() asm("Tz__JmAlbum__PhotoControl");
void Tz__JmAlbum__PhotoControl() {
    s32 r = func_00289380_x10684(D_0035f200_298);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_00276368() || func_0028acc8_x10688(D_0035f200_298) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                Tz__JmAlbum__LeaveAll(func_00287c10());
            }
            return;
        }
        func_00276690(0);
        func_002766b0(1);
        Tz__JmAlbum__LeaveAll(func_00287c10());
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x10700(D_0035f200_298, 115);
        if (s == 4) {
            Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
            func_002765e8(func_00287bc0(), D_0035f5a0, 0);
            func_00297e68();
        } else if (s == 5) {
            Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
            func_002986e0();
        }
        return;
    }
    func_00299090();
    if (r != -1 || func_00289310_x10708(D_0035f200_298)) {
        if (!func_00276398()) {
            Tz__Jiminy__SetParentSeqNum(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_298(r, func_00289310_x10708(D_0035f200_298), 1, func_00299408, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            Tz__JmAlbum__MovePage(r);
            func_00297df8();
            Tz__Jiminy__SetParentSeqNum(r != -10, 1);
            func_00287c00(func_00287bc0());
            func_00287cc0(2);
            break;
        case -2:
            func_00297df8();
            Tz__Jiminy__FadeOutHelp();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(4);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00298988
#undef QCOPY

// 00298c60 (was src/anon/batch_w114.cpp)
namespace n00298c60 {
// ---- 00298c60
struct List12 { s32 count; s16 items[1]; };
extern s8 D_0035f5a0 asm("D_0035f5a0");
extern List12* D_0035f598 asm("D_0035f598");
u32 func_002983d8(s32) asm("func_002983d8");
s32 func_00294348(u32) asm("func_00294348");
void func_00299290(void) asm("func_00299290");
static inline s32 usable12(s32 i) { return func_00294348(func_002983d8(D_0035f598->items[i])); }
void Tz__JmAlbum__MovePage(s32 dir) asm("Tz__JmAlbum__MovePage");
/*TARGET 00298c60*/
void Tz__JmAlbum__MovePage(s32 dir) asm("Tz__JmAlbum__MovePage");
void Tz__JmAlbum__MovePage(s32 dir) {
    s32 cur = D_0035f5a0;
    s32 i;
    if (dir == -10) {
        for (i = cur + 1; i < D_0035f598->count; i++) {
            if (usable12(i)) break;
        }
        if (i >= 8) {
            for (i = 0; i < cur; i++) {
                if (usable12(i)) break;
            }
        }
        cur = i;
        if (i >= D_0035f598->count) cur = 0;
    } else {
        for (i = cur - 1; i >= 0; i--) {
            if (usable12(i)) break;
        }
        if (i < 0) {
            for (i = D_0035f598->count - 1; cur < i; i--) {
                if (usable12(i)) break;
            }
        }
        cur = i >= 0 ? i : D_0035f598->count - 1;
    }
    D_0035f5a0 = cur;
    func_00299290();
}
}  // namespace n00298c60

// 00298e20 (was src/anon/batch_w1587.cpp)
namespace n00298e20 {
void func_00299290(void) asm("func_00299290");
/*TARGET 00298e20*/
void func_00298e20(u32 a0, s32 a1) asm("func_00298e20");
void func_00298e20(u32 a0, s32 a1) {
    if (a1 == 4) func_00299290();
}
}  // namespace n00298e20

// 00298e48 (was src/anon/batch_w63.cpp)
namespace n00298e48 {
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_002766d0(void) asm("func_002766d0");
u8* func_002983d8(s32) asm("func_002983d8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
u32 func_00192048(s32) asm("func_00192048");
extern s8 D_0035f5a0 asm("D_0035f5a0");
extern s16* D_0035f598 asm("D_0035f598");
extern u32 D_0035f200 asm("D_0035f200");
/*TARGET 00298e48*/
// 0028e560: moved to src/anon/unit_0028c878.cpp

void Tz__JmAlbum__UpdateMess(void) asm("Tz__JmAlbum__UpdateMess");
// 0028e560: moved to src/anon/unit_0028c878.cpp

void Tz__JmAlbum__UpdateMess(void) {
    if (func_00287bc0() != 5) return;
    u8* v;
    u8* s = func_002766d0() + 3376;
    v = func_002983d8(D_0035f598[D_0035f5a0 + 2]);
    *(u32*)(s + 408) = func_00192048(*(u16*)(v + 8));
    u8* s2 = func_002891b8(D_0035f200, 0);
    *(u32*)(s2 + 408) = func_00192048(*(u16*)(v + 10));
}
}  // namespace n00298e48

// 00298ee0 (was src/anon/batch_wcx.cpp)
namespace n00298ee0 {
// 0x00295710: definition moved into src/anon/unit_00292e60.cpp
extern u32 D_0035f59c asm("D_0035f59c");
extern s16* D_0035f598 asm("D_0035f598");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern u8 D_0035f5a2 asm("D_0035f5a2");
void func_0023f900(u32) asm("func_0023f900");
s32 func_00292630(void) asm("func_00292630");
s8* func_002983d8(s16) asm("func_002983d8");
char* func_00293de8(s8) asm("func_00293de8");
void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
void func_002feee8(char*, const char*) asm("func_002feee8");
u32 func_00293db8(s32, char*) asm("func_00293db8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
/*TARGET 00298ee0*/
void Tz__JmAlbum__FileAlloc(void) asm("Tz__JmAlbum__FileAlloc");
void Tz__JmAlbum__FileAlloc(void)
{
    char buf[32];
    func_0023f900(D_0035f59c);
    if (func_00292630()) return;
    s8* s = func_002983d8(D_0035f598[D_0035f5a1 + 2]);
    func_002ff2e8(buf, func_00293de8(s[0]));
    func_002feee8(buf, (char*)s + 1);
    func_0023fa08(D_0035f59c, func_00293db8(3, buf));
    D_0035f5a2 = 1;
}
}  // namespace n00298ee0

// 00298f90 (was src/anon/batch_w25.cpp)
namespace n00298f90 {
void LayFileReset(void) asm("_ZN2Tz12LayFileResetEv");
// 0x00294480: definition moved into src/anon/unit_00292e60.cpp

extern u8 D_0035f5a2 asm("D_0035f5a2");
extern u32 D_0035f59c asm("D_0035f59c");
s32 func_0023f900(u32) asm("func_0023f900");
void func_0023fad0(u32) asm("func_0023fad0");
void func_00293d80(u32) asm("func_00293d80");
/*TARGET 00298f90*/
void LayFileReset(void) asm("_ZN2Tz12LayFileResetEv");
void LayFileReset(void) {
    if (D_0035f5a2) {
        if (func_0023f900(D_0035f59c)) func_0023fad0(D_0035f59c);
    }
    func_00293d80(5101);
    D_0035f5a2 = 0;
}
}  // namespace n00298f90

// 00298fe8 (was src/tozawa/jm_album.cpp)
namespace Tz { // method 00298fe8
extern u32 D_0035f598 asm("D_0035f598");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern u8 D_0035f5a3 asm("D_0035f5a3");
u32 LoadDataIsFlushing() asm("_ZN2Tz18LoadDataIsFlushingEv");
void LayFileBuildData(void*, u32) asm("_ZN2Tz16LayFileBuildDataEPvj");
void LayFileSetImdData(u32, u32) asm("_ZN2Tz17LayFileSetImdDataEjj");
void LayFileReset() asm("_ZN2Tz12LayFileResetEv");
void LoadDataFlush() asm("_ZN2Tz13LoadDataFlushEv");
/*TARGET 00298fe8*/
void JmAlbum::RequestGraLoad(s32 a0) {
    u8 buf[32];
    s32 idx = (s8)a0;
    u32 off = (u32)idx;
    off <<= 1;
    off += D_0035f598;
    D_0035f5a1 = (s8)a0;
    u32 s0 = (u32)GetAlbumData(*(s16*)(off + 4));
    if (LoadDataIsFlushing() != 0) {
        D_0035f5a3 = 0;
        return;
    }
    u32 v = GetImageName(*(s8*)s0);
    LayFileBuildData(buf, v);
    LayFileSetImdData((u32)buf, s0 + 1);
    LayFileReset();
    RequestLoad(3, buf, 0);
    LoadDataFlush();
    D_0035f5a3 = 1;
}
}  // Tz

// 00299090 (was src/anon/perm_00299090.cpp)
namespace n00299090 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;
struct Sub2990
{
  u8 p[184];
  u32 flags;
};
struct Ctl2990
{
  u8 p0[24];
  Sub2990 sub;
  u8 p1[(392 - 24) - 188];
  s32 mode;
  u8 p2[405 - 396];
  u8 b195;
};
struct Q2990
{
  u8 p[400];
  u8 b190;
};
struct Base2990
{
  u8 p0[24];
  u8 s18[17304 - 24];
  Ctl2990 ctl;
  u8 p1[(0xdca0 - 17304) - (sizeof(Ctl2990))];
  Q2990 q;
};
inline static void SetC(Ctl2990 *c, s32 v)
{
  c->b195 = v;
}
Base2990 *func_002766d0() asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_00139d78(Ctl2990 *) asm("_Z16u_call4_00139d78jjjj");
void func_00298fe8(s32) asm("_ZN2Tz7JmAlbum14RequestGraLoadEi");
s32 func_00292630() asm("_ZN2Tz18LoadDataIsFlushingEv");
void Tz__JmAlbum__FileAlloc() asm("Tz__JmAlbum__FileAlloc");
s32 func_0023f1b0(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 func_0023c4b8(s32, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 func_0023f988(s32, s32) asm("_ZNK2Tz7LayFile13getImdAddressEi");
void YI__IMAGE__Init(Q2990 *, s32) asm("YI__IMAGE__Init");
void dk__Sprite__create(Ctl2990 *, s32, s32, Q2990 *, s32, s32) asm("dk__Sprite__create");
void func_00139620(Ctl2990 *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_0028dcc0(Ctl2990 *, Base2990 *) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
s32 func_0023aa18(void *) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 func_0023aa38(void *) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void func_00138c68(Ctl2990 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f59c asm("D_0035f59c");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern u8 D_0035f5a3 asm("D_0035f5a3");
/*TARGET 00299090*/
void func_00299090(void) asm("func_00299090");
void func_00299090(void)
{
  Base2990 *base = func_002766d0();
  Ctl2990 *new_var;
  Ctl2990 *c = &base->ctl;
  if (func_00139d78(c))
  {
    return;
  }
  if ((D_0035f5a3 == 0) && (D_0035f5a1 >= 0))
  {
    func_00298fe8(D_0035f5a1);
    return;
  }
  if ((double) ((D_0035f5a1 < 0) || func_00292630()))
  {
    return;
  }
  Tz__JmAlbum__FileAlloc();
  Q2990 *q = &base->q;
  s32 f = D_0035f210;
  s32 x = D_0035f3d4;
  void *s = base->s18;
  s32 r = func_0023c4b8(func_0023f1b0(f), 1);
  YI__IMAGE__Init(q, func_0023f988(D_0035f59c, 0));
  q->b190 = 1;
  dk__Sprite__create(c, x, r, q, 1, 0);
  c->mode = 2;
  new_var = c;
  func_00139620(new_var);
  Sub2990 *sb = &base->ctl.sub;
  sb->flags |= 8;
  SetC(c, 1);
  func_0028dcc0(c, base);
  s32 a = func_0023aa18(s);
  D_0035f3d4 += 0;
  func_00138c68(c, a, func_0023aa38(s));
  D_0035f5a1 = -1;
  D_0035f5a3 = 0;
}
}  // namespace n00299090

// 00299238 (was src/anon/batch_w1.cpp)
namespace n00299238 {
void* func_002766d0(void) asm("func_002766d0");
void func_0028dac8(void*, s32) asm("func_0028dac8");
/*TARGET 00299238*/
// 0x00281108: definition moved into src/anon/unit_0027f2b0.cpp

void func_00299238(void) asm("func_00299238");
// 0x00281108: definition moved into src/anon/unit_0027f2b0.cpp

void func_00299238(void) {
    func_0028dac8((u8*)func_002766d0() + 17304, 3);
}
}  // namespace n00299238

// 00299260 (was src/anon/batch_w10.cpp)
namespace n00299260 {
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00276c50(s32, s32) asm("func_00276c50");
/*TARGET 00299260*/
// 0x0028b218: definition moved into src/anon/unit_00288b00.cpp

void func_00299260(void) asm("func_00299260");
// 0x0028b218: definition moved into src/anon/unit_00288b00.cpp

void func_00299260(void) {
    func_00276c50(func_00287bc0() == 4 ? 18648 : 18649, 0);
}
}  // namespace n00299260

// 00299290 (was src/anon/batch_w1584_g.cpp)
namespace n00299290 {
extern s32 D_0035f200 asm("D_0035f200");
extern s16* D_0035f598 asm("D_0035f598");
extern s8 D_0035f5a0 asm("D_0035f5a0");
void func_00138c10(s32, s32) asm("func_00138c10");
s32 func_00139d78(s32) asm("func_00139d78");
s8* func_00276568() asm("func_00276568");
s32 func_002766d0() asm("func_002766d0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00294348(s32) asm("func_00294348");
s32 func_002983d8(s32) asm("func_002983d8");
s32 func_002a9d68() asm("func_002a9d68");
u32 func_002aa5b8(s32, s32) asm("func_002aa5b8");
void func_002aa8e0(s32, s32) asm("func_002aa8e0");
/*TARGET 00299290*/
void func_00299290(void) asm("func_00299290");
void func_00299290(void) {
    s32 s2 = func_002a9d68();
    s32 s3 = func_002766d0();
    if (*(s32*)D_0035f598 == 0) return;
    s32 mode = func_00287bc0();
    s32 idx;
    if (mode == 4) {
        idx = func_0028b040(D_0035f200);
    } else {
        idx = D_0035f5a0;
    }
    s32 id = D_0035f598[idx + 2];
    if (func_00294348(func_002983d8(id)) == 0) return;
    s32 c = *func_00276568();
    u32 bit = func_002aa5b8(c, id);
    s32 q = s2 + c * 4;
    q += (bit >> 5) * 4;
    if (*(u32*)(q + 0x44) & (1 << (bit & 0x1f))) return;
    func_002aa8e0(*func_00276568(), id);
    if (mode != 4) return;
    s32 p = 0x198;
    p = func_002891e8(D_0035f200) * p;
    u8* qq = (u8*)s3;
    qq += p;
    qq += 0xA998;
    p = (s32)qq;
    if (func_00139d78(p) == 0) return;
    func_00138c10(p, 0x5D);
}
}  // namespace n00299290

// 00299408 (gap: album select-check callback)
namespace g00299408 {
struct Ids { s32 n; s16 e[8]; };
extern Ids* D_0035f598 asm("D_0035f598");
s32 func_00287bc0(void) asm("func_00287bc0");
void* func_002983d8(s32) asm("func_002983d8");
s32 func_00294348(void*) asm("func_00294348");
void func_00299290(void) asm("func_00299290");
s32 func_00299408(s32 a0) asm("func_00299408");
s32 func_00299408(s32 a0) {
    s32 r;
    u32 m = func_00287bc0();
    if (m == 4) goto c4;
    if (m == 5) goto c5;
dflt:
    r = 1;
done:
    return r;
c5:
    if ((u32)(a0 + 11) >= 2) goto dflt;
    {
        s32 i, c = 0;
        for (i = 0; i < D_0035f598->n; i++) {
            if (func_00294348(func_002983d8(D_0035f598->e[i]))) c++;
        }
        i = c >= 2;
        r = i;
    }
    goto done;
c4:
    r = 1;
    if (a0 >= 0) r = func_00294348(func_002983d8(D_0035f598->e[a0])) != 0;
    func_00299290();
    goto done;
}
}  // namespace g00299408

// 002994f8 (was src/anon/batch_w1589_g.cpp)
namespace n002994f8 {
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_0023f800(void*) asm("func_0023f800");
extern u8 D_0035f5a8 asm("D_0035f5a8");
extern u8 D_0035f5a9 asm("D_0035f5a9");
extern void* D_0035f5a4 asm("D_0035f5a4");
/*TARGET 002994f8*/
// 0x002957b8: definition moved into src/anon/unit_00292e60.cpp

void Tz__JmCollection__Init(void) asm("Tz__JmCollection__Init");
// 0x002957b8: definition moved into src/anon/unit_00292e60.cpp

void Tz__JmCollection__Init(void)
{
    void* o;
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    o = func_001063c0(28, func_00103570());
    func_0023f800(o);
    D_0035f5a4 = o;
}
}  // namespace n002994f8

// 00299550 (was src/anon/batch_w28.cpp)
namespace n00299550 {
extern u8 D_0035f5a8 asm("D_0035f5a8");
extern u8 D_0035f5a9 asm("D_0035f5a9");
extern u8* D_0035f5a4 asm("D_0035f5a4");
/*TARGET 00299550*/
// 002924d0: moved to src/anon/unit_00290f78.cpp

void func_00299550(void) asm("func_00299550");
// 002924d0: moved to src/anon/unit_00290f78.cpp

void func_00299550(void) {
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    if (D_0035f5a4) {
        u8* o = D_0035f5a4;
        (*(void (**)(void*))(*(u8**)o + 4))(o);
        D_0035f5a4 = 0;
    }
}
}  // namespace n00299550

// 002995a0 (was src/anon/misc_2.cpp)
namespace n002995a0 {
/*TARGET 002995a0*/
// 0x00297df8: definition moved into src/anon/unit_00295d28.cpp

void func_002995a0(void* self) asm("_Z13func_002995a0Pv");
// 0x00297df8: definition moved into src/anon/unit_00295d28.cpp

void func_002995a0(void* self) {}
}  // namespace n002995a0

// 002995a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002995a8 {
u32 func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
u32 func_00287bc0(...) asm("func_00287bc0");
u32 func_0029a310(...) asm("func_0029a310");
/*TARGET 002995a8*/
u32 Tz__JmCollection__LeaveAll(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z26Tz__JmCollection__LeaveAlljjjjjjjj");
u32 Tz__JmCollection__LeaveAll(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00287bc0)();
    r15 = (u32)((s32)0u + (13));
    if (r2 == r15) {
        r2 = ((u32(*)())func_0029a310)();
        r2 = ((u32(*)())func_00274ac8)();
        r15 = (u32)(0x0036u << 16);
        *(volatile u8*)((u32)r15 + (s32)(-2647)) = (u8)0u;
    }
    return r2;
}
}  // namespace n002995a8

// 002995e8 (was src/anon/batch_w3912_mam.cpp)
namespace n002995e8 {
struct E { u8 pad[408]; };
struct Obj { u8 pad[30360]; E a[32]; E b[12]; };
extern void* D_0035f200 asm("D_0035f200");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f210 asm("D_0035f210");
void* func_00276348(void) asm("func_00276348");
Obj* func_002766d0(void) asm("func_002766d0");
void func_00276588(s32) asm("func_00276588");
void func_00288e88(void*) asm("func_00288e88");
void Tz__JmAnsem__GetHaveReport(void) asm("Tz__JmAnsem__GetHaveReport");
void func_0029a2a0(void) asm("func_0029a2a0");
void func_00275a80(void) asm("func_00275a80");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00276088(s32, s32*, s32*) asm("func_00276088");
void Tz__Jiminy__SetMainFrameLRMess(s32, s32) asm("Tz__Jiminy__SetMainFrameLRMess");
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32) asm("Tz__JmWorldSel__GetId2WorldName");
void func_00275e68(s32) asm("func_00275e68");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(void*) asm("func_00139620");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_0023aa78(void*) asm("func_0023aa78");
void Tz__Select__SetItem(void*, s32, s32, s32, s32, s32, s16*, s16*) asm("Tz__Select__SetItem");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void Tz__JmCollection__CreateGra(s32) asm("Tz__JmCollection__CreateGra");
s32 func_00276608(s32) asm("func_00276608");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void Tz__JmCollection__SetupSelMess(void) asm("Tz__JmCollection__SetupSelMess");
s32 func_0028af88(void*) asm("func_0028af88");
void func_0028af18(void*, s32) asm("func_0028af18");
void func_0029a740(void) asm("func_0029a740");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002995e8*/
void func_002995e8(void) asm("func_002995e8");
void func_002995e8(void) {
    s16 a[2][4];
    s32 x, y;
    s32 i, j;
    s32 n;
    s32 h;
    i = 0;
    void* c = func_00276348();
    Obj* o = func_002766d0();
    func_00276588(2);
    func_00288e88(D_0035f200);
    Tz__JmAnsem__GetHaveReport();
    func_0029a2a0();
    func_00275a80();
    func_00276088(func_00287bc0(), &x, &y);
    Tz__Jiminy__SetMainFrameLRMess(x, y);
    func_00275e68(Tz__JmWorldSel__GetId2WorldName(15, 0));
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) a[i][j] = 3;
    }
    n = D_0035f3d4 - 1;
    func_0028d8c0(o, n, D_0035f14c, D_0035f148, D_0035f210, 155, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, c);
    u8* o2 = (u8*)o + 816;
    func_0028d8c0(o2, n, D_0035f14c, D_0035f148, D_0035f210, 165, -1, 0);
    func_00139620(o2);
    func_0028dcc0(o2, c);
    h = func_0023aa78((u8*)o + 24);
    n = D_0035f3d4;
    for (i = 0; i < 12; i++) {
        Tz__Select__SetItem(D_0035f200, i, D_0035f14c, D_0035f148, D_0035f210, -1, a[0], a[1]);
        u8* p = func_002891b8(D_0035f200, i);
        func_00139620(p);
        func_0028dcc0(p, o);
        func_00138c68(p, 0, i * h);
        E* e = &o->a[i];
        func_0028d8c0(e, n + 1, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        func_0028dcc0(e, p);
        e = &o->b[i];
        func_0028d8c0(e, n + 2, D_0035f14c, D_0035f148, D_0035f210, 3, -1, 0);
        func_0028dcc0(e, p);
    }
    Tz__JmCollection__CreateGra(0);
    Tz__Select__SetCurrent(D_0035f200, func_00276608(func_00287bc0()), 0, -1, -1);
    func_002765e8(func_00287bc0(), 0, 0);
    Tz__JmCollection__SetupSelMess();
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0x3000);
    func_0029a740();
    func_00287cc0(0);
}
}  // namespace n002995e8

