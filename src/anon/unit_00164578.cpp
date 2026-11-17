#include "../common/types.h"

inline void* operator new(unsigned int, void* p) { return p; }

// 00164578 (from src/anon/batch_w3909_nsa.cpp)
namespace n00164578 {
struct W3909V {
    f32 x, y, z, w;
    W3909V() {}
    W3909V(const W3909V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W3909V& operator=(const W3909V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W3909Box { u8 d[0x20]; };
struct W3909Node { u8 pad[0x30]; W3909V v; u8 pad2[0x30]; u64 lo:34; u64 f:1; u64 hi:29;
    void setF(u32 x) { f = x; }
    u32 getF() { return f; }
};
void func_00144490(W3909Box*, f32, f32, f32, f32, f32, f32) asm("func_00144490");
s32 func_00163898(void*, u16, W3909V*, W3909Box*, W3909V*, W3909Node*) asm("func_00163898");
void func_00164578(void* ctx, W3909Node* n, W3909V* v, u16 k, s32* cnt, W3909V t, f32 r) asm("func_00164578");
void func_00164578(void* ctx, W3909Node* n, W3909V* v, u16 k, s32* cnt, W3909V t, f32 r) {
    W3909Box b;
    (*cnt)++;
    func_00144490(&b, v->x - r, v->y - r, v->z - r, v->x + r, v->y + r, v->z + r);
    s32 res = func_00163898(ctx, k, v, &b, &n->v, n);
    if (res != -1) {
        if (res == 0) { n->v = *v; bool x = n->f; n->setF(x); }
        else { if (*cnt >= 6) return; *v = n->v; func_00164578(ctx, n, v, k, cnt, t, r); n->setF(1); }
    } else { n->v = t; n->setF(1); }
}
} // n00164578

// 00164718 (from src/anon/batch_w3848_nsa.cpp)
namespace n00164718 {
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V& operator=(const V& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator+(const V& o) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V& operator+=(const V& o) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    V operator-(const V& o) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V operator/(f32 s) const {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct M4 {
    V r[4];
    V operator*(const V& v) const {
        V o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
};
struct Obj { u8 pad[80]; M4 m80; M4 m144; u8 pad2[1]; u8 b209; };
struct Ent {
    V v0;
    V v16;
    f32 r;
    V v48;
    u8 pad[44];
    f32 h;
    u32 b0 : 1;
    u32 mode : 2;
    u32 kind : 4;
    u32 pad7 : 25;
    u32 pad8 : 2;
    u32 hitf : 1;
} __attribute__((aligned(16)));
struct Box6 { f32 a[6]; Box6() {} Box6(const V& p) { a[0] = p.x; a[1] = p.y; a[2] = p.z; a[3] = p.x; a[4] = p.y; a[5] = p.z; } };
struct Aab;
void func_00144490(Aab*, f32, f32, f32, f32, f32, f32) asm("func_00144490");
void func_001444f8(Aab*, const Box6*, const Aab*) asm("func_001444f8");
struct Aab { V lo, hi; Aab() {} Aab(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) { func_00144490(this, a, b, c, d, e, f); } Aab(const Box6& b, const Aab& o) { func_001444f8(this, &b, &o); } };
struct Sphere { V c; f32 r; };
struct Seg { V a, b; Seg() {} Seg(const V& x, const V& y) { a = x; b = y; } };
void func_00144e30(V*) asm("func_00144e30");
u32 func_00141970(Obj*) asm("func_00141970");
void func_00144e50(V*, Aab*, u32) asm("func_00144e50");
void func_00141980(Obj*, u8*) asm("func_00141980");
void func_00141c18(Obj*, s32, s32, s32, s32) asm("func_00141c18");
void func_00141c38(Obj*, s32, V*, u16*, s32) asm("func_00141c38");
s32 func_00141ff0(Obj*, Seg*, V*, u16*, s32) asm("func_00141ff0");
void func_00164578(Obj*, Ent*, Sphere*, u16, s32*, V, f32) asm("func_00164578");
s32 func_00164718(Obj* o, Ent* e) asm("func_00164718");
s32 func_00164718(Obj* o, Ent* e) {
    if (e->kind == 6) e->mode = 2;
    V step;
    V p0;
    f32 r = e->r;
    p0 = e->v0;
    V d;
    d = e->v16;
    p0.y -= e->h;
    V p1 = p0 + d;
    p1.w = 1.0f;
    if (!o->b209) {
        p1 = o->m144 * p1;
        p0 = o->m144 * p0;
    }
    d = p1 - p0;
    s32 n = (s32)(d.length() / r);
    s32 cnt = n + 1;
    if (n == 0) step = d;
    else step = d / (f32)cnt;
    f32 rk = r * 1.5f;
    Box6 b6(p0);
    Aab a(p1.x - rk, p1.y - rk, p1.z - rk, p1.x + rk, p1.y + rk, p1.z + rk);
    Aab u(b6, a);
    V bb;
    func_00144e30(&bb);
    func_00144e50(&bb, &u, func_00141970(o));
    u16 hit = 0;
    u8 buf[2048];
    func_00141980(o, buf);
    func_00141c18(o, 15, 4, 1, 0);
    func_00141c38(o, 0, &bb, &hit, e->kind);
    if (hit == 0) {
        e->v48 = p1;
        if (!o->b209) e->v48 = o->m80 * e->v48;
        e->v48.y += e->h;
        return 0;
    }
    Sphere s;
    s.r = r;
    s.c = p0;
    for (s32 i = 0; i < cnt; i++) {
        V prev(s.c);
        s.c += step;
        s32 c = 0;
        func_00164578(o, e, &s, hit, &c, prev, rk);
        s.c = e->v48;
    }
    if (!o->b209) e->v48 = o->m80 * e->v48;
    if (e->kind != 6) {
        if (p0.x != e->v48.x || p0.y != e->v48.y || p0.z != e->v48.z) {
            V out;
            u16 id;
            p0 = e->v0;
            p0.y -= e->h;
            Seg sg(p0, e->v48);
            if (func_00141ff0(o, &sg, &out, &id, e->kind)) {
                e->v48 = e->v0;
                return 0;
            }
        }
    }
    e->v48.y += e->h;
    return e->hitf;
}
} // n00164718

// 00164c70 (from src/anon/batch_w1810_nsa.cpp)
namespace n00164c70 {
struct W1810Vec {
    f32 x, y, z, w;
    W1810Vec() {}
    W1810Vec& operator=(const W1810Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1810Vec operator-(const W1810Vec& a, const W1810Vec& b) {
    W1810Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1810_norm(W1810Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1810_len(const W1810Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W1810Ray { W1810Vec o; W1810Vec d; };
struct W1810Seg2 { W1810Vec a; W1810Vec b; };
f32 func_00164c70(void* self, const W1810Vec& a, const W1810Vec& b, const W1810Vec& c) asm("func_00164c70");
f32 func_00164c70(void* self, const W1810Vec& a, const W1810Vec& b, const W1810Vec& c)
{
    W1810Seg2 s;
    s.a = a;
    s.b = c;
    W1810Ray r;
    r.o = s.a;
    r.d = s.b - s.a;
    r.d.w = 1.0f;
    r.o.w = 1.0f;
    w1810_norm(&r.d);
    return w1810_len(&(r.d - b)) * 10.0f;
}
} // n00164c70

// 00164d60 (from src/anon/batch_w3868_gnsamam.cpp)
namespace n00164d60 {
struct W3868V {
    f32 x, y, z, w;
    W3868V() {}
    W3868V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    ~W3868V() {}
    W3868V& operator=(const W3868V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3868V operator+(const W3868V& o) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3868V operator-(const W3868V& o) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3868V operator*(f32 s) const {
        W3868V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const W3868V& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 lenSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) f32 W3868Dist2(const W3868V& a, const W3868V& b) {
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.wxyz $vf5, $vf6, $vf4\n\tvmove.wxyz $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$2");
    return r;
}
struct W3868Line { W3868V o, d; };
struct W3868Poly { W3868V* v[4]; s32 n; };
extern s8 D_004f41a0 asm("D_004f41a0");
extern W3868V D_004f41b0 asm("D_004f41b0");
extern const s32 D_0034c780[] asm("D_0034c780");
extern const s32 D_0034c790[] asm("D_0034c790");
void func_001656b8(void) asm("func_001656b8");
void func_002fd188(void (*)(void)) asm("func_002fd188");
static inline __attribute__((always_inline)) bool W3868InBox(const W3868V& p, const W3868V& lo, const W3868V& hi) {
    s32 o;
    o = p.x < lo.x; if (hi.x < p.x) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.y < lo.y; if (hi.y < p.y) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.z < lo.z; if (hi.z < p.z) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = 0; return o;
yes:
    o = 1; return o;
}
s32 func_00164d60(void* self, W3868Poly* p, W3868V* c, W3868V* out, W3868V* outA, W3868V* outB) asm("func_00164d60");
s32 func_00164d60(void* self, W3868Poly* p, W3868V* c, W3868V* out, W3868V* outA, W3868V* outB) {
    if (!D_004f41a0) {
        new (&D_004f41b0) W3868V(0.008f, 0.008f, 0.008f, 1.0f);
        D_004f41a0 = 1;
        func_002fd188(func_001656b8);
    }
    W3868V buf[4];
    W3868V bufA[4];
    W3868V bufB[4];
    s32 cnt = 0;
    s32 n = p->n;
    const s32* next = n == 3 ? D_0034c780 : D_0034c790;
    s32 i;
    for (i = 0; i < n; i++) {
        W3868V* pa = p->v[i];
        W3868V* pb = p->v[next[i]];
        W3868V a; a = *pa;
        W3868V b; b = *pb;
        W3868Line l;
        l.o = a;
        l.d = b - a;
        l.d.w = 1.0f;
        l.o.w = 1.0f;
        *out = l.d * -((l.o - *c).dot(l.d) / l.d.lenSq()) + l.o;
        W3868V lo = a + D_004f41b0;
        W3868V hi = b + D_004f41b0;
        if (W3868InBox(*out, lo, hi)) {
            bufA[cnt] = a;
            bufB[cnt] = b;
            buf[cnt++] = *out;
        }
    }
    if (cnt != 0) {
        if (cnt == 1) { *out = buf[0]; *outA = bufA[0]; *outB = bufB[0]; return 1; }
        f32 best = 99999991988224.0f;
        s32 idx = 0;
        for (s32 j = 0; j < cnt; j++) {
            f32 d = W3868Dist2(*c, buf[j]);
            if (d < best) { best = d; idx = j; }
        }
        *out = buf[idx];
        *outA = bufA[idx];
        *outB = bufB[idx];
        return 1;
    }
    return 0;
}
} // n00164d60
