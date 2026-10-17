#include "../common/types.h"
// 00177008: start a reaction/motion on an actor from a target record (w1621).
extern "C" {
struct W1621Rec20 { u32 w[5]; };
// 16-byte vector; the u8 member makes stores to it alias like the original (no strict aliasing).
struct W1621V4 {
    union { struct { f32 x, y, z, w; }; u8 b[16]; };
    W1621V4& operator=(const W1621V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// VU0: normalize xyz in place, return the old length.
static inline f32 W1621Norm(W1621V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
// VU0: all four lanes times s.
static inline W1621V4 operator*(const W1621V4& a, f32 s) {
    W1621V4 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct W1621Flags { u32 b0:1; u32 b1:1; u32 rest:30; };
// Reaction parameters (second argument).
struct W1621Act {
    u8 pad0[4];
    W1621Flags fl;   // 0x04
    union { u16 motion; u8 mb[2]; };  // 0x08 (union: load must not move above the record copy)
    u16 motion2;     // 0x0a
    f32 speed;       // 0x0c
    f32 f10;         // 0x10
    f32 f14;         // 0x14
    f32 lo;          // 0x18
    f32 hi;          // 0x1c
    u8 pad20[0x18];
    f32 f38;         // 0x38
    f32 f3c;         // 0x3c
};
struct W1621Ctl;
struct W1621CtlVt { void* f0; void* f4; void (*set)(W1621Ctl*, u8*, W1621V4*); };
struct W1621Ctl { W1621CtlVt* vt; };
struct W1621Pl { u8 pad0[0xc]; W1621Ctl* ctl; u8 pad10[0x9f4 - 0x10]; W1621Rec20 rec; };
extern u8* D_00352130;
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
u32 func_00112ab8(s32, W1621Rec20*);
W1621V4 func_0016af58(u8*);
f32 func_0016c4e8(u8*);
f32 func_001773b8(u8*, W1621Rec20*, W1621V4*);
void func_00177a28(u8*);
f32 func_0017d130(f32);
s32 func_00190140(W1621Rec20*);
s32 func_0019c090(u8*);

#define W1621CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((hi) < (x) ? (hi) : (x)))

static inline bool W1621Valid(W1621Rec20* r) { return func_00190140(r) && r->w[0]; }
static inline bool W1621Bit1(W1621Act* e) { return e->fl.b1; }
static inline u32 W1621Busy(u8* p) { return *(u32*)(*(u8**)(p + 12) + 8) & 2; }
static inline u32 W1621Hold(u8* p) { return *(u32*)(p + 0x160) & 0x40; }
static inline bool W1621Any2(u8* p) { return W1621Busy(p) || W1621Hold(p); }

void func_00177008(u8* p, W1621Act* e, W1621Rec20* r)
{
    W1621V4 v;
    u8* mot = p + 320;
    ((W1621Pl*)p)->rec = *r;
    f32 a = 0.0f;
    func_0017f488(mot, e->motion, a, a);
    if (a < e->speed) {
        if (!func_0019c090(p)) func_00177a28(p);
        f32 lo = e->lo;
        f32 hi = e->hi;
        f32 w;
        if (W1621Valid(r)) {
            w = e->f10;
            if (W1621Bit1(e)) w += func_0016c4e8(p);
            f32 base = func_001773b8(p, r, &v);
            a = W1621CLAMP(-v.y, e->f14, w);
            v.y = 0.0f;
            f32 d = W1621Norm(&v) - base + e->f3c;
            w = W1621CLAMP(d / func_0017d130(a), lo, hi);
        } else {
            w = hi;
            a = e->speed;
            v = func_0016af58(p);
        }
        v.w = w;
        v.y = a;
        W1621Ctl* o = ((W1621Pl*)p)->ctl;
        o->vt->set(o, p, &v);
        *(s32*)(p + 0x104) = 5;
    } else if (W1621Any2(p)) {
        if (W1621Valid(r)) {
            f32 base = func_001773b8(p, r, &v);
            f32 d = (W1621Norm(&v) - base + e->f3c) * *(f32*)(D_00352130 + 0xa8);
            *(W1621V4*)(p + 0x20) = v * W1621CLAMP(d, e->lo, e->hi);
        }
    }
    func_0017f5e0(mot, e->motion2, 0, e->f38, 0.0f);
    func_00112ab8(1, r);
    *(u32*)(p + 0x108) &= ~0x2000000;
}
}
