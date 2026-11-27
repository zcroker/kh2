// Linked unit 0x195d00-0x196bf0 (YS object helpers). Gap functions written: 0x195dc8, 0x195fb8,
// 0x196210. .rodata 0x36d048-0x36d078.
// The unwritten gap function 0x196bf0 (record init, store order not reproduced) stays outside.
// Flags: -G0 -fno-strict-aliasing.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00195d00 from src/anon/batch_w86.cpp
namespace n00195d00 {
struct Obj;
struct Obj;
struct Obj;
struct Ent { u8 p0[20]; f32 f20; u8 p24[296]; u8 sub320[2548]; u16 f2868; };
struct Obj;
typedef void (*OFn)(Obj*, Ent*, s32);
struct Obj { OFn* vt; };
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, f32, f32, void (*)(void)) asm("func_0017f5e0");
void func_00195c80(void) asm("func_00195c80");
s32 func_00143448(u16) asm("func_00143448");
void YS__ACTION_HANG__control(Obj* o, Ent* e) asm("YS__ACTION_HANG__control");
void YS__ACTION_HANG__control(Obj* o, Ent* e)
{
    if (e->f20 < 0.0f) {
        func_0017f488(e->sub320, 8, 0.0f, 0.0f);
        func_0017f5e0(e->sub320, 4, 0.0f, 0.0f, func_00195c80);
        ((void (*)(Obj*, Ent*))o->vt[1])(o, e);
    } else {
        if (func_00143448(e->f2868)) return;
        o->vt[8](o, e, 0);
    }
}
}  // namespace n00195d00

// ---- 00195dc8 gap
namespace n00195dc8 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VObj { void (**vt)(VObj*, u8*, V4*); };
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_00195dc8(u8*, u8* o) asm("func_00195dc8");
void func_00195dc8(u8*, u8* o) {
    V4 v;
    asm("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&v) : "memory");
    VObj* m = *(VObj**)(o + 12);
    m->vt[2](m, o, &v);
    func_0017f488(o + 320, 4, 16.0f, 0.0f);
}
}  // namespace n00195dc8

// ---- 00195e20 data: .rodata 0x36d04c-0x36d078 (a zero word, then the file-name strings that the
// .data table at 0x350330 points to). aligned(4) keeps the section 4-byte aligned (gcc gives char
// arrays .align 3 by default, and gas would pad the section to 0x36d0b0, into the next unit at 0x36d0ac).
extern "C" const s32 D_0036d04c = 0;
extern "C" const char D_0036d050[16] __attribute__((aligned(4))) = "00common.bdx";
extern "C" const char D_0036d060[24] __attribute__((aligned(4))) = "00worldpoint.bin";

// ---- 00195e28 from src/anon/batch_wcx.cpp
namespace n00195e28 {
extern u8 D_003502d8[] asm("D_003502d8");
extern u8 D_0032bae0[] asm("D_0032bae0");
void func_001980d0(u8*, u32, s32, u32) asm("func_001980d0");
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
s32 func_0016a020(u8*) asm("func_0016a020");
s32 func_00196388(u8, u8) asm("func_00196388");
void func_001963c8(s32) asm("func_001963c8");
void func_00195e28(u8* p, u32 a, u32 b) asm("func_00195e28");
void func_00195e28(u8* p, u32 a, u32 b)
{
    func_001980d0(p, a, 7, b);
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_003502d8;
    p[2557] = 1;
    *(u32*)(p + 1416) |= 0x1000;
    p[2556] = 0;
    *(u32*)(p + 2548) = func_0016ac38(p, 1, 1, 0, 0);
    if (func_0016a020(p) == 569) {
        s32 r = func_00196388(D_0032bae0[0], D_0032bae0[1]);
        if (r >= 0) func_001963c8(r);
    }
}
}  // namespace n00195e28

