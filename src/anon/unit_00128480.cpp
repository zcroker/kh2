// Linked unit 0x00128480-0x00130d18: motion/skeleton evaluation (one namespace per old matched source).
// In the expression evaluator (0x129060) case 15/43 sits right after case 14, as the retail literal
// order shows (60.0f is pooled before 1.0f).
#include "../common/types.h"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00128480 (was src/anon/batch_w2390.cpp)
namespace n00128480 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Key { QWord h; QWord s; QWord r; QWord t; };
struct Src;
struct SrcVT { u8 pad[0x20]; Key* (*get)(Src*); };
struct Src { SrcVT* vt; };
struct Pose { u8 pad[0x14]; Src* src; u8 pad2[4]; QWord* s; QWord* r; QWord* t; };
struct Chan { u16 bone; u16 ch; f32 val; };
struct Hdr { u8 pad[0x10]; u16 n; u8 pad2[0x24 - 0x12]; s32 off; s32 cnt; };
struct Self { u8 pad[4]; Hdr* hdr; };
// Element j of bone b's channel vector, addressed as bytes.
static inline void set(QWord* a, u16 b, s32 j, f32 v) { *(f32*)((u32)a + (b << 4) + (j << 2)) = v; }
/*TARGET 00128480*/
// 00128480: copies the pose keys (scale/rotation/translation per bone) from the source, then applies
// per-channel overrides (channel 0-2 scale, 3-5 rotation, 6-8 translation xyz).
void func_00128480(Self* self, Pose* p) asm("func_00128480");
// 00128480: copies the pose keys (scale/rotation/translation per bone) from the source, then applies
// per-channel overrides (channel 0-2 scale, 3-5 rotation, 6-8 translation xyz).
void func_00128480(Self* self, Pose* p) {
    Hdr* h = self->hdr;
    s32 n = h->n;
    Key* k = p->src->vt->get(p->src);
    s32 i;
    for (i = 0; i < n; i++, k++) {
        p->s[i] = k->s;
        p->r[i] = k->r;
        p->t[i] = k->t;
    }
    n = h->cnt;
    if (n == 0) return;
    Chan* c = (Chan*)((u8*)h + h->off);
    for (i = 0; i < n; i++, c++) {
        switch (c->ch) {
        case 0: case 1: case 2:
            set(p->s, c->bone, c->ch, c->val);
            break;
        case 3: case 4: case 5:
            set(p->r, c->bone, c->ch - 3, c->val);
            break;
        case 6: case 7: case 8:
            set(p->t, c->bone, c->ch - 6, c->val);
            break;
        }
    }
}
}  // namespace n00128480

// 001285f8 (was src/anon/batch_w87.cpp)
namespace n001285f8 {
// ---- 0x1285f8: binary search of x in a sorted float table -> bracketing indices ----
struct Curve { u8 pad[32]; s32 count; u8 pad2[32]; s32 off; };
/*TARGET 001285f8*/
void func_001285f8(u8* p, f32 x, s32* lo, s32* hi) asm("func_001285f8");
void func_001285f8(u8* p, f32 x, s32* lo, s32* hi) {
    Curve* c = *(Curve**)(p + 4);
    f32* arr = (f32*)((u8*)c + c->off);
    if (arr[c->count - 1] <= x) {
        *lo = c->count - 1;
        *hi = c->count;
        return;
    }
    if (x <= arr[0]) {
        *lo = -1;
        *hi = 0;
        return;
    }
    *lo = 0;
    *hi = c->count - 1;
    while (*hi - *lo > 1) {
        s32 m = (*lo + *hi) / 2;
        if (x < arr[m]) *hi = m;
        else if (arr[m] < x) *lo = m;
        else { *hi = m; *lo = m; return; }
    }
}
}  // namespace n001285f8

// 001286d0 (was src/anon/batch_w51.cpp)
namespace n001286d0 {
/*TARGET 001286d0*/
// Cubic Hermite interpolation between (t0, p0, m0) and (t1, p1, m1).
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1) asm("func_001286d0");
// Cubic Hermite interpolation between (t0, p0, m0) and (t1, p1, m1).
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1) {
    f32 inv = t1 - t0;
    t = t - t0;
    inv = 1.0f / inv;
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 a = t2 * 3.0f;
    f32 inv2 = inv * inv;
    f32 c = t2 * inv;
    f32 b = t3 * inv2;
    a = a * inv2;
    f32 d = (b + b) * inv;
    return p0 * (d - a + 1.0f) + p1 * (a - d) + m0 * (b - (c + c) + t) + m1 * (b - c);
}
}  // namespace n001286d0

// 00128750 (was src/anon/batch_w2356_nsa.cpp)
namespace n00128750 {
// ---- 00128750: animation curve channel evaluation ----
struct MKey { u16 type:2; u16 time:14; u16 v; u16 tin; u16 tout; };
struct MHdr { u8 pad[64]; s32 keyOff; s32 timeOff; s32 valOff; s32 tanOff; };
struct MObj { u32 x; MHdr* h; };
struct MCh { u16 idx; u16 ch:4; u16 pre:2; u16 post:2; u16 cnt:8; u16 start; };
void func_001285f8(MObj*, f32, s32*, s32*) asm("func_001285f8");
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1) asm("func_001286d0");
/*TARGET 00128750*/
/* Evaluate one animation curve channel at time t (lo/hi: bracketing time-table indices). */
f32 func_00128750(MObj* o, MCh* k, s32 lo, s32 hi, f32 t) asm("func_00128750");
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
}  // namespace n00128750

// 00128b38 (was src/anon/batch_w1992.cpp)
namespace n00128b38 {
// ---- 00128b38 ----
struct V4w1992 { f32 v[4]; };
struct M4w1992 { f32 m[4][4]; };
struct Key128b38 { u16 idx; u8 ch:4; u8 hi:4; u8 pad[3]; };
struct Hdr128b38 { u8 pad[0x18]; s32 offM; u8 pad2[0x30 - 0x1c]; s32 off1; s32 n1; s32 off2; s32 n2; };
struct Obj128b38 { u32 x; Hdr128b38* h; };
struct Out128b38 { u8 pad[0x1c]; V4w1992* a; V4w1992* b; V4w1992* c; };
void func_001285f8(Obj128b38*, s32*, s32*) asm("func_001285f8");
f32 func_00128750(Obj128b38*, Key128b38*, s32, s32, f32) asm("func_00128750");
/*TARGET 00128b38*/
void kn__MotionPrototype0__setFcurveValue(Obj128b38* o, Out128b38* out, f32 t) asm("kn__MotionPrototype0__setFcurveValue");
void kn__MotionPrototype0__setFcurveValue(Obj128b38* o, Out128b38* out, f32 t) {
    s32 s0, s1;
    func_001285f8(o, &s0, &s1);
    Hdr128b38* h = o->h;
    Key128b38* k = (Key128b38*)((u8*)h + h->off1);
    s32 n = h->n1;
    for (s32 i = 0; i < n; i++, k++) {
        f32 v = func_00128750(o, k, s0, s1, t);
        switch (k->ch) {
        case 0: case 1: case 2: { u8* q = (u8*)out->a + k->idx * 16; s32 j = k->ch * 4; *(f32*)(q + j) = v; } break;
        case 3: case 4: case 5: { u8* q = (u8*)out->b + k->idx * 16; s32 j = k->ch - 3; s32 j4 = j * 4; *(f32*)(q + j4) = v; } break;
        case 6: case 7: case 8: { u8* q = (u8*)out->c + k->idx * 16; s32 j = k->ch - 6; s32 j4 = j * 4; *(f32*)(q + j4) = v; } break;
        }
    }
    M4w1992* m = (M4w1992*)((u8*)h + h->offM);
    k = (Key128b38*)((u8*)h + h->off2);
    n = h->n2;
    for (s32 i = 0; i < n; i++, k++) {
        f32 v = func_00128750(o, k, s0, s1, t);
        switch (k->ch) {
        case 0: case 1: case 2: { u8* q = (u8*)m + k->idx * 64; s32 j = (k->ch) * 4; *(f32*)(q + j + 16) = v; } break;
        case 3: case 4: case 5: { u8* q = (u8*)m + k->idx * 64; s32 j = k->ch - 3; s32 j4 = j * 4; *(f32*)(q + j4 + 32) = v; } break;
        case 6: case 7: case 8: { u8* q = (u8*)m + k->idx * 64; s32 j = k->ch - 6; s32 j4 = j * 4; *(f32*)(q + j4 + 48) = v; } break;
        }
    }
}
}  // namespace n00128b38

