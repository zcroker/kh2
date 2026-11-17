// Linked unit 0x00153678-0x00153ea0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../harata/libdk/information.hpp"
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }

// 00153678 (was src/anon/batch_w1941_nsa.cpp)
namespace n00153678 {
struct Al1941;
struct AlVt1941 { void* (*alloc)(Al1941*, u32, s32); };
struct Al1941 { AlVt1941* vt; };
struct InHdr1941 { s32 off; u32 size; };
struct InEnt1941 { s32 a; f32 x, y, z, w; s32 b; };
struct OutEnt1941 { f32 x, y, z, pad; f32 w; u8 rest[44]; };
// --- 00153678: load a 24-byte entry table, allocate the 64-byte work entries and init each one
extern Al1941* D_0034a78c asm("D_0034a78c");
extern InEnt1941* D_0034a778 asm("D_0034a778");
extern s32 D_0034a77c asm("D_0034a77c");
extern OutEnt1941* D_0034a790 asm("D_0034a790");
void func_001535f0(f32, f32, f32) asm("func_001535f0");
void func_001535b0(OutEnt1941*, s32) asm("func_001535b0");
void func_00153840(void*) asm("func_00153840");
/*TARGET 00153678*/
void func_00153678(InHdr1941* h, void* p, Al1941* al) asm("func_00153678");
void func_00153678(InHdr1941* h, void* p, Al1941* al) {
    D_0034a78c = al;
    if (h == 0) {
        D_0034a77c = 0;
        D_0034a778 = 0;
        D_0034a790 = 0;
        return;
    }
    D_0034a778 = (InEnt1941*)((u8*)h + h->off);
    D_0034a77c = h->size / 24;
    D_0034a790 = (OutEnt1941*)al->vt->alloc(al, D_0034a77c << 6, 0);
    func_001535f0(0.125f, 0.5f, 16.0f);
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) {
        OutEnt1941* o = &D_0034a790[i];
        f32 x = D_0034a778[i].x, y = D_0034a778[i].y, z = D_0034a778[i].z, w = D_0034a778[i].w;
        o->x = x;
        o->y = y;
        o->z = z;
        o->w = w;
        func_001535b0(&D_0034a790[i], i);
    }
    func_00153840(p);
}
}  // namespace n00153678

// 001537f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001537f8 {
extern u32 D_0034a78c asm("D_0034a78c");
extern u32 D_0034a790 asm("D_0034a790");
/*TARGET 001537f8*/
void func_001537f8() asm("_Z13func_001537f8v");
void func_001537f8() {
    u32 v = D_0034a790;
    if (v != 0) {
        Obj001537f8* o = (Obj001537f8*)D_0034a78c;
        o->vtbl->fn4(o, v);
        D_0034a790 = 0;
    }
}
}  // namespace n001537f8

// 00153840 (was src/anon/batch_w56.cpp)
namespace n00153840 {
// 00153840: mark every slot, then process each bit set in a 64-bit mask
extern s32 D_0034a77c asm("D_0034a77c");
extern u8* D_0034a790 asm("D_0034a790");
void func_00153948(u8) asm("func_00153948");
/*TARGET 00153840*/
void func_00153840(u64 mask) asm("func_00153840");
void func_00153840(u64 mask)
{
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) D_0034a790[i * 64 + 48] = 1;
    for (s32 i = 0; i < 64; i++) {
        u64 bit = 1ULL << i;
        if (mask & bit) func_00153948(i);
    }
}
}  // namespace n00153840

// 001538d8 (was src/anon/batch_w42.cpp)
namespace n001538d8 {
// 0x0010fea0: definition moved into src/anon/unit_0010fea0.cpp

// 001538d8: flag every entry whose id matches
extern u8* D_0034a790 asm("D_0034a790");
extern s32 D_0034a77c asm("D_0034a77c");
extern u8* D_0034a778 asm("D_0034a778");
/*TARGET 001538d8*/
void func_001538d8(u8 id) asm("func_001538d8");
void func_001538d8(u8 id)
{
    if (!D_0034a790) return;
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) {
        if (*(u32*)(D_0034a778 + i * 24) == id) D_0034a790[i * 64 + 48] = 1;
    }
}
}  // namespace n001538d8

