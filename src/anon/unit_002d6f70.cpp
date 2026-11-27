// Linked unit: Ti::MGHachimitsu minigame (honey hunt: gophers, balloons, player). Built from the old per-function sources;
// functions marked "gap function" were never written before.
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../taito/mg_hachimitsu.hpp"
#include "../taito/debug.hpp"

// 002d6f70 (was never written: gap function)
namespace n002d6f70 {
struct Ent { u8 pad[8]; s32 data; };
struct G {
    u32 vt; u8 pad0[88]; s32 f92; s32 bar; f32 f100; s32 f104; u8 pad1[40]; s32 f148; s32 id; s32 f156; u8* f160;
    u8 pad2[24]; u8 m188[16]; s32 f204; u8 pad3[256]; u8 f464; u8 f465; u8 f466; u8 pad4[9]; s32 f476;
};
extern u8 D_003625a8[] asm("D_003625a8");
extern u8 D_00362570[] asm("D_00362570");
void func_002ce958(G*, s32, s32, s32) asm("func_002ce958");
void func_002e34b8(u8*) asm("func_002e34b8");
void func_002e34c0(u8*, s32) asm("func_002e34c0");
s32 func_002e34c8(u8*) asm("func_002e34c8");
void make_data_path(G*, char*, const char*) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
s32 Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Ent* func_00168b38(s32, s32, s32) asm("func_00168b38");
s32 func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(u32, s32) asm("func_001063c0");
void Ti__Afp__Afp(u8*, s32) asm("Ti__Afp__Afp");
void func_00102c80(void) asm("func_00102c80");
void func_002d7630(G*) asm("func_002d7630");
void Ti__MiniGame__create_task(s32, u8*) asm("Ti__MiniGame__create_task");
void func_002d6f70(G* g, s32 id, s32 arg, s32 a3) asm("func_002d6f70");
void func_002d6f70(G* g, s32 id, s32 arg, s32 a3)
{
    func_002ce958(g, 1, arg, 0x800);
    u8* m = g->m188;
    g->f104 = a3;
    g->id = id;
    g->vt = (u32)D_003625a8;
    g->f100 = 1.0471975f;
    func_002e34b8(m);
    g->f464 = 0;
    g->f465 = 0;
    g->f476 = 0;
    g->f156 = 0;
    s32 bar;
    {
        char path[64];
        make_data_path(g, path, "po_07");
        bar = Alloc(path, -1);
    }
    g->bar = bar;
    func_00168b38(bar, 42, 0);
    g->f204 = func_00168b38(bar, 42, 0)->data + 16;
    func_00168b38(bar, 42, 1);
    func_002e34c0(m, func_00168b38(bar, 42, 1)->data);
    func_00168b38(bar, 42, 2);
    g->f156 = func_00168b38(bar, 42, 2)->data;
    func_00168b38(bar, 42, g->id + 3);
    g->f92 = func_00168b38(bar, 42, g->id + 3)->data;
    g->f148 = func_002e34c8(m);
    u8* o = func_001063c0(12, func_001050c8());
    Ti__Afp__Afp(o, g->f156);
    g->f160 = o;
    func_00102c80();
    func_002d7630(g);
    g->f466 = 0;
    Ti__MiniGame__create_task(3, D_00362570);
}
}  // namespace n002d6f70

// 002d7128 (was src/anon/batch_w288.cpp)
namespace n002d7128 {
struct Blk_d7128 { u32 a; u32 b; u32 data; };
extern char D_003625a8[] asm("D_003625a8");
extern char D_00375b68[] asm("D_00375b68");
extern char D_00362570[] asm("D_00362570");
void func_002ce958(void*, s32, u32, s32) asm("func_002ce958");
void f2e34b8(void*) asm("_Z13func_002e34b8Pv");
void mg_make_data_path(void*, char*, char*) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
void* cb_alloc(char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Blk_d7128* func_00168b38(void*, s32, s32) asm("func_00168b38");
// entry_array_find_nth
void f2e34c0(void*, u32) asm("_Z13func_002e34c0Pvi");
void* func_002e34c8(void*) asm("func_002e34c8");
// obj_get_field8_by_vtable
void* area_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
void* tz_load_data_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void Ti__Afp__Afp(void*, u32) asm("Ti__Afp__Afp");
char* getFieldMode_(void) asm("_Z12getFieldModev");
void func_002d7630(void*) asm("func_002d7630");
void Ti__MiniGame__create_task(s32, void*) asm("Ti__MiniGame__create_task");
struct MG_d7128 {
    u32 vt; u8 p0[88]; u32 f5c; void* f60; f32 f64; u32 f68; u8 p1[40]; void* f94; u32 f98; u32 f9c; void* fa0;
    u8 p2[24]; u32 fbc; u8 p3[12]; u32 fcc; u8 p4[256]; u8 f1d0; u8 f1d1; u8 f1d2; u8 p5[9]; u32 f1dc;
};
void Ti__MGHachimitsu__MGHachimitsu(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z30Ti__MGHachimitsu__MGHachimitsujjjj");
/*TARGET 002d7128*/
void Ti__MGHachimitsu__MGHachimitsu(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z30Ti__MGHachimitsu__MGHachimitsujjjj");
void Ti__MGHachimitsu__MGHachimitsu(u32 a0, u32 a1, u32 a2, u32 a3) {
    MG_d7128* p = (MG_d7128*)a0;
    char buf[64];
    func_002ce958(p, 1, a2, 2048);
    p->f68 = a3;
    p->f98 = a1;
    p->vt = (u32)D_003625a8;
    p->f64 = 1.04719746f;
    f2e34b8(&p->fbc);
    p->f1d0 = 0; p->f1d1 = 0; p->f1dc = 0; p->f9c = 0;
    mg_make_data_path(p, buf, D_00375b68);
    void* cb = cb_alloc(buf, -1);
    p->f60 = cb;
    func_00168b38(cb, 42, 0);  // entry_array_find_nth
    p->fcc = func_00168b38(cb, 42, 0)->data + 16;
    func_00168b38(cb, 42, 1);  // entry_array_find_nth
    f2e34c0(&p->fbc, func_00168b38(cb, 42, 1)->data);  // entry_array_find_nth
    func_00168b38(cb, 42, 2);  // entry_array_find_nth
    p->f9c = func_00168b38(cb, 42, 2)->data;
    func_00168b38(cb, 42, p->f98 + 3);  // entry_array_find_nth
    p->f5c = func_00168b38(cb, 42, p->f98 + 3)->data;
    p->f94 = func_002e34c8(&p->fbc);  // obj_get_field8_by_vtable
    void* d = tz_load_data_alloc(12, area_get_allocator());
    Ti__Afp__Afp(d, p->f9c);
    p->fa0 = d;
    getFieldMode_();
    func_002d7630(p);
    p->f1d2 = 0;
    Ti__MiniGame__create_task(3, D_00362570);
}
}  // namespace n002d7128

// 002d72e0 (was src/anon/batch_w26.cpp)
namespace n002d72e0 {
// big_obj_dtor
void func_002e70b0(void*) asm("func_002e70b0");
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
u8 func_002cea28(void*) asm("func_002cea28");
extern u8 D_003625a8[] asm("D_003625a8");
/*TARGET 002d72e0*/
// 0x002cff98: definition moved into src/anon/unit_002cf260.cpp

u8 func_002d72e0(u8* o) asm("func_002d72e0");
// 0x002cff98: definition moved into src/anon/unit_002cf260.cpp

u8 func_002d72e0(u8* o) {
    *(u8**)o = D_003625a8;
    void* p = *(void**)(o + 160);
    if (p) {
        func_002e70b0(p);
        LoadDataFree(p);
    }
    return func_002cea28(o);
}
}  // namespace n002d72e0

// 002d7338 (was src/anon/batch_w27.cpp)
namespace n002d7338 {
// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call (as in the game's destructors).
struct NoTail { ~NoTail() {} };
// 0x001d3f38: definition moved into src/anon/unit_001d3c08.cpp

void func_00106420(void*) asm("func_00106420");
// 0x002cffe0: definition moved into src/anon/unit_002cf260.cpp

extern u32 D_003625a8 asm("D_003625a8");
void func_002e70b0(void*) asm("func_002e70b0");
void func_002cea28(void*) asm("func_002cea28");
/*TARGET 002d7338*/
void func_002d7338(u8* p) asm("func_002d7338");
void func_002d7338(u8* p) {
    NoTail g;
    *(void**)p = &D_003625a8;
    void* c = *(void**)(p + 160);
    if (c) {
        func_002e70b0(c);
        func_00106420(c);
    }
    func_002cea28(p);
}
}  // namespace n002d7338

// 002d7390 (was src/anon/auto80_199_queue.cpp)
namespace n002d7390 {
/*TARGET 002d7390*/
void func_002d7390(u32 a0) asm("_Z13func_002d7390j");
void func_002d7390(u32 a0) {
    *(u32*)a0 = (u32)&D_003625a8;
    u32 s0 = *(u32*)(a0 + 160);
    if (s0 != 0) {
        func_002e70b0(s0);
        func_00106420(s0);
    }
    func_002cea28(a0);
    func_00105110(a0);
}
}  // namespace n002d7390

// 002d73f0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002d73f0 {
/*TARGET 002d73f0*/
u32 func_002d73f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d73f0jjjj");
u32 func_002d73f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = *(u32*)((u32)r4 + (s32)(164));
    r2 = *(u32*)((u32)r4 + (s32)(204));
    r15 = (u32)(r15 << 7);
    r2 = (u32)(r2 + r15);
    r2 = (u32)((s32)r2 + (-128));
    return r2;
}
}  // namespace n002d73f0

// 002d7408 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d7408 {
u32 func_002cebc0(u32, u32, u32, u32) asm("_Z13func_002cebc0jjjj");
/*TARGET 002d7408*/
// 0x002d2140: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d7408(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d7408jjjj");
// 0x002d2140: definition moved into src/anon/unit_002cf260.cpp

u32 func_002d7408(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cebc0(a0, a1, a2, a3);
}
}  // namespace n002d7408

