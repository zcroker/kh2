// Linked unit 0x002de3c8-0x002e18f8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002de3c8 (was never written: gap function)
namespace n002de3c8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002de3c8(u8* o) asm("func_002de3c8");
void func_002de3c8(u8* o) { func_002d0070(o); }
}  // namespace n002de3c8

// 002de3e0 (was src/anon/batch_w258.cpp)
namespace n002de3e0 {
struct V4w258 {
    f32 x, y, z, w;
    V4w258() {}
    V4w258(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V4w258& operator=(const V4w258& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4w258 operator-(const V4w258& b) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V4w258 operator*(f32 k) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "f"(k) : "$8", "memory");
        return d;
    }
    f32 len() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Box3w258 { f32 mn[3]; f32 mx[3]; };
// 0x002c1200: definition moved into src/anon/unit_002c10e0.cpp

void Aabbox_init(Box3w258*) asm("_ZN2dk6Aabbox4initEv");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_001b7c80(void*, Box3w258*) asm("func_001b7c80");
V4w258* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
void func_002de500(u8*, V4w258*) asm("func_002de500");
void wtarget_002cf280(u8*, s32, s32) asm("_Z16wtarget_002cf280jjjj");
/*TARGET 002de3e0*/
void func_002de3e0(u8* p) asm("func_002de3e0");
void func_002de3e0(u8* p) {
    V4w258 t;
    func_0016ac38(p, 0, 1, 0, 0);
    if (*(void**)(p + 1296) != 0) {
        Box3w258 b;
        Aabbox_init(&b);
        func_001b7c80(*(void**)(p + 1296), &b);
        V4w258 c(b.mn[0] + b.mx[0], b.mn[1] + b.mx[1], b.mn[2] + b.mx[2], 0.0f);
        t = c * 0.5f;
    } else {
        t = *func_0016c028(p);  // obj_get_attach_or_alt
    }
    t.z = 0.0f;
    func_002de500(p, &t);
    wtarget_002cf280(p + 2800, 4, 0);
    wtarget_002cf280(p + 2800, 0x4000, 0);
}
}  // namespace n002de3e0

// 002de500 (was src/anon/batch_w283.cpp)
namespace n002de500 {
struct W283_V4 {
    f32 x, y, z, w;
    W283_V4& operator=(const W283_V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W283_JCfg { u8 pad[188]; f32 step; f32 f192; f32 f196; f32 f200; };
struct W283_JTbl { s16 f0; s16 n; u8 e[1]; };
struct W283_JObj { u8 pad[64]; f32 f64; u8 pad2[28]; f32 f96, f100, f104; u8 pad3[4]; W283_V4 pos; u8 pad4[32]; f32 ang; u8 pad5[4]; f32 f168; f32 f172; u8 pad6[4]; f32 f180; };
extern void* D_00361f60 asm("D_00361f60");
W283_JCfg* W283_MGJump_config(void*) asm("_ZN2Ti6MGJump6configEv");
W283_JTbl* func_002dd650(void*) asm("func_002dd650");
W283_JObj* func_001cbeb8(W283_V4*, u32) asm("func_001cbeb8");
/*TARGET 002de500*/
void func_002de500(void* self, W283_V4* pos) asm("func_002de500");
void func_002de500(void* self, W283_V4* pos) {
    void* mg = D_00361f60;
    if (mg == 0) return;
    W283_JCfg* cfg = W283_MGJump_config(mg);
    f32* p188 = &cfg->step;
    f32* p192 = &cfg->f192;
    f32* p196 = &cfg->f196;
    W283_JTbl* t = func_002dd650(mg);
    s32 n = t->n;
    for (s32 j = 0; j < n; j++) {
        f32 y = (f32)j * *p188;
        u32 kind = ((u8*)t)[4 + j * 2];
        s32 cnt = ((u8*)t)[5 + j * 2];
        for (s32 i = 0; i < cnt; i++) {
            W283_JObj* o = func_001cbeb8(pos, kind);
            if (o == 0) continue;
            f32 a = (f32)i * 6.2831855f / (f32)cnt - 3.1415927f;
            o->pos = *pos;
            o->ang = a;
            o->f168 = *p196;
            o->f172 = 0.0f;
            o->f180 = *p192;
            o->f96 = y;
            o->f100 = 120.0f;
            o->f104 = p188[3];
            o->f64 = 0.0f;
        }
    }
}
}  // namespace n002de500

// 002de698 (was src/anon/batch_w33.cpp)
namespace n002de698 {
// 0x002db928: definition moved into src/anon/unit_002da040.cpp

extern void* D_00361f60 asm("D_00361f60");
void func_002cf280(void*, s32, s32) asm("func_002cf280");
u8* func_002dc7c8(void*) asm("func_002dc7c8");
/*TARGET 002de698*/
void func_002de698(u8* p) asm("func_002de698");
void func_002de698(u8* p) {
    void* m = D_00361f60;
    func_002cf280(p + 2800, 8, 0);
    *(f32*)(p + 3060) = *(f32*)(func_002dc7c8(m) + 172);
}
}  // namespace n002de698

// 002de6e8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002de6e8 {
u32 func_0016bc20(...) asm("func_0016bc20");
void func_0018a818(...) asm("func_0018a818");
/*TARGET 002de6e8*/
// 0x002dd4a8: definition moved into src/anon/unit_002da040.cpp

f32 func_002de6e8(u32 a0) asm("_Z13func_002de6e8j");
// 0x002dd4a8: definition moved into src/anon/unit_002da040.cpp

f32 func_002de6e8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_0016bc20(a0, 2, 0xffffffffu);

    u32 w[6];
    w[3] = 0;
    func_0018a818((u32)w, s0, v0);

    return *(f32*)&w[5] - *(f32*)&w[2];
}
}  // namespace n002de6e8

// 002de738 (was src/anon/tiny_auto80_queue.cpp)
namespace n002de738 {
/*TARGET 002de738*/
u32 func_002de738(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002de738jjjjjjjj");
u32 func_002de738(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2808));
    r2 = (u32)((s32)0u + (-1));
    if (r15 != 0u) {
        r2 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(22)));
    }
    return r2;
}
}  // namespace n002de738

