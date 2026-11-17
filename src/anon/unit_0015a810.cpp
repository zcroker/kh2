// Linked unit (extracted from the matched per-function sources).
#include "../common/types.h"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../kn/fvector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include <stdarg.h>

// ---- 0x0015a810 (src/anon/batch_w12.cpp)
namespace n0015a810 {
void* func_001050c8(void) asm("func_001050c8");
extern s32 D_0034aa90 asm("D_0034aa90");
void func_0015a810(void) asm("func_0015a810");
void func_0015a810(void) {
    void* a = func_001050c8();
    D_0034aa90 = (*(s32 (**)(void*, s32, s32))*(void**)a)(a, 0x800, 0);
}
}  // namespace n0015a810

// ---- 0x0015a850 (src/anon/tiny_auto80_queue.cpp)
namespace n0015a850 {
ObjCommon_001050c8* func_001050c8(void) asm("func_001050c8");
ObjCommon_001050c8* func_001050c8(void) asm("func_001050c8");
extern u32 D_0034aa90 asm("D_0034aa90");
void func_0015a850() asm("func_0015a850");
void func_0015a850() {
    u32 v = D_0034aa90;
    if (v != 0) {
        Obj0015a850* o = func_001050c8();
        o->vtbl->fn4(o, D_0034aa90);
        D_0034aa90 = 0;
    }
}
}  // namespace n0015a850

// ---- 0x0015a8a0 (src/anon/batch_w9.cpp)
namespace n0015a8a0 {
u32 func_0016c3a8(u32, u32) asm("func_0016c3a8");
extern u32 D_0034aa90 asm("D_0034aa90");
extern u32 D_0034aa94 asm("D_0034aa94");
void bc_make(void) asm("_ZN2dk14BlindCollision4makeEv");
void bc_make(void) asm("_ZN2dk14BlindCollision4makeEv");
void bc_make(void) {
    D_0034aa94 = func_0016c3a8(D_0034aa90, 64);
}
}  // namespace n0015a8a0

