// Linked unit 0x00110b00-0x00111520 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../naka/libkn/friend.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../../src/common/types.h"
extern "C" float fabsf(float);
#include "tiny_auto80_solver_structs.hpp"

// 00110b00 (was src/anon/batch_w112.cpp)
namespace n00110b00 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
Vec4* func_0016c028(void*) asm("func_0016c028");
// obj_get_attach_or_alt
f32 fabsf(f32) asm("fabsf");
struct RayQ { Vec4 a, b, c, hit; u8 pad[48]; u64 on : 1, rest : 33, hitflag : 1, rest2 : 29; u8 pad2[24]; };
extern u8 D_003a9250[] asm("D_003a9250");
extern u8* D_00341708 asm("D_00341708");
s32 w146730(void*, u32) asm("_Z16wtarget_00146730jjjj");
void func_00319e90(RayQ*, void*) asm("func_00319e90");
void func_00143928(RayQ*) asm("func_00143928");
static inline void vsub(Vec4* d, const Vec4* a, const Vec4* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vdot(const Vec4* a, const Vec4* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
static inline void QvCopy(Vec4* d, Vec4* s) { if (d != s) QCOPY(d, s); }
/*TARGET 00110b00*/
// Checks whether pos is in front of / reachable from the object with a ground ray test.
s32 func_00110b00(u8* o, Vec4* pos, u32 a2) asm("func_00110b00");
// Checks whether pos is in front of / reachable from the object with a ground ray test.
s32 func_00110b00(u8* o, Vec4* pos, u32 a2) {
    s32 r = w146730(D_003a9250, a2);
    Vec4 d;
    f32 k;
    if (r == 1) return 0;
    if (r != 0) return 0;
    if (*(u32*)(D_00341708 + 352) & 0x4000) return 0;
    vsub(&d, pos, func_0016c028(D_00341708));  // obj_get_attach_or_alt
    k = *(f32*)(o + 2944);
    if (0.0f < d.y * k) return 0;
    d.y = 0.0f;
    if (fabsf(k) < 1000.0f) {  // fabsf
        if (0.0f < vdot((Vec4*)(o + 2976), &d)) return 0;
    } else {
        if (-0.5f < vdot((Vec4*)(o + 2976), &d)) return 0;
    }
    {
        RayQ ray;
        func_00319e90(&ray, o + 1424);
        QvCopy(&ray.a, pos);
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&ray.b) : "memory");
        ray.on = 0;
        func_00143928(&ray);
        if (ray.hitflag) return 0;
        return 1;
    }
}
}  // namespace n00110b00