// 00153948 (was src/anon/batch_w49.cpp)
namespace n00153948 {
// 0014b4b0: moved to src/anon/unit_0014b150.cpp


struct E34a790 { u8 pad[48]; u8 f48; u8 pad2[15]; };
struct E34a778 { u32 id; u8 pad[20]; };
extern E34a790* D_0034a790 asm("D_0034a790");
extern s32 D_0034a77c asm("D_0034a77c");
extern E34a778* D_0034a778 asm("D_0034a778");
/*TARGET 00153948*/
void func_00153948(u8 id) asm("func_00153948");
void func_00153948(u8 id) {
    if (D_0034a790 == 0) return;
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++)
        if (D_0034a778[i].id == id) D_0034a790[i].f48 = 0;
}
}  // namespace n00153948

// 001539b0 (was gap, never written)
namespace n001539b0 {
extern s32 D_0034a77c asm("D_0034a77c");
s32 func_001539b0(void) asm("func_001539b0");
s32 func_001539b0(void) { return D_0034a77c; }
}  // namespace n001539b0

// 001539c0 (was src/anon/batch_w1631_g.cpp)
namespace n001539c0 {
#define W1631_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1631Vec {
    f32 x, y, z, w;
    W1631Vec() {}
    W1631Vec(const W1631Vec& o) { W1631_QCOPY(this, &o); }
    W1631Vec& operator=(const W1631Vec& o) { if (this != &o) W1631_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0: d = v * s.
static inline W1631Vec operator*(const W1631Vec& v, f32 s) {
    W1631Vec d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&v), "f"(s) : "$8", "memory");
    return d;
}
// VU0: v *= s.
static inline void W1631_scale(W1631Vec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
// VU0: v += a.
static inline void W1631_add(W1631Vec& v, const W1631Vec& a) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "r"(&a) : "memory");
}
// VU0: v = clamp(v, lo, hi) per component.
static inline void W1631_clamp(W1631Vec& v, f32 lo, f32 hi) {
    asm volatile("mfc1 $8, %1\n\tmfc1 $9, %2\n\tlqc2 $vf1, 0(%0)\n\tqmtc2 $8, $vf2\n\tqmtc2 $9, $vf3\n\tvmaxx.wxyz $vf1, $vf1, $vf2x\n\tvminix.wxyz $vf1, $vf1, $vf3x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}
struct W1631Light {
    u8 pad0[16];
    f32 range;          // 0x10
    u8 pad1[12];
    W1631Vec color;     // 0x20
    u8 off;             // 0x30
    u8 pad2[15];
};
extern s32 D_0034a77c asm("D_0034a77c");
// light count
extern W1631Light* D_0034a790 asm("D_0034a790");
// light array
void func_00153540(W1631Vec*, u8, u8, u8, u8) asm("func_00153540");
f32 func_00153610(f32) asm("func_00153610");
s32 func_00163268(W1631Light*, W1631Vec*, f32*) asm("func_00163268");
/*TARGET 001539c0*/
// Tints an RGBA colour (in place) by the first enabled light that reaches pos:
// col = clamp(col * (1 - k) + light.color * k), k from the distance ratio.
// Matches only with -g.
void func_001539c0(u8* rgba, W1631Vec* pos) asm("func_001539c0");
// Tints an RGBA colour (in place) by the first enabled light that reaches pos:
// col = clamp(col * (1 - k) + light.color * k), k from the distance ratio.
// Matches only with -g.
void func_001539c0(u8* rgba, W1631Vec* pos) {
    W1631Vec add;
    W1631Vec col;
    f32 t;
    s32 n = D_0034a77c;
    s32 i;
    f32 f;
    if (n == 0) return;
    t = 0.0f;
    f = 0.0f;
    func_00153540(&col, rgba[0], rgba[1], rgba[2], rgba[3]);
    for (i = 0; i < n; i++) {
        if (D_0034a790[i].off != 0) continue;
        if (!func_00163268(&D_0034a790[i], pos, &t)) continue;
        add = D_0034a790[i].color;
        t = t / D_0034a790[i].range;
        f = func_00153610(t);
        col = col * (1.0f - f);
        W1631_clamp(col, 0.0f, 1.0f);
        add = add * f;
        W1631_add(col, add);
        W1631_clamp(col, 0.0f, 1.0f);
        break;
    }
    W1631_clamp(col, 0.0f, 1.0f);
    W1631_scale(col, 255.0f);
    *rgba++ = (s32)col.x;
    *rgba++ = (s32)col.y;
    *rgba++ = (s32)col.z;
    *rgba = (s32)col.w;
}
}  // namespace n001539c0

// 00153c60 (was src/anon/batch_w2.cpp)
namespace dk { // method 00153c60
void* func_001050c8() asm("func_001050c8");
void func_0023edb0(void*) asm("func_0023edb0");
class Layout;
/*TARGET 00153c60*/
void Layout_init(Layout* self) asm("_ZN2dk6Layout4initEv");
void Layout_init(Layout* self) {
    func_0023edb0(func_001050c8());  // AREA::GetAllocator
}
}  // dk

// 00153c80 (was src/anon/tiny.cpp)
namespace n00153c80 {
void func_0023ede8(void*) asm("_Z13func_0023ede8Pv");
/*TARGET 00153c80*/
void func_00153c80(BD_VALUE* bd) asm("_Z13func_00153c80P8BD_VALUE");
void func_00153c80(BD_VALUE* bd) { func_0023ede8(bd); }
}  // namespace n00153c80

// 00153c98 (was src/anon/batch_w1669.cpp)
namespace n00153c98 {
// 0x001e7440: definition moved into src/anon/unit_001e0cb8.cpp
struct W1669VObj { void** vt; };
/*TARGET 00153c98*/
void func_00153c98(W1669VObj* p) asm("func_00153c98");
void func_00153c98(W1669VObj* p) {
    if (p) ((void (*)(W1669VObj*))p->vt[4])(p);
}
}  // namespace n00153c98

// 00153cc8 (was src/anon/auto80_199_queue.cpp)
namespace n00153cc8 {
/*TARGET 00153cc8*/
void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("_Z13func_00153cc8jjjjj");
void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u8 ctx[32];
    u32 s0 = a0;
    u32 s2 = a2;
    u32 s3 = a3;
    u32 s4 = a4;

    *(u32*)(s0 + 160) = a1;

    func_0023f800(ctx);
    func_0023fa08(ctx, *(u32*)(s0 + 160));

    u32 s1 = func_0023f948(ctx, 0);
    u32 v = func_0023f908(ctx, 0);

    func_0023eea0(s0, s2, s1, v, s3, s4);
    func_0023f848(ctx);
}
}  // namespace n00153cc8