// ---- 00195ed8 from src/anon/batch_wcx.cpp
namespace n00195ed8 {
extern u8 D_003502d8[] asm("D_003502d8");
extern u8 D_0032bae0a[] asm("D_0032bae0");
void func_001980d0(u8*, u32, s32, u32) asm("func_001980d0");
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
s32 func_0016a020(u8*) asm("func_0016a020");
s32 func_00196388(u8, u8) asm("func_00196388");
void func_001963c8(s32) asm("func_001963c8");
void YS__SAVEPOINT__SAVEPOINT(u8* p, u32 a, u32 b) asm("YS__SAVEPOINT__SAVEPOINT");
void YS__SAVEPOINT__SAVEPOINT(u8* p, u32 a, u32 b)
{
    func_001980d0(p, a, 7, b);
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_003502d8;
    p[2557] = 1;
    *(u32*)(p + 1416) |= 0x1000;
    p[2556] = 0;
    *(u32*)(p + 2548) = func_0016ac38(p, 1, 1, 0, 0);
    if (func_0016a020(p) == 569) {
        s32 r = func_00196388(D_0032bae0a[0], D_0032bae0a[1]);
        if (r >= 0) func_001963c8(r);
    }
}
}  // namespace n00195ed8

// ---- 00195f88 from src/anon/batch_w8.cpp
namespace n00195f88 {
void func_001dc878(u32) asm("func_001dc878");
void YS__OBJ___OVR_leave(void*) asm("YS__OBJ___OVR_leave");
void savepoint_leave(u8* o) asm("_ZN2YS3OBJ6VTABLEINS_9SAVEPOINTEE5leaveEPS0_");
void savepoint_leave(u8* o) {
    func_001dc878(*(u32*)(o + 2548));
    YS__OBJ___OVR_leave(o);
}
}  // namespace n00195f88

// ---- 00195fb8 gap
namespace n00195fb8 {
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_001dc818(u32) asm("func_001dc818");
void func_00195fb8(u8* o) asm("func_00195fb8");
void func_00195fb8(u8* o) {
    if (o[2556]) {
        if (*(u32*)(o + 2552) == 0) *(u32*)(o + 2552) = func_0016ac38(o, 2, 1, 0, 0);
    } else {
        u32 h = *(u32*)(o + 2552);
        if (h) {
            func_001dc818(h);
            *(u32*)(o + 2552) = 0;
        }
    }
    o[2556] = 0;
}
}  // namespace n00195fb8

// ---- 00196028 from src/anon/batch_w3823.cpp
namespace n00196028 {
struct Obj196 { s32 a0; s32 a4; u8 pad[0x178]; s32 c180; s32 c184; u8 pad2[0xd4]; s32 c25c;
  s32 ilt2() { return c180 < c184; } bool full() { return a0 >= a4; }
};
struct Self { u8 pad[0x9fc]; u8 f9fc; u8 f9fd; };
Obj196* func_001a1658(s32, s32) asm("func_001a1658");
void YS__SHEET__Free(Obj196*) asm("YS__SHEET__Free");
void func_001a1910(Obj196*, s32, s32) asm("func_001a1910");
void YS__SHEET__add_hp(Obj196*, s32, s32, s32) asm("YS__SHEET__add_hp");
void YS__SHEET__add_mp(Obj196*, s32, s32) asm("YS__SHEET__add_mp");
void func_001a1a50(Obj196*, s32) asm("func_001a1a50");
s32 YS__SHEET__is_mpdrive(Obj196*, s32) asm("YS__SHEET__is_mpdrive");
s32 func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8c10(s32, s32) asm("func_001a8c10");
void YS__SAVEPOINT__recover(Self* self) asm("YS__SAVEPOINT__recover");
void YS__SAVEPOINT__recover(Self* self) {
    register s32 g asm("$20") = func_001a8bd0(-1);
    for (s32 i = 0; i < 4; i++) {
        s32 h = func_001a8c10(g, i);
        if (h == 0) continue;
        Obj196* o = func_001a1658(h, -1);
        if (o->c25c != 0) {
            register s32 r asm("$5") = 1;
            if (o->full()) { s32 b = 0; if (!YS__SHEET__is_mpdrive(o, r)) b = !o->ilt2(); u8 c = b; asm volatile(""); r = 1; if (c) goto done; }
            YS__SHEET__add_hp(o, r, 0, 0);
            YS__SHEET__add_mp(o, 1, 0);
            self->f9fc = 1;
        } else {
            func_001a1a50(o, 0);
            s32 n = o->a4; func_001a1910(o, n, 0);
        }
    done:;
        YS__SHEET__Free(o);
    }
    if (self->f9fd) {
        self->f9fd = 0;
        self->f9fc = 1;
    }
}
}  // namespace n00196028

