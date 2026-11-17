#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../harata/libdk/lockon.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/dbg_smenu.hpp"
#include "../harata/libdk/objcamera.hpp"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 0013fca8 from src/anon/tiny_auto80_solver.cpp
namespace n0013fca8 {
u32 func_0013f9e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0013f9e0jjjjjjjj");
u32 func_0013fca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0013fca8jjjjjjjj");
u32 func_0013fca8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 = a0;
    a2 = a0 + 96;
    a3 = 1;
    a0 = a0 + 112;
    a1 = a1 + 128;
    a4 = 0;
    return ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013f9e0)(a0, a1, a2, a3, a4, a5, a6, a7);
}
}  // namespace n0013fca8

// ---- 0013fcd8 from src/anon/tiny_auto80_queue.cpp
namespace n0013fcd8 {
f32 func_002f8ad0(f32, f32) asm("_Z13func_002f8ad0ff");
void func_0013fcd8(u32 a0, f32* a1) asm("_Z13func_0013fcd8jPf");
void func_0013fcd8(u32 a0, f32* a1) {
    f32 f0 = -a1[0];
    f32 f1 = -a1[2];
    a1[0] = f0;
    a1[2] = f1;
    func_002f8ad0(f0, f1);
}
}  // namespace n0013fcd8

// ---- 0013fd10 from src/anon/batch_w48.cpp
namespace n0013fd10 {
struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
Vq func_0016af58(u32) asm("func_0016af58");
void func_0013fcd8(void*, Vq) asm("func_0013fcd8");
void func_0013fd10(u8* o) asm("func_0013fd10");
void func_0013fd10(u8* o) {
    Vq v;
    v = func_0016af58(*(u32*)(o + 68));
    func_0013fcd8(o, v);
}
}  // namespace n0013fd10

// ---- 0013fd78 from src/harata/libdk/objcamera.cpp
namespace dk {
void ObjCamera::initRadius() {
    ObjCameraLayout* c = reinterpret_cast<ObjCameraLayout*>(this);
    c->radius = c->defaultRadius;
}
}  // namespace dk

// ---- 0013fd88 from src/anon/misc_1.cpp
namespace n0013fd88 {
void func_0013fd88(void* self) asm("_Z13func_0013fd88Pv");
void func_0013fd88(void* self) { *(s32*)((char*)self + 196) = 0; }
}  // namespace n0013fd88

// ---- 0013fd90 from src/harata/libdk/objcamera.cpp
namespace dk {
void ObjCamera::initLockRadius() {
    ObjCameraLayout* c = reinterpret_cast<ObjCameraLayout*>(this);
    c->radius = c->defaultLockRadius;
}
}  // namespace dk

// ---- 0013fda0 from src/anon/tiny_auto80_queue.cpp
namespace n0013fda0 {
u32 func_0013fda0(u32 a0) asm("_Z13func_0013fda0j");
u32 func_0013fda0(u32 a0) {                  
    f32 f0 = *(f32*)((u32)a0 + (s32)(72));
    f32 f1 = *(f32*)((u32)a0 + (s32)(208));
    u32 r2 = 0u;
    if (f0 <= f1) {
        *(f32*)((u32)a0 + (s32)(72)) = f1;
        r2 = 1u;
    }
    return r2;
}
}  // namespace n0013fda0

// ---- 0013fdc8 from src/anon/tiny_auto80_queue.cpp
namespace n0013fdc8 {
u32 func_0013fdc8(u32 a0) asm("_Z13func_0013fdc8j");
u32 func_0013fdc8(u32 a0) {                  
    f32 f0 = *(f32*)((u32)a0 + (s32)(72));
    f32 f1 = *(f32*)((u32)a0 + (s32)(212));
    u32 r2 = 0u;
    if (f1 <= f0) {
        *(f32*)((u32)a0 + (s32)(72)) = f1;
        r2 = 1u;
    }
    return r2;
}
}  // namespace n0013fdc8

// ---- 0013fdf0 from src/anon/batch_w82.cpp
namespace n0013fdf0 {
s32 func_00158450(void*) asm("func_00158450");
s32 func_001584a0(void*) asm("func_001584a0");
void func_0013fda0(void*) asm("func_0013fda0");
void func_0013fdc8(void*) asm("func_0013fdc8");
void func_0013fdf0(u8* o, u8* p, f32 s) asm("func_0013fdf0");
void func_0013fdf0(u8* o, u8* p, f32 s)
{
    if (func_00158450(p)) {
        *(f32*)(o + 72) -= *(f32*)(p + 44) * 8.0f * s;
        func_0013fda0(o);
    } else if (func_001584a0(p)) {
        *(f32*)(o + 72) += *(f32*)(p + 44) * 8.0f * s;
        func_0013fdc8(o);
    }
}
}  // namespace n0013fdf0

