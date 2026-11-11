#include "bg.hpp"

// YS::BG (0x1a7588-0x1a8098): ground and line-of-sight queries against the field collision, and
// a random spiral search for a free spot (SEARCH). 128-bit lq/sq copies and VU0 vector math are
// hand-written inline asm (VU0 macro code), as in the original.

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W1788V4 {
    f32 x, y, z, w;
    W1788V4() {}
    W1788V4& operator=(const W1788V4& o) {
        // 128-bit copy (lq/sq), skipped for self-assignment
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1788Hit { W1788V4 pos; W1788V4 nrm; };

struct Vk {
    f32 x, y, z, w;
    Vk() {}
    Vk& operator=(const Vk& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mc {
    Vq r[4];
    Mc() {}
    Mc(const Mc& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); }
} __attribute__((aligned(16)));
struct Seg91 { Vk a, b; };
struct Ob64 { u8 b[64]; } __attribute__((aligned(16)));

struct V7b {
    f32 x, y, z, w;
    V7b() {}
    V7b(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V7b& operator=(const V7b& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct O7b {
    V7b pos;
    f32 f10, f14, f18;
    s32 cnt;
    s32 x20;
};
static inline V7b operator*(const V7b& a, f32 s) {
    V7b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline V7b operator+(const V7b& a, const V7b& b) {
    V7b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline __attribute__((always_inline)) f32 subh(f32 y, f32 h) { return y - h; }
struct V1a7da8 {
    f32 x, y, z, w;
    V1a7da8() {}
    V1a7da8(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1a7da8(const V1a7da8& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct S1a7da8 {
    V1a7da8 pos;
    f32 bottom;
    f32 top;
    f32 angle;
    s32 count;
    s32 arg;
};

// The spiral search state (36 bytes).
struct W1835Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct SEARCH {
    W1835Vec pos;
    f32 lo;
    f32 val;
    f32 ang;
    s32 zero;
    s32 n;
    SEARCH(W1835Vec* v, f32 lo, f32 hi, s32 n);
};
extern "C" {
extern u32 D_003638d0;   // random seed
void* func_001d35e0(void*, void*, u32);
s32 func_001d35e0_hit(W1788Hit*, W1788V4*, W1788V4*, u32) asm("func_001d35e0");
s32 func_001d35e0_4(void*, u32, u32, u32) asm("func_001d35e0");
u32 func_00143a48(Seg91*);
u8* func_00106a18(s32);
Mc* func_00106ad0(u8*);
u8* func_00106a60(s32);
void func_00146680(Ob64*, Mc*);
u32 func_00146730(Ob64*, u8*);
f32 func_0017ce10(f32);
f32 sinf(f32);
f32 cosf(f32);
s32 func_001a7610_v(const V7b&, V7b*, s32, f32, f32) asm("func_001a7610");
s32 func_001a75d8_o(O7b*, V7b*, s32) asm("func_001a75d8");
s32 func_001a75d8_s(S1a7da8*, V1a7da8*, s32) asm("func_001a75d8");
V7b func_001a7b78(O7b* o);
V1a7da8 func_001a7da8(S1a7da8* s, f32 lo, f32 hi);
}

static inline void W1835Copy(W1835Vec* d, const W1835Vec* s)
{
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 W1835Rnd()
{
    D_003638d0 *= 0x10dcd;
    return (f32)D_003638d0 * 2.3283064365386963e-10f;
}
static inline f32 W1835RandF(f32 r) __attribute__((always_inline));
static inline f32 W1835RandF(f32 r) { return W1835Rnd() * r; }
static inline void mmul91(Mc* r, Mc* a, Mc* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void vmul(V1a7da8* r, const V1a7da8* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "r"(a), "f"(s) : "$8");
}
static inline void vadd(V1a7da8* r, const V1a7da8* a, const V1a7da8* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "r"(a), "r"(b));
}
static inline void vcpy(V1a7da8* d, const V1a7da8* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

struct VEC4 { f32 v[4]; } __attribute__((aligned(16)));
// The zero vector (0x350990).
struct ZVEC {
    f32 x, y, z, w;
    ZVEC() { w = z = y = x = 0.0f; }
    ~ZVEC() {}
} __attribute__((aligned(16)));
ZVEC D_00350990;
extern "C" s32 D_003509a0;   // next search direction
s32 D_003509a0;

extern "C" {

u32 func_001a7588(void* p, u32 a1, Q16* out) {
    u32 tmp[8] __attribute__((aligned(16)));
    if (func_001d35e0(tmp, p, a1)) {
        if (out != (Q16*)tmp) { QCOPY(out, tmp); }
    }
    return tmp[5];
}

u32 func_001a75d8(void* p, u32 a1, u32 a2) {
    u8 tmp[32];
    u32 r = (u32)func_001d35e0_4(tmp, (u32)p, a1, a2);
    return (r ^ 1u) & 0xFFu;
}

s32 func_001a7610(unsigned int a0, unsigned int a1, unsigned int a2, float f, float g) {
    W1788V4 p, q;
    W1788Hit h2;
    W1788Hit out;
    p = *(W1788V4*)a0;
    p.y -= g;
    q = *(W1788V4*)a0;
    q.y += f + g;
    if (func_001d35e0_hit(&out, &p, &q, a2)) {
        *(W1788V4*)a1 = out.pos;
        return 1;
    }
    *(W1788V4*)a1 = *(W1788V4*)a0;
    return 0;
}

u32 func_001a76c8(Vk* a, Vk* out) {
    Vk v0, v1;
    Seg91 s;
    v0 = *a;
    v0.y -= 50.0f;
    v1 = *a;
    v1.y += 100.0f;
    s.a = v0;
    s.b = v1;
    if (func_00143a48(&s)) return 1;
    *out = *a;
    return 0;
}

u32 func_001a7790(u8* a) {
    Ob64 ob;
    Mc m(*func_00106ad0(func_00106a18(1)));
    u8* t = func_00106a60(1);  // buffer_get_by_index
    Mc* n = t ? (Mc*)(t + 16) : 0;
    Mc r;
    mmul91(&r, &m, n);
    func_00146680(&ob, &r);  // copy_quad4_if_diff
    return func_00146730(&ob, a) == 0;
}

V7b func_001a7888(W1835Vec* v, f32 lo, f32 hi, s32 n) {
    SEARCH s(v, lo, hi, n);
    return func_001a7b78((O7b*)&s);
}

V1a7da8 func_001a78c0(W1835Vec* v, f32 lo, f32 hi, s32 n, f32 z, f32 w) {
    SEARCH s(v, lo, hi, n);
    return func_001a7da8((S1a7da8*)&s, z, w);
}

}  // extern "C"

SEARCH::SEARCH(W1835Vec* v, f32 lo_, f32 hi, s32 n_) {
    W1835Copy(&pos, v);
    lo = lo_;
    val = lo_ + W1835Rnd() * (hi - lo_);
    n = n_;
    zero = 0;
    f32 k = 0.78539818525f;
    ang = (f32)(((D_003509a0 & 4) >> 2) | (D_003509a0 << 1)) * k + W1835RandF(k);
    D_003509a0 = (D_003509a0 + 1) % 8;
}

extern "C" {

V7b func_001a7b78(O7b* o) {
    V7b ret;
    while (o->f14 >= o->f10) {
        f32 a;
        o->cnt++;
        a = func_0017ce10(o->f18 + (f32)o->cnt * 0.7853982f);
        f32 s = sinf(a);
        V7b d(s, 0.0f, cosf(a), 0.0f);
        if (func_001a7610_v(o->pos + d * o->f14, &ret, o->x20, 1000.0f, 200.0f)) {
            d = o->pos + d * (o->f14 + 20.0f);
            d.y = subh(ret.y, 100.0f);
            if (func_001a75d8_o(o, &d, o->x20)) return ret;
        }
        if (o->cnt >= 8) {
            o->cnt = 0;
            o->f14 = subh(o->f14, 100.0f);
        }
    }
    func_001a7610_v(o->pos, &ret, o->x20, 1000.0f, 200.0f);
    return ret;
}

V1a7da8 func_001a7da8(S1a7da8* s, f32 lo, f32 hi)
{
    V1a7da8 v;
    V1a7da8 p;
    V1a7da8 tsum;
    V1a7da8 tmul;
    while (s->top >= s->bottom) {
        f32 step = 0.7853981852531433f;
        f32 zero = 0.0f;
        f32 scale = 2.3283064365386963e-10f;
        f32 up = 20.0f;
        V1a7da8* pp = &p;
        V1a7da8* pm = &tmul;
        V1a7da8* pu = &tsum;
        s->count++;
        f32 a = func_0017ce10(s->angle + (f32)s->count * step);
        f32 sx = sinf(a);
        f32 cz = cosf(a);
        v.x = sx; v.z = cz; v.y = zero; v.w = zero;
        vmul(pm, &v, s->top);
        vadd(pu, &s->pos, pm);
        vcpy(pp, pu);
        D_003638d0 *= 0x10dcd;
        p.y -= lo + (f32)D_003638d0 * scale * (hi - lo);
        vmul(pm, &v, s->top + up);
        vadd(pu, &s->pos, pm);
        vcpy(&v, pu);
        v.y = p.y - 100.0f;
        if (func_001a75d8_s(s, &v, s->arg)) return p;
        if (s->count >= 8) {
            s->count = 0;
            s->top -= 100.0f;
        }
    }
    return s->pos;
}


}  // extern "C"