// ---- 00196170 from src/anon/batch_w4.cpp
namespace n00196170 {
u32 YS__DATABUFF__Read(u32) asm("YS__DATABUFF__Read");
extern u32 D_00350330 asm("D_00350330");
extern u32 D_01c61b00 asm("D_01c61b00");
void func_00196170(void) asm("func_00196170");
void func_00196170(void) {
    D_01c61b00 = YS__DATABUFF__Read(D_00350330);
}
}  // namespace n00196170

// ---- 00196198 from src/anon/batch_w48.cpp
namespace n00196198 {
void func_0016c750(u32) asm("func_0016c750");
void* func_0016d080(u32, s32) asm("func_0016d080");
void func_0016cbc8(void*, s32, s32, s32) asm("func_0016cbc8");
void YS__VM__exec(void*, s32) asm("YS__VM__exec");
void func_0016cab8(void*) asm("func_0016cab8");
void func_0016c7d8(void*) asm("func_0016c7d8");
void func_0016c770(void) asm("func_0016c770");
extern u32 D_0032b91c asm("D_0032b91c");
extern u32 D_01c61b00 asm("D_01c61b00");
void YS__VMCOMMON__NewGame(void) asm("YS__VMCOMMON__NewGame");
void YS__VMCOMMON__NewGame(void) {
    func_0016c750(D_0032b91c);
    void* h = func_0016d080(D_01c61b00, 0);
    func_0016cbc8(h, 7, 0, 0);
    YS__VM__exec(h, 0);
    if (h) {
        func_0016cab8(h);
        func_0016c7d8(h);
    }
    func_0016c770();
}
}  // namespace n00196198

// ---- 00196210 gap
namespace n00196210 {
extern u32 D_01c61b00 asm("D_01c61b00");
u8* func_0016d080(u32, s32) asm("func_0016d080");
void func_0016cbc8(u8*, s32, void*, s32) asm("func_0016cbc8");
void YS__VM__exec(u8*, s32) asm("YS__VM__exec");
void func_0016cab8(u8*) asm("func_0016cab8");
void func_0016c7d8(u8*) asm("func_0016c7d8");
void func_00196210(u32 a) asm("func_00196210");
void func_00196210(u32 a) {
    u32 arg[4];
    u8* vm = func_0016d080(D_01c61b00, 0);
    arg[0] = a;
    func_0016cbc8(vm, 8, arg, 1);
    YS__VM__exec(vm, 0);
    if (vm) {
        func_0016cab8(vm);
        func_0016c7d8(vm);
    }
}
}  // namespace n00196210

// ---- 00196288 from src/anon/batch_w49.cpp
namespace n00196288 {
u8* func_0016d080(u32, s32) asm("func_0016d080");
void func_0016cbc8(u8*, s32, u32*, s32) asm("func_0016cbc8");
void YS__VM__exec(u8*, s32) asm("YS__VM__exec");
void func_0016cab8(u8*) asm("func_0016cab8");
void func_0016c7d8(u8*) asm("func_0016c7d8");
extern u32 D_01c61b00 asm("D_01c61b00");
void func_00196288(u32 a) asm("func_00196288");
void func_00196288(u32 a) {
    u8* v = func_0016d080(D_01c61b00, 0);
    u32 t = a;
    func_0016cbc8(v, 12, &t, 1);
    YS__VM__exec(v, 0);
    if (v) {
        func_0016cab8(v);
        func_0016c7d8(v);
    }
}
}  // namespace n00196288

// ---- 00196300 from src/anon/batch_w5.cpp
namespace n00196300 {
u32 YS__DATABUFF__Read(u32) asm("YS__DATABUFF__Read");
extern u32 D_00350334 asm("D_00350334");
extern u32 D_01c61b04 asm("D_01c61b04");
void func_00196300(void) asm("func_00196300");
void func_00196300(void) {
    D_01c61b04 = YS__DATABUFF__Read(D_00350334);
}
}  // namespace n00196300

