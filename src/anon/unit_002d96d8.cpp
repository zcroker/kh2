// Linked unit 0x002d96d8-0x002d9f10 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../ti/minigame_accessors.hpp"
#include "../taito/mg_hachimitsu_po.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../taito/mg_jump.hpp"

// 002d96d8 (was src/anon/batch_w26.cpp)
namespace n002d96d8 {
void func_002d0ea8(void*) asm("func_002d0ea8");
extern u8 D_003625e0[] asm("D_003625e0");
/*TARGET 002d96d8*/
// 0x002d72e0: definition moved into src/anon/unit_002d6f70.cpp

void func_002d96d8(u8* o) asm("func_002d96d8");
// 0x002d72e0: definition moved into src/anon/unit_002d6f70.cpp

void func_002d96d8(u8* o) {
    func_002d0ea8(o);
    *(u8**)o = D_003625e0;
    *(u32*)(o + 3056) = 0;
    *(u32*)(o + 3060) = 0;
    o[3068] = 1;
    *(u32*)(o + 3072) = 0;
    o[3076] = 1;
    *(u32*)(o + 3216) = 0;
    *(u32*)(o + 3220) = 0;
    *(u32*)(o + 3224) = 0;
}
}  // namespace n002d96d8

// 002d9730 (was src/anon/batch_w27.cpp)
namespace n002d9730 {
// 0x002d7338: definition moved into src/anon/unit_002d6f70.cpp

extern u32 D_003625e0 asm("D_003625e0");
void func_002d0ea8(void*) asm("func_002d0ea8");
/*TARGET 002d9730*/
void func_002d9730(u8* p) asm("func_002d9730");
void func_002d9730(u8* p) {
    func_002d0ea8(p);
    *(void**)p = &D_003625e0;
    *(u32*)(p + 3056) = 0;
    *(u32*)(p + 3060) = 0;
    p[3068] = 1;
    *(u32*)(p + 3072) = 0;
    p[3076] = 1;
    *(u32*)(p + 3216) = 0;
    *(u32*)(p + 3220) = 0;
    *(u32*)(p + 3224) = 0;
}
}  // namespace n002d9730

