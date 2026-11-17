// Linked unit 0x1c8e80-0x1c91c8: the file after mutex.cpp. Its vtable is at 0x351ed0 (gap methods
// 0x1c8f68 and 0x1c8fc0 written here). No .rodata; the next file (vtable 0x351f08) starts at 0x1c91c8.

#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"

// ---- 001c8e80 from src/anon/tiny.cpp
namespace n001c8e80 {
void func_001c8e80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c8e80jjjj");
void func_001c8e80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-26248)) = (u32)a0;
}
}  // namespace n001c8e80

// ---- 001c8e90 from src/anon/tiny_auto80_queue.cpp
namespace n001c8e90 {
extern u8  D_0032fcc9 asm("D_0032fcc9");
void func_001c8ec0(...) asm("func_001c8ec0");
void func_001c8e90() asm("_Z13func_001c8e90v");
void func_001c8e90() {
    u8 t6 = D_0032fcc9;
    if (t6 == 0) {
        return;
    }
    func_001c8ec0((u32)t6);
}
}  // namespace n001c8e90

// ---- 001c8ec0 from src/anon/batch_wcx.cpp
namespace n001c8ec0 {
struct Bits { u32 a, b; u64 on; u64 off; };
extern u8* D_01d49978 asm("D_01d49978");
extern u8 D_00321058[] asm("D_00321058");
Bits* func_002fd248(u32, u8*, u32, s32, u8*) asm("func_002fd248");
void func_0015ee90(s32) asm("func_0015ee90");
void func_0015ee10(s32) asm("func_0015ee10");
void func_001c8ec0(u32 a0) asm("func_001c8ec0");
void func_001c8ec0(u32 a0)
{
    Bits* b = func_002fd248(a0, D_01d49978 + 8, *(u32*)(D_01d49978 + 4), 24, D_00321058);
    for (s32 i = 0; i < 64; i++) {
        if ((u8)((b->on >> i) & 1)) func_0015ee90(i);
        else if ((u8)((b->off >> i) & 1)) func_0015ee10(i);
    }
}
}  // namespace n001c8ec0

// ---- 001c8f68 gap: vtable 0x351ed0 slot 0
namespace n001c8f68 {
s32 func_0019c090(u8*) asm("func_0019c090");
u8* func_0016c028(u8*) asm("func_0016c028");
void func_0019fb70(void*, u8*) asm("func_0019fb70");
void func_001c8f68(void* self, u8* o) asm("func_001c8f68");
void func_001c8f68(void* self, u8* o) {
    if (func_0019c090(o) == 0) {
        *(f32*)(o + 224) = *(f32*)(func_0016c028(o) + 4);
    }
    func_0019fb70(self, o);
}
}  // namespace n001c8f68

// ---- 001c8fc0 gap: vtable 0x351ed0 slot 5, calls slot 9 of the object with 10
namespace n001c8fc0 {
struct VObj;
typedef void (*VFn8fc0)(VObj*, u8*, s32);
struct VObj { VFn8fc0* vt; };
void func_001c8fc0(VObj* self, u8* o) asm("func_001c8fc0");
void func_001c8fc0(VObj* self, u8* o) {
    struct NoTail { ~NoTail() {} } n;
    self->vt[9](self, o, 10);
}
}  // namespace n001c8fc0

// ---- 001c8fe8 from src/anon/batch_w1774.cpp
namespace n001c8fe8 {
struct W1774Vec {
    f32 x, y, z, w;
    W1774Vec() {}
    W1774Vec& operator=(const W1774Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1774Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(void*);
};
W1774Vec func_0019fbe0r(void) asm("func_0019fbe0");
s32 func_001b2d10(void*, W1774Vec*) asm("func_001b2d10");
W1774Vec* func_001c8fe8(W1774Vec* r, W1774Obj* o, void* x) asm("func_001c8fe8");
W1774Vec* func_001c8fe8(W1774Vec* r, W1774Obj* o, void* x) {
    W1774Vec t;
    *r = func_0019fbe0r();
    if (r->y > 0.0f) {
        if (func_001b2d10(x, r)) o->v5(x);
    }
    return r;
}
}  // namespace n001c8fe8

// ---- 001c9080 from src/anon/batch_w13.cpp
namespace n001c9080 {
struct Q128 { u32 w[4]; };
void func_0017c4c8(void*, void*) asm("func_0017c4c8");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void func_001c9080(void* a0, void* a1, Q128* a2) asm("func_001c9080");
void func_001c9080(void* a0, void* a1, Q128* a2) {
    Q128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(a2) : "$8", "memory");
    func_0017c4c8(a1, &t);
    func_0016bd60(a1, 20);
}
}  // namespace n001c9080

// ---- 001c90c0 from src/anon/batch_w7.cpp
namespace n001c90c0 {
void func_0017c430(u32) asm("func_0017c430");
void func_0016bd60(u32, u32) asm("func_0016bd60");
void func_001c90c0(u32 a0, u32 a1) asm("func_001c90c0");
void func_001c90c0(u32 a0, u32 a1) {
    func_0017c430(a1);
    func_0016bd60(a1, 20);
}
}  // namespace n001c90c0

// ---- 001c90f0 from src/anon/tiny_more.cpp
namespace n001c90f0 {
u32 func_001c90f0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001c90f0jjjj");
u32 func_001c90f0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a1 + (340))) + (-201)); return (v < (u32)4); }
}  // namespace n001c90f0

// ---- 001c9100 from src/anon/tiny.cpp
namespace n001c9100 {
u32 func_001c9100(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c9100jjjj");
u32 func_001c9100(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a2;
    (void)a3;
    return ((*(u32*)((u32)a1 + (340)) ^ 0x00c3u) == 0);
}
}  // namespace n001c9100

// ---- 001c9110 from src/anon/auto80_199_queue.cpp
namespace n001c9110 {
u32 func_001c9110(u32 a0, u32 a1) asm("_Z13func_001c9110jj");
u32 func_001c9110(u32 a0, u32 a1) {
    u32 s16 = a1;
    u32 s17 = a0;

    if (func_001c90f0(s17, s16) == 0 && func_001c9100(s17, s16) == 0 && func_0017fd20(s16 + 320) == 0) {                  
        return func_0016bd60(s16, 0);
    }

    if (func_001c9100(s17, s16) != 0) {
        u32 t = *(u32*)(s16 + 2884);
        if ((*(u32*)(t + 8) & 4) == 0) {
            return func_0016bd60(s16, 0);
        }
    }

    u32 vt = *(u32*)s16;
    u32 fn_addr = *(u32*)(vt + 64);
    Fn001c9110 fn = (Fn001c9110)fn_addr;
    u32 r = fn(s16);
    if (r != 0) {
        return r;
    }
    return func_0016bd60(s16, 0);
}
}  // namespace n001c9110

