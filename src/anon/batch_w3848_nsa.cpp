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
s32 func_00164718(Obj* o, Ent* e);  // 0x00164718: definition moved into src/anon/unit_00164578.cpp
}