// 002d9788 (was src/anon/sweep_002d9788_nsa.cpp)
namespace n002d9788 {
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct O4s { u8 pad[8]; u32 fl; } O4s;
typedef struct O4 { u8 pad[0xc]; O4s* s; u8 pad2[0x108 - 0x10]; u32 fl; } O4;
void func_001780d8(O4*) asm("_Z13func_001780d8P2O4");
void func_00198860(O4*, s32) asm("_Z13func_00198860P2O4i");
void func_0016bd60(O4*, s32) asm("_Z13func_0016bd60P2O4i");
void func_0016b070(O4*, V4*) asm("_Z13func_0016b070P2O4P2V4");
void func_0017a7d8(O4*) asm("_Z13func_0017a7d8P2O4");
static inline void vset(V4* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
/*TARGET 002d9788*/
void func_002d9788(O4* p) asm("_Z13func_002d9788P2O4");
void func_002d9788(O4* p) {
    V4 v;
    func_001780d8(p);
    func_00198860(p, 7);
    func_0016bd60(p, 3);
    if (p->s) p->s->fl |= 0x800;
    vset(&v, 0.0f, 0.0f, 0.0f, 0.0f);
    p->fl |= 3;
    func_0016b070(p, &v);
    func_0017a7d8(p);
}
}  // namespace n002d9788

// 002d9810 (was src/anon/batch_wcx2_nsa.cpp)
namespace n002d9810 {
struct Tgt2d9810;
#define W2d9810_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W2d9810Vec {
    f32 x, y, z, w;
    W2d9810Vec() {}
    W2d9810Vec(const W2d9810Vec& o) { W2d9810_QCOPY(this, &o); }
    W2d9810Vec& operator=(const W2d9810Vec& o) { if (this != &o) W2d9810_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W2d9810Mtx {
    W2d9810Vec r0, r1, r2, r3;
    W2d9810Mtx() {}
    W2d9810Mtx(const W2d9810Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W2d9810Mtx& operator=(const W2d9810Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W2d9810Vec operator*(const W2d9810Vec& v) const {
        W2d9810Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void o2d9810_00190128(Tgt2d9810*) asm("func_00190128");
void o2d9810_set_obj(Tgt2d9810*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
struct Tgt2d9810 {
    s32 f0, f4, f8, f12, f16;
    Tgt2d9810(void* obj) { o2d9810_00190128(this); o2d9810_set_obj(this, obj, 0); }
};
struct G2d9810 { u8 pad[201]; u8 over; u8 pad2[336 - 202]; W2d9810Mtx view; };
struct O2d9810 {
    u8 pad0[2884]; s32 f2884; u8 pad1[3056 - 2888];
    void* pot; void* pooh; f32 f3064; u8 f3068; u8 pad2[3]; f32 f3072; bool f3076; u8 pad3[11];
    W2d9810Mtx m;
};
extern G2d9810* g2d9810_game asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
void o2d9810_002d10a0(O2d9810*) asm("func_002d10a0");
void* o2d9810_0016b740(s32) asm("func_0016b740");
void func_002dbca0(void*, bool) asm("func_002dbca0");
s32 o2d9810_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void o2d9810_001c0d38(void*, O2d9810*, s32, s32) asm("_Z16u_tail4_001c0d38jjjj");
s32 func_002da308(O2d9810*) asm("func_002da308");
void* o2d9810_get_gopher(G2d9810*) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 func_002da238(O2d9810*) asm("func_002da238");
s32 func_002d8898(G2d9810*) asm("func_002d8898");
s32 o2d9810_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
void o2d9810_001bd3e0(s32, s32, s32, Tgt2d9810*, s32, s32) asm("func_001bd3e0");
W2d9810Vec* o2d9810_0016c028(O2d9810*) asm("func_0016c028");
void o2d9810_0011b6a8(W2d9810Mtx*) asm("func_0011b6a8");
W2d9810Vec* o2d9810_get_xyzrot(O2d9810*) asm("_ZN2YS3OBJ10get_xyzrotEv");
void o2d9810_rotateXYZ(W2d9810Mtx*, W2d9810Vec*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
/*TARGET 002d9810*/
void func_002d9810(O2d9810* o) asm("func_002d9810");
void func_002d9810(O2d9810* o)
{
    o2d9810_002d10a0(o);
    G2d9810* g = g2d9810_game;
    if (g->over) return;
    void* pot = o->pot;
    if (pot || (o->pot = pot = o2d9810_0016b740(1630)) != 0) {
        if (o->f3076) {
            func_002dbca0(pot, !o->f3076);
            o->f3076 = 0;
        }
    }
    void* pooh = o->pooh;
    if (pooh || (o->pooh = pooh = o2d9810_0016b740(1633)) != 0) {
        if (!o2d9810_is_attach(pooh)) o2d9810_001c0d38(o->pooh, o, 0x4000, 0);
    }
    if (func_002da308(o)) {
        Tgt2d9810 t(o2d9810_get_gopher(g));
        o2d9810_001bd3e0(o->f2884, 1, 498, &t, 1, 100);
    } else if (func_002da238(o) && func_002d8898(g) && !o2d9810_IsExec()) {
        Tgt2d9810 t(o->pot);
        o2d9810_001bd3e0(o->f2884, 1, 461, &t, 1, 100);
    }
    o->f3064 = 0.0f;
    if (!o->f3068) {
        W2d9810Mtx m(g->view);
        m.invOrtho();
        W2d9810Vec p(*o2d9810_0016c028(o));
        p.w = 1.0f;
        W2d9810Vec q = m * p;
        q.w = 1.0f;
        o->f3064 = q.x;
        q.y = 0.0f;
        q.z = 0.0f;
    }
    o2d9810_0011b6a8(&o->m);
    o2d9810_rotateXYZ(&o->m, o2d9810_get_xyzrot(o));
    o->m.r3 = *o2d9810_0016c028(o);
    o->m.r3.w = 1.0f;
    if (0.0f < o->f3072) o->f3072 -= D_00349e10;
}
}  // namespace n002d9810

// 002d9ad8 (was never written: gap function)
namespace n002d9ad8 {
struct V {
    f32 x, y, z, w;
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Snd { void** vt; };
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002cf308(s32) asm("func_002cf308");
Snd* func_0016b740(s32) asm("func_0016b740");
void func_001d86a0(s32, s32) asm("func_001d86a0");
u8* func_002d9210(u8*) asm("func_002d9210");
void func_002dae38(u8*) asm("func_002dae38");
void func_002dbca0(u8*, s32) asm("func_002dbca0");
void func_001dc920(u32) asm("func_001dc920");
u32 func_0016abf8(u8*, s32, s32, s32) asm("func_0016abf8");
V* func_001dc5f8(u32) asm("func_001dc5f8");
V func_0016bda8(u8*) asm("func_0016bda8");
u32 func_001dc9d0(u32) asm("func_001dc9d0");
void func_001788b8(u8*) asm("func_001788b8");
s32 func_002da110(u8*) asm("func_002da110");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_002d1228(u8*) asm("func_002d1228");
void func_0016ace0(u8*, V*) asm("func_0016ace0");
void func_0016b070(u8*, V*) asm("func_0016b070");
void func_002da670(u8*) asm("func_002da670");
s32 func_002d8d68(u8*, u8*, u8*, u8*) asm("func_002d8d68");
void func_002da120(u8*) asm("func_002da120");
s32 func_002d8898(u8*) asm("func_002d8898");
s32 func_002d8900(u8*) asm("func_002d8900");
f32* func_002d73f0(u8*) asm("func_002d73f0");


void func_002d9ad8(u8* o, u16* m) asm("func_002d9ad8");
void func_002d9ad8(u8* o, u16* m)
{
    u8* s = 0;
    if (*m == 498) {
        u8* t = func_002d9210(D_00361f60);
        if (!t) return;
        func_002dae38(t);
        s = t;
    } else if (*m == 461) {
        func_002dbca0(*(u8**)(o + 3056), 1);
        s = *(u8**)(o + 3056);
    }
    if (s) {
        if (*(u32*)(o + 3224)) func_001dc920(*(u32*)(o + 3224));
        *(u32*)(o + 3224) = func_0016abf8(o, 1, 0, 0);
        if (*(u32*)(o + 3224)) {
            *func_001dc5f8(*(u32*)(o + 3224)) = func_0016bda8(s);
            *(u8**)(o + 3216) = s;
        }
        if (*(u32*)(o + 3220)) func_001dc920(*(u32*)(o + 3220));
        *(u32*)(o + 3220) = func_0016abf8(o, 0, 0, 0);
        if (*(u32*)(o + 3220)) *func_001dc5f8(*(u32*)(o + 3220)) = func_0016bda8(o);
    }
}
}  // namespace n002d9ad8

// 002d9c10 (was never written: gap function)
namespace n002d9c10 {
struct V {
    f32 x, y, z, w;
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Snd { void** vt; };
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002cf308(s32) asm("func_002cf308");
Snd* func_0016b740(s32) asm("func_0016b740");
void func_001d86a0(s32, s32) asm("func_001d86a0");
u8* func_002d9210(u8*) asm("func_002d9210");
void func_002dae38(u8*) asm("func_002dae38");
void func_002dbca0(u8*, s32) asm("func_002dbca0");
void func_001dc920(u32) asm("func_001dc920");
u32 func_0016abf8(u8*, s32, s32, s32) asm("func_0016abf8");
V* func_001dc5f8(u32) asm("func_001dc5f8");
V func_0016bda8(u8*) asm("func_0016bda8");
u32 func_001dc9d0(u32) asm("func_001dc9d0");
void func_001788b8(u8*) asm("func_001788b8");
s32 func_002da110(u8*) asm("func_002da110");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_002d1228(u8*) asm("func_002d1228");
void func_0016ace0(u8*, V*) asm("func_0016ace0");
void func_0016b070(u8*, V*) asm("func_0016b070");
void func_002da670(u8*) asm("func_002da670");
s32 func_002d8d68(u8*, u8*, u8*, u8*) asm("func_002d8d68");
void func_002da120(u8*) asm("func_002da120");
s32 func_002d8898(u8*) asm("func_002d8898");
s32 func_002d8900(u8*) asm("func_002d8900");
f32* func_002d73f0(u8*) asm("func_002d73f0");


void func_002d9c10(u8* o) asm("func_002d9c10");
void func_002d9c10(u8* o)
{
    func_001788b8(o);
    u8* g = D_00361f60;
    if (g[201] || g[480]) return;
    if (!func_002da110(o) || (func_002da110(o) && (*(u32*)(o + 352) & 0x10) && *(f32*)(o + 16) != 0.0f)) {
        s32 a = 0, b = 0;
        if (*(f32*)(o + 16) < 0.0f) { a = 152; b = 154; }
        else if (0.0f < *(f32*)(o + 16)) { a = 153; b = 155; }
        func_0017f540(o + 320, a, 8.0f, 0.0f);
        if (*(u8**)(o + 3060)) func_0017f540(*(u8**)(o + 3060) + 320, a, 8.0f, 0.0f);
        if (*(u8**)(o + 3056) && func_001c0cd8(*(u8**)(o + 3056))) func_0017f540(*(u8**)(o + 3056) + 320, b, 8.0f, 0.0f);
    }
    if (*(u32*)(o + 3224)) {
        if (func_001dc9d0(*(u32*)(o + 3224))) {
            *func_001dc5f8(*(u32*)(o + 3224)) = func_0016bda8(*(u8**)(o + 3216));
        } else {
            func_001dc920(*(u32*)(o + 3224));
            *(u32*)(o + 3224) = 0;
        }
    }
    if (*(u32*)(o + 3220)) {
        if (func_001dc9d0(*(u32*)(o + 3220))) {
            *func_001dc5f8(*(u32*)(o + 3220)) = func_0016bda8(o);
        } else {
            func_001dc920(*(u32*)(o + 3220));
            *(u32*)(o + 3220) = 0;
        }
    }
}
}  // namespace n002d9c10

// 002d9e00 (was never written: gap function)
namespace n002d9e00 {
struct V {
    f32 x, y, z, w;
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Snd { void** vt; };
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_002cf308(s32) asm("func_002cf308");
Snd* func_0016b740(s32) asm("func_0016b740");
void func_001d86a0(s32, s32) asm("func_001d86a0");
u8* func_002d9210(u8*) asm("func_002d9210");
void func_002dae38(u8*) asm("func_002dae38");
void func_002dbca0(u8*, s32) asm("func_002dbca0");
void func_001dc920(u32) asm("func_001dc920");
u32 func_0016abf8(u8*, s32, s32, s32) asm("func_0016abf8");
V* func_001dc5f8(u32) asm("func_001dc5f8");
V func_0016bda8(u8*) asm("func_0016bda8");
u32 func_001dc9d0(u32) asm("func_001dc9d0");
void func_001788b8(u8*) asm("func_001788b8");
s32 func_002da110(u8*) asm("func_002da110");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_002d1228(u8*) asm("func_002d1228");
void func_0016ace0(u8*, V*) asm("func_0016ace0");
void func_0016b070(u8*, V*) asm("func_0016b070");
void func_002da670(u8*) asm("func_002da670");
s32 func_002d8d68(u8*, u8*, u8*, u8*) asm("func_002d8d68");
void func_002da120(u8*) asm("func_002da120");
s32 func_002d8898(u8*) asm("func_002d8898");
s32 func_002d8900(u8*) asm("func_002d8900");
f32* func_002d73f0(u8*) asm("func_002d73f0");


void func_002d9e00(u8* o) asm("func_002d9e00");
void func_002d9e00(u8* o)
{
    func_002d1228(o);
    u8* g = D_00361f60;
    if (g[201]) {
        V v;
        v.w = v.z = v.y = v.x = 0.0f;
        func_0016ace0(o, &v);
        v.w = v.z = v.y = v.x = 0.0f;
        func_0016b070(o, &v);
        return;
    }
    *(f32*)(o + 3064) += *(f32*)(o + 16);
    func_002da670(o);
    if (!o[3068]) {
        if (func_002d8d68(g, o, o + 3152, o + 3088) > 0 && !func_002da110(o) &&
            !((s32 (*)(u8*))(*(void***)o)[24])(o))
            func_002da120(o);
    }
    if (o[3068]) o[3068] = 0;
}
}  // namespace n002d9e00

