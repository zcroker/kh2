#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/sora.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 001ce6e8 gap (never-written function)
namespace g001ce6e8 {
u32 YS__ACTION_JUMP__start(u32, u8*) asm("YS__ACTION_JUMP__start");
u32 func_001ce6e8(u32 a, u8* o) asm("func_001ce6e8");
u32 func_001ce6e8(u32 a, u8* o) {
    *(u32*)(o + 268) = (*(u32*)(o + 268) | 0x10) & ~0x80000;
    return YS__ACTION_JUMP__start(a, o);
}
}  // namespace g001ce6e8

// ---- 001ce718 gap (never-written function)
namespace g001ce718 {
u32 func_0017c660(u32, u8*) asm("func_0017c660");
u32 func_001ce718(u32 a, u8* o) asm("func_001ce718");
u32 func_001ce718(u32 a, u8* o) {
    *(u32*)(o + 268) &= ~0x10;
    return func_0017c660(a, o);
}
}  // namespace g001ce718

// ---- 001ce740 gap (never-written function)
namespace g001ce740 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
void func_0017c690(u32, u8*) asm("func_0017c690");
Vq func_0016b040() asm("func_0016b040");
void func_001ce740(u32 a, u8* o) asm("func_001ce740");
void func_001ce740(u32 a, u8* o) {
    u32 f = *(u32*)(o + 268);
    if (f & 0x80000) {
        *(f32*)(o + 28) = 0.0f;
    } else {
        if (f & 0x40000) *(u32*)(o + 268) = f | 0x80000;
        if (*(f32*)(o + 28) == 0.0f) *(Vq*)(o + 16) = func_0016b040();
        *(f32*)(o + 28) = *(f32*)(*(u8**)(o + 300) + 36);
    }
    func_0017c690(a, o);
}
}  // namespace g001ce740

// ---- 001ce7e8 gap (never-written function)
namespace g001ce7e8 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
Vq func_0017c870(u32, u8*, f32, f32) asm("func_0017c870");
Vq func_001ce7e8(u32 a, u8* o) asm("func_001ce7e8");
Vq func_001ce7e8(u32 a, u8* o) {
    u8* p = *(u8**)(o + 300);
    return func_0017c870(a, o, *(f32*)(p + 40), *(f32*)(p + 44));
}
}  // namespace g001ce7e8

// ---- 001ce820 from src/anon/tiny_wrappers_more.cpp
namespace n001ce820 {
u32 YS__ACTION_JUMP___land(u32, u32, u32, u32) asm("_Z22YS__ACTION_JUMP___landjjjj");
u32 func_001ce820(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce820jjjj");
u32 func_001ce820(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS__ACTION_JUMP___land(a0, a1, 0x00000016u, a3);
}
}  // namespace n001ce820

// ---- 001ce838 from src/anon/tiny.cpp
namespace n001ce838 {
void func_0017a8f8(void*) asm("_Z13func_0017a8f8Pv");
void func_001ce838(BD_VALUE* bd) asm("_Z13func_001ce838P8BD_VALUE");
void func_001ce838(BD_VALUE* bd) { func_0017a8f8(bd); }
}  // namespace n001ce838

// ---- 001ce850 gap (never-written function)
namespace g001ce850 {
void YS__OBJ__prepare_jump_height(u8*) asm("YS__OBJ__prepare_jump_height");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_001ce850(u32, u8* o) asm("func_001ce850");
void func_001ce850(u32, u8* o) {
    YS__OBJ__prepare_jump_height(o);
    func_0016bd60(o, 26);
}
}  // namespace g001ce850

// ---- 001ce880 from src/anon/tiny_auto80_solver.cpp
namespace n001ce880 {
u32 Tz__Mg2DTron__Mg2DTron(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z22Tz__Mg2DTron__Mg2DTronjjjjjjjj");
u32 func_001ce880(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001ce880jjjjjjjj");
u32 func_001ce880(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    *(volatile u32*)((u32)r4 + (s32)(0)) = 0u;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(8)) = 0u;
    r4 = (u32)((s32)r4 + (12));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))Tz__Mg2DTron__Mg2DTron)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(52)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(56)) = 0u;
    return r2;
}
}  // namespace n001ce880

// ---- 001ce8b8 from src/anon/tiny_auto80_solver.cpp
namespace n001ce8b8 {
u32 Tz__Mg2DTron__Mg2DTron(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z22Tz__Mg2DTron__Mg2DTronjjjjjjjj");
u32 func_001ce8b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001ce8b8jjjjjjjj");
u32 func_001ce8b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    *(volatile u32*)((u32)r4 + (s32)(0)) = 0u;
    r16 = r4;
    *(volatile u32*)((u32)r16 + (s32)(8)) = 0u;
    r4 = (u32)((s32)r4 + (12));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))Tz__Mg2DTron__Mg2DTron)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)((u32)r16 + (s32)(52)) = 0u;
    *(volatile u32*)((u32)r16 + (s32)(56)) = 0u;
    return r2;
}
}  // namespace n001ce8b8