// 002de750 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002de750 {
u32 func_002cfeb0(u32, u32, u32, u32) asm("_Z13func_002cfeb0jjjj");
extern u8 D_00362ad8 asm("D_00362ad8");
/*TARGET 002de750*/
u32 func_002de750(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002de750jjjj");
u32 func_002de750(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = 0u;
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002de750

// 002de788 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002de788 {
u32 func_002cfeb0(u32, u32, u32, u32) asm("_Z13func_002cfeb0jjjj");
extern u8 D_00362ad8 asm("D_00362ad8");
/*TARGET 002de788*/
u32 func_002de788(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002de788jjjj");
u32 func_002de788(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_ctor_arg
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = r6;
    r6 = 0u;
    r16 = r4;
    r2 = func_002cfeb0(r4, r5, r6, r7);  // obj_init_field1416_bit800
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002de788

// 002de7c0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002de7c0 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362ad8 asm("D_00362ad8");
/*TARGET 002de7c0*/
u32 func_002de7c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002de7c0jjjj");
u32 func_002de7c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002de7c0

// 002de7e8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002de7e8 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362ad8 asm("D_00362ad8");
/*TARGET 002de7e8*/
u32 func_002de7e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002de7e8jjjj");
u32 func_002de7e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362ad8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002de7e8

// 002de810 (was src/anon/batch_w13.cpp)
namespace n002de810 {
void func_00105110(void*) asm("func_00105110");
void func_002cff98(void*) asm("func_002cff98");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_00362ad8 asm("D_00362ad8");
/*TARGET 002de810*/
// 0x002cd910: definition moved into src/taito/path.cpp

void func_002de810(void** p) asm("func_002de810");
// 0x002cd910: definition moved into src/taito/path.cpp

void func_002de810(void** p) {
    *p = &D_00362ad8;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002de810

// 002de848 (was never written: gap function)
namespace n002de848 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002de848(u8* p) asm("func_002de848");
void func_002de848(u8* p) {
    func_002d00a0(p);
    func_0016bd60(p, 3);
    *(u32*)(p + 264) |= 1;
}
}  // namespace n002de848

// 002de888 (was src/anon/auto80_199_queue.cpp)
namespace n002de888 {
/*TARGET 002de888*/
void func_002de888(u32 a0) asm("_Z13func_002de888j");
void func_002de888(u32 a0) {
    func_00187750(a0);
    if (func_001c0cd8(a0) != 0) {
        return;
    }
    u32 v = D_0034e948;
    if (v == 0) {
        return;
    }
    func_001c0d38(a0, v, 67, 0);
}
}  // namespace n002de888

// 002de8e8 (was src/anon/batch_w62.cpp)
namespace n002de8e8 {
// 00188170: moved to src/anon/unit_00185d10.cpp

s32 func_001c0cd8(u8*) asm("func_001c0cd8");
// 0x002d3f18: definition moved into src/anon/unit_002d2498.cpp

void func_00198690(u8*) asm("func_00198690");
void func_0016b070(u8*, f32*) asm("func_0016b070");
void func_0016ace0(u8*, f32*) asm("func_0016ace0");
/*TARGET 002de8e8*/
void func_002de8e8(u8* p) asm("func_002de8e8");
void func_002de8e8(u8* p) {
    f32 a[4];
    f32 b[4];
    func_00198690(p);
    if (!func_001c0cd8(p)) return;
    a[1] = a[0] = -1.57079625f;
    a[3] = a[2] = 0.0f;
    func_0016b070(p, a);
    b[3] = b[2] = b[1] = b[0] = 0.0f;
    func_0016ace0(p, b);
}
}  // namespace n002de8e8

// 002de968 (was src/anon/batch_w54.cpp)
namespace n002de968 {
/*TARGET 002de968*/
// 0x002dba40: definition moved into src/anon/unit_002da040.cpp

// wrap an angle into [-pi, pi]
f32 func_002de968(f32 a) asm("func_002de968");
// 0x002dba40: definition moved into src/anon/unit_002da040.cpp

// wrap an angle into [-pi, pi]
f32 func_002de968(f32 a) {  // clamp_angle
    if (a > 0.0f) {
        if (a > 3.1415927f) {
            do a -= 6.2831855f;
            while (a > 3.1415927f);
        }
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}
}  // namespace n002de968

// 002dea00 (was src/anon/batch_w50.cpp)
namespace n002dea00 {
extern u8 D_00362d20[] asm("D_00362d20");
/*TARGET 002dea00*/
// 0x002dc1b8: definition moved into src/anon/unit_002da040.cpp

void func_002dea00(u8* o, f32 a, f32 b) asm("func_002dea00");
// 0x002dc1b8: definition moved into src/anon/unit_002da040.cpp

void func_002dea00(u8* o, f32 a, f32 b) {  // obj_init_with_floats
    *(u32*)(o + 4) = 30;
    *(u32*)(o + 8) = 256;
    *(u8**)o = D_00362d20;
    *(f32*)(o + 12) = b;
    *(f32*)(o + 16) = 10.0f;
    *(f32*)(o + 20) = a;
    *(s32*)(o + 56) = -1;
}
}  // namespace n002dea00

// 002dea40 (was never written: gap function)
namespace n002dea40 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002dea40(C* o, f32 a, f32 b) asm("func_002dea40");
void func_002dea40(C* o, f32 a, f32 b) {
    o->f4 = 30; o->f8 = 256; o->vt = D_00362d20; o->f12 = b; o->f16 = 10.0f; o->f20 = a; o->f56 = -1;
}
}  // namespace n002dea40

// 002dea80 (was src/anon/tiny.cpp)
namespace n002dea80 {
extern u32 D_00362d20 asm("D_00362d20");
/*TARGET 002dea80*/
// 0x002dc7e8: definition moved into src/anon/unit_002da040.cpp

void func_002dea80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dea80jjjj");
// 0x002dc7e8: definition moved into src/anon/unit_002da040.cpp

void func_002dea80(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_362d20
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00362d20;
}
}  // namespace n002dea80

// 002dea90 (was never written: gap function)
namespace n002dea90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002dea90(C* o) asm("func_002dea90");
void func_002dea90(C* o) { o->vt = D_00362d20; }
}  // namespace n002dea90

// 002deaa0 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n002deaa0 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00362d20 asm("D_00362d20");
/*TARGET 002deaa0*/
// 0x00288f48: definition moved into src/anon/unit_00288b00.cpp

u32 func_002deaa0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002deaa0jjjjjjjj");
// 0x00288f48: definition moved into src/anon/unit_00288b00.cpp

u32 func_002deaa0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00362d20;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n002deaa0

// 002deac0 (was src/anon/batch_w214.cpp)
namespace n002deac0 {
// 0x0019fb70: definition moved into src/anon/unit_0019fb70.cpp

extern f32 func_001065a8() asm("func_001065a8");
struct W214O { u8 pad[24]; f32 f; };
/*TARGET 002deac0*/
void func_002deac0(W214O* o, f32 a, f32 b) asm("func_002deac0");
void func_002deac0(W214O* o, f32 a, f32 b) {  // set_float24_scaled
    if (a == b) { asm("" : "+r"(o)); o->f = a; }
    else o->f = func_001065a8();
    o->f = o->f * 0.01f;
}
}  // namespace n002deac0

// 002deb18 (was src/anon/batch_w58.cpp)
namespace n002deb18 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 128-bit copy.
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
// 0x002c1a58: definition moved into src/anon/unit_002c10e0.cpp

void func_002df160(u32) asm("func_002df160");
Vec4* func_0016c028(u32) asm("func_0016c028");
// obj_get_attach_or_alt
f32 func_002df1a0(u32) asm("func_002df1a0");
void func_0016ace0(u32, Vec4*) asm("func_0016ace0");
extern const f32 D_00375d40 asm("D_00375d40");
/*TARGET 002deb18*/
void func_002deb18(u32 a0, u32 a1) asm("func_002deb18");
void func_002deb18(u32 a0, u32 a1) {
    Vec4 v;
    func_002df160(a0);
    cpq(&v, func_0016c028(a1));  // obj_get_attach_or_alt
    f32 r = func_002df1a0(a0);
    v.z = 0;
    v.y = -r * 100.0f - D_00375d40;
    func_0016ace0(a1, &v);
}
}  // namespace n002deb18

// 002deba0 (was src/anon/batch_w1958_nsa.cpp)
namespace n002deba0 {
struct A58b { u8 pad[0x588]; u32 x588; };
struct O58b { u8 pad[0x34]; s32 x34; s32 x38; };
struct V58e {
    f32 x, y, z, w;
    V58e() {}
    V58e& operator=(const V58e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
    }
} __attribute__((aligned(16)));
static inline V58e operator+(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void* func_0016c028(void*) asm("func_0016c028");
void func_002dd2d8(s32, f32*, f32*) asm("func_002dd2d8");
f32 func_00106558(f32) asm("func_00106558");
extern s32 D_00361f60 asm("D_00361f60");
extern void* D_0034e948 asm("D_0034e948");
/*TARGET 002deba0*/
// 0x002c04c8: definition moved into src/anon/unit_002bebd0.cpp

void func_002deba0(O58b* o, A58b* act, f32 a, f32 b) asm("func_002deba0");
// 0x002c04c8: definition moved into src/anon/unit_002bebd0.cpp

void func_002deba0(O58b* o, A58b* act, f32 a, f32 b) {
    f32 lo, hi;
    if (act->x588 & 0x80) return;
    func_002dd2d8(D_00361f60, &lo, &hi);
    lo *= 0.8f;
    hi *= 0.8f;
    f32* p = (f32*)func_0016c028(act);
    if (o->x38 != 0) {
        o->x38 = -1;
        f32 v = func_00106558(1.0f);
        s32 s;
        if (v < a) {
            if (o->x34 <= 0) o->x34 = 1;
            else o->x34 = -1;
            s = o->x38;
        } else if (v < a + b) {
            s = o->x38 = 0;
        } else {
            s = o->x38;
        }
        if (s >= 0) goto L;
        if (o->x34 >= 0) {
            if (hi <= *p) o->x34 = -1;
            if (o->x34 > 0) return;
        }
        if (*p <= lo) o->x34 = 1;
        return;
    }
L:
    {
        f32* q = (f32*)func_0016c028(D_0034e948);
        f32* m = (f32*)func_0016c028(act);
        o->x34 = (*q >= *m) ? 1 : -1;
        if (o->x34 >= 0 && hi <= *p) o->x34 = 0;
        if (o->x34 <= 0 && *p <= lo) o->x34 = 0;
    }
}
}  // namespace n002deba0

// 002ded60 (was never written: gap function)
namespace n002ded60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002ded60(void) asm("func_002ded60");
s32 func_002ded60(void) { return 3; }
}  // namespace n002ded60

// 002ded68 (was never written: gap function)
namespace n002ded68 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002ded68(void) asm("func_002ded68");
s32 func_002ded68(void) { return 4; }
}  // namespace n002ded68

// 002ded70 (was never written: gap function)
namespace n002ded70 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002ded70(void) asm("func_002ded70");
s32 func_002ded70(void) { return 5; }
}  // namespace n002ded70

// 002ded78 (was never written: gap function)
namespace n002ded78 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

V func_002ded78(u8* self, u8* x) asm("func_002ded78");
V func_002ded78(u8* self, u8* x) {
    V r = *(V*)(x + 16);
    r *= r.w;
    r.z = 0.0f;
    return r;
}
}  // namespace n002ded78

// 002deda8 (was src/anon/batch_w2393_nsa.cpp)
namespace n002deda8 {
struct W2393Obj;
void* func_0016c028(void*) asm("func_0016c028");
#define W2393QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2393V {
    f32 x, y, z, w;
    W2393V() {}
    W2393V(const W2393V& o) { W2393QCOPY(this, &o); }
    W2393V& operator=(const W2393V& o) { if (this != &o) W2393QCOPY(this, &o); return *this; }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W2393Ent { u8 pad0[16]; W2393V vel; };
typedef void (*W2393Fn)(W2393Obj*, W2393Ent*, f32);
typedef void (*W2393Fn2)(W2393Obj*, W2393Ent*);
struct W2393Obj { void** vt; u8 pad4[36]; f32 f40; };
extern f32 D_00349e10 asm("D_00349e10");
extern const f32 D_00375d40 asm("D_00375d40");
s32 func_002df198(W2393Obj*) asm("_Z13func_002df198Pv");
f32 func_002df1a0(W2393Obj*) asm("_Z13func_002df1a0Pv");
f32 func_002df1a8(W2393Obj*, f32) asm("func_002df1a8");
/*TARGET 002deda8*/
/* 002deda8: scales the entity velocity by its w, snaps x to the height from func_002df1a8 (two
   paths, kept apart so cross-jumping only merges from the v.x store on), then recomputes y and
   renormalises the velocity, keeping its length in w. */
void func_002deda8(W2393Obj* self, W2393Ent* e) asm("func_002deda8");
/* 002deda8: scales the entity velocity by its w, snaps x to the height from func_002df1a8 (two
   paths, kept apart so cross-jumping only merges from the v.x store on), then recomputes y and
   renormalises the velocity, keeping its length in w. */
void func_002deda8(W2393Obj* self, W2393Ent* e) {
    W2393V* pos = (W2393V*)func_0016c028(e);
    W2393V v = e->vel;
    v.scale(v.w);
    f32 old = self->f40;
    if (func_002df198(self)) {
        f32 h = func_002df1a8(self, pos->x);
        v.x = h - pos->x;
        ((W2393Fn)self->vt[9])(self, e, h);
    } else {
        f32 t = pos->x + v.x;
        t = func_002df1a8(self, t);
        v.x = t - pos->x;
        ((W2393Fn)self->vt[9])(self, e, t);
    }
    if (old >= 0.0f && self->f40 < 0.0f) ((W2393Fn2)self->vt[14])(self, e);
    f32 g = func_002df1a0(self);
    v.y = (-g * 100.0f - D_00375d40 - pos->y) / D_00349e10;
    v.z = 0.0f;
    e->vel = v;
    f32 len = e->vel.length();
    e->vel.normalize();
    e->vel.w = len;
}
}  // namespace n002deda8

// 002def70 (was src/anon/auto80_199_queue.cpp)
namespace n002def70 {
/*TARGET 002def70*/
void func_002def70(u32 a0, u32 a1) asm("_Z13func_002def70jj");
void func_002def70(u32 a0, u32 a1) {
    u32 a = a1 + 320;
    f32 z = 0.0f;

    u32 v = call_vt_48(a0);
    ((u32(*)(u32, u32, f32, f32))func_0017f488)(a, v, z, z);

    v = call_vt_40(a0);
    ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(a, v, 0, z, z);
}
}  // namespace n002def70

// 002deff0 (was never written: gap function)
namespace n002deff0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002deff0(void*** o, u8* p) asm("func_002deff0");
void func_002deff0(void*** o, u8* p) {
    u8* m = p + 320;
    u32 v = ((u32 (*)(void*))(*o)[11])(o);
    func_0017f488(m, v, 8.0f, 0.0f);
}
}  // namespace n002deff0

// 002df038 (was never written: gap function)
namespace n002df038 {
void func_002df038(void) asm("func_002df038");
void func_002df038(void) {}
}  // namespace n002df038

