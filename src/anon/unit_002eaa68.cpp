#include "../common/types.h"

// Ts lock-on callbacks (0x2eaa68-0x2ead98): action setters, the per-target callbacks and their tiny
// wrappers (0x2eab20, 0x2eab40, 0x2eab58, 0x2eab90, 0x2eacb8, 0x2ead08 and the empty 0x2eaa68 were never
// written before), the lock-on tuning setter and the static init of D_00363448 with its _GLOBAL__I_ stub
// as plain functions. Every symbol is bound by asm label.

namespace n002eaa68 {
void func_002eaa68(void) asm("func_002eaa68");
void func_002eaa68(void) {}
}  // namespace n002eaa68

// 002eaa70 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002eaa70 {
extern "C" u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
// 002e8f58: moved to src/anon/unit_002e8b50.cpp

// 002e8f90: moved to src/anon/unit_002e8b50.cpp

// 002e8fc0: moved to src/anon/unit_002e8b50.cpp

// 002e9158: moved to src/anon/unit_002e8b50.cpp

u32 func_002eaa70(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002eaa70");
u32 func_002eaa70(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r4 = r5;
    r16 = r5;
    r5 = 0u;
    r2 = YS_OBJ_change_action(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(264));
    r14 = (u32)(0x0800u << 16);
    r15 = (u32)(r15 | r14);
    *(u32*)((u32)r16 + (s32)(264)) = r15;
    return r2;
}
}  // namespace n002eaa70

// 002eaab0 (from src/anon/batch_w16.cpp)
namespace n002eaab0 {
void func_0017c4c8(u32, void*) asm("func_0017c4c8");
void func_0016bd60(u32, u32) asm("func_0016bd60");
// 0x001d9ca0: definition moved into src/anon/unit_001d7458.cpp

void wtarget_002eaab0(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002eaab0jjjj");
void wtarget_002eaab0(u32 a0, u32 a1, u32, u32) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(a1) : "$8", "memory");
    func_0017c4c8(a0, tmp);
    func_0016bd60(a0, 44);
}
}  // namespace n002eaab0

// 002eaaf0 (from src/anon/batch_w12.cpp)
namespace n002eaaf0 {
void func_0016bd60(u32, s32) asm("func_0016bd60");
void func_0017c430(void*) asm("func_0017c430");
// 002e2dd8: moved to src/anon/unit_002e2d18.cpp

void func_002eaaf0(void* p) asm("func_002eaaf0");
void func_002eaaf0(void* p) {
    func_0017c430(p);
    func_0016bd60((u32)p, 44);
}
}  // namespace n002eaaf0

namespace n002eab20 {
extern f32 D_00363448 asm("D_00363448");
extern f32 D_0036344c asm("D_0036344c");
void func_002eab20(void*, u8* o) asm("func_002eab20");
void func_002eab20(void*, u8* o) {
    *(f32*)(o + 284) = D_00363448;
    *(f32*)(o + 280) = D_0036344c;
}
void func_002eab40(void*, u8* o) asm("func_002eab40");
void func_002eab40(void*, u8* o) {
    u8* t = *(u8**)(o + 300);
    *(f32*)(o + 284) = *(f32*)(t + 12);
    *(f32*)(o + 280) = *(f32*)(t + 8);
}
void func_002eab58(void*, u8* o) asm("func_002eab58");
void func_002eab58(void*, u8* o) {
    *(u32*)(o + 264) |= 0x8000000;
}
}  // namespace n002eab20

// 002eab70 (from src/anon/tiny_wrappers_more.cpp)
namespace n002eab70 {
u32 func_002eaab0(u32, u32, u32, u32) asm("func_002eaab0");
// 002e8b68: moved to src/anon/unit_002e8b50.cpp

// 002e8c10: moved to src/anon/unit_002e8b50.cpp

// 002e8ff8: moved to src/anon/unit_002e8b50.cpp

// 002e9080: moved to src/anon/unit_002e8b50.cpp

// 002e90a8: moved to src/anon/unit_002e8b50.cpp

// 002e9208: moved to src/anon/unit_002e8b50.cpp

// 002e9988: _GLOBAL__I_ stub, now made by gcc in src/sugi/flare.cpp

u32 func_002eab70(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002eab70");
u32 func_002eab70(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002eaab0(a1, a2, a2, a3);
}
}  // namespace n002eab70

namespace n002eab90 {
void func_002eaaf0(u8*) asm("func_002eaaf0");
void func_002eab90(void*, u8* o) asm("func_002eab90");
void func_002eab90(void*, u8* o) { func_002eaaf0(o); }
}  // namespace n002eab90

// 002eaba8 (from src/anon/batch_w53.cpp)
namespace n002eaba8 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
extern f32 D_00363440 asm("D_00363440");
// Returns (o+16) scaled by D_00363440 (VU0).
Q16* func_002eaba8(Q16* ret, u32, u8* o) asm("func_002eaba8");
Q16* func_002eaba8(Q16* ret, u32, u8* o) {
    Q16 t;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&t), "r"(o + 16), "f"(D_00363440) : "$8", "memory");
    if (ret != &t) QCOPY(ret, &t);
    return ret;
}
}  // namespace n002eaba8