// 00153d70 (was src/anon/batch_wcx.cpp)
namespace n00153d70 {
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0034a7c0[] asm("D_0034a7c0");
u8* func_0023ee30(s32) asm("func_0023ee30");
void func_002369a0(u8*) asm("func_002369a0");
// obj_ctor_36eac8
void func_0023c008(u8*) asm("func_0023c008");
// obj_ctor_36eae8
void func_00153cc8(u8*, u32, s32, u32, s32) asm("func_00153cc8");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_00236bb8(u8*, f32) asm("func_00236bb8");
/*TARGET 00153d70*/
u8* func_00153d70(u32 a, u32 b) asm("func_00153d70");
u8* func_00153d70(u32 a, u32 b)
{
    u8* o = func_0023ee30(164);
    *(u32*)(o + 12) = 0;
    *(void**)o = D_0035eb98;
    func_002369a0(o + 24);  // obj_ctor_36eac8
    func_0023c008(o + 48);  // obj_ctor_36eae8
    *(void**)o = D_0034a7c0;
    func_00153cc8(o, a, 4800, b, 0);
    if (func_0013a9d0()) func_00236bb8(o + 24, 1.0f);
    return o;
}
}  // namespace n00153d70

// 00153e28 (was src/anon/tiny_auto80_queue.cpp)
namespace n00153e28 {
u32 func_0023ca70(...) asm("func_0023ca70");
u32 func_0023f1b0(...) asm("func_0023f1b0");
/*TARGET 00153e28*/
u32 func_00153e28(f32 a0, f32 a1) asm("_Z13func_00153e28ff");
u32 func_00153e28(f32 a0, f32 a1) {
    f32 f20 = a0;
    f32 f21 = a1;
    u32 v0 = ((u32(*)(f32))(u32)func_0023f1b0)(a0);
    return ((u32(*)(u32,s32,s32))(u32)func_0023ca70)(v0, (s32)f20, (s32)f21);
}
}  // namespace n00153e28

// 00153e70 (was gap, never written)
namespace n00153e70 {
void func_00170950(u32) asm("func_00170950");
void func_00153c98(u8*) asm("func_00153c98");
void func_00153e70(u8* p) asm("func_00153e70");
void func_00153e70(u8* p) {
    func_00170950(*(u32*)(p + 160));
    func_00153c98(p);
}
}  // namespace
