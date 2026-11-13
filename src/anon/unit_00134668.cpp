// Lights (0x134668-0x1357c8): a directional light (position + colour), the 3-light set that is
// sent to VU1 (transposed directions + colour matrix), the global shadow light and the global
// ambient colour, and the shadow camera that looks at a box of 8 points.
#include "../common/types.h"

// ---- VU0 vector/matrix helpers
struct FVector {
    f32 x, y, z, w;
    FVector() {}
    FVector(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    FVector& operator=(const FVector& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    // VU0 zero vector (vsub vf0-vf0).
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct FMatrixC {
    FVector r[4];
    FMatrixC() {}
    FMatrixC(const FMatrixC& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); }
} __attribute__((aligned(16)));

// A light: position (or direction) and colour.
class LIGHT {
public:
    FVector pos;
    FVector color;
    LIGHT();
    ~LIGHT();
};

// The light set: 3 directions stored transposed (row i = component i of the 3 lights),
// then the 3 colours and the ambient colour.
struct LIGHTSET { FVector dir[3]; FVector col[3]; FVector amb; };

extern "C" {
LIGHT D_00347cc0;                                   // shadow light
FVector D_00347ce0(0.3f, 0.3f, 0.3f, 1.0f);         // ambient colour

void func_00134668(LIGHTSET* o) {
    FVector* b = &o->dir[1]; FVector* c = &o->dir[2]; FVector* d = &o->col[0]; FVector* e = &o->col[1]; FVector* f = &o->col[2]; FVector* g = &o->amb;
    o->dir[0].Zero();
    b->Zero();
    c->Zero();
    o->dir[1].z = 1.0f;
    o->dir[1].y = 1.0f;
    o->dir[1].x = 1.0f;
    *f = FVector(1.0f, 1.0f, 1.0f, 1.0f);
    *e = *f;
    *d = *e;
    *g = D_00347ce0;
}

void func_00134710(LIGHTSET* o, const FVector* v) {
    o->amb = *v;
}
}

static inline void Zero_w2050a(FVector* v) { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory"); }
static inline void Inverse_w2050a(FMatrixC* m)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
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
        "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
        "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
static inline void ApplyPoint_w2050a(FVector* o, const FMatrixC* m, const FVector* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
        : : "r"(o), "r"(m), "r"(v) : "memory");
}
static inline f32 Normalize_w2050a(FVector* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern "C" {
void func_00134d78(LIGHT*, FVector*);
void func_00134db0(LIGHT*, FVector*);
void func_00135670(FVector*);

void func_00134730(LIGHTSET* self, const FMatrixC& src, LIGHT* a, LIGHT* b, LIGHT* c)
{
    FMatrixC m(src);
    FVector v;
    FVector t;
    LIGHT* n[3] = { a, b, c };
    Zero_w2050a(&self->dir[0]);
    FVector* a1 = &self->dir[1];
    Zero_w2050a(a1);
    FVector* a2 = &self->dir[2];
    Zero_w2050a(a2);
    Inverse_w2050a(&m);
    for (s32 i = 0; i < 3; i++) {
        if (n[i]) {
            func_00134d78(n[i], &v);
            ApplyPoint_w2050a(&t, &m, &v);
            t.y = -t.y;
            t.z = -t.z;
            t.w = 0;
            Normalize_w2050a(&t);
            s32 o = i * 4;
            *(f32*)((u8*)self + o) = t.x;
            *(f32*)((u8*)a1 + o) = t.y;
            *(f32*)((u8*)a2 + o) = t.z;
            func_00134db0(n[i], &self->col[i]);
        } else {
            Zero_w2050a(&self->col[i]);
        }
    }
    func_00135670(&self->amb);
}
}

// ---- 0x1349a8
extern "C" {

// VU0 macro helpers (libvu0-style inline asm): matrix copy, row clear,
// 3x3 inverse with translation, apply, normalize.
typedef f32 W2048V4[4] __attribute__((aligned(16)));
struct W2048M4 { W2048V4 r[4]; };
struct W2048V3 { f32 x, y, z; };
struct W2048Src { W2048V3 a[3]; W2048V3 b[4]; };
struct W2048Dst { W2048V4 r[3]; W2048V4 p[4]; };

static inline void w2048_mcopy(W2048M4* d, W2048M4* s) {
    asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)" : : "r"(d), "r"(s) : "$8","$9","$10","$11","memory");
}
static inline void w2048_vzero(f32* v) {
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(v) : "memory");
}
static inline void w2048_vinv(W2048M4* d, W2048M4* s) {
    asm volatile(
"lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vopmula.xyz ACC,$vf2,$vf3\n\tvopmsub.xyz $vf5,$vf3,$vf2\n\t"
"vopmula.xyz ACC,$vf3,$vf1\n\tvopmsub.xyz $vf6,$vf1,$vf3\n\t"
"vopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf7,$vf2,$vf1\n\t"
"vmul.xyz $vf8,$vf1,$vf5\n\tvmul.xyz $vf1,$vf4,$vf5\n\tvmul.xyz $vf2,$vf4,$vf6\n\tvmul.xyz $vf3,$vf4,$vf7\n\t"
"vaddy.x $vf8,$vf8,$vf8y\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddx.y $vf2,$vf2,$vf2x\n\tvaddx.z $vf3,$vf3,$vf3x\n\t"
"vaddz.x $vf8,$vf8,$vf8z\n\tvaddz.x $vf4,$vf1,$vf1z\n\tvaddz.y $vf4,$vf2,$vf2z\n\tvaddy.z $vf4,$vf3,$vf3y\n\t"
"vdiv Q,$vf0w,$vf8x\n\t"
"qmfc2 $8,$vf5\n\tqmfc2 $9,$vf6\n\tqmfc2 $10,$vf7\n\tqmfc2 $11,$vf0\n\t"
"pextlw $12,$9,$8\n\tpextuw $13,$9,$8\n\tpextlw $14,$11,$10\n\tpextuw $15,$11,$10\n\t"
"pcpyld $8,$14,$12\n\tpcpyud $9,$12,$14\n\tpcpyld $10,$15,$13\n\t"
"qmtc2 $8,$vf1\n\tqmtc2 $9,$vf2\n\tqmtc2 $10,$vf3\n\t"
"vsub.xyz $vf4,$vf0,$vf4\n\tvwaitq\n\t"
"vmulq.wxyz $vf1,$vf1,Q\n\tvmulq.wxyz $vf2,$vf2,Q\n\tvmulq.wxyz $vf3,$vf3,Q\n\tvmulq.xyz $vf4,$vf4,Q\n\t"
"sqc2 $vf1,0(%0)\n\tsqc2 $vf2,16(%0)\n\tsqc2 $vf3,32(%0)\n\tsqc2 $vf4,48(%0)"
    : : "r"(d), "r"(s) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
}
static inline void w2048_vapply(f32* o, W2048M4* m, f32* v) {
    asm volatile(
"lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\tvmaddw.xyz $vf5,$vf4,$vf0w\n\t"
"vmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}
static inline f32 w2048_vnorm(f32* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\tvsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,%0\n\tvnop\n\tvdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// builds a 3-row normal basis from the inverse of m and copies 4 points
void func_001349a8(W2048Dst* d, W2048M4* sm, W2048Src* s) {
    W2048M4 m; w2048_mcopy(&m, sm);
    W2048V4 v, o;
    f32* r0 = d->r[0]; w2048_vzero(r0);
    f32* r1 = d->r[1]; w2048_vzero(r1);
    f32* r2 = d->r[2]; w2048_vzero(r2);
    w2048_vinv(&m, &m);
    W2048V4* p = d->p;
    v[3] = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        v[0] = s->a[i].x; v[1] = s->a[i].y; v[2] = s->a[i].z;
        w2048_vapply(o, &m, v);
        o[1] = -o[1]; o[2] = -o[2]; o[3] = 0.0f;
        w2048_vnorm(o);
        s32 k = i * 4;
        *(f32*)((u8*)r0 + k) = o[0]; *(f32*)((u8*)r1 + k) = o[1]; *(f32*)((u8*)r2 + k) = o[2];
        p[i][0] = s->b[i].x; p[i][1] = s->b[i].y; p[i][2] = s->b[i].z; p[i][3] = 1.0f;
    }
    d->p[3][0] = s->b[3].x; d->p[3][1] = s->b[3].y; d->p[3][2] = s->b[3].z; d->p[3][3] = 1.0f;
}
}

// ---- 0x134c00: send the light set to a packet (3 directions, then the colour matrix)
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W78Mtx {
    W78Vec r[4];
    W78Mtx& operator=(const W78Mtx& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
extern "C" {
W78Vec* func_00133bb8(u32, s32, u32, u32);  // forward_sub24_to_133848

void func_00134c00(W78Vec* v, u32 a) {
    W78Vec* d = func_00133bb8(a, 3, 0x01000101, 0x6c034005);  // forward_sub24_to_133848
    d[0] = v[0];
    d[1] = v[1];
    d[2] = v[2];
    W78Mtx* m = (W78Mtx*)func_00133bb8(a, 4, 0x01000101, 0x6c04400a);  // forward_sub24_to_133848
    *m = *(W78Mtx*)(v + 3);
}
}

// ---- LIGHT
LIGHT::LIGHT() {
    pos.x = 0.0f;
    pos.y = -1e7f;
    pos.z = 0.0f;
    pos.w = 1.0f;
    color.x = 1.0f;
    color.y = 1.0f;
    color.z = 1.0f;
    color.w = 1.0f;
}

LIGHT::~LIGHT() {}

extern "C" {
void func_00134d60(LIGHT* l, const FVector* v) { l->pos = *v; }
void func_00134d78(LIGHT* l, FVector* v) { *v = l->pos; }
void func_00134d90(LIGHT* l, const FVector* v) { l->color = *v; }
void func_00134db0(LIGHT* l, FVector* v) { *v = l->color; }
void func_00134dd0(LIGHT* l, const FMatrixC& m, LIGHTSET* s) { func_00134730(s, m, l, 0, 0); }
}

// ---- 0x134df8: shadow camera
inline void* operator new(unsigned int, void* p) { return p; }

struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    void set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V& operator=(const V& r) {
        if (this != &r) asm volatile(".set noreorder\n\t""lq $8,0(%1)\n\tsq $8,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&r) : "$8", "memory");
        return *this;
    }
    V& operator+=(const V& r) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&r) : "memory");
        return *this;
    }
    V& operator*=(f32 s) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%0)\n\tmfc1 $8,%1\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V operator-(const V& r) const {
        V t;
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)""\n\t.set reorder" : : "r"(&t), "r"(this), "r"(&r) : "memory");
        return t;
    }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\tvsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,%0\n\tvnop\n\tvdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%1)\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tvsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0\n\t.set reorder"
            : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 dot(const V& r) const {
        f32 d;
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvmul.xyz $vf1,$vf1,$vf2\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tqmfc2 $8,$vf1\n\tmtc1 $8,%0""\n\t.set reorder"
            : "=f"(d) : "r"(this), "r"(&r) : "$8", "memory");
        return d;
    }
    void cross(const V& a, const V& b) {
        asm volatile(".set noreorder\n\t""lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\tvopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)""\n\t.set reorder" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
} __attribute__((aligned(16)));

struct M {
    V r[4];
    M() {}
    M& operator=(const M& s) {
        if (this != &s)
            asm volatile(".set noreorder\n\t""lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)""\n\t.set reorder" : : "r"(this), "r"(&s) : "$8","$9","$10","$11","memory");
        return *this;
    }
    M operator*(const M& b) const {
        M t;
        asm volatile(".set noreorder\n\t"
"lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
"vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
"vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
"vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
"vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
"sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)""\n\t.set reorder"
            : : "r"(&t), "r"(this), "r"(&b) : "memory");
        return t;
    }
    V operator*(const V& v) const;
    void translate(const V& r) {
        asm volatile(".set noreorder\n\tlqc2 $vf1,48(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,48(%0)\n\t.set reorder" : : "r"(this), "r"(&r) : "memory");
    }
    void invert() {
        asm volatile(".set noreorder\n\t"
"lq $8,0(%0)\n\tlq $9,16(%0)\n\tlq $10,32(%0)\n\tqmfc2 $11,$vf0\n\tlqc2 $vf4,48(%0)\n\t"
"pextlw $12,$9,$8\n\tpextuw $13,$9,$8\n\tpextlw $14,$11,$10\n\tpextuw $15,$11,$10\n\t"
"pcpyld $8,$14,$12\n\tpcpyud $9,$12,$14\n\tpcpyld $10,$15,$13\n\t"
"qmtc2 $8,$vf1\n\tqmtc2 $9,$vf2\n\tqmtc2 $10,$vf3\n\t"
"vmulax.xyz ACC,$vf1,$vf4x\n\tvmadday.xyz ACC,$vf2,$vf4y\n\tvmaddz.xyz $vf4,$vf3,$vf4z\n\tvsub.xyz $vf4,$vf0,$vf4\n\t"
"sq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsqc2 $vf4,48(%0)""\n\t.set reorder"
            : : "r"(this) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
    }
};

static inline void mulMV(V* o, const M* m, const V* v) {
    register const M* rm asm("$12") = m; register V* ro asm("$11") = o;
    asm volatile(".set noreorder\n\t"
"lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
"sqc2 $vf5,0(%0)""\n\t.set reorder" : : "r"(ro), "r"(rm), "r"(v) : "memory");
}
inline V M::operator*(const V& v) const {
    V t;
    mulMV(&t, this, &v);
    return t;
}
struct AXIS : V {
    AXIS(f32 ax, f32 ay, f32 az, f32 aw) { set(ax, ay, az, aw); }
    ~AXIS() {}
};

extern "C" {
void func_0011b6a8(M* m);
static inline s32 shadowSize(s32 mode) {
    switch (mode) {
    case 0: return 64;
    case 1: return 128;
    case 2: return 256;
    }
    return 0;
}

// builds the light view and projection matrices of a shadow camera looking at a box of 8 points
void func_00134df8(V* pos, V* pts, M* view, M* tex, s32 mode) {
    static AXIS axes[3] = { AXIS(1.0f, 0.0f, 0.0f, 0.0f), AXIS(0.0f, 1.0f, 0.0f, 0.0f), AXIS(0.0f, 0.0f, 1.0f, 0.0f) };
    V c;
    c = pts[0];
    for (s32 i = 1; i < 8; i++) c += pts[i];
    c *= 0.125f;
    M m;
    func_0011b6a8(&m);
    m.r[2] = c - *pos;
    f32 dist = m.r[2].normalize();
    f32 best = m.r[2].dot(axes[0]);
    if (best < 0.0f) best = -best;
    s32 bi = 0;
    for (s32 i = 1; i < 3; i++) {
        f32 d = m.r[2].dot(axes[bi]);
        if (d < 0.0f) d = -d;
        if (d < best) { best = d; bi = i; }
    }
    m.r[0].cross(axes[bi], m.r[2]);
    m.r[0].normalize();
    m.r[1].cross(m.r[2], m.r[0]);
    m.r[1].normalize();
    m.translate(*pos);
    m.invert();
    f32 mx = 0.0f, my = 0.0f;
    for (s32 i = 0; i < 8; i++) {
        V v;
        v = m * pts[i];
        f32 x = v.x * dist / v.z;
        f32 y = v.y * dist / v.z;
        if (x < 0.0f) x = -x;
        if (y < 0.0f) y = -y;
        if (mx < x) mx = x;
        if (my < y) my = y;
    }
    M p;
    func_0011b6a8(&p);
    p.r[0].x = dist;
    p.r[1].y = dist;
    p.r[2].z = 0.0f;
    p.r[2].w = 1.0f;
    p.r[3].z = 1.0f;
    p.r[3].w = 0.0f;
    f32 nearz = 1.0f;
    f32 farz = dist + (pts[6] - pts[0]).length();
    f32 w = shadowSize(mode);
    f32 h = shadowSize(mode);
    f32 sx = mx + mx;
    f32 sy = my + my;
    f32 w2 = w - 2.0f;
    f32 h2 = h - 2.0f;
    M s;
    func_0011b6a8(&s);
    s.r[0].x = w2 / sx;
    s.r[1].y = h2 / sy;
    s.r[2].z = farz * 16769999.0f / (farz - nearz);
    s.r[3].x = 2048.0f;
    s.r[3].y = 2048.0f;
    s.r[3].z = (farz + -16770000.0f) / (farz - nearz);
    *view = s * p * m;
    func_0011b6a8(&s);
    s.r[0].x = w2 / (sx * w);
    s.r[1].y = h2 / (sy * h);
    s.r[2].z = farz * 16769999.0f / (farz - nearz);
    s.r[3].x = 0.5f;
    s.r[3].y = 0.5f;
    s.r[3].z = (farz + -16770000.0f) / (farz - nearz);
    *tex = s * p * m;
}

LIGHT* func_00135640(void) { return &D_00347cc0; }
void func_00135650(const FVector* v) { D_00347ce0 = *v; }
void func_00135670(FVector* v) { *v = D_00347ce0; }
}