// 002df040 (was src/anon/batch_w1552.cpp)
namespace n002df040 {
struct V4_df040 {
    f32 x, y, z, w;
    V4_df040() {}
    V4_df040(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    V4_df040(const V4_df040& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4_df040& operator=(const V4_df040& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
void func_0016aef0(u8*, V4_df040*) asm("func_0016aef0");
V4_df040* func_0016c028(u8*) asm("func_0016c028");
void func_0016ace0(u8*, V4_df040*) asm("func_0016ace0");
void func_002deda8(u8*, u8*) asm("func_002deda8");
/*TARGET 002df040*/
void func_002df040(u8* a0, u8* a1) asm("func_002df040");
void func_002df040(u8* a0, u8* a1) {
    V4_df040 v(0.0f, 0.0f, -1.0f, 0.0f);
    func_0016aef0(a1, &v);
    v = *func_0016c028(a1);
    v.z = *(f32*)(a0 + 0x14);
    func_0016ace0(a1, &v);
    func_002deda8(a0, a1);
}
}  // namespace n002df040

// 002df0d0 (was never written: gap function)
namespace n002df0d0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002df0d0(void) asm("func_002df0d0");
void func_002df0d0(void) {}
}  // namespace n002df0d0

// 002df0d8 (was src/anon/batch_w48.cpp)
namespace n002df0d8 {
// 0x002bcbf0: definition moved into src/anon/unit_002bc978.cpp

struct VObj { s32 (**vt)(VObj*); };
/*TARGET 002df0d8*/
s32 func_002df0d8(VObj* o, u8* b) asm("func_002df0d8");
s32 func_002df0d8(VObj* o, u8* b) {
    u8* s = b + 320;
    s32 x = *(s32*)(s + 20);
    s32 r = 0;
    if (x != ((s32 (*)(VObj*))(((void**)o->vt)[12]))(o)) {
        if (*(f32*)(s + 48) >= 8.0f) r = 1;
    }
    return r;
}
}  // namespace n002df0d8

// 002df140 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002df140 {
u32 func_002dc7e8(u32, u32, u32, u32) asm("_Z13func_002dc7e8jjjj");
/*TARGET 002df140*/
// 0x002be408: definition moved into src/anon/unit_002be020.cpp

u32 func_002df140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002df140jjjj");
// 0x002be408: definition moved into src/anon/unit_002be020.cpp

u32 func_002df140(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(8032));
    return func_002dc7e8(r4, r5, r6, r7);
}
}  // namespace n002df140

// 002df160 (was src/anon/batch_w21.cpp)
namespace n002df160 {
/*TARGET 002df160*/
// 0x002db8e8: definition moved into src/anon/unit_002da040.cpp

void func_002df160(f32* p) asm("func_002df160");
// 0x002db8e8: definition moved into src/anon/unit_002da040.cpp

void func_002df160(f32* p) {
    p[8] = 0.0f;
    f32 a = p[6];
    f32 b = p[8];
    ((u8*)p)[48] = 0;
    ((u8*)p)[49] = 0;
    p[7] = a;
    p[10] = b;
    p[9] = a;
    p[11] = b;
}
}  // namespace n002df160

// 002df188 (was never written: gap function)
namespace n002df188 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

f32 func_002df188(u8* o) asm("func_002df188");
f32 func_002df188(u8* o) { return *(f32*)(o + 24); }
}  // namespace n002df188

// 002df190 (was never written: gap function)
namespace n002df190 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

f32 func_002df190(u8* o) asm("func_002df190");
f32 func_002df190(u8* o) { return *(f32*)(o + 40); }
}  // namespace n002df190

// 002df198 (was src/anon/misc_2.cpp)
namespace n002df198 {
/*TARGET 002df198*/
// 0x002d9208: definition moved into src/anon/unit_002d6f70.cpp

u8 func_002df198(void* self) asm("_Z13func_002df198Pv");
// 0x002d9208: definition moved into src/anon/unit_002d6f70.cpp

u8 func_002df198(void* self) { return (u8)(*(u8*)((char*)self + 48)); }
}  // namespace n002df198

// 002df1a0 (was src/anon/misc_2.cpp)
namespace n002df1a0 {
/*TARGET 002df1a0*/
f32 func_002df1a0(void* self) asm("_Z13func_002df1a0Pv");
f32 func_002df1a0(void* self) { return (f32)(*(f32*)((char*)self + 36)); }
}  // namespace n002df1a0

// 002df1a8 (was src/anon/tiny_wrappers_imp.cpp)
namespace n002df1a8 {
u32 func_002dd348(u32, u32, u32, u32) asm("_Z13func_002dd348jjjj");
/*TARGET 002df1a8*/
u32 func_002df1a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002df1a8jjjj");
u32 func_002df1a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    r4 = *(u32*)((u32)r15 + (s32)(8032));
    return func_002dd348(r4, r5, r6, r7);
}
}  // namespace n002df1a8

// 002df1c8 (was never written: gap function)
namespace n002df1c8 {
struct P;
struct O {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12();
    virtual void land(P*);
    virtual void s14();
    virtual void jump(P*, s32);
    virtual s32 ready(P*, f32);
    virtual void wait(P*, f32, f32, f32);
    u8 pad0[12];
    f32 grav;
    u8 pad1[4];
    f32 top;
    f32 base;
    f32 v0;
    f32 y;
    f32 vel;
    f32 time;
    u8 onGround;
    u8 big;
};
extern f32 D_00349e10 asm("D_00349e10");
extern u8* D_00361f60 asm("D_00361f60");
void* func_002df140(O*) asm("func_002df140");
f32 func_002e51b0(void*, f32) asm("func_002e51b0");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void func_002deac0(O*, f32, f32) asm("func_002deac0");
void func_002deb18(O*, P*) asm("func_002deb18");

struct Q { u8 pad[52]; s32 f52; };
void func_002df1c8(O* o, P* p, f32 x) asm("func_002df1c8");
void func_002df1c8(O* o, P* p, f32 x)
{
    void* fld = func_002df140(o);
    x *= 0.01f;
    f32 h = func_002e51b0(fld, x);
    f32 h1 = func_002e51b0(fld, x + 0.2f);
    f32 h2 = func_002e51b0(fld, x - 0.2f);
    if (h < h1) h = h1;
    if (h < h2) h = h2;
    if (o->onGround) {
        o->wait(p, o->time, x, 0.0f);
        if (o->ready(p, o->time)) {
            f32 d = o->top - o->base;
            o->onGround = 0;
            o->base = h;
            o->y = h;
            o->vel = 0.0f;
            o->time = 0.0f;
            o->v0 = __builtin_sqrtf((o->grav + o->grav) * d);
            o->jump(p, 0);
        } else {
            o->y = h;
            o->time += D_00349e10;
        }
        return;
    }
    f32 t = o->time / 60.0f;
    o->vel = o->v0 - o->grav * t;
    o->y = o->base + o->v0 * t - o->grav * 0.5f * t * t;
    o->time += D_00349e10;
    if (o->vel < 0.0f && o->y <= h) {
        o->y = h;
        o->onGround = 1;
        o->time = 0.0f;
        o->land(p);
        o->big = 0;
    }
}
}  // namespace n002df1c8

// 002df3f0 (was never written: gap function)
namespace n002df3f0 {
struct P;
struct O {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12();
    virtual void land(P*);
    virtual void s14();
    virtual void jump(P*, s32);
    virtual s32 ready(P*, f32);
    virtual void wait(P*, f32, f32, f32);
    u8 pad0[12];
    f32 grav;
    u8 pad1[4];
    f32 top;
    f32 base;
    f32 v0;
    f32 y;
    f32 vel;
    f32 time;
    u8 onGround;
    u8 big;
};
extern f32 D_00349e10 asm("D_00349e10");
extern u8* D_00361f60 asm("D_00361f60");
void* func_002df140(O*) asm("func_002df140");
f32 func_002e51b0(void*, f32) asm("func_002e51b0");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void func_002deac0(O*, f32, f32) asm("func_002deac0");
void func_002deb18(O*, P*) asm("func_002deb18");

struct Q { u8 pad[52]; s32 f52; };
void func_002df3f0(O* o, P* p) asm("func_002df3f0");
void func_002df3f0(O* o, P* p)
{
    u8* g = D_00361f60;
    u8* c = config(g);
    func_002deac0(o, *(f32*)(c + 220), *(f32*)(config(g) + 224));
    func_002deb18(o, p);
    ((Q*)o)->f52 = 1;
}
}  // namespace n002df3f0

// 002df470 (was src/anon/batch_w52.cpp)
namespace n002df470 {
// 0x002d4868: definition moved into src/anon/unit_002d4548.cpp

void func_002def70(u8*, u32) asm("func_002def70");
u8* func_002dc7c8(u32) asm("func_002dc7c8");
void func_002deac0(u8*, f32, f32) asm("func_002deac0");
// set_float24_scaled
void func_002deba0(u8*, u32, f32, f32) asm("func_002deba0");
extern u32 D_00361f60 asm("D_00361f60");
/*TARGET 002df470*/
void func_002df470(u8* p, u32 b) asm("func_002df470");
void func_002df470(u8* p, u32 b) {
    func_002def70(p, b);
    u32 g = D_00361f60;
    u8* a1 = func_002dc7c8(g);
    u8* a2 = func_002dc7c8(g);
    func_002deac0(p, *(f32*)(a1 + 220), *(f32*)(a2 + 224));  // set_float24_scaled
    u8* a3 = func_002dc7c8(g);
    u8* a4 = func_002dc7c8(g);
    func_002deba0(p, b, *(f32*)(a3 + 228), *(f32*)(a4 + 232));
}
}  // namespace n002df470

// 002df500 (was src/anon/batch_w1965.cpp)
namespace n002df500 {
#define W1965bQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965bV {
    f32 x, y, z, w;
    W1965bV() {}
    W1965bV(const W1965bV& o) { W1965bQCOPY(this, &o); }
    W1965bV& operator=(const W1965bV& o) { if (this != &o) W1965bQCOPY(this, &o); return *this; }
    W1965bV operator-(const W1965bV& b) const {
        W1965bV r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1965bV& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1965bPrm { u8 pad[216]; f32 f216; u8 pad2[16]; f32 f236; };
struct W1965bCtl { u8 pad[52]; s32 i52; s32 i56; };
struct W1965bBod { u8 pad[16]; W1965bV vel; };
struct W1965bBodV { u8 pad[16]; f32 vx; u8 pad2[8]; f32 spd; };
extern s32 D_00361f60 asm("D_00361f60");
extern u8* D_0034e948 asm("D_0034e948");
W1965bV* w1965_pos(void*) asm("func_0016c028");
void func_002df040(void) asm("func_002df040");
W1965bPrm* func_002dc7c8(s32) asm("func_002dc7c8");
void func_002dd2d8(s32, f32*, f32*) asm("func_002dd2d8");
/*TARGET 002df500*/
void func_002df500(W1965bCtl* a, W1965bBod* b) asm("func_002df500");
void func_002df500(W1965bCtl* a, W1965bBod* b)
{
    func_002df040();
    s32 id = D_00361f60;
    W1965bV p = *w1965_pos(b);
    W1965bV* vel = &b->vel;
    p.x += func_002dc7c8(id)->f216 * (f32)a->i52;
    f32 lo, hi;
    func_002dd2d8(id, &lo, &hi);
    hi *= 0.95f;
    lo *= 0.95f;
    if (hi < p.x) p.x = hi;
    if (p.x < lo) p.x = lo;
    *vel *= ((W1965bBodV*)b)->spd;
    ((W1965bBodV*)b)->vx = p.x - w1965_pos(b)->x;
    f32 len = vel->length();
    vel->normalize();
    ((W1965bBodV*)b)->spd = len;
    if (a->i56 == 0) {
        W1965bV d = *w1965_pos(D_0034e948) - p;
        f32 dl = d.length();
        if (dl <= func_002dc7c8(id)->f236) a->i56 = 1;
    }
}
}  // namespace n002df500

// 002df6d8 (was src/anon/perm_002df6d8.cpp)
namespace n002df6d8 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
extern s32 D_00361f60 asm("D_00361f60");
extern u8 D_00362c08[] asm("D_00362c08");
s32 func_001b0320(s32) asm("func_001b0320");
u8 *func_002dc7c8(s32) asm("func_002dc7c8");
void func_002e7568(f32, void *, s32, void *) asm("func_002e7568");
typedef struct W
{
  u8 pad[0x9b8];
  s32 h;
} W;
/*TARGET 002df6d8*/
void func_002df6d8(void *a0, W *p) asm("func_002df6d8");
void func_002df6d8(void *a0, W *p)
{
  s32 r;
  u8 *new_var2;
  s32 g = D_00361f60;
  u8 *new_var;
  s32 h;
  r = 0;
  h = p->h;
  new_var2 = D_00362c08;
  if (h)
  {
    r = func_001b0320(h);
  }
  if (!((u8) r))
  {
    new_var = new_var2;
    func_002e7568(((f32 *) func_002dc7c8(g))[0xcc / 4], p, 6, new_var);
  }
}
}  // namespace n002df6d8

