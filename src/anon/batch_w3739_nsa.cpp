#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).

/* 0031a9d8: out-of-line implicit operator= of a polymorphic 0xb0-byte class (vptr skipped).
   Levels up to 0x88 are copied by the inherited operator=; the last level copies a0/a8 first,
   then the rest. The empty asm with "m" inputs keeps the last group's loads after the a0/a8
   stores (no code emitted). */
struct P3 { s32 a, b, c; };
struct P6 { s32 v[6]; };
struct L1 { virtual void f(); s32 a04, a08, a0c; };
struct L2 : L1 { P3 p10, p1c, p28_; };
struct L3 : L2 { s32 b34, b38, b3c, b40; };
struct L4 : L3 { f32 c44, c48, c4c; };
struct L5 : L4 { P6 p50; };
struct M4_0 : L5 { s32 f68; f32 f6c; f32 f70; f32 f74; f32 f78; f32 f7c; f32 f80; f32 f84; s32 f88; };
struct C0031a9d8 : M4_0 { s32 f8c; s32 f90; s32 f94; s32 f98; s32 f9c; s32 fa0; s32 fa4; s32 fa8; s32 fac; };

/* 00159790: camera/target follow update (VU0 vector maths; lq/sq copies and VU0 ops are asm). */
struct V159790 {
    f32 x, y, z, w;
    V159790() {}
    V159790(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V159790& operator=(const V159790& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V159790 operator-(const V159790& b) const {
        V159790 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V159790 operator+(const V159790& b) const {
        V159790 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M159790 {
    f32 r[4][4];
    M159790() {}
    M159790& operator=(const M159790& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    V159790 operator*(const V159790& v) const {
        V159790 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct S159790 { f32 f0, dist, height; s32 flag; V159790 pos; };
struct Obj159790 { u8 pad[1712]; M159790 mtx; };
struct C159790 { u8 p0[48]; f32 f48; s32 x52; u8 p38[12]; void* target; u8 p48[24]; V159790 v96; u8 p70[16]; V159790 v128; };
extern Obj159790* D_0034aa18;
extern u8 D_0034aa11;
extern f32 D_004f3600;
extern "C" {
void func_001904f0(Obj159790**, S159790*);
V159790* func_0016c028(void*);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void func_0011b6a8(M159790*);
void func_0011b720(M159790*, f32);
void func_0013f648(C159790*);
C0031a9d8* func_0031a9d8(C0031a9d8* d, C0031a9d8* s) {
    *(M4_0*)d = *(M4_0*)s;
    s32 a0 = s->fa0, a8 = s->fa8; d->fa0 = a0; d->fa8 = a8;
    C0031a9d8* q; asm("" : "=r"(q) : "0"(s), "m"(d->fa0), "m"(d->fa8));
    s32 xac = q->fac, x90 = q->f90, x94 = q->f94, x98 = q->f98, x9c = q->f9c, xa4 = q->fa4, x8c = q->f8c;
    d->f8c = x8c; d->f90 = x90; d->f94 = x94; d->f98 = x98; d->f9c = x9c; d->fa4 = xa4; d->fac = xac;
    return d; }

// 00159790: moved to src/harata/libdk/talkcamera.cpp
}