// 00110c90 (was src/anon/batch_w3733_nsa.cpp)
namespace n00110c90 {
struct Box110c90;
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V110c90 {
    f32 x, y, z, w;
    V110c90() {}
    V110c90(const V110c90& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V110c90& operator=(const V110c90& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V110c90 operator-(const V110c90& b) const
    {
        V110c90 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
void func_00144450(Box110c90*) asm("func_00144450");
struct Box110c90 {
    f32 lx, ly, lz, hx, hy, hz;
    Box110c90() { func_00144450(this); }
};
struct Pts110c90 { u8 on; u8 pad[3]; s32 count; u8 pad2[8]; V110c90 pts[32]; };
struct O110c90 {
    u8 pad0[1856];
    Box110c90 box;
    const Box110c90& getBox() const { return box; }
    u8 pad1[2940 - 1880];
    u32 flags;
    u8 pad2[3288 - 2944];
    s32 f3288;
    f32 f3292;
    s32 f3296;
};
extern Pts110c90 D_003a9040 asm("D_003a9040");
extern u8 D_003a9250[] asm("D_003a9250");
extern O110c90* D_00341708 asm("D_00341708");
s32 func_00146730(u8*, Box110c90*) asm("func_00146730");
V110c90* f110c90_attach(O110c90*) asm("func_0016c028");
s32 func_00110b00(O110c90*, V110c90*, Box110c90*) asm("func_00110b00");
s32 f110c90_rand(s32) asm("func_0010f648");
/*TARGET 00110c90*/
// Picks a free warp point near o (pb pins &b to s7; gcc swaps it with best otherwise).
s32 func_00110c90(O110c90* o) asm("func_00110c90");
// Picks a free warp point near o (pb pins &b to s7; gcc swaps it with best otherwise).
s32 func_00110c90(O110c90* o)
{
    Pts110c90* w = &D_003a9040;
    if (D_003a9040.count < 0) return -1;
    if (0.0f < o->f3292) return -1;
    if (__builtin_expect(!!(o->f3288 < 40), 1)) return -1;
    Box110c90 box = o->getBox();
    if (func_00146730(D_003a9250, &box)) return -1;
    V110c90 p = *f110c90_attach(o);
    Box110c90 b;
    register Box110c90* pb asm("$23") = &b;
    s32 best = -1;
    V110c90 d;
    if (o->flags & 0x8000) {
        V110c90 q = *f110c90_attach(D_00341708);
        f32 bestDist = 0.0f;
        for (s32 i = 0; i < 32; i++) {
            d = w->pts[i] - p;
            b = box;
            b.lx += d.x;
            b.ly += d.y;
            b.lz += d.z;
            b.hx += d.x;
            b.hy += d.y;
            b.hz += d.z;
            s32 ok = func_00110b00(o, &w->pts[i], pb);
            if (__builtin_expect(ok, 1)) {
                f32 dist = (w->pts[i] - q).lengthSq();
                if (best == -1 || dist < bestDist) {
                    bestDist = dist;
                    best = i;
                }
            }
        }
    } else {
        s32 idx = o->f3296;
        register s32 four asm("$4") = 4;
        V110c90* pts;
        // pts = w->pts, built by hand after the li a0,4 (as in the original schedule)
        asm volatile("addiu %0,%1,16" : "=r"(pts) : "r"(w));
        s32 n = 0;
        asm("" : "+r"(idx) : "r"(n), "r"(pts), "r"(four));
        idx += 28;
        idx += f110c90_rand(four);
        // barrier keeps the sp+96 setup after the call; two asms delay the &31 after the &d setup
        asm volatile(""); asm("" : "+r"(idx)); asm("" : "+r"(idx));
        idx &= 31;
        for (; n < 11; n++) {
            d = *(V110c90*)((idx << 4) + (u32)pts) - p;
            b = box;
            b.lx += d.x;
            b.ly += d.y;
            b.lz += d.z;
            b.hx += d.x;
            b.hy += d.y;
            b.hz += d.z;
            if (func_00110b00(o, &*(V110c90*)((idx << 4) + (u32)pts), pb)) {
                best = idx;
                break;
            }
            idx += 3;
            if (idx >= 32) idx -= 32;
        }
    }
    return best;
}
}  // namespace n00110c90

// 00111000 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00111000 {
u32 func_0010b568(u32, u32, u32, u32) asm("_Z13func_0010b568jjjj");
extern u8 D_003a9040 asm("D_003a9040");
/*TARGET 00111000*/
// 0010ab80: moved to src/anon/unit_0010a918.cpp

u32 func_00111000(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00111000jjjj");
// 0010ab80: moved to src/anon/unit_0010a918.cpp

u32 func_00111000(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0010b568((u32)&D_003a9040, a0, a2, a3);
}
}  // namespace n00111000

// 00111020 (was src/anon/tiny_wrappers_more80_reloc.cpp)
namespace n00111020 {
u32 func_0010b468(u32, u32, u32, u32) asm("_Z13func_0010b468jjjj");
extern u8 D_003a9040 asm("D_003a9040");
/*TARGET 00111020*/
u32 func_00111020(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00111020jjjj");
u32 func_00111020(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0010b468((u32)&D_003a9040, a0, a2, a3);
}
}  // namespace n00111020

// 00111040 (was src/anon/tiny_leaf.cpp)
namespace n00111040 {
/*TARGET 00111040*/
void func_00111040(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00111040jjjj");
void func_00111040(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(2940));
    r15 = (u32)((s32)0u + (1000));
    *(u32*)((u32)r4 + (s32)(3288)) = r15;
    r14 = (u32)(r14 | 0x8000u);
    *(u32*)((u32)r4 + (s32)(3292)) = 0u;
    *(u32*)((u32)r4 + (s32)(2940)) = r14;
}
}  // namespace n00111040

// 0x36a544-0x36a54b: two .rodata words no code loads
extern "C" const s32 D_0036a544 = 4;
extern "C" const s32 D_0036a548 = 3;

// 00111060 (was src/anon/batch_w60.cpp)
namespace n00111060 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_0016adc8(void*, void*) asm("func_0016adc8");
void func_00176a60(void*, f32) asm("func_00176a60");
/*TARGET 00111060*/
// Is `id` in the -1-terminated id table?
// 00103428: moved to src/common/unit_001031b0.cpp

void func_00111060(u8* p, void* v) asm("func_00111060");
// Is `id` in the -1-terminated id table?
// 00103428: moved to src/common/unit_001031b0.cpp

void func_00111060(u8* p, void* v) {
    u32 tmp[4] __attribute__((aligned(16)));
    QCOPY(tmp, v);
    func_0016adc8(p, tmp);
    *(u32*)(p + 2940) |= 1;
    u8* o = *(u8**)(p + 2912);
    (*(void (**)(void*))(*(u32*)o + 48))(o);
    func_00176a60(p, 30.0f);
    *(u32*)(p + 3296) += 1;
    *(f32*)(p + 3292) = 480.0f;
    *(u32*)(p + 3288) = 0;
}
}  // namespace n00111060

// 001110e8 (was src/anon/batch_w86.cpp)
namespace n001110e8 {
struct Obj;
typedef s32 (*VFn)(Obj*);
struct Obj { VFn* vt; u8 pad[2936]; u32 b0:1; u32 b1:1; u32 b2:13; u32 b15:1; u32 rest:16; };
struct Ent { u32 v[4]; };
static inline bool IsB0(Obj* o) { return o->b0; }
extern s32 D_00341780 asm("D_00341780");
extern Ent D_003a9050[] asm("D_003a9050");
s32 func_001917c0(void) asm("func_001917c0");
s32 func_00110c90(Obj*) asm("func_00110c90");
void func_00111060(Obj*, Ent*) asm("func_00111060");
/*TARGET 001110e8*/
void func_001110e8(Obj* o) asm("func_001110e8");
void func_001110e8(Obj* o)
{
    if (IsB0(o)) {
        if (!o->vt[24](o)) {
            o->b0 = 0;
            o->b15 = 0;
        }
        return;
    }
    if (o->b1) return;
    s32 m = D_00341780;
    if (m != 1) {
        if (m < 2) {
            if (m == 0) return;
        }
    } else if (func_001917c0()) return;
    s32 r = func_00110c90(o);
    if (r < 0) return;
    func_00111060(o, &D_003a9050[r]);
}
}  // namespace n001110e8

// 001111c8 (was src/anon/batch_wcx.cpp)
namespace n001111c8 {
f32 func_001142a0(u32) asm("func_001142a0");
f32 func_0010f660(void) asm("func_0010f660");
/*TARGET 001111c8*/
// cvt_20001_scaled
void func_001111c8(u8* p) asm("func_001111c8");
// cvt_20001_scaled
void func_001111c8(u8* p)
{
    *(u32*)(p + 2940) &= ~0x20;
    if (*(u8**)(p + 1164)) {
        f32 a = func_001142a0(*(u32*)(p + 2912));
        u8* q = *(u8**)(p + 1164);
        a *= (f32)*(s32*)(q + 384) / (f32)*(s32*)(q + 388) * 0.75f + 0.25f;
        if (func_0010f660() <= a) *(u32*)(p + 2940) |= 0x20;
    }
}
}  // namespace n001111c8

// 00111278 (was src/anon/batch_w6.cpp)
namespace n00111278 {
/*TARGET 00111278*/
// 00102ed8: moved to src/common/title.cpp

// True when the state at +0xb6c is 16, 12 or 15.
u32 func_00111278(u8* p) asm("func_00111278");
// 00102ed8: moved to src/common/title.cpp

// True when the state at +0xb6c is 16, 12 or 15.
u32 func_00111278(u8* p) {
    s32 v = *(s32*)(p + 0xb6c);
    if (v == 16 || v == 12 || v == 15) return 1;
    return 0;
}
}  // namespace n00111278

// 001112a8 (was src/anon/batch_wcx2.cpp)
namespace n001112a8 {
// --------------------
// 001112a8: party member AI tick (state fixups, choose a target, copy the camera vectors)
struct V1112a8 {
    f32 x, y, z, w;
    V1112a8& operator=(const V1112a8& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct St1112a8 { s32 f0; u32 state; };
struct Fr1112a8 {
    u8 pad0[12];
    St1112a8* st;
    V1112a8 pos;
    V1112a8 rot;
    u8 pad1[352 - 48];
    u32 f352;
    u8 pad2[1632 - 356];
    u64 f1632;
    u8 pad3[2040 - 1640];
    u32 f2040;
    u8 pad4[2064 - 2044];
    s32 f2064;
    u8 pad5[2924 - 2068];
    s32 f2924;
    u8 pad6[2940 - 2928];
    u32 flags;
    f32 f2944;
    u8 pad7[3072 - 2948];
    V1112a8 dir;
    u8 pad8[3104 - 3088];
    V1112a8 up;
    u8 pad9[3288 - 3120];
    s32 f3288;
    bool isA() { if (f352 & 4) return true; return false; }
    bool isB() { if (f352 & 8) return true; return false; }
    bool isC() { if (f352 & 0x10) return true; return false; }
    bool busy() { return isA() || isB() || isC(); }
};
extern Fr1112a8* g1112a8_leader asm("D_00341708");
void f1112a8_setState(Fr1112a8*, s32) asm("func_0016bd60");
s32 func_00111278(Fr1112a8*) asm("func_00111278");
s32 func_0010f8d0(Fr1112a8*) asm("func_0010f8d0");
void func_0010e130(Fr1112a8*, s32) asm("func_0010e130");
f32 fabsf(f32) asm("fabsf");
s32 func_001917c0(void) asm("func_001917c0");
void func_001111c8(Fr1112a8*) asm("func_001111c8");
void func_0010fa68(Fr1112a8*) asm("func_0010fa68");
s32 func_0010fb10(Fr1112a8*) asm("func_0010fb10");
void func_0010ff08(Fr1112a8*) asm("func_0010ff08");
void func_00110500(Fr1112a8*) asm("func_00110500");
void func_001106a0(Fr1112a8*) asm("func_001106a0");
void func_00140dc0(void) asm("func_00140dc0");
/*TARGET 001112a8*/
void func_001112a8(Fr1112a8* o) asm("func_001112a8");
void func_001112a8(Fr1112a8* o)
{
    if ((o->f2040 & 4) && o->f2924 == 12 && o->st->state - 31 < 2) f1112a8_setState(o, 0);
    if (!o->busy() && !(o->f352 & 0x40000000)) return;
    if (o->busy() && !(o->flags & 0x80000000)) o->flags |= 0x80000000;
    if (func_00111278(o)) {
        if (!func_0010f8d0(o) && o->st->state == 32) f1112a8_setState(o, 31);
        if (!(o->f2040 & 4) && !(o->st->state - 31 < 3)) f1112a8_setState(o, 31);
    }
    func_0010e130(o, 0);
    if (o->f1632 & 4) o->f3288++;
    if (g1112a8_leader->f2064) o->f3288++;
    if (400.0f < fabsf(o->f2944)) o->f3288++;
    if (func_001917c0() && !(o->f352 & 0x40000000)) {
        func_001111c8(o);
        func_0010fa68(o);
        if (!func_0010fb10(o)) func_0010ff08(o);
    } else {
        func_00110500(o);
    }
    if (!(o->flags & 0x80)) func_001106a0(o);
    func_00140dc0();
    o->pos = o->dir;
    o->rot = o->up;
}
}  // namespace n001112a8