// 002d7420 (was src/anon/auto80_199_queue.cpp)
namespace n002d7420 {
/*TARGET 002d7420*/
void Ti__MGHachimitsu__show_course_bg_group(u32 a0) asm("_Z38Ti__MGHachimitsu__show_course_bg_groupj");
void Ti__MGHachimitsu__show_course_bg_group(u32 a0) {
    u8* s1 = (u8*)a0;
    u32 s0 = 0;
    while (1) {
        u8* t7 = *(u8**)(s1 + 184);
        u32 t6 = t7[9];
        if (s0 == t6) {
            func_0015ee90(s0);
            func_00160f10(s0);
        } else {
            func_0015ee10(s0);
        }
        s0 += 1;
        if (!(s0 < 16)) {
            u8* t7f = *(u8**)(s1 + 184);
            u8* t6p = t7f + 12;
            u8 t5 = t6p[4];
            u8 t7v = t6p[5];
            f32 f12 = (f32)*(s32*)(t6p + 8);
            f32 f13 = (f32)*(s32*)(t6p + 12);
            f32 f14 = (f32)t5;
            f32 f15 = (f32)t7v;
            func_0015ca40(
                t6p[0],
                t6p[1],
                t6p[2],
                f12,
                f13,
                f14,
                f15);
            return;
        }
    }
}
}  // namespace n002d7420

// 002d74c8 (was src/anon/batch_w8024.cpp)
namespace n002d74c8 {
struct R2e_w8024 { s32 i0; u8 pad[4]; u8 b8; };
struct P2d_w8024 { u8 pad[0x20]; f32 f20; f32 f24; };
struct O2d_w8024 {
    u8 pad0[0x6c]; s32 m6c; s32 m70; s32 m74; u8 p78[0x84-0x78]; s32 a84[3];
    u8 p90[0xa4-0x90]; s32 ma4; s32 ma8; f32 fac; f32 fb0; s8 bb4; u8 pb5[3]; R2e_w8024* rb8; u8 bc[0x1d0-0xbc];
    s8 b1d0; u8 p1d1[0x1e0-0x1d1]; s8 b1e0;
};
s32 func_002d1260() asm("func_002d1260");
R2e_w8024* func_002e34d8(void*) asm("func_002e34d8");
void func_002d0a78() asm("func_002d0a78");
void YS__PRIZE__ClearAll() asm("YS__PRIZE__ClearAll");
void Ti__MGHachimitsu__show_course_bg_group(O2d_w8024*) asm("Ti__MGHachimitsu__show_course_bg_group");
void func_002da040(s32) asm("func_002da040");
void func_002cf2d8() asm("func_002cf2d8");
void Ti__MGObj__reset_all_members(s32) asm("Ti__MGObj__reset_all_members");
s32 Ti__MGObj__get_prize_count(s32) asm("Ti__MGObj__get_prize_count");
void func_002d9220(O2d_w8024*, s32) asm("func_002d9220");
P2d_w8024* func_002d73f0(O2d_w8024*) asm("func_002d73f0");
void func_001ca8f8(f32, f32) asm("func_001ca8f8");
/*TARGET 002d74c8*/
void func_002d74c8(O2d_w8024* o, s32 a1, u8 a2) asm("func_002d74c8");
void func_002d74c8(O2d_w8024* o, s32 a1, u8 a2)
{
    R2e_w8024* r;
    s32 i;
    o->bb4 = 0;
    o->ma8 = a1;
    o->b1e0 = 0;
    r = func_002e34d8(o->bc);
    o->rb8 = r;
    o->ma4 = r->b8;
    o->fac = (f32)r->i0;
    if (a2) {
        func_002d0a78();
        YS__PRIZE__ClearAll();
    }
    Ti__MGHachimitsu__show_course_bg_group(o);
    a1 = func_002d1260();
    func_002da040(a1);
    func_002cf2d8();
    Ti__MGObj__reset_all_members(1);
    o->m6c += Ti__MGObj__get_prize_count(0);
    o->m70 += Ti__MGObj__get_prize_count(1);
    o->m74 += Ti__MGObj__get_prize_count(2);
    for (i = 0; i < 3; i++) o->a84[i] = 0;
    o->b1d0 = 1;
    if (o->ma4 == 5) func_002d9220(o, 0);
    else if (o->ma4 == 6) func_002d9220(o, 1);
    o->fb0 = o->fac - 1.0f;
    P2d_w8024* p = func_002d73f0(o);
    func_001ca8f8(p->f24, func_002d73f0(o)->f20);
}
}  // namespace n002d74c8