// 002df758 (was src/anon/auto80_199_queue.cpp)
namespace n002df758 {
/*TARGET 002df758*/
void func_002df758(u32 a0, u32 a1) asm("_Z13func_002df758jj");
void func_002df758(u32 a0, u32 a1) {
    u32 p = D_00361f60;
    u32 s = func_002dc7c8(p);
    u32 t = func_002dc7c8(p);

    func_002deac0(a0, *(f32*)(s + 244), *(f32*)(t + 248));  // set_float24_scaled
    func_002deb18(a0, a1);
    *(u32*)(a0 + 52) = 0xffffffffu;
}
}  // namespace n002df758

// 002df7d8 (was src/anon/batch_w53.cpp)
namespace n002df7d8 {
extern u32 D_00361f60 asm("D_00361f60");
void func_002def70(u8*) asm("func_002def70");
u8* func_002dc7c8(u32) asm("func_002dc7c8");
void func_002deac0(u8*, f32, f32) asm("func_002deac0");
// set_float24_scaled
void func_002deba0(u8*, u32, f32, f32) asm("func_002deba0");
/*TARGET 002df7d8*/
// 0x002db808: definition moved into src/anon/unit_002da040.cpp

void func_002df7d8(u8* p, u32 b) asm("func_002df7d8");
// 0x002db808: definition moved into src/anon/unit_002da040.cpp

void func_002df7d8(u8* p, u32 b) {
    func_002def70(p);
    u32 s = D_00361f60;
    u8* x1 = func_002dc7c8(s);
    u8* y1 = func_002dc7c8(s);
    func_002deac0(p, *(f32*)(x1 + 244), *(f32*)(y1 + 248));  // set_float24_scaled
    u8* x2 = func_002dc7c8(s);
    u8* y2 = func_002dc7c8(s);
    func_002deba0(p, b, *(f32*)(x2 + 252), *(f32*)(y2 + 256));
}
}  // namespace n002df7d8

// 002df868 (was src/anon/batch_w293.cpp)
namespace n002df868 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void ScaleIn(QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline f32 Length(const QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void Normalize(QWord* v)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "$8", "$f0", "memory");
}
extern u8* D_00361f60 asm("D_00361f60");
extern u8* D_0034e948 asm("D_0034e948");
void func_002df040(u8*, u8*) asm("func_002df040");
QWord* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
u8* func_002dc7c8(u8*) asm("func_002dc7c8");
void func_002dd2d8(u8*, f32*, f32*) asm("func_002dd2d8");
/*TARGET 002df868*/
void func_002df868(u8* s, u8* o) asm("func_002df868");
void func_002df868(u8* s, u8* o)
{
    func_002df040(s, o);
    u8* m = D_00361f60;
    QWord t = *func_0016c028(o);  // obj_get_attach_or_alt
    QWord* d = (QWord*)(o + 16);
    t.v[0] = t.v[0] + *(f32*)(func_002dc7c8(m) + 240) * (f32)*(s32*)(s + 52);
    f32 lo, hi;
    func_002dd2d8(m, &lo, &hi);
    hi *= 0.95f;
    lo *= 0.95f;
    if (hi < t.v[0]) t.v[0] = hi;
    if (t.v[0] < lo) t.v[0] = lo;
    ScaleIn(d, *(f32*)(o + 28));
    *(f32*)(o + 16) = t.v[0] - func_0016c028(o)->v[0];
    f32 len = Length(d);
    Normalize(d);
    *(f32*)(o + 28) = len;
    if (*(s32*)(s + 56) == 0) {
        QWord e = Sub(*func_0016c028(D_0034e948), t);  // obj_get_attach_or_alt
        f32 dist = Length(&e);
        if (dist <= *(f32*)(func_002dc7c8(m) + 260)) *(s32*)(s + 56) = 1;
    }
}
}  // namespace n002df868

// 002dfa40 (was src/anon/perm_002dfa40.cpp)
namespace n002dfa40 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
extern s32 D_00361f60 asm("D_00361f60");
extern u8 D_00362c00[] asm("D_00362c00");
s32 func_001b0320(s32) asm("func_001b0320");
u8 *func_002dc7c8(s32) asm("func_002dc7c8");
void func_002e7568(f32, void *, s32, void *) asm("func_002e7568");
typedef struct W
{
  u8 pad[0x9b8];
  s32 h;
} W;
inline f32 inline_fn(s32 arg0)
{
  return ((f32 *) func_002dc7c8(arg0))[0xcc / 4];
}
/*TARGET 002dfa40*/
void func_002dfa40(void *a0, W *p) asm("func_002dfa40");
void func_002dfa40(void *a0, W *p)
{
  s32 r;
  s32 g = D_00361f60;
  u8 *new_var;
  s32 h;
  r = 0;
  h = p->h;
  new_var = D_00362c00;
  if (h)
  {
    r = func_001b0320(h);
  }
  if (!((u8) r))
  {
    func_002e7568(inline_fn(g), p, 6, new_var);
  }
}
}  // namespace n002dfa40

// 002dfac0 (was src/anon/batch_w212.cpp)
namespace n002dfac0 {
extern void func_002dea00(f32, f32) asm("func_002dea00");
extern u32 D_00362c18 asm("D_00362c18");
/*TARGET 002dfac0*/
void func_002dfac0(u32* t) asm("func_002dfac0");
void func_002dfac0(u32* t) {
    func_002dea00(0.0f, 50.0f);  // obj_init_with_floats
    t[2] |= 0x800;
    t[0] = (u32)&D_00362c18;
}
}  // namespace n002dfac0

// 002dfb10 (was src/anon/batch_w212.cpp)
namespace n002dfb10 {
extern void func_002dea00(f32, f32) asm("func_002dea00");
extern u32 D_00362c18 asm("D_00362c18");
/*TARGET 002dfb10*/
void func_002dfb10(u32* t) asm("func_002dfb10");
void func_002dfb10(u32* t) {
    func_002dea00(0.0f, 50.0f);  // obj_init_with_floats
    t[2] |= 0x800;
    t[0] = (u32)&D_00362c18;
}
}  // namespace n002dfb10

// 002dfb60 (was never written: gap function)
namespace n002dfb60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002dfb60(u8* o) asm("func_002dfb60");
s32 func_002dfb60(u8* o) { return o[49] ? 3 : 154; }
}  // namespace n002dfb60

// 002dfb78 (was never written: gap function)
namespace n002dfb78 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002dfb78(u8* o) asm("func_002dfb78");
s32 func_002dfb78(u8* o) { return o[49] ? 4 : 155; }
}  // namespace n002dfb78

// 002dfb90 (was never written: gap function)
namespace n002dfb90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002dfb90(u8* o) asm("func_002dfb90");
s32 func_002dfb90(u8* o) { return o[49] ? 5 : 156; }
}  // namespace n002dfb90

// 002dfba8 (was src/anon/batch_w99.cpp)
namespace n002dfba8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2dfb {
    f32 x, y, z, w;
    V2dfb& operator=(const V2dfb& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct P2dfb {
    u8 pad[24]; f32 f24; u8 pad2[21]; u8 b49; u8 pad3[10]; f32 f60; f32 f64; f32 f68; u32 w72;
    u8 pad4[8]; u8 b84; u8 pad5[3]; f32 f88; f32 f92; u32 w96; u8 pad6[12]; V2dfb pos;
};
extern u32 D_00361f60 asm("D_00361f60");
f32 func_002dd250(u32, s32) asm("func_002dd250");
void func_002deb18(P2dfb*, u8*) asm("func_002deb18");
V2dfb* func_0016c028_2dfba8(u8*) asm("func_0016c028");
f32* func_002dc7c8(u32) asm("func_002dc7c8");
/*TARGET 002dfba8*/
void func_002dfba8(P2dfb* p, u8* o) asm("func_002dfba8");
void func_002dfba8(P2dfb* p, u8* o)
{
    u32 m = D_00361f60;
    f32 k = 0.01f;
    p->f24 = func_002dd250(m, 0) * k;
    func_002deb18(p, o);
    p->b49 = 0;
    p->w72 = 0;
    p->b84 = 0;
    p->pos = *func_0016c028_2dfba8(o);
    p->w96 = 0;
    p->f24 = func_002dd250(m, 0) * k;
    p->f88 = 10.0f;
    p->f92 = func_002dc7c8(m)[36];
    p->f60 = func_002dc7c8(m)[1];
    p->f64 = func_002dc7c8(m)[2];
    p->f68 = func_002dc7c8(m)[3];
}
}  // namespace n002dfba8

// 002dfcb0 (was src/anon/batch_w280.cpp)
namespace n002dfcb0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void QZero(QWord* p)
{
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory");
}
extern u8* D_00361f60 asm("D_00361f60");
void func_0016aef0(u8*, QWord*) asm("func_0016aef0");
QWord* func_0016c028(u8*) asm("func_0016c028");
// obj_get_attach_or_alt
void func_0016ace0(u8*, QWord*) asm("func_0016ace0");
void func_002dff60(u8*, u8*) asm("func_002dff60");
void func_002e0230(u8*, u8*) asm("func_002e0230");
void func_002deda8(u8*, u8*) asm("func_002deda8");
f32 func_002de6e8(u32) asm("func_002de6e8");
f32 func_002dc248(u8*) asm("func_002dc248");
/*TARGET 002dfcb0*/
void func_002dfcb0(u8* a, u8* b) asm("func_002dfcb0");
void func_002dfcb0(u8* a, u8* b)
{
    u8* g = D_00361f60;
    if (!g) return;
    {
        QWord v(0.0f, 0.0f, -1.0f, 0.0f);
        func_0016aef0(b, &v);
    }
    QWord p = *func_0016c028(b);  // obj_get_attach_or_alt
    p.f[2] = 0.0f;
    func_0016ace0(b, &p);
    if (*(u32*)(a + 72)) func_002dff60(a, b);
    else func_002e0230(a, b);
    if (*(u32*)(a + 72)) {
        QZero((QWord*)(b + 16));
        QWord w = *func_0016c028(b);  // obj_get_attach_or_alt
        w.f[1] = func_002de6e8(*(u32*)(a + 72));
        func_0016ace0(b, &w);
    } else {
        func_002deda8(a, b);
    }
    if (*(f32*)(a + 40) <= 0.0f) {
        if (func_002dc248(g) <= p.f[1]) *(u8*)(a + 84) = 0;
    }
    u8 r = 0;
    if (*(u8*)(a + 84)) {
        if (p.f[1] < func_002dc248(g)) r = 1;
    }
    *(u8*)(g + 0x8000 + 108) = r;
    *(u32*)(b + 264) &= 0xfffeffff;
}
}  // namespace n002dfcb0