// ---- 001ce8f0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001ce8f0 {
u32 func_00287760(u32, u32, u32, u32) asm("_Z13func_00287760jjjj");
u32 func_001ce8f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce8f0jjjj");
u32 func_001ce8f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (12));
    u32 (*fp_call4_00287760)(u32, u32, u32, u32) = func_00287760;
    r2 = fp_call4_00287760(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001ce8f0

// ---- 001ce910 from src/anon/tiny_auto80_fptr4.cpp
namespace n001ce910 {
u32 func_00287760(u32, u32, u32, u32) asm("_Z13func_00287760jjjj");
u32 func_001ce910(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce910jjjj");
u32 func_001ce910(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)r4 + (12));
    u32 (*fp_call4_00287760)(u32, u32, u32, u32) = func_00287760;
    r2 = fp_call4_00287760(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001ce910

// ---- 001ce930 from src/anon/batch_w92.cpp
namespace n001ce930 {
inline void* operator new(unsigned int, void* p) { return p; }
struct S1ce { s32 state; u32 f4; union { struct { u32 r0 : 1; u32 r1 : 1; } b; u32 req; }; };
u32 func_00167f18(s32) asm("func_00167f18");
void func_001ceb40(S1ce*, s32) asm("func_001ceb40");
s32 YS__BTLOBJ__is_damage_motion(u8*) asm("YS__BTLOBJ__is_damage_motion");
void YS__LIGHTCYCLE__check_turn(S1ce*, u8*, u32) asm("YS__LIGHTCYCLE__check_turn");
extern u8* D_0034e948 asm("D_0034e948");
void wt_001ce930(S1ce*) asm("_Z16wtarget_001ce930jjjj");
void wt_001ce930(S1ce* s) {
    s32 on = 2;
    s32 one = 1;
    u32 v = func_00167f18(0);
    u8* t = D_0034e948;
    if (s->b.r1) {
        s32 st = s->state;
        if (st < 2) {
            func_001ceb40(s, 2);
            s->state = on;
            st = on;
        }
        if (st == on && (!YS__BTLOBJ__is_damage_motion(t) || (*(u32*)(t + 352) & 0x10))) YS__LIGHTCYCLE__check_turn(s, t, v);
    } else if (s->b.r0) {
        if (s->state <= 0) {
            func_001ceb40(s, 0);
            s->state = one;
        }
    } else {
        switch (s->state) {
        case 1: func_001ceb40(s, 1); break;
        case 2: func_001ceb40(s, 4); break;
        }
        s->state = 0;
    }
    s->req = 0;
}
}  // namespace n001ce930

// ---- 001cea48 from src/anon/batch_w89.cpp
namespace n001cea48 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord operator-(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Cea { s32 state; u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
void Tz__Mg2DTron__CreateSeq(u8*, u32, u32) asm("Tz__Mg2DTron__CreateSeq");
void YS__LIGHTCYCLE__check_turn(Cea* o, u8* e, u64* pad) asm("YS__LIGHTCYCLE__check_turn");
void YS__LIGHTCYCLE__check_turn(Cea* o, u8* e, u64* pad) {
    u64 b = *pad;
    if ((b & (1ULL << 34)) && (u8)o->b0) {
        Tz__Mg2DTron__CreateSeq((u8*)o + 12, 0, 3);
        if (o->b1) Tz__Mg2DTron__CreateSeq((u8*)o + 12, 1, 4);
        *(s32*)(e + 2928) = 1;
        o->state = 3;
    } else if ((b & (1ULL << 35)) && o->b1) {
        Tz__Mg2DTron__CreateSeq((u8*)o + 12, 1, 3);
        if ((u8)o->b0) Tz__Mg2DTron__CreateSeq((u8*)o + 12, 0, 4);
        *(s32*)(e + 2928) = 2;
        o->state = 3;
    }
}
}  // namespace n001cea48

// ---- 001ceb40 from src/anon/auto80_199_queue.cpp
namespace n001ceb40 {
void func_001ceb40(u8* a0, u32 a1) asm("_Z13func_001ceb40Phj");
void func_001ceb40(u8* a0, u32 a1) {
    s32 i = 0;
    while (i < 2) {
        s32 x = *(s32*)(a0 + 4);
        s32 v = (x >> i) & 1;
        u8 b = (u8)v;
        if (b != 0) {
            Tz__Mg2DTron__CreateSeq((u32)(a0 + 12), (u32)i, a1);
        }
        i = i + 1;
    }
}
}  // namespace n001ceb40

// ---- 001cebb0 from src/anon/batch_w2365.cpp
namespace n001cebb0 {
struct TASK;
typedef void (*W2365_TaskFn)(TASK*);
struct W2365_Task { u8 pad[0x30]; W2365_TaskFn next; };
void* W2365_AreaAlloc(u32) asm("_ZN4AREA5AllocEj");
W2365_Task* W2365_CreateTask(s32, s32, W2365_TaskFn) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
struct W2365_Obj;
void func_001ce8b8(W2365_Obj*) asm("func_001ce8b8");
void func_001cec08(TASK*) asm("func_001cec08");
void func_001cec28(TASK*) asm("func_001cec28");
struct W2365_Obj {
    u8 data[60];
    static void* operator new(unsigned int n) { return W2365_AreaAlloc(n); }
    W2365_Obj() { func_001ce8b8(this); }
};
extern W2365_Obj* D_003521d0 asm("D_003521d0");
void func_001cebb0(void) asm("func_001cebb0");
void func_001cebb0(void)
{
    D_003521d0 = new W2365_Obj;
    W2365_CreateTask(1, 14001, func_001cec08)->next = func_001cec28;
}
}  // namespace n001cebb0

// ---- 001cec08 from src/anon/tiny_wrappers_imp.cpp
namespace n001cec08 {
u32 func_001ce930(u32, u32, u32, u32) asm("_Z13func_001ce930jjjj");
u32 func_001cec08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001cec08jjjj");
u32 func_001cec08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(8656));
    return func_001ce930(r4, r5, r6, r7);
}
}  // namespace n001cec08

// ---- 001cec28 gap (never-written function)
namespace g001cec28 {
extern u8* D_003521d0 asm("D_003521d0");
void func_001ce910(u8*) asm("func_001ce910");
void func_00105110(u8*) asm("func_00105110");
void func_001cec28() asm("func_001cec28");
void func_001cec28() {
    u8* p = D_003521d0;
    if (p) {
        func_001ce910(p);
        func_00105110(p);
    }
    D_003521d0 = 0;
}
}  // namespace g001cec28

// ---- 001cec70 from src/anon/auto80_199_queue.cpp
namespace n001cec70 {
void func_001cec70(u32 a0, u32 a1, u32 a2) asm("_Z13func_001cec70jjj");
void func_001cec70(u32 a0, u32 a1, u32 a2) {
    u32 p = D_003521d0;
    if (p == 0) {
        return;
    }

    a2 = a2 & 0xffu;
    *(u32*)(p + 4) = a1;

    if (a2 != 0) {
        u32 p1 = D_003521d0;
        u32 t = *(u32*)(p1 + 8);
        t = t | 1u;
        *(u32*)(p1 + 8) = t;

        u32 p2 = D_003521d0;
        *(u32*)(p2 + 52) = a0;
        return;
    }

    u32 p1 = D_003521d0;
    u32 t = *(u32*)(p1 + 8);
    t = t | 2u;
    *(u32*)(p1 + 8) = t;

    u32 p2 = D_003521d0;
    *(u32*)(p2 + 56) = a0;
}
}  // namespace n001cec70

// ---- 001cecc8 from src/anon/tiny_auto80_queue.cpp
namespace n001cecc8 {
extern u8  D_00350000 asm("D_00350000");
u32 func_001cecc8() asm("_Z13func_001cecc8v");
u32 func_001cecc8() {
    u8* v0 = *(u8**)((u8*)&D_00350000 + 8656u);
    s32 t6;
    s32 t7;

    if (v0 == 0) {
        goto ret0;
    }

    t6 = *(s32*)(v0 + 0);
    if (t6 <= 0) {
        goto ret0;
    }

    t7 = t6 < 3;
    if (t7 != 0) {
        goto ret52;
    }

    t7 = 3;
    if (t6 == t7) {
        goto ret56;
    }

ret0:
    return 0;

ret56:
    return *(u32*)(v0 + 56);

ret52:
    return *(u32*)(v0 + 52);
}
}  // namespace n001cecc8

// ---- 001ced10 from src/anon/batch_w34.cpp
namespace n001ced10 {
void func_00177dc8(void*, u32, u32, u32, u32) asm("func_00177dc8");
void func_001d56f0(void*) asm("func_001d56f0");
extern void* D_003521e0[] asm("D_003521e0");
void func_001ced10(u8* p, u32 a, u32 b, u32 c) asm("func_001ced10");
void func_001ced10(u8* p, u32 a, u32 b, u32 c) {
    func_00177dc8(p, a, 0, b, c);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2928) = 0;
    *(void**)p = D_003521e0;
    func_001d56f0(p + 2932);                     
    *(u32*)(p + 1420) |= 4;
}
}  // namespace n001ced10

// ---- 001ced68 from src/anon/batch_w35.cpp
namespace n001ced68 {
void func_00177dc8(void*, u32, u32, u32, u32) asm("func_00177dc8");
void func_001d56f0(void*) asm("func_001d56f0");
extern u8 D_003521e0[] asm("D_003521e0");
void func_001ced68(u8* p, u32 a1, u32 a2, u32 a3) asm("func_001ced68");
void func_001ced68(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 0, a2, a3);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2928) = 0;
    *(void**)p = D_003521e0;
    func_001d56f0(p + 2932);                     
    *(u32*)(p + 1420) |= 4;
}
}  // namespace n001ced68

