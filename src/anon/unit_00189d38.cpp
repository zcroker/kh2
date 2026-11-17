// File 0x189d38-0x18aac0: event key walkers, collision shape tests and placement helpers.
// Old copies came from _nsa files: the unit needs -fno-strict-aliasing.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/npc.hpp"

// ---- 00189d38 from src/anon/batch_w8002_nsa.cpp
namespace n00189d38 {
struct Msg189d38 { s32 a; s32 b; s32 c; };
s32 func_00180dc0(void*, u16) asm("func_00180dc0");
s32 func_001de168(s32*, u16, s32, s32, s32, void*) asm("func_001de168");
s32 func_001b5918(s32*, void*, u16, s32) asm("func_001b5918");
void func_0016cce8(s32, s32, Msg189d38*, s32, s32) asm("func_0016cce8");
struct Obj189d38 { u8 pad0[8]; u8* owner; u8 pad[0xf0-12]; s32* list; u8 pad2[8]; u8* alt; };
struct Arg189d38 { s32 x; u16 id; };
void func_00189d38(Obj189d38* self, Arg189d38* arg) asm("func_00189d38");
void func_00189d38(Obj189d38* self, Arg189d38* arg) {
    u8* owner = self->owner;
    if (func_00180dc0(self, arg->id) == 0) {
        s32 r;
        if (*self->list != 0) r = func_001de168(self->list, arg->id, 1, 1, 0, owner);
        else r = 0;
        u8* t = self->alt ?: owner;
        if (func_001b5918(self->list, owner, arg->id, r) == 0 && *(s32*)(t + 0x484) != 0) {
            Msg189d38 m;
            m.a = (s32)owner;
            m.b = arg->id;
            m.c = r;
            func_0016cce8(*(s32*)(t + 0x484), 16, &m, 3, 0);
        }
    }
}
}  // namespace n00189d38