// ---- 0x0015a8d0 (src/anon/batch_w1959.cpp)
namespace n0015a8d0 {
#define W1959QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1959V {
    f32 x, y, z, w;
    W1959V() {}
    W1959V(const W1959V& o) { W1959QCOPY(this, &o); }
    W1959V& operator=(const W1959V& o) { if (this != &o) W1959QCOPY(this, &o); return *this; }
    void sub(const W1959V& a, const W1959V& b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
    W1959V operator-(const W1959V& b) const {
        W1959V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1959Sphere { W1959V c; f32 r; };
struct W1959Item { u32 pad0; f32 r; u32 pad8[2]; W1959V c; };
extern W1959Item* D_0034aa90 asm("D_0034aa90");
extern s32 D_0034aa94 asm("D_0034aa94");
s32 func_00163268(W1959Sphere*, W1959V*, f32*) asm("func_00163268");
s32 func_001632c0(W1959Sphere*, W1959V*, W1959V*) asm("func_001632c0");
s32 func_0015a8d0(W1959V* seg, W1959V* out) asm("func_0015a8d0");
s32 func_0015a8d0(W1959V* seg, W1959V* out) {
    W1959V a = seg[0];
    W1959V b = seg[1];
    W1959V q;
    W1959V d;
    d.sub(seg[1], seg[0]);
    f32 len = d.length();
    W1959Item* it = D_0034aa90;
    s32 found = 0;
    s32 i;
    for (i = 0; i < D_0034aa94; i++) {
        W1959Sphere s;
        W1959V x;
        W1959V y;
        f32 t;
        f32 r = it->r;
        s.c = it->c;
        s.r = r;
        if (func_00163268(&s, &a, &t)) continue;
        if (func_001632c0(&s, &a, &q)) {
            x = a;
            y = q;
            d.sub(y, x);
            if (d.length() < len) {
                b = q;
                *out = b;
                found = 1;
            }
        }
        it++;
    }
    return found;
}
}  // namespace n0015a8d0

// ---- 0x0015aa98 (src/anon/batch_w61.cpp)
namespace n0015aa98 {
void func_001391c8(void*, u32, u32) asm("func_001391c8");
void func_0015aa98(u8* p, u32 a, u32 b, f32 f) asm("func_0015aa98");
void func_0015aa98(u8* p, u32 a, u32 b, f32 f) {
    func_001391c8(p, 11000, 0);
    *(u32*)(p + 24) = a;
    *(f32*)(p + 28) = f;
    *(u32*)(p + 32) = b;
}
}  // namespace n0015aa98

// ---- 0x0015aaf8 (src/anon/batch_w36.cpp)
namespace n0015aaf8 {
typedef void (*VFn)(void*);
s32 func_00197920(u8*) asm("func_00197920");
extern f32 D_00349e14 asm("D_00349e14");
void func_0015aaf8(u8* p) asm("func_0015aaf8");
void func_0015aaf8(u8* p) {
    if (func_00197920(p)) {
        ((VFn)(*(void***)p)[5])(p);
        return;
    }
    if (*(f32*)(p + 28) <= 0.0f) ((VFn)(*(void***)p)[5])(p);
    *(f32*)(p + 28) = *(f32*)(p + 28) - D_00349e14;
}
}  // namespace n0015aaf8

// ---- 0x0015ab70 (gap, written here)
namespace n0015ab70 {
void func_001aa728(s32, u32, s32, s32, u32, s32, s32) asm("func_001aa728");
extern "C" void func_0015ab70(u8* o) { func_001aa728(2, *(u32*)(o + 24), 256, 384, 0x80ffffff, 0, 4); }
}

// ---- 0x0015aba8 (src/anon/batch_w89.cpp)
namespace n0015aba8 {
void func_001386e0(u8*, u32, u32, s32, u32, u32) asm("func_001386e0");
extern u8 D_0032bae0 asm("D_0032bae0");
void func_002362b0(u8*) asm("func_002362b0");
void func_002367c8(u8*) asm("func_002367c8");
s32 func_00105c30(void) asm("func_00105c30");
s32 func_00241ed8(u8) asm("func_00241ed8");
void func_001386e0(u8*, u32, u32, s32, u32, u32) asm("func_001386e0");
void func_0015aba8(u8* o, u32 a1, u32 a2) asm("func_0015aba8");
void func_0015aba8(u8* o, u32 a1, u32 a2) {
    u8* s = o + 416;
    s32 skip = 0;
    s32 x = 0;
    func_002362b0(s);
    func_002367c8(s);  // obj_dispatch_bitfield64
    if (func_00105c30() == 1 || func_00105c30() == 8) skip = 1;
    if (!(u8)skip) x = func_00241ed8(D_0032bae0) != 0;
    func_001386e0(o, 20000, a2, (s32)s, x, 0);
}
}  // namespace n0015aba8

// ---- 0x0015ac68 (src/anon/batch_w36.cpp)
namespace n0015ac68 {
typedef void (*VFn)(void*);
s32 func_00197920(u8*) asm("func_00197920");
s32 func_001ad938(void) asm("func_001ad938");
struct Flags34f240 { u32 b0 : 1; };
extern Flags34f240 D_0034f240 asm("D_0034f240");
void func_00138840(u8*) asm("func_00138840");
void func_0015ac68(u8* p) asm("func_0015ac68");
void func_0015ac68(u8* p) {
    if (func_00197920(p) || func_001ad938() || (u8)D_0034f240.b0) {
        ((VFn)(*(void***)p)[5])(p);
        return;
    }
    func_00138840(p);
}
}  // namespace n0015ac68

// ---- 0x0015ace0 (gap, written here)
namespace n0015ace0 {
s32 func_00139538(u8*) asm("func_00139538");
void func_00236788(u8*) asm("func_00236788");
void func_00138988(u8*) asm("func_00138988");
extern "C" void func_0015ace0(u8* o) {
    if (func_00139538(o)) return;
    func_00236788(o + 416);
    func_00138988(o);
}
}

// ---- 0x0015ad28 (src/anon/auto80_199_queue.cpp)
namespace n0015ad28 {
void func_0015ad28(u32 a0) asm("_ZN2dk17BILLBOARD_PLACE_M4drawEv");
void func_0015ad28(u32 a0) {
    u32 s0 = a0;
    if (func_00139538(s0) != 0) {
        return;
    }
    func_001aa728(2, *(u32*)(s0 + 24), 256, 192, 0x80ffffff, 0, 4);
}
}  // namespace n0015ad28

// ---- 0x0015ad80 (src/anon/auto80_199_queue.cpp)
namespace n0015ad80 {
void func_00138d60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) asm("func_00138d60");
void func_0015ad80(u32 a0, u32 a1, f32 a2) asm("func_0015ad80");
void func_0015ad80(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;
    u32 s0;
    u32 v0;

    s0 = func_0013a7e8(1);
    v0 = func_0013d7e0();
    *(f32*)(s1 + 436) = f20;
    func_00138d60(s1, 10000, s0, v0, 47, s2, 0);
    *(u32*)(s1 + 428) = 1;
}
}  // namespace n0015ad80

// ---- 0x0015ae00 (src/anon/batch_w233.cpp)
namespace n0015ae00 {
extern f32 D_00349e14 asm("D_00349e14");
s32 func_00197920(void*) asm("func_00197920");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_001390a8(void*) asm("func_001390a8");
struct V15ae { u8 p[20]; void (*f5)(void*); };
void func_0015ae00(u8* a) asm("func_0015ae00");
void func_0015ae00(u8* a) {
    if (func_00197920(a)) {
        (*(V15ae**)a)->f5(a);
        return;
    }
    f32 f = *(f32*)(a + 436);
    if (f <= 0.0f) {
        func_00138c10(a, 0x30);
        *(f32*)(a + 436) = 20000.0f;
        f = *(f32*)(a + 436);
    }
    if (f != 20000.0f) *(f32*)(a + 436) = f - D_00349e14;
    func_001390a8(a);
}
}  // namespace n0015ae00

// ---- 0x0015aea8 (src/anon/tiny_auto80_queue.cpp)
namespace n0015aea8 {
extern "C" u32 func_00138c10(...) asm("func_00138c10");
void func_0015aea8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0015aea8");
void func_0015aea8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15, r16, r17;
    r15 = (u32)((s32)0u + (48));
    r16 = r4;
    r17 = r5;
    r14 = *(volatile u32*)((u32)r4 + (s32)(388));
    r5 = (u32)((s32)0u + (47));
    if (r14 == r15) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00138c10)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    *(volatile u32*)((u32)r16 + (s32)(408)) = r17;
}
}  // namespace n0015aea8

// ---- 0x0015aef0 (src/anon/tiny_auto80_queue.cpp)
namespace n0015aef0 {
extern "C" u32 func_001390c0(...) asm("func_001390c0");
extern "C" u32 func_00139538(...) asm("func_00139538");
void func_0015aef0(u32 a0) asm("_ZN2dk24BILLBOARD_DISABLE_REASON4drawEv");
void func_0015aef0(u32 a0) {
    u32 s0 = a0;
    if (func_00139538(a0) == 0u) {
        func_001390c0(s0);
        return;
    }
}
}  // namespace n0015aef0

// ---- 0x0015af30 (gap, written here)
namespace n0015af30 {
extern s32 D_0034aa98 asm("D_0034aa98");
extern "C" void func_0015af30(void) { D_0034aa98--; }
}