// ---- 001cedc0 from src/anon/batch_wcx2.cpp
namespace n001cedc0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
void func_001780d8(u8*) asm("func_001780d8");
u8* func_0016b740_edc0(u32) asm("func_0016b740");
void YS__OBJ__attach(u8*, u8*, u32, u32) asm("YS__OBJ__attach");
void func_0017fd30(u8*, u8*) asm("func_0017fd30");
void func_0017f488_edc0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32) asm("func_0017f5e0");
void func_0016bd60_edc0(u8*, u32) asm("func_0016bd60");
void func_00198860(u8*, u32) asm("func_00198860");
void func_001cedc0(u8* p) asm("func_001cedc0");
void func_001cedc0(u8* p) {
    func_001780d8(p);
    u8* r = func_0016b740_edc0(1620);
    *(u8**)(p + 2924) = r;
    if (r) {
        YS__OBJ__attach(r, p, 16386, 0);
        func_0017fd30(p + 320, *(u8**)(p + 2924) + 320);
    }
    f32 z = 0.0f;
    func_0017f488_edc0(p + 320, 44, z, z);
    func_0017f5e0(p + 320, 0, 0, z, z);
    func_0016bd60_edc0(p, 23);
    func_00198860(p, 9);
}
}  // namespace n001cedc0

