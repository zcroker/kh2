// Linked unit 0x2cac58-0x2cb200: worldmap::CloseUpCamera (C2/C1 ctor, update, D2/D1/D0, start, end),
// the static init of its two angles and the _GLOBAL__I_ stub. The vtable (0x361e60), the instance
// pointer (0x361e50) and the angles (.bss 0x1e2be10) stay retail data.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 002cac58: C2 copy of the ctor at 0x2cae60 (never written before). It inlines the member
// ctor at +84 (one zero store) where C1 calls the out-of-line copy 0x31cc28.
namespace n002cac58 {
struct VecE {
    f32 x, y, z, w;
    VecE() {}
    VecE(f32 a, f32 b, f32 c, f32 e) { x = a; y = b; z = c; w = e; }
    VecE operator+(const VecE& o) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    VecE operator*(f32 s) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    VecE& operator=(const VecE& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct PairE { VecE a; VecE b; };
struct ObjE { void* vt; u8 pad[44]; VecE p48; VecE p64; u8 pad2[4]; u8 m84[8]; f32 f5c; f32 f60; };
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361e60[] asm("D_00361e60");
extern ObjE* D_00361e50 asm("D_00361e50");
extern f32 D_01e2be10 asm("D_01e2be10");
extern f32 D_01e2be14 asm("D_01e2be14");
void func_0031cc28(void*) asm("func_0031cc28");
void func_002c6420(ObjE*) asm("func_002c6420");
void func_001903d0(s32*, PairE*) asm("func_001903d0");
s32 func_00106a18(s32) asm("func_00106a18");
f32 func_001070a0(s32) asm("func_001070a0");
s32 func_0016a020(s32) asm("func_0016a020");
void func_00162058(f32) asm("func_00162058");
static inline f32 normE(VecE* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

void func_002cac58(ObjE* self, s32* a1, VecE* a2, f32 f) asm("func_002cac58");
void func_002cac58(ObjE* self, s32* a1, VecE* a2, f32 f) {
    PairE pr;
    f32 z0 = 0.0f;
    VecE d;
    VecE v;
    *(u32*)self->m84 = 0;
    self->vt = D_00361da8;
    *(u32*)&self->f5c = 0;
    func_002c6420(self);
    *(u32*)&pr.a.w = 0;
    self->vt = D_00361e60;
    D_00361e50 = self;
    func_001903d0(a1, &pr);
    d.x = z0;
    d.y = -pr.a.z;
    d.z = -pr.a.y;
    d.w = z0;
    f32 len = normE(&d);
    f32 s = len * a2->z;
    f32 k = s / func_001070a0(func_00106a18(1));
    v.x = a2->x * k;
    v.y = a2->y * k;
    v.z = z0;
    v.w = z0;
    VecE& r = (self->p64 = pr.b + v);
    self->p48 = r + d * s;
    self->p48.x -= a2->x * k;
    if (func_0016a020(*a1) == 1110) self->f60 = D_01e2be14; else self->f60 = D_01e2be10;
    if (f == 0.0f) func_00162058(8.0f);
    self->f5c = f;
}
}  // namespace n002cac58

// ---- 002cae60 (from batch_w2000_nsa.cpp)
namespace n002cae60 {
struct VecE {
    f32 x, y, z, w;
    VecE() {}
    VecE(f32 a, f32 b, f32 c, f32 e) { x = a; y = b; z = c; w = e; }
    VecE operator+(const VecE& o) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    VecE operator*(f32 s) const {
        VecE r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    VecE& operator=(const VecE& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct PairE { VecE a; VecE b; };
struct ObjE { void* vt; u8 pad[44]; VecE p48; VecE p64; u8 pad2[4]; u8 m84[8]; f32 f5c; f32 f60; };
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361e60[] asm("D_00361e60");
extern ObjE* D_00361e50 asm("D_00361e50");
extern f32 D_01e2be10 asm("D_01e2be10");
extern f32 D_01e2be14 asm("D_01e2be14");
void func_0031cc28(void*) asm("func_0031cc28");
void func_002c6420(ObjE*) asm("func_002c6420");
void func_001903d0(s32*, PairE*) asm("func_001903d0");
s32 func_00106a18(s32) asm("func_00106a18");
f32 func_001070a0(s32) asm("func_001070a0");
s32 func_0016a020(s32) asm("func_0016a020");
void func_00162058(f32) asm("func_00162058");
static inline f32 normE(VecE* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

void func_002cae60(ObjE* self, s32* a1, VecE* a2, f32 f) asm("func_002cae60");
void func_002cae60(ObjE* self, s32* a1, VecE* a2, f32 f) {
    PairE pr;
    f32 z0 = 0.0f;
    VecE d;
    VecE v;
    self->vt = D_00361da8;
    func_0031cc28(self->m84);
    *(u32*)&self->f5c = 0;
    func_002c6420(self);
    *(u32*)&pr.a.w = 0;
    self->vt = D_00361e60;
    D_00361e50 = self;
    func_001903d0(a1, &pr);
    d.x = z0;
    d.y = -pr.a.z;
    d.z = -pr.a.y;
    d.w = z0;
    f32 len = normE(&d);
    f32 s = len * a2->z;
    f32 k = s / func_001070a0(func_00106a18(1));
    v.x = a2->x * k;
    v.y = a2->y * k;
    v.z = z0;
    v.w = z0;
    VecE& r = (self->p64 = pr.b + v);
    self->p48 = r + d * s;
    self->p48.x -= a2->x * k;
    self->f60 = func_0016a020(*a1) == 1110 ? D_01e2be14 : D_01e2be10;
    if (f == 0.0f) func_00162058(8.0f);
    self->f5c = f;
}
}  // namespace n002cae60

// ---- 002cb070: per-frame update: copy the target fov, then the base camera update (never written before)
namespace n002cb070 {
struct NoTail { ~NoTail() {} };
s32 func_002c6490(u8*) asm("func_002c6490");
void func_002cb070(u8* p) asm("func_002cb070");
void func_002cb070(u8* p) {
    NoTail nt;
    *(f32*)(p + 80) = *(f32*)(p + 96);
    func_002c6490(p);
}
}  // namespace n002cb070

// ---- 002cb090 / 002cb0a8: D2 / D1 dtors (never written before; the D0 at 0x2cb0c0 without the free)
namespace n002cb090 {
extern u8 D_00360000 asm("D_00360000");
extern u8 D_00361da8 asm("D_00361da8");
void func_002cb090(u32 a0) asm("func_002cb090");
void func_002cb090(u32 a0) {
    *(u32*)((u32)((u32)&D_00360000) + 7760u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
}
void func_002cb0a8(u32 a0) asm("func_002cb0a8");
void func_002cb0a8(u32 a0) {
    *(u32*)((u32)((u32)&D_00360000) + 7760u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
}
}  // namespace n002cb090

// ---- 002cb0c0 (from tiny_wrappers_more80_relaxed.cpp)
namespace n002cb0c0 {
u32 func_00105110(u32, u32, u32, u32) asm("func_00105110");
extern u8 D_00360000 asm("D_00360000");
extern u8 D_00361da8 asm("D_00361da8");


u32 func_002cb0c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002cb0c0");
u32 func_002cb0c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)((u32)&D_00360000) + 7760u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n002cb0c0

// ---- 002cb0e8 (from auto80_199_queue.cpp)
namespace n002cb0e8 {


void func_002cb0e8(u32 a0, u32 a1, f32 a2) asm("func_002cb0e8");
void func_002cb0e8(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;

    func_002cb160(s1);

    u32 s0 = func_001050d8(112);
    func_002cae60(f20, s0, s1, s2);

    u32 v0 = func_002c6218();
    func_002c6228(v0, 2, s0);
}
}  // namespace n002cb0e8

// ---- 002cb160: worldmap::CloseUpCamera::end (from batch_w5.cpp)
namespace n002cb160 {
u32 func_002c6218(void) asm("func_002c6218");
void func_002c6280(u32, u32) asm("func_002c6280");
void worldmap_closeup_end(void) asm("_ZN8worldmap13CloseUpCamera3endEv");
void worldmap_closeup_end(void) {
    func_002c6280(func_002c6218(), 2);
}
}  // namespace n002cb160

// ---- 002cb188: static init of the two close-up angles (65 and 105 degrees) (from batch_w51.cpp)
namespace n002cb188 {
extern f32 D_01e2be10 asm("D_01e2be10");
extern f32 D_01e2be14 asm("D_01e2be14");
void wtarget_002cb188(u32, u32, u32, u32) asm("_Z16wtarget_002cb188jjjj");
void wtarget_002cb188(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) D_01e2be10 = 1.1344639f;
    if (b == 0xffff && a == 1) D_01e2be14 = 1.8325956f;
}
}  // namespace n002cb188

// ---- 002cb1e0 (from tiny_wrappers_more.cpp)
namespace n002cb1e0 {
u32 func_002cb188(u32, u32, u32, u32) asm("func_002cb188");


u32 func_002cb1e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002cb1e0");
u32 func_002cb1e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002cb188(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002cb1e0

