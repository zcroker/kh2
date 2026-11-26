// Linked unit 0x00130d18-0x00131418 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 00130d18 (was unwritten gap)
namespace n00130d18 {
struct C { u8 pad[20]; u32 v; };
struct O { u32 x0; C* c; };
u32 func_00130d18(O* o) asm("func_00130d18");
u32 func_00130d18(O* o) { return o->c->v; }
}  // namespace

// 00130d28 (was src/anon/batch_w277.cpp)
namespace n00130d28 {
struct Mtx { f32 m[4][4]; } __attribute__((aligned(16)));
static inline void CopyMtx(Mtx* d, const Mtx* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ScaleRow(f32* r, f32 s)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "f"(s) : "$8", "memory");
}
struct Cam { s32 x0; s32 type; u8 pad[136]; f32 a; f32 b4; f32 c; };
struct Obj { s32 x0; Cam* cam; };
struct Arg { u8 pad[24]; Obj* owner; };
union UF { f32 f; u8 c; };
extern UF D_00347b70 asm("D_00347b70");
void func_00127cf8(void*) asm("func_00127cf8");
void func_00128480(Obj*, Arg*) asm("func_00128480");
void kn__MotionPrototype0__setFcurveValue(Obj*, Arg*, f32) asm("kn__MotionPrototype0__setFcurveValue");
void func_00130c18(Obj*, f32) asm("func_00130c18");
void func_0012d728(Obj*, Arg*, Mtx*, void*, void*) asm("func_0012d728");
void func_00129c38(Obj*, Arg*, Mtx*, void*, void*) asm("func_00129c38");
/*TARGET 00130d28*/
void func_00130d28(Obj* o, Arg* a, const Mtx* mtx, void* p3, void* p4, f32 t) asm("func_00130d28");
void func_00130d28(Obj* o, Arg* a, const Mtx* mtx, void* p3, void* p4, f32 t) {
    func_00127cf8(p4);
    t += o->cam->a * 60.0f / o->cam->c;
    D_00347b70.f = o->cam->a + t * o->cam->c / 60.0f;
    if (a->owner != o) func_00128480(o, a);
    kn__MotionPrototype0__setFcurveValue(o, a, t);
    func_00130c18(o, t);
    Mtx m;
    f32* r1 = m.m[1];
    f32* r2 = m.m[2];
    CopyMtx(&m, mtx);
    ScaleRow(r1, -1.0f);
    ScaleRow(r2, -1.0f);
    if (o->cam->type == 1) func_0012d728(o, a, &m, p3, p4);
    else func_00129c38(o, a, &m, p3, p4);
}
}  // namespace n00130d28



// 00130ea0 (was unwritten gap; vtable 0x347bc0 slot). Collects the skeleton's flagged joints (at most 32,
// sorted by joint id) and builds, for each, its frame relative to the parent joint.
namespace n00130ea0 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mtx {
    Vec r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    void inverse() {
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
static inline Vec operator*(const Mtx& m, const Vec& v) {
    Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline void Rotate(Vec* d, const Vec* sv, const Mtx& m) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
                 "sqc2 $vf4, 0(%0)"
                 : : "r"(d), "r"(sv), "r"(&m) : "memory");
}

struct Ent { u16 id; u16 flags; };
struct Hdr { u8 pad[16]; u16 max; u16 num; u8 pad2[8]; s32 ents; };
struct Pick { s16 id; s16 kind; };
struct Rec { u32 f0; s16 parent; s16 f6; u32 f8; u32 flags; u8 pad[12]; f32 f28; u8 pad2[32]; };
struct Out {
    f32 p[3];
    u32 id : 16;
    u32 kind : 2;
    u32 flag : 1;
    u32 : 13;
    f32 a[3]; u32 pa;
    f32 b[3]; u32 pb;
    f32 c[3]; u32 pc;
};
struct Alloc { virtual void* alloc(s32 size, s32 align); };
struct Skel { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
              virtual void v5(); virtual void v6(); virtual void v7(); virtual Rec* recs(); };
struct Arg { u8 pad[20]; Skel* skel; u8 pad2[20]; Mtx* mats; };
struct Self { u32 x0; Hdr* h; };
static Pick D_003b8a10[32];  // .bss@003b8a10 (file static, 128 bytes)
s32 func_0011f270(Skel*, s32) asm("func_0011f270");

Out* func_00130ea0(Self* self, Arg* a, Alloc* al) asm("func_00130ea0");
Out* func_00130ea0(Self* self, Arg* a, Alloc* al) {
    Pick t;
    Hdr* h = self->h;
    Ent* e = (Ent*)((u8*)h + h->ents);
    s32 n = 0;
    s32 i;
    for (i = 0; i < h->num; i++, e++) {
        if ((e->flags & 3) < 2) continue;
        u16 id = e->id;
        if (id < h->max && n < 32) {
            D_003b8a10[n].id = id;
            D_003b8a10[n].kind = e->flags & 3;
            n++;
        }
    }
    for (i = 0; i < n - 1; i++) {
        for (s32 j = i + 1; j < n; j++) {
            if (D_003b8a10[j].id < D_003b8a10[i].id) {
                t = D_003b8a10[i];
                D_003b8a10[i] = D_003b8a10[j];
                D_003b8a10[j] = t;
            }
        }
    }
    Out* mem = 0;
    if (n > 0) {
        s32 size = n << 6;
        mem = (Out*)al->alloc(size + 64, 0);
        Rec* rec = a->skel->recs();
        for (i = 0; i < n; i++) {
            Out* o = &mem[i];
            Pick* p = &D_003b8a10[i];
            o->id = p->id;
            o->kind = p->kind;
            Vec v0;
            v0.unit();
            Rec* r = &rec[p->id]; v0.x = r[1].f28;
            Vec v1 = a->mats[p->id + 1] * v0;
            Vec v2, v3;
            Mtx inv;
            s32 par = func_0011f270(a->skel, p->id);
            if (par < 0) par = rec[p->id].parent;
            inv = a->mats[par];
            inv.inverse();
            v0 = inv * a->mats[p->id].r[3];
            v1 = inv * v1;
            v2 = a->mats[p->id].r[1];
            Rotate(&v2, &v2, inv);
            v3 = a->mats[p->id].r[2];
            Rotate(&v3, &v3, inv);
            o->p[0] = v0.x; o->p[1] = v0.y; o->p[2] = v0.z;
            o->a[0] = v1.x; o->a[1] = v1.y; o->a[2] = v1.z;
            o->b[0] = v2.x; o->b[1] = v2.y; o->b[2] = v2.z;
            o->c[0] = v3.x; o->c[1] = v3.y; o->c[2] = v3.z;
            o->flag = rec[rec[p->id].parent].flags & 1;
        }
        Out* last = (Out*)((u32)size + (u32)mem);
        last->id = 0xffff;
        last->kind = 0;
    }
    return mem;
}
}  // namespace