// ---- 0013fec0 from src/anon/batch_w27.cpp
namespace n0013fec0 {
f32 func_0013fd10(void*) asm("func_0013fd10");
void func_0013fd78(void*) asm("func_0013fd78");
void func_0013fec0(u8* p) asm("func_0013fec0");
void func_0013fec0(u8* p) {
    *(f32*)(p + 80) = func_0013fd10(p);
    func_0013fd78(p);
    u8* d = p + 16;
    u8* s = p + 96;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace n0013fec0

// ---- 0013ff08 from src/anon/batch_w286.cpp
namespace n0013ff08 {
#define QCOPY_bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_bfa0 {
    f32 x, y, z, w;
    QV_bfa0() {}
    QV_bfa0(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_bfa0(const QV_bfa0& o) { QCOPY_bfa0(this, &o); }
    QV_bfa0& operator=(const QV_bfa0& o) { if (this != &o) QCOPY_bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline QV_bfa0 operator-(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator+(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator*(const QV_bfa0& a, f32 k) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
#define QCOPY_b0a8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_b0a8 {
    f32 x, y, z, w;
    QV_b0a8() {}
    QV_b0a8(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_b0a8(const QV_b0a8& o) { QCOPY_b0a8(this, &o); }
} __attribute__((aligned(16)));
struct In13 { u64 x0; u64 x8; u8 p10[0x1c]; f32 x2c; u8 p30[0xc]; f32 x3c; };
struct Ob13 { u8 p0[0x3a]; u8 x3a; u8 p3b[5]; s32 x40; u8* x44; u8 p48[4]; f32 x4c; f32 x50; u8 p54[0x6c]; f32 xc0; };
extern f32 D_004573e8 asm("D_004573e8");
s32 func_0019c498(u8*) asm("func_0019c498");
s32 func_0019c4d0(u8*) asm("func_0019c4d0");
void func_0013fd88(Ob13*) asm("func_0013fd88");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
void func_0013fdf0(Ob13*, In13*, f32) asm("func_0013fdf0");
void func_0013fec0(Ob13*) asm("func_0013fec0");
s32 func_001585a0(In13*) asm("func_001585a0");
s32 func_001584f8(In13*) asm("func_001584f8");
s32 func_00158548(In13*) asm("func_00158548");
f32 func_0017ce10(f32) asm("func_0017ce10");
s32 func_0013ff08(Ob13* o, In13* in, f32 dt) asm("func_0013ff08");
s32 func_0013ff08(Ob13* o, In13* in, f32 dt) {
  s32 r = 0;
  if (func_0019c498(o->x44) && (in->x8 & 0x400000)) {
    o->x40 = 1;
    o->xc0 = o->x4c + 0x1.921fb4p+1f;
    func_0013fd88(o);
    { f32 c = 30.0f; f32 a = 1.0f; func_001ad990(o->x44 + 0x834, a, 0.0f, c); }
  } else if (in->x8 & 0x20000) {
    func_0013fec0(o);
    r = 0;
    if (in->x3c != 0.0f) r = 1;
  } else if (func_001584f8(in)) {
    o->x4c += D_004573e8 * in->x2c * dt;
    o->x50 = o->x4c = func_0017ce10(o->x4c);
  } else if (func_00158548(in)) {
    o->x4c -= D_004573e8 * in->x2c * dt;
    o->x50 = o->x4c = func_0017ce10(o->x4c);
  }
  if (!func_0019c4d0(o->x44) || (in->x0 & (1ull << 32))) {
    func_0013fdf0(o, in, dt);
  }
  o->x3a = 1;
  if (func_001585a0(in)) o->x3a = 0;
  return r;
}
}  // namespace n0013ff08
#undef QCOPY_bfa0
#undef QCOPY_b0a8

// ---- 001400b0 from src/anon/batch_wcx.cpp
namespace n001400b0 {
f32 fabsf(f32) asm("fabsf");
void func_0013fda0(u8*) asm("func_0013fda0");
void func_0013fdc8(u8*) asm("func_0013fdc8");
void func_001400b0(u8* p, f32 x) asm("func_001400b0");
void func_001400b0(u8* p, f32 x)
{
    if (fabsf(*(f32*)(p + 72) - *(f32*)(p + 204)) >= 1.0f) {          
        if (*(f32*)(p + 204) < *(f32*)(p + 72)) {
            *(f32*)(p + 72) = *(f32*)(p + 72) - x;
            func_0013fda0(p);
        } else {
            *(f32*)(p + 72) = *(f32*)(p + 72) + x;
            func_0013fdc8(p);
        }
    }
}
}  // namespace n001400b0

// ---- 00140150 from src/anon/batch_wcx.cpp
namespace n00140150 {
f32 fabsf(f32) asm("fabsf");
void func_0013fda0(u8*) asm("func_0013fda0");
void func_0013fdc8(u8*) asm("func_0013fdc8");
void func_00140150(u8* p, f32 x) asm("func_00140150");
void func_00140150(u8* p, f32 x)
{
    if (fabsf(*(f32*)(p + 72) - *(f32*)(p + 200)) >= 1.0f) {          
        if (*(f32*)(p + 200) < *(f32*)(p + 72)) {
            *(f32*)(p + 72) = *(f32*)(p + 72) - x * 0.5f;
            func_0013fda0(p);
        } else {
            *(f32*)(p + 72) = *(f32*)(p + 72) + x * 0.5f;
            func_0013fdc8(p);
        }
    }
}
}  // namespace n00140150

// ---- 00140210 from src/anon/batch_w100.cpp
namespace n00140210 {
extern f32 D_004573e0 asm("D_004573e0");
extern f32 D_004573e4 asm("D_004573e4");
s32 func_00184478(u32) asm("func_00184478");
f32 func_0013fd10(u8*) asm("func_0013fd10");
f32 fabsf(f32) asm("fabsf");
f32 func_0017ce80(f32, f32, f32) asm("func_0017ce80");
void func_00140150(u8*, f32) asm("func_00140150");
void func_00140210(u8* o, u8* b, f32 k) asm("func_00140210");
void func_00140210(u8* o, u8* b, f32 k) {
    f32 h, r, sc, v, a, c;
    if (!func_00184478(*(u32*)(o + 68))) return;
    if (*(f32*)(b + 60) == 0.0f) return;
    if (*(f32*)(b + 44) != 0.0f) return;
    if (!(*(f32*)(b + 52) < 0.9f)) return;
    h = 1.0f;
    r = func_0013fd10(o);
    sc = D_004573e0 + D_004573e4 * (*(f32*)(*(u8**)(o + 68) + 276) - 8.0f);
    a = (fabsf(*(f32*)(b + 52)) + h) * ((fabsf(*(f32*)(b + 48)) + h) * 2.0f) * *(f32*)(b + 60) * sc * k;
    v = func_0017ce80(*(f32*)(o + 76), r, a);
    *(f32*)(o + 76) = v;
    *(f32*)(o + 80) = v;
    func_00140150(o, k);
}
}  // namespace n00140210

// ---- 00140370 from src/anon/tiny_auto80_queue.cpp
namespace n00140370 {
u32 func_0013fec0(...) asm("func_0013fec0");
u32 func_00140370(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00140370jjjjjjjj");
u32 func_00140370(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15, r16;
    r15 = (u32)((s32)0u + (1));
    r14 = (u32)(*(u8*)((u32)r4 + (s32)(57)));
    r16 = (u32)(r5 & 0x00ffu);
    if (r14 == r15) {
        *(u8*)((u32)r4 + (s32)(57)) = (u8)0u;
        r16 = (u32)((s32)0u + (1));
        r2 = ((u32(*)())func_0013fec0)();
    }
    r2 = r16;
    return r2;
}
}  // namespace n00140370

// ---- 001403b0 from src/anon/batch_w90.cpp
namespace n001403b0 {
struct VObj { void** vt; };
typedef s32 (*VFn)(void*);
extern f32 D_00349e10 asm("D_00349e10");
void func_0013f5f0(void*) asm("func_0013f5f0");
s32 func_00167f18(s32) asm("func_00167f18");
s32 func_0013ff08(void*, s32, f32) asm("func_0013ff08");
s32 func_00140370(void*, s32) asm("func_00140370");
void func_00140210(void*, s32, f32) asm("func_00140210");
void func_0013f828(void*) asm("func_0013f828");
void func_0013f888(void*, void*, s32) asm("func_0013f888");
void func_0013fca8(void*) asm("func_0013fca8");
void func_001403b0(u8* self) asm("func_001403b0");
void func_001403b0(u8* self)
{
    s32 r = 0;
    func_0013f5f0(self);                         
    s32 g = func_00167f18(0);
    VObj* o = *(VObj**)(self + 68);
    f32 dt = D_00349e10;
    if (((VFn)o->vt[16])(o)) r = func_0013ff08(self, g, dt);
    r = func_00140370(self, r);
    if (!r && self[58] == 1) func_00140210(self, g, dt);
    func_0013f828(self);
    func_0013f888(self, self + 128, r);
    func_0013fca8(self);
}
}  // namespace n001403b0

// ---- 00140480 from src/anon/batch_w54.cpp
namespace n00140480 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q16 {
    u128 v;
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct Q16Pair {
    Q16 v[2];
};
s32 func_00143d10(Q16Pair*, Q16*, void*, s32*) asm("func_00143d10");
void func_00140480(Q16* p) asm("func_00140480");
void func_00140480(Q16* p) {
    Q16Pair in;
    Q16 out;
    s32 x;
    s32 y;
    Q16* pi = &in.v[1];
    Q16* ps = p + 1;
    in.v[0] = p[0];
    *pi = *ps;
    y = 0;
    Q16* po = &out;
    s32* px = &x;
    if (func_00143d10(&in, po, px, &y)) *p = *po;
}
}  // namespace n00140480

// ---- 00140500 from src/anon/batch_w94.cpp
namespace n00140500 {
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0011b6a8(f32*) asm("func_0011b6a8");
void func_0011b6d8(f32*, f32) asm("func_0011b6d8");
void func_0011b720(f32*, f32) asm("func_0011b720");
extern f32 D_004573f0 asm("D_004573f0");
extern f32 D_004573f4 asm("D_004573f4");
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void qcopy(V4* d, V4* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void mulv(V4* out, f32* m, V4* v) {
    V4 t;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t"
                 "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(&t) : "memory");
    qcopy(out, &t);
}
static inline void addv(V4* out, V4* a, V4* b) {
    V4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&t), "r"(a), "r"(b) : "memory");
    qcopy(out, &t);
}
void func_00140500(u8* p) asm("func_00140500");
void func_00140500(u8* p) {
    *(f32*)(p + 192) = func_0017ce10(*(f32*)(p + 192));
    f32 v = func_0017ce10(*(f32*)(p + 196));
    *(f32*)(p + 196) = v;
    if (D_004573f4 < v) *(f32*)(p + 196) = D_004573f4;
    else if (v < D_004573f0) *(f32*)(p + 196) = D_004573f0;
    V4 d;
    f32 m[16] __attribute__((aligned(16)));
    d.w = d.y = d.x = 0.0f;
    d.z = 350.0f;
    func_0011b6a8(m);
    func_0011b6d8(m, *(f32*)(p + 196));
    func_0011b720(m, *(f32*)(p + 192));
    mulv(&d, m, &d);
    addv((V4*)(p + 128), (V4*)(p + 96), &d);
}
}  // namespace n00140500

// ---- 00140618 from src/anon/batch_w92.cpp
namespace n00140618 {
struct V140 {
    f32 x, y, z, w;
    V140& operator=(const V140& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct In140 { u64 f0; u64 f8; u8 pad[20]; f32 f36; u32 pad2; f32 f44; };
s32 func_0019c498(u32) asm("func_0019c498");
s32 func_0019c4d0(u32) asm("func_0019c4d0");
void func_00141010(f32) asm("func_00141010");
f32 func_0013fd10(u8*) asm("func_0013fd10");
void func_0013f828(u8*) asm("func_0013f828");
void func_0013f888(u8*, u8*, s32) asm("func_0013f888");
void func_0013fd88(u8*) asm("func_0013fd88");
V140 func_0016c508(u32) asm("func_0016c508");
void func_00140500(u8*) asm("func_00140500");
extern f32 D_004573ec asm("D_004573ec");
extern f32 D_00349e10 asm("D_00349e10");
void func_00140618(u8* p, In140* in) asm("func_00140618");
void func_00140618(u8* p, In140* in) {
    if (!func_0019c498(*(u32*)(p + 68)) || (in->f8 & 0x400000)) {
        func_00141010(30.0f);
        *(f32*)(p + 76) = *(f32*)(p + 80) = func_0013fd10(p);
        func_0013f828(p);
        func_0013f888(p, p + 128, 0);
        return;
    }
    if (in->f8 & 0x20000) func_0013fd88(p);
    f32 k = D_00349e10;
    *(V140*)(p + 96) = func_0016c508(*(u32*)(p + 68));
    f32 x = func_0013fd10(p);
    *(f32*)(p + 80) = x;
    *(f32*)(p + 76) = x;
    *(f32*)(p + 192) = x + 3.1415925f;
    if (!func_0019c4d0(*(u32*)(p + 68)) && (in->f0 & 0xc0000)) {
        *(f32*)(p + 196) -= in->f36 * in->f44 * D_004573ec * k;
    }
    func_00140500(p);
}
}  // namespace n00140618

// ---- 00140760 from src/anon/batch_w37.cpp
namespace n00140760 {
void func_0013f5f0(void*) asm("func_0013f5f0");
u32 func_00167f18(u32) asm("func_00167f18");
void func_00140618(void*, u32) asm("func_00140618");
typedef s32 (*VFn)(void*);
void func_00140760(u8* p) asm("func_00140760");
void func_00140760(u8* p) {
    func_0013f5f0(p);                         
    u32 v = func_00167f18(0);
    u8* o = *(u8**)(p + 68);
    if ((*(VFn*)(*(u8**)o + 64))(o)) func_00140618(p, v);
}
}  // namespace n00140760

// ---- 001407d0 from src/anon/batch_w55.cpp
namespace n001407d0 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct FpW55 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; } __attribute__((aligned(16)));
s32 func_0015ce80(void) asm("func_0015ce80");
void func_0015ceb8(Q16*) asm("func_0015ceb8");
void func_0015cea0(Q16*) asm("func_0015cea0");
f32 func_0015ced0(void) asm("func_0015ced0");
f32 func_0015cee0(void) asm("func_0015cee0");
void func_0015ce90(void) asm("func_0015ce90");
void func_001407d0(u8* p) asm("func_001407d0");
void func_001407d0(u8* p) {
    if (!func_0015ce80()) return;
    Q16 t;
    func_0015ceb8(&t);
    if ((Q16*)p != &t) copyQ(p, &t);
    u8* q = p + 16;
    func_0015cea0(&t);
    if ((Q16*)q != &t) copyQ(q, &t);
    *(f32*)(p + 32) = func_0015ced0();
    *(f32*)(p + 36) = func_0015cee0();
    func_0015ce90();                       
}
}  // namespace n001407d0

// ---- 00140850 from src/anon/batch_w26.cpp
namespace n00140850 {
static inline void qcopy(void* d, const void* s) {
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
inline void* operator new(unsigned int, void* p) { return p; }
void func_00140850(u8* p) asm("func_00140850");
void func_00140850(u8* p) {
    qcopy(p + 144, p + 128);
    qcopy(p + 112, p + 96);
    qcopy(p + 176, p + 160);
}
}  // namespace n00140850

// ---- 001408a0 from src/anon/batch_w1625.cpp
namespace n001408a0 {
struct W1625V4 {
    f32 x, y, z, w;
    W1625V4() {}
    W1625V4(const W1625V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1625V4& operator=(const W1625V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void set(const W1625V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1625Target { u8 pad[0x114]; f32 dist; };
struct W1625Cam {
    W1625V4 eye;             
    W1625V4 at;              
    W1625V4 up;                                  
    u8 pad30[0x10];
    u32 mode;                
    W1625Target* target;         
    u8 pad48[0x18];
    W1625V4 at2;             
    W1625V4 at3;             
    W1625V4 eyeGoal;         
    W1625V4 eyeVel;          
    W1625V4 upGoal;          
    W1625V4 upVel;           
};
void Spring_13f6e8(W1625V4* out, W1625V4* pos, W1625V4* goal, W1625V4* vel, f32 dt, f32 k, f32 damp, f32 rest) asm("func_0013f6e8");
u8 func_0013f9e0(W1625V4*, W1625Cam*, W1625V4*, s32, s32) asm("func_0013f9e0");
void func_00140480(W1625Cam*) asm("func_00140480");
void func_0015a4e0(W1625Cam*) asm("func_0015a4e0");
u8* func_00106a18(s32) asm("func_00106a18");
void func_00106de8(u8*, s32, f32) asm("func_00106de8");
u8* func_00106a60(s32) asm("func_00106a60");
void func_00107300(u8*, W1625V4*, W1625Cam*, f32) asm("func_00107300");
void func_001408a0(W1625Cam* c, u8 noUpdate) asm("func_001408a0");
void func_001408a0(W1625Cam* c, u8 noUpdate)
{
    W1625V4 out, pos, goal, vel;
    f32 dt = 0.07f;
    if (!noUpdate && c->target) dt += (c->target->dist - 8.0f) * 0.0006f;
    pos.set(c->eye); goal.set(c->eyeGoal); vel.set(c->eyeVel);
    Spring_13f6e8(&out, &pos, &goal, &vel, dt + 0.03f, 2.5f, 0.5f, 1.0f);
    c->eye = out;
    pos.set(c->at); goal.set(c->at2); vel.set(c->at3);
    Spring_13f6e8(&out, &pos, &goal, &vel, dt, 2.5f, 0.5f, 1.0f);
    c->at = out;
    pos.set(c->up); goal.set(c->upGoal); vel.set(c->upVel);
    Spring_13f6e8(&out, &pos, &goal, &vel, dt, 2.5f, 0.5f, 0.001f);
    c->up = out;
    if (noUpdate) return;
    switch (c->mode) {
    case 0: case 3: case 6: case 8:
        if (func_0013f9e0(&c->at3, c, &c->at, 1, 0)) c->at2 = c->at;
        break;
    case 2:
        func_0015a4e0(c);
        break;
    case 1: case 7: case 9: case 10:
        func_00140480(c);
        break;
    case 11:
        break;
    }
    func_00106de8(func_00106a18(1), 0, c->up.x);
    func_00107300(func_00106a60(1), &c->at, c, c->up.y);
}
}  // namespace n001408a0

// ---- 00140b68 from src/anon/batch_wcx2.cpp
namespace n00140b68 {
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
u32 func_001069e8(void) asm("func_001069e8");
void func_00140850(u8*) asm("func_00140850");
void func_001403b0(u8*) asm("func_001403b0");
void func_0013f608(u8*) asm("func_0013f608");
void func_00140f30(u8*) asm("func_00140f30");
void func_001407d0(u8*) asm("func_001407d0");
void func_001408a0(u8*, u8) asm("func_001408a0");
void func_00140760(u8*) asm("func_00140760");
void func_0015a5a8(u8*) asm("func_0015a5a8");
void func_00159070_x8002(u8*) asm("func_00159070");
void func_00159b00(u8*) asm("func_00159b00");
void func_00159368(u8*) asm("func_00159368");
void func_00158dc0(u8*) asm("func_00158dc0");
void func_00158708(u8*) asm("func_00158708");
void func_00158658(u8*) asm("func_00158658");
void func_0014e8b8(u8*) asm("func_0014e8b8");
void func_001589d0(u8*) asm("func_001589d0");
void wtarget_00140b68(u8* p, u8 flag) asm("_Z16wtarget_00140b68jjjj");
void wtarget_00140b68(u8* p, u8 flag) {
    if (*(u32*)(p + 68) == 0) return;
    if (flag == 0 && func_001069e8() != 0) return;
    func_00140850(p);
    switch (*(u32*)(p + 64)) {
    case 0: func_001403b0(p); break;
    case 1: func_00140760(p); break;
    case 2: func_0015a5a8(p); break;
    case 3: func_00159070_x8002(p); break;
    case 4: func_00159b00(p); break;
    case 5: func_00159368(p); break;
    case 6: func_00158dc0(p); break;
    case 7: func_00158708(p); break;
    case 8: func_00158658(p); break;
    case 9: func_0014e8b8(p); break;
    case 10: func_001589d0(p); break;
    case 11: break;
    }
    func_0013f608(p);
    func_00140f30(p);
    func_001407d0(p);
    func_001408a0(p, flag);
}
}  // namespace n00140b68

// ---- 00140cc8 from src/anon/tiny_wrappers_more80_reloc.cpp
namespace n00140cc8 {
u32 func_00140b68(u32, u32, u32, u32) asm("_Z13func_00140b68jjjj");
extern u8 D_00348710 asm("D_00348710");
u32 func_00140cc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140cc8jjjj");
u32 func_00140cc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00140b68((u32)&D_00348710, 0x00000000u, a2, a3);
}
}  // namespace n00140cc8

// ---- 00140ce8 from src/anon/batch_w29.cpp
namespace n00140ce8 {
void createTask(void) asm("_ZN2dk9ObjCamera10createTaskEv");
void camera_task(void) asm("_ZN2dk11camera_taskEP4TASK");
void func_0015ce90(void) asm("func_0015ce90");
void func_001069b8(u32) asm("func_001069b8");
void func_0013f558(void*) asm("func_0013f558");
u8* func_00102c80(void) asm("func_00102c80");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
extern u8 D_00348710[] asm("D_00348710");
void createTask(void) {
    func_0015ce90();                       
    func_001069b8(0);                     
    func_0013f558(D_00348710);
    func_00102788(*(u32*)(func_00102c80() + 4), 1, 26000, (void*)camera_task);
}
}  // namespace n00140ce8

// ---- 00140d38 from src/anon/auto80_199_queue.cpp
namespace n00140d38 {
void func_00140d38(u32 a0, u32 a1) asm("_Z13func_00140d38jj");
void func_00140d38(u32 a0, u32 a1) {
    u8* s0 = D_00348710;
    *(u32*)(s0 + 68) = a0;

    if (func_00140dc0() == 7) {
        return;
    }

    *(u32*)(s0 + 60) = a1;
    *(u32*)(s0 + 64) = 0;
    func_00140ef8((u32)s0);

    if (func_001069e8() == 1) {
        return;
    }

    func_001069b8(0);                     
}
}  // namespace n00140d38

// ---- 00140db0 from src/anon/tiny.cpp
namespace n00140db0 {
void func_00140db0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140db0jjjj");
void func_00140db0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u32*)((u32)b + (-30892)) = (u32)0;
}
}  // namespace n00140db0

// ---- 00140dc0 from src/harata/libdk/objcamera.cpp
namespace dk {
extern u32 D_00348750 asm("D_00348750");
s32 ObjCamera::getMode() { return (s32)D_00348750; }
}  // namespace dk

// ---- 00140dd0 from src/anon/auto200_999.cpp
namespace dk {
void ObjCamera::returnMode() {
    if (*(u8 *)((u8 *)this + 59) != 0) {
        *(u32 *)((u8 *)this + 64) = 2;
        return;
    }
    *(u32 *)((u8 *)this + 64) = 0;
}
}  // namespace dk

// ---- 00140df0 from src/harata/libdk/objcamera.cpp
namespace dk {
extern ObjCamera D_00348710 asm("D_00348710");
ObjCamera* ObjCamera::getInstance() { return &D_00348710; }
}  // namespace dk

// ---- 00140e00 from src/anon/tiny_wrappers_more.cpp
namespace n00140e00 {
u32 func_00140e30(u32, u32, u32, u32) asm("_Z13func_00140e30jjjj");
u32 func_00140e00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140e00jjjj");
u32 func_00140e00(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00140e30(a0, 0x00000001u, a2, a3);
}
}  // namespace n00140e00

// ---- 00140e18 from src/anon/tiny_wrappers_more.cpp
namespace n00140e18 {
u32 func_00140e30(u32, u32, u32, u32) asm("_Z13func_00140e30jjjj");
u32 func_00140e18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140e18jjjj");
u32 func_00140e18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00140e30(a0, 0x00000000u, a2, a3);
}
}  // namespace n00140e18

// ---- 00140e30 from src/anon/batch_w77.cpp
namespace n00140e30 {
void wtarget_00140e30(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00140e30jjjj");
extern f32 D_004573f8[] asm("D_004573f8");
void func_0013f5f0(u8*) asm("func_0013f5f0");
void func_0013f608(u8*) asm("func_0013f608");
void func_0013fd78(u8*) asm("func_0013fd78");
static inline f32 Get(s32 i)
{
    return D_004573f8[i];
}
void wtarget_00140e30(u32 a, u32 b, u32 c, u32 d)
{
    u8* p = (u8*)a;
    s32 i = b * 6;
    *(f32*)(p + 220) = Get(i);
    *(f32*)(p + 224) = 0.0f;
    func_0013f5f0(p);                         
    func_0013f608(p);
    *(f32*)(p + 200) = Get(i + 1);
    *(f32*)(p + 204) = Get(i + 2);
    *(f32*)(p + 208) = Get(i + 3);
    *(f32*)(p + 212) = Get(i + 4);
    *(f32*)(p + 216) = Get(i + 5);
    func_0013fd78(p);
}
}  // namespace n00140e30

// ---- 00140ef8 from src/anon/tiny_wrappers_more.cpp
namespace n00140ef8 {
u32 func_00140e30(u32, u32, u32, u32) asm("_Z13func_00140e30jjjj");
u32 func_00140ef8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140ef8jjjj");
u32 func_00140ef8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00140e30(a0, ((u32)(*(u32*)((u32)(a0) + 60u))), a2, a3);
}
}  // namespace n00140ef8

// ---- 00140f10 from src/anon/tiny.cpp
namespace n00140f10 {
void func_00140f10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140f10jjjj");
void func_00140f10(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)((u32)a0 + (56)) = (u8)v;
}
}  // namespace n00140f10

// ---- 00140f20 from src/anon/tiny.cpp
namespace n00140f20 {
void func_00140f20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00140f20jjjj");
void func_00140f20(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)((u32)a0 + (57)) = (u8)v;
}
}  // namespace n00140f20

// ---- 00140f30 from src/anon/tiny_auto80_queue.cpp
namespace n00140f30 {
u32 func_0013f5f0(...) asm("func_0013f5f0");
u32 func_0013f648(...) asm("func_0013f648");
void func_00140f30(u32 a0) asm("_Z13func_00140f30j");
void func_00140f30(u32 a0) {
    if (*(u8*)((u32)a0 + (s32)(56)) == (u8)0u) {
        return;
    }
    u32 s0 = a0;
    *(u8*)((u32)a0 + (s32)(56)) = (u8)0u;
    func_0013f5f0(a0);                         
    func_0013f648(s0);
}
}  // namespace n00140f30

// ---- 00140f78 from src/anon/batch_w52.cpp
namespace n00140f78 {
u32 func_00140dc0(void) asm("func_00140dc0");
extern u8 D_00348710[] asm("D_00348710");
void func_0013fd78(u8*) asm("func_0013fd78");
void func_0013f558(u8*) asm("func_0013f558");
void func_00140b68(u8*, u32) asm("func_00140b68");
void func_00140f78(u8* a, u8* b) asm("func_00140f78");
void func_00140f78(u8* a, u8* b) {
    u32 v = func_00140dc0();
    u8* g = D_00348710;
    *(u32*)(g + 64) = 0;
    func_0013fd78(g);
    func_0013f558(g);
    func_00140b68(g, 1);
    if (a != g + 16) QCOPY(a, g + 16);
    if (b != g) QCOPY(b, g);
    *(u32*)(g + 64) = v;
}
}  // namespace n00140f78

// ---- 00141010 from src/anon/batch_w49.cpp
namespace n00141010 {
s32 func_00141080(f32) asm("func_00141080");
void func_001ad990(u32, f32, f32, f32) asm("func_001ad990");
struct S348710 { u8 pad[64]; u32 f64; u32 f68; };
extern S348710 D_00348710 asm("D_00348710");
void func_00141010(f32 x) asm("func_00141010");
void func_00141010(f32 x) {
    if (func_00141080(x)) {
        S348710* s = &D_00348710;
        if (s->f68) {
            func_001ad990(s->f68 + 2100, 0.0f, 1.0f, x);
            s->f64 = 0;
        }
    }
}
}  // namespace n00141010

// ---- 00141070 from src/anon/tiny.cpp
namespace n00141070 {
extern u32 D_00348730 asm("D_00348730");
f32 func_00141070(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00141070jjjj");
f32 func_00141070(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return *(f32*)&D_00348730;
}
}  // namespace n00141070

// ---- 00141080 from src/anon/tiny_auto80_queue.cpp
namespace n00141080 {
u32 func_00140dc0(...) asm("func_00140dc0");
u32 func_001410b8(...) asm("func_001410b8");
u32 func_00141080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00141080jjjjjjjj");
u32 func_00141080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001410b8)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00140dc0)();
        r2 = (u32)(r2 ^ 0x0001u);
        r15 = ((u32)r2 < 0x00000001u);
    }
    r2 = r15;
    return r2;
}
}  // namespace n00141080

// ---- 001410b8 from src/anon/tiny.cpp
namespace n001410b8 {
extern u32 D_00348754 asm("D_00348754");
u32 func_001410b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001410b8jjjj");
u32 func_001410b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_00348754 != 0);
}
}  // namespace n001410b8

// ---- 001410c8 from src/anon/tiny_auto80_queue.cpp
namespace n001410c8 {
u32 func_00140dc0(...) asm("func_00140dc0");
u32 func_001410b8(...) asm("func_001410b8");
u32 func_001410c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001410c8jjjjjjjj");
u32 func_001410c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001410b8)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00140dc0)();
        r2 = (u32)(r2 ^ 0x0007u);
        r15 = ((u32)r2 < 0x00000001u);
    }
    r2 = r15;
    return r2;
}
}  // namespace n001410c8