// 002dfe38 (was src/anon/batch_w261.cpp)
namespace n002dfe38 {
union W261Vf { u32 (*f)(void*); u8 c; };
struct W261Act {
    W261Vf* vt; u8 pad4[24]; f32 f28; u8 pad32[8]; f32 f40; f32 f44; u8 b48; u8 b49; u8 pad50[22];
    u32 f72; f32 f76; u32 f80;
};
extern const f32 D_00375d40 asm("D_00375d40");
extern u8 D_00362bf8[] asm("D_00362bf8");
// 001a82f0: moved to src/anon/unit_001a82f0.cpp

void func_002de698(u32) asm("func_002de698");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
s32 func_002ddbb8(u32) asm("func_002ddbb8");
// get_bit0_of_field2808
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
/*TARGET 002dfe38*/
void func_002dfe38(W261Act* o, u8* a1, u32 a2, u32 a3, f32 f) asm("func_002dfe38");
void func_002dfe38(W261Act* o, u8* a1, u32 a2, u32 a3, f32 f) {
    func_002de698(a2);
    o->f72 = a2;
    o->f80 = a3;
    o->f76 = f;
    o->b49 = 0;
    u32 v = o->vt[12].f(o);
    func_0017f488(a1 + 320, v, 0.0f, 0.0f);
    o->f40 = 0.0f;
    o->f44 = 0.0f;
    o->f28 = -(o->f76 + D_00375d40) * 0.01f;
    if (func_002ddbb8(o->f72)) {  // get_bit0_of_field2808
        void* p = func_0016b740(1635);
        if (p) func_002e7568(p, 2, D_00362bf8, 1.0f);
    }
}
}  // namespace n002dfe38

