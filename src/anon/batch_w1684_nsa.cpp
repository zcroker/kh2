#include "../common/types.h"
// VU0 vector / matrix helpers (inline asm like the game's vector library).
struct W1654Vec {
    f32 x, y, z, w;
    W1654Vec() {}
    W1654Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1654Vec& operator=(const W1654Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1654Vec& operator+=(const W1654Vec& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    // Perspective divide: this *= 1/w.
    void divW() {
        f32 d = w;
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(d) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W1654Mtx {
    W1654Vec r[4];
    W1654Mtx() {}
    W1654Mtx(const W1654Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1654Mtx& operator=(const W1654Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // Full 4x4 transform.
    void apply(W1654Vec& o, const W1654Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Point transform (w = 1).
    void applyPoint(W1654Vec& o, const W1654Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Inverse of a rotation + translation matrix (transpose, translation = -R^T t).
    void orthoInverse() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
                     "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                     "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                     "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
extern "C" void func_0031bae0(void*, const void*);   // sceVu0CopyMatrix
struct W1654F2 { f32 v[2]; };
struct W1654I3 { s32 v[3]; };
struct W1654DI { u64 d; s32 i; };
struct W1654I5 { s32 v[5]; };
struct W1654U64 { u64 v; };
struct W1654S32 { s32 v; };
struct W1654Mtx2 {
    f32 m[4][4];
    W1654Mtx2(const W1654Mtx2& o) { func_0031bae0(m, o.m); }
} __attribute__((aligned(16)));
void W1654_projDtor(void*) asm("_ZN2kn10ProjectionD1Ev");
// kn::Projection (256 bytes)
struct W1654Proj {
    W1654Mtx view;      // 0
    f32 f64;
    W1654F2 fov;
    W1654I3 i76;
    W1654U64 d88;
    W1654S32 i96;
    f32 f100, f104, f108, f112, f116, f120;
    W1654Mtx2 m128;
    W1654Mtx2 m192;
    inline W1654Proj(const W1654Proj& o) __attribute__((always_inline));
    ~W1654Proj() { W1654_projDtor(this); }
};
inline W1654Proj::W1654Proj(const W1654Proj& o)
        : view(o.view), f64(o.f64), fov(o.fov), i76(o.i76), d88(o.d88), i96(o.i96),
          f100(o.f100), f104(o.f104), f108(o.f108), f112(o.f112), f116(o.f116), f120(o.f120), m128(o.m128), m192(o.m192) {}
struct W1654Box { f32 x0, y0, z0, x1, y1, z1; };
struct W1654Ob {
    s32 id;             // 0
    u32 pad4;
    u8 sub8[16];        // 8
    u64 gs24;           // 24
    u64 gs32;           // 32
    u8 pad40[24];
    W1654Mtx mtx;       // 64
    u8 pad128[64];
    W1654Vec pos;       // 192
    W1654Box box;       // 208, bounds
    u8 color[4];        // 232
    u8 pad236[12];
    u32 flags;          // 248
    u8 pad252[8];
    f32 boxGrow;        // 260
    f32 fadeDist;       // 264
    u8 alpha;           // 268
    u8 b269;            // 269
    u8 vis[2];          // 270, per slot
    u8 pad272[14];
    u8 b286;            // 286
    u8 pad287;
    W1654Mtx* attach;   // 288
};
struct W1654ObFl { u8 pad[248]; u32 flags; };
struct W1654Mgr {
    u8 pad0[32];
    W1654Proj proj;     // 32
    u8 pad288[16];
    W1654Mtx view;      // 304
    W1654Mtx screen;    // 368?
    W1654Mtx clip;      // 432
    u8 frustum[21352 - 496];    // 496
    s32 x21352;         // 21352
    s32 slot;           // 21356
};
struct W1654Pkt { u8 pad0[20]; u32 xy; u8 pad24[56]; void* cb0; void* cb1; };
// Render/draw state block (56 bytes), set up by func_00108698.
struct W1654Gs {
    u32 flags;
    u8 col[4];
    s8 c[4];
    u8 pad[44];
} __attribute__((aligned(8)));
extern "C" {
extern W1654Gs D_00457480;
extern W1654Ob** D_00457478;
void func_00108698(W1654Gs*);
void func_00144860(W1654Box*, W1654Box*, W1654Box*);
s32 func_00146730(void*, W1654Box*);
s32 func_00146088(W1654Mgr*, W1654Box*);
void func_00146080(W1654Mgr*, s16*);
void func_00148c50(W1654Mgr*, s32, W1654Box*, s32*, u8, W1654Ob**);
void func_0011de88(s32, W1654Gs*, s16*, W1654Ob**, s32);

void func_00148ef0(W1654Mgr* m, W1654Ob** list, s32 n)
{
    W1654Gs g;
    W1654Box box;
    s16 idx[1024];
    s32 cnt;
    W1654Ob** p = list;
    func_00108698(&g);
    W1654Ob* o = list[0];
    if (!(g.col[3] = o->alpha)) return;
    W1654Box* src = &o->box;
    box = *src;
    for (s32 i = 0; i < n; i++) {
        func_00144860(&box, &box, &(*p)->box);
        p++;
    }
    f32 h = (box.y1 - box.y0) * 0.5f;
    box.y1 += h + h;
    box.y1 += o->boxGrow;
    if (!func_00146730(m->frustum, &box)) return;
    if (func_00146088(m, &box) == 1) return;
    if (o->flags & 0x40) {
        g.flags |= 1;
        g.col[0] = o->color[0];
        g.col[1] = o->color[1];
        g.col[2] = o->color[2];
        g.col[3] = o->color[3];
    }
    s32 mode;
    if (o->flags & 0x200) mode = 1;
    else if (!(o->flags & 0x400)) mode = 0;
    else mode = 2;
    u8 b = o->b286;
    D_00457480 = g;
    D_00457478 = list;
    cnt = 0;
    func_00146080(m, idx);
    idx[0] = -1;
    func_00148c50(m, 0, &box, &cnt, b, list);
    idx[cnt] = -1;
    g.c[0] = g.c[1] = g.c[2] = -128;
    g.c[3] = -1;
    g.flags |= 2;
    func_0011de88(m->x21352, &g, idx, list, mode);
}
}
