#include "../common/types.h"
extern "C" {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VtA { u8 pad[0xa0]; V4* (*get)(void*); };
struct ObjA { VtA* vt; };
struct VtB { u8 pad[0x28]; void (*f)(void*, s32, s32); };
struct ObjB { VtB* vt; };
struct S {
    V4 v;            // 0x00
    void* state;     // 0x10
    u8 p14[0x40 - 0x14];
    f32 t;           // 0x40
    u8 p44[0x4c - 0x44];
    s32* p4c;        // 0x4c
    u8 p50[0x60 - 0x50];
    f32 f60, f64, f68;
    u8 p6c[4];
    V4 v70;          // 0x70
    u8 p80[0xa0 - 0x80];
    f32 fa0, fa4, fa8, fac, fb0, fb4;
};
extern f32 D_00349e10;
extern f32 D_00351fd8;
extern ObjB* D_00361f60;
void func_001cb8a0();
void func_001ca910(S*);
s32 func_001ca9c0(S*);
s32 func_001cbab0(S*);
f32 func_001cbf50(f32);
ObjA* func_002d1260();
f32 cosf(f32);
f32 sinf(f32);

static inline __attribute__((always_inline)) void scl(V4* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline __attribute__((always_inline)) void add(V4* d, const V4* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline __attribute__((always_inline)) void sub(V4* d, const V4* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline __attribute__((always_inline)) f32 nrm(V4* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// Steps a VU0-driven object toward its target vector; on arrival snaps,
// normalises the offset and switches state.
s32 func_001cb8c0(S* o) {
    // Register placeholder: occupies s0 while o is live so that o takes s1
    // and q (&o->v70) takes s0, as in the original. Emits no code.
    register s32 d asm("$16");
    if (o->t >= o->f60) {
        o->fa0 += o->fa8 * D_00349e10;
        o->fac += o->fb4 * D_00349e10;
    }
    f32 a = func_001cbf50(o->fa0);
    o->v.x = cosf(a);
    o->v.y = sinf(a);
    *(s32*)&o->v.z = 0;
    asm ("" : "=r"(d));
    scl(&o->v, o->fac);
    asm ("" : : "r"(d));
    V4* q = &o->v70;
    add(&o->v, q);
    if (o->f68 < o->t) {
        if (func_001cbab0(o)) {
            ObjA* c = func_002d1260();
            V4* p = (V4*)((u8*)c->vt->get(c) + 48);
            sub(q, p);
            o->v70.w = nrm(q);
            o->t = D_00351fd8;
            o->state = (void*)func_001cb8a0;
            D_00361f60->vt->f(D_00361f60, 1, *o->p4c);
            func_001ca910(o);
            return 1;
        }
    }
    o->t += D_00349e10;
    if (o->t < o->f64) return 1;
    return (u8)(func_001ca9c0(o) ^ 1);
}

}
