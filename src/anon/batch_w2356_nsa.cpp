#include "../common/types.h"

// ---- 001319d8: colour desaturation through a lazily built YIQ matrix ----
#define Q_COPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct CVec {
    f32 x, y, z, w;
    CVec() {}
    CVec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    CVec(const CVec& o) { Q_COPY(this, &o); }
    CVec& operator=(const CVec& o) { if (this != &o) Q_COPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct CMtx { CVec r[4]; };
static inline void CApply(CVec& d, const CMtx& m, const CVec& v) {
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&d), "r"(&v), "r"(&m) : "memory");
}
static inline void CClamp(CVec& v, f32 lo, f32 hi) {
    asm volatile("mfc1 $8, %1\n\tmfc1 $9, %2\n\tlqc2 $vf1, 0(%0)\n\tqmtc2 $8, $vf2\n\tqmtc2 $9, $vf3\n\tvmaxx.wxyz $vf1, $vf1, $vf2x\n\tvminix.wxyz $vf1, $vf1, $vf3x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}
static inline void CScale(CVec& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
static inline void CAdd(CVec& d, const CVec& a, const CVec& b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&d), "r"(&a), "r"(&b) : "memory");
}
static inline u32 CPack(f32 r, f32 g, f32 b, f32 a) {
    return ((s32)a << 24) | ((s32)b << 16) | ((s32)g << 8) | (s32)r;
}
extern "C" {
extern s8 D_003b8a90;
extern CMtx D_003b8aa0;
void func_001320a8(void);
s32 func_002fd188(void (*)(void));
/* Desaturate an RGBA colour: t >= 1 gives grey (YIQ luma), t < 1 blends towards the original. */
u32 func_001319d8(u32 c, f32 t) {
    if (!D_003b8a90) {
        CVec r0(0.299f, 0.587f, 0.114f, 0.0f);
        CVec r1(0.596f, -0.274f, -0.322f, 0.0f);
        CVec r2(0.211f, -0.523f, 0.312f, 0.0f);
        CVec r3(0.0f, 0.0f, 0.0f, 1.0f);
        Q_COPY(&D_003b8aa0.r[0], &r0);
        Q_COPY(&D_003b8aa0.r[1], &r1);
        Q_COPY(&D_003b8aa0.r[2], &r2);
        Q_COPY(&D_003b8aa0.r[3], &r3);
        D_003b8a90 = 1;
        func_002fd188(func_001320a8);
    }
    CVec a;
    CVec v;
    CVec w;
    CVec* p = &v;  // x goes through a pointer: the original stores it via the &v register
    p->x = (f32)(c & 0xff);
    v.y = (f32)((c >> 8) & 0xff);
    v.z = (f32)((c >> 16) & 0xff);
    v.w = (f32)((c >> 24) & 0xff);
    if (t < 1.0f) a = v;
    CApply(w, D_003b8aa0, v);
    v = w;
    CClamp(v, 0.0f, 255.0f);
    if (t < 1.0f) {
        v.y = v.z = v.x;
        CScale(v, t);
        CScale(a, 1.0f - t);
        CAdd(w, v, a);
        a = w;
        CClamp(a, 0.0f, 255.0f);
        return CPack(a.x, a.y, a.z, a.w);
    }
    return CPack(v.x, v.x, v.x, v.w);
}
}

// ---- 00128750: animation curve channel evaluation ----
struct MKey { u16 type:2; u16 time:14; u16 v; u16 tin; u16 tout; };
struct MHdr { u8 pad[64]; s32 keyOff; s32 timeOff; s32 valOff; s32 tanOff; };
struct MObj { u32 x; MHdr* h; };
struct MCh { u16 idx; u16 ch:4; u16 pre:2; u16 post:2; u16 cnt:8; u16 start; };
extern "C" {
void func_001285f8(MObj*, f32, s32*, s32*);
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1);
/* Evaluate one animation curve channel at time t (lo/hi: bracketing time-table indices). */
f32 func_00128750(MObj* o, MCh* k, s32 lo, s32 hi, f32 t) {
    MHdr* h = o->h;
    MKey* keys = (MKey*)((u8*)h + h->keyOff);
    MKey* first = &keys[k->start];
    MKey* last = &keys[k->start + k->cnt] - 1;
    f32* times = (f32*)((u8*)h + h->timeOff);
    f32* vals = (f32*)((u8*)h + h->valOff);
    f32* tans = (f32*)((u8*)h + h->tanOff);
    f32 time = t;
    s32 i0 = first->time;
    if (!(i0 < hi)) {
        switch (k->pre) {
        case 0: return vals[first->v];
        case 1: return vals[first->v] - (times[i0] - t) * tans[first->tin];
        case 2: {
            f32 a = times[i0];
            f32 d = times[last->time] - a;
            if (t < a) { do t += d; while (t < a); time = t; }
            break;
        }
        default: return 0.0f;
        }
        func_001285f8(o, time, &lo, &hi);
    } else {
        s32 i1 = last->time;
        if (!(lo < i1)) {
            switch (k->post) {
            case 0: return vals[last->v];
            case 1: return vals[last->v] + (t - times[i1]) * tans[last->tout];
            case 2: {
                f32 a = times[i0];
                f32 b = times[i1];
                f32 d = b - a;
                if (b < t) { do t -= d; while (b < t); time = t; }
                break;
            }
            default: return 0.0f;
            }
            func_001285f8(o, time, &lo, &hi);
        }
    }
    s32 a = k->start;
    s32 b = a + k->cnt - 1;
    while (b - a >= 2) {
        s32 m = (a + b) / 2;
        MKey* km = &keys[m];
        s32 ti = km->time;
        if (times[ti] == time) return vals[km->v];
        if (ti < lo) { a = m; first = km; }
        else if (hi < ti) { b = m; last = km; }
        else if (ti == lo) { first = km; last = km + 1; break; }
        else if (ti == hi) { last = km; first = km - 1; break; }
    }
    u16 type = first->type;
    if (type == 0) return vals[first->v];
    f32 t0 = times[first->time];
    f32 p0 = vals[first->v];
    f32 m0 = tans[first->tout];
    f32 t1 = times[last->time];
    f32 p1 = vals[last->v];
    f32 m1 = tans[last->tin];
    switch (type) {
    case 1: return p0 + (p1 - p0) * (time - t0) / (t1 - t0);
    case 2: return func_001286d0(time, t0, p0, m0, t1, p1, m1);
    }
    return 0.0f;
}
}
