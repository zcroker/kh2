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

// ---- 001d0cb8 gap (never-written function)
namespace g001d0cb8 {
typedef void (*VF)(u8*, u8*, f32);
void func_001d0cb8(u8* p) asm("func_001d0cb8");
void func_001d0cb8(u8* p) { u8* t = *(u8**)(p + 12); (*(VF*)(*(u8**)t + 12))(t, p, 0.0f); }
}  // namespace g001d0cb8

// ---- 001d0ce8 from src/anon/tiny_wrappers_imp.cpp
namespace n001d0ce8 {
u32 YS__PLAYER___OVR_leave_req(u32, u32, u32, u32) asm("_Z26YS__PLAYER___OVR_leave_reqjjjj");
u32 func_001d0ce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d0ce8jjjj");
u32 func_001d0ce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(9216)) = 0u;
    return YS__PLAYER___OVR_leave_req(r4, r5, r6, r7);
}
}  // namespace n001d0ce8

// ---- 001d0d08 gap (never-written function)
namespace g001d0d08 {
void func_00186008(u8*) asm("func_00186008");
extern u8 D_00351eb8[] asm("D_00351eb8");
void func_001c8d98(u8*, s32) asm("func_001c8d98");
static inline bool InRange(s32 v) { return v != 0 && v < 7; }
void func_001d0d08(u8* p) asm("func_001d0d08");
void func_001d0d08(u8* p) {
    func_00186008(p);
    if (InRange(*(s32*)(p + 2896))) func_001c8d98(D_00351eb8, 0);
}
}  // namespace g001d0d08