// 00128d40 (was src/anon/batch_w100.cpp)
namespace n00128d40 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
/*TARGET 00128d40*/
void func_00128d40(const QWord* fwd, const QWord* up, QWord* out) asm("func_00128d40");
void func_00128d40(const QWord* fwd, const QWord* up, QWord* out) {  // vec4_copy_normalize
    asm volatile(".set noreorder\n\t.set reorder"); // keeps gas from moving the prologue into the first branch delay slot
    out[0] = *fwd;
    Normalize(&out[0]);
    QWord s;
    s = Cross(*fwd, *up);
    out[1] = Cross(s, *fwd);
    Normalize(&out[1]);
    out[2] = Cross(*fwd, out[1]);
    Normalize(&out[2]);
    out[0].f[3] = out[1].f[3] = out[2].f[3] = 0.0f;
}
}  // namespace n00128d40

// 00128e98 (was src/anon/batch_w1888_nsa.cpp)
namespace n00128e98 {
// func_00128e98: bone midpoint helper (MotCtx/MotPose, see func_0012d728).
struct W1888eV {
    f32 x, y, z, w;
    W1888eV() {}
    W1888eV(const W1888eV& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1888eV& operator=(const W1888eV& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1888eV operator+(const W1888eV& b) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1888eV operator*(f32 k) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1888eM {
    W1888eV r[4];
} __attribute__((aligned(16)));
static inline W1888eV operator*(const W1888eM& m, const W1888eV& v) {
    W1888eV r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
struct W1888eH { u8 pad0[0x10]; u16 boneCount; };
struct W1888eC { u8 pad0[4]; W1888eH* mot; W1888eM* work; W1888eM* localX; W1888eM* worldX; };
struct W1888eP { u8 pad0[0x2c]; W1888eM* world; };
static inline W1888eM* w1888eWorld(W1888eC* ctx, W1888eP* pose, s32 i) {
    W1888eH* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
/*TARGET 00128e98*/
void func_00128e98(W1888eC* ctx, W1888eP* pose, s32 i, s32 j, W1888eV* out, W1888eM* m, W1888eV* out2) asm("func_00128e98");
void func_00128e98(W1888eC* ctx, W1888eP* pose, s32 i, s32 j, W1888eV* out, W1888eM* m, W1888eV* out2)
{
    if (j >= 0) {
        W1888eV a = w1888eWorld(ctx, pose, i)->r[3];
        W1888eV b = w1888eWorld(ctx, pose, j)->r[3];
        *out = (a + b) * 0.5f;
    } else {
        *out = w1888eWorld(ctx, pose, i)->r[3];
    }
    if (m && out2) *out2 = *m * *out;
}
}  // namespace n00128e98

// 00129008 (was src/anon/auto80_199_queue.cpp)
namespace n00129008 {
/*TARGET 00129008*/
u32 func_00129008(u32 a0, u32 a1, u8* a2, u32 a3, u32 a4, u32 a5) asm("_Z13func_00129008jjPhjjj");
u32 func_00129008(u32 a0, u32 a1, u8* a2, u32 a3, u32 a4, u32 a5) {
    u32 t3 = a3;
    u32 t5 = a4;
    u32 t4 = a5;

    u32 out_a3 = -1;
    u32 out_a4 = t3;
    u32 out_a5 = t5;
    u32 out_a6 = t4;

    if (*(u8*)(a2 + 0) == 5) {
        out_a3 = *(u16*)(a2 + 6);
        a2 = (u8*)(u32)(*(u16*)(a2 + 4));
        return func_00128e98(a0, a1, (u32)a2, out_a3, out_a4, out_a5, out_a6);
    }

    a2 = (u8*)(u32)(*(u16*)(a2 + 4));
    return func_00128e98(a0, a1, (u32)a2, out_a3, out_a4, out_a5, out_a6);
}
}  // namespace n00129008

// 00129060 (was src/anon/batch_w2478.cpp)
namespace n00129060 {
// Motion expression evaluator (expression nodes of the motion data; joints, math, logic, curves).

struct MotVec {
    f32 x, y, z, w;
    MotVec() {}
    MotVec(const MotVec& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
static inline MotVec operator-(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct MotMtx {
    MotVec r[4];
} __attribute__((aligned(16)));
struct MotBone {            // 64 bytes: rest pose entry
    u8 pad0[0x10];
    MotVec scale;           // 0x10
    MotVec rot;             // 0x20
    MotVec trans;           // 0x30
};
struct MotNode {            // 12 bytes: expression node
    s8 op;
    u8 world : 1;
    u16 joint;              // 0x02
    f32 value;              // 0x04
    u16 a;                  // 0x08
    u16 b;                  // 0x0a
};
struct MotKey { u8 pad[6]; };
struct MotHeader {
    u8 pad0[0x10];
    u16 boneCount;          // 0x10
    u16 jointCount;         // 0x12
    u8 pad14[4];
    s32 restOff;            // 0x18
    u8 pad1c[0x14];
    s32 keyOffA;            // 0x30
    u32 keyCountA;          // 0x34
    s32 keyOffB;            // 0x38
    u8 pad3c[0x2c];
    s32 nodeOff;            // 0x68
    u32 nodeCount;          // 0x6c
    u8 pad70[0x28];
    f32 frameRate;          // 0x98
};
struct MotPose {
    u8 pad0[0x1c];
    MotVec* scale;          // 0x1c
    MotVec* rot;            // 0x20
    MotVec* trans;          // 0x24
    MotMtx* local;          // 0x28
    MotMtx* world;          // 0x2c
};
struct MotCtx {
    u8 pad0[4];
    MotHeader* mot;         // 0x04
    MotMtx* work;           // 0x08
    MotMtx* localX;         // 0x0c
    MotMtx* worldX;         // 0x10
    MotVec* workScale;      // 0x14
};
static inline MotBone* motRest(MotHeader* m, s32 i) {
    return (MotBone*)((u8*)m + m->restOff) + (i - m->boneCount);
}
static inline MotVec* motRot(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->rot[i];
    return &motRest(m, i)->rot;
}
static inline MotVec* motScale(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->scale[i];
    return &motRest(m, i)->scale;
}
static inline MotMtx* motLocal(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->local[i];
    return &ctx->localX[i - m->boneCount];
}
static inline MotMtx* motWorld(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
extern f32 D_00347b70 asm("D_00347b70");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
f32 func_002f8a18(f32) asm("func_002f8a18");
f32 func_002f8ab8(f32) asm("func_002f8ab8");
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
f32 atanf(f32) asm("atanf");
f32 func_002f8b18(f32) asm("func_002f8b18");
f32 func_002f8ae8(f32) asm("func_002f8ae8");
f32 fabsf(f32) asm("fabsf");
f32 f_powf(f32, f32) asm("f_powf");
f32 func_002f8b00(f32, f32) asm("func_002f8b00");
void func_0011bac8(MotMtx*, MotVec*) asm("func_0011bac8");
void func_001285f8(MotCtx*, f32, s32*, s32*) asm("func_001285f8");
f32 func_00128750(MotCtx*, MotKey*, s32, s32, f32) asm("func_00128750");
/*TARGET 00129060*/
f32 kn__MotionPrototype0__evalExpression(MotCtx* ctx, MotPose* pose, u16 idx) asm("kn__MotionPrototype0__evalExpression");
f32 kn__MotionPrototype0__evalExpression(MotCtx* ctx, MotPose* pose, u16 idx) {
    MotHeader* hdr = ctx->mot;
    f32 r;
    if (idx >= hdr->nodeCount) return 0.0f;
    {
        MotNode* nodes = (MotNode*)((u8*)hdr + hdr->nodeOff);
        MotNode* n = &nodes[idx];
        switch (n->op) {
        case 0: return sinf(kn__MotionPrototype0__evalExpression(ctx, pose, n->a) * 0.017453292f);
        case 1: return cosf(kn__MotionPrototype0__evalExpression(ctx, pose, n->a) * 0.017453292f);
        case 2: return func_002f8a18(kn__MotionPrototype0__evalExpression(ctx, pose, n->a) * 0.017453292f);
        case 3: return func_002f8ab8(kn__MotionPrototype0__evalExpression(ctx, pose, n->a)) * 57.295776f;
        case 4: return acos_2f8aa0(kn__MotionPrototype0__evalExpression(ctx, pose, n->a)) * 57.295776f;
        case 5: return atanf(kn__MotionPrototype0__evalExpression(ctx, pose, n->a)) * 57.295776f;
        case 6: return func_002f8b18(kn__MotionPrototype0__evalExpression(ctx, pose, n->a));
        case 7: return func_002f8ae8(kn__MotionPrototype0__evalExpression(ctx, pose, n->a));
        case 8: return fabsf(kn__MotionPrototype0__evalExpression(ctx, pose, n->a));
        case 9: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return f_powf(a, kn__MotionPrototype0__evalExpression(ctx, pose, n->b));
        }
        case 10: return __builtin_sqrtf(kn__MotionPrototype0__evalExpression(ctx, pose, n->a));
        case 11: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            r = kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
            if (a < r) return a;
            return r;
        }
        case 12: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            f32 b = kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
            if (b < a) return a;
            return b;
        }
        case 13: {
            MotNode* p = &nodes[n->a];
            f32 sum = 0.0f;
            s32 cnt = 0;
            while (p->a < hdr->nodeCount) {
                sum += kn__MotionPrototype0__evalExpression(ctx, pose, p->a);
                cnt++;
                p = &nodes[p->b];
            }
            return sum / cnt;
        }
        case 14:
            if (kn__MotionPrototype0__evalExpression(ctx, pose, nodes[n->a].a) != 0.0f)
                return kn__MotionPrototype0__evalExpression(ctx, pose, nodes[nodes[n->a].b].a);
            return kn__MotionPrototype0__evalExpression(ctx, pose, nodes[nodes[nodes[n->a].b].b].a);
        case 15: case 43: {
            s32 lo, hi;
            f32 t = kn__MotionPrototype0__evalExpression(ctx, pose, n->a) * 60.0f / hdr->frameRate;
            func_001285f8(ctx, t, &lo, &hi);
            MotKey* k;
            if (n->b >= hdr->keyCountA) k = (MotKey*)((u8*)hdr + hdr->keyOffB) + (n->b - hdr->keyCountA);
            else k = (MotKey*)((u8*)hdr + hdr->keyOffA) + n->b;
            r = func_00128750(ctx, k, lo, hi, t);
            if (n->op == 43) r *= 57.295776f;
            return r;
        }
        case 16:
            return (motWorld(ctx, pose, n->a)->r[3] - motWorld(ctx, pose, n->b)->r[3]).length();
        case 17: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return func_002f8b00(a, kn__MotionPrototype0__evalExpression(ctx, pose, n->b));
        }
        case 18: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a + kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
        }
        case 19: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a - kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
        }
        case 20: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a * kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
        }
        case 21: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a / kn__MotionPrototype0__evalExpression(ctx, pose, n->b);
        }
        case 22: {
            s32 a = (s32)kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return (f32)(a % (s32)kn__MotionPrototype0__evalExpression(ctx, pose, n->b));
        }
        case 23: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a == kn__MotionPrototype0__evalExpression(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 24: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a > kn__MotionPrototype0__evalExpression(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 25: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a >= kn__MotionPrototype0__evalExpression(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 26: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a < kn__MotionPrototype0__evalExpression(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 27: {
            f32 a = kn__MotionPrototype0__evalExpression(ctx, pose, n->a);
            return a <= kn__MotionPrototype0__evalExpression(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 28:
            return (kn__MotionPrototype0__evalExpression(ctx, pose, n->a) != 0.0f && kn__MotionPrototype0__evalExpression(ctx, pose, n->b) != 0.0f) ? 1.0f : 0.0f;
        case 29:
            r = (kn__MotionPrototype0__evalExpression(ctx, pose, n->a) != 0.0f || kn__MotionPrototype0__evalExpression(ctx, pose, n->b) != 0.0f) ? 1.0f : 0.0f;
            return r;
        case 30: return D_00347b70;
        case 31: return n->value;
        case 32: case 33: case 34: {
            MotMtx* m = n->world ? motWorld(ctx, pose, n->joint) : motLocal(ctx, pose, n->joint);
            return m->r[3][n->op - 32];
        }
        case 35: case 36: case 37:
            if (n->world) {
                MotVec v(*motRot(ctx, pose, n->joint));
                func_0011bac8(&ctx->work[n->joint], &v);
                return v[n->op - 35] * 57.295776f;
            }
            return (*motRot(ctx, pose, n->joint))[n->op - 35] * 57.295776f;
        case 38: case 39: case 40:
            if (n->world) return ctx->workScale[n->joint][n->op - 38];
            return (*motScale(ctx, pose, n->joint))[n->op - 38];
        case 41: case 42:
            return 0.0f;
        }
    }
    return 0.0f;
}
}  // namespace n00129060

// 00129960 (was src/anon/batch_w2354.cpp)
namespace n00129960 {
struct V129960 {
    f32 x, y, z, w;
    V129960() {}
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V129960(const V129960& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V129960& operator=(const V129960& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void cross(const V129960& a, const V129960& b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
    V129960& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M129960 {
    V129960 r[4];
    M129960& operator=(const M129960& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(M129960*) asm("func_0011b6a8");
/*TARGET 00129960*/
/* Re-orthonormalize a matrix's rotation rows, keeping each row's length;
   when the x row is nearly vertical, rebuild the basis around an up axis. */
void func_00129960(const M129960* src, M129960* dst) asm("func_00129960");
/* Re-orthonormalize a matrix's rotation rows, keeping each row's length;
   when the x row is nearly vertical, rebuild the basis around an up axis. */
void func_00129960(const M129960* src, M129960* dst)
{
    V129960 x(src->r[0]);
    V129960 y(src->r[1]);
    V129960 z(src->r[2]);
    f32 lx = x.normalize();
    f32 ly = y.normalize();
    f32 lz = z.normalize();
    f32 xy = x.y;
    if (0.6499999761581421f <= xy || xy <= -0.6499999761581421f) {
        func_0011b6a8(dst);
        V129960 up;
        if (xy < 0.0f) { up.set(0.0f, -1.0f, 0.0f, 0.0f); dst->r[0] = up; }
        else { up.set(0.0f, 1.0f, 0.0f, 0.0f); dst->r[0] = up; }
        dst->r[2].cross(dst->r[0], y);
        dst->r[2].normalize();
        dst->r[1].cross(dst->r[2], dst->r[0]);
        dst->r[1].normalize();
        dst->r[0] *= lx;
        dst->r[1] *= ly;
        dst->r[2] *= lz;
        dst->r[3] = src->r[3];
    } else {
        *dst = *src;
    }
}
}  // namespace n00129960

// 00129c38 (was src/anon/batch_w1658_nsa.cpp)
namespace n00129c38 {
// Motion joint solver with per-joint scale (sibling of func_0012d728, which is the
// same solver without scale). Types are a copy of batch_w1659_nsa.cpp's, kept in
// namespace mot1 so the two files do not clash; MotCtx gains the accumulated
// scale array (0x14) and MotBone its rest scale (0x10).
// Per joint: expression channels, constraint scan, then one of
//   - 0x200000: plain local rotation (optional rebuild from rot)
//   - mode 1: one-bone IK, mode 2/3: two-bone IK (with optional ground entities)
//   - mode 0: constraint driven (copy/aim) or plain FK
// and finally an optional look-at target.

struct MotVec {
    f32 x, y, z, w;
    MotVec() {}
    MotVec(const MotVec& o) {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    MotVec& operator=(const MotVec& o) {
        if (this != &o) asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void cross(const MotVec& a, const MotVec& b) {
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
} __attribute__((aligned(16)));
static inline MotVec operator-(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline MotVec motLerp(const MotVec& a, const MotVec& b, f32 t) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct MotMtx {
    MotVec r[4];
    MotMtx() {}
    MotMtx(const MotMtx& o) {
        asm volatile(".set noreorder\n\t"
                     "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    MotMtx& operator=(const MotMtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // general 4x4 (affine) inverse in place
    void inverse() {
        asm volatile(".set noreorder\n\t"
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
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
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
} __attribute__((aligned(16)));
static inline MotVec mulElem(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// rows 0..2 of m scaled by s.x, s.y, s.z
static inline void motScaleRows(MotMtx* m, const MotVec* s) {
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\t"
                 "vmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\t"
                 "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\t.set reorder" : : "r"(m), "r"(s) : "memory");
}
static inline MotMtx operator*(const MotMtx& a, const MotMtx& b) {
    MotMtx r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline MotVec operator*(const MotMtx& m, const MotVec& v) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
// out = this * (v.xyz, 1), w = 1
static inline void motXfpt(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "vmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = this * (v.xyz, 1), w kept
static inline void motXfp(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = rotation part * v.xyz
static inline void motRot3(MotVec* out, const MotMtx& mr, const MotVec* v) {
    const MotMtx* m = &mr;
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
                 "sqc2 $vf4, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
struct MotBone {            // 64 bytes: rest pose entry
    s16 index;
    s16 pad2;
    s16 parent;             // 0x04
    s16 pad6;
    u8 pad8[8];
    f32 scale[3];           // 0x10
    f32 len;                // 0x1c
    MotVec rot;             // 0x20
    MotVec trans;           // 0x30
};
struct MotExpr {            // 8 bytes
    u16 joint;
    u16 channel;
    u16 pad4;
    u16 node;
};
struct MotConstraint {      // 12 bytes
    u8 type;
    u8 active;
    u16 joint;
    u16 source;
    u16 limiter;
    u16 pad8;
    u16 padA;
};
struct MotHeader {
    u8 pad0[0x10];
    u16 boneCount;          // 0x10
    u16 jointCount;         // 0x12
    u8 pad14[4];
    s32 restOff;            // 0x18
    s32 jointOff;           // 0x1c
    u8 pad20[0x30];
    s32 constraintOff;      // 0x50
    s32 constraintCount;    // 0x54
    u8 pad58[4];
    s32 limiterOff;         // 0x5c
    s32 exprOff;            // 0x60
    s32 exprCount;          // 0x64
    u8 pad68[0x38];
    s32 tableA0Off;         // 0xa0
};
struct MotSkel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual f32 slotValue(s32);     // vtable + 0x14
    virtual s32 slotJoint(s32);     // vtable + 0x18
    virtual void v7();
    virtual MotBone* getBones();    // vtable + 0x20
};
struct MotPose {
    u8 pad0[0x14];
    MotSkel* skel;          // 0x14
    u8 pad18[4];
    MotVec* scale;          // 0x1c
    MotVec* rot;            // 0x20
    MotVec* trans;          // 0x24
    MotMtx* local;          // 0x28
    MotMtx* world;          // 0x2c
};
struct MotCtx {
    u8 pad0[4];
    MotHeader* mot;         // 0x04
    MotMtx* work;           // 0x08 world matrices, all joints
    MotMtx* localX;         // 0x0c local matrices of the extra (non-skeleton) joints
    MotMtx* worldX;         // 0x10 world matrices of the extra joints
    MotVec* scl;            // 0x14 accumulated scale, all joints
};
struct MotTarget {          // look-at target
    MotVec pos;             // w = blend
    union {
        u64 flags;          // 0x10000: pos is a direction
        u16 joint;
    } u;
};
struct MotEnt {             // 0x20: ground/contact entity list, ends with flag bit 53
    MotVec pos;
    union {
        u64 flags;
        u32 lo;
    } u;                    // 0x10
    f32 yofs;               // 0x18
    u16 joint;              // 0x1c
    u16 pad1e;
};
void func_0011b6a8(MotMtx*) asm("func_0011b6a8");
u32 FMatrix_rotateX(MotMtx*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void FMatrix_rotateXYZ(MotMtx*, MotVec*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_0011bac8(MotMtx*, MotVec*) asm("func_0011bac8");
void gm__GRID__draw(MotVec*, MotVec*, s32, f32, f32, MotMtx*, MotMtx*, f32, f32, MotVec*) asm("gm__GRID__draw");
void func_00128040(MotCtx*, void*, MotVec*, MotVec*) asm("func_00128040");
void func_00128d40(MotVec*, MotVec*, MotMtx*) asm("func_00128d40");
void func_00128e98(MotCtx*, MotPose*, u32, u32, MotVec*, MotMtx*, MotVec*) asm("func_00128e98");
void func_00129008(MotCtx*, MotPose*, MotConstraint*, MotVec*, MotMtx*, MotVec*) asm("func_00129008");
f32 kn__MotionPrototype0__evalExpression(MotCtx*, MotPose*, u16) asm("kn__MotionPrototype0__evalExpression");
void func_00129960(MotMtx*, MotMtx*) asm("func_00129960");
s32 func_00143c68(MotVec*, MotVec*) asm("func_00143c68");
static inline MotBone* motRest(MotHeader* m, s32 i) {
    return (MotBone*)((u8*)m + m->restOff) + (i - m->boneCount);
}
static inline MotBone* motBone(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return pose->skel->getBones() + i;
    return motRest(m, i);
}
static inline MotVec* motScl(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->scale[i];
    return (MotVec*)motRest(m, i)->scale;
}
static inline MotVec* motWScl(MotCtx* ctx, s32 i) { return &ctx->scl[i]; }
static inline f32 motScaled(const MotVec* s, MotBone* b) { return s->x * b->len; }
static inline MotVec* motRot(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->rot[i];
    return &motRest(m, i)->rot;
}
static inline MotVec* motTrans(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->trans[i];
    return &motRest(m, i)->trans;
}
static inline MotMtx* motLocal(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->local[i];
    return &ctx->localX[i - m->boneCount];
}
static inline MotMtx* motWorld(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
static inline void motSetRot(MotMtx* m, MotVec* r) { func_0011bac8(m, r); }
static inline void motRotXYZ(MotMtx* m, MotVec* r) { FMatrix_rotateXYZ(m, r); }
static inline void motIK2(MotVec* a, MotVec* b, f32 l1, f32 l2, MotMtx* m1, MotMtx* m2, f32& r1, f32& r2, s32 type, MotVec* pole) {
    gm__GRID__draw(a, b, type, l1, l2, m1, m2, r1, r2, pole);
}
static inline void motIK1(MotVec* a, MotVec* b, f32 l1, MotMtx* m1, f32& r1, MotVec* pole) {
    gm__GRID__draw(a, b, 0, l1, 0.0f, m1, 0, r1, 0.0f, pole);
}
static inline void motLimit(MotCtx* ctx, void* lim, MotVec v, MotVec* io) { func_00128040(ctx, lim, &v, io); }
static inline bool motIsEndType(s32 t) {
    switch (t) {
    case 0: case 1: case 5:
        return true;
    }
    return false;
}
/*TARGET 00129c38*/
void func_00129c38(MotCtx* ctx, MotPose* pose, MotMtx* base, MotTarget* tgt, MotEnt* ents) asm("func_00129c38");
void func_00129c38(MotCtx* ctx, MotPose* pose, MotMtx* base, MotTarget* tgt, MotEnt* ents) {
    MotMtx m0;
    MotMtx m40;
    MotVec v80;
    MotVec v90;
    MotVec vA0;
    MotVec vB0;
    MotVec vC0;
    MotHeader* mot;
    u32* joints;
    MotConstraint* con;
    MotConstraint* conEnd;
    MotExpr* expr;
    MotExpr* exprEnd;
    s16* tblA0;
    s32 n;

    mot = ctx->mot;
    joints = (u32*)((u8*)mot + mot->jointOff);
    con = (MotConstraint*)((u8*)mot + mot->constraintOff);
    conEnd = con + mot->constraintCount;
    expr = (MotExpr*)((u8*)mot + mot->exprOff);
    exprEnd = expr + mot->exprCount;
    tblA0 = (s16*)((u8*)mot + mot->tableA0Off);
    func_0011b6a8(&m0);
    for (n = 0; n < mot->jointCount; n++, joints++) {
        u32 flags = *joints;
        s32 idx = flags & 0xffff;
        s32 parent = motBone(ctx, pose, idx)->parent;

        while (expr != exprEnd && expr->joint == (u16)idx) {
                f32 v = kn__MotionPrototype0__evalExpression(ctx, pose, expr->node);
                switch (expr->channel) {
                case 0: case 1: case 2:
                    (*motScl(ctx, pose, idx))[expr->channel] = v;
                    break;
                case 3: case 4: case 5:
                    (*motRot(ctx, pose, idx))[expr->channel - 3] = v * 0.017453292f;
                    break;
                case 6: case 7: case 8:
                    (*motTrans(ctx, pose, idx))[expr->channel - 6] = v;
                    break;
                }
                expr++;
                flags &= ~0x200000;
            }

        MotConstraint* cA;
        MotConstraint* cB;
        MotConstraint* cS;
        MotConstraint* cT;
        u8* lim0;
        u32 srcA, srcB, srcL;
        MotMtx m;
        MotVec v110;
        cA = 0; srcA = (u32)-1;
        cB = 0; srcB = (u32)-1;
        lim0 = 0; srcL = (u32)-1;
        cS = 0;
        while (con != conEnd && con->joint == (u16)idx) {
            {
                if (con->active) {
                    switch (con->type) {
                    case 0:
                        if (srcA == (u32)-1) srcA = con->source;
                        else if (srcB == (u32)-1) srcB = con->source;
                        break;
                    case 2:
                        cA = con;
                        break;
                    case 3:
                        cA = con;
                        break;
                    case 4:
                        cA = con;
                        break;
                    case 5:
                        srcA = con->source;
                        srcB = con->limiter;
                        cA = con;
                        break;
                    case 6:
                        cS = con;
                        break;
                    case 12:
                        lim0 = (u8*)mot + mot->limiterOff + con->limiter * 0x30;
                        srcL = con->source;
                        break;
                    case 13:
                        cB = (MotConstraint*)((u8*)mot + mot->limiterOff + con->limiter * 0x30);
                        break;
                    }
                }
                con++;
            }
        }

        cT = 0;
        if (flags & 0x30000) {
            s32 j;
            if (flags & 0x800000) j = *tblA0++;
            else j = (flags & 0x30000) == 0x10000 ? idx + 1 : idx + 2;
            while (con != conEnd) {
                if (con->active && con->joint == j && motIsEndType(con->type)) {
                    cT = con++;
                    break;
                }
                con++;
            }
            if (!cT) flags &= ~0x30000;
        }

        if (cS) {
            *motWScl(ctx, idx) = *motWScl(ctx, cS->source);
            if (parent >= 0) {
                motScl(ctx, pose, idx)->x = motWScl(ctx, idx)->x / motWScl(ctx, parent)->x;
                motScl(ctx, pose, idx)->y = motWScl(ctx, idx)->y / motWScl(ctx, parent)->y;
                motScl(ctx, pose, idx)->z = motWScl(ctx, idx)->z / motWScl(ctx, parent)->z;
            } else {
                *motScl(ctx, pose, idx) = *motWScl(ctx, idx);
            }
        } else {
            if (parent >= 0) *motWScl(ctx, idx) = mulElem(*motWScl(ctx, parent), *motScl(ctx, pose, idx));
            else *motWScl(ctx, idx) = *motScl(ctx, pose, idx);
        }

        if (flags & 0x200000) {
            if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
        } else {
            f32 yofs;
            MotEnt* ent;
            s32 found;
            s32 flip;
            yofs = 0.0f;
            ent = 0;
            found = 0;
            flip = 0;
            switch (flags >> 16 & 3) {
            case 1: {
                v90 = *motTrans(ctx, pose, idx);
                v90.w = 1.0f;
                v80 = *motWorld(ctx, pose, parent) * v90;
                m40 = ctx->work[parent];
                m40.invOrtho();
                vA0 = m40 * v80;
                func_00129008(ctx, pose, cT, &v110, &m40, &vB0);
                MotVec v120;
                if (cA && cA->type == 4) {
                    motXfpt(&v120, &m40, &motWorld(ctx, pose, cA->source)->r[3]);
                    motIK1(&vA0, &vB0, motScaled(motWScl(ctx, idx), motBone(ctx, pose, idx)), motLocal(ctx, pose, idx), motRot(ctx, pose, idx)->x, &v120);
                } else {
                    motIK1(&vA0, &vB0, motScaled(motWScl(ctx, idx), motBone(ctx, pose, idx)), motLocal(ctx, pose, idx), motRot(ctx, pose, idx)->x, 0);
                }
                if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                motLocal(ctx, pose, idx)->r[3].x = v90.x;
                ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motScaleRows(motWorld(ctx, pose, idx), motWScl(ctx, idx));
                motWorld(ctx, pose, idx)->r[3] = v80;
                {
                    motXfpt(&motWorld(ctx, pose, cT->joint)->r[3], motWorld(ctx, pose, idx), motTrans(ctx, pose, cT->joint));
                }
                break;
            }
            case 2: case 3: {
                if (cA && cA->type != 4) cA = 0;
                v90 = *motTrans(ctx, pose, idx);
                v90.w = 1.0f;
                v80 = *motWorld(ctx, pose, parent) * v90;
                m40 = ctx->work[parent];
                m40.invOrtho();
                vA0 = m40 * v80;
                while (con != conEnd && con->joint == (u16)(idx + 1)) con++;
                ctx->scl[idx + 1] = mulElem(*motWScl(ctx, idx), *motScl(ctx, pose, idx + 1));
                func_00129008(ctx, pose, cT, &vC0, &m40, &vB0);
                if (ents) {
                    ent = ents;
                    while (!(ent->u.flags & (1ULL << 53))) {
                        if (ent->joint == (u16)idx) {
                            s32 k;
                            found = 1;
                            flip = (u32)(ent->u.flags >> 52) & 1;
                            for (k = 32; k < 36; k++) {
                                if (idx == pose->skel->slotJoint(k)) {
                                    yofs = pose->skel->slotValue(k - 32);
                                    break;
                                }
                            }
                            if (ent->u.flags & (1ULL << 51)) yofs = ent->yofs;
                            break;
                        }
                        ent++;
                    }
                }
                if (found) {
                    MotVec v120;
                    MotVec v130;
                    v130 = *base * vC0;
                    v130.y += yofs;
                    v120 = v130;
                    v120[1] -= motScaled(&ctx->scl[idx + 1], motBone(ctx, pose, idx + 1)) + yofs;
                    if (flip) v130[1] += motScaled(&ctx->scl[idx + 1], motBone(ctx, pose, idx + 1)) + yofs;
                    MotVec v140;
                    if (func_00143c68(&v120, &v140)) {
                        ent->u.lo |= 1;
                        ent->pos = v140;
                        MotMtx inv = *base;
                        inv.inverse();
                        v140.y -= yofs;
                        motXfp(&vC0, &inv, &v140);
                        motXfpt(&vB0, &m40, &vC0);
                    }
                }
                if (cA) {
                    MotVec v120;
                    motXfpt(&v120, &m40, &motWorld(ctx, pose, cA->source)->r[3]);
                    motIK2(&vA0, &vB0, motScaled(motWScl(ctx, idx), motBone(ctx, pose, idx)), motScaled(&ctx->scl[idx + 1], motBone(ctx, pose, idx + 1)),
                           motLocal(ctx, pose, idx), motLocal(ctx, pose, idx + 1),
                           motRot(ctx, pose, idx)->x, motRot(ctx, pose, idx + 1)->x, (flags >> 16 & 3) - 2, &v120);
                } else {
                    motIK2(&vA0, &vB0, motScaled(motWScl(ctx, idx), motBone(ctx, pose, idx)), motScaled(&ctx->scl[idx + 1], motBone(ctx, pose, idx + 1)),
                           motLocal(ctx, pose, idx), motLocal(ctx, pose, idx + 1),
                           motRot(ctx, pose, idx)->x, motRot(ctx, pose, idx + 1)->x, (flags >> 16 & 3) - 2, 0);
                }
                if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                motLocal(ctx, pose, idx)->r[3].x = v90.x;
                ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motScaleRows(motWorld(ctx, pose, idx), motWScl(ctx, idx));
                motWorld(ctx, pose, idx)->r[3] = v80;
                motLocal(ctx, pose, idx + 1)->r[3][0] = motBone(ctx, pose, idx)->len;
                ctx->work[idx + 1] = ctx->work[idx] * *motLocal(ctx, pose, idx + 1);
                *motWorld(ctx, pose, idx + 1) = ctx->work[idx + 1];
                motScaleRows(motWorld(ctx, pose, idx + 1), &ctx->scl[idx + 1]);
                motXfpt(&motWorld(ctx, pose, idx + 1)->r[3], motWorld(ctx, pose, idx), &motLocal(ctx, pose, idx + 1)->r[3]);
                {
                    motXfpt(&motWorld(ctx, pose, cT->joint)->r[3], motWorld(ctx, pose, idx + 1), motTrans(ctx, pose, cT->joint));
                }
                break;
            }
            default: {
                if (srcA != (u32)-1 || srcB != srcA || cA || (flags & 0xc0000) || lim0 || cB) {
                    if (parent < 0) m40 = m0;
                    else m40 = *motWorld(ctx, pose, parent);
                    m40.inverse();
                }
                if (flags & 0x40000) {
                    v80 = motWorld(ctx, pose, idx)->r[3];
                    v80.w = 1.0f;
                    v90 = m40 * v80;
                    v90.w = 1.0f;
                } else {
                    if (srcA != (u32)-1 || srcB != srcA) {
                        func_00128e98(ctx, pose, srcA, srcB, &v80, &m40, &v90);
                        v90.w = 1.0f;
                        if (lim0) {
                            MotVec t = m40 * motWorld(ctx, pose, srcL)->r[3];
                            motLimit(ctx, lim0, t, &v90);
                            if (parent < 0) v80 = m0 * v90;
                            else v80 = *motWorld(ctx, pose, parent) * v90;
                        }
                        v80.w = 1.0f;
                    } else {
                        v90 = *motTrans(ctx, pose, idx);
                        v90.w = 1.0f;
                        if (lim0) {
                            MotVec t = m40 * motWorld(ctx, pose, srcL)->r[3];
                            motLimit(ctx, lim0, t, &v90);
                        }
                        if (parent < 0) v80 = m0 * v90;
                        else v80 = *motWorld(ctx, pose, parent) * v90;
                        v80.w = 1.0f;
                    }
                }
                if (cA) {
                    switch (cA->type) {
                    case 2:
                        ctx->work[idx] = ctx->work[cA->source];
                        break;
                    case 3: case 5: {
                        MotVec v120;
                        MotVec v130;
                        MotMtx rx;
                        u16 src = cA->type == 3 ? cA->source : cA->limiter;
                        vB0 = m40 * motWorld(ctx, pose, src)->r[3];
                        v120 = vB0 - v90;
                        v130.x = 0.0f;
                        v130.z = 0.0f;
                        v130.y = 1.0f;
                        func_00128d40(&v120, &v130, motLocal(ctx, pose, idx));
                        func_0011b6a8(&rx);
                        FMatrix_rotateX(&rx, motRot(ctx, pose, idx)->x);
                        *motLocal(ctx, pose, idx) = *motLocal(ctx, pose, idx) * rx;
                        motLocal(ctx, pose, idx)->r[3] = v90;
                        if (parent < 0) ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
                        else ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                        break;
                    }
                    }
                } else {
                    func_0011b6a8(motLocal(ctx, pose, idx));
                    if (cB) {
                        motLimit(ctx, cB, *motRot(ctx, pose, idx), motRot(ctx, pose, idx));
                    }
                    motRotXYZ(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                    motLocal(ctx, pose, idx)->r[3] = v90;
                    if (parent < 0 || (flags & 0x80000)) ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
                    else ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                }
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motScaleRows(motWorld(ctx, pose, idx), motWScl(ctx, idx));
                motWorld(ctx, pose, idx)->r[3] = v80;
                if (cA || (flags & 0x80000)) {
                    if (parent < 0) m40 = m0;
                    else m40 = ctx->work[parent];
                    m40.invOrtho();
                    *motLocal(ctx, pose, idx) = m40 * ctx->work[idx];
                    motLocal(ctx, pose, idx)->r[3] = v90;
                    if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                }
                break;
            }
            }
        }

        if (tgt && tgt->u.joint == idx) {
            m = *motLocal(ctx, pose, idx);
            if (!(tgt->u.flags & 0x10000)) {
                if (parent >= 0) {
                    m40 = *base * *motWorld(ctx, pose, parent);
                    v80 = *motWorld(ctx, pose, parent) * m.r[3];
                } else {
                    m40 = *base;
                    v80 = m0 * m.r[3];
                }
                m40.inverse();
                motXfpt(&vB0, &m40, &tgt->pos);
                v110 = vB0 - m.r[3];
                v110.normalize();
            } else {
                if (parent >= 0) {
                    MotMtx s;
                    m40 = *motWorld(ctx, pose, parent);
                    func_00129960(motWorld(ctx, pose, parent), &s);
                    v80 = *motWorld(ctx, pose, parent) * m.r[3];
                    m40.inverse();
                    motRot3(&v110, m40 * s, &tgt->pos);
                } else {
                    v80 = m0 * m.r[3];
                    v110 = tgt->pos;
                }
                v110.w = 0.0f;
            }
            m.r[1] = motLerp(m.r[1], v110, tgt->pos.w);
            m.r[1].normalize();
            m.r[2].cross(m.r[0], m.r[1]);
            m.r[2].normalize();
            m.r[0].cross(m.r[1], m.r[2]);
            m.r[0].normalize();
            m.r[2].cross(m.r[0], m.r[1]);
            m.r[2].normalize();
            *motLocal(ctx, pose, idx) = m;
            if (parent >= 0) ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
            else ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
            *motWorld(ctx, pose, idx) = ctx->work[idx];
            motScaleRows(motWorld(ctx, pose, idx), motWScl(ctx, idx));
            motWorld(ctx, pose, idx)->r[3] = v80;
        }
    }
}
}  // namespace n00129c38

// 0012d728 (was src/anon/batch_w1659_nsa.cpp)
namespace n0012d728 {
// Motion joint solver, second variant (sibling of func_00129c38).
// Per joint: expression channels, constraint scan, then one of
//   - 0x200000: plain local rotation (optional rebuild from rot)
//   - mode 1: one-bone IK, mode 2/3: two-bone IK (with optional ground entities)
//   - mode 0: constraint driven (copy/aim) or plain FK
// and finally an optional look-at target.

struct MotVec {
    f32 x, y, z, w;
    MotVec() {}
    MotVec(const MotVec& o) {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    MotVec& operator=(const MotVec& o) {
        if (this != &o) asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void cross(const MotVec& a, const MotVec& b) {
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
} __attribute__((aligned(16)));
static inline MotVec operator-(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline MotVec motLerp(const MotVec& a, const MotVec& b, f32 t) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct MotMtx {
    MotVec r[4];
    MotMtx() {}
    MotMtx(const MotMtx& o) {
        asm volatile(".set noreorder\n\t"
                     "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    MotMtx& operator=(const MotMtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // general 4x4 (affine) inverse in place
    void inverse() {
        asm volatile(".set noreorder\n\t"
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
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
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
} __attribute__((aligned(16)));
static inline MotMtx operator*(const MotMtx& a, const MotMtx& b) {
    MotMtx r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline MotVec operator*(const MotMtx& m, const MotVec& v) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
// out = this * (v.xyz, 1), w = 1
static inline void motXfpt(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "vmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = this * (v.xyz, 1), w kept
static inline void motXfp(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = rotation part * v.xyz
static inline void motRot3(MotVec* out, const MotMtx& mr, const MotVec* v) {
    const MotMtx* m = &mr;
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
                 "sqc2 $vf4, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
struct MotBone {            // 64 bytes: rest pose entry
    s16 index;
    s16 pad2;
    s16 parent;             // 0x04
    s16 pad6;
    u8 pad8[0x14];
    f32 len;                // 0x1c
    MotVec rot;             // 0x20
    MotVec trans;           // 0x30
};
struct MotExpr {            // 8 bytes
    u16 joint;
    u16 channel;
    u16 pad4;
    u16 node;
};
struct MotConstraint {      // 12 bytes
    u8 type;
    u8 active;
    u16 joint;
    u16 source;
    u16 limiter;
    u16 pad8;
    u16 padA;
};
struct MotHeader {
    u8 pad0[0x10];
    u16 boneCount;          // 0x10
    u16 jointCount;         // 0x12
    u8 pad14[4];
    s32 restOff;            // 0x18
    s32 jointOff;           // 0x1c
    u8 pad20[0x30];
    s32 constraintOff;      // 0x50
    s32 constraintCount;    // 0x54
    u8 pad58[4];
    s32 limiterOff;         // 0x5c
    s32 exprOff;            // 0x60
    s32 exprCount;          // 0x64
    u8 pad68[0x38];
    s32 tableA0Off;         // 0xa0
};
struct MotSkel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual f32 slotValue(s32);     // vtable + 0x14
    virtual s32 slotJoint(s32);     // vtable + 0x18
    virtual void v7();
    virtual MotBone* getBones();    // vtable + 0x20
};
struct MotPose {
    u8 pad0[0x14];
    MotSkel* skel;          // 0x14
    u8 pad18[4];
    MotVec* scale;          // 0x1c
    MotVec* rot;            // 0x20
    MotVec* trans;          // 0x24
    MotMtx* local;          // 0x28
    MotMtx* world;          // 0x2c
};
struct MotCtx {
    u8 pad0[4];
    MotHeader* mot;         // 0x04
    MotMtx* work;           // 0x08 world matrices, all joints
    MotMtx* localX;         // 0x0c local matrices of the extra (non-skeleton) joints
    MotMtx* worldX;         // 0x10 world matrices of the extra joints
};
struct MotTarget {          // look-at target
    MotVec pos;             // w = blend
    union {
        u64 flags;          // 0x10000: pos is a direction
        u16 joint;
    } u;
};
struct MotEnt {             // 0x20: ground/contact entity list, ends with flag bit 53
    MotVec pos;
    union {
        u64 flags;
        u32 lo;
    } u;                    // 0x10
    f32 yofs;               // 0x18
    u16 joint;              // 0x1c
    u16 pad1e;
};
void func_0011b6a8(MotMtx*) asm("func_0011b6a8");
u32 FMatrix_rotateX(MotMtx*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void FMatrix_rotateXYZ(MotMtx*, MotVec*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_0011bac8(MotMtx*, MotVec*) asm("func_0011bac8");
void gm__GRID__draw(MotVec*, MotVec*, s32, f32, f32, MotMtx*, MotMtx*, f32, f32, MotVec*) asm("gm__GRID__draw");
void func_00128040(MotCtx*, void*, MotVec*, MotVec*) asm("func_00128040");
void func_00128d40(MotVec*, MotVec*, MotMtx*) asm("func_00128d40");
void func_00128e98(MotCtx*, MotPose*, u32, u32, MotVec*, MotMtx*, MotVec*) asm("func_00128e98");
void func_00129008(MotCtx*, MotPose*, MotConstraint*, MotVec*, MotMtx*, MotVec*) asm("func_00129008");
f32 kn__MotionPrototype0__evalExpression(MotCtx*, MotPose*, u16) asm("kn__MotionPrototype0__evalExpression");
void func_00129960(MotMtx*, MotMtx*) asm("func_00129960");
s32 func_00143c68(MotVec*, MotVec*) asm("func_00143c68");
static inline MotBone* motRest(MotHeader* m, s32 i) {
    return (MotBone*)((u8*)m + m->restOff) + (i - m->boneCount);
}
static inline MotBone* motBone(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return pose->skel->getBones() + i;
    return motRest(m, i);
}
static inline MotVec* motRot(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->rot[i];
    return &motRest(m, i)->rot;
}
static inline MotVec* motTrans(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->trans[i];
    return &motRest(m, i)->trans;
}
static inline MotMtx* motLocal(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->local[i];
    return &ctx->localX[i - m->boneCount];
}
static inline MotMtx* motWorld(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
static inline void motSetRot(MotMtx* m, MotVec* r) { func_0011bac8(m, r); }
static inline void motRotXYZ(MotMtx* m, MotVec* r) { FMatrix_rotateXYZ(m, r); }
static inline void motIK2(MotVec* a, MotVec* b, f32& l1, f32& l2, MotMtx* m1, MotMtx* m2, f32& r1, f32& r2, s32 type, MotVec* pole) {
    gm__GRID__draw(a, b, type, l1, l2, m1, m2, r1, r2, pole);
}
static inline void motIK1(MotVec* a, MotVec* b, f32& l1, MotMtx* m1, f32& r1, MotVec* pole) {
    gm__GRID__draw(a, b, 0, l1, 0.0f, m1, 0, r1, 0.0f, pole);
}
static inline void motLimit(MotCtx* ctx, void* lim, MotVec v, MotVec* io) { func_00128040(ctx, lim, &v, io); }
static inline bool motIsEndType(s32 t) {
    switch (t) {
    case 0: case 1: case 5:
        return true;
    }
    return false;
}
/*TARGET 0012d728*/
void func_0012d728(MotCtx* ctx, MotPose* pose, MotMtx* base, MotTarget* tgt, MotEnt* ents) asm("func_0012d728");
void func_0012d728(MotCtx* ctx, MotPose* pose, MotMtx* base, MotTarget* tgt, MotEnt* ents) {
    MotMtx m0;
    MotMtx m40;
    MotVec v80;
    MotVec v90;
    MotVec vA0;
    MotVec vB0;
    MotVec vC0;
    MotHeader* mot;
    u32* joints;
    MotConstraint* con;
    MotConstraint* conEnd;
    MotExpr* expr;
    MotExpr* exprEnd;
    s16* tblA0;
    s32 n;

    mot = ctx->mot;
    joints = (u32*)((u8*)mot + mot->jointOff);
    con = (MotConstraint*)((u8*)mot + mot->constraintOff);
    conEnd = con + mot->constraintCount;
    expr = (MotExpr*)((u8*)mot + mot->exprOff);
    exprEnd = expr + mot->exprCount;
    tblA0 = (s16*)((u8*)mot + mot->tableA0Off);
    func_0011b6a8(&m0);
    for (n = 0; n < mot->jointCount; n++, joints++) {
        u32 flags = *joints;
        s32 idx = flags & 0xffff;
        s32 parent = motBone(ctx, pose, idx)->parent;

        while (expr != exprEnd && expr->joint == (u16)idx) {
                f32 v = kn__MotionPrototype0__evalExpression(ctx, pose, expr->node);
                switch (expr->channel) {
                case 6: case 7: case 8:
                    (*motTrans(ctx, pose, idx))[expr->channel - 6] = v;
                    break;
                case 3: case 4: case 5:
                    (*motRot(ctx, pose, idx))[expr->channel - 3] = v * 0.017453292f;
                    break;
                }
                expr++;
                flags &= ~0x200000;
            }

        MotConstraint* cA;
        MotConstraint* cB;
        MotConstraint* cT;
        u8* lim0;
        u32 srcA, srcB, srcL;
        MotMtx m;
        MotVec v110;
        cA = 0; srcA = (u32)-1;
        cB = 0; srcB = (u32)-1;
        lim0 = 0; srcL = (u32)-1;
        if (con != conEnd && con->joint == (u16)idx) {
            do {
                if (con->active) {
                    switch (con->type) {
                    case 0:
                        if (srcA == (u32)-1) srcA = con->source;
                        else if (srcB == (u32)-1) srcB = con->source;
                        break;
                    case 2: case 3: case 4:
                        cA = con;
                        break;
                    case 5:
                        srcA = con->source;
                        srcB = con->limiter;
                        cA = con;
                        break;
                    case 12:
                        lim0 = (u8*)mot + mot->limiterOff + con->limiter * 0x30;
                        srcL = con->source;
                        break;
                    case 13:
                        cB = (MotConstraint*)((u8*)mot + mot->limiterOff + con->limiter * 0x30);
                        break;
                    }
                }
                con++;
            } while (con != conEnd && con->joint == (u16)idx);
        }

        cT = 0;
        if (flags & 0x30000) {
            s32 j;
            if (flags & 0x800000) j = *tblA0++;
            else j = (flags & 0x30000) == 0x10000 ? idx + 1 : idx + 2;
            while (con != conEnd) {
                if (con->active && con->joint == j && motIsEndType(con->type)) {
                    cT = con++;
                    break;
                }
                con++;
            }
            if (!cT) flags &= ~0x30000;
        }

        if (flags & 0x200000) {
            if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
        } else {
            f32 yofs;
            MotEnt* ent;
            s32 found;
            s32 flip;
            yofs = 0.0f;
            ent = 0;
            found = 0;
            flip = 0;
            switch (flags >> 16 & 3) {
            case 1: {
                v90 = *motTrans(ctx, pose, idx);
                v90.w = 1.0f;
                v80 = *motWorld(ctx, pose, parent) * v90;
                m40 = ctx->work[parent];
                m40.invOrtho();
                vA0 = m40 * v80;
                func_00129008(ctx, pose, cT, &v110, &m40, &vB0);
                MotVec v120;
                if (cA && cA->type == 4) {
                    motXfpt(&v120, &m40, &motWorld(ctx, pose, cA->source)->r[3]);
                    motIK1(&vA0, &vB0, motBone(ctx, pose, idx)->len, motLocal(ctx, pose, idx), motRot(ctx, pose, idx)->x, &v120);
                } else {
                    motIK1(&vA0, &vB0, motBone(ctx, pose, idx)->len, motLocal(ctx, pose, idx), motRot(ctx, pose, idx)->x, 0);
                }
                if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                motLocal(ctx, pose, idx)->r[3].x = v90.x;
                ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motWorld(ctx, pose, idx)->r[3] = v80;
                {
                    motXfpt(&motWorld(ctx, pose, cT->joint)->r[3], motWorld(ctx, pose, idx), motTrans(ctx, pose, cT->joint));
                }
                break;
            }
            case 2: case 3: {
                if (cA && cA->type != 4) cA = 0;
                v90 = *motTrans(ctx, pose, idx);
                v90.w = 1.0f;
                v80 = *motWorld(ctx, pose, parent) * v90;
                m40 = ctx->work[parent];
                m40.invOrtho();
                vA0 = m40 * v80;
                while (con != conEnd && con->joint == (u16)(idx + 1)) con++;
                func_00129008(ctx, pose, cT, &vC0, &m40, &vB0);
                if (ents) {
                    ent = ents;
                    while (!(ent->u.flags & (1ULL << 53))) {
                        if (ent->joint == (u16)idx) {
                            s32 k;
                            found = 1;
                            flip = (u32)(ent->u.flags >> 52) & 1;
                            for (k = 32; k < 36; k++) {
                                if (idx == pose->skel->slotJoint(k)) {
                                    yofs = pose->skel->slotValue(k - 32);
                                    break;
                                }
                            }
                            if (ent->u.flags & (1ULL << 51)) yofs = ent->yofs;
                            break;
                        }
                        ent++;
                    }
                }
                if (found) {
                    MotVec v120;
                    MotVec v130;
                    v130 = *base * vC0;
                    v130.y += yofs;
                    v120 = v130;
                    v120[1] -= motBone(ctx, pose, idx + 1)->len + yofs;
                    if (flip) v130[1] += motBone(ctx, pose, idx + 1)->len + yofs;
                    MotVec v140;
                    if (func_00143c68(&v120, &v140)) {
                        ent->u.lo |= 1;
                        ent->pos = v140;
                        MotMtx inv = *base;
                        inv.inverse();
                        v140.y -= yofs;
                        motXfp(&vC0, &inv, &v140);
                        motXfpt(&vB0, &m40, &vC0);
                    }
                }
                if (cA) {
                    MotVec v120;
                    motXfpt(&v120, &m40, &motWorld(ctx, pose, cA->source)->r[3]);
                    motIK2(&vA0, &vB0, motBone(ctx, pose, idx)->len, motBone(ctx, pose, idx + 1)->len,
                           motLocal(ctx, pose, idx), motLocal(ctx, pose, idx + 1),
                           motRot(ctx, pose, idx)->x, motRot(ctx, pose, idx + 1)->x, (flags >> 16 & 3) - 2, &v120);
                } else {
                    motIK2(&vA0, &vB0, motBone(ctx, pose, idx)->len, motBone(ctx, pose, idx + 1)->len,
                           motLocal(ctx, pose, idx), motLocal(ctx, pose, idx + 1),
                           motRot(ctx, pose, idx)->x, motRot(ctx, pose, idx + 1)->x, (flags >> 16 & 3) - 2, 0);
                }
                if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                motLocal(ctx, pose, idx)->r[3].x = v90.x;
                ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motWorld(ctx, pose, idx)->r[3] = v80;
                motLocal(ctx, pose, idx + 1)->r[3][0] = motBone(ctx, pose, idx)->len;
                ctx->work[idx + 1] = ctx->work[idx] * *motLocal(ctx, pose, idx + 1);
                *motWorld(ctx, pose, idx + 1) = ctx->work[idx + 1];
                motXfpt(&motWorld(ctx, pose, idx + 1)->r[3], motWorld(ctx, pose, idx), &motLocal(ctx, pose, idx + 1)->r[3]);
                {
                    motXfpt(&motWorld(ctx, pose, cT->joint)->r[3], motWorld(ctx, pose, idx + 1), motTrans(ctx, pose, cT->joint));
                }
                break;
            }
            default: {
                if (srcA != (u32)-1 || srcB != srcA || cA || (flags & 0xc0000) || lim0 || cB) {
                    if (parent < 0) m40 = m0;
                    else m40 = *motWorld(ctx, pose, parent);
                    m40.invOrtho();
                }
                if (flags & 0x40000) {
                    v80 = motWorld(ctx, pose, idx)->r[3];
                    v80.w = 1.0f;
                    v90 = m40 * v80;
                    v90.w = 1.0f;
                } else {
                    if (srcA != (u32)-1 || srcB != srcA) {
                        func_00128e98(ctx, pose, srcA, srcB, &v80, &m40, &v90);
                        v90.w = 1.0f;
                        if (lim0) {
                            MotVec t = m40 * motWorld(ctx, pose, srcL)->r[3];
                            motLimit(ctx, lim0, t, &v90);
                            if (parent < 0) v80 = m0 * v90;
                            else v80 = *motWorld(ctx, pose, parent) * v90;
                        }
                        v80.w = 1.0f;
                    } else {
                        v90 = *motTrans(ctx, pose, idx);
                        v90.w = 1.0f;
                        if (lim0) {
                            MotVec t = m40 * motWorld(ctx, pose, srcL)->r[3];
                            motLimit(ctx, lim0, t, &v90);
                        }
                        if (parent < 0) v80 = m0 * v90;
                        else v80 = *motWorld(ctx, pose, parent) * v90;
                        v80.w = 1.0f;
                    }
                }
                if (cA) {
                    switch (cA->type) {
                    case 2:
                        ctx->work[idx] = ctx->work[cA->source];
                        break;
                    case 3: case 5: {
                        MotVec v120;
                        MotVec v130;
                        MotMtx rx;
                        u16 src = cA->type == 3 ? cA->source : cA->limiter;
                        vB0 = m40 * motWorld(ctx, pose, src)->r[3];
                        v120 = vB0 - v90;
                        v130.x = 0.0f;
                        v130.z = 0.0f;
                        v130.y = 1.0f;
                        func_00128d40(&v120, &v130, motLocal(ctx, pose, idx));
                        func_0011b6a8(&rx);
                        FMatrix_rotateX(&rx, motRot(ctx, pose, idx)->x);
                        *motLocal(ctx, pose, idx) = *motLocal(ctx, pose, idx) * rx;
                        motLocal(ctx, pose, idx)->r[3] = v90;
                        if (parent < 0) ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
                        else ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                        break;
                    }
                    }
                } else {
                    func_0011b6a8(motLocal(ctx, pose, idx));
                    if (cB) {
                        motLimit(ctx, cB, *motRot(ctx, pose, idx), motRot(ctx, pose, idx));
                    }
                    motRotXYZ(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                    motLocal(ctx, pose, idx)->r[3] = v90;
                    if (parent < 0 || (flags & 0x80000)) ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
                    else ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
                }
                *motWorld(ctx, pose, idx) = ctx->work[idx];
                motWorld(ctx, pose, idx)->r[3] = v80;
                if (cA || (flags & 0x80000)) {
                    if (parent < 0) m40 = m0;
                    else m40 = ctx->work[parent];
                    m40.invOrtho();
                    *motLocal(ctx, pose, idx) = m40 * ctx->work[idx];
                    motLocal(ctx, pose, idx)->r[3] = v90;
                    if (flags & 0x400000) motSetRot(motLocal(ctx, pose, idx), motRot(ctx, pose, idx));
                }
                break;
            }
            }
        }

        if (tgt && tgt->u.joint == idx) {
            m = *motLocal(ctx, pose, idx);
            if (!(tgt->u.flags & 0x10000)) {
                if (parent >= 0) {
                    m40 = *base * *motWorld(ctx, pose, parent);
                    v80 = *motWorld(ctx, pose, parent) * m.r[3];
                } else {
                    m40 = *base;
                    v80 = m0 * m.r[3];
                }
                m40.inverse();
                motXfpt(&vB0, &m40, &tgt->pos);
                v110 = vB0 - m.r[3];
                v110.normalize();
            } else {
                if (parent >= 0) {
                    MotMtx s;
                    m40 = *motWorld(ctx, pose, parent);
                    func_00129960(motWorld(ctx, pose, parent), &s);
                    v80 = *motWorld(ctx, pose, parent) * m.r[3];
                    m40.inverse();
                    motRot3(&v110, m40 * s, &tgt->pos);
                } else {
                    v80 = m0 * m.r[3];
                    v110 = tgt->pos;
                }
                v110.w = 0.0f;
            }
            m.r[1] = motLerp(m.r[1], v110, tgt->pos.w);
            m.r[1].normalize();
            m.r[2].cross(m.r[0], m.r[1]);
            m.r[2].normalize();
            m.r[0].cross(m.r[1], m.r[2]);
            m.r[0].normalize();
            m.r[2].cross(m.r[0], m.r[1]);
            m.r[2].normalize();
            *motLocal(ctx, pose, idx) = m;
            if (parent >= 0) ctx->work[idx] = ctx->work[parent] * *motLocal(ctx, pose, idx);
            else ctx->work[idx] = m0 * *motLocal(ctx, pose, idx);
            *motWorld(ctx, pose, idx) = ctx->work[idx];
            motWorld(ctx, pose, idx)->r[3] = v80;
        }
    }
}
}  // namespace n0012d728

// 00130c18 (was src/anon/batch_w89.cpp)
namespace n00130c18 {
struct AnKey { f32 t; s32 v; };
struct AnTrack { u8 pad0; u8 flag; u8 pad[6]; u16 count; u16 start; };
struct AnData { u8 pad[80]; s32 trackOff; s32 nTracks; s32 keyOff; };
/*TARGET 00130c18*/
// Samples every on/off track at time t (binary search over its keys).
void func_00130c18(u8* o, f32 t) asm("func_00130c18");
// Samples every on/off track at time t (binary search over its keys).
void func_00130c18(u8* o, f32 t) {
    AnData* a = *(AnData**)(o + 4);
    AnTrack* tr = (AnTrack*)((u8*)a + a->trackOff);
    AnKey* keys = (AnKey*)((u8*)a + a->keyOff);
    for (s32 i = 0; i < a->nTracks; i++, tr++) {
        if (tr->count == 0) continue;
        s32 lo = tr->start;
        s32 hi = lo + tr->count - 1;
        if (t < keys[lo].t) { tr->flag = keys[lo].v == 0; continue; }
        if (keys[hi].t <= t) { tr->flag = keys[hi].v != 0; continue; }
        while (hi - lo >= 2) {
            s32 mid = (lo + hi) / 2;
            if (t < keys[mid].t) hi = mid;
            else if (keys[mid].t < t) lo = mid;
            else { lo = mid; break; }
        }
        tr->flag = keys[lo].v != 0;
    }
}
}  // namespace n00130c18

