// Linked unit 0x1c91c8-0x1c9770: the class with the vtable at 0x351f08 (gap methods 0x1c9288,
// 0x1c94c8 and 0x1c9608 written here). .rodata at 0x36e098. YS::SACRIFICE (sacrifice.cpp) follows.

#include "../common/types.h"

// ---- 001c91c8 from src/anon/batch_w87.cpp
namespace n001c91c8 {
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
extern u8* D_00352130 asm("D_00352130");
struct Elem64 { u8 p8[8]; void* h; u8 d[52]; ~Elem64() {} } __attribute__((aligned(16)));
void YS__ACTION_LKDASH__start(void* unused, u8* p) asm("YS__ACTION_LKDASH__start");
void YS__ACTION_LKDASH__start(void* unused, u8* p) {
    f32 tmp[4] __attribute__((aligned(16)));
    f32* dst = (f32*)(p + 32);
    f32 s = *(f32*)(*(u8**)(p + 300) + 36);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(tmp), "r"(p + 16), "f"(s) : "$8", "memory");
    if (dst != tmp)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(tmp) : "$8", "memory");
    *(u32*)(p + 268) = (*(u32*)(p + 268) | 0x10) & ~0x20;
    func_0017f488(p + 320, 202, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 201, 0, 0.0f, 0.0f);
    *(f32*)(p + 240) = *(f32*)(D_00352130 + 192);
}
}  // namespace n001c91c8

// ---- 001c9288 gap: vtable 0x351f08 slot 1
namespace n001c9288 {
void func_001c9288(void* self, u8* o) asm("func_001c9288");
void func_001c9288(void* self, u8* o) {
    *(u32*)(o + 268) &= ~0x10;
}
}  // namespace n001c9288