// ---- 001cee80 gap (never-written function)
namespace g001cee80 {
struct Vq { f32 x, y, z, w; Vq& operator=(const Vq& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
void func_001cee80(u8* p) asm("func_001cee80");
void func_001cee80(u8* p) {
    u8* q = *(u8**)(p + 2884);
    f32 v = *(f32*)(q + 2608) * *(f32*)(q + 2620);
    if (v != 0.0f) {
        f32 s;
        if (v > 0.0f) s = 1.0f; else s = -1.0f;
        *(f32*)(p + 16) = s; *(f32*)(p + 20) = 0.0f; *(f32*)(p + 24) = 0.0f; *(f32*)(p + 28) = *(f32*)(p + 272);
    } else {
        *(Vq*)(p + 16) = *(Vq*)(p + 1360);
        *(f32*)(p + 28) = 0.0f;
    }
}
}  // namespace g001cee80

// ---- 001ceef8 from src/anon/batch_w1789_nsa.cpp
namespace n001ceef8 {
struct W1789Vec { u8 b[16]; };
struct W1789Obj { u8 pad[0x7f8]; u32 flags; u8 pad2[0xb70 - 0x7fc]; s32 state; };
void YS__OBJ__get_dir(W1789Vec*, W1789Obj*) asm("YS__OBJ__get_dir");
void YS__MATH__VectorRotY(W1789Vec*, W1789Vec*, f32) asm("YS__MATH__VectorRotY");
void func_0016aef0(W1789Obj*, W1789Vec*) asm("func_0016aef0");
void YS__PLAYER___OVR_exec(W1789Obj*) asm("YS__PLAYER___OVR_exec");
void func_001ceef8(W1789Obj* p) asm("func_001ceef8");
void func_001ceef8(W1789Obj* p) {
    if (p->flags & 4) return;
    s32 s = p->state;
    if (s != 0) {
        switch (s) {
        case 1: { W1789Vec b; W1789Vec a; YS__OBJ__get_dir(&a, p); YS__MATH__VectorRotY(&b, &a, -1.57079637f); func_0016aef0(p, &b); } break;
        case 2: { W1789Vec b; W1789Vec a; YS__OBJ__get_dir(&a, p); YS__MATH__VectorRotY(&b, &a, 1.57079637f); func_0016aef0(p, &b); } break;
        }
        p->state = 0;
    }
    YS__PLAYER___OVR_exec(p);
}
}  // namespace n001ceef8