// ---- 00196328 from src/anon/batch_w1760_nsa.cpp
namespace n00196328 {
inline void* operator new(unsigned int, void* p) { return p; }
extern u8* D_01c61b04 asm("D_01c61b04");
struct W1760Q6 {
    u16 x, y, z;
    W1760Q6(int v) : x(v), y(v), z(v) {}
};
struct W1760C3 {
    u8 r, g, b, a;
    W1760Q6 q;
    W1760C3(int v) : r(v), g(v), b(v), q(v) {}
};
W1760C3* func_00196328(W1760C3* p, s32 i) asm("func_00196328");
W1760C3* func_00196328(W1760C3* p, s32 i) {
    new (p) W1760C3(0xffff);
    p->r = D_01c61b04[i * 4 + 0];
    p->g = D_01c61b04[i * 4 + 1];
    p->b = D_01c61b04[i * 4 + 2];
    return p;
}
}  // namespace n00196328

// ---- 00196388 from src/anon/tiny_auto80_queue.cpp
namespace n00196388 {
u32 func_00196388(u32 a0, u32 a1) asm("_Z13func_00196388jj");
u32 func_00196388(u32 a0, u32 a1) {
    u32 t7 = (u32)(0x01c6u << 16);
    u32 t5 = 0u;
    u32 t6 = *(u32*)((u32)t7 + (s32)(6916));
L0:
    u32 t7v = *(u8*)((u32)t6 + (s32)(0));
    if (t7v == a0) {
        t7v = *(u8*)((u32)t6 + (s32)(1));
        if (t7v == a1) {
            return t5;
        }
    }
    t5 = (u32)(t5 + (1));
    if ((s32)t5 < (s32)54) {
        t6 = (u32)((s32)t6 + (4));
        goto L0;
    }
    return (u32)-1;
}
}  // namespace n00196388

// ---- 001963c8 from src/anon/auto200_999.cpp
namespace n001963c8 {
extern u8 D_0032da20 asm("D_0032da20");
void func_001963c8(u32 a0) asm("_Z13func_001963c8j");
void func_001963c8(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032da20 + (idx << 2));
    a0 &= 31;
    u32 val = *p;
    u32 mask = 1u << a0;
    *p = val | mask;
}
}  // namespace n001963c8

// ---- 001963f8 from src/anon/tiny_auto80_solver.cpp
namespace n001963f8 {
extern u8 D_0032da20 asm("D_0032da20");
void func_001963f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001963f8jjjjjjjj");
void func_001963f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = a0 >> 5;
    u32 base = (u32)&D_0032da20;
    idx <<= 2;
    idx += base;
    a0 &= 31;
    u32 mask = 1;
    u32 val = *(u32*)idx;
    mask <<= a0;
    mask = ~mask;
    val &= mask;
    *(u32*)idx = val;
}
}  // namespace n001963f8

// ---- 00196430 from src/anon/batch_w1782_nsa.cpp
namespace n00196430 {
struct S196430 {
    u8 a, b, c;
    u16 d, e, f;
    S196430() { u16 m = 0xffff; a = m; b = m; c = m; d = m; e = m; f = m; }
};
S196430 func_00196328(u32) asm("func_00196328");
s32 func_00196768(u8, u8) asm("func_00196768");
extern u32 D_0032da20[] asm("D_0032da20");
s32 func_00196430(u32 x) asm("func_00196430");
s32 func_00196430(u32 x) {
    S196430 s;
    s32 r = 0;
    if (D_0032da20[x >> 5] & (1 << (x & 0x1f))) {
        s = func_00196328(x);
        r = func_00196768(s.a, s.b) == 0 ? 1 : 2;
    }
    return r;
}
}  // namespace n00196430

// ---- 001964d8 from src/anon/batch_w38.cpp
namespace n001964d8 {
struct S1964d8 { u8 a, b, c; u16 d, e, f; };
S1964d8 func_00196328(u32) asm("func_00196328");
void func_001967f0(u8, u8, s32) asm("func_001967f0");
void func_001964d8(u32 x) asm("func_001964d8");
void func_001964d8(u32 x) {
    S1964d8 s;
    u16 m = 0xffff;
    s.a = m;
    s.b = m;
    s.c = m;
    s.d = m;
    s.e = m;
    s.f = m;
    s = func_00196328(x);
    func_001967f0(s.a, s.b, 1);
}
}  // namespace n001964d8