// 002eabe8 (from src/anon/batch_w60.cpp)
namespace n002eabe8 {
// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
extern f32 D_00363450 asm("D_00363450");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017c030(void*, void*, void*, u8) asm("func_0017c030");
void func_0017c4c8(void*, void*) asm("func_0017c4c8");
// 0x002c5418: definition moved into src/anon/unit_002c53c8.cpp

void func_002eabe8(void* self, u8* o, u8 c) asm("func_002eabe8");
void func_002eabe8(void* self, u8* o, u8 c) {
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    s32 k;
    func_0017c030(v, o, &k, c);
    v[3] *= D_00363450;
    QCOPY(w, v);
    func_0017c4c8(o, w);
    o[1300] = 7;
    func_0017f488(o + 320, k, 0.0f, 0.0f);
    *(s32*)(o + 256) = 4;
    *(s32*)(o + 260) = 5;
}
}  // namespace n002eabe8

// 002eac70 (from src/anon/batch_w1.cpp)
namespace n002eac70 {
extern f32 D_00363440 asm("D_00363440");
extern f32 D_00363448 asm("D_00363448");
extern f32 D_0036344c asm("D_0036344c");
extern f32 D_00363450 asm("D_00363450");
void func_002eac70(f32 a, f32 b, f32 c, f32 d) asm("func_002eac70");
void func_002eac70(f32 a, f32 b, f32 c, f32 d) {
    D_00363440 = a;
    D_00363448 = b;
    D_0036344c = c;
    D_00363450 = d;
}
}  // namespace n002eac70

// 002eac98 (from src/anon/tiny_wrappers_more.cpp)
namespace n002eac98 {
u32 func_002eaab0(u32, u32, u32, u32) asm("func_002eaab0");
u32 func_002eac98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002eac98");
u32 func_002eac98(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002eaab0(a1, a2, a2, a3);
}
}  // namespace n002eac98

namespace n002eacb8 {
void func_002eaaf0(u8*) asm("func_002eaaf0");
void func_002eacb8(void*, u8* o) asm("func_002eacb8");
void func_002eacb8(void*, u8* o) { func_002eaaf0(o); }
}  // namespace n002eacb8

// 002eacd0 (from src/anon/tiny_wrappers_more.cpp)
namespace n002eacd0 {
u32 func_0017cc30(u32, u32, u32, u32) asm("func_0017cc30");
u32 func_002eacd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002eacd0");
u32 func_002eacd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0017cc30(a0, a1, 0x0000002bu, a3);
}
}  // namespace n002eacd0

// 002eace8 (from src/anon/tiny_wrappers_more.cpp)
namespace n002eace8 {
u32 func_002eaab0(u32, u32, u32, u32) asm("func_002eaab0");
u32 func_002eace8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002eace8");
u32 func_002eace8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002eaab0(a1, a2, a2, a3);
}
}  // namespace n002eace8

namespace n002ead08 {
void func_002eaaf0(u8*) asm("func_002eaaf0");
void func_002ead08(void*, u8* o) asm("func_002ead08");
void func_002ead08(void*, u8* o) { func_002eaaf0(o); }
}  // namespace n002ead08

// 002ead20 (from src/anon/batch_w2.cpp)
namespace n002ead20 {
typedef void (*VFn3)(void*, u32, u32);
void func_002ead20(void** o, u32 a1) asm("func_002ead20");
void func_002ead20(void** o, u32 a1) {
    ((VFn3*)*o)[9](o, a1, 43);
}
}  // namespace n002ead20

// 002ead48 (from src/anon/batch_w201.cpp)
namespace n002ead48 {
void wtarget_002ead48(u32, u32, u32, u32) asm("_Z16wtarget_002ead48jjjj");
extern f32 D_00363448 asm("D_00363448");
// 00159728: static initialiser, now made by gcc in src/anon/unit_00159240.cpp
void wtarget_002ead48(u32 a, u32 b, u32, u32) asm("_Z16wtarget_002ead48jjjj");
void wtarget_002ead48(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_00363448 = 0.392699063f; }
}  // namespace n002ead48

// 002ead78 (from src/anon/tiny_wrappers_more.cpp)
namespace n002ead78 {
u32 func_002ead48(u32, u32, u32, u32) asm("func_002ead48");
u32 func_002ead78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002ead78");
u32 func_002ead78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ead48(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002ead78

