#include "../common/types.h"

#define W1676_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// VU0 4-float vector (same shape as W1640Vec).
struct W1676Vec {
    f32 x, y, z, w;
    W1676Vec() {}
    W1676Vec(const W1676Vec& o) { W1676_QCOPY(this, &o); }
    W1676Vec& operator=(const W1676Vec& o) { if (this != &o) W1676_QCOPY(this, &o); return *this; }
    W1676Vec operator+(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1676Vec operator-(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1676Vec operator*(f32 k) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1676Vec& operator*=(f32 k) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    // Normalises xyz in place; returns the old length.
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    W1676Vec cross(const W1676Vec& o) const {
        W1676Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

// Vector with a (trivial) destructor, used for local point arrays.
struct W1676Pt : W1676Vec {
    W1676Pt& operator=(const W1676Vec& o) { W1676Vec::operator=(o); return *this; }
    ~W1676Pt() {}
} __attribute__((aligned(16)));

// 4x4 matrix of row vectors.
struct W1676Mtx {
    W1676Vec r[4];
    W1676Vec operator*(const W1676Vec& v) const {
        W1676Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));

struct W1676Ctl {
    void** vt;
    u8 pad4[4];
    union {
        u32 flags;
        struct { u32 hold : 1; u32 busy : 1; };
    };
};

// RGBA colour, byte aligned.
struct W1676Tag {
    u8 b[4];
    void set(s32 r, s32 g, s32 bl, s32 a) { b[0] = r; b[1] = g; b[2] = bl; b[3] = a; }
};

// Ground/contact info block at obj+0x620.
struct W1676Ground {
    u8 pad0[0x20];
    W1676Tag color;      // +0x20 (obj+0x640): target colour
    u16 poly;         // +0x24 (obj+0x644)
    u8 pad26[6];
    u8 b2c;           // +0x2c (obj+0x64c)
    u8 pad2d[3];
    s32 kind;         // +0x30 (obj+0x650)
    s32 getKind() { return kind; }
    u8 b34;           // +0x34 (obj+0x654)
    u8 pad35[0x40 - 0x35];
    u32 u40;          // +0x40 (obj+0x660)
};

struct W1676Collider;
struct W1676ColliderVt { void* pad[2]; s32 (*hit)(W1676Collider*, const W1676Vec&); };
struct W1676Collider { W1676ColliderVt* vt; };


struct W1676Obj {
    u8 pad0[0xc];
    W1676Ctl* ctl;            // 0x0c
    u8 pad10[0x20 - 0x10];
    W1676Vec dir;             // 0x20
    u8 pad30[0x108 - 0x30];
    u32 flags108;
    u32 flags10C;
    u8 pad110[0x160 - 0x110];
    u32 flags160;
    u8 pad164[0x540 - 0x164];
    W1676Vec pos;             // 0x540
    u8 pad550[0x560 - 0x550];
    W1676Vec push;            // 0x560
    W1676Obj* parent;         // 0x570
    u8 pad574[0x588 - 0x574];
    u32 flags588;
    u32 flags58C;
    W1676Vec prevPos;         // 0x590
    W1676Vec target;          // 0x5a0
    f32 f5b0;                 // 0x5b0
    u8 pad5b4[0x5c0 - 0x5b4];
    W1676Vec hitPos;          // 0x5c0
    u8 pad5d0[0x600 - 0x5d0];
    union {
        u64 flags600;
        struct { u32 lo600; u32 hi604; };
    };
    s32 x608;
    u8 pad60c[0x620 - 0x60c];
    W1676Ground ground;       // 0x620
    u8 pad664[0x78e - 0x664];
    u8 b78e;
    u8 pad78f[0x810 - 0x78f];
    s32 x810;
    u8 pad814[0x8a0 - 0x814];
    W1676Vec v8a0;
    u8 pad8b0[0x8bc - 0x8b0];
    W1676Tag color;           // 0x8bc
    u8 pad8c0[0x8dc - 0x8c0];
    u8 b8dc;
    u8 pad8dd[0xad0 - 0x8dd];
    W1676Vec vad0;
} __attribute__((aligned(16)));
extern "C" {
extern f32 D_00349e10;
extern W1676Vec D_00350990;
void func_00143f50(u16, W1676Pt*);
W1676Vec W1676_GetNormal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
void W1676_MtxUnit(W1676Mtx*) asm("_Z13func_0011b6a8Pv");

W1676Vec func_00184bb0(W1676Obj* self)
{
    W1676Pt pts[4];
    W1676Vec v;
    W1676Vec up;
    W1676Mtx m;
    func_00143f50(self->ground.poly, pts);
    s32 n = 3;
    do {
        s32 last = -1;
        for (s32 j = 1; j <= n; j++) {
            if (pts[j - 1].z > pts[j].z) {
                last = j - 1;
                v = pts[last];
                pts[last] = pts[j];
                pts[j] = v;
            }
        }
        n = last;
    } while (n >= 0);
    if (pts[0].x > pts[1].x) v = pts[1] - pts[0];
    else v = pts[0] - pts[1];
    v.normalize();
    up = W1676_GetNormal(self->ground.poly, 0);
    W1676_MtxUnit(&m);
    m.r[0] = v.cross(up);
    m.r[0].normalize();
    m.r[1] = up;
    m.r[2] = m.r[0].cross(m.r[1]);
    m.r[2].normalize();
    m.r[0].w = 0.0f;
    m.r[1].w = 0.0f;
    m.r[2].w = 0.0f;
    v = D_00350990;
    v.w = 0.0f;
    return (m * v) * D_00349e10;
}
}