// ---- 00196540 from src/anon/batch_w87.cpp
namespace n00196540 {
void func_001963c8(s32) asm("func_001963c8");
void func_00196540(s32 id) asm("func_00196540");
void func_00196540(s32 id) {
    switch (id) {
    case 2232: func_001963c8(47); return;
    case 4193: func_001963c8(30); return;
    case 5151: func_001963c8(9); return;
    case 6178:
    case 6263: func_001963c8(31); return;
    case 8227: func_001963c8(41); return;
    case 10274: func_001963c8(38); return;
    case 12306: func_001963c8(19); return;
    case 16414: func_001963c8(16); return;
    }
}
}  // namespace n00196540

// ---- 00196608 from src/anon/tiny.cpp
namespace n00196608 {
void func_00196608(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00196608jjjj");
void func_00196608(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (6920)) = (u32)a0;
}
}  // namespace n00196608

// ---- 00196618 from src/anon/batch_w27.cpp
namespace n00196618 {
struct Pair196618 { u8 a, b; };
struct Tbl196618 { u16 count; Pair196618 e[1]; };
extern Tbl196618* D_01c61b08 asm("D_01c61b08");
s32 func_00196618(s32 a, s32 b) asm("func_00196618");
s32 func_00196618(s32 a, s32 b) {
    for (s32 i = 0; i < D_01c61b08->count; i++) {
        if (D_01c61b08->e[i].a == a && D_01c61b08->e[i].b == b) return i;
    }
    return -1;
}
}  // namespace n00196618

