#include "../common/types.h"

extern "C" {

// 16-byte VU0 vector
struct W1834Vec {
    f32 x, y, z, w;
    W1834Vec() {}
    W1834Vec(const W1834Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1834Vec& operator=(const W1834Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1834VObj { u8 pad[0x10]; W1834Vec a; W1834Vec b; };
extern f32 D_00349e10;

// normalize xyz in place, return the old length
static inline f32 w1834_norm(W1834Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W1834Vec w1834_mul(const W1834Vec& a, f32 s) {
    W1834Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline W1834Vec w1834_lerp(const W1834Vec& a, const W1834Vec& b, f32 t) {
    W1834Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}

W1834Vec func_002d2740(void* self, W1834VObj* o, f32 t0, f32 t1) {
    W1834Vec x;
    W1834Vec d = o->b;
    d.w = w1834_norm(&d);
    if (d.w <= o->a.w) {
        x = w1834_lerp(w1834_mul(o->a, o->a.w), o->b, t0);
    } else {
        x = w1834_lerp(w1834_mul(o->a, o->a.w), o->b, t1);
    }
    o->b = x;
    return w1834_mul(x, D_00349e10);
}

struct W1834E12 { s32 a, b, c; };
struct W1834H4 { s16 a, b, c, d; };
struct W1834P2 { s32 n, m; };
struct W1834Grp { s32 a[8]; u8 pad[0x78 - 0x20]; };
struct W1834Big {
    W1834E12 e[32];         // 0x000
    s32 f180, f184;         // 0x180
    W1834H4 h188, h190;     // 0x188
    W1834P2 p198, p1a0;     // 0x198
    u8 c1a8[7];             // 0x1a8
    u8 b1af, b1b0, b1b1, b1b2;
    s32 w1b4[6];            // 0x1b4
    W1834Grp grp;           // 0x1cc
    s32 f244, f248;
    u8 b24c; u8 pad24d[3];
    s32 f250, f254, f258, f25c, f260, f264;
};
void func_001c2f90(W1834Grp*, W1834Big*);
static inline void w1834_h4_init(W1834H4* h) { h->a = 0; h->b = 0; h->c = 0; h->d = 0; }
static inline void w1834_p2_init(W1834P2* p) { p->n = 99999; p->m = 1; }
static inline void w1834_grp_init(W1834Grp* g) { s32 k; for (k = 0; k < 8; k++) g->a[k] = 0; }

// constructor-like init (two identical copies)
void func_001a0c18(W1834Big* o) {
    W1834E12* e = o->e;
    s32 i = 31;
    do { e->a = 0; e->b = 0; e->c = 0; e++; i--; } while (i != -1);
    o->f180 = 0; o->f184 = 0;
    w1834_h4_init(&o->h188); w1834_h4_init(&o->h190);
    w1834_p2_init(&o->p198); w1834_p2_init(&o->p1a0);
    o->b1af = 0; o->b1b0 = 0; o->b1b1 = 0; o->b1b2 = 0;
    o->w1b4[0] = 0; o->w1b4[1] = 0; o->w1b4[2] = 0; o->w1b4[3] = 0; o->w1b4[4] = 0; o->w1b4[5] = 0;
    w1834_grp_init(&o->grp);
    o->f244 = 0; o->f248 = 0; o->b24c = 0; o->f250 = 0;
    o->f254 = -1; o->f258 = 1; o->f25c = 0; o->f260 = 0; o->f264 = 0;
    s32 k;
    for (k = 0; k < 7; k++) o->c1a8[k] = 100;
    func_001c2f90(&o->grp, o);
}

void func_001a0d48(W1834Big* o) {
    W1834E12* e = o->e;
    s32 i = 31;
    do { e->a = 0; e->b = 0; e->c = 0; e++; i--; } while (i != -1);
    o->f180 = 0; o->f184 = 0;
    w1834_h4_init(&o->h188); w1834_h4_init(&o->h190);
    w1834_p2_init(&o->p198); w1834_p2_init(&o->p1a0);
    o->b1af = 0; o->b1b0 = 0; o->b1b1 = 0; o->b1b2 = 0;
    o->w1b4[0] = 0; o->w1b4[1] = 0; o->w1b4[2] = 0; o->w1b4[3] = 0; o->w1b4[4] = 0; o->w1b4[5] = 0;
    w1834_grp_init(&o->grp);
    o->f244 = 0; o->f248 = 0; o->b24c = 0; o->f250 = 0;
    o->f254 = -1; o->f258 = 1; o->f25c = 0; o->f260 = 0; o->f264 = 0;
    s32 k;
    for (k = 0; k < 7; k++) o->c1a8[k] = 100;
    func_001c2f90(&o->grp, o);
}

}
