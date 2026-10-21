#include "../common/types.h"

struct V58a {
    f32 x, y, z, w;
    V58a() {}
    V58a& operator=(const V58a& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct O58a { u8 pad[0x60]; void* x60; u8 x64[0x10]; };
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
static inline V58e operator-(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline V58e operator+(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct S58e { u8 pad[0x9f4]; u8 x9f4[0x10]; };
struct O58e { u8 pad[0xc]; s32 xc; u8 pad2[0x84 - 0x10]; S58e* x84; u8 pad3[0xe0 - 0x88]; V58e xe0; };
static inline void w1958_lerp(V58a* r, const V58a* a, const V58a* b, f32 t) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline void w1958a_vsub(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline void w1958a_vadd(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline f32 w1958a_vlen(const V58a* a) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(a) : "$8", "memory");
    return len;
}
extern "C" {
void* func_0016c028(void*);
void func_001904a8(V58a*, void*);
extern V58a D_01e2bc70;
extern V58a D_01e2bc80;
extern V58a D_01e2bc90;
void func_002dd2d8(s32, f32*, f32*);
f32 func_00106558(f32);
extern s32 D_00361f60;
extern void* D_0034e948;
s32 func_0019ba60(s32);
V58e func_0016bda8(s32);
V58e func_0016af58(S58e*);
s32 func_00190140(void*);
V58e func_00190388(void*);


void func_002c04c8(O58a* o, V58a* out1, V58a* out2) {
    V58a c;
    V58a a;
    V58a b;
    V58a* p = (V58a*)func_0016c028(o->x60);
    func_001904a8(&a, o->x64);
    w1958_lerp(&c, p, &a, 0.15f);
    V58a* q = (V58a*)func_0016c028(o->x60);
    func_001904a8(&b, o->x64);
    w1958a_vsub(&a, q, &b);
    f32 len = w1958a_vlen(&a);
    f32 t = 0.0f;
    if (1000.0f < len) {
        if (len < 6000.0f) t = (len - 1000.0f) / 5000.0f;
        else t = 1.0f;
    }
    w1958_lerp(&b, &D_01e2bc80, &D_01e2bc90, t);
    w1958a_vadd(&a, &c, &b);
    *out1 = a;
    w1958a_vadd(&a, &c, &D_01e2bc70);
    *out2 = a;
}

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

V58e* func_001a4b78(V58e* r, O58e* o) {
    V58e d;
    if (func_0019ba60(o->xc)) {
        *r = func_0016bda8(o->xc) - o->xe0;
        r->normalize();
    } else {
        *r = func_0016af58(o->x84);
    }
    if (func_00190140(o->x84->x9f4)) {
        d = func_00190388(o->x84->x9f4) - o->xe0;
        d.normalize();
        *r = *r + d;
        r->normalize();
    }
    return r;
}
}
