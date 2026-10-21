#include "../common/types.h"

extern "C" {

// ---- 00222f88: GS packet setup, then VU0 register preload (VU0 macro asm) ----
struct W2042A { u8 p0[0x20]; void* m20; u8 p24[4]; void* m28; u8 p2c[0x10]; s32 m3c; u64 m40; u64 m48; u16 m50; u16 p52; u16 m54; };
struct W2042P { u64 a0, a8, a10, a18, a20, a28, a30, a38, a40, a48, a50, a58, a60, a68; s32 b70, b74; u64 a78; s32 b80, b84; };
extern s32 D_01da8bf0;
extern s32 D_01da8bf4;
void* func_0020eaf8(s32);
void func_0020ebd8(s32);

void func_00222f88(W2042A* a) {
    W2042P* p = (W2042P*)func_0020eaf8(0x90);
    p->a0 = (1ULL << 62) | 1;
    p->a8 = 0xeeee;
    p->a10 = (a->m40 & ~(0xffULL << 26)) | (0x55ULL << 27);
    p->a18 = 6;
    if (a->m3c & 4) p->a20 = 0x31001; else p->a20 = 0x71001;
    p->a28 = 0x47;
    p->a30 = 0x44;
    p->a38 = 0x42;
    u64 v = a->m48;
    p->a40 = ((v & 0x7ff) << 4) | (((v >> 32) & 0x7ff) << 24) | ((((v >> 16) & 0x7ff) - 1) << 14) | 0xa | ((((v >> 48) & 0x7ff) - 1) << 34);
    p->a48 = 8;
    p->a50 = (0xc0bbULL << 46) | 0xa;
    p->a58 = 0x412;
    p->a60 = (1ULL << 60) | 0x8001;
    p->a68 = 0xe;
    p->b70 = D_01da8bf0;
    p->b74 = D_01da8bf4;
    p->a78 = 0x47;
    u64 x = a->m50; p->b80 = (s32)(x - 8);
    u64 y = a->m54; p->b84 = (s32)(y - 8);
    void* q28 = a->m28;
    void* q20 = a->m20;
    asm volatile(
        "lqc2 $vf25,0(%0)\n\tlqc2 $vf27,16(%0)\n\tlqc2 $vf29,32(%0)\n\tlqc2 $vf21,48(%0)\n\t"
        "lqc2 $vf14,64(%0)\n\tlqc2 $vf20,80(%0)\n\tlqc2 $vf9,96(%0)\n\tlqc2 $vf3,112(%0)\n\t"
        "lqc2 $vf2,0(%1)\n\tlqc2 $vf31,16(%1)\n\tvadd.y $vf2,$vf0,$vf31\n\t"
        "lui $2,0x3a80\n\tqmtc2 $2,$vf24\n\t"
        "lqc2 $vf4,0(%2)\n\tlqc2 $vf5,16(%2)\n\tlqc2 $vf6,32(%2)\n\tlqc2 $vf7,48(%2)\n\t"
        "lqc2 $vf11,128(%0)\n\tvitof4.wxyz $vf11,$vf11\n\t"
        "lqc2 $vf31,80(%3)\n\tvmove.x $vf15,$vf0\n\tvaddw.y $vf15,$vf0,$vf31w\n\tvaddz.x $vf17,$vf0,$vf31z\n\tvmove.y $vf17,$vf0\n\t"
        "lui $2,0x3f35\n\tori $2,$2,0x4f3\n\tdsll $2,$2,0x10\n\tori $2,$2,0x3f35\n\tdsll $2,$2,0x10\n\tori $2,$2,0x4f3\n\t"
        "qmtc2 $2,$vf16\n\tvmul.xy $vf16,$vf16,$vf2\n\tlqc2 $vf1,48(%3)\n\tvmul.xy $vf1,$vf2,$vf1\n\t"
        "vmulz.xy $vf18,$vf2,$vf1z\n\tvmulz.xy $vf19,$vf16,$vf1z\n\tvmul.x $vf16,$vf16,$vf17\n\tvmul.y $vf16,$vf16,$vf15\n\t"
        "vmul.y $vf15,$vf15,$vf2\n\tvmul.x $vf17,$vf17,$vf2\n\t"
        "lui $2,0x4580\n\tqmtc2 $2,$vf28\n\tvaddx.y $vf28,$vf0,$vf28x\n\tvaddw.z $vf26,$vf0,$vf0w\n\tvsubw.w $vf30,$vf0,$vf0w"
        : : "r"(p), "r"(q20), "r"(q28), "r"(a) : "$2", "memory");
    func_0020ebd8(0x90);
}

// ---- 00184780 ----
struct W2042Vec {
    f32 x, y, z, w;
    W2042Vec() {}
    W2042Vec& operator=(const W2042Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2042Seg { W2042Vec a, b; };
struct W2042Obj { u8 p0[0x5fc]; f32 r; u64 :3; s64 k:32; };
W2042Vec* func_0016c028(W2042Obj*);
s32 func_00143ae0(W2042Seg*, W2042Vec*, W2042Vec*, s32);

static inline f32 w2042_norm(W2042Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W2042Vec w2042_mul(const W2042Vec& a, f32 s) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline W2042Vec w2042_add(const W2042Vec& a, const W2042Vec& b) {
    W2042Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

s32 func_00184780(W2042Obj* o, W2042Vec* dir, f32 s, f32 d, f32 e) {
    W2042Seg seg;
    W2042Vec A, B, C, D, o1, o2;
    A = *func_0016c028(o);
    B = *dir;
    B.y = 0;
    w2042_norm(&B);
    C = A;
    C.y -= d;
    D = w2042_add(C, w2042_mul(B, s));
    seg.a = C;
    seg.b = D;
    if (func_00143ae0(&seg, &o1, &o2, o->k & 0xf)) return 3;
    C = D;
    C.y += d + e;
    seg.a = D;
    seg.b = C;
    if (!func_00143ae0(&seg, &o1, &o2, o->k & 0xf)) return 3;
    f32 f = o->r * 0.4f;
    if (o1.y < A.y - f) return 1;
    if (A.y + f < o1.y) return 2;
    return 0;
}

}
