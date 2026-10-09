#include "../common/types.h"
struct Bits3188 { u32 w[1]; void set(u32 i) { w[i >> 5] |= 1 << (i & 31); } };
struct S3188 { u8 pad[0x1898]; Bits3188 bits; };
struct R3188 { u8 b0, b1, b2, b3; u8 pad[14]; u16 id; };
struct VH {
    f32 x, y, z, w;
    VH() {}
    VH(const VH& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    VH& operator=(const VH& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    VH& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    VH& operator+=(const VH& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline VH operator-(const VH& a, const VH& b) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline VH operator*(const VH& a, f32 s) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline VH Lerp(const VH& a, const VH& b, f32 t) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct ObjH { VH pos; u8 pad[32]; VH vel; u8 pad2[8]; u8* owner; };
union UUd098 { f32* p; s16 h; u32 u; u8 c; };
struct P22d098 { u8 pad[4]; s16 h4; s16 h6; u8 x8[4]; u8 x12[4]; };
extern "C" {
extern S3188 D_0032e020;
R3188* func_001a80c8(void*, s32);
s32 func_001a3018(void*, s32, s32);
void func_001a32c8(void*, s32);
void* func_00188fe0(void*, s32);
void func_00188a28(void*, void*);
void func_00188b68(void*, void*, u8);
void func_001a39c8(void*);
s32 func_001a3188(void* a0, s32 a1, u8 a2) {
    R3188* r = func_001a80c8(a0, a1);
    S3188* g = &D_0032e020;
    s32 n = func_001a3018(a0, a1, 1);
    u32 one = 1;
    if (n == 0) return 0;
    if (r->b3 & one) goto A;
    if (n == 100) {
A:
        func_001a32c8(a0, 1);
    } else {
        void* v = func_00188fe0(g, n);
        switch (r->b2) {
        case 0:
            func_00188a28(v, a0);
            if (n == 1 || n == 14) func_001a39c8(a0);
            break;
        case 19:
            func_00188b68(v, a0, a2);
            break;
        }
    }
    if (r->b3 & one) return 1;
    g->bits.set(r->id);
    return 1;
}
extern f32 D_00349e10;
VH func_0016bda8(u8*);
s32 func_001ccc38(ObjH* a0) {
    VH d = func_0016bda8(a0->owner) - a0->pos;
    f32 len = d.Normalize();
    d *= 20.0f;
    a0->vel = Lerp(a0->vel, d, 0.1f);
    a0->pos += a0->vel * D_00349e10;
    if (len < 100.0f) {
        ++*(s32*)(a0->owner + 2760);
        return 0;
    }
    return 1;
}
void func_0022d000(u32);
void func_0022d068(u32*);
s32 func_002282f0(s32);
s32 func_002282d8(void);
s32 func_00225b00(s32);
void func_0015c880(f32);
u8* func_00102c18(s32, s32, void*);
u32 func_001050c8(void);
f32* func_001063c0(s32, u32);
f32 func_00227c78(void*);
void func_0014f030(void*, f32, f32, f32);
void func_0022d098(P22d098* p) {
    if (func_002282f0(p->h4)) return;
    s32 id = func_002282d8();
    if (!func_00225b00(p->h4)) {
        u8* s1 = func_00102c18(1, id, (void*)func_0022d000);
        *(void**)(s1 + 48) = (void*)func_0022d068;
        f32* o = func_001063c0(12, func_001050c8());
        ((UUd098*)o)[0].u = 0; ((UUd098*)o)[1].u = 0; o[2] = 1.0f;
        ((UUd098*)(s1 + 8))->p = o;
        f32 a = ((UUd098*)&p->h6)->h;
        f32 x = func_00227c78(p->x8);
        a = a + a;
        func_0014f030(o, x, func_00227c78(p->x12), a);
    } else {
        func_0015c880(func_00227c78(p->x12));
    }
}
}
