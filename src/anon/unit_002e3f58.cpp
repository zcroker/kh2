// Linked unit 0x002e3f38-0x002e5518.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002e3f38 (was an unwritten gap): the twin of 0x2e3f58
namespace n002e3f38 {
void gap_002e3f38(u32* p) asm("gap_002e3f38");
void gap_002e3f38(u32* p) { p[0] = 0; p[1] = 0; p[2] = 0; ((f32*)p)[3] = 1.0f; }
}  // namespace n002e3f38

// 002e3f58 (was src/anon/batch_wlit.cpp)
namespace n002e3f58 {
/*TARGET 002e3f58*/
// 0x00132270: definition moved into src/anon/unit_00131418.cpp

// 00134d10: moved to src/anon/unit_00134668.cpp

// 001bbfd0: moved to src/yasui/libys/mission.cpp

// Vector (0, 0, 0, 1).
void func_002e3f58(u32* p) asm("func_002e3f58");
// 0x00132270: definition moved into src/anon/unit_00131418.cpp

// 00134d10: moved to src/anon/unit_00134668.cpp

// 001bbfd0: moved to src/yasui/libys/mission.cpp

// Vector (0, 0, 0, 1).
void func_002e3f58(u32* p) { p[0] = 0; p[1] = 0; p[2] = 0; ((f32*)p)[3] = 1.0f; }
}  // namespace n002e3f58

// 002e3f78 (was src/anon/batch_wlit.cpp)
namespace n002e3f78 {
/*TARGET 002e3f78*/
void func_002e3f78(f32* v) asm("func_002e3f78");
void func_002e3f78(f32* v) { v[0] = v[1] = v[2] = 0.0f; v[3] = 1.0f; }
}  // namespace n002e3f78

