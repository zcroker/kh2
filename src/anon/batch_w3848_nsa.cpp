#include "../common/types.h"
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
extern "C" void func_00144490(Aab*, f32, f32, f32, f32, f32, f32);
extern "C" void func_001444f8(Aab*, const Box6*, const Aab*);
struct Aab { V lo, hi; Aab() {} Aab(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) { func_00144490(this, a, b, c, d, e, f); } Aab(const Box6& b, const Aab& o) { func_001444f8(this, &b, &o); } };
struct Sphere { V c; f32 r; };
struct Seg { V a, b; Seg() {} Seg(const V& x, const V& y) { a = x; b = y; } };
struct BB { u16 h[6]; } __attribute__((aligned(16)));
extern "C" {
void func_00144e30(V*);
u32 func_00141970(Obj*);
void func_00144e50(V*, Aab*, u32);
void func_00141980(Obj*, u8*);
void func_00141c18(Obj*, s32, s32, s32, s32);
void func_00141c38(Obj*, s32, V*, u16*, s32);
s32 func_00141ff0(Obj*, Seg*, V*, u16*, s32);
void func_00164578(Obj*, Ent*, Sphere*, u16, s32*, V, f32);

// Moves an entity from v0 by v16 through the collision mesh in radius-sized steps
// (sphere sweep via func_00164578), then checks the final segment with func_00141ff0.
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
}