// ---- 00196670 from src/anon/tiny_auto80_solver.cpp
namespace n00196670 {
extern u8 D_0032bb30 asm("D_0032bb30");
void func_00196670(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00196670jjjjjjjj");
void func_00196670(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0032bb30;
    r4 = (u32)(r4 << 2);    r4 = (u32)(r4 + r15);
    r15 = (u32)((s32)r4 + (7904));
    *(u16*)((u32)r15 + (s32)(24)) = (u16)r5;
    r4 = (u32)((s32)r4 + (7906));
    *(u16*)((u32)r4 + (s32)(24)) = (u16)r6;
}
}  // namespace n00196670

// ---- 00196698 from src/anon/tiny_auto80_solver.cpp
namespace n00196698 {
extern u8 D_0032bb30 asm("D_0032bb30");
void func_00196698(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00196698jjjjjjjj");
void func_00196698(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0032bb30;
    r4 = (u32)(r4 << 2);    r4 = (u32)(r4 + r15);
    *(u16*)((u32)r4 + (s32)(7928)) = (u16)0u;
}
}  // namespace n00196698

// ---- 001966b0 from src/anon/batch_w65.cpp
namespace n001966b0 {
struct S16x2 { s16 a, b; };
struct Tbl7928 { u8 pad[7928]; S16x2 arr[1]; };
extern Tbl7928 D_0032bb30 asm("D_0032bb30");
extern u8* D_01c61b08 asm("D_01c61b08");
s32 func_00196388(u32, u32) asm("func_00196388");
void func_001963f8(s32) asm("func_001963f8");
void func_001966b0(s32 i) asm("func_001966b0");
void func_001966b0(s32 i) {
    D_0032bb30.arr[i].a = -1;
    u8* e = (u8*)(i * 2 + (u32)D_01c61b08);
    s32 r = func_00196388(e[2], e[3]);
    if (r >= 0) func_001963f8(r);
}
}  // namespace n001966b0

// ---- 00196710 from src/anon/batch_w28.cpp
namespace n00196710 {
void func_00196698(u32) asm("func_00196698");
s32 func_00196388(u8, u8) asm("func_00196388");
void func_001963f8(s32) asm("func_001963f8");
extern u8* D_01c61b08 asm("D_01c61b08");
void func_00196710(u32 i) asm("func_00196710");
void func_00196710(u32 i) {
    func_00196698(i);
    u8* e = (u8*)(i * 2) + (u32)D_01c61b08;
    s32 r = func_00196388(e[2], e[3]);
    if (r >= 0) func_001963f8(r);
}
}  // namespace n00196710

// ---- 00196768 from src/anon/batch_w1545.cpp
namespace n00196768 {
struct W1545T32 { u16 a; u16 b; };
struct W1545S32 { u8 pad[0x1ef8]; W1545T32 arr[1]; };
s32 func_00196618() asm("func_00196618");
s32 func_001d52a0(s32, s32) asm("func_001d52a0");
extern W1545S32 D_0032bb30 asm("D_0032bb30");
s32 func_00196768(s32 a, s32 b) asm("func_00196768");
s32 func_00196768(s32 a, s32 b) {
    s32 idx = func_00196618();
    s32 r = 0;
    if (idx >= 0) {
        s32 t = D_0032bb30.arr[idx].a;
        if (t != 0 && t != -1) t = -2;
        if (t == 0) { if (func_001d52a0(a, b)) t = -2; }
        r = t;
    }
    return r;
}
}  // namespace n00196768

// ---- 001967f0 from src/anon/batch_w55.cpp
namespace n001967f0 {
struct S1967 { u8 pad[7928]; u16 t[1]; };
extern u8 D_0032bb30[] asm("D_0032bb30");
s32 func_00196618(u32, u32, s32) asm("func_00196618");
u32 func_001d52c0(u32, u32) asm("func_001d52c0");
s32 func_00192048(u32) asm("func_00192048");
s32 func_001967f0(u32 a, u32 b, s32 c) asm("func_001967f0");
s32 func_001967f0(u32 a, u32 b, s32 c) {
    s32 i = func_00196618(a, b, c);
    if (i < 0) return 0;
    u32 v = ((S1967*)D_0032bb30)->t[i * 2 + c];
    if (!v) v = func_001d52c0(a, b);
    return func_00192048(v);
}
}  // namespace n001967f0

// ---- 00196888 from src/anon/batch_w63.cpp
namespace n00196888 {
void func_0016d110(void) asm("func_0016d110");
u32 YS__VM__exec(u32, s32) asm("YS__VM__exec");
extern u32 D_0034f240 asm("D_0034f240");
struct P8 { u32 a; u32 b; };
extern P8 D_00350338[8] asm("D_00350338");
void func_00196888(void) asm("func_00196888");
void func_00196888(void) {
    func_0016d110();
    if (D_0034f240 & 0x20) return;
    P8* e = D_00350338;
    for (s32 i = 7; i >= 0; i--, e++) {
        if (e->b && !e->a) e->a = YS__VM__exec(e->b, 0);
    }
}
}  // namespace n00196888

// ---- 00196908 from src/anon/batch_w66.cpp
namespace n00196908 {
struct E196 { u32 f0; u8* f4; };
extern E196 D_00350338[8] asm("D_00350338");
u8* func_0016d080(u32, s32) asm("func_0016d080");
void func_0016cce8(u8*, s32, s32, s32, s32) asm("func_0016cce8");
void func_0016cbc8(u8*, s32, s32, s32) asm("func_0016cbc8");
u32 func_0016cb88(u8*, s32) asm("func_0016cb88");
s32 YS__UNITSCRIPT__Start(u32 a) asm("YS__UNITSCRIPT__Start");
s32 YS__UNITSCRIPT__Start(u32 a) {
    s32 i;
    for (i = 0; i < 8; i++) if (!D_00350338[i].f4) break;
    E196* e = &D_00350338[i];
    u8* v = func_0016d080(a, 0);
    e->f4 = v;
    func_0016cce8(v, 2, 0, 0, 0);
    func_0016cbc8(v, 3, 0, 0);
    *(u32*)(v + 36) = func_0016cb88(v, 4);
    e->f0 = 0;
    return i;
}
}  // namespace n00196908

// ---- 001969c0 from src/anon/tiny_auto80_queue.cpp
namespace n001969c0 {
u32 func_0016ced0(...) asm("func_0016ced0");
extern u8 D_00350338 asm("D_00350338");
u32 func_001969c0(...) asm("func_001969c0");
void func_001969c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001969c0");
void func_001969c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15, r16;
    r15 = (u32)&D_00350338;
    r4 = (u32)(r4 << 3);
    r16 = (u32)(r4 + r15);
    r14 = *(u32*)((u32)r16 + (s32)(4));
    r4 = r14;
    if (r14 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0016ced0)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(u32*)((u32)r16 + (s32)(4)) = 0u;
    }
}
}  // namespace n001969c0