// 002d7630 (was src/anon/auto80_199_queue.cpp)
namespace n002d7630 {
/*TARGET 002d7630*/
void func_002d7630(u32 a0) asm("_Z13func_002d7630j");
void func_002d7630(u32 a0) {
    *(u32*)(a0 + 468) = 0;
    *(u32*)(a0 + 472) = 0;
    *(u8*)(a0 + 144) = 0;
    u32 t5 = a0;
    s32 t4 = 2;
    do {
        *(u32*)(t5 + 108) = 0;
        t4 -= 1;
        *(u32*)(t5 + 120) = 0;
        *(u32*)(t5 + 132) = 0;
        t5 += 4;
    } while (t4 >= 0);
    u32 a1 = *(u32*)(a0 + 104);
    *(u8*)(a0 + 192) = 0;
    *(u8*)(a0 + 193) = 0;
    *(u8*)(a0 + 201) = 0;
    func_002d74c8(a0, a1 & 0xfff, 0);
}
}  // namespace n002d7630

// 002d7698 (was src/anon/batch_w2000_nsa.cpp)
namespace n002d7698 {
// 0x2cae60: moved to src/anon/unit_002cac58.cpp


struct EntI { s32 a; s32 b; u8 type; u8 arg; u8 pad[2]; };
struct HdrI { u8 pad[10]; u8 n; u8 pad2[53]; EntI ent[1]; };
struct ObjI { u8 pad[144]; u8 b90; u8 pad1[23]; s32 i168; f32 cur; f32 prev; u8 pad2[8]; u8 sub[4]; u8 b192; u8 b193; u8 pad3[2]; s32 i196; };
HdrI* func_002e34d8(void*, s32) asm("func_002e34d8");
void* func_0014abd8(void) asm("func_0014abd8");
void func_0014aa58(void*, s32, s32) asm("func_0014aa58");
void func_0014aa80(void*, s32, s32) asm("func_0014aa80");
void* func_002d1260(void) asm("func_002d1260");
void func_002daa00(void*, u8) asm("func_002daa00");
void func_001991a8(s32, s32) asm("func_001991a8");
/*TARGET 002d7698*/
void func_002d7698(ObjI* self) asm("func_002d7698");
void func_002d7698(ObjI* self) {
    s32 i = 0;
    HdrI* h = func_002e34d8(self->sub, self->i168);
    self->b192 = 0;
    self->i196 = -1;
    self->b193 = 0;
    s32 n = h->n;
    for (; i < n; i++) {
        EntI* e = &h->ent[i];
        if (e->a < 0) return;
        f32 fa = (f32)e->a;
        f32 fb = (f32)e->b;
        s32 len = (e->b - e->a) * 2 + 2;
        f32 cur = self->cur;
        s32 in1 = 0;
        if (fa <= cur && cur <= fb) in1 = 1;
        s32 in2 = 0;
        if (self->prev < fa && fa <= cur) in2 = 1;
        if (in1) {
            u32 t = e->type;
            switch (t) {
            case 0: break;
            case 1: self->b192 = t; break;
            case 6 ... 8:
                if (in1) self->i196 = e->type - 6;
                break;
            }
        }
        if (in2) {
            switch (e->type) {
            case 2: func_0014aa58(func_0014abd8(), len, 0); break;
            case 3: func_0014aa80(func_0014abd8(), len, 0); break;
            case 4: func_0014aa58(func_0014abd8(), len, 1); break;
            case 5: func_0014aa80(func_0014abd8(), len, 1); break;
            case 11: func_002daa00(func_002d1260(), e->arg); break;
            case 12:
                if (!self->b90) {
                    func_001991a8(21, 0);
                    self->b90 = 1;
                }
                break;
            }
        }
    }
}
}  // namespace n002d7698

// 002d78a8 (was src/anon/batch_w2394.cpp)
namespace n002d78a8 {
#define QCOPY4_W(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct WM {
    f32 m[4][4];
    WM() {}
    WM(const WM& o) { QCOPY4_W(this, &o); }
    WM& operator=(const WM& o) { if (this != &o) QCOPY4_W(this, &o); return *this; }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct WCamHead { u8 pad[16]; };
struct WCam : WCamHead, WM {};
struct WTgt {
    u8 pad0[0x64];
    f32 f64;
    u8 pad68[0xb4 - 0x68];
    u8 bB4;
    u8 padB5[0xc9 - 0xb5];
    u8 bC9;
    u8 padCA[0x190 - 0xca];
    WM mat;
};
WCam* func_00106a60(s32) asm("func_00106a60");
void* kn__getProjection(void) asm("kn__getProjection");
void kn__Projection__setFOV(void*, s32, f32) asm("kn__Projection__setFOV");
void kn__Projection__calcMatrix(void*) asm("kn__Projection__calcMatrix");
void Ti__MGHachimitsu__update_camera(u32 a0, u32, u32, u32) asm("_Z31Ti__MGHachimitsu__update_camerajjjj");
/*TARGET 002d78a8*/
/* 002d78a8: target matrix update. One variable c holds both call results (camera in the first branch,
   object in the second), which gives the original's saved-register order. */
void Ti__MGHachimitsu__update_camera(u32 a0, u32, u32, u32) asm("_Z31Ti__MGHachimitsu__update_camerajjjj");
/* 002d78a8: target matrix update. One variable c holds both call results (camera in the first branch,
   object in the second), which gives the original's saved-register order. */
void Ti__MGHachimitsu__update_camera(u32 a0, u32, u32, u32) {
    WTgt* t = (WTgt*)a0;
    WM* pm;
    WCam* c;
    if (t->bC9) {
        pm = &t->mat;
        c = func_00106a60(1);
        WM m = *c;
        *pm = m;
        pm->invOrtho();
    } else {
        c = (WCam*)kn__getProjection();
        kn__Projection__setFOV(c, 1, t->f64);
        kn__Projection__calcMatrix(c);
        WM m = t->mat;
        m.invOrtho();
        func_00106a60(1)->WM::operator=(m);
        t->bB4 = 1;
    }
}
}  // namespace n002d78a8

// 002d7a80 (was never written: gap function)
namespace n002d7a80 {
struct PadE { u64 b0 : 1; u64 rest : 63; u64 w8; };
PadE* func_00167bf0(s32) asm("func_00167bf0");
void func_002d88a8(u8*) asm("func_002d88a8");
static inline bool on(PadE* p) { u8 r = p->b0; return r; }
void func_002d7a80(u8* o) asm("func_002d7a80");
void func_002d7a80(u8* o)
{
    PadE* p = func_00167bf0(0);
    if (on(p)) func_002d88a8(o);
    if (p->w8 & 4) o[465] ^= 1;
}
}  // namespace n002d7a80