// ---- 001d0d60 from src/anon/batch_w93.cpp
namespace n001d0d60 {
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator-(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator+(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
struct W93Q16 { u8 v[16]; } __attribute__((aligned(16)));
struct W93Map { u8 pad[4]; u16 flags; };
union W93UM { W93Map* p; u32 u; };
extern W93UM D_0034f240 asm("D_0034f240");
struct W93Pl { u8 pad[2896]; s32 state; };
s32 func_001bb7f8(void) asm("func_001bb7f8");
void func_00179e18(W93Pl*) asm("func_00179e18");
s32 YS__PLAYER__is_changing(W93Pl*) asm("YS__PLAYER__is_changing");
void func_001d0eb8(W93Pl*) asm("func_001d0eb8");
void func_001991a8(s32, s32) asm("func_001991a8");
void YS__CHANGEFORM__Dead(W93Pl*) asm("YS__CHANGEFORM__Dead");
s32 func_001c8b48(void) asm("func_001c8b48");
s32 func_001bbb50(void) asm("func_001bbb50");
s32 func_001c8ab0(void) asm("func_001c8ab0");
void func_001d1408(W93Pl*) asm("func_001d1408");
void func_001af328(W93Pl*) asm("func_001af328");
void func_001af360(W93Pl*) asm("func_001af360");
void func_001af290(W93Pl*) asm("func_001af290");
static inline bool W93Dead(W93Pl* p) { return p->state == 12; }
void func_001d0d60(W93Pl* p) asm("func_001d0d60");
void func_001d0d60(W93Pl* p)
{
    if (D_0034f240.u & 0x20000) {
        if (func_001bb7f8()) {
            func_001991a8(90, 0);
            return;
        }
        func_00179e18(p);
        if (YS__PLAYER__is_changing(p) || W93Dead(p)) {
            YS__CHANGEFORM__Dead(p);
            return;
        }
        func_001d0eb8(p);
        func_001991a8(90, 0);
        return;
    }
    func_00179e18(p);
    if (func_001c8b48()) {
        if (W93Dead(p)) { YS__CHANGEFORM__Dead(p); return; }
        func_001d0eb8(p);
        func_001af328(p);
        return;
    }
    if (func_001bbb50()) {                    
        func_001d0eb8(p);
        func_001af360(p);
        return;
    }
    if (YS__PLAYER__is_changing(p) || W93Dead(p)) {
        YS__CHANGEFORM__Dead(p);
        return;
    }
    if (func_001c8ab0() == 2) func_001d1408(p);
    func_001d0eb8(p);
    func_001af290(p);
}
}  // namespace n001d0d60

// ---- 001d0eb8 from src/anon/tiny_auto80_queue.cpp
namespace n001d0eb8 {
void func_0017f488(...) asm("func_0017f488");
u32 func_001c0e60(...) asm("func_001c0e60");
u32 func_0016bd60(...) asm("func_0016bd60");
u32 func_001c0cd8(...) asm("func_001c0cd8");
void func_001d0eb8(u8* a0) asm("_Z13func_001d0eb8Ph");
void func_001d0eb8(u8* a0) {
    u8* s0 = a0;
    if (func_001c0cd8(s0) != 0) {
        func_001c0e60(s0);
    }
    ((void(*)(u32, u32, f32, f32))func_0017f488)((u32)(s0 + 320), 54, 0.0f, 0.0f);
    func_0016bd60(s0, 41);
}
}  // namespace n001d0eb8

// ---- 001d0f08 from src/anon/batch_w8021.cpp
namespace n001d0f08 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W8021Q1 { u8 pad[0x1b4]; f32 f1b4; };
struct W8021A {
    u8 p0[0x160]; u32 m160; u8 p1[0x48c - 0x164]; W8021Q1* q48c; u8 p2[0x7f8 - 0x490]; u32 m7f8;
    u8 p3[0xaec - 0x7fc]; s32 maec; u8 p4[0xb50 - 0xaf0]; s32 mb50;
};
void YS__PLAYER___OVR_exec() asm("YS__PLAYER___OVR_exec");
s32 func_00179c08(W8021A*, s32) asm("func_00179c08");
s32 YS__PLAYER__is_changing(W8021A*) asm("YS__PLAYER__is_changing");
s32 YS__OBJ__can_decide(W8021A*, s32) asm("YS__OBJ__can_decide");
void func_001b6b10(W8021A*, s32) asm("func_001b6b10");
void YS__CHANGEFORM__CaptureEnd(W8021A*) asm("YS__CHANGEFORM__CaptureEnd");
s32 YS__COMMAND_ELEM__Get(s32) asm("YS__COMMAND_ELEM__Get");
s32 YS__COMMAND_SLOT__GetStatus(s32, W8021A*, s32) asm("YS__COMMAND_SLOT__GetStatus");
s32 func_001c8ab0() asm("func_001c8ab0");
void func_001d1408(W8021A*) asm("func_001d1408");
static inline u8 lt4(s32 id, W8021A* a) { return YS__COMMAND_SLOT__GetStatus(id, a, 0) < 4; }
static inline u32 is12(W8021A* a) { return a->mb50 == 12; }
void func_001d0f08(W8021A* a) asm("func_001d0f08");
void func_001d0f08(W8021A* a) {
    YS__PLAYER___OVR_exec();
    if (a->m7f8 & 4) return;
    if (a->maec != 0) return;
    if (a->m160 & 0x4000) return;
    W8021Q1* q = a->q48c;
    if (q == 0) return;
    if (!(q->f1b4 <= 0.0f)) return;
    if (YS__PLAYER__is_changing(a)) {
        s32 r = YS__COMMAND_ELEM__Get(5);
        r = func_00179c08(a, r);
        if (r) func_001b6b10(a, 0);
    } else if (is12(a)) {
        s32 id = YS__COMMAND_ELEM__Get(5);
        if (YS__OBJ__can_decide(a, id) && lt4(id, a)) YS__CHANGEFORM__CaptureEnd(a);
    } else if (func_001c8ab0() == 2) {
        s32 r = YS__COMMAND_ELEM__Get(0x13c);
        r = func_00179c08(a, r);
        if (r) func_001d1408(a);
    }
}
}  // namespace n001d0f08

// the four ids that 0x1d1070 tries in turn
extern "C++" const u16 R_0036e390[4] asm("D_0036e390") = { 0x184, 0x183, 0x182, 0x181 };

// ---- 001d1070 from src/anon/batch_w92.cpp
namespace n001d1070 {
inline void* operator new(unsigned int, void* p) { return p; }
struct T1d1 { u16 f0, f2, bit; u16 pad[5]; u16 id; };
struct B1d1 { u32 w[8]; };
s32 YS__PLAYER__is_changing(u8*) asm("YS__PLAYER__is_changing");
s32 func_001a2478(u32) asm("func_001a2478");
u32* func_00177860(u8*) asm("func_00177860");
T1d1* func_001a80c8(u16) asm("func_001a80c8");
void* YS__COMMAND_ELEM__Get(u16) asm("YS__COMMAND_ELEM__Get");
s32 YS__COMMAND_SLOT__GetStatus(void*, u8*, s32) asm("YS__COMMAND_SLOT__GetStatus");
void func_00190128(B1d1*) asm("func_00190128");
void func_001bd3e0(u32, s32, u16, B1d1*, s32, s32) asm("func_001bd3e0");
extern u16 D_0036e390[] asm("D_0036e390");
s32 func_001d1070(u8* self) asm("func_001d1070");
s32 func_001d1070(u8* self) {
    if (YS__PLAYER__is_changing(self) || !func_001a2478(*(u32*)(self + 1164))) return 0;
    u32* bits = func_00177860(self);
    u16* ids = D_0036e390;
    for (u32 i = 0; i < 4; i++) {
        T1d1* t = func_001a80c8(*ids++);                       
        u32 k = t->bit;
        if (bits[k >> 5] & (1 << (k & 31))) {
            if (YS__COMMAND_SLOT__GetStatus(YS__COMMAND_ELEM__Get(t->id), self, 0) < 4) {
            B1d1 b;
            func_00190128(&b);
            func_001bd3e0(*(u32*)(self + 2884), 1, t->id, &b, 1, 0);
            return 1;
            }
        }
    }
    return 0;
}
}  // namespace n001d1070

