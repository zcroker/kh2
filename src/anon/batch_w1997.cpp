#include "../common/types.h"
extern "C" {
struct Snd9b8 { u8 pad[0x10]; s32 f10; s32 f14; s32 f18; u8 pad1[8]; u32 f24; u8 pad2[4]; s16 f2c; u8 pad3[2]; u8 b30; u8 b31; };
void func_002b726c(s32, s32, s32, s32, s32);
void wt72e4(u32, u32, u32) asm("_Z16wtarget_002b72e4jjjj");
void func_002b7334(s32, s32, s32, s32, s32);
void func_002b73ac(s32, s32, s32, s32, s32);
s32 func_002bb510(Snd9b8*);
void func_002bb5f8(Snd9b8*);
s32 func_002bb8b0(Snd9b8*);
void func_002bb950(Snd9b8*);
void StopBg9b8(s32, s32) asm("_ZN2Tz9MenuSound14StopBgSeHandleEz");
void func_002bb9b8(Snd9b8* s) {
    s32 r;
    switch (s->b30) {
    case 0:
        return;
    case 1:
        switch (s->b31) {
        case 1: case 2: case 3: func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        case 4: func_002bb950(s); func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        default: func_002bb5f8(s); func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        }
        break;
    case 2:
        if ((s->f24 & 2) && func_002bb510(s) == 0) {
            StopBg9b8(s->f14, 1);
            return;
        }
        switch (s->b31) {
        case 2:
            func_002b73ac(s->f18, s->f10, s->f14, func_002bb8b0(s), 30);
            return;
        case 4:
            func_002bb950(s);
            r = func_002bb8b0(s);
            if (r == 0) {
                if (func_002bb510(s)) wt72e4(s->f18, s->f10, s->f14);
                return;
            }
            if (func_002bb510(s)) func_002b7334(s->f18, s->f10, s->f14, r, s->f2c);
            else func_002b726c(s->f18, s->f10, s->f14, r, s->f2c);
            return;
        default:
            func_002bb5f8(s);
        case 1: case 3:
            r = func_002bb8b0(s);
            func_002b7334(s->f18, s->f10, s->f14, r, s->f2c);
            return;
        }
    case 3:
        StopBg9b8(s->f14, 1);
        return;
    }
}

struct Vec4f0 {
    f32 x, y, z, w;
    Vec4f0() {}
    Vec4f0(const Vec4f0& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec4f0& operator=(const Vec4f0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj4f0 { u8 pad[16]; Vec4f0 v10; Vec4f0 v20; u8 pad2[284 - 48]; f32 f11c; };
Vec4f0 func_0016af58(Obj4f0*);
void func_00184ad0(Obj4f0*, Vec4f0*, f32);
void func_00184540(u8*, u32, f32, f32);
f32 func_002f87c0(f32);
f32 func_002f8870(f32);
u64 func_00313b80(f32) __attribute__((const));
s32 func_003142e0(u64, u64) __attribute__((const));
extern s8 D_01e2c068;
extern f32 D_01e2c070;
static inline f32 v4f0_len(const Vec4f0& v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
static inline Vec4f0 v4f0_scale(const Vec4f0& v, f32 s) {
    Vec4f0 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline f32 v4f0_norm(Vec4f0* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 v4f0_dot(const Vec4f0& a, const Vec4f0& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
u8* func_002eb4f0(u8* ret, Obj4f0* o) {
    if (!D_01e2c068) {
        D_01e2c070 = func_002f87c0(0.34906584f);
        D_01e2c068 = 1;
    }
    Vec4f0 a;
    if (func_003142e0(0, func_00313b80(o->v10.w)) < 0) {
        func_00184ad0(o, &o->v10, o->f11c);
        a = func_0016af58(o);
        f32 l = v4f0_len(o->v20);
        o->v20 = v4f0_scale(a, l);
        a.w = o->v10.w;
        o->v10 = a;
    }
    a = o->v20;
    v4f0_norm(&a);
    Vec4f0 b = func_0016af58(o);
    f32 d = func_002f8870(v4f0_dot(a, b));
    f32 k = d < D_01e2c070 ? 0.1f : 0.015f;
    func_00184540(ret, (u32)o, 0.4f, 1.0f - k);
    return ret;
}
}