// 002e3fa0 (was src/anon/auto80_199_queue.cpp)
namespace n002e3fa0 {
/*TARGET 002e3fa0*/
// 0x002e0f20: definition moved into src/anon/unit_002de3c8.cpp

// 002e22f0: moved to src/anon/unit_002e1908.cpp

// 002e2660: moved to src/anon/unit_002e1908.cpp

// 002e26c0: moved to src/anon/unit_002e1908.cpp

// 002e3688: moved to src/anon/unit_002e2f08.cpp

// 002e36f0: moved to src/anon/unit_002e2f08.cpp

// 002e39c0: moved to src/anon/unit_002e2f08.cpp

// 002e3de0: moved to src/anon/unit_002e2f08.cpp

void func_002e3fa0(f32* a0, f32* a1, f32 a2) asm("_Z13func_002e3fa0PfS_f");
// 0x002e0f20: definition moved into src/anon/unit_002de3c8.cpp

// 002e22f0: moved to src/anon/unit_002e1908.cpp

// 002e2660: moved to src/anon/unit_002e1908.cpp

// 002e26c0: moved to src/anon/unit_002e1908.cpp

// 002e3688: moved to src/anon/unit_002e2f08.cpp

// 002e36f0: moved to src/anon/unit_002e2f08.cpp

// 002e39c0: moved to src/anon/unit_002e2f08.cpp

// 002e3de0: moved to src/anon/unit_002e2f08.cpp

void func_002e3fa0(f32* a0, f32* a1, f32 a2) {
    f32 v = cosf((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = sinf(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}
}  // namespace n002e3fa0

// 002e4010 (was src/anon/auto80_199_queue.cpp)
namespace n002e4010 {
/*TARGET 002e4010*/
void func_002e4010(f32* a0, f32* a1, f32 a2) asm("_Z13func_002e4010PfS_f");
void func_002e4010(f32* a0, f32* a1, f32 a2) {
    f32 v = cosf((u32)a0, (u32)a1);
    a0[3] = v;
    f32 s = sinf(a2);

    a0[0] = a1[0] * s;
    a0[1] = a1[1] * s;
    a0[2] = a1[2] * s;
}
}  // namespace n002e4010

// 002e4080 (was an unwritten gap): the twin of 0x2e40a8
namespace n002e4080 {
void gap_002e4080(u32 a0, u32 a1) asm("gap_002e4080");
void gap_002e4080(u32 a0, u32 a1) {
    volatile f32* s = (volatile f32*)a1;
    f32 f0 = s[3];
    f32 f1 = s[0];
    f32 f2 = s[1];
    f32 f3 = s[2];
    *(volatile f32*)(a0 + 12) = f0;
    *(volatile f32*)(a0 + 0) = f1;
    *(volatile f32*)(a0 + 4) = f2;
    *(volatile f32*)(a0 + 8) = f3;
}
}  // namespace n002e4080

// 002e40a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e40a8 {
/*TARGET 002e40a8*/
// 0x002e13d8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3980: moved to src/anon/unit_002e2f08.cpp

// 002e3b08: moved to src/anon/unit_002e2f08.cpp

// 002e3b48: moved to src/anon/unit_002e2f08.cpp

// 002e3be8: moved to src/anon/unit_002e2f08.cpp

void func_002e40a8(u32 a0, u32 a1) asm("_Z13func_002e40a8jj");
// 0x002e13d8: definition moved into src/anon/unit_002de3c8.cpp

// 002e3980: moved to src/anon/unit_002e2f08.cpp

// 002e3b08: moved to src/anon/unit_002e2f08.cpp

// 002e3b48: moved to src/anon/unit_002e2f08.cpp

// 002e3be8: moved to src/anon/unit_002e2f08.cpp

void func_002e40a8(u32 a0, u32 a1) {
    volatile f32* s = (volatile f32*)a1;
    f32 f0 = s[3];
    f32 f1 = s[0];
    f32 f2 = s[1];
    f32 f3 = s[2];
    *(volatile f32*)(a0 + 12) = f0;
    *(volatile f32*)(a0 + 0) = f1;
    *(volatile f32*)(a0 + 4) = f2;
    *(volatile f32*)(a0 + 8) = f3;
}
}  // namespace n002e40a8

// 002e40d0, 002e40e8 (were unwritten gaps): a ctor pair that sets x, y, z, w
namespace n002e40d0 {
void gap_002e40d0(f32* p, f32 x, f32 y, f32 z, f32 w) asm("gap_002e40d0");
void gap_002e40d0(f32* p, f32 x, f32 y, f32 z, f32 w) { p[0] = x; p[1] = y; p[2] = z; p[3] = w; }
void gap_002e40e8(f32* p, f32 x, f32 y, f32 z, f32 w) asm("gap_002e40e8");
void gap_002e40e8(f32* p, f32 x, f32 y, f32 z, f32 w) { p[0] = x; p[1] = y; p[2] = z; p[3] = w; }
}  // namespace n002e40d0

// 002e4100 (was src/anon/perm_002e4100.cpp)
namespace n002e4100 {
typedef signed int s32;
typedef float f32;
void func_002e3f78(f32 *q) asm("func_002e3f78");
/*TARGET 002e4100*/
void func_002e4100(f32 *q, f32 (*m)[4]) asm("func_002e4100");
void func_002e4100(f32 *q, f32 (*m)[4])
{
  f32 t[4];
  s32 i;
  s32 j;
  int new_var;
  s32 k;
  f32 s;
  f32 d;
  new_var = 1;
  i = 0;
  if (m[new_var][new_var] > m[0][0])
  {
    i = new_var;
  }
  if (m[2][2] > m[i][i])
  {
    i = 2;
  }
  j = (i + new_var) % 3;
  k = (j + new_var) % 3;
  s = __builtin_sqrtf(((m[i][i] - m[j][j]) - m[k][k]) + 1.0f) * 0.5f;
  t[i] = s;
  if (s <= 0.001f)
  {
    func_002e3f78(q);
    return;
  }
  d = s * ((long) 4.0f);
  t[j] = (m[i][j] + m[j][i]) / d;
  t[k] = (m[i][k] + m[k][i]) / d;
  t[3] = (m[j][k] - m[k][j]) / d;
  q[0] = t[0];
  q[new_var] = t[new_var];
  q[2] = t[2];
  q[3] = t[3];
}
}  // namespace n002e4100

// 002e42d8 (was src/anon/perm_002e42d8.cpp)
namespace n002e42d8 {
typedef signed int s32;
typedef float f32;
void func_002e3f78(f32 *q) asm("func_002e3f78");
/*TARGET 002e42d8*/
void func_002e42d8(f32 *q, f32 (*m)[4]) asm("func_002e42d8");
void func_002e42d8(f32 *q, f32 (*m)[4])
{
  f32 t[4];
  s32 i;
  s32 j;
  s32 k;
  f32 s;
  int new_var;
  f32 d;
  i = 0;
  new_var = 1;
  if (m[new_var][new_var] > m[0][0])
  {
    i = new_var;
  }
  if (m[2][2] > m[i][i])
  {
    i = 2;
  }
  j = (i + new_var) % 3;
  k = (j + new_var) % 3;
  s = __builtin_sqrtf(((m[i][i] - m[j][j]) - m[k][k]) + 1.0f) * 0.5f;
  t[i] = s;
  if (s <= 0.001f)
  {
    func_002e3f78(q);
    return;
  }
  d = s * 4.0f;
  t[j] = (m[i][j] + m[j][i]) / d;
  t[k] = (m[i][k] + m[k][i]) / d;
  t[3] = (m[j][k] - m[k][j]) / d;
  q[0] = t[0];
  q[new_var] = t[new_var];
  q[2] = t[2];
  q[3] = t[3];
}
}  // namespace n002e42d8

// 002e44b0 (was an unwritten gap): empty
namespace n002e44b0 {
void gap_002e44b0(void* self) asm("gap_002e44b0");
void gap_002e44b0(void* self) {}
}  // namespace n002e44b0

// 002e44b8 (was src/anon/misc_2.cpp)
namespace n002e44b8 {
/*TARGET 002e44b8*/
// 0x002df1a0: definition moved into src/anon/unit_002de3c8.cpp

// 002e34b8: moved to src/anon/unit_002e2f08.cpp

// 002e34c0: moved to src/anon/unit_002e2f08.cpp

void func_002e44b8(void* self) asm("_Z13func_002e44b8Pv");
// 0x002df1a0: definition moved into src/anon/unit_002de3c8.cpp

// 002e34b8: moved to src/anon/unit_002e2f08.cpp

// 002e34c0: moved to src/anon/unit_002e2f08.cpp

void func_002e44b8(void* self) {}
}  // namespace n002e44b8

// 002e44c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e44c0 {
/*TARGET 002e44c0*/
u32 func_002e44c0(u32 a0, f32 a1) asm("_Z13func_002e44c0jf");
u32 func_002e44c0(u32 a0, f32 a1) {  // vec4_scale
    *(f32*)(a0 + 0) *= a1;
    *(f32*)(a0 + 4) *= a1;
    *(f32*)(a0 + 8) *= a1;
    *(f32*)(a0 + 12) *= a1;
    return a0;
}
}  // namespace n002e44c0

// 002e44f8, 002e4520 (were unwritten gaps): copy (returns the target) and inverse
namespace n002e44f8 {
f32* gap_002e44f8(f32* d, f32* s) asm("gap_002e44f8");
f32* gap_002e44f8(f32* d, f32* s) {
    volatile f32* v = (volatile f32*)s;
    f32 w = v[3];
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    volatile f32* o = (volatile f32*)d;
    o[0] = x;
    o[1] = y;
    o[2] = z;
    o[3] = w;
    return d;
}
void gap_002e4520(f32* q) asm("gap_002e4520");
void gap_002e4520(f32* q) {
    f32 w = q[3], x = q[0], y = q[1], z = q[2];
    f32 n = w * w + x * x + y * y + z * z;
    f32 r = 1.0f / n;
    q[3] = w * r;
    q[0] = -x * r;
    q[1] = -y * r;
    q[2] = -z * r;
}
}  // namespace n002e44f8

// 002e4588 (was src/anon/batch_w267.cpp)
namespace n002e4588 {
/*TARGET 002e4588*/
// 0x002e0be0: definition moved into src/anon/unit_002de3c8.cpp
f32* func_002e4588(f32* m, f32* q) asm("func_002e4588");
// 0x002e0be0: definition moved into src/anon/unit_002de3c8.cpp
f32* func_002e4588(f32* m, f32* q) {
  m[0] = 1.0f - (q[1] * q[1] + q[2] * q[2]) * 2.0f;
  m[1] = (q[0] * q[1] + q[3] * q[2]) * 2.0f;
  m[2] = (q[0] * q[2] - q[3] * q[1]) * 2.0f;
  m[3] = 0.0f;
  m[4] = (q[0] * q[1] - q[3] * q[2]) * 2.0f;
  m[5] = 1.0f - (q[0] * q[0] + q[2] * q[2]) * 2.0f;
  m[6] = (q[1] * q[2] + q[3] * q[0]) * 2.0f;
  m[7] = 0.0f;
  m[8] = (q[0] * q[2] + q[3] * q[1]) * 2.0f;
  m[9] = (q[1] * q[2] - q[3] * q[0]) * 2.0f;
  m[10] = 1.0f - (q[0] * q[0] + q[1] * q[1]) * 2.0f;
  m[11] = 0.0f;
  m[12] = 0.0f;
  m[13] = 0.0f;
  m[14] = 0.0f;
  m[15] = 1.0f;
  return m;
}
}  // namespace n002e4588

// 002e46d0 (was src/anon/batch_w84.cpp)
namespace n002e46d0 {
// 0x0028aa40: definition moved into src/anon/unit_00288b00.cpp

// Quaternion product o = a * b.
struct Qt { f32 x, y, z, w; };
void func_002e3f58(Qt*, Qt*, Qt*) asm("func_002e3f58");
/*TARGET 002e46d0*/
Qt* func_002e46d0(Qt* o, Qt* a, Qt* b) asm("func_002e46d0");
Qt* func_002e46d0(Qt* o, Qt* a, Qt* b) {
    func_002e3f58(o, a, b);
    o->w = a->w * b->w - (a->x * b->x + a->y * b->y + a->z * b->z);
    o->x = (a->w * b->x + b->w * a->x) + (a->y * b->z - a->z * b->y);
    o->y = (a->w * b->y + b->w * a->y) + (a->z * b->x - a->x * b->z);
    o->z = (a->w * b->z + b->w * a->z) + (a->x * b->y - a->y * b->x);
    return o;
}
}  // namespace n002e46d0

// 002e47a8 (was src/anon/batch_w3754.cpp)
namespace n002e47a8 {
struct Q1987 { f32 x, y, z, w; } __attribute__((aligned(16)));
void func_002e40a8(Q1987*, Q1987*) asm("func_002e40a8");
f32 func_002e49a8(Q1987*, Q1987*) asm("func_002e49a8");
void func_002e44c0(Q1987*, f32) asm("func_002e44c0");
void func_002e3f58(Q1987*) asm("func_002e3f58");
void f2e44b8_1987(Q1987*) asm("_Z13func_002e44b8Pv");
f32 acos1987(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
f32 sinf(f32) asm("sinf");
f32 fabsf(f32) asm("fabsf");
/*TARGET 002e47a8*/
Q1987* func_002e47a8(Q1987* out, Q1987* a, Q1987* b, f32 tp) asm("func_002e47a8");
Q1987* func_002e47a8(Q1987* out, Q1987* a, Q1987* b, f32 tp)
{
    Q1987 q;
    f32 t; register f32 u asm("$f24"); f32 s0; f32 s; f32 s1;
    f32 c, om;
    t = tp;
    func_002e40a8(&q, b);
    if (func_002e49a8(a, &q) < 0.0f) {
        func_002e44c0(&q, -1.0f);
    }
    func_002e3f58(out);
    c = a->x * q.x + a->y * q.y + a->z * q.z + a->w * q.w;
    if (1.0f < c) c = 1.0f;
    om = acos1987(c);
    u = 1.0f - t;
    s = sinf(om);
    s0 = sinf(om * u);
    s1 = sinf(om * t);
    if (fabsf(s) < 1e-05f) {
        out->x = a->x * u + q.x * t;
        out->y = a->y * u + q.y * t;
        out->z = a->z * u + q.z * t;
        out->w = a->w * u + q.w * t;
        f2e44b8_1987(&q);
        return out;
    } else {
        s = 1.0f / s;
        out->x = (a->x * s0 + q.x * s1) * s;
        out->y = (a->y * s0 + q.y * s1) * s;
        out->z = (a->z * s0 + q.z * s1) * s;
        out->w = (a->w * s0 + q.w * s1) * s;
        f2e44b8_1987(&q);
        return out;
    }
}
}  // namespace n002e47a8

// 002e49a8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e49a8 {
/*TARGET 002e49a8*/
f32 func_002e49a8(u32 a0, u32 a1) asm("_Z13func_002e49a8jj");
f32 func_002e49a8(u32 a0, u32 a1) {  // vec4_dot_2
    f32* p = (f32*)a0;
    f32* q = (f32*)a1;
    return p[0] * q[0] + p[1] * q[1] + p[2] * q[2] + p[3] * q[3];
}
}  // namespace n002e49a8

// 002e49e0 (was an unwritten gap): the twin of 0x2e4a08
namespace n002e49e0 {
struct V2e49e0 { f32 x, y; };
void gap_002e49e0(V2e49e0* v) asm("gap_002e49e0");
void gap_002e49e0(V2e49e0* v) {
    v->x = 15.0f;
    v->y = 6.0f;
}
}  // namespace n002e49e0

// 002e4a08 (was src/anon/batch_wcx2.cpp)
namespace n002e4a08 {
// 0x00261668: definition moved into src/anon/unit_0025f6b8.cpp

// --------------------
struct V2e4a08 { f32 x, y; };
/*TARGET 002e4a08*/
void func_002e4a08(V2e4a08* v) asm("func_002e4a08");
void func_002e4a08(V2e4a08* v) {
    v->x = 15.0f;
    v->y = 6.0f;
}
}  // namespace n002e4a08

// 002e4a30 (was an unwritten gap): the twin of 0x2e4a90 (C2e4a90 is defined there)
namespace n002e4a90 {
struct C2e4a90;
void gap_002e4a30(C2e4a90* c) asm("gap_002e4a30");
}  // namespace n002e4a90

// 002e4a90 (was src/anon/batch_w49.cpp)
namespace n002e4a90 {
// 0x0018f940: definition moved into src/anon/unit_0018f140.cpp

// Destructor body of an object holding two member arrays with empty element destructors.
struct A2e4a90 { u8 d[16]; ~A2e4a90() {} } __attribute__((aligned(16)));
struct B2e4a90 { u8 d[96]; ~B2e4a90() {} } __attribute__((aligned(16)));
struct C2e4a90 {
    u8 pad[16];
    B2e4a90 b[41];
    u8 pad2[528];
    A2e4a90 a[861];
    ~C2e4a90() {}
};
void gap_002e4a30(C2e4a90* c) {
    c->~C2e4a90();
}
/*TARGET 002e4a90*/
void func_002e4a90(C2e4a90* c) asm("func_002e4a90");
void func_002e4a90(C2e4a90* c) {  // in_even_range
    c->~C2e4a90();
}
}  // namespace n002e4a90

// 002e4af0 (was src/anon/misc_2.cpp)
namespace n002e4af0 {
/*TARGET 002e4af0*/
f32 func_002e4af0(void* self) asm("_Z13func_002e4af0Pv");
f32 func_002e4af0(void* self) { return (f32)(*(f32*)((char*)self + 0)); }
}  // namespace n002e4af0

// 002e4af8 (was src/anon/batch_w2044_nsa.cpp)
namespace n002e4af8 {
// 002e4af8: lq/sq copy, VU0 vector subtract and length as inline asm.
struct W2044QV { f32 x, y, z, w;
  W2044QV() {}
  W2044QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  W2044QV& operator=(const W2044QV& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline W2044QV operator-(const W2044QV& a, const W2044QV& b) { W2044QV r; asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.xyzw $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" :: "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline f32 vlen(const W2044QV& v) { f32 l; asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tvsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0" : "=f"(l) : "r"(&v) : "$8", "memory"); return l; }
struct W2044Node { W2044QV pos, v1, v2, v3, v4; u8 flag; u8 pad[15]; };
struct W2044Seg { f32 a; s32 b; f32 len; };
struct W2044Rope { f32 len; u8 pad[12]; W2044Node n[41]; W2044Seg s[40]; f32 tbl[11]; };
f32 func_002f8ae8(f32) asm("func_002f8ae8");
/*TARGET 002e4af8*/
void func_002e4af8(W2044Rope* r) asm("func_002e4af8");
void func_002e4af8(W2044Rope* r) {
  f32 h = r->len * 0.5f;
  s32 i;
  for (i = 0; i < 41; i++) {
    W2044Node* n = &r->n[i];
    n->pos = W2044QV(r->len * i / 40.0f - h, 0.0f, 0.0f, 0.0f);
    n->v3 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v4 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v2 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v1 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->flag = 0;
  }
  r->n[0].flag = 1;
  r->n[40].flag = 1;
  s32 j = 0;
  for (; j < 40; ) {
    s32 k = j + 1;
    W2044Seg* s = &r->s[j];
    s->a = 1000.0f;
    s->b = 0;
    s->len = vlen(r->n[j].pos - r->n[k].pos);
    j = k;
  }
  s32 m;
  s32 n = 10;
  for (m = 0; m <= n; m++) {
    f32 x = m * 1.3f / n;
    r->tbl[m] = func_002f8ae8(-x * x);
  }
}
}  // namespace n002e4af8

// 002e4d30 (was src/anon/batch_w2415_nsa.cpp)
namespace n002e4d30 {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V2e4d30 {
    f32 x, y, z, w;
    V2e4d30() {}
    V2e4d30(const V2e4d30& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2e4d30 operator-(const V2e4d30& b) const
    {
        V2e4d30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e4d30 operator*(f32 k) const
    {
        V2e4d30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V2e4d30& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V2e4d30& operator+=(const V2e4d30& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 dot(const V2e4d30& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Node2e4d30 { V2e4d30 pos; V2e4d30 vel; u8 pad[32]; V2e4d30 force; u8 fixed; u8 pad2[15]; };
struct Spring2e4d30 { f32 k, damp, rest; };
struct Rope2e4d30 { u8 hdr[16]; Node2e4d30 n[41]; Spring2e4d30 s[40]; };
/*TARGET 002e4d30*/
void func_002e4d30(Rope2e4d30* r) asm("func_002e4d30");
void func_002e4d30(Rope2e4d30* r)
{
    for (s32 i = 0; i < 41; i++) {
        Node2e4d30* n = &r->n[i];
        if (!n->fixed) {
            V2e4d30 v(n->vel);
            v *= -1.0f;
            f32 s = n->vel.length();
            v.normalize();
            n->force += v * (s * s) * 0.1f;
        }
    }
    s32 j;
    for (s32 i = 0; i < 40; i = j) {
        Spring2e4d30* sp = &r->s[i];
        Node2e4d30* p = &r->n[i];
        j = i + 1;
        Node2e4d30* q = &r->n[j];
        V2e4d30 d = p->pos - q->pos;
        V2e4d30 dv = p->vel - q->vel;
        f32 rest = sp->rest;
        f32 len = d.length();
        f32 inv = 1.0f / len;
        f32 f = -(dv.dot(d) * sp->damp * inv + (len - rest) * sp->k);
        V2e4d30 F = d * inv * f;
        V2e4d30 G = F * -1.0f;
        if (!p->fixed) p->force += F;
        if (!q->fixed) q->force += G;
    }
}
}  // namespace n002e4d30

// 002e5010 (was src/anon/perm_002e5010.cpp)
namespace n002e5010 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
struct E2e5010
{
  u8 pad[52];
  f32 v;
  u8 pad2[40];
};
struct O2e5010
{
  f32 w;
  u8 pad[12];
  E2e5010 e[41];
};
/*TARGET 002e5010*/
void func_002e5010(O2e5010 *o, f32 a, f32 b) asm("func_002e5010");
void func_002e5010(O2e5010 *o, f32 a, f32 b)
{
  f32 w;
  f32 t;
  f32 x;
  s32 i;
  f32 f;
  s32 j;
  E2e5010 *e;
  E2e5010 *e0;
  E2e5010 *e1;
  w = o->w;
  t = (a + (w * 0.5f)) / w;
  if (t < 0.0f)
  {
    return;
  }
  if (1.0f < t)
  {
    return;
  }
  x = t * 40.0f;
  i = (s32) x;
  f = x - ((f32) i);
  if (f < 0.0001f)
  {
    e = &o->e[i];
    e->v += b;
    return;
  }
  j = i + 1;
  e0 = &o->e[i];
  e1 = &o->e[j];
  e0->v += b * (1.0f - (x - ((f32) i)));
  e1->v += b * (x - ((f32) i));
}
}  // namespace n002e5010

// 002e50f8 (was src/anon/batch_wcx2.cpp)
namespace n002e50f8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
f32 fabsf(f32 x) asm("fabsf");
// 0x002ac748: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct O2e50f8 { u8 pad[4]; f32 w; u8 pad8[0x1148]; f32 tbl[22]; };
f32 func_002e51b0(O2e50f8*, f32) asm("func_002e51b0");
/*TARGET 002e50f8*/
f32 Ti__Cord__init(O2e50f8* o, f32 a, f32 b) asm("Ti__Cord__init");
f32 Ti__Cord__init(O2e50f8* o, f32 a, f32 b)
{
    f32 h = 0.5f;
    f32 v = func_002e51b0(o, a);
    if (fabsf(b) > o->w * h) return v;
    b = fabsf(b * h);
    return v * o->tbl[(s32)(b * 21.0f / o->w + h)];
}
}  // namespace n002e50f8

// 002e51b0 (was src/anon/batch_w84.cpp)
namespace n002e51b0 {
// 0x00200a78: definition moved into src/anon/unit_00200578.cpp

// Linear interpolation over a table of 96-byte keys (40 steps).
struct K96 { f32 x; u8 _4[16]; f32 v; u8 _24[72]; };
static inline K96* KeyAt(K96* k, s32 i) {
    K96* r = k + i;
    return r;
}
/*TARGET 002e51b0*/
f32 func_002e51b0(K96* k, f32 t) asm("func_002e51b0");
f32 func_002e51b0(K96* k, f32 t) {
    f32 r = 0.0f;
    f32 x = k->x;
    t += x * 0.5f;
    t /= x;
    if (t < 0.0f || 1.0f < t) return r;
    f32 s = t * 40.0f;
    s32 i = (s32)s;
    s32 j = i + 1;
    t = s - (f32)i;
    if (t < 9.99999975e-05f) return KeyAt(k, i)->v;
    return KeyAt(k, i)->v * (1.0f - t) + KeyAt(k, j)->v * t;
}
}  // namespace n002e51b0

// 002e5280 (was an unwritten gap): 0x2e51b0 on the field at +84
namespace n002e5280 {
struct K96 { f32 x; u8 _4[80]; f32 v; u8 _88[8]; };
static inline K96* KeyAt(K96* k, s32 i) {
    K96* r = k + i;
    return r;
}
f32 gap_002e5280(K96* k, f32 t) asm("gap_002e5280");
f32 gap_002e5280(K96* k, f32 t) {
    f32 r = 0.0f;
    f32 x = k->x;
    t += x * 0.5f;
    t /= x;
    if (t < 0.0f || 1.0f < t) return r;
    f32 s = t * 40.0f;
    s32 i = (s32)s;
    s32 j = i + 1;
    t = s - (f32)i;
    if (t < 9.99999975e-05f) return KeyAt(k, i)->v;
    return KeyAt(k, i)->v * (1.0f - t) + KeyAt(k, j)->v * t;
}
}  // namespace n002e5280

// 002e5350 (was src/anon/batch_w1962.cpp)
namespace n002e5350 {
struct W1962QV {
    f32 x, y, z, w;
    W1962QV() {}
    W1962QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1962QV& operator=(const W1962QV& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    W1962QV operator*(f32 s) const { W1962QV r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory"); return r; }
    W1962QV& operator+=(const W1962QV& o) { asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1962Pt { W1962QV v0, pos, vel, acc, frc, imp; };
struct W1962Sys { W1962Pt p[41]; };
// ---- func_002e5350
void func_002e4d30(W1962Sys*) asm("func_002e4d30");
/*TARGET 002e5350*/
void func_002e5350(W1962Sys* s, f32 t, s32 n) asm("func_002e5350");
void func_002e5350(W1962Sys* s, f32 t, s32 n) {
    f32 h = t / (f32)n;
    f32 k = 1.0f / (f32)n;
    s32 i, j, k2, m;
    for (i = 0; i < n; i++) {
        for (k2 = 0; k2 < 41; k2++) s->p[k2].imp = s->p[k2].frc * k;
        func_002e4d30(s);
        for (j = 0; j < 41; j++) {
            W1962Pt* e = &s->p[j]; W1962QV& f = e->imp; W1962QV& p = e->pos; W1962QV& a = e->acc; a = f * 100.0f; e->vel += a * h; p += e->vel * h;
        }
    }
    for (m = 0; m < 41; m++) s->p[m].frc = W1962QV(0.0f, 0.0f, 0.0f, 0.0f);
}
}  // namespace n002e5350