// ---- 00189e18 from src/anon/batch_w1816.cpp
namespace n00189e18 {
#define W1816_AI __attribute__((always_inline))
struct W1816V {
    f32 x, y, z, w;
    W1816V& operator=(const W1816V& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1816_AI W1816V operator+(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1816_AI W1816V operator-(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W1816Act;
struct W1816Sub { u8 pad[32]; u32 flags; u8 pad2[252 - 36]; W1816Act* tgt; };
struct W1816Act { u8 p0[320]; W1816Sub sub; };
struct W1816Buf { f32 v[8]; };
#define W1816F(o, off, T) (*(T*)((u8*)(o) + (off)))
extern W1816Act* D_0034e948 asm("D_0034e948");
s32 func_0019ba60(W1816Act*) asm("func_0019ba60");
void func_00190128(W1816Buf*) asm("func_00190128");
void func_00190878(W1816Buf*, W1816Act*, s32) asm("func_00190878");
s32 func_001bd418(s32, s32, s32, W1816Buf*, s32, s32) asm("func_001bd418");
s32 func_001bd3e0(s32, s32, s32, W1816Buf*, s32, s32) asm("func_001bd3e0");
void func_00189e18(W1816Act* self, s32 a, s32 b) asm("func_00189e18");
void func_00189e18(W1816Act* self, s32 a, s32 b) {
    W1816Act* pl = D_0034e948;
    if (!func_0019ba60(pl)) return;
    W1816Buf v; func_00190128(&v);
    if (W1816F(self, 0x588, u32) & 0x80) {
        W1816Sub* s = &self->sub;
        if (W1816F(self, 0x160, u32) & 0x4000) { func_00190878(&v, s->tgt, b); goto done; }
    }
    func_00190878(&v, self, b);
done:
    if (pl == self) { if (!func_001bd418(W1816F(pl, 0xb44, s32), 1, a, &v, 1, 100)) return; }
    else if (!func_001bd3e0(W1816F(pl, 0xb44, s32), 1, a, &v, 1, 100)) return;
    W1816F(pl, 0x50c, s32) = a; W1816F(pl, 0x160, u32) |= 0x20000;
}
}  // namespace n00189e18

// ---- 00189f20 from src/anon/batch_w78.cpp
namespace n00189f20 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
static inline bool inRange(u8* p, f32 t) {
    bool r = false;
    if ((f32)*(u16*)p <= t) {
        if (*(u16*)(p + 2) != 0xffff) { if (t < (f32)*(u16*)(p + 2)) r = true; }
        else r = true;
    }
    return r;
}
typedef void (*W78Cb)(u8*, void*);
void func_00189f20(u8* tbl, W78Cb cb, void* arg, f32 t) asm("func_00189f20");
void func_00189f20(u8* tbl, W78Cb cb, void* arg, f32 t) {
    u8* p = tbl + 4;
    for (s32 i = 0; i < tbl[0]; i++) {
        bool hit = inRange(p, t);
        if (hit) cb(p, arg);
        p = p + p[5] * 2 + 6;
    }
}
}  // namespace n00189f20

// ---- 0018a008 from src/anon/batch_w86.cpp
namespace n0018a008 {
struct Key { u16 t; u8 f2; u8 n; u16 data[1]; };
struct Hdr { u8 f0; u8 n; u16 off; };
typedef void (*KFn)(Key*, void*);
static inline bool InRange(f32 t, f32 lo, f32 hi) { return (lo < t && t <= hi) || (hi < 0.0f && t == lo); }
void func_0018a008(Hdr* h, KFn fn, void* arg, f32 lo, f32 hi) asm("func_0018a008");
void func_0018a008(Hdr* h, KFn fn, void* arg, f32 lo, f32 hi)
{
    Key* k = (Key*)((u8*)h + h->off);
    for (s32 i = 0; i < h->n; i++) {
        if (InRange(k->t, lo, hi)) fn(k, arg);
        k = (Key*)&k->data[k->n];
    }
}
}  // namespace n0018a008

// ---- 0018a100 from src/anon/batch_w2367.cpp
namespace n0018a100 {
struct W2367Entry { u32 a; u8 id; u8 pad[15]; };
struct W2367Table { s32 n; u8 pad[60]; W2367Entry e[1]; };
W2367Entry* func_0018a100(W2367Table* t, s32 id, W2367Entry* p) asm("func_0018a100");
W2367Entry* func_0018a100(W2367Table* t, s32 id, W2367Entry* p) {
    W2367Entry* end;
    p = p == 0 ? t->e : p + 1;
    end = t->e + t->n;
    while (p < end) {
        if (id == 22 || p->id == id) return p;
        p++;
    }
    return 0;
}
}  // namespace n0018a100

// ---- 0018a160 gap: find the entry with this id and kind (never written before)
namespace n0018a160 {
struct Entry20 { u8 kind; u8 pad[3]; u8 id; u8 pad2[15]; };
struct Table20 { s32 n; u8 pad[60]; Entry20 e[1]; };
Entry20* func_0018a160(Table20* t, s32 id, s32 kind) asm("func_0018a160");
Entry20* func_0018a160(Table20* t, s32 id, s32 kind) {
    Entry20* p = t->e;
    Entry20* end = t->e + t->n;
    for (; p < end; p++) {
        if (p->id == id && p->kind == kind) return p;
    }
    return 0;
}
}  // namespace n0018a160

// ---- 0018a1b8 from src/anon/batch_w42.cpp
namespace n0018a1b8 {
struct E20 { u32 a; u8 bit; u8 pad[15]; };
E20* func_0018a1b8(u8* p, u32 mask, E20* e) asm("func_0018a1b8");
E20* func_0018a1b8(u8* p, u32 mask, E20* e)
{
    E20* end = (E20*)(p + 64) + *(s32*)p;
    e = !e ? (E20*)(p + 64) : e + 1;
    for (; e < end; e++) {
        if (mask & (1 << e->bit)) return e;
    }
    return 0;
}
}  // namespace n0018a1b8

// ---- 0018a218 from src/anon/tiny_auto80_queue.cpp
namespace n0018a218 {
u32 func_0018a218(u32 a0, u32 a1) asm("_Z13func_0018a218jj");
u32 func_0018a218(u32 a0, u32 a1) {
    register u32 t7 asm("$15") = *(u32*)((u32)a0 + (s32)(0));
    if ((s32)t7 <= 0) {
        return 0u;
    }
    register u32 t5 asm("$13");
    u32 p = (u32)((s32)a0 + (68));
    t5 = t7;
    u32 v0 = 0u;
    do {
        t7 = (u32)(*(u8*)((u32)p + (s32)(0)));
        register u32 t6 asm("$14") = (u32)(v0 + 1u);
        t5 = (u32)((s32)t5 + (-1));
        t7 = (u32)(t7 ^ a1);
        p = (u32)((s32)p + (20));
        if (t7 == 0u) {
            v0 = t6;
        }
    } while (t5 != 0u);
    return v0;
}
}  // namespace n0018a218

// ---- 0018a250 from src/anon/batch_w1795.cpp
namespace n0018a250 {
struct W1795V4 { f32 x, y, z, w;
  W1795V4() {}
  W1795V4& operator=(const W1795V4& o) { if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline W1795V4 operator-(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1795V4 operator*(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1795_dot(const W1795V4& a, const W1795V4& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct W1795Ob { f32 f0, y, z, w; W1795V4 p; };
s32 func_0018a250(W1795Ob* a, W1795Ob* b) asm("func_0018a250");
s32 func_0018a250(W1795Ob* a, W1795Ob* b) {
    W1795V4 m;
    W1795V4 s;
    f32 r = 1.0f / (a->y + b->y);
    s.z = r;
    s.y = 1.0f / (a->z + b->z);
    s.x = r;
    m = (b->p - a->p) * s;
    return w1795_dot(m, m) < 1.0f;
}
}  // namespace n0018a250

// ---- 0018a318 from src/anon/batch_w253.cpp
namespace n0018a318 {
struct W253Vec {
    f32 x, y, z, w;
    W253Vec() {}
    W253Vec(const W253Vec& o) { asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W253Vec& operator=(const W253Vec& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
f32 fabsf(f32) asm("fabsf");
static inline W253Vec vsub(const f32* a, const f32* b) {
    W253Vec r;
    asm volatile(".set noreorder\n\tlqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvsub.xyzw vf1,vf1,vf2\n\tsqc2 vf1,0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline f32 vdot3m(const W253Vec& a, const W253Vec& b) {
    f32 r;
    asm volatile("lqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvmul.xyz vf1,vf1,vf2\n\tvaddy.x vf1,vf1,vf1\n\tvaddz.x vf1,vf1,vf1\n\tqmfc2 $8,vf1\n\tmtc1 $8,%0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
s32 func_0018a318(u8* a0, u8* a1) asm("func_0018a318");
s32 func_0018a318(u8* a0, u8* a1) {
    W253Vec d;
    d = vsub((f32*)(a1 + 16), (f32*)(a0 + 16));
    f32 dy;
    dy = fabsf(d.y);          
    f32 r1 = *(f32*)(a1 + 8);
    f32 r0 = *(f32*)(a0 + 8);
    if (r0 + r1 <= dy) return 0;
    f32 lim;
    if (r1 < dy) {
        dy = (dy - r1) / r0;
        lim = __builtin_sqrtf(1.0f - dy * dy) * *(f32*)(a0 + 4) + *(f32*)(a1 + 4);
    } else {
        lim = *(f32*)(a0 + 4) + *(f32*)(a1 + 4);
    }
    d.y = 0;
    if (vdot3m(d, d) < lim * lim) return 1;
    return 0;
}
}  // namespace n0018a318

// ---- 0018a420 from src/anon/batch_wcx.cpp
namespace n0018a420 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
struct B32 { f32 a, y, c; u32 d; V4 pos; };
f32 fabsf(f32) asm("fabsf");
s32 func_0018a420(B32* a, B32* b) asm("func_0018a420");
s32 func_0018a420(B32* a, B32* b)
{
    V4 t, d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&b->pos), "r"(&a->pos), "r"(&d) : "memory");
    VCopyChk(&t, &d);
    f32 dy = fabsf(t.y);          
    if (a->c + b->c <= dy) return 0;
    f32 r = a->y + b->y;
    *(u32*)&t.y = 0;
    if (VDot(&t, &t) < r * r) return 1;
    return 0;
}
}  // namespace n0018a420

// ---- 0018a4d8 from src/anon/batch_w46.cpp
namespace n0018a4d8 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline Vq vsub46n(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vdot46(const Vq& a, const Vq& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Sph18a { u32 pad; f32 r; u32 pad2[2]; Vq c; };
s32 func_0018a4d8(Sph18a* a, Sph18a* b) asm("func_0018a4d8");
s32 func_0018a4d8(Sph18a* a, Sph18a* b) {
    Vq d;
    d = vsub46n(b->c, a->c);
    f32 dd = vdot46(d, d);
    f32 rr = a->r + b->r;
    return dd < rr * rr;
}
}  // namespace n0018a4d8

// ---- 0018a550 from src/anon/batch_w97.cpp
namespace n0018a550 {
struct Shape18a { s32 type; };
u8 func_0018a250(Shape18a*, Shape18a*) asm("func_0018a250");
u8 func_0018a318(Shape18a*, Shape18a*) asm("func_0018a318");
u8 func_0018a420(Shape18a*, Shape18a*) asm("func_0018a420");
u8 func_0018a4d8(Shape18a*, Shape18a*) asm("func_0018a4d8");
s32 func_0018a550(Shape18a* a, Shape18a* b) asm("func_0018a550");
s32 func_0018a550(Shape18a* a, Shape18a* b) {                         
    switch (a->type) {
    case 0:
        switch (b->type) {
        case 0: case 3: return func_0018a250(a, b);
        case 1: return func_0018a318(a, b);
        }
        break;
    case 1:
        switch (b->type) {
        case 0: case 3: return func_0018a318(b, a);
        case 1: return func_0018a420(a, b);
        }
        break;
    case 3:
        switch (b->type) {
        case 0: return func_0018a250(a, b);
        case 1: return func_0018a318(a, b);
        case 3: return func_0018a4d8(a, b);
        }
        break;
    }
    return 0;
}
}  // namespace n0018a550

// ---- 0018a670 from src/anon/batch_w1886.cpp
namespace n0018a670 {
#define W1886QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1886V {
    f32 x, y, z, w;
    W1886V() {}
    W1886V(const W1886V& o) { W1886QCOPY(this, &o); }
    W1886V& operator=(const W1886V& o) { if (this != &o) W1886QCOPY(this, &o); return *this; }
    W1886V operator-(const W1886V& b) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1886V operator*(const W1886V& b) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1886V operator*(f32 s) const {
        W1886V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1886Body { u8 pad[4]; f32 h; f32 r; u8 pad2[4]; W1886V pos; };
void func_0018a670(W1886Body* a, W1886Body* b, W1886V* out) asm("func_0018a670");
void func_0018a670(W1886Body* a, W1886Body* b, W1886V* out)
{
    W1886V s;
    W1886V inv;
    W1886V d;
    inv.x = inv.z = 1.0f / (a->h + b->h);
    inv.y = 1.0f / (a->r + b->r);
    d = b->pos - a->pos;
    s = d * inv;
    f32 l = s.x * s.x + s.z * s.z;
    if (0.0f < l) {
        *out = s * ((__builtin_sqrtf((1.0f - s.y * s.y) / l) - 1.0f) * (a->h + b->h + 5.0f));
    } else {
        out->x = a->h + b->h + 5.0f;
        out->z = 0.0f;
    }
    out->y = 0.0f;
}
}  // namespace n0018a670

// ---- 0018a7d0 from src/anon/tiny_auto80_queue.cpp
namespace n0018a7d0 {
u32 func_0018a670(...) asm("func_0018a670");
void func_0018a7d0(u32 a0, u32 a1) asm("_Z13func_0018a7d0jj");
void func_0018a7d0(u32 a0, u32 a1) {
    register u32 t6 asm("$14") = *(u32*)((u32)a0 + (s32)(0));
    register u32 t5 asm("$13") = a1;
    if (t6 != 0u) {
        if (t6 != 3u) {
            return;
        }
    }
    t6 = *(u32*)((u32)t5 + (s32)(0));
    if (t6 != 0u) {
        if (t6 != 3u) {
            return;
        }
    }
    func_0018a670();
}
}  // namespace n0018a7d0

// ---- 0018a818 from src/anon/batch_w1878_nsa.cpp
namespace n0018a818 {
#define W1878_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1878Q {
    f32 v[4];
    W1878Q() {}
    W1878Q(const W1878Q& o) { W1878_QCOPY(this, &o); }
    W1878Q& operator=(const W1878Q& o) {
        if (this != &o) W1878_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1878Mtx { W1878Q r[4]; };
static inline W1878Q W1878MulMV(const W1878Mtx& m, const W1878Q& v)
{
    W1878Q r;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(&v), "r"(&m) : "memory");
    return r;
}
struct W1878Src { u8 pad[5]; u8 b5; u16 flags; s16 x, y, z, dy, px, py; };
struct W1878Dst { s32 f0; f32 f4, f8; W1878Src* src; W1878Q pos; };
struct W1878Ctx { u8 pad[0x7f8]; s32 f7f8; };
void func_0016b0e0(W1878Ctx*, s32, W1878Mtx*) asm("func_0016b0e0");
void func_0018a818(W1878Dst* o, W1878Ctx* c, W1878Src* s) asm("func_0018a818");
void func_0018a818(W1878Dst* o, W1878Ctx* c, W1878Src* s) {
    W1878Mtx m;
    W1878Q v;
    W1878Q* pv = &v;
    pv->v[0] = s->x;
    pv->v[1] = s->y;
    pv->v[2] = s->z;
    o->f0 = s->b5;
    o->src = s;
    pv->v[3] = 1.0f;
    if ((s->flags & 0x4000) || (c->f7f8 & 0x400)) {
        o->f4 = s->px;
        o->f8 = s->py;
        func_0016b0e0(c, s->flags, &m);
        o->pos = W1878MulMV(m, *pv);
        o->pos.v[1] -= s->dy;
    } else {
        o->f4 = o->f8 = 0.0f;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&o->pos) : "memory");
    }
}
}  // namespace n0018a818

// ---- 0018a958 from src/anon/tiny_auto80_queue.cpp
namespace n0018a958 {
void func_0018a958(u32 a0, u32 a1, f32 f12, f32 f13) asm("_Z13func_0018a958jjff");
void func_0018a958(u32 a0, u32 a1, f32 f12, f32 f13) {
    *(u32*)((u32)a0 + (s32)(0)) = a1;
    *(u32*)((u32)a0 + (s32)(12)) = 0u;
    *(f32*)((u32)a0 + (s32)(4)) = f12;
    *(f32*)((u32)a0 + (s32)(8)) = f13;
}
}  // namespace n0018a958

// ---- 0018a970 from src/anon/batch_w270.cpp
namespace n0018a970 {
struct W270V {
    f32 x, y, z, w;
    W270V& operator=(const W270V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W270V operator-(const W270V& b) const {
        W270V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline f32 w270_vlen(W270V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w270_vnorm(W270V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void w270_vscale(W270V* d, const W270V* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
struct W270Sh { s32 type; f32 a; f32 b; u32 pad; W270V pos; };
f32 func_0018a970(W270Sh* s, const W270V* q) asm("func_0018a970");
f32 func_0018a970(W270Sh* s, const W270V* q) {                     
    f32 r = 0.0f;
    W270V d;
    W270V u;
    W270V t = s->pos - *q;
    d = t;
    switch (s->type) {
    case 0:
        if (r < s->a && r < s->b) {
            d.y *= s->a / s->b;
            r = w270_vnorm(&d);
            w270_vscale(&d, &d, r - s->a);
            d.y *= s->b / s->a;
        }
        r = w270_vlen(&d);
        break;
    case 3:
        r = w270_vlen(&d) - s->a;
        break;
    }
    return r;
}
}  // namespace n0018a970