// ---- 001c92a0 from src/anon/batch_w320.cpp
namespace n001c92a0 {
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QWord& operator=(const QWord& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline QWord Cross(QWord& a, QWord& b) {
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot(QWord& a, QWord& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Sub2884 { u32 f0; u32 f4; u32 f8; };
struct Cfg { u8 pad[172]; f32 f172; u8 pad176[12]; f32 f188; };
struct Ob {
    u8 p0[16]; QWord q16; QWord q32; u8 p48[268 - 48]; u32 flags; u8 p272[320 - 272];
    u8 sub[32]; u32 f352; u8 p356[380 - 356]; s32 f380; s32 f384; u8 p388[2884 - 388]; Sub2884* p2884;
};
extern Cfg* D_00352130 asm("D_00352130");
s32 func_001c90f0(void) asm("func_001c90f0");
void func_001c9110(void*, Ob*) asm("func_001c9110");
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_0016bd60(Ob*, s32) asm("func_0016bd60");
void YS__ACTION_LKDASH__control(void* x, Ob* o) asm("YS__ACTION_LKDASH__control");
void YS__ACTION_LKDASH__control(void* x, Ob* o)
{
    QWord v;
    v = o->q32;
    Normalize(&v);
    QWord c;
    c = Cross(v, o->q16);
    u32 fl = o->flags;
    if (fl & 0x10) {
        f32 d = Dot(v, o->q16);
        if (func_001c90f0() && !(o->p2884->f8 & 4)) {                  
            o->flags &= ~0x10;
            func_0017f540(o->sub, 202, 0.0f, 0.0f);
            if (c.f[1] <= 0.0f) func_0017f5e0(o->sub, 203, 0, 0.0f, 0.0f);
            else func_0017f5e0(o->sub, 204, 0, 0.0f, 0.0f);
            return;
        }
        if (!(o->flags & 0x20)) {
            void* s = o->sub;
            if (o->f352 & 4) {
                if (D_00352130->f188 < d) {
                    func_0017f540(s, 201, 8.0f, 0.0f);
                } else {
                    f32 z = 0.0f; s32 id = 203; if (!(c.f[1] <= z)) id = 204; func_0017f540(s, id, 12.0f, z);
                }
                return;
            }
        }
    } else if ((fl & 0x20) && o->f384 == o->f380) {
        u32 t = o->f352;
        if (t & 0x10) goto call;
        if (t & 4) {
        call:
            func_0016bd60(o, 0);
            return;
        }
    }
    func_001c9110(x, o);
}
}  // namespace n001c92a0

// ---- 001c94c8 gap: vtable 0x351f08 slot 7
namespace n001c94c8 {
struct V94c8 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8* D_00352130 asm("D_00352130");
extern f32 D_00349e10 asm("D_00349e10");
V94c8 kn__MotionPrototype0__calcLimitValue(u8*, f32, f32) asm("kn__MotionPrototype0__calcLimitValue");
u32 func_001c90f0(void*, u8*) asm("_Z13func_001c90f0jjjj");
void func_0017f540(u8*, s32, f32, f32) asm("_ZN2YS6MOTION6changeEiff");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
V94c8 func_001c94c8(void* self, u8* o) asm("func_001c94c8");
V94c8 func_001c94c8(void* self, u8* o) {
    V94c8 unused;
    f32 v;
    u32 fl = *(u32*)(o + 268);
    if (fl & 0x10) {
        u8* t = *(u8**)(o + 300);
        *(f32*)(o + 28) = *(f32*)(t + 36);
        v = *(f32*)(t + 40);
    } else if (fl & 0x20) {
        *(f32*)(o + 28) = 0.0f;
        v = *(f32*)(D_00352130 + 200);
    } else {
        if (0.0f < *(f32*)(o + 28)) *(f32*)(o + 28) = *(f32*)(D_00352130 + 204);
        f32 t = *(f32*)(o + 240) - D_00349e10;
        *(f32*)(o + 240) = t;
        if (t <= 0.0f) {
            if (func_001c90f0(self, o)) func_0017f540(o + 320, 202, 0.0f, 0.0f);
            func_0017f5e0(o + 320, 5, 0, 0.0f, 0.0f);
            func_0017f5e0(o + 320, 0, 0, 0.0f, 0.0f);
            *(u32*)(o + 268) |= 0x20;
        }
        v = *(f32*)(D_00352130 + 196);
    }
    return kn__MotionPrototype0__calcLimitValue(o, v, v);
}
}  // namespace n001c94c8

// ---- 001c9608 gap: vtable 0x351f08 slot 4
namespace n001c9608 {
struct V9608 {
    f32 x, y, z, w;
    V9608() {}
    V9608(const V9608& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V9608& operator=(const V9608& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
void YS__OBJ__prepare_jump(u8*, V9608) asm("YS__OBJ__prepare_jump");
void func_0016bd60(u8*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_001c9608(void* self, u8* o) asm("func_001c9608");
void func_001c9608(void* self, u8* o) {
    V9608 v;
    v = *(V9608*)(o + 2144);
    v.y = 0.0f;
    v.w = v.normalize();
    YS__OBJ__prepare_jump(o, v);
    func_0016bd60(o, 26);
    func_0017f488(o + 320, 4, 8.0f, 0.0f);
    *(u32*)(o + 264) |= 0x4000000;
}
}  // namespace n001c9608

// ---- 001c96c8 from src/anon/batch_w67.cpp
namespace n001c96c8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Mtx {
    Vec4 r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void YS__OBJ__prepare_jump(void*, Vec4) asm("YS__OBJ__prepare_jump");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
Vec4 func_0017c030(u8*, s32*, u8) asm("func_0017c030");
void YS__ACTION_LKDASH__party_jump(void* a, u8* o, u8 f) asm("YS__ACTION_LKDASH__party_jump");
void YS__ACTION_LKDASH__party_jump(void* a, u8* o, u8 f)
{
    s32 x;
    Vec4 v = func_0017c030(o, &x, f);
    if (*(u32*)(o + 268) & 0x10) {
        v.w = *(f32*)(*(u8**)(o + 300) + 36);
        YS__OBJ__prepare_jump(o, v);
        o[1300] = 5;
    } else {
        YS__OBJ__prepare_jump(o, v);
    }
    func_0017f488(o + 320, x, 0.0f, 0.0f);
    *(s32*)(o + 256) = 4;
    *(s32*)(o + 260) = 5;
}
}  // namespace n001c96c8