// ---- 00196a08 from src/anon/tiny_auto80_queue.cpp
namespace n00196a08 {
u32 func_0016d110(...) asm("func_0016d110");
u32 func_001969c0(...) asm("func_001969c0");
void func_00196a08(void) asm("_Z13func_00196a08v");
void func_00196a08(void) {
    u32 s0 = 0u;
L0:
    func_001969c0(s0);
    s0 = (u32)(s0 + 1u);
    if ((s32)s0 < 8) {
        goto L0;
    }
    func_0016d110();
}
}  // namespace n00196a08

// ---- 00196a40 from src/anon/batch_w44.cpp
namespace n00196a40 {
void* func_00102c18(u32, u32, void*) asm("func_00102c18");
void func_00196888(void) asm("func_00196888");
void func_00196a08(void) asm("func_00196a08");
struct Pair { u32 a, b; };
extern Pair D_00350338[8] asm("D_00350338");
void func_00196a40(void) asm("func_00196a40");
void func_00196a40(void) {
    for (s32 i = 0; i < 8; i++) D_00350338[i].b = 0;
    u8* t = (u8*)func_00102c18(1, 14002, (void*)func_00196888);
    *(void**)(t + 48) = (void*)func_00196a08;
}
}  // namespace n00196a40

// ---- 00196aa0 from src/anon/batch_w54.cpp
namespace n00196aa0 {
struct Pair8 {
    u32 a;
    void* p;
};
extern Pair8 D_00350338[8] asm("D_00350338");
void func_0016cce8(void*, void*, s32, s32, s32) asm("func_0016cce8");
void func_00196aa0(void* a0, s32 a1, s32 a2) asm("func_00196aa0");
void func_00196aa0(void* a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < 8; i++) {
        void* o = D_00350338[i].p;
        if (o) func_0016cce8(o, a0, a1, a2, 0);
    }
}
}  // namespace n00196aa0

// ---- 00196b28 from src/anon/tiny_auto80_queue.cpp
namespace n00196b28 {
u32 func_00196aa0(...) asm("func_00196aa0");
void func_00196b28(u32 a0, u32 a1) asm("_Z13func_00196b28jj");
void func_00196b28(u32 a0, u32 a1) {
    u32 sp[2];
    sp[0] = a0;
    sp[1] = a1;
    func_00196aa0(10u, (u32)&sp[0], 2u);
}
}  // namespace n00196b28

// ---- 00196b58 from src/anon/tiny_auto80_queue.cpp
namespace n00196b58 {
u32 func_00196aa0(...) asm("func_00196aa0");
void func_00196b58(u32 a0, u32 a1) asm("_Z13func_00196b58jj");
void func_00196b58(u32 a0, u32 a1) {
    u32 sp[2];
    sp[0] = a0;
    sp[1] = a1;
    func_00196aa0(6u, (u32)&sp[0], 2u);
}
}  // namespace n00196b58

// ---- 00196b88 from src/anon/batch_w39.cpp
namespace n00196b88 {
extern u8 D_00350378 asm("D_00350378");
extern u8 D_00350379 asm("D_00350379");
extern u32 D_01c61b40 asm("D_01c61b40");
u32 func_00198d20(int) asm("func_00198d20");
void func_00196b88(void) asm("func_00196b88");
void func_00196b88(void) {
    u32 v = func_00198d20(0);
    D_00350379 = 0;
    if ((v & 0x3f) - 2 < 2) {
        D_00350378 = 1;
        if (!(v & 0xc0)) D_00350379 = 1;
    } else {
        D_00350378 = 0;
    }
    D_01c61b40 = 1;
}
}  // namespace n00196b88

