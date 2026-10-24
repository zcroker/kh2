#include "../common/types.h"
/* batch w2393: built with -fno-strict-aliasing (_nsa). */

struct Vec10da40 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Hnd10da40 { s32 id; s32 a; s32 b; s32 c; s32 d; };
struct Info10da40 { s32 p0; f32 r; s32 p8; s32 pc; Vec10da40 pos; Info10da40() { pc = 0; } };
extern "C" {
s32 func_00190140(Hnd10da40*) asm("_ZNK2YS6TARGET8is_existEv");
void func_00190128(Hnd10da40*);
void func_00190878(Hnd10da40*, s32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 func_00190730(Hnd10da40*, s32);
void func_0018a818(Info10da40*, s32, s32);
void* func_0016c028(void*);
extern Hnd10da40 D_003417b0;
extern s32 D_003417c4;
}
static inline void vsub10da40(const Vec10da40* a, const Vec10da40* b, Vec10da40* r) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline f32 vlen10da40(const Vec10da40* a) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(a) : "$8", "memory");
    return len;
}
static inline bool valid10da40(Hnd10da40* h) { return func_00190140(h) && h->id != 0; }
/* 0010da40: copies into out the handle entry matching the current key (D_003417c4) that is
   nearest to self, or the cached handle D_003417b0 when it is valid and already matches. */
extern "C" {
void func_0010da40(void* self, s32 unused, Hnd10da40* out) {
    if (D_003417c4 == 0) return;
    if (valid10da40(&D_003417b0) && D_003417b0.id == D_003417c4) {
        *out = D_003417b0;
        return;
    }
    Info10da40 info;
    f32 best = 0.0f;
    s32 key = D_003417c4;
    Hnd10da40 it;
    func_00190128(&it);
    s32 cur = 0;
    func_00190878(&it, key, 0);
    while ((cur = func_00190730(&it, cur)) != 0 && it.id == D_003417c4) {
        func_0018a818(&info, it.id, cur);
        Vec10da40* p = (Vec10da40*)func_0016c028(self);
        Vec10da40 d;
        vsub10da40(&info.pos, p, &d);
        f32 dist = vlen10da40(&d) - info.r;
        if (best == 0.0f || dist < best) {
            best = dist;
            *out = it;
        }
    }
}
}

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
struct W2393Obj;
typedef void (*W2393Fn)(W2393Obj*, W2393Ent*, f32);
typedef void (*W2393Fn2)(W2393Obj*, W2393Ent*);
struct W2393Obj { void** vt; u8 pad4[36]; f32 f40; };
extern "C" {
extern f32 D_00349e10;
extern f32 D_00375d40;
s32 func_002df198(W2393Obj*) asm("_Z13func_002df198Pv");
f32 func_002df1a0(W2393Obj*) asm("_Z13func_002df1a0Pv");
f32 func_002df1a8(W2393Obj*, f32);
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
}