// 002dff60 (was src/anon/batch_w2414_nsa.cpp)
namespace n002dff60 {
struct P2dff60;
struct P2dff60Vt { void* f[15]; void (*land)(P2dff60*, void*, bool); };
struct P2dff60 {
    P2dff60Vt* vt;
    u8 pad0[20];
    f32 vx, vy, vz, f36;
    s32 f40;
    f32 f44;
    u8 pad1;
    u8 fell;
    u8 pad2[22];
    void* gim;
    f32 f76;
    s32 lane;
    u8 f84;
    u8 pad3[3];
    f32 f88;
    u8 pad4[4];
    f32 f96;
};
struct H2dff60 { u8 pad[264]; u32 flags; };
struct G2dff60 { u8 pad[128]; s32 mode; u8 pad2[0x8000 + 108 - 132]; u8 alt; };
extern G2dff60* D_00361f60 asm("D_00361f60");
extern const f32 D_00375d40 asm("D_00375d40");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002ddbb8(void*) asm("func_002ddbb8");
f32 func_002dd2b0(G2dff60*) asm("func_002dd2b0");
s32 p2dff60_reset_stage(void*) asm("_ZN2Ti12MGJumpGimObj18get_reset_stage_idEv");
void func_002dd530(G2dff60*, s32) asm("func_002dd530");
f32 func_002de6e8(void*) asm("func_002de6e8");
f32 func_002dd250(G2dff60*, s32) asm("func_002dd250");
f32 func_002dd280(G2dff60*, s32) asm("func_002dd280");
void func_002e0870(P2dff60*, f32*, f32*, f32*) asm("func_002e0870");
void func_002de3e0(void*) asm("func_002de3e0");
void func_002dd4a8(G2dff60*, s32) asm("func_002dd4a8");
void p2dff60_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void p2dff60_ready(P2dff60*, H2dff60*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
/*TARGET 002dff60*/
void func_002dff60(P2dff60* p, H2dff60* h) asm("func_002dff60");
void func_002dff60(P2dff60* p, H2dff60* h)
{
    G2dff60* g = D_00361f60;
    s32 hit = 0;
    if (!func_002ddbb8(p->gim) && (h->flags & 0x10000)) {
        p->fell = 1;
        hit = 1;
    }
    if (func_002dd2b0(g) <= p->f44 || p->fell) {
        if (g->alt && p->lane == 3 && p2dff60_reset_stage(p->gim) > 0) func_002dd530(g, p2dff60_reset_stage(p->gim));
        f32 t = func_002de6e8(p->gim);
        f32 d[1];
        s32 lane;
        if (func_002ddbb8(p->gim)) {
            p->fell = 1;
            p->f84 = 1;
            lane = g->alt ? 11 : 10;
            f32 a = func_002dd250(g, lane) * 0.01f;
            d[0] = a - (-t - D_00375d40) * 0.01f;
            p->vx = a;
        } else {
            lane = p->lane * 2 + (!p->fell ? 2 : 3);
            f32 e = -(p->f76 - t);
            f32 a = (func_002dd250(g, lane) + e) * 0.01f;
            d[0] = a;
            p->vx = -(t + D_00375d40) * 0.01f + a;
        }
        f32 z = func_002dd280(g, lane);
        f32 y = -(t + D_00375d40) * 0.01f;
        p->vz = z;
        p->vy = y;
        func_002e0870(p, &p->f88, &p->vz, d);
        p->f36 = p->vy;
        p->f40 = 0;
        p->f44 = 0.0f;
        p->f96 = p->vz / p->f88;
        func_002de3e0(p->gim);
        p->vt->land(p, h, hit);
        p->gim = 0;
        func_002dd4a8(g, 1);
        if (g->mode == 1) p2dff60_AddCount(1, 0);
    } else {
        p2dff60_ready(p, h);
        p->f36 = -D_00375d40 * 0.01f;
        p->f44 += D_00349e10;
    }
}
}  // namespace n002dff60

// 002e0230 (was src/anon/batch_w2424_nsa.cpp)
namespace n002e0230 {
struct V2e0230 {
    f32 x, y, z, w;
    V2e0230() {}
    ~V2e0230() {}
    V2e0230(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2e0230(const V2e0230& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2e0230& operator=(const V2e0230& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2e0230 operator-(const V2e0230& b) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e0230 operator+(const V2e0230& b) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e0230 operator*(f32 k) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box2e0230 { f32 x, y, z; s32 pc; V2e0230 pos; };
struct Info2e0230 { f32 x, y, z; s32 pc; V2e0230 pos; Info2e0230() { pc = 0; } };
struct Col2e0230 { u8 pad[8]; s16 x, top, z, bottom; };
struct Kind2e0230 { u8 pad[5]; u8 kind; };
struct Obj2e0230 { u8 pad0[8]; Kind2e0230* info; u8 pad1[2800 - 12]; u8 flag[36]; s32 f2836; };
struct Self2e0230 { u8 pad0[40]; f32 f40; u8 pad1[112 - 44]; V2e0230 pos; };
V2e0230* func_0016c028(void*) asm("func_0016c028");
Col2e0230* func_0016bba8(void*, s32, s32) asm("func_0016bba8");
void func_0018a818(void*, void*, void*) asm("func_0018a818");
Obj2e0230* func_001b9bc8(Obj2e0230*) asm("func_001b9bc8");
s32 func_0019c768(Obj2e0230*) asm("func_0019c768");
s32 func_0019c5d0(Obj2e0230*) asm("func_0019c5d0");
s32 func_002cf270(void*, s32) asm("func_002cf270");
void* func_0016bc20(Obj2e0230*, s32, s32) asm("func_0016bc20");
s32 func_0018a550(void*, void*) asm("func_0018a550");
s32 func_002df198(Self2e0230*) asm("func_002df198");
void func_002dfe38(Self2e0230*, void*, Obj2e0230*, s32, f32) asm("func_002dfe38");
/*TARGET 002e0230*/
s32 func_002e0230(Self2e0230* self, void* ent) asm("func_002e0230");
s32 func_002e0230(Self2e0230* self, void* ent)
{
    V2e0230 prev = self->pos;
    V2e0230 cur = *func_0016c028(ent);
    Col2e0230* col = func_0016bba8(ent, 6, 0);
    if (!col) return 0;
    V2e0230 a[5];
    Box2e0230 me;
    func_0018a818(&me, ent, col);
    for (s32 i = 1; i < 5; i++) {
        f32 k = (f32)i / 5.0f;
        a[i] = (cur - prev) * k + prev;
    }
    V2e0230 b[5];
    {
        V2e0230 ofs((f32)col->x, (f32)(col->top - col->bottom), (f32)col->z, 1.0f);
        for (s32 i = 1; i < 5; i++) b[i] = a[i] + ofs;
    }
    f32 h = 0.0f;
    s32 hit = 0;
    Obj2e0230* o = 0;
    while (!hit && (o = func_001b9bc8(o)) != 0) {
        if (func_0019c768(o)) continue;
        if (func_0019c5d0(o)) continue;
        if (o->info->kind != 22) continue;
        if (func_002cf270(o->flag, 4)) continue;
        void* t = func_0016bc20(o, 2, -1);
        if (!t) continue;
        Info2e0230 box;
        func_0018a818(&box, o, t);
        for (s32 j = 1; j < 5; j++) {
            me.pos = b[j];
            if (func_0018a550(&me, &box)) {
                hit++;
                h = box.pos.y - box.z;
                break;
            }
        }
    }
    if (hit > 0 && o && !func_002df198(self) && self->f40 < 0.0f) {
        s32 k = o->f2836;
        func_002dfe38(self, ent, o, k, h);
    }
    self->pos = cur;
    return hit;
}
}  // namespace n002e0230

// 002e05a8 (was never written: gap function)
namespace n002e05a8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002e05a8(J* o, u8* p, f32 x, f32 y, f32 z) asm("func_002e05a8");
void func_002e05a8(J* o, u8* p, f32 x, f32 y, f32 z) {
    if (o->f68 <= x) {
        if (*(u32*)(p + 264) & 0x10000) o->b49 = 1;
        else func_002e0858((u8*)o);
    }
    if (!o->b49 && x < o->f64) func_002e5010(func_002df140((u8*)o), y, -z);
}
}  // namespace n002e05a8

// 002e0670 (was never written: gap function)
namespace n002e0670 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002e0670(J* o, f32 x) asm("func_002e0670");
s32 func_002e0670(J* o, f32 x) {
    return o->f60 <= x || o->b49;
}
}  // namespace n002e0670

// 002e0698 (was src/anon/batch_wcx2.cpp)
namespace n002e0698 {
// 0x002aaa38: definition moved into src/anon/unit_002a99c8.cpp

// ---- 002e0698
extern u8* D_00361f60 asm("D_00361f60");
struct VT_002e0698 { u8 pad[48]; u32 (*f)(void*); };
void func_00180c88(u8*, u32, f32) asm("func_00180c88");
s32 func_00197920() asm("func_00197920");
void func_001d86a0(s32, u32) asm("func_001d86a0");
void func_002dd4f8(u8*) asm("func_002dd4f8");
/*TARGET 002e0698*/
void func_002e0698(VT_002e0698** o, u8* p) asm("func_002e0698");
void func_002e0698(VT_002e0698** o, u8* p) {
    u32 t = (*o)->f(o);
    func_00180c88(p + 320, t, 0.0f);
    u8* g = D_00361f60;
    if (*(s32*)(g + 0x8000 + 116) > 0 && *(s32*)(g + 128) == 2 && !func_00197920()) func_001d86a0(-1, 1);
    func_002dd4f8(g);
}
}  // namespace n002e0698

// 002e0720 (was src/anon/batch_wcx2.cpp)
namespace n002e0720 {
struct O2e0720;
struct VT2e0720 { u8 pad[44]; s32 (*f44)(O2e0720*); };
struct O2e0720 { VT2e0720* vt; };
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
/*TARGET 002e0720*/
void func_002e0720(O2e0720* o, u8* p) asm("func_002e0720");
void func_002e0720(O2e0720* o, u8* p) {
    u8* q = p + 320;
    func_0017f488(q, o->vt->f44(o), 8.0f, 0.0f);
}
}  // namespace n002e0720

// 002e0768 (was never written: gap function)
namespace n002e0768 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002e0768(K* o, u8* p, s32 flag) asm("func_002e0768");
void func_002e0768(K* o, u8* p, s32 flag) {
    u32 v = ((u32 (*)(K*))o->vt[10])(o);
    func_0017f488(p + 320, v, 0.0f, 0.0f);
    u8* g = D_00361f60;
    if (flag) {
        *(s32*)(g + 0x8000 + 112) = 1;
        o->f92 = *(f32*)(config(g) + 184);
    } else {
        *(s32*)(g + 0x8000 + 112) = 0;
        o->f92 = *(f32*)(config(g) + 144);
    }
    if (o->b84) return;
    void* s = func_0016b740(1635);
    if (s) func_002e7568(s, 5, D_00362bf0, *(f32*)(config(g) + 204));
}
}  // namespace n002e0768

// 002e0858 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e0858 {
u32 func_002dd968(u32, u32, u32, u32) asm("_Z13func_002dd968jjjj");
/*TARGET 002e0858*/
u32 func_002e0858(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e0858jjjj");
u32 func_002e0858(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002dd968(a1, a1, a2, a3);
}
}  // namespace n002e0858

// 002e0870 (was src/anon/tiny_leaf_fpu.cpp)
namespace n002e0870 {
/*TARGET 002e0870*/
// 0x0013f5f0: definition moved into src/anon/unit_0013ef70.cpp

void func_002e0870(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e0870jjjj");
// 0x0013f5f0: definition moved into src/anon/unit_0013ef70.cpp

void func_002e0870(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    f32 f0 = 0.0f, f1 = 0.0f;
    f1 = *(f32*)((u32)r4 + (s32)(32));
    f0 = *(f32*)((u32)r7 + (s32)(0));
    f1 = f1 * f1;
    f0 = f0 + f0;
    f1 = f1 / f0;
    *(f32*)((u32)r5 + (s32)(0)) = f1;
}
}  // namespace n002e0870

// 002e0898 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002e0898 {
// 0x002db210: definition moved into src/anon/unit_002da040.cpp

// --------------------
// 002e0898: jumping object update: sample ground height at three points, wait on the ground, launch, then fall back and land
struct P2e0898;
struct O2e0898 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12();
    virtual void land(P2e0898*);
    virtual void s14();
    virtual void jump(P2e0898*, s32);
    virtual s32 ready(P2e0898*, f32);
    virtual void wait(P2e0898*, f32, f32, f32);
    u8 pad0[8];
    f32 f12;
    u8 pad1[8];
    f32 top;
    f32 base;
    f32 v0;
    f32 y;
    f32 vel;
    f32 time;
    u8 onGround;
    u8 big;
    u8 pad2[38];
    f32 grav;
    f32 f92;
    f32 dur;
};
struct G2e0898 { u8 pad[3072]; f32 speed; };
extern void* g2e0898_game asm("D_00361f60");
extern G2e0898* g2e0898_gs asm("D_0034e948");
extern f32 g2e0898_one asm("D_00349e10");
void* func_002df140(void) asm("func_002df140");
f32 func_002e51b0(void*, f32) asm("func_002e51b0");
void func_002e5010(void*, f32, f32) asm("func_002e5010");
f32 fabsf(f32) asm("fabsf");
f32 func_002dd250(void*, s32) asm("func_002dd250");
f32 func_002dd280(void*, s32) asm("func_002dd280");
void func_002e0870(O2e0898*, f32*, f32*, f32*) asm("func_002e0870");
/*TARGET 002e0898*/
void func_002e0898(O2e0898* o, P2e0898* p, f32 x) asm("func_002e0898");
void func_002e0898(O2e0898* o, P2e0898* p, f32 x)
{
    void* g = g2e0898_game;
    x *= 0.01f;
    void* fld = func_002df140();
    f32 h = func_002e51b0(fld, x);
    f32 h1 = func_002e51b0(fld, x + 0.2f);
    f32 h2 = func_002e51b0(fld, x - 0.2f);
    if (h < h1) h = h1;
    if (h < h2) h = h2;
    f32 bounce = fabsf(o->vel * o->f12) * 0.3f;
    if (o->onGround) {
        o->wait(p, o->time, x, bounce);
        if (o->ready(p, o->time)) {
            s32 big = o->big != 0;
            o->base = h;
            o->onGround = 0;
            o->top = func_002dd250(g, big) * 0.01f;
            f32 dist = o->top - o->base;
            o->v0 = func_002dd280(g, big);
            func_002e0870(o, &o->grav, &o->v0, &dist);
            o->vel = 0.0f;
            o->y = o->base;
            o->time = 0.0f;
            o->dur = o->v0 / o->grav;
            o->jump(p, o->big != 0);
        } else {
            o->y = h;
            o->time += g2e0898_one;
        }
        return;
    }
    f32 t = o->time / 60.0f;
    G2e0898* gs = g2e0898_gs;
    f32 rate = 1.0f;
    if (o->dur < t) {
        rate = gs->speed;
        f32 dt = t - o->dur;
        o->vel = -o->f92 * dt;
        o->y = o->top - o->f92 * 0.5f * dt * dt;
    } else {
        gs->speed = rate;
        o->vel = o->v0 - o->grav * t;
        o->y = o->base + (o->v0 * t - o->grav * 0.5f * t * t);
    }
    o->time += g2e0898_one * rate;
    if (o->vel < 0.0f && o->y <= h) {
        o->y = h;
        func_002e5010(fld, x, -bounce);
        o->time = 0.0f;
        o->onGround = 1;
        o->land(p);
        o->big = 0;
    }
}
}  // namespace n002e0898

// 002e0bb0 (was src/anon/batch_w9.cpp)
namespace n002e0bb0 {
void* func_001050d8(u32) asm("func_001050d8");
void func_002e0d28(void*, u32) asm("func_002e0d28");
/*TARGET 002e0bb0*/
// 0x002bc158: definition moved into src/anon/unit_002bb8b0.cpp

void func_002e0bb0(u32 a) asm("func_002e0bb0");
// 0x002bc158: definition moved into src/anon/unit_002bb8b0.cpp

void func_002e0bb0(u32 a) {
    func_002e0d28(func_001050d8(240), a);
}
}  // namespace n002e0bb0

// 002e0be0 (was src/anon/batch_w267.cpp)
namespace n002e0be0 {
extern char D_00362dc8[] asm("D_00362dc8");
extern char D_00375eb8[] asm("D_00375eb8");
extern char D_00362d90[] asm("D_00362d90");
extern u8* D_0034e948 asm("D_0034e948");
void func_002ce958(void*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(void*) asm("func_002e34b8");
void func_002ceae8(void*, char*, char*) asm("func_002ceae8");
u32 func_001708f8(char*, s32) asm("func_001708f8");
u8* func_00168b38(u32, s32, s32) asm("func_00168b38");
// entry_array_find_nth
void func_002e34c0(void*, u32) asm("func_002e34c0");
u32 func_001050c8(void) asm("func_001050c8");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_002e6fc0(void*, u32) asm("func_002e6fc0");
void func_00102c80(void) asm("func_00102c80");
void func_002e1020(void*) asm("func_002e1020");
void func_002cedd0(s32, char*) asm("func_002cedd0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0016b740(s32) asm("func_0016b740");
struct S2e0 {
  void* vt; char pad[84];
  u8 f88; char pad2[7];
  u32 f96; u32 pad3;
  char f104[4];
  u32 f108;
  void* f112;
};
/*TARGET 002e0be0*/
void func_002e0be0(S2e0* p, u32 a1) asm("func_002e0be0");
void func_002e0be0(S2e0* p, u32 a1) {
  char buf[64];
  u8* o;
  void* n;
  u32 v;
  func_002ce958(p, 4, a1, 0);
  p->vt = D_00362dc8;
  func_002e34b8(p->f104);
  p->f108 = 0;
  func_002ceae8(p, buf, "al_14");
  v = func_001708f8(buf, -1);
  p->f96 = v;
  func_002e34c0(p->f104, *(u32*)(func_00168b38(v, 42, 0) + 8));
  p->f108 = *(u32*)(func_00168b38(v, 42, 1) + 8);  // entry_array_find_nth
  n = func_001063c0(12, func_001050c8());
  func_002e6fc0(n, p->f108);
  p->f112 = n;
  func_00102c80();
  func_002e1020(p);
  func_002cedd0(3, D_00362d90);
  o = D_0034e948;
  func_0016bd60(o, 24);
  *(u32*)(o + 264) |= 1;
  o = func_0016b740(1514);
  func_0016bd60(o, 25);
  *(u32*)(o + 264) |= 1;
  p->f88 = 1;
}
}  // namespace n002e0be0

// 002e0d28 (was src/anon/batch_w99.cpp)
namespace n002e0d28 {
// ---- 002cd770
struct Vec2cd { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline Vec2cd operator+(const Vec2cd& a, const Vec2cd& b)
{
    Vec2cd r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Buf2e0d { u8 b[64]; };
extern u8 D_00362dc8[] asm("D_00362dc8");
extern u8 D_00375eb8[] asm("D_00375eb8");
extern u8 D_00362d90[] asm("D_00362d90");
extern u8* D_0034e948 asm("D_0034e948");
void func_002ce958(u8*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*) asm("func_002e34b8");
void func_002ceae8(u8*, Buf2e0d*, void*) asm("func_002ceae8");
u8* func_001708f8(Buf2e0d*, s32) asm("func_001708f8");
u8* func_00168b38(u8*, s32, s32) asm("func_00168b38");
// entry_array_find_nth
void func_002e34c0(u8*, u32) asm("func_002e34c0");
u32 func_001050c8(void) asm("func_001050c8");
u8* func_001063c0(u32, u32) asm("func_001063c0");
void func_002e6fc0(u8*, u32) asm("func_002e6fc0");
void func_00102c80(void) asm("func_00102c80");
void func_002e1020(u8*) asm("func_002e1020");
void func_002cedd0(s32, void*) asm("func_002cedd0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
u8* func_0016b740(s32) asm("func_0016b740");
/*TARGET 002e0d28*/
void func_002e0d28(u8* p, u32 a) asm("func_002e0d28");
void func_002e0d28(u8* p, u32 a)
{
    Buf2e0d s;
    func_002ce958(p, 4, a, 0);
    *(u8**)p = D_00362dc8;
    func_002e34b8(p + 104);
    *(u32*)(p + 108) = 0;
    func_002ceae8(p, &s, (u8*)"al_14");
    u8* r = func_001708f8(&s, -1);
    *(u8**)(p + 96) = r;
    func_002e34c0(p + 104, *(u32*)(func_00168b38(r, 42, 0) + 8));
    *(u32*)(p + 108) = *(u32*)(func_00168b38(r, 42, 1) + 8);
    u8* x = func_001063c0(12, func_001050c8());
    func_002e6fc0(x, *(u32*)(p + 108));
    *(u8**)(p + 112) = x;
    func_00102c80();
    func_002e1020(p);
    func_002cedd0(3, D_00362d90);
    u8* o = D_0034e948;
    func_0016bd60(o, 24);
    *(u32*)(o + 264) |= 1;
    o = func_0016b740(1514);
    func_0016bd60(o, 25);
    *(u32*)(o + 264) |= 1;
    p[88] = 1;
}
}  // namespace n002e0d28

// 002e0e70 (was src/anon/batch_w28.cpp)
namespace n002e0e70 {
void func_002e70b0(void*) asm("func_002e70b0");
void func_00106420(void*) asm("func_00106420");
u8 func_002cea28(void*) asm("func_002cea28");
extern u8 D_00362dc8[] asm("D_00362dc8");
/*TARGET 002e0e70*/
// 002cebc8: moved to src/taito/minigame_base.cpp (linked unit)

u8 func_002e0e70(u8* p) asm("func_002e0e70");
// 002cebc8: moved to src/taito/minigame_base.cpp (linked unit)

u8 func_002e0e70(u8* p) {
    *(void**)p = D_00362dc8;
    u8* s = *(u8**)(p + 0x70);
    if (s) {
        func_002e70b0(s);
        func_00106420(s);
    }
    return func_002cea28(p);
}
}  // namespace n002e0e70

// 002e0ec8 (was src/anon/batch_w29.cpp)
namespace n002e0ec8 {
void func_002e70b0(void*) asm("func_002e70b0");
void func_00106420(void*) asm("func_00106420");
u8 func_002cea28(void*) asm("func_002cea28");
extern u8 D_00362dc8[] asm("D_00362dc8");
/*TARGET 002e0ec8*/
// 0x002daa50: definition moved into src/anon/unit_002da040.cpp

u8 func_002e0ec8(u8* p) asm("func_002e0ec8");
// 0x002daa50: definition moved into src/anon/unit_002da040.cpp

u8 func_002e0ec8(u8* p) {
    *(void**)p = D_00362dc8;
    void* q = *(void**)(p + 112);
    if (q) {
        func_002e70b0(q);
        func_00106420(q);
    }
    return func_002cea28(p);
}
}  // namespace n002e0ec8

// 002e0f20 (was src/anon/auto80_199_queue.cpp)
namespace n002e0f20 {
/*TARGET 002e0f20*/
void func_002e0f20(u32 a0) asm("_Z13func_002e0f20j");
void func_002e0f20(u32 a0) {
    *(u32*)a0 = (u32)&D_00362dc8;
    u32 p = *(u32*)(a0 + 112);
    if (p != 0) {
        func_002e70b0(p);
        func_00106420(p);
    }
    func_002cea28(a0);
    func_00105110(a0);
}
}  // namespace n002e0f20

// 002e0f80 (was never written: gap function)
namespace n002e0f80 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002e0f80(u8* o) asm("func_002e0f80");
void func_002e0f80(u8* o) { func_002cebc0(o); }
}  // namespace n002e0f80

// 002e0f98 (was never written: gap function)
namespace n002e0f98 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

u8 func_002e0f98(u8* o) asm("func_002e0f98");
u8 func_002e0f98(u8* o) { return o[133]; }
}  // namespace n002e0f98

// 002e0fa0 (was src/anon/batch_w2030_nsa.cpp)
namespace n002e0fa0 {
struct W2030Q { s32 v; };
struct W2030P {
    u8 pad0[0x64];
    s32* r;            // 0x64
    W2030Q q;          // 0x68
    u8 pad6c[0x74 - 0x6c];
    s32 a;             // 0x74
    f32 f;             // 0x78
    u8 pad7c[0x85 - 0x7c];
    u8 b;              // 0x85
};
s32* func_002e34d8(W2030Q*, s32) asm("func_002e34d8");
/*TARGET 002e0fa0*/
// 002bacc0: moved to src/anon/unit_002bac78.cpp

void func_002e0fa0(W2030P* p, s32 a) asm("func_002e0fa0");
// 002bacc0: moved to src/anon/unit_002bac78.cpp

void func_002e0fa0(W2030P* p, s32 a) {
    p->a = a;
    p->r = func_002e34d8(&p->q, a);
    p->f = (f32)*p->r;
    p->b = 1;
}
}  // namespace n002e0fa0

// 002e0fe8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e0fe8 {
u32 func_002e34d8(...) asm("func_002e34d8");
/*TARGET 002e0fe8*/
// list_walk_stride12

u32 func_002e0fe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002e0fe8jjjjjjjj");
// list_walk_stride12

u32 func_002e0fe8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r5 = *(volatile u32*)((u32)r4 + (s32)(116));
    r4 = (u32)((s32)r4 + (104));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002e34d8)(r4, r5, r6, r7, r8, r9, r10, r11);
    r14 = (u32)(*(u8*)((u32)r2 + (s32)(8)));
    r15 = (u32)((s32)0u + (1));
    r2 = 0u;
    if (r14 != r15) {
        r15 = (u32)(r14 ^ 0x0005u);
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}
}  // namespace n002e0fe8

// 002e1020 (was src/anon/batch_w1779_nsa.cpp)
namespace n002e1020 {
// 0x002cb5d8: definition moved into src/taito/path.cpp

struct W1779V4 {
    f32 x, y, z, w;
    W1779V4() {}
    W1779V4(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W1779V4& operator=(const W1779V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1779Obj { u8 pad[0x7c]; s32 m7c; u8 p80[4]; u8 m84; u8 p85[0xd0 - 0x85]; W1779V4 md0; W1779V4 me0; };
void func_002e0fa0(W1779Obj*, s32) asm("func_002e0fa0");
/*TARGET 002e1020*/
void func_002e1020(W1779Obj* p) asm("func_002e1020");
void func_002e1020(W1779Obj* p) {
    p->m7c = 100;
    p->m84 = 0;
    p->md0 = W1779V4(80.0f, 155.0f, 0.0f, 0.0f);
    p->me0 = W1779V4(100.0f, 85.0f, 0.0f, 0.0f);
    func_002e0fa0(p, 0);
}
}  // namespace n002e1020

// 002e10c0 (was src/anon/tiny.cpp)
namespace n002e10c0 {
/*TARGET 002e10c0*/
u32 func_002e10c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e10c0jjjj");
u32 func_002e10c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (144));
}
}  // namespace n002e10c0

// 002e10d0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e10d0 {
u32 func_002e71a0(u32, u32, u32, u32) asm("_Z13func_002e71a0jjjj");
/*TARGET 002e10d0*/
// 0x002dd4f8: definition moved into src/anon/unit_002da040.cpp

u32 func_002e10d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e10d0jjjj");
// 0x002dd4f8: definition moved into src/anon/unit_002da040.cpp

u32 func_002e10d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = (u32)((s32)0u + (1));
    r16 = r4;
    r15 = *(u32*)((u32)r5 + (s32)(100));
    r5 = *(u32*)((u32)r5 + (s32)(112));
    r6 = (u32)(*(u8*)((u32)r15 + (s32)(8)));
    r2 = func_002e71a0(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n002e10d0

// 002e1108 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e1108 {
u32 func_002e71a0(u32, u32, u32, u32) asm("_Z13func_002e71a0jjjj");
/*TARGET 002e1108*/
u32 func_002e1108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e1108jjjj");
u32 func_002e1108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = (u32)((s32)0u + (2));
    r16 = r4;
    r15 = *(u32*)((u32)r5 + (s32)(100));
    r5 = *(u32*)((u32)r5 + (s32)(112));
    r6 = (u32)(*(u8*)((u32)r15 + (s32)(8)));
    r2 = func_002e71a0(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n002e1108

// 002e1140 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002e1140 {
u32 func_002e71a0(u32, u32, u32, u32) asm("_Z13func_002e71a0jjjj");
/*TARGET 002e1140*/
u32 func_002e1140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e1140jjjj");
u32 func_002e1140(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r7 = (u32)((s32)0u + (3));
    r16 = r4;
    r15 = *(u32*)((u32)r5 + (s32)(100));
    r5 = *(u32*)((u32)r5 + (s32)(112));
    r6 = (u32)(*(u8*)((u32)r15 + (s32)(8)));
    r2 = func_002e71a0(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace n002e1140

// 002e1178 (was src/anon/batch_w254.cpp)
namespace n002e1178 {
struct Mtx { f32 m[16]; } __attribute__((aligned(16)));
static inline void MtxCopy(Mtx* d, const Mtx* s) {
    if (d != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
// In-place inverse of an orthonormal affine matrix: transpose rotation, negate rotated translation (VU0).
static inline void MtxInverseOrtho(Mtx* m) {
    asm volatile(
        "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
        "vsub.xyz $vf4, $vf0, $vf4\n\t"
        "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
extern f32 D_00362d70 asm("D_00362d70");
u8* func_00106a18(s32) asm("func_00106a18");
// buffer_get_256
void func_00106de8(u8*, s32, f32) asm("func_00106de8");
void func_00106c08(u8*) asm("func_00106c08");
u8* func_00106a60(s32) asm("func_00106a60");
// buffer_get_by_index
void func_002e71a0(Mtx*, u32, u8, s32) asm("func_002e71a0");
void wtarget_002e1178(u8* a0, u32, u32, u32) asm("_Z16wtarget_002e1178jjjj");
/*TARGET 002e1178*/
// Set camera FOV from degrees, rebuild projection, then store the inverse of a fresh view matrix.
void wtarget_002e1178(u8* a0, u32, u32, u32) asm("_Z16wtarget_002e1178jjjj");
// Set camera FOV from degrees, rebuild projection, then store the inverse of a fresh view matrix.
void wtarget_002e1178(u8* a0, u32, u32, u32) {
    u8* v = func_00106a18(1);  // buffer_get_256
    Mtx tmp;
    Mtx* d;
    func_00106de8(v, 1, D_00362d70 * 0.017453292f);
    func_00106c08(v);
    u8* c = func_00106a60(1);  // buffer_get_by_index
    func_002e71a0(&tmp, *(u32*)(a0 + 112), (*(u8**)(a0 + 100))[8], 1);
    d = (Mtx*)(c + 16);
    MtxCopy(d, &tmp);
    MtxInverseOrtho(d);
}
}  // namespace n002e1178

// 002e1288 (was src/anon/batch_w269.cpp)
namespace n002e1288 {
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void ncopy269(NM269* d, const NM269* s) { *d = *s; }
struct NI269 { s32 h0; s32 frames; u8 b8; };
struct NO269 {
    u8 pad[100];
    NI269* info;   // 100
    u8 sub[8];     // 104
    s32 f112;      // 112
    s32 idx;       // 116
    f32 time;      // 120
    s32 speed;     // 124
    u32 pad128;
    u8 stop;       // 132
    u8 flag;       // 133
    u8 pad134[10];
    NM269 mtx;     // 144
};
// 0x002da520: definition moved into src/anon/unit_002da040.cpp

extern f32 D_00349e10 asm("D_00349e10");
s32 func_002e34c8(u8*) asm("func_002e34c8");
// obj_get_field8_by_vtable
void func_001991a8(s32, s32) asm("func_001991a8");
void func_002e0fa0(NO269*, s32) asm("func_002e0fa0");
NM269 func_002e71a0(s32, u8, s32) asm("func_002e71a0");
void wt269(NO269* a0, u32, u32, u32) asm("_Z16wtarget_002e1288jjjj");
/*TARGET 002e1288*/
void wt269(NO269* a0, u32, u32, u32) asm("_Z16wtarget_002e1288jjjj");
void wt269(NO269* a0, u32, u32, u32) {
    a0->flag = 0;
    if (!a0->stop) {
        a0->time += (f32)a0->speed * D_00349e10 * 0.5f / 100.0f;
    }
    if ((f32)a0->info->frames + 1.0f <= a0->time) {
        a0->idx++;
        if (a0->idx >= func_002e34c8(a0->sub)) {  // obj_get_field8_by_vtable
            func_001991a8(21, 0);
            a0->idx = func_002e34c8(a0->sub) - 1;
            a0->time = (f32)a0->info->frames;
        } else {
            func_002e0fa0(a0, a0->idx);
        }
    }
    NM269 t = func_002e71a0(a0->f112, a0->info->b8, 1);
    ncopy269(&a0->mtx, &t);
}
}  // namespace n002e1288

// 002e13d8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e13d8 {
void func_002e7108(u32, f32) asm("_Z13func_002e7108jf");
/*TARGET 002e13d8*/
void func_002e13d8(u32 a0) asm("_Z13func_002e13d8j");
void func_002e13d8(u32 a0) {
    func_002e7108(*(u32*)(a0 + 112), *(f32*)(a0 + 120));
}
}  // namespace n002e13d8

// 002e13f8 (was never written: gap function)
namespace n002e13f8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002e13f8(void) asm("func_002e13f8");
void func_002e13f8(void) {
    u8 buf[16];
    func_00199718(buf, 61, -1);
    func_00195750();
    func_00104f58(buf, 1, 0, 0, 0);
}
}  // namespace n002e13f8

// 002e1440 (was src/anon/batch_w2040.cpp)
namespace n002e1440 {
struct C2040Vec {
    f32 x, y, z, w;
    C2040Vec() {}
    C2040Vec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    C2040Vec& operator=(const C2040Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct C2040Mtx {
    f32 m[16];
    C2040Mtx() {}
    C2040Mtx(const C2040Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    C2040Mtx& operator=(const C2040Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // inverse of a rotation + translation matrix, in place
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    C2040Mtx inverse() const {
        C2040Mtx r(*this);
        r.invOrtho();
        return r;
    }
    C2040Vec operator*(const C2040Vec& v) const {
        C2040Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&v), "r"(this) : "memory");
        return r;
    }
    C2040Mtx operator*(const C2040Mtx& b) const {
        C2040Mtx r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
extern f32 D_00362d70 asm("D_00362d70");
C2040Mtx func_002e10d0(void*) asm("func_002e10d0");
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002e1440*/
// 0x002dc4e0: definition moved into src/anon/unit_002da040.cpp
void func_002e1440(void* self, C2040Vec* v, C2040Vec* mn, C2040Vec* mx) asm("func_002e1440");
// 0x002dc4e0: definition moved into src/anon/unit_002da040.cpp
void func_002e1440(void* self, C2040Vec* v, C2040Vec* mn, C2040Vec* mx) {
    C2040Mtx m = func_002e10d0(self);
    C2040Mtx inv = m.inverse();
    v->w = 1.0f;
    *v = inv * *v;
    f32 t = func_002f8a18(D_00362d70 * 0.5f * 0.017453292f) * fabsf(v->z);
    f32 hx = t * 4.0f / 3.0f;
    if (hx - mx->x < v->x) v->x = hx - mx->x;
    if (v->x < mn->x - hx) v->x = mn->x - hx;
    if (t - mx->y < v->y) v->y = t - mx->y;
    if (v->y < mn->y - t) v->y = mn->y - t;
    *v = m * *v;
}
}  // namespace n002e1440

// 002e1668 (was src/anon/batch_w80.cpp)
namespace n002e1668 {
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
static inline void U23_w80_vsub(U23_W80Vec* d, const U23_W80Vec* a, const U23_W80Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct U23_W80Obj { u8 pad[88]; u8 active; u8 pad2[208 - 89]; U23_W80Vec f208; U23_W80Vec f224; };
static inline void U23_w80_vadd(U23_W80Vec* d, const U23_W80Vec* a, const U23_W80Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void U23_w80_vcopy(U23_W80Vec* d, const U23_W80Vec* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
s32 func_00197920(U23_W80Obj*) asm("func_00197920");
void func_002e1440(U23_W80Obj*, U23_W80Vec*, U23_W80Vec*, U23_W80Vec*) asm("func_002e1440");
U23_W80Vec* w80_pos_vec(void*) asm("func_0016c028");
/*TARGET 002e1668*/
// 0x002d8a78: definition moved into src/anon/unit_002d6f70.cpp
void func_002e1668(U23_W80Obj* o, void* p, const U23_W80Vec* ofs, U23_W80Vec* acc) asm("func_002e1668");
// 0x002d8a78: definition moved into src/anon/unit_002d6f70.cpp
void func_002e1668(U23_W80Obj* o, void* p, const U23_W80Vec* ofs, U23_W80Vec* acc) {
    if (func_00197920(o)) return;
    if (!o->active) return;
    if (!(*(u32*)((u8*)p + 1416) & 0x80)) return;
    {
        U23_W80Vec u, t;
        U23_w80_vadd(&t, w80_pos_vec(p), ofs);
        U23_w80_vadd(&u, &t, acc);
        U23_w80_vcopy(&t, &u);
        func_002e1440(o, &t, &o->f208, &o->f224);
        {
            U23_W80Vec x, w;
            U23_w80_vsub(&w, &t, &u);
            U23_w80_vadd(&x, &w, acc);
            *acc = x;
        }
    }
}
}  // namespace n002e1668

// 002e1758 (was src/anon/tiny.cpp)
namespace n002e1758 {
void func_002e13d8(s32) asm("_Z13func_002e13d8i");
/*TARGET 002e1758*/
// 0x002dd200: definition moved into src/anon/unit_002da040.cpp
void func_002e1758(BD_VALUE* bd) asm("_Z13func_002e1758P8BD_VALUE");
// 0x002dd200: definition moved into src/anon/unit_002da040.cpp
void func_002e1758(BD_VALUE* bd) { func_002e13d8(bd[1].i); }
}  // namespace n002e1758

// 002e1770 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e1770 {
u32 func_002e1178(u32, u32, u32, u32) asm("_Z13func_002e1178jjjj");
/*TARGET 002e1770*/
u32 func_002e1770(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e1770jjjj");
u32 func_002e1770(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e1178(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002e1770

// 002e1788 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e1788 {
u32 func_002e1288(u32, u32, u32, u32) asm("_Z13func_002e1288jjjj");
/*TARGET 002e1788*/
u32 func_002e1788(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e1788jjjj");
u32 func_002e1788(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e1288(((u32)(*(u32*)((u32)(a0) + 4u))), a1, a2, a3);
}
}  // namespace n002e1788

// 002e17a0 (was src/anon/batch_w83.cpp)
namespace n002e17a0 {
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
// 0x002da308: definition moved into src/anon/unit_002da040.cpp

s32 func_002e0fe8(void*) asm("func_002e0fe8");
/*TARGET 002e17a0*/
// Direction (scaled xy, normalized) with its length in w; zero if a is not ready.
Vec4 func_002e17a0(void* a, f32* b) asm("func_002e17a0");
// Direction (scaled xy, normalized) with its length in w; zero if a is not ready.
Vec4 func_002e17a0(void* a, f32* b) {
    if (!func_002e0fe8(a)) {
        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Vec4 t;
    t.x = b[0];
    t.y = b[1];
    t.w = t.z = 0.0f;
    f32 k = 25.0f;
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&t), "f"(k) : "$8", "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&t) : "$8", "memory");
    t.w = len;
    return t;
}
}  // namespace n002e17a0

// 002e1878 (was src/anon/batch_w51.cpp)
namespace n002e1878 {
void wtarget_002e1878(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");
// 002cf1f8: moved to src/taito/minigame_base.cpp (linked unit)

struct Vec4f { f32 x, y, z, w; };
extern Vec4f D_00362d80 asm("D_00362d80");
/*TARGET 002e1878*/
void wtarget_002e1878(u32 a, u32 b, u32, u32) asm("_Z16wtarget_002e1878jjjj");
void wtarget_002e1878(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_00362d80.x = D_00362d80.y = D_00362d80.w = 0.0f;
        D_00362d80.z = 590.0f;
    }
}
}  // namespace n002e1878

// 002e18b8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e18b8 {
u32 func_002e1878(u32, u32, u32, u32) asm("_Z13func_002e1878jjjj");
/*TARGET 002e18b8*/
u32 func_002e18b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e18b8jjjj");
u32 func_002e18b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e1878(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002e18b8

// 002e18d8 (was never written: gap function)
namespace n002e18d8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

u32 func_002e18d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002e18d8");
u32 func_002e18d8(u32 a0, u32 a1, u32 a2, u32 a3) { return init(0, 0xffff, a2, a3); }
}  // namespace n002e18d8


// ---- 2e18f8 (gap, was src/anon/asm_002e18f8.s): sets bit 0x40 in the flag word at +0xabc of the second argument.
namespace n002e18f8 {
void func_002e18f8(void*, u8* p) asm("func_002e18f8");
void func_002e18f8(void*, u8* p) { *(u32*)(p + 0xabc) |= 0x40; }
}  // namespace n002e18f8