// 002d7af0 (was src/anon/batch_w3796_nsa.cpp)
namespace n002d7af0 {
#define Q7_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define Q7_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W2d7af0Vec {
    f32 x, y, z, w;
    W2d7af0Vec() {}
    W2d7af0Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2d7af0Vec(const W2d7af0Vec& o) { *this = o; }
    W2d7af0Vec& operator=(const W2d7af0Vec& o) { if (this != &o) Q7_QCOPY(this, &o); return *this; }
    W2d7af0Vec& operator*=(f32 s) { asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
static inline W2d7af0Vec Q7Cross(const W2d7af0Vec& a, const W2d7af0Vec& b) {
    W2d7af0Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W2d7af0Mtx {
    W2d7af0Vec r0, r1, r2, r3;
    W2d7af0Mtx() {}
    W2d7af0Mtx(const W2d7af0Mtx& o) { Q7_MCOPY(this, &o); }
    W2d7af0Mtx& operator=(const W2d7af0Mtx& o) { if (this != &o) Q7_MCOPY(this, &o); return *this; }
    W2d7af0Vec operator*(const W2d7af0Vec& v) const {
        W2d7af0Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    // Inverse of a rigid transform: transpose the rotation, translation = -(R^T t).
    void InvertOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
                     "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                     "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                     "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Seg2d7af0 {
    W2d7af0Vec a, b;
    Seg2d7af0() {}
    Seg2d7af0(const W2d7af0Vec& pa, const W2d7af0Vec& pb) { a = pa; b = pb; }
    void Set(W2d7af0Vec pa, W2d7af0Vec pb) { a = pa; b = pb; }
};
struct X2d7af0 { u8 pad[193]; u8 off; u8 pad2[14]; W2d7af0Mtx base; W2d7af0Mtx cur; u8 pad3[468 - 336]; f32 hi, lo; };
s32 dk__Octree__intersectLineMapKind(Seg2d7af0*, W2d7af0Vec*, u16*, s32, s32) asm("dk__Octree__intersectLineMapKind");
W2d7af0Vec func_00143e50(u16, s32) asm("func_00143e50");
s32 func_002d8898(X2d7af0*) asm("func_002d8898");
/*TARGET 002d7af0*/
// Ti minigame camera: drop the base matrix onto the ground (ray test from
// y=-150 to y=+250), rebuild its axes from the hit triangle's normal, store it
// as the current matrix, then probe left/right (x=-600/+600 at y=-80) and keep
// the hit points' local x as the lo/hi limits.
void Ti__MGHachimitsu__calc_player_center_matrix(X2d7af0* x) asm("Ti__MGHachimitsu__calc_player_center_matrix");
// Ti minigame camera: drop the base matrix onto the ground (ray test from
// y=-150 to y=+250), rebuild its axes from the hit triangle's normal, store it
// as the current matrix, then probe left/right (x=-600/+600 at y=-80) and keep
// the hit points' local x as the lo/hi limits.
void Ti__MGHachimitsu__calc_player_center_matrix(X2d7af0* x)
{
    if (x->off) x->cur = x->base;
    W2d7af0Mtx m(x->base);
    W2d7af0Vec& up = m.r1;
    W2d7af0Vec& pos = m.r3;
    W2d7af0Vec hit;
    W2d7af0Vec p0, p1;
    Seg2d7af0 seg;
    u16 id;
    p0 = m * W2d7af0Vec(0.0f, -150.0f, 0.0f, 1.0f);
    p1 = m * W2d7af0Vec(0.0f, 250.0f, 0.0f, 1.0f);
    seg.Set(p0, p1);
    if (!dk__Octree__intersectLineMapKind(&seg, &hit, &id, 1, 15)) {
        x->cur = m;
        return;
    }
    pos = hit;
    up = func_00143e50(id, 0);
    up *= -1.0f;
    m.r0 = Q7Cross(up, x->base.r2);
    m.r2 = Q7Cross(m.r0, up);
    m.r0.Normalize();
    up.Normalize();
    m.r2.Normalize();
    m.r0.w = 0.0f;
    m.r1.w = 0.0f;
    m.r2.w = 0.0f;
    x->cur = m;
    if (func_002d8898(x)) {
        W2d7af0Vec c = m * W2d7af0Vec(0.0f, -80.0f, 0.0f, 1.0f);
        W2d7af0Vec l = m * W2d7af0Vec(-600.0f, -80.0f, 0.0f, 1.0f);
        W2d7af0Vec r = m * W2d7af0Vec(600.0f, -80.0f, 0.0f, 1.0f);
        Seg2d7af0 sr(c, r), sl(c, l);
        W2d7af0Vec hl, hr;
        u16 id2;
        s32 a = dk__Octree__intersectLineMapKind(&sr, &hr, &id2, 2, 15);
        s32 b = dk__Octree__intersectLineMapKind(&sl, &hl, &id2, 2, 15);
        if (!a && !b) {
            x->hi = 0.0f;
            x->lo = 0.0f;
        } else {
            hl.w = 1.0f;
            hr.w = 1.0f;
            m.InvertOrtho();
            hl = m * hl;
            hr = m * hr;
            x->hi = hr.x;
            x->lo = hl.x;
        }
    }
}
}  // namespace n002d7af0

// 002d8110 (was src/anon/tiny.cpp)
namespace n002d8110 {
/*TARGET 002d8110*/
u32 Ti__MGHachimitsu__get_current_center_matrix(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z43Ti__MGHachimitsu__get_current_center_matrixjjjj");
u32 Ti__MGHachimitsu__get_current_center_matrix(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (272));
}
}  // namespace n002d8110

// 002d8120 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002d8120 {
u32 func_002d8150(u32, u32, u32, u32) asm("_Z13func_002d8150jjjj");
/*TARGET 002d8120*/
// 0x002bbf68: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002d8120(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d8120jjjj");
// 0x002bbf68: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002d8120(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r7 = (u32)((s32)r5 + (272));
    r16 = r4;
    r2 = func_002d8150(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n002d8120

// 002d8150 (was src/anon/batch_w3794_nsa.cpp)
namespace n002d8150 {
#define W2d8150_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d8150Vec {
    f32 x, y, z, w;
    W2d8150Vec() {}
    W2d8150Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2d8150Vec& operator+=(const W2d8150Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory"); return *this; }
    W2d8150Vec(const W2d8150Vec& o) { *this = o; }
    W2d8150Vec& operator=(const W2d8150Vec& o) { if (this != &o) W2d8150_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d8150Mtx {
    W2d8150Vec r0, r1, r2, r3;
    W2d8150Mtx() {}
    W2d8150Mtx(const W2d8150Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // translation.xyz += v.xyz
    void AddTransXYZ(const W2d8150Vec& b) { asm volatile(".set noreorder\n\tlqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory"); }
    // VU0 matrix * column vector.
    W2d8150Vec operator*(const W2d8150Vec& v) const {
        W2d8150Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Seg2d8150 {
    W2d8150Vec a, b;
    void Set(W2d8150Vec pa, W2d8150Vec pb) { a = pa; b = pb; }
};
struct X2d8150 { u8 pad[193]; u8 off; u8 pad2[14]; W2d8150Vec r0, r1, r2; u8 pad3[468 - 256]; f32 hi, lo; };
s32 dk__Octree__intersectLineMapKind(Seg2d8150*, W2d8150Vec*, u16*, s32, s32) asm("dk__Octree__intersectLineMapKind");
W2d8150Mtx c2d8150(X2d8150*, f32*, const W2d8150Mtx&, f32) asm("_Z16ctarget_002d8150jjjj");
/*TARGET 002d8150*/
// Camera matrix for the Ti minigame: copy the base matrix, clamp the height *y
// between lo+30 and hi-30, shift along the matrix x axis by it, drop onto the
// ground found by a ray test from y=-100 to y=+100, then take the rotation rows
// from x and add the height offset h.
W2d8150Mtx c2d8150(X2d8150* x, f32* y, const W2d8150Mtx& base, f32 h) asm("_Z16ctarget_002d8150jjjj");
// Camera matrix for the Ti minigame: copy the base matrix, clamp the height *y
// between lo+30 and hi-30, shift along the matrix x axis by it, drop onto the
// ground found by a ray test from y=-100 to y=+100, then take the rotation rows
// from x and add the height offset h.
W2d8150Mtx c2d8150(X2d8150* x, f32* y, const W2d8150Mtx& base, f32 h)
{
    W2d8150Mtx m(base);
    if (x->off) {
        *y = 0.0f;
        return m;
    }
    if (x->hi - 30.0f < x->lo + 30.0f) {
        *y = (x->hi + x->lo) * 0.5f;
    } else {
        if (*y < x->lo + 30.0f) *y = x->lo + 30.0f;
        if (x->hi - 30.0f < *y) *y = x->hi - 30.0f;
    }
    W2d8150Vec hit;
    W2d8150Vec p0, p1;
    Seg2d8150 seg;
    u16 id;
    W2d8150Vec d = m * W2d8150Vec(*y, 0.0f, 0.0f, 0.0f);
    m.AddTransXYZ(d);
    p0 = m * W2d8150Vec(0.0f, -100.0f, 0.0f, 1.0f);
    p1 = m * W2d8150Vec(0.0f, 100.0f, 0.0f, 1.0f);
    seg.Set(p0, p1);
    if (dk__Octree__intersectLineMapKind(&seg, &hit, &id, 1, 15)) m.r3 = hit;
    W2d8150Vec t = m * W2d8150Vec(0.0f, h, 0.0f, 0.0f);
    m.r0 = x->r0;
    m.r1 = x->r1;
    m.r2 = x->r2;
    m.r3 += t;
    return m;
}
}  // namespace n002d8150

// 002d8460 (was never written: gap function)
namespace n002d8460 {
s32 func_002d8460(u8* o) asm("func_002d8460");
s32 func_002d8460(u8* o)
{
    switch (*(u32*)(o + 164)) {
    case 0: return -1;
    case 1: return 0;
    case 2: return -1;
    case 3: return 1;
    case 4: return 2;
    case 5: return -1;
    case 6: return -1;
    case 7: return 0;
    case 8: return 0;
    }
    return -1;
}
}  // namespace n002d8460

// 002d84a8 (was src/anon/batch_w291.cpp)
namespace n002d84a8 {
struct W291Mtx2d {
    u32 m[16];
    W291Mtx2d& operator=(const W291Mtx2d& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W291K2d { u8 pad[8]; u8 b8; };
struct W291R2d { u8 pad[3077]; u8 b3077; };
struct W291O2d {
    u8 pad0[160]; s32 f160; s32 f164; u8 pad168[4]; f32 f172; u8 pad176[8]; W291K2d* p184;
    u8 pad188[8]; s32 f196; u8 pad200; u8 b201; u8 pad202[6];
    W291Mtx2d m208; W291Mtx2d m272; W291Mtx2d m336; W291Mtx2d m400; u8 b464; u8 pad465[15]; u8 b480;
};
// 00176458: moved to src/yasui/libys/party.cpp

extern s32 D_0034e948 asm("D_0034e948");
void func_002cf248() asm("func_002cf248");
void func_002cfb30() asm("func_002cfb30");
W291R2d* func_002d1260() asm("func_002d1260");
void func_002d7698(W291O2d*) asm("func_002d7698");
void func_002da8f0(W291R2d*, s32) asm("func_002da8f0");
void Ti__MGHachimitsuPlayer__start_special_motion(s32) asm("Ti__MGHachimitsuPlayer__start_special_motion");
void func_002d9218(W291O2d*) asm("func_002d9218");
void func_002e7108(s32, f32) asm("func_002e7108");
W291Mtx2d func_002e71a0(s32, u8, s32) asm("func_002e71a0");
void Ti__MGHachimitsu__calc_player_center_matrix(W291O2d*) asm("Ti__MGHachimitsu__calc_player_center_matrix");
void func_002d84a8_w(W291O2d* o) asm("_Z13func_002d84a8i");
/*TARGET 002d84a8*/
void func_002d84a8_w(W291O2d* o) asm("_Z13func_002d84a8i");
void func_002d84a8_w(W291O2d* o)
{
    func_002cf248();
    func_002cfb30();
    W291R2d* r = func_002d1260();
    func_002d7698(o);
    func_002da8f0(r, o->f196);
    if (!o->b480 && o->f164 == 4 && 671.0f <= o->f172) {
        Ti__MGHachimitsuPlayer__start_special_motion(D_0034e948);
        o->b480 = 1;
    }
    if (o->b201) {
        func_002d9218(o);
    } else {
        func_002e7108(o->f160, o->f172);
        o->m400 = func_002e71a0(o->f160, o->p184->b8, 1);
        o->m208 = func_002e71a0(o->f160, o->p184->b8, 2);
        Ti__MGHachimitsu__calc_player_center_matrix(o);
        if (o->b464) {
            o->m336 = o->m272;
            o->b464 = 0;
        }
    }
    u8 t = 0;
    if (o->p184->b8 == 7 && 250.0f <= o->f172) t = 1;
    r->b3077 = t;
}
}  // namespace n002d84a8

// 002d8670 (was src/anon/batch_w99.cpp)
namespace n002d8670 {
// ---- 002cd770
struct Vec2cd { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline Vec2cd operator+(const Vec2cd& a, const Vec2cd& b)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct M2d86 {
    u32 m[16];
    M2d86& operator=(const M2d86& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct P2d86 {
    u8 pad[88]; u8 dirty; u8 pad1[55]; u8 played; u8 pad2[3]; s32 count; u8 pad3[16]; s32 frame;
    f32 t; f32 prev; u8 pad4[4]; s32* info; u8 pad5[13]; u8 b201; u8 pad6[70]; M2d86 src; M2d86 dst;
    u8 pad7[65]; u8 b465; u8 done;
};
extern f32 D_00349e10 asm("D_00349e10");
f32* func_002d73f0(P2d86*) asm("func_002d73f0");
s32 func_002d94b8(P2d86*) asm("func_002d94b8");
void func_002d74c8(P2d86*, s32, s32) asm("func_002d74c8");
void func_001991a8_2d8670(s32, s32) asm("func_001991a8");
void func_002d8670_(s32) asm("_Z13func_002d8670i");
/*TARGET 002d8670*/
void func_002d8670_(s32 a) asm("_Z13func_002d8670i");
void func_002d8670_(s32 a)
{
    P2d86* p = (P2d86*)a;
    if (p->b465) goto copy;
    if (!p->done) {
        p->prev = p->t;
        p->t += *func_002d73f0(p) * D_00349e10 * 0.5f;
        s32 end = p->b201 ? func_002d94b8(p) : ((f32)p->info[1] < p->t);
        if (end) {
            s32 n = ++p->frame;
            if (!(n < p->count)) {
                if (!p->played) {
                    func_001991a8_2d8670(21, 0);
                    p->played = 1;
                }
                p->frame = p->count - 1;
                p->t = (f32)p->info[1];
                p->done = 1;
            } else {
                func_002d74c8(p, n, 1);
            }
        }
    }
copy:
    p->dst = p->src;
    p->dirty = 1;
}
}  // namespace n002d8670

// 002d87c0 (was never written: gap function)
namespace n002d87c0 {
static inline u32 Id(const char* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
u32 func_002d87c0(u8* o, u32 id) asm("func_002d87c0");
u32 func_002d87c0(u8* o, u32 id)
{
    const char* tbl[9] = { 0, "m_10", "m_20", "m_30", "m_40", "m_50", "m_60", "m_70", "m_80" };
    if (id == Id("m_00")) return 1;
    return ((Id(tbl[*(*(u8**)(o + 184) + 8)]) ^ id) & 0xffffff) == 0;
}
}  // namespace n002d87c0

// 002d8898 (was src/anon/tiny_leaf.cpp)
namespace n002d8898 {
/*TARGET 002d8898*/
// 0x002c5608: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002d8898(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d8898jjjj");
// 0x002c5608: definition moved into src/anon/unit_002c53c8.cpp

u32 func_002d8898(u32 a0, u32 a1, u32 a2, u32 a3) {  // invert_byte192
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u8*)((u32)r4 + (s32)(192)));
    r2 = (u32)(r2 ^ 0x0001u);
    return r2;
}
}  // namespace n002d8898

// 002d88a8 (was src/anon/batch_w1756_g.cpp)
namespace n002d88a8 {
struct S10_w1756 { s16 h[5]; };
extern S10_w1756 D_0032bae0 asm("D_0032bae0");
void func_00195750() asm("func_00195750");
void AREA__MapJump(S10_w1756*, s32, s32, s32, s32) asm("AREA__MapJump");
/*TARGET 002d88a8*/
// 0x002d2070: definition moved into src/anon/unit_002cf260.cpp

void func_002d88a8() asm("func_002d88a8");
// 0x002d2070: definition moved into src/anon/unit_002cf260.cpp

void func_002d88a8()
{
    S10_w1756 x = D_0032bae0;
    func_00195750();
    AREA__MapJump(&x, 1, 0, 0, 0);
}
}  // namespace n002d88a8

// 002d8900 (was src/anon/tiny.cpp)
namespace n002d8900 {
/*TARGET 002d8900*/
u32 func_002d8900(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d8900jjjj");
u32 func_002d8900(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_state_is_4
    (void)a1;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a0 + (164)) ^ 0x0004u) == 0);
}
}  // namespace n002d8900

// 002d8910 (was src/anon/batch_w1779.cpp)
namespace n002d8910 {
struct W1779Vec {
    f32 x, y, z, w;
    W1779Vec() {}
    W1779Vec(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
struct W1779Src { s32 m0; f32 x, y, z; };
struct W1779B { u8 pad[0x68]; u32 flags; W1779Src* src; };
struct W1779A { u8 pad[0x1c0]; W1779Vec pos; };
struct W1779R { u8 pad[0x14]; f32 range; };
W1779R* func_002d73f0(W1779A*) asm("func_002d73f0");
// VU0: d = a - b (xyzw)
static inline void w1779_vsub(W1779Vec* d, const W1779Vec* a, const W1779Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
// VU0: length of xyz
static inline f32 w1779_vlen(const W1779Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
/*TARGET 002d8910*/
s32 func_002d8910(W1779A* a, W1779B* b) asm("func_002d8910");
s32 func_002d8910(W1779A* a, W1779B* b) {
    W1779Vec d;
    W1779Src* s = b->src;
    W1779Vec v(s->x, s->y, s->z);
    w1779_vsub(&d, &a->pos, &v);
    f32 len = w1779_vlen(&d);
    if (func_002d73f0(a)->range < len) return 0;
    return b->flags & 1;
}
}  // namespace n002d8910

// 002d89b0 (was src/anon/batch_w83.cpp)
namespace n002d89b0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// 0x002ab448: definition moved into src/anon/unit_002a99c8.cpp

u8* func_002d73f0(void) asm("func_002d73f0");
s32 func_002cee58(void*, void*) asm("func_002cee58");
// d = a - b (xyzw) via VU0.
static inline void vsub(Vec4* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
// |v.xyz| via VU0.
static inline f32 vlen(const Vec4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Pt4 {
    f32 x, y, z, w;
    Pt4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
/*TARGET 002d89b0*/
s32 func_002d89b0(u8* p, u8* a) asm("func_002d89b0");
s32 func_002d89b0(u8* p, u8* a) {
    s32* t = *(s32**)(a + 12);
    if ((u32)(t[0] - 2034) < 2) return 1;
    Pt4 q(((f32*)t)[1], ((f32*)t)[2], ((f32*)t)[3], 0.0f);
    Vec4 d;
    vsub(&d, p + 448, &q);
    f32 dist = vlen(&d);
    if (*(f32*)(func_002d73f0() + 20) < dist) return 0;
    return func_002cee58(p, t);
}
}  // namespace n002d89b0

// 002d8a78 (was src/anon/batch_w80.cpp)
namespace n002d8a78 {
// ---- unit 23 (n3.cpp)
struct U23_W80Vec {
    f32 x, y, z, w;
    U23_W80Vec() {}
    U23_W80Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    U23_W80Vec operator-(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec operator+(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec& operator=(const U23_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 U23_w80_vlen(const U23_W80Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct U23_Ai { u8 pad[448]; U23_W80Vec pos; };
struct U23_AiTgt { u8 pad[2820]; f32 f2820; };
struct U23_AiParam { u8 pad[24]; f32 range; };
extern f32 D_00349e10 asm("D_00349e10");
U23_W80Vec* w80_pos_vec(void*) asm("YS__OBJ__get_pos");
U23_AiParam* func_002d73f0(U23_Ai*) asm("func_002d73f0");
s32 func_002ceef8(U23_Ai*, U23_AiTgt*) asm("func_002ceef8");
/*TARGET 002d8a78*/
// 001ad838: moved to src/anon/unit_001abb28.cpp


// 0x1c81d0: moved to src/yasui/libys/summon.cpp


s32 func_002d8a78(U23_Ai* a, U23_AiTgt* t) asm("func_002d8a78");
// 001ad838: moved to src/anon/unit_001abb28.cpp


// 0x1c81d0: moved to src/yasui/libys/summon.cpp


s32 func_002d8a78(U23_Ai* a, U23_AiTgt* t) {
    U23_W80Vec d = a->pos - *w80_pos_vec(t);
    f32 dist = U23_w80_vlen(&d);
    if (func_002d73f0(a)->range < dist) return 1;
    if (func_002ceef8(a, t)) t->f2820 = 0;
    else t->f2820 += D_00349e10;
    if (60.0f < t->f2820) return 1;
    return 0;
}
}  // namespace n002d8a78

// 002d8b58 (was never written: gap function)
namespace n002d8b58 {
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V operator-(const V& b) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
u8* config(u8*) asm("_ZN2kn7FMatrixaSERKS0_");
u32 func_002cef80(u8*, u8*) asm("func_002cef80");
void wt_002cf058(u8*, u8*) asm("_Z27Ti__MiniGame___prepare_zonejjjj");
u32 func_002d8b58(u8* o, u8* x) asm("func_002d8b58");
u32 func_002d8b58(u8* o, u8* x)
{
    f32 d = (*(V*)(o + 448) - *(V*)x).length();
    if (*(f32*)(config(o) + 24) < d) return 1;
    if (func_002cef80(o, x)) *(f32*)(x + 88) = 0.0f;
    else *(f32*)(x + 88) += 2.0f;
    return 60.0f < *(f32*)(x + 88);
}
struct T { u8 pad[4]; f32 x, y, z; };
void func_002d8c30(u8* o, u8* e) asm("func_002d8c30");
void func_002d8c30(u8* o, u8* e)
{
    wt_002cf058(o, e);
    if (*(u32*)(e + 104) & 4) {
        T* t = *(T**)(e + 108);
        f32 d = (*(V*)(o + 448) - V(t->x, t->y, t->z, 0.0f)).length();
        if (*(f32*)(config(o) + 24) < d) *(u32*)(e + 104) |= 2;
    }
}
}  // namespace n002d8b58

// 002d8cf0 (was src/anon/tiny.cpp)
namespace n002d8cf0 {
void func_002d84a8(s32) asm("_Z13func_002d84a8i");
/*TARGET 002d8cf0*/
// 0x002d1f50: definition moved into src/anon/unit_002cf260.cpp
void func_002d8cf0(BD_VALUE* bd) asm("_Z13func_002d8cf0P8BD_VALUE");
// 0x002d1f50: definition moved into src/anon/unit_002cf260.cpp
void func_002d8cf0(BD_VALUE* bd) { func_002d84a8(bd[1].i); }
}  // namespace n002d8cf0

// 002d8d08 (was src/anon/tiny_wrappers_more.cpp)
namespace n002d8d08 {
u32 Ti__MGHachimitsu__update_camera(u32, u32, u32, u32) asm("_Z31Ti__MGHachimitsu__update_camerajjjj");
/*TARGET 002d8d08*/
u32 func_002d8d08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002d8d08jjjj");
u32 func_002d8d08(u32 a0, u32 a1, u32 a2, u32 a3) {
    return Ti__MGHachimitsu__update_camera(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002d8d08

// 002d8d20 (was never written: gap function)
namespace n002d8d20 {
void func_002d8d20(void) asm("func_002d8d20");
void func_002d8d20(void) {}
}  // namespace n002d8d20

// 002d8d28 (was src/anon/tiny.cpp)
namespace n002d8d28 {
void func_002d8670(s32) asm("_Z13func_002d8670i");
/*TARGET 002d8d28*/
void func_002d8d28(BD_VALUE* bd) asm("_Z13func_002d8d28P8BD_VALUE");
void func_002d8d28(BD_VALUE* bd) { func_002d8670(bd[1].i); }
}  // namespace n002d8d28

// 002d8d40 (was src/anon/batch_w201.cpp)
namespace n002d8d40 {
/*TARGET 002d8d40*/
void func_002d8d40(u8* a, f32* b, f32* c) asm("func_002d8d40");
void func_002d8d40(u8* a, f32* b, f32* c) { *b = *(f32*)(a + 472) + 30.0f; *c = *(f32*)(a + 468) - 30.0f; }
}  // namespace n002d8d40

// 002d8d68 (was src/anon/batch_w2463_nsa.cpp)
namespace n002d8d68 {
struct Obj;
struct Quat;
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    QV operator+(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator*(f32 s) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 Length() const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct PV : QV {
    PV() {}
    ~PV() {}
    PV& operator=(const QV& o) { QV::operator=(o); return *this; }
} __attribute__((aligned(16)));
struct Mtx {
    QV r[4];
    Mtx() {}
    ~Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    QV operator*(const QV& v) const {
        QV o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    // Inverse of an orthonormal frame: transpose the rotation, translation = -(R^T t).
    void InvOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
void quat_dtor(Quat*) asm("_Z13func_002e44b8Pv");
struct Quat {
    f32 x, y, z, w;
    Quat() {}
    ~Quat() { quat_dtor(this); }
} __attribute__((aligned(16)));
struct Hit { s32 a; f32 b; s32 x8; s32 c; QV v; };
struct Rgn { u8 pad[8]; s16 x, y, z; };
struct Kind { u8 pad[5]; u8 kind; };
struct LFlag { u8 pad; };
typedef void (*ObjFn)(Obj*);
struct Obj { ObjFn* vt; u8 pad4[4]; Kind* kind; u8 pad0c[2040 - 12]; u32 f7f8; u8 pad7fc[2800 - 2044]; LFlag flag; };
s32 lflag_check(LFlag*, u32) asm("_ZN2Ti5LFlag5checkEj");
void quat_from_mtx(Quat*, Mtx*) asm("func_002e42d8");
Quat quat_slerp(const Quat&, const Quat&, f32) asm("func_002e47a8");
Mtx quat_to_mtx(const Quat&) asm("func_002e4588");
Rgn* func_0016bc20(Obj*, s32, s32) asm("func_0016bc20");
void YS__COLLISION__set(Hit*, Obj*, Rgn*) asm("YS__COLLISION__set");
Obj* YS__OBJ__Each(Obj*) asm("YS__OBJ__Each");
QV* YS__OBJ__get_pos(Obj*) asm("YS__OBJ__get_pos");
s32 func_0018a550(Hit*, Hit*) asm("func_0018a550");
void func_002cf280(LFlag*, u32, u32) asm("func_002cf280");
/*TARGET 002d8d68*/
s32 func_002d8d68(void* self, Obj* obj, Mtx* m2, Mtx* m3) asm("func_002d8d68");
s32 func_002d8d68(void* self, Obj* obj, Mtx* m2, Mtx* m3)
{
    Quat qa;
    quat_from_mtx(&qa, m3);
    QV va = m3->r[3];
    Quat qb;
    quat_from_mtx(&qb, m2);
    QV vb = m2->r[3];
    Rgn* rg = func_0016bc20(obj, 2, -1);
    if (!rg) return 0;
    Mtx mats[5];
    Hit x;
    YS__COLLISION__set(&x, obj, rg);
    for (s32 i = 1; i < 5; i++) {
        f32 t = (f32)i / 5.0f;
        mats[i] = quat_to_mtx(quat_slerp(qa, qb, t));
        mats[i].r[3] = (vb - va) * t + va;
        mats[i].r[3].w = 1.0f;
    }
    PV pts[5];
    {
        QV w((f32)rg->x, (f32)rg->y, (f32)rg->z, 1.0f);
        for (s32 k = 1; k < 5; k++) pts[k] = mats[k] * w;
    }
    for (s32 k = 1; k < 5; k++) mats[k].InvOrtho();
    s32 n = 0;
    Obj* e = 0;
    f32 range = 1000.0f;
    while ((e = YS__OBJ__Each(e)) != 0) {
        if (e->kind->kind != 21) continue;
        if (lflag_check(&e->flag, 64)) continue;
        QV d = *YS__OBJ__get_pos(e) - *YS__OBJ__get_pos(obj);
        if (d.Length() > range) continue;
        Rgn* h = func_0016bc20(e, 6, -1);
        if (!h) continue;
        Hit y;
        y.c = 0;
        YS__COLLISION__set(&y, e, h);
        for (s32 j = 1; j < 5; j++) {
            x.v = pts[j];
            if (func_0018a550(&x, &y) && !(e->f7f8 & 4)) {
                func_002cf280(&e->flag, 256, 0);
                n++;
                e->vt[8](e);
                break;
            }
        }
    }
    return n;
}
}  // namespace n002d8d68

// 002d9208 (was src/anon/misc_2.cpp)
namespace n002d9208 {
/*TARGET 002d9208*/
void func_002d9208(void* self, s32 v) asm("_Z13func_002d9208Pvi");
void func_002d9208(void* self, s32 v) { *(s32*)((char*)self + 476) = v; }
}  // namespace n002d9208

// 002d9210 (was src/taito/mg_hachimitsu.cpp)
namespace Ti { // method 002d9210
/*TARGET 002d9210*/
s32 MGHachimitsu_get_gopher(MGHachimitsu* self) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 MGHachimitsu_get_gopher(MGHachimitsu* self) { return reinterpret_cast<MGHachimitsuLayout*>(self)->gopher; }
}  // Ti

// 002d9218 (was src/taito/debug.cpp)
namespace Ti { // method 002d9218
/*TARGET 002d9218*/
void Debug_set_param(Debug* self, s32 v) asm("_ZN2Ti5Debug9set_paramEi");
void Debug_set_param(Debug* self, s32 v) { (void)v; }
}  // Ti

// 002d9220 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d9220 {
// --------------------
// 002d9220: Ti::MGHachimitsuPo honey-pot round start (spawn pot, Pooh and the pot object, reset them, start motions)
struct V2d9220 {
    f32 x, y, z, w;
    V2d9220(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));
struct Obj2d9220 { u8 pad[320]; u8 motion[16]; };
struct O2d9220 { u8 pad[172]; s32 f172; u8 pad2[200 - 176]; u8 attached; u8 started; };
extern void* g2d9220_player asm("D_0034e948");
Obj2d9220* o2d9220_0016b740(s32) asm("func_0016b740");
Obj2d9220* func_0016f000(s32, const V2d9220&, f32) asm("func_0016f000");
s32 o2d9220_is_attach(Obj2d9220*) asm("_ZN2YS3OBJ9is_attachEv");
void o2d9220_stop_voice(Obj2d9220*) asm("_ZN2Ti14MGHachimitsuPo19stop_interval_voiceEv");
void o2d9220_detach(Obj2d9220*) asm("_ZN2YS3OBJ6detachEv");
void o2d9220_0016b070(Obj2d9220*, const V2d9220&) asm("_Z16wtarget_0016b070jjjj");
void o2d9220_set_pos(Obj2d9220*, const V2d9220&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void o2d9220_001987a8(Obj2d9220*, const char*, s32) asm("_Z24YS__STDOBJ__start_camerajjjj");
void YS__MOTION__capture(void*, void*, s32, f32) asm("YS__MOTION__capture");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void o2d9220_texanm_stop(Obj2d9220*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");
struct Names2d9220 { const char* n[2]; };
/*TARGET 002d9220*/
void func_002d9220(O2d9220* o, s32 mode) asm("func_002d9220");
void func_002d9220(O2d9220* o, s32 mode)
{
    o->f172 = 0;
    o->started = 1;
    void* pl = g2d9220_player;
    Obj2d9220* a = o2d9220_0016b740(1630);
    Obj2d9220* b = o2d9220_0016b740(1633);
    Obj2d9220* c = func_0016f000(mode ? 2035 : 2034, V2d9220(0.0f, 0.0f, 0.0f, 0.0f), 0.0f);
    o->attached = o2d9220_is_attach(a);
    o2d9220_stop_voice(a);
    if (o2d9220_is_attach(a)) o2d9220_detach(a);
    if (o2d9220_is_attach(b)) o2d9220_detach(b);
    o2d9220_0016b070(a, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(a, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_0016b070(b, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(b, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_0016b070(c, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    o2d9220_set_pos(c, V2d9220(0.0f, 0.0f, 0.0f, 0.0f));
    Names2d9220 names = { { "00", "10" } };
    switch (mode) {
    case 0:
        o2d9220_001987a8(a, names.n[0], 0);
        YS__MOTION__capture(a->motion, pl, 252, 0.0f);
        func_0017f488(a->motion, 171, 0.0f, 0.0f);
        func_0017f488(b->motion, 171, 0.0f, 0.0f);
        func_0017f488(c->motion, 161, 0.0f, 0.0f);
        o2d9220_texanm_stop(a, 12);
        break;
    case 1:
        o2d9220_001987a8(a, names.n[1], 0);
        YS__MOTION__capture(a->motion, pl, 253, 0.0f);
        func_0017f488(a->motion, 172, 0.0f, 0.0f);
        func_0017f488(b->motion, 172, 0.0f, 0.0f);
        func_0017f488(c->motion, 170, 0.0f, 0.0f);
        o2d9220_texanm_stop(a, 12);
        break;
    }
}
}  // namespace n002d9220

// 002d94b8 (was src/anon/batch_w1799.cpp)
namespace n002d94b8 {
// 0x002ab818: definition moved into src/anon/unit_002a99c8.cpp

// ---- func_002d94b8 ----
s32 w1799_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
f32 w1799_GetRestTime(void) asm("_ZN2YS5EVENT11GetRestTimeEv");
void w1799_texanm_start(u8* obj, s32 n) asm("_ZN2YS3OBJ12texanm_startEi");
void w1799_change(u8* mot, s32 n, f32 a, f32 b) asm("_ZN2YS6MOTION6changeEiff");
void w1799_ut_1c0d38(u8*, s32, s32, s32) asm("_Z15YS__OBJ__attachjjjj");
u8* func_0016b740(s32) asm("func_0016b740");
void Ti__Afp__calc_local_matrix(u8*, u8) asm("Ti__Afp__calc_local_matrix");
extern s32 D_0034e948 asm("D_0034e948");
struct W1799Obj { u8 pad[200]; u8 flag; u8 active; };
/*TARGET 002d94b8*/
s32 func_002d94b8(W1799Obj* self) asm("func_002d94b8");
s32 func_002d94b8(W1799Obj* self) {
    if (self->active) {
        if (!w1799_IsExec() || w1799_GetRestTime() < 1.0f) {
            self->active = 0;
            u8* o = func_0016b740(1630);
            w1799_texanm_start(o, 12);
            if (self->flag) {
                w1799_ut_1c0d38(o, D_0034e948, 67, 0);
                w1799_change(o + 320, 0, 0.0f, 0.0f);
            }
            Ti__Afp__calc_local_matrix(o, self->flag);
            return 1;
        }
    }
    return 0;
}
}  // namespace n002d94b8

