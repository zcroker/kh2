#include "../common/types.h"
struct W1636V4 {
    f32 x, y, z, w;
    W1636V4() {}
    W1636V4(const W1636V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1636V4& operator=(const W1636V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    W1636V4& operator=(const struct W1636V4L& o);
} __attribute__((aligned(16)));
struct W1636V4L { f32 x, y, z, w; } __attribute__((aligned(16)));
inline W1636V4& W1636V4::operator=(const W1636V4L& o) { if ((void*)this != (void*)&o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
static inline W1636V4L W1636Lerp(const W1636V4& a, const W1636V4& b, f32 t) {
    W1636V4L r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline W1636V4 operator-(const W1636V4& a, const W1636V4& b) {
    W1636V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1636V4 operator+(const W1636V4& a, const W1636V4& b) {
    W1636V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W1636Length(const W1636V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void W1636LerpTo(W1636V4* r, const W1636V4& a, const W1636V4& b, f32 t) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
}
static inline void W1636Sub(W1636V4* r, const W1636V4& a, const W1636V4& b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
static inline void W1636Add(W1636V4* r, const W1636V4& a, const W1636V4& b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
static inline f32 W1636Clamp(f32 v, f32 lo, f32 hi) { return v < lo ? lo : (hi < v ? hi : v); }
struct W1636Cam {
    u8 pad[16];
    W1636V4 a0;    // 16
    W1636V4 b0;    // 32
    W1636V4 a1;    // 48
    W1636V4 b1;    // 64
    f32 f80;
    u32 flags;
    f32 t;
    f32 dur;
    void* obj;     // 96
    u8 pad100[44];
    f32 f144;
};
struct W1636Flags { u8 state; u8 pad[2]; u8 bits; };
static inline bool W1636Ready(W1636Flags* f) { return f->state >= 2 && !(f->bits & 2); }
extern "C" {
extern W1636V4 D_01e2bdc0;
extern W1636V4 D_01e2bdd0;
extern W1636V4 D_01e2bde0;
extern W1636V4 D_01e2bdf0;
extern W1636V4 D_01e2be00;
s32 func_0019ba60(void*);
W1636V4* func_0016c028(void*);  // obj_get_attach_or_alt
W1636Flags* func_001b6d70(s32);  // table_entry_ptr_b
void* func_0016b740(s32);
f32 func_002f8960(f32);
s32 func_002c6490(W1636Cam*);

// Worldmap camera target update (blends the a/b offsets by distance to object 1110 and by depth).
// Register pins: p in s1, an unused s0 kept live (the original saves s0 but never uses it),
// the VU0 length result in $f2 and the clamp floor in $f0.
s32 func_002c68f0(W1636Cam* pp)
{
    register W1636Cam* p asm("$17") = pp;
    register s32 ph asm("$16");
    if (!func_0019ba60(pp->obj)) return 0;
    asm("" : "+r"(p));
    W1636V4 pos = *func_0016c028(p->obj);
    if (pos.z < -14000.0f) pos.z = -14000.0f;
    W1636V4 a;
    W1636V4 b;
    if (W1636Ready(func_001b6d70(18))) {
        W1636V4 d = *func_0016c028(func_0016b740(1110)) - pos;
        d.y = 0.0f;
        register f32 len asm("$f2");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        register f32 lo asm("$f0") = d.y;
        f32 t = W1636Clamp((len - 5000.0f) / 8000.0f, lo, 1.0f);
        f32 s = func_002f8960(t * 3.1415927f * 0.5f);
        a = W1636Lerp(D_01e2bdf0, D_01e2bdd0, s);
        b = W1636Lerp(D_01e2bde0, D_01e2bdc0, s);
    } else {
        a = D_01e2bdd0;
        b = D_01e2bdc0;
    }
    if (pos.z < -8000.0f) {
        f32 t = W1636Clamp((pos.z - -14000.0f) / 6000.0f, 0.0f, 1.0f);
        f32 s = func_002f8960(t * 3.1415927f * 0.5f);
        W1636V4 e;
        W1636LerpTo(&e, D_01e2be00, a, s);
        a = e;
    }
    p->a1 = pos + a;
    p->b1 = pos + b;
    p->f80 = p->f144 * 0.017453292f;
    func_002c6490(p);
    asm("" : : "r"(ph));
    return 1;
}
}
