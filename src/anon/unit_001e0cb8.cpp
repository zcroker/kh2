// Linked unit 0x001e0cb8-0x001e8ac8 (particle manager: partMng.c, pppPart.c; one namespace per old matched source).
// Built as C++ with -G0 -g -fno-strict-aliasing. The .rodata (0x36e8b8-0x36efb4) holds the files' assert strings in place.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001e0c98 manual (gap: empty out-of-line ctor/dtor pair, C2 C1 D2 D1)
namespace n001e0c98 {
struct OBJ { OBJ(); ~OBJ(); };
OBJ::OBJ() {}
OBJ::~OBJ() {}
}  // namespace n001e0c98

#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../global/misc.hpp"

// 001e0cb8 (was src/anon/tiny_auto80.cpp)
namespace n001e0cb8 {
/*TARGET 001e0cb8*/
void func_001e0cb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e0cb8jjjj");
void func_001e0cb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32* p = (u32*)a0;
    p[8] = a1;
    p[9] = 0;
    p[10] = 0;
}
}  // namespace n001e0cb8

// 001e0cc8 (was src/anon/tiny_leaf.cpp)
namespace n001e0cc8 {
/*TARGET 001e0cc8*/
// 0x001dca50: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001e0cc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e0cc8jjjj");
// 0x001dca50: definition moved into src/anon/unit_001dbfd8.cpp

u32 func_001e0cc8(u32 a0, u32 a1, u32 a2, u32 a3) {  // entry64_by_field32
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r14 = (u32)(0x0035u << 16);
    r15 = *(u32*)((u32)r4 + (s32)(32));
    r13 = *(u32*)((u32)r14 + (s32)(11216));
    r15 = (u32)(r15 << 6);
    r2 = *(u32*)((u32)r13 + (s32)(3524));
    r2 = (u32)(r2 + r15);
    r2 = (u32)((s32)r2 + (48));
    return r2;
}
}  // namespace n001e0cc8

// 001e0ce8 (was src/anon/tiny_leaf.cpp)
namespace n001e0ce8 {
/*TARGET 001e0ce8*/
u32 func_001e0ce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e0ce8jjjj");
u32 func_001e0ce8(u32 a0, u32 a1, u32 a2, u32 a3) {  // entry64_by_field32_b
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r14 = (u32)(0x0035u << 16);
    r15 = *(u32*)((u32)r4 + (s32)(32));
    r13 = *(u32*)((u32)r14 + (s32)(11216));
    r15 = (u32)(r15 << 6);
    r2 = *(u32*)((u32)r13 + (s32)(3524));
    r2 = (u32)(r2 + r15);
    r2 = (u32)((s32)r2 + (32));
    return r2;
}
}  // namespace n001e0ce8

// 001e0d08 (was src/anon/perm_001e0d08_nsa.cpp)
namespace n001e0d08 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
struct M
{
  f32 m[16];
};
struct G
{
  u8 pad[0xdc4];
  M *arr;
};
extern G *D_00352bd0 asm("D_00352bd0");
struct Obj
{
  u8 pad[0x20];
  s32 idx;
};
inline static M *get(Obj *o)
{
  return &D_00352bd0->arr[o->idx];
}
/*TARGET 001e0d08*/
void func_001e0d08(Obj *o, f32 *v) asm("func_001e0d08");
void func_001e0d08(Obj *o, f32 *v)
{
  f32 z = v[2];
  int new_var4;
  M *new_var3;
  M *new_var5;
  f32 new_var;
  f32 x = v[0];
  Obj *new_var2;
  f32 y = v[1];
  new_var4 = 0;
  new_var5 = get(o);
  do
  {
    new_var = z;
    new_var5->m[12] = x;
    z = y;
    (new_var3 = get(o))->m[13] = z;
    new_var2 = o;
    get(new_var2)->m[14] = new_var;
  }
  while (new_var4);
}
}  // namespace n001e0d08

// 001e0d68 (was src/anon/perm_001e0d68_nsa.cpp)
namespace n001e0d68 {
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
struct M
{
  f32 m[16];
};
struct G
{
  u8 pad[0xdc4];
  M *arr;
};
extern G *D_00352bd0 asm("D_00352bd0");
struct Obj
{
  u8 pad[0x20];
  s32 idx;
};
inline static M *get(Obj *o)
{
  return &D_00352bd0->arr[o->idx];
}
/*TARGET 001e0d68*/
void func_001e0d68(Obj *o, f32 *v) asm("func_001e0d68");
void func_001e0d68(Obj *o, f32 *v)
{
  f32 y;
  Obj *new_var2;
  f32 new_var5;
  f32 z;
  M *new_var4;
  f32 x;
  f32 new_var6;
  Obj *new_var;
  short new_var3;
  new_var = o;
  new_var3 = 0;
  new_var6 = v[0];
  y = v[1];
  new_var5 = new_var6;
  new_var4 = get(o);
  do
  {
  }
  while (new_var3);
  z = v[2];
  new_var4->m[8] = new_var5;
  new_var2 = new_var;
  get(new_var2)->m[9 ^ 0] = y;
  get(o)->m[10] = z;
}
}  // namespace n001e0d68

// 001e0dc8 (was src/anon/auto200_999.cpp)
namespace n001e0dc8 {
extern u32 D_00352bd0 asm("D_00352bd0");
/*TARGET 001e0dc8*/
// 0x001c6c60: definition moved into src/anon/unit_001c6c60.cpp

void func_001e0dc8(u32 a0) asm("_Z13func_001e0dc8j");
// 0x001c6c60: definition moved into src/anon/unit_001c6c60.cpp

void func_001e0dc8(u32 a0) {
    u32 idx = *(u32 *)(a0 + 32);
    u32 base = D_00352bd0;
    idx <<= 6;
    u32 p = *(u32 *)(base + 3524);
    p += idx;
    *(u32 *)(p + 60) = 0;
}
}  // namespace n001e0dc8

// 001e0de8 (was src/anon/batch_w59.cpp)
namespace n001e0de8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// --- 001e0de8
Vec4* func_001e0cc8(Vec4*) asm("func_001e0cc8");
// entry64_by_field32
Vec4* func_001e0ce8(Vec4*) asm("func_001e0ce8");
/*TARGET 001e0de8*/
// entry64_by_field32_b
void func_001e0de8(Vec4* p) asm("func_001e0de8");
// entry64_by_field32_b
void func_001e0de8(Vec4* p) {
    p[0] = *func_001e0cc8(p);  // entry64_by_field32
    *(u32*)&p[0].w = 0;
    p[1] = *func_001e0ce8(p);  // entry64_by_field32_b
}
}  // namespace n001e0de8

// 001e0e40 (was src/anon/tiny_more.cpp)
namespace n001e0e40 {
/*TARGET 001e0e40*/
// 0x001ca498: definition moved into src/anon/unit_001ca148.cpp

void func_001e0e40(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e0e40jjjj");
// 0x001ca498: definition moved into src/anon/unit_001ca148.cpp

void func_001e0e40(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)1); *(u32*)((u32)a0 + (36)) = v; }
}  // namespace n001e0e40

// 001e0e50 (was src/anon/batch_w2387.cpp)
namespace n001e0e50 {
#define QCOPY_w2387(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord_w2387 {
    u32 v[4];
    QWord_w2387() {}
    QWord_w2387(const QWord_w2387& o) { QCOPY_w2387(this, &o); }
    QWord_w2387& operator=(const QWord_w2387& o) {
        if (this != &o) QCOPY_w2387(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord_w2387 VSub_w2387(const QWord_w2387& a, const QWord_w2387& b)
{
    QWord_w2387 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
/* Normalize xyz in place (VU0), returns the length. */
static inline f32 VNormalize_w2387(QWord_w2387* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Act_w2387 { u8 pad[340]; s32 state; };
struct Self_w2387 { u8 pad[36]; s32 f24; s32 f28; };
QWord_w2387 actor_pos_w2387(Act_w2387*) asm("_Z16ctarget_0016bda8jjjj");
extern Act_w2387* D_0034e948 asm("D_0034e948");
extern u32 D_003638d0 asm("D_003638d0");
Act_w2387* friend_get_w2387(s32) asm("_ZN2YS6FRIEND3GetEi");
QWord_w2387* func_001e0cc8(Self_w2387*) asm("func_001e0cc8");
void func_001e0d68(Self_w2387*, QWord_w2387*) asm("func_001e0d68");
/*TARGET 001e0e50*/
/* Pick D_0034e948 or party actor 0 (by state 270/271, else a random bit), then store the
   normalized direction from this object's point to that actor's position. */
void func_001e0e50(Self_w2387* o) asm("func_001e0e50");
/* Pick D_0034e948 or party actor 0 (by state 270/271, else a random bit), then store the
   normalized direction from this object's point to that actor's position. */
void func_001e0e50(Self_w2387* o) {
    Act_w2387* p = D_0034e948;
    Act_w2387* q = friend_get_w2387(0);
    QWord_w2387 v;
    if (p->state == 270) v = actor_pos_w2387(q);
    else if (p->state == 271) v = actor_pos_w2387(q);
    else if (q->state == 270) v = actor_pos_w2387(p);
    else if (q->state == 271) v = actor_pos_w2387(p);
    else {
        D_003638d0 *= 0x10dcd;
        if ((u32)(((u64)D_003638d0 * 2) >> 32)) v = actor_pos_w2387(p);
        else v = actor_pos_w2387(q);
    }
    QWord_w2387* d = func_001e0cc8(o);
    v = VSub_w2387(v, *d);
    VNormalize_w2387(&v);
    func_001e0d68(o, &v);
    o->f28 = 0;
    o->f24 = 3;
}
}  // namespace n001e0e50

// 001e0f90 (was src/anon/batch_w22.cpp)
namespace n001e0f90 {
// 0x001d9688: definition moved into src/anon/unit_001d7458.cpp

// --- 001e0f90
extern u32 D_00352bd0 asm("D_00352bd0");
u32 func_001e0cc8(void*) asm("func_001e0cc8");
// entry64_by_field32
void func_001e26b8(u32, u32) asm("func_001e26b8");
/*TARGET 001e0f90*/
void func_001e0f90(u8* p) asm("func_001e0f90");
void func_001e0f90(u8* p) {
    func_001e26b8(D_00352bd0, func_001e0cc8(p));
    *(u32*)(p + 36) = 5;
    *(u32*)(p + 40) = 0;
}
}  // namespace n001e0f90

// 001e0fd0 (was src/anon/tiny_more.cpp)
namespace n001e0fd0 {
/*TARGET 001e0fd0*/
u32 func_001e0fd0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e0fd0jjjj");
u32 func_001e0fd0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (36))) + (-1)); return (v < (u32)3); }
}  // namespace n001e0fd0

// 001e0fe0 (was src/anon/batch_w1665.cpp)
namespace n001e0fe0 {
/*TARGET 001e0fe0*/
void func_001e0fe0(void) asm("func_001e0fe0");
void func_001e0fe0(void) {}
}  // namespace n001e0fe0

// 001e0fe8 (was src/anon/batch_w1766.cpp)
namespace n001e0fe8 {
extern s32 D_00352bd0 asm("D_00352bd0");
void* func_001e2760(s32, s32) asm("func_001e2760");
/*TARGET 001e0fe8*/
void func_001e0fe8(u8* p) asm("func_001e0fe8");
void func_001e0fe8(u8* p) {
    u8* r = (u8*)func_001e2760(D_00352bd0, *(s32*)(p + 0x20));
    if ((s8)r[0] < 0) { *(s32*)(p + 0x24) = 2; return; }
    r[0] += 10;
    r[0] = (s8)r[0] < 0 ? 0x80 : r[0];
    r[1] = 0;
    r[2] = 0;
    r[3] = 10;
}
}  // namespace n001e0fe8

// 001e1068 (was src/anon/batch_w1665.cpp)
namespace n001e1068 {
/*TARGET 001e1068*/
void func_001e1068(void) asm("func_001e1068");
void func_001e1068(void) {}
}  // namespace n001e1068

// 001e1070 (was src/anon/batch_w91.cpp)
namespace n001e1070 {
// 00184f90: moved to src/anon/unit_00183088.cpp

// --- 001a1840
// Mirrors this object's colour/params into its two linked records.
union UF91 { f32 f; u32 u; };
// 0x001d7538: definition moved into src/anon/unit_001d7458.cpp

// --- 001e1070
u8* func_001050d8(u32) asm("func_001050d8");
void func_0018d238(u8*, u32, u32, u32, u32, s32, s32) asm("func_0018d238");
UF91* func_0018da18(u8*, u8*, u32, u32) asm("func_0018da18");
void func_0018ca10(UF91*) asm("func_0018ca10");
// alloc_from_pool_magic
void func_0018f028(u8*) asm("func_0018f028");
extern u8* D_00352bd0 asm("D_00352bd0");
// Unused 16-byte local with trivial ctor/dtor: reserves the frame slot and blocks the tail call.
struct NT16 { u32 x[4]; NT16() {} ~NT16() {} };
/*TARGET 001e1070*/
void func_001e1070(u32, u8* a) asm("func_001e1070");
void func_001e1070(u32, u8* a) {
    NT16 nt;
    u8* o = func_001050d8(208);
    func_0018d238(o, *(u32*)(D_00352bd0 + 3536), 0, 1143, 0, -1, -1);
    UF91* m = func_0018da18(o, a, *(u32*)(o + 40), 0);
    if (m) {
        m[3].f = m[2].f = m[0].f = 0.0f;
        m[1].f = 1.0f;
        (*(void (**)(u8*, UF91*))(*(u32*)a + 100))(a, m);
        func_0018ca10(m);  // alloc_from_pool_magic
    }
    u8* x = *(u8**)(D_00352bd0 + 3536);
    (*(void (**)(u8*, u8*, u8*, u32))(*(u8**)x + 116))(x, a, o, m[8].u);
    func_0018f028(o);
}
}  // namespace n001e1070

// 001e1160 (was src/anon/batch_w1975_nsa.cpp)
namespace n001e1160 {
#define W1975_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1975_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1975V {
    f32 x, y, z, w;
    W1975V() {}
    W1975V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1975V(const W1975V& o) { W1975_QCOPY(this, &o); }
    W1975V& operator=(const W1975V& o) { if (this != &o) W1975_QCOPY(this, &o); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(this), "f"(s) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1975M {
    W1975V r[4];
    W1975M() {}
    W1975M& operator=(const W1975M& o) { if (this != &o) W1975_QCOPY4(this, &o); return *this; }
    W1975V operator*(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t.set noreorder\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1975V apply3(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void W1975_identity(W1975M*) asm("_Z13func_0011b6a8Pv");
void W1975_rotateY(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
// func_001e1160 types
struct W1975Obj { u8 pad[36]; s32 f24; s32 f28; };
extern u32 D_003638d0 asm("D_003638d0");
W1975V* func_001e0ce8(W1975Obj*) asm("func_001e0ce8");
void func_001e0d68(W1975Obj*, W1975V*) asm("func_001e0d68");
// 0x001bd6a8: definition moved into src/anon/unit_001bc568.cpp

static inline f32 W1975_frand() {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f;
}
static inline f32 W1975_frange(f32 lo, f32 hi) { return lo + W1975_frand() * (hi - lo); }
/*TARGET 001e1160*/
void func_001e1160(W1975Obj* self) asm("func_001e1160");
void func_001e1160(W1975Obj* self) {
    W1975V v;
    W1975M m;
    v = *func_001e0ce8(self);
    v.scale(-1.0f);
    v.y -= W1975_frange(0.5f, 1.0f);
    v.w = 0.0f;
    W1975_identity(&m);
    W1975_rotateY(&m, W1975_frange(-0.17453292f, 0.17453292f));
    v = m * v;
    v.normalize();
    func_001e0d68(self, &v);
    self->f28 = 0;
    self->f24 = 4;
}
}  // namespace n001e1160

// 001e1350 (was src/anon/batch_w110.cpp)
namespace n001e1350 {
#define QCPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QP {
    f32 x, y, z, w;
    QP() {}
    QP(const QP& o) { QCPY(this, &o); }
    QP& operator=(const QP& o) {
        if (this != &o) QCPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Sph {
    s32 type;
    f32 r0, r1;
    s32 f12;
    QP c;
    Sph(const QP& p, f32 r) : type(3), r0(r), r1(r), f12(0), c(p) {}
};
struct HitShape { u8 pad[32]; };
struct ActSub { u8 pad[20]; s32 state; };
struct Actor { u8 pad[320]; ActSub sub; u8 pad344[1072]; u32 flags; };
struct HitCtx { u8 pad[36]; s32 mode; };
extern u32 D_00352bd0 asm("D_00352bd0");
s32 func_0019ba60(Actor*) asm("func_0019ba60");
const QP& func_001e0cc8(HitCtx*) asm("func_001e0cc8");
// entry64_by_field32
u32 func_0016bc20(Actor*, s32, s32) asm("func_0016bc20");
void func_0018a818(HitShape*, Actor*, u32) asm("func_0018a818");
s32 func_0018a550(Sph*, HitShape*) asm("func_0018a550");
// state_dispatch_0_1_3
s32 func_00180618(ActSub*) asm("func_00180618");
void func_001e2660(u32, QP*) asm("func_001e2660");
void func_002bc188(u32, QP*) asm("func_002bc188");
void func_001e1070(HitCtx*, Actor*) asm("func_001e1070");
void func_001e23b0(u32, QP*) asm("func_001e23b0");
/*TARGET 001e1350*/
// Hit check around the context position: big sphere vs downed actor (state 254-256), else small sphere.
s32 func_001e1350(HitCtx* c, Actor* o) asm("func_001e1350");
// Hit check around the context position: big sphere vs downed actor (state 254-256), else small sphere.
s32 func_001e1350(HitCtx* c, Actor* o) {
    if (o && func_0019ba60(o)) {
        QP pos;
        pos = func_001e0cc8(c);  // entry64_by_field32
        Sph near(pos, 50.0f);
        Sph far(pos, 200.0f);
        HitShape sh;
        func_0018a818(&sh, o, func_0016bc20(o, 1, -1));
        if (func_0018a550(&far, &sh)) {  // state_dispatch_0_1_3
            ActSub* q = &o->sub;
            if (q->state == 254) goto down;
            if (q->state == 255) goto down;
            if (q->state != 256) goto skip;
        down:
            if (!func_00180618(q)) {
                func_001e2660(D_00352bd0, &pos);
                if (o->flags & 0x80) func_002bc188(0x5b531, &pos);
                else func_002bc188(0x5b532, &pos);
                c->mode = 6;
                return 1;
            }
        }
    skip:
        if (func_0018a550(&near, &sh)) {  // state_dispatch_0_1_3
            func_001e1070(c, o);
            func_001e23b0(D_00352bd0, &pos);
            func_002bc188(0x5b51f, &pos);
            c->mode = 6;
            return 1;
        }
    }
    return 0;
}
}  // namespace n001e1350

// 001e1500 (was src/anon/batch_wcx.cpp)
namespace n001e1500 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
// 0x001d8718: definition moved into src/anon/unit_001d7458.cpp
extern f32 D_00349e10 asm("D_00349e10");
V4* func_001e0cc8(u8*) asm("func_001e0cc8");
// entry64_by_field32
V4* func_001e0ce8(u8*) asm("func_001e0ce8");
// entry64_by_field32_b
void func_001e0d08(u8*, V4*) asm("func_001e0d08");
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
/*TARGET 001e1500*/
void func_001e1500(u8* p) asm("func_001e1500");
void func_001e1500(u8* p)
{
    V4 a, b, u, t;
    VCp(&a, func_001e0cc8(p));  // entry64_by_field32
    VCp(&b, func_001e0ce8(p));  // entry64_by_field32_b
    VScale(&t, &b, 40.0f);
    VScale(&u, &t, D_00349e10);
    VAdd(&a, &a, &u);
    func_001e0d08(p, &a);
}
}  // namespace n001e1500

// 001e15a8 (was src/anon/batch_w61.cpp)
namespace n001e15a8 {
// 0x001dc4e8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e1500(void*) asm("func_001e1500");
s32 func_001e1350(void*, u32) asm("func_001e1350");
u32 func_0017df58(u32) asm("func_0017df58");
extern u32 D_0034e948 asm("D_0034e948");
extern f32 D_00349e10 asm("D_00349e10");
/*TARGET 001e15a8*/
void func_001e15a8(u8* p) asm("func_001e15a8");
void func_001e15a8(u8* p) {
    func_001e1500(p);
    if (func_001e1350(p, D_0034e948)) return;
    if (func_001e1350(p, func_0017df58(0))) return;
    f32 t = *(f32*)(p + 40);
    if (60.0f <= t) {
        *(f32*)(p + 40) = 0.0f;
        *(u32*)(p + 36) = 6;
    } else {
        *(f32*)(p + 40) = t + D_00349e10;
    }
}
}  // namespace n001e15a8

// 001e1638 (was src/anon/batch_w1671.cpp)
namespace n001e1638 {
// 0x002bfa98: definition moved into src/anon/unit_002bebd0.cpp

void func_001e1500(void*) asm("func_001e1500");
extern f32 D_00349e10 asm("D_00349e10");
/*TARGET 001e1638*/
void func_001e1638(u8* a0) asm("func_001e1638");
void func_001e1638(u8* a0) {
    func_001e1500(a0);
    f32 t = *(f32*)(a0 + 0x28);
    if (30.0f <= t) { *(f32*)(a0 + 0x28) = 0.0f; *(s32*)(a0 + 0x24) = 6; }
    else *(f32*)(a0 + 0x28) = t + D_00349e10;
}
}  // namespace n001e1638

// 001e1698 (was src/anon/batch_w1668.cpp)
namespace n001e1698 {
// 0x001bf118: definition moved into src/anon/unit_001bc568.cpp

void func_001e0dc8(void*) asm("func_001e0dc8");
/*TARGET 001e1698*/
void func_001e1698(u8* p) asm("func_001e1698");
void func_001e1698(u8* p) { func_001e0dc8(p); *(u32*)(p + 0x24) = 0; }
}  // namespace n001e1698

// 001e16c0 (was src/anon/auto80_199_queue.cpp)
namespace n001e16c0 {
/*TARGET 001e16c0*/
// 001e0868: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0ac0: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e16c0(u32 a0) asm("_Z13func_001e16c0j");
// 001e0868: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0ac0: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e16c0(u32 a0) {
    u32 s0 = a0;
    u32* base = (u32*)0x00350000;
    func_001e0d08(a0, a0);
    func_001e0d68(s0, s0 + 16);
    func_001e0dc8(s0);
    if (func_001e2778(base[0x0AF4])) {
        func_001e0e40(s0);
        return;
    }
    *(u32*)(s0 + 36) = 0;
}
}  // namespace n001e16c0

// 001e1728 (was src/anon/batch_wcx2.cpp)
namespace n001e1728 {
// --------------------
void func_001e0fe0(u8*) asm("func_001e0fe0");
void func_001e0fe8(u8*) asm("func_001e0fe8");
void func_001e1068(u8*) asm("func_001e1068");
void func_001e15a8(u8*) asm("func_001e15a8");
void func_001e1638(u8*) asm("func_001e1638");
void func_001e1698(u8*) asm("func_001e1698");
void func_001e16c0(u8*) asm("func_001e16c0");
/*TARGET 001e1728*/
void func_001e1728(u8* p) asm("func_001e1728");
void func_001e1728(u8* p) {
    switch (*(s32*)(p + 36)) {
    case 0: func_001e0fe0(p); break;
    case 1: func_001e0fe8(p); break;
    case 2: func_001e1068(p); break;
    case 3: func_001e15a8(p); break;
    case 4: func_001e1638(p); break;
    case 5: func_001e1698(p); break;
    case 6: func_001e16c0(p); break;
    }
}
}  // namespace n001e1728

// 001e17b8 (was src/anon/batch_w258.cpp)
namespace n001e17b8 {
// 0x00275f68: definition moved into src/anon/unit_002748a0.cpp
void w_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
s32 ATTACK_CHECK_NewComboGroup(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
void func_001e0cb8(u8*, s32) asm("func_001e0cb8");
struct O17 {
    u8 a[160]; u8 b[160]; u8 c[3200]; u8 pad[3524 - 3520];
    u8* x3524; u8* x3528; s32 x3532; u32 x3536; u32 x3540; u32 x3544; u32 x3548; u32 x3552;
    u8 pad2[3568 - 3556]; s32 x3568; u8 pad3[3584 - 3572]; s32 x3584;
};
/*TARGET 001e17b8*/
void func_001e17b8(O17* p) asm("func_001e17b8");
void func_001e17b8(O17* p) {
    s32 i, j;
    w_memset(p->a, 0, 160);
    w_memset(p->b, 0, 160);
    w_memset(p->c, 0, 3200);
    p->x3532 = 0;
    { s32 k = 6; for (j = 0; j < 15; j++) { p->x3532 += k; k += 3; } }
    p->x3524 = AREA_Alloc(p->x3532 << 6);
    w_memset(p->x3524, 0, p->x3532 << 6);
    p->x3528 = AREA_Alloc(p->x3532 * 48);
    for (i = 0; i < p->x3532; i++) func_001e0cb8(p->x3528 + i * 48, i);
    p->x3540 = 0;
    p->x3544 = 0;
    p->x3548 = 0;
    p->x3552 = 0;
    p->x3568 = ATTACK_CHECK_NewComboGroup();
    p->x3584 = -1;
}
}  // namespace n001e17b8

// 001e18d8 (was src/anon/auto80_199_queue.cpp)
namespace n001e18d8 {
/*TARGET 001e18d8*/
void func_001e18d8(u32 a0) asm("_Z13func_001e18d8j");
void func_001e18d8(u32 a0) {
    u32 s0 = a0;
    u32 v0 = *(u32*)(s0 + 3540);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3540) = 0;
    }

    v0 = *(u32*)(s0 + 3544);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3544) = 0;
    }

    v0 = *(u32*)(s0 + 3548);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3548) = 0;
    }

    v0 = *(u32*)(s0 + 3552);
    if (v0 != 0) {
        func_001dc920(v0);
        *(u32*)(s0 + 3552) = 0;
    }

    v0 = *(u32*)(s0 + 3524);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3524) = 0;
    }

    v0 = *(u32*)(s0 + 3528);
    if (v0 != 0) {
        func_00105110(v0);
        *(u32*)(s0 + 3528) = 0;
    }
}
}  // namespace n001e18d8

// 001e1988 (was src/anon/batch_wcx2_nsa.cpp)
namespace n001e1988 {
// 0x001253c0: definition moved into src/anon/unit_00123990.cpp

struct V1e1988 {
    f32 x, y, z, w;
    V1e1988() {}
    V1e1988& operator=(const V1e1988& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1e1988 operator-(const V1e1988& o) const {
        V1e1988 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tsqc2 $vf0, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M1e1988 {
    V1e1988 r[4];
    V1e1988 operator*(const V1e1988& v) const {
        V1e1988 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Self1e1988 {
    u8 pad0[3524];
    M1e1988* mats;
    u8* items;
    s32 nitems;
    void* res;
    void* o3540;
    void* o3544;
    void* o3548;
    void* o3552;
};
void* func_0016abf8(void*, s32, s32, s32) asm("func_0016abf8");
void func_001dca50(void*, M1e1988*, s32) asm("func_001dca50");
void func_001dca30(void*, void*, s32) asm("func_001dca30");
f32 cosf(f32) asm("cosf");
void func_0011b6a8(M1e1988*) asm("func_0011b6a8");
void func_0011b720(M1e1988*, f32) asm("func_0011b720");
void func_001e0de8(void*) asm("func_001e0de8");
/*TARGET 001e1988*/
void func_001e1988(Self1e1988* s) asm("func_001e1988");
void func_001e1988(Self1e1988* s)
{
    s32 n = 6;
    s32 idx = 0;
    f32 y = -700.0f;
    f32 a = 1.483529806137085f;
    f32 da = -0.09890198707580566f;
    f32 dy = -46.666664123535156f;
    s->o3540 = func_0016abf8(s->res, 14, 0, 0);
    func_001dca50(s->o3540, s->mats, s->nitems);
    s->o3544 = func_0016abf8(s->res, 70, 0, 0);
    func_001dca30(s->o3544, s, 10);
    s->o3548 = func_0016abf8(s->res, 69, 0, 0);
    func_001dca30(s->o3548, (u8*)s + 160, 10);
    s->o3552 = func_0016abf8(s->res, 70, 0, 0);
    func_001dca30(s->o3552, (u8*)s + 320, 200);
    for (s32 r = 14; r >= 0; r--) {
        for (s32 i = 0; i < n; i++, idx++) {
            V1e1988 p, d, c;
            M1e1988 m;
            p.zero();
            p.z = cosf(a) * 700.0f;
            p.y = y;
            func_0011b6a8(&m);
            func_0011b720(&m, 6.2831854820251465f / (f32)n * (f32)i);
            p = m * p;
            p.w = 0.0f;
            c.zero();
            c.y = -100.0f;
            d = c - p;
            d.normalize();
            d.w = 0.0f;
            func_0011b6a8(&s->mats[idx]);
            s->mats[idx].r[2] = d;
            s->mats[idx].r[3] = p;
        }
        y -= dy;
        a += da;
        n += 3;
    }
    for (s32 i = 0; i < s->nitems; i++) func_001e0de8(s->items + i * 48);
}
}  // namespace n001e1988

// 001e1ce0 (was src/anon/batch_w15.cpp)
namespace n001e1ce0 {
void func_001e1988(void*) asm("func_001e1988");
/*TARGET 001e1ce0*/
void func_001e1ce0(u8* p) asm("func_001e1ce0");
void func_001e1ce0(u8* p) {
    func_001e1988(p);
    *(u32*)(p + 3520) = 1;
    *(u32*)(p + 3564) = *(u32*)(p + 3532);
    *(u32*)(p + 3560) = 0;
    *(u32*)(p + 3556) = 0;
}
}  // namespace n001e1ce0

// 001e1d20 (was src/anon/batch_w82.cpp)
namespace n001e1d20 {
void func_001e0e40(u8*) asm("func_001e0e40");
/*TARGET 001e1d20*/
// Drains queued entries in 0.25 steps of the accumulated time.
void func_001e1d20(u8* a0) asm("func_001e1d20");
// Drains queued entries in 0.25 steps of the accumulated time.
void func_001e1d20(u8* a0)
{
    if (*(f32*)(a0 + 3560) < 140.0f) {
        *(f32*)(a0 + 3556) = 25.0f;
        return;
    }
    if (0.25f <= *(f32*)(a0 + 3556)) {
        do {
            s32 n = *(s32*)(a0 + 3564);
            if (n <= 0) {
                *(f32*)(a0 + 3560) = 0;
                *(f32*)(a0 + 3556) = 0;
                *(s32*)(a0 + 3520) = 2;
                return;
            }
            {
                s32 m = n - 1;
                *(s32*)(a0 + 3564) = m;
                func_001e0e40(*(u8**)(a0 + 3528) + m * 48);
            }
            *(f32*)(a0 + 3556) -= 0.25f;
        } while (0.25f <= *(f32*)(a0 + 3556));
    }
}
}  // namespace n001e1d20

// 001e1df0 (was src/anon/misc_1.cpp)
namespace n001e1df0 {
/*TARGET 001e1df0*/
// 001e0998: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e1df0(void* self) asm("_Z13func_001e1df0Pv");
// 001e0998: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e1df0(void* self) {}
}  // namespace n001e1df0

// 001e1df8 (was src/anon/batch_w211.cpp)
namespace n001e1df8 {
/*TARGET 001e1df8*/
// 0x0011eea8: definition moved into src/anon/unit_0011c128.cpp

void func_001e1df8(u8* p) asm("func_001e1df8");
// 0x0011eea8: definition moved into src/anon/unit_0011c128.cpp

void func_001e1df8(u8* p) {
    if (20.0f <= *(f32*)(p + 0xde4)) {
        *(u32*)(p + 0xde8) = 0;
        *(u32*)(p + 0xdfc) = 0;
        *(f32*)(p + 0xde4) = 0;
        *(f32*)(p + 0xdf4) = 10.0f;
        *(u32*)(p + 0xdc0) = 4;
        *(f32*)(p + 0xdf8) = 10.0f;
    }
}
}  // namespace n001e1df8

// 001e1e40 (was src/anon/batch_w333.cpp)
namespace n001e1e40 {
struct W333E48 { u8 pad[36]; s32 w24; u8 pad2[8]; };
struct W333O {
    u8 pad[0xdc8];
    union { W333E48* arr; u32 arru; };
    s32 n;          /* dcc */
    u8 pad2[0xde4 - 0xdd0];
    union { f32 de4; u32 de4u; };
    f32 de8;
    u8 pad3[0xdf4 - 0xdec];
    union { f32 df4; u32 df4u; };
    f32 df8;
    f32 dfc;
    s32 e00;
};
extern u32 D_003638d0[] asm("D_003638d0");
extern f32 D_00349e10[] asm("D_00349e10");
s32 func_002bc1e8(s32) asm("func_002bc1e8");
void func_001e0e50(W333E48*) asm("func_001e0e50");
s32 func_001e0fd0(W333E48*) asm("func_001e0fd0");
void func_001e0f90(W333E48*) asm("func_001e0f90");
/* Random pick in [0, m): seed *= 69069; seed / ceil(2^32 / m). */
static inline s32 W333Rand(u32 m) {
    D_003638d0[0] *= 0x10dcd;
    return (u64)D_003638d0[0] / ((0x100000000ull + (m - 1)) / m);
}
/*TARGET 001e1e40*/
void func_001e1e40(W333O* o) asm("func_001e1e40");
void func_001e1e40(W333O* o) {
    if (o->e00 < 0) o->e00 = func_002bc1e8(0x5b518);
    while (o->df4 <= o->de4) {
        for (s32 i = 0; i < o->n; i++) {
            W333E48* e = (W333E48*)(W333Rand(o->n) * sizeof(W333E48) + o->arru);
            if (e->w24 == 2) {
                func_001e0e50(e);
                break;
            }
        }
        o->de4 -= o->df4;
    }
    f32 de8 = o->de8;
    f32 v = o->df4 + D_00349e10[0] * -0.04f;
    o->df4 = v;
    if (de8 < 900.0f) { if (!(0.5f < v)) v = 0.5f; } else { if (!(0.15f < v)) v = 0.15f; }
    o->df4 = v;
    if (1560.0f < o->de8) {
        while (o->df8 <= o->dfc) {
            for (s32 i = 0; i < o->n; i++) {
                s32 idx = W333Rand(o->n);
                if (func_001e0fd0(&o->arr[idx])) {
                    func_001e0f90(&o->arr[idx]);
                    break;
                }
            }
            o->dfc -= o->df8;
        }
        o->dfc += D_00349e10[0];
        o->df8 += D_00349e10[0] * -0.05f;
        o->df8 = o->df8 < 0.01f ? 0.01f : (10.0f < o->df8 ? 10.0f : o->df8);
    }
}
}  // namespace n001e1e40

// 001e2130 (was src/anon/batch_w90.cpp)
namespace n001e2130 {
// 0x001d5f30: definition moved into src/anon/unit_001d4f40.cpp

// 001e2130
void func_001e0e50(void*) asm("func_001e0e50");
/*TARGET 001e2130*/
void func_001e2130(u8* self) asm("func_001e2130");
void func_001e2130(u8* self)
{
    s32 n = *(s32*)(self + 3532);
    s32 all = 1;
    for (s32 i = 0; i < n; i++)
        if (*(s32*)(*(u8**)(self + 3528) + i * 48 + 36) != 2) { all = 0; break; }
    if (!all) return;
    for (s32 i = 0; i < *(s32*)(self + 3532); i++) func_001e0e50(*(u8**)(self + 3528) + i * 48);
    *(s32*)(self + 3572) = 0;
    *(s32*)(self + 3520) = 6;
    *(s32*)(self + 3556) = 0;
}
}  // namespace n001e2130

// 001e21f0 (was src/anon/misc_1.cpp)
namespace n001e21f0 {
/*TARGET 001e21f0*/
void func_001e21f0(void* self) asm("_Z13func_001e21f0Pv");
void func_001e21f0(void* self) {}
}  // namespace n001e21f0

// 001e21f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e21f8 {
u32 func_002bc358(...) asm("func_002bc358");
/*TARGET 001e21f8*/
void func_001e21f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001e21f8jjjjjjjj");
void func_001e21f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(3584));
    r4 = r15;
    if ((s32)r15 >= 0) {
        r5 = (u32)((s32)0u + (120));
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002bc358)(r4, r5, r6, r7, r8, r9, r10, r11);
        r15 = (u32)((s32)0u + (-1));
        *(volatile u32*)((u32)r16 + (s32)(3584)) = r15;
    }
}
}  // namespace n001e21f8

// 001e2238 (was src/anon/batch_w38.cpp)
namespace n001e2238 {
void func_001e1728(void*) asm("func_001e1728");
/*TARGET 001e2238*/
void func_001e2238(u8* p) asm("func_001e2238");
void func_001e2238(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 3532); i++) func_001e1728(*(u8**)(p + 3528) + i * 48);
}
}  // namespace n001e2238

// 001e2298 (was src/anon/batch_wcx2.cpp)
namespace n001e2298 {
// 001cd078: moved to src/anon/unit_001cd078.cpp

// --------------------
extern f32 D_00349e10 asm("D_00349e10");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_001e1ce0(u8*) asm("func_001e1ce0");
void func_001e1d20(u8*) asm("func_001e1d20");
void func_001e1df0(u8*) asm("func_001e1df0");
void func_001e1df8(u8*) asm("func_001e1df8");
void func_001e1e40(u8*) asm("func_001e1e40");
void func_001e2130(u8*) asm("func_001e2130");
void func_001e21f0(u8*) asm("func_001e21f0");
void func_001e21f8(u8*) asm("func_001e21f8");
void func_001e2238(u8*) asm("func_001e2238");
void func_001e2620(u8*) asm("func_001e2620");
void func_001e2640(u8*) asm("func_001e2640");
/*TARGET 001e2298*/
void func_001e2298(u8* p) asm("func_001e2298");
void func_001e2298(u8* p) {
    if (!func_0019ba60(*(u8**)(p + 3536))) *(s32*)(p + 3520) = 7;
    switch (*(u32*)(p + 3520)) {
    case 0: func_001e1ce0(p); break;
    case 1: func_001e1d20(p); break;
    case 2: func_001e1df0(p); break;
    case 3: func_001e1df8(p); break;
    case 4: func_001e1e40(p); break;
    case 5: func_001e2130(p); break;
    case 6: func_001e21f0(p); break;
    case 7: func_001e21f8(p); break;
    }
    func_001e2238(p);
    func_001e2620(p);
    func_001e2640(p);
    *(f32*)(p + 3556) += D_00349e10;
    *(f32*)(p + 3560) += D_00349e10;
}
}  // namespace n001e2298

// 001e23b0 (was src/anon/batch_w231.cpp)
namespace n001e23b0 {
// 0x0019cb48: definition moved into src/anon/unit_0019ba60.cpp

s64 func_00312db8(s64, s64) asm("func_00312db8");
extern u32 D_003638d0 asm("D_003638d0");
struct W231Sl { u8 pad[12]; u8 st; u8 b13; s8 b14; s8 b15; };
/*TARGET 001e23b0*/
void func_001e23b0(W231Sl* p, W231Sl* src) asm("func_001e23b0");
void func_001e23b0(W231Sl* p, W231Sl* src) {
    for (s32 i = 0; i < 10; i++, p++) {
        if (p->st == 0) {
            s8 k = -128;
            if (p != src) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(p), "r"(src) : "$8", "memory");
            p->b13 = 0;
            p->st = k;
            D_003638d0 = D_003638d0 * 0x10dcd;
            s32 r = (s32)func_00312db8(D_003638d0, 0x1010102);
            p->b14 = r;
            p->b15 = 30;
            return;
        }
    }
}
}  // namespace n001e23b0

// 001e2450 (was src/anon/batch_w1964.cpp)
namespace n001e2450 {
struct E2 {
    f32 x, y, z;
    union { f32 w; u8 flag; };
    E2() {}
    E2(const E2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    E2& operator=(const E2& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M2 { f32 m[4][4]; } __attribute__((aligned(16)));
struct C2 { u8 pad[16]; M2 mtx; };
C2* func_00106a60(s32) asm("func_00106a60");
static inline __attribute__((always_inline)) void apply(E2* d, const M2* m, const E2* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(m), "r"(s) : "memory");
}
void wtarget_001e2450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001e2450jjjj");
/*TARGET 001e2450*/
void wtarget_001e2450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001e2450jjjj");
void wtarget_001e2450(u32 a0, u32 a1, u32 a2, u32 a3) {
    E2* e = (E2*)a1;
    s32 n = a2;
    f32 d[n];
    C2* c = func_00106a60(0);
    s32 i, j;
    for (s32 k = 0; k < n; k++) {
        if (e[k].flag) {
            E2 t(e[k]);
            t.w = 1.0f;
            apply(&t, &c->mtx, &t);
            d[k] = t.z;
        } else {
            d[k] = 0;
        }
    }
    for (i = 0; i < n - 1; i++) {
        s32 b = i;
        f32 mx = d[i];
        for (j = i + 1; j < n; j++) {
            if (e[j].flag && mx < d[j]) {
                mx = d[j];
                b = j;
            }
        }
        E2 t;
        t = e[b];
        e[b] = e[i];
        e[i] = t;
        f32 f = d[b];
        d[b] = d[i];
        d[i] = f;
    }
}
}  // namespace n001e2450

// 001e2620 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e2620 {
u32 func_001e2450(u32, u32, u32, u32) asm("_Z13func_001e2450jjjj");
/*TARGET 001e2620*/
// 001e07c8: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_001e0398.cpp

// 001e0b20: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0c58: _GLOBAL__I_ stub, now made by gcc in src/rikeda/saveram_gumibattle.cpp

u32 func_001e2620(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2620jjjj");
// 001e07c8: _GLOBAL__I_ stub, now made by gcc in src/anon/unit_001e0398.cpp

// 001e0b20: moved to src/rikeda/saveram_gumibattle.cpp

// 001e0c58: _GLOBAL__I_ stub, now made by gcc in src/rikeda/saveram_gumibattle.cpp

u32 func_001e2620(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e2450(a0, a0, 0x0000000au, a3);
}
}  // namespace n001e2620

// 001e2640 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e2640 {
u32 func_001e2450(u32, u32, u32, u32) asm("_Z13func_001e2450jjjj");
/*TARGET 001e2640*/
u32 func_001e2640(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2640jjjj");
u32 func_001e2640(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e2450(a0, ((u32)(a0) + 320u), 0x000000c8u, a3);
}
}  // namespace n001e2640

// 001e2660 (was src/anon/batch_w60.cpp)
namespace n001e2660 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
/*TARGET 001e2660*/
// 001e08c8: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e2660(u8* p, u8* v) asm("func_001e2660");
// 001e08c8: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e2660(u8* p, u8* v) {
    s32 i;
    for (i = 0; i < 10; i++, p += 16) {
        if (p[172] == 0) {
            if (p + 160 != v) QCOPY(p + 160, v);
            p[174] = 0;
            p[175] = 30;
            p[172] = 0x80;
            p[173] = 0;
            return;
        }
    }
}
}  // namespace n001e2660

// 001e26b8 (was src/anon/batch_w233.cpp)
namespace n001e26b8 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 0x0015ae00: definition moved into src/anon/unit_0015a810.cpp

extern u32 D_003638d0 asm("D_003638d0");
s64 func_00312db8(u64, u64) asm("func_00312db8");
/*TARGET 001e26b8*/
void func_001e26b8(u8* a, Vq* src) asm("func_001e26b8");
void func_001e26b8(u8* a, Vq* src) {
    for (s32 i = 0; i < 200; i++, a += 16) {
        if (a[332] == 0) {
            *(Vq*)(a + 320) = *src;
            a[333] = 0;
            a[332] = 0x80;
            D_003638d0 = D_003638d0 * 69069;
            s32 r = func_00312db8(D_003638d0, 0x01010102);
            a[334] = r;
            a[335] = 60;
            return;
        }
    }
}
}  // namespace n001e26b8

// 001e2760 (was src/anon/tiny_leaf.cpp)
namespace n001e2760 {
/*TARGET 001e2760*/
u32 func_001e2760(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2760jjjj");
u32 func_001e2760(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(3524));
    r5 = (u32)(r5 << 6);
    r2 = (u32)(r2 + r5);
    r2 = (u32)((s32)r2 + (60));
    return r2;
}
}  // namespace n001e2760

// 001e2778 (was src/anon/tiny_more.cpp)
namespace n001e2778 {
/*TARGET 001e2778*/
u32 func_001e2778(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e2778jjjj");
u32 func_001e2778(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (3520))) + (-4)); return (v < (u32)2); }
}  // namespace n001e2778

// 001e2788 (was src/anon/batch_w12.cpp)
namespace n001e2788 {
void func_001e17b8(void*) asm("func_001e17b8");
/*TARGET 001e2788*/
// 0x001dc9f0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e2788(u8* p) asm("func_001e2788");
// 0x001dc9f0: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e2788(u8* p) {
    *(s32*)(p + 3520) = 0;
    *(s32*)(p + 3524) = 0;
    *(s32*)(p + 3532) = 0;
    *(s32*)(p + 3536) = 0;
    *(s32*)(p + 3556) = 0;
    *(s32*)(p + 3564) = 0;
    *(s32*)(p + 3584) = -1;
    func_001e17b8(p);
}
}  // namespace n001e2788

// 001e27c0 (was src/anon/batch_w13.cpp)
namespace n001e27c0 {
void func_001e17b8(void*) asm("func_001e17b8");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 001e27c0*/
void func_001e27c0(u8* p) asm("func_001e27c0");
void func_001e27c0(u8* p) {
    *(s32*)(p + 3584) = -1;
    *(s32*)(p + 3524) = 0;
    *(s32*)(p + 3532) = 0;
    *(s32*)(p + 3536) = 0;
    *(s32*)(p + 3556) = 0;
    *(s32*)(p + 3564) = 0;
    *(s32*)(p + 3520) = 0;
    func_001e17b8(p);
}
}  // namespace n001e27c0

// 001e27f8 (gap, written for the unit)
namespace n001e27f8 {
void func_001e18d8_g(u32 a0) asm("_Z13func_001e18d8j");
static inline __attribute__((always_inline)) void DestroyArr(u8* t, s32 off, s32 end)
{
    // member array of 16-byte vectors with an empty dtor, destroyed back to front
    if (t != (u8*)-off) {
        u8* p = t + end; u8* b = t + off;
    top:
        if (b == p) goto done;
        p -= 16;
        goto top;
    done:;
    }
}
void func_001e27f8(u8* t) asm("func_001e27f8");
void func_001e27f8(u8* t)
{
    func_001e18d8_g((u32)t);
    DestroyArr(t, 320, 3520);
    DestroyArr(t, 160, 320);
    DestroyArr(t, 0, 160);
}
}  // namespace n001e27f8

// 001e2898 (was src/anon/batch_w66.cpp)
namespace n001e2898 {
// ---- destructors and others (C++ part)

struct E16 { u8 d[16]; ~E16() {} };
void func_001e18d8(void*) asm("func_001e18d8");
// 00135690: moved to src/anon/unit_00134668.cpp

struct Obj1e2 {
    E16 a[10];
    E16 b[10];
    E16 c[200];
    ~Obj1e2() { func_001e18d8(this); }
};
/*TARGET 001e2898*/
void func_001e2898(Obj1e2* p) asm("func_001e2898");
void func_001e2898(Obj1e2* p) { p->~Obj1e2(); }
}  // namespace n001e2898

// 001e2938 (was src/anon/auto80_199_queue.cpp)
namespace n001e2938 {
/*TARGET 001e2938*/
void func_001e2938(u32 a0) asm("_Z13func_001e2938j");
void func_001e2938(u32 a0) {
    u32 s1 = a0;
    u32* base = (u32*)0x00350000;
    func_001e2298(base[0x0AF4]);
    if (*(u32*)(base[0x0AF4] + 3520) == 7) {
        func_001024a8(s1);
        return;
    }
}
}  // namespace n001e2938

// 001e2998 (was src/anon/batch_w31.cpp)
namespace n001e2998 {
extern void* D_00352bd0 asm("D_00352bd0");
void func_001e2898(void*) asm("func_001e2898");
void func_00105110(void*) asm("func_00105110");
/*TARGET 001e2998*/
// 0x001dc018: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e2998(void) asm("func_001e2998");
// 0x001dc018: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e2998(void) {
    void* o = D_00352bd0;
    if (o) {
        func_001e2898(o);
        func_00105110(o);
    }
    D_00352bd0 = 0;
}
}  // namespace n001e2998

// 001e29e0 (was src/anon/batch_w222.cpp)
namespace n001e29e0 {
// 0x00119f48: definition moved into src/anon/unit_00119f48.cpp

char* getFieldMode_(void) asm("_Z12getFieldModev");
char* create_task_(void*, int, int, void*) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
char* area_alloc_(int) asm("_ZN4AREA5AllocEj");
void func_001e27c0(void*) asm("func_001e27c0");
void func_001e2938(void) asm("func_001e2938");
void func_001e2998(void) asm("func_001e2998");
extern int D_00352bd0 asm("D_00352bd0");
/*TARGET 001e29e0*/
void func_001e29e0(int a) asm("func_001e29e0");
void func_001e29e0(int a) {
    char* r = getFieldMode_();
    char* x = create_task_(*(void**)(r + 4), 1, 20500, (void*)func_001e2938);
    *(void**)(x + 48) = (void*)func_001e2998;
    char* s = area_alloc_(3600);
    func_001e27c0(s);
    D_00352bd0 = (int)s;
    *(int*)(s + 3536) = a;
}
}  // namespace n001e29e0

// 001e2a50 (was src/anon/tiny_auto80.cpp)
namespace n001e2a50 {
u32 func_0015f700() asm("_Z13func_0015f700v");
u32 func_0015ee10(u32, u32, u32, u32) asm("_Z13func_0015ee10jjjj");
u32 func_0015e038() asm("_Z13func_0015e038v");
/*TARGET 001e2a50*/
// 0x00188fc0: definition moved into src/anon/unit_00188848.cpp

// 001919a8: moved to src/yasui/libys/status.cpp

u32 func_001e2a50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2a50jjjj");
// 0x00188fc0: definition moved into src/anon/unit_00188848.cpp

// 001919a8: moved to src/yasui/libys/status.cpp

u32 func_001e2a50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = 0u;
    r2 = func_0015ee10(r4, r5, r6, r7);
    r2 = func_0015f700();
    return func_0015e038();
}
}  // namespace n001e2a50

// 001e2a78 (was src/anon/batch_w1668.cpp)
namespace n001e2a78 {
void dkMap_setVisibleGroup(u32) asm("_ZN2dk3Map15setVisibleGroupEj");
void func_0015f6e8(void) asm("func_0015f6e8");
void func_0015e018(void) asm("func_0015e018");
/*TARGET 001e2a78*/
void func_001e2a78(void) asm("func_001e2a78");
void func_001e2a78(void) { dkMap_setVisibleGroup(0); func_0015f6e8(); func_0015e018(); }
}  // namespace n001e2a78

// 001e2aa0 (was src/anon/batch_w1667.cpp)
namespace n001e2aa0 {
extern u32 D_00352bd0 asm("D_00352bd0");
/*TARGET 001e2aa0*/
// 002ef5c8: moved to src/anon/unit_002ef1f8.cpp

// 0014dd80: moved to src/anon/unit_0014d680.cpp

void func_001e2aa0(void) asm("func_001e2aa0");
// 002ef5c8: moved to src/anon/unit_002ef1f8.cpp

// 0014dd80: moved to src/anon/unit_0014d680.cpp

void func_001e2aa0(void) {
    *(s32*)(D_00352bd0 + 0xdc0) = 3;
    *(s32*)(D_00352bd0 + 0xde4) = 0;
}
}  // namespace n001e2aa0

// 001e2ac0 (was src/anon/batch_w1667.cpp)
namespace n001e2ac0 {
extern u32 D_00352bd0 asm("D_00352bd0");
/*TARGET 001e2ac0*/
// 00198a90: moved to src/anon/unit_00197fe0.cpp

void func_001e2ac0(void) asm("func_001e2ac0");
// 00198a90: moved to src/anon/unit_00197fe0.cpp

void func_001e2ac0(void) { *(s32*)(D_00352bd0 + 0xdc0) = 7; }
}  // namespace n001e2ac0

// 001e2ad8 (was src/anon/batch_w47.cpp)
namespace n001e2ad8 {
// Prints three diagnostic lines, then traps.
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9b0[] asm("D_0036e9b0");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*TARGET 001e2ad8*/
// device_vprintf_va
void func_001e2ad8(u32 a, u32 b, u32 c, u32 d) asm("func_001e2ad8");
// device_vprintf_va
void func_001e2ad8(u32 a, u32 b, u32 c, u32 d) {
    func_002fdfc8(D_0036e978, a);  // device_vprintf_va
    func_002fdfc8(D_0036e998, b, c);  // device_vprintf_va
    func_002fdfc8(D_0036e9b0, d);  // device_vprintf_va
    asm volatile("break");
}
}  // namespace n001e2ad8

// 001e2b50 (was src/anon/tiny_more2.cpp)
namespace n001e2b50 {
extern u32 D_01d9eaac asm("D_01d9eaac");
extern u32 D_01d9eab0 asm("D_01d9eab0");
/*TARGET 001e2b50*/
// 0x001d56f0: definition moved into src/anon/unit_001d4f40.cpp

void func_001e2b50(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e2b50jjjj");
// 0x001d56f0: definition moved into src/anon/unit_001d4f40.cpp

void func_001e2b50(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_01d9eaac = a0; D_01d9eab0 = a1; }
}  // namespace n001e2b50

// 001e2b68 (was src/anon/tiny.cpp)
namespace n001e2b68 {
/*TARGET 001e2b68*/
// 0x001ddb68: definition moved into src/anon/unit_001dd920.cpp

void func_001e2b68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2b68jjjj");
// 0x001ddb68: definition moved into src/anon/unit_001dd920.cpp

void func_001e2b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01dau << 16);
    *(u32*)((u32)b + (-5448)) = (u32)0;
}
}  // namespace n001e2b68

// 001e2b78 (was src/anon/tiny.cpp)
namespace n001e2b78 {
void func_001e7698(void*) asm("_Z13func_001e7698Pv");
/*TARGET 001e2b78*/
// 0x001dd1b0: definition moved into src/anon/unit_001dbfd8.cpp
void func_001e2b78(BD_VALUE* bd) asm("_Z13func_001e2b78P8BD_VALUE");
// 0x001dd1b0: definition moved into src/anon/unit_001dbfd8.cpp
void func_001e2b78(BD_VALUE* bd) { func_001e7698(bd); }
}  // namespace n001e2b78

// 001e2b90 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e2b90 {
u32 func_0020df70(...) asm("func_0020df70");
u32 func_0020e758(...) asm("func_0020e758");
/*TARGET 001e2b90*/
void func_001e2b90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001e2b90jjjjjjjj");
void func_001e2b90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r15 = (u32)(0x01dau << 16);
    r14 = *(volatile u32*)((u32)r15 + (s32)(-5464));
    if (r14 != 0u) {
    u32 (*fp_call0_0020e758)() = (u32(*)())func_0020e758;
        ((void(*)())fp_call0_0020e758)();
    u32 (*fp_call0_0020df70)() = (u32(*)())func_0020df70;
        ((void(*)())fp_call0_0020df70)();
    }
}
}  // namespace n001e2b90

// 001e2bc8 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n001e2bc8 {
u32 func_0020dde8() asm("_Z13func_0020dde8v");
u32 func_0020de30() asm("_Z13func_0020de30v");
u32 func_0020df70() asm("_Z13func_0020df70v");
u32 func_0020e960() asm("_Z13func_0020e960v");
/*TARGET 001e2bc8*/
// 0x001d7778: definition moved into src/anon/unit_001d7458.cpp

u32 func_001e2bc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2bc8jjjj");
// 0x001d7778: definition moved into src/anon/unit_001d7458.cpp

u32 func_001e2bc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_0020dde8)() = func_0020dde8;
    r2 = fp_call0_0020dde8();
    u32 (*fp_call0_0020de30)() = func_0020de30;
    r2 = fp_call0_0020de30();
    u32 (*fp_call0_0020df70)() = func_0020df70;
    r2 = fp_call0_0020df70();
    u32 (*fp_call0_0020e960)() = func_0020e960;
    r2 = fp_call0_0020e960();
    return r2;
}
}  // namespace n001e2bc8

// 001e2c00 (was src/anon/batch_w35.cpp)
namespace n001e2c00 {
// 0x001d2130: definition moved into src/anon/unit_001d14e0.cpp

// "Assertion failed: %s\n" / "   File %s, Line %u\n" then break.
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e9c0[] asm("D_0036e9c0");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036e998[] asm("D_0036e998");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
static inline void assert_fail_1e2c00(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
u8 func_001e7cc0(void*) asm("func_001e7cc0");
/*TARGET 001e2c00*/
u8 func_001e2c00(void* pMng) asm("func_001e2c00");
u8 func_001e2c00(void* pMng) {
    if (!pMng) assert_fail_1e2c00(D_0036e9c0, D_0036e9d0, 357);
    return func_001e7cc0(pMng);
}
}  // namespace n001e2c00

// 001e2c60 (gap, written for the unit)
namespace n001e2c60 {
void func_001e2c60(u8* p) asm("func_001e2c60");
void func_001e2c60(u8* p) { p[169] ^= 1; }
}  // namespace n001e2c60

// 001e2c70 (was src/anon/misc_1.cpp)
namespace n001e2c70 {
/*TARGET 001e2c70*/
void func_001e2c70(void* self, s32 v) asm("_Z13func_001e2c70Pvi");
void func_001e2c70(void* self, s32 v) { *(u8*)((char*)self + 169) = (u8)v; }
}  // namespace n001e2c70

// 001e2c78 (was src/anon/tiny.cpp)
namespace n001e2c78 {
/*TARGET 001e2c78*/
u32 func_001e2c78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2c78jjjj");
u32 func_001e2c78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (u32)(*(u8*)((u32)a0 + (132)));
}
}  // namespace n001e2c78

// 001e2c80 (was src/anon/tiny.cpp)
namespace n001e2c80 {
/*TARGET 001e2c80*/
// 0x001ddb58: definition moved into src/anon/unit_001dd920.cpp

void func_001e2c80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e2c80jjjj");
// 0x001ddb58: definition moved into src/anon/unit_001dd920.cpp

void func_001e2c80(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)((u32)a0 + (133)) = (u8)v;
}
}  // namespace n001e2c80

// .rodata 0x36e974-0x36eab0 (strings the code reads as extern D_)
extern const u32 R_0036e974[1] asm("D_0036e974") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_0036e978[8] asm("D_0036e978") __attribute__((aligned(4))) = { 0x416a7952, 0x72657373, 0x6e6f6974, 0x69616620, 0x3a64656c, 0xa732520, 0x0, 0x0 };
extern const u32 R_0036e998[6] asm("D_0036e998") __attribute__((aligned(4))) = { 0x46202020, 0x20656c69, 0x202c7325, 0x656e694c, 0xa752520, 0x0 };
extern const u32 R_0036e9b0[4] asm("D_0036e9b0") __attribute__((aligned(4))) = { 0x22202020, 0xa227325, 0x0, 0x0 };
extern const u32 R_0036e9c0[4] asm("D_0036e9c0") __attribute__((aligned(4))) = { 0x676e4d70, 0x203d2120, 0x4c4c554e, 0x0 };
extern const u32 R_0036e9d0[4] asm("D_0036e9d0") __attribute__((aligned(4))) = { 0x74726170, 0x2e676e4d, 0x63, 0x0 };
extern const u32 R_0036e9e0[12] asm("D_0036e9e0") __attribute__((aligned(4))) = { 0x4e584554, 0x414d524f, 0x54535f4c, 0x20545241, 0x28203d3c, 0x65546873, 0x6c4f7078, 0x202b2064, 0x65546873, 0x69447078, 0x2966, 0x0 };
extern const u32 R_0036ea10[12] asm("D_0036ea10") __attribute__((aligned(4))) = { 0x54687328, 0x4f707865, 0x2b20646c, 0x54687320, 0x44707865, 0x20296669, 0x4c43203c, 0x4f435455, 0x4e4f4d4d, 0x4154535f, 0x5452, 0x0 };
extern const u32 R_0036ea40[12] asm("D_0036ea40") __attribute__((aligned(4))) = { 0x54554c43, 0x4d524f4e, 0x535f4c41, 0x54524154, 0x203d3c20, 0x43687328, 0x7074756c, 0x20646c4f, 0x6873202b, 0x74756c43, 0x66694470, 0x29 };
extern const u32 R_0036ea70[10] asm("D_0036ea70") __attribute__((aligned(4))) = { 0x43687328, 0x7074756c, 0x20646c4f, 0x6873202b, 0x74756c43, 0x66694470, 0x203c2029, 0x54554c43, 0x444e455f, 0x0 };
extern const u32 R_0036ea98[2] asm("D_0036ea98") __attribute__((aligned(4))) = { 0x534c4146, 0x45 };
extern const u32 R_0036eaa0[4] asm("D_0036eaa0") __attribute__((aligned(4))) = { 0x6e6b6e75, 0x206e776f, 0x70797470, 0x2e65 };

// 001e2c90 (was src/anon/batch_w3723.c)
namespace n001e2c90 {
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[4]; u32 tex0lo; u32 tex0hi; } PartRec1e2c90;
typedef struct { u8 pad0[2]; s16 texp; s16 clutp; } PartCur1e2c90;
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036e9e0[] asm("D_0036e9e0");
extern char D_0036ea10[] asm("D_0036ea10");
extern char D_0036ea40[] asm("D_0036ea40");
extern char D_0036ea70[] asm("D_0036ea70");
extern char D_0036ea98[] asm("D_0036ea98");
extern char D_0036eaa0[] asm("D_0036eaa0");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
static inline void ryj001e2c90(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT1e2c90(c, s, line) if (!(c)) ryj001e2c90(s, D_0036e9d0, line)
/*TARGET 001e2c90*/
void func_001e2c90(u8* base, PartCur1e2c90* cur, s16 shTexpNew, s16 shClutpNew) asm("func_001e2c90");
void func_001e2c90(u8* base, PartCur1e2c90* cur, s16 shTexpNew, s16 shClutpNew)
{
    s16 shTexpDif = 0;
    s16 shClutpDif = 0;
    s32 first = 0;
    PartRec1e2c90* p = (PartRec1e2c90*)(base + *(s32*)(base + 4));
    if (cur->texp == 0) {
        first = 1;
        cur->texp = 11264;
        cur->clutp = 15744;
    }
    if (!(shTexpNew || shClutpNew || first)) return;
    if (shTexpNew) shTexpDif = shTexpNew - cur->texp;
    if (shClutpNew) shClutpDif = shClutpNew - cur->clutp;
    if (!shTexpDif && !shClutpDif && !first) return;
    while (p->type != -1) {
        s16 shTexpOld;
        s32 tex = 1;
        s32 sz = 0;
        s32 type = p->type; switch (type) {
        case 0:
            sz = 20;
            tex = 0;
            break;
        case 1:
            sz = 28;
            tex = 0;
            break;
        case 2:
            sz = 32;
            break;
        case 4:
            sz = 24;
            tex = 0;
            break;
        case 5:
            sz = 32;
            tex = 0;
            break;
        case 3:
        case 6:
            sz = 40;
            break;
        case 7:
            sz = 48;
            break;
        default:
            func_001e2ad8(D_0036ea98, D_0036e9d0, 464, D_0036eaa0);
            break;
        }
        if (tex) {
            if (first) {
                shTexpOld = p->tex0lo & 0x3fff;
                if (shTexpOld >= 12288) p->tex0lo = (p->tex0lo & ~0x3fff) + (shTexpOld - 1024);
                else p->tex0lo = (p->tex0lo & ~0x3fff) + (shTexpOld - 512);
                s16 shClutpOld = (p->tex0hi >> 5) & 0x3fff;
                if (shClutpOld >= 15872) p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld - 128) << 5);
                else p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld + 3840) << 5);
            }
            if (shTexpNew && shTexpDif) {
                shTexpOld = p->tex0lo & 0x3fff;
                if (shTexpOld >= 11264) {
                    s32 n = shTexpOld + shTexpDif;
                    ASSERT1e2c90(11264 <= n, D_0036e9e0, 495);
                    ASSERT1e2c90(n < 15616, D_0036ea10, 496);
                    p->tex0lo = (p->tex0lo & ~0x3fff) + n;
                }
            }
            if (shClutpNew && shClutpDif) {
                s16 shClutpOld = (p->tex0hi >> 5) & 0x3fff;
                if (shClutpOld >= 15744) {
                    s32 n = shClutpOld + shClutpDif;
                    ASSERT1e2c90(15744 <= n, D_0036ea40, 506);
                    ASSERT1e2c90(n < 16384, D_0036ea70, 507);
                    p->tex0hi = (p->tex0hi & 0xfff8001f) + (n << 5);
                }
            }
        }
        p = (PartRec1e2c90*)((u8*)p + sz * p->count);
        p++;
    }
}
}  // namespace n001e2c90

// 001e3040 (was src/anon/batch_w2336_gnsa.c)
namespace n001e3040 {
/* Plain C (partMng.c), built with -g and without strict aliasing (-g makes no difference here). */
typedef struct { u8 pad0[16]; u32 tex0lo; u32 tex0hi; } PartRec1e3040;
typedef struct { s16 off; u8 pad[6]; } PartEnt1e3040;
typedef struct { u8 pad0[6]; s16 count; u8 pad8[8]; PartEnt1e3040 ent[1]; } PartHdr1e3040;
typedef struct { u8 pad0[2]; s16 texp; s16 clutp; } PartCur1e3040;
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036e9e0[] asm("D_0036e9e0");
extern char D_0036ea10[] asm("D_0036ea10");
extern char D_0036ea40[] asm("D_0036ea40");
extern char D_0036ea70[] asm("D_0036ea70");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
static inline void ryj001e3040(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT1e3040(c, s, line) if (!(c)) ryj001e3040(s, D_0036e9d0, line)
/*TARGET 001e3040*/
void func_001e3040(PartHdr1e3040* h, PartCur1e3040* cur, s16 shTexpNew, s16 shClutpNew) asm("func_001e3040");
void func_001e3040(PartHdr1e3040* h, PartCur1e3040* cur, s16 shTexpNew, s16 shClutpNew)
{
    s16 shTexpDif = 0;
    s16 shClutpDif = 0;
    s32 first = 0;
    s32 n;
    s16 shTexpOld, shClutpOld;
    PartEnt1e3040* e;
    if (cur->texp == 0) {
        first = 1;
        cur->texp = 11264;
        cur->clutp = 15744;
    }
    if (!shTexpNew && !shClutpNew && !first) return;
    if (shTexpNew) shTexpDif = shTexpNew - cur->texp;
    if (shClutpNew) shClutpDif = shClutpNew - cur->clutp;
    e = h->ent;
    for (n = h->count; n > 0; n--, e++) {
        PartRec1e3040* p = (PartRec1e3040*)((u8*)h + e->off);
        if (first) {
            shTexpOld = p->tex0lo & 0x3fff;
            if (shTexpOld >= 12288) p->tex0lo = (p->tex0lo & ~0x3fff) + shTexpOld - 1024;
            else p->tex0lo = (p->tex0lo & ~0x3fff) + shTexpOld - 512;
            shClutpOld = (p->tex0hi >> 5) & 0x3fff;
            if (shClutpOld >= 15872) p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld - 128) << 5);
            else p->tex0hi = (p->tex0hi & 0xfff8001f) + ((shClutpOld + 3840) << 5);
        }
        if (shTexpNew && shTexpDif) {
            shTexpOld = p->tex0lo & 0x3fff;
            if (shTexpOld >= 11264) {
                s32 v = shTexpOld + shTexpDif;
                ASSERT1e3040(11264 <= v, D_0036e9e0, 576);
                ASSERT1e3040(v < 15616, D_0036ea10, 577);
                p->tex0lo = (p->tex0lo & ~0x3fff) + v;
            }
        }
        if (shClutpNew && shClutpDif) {
            shClutpOld = (p->tex0hi >> 5) & 0x3fff;
            if (shClutpOld >= 15744) {
                s32 v = shClutpOld + shClutpDif;
                ASSERT1e3040(15744 <= v, D_0036ea40, 587);
                ASSERT1e3040(v < 16384, D_0036ea70, 588);
                p->tex0hi = (p->tex0hi & 0xfff8001f) + (v << 5);
            }
        }
    }
}
}  // namespace n001e3040

// 001e3330 (was src/anon/batch_w1836_nsa.cpp)
namespace n001e3330 {
struct W1836Vec { float x, y, z, w; } __attribute__((aligned(16)));
void func_001e7da8(void) asm("func_001e7da8");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0OuterProduct(void*, void*, void*) asm("sceVu0OuterProduct");
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
extern u8 D_01d9e6f0[] asm("D_01d9e6f0");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern float D_01d9e840[] asm("D_01d9e840");
extern W1836Vec D_01d9e870 asm("D_01d9e870");
extern W1836Vec D_01d9e880 asm("D_01d9e880");
extern W1836Vec D_01d9e890 asm("D_01d9e890");
extern W1836Vec D_01d9e8a0 asm("D_01d9e8a0");
extern W1836Vec D_01d9e8b0 asm("D_01d9e8b0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_01d9e900[] asm("D_01d9e900");
extern u8 D_01d9e940[] asm("D_01d9e940");
/*TARGET 001e3330*/
void func_001e3330(void) asm("func_001e3330");
void func_001e3330(void)
{
    W1836Vec u;
    W1836Vec t;
    W1836Vec w;

    func_001e7da8();
    sceVu0MulMatrix(D_01d9e840, D_01d9e730, D_01d9e6f0);
    sceVu0MulMatrix(D_01d9e900, D_01d9e8c0, D_01d9e840);
    t.x = D_01d9e840[4];
    t.y = D_01d9e840[5];
    t.z = D_01d9e840[6];
    *(s32*)&t.w = 0;
    sceVu0Normalize(&t, &t);
    D_01d9e890 = t;
    u.x = t.y;
    u.y = -t.x;
    *(s32*)&u.z = 0;
    *(s32*)&u.w = 0;
    sceVu0Normalize(&u, &u);
    D_01d9e880 = u;
    sceVu0OuterProduct(&w, &u, &t);
    sceVu0Normalize(&w, &w);
    D_01d9e8a0 = w;
    D_01d9e8b0 = D_01d9e870;
    sceVu0MulMatrix(D_01d9e940, D_01d9e8c0, &D_01d9e880);
}
}  // namespace n001e3330

// 001e3468 (was src/anon/batch_w48.cpp)
namespace n001e3468 {
// 0x001d5d20: definition moved into src/anon/unit_001d4f40.cpp

extern u8 D_01d9e370[] asm("D_01d9e370");
extern u8 D_01d9e6f0[] asm("D_01d9e6f0");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
/*TARGET 001e3468*/
u8* func_001e3468(u8* o) asm("func_001e3468");
u8* func_001e3468(u8* o) {
    u8* b = *(u8**)(o + 140);
    for (s32 i = 0; i < 8; i++) sceVu0ApplyMatrix(D_01d9e370 + i * 16, D_01d9e6f0, b + i * 16);
    return D_01d9e370;
}
}  // namespace n001e3468

// 001e34e0 (was src/anon/batch_switch1.c)
namespace n001e34e0 {
/* Particle draw mode from a blend index (pppPart). Switch jump table at 0x36ead0 (first switch matched, 2026-10-11). */
struct PartW { u8 pad[0xa8]; u8 mode; };
void w_part_mode_odd(struct PartW* p, u32 k) asm("_Z16wtarget_001e34e0jjjj");
/*TARGET 001e34e0*/
void w_part_mode_odd(struct PartW* p, u32 k) asm("_Z16wtarget_001e34e0jjjj");
void w_part_mode_odd(struct PartW* p, u32 k) {
    switch (k) {
    case 0: p->mode = 1; break;
    case 1: p->mode = 3; break;
    case 2: p->mode = 5; break;
    case 3: p->mode = 7; break;
    case 4: p->mode = 9; break;
    default: p->mode = 11; break;
    }
}
}  // namespace n001e34e0

// 001e3538 (was src/anon/batch_switch1.c)
namespace n001e3538 {
/* Particle draw mode from a blend index (pppPart). Switch jump table at 0x36ead0 (first switch matched, 2026-10-11). */
struct PartW { u8 pad[0xa8]; u8 mode; };
void w_part_mode_even(struct PartW* p, u32 k) asm("_Z16wtarget_001e3538jjjj");
/*TARGET 001e3538*/
/* Same with the even modes; jump table at 0x36eae4. */
void w_part_mode_even(struct PartW* p, u32 k) asm("_Z16wtarget_001e3538jjjj");
/* Same with the even modes; jump table at 0x36eae4. */
void w_part_mode_even(struct PartW* p, u32 k) {
    switch (k) {
    case 0: p->mode = 2; break;
    case 1: p->mode = 4; break;
    case 2: p->mode = 6; break;
    case 3: p->mode = 8; break;
    case 4: p->mode = 10; break;
    default: p->mode = 12; break;
    }
}
}  // namespace n001e3538

// 001e3590 (was src/anon/batch_w401.cpp)
namespace n001e3590 {
struct S109 { u8 pad[168]; u8 f168; };
/*TARGET 001e3590*/
int func_001e3590(S109* a0) asm("func_001e3590");
int func_001e3590(S109* a0) {
    int r = 0;
    switch (a0->f168) {
    case 1: r = 1; break;
    case 3: r = 2; break;
    case 5: r = 3; break;
    case 7: r = 4; break;
    case 9: r = 5; break;
    case 11: r = 6; break;
    default: r = 0; break;
    }
    return r;
}
}  // namespace n001e3590

// 001e35f0 (was src/anon/batch_w401.cpp)
namespace n001e35f0 {
struct S109 { u8 pad[168]; u8 f168; };
/*TARGET 001e35f0*/
int func_001e35f0(S109* a0) asm("func_001e35f0");
int func_001e35f0(S109* a0) {
    int r = 0;
    switch (a0->f168) {
    case 2: r = 1; break;
    case 4: r = 2; break;
    case 6: r = 3; break;
    case 8: r = 4; break;
    case 10: r = 5; break;
    case 12: r = 6; break;
    default: r = 0; break;
    }
    return r;
}
}  // namespace n001e35f0

// 001e3650 (was src/anon/tiny.cpp)
namespace n001e3650 {
/*TARGET 001e3650*/
u32 func_001e3650(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e3650jjjj");
u32 func_001e3650(u32 a0, u32 a1, u32 a2, u32 a3) {  // ptr_add4
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (4));
}
}  // namespace n001e3650

// 001e3660 (was src/anon/auto200_999_queue.cpp)
namespace n001e3660 {
/*TARGET 001e3660*/
// 0x0010f340: definition moved into src/anon/unit_0010f338.cpp

u32 func_001e3660(u32 a0, s32 a1) asm("_Z13func_001e3660ji");
// 0x0010f340: definition moved into src/anon/unit_0010f338.cpp

u32 func_001e3660(u32 a0, s32 a1) {
    if (a1 <= 0) {
        return a0;
    }

    u32 v0 = a0;
    do {
        u32 t7 = *(u32*)v0;
        a1 -= 1;
        t7 <<= 2;
        v0 += 4;
        v0 += t7;
    } while (a1 != 0);
    return v0;
}
}  // namespace n001e3660

// 001e3690 (was src/anon/batch_w316.cpp)
namespace n001e3690 {
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036eb60[] asm("D_0036eb60");
extern char D_0036eb90[] asm("D_0036eb90");
extern char D_0036ebc8[] asm("D_0036ebc8");
extern char D_0036ebf0[] asm("D_0036ebf0");
extern char D_0036ec18[] asm("D_0036ec18");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
s32* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
s32* func_001e3660_x(s32*, s32) asm("_Z13func_001e3660ji");
static inline void assert_fail_1e3690(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e3690*/
s32 func_001e3690(u8* o) asm("func_001e3690");
s32 func_001e3690(u8* o) {
  s32 r = 0;
  s32* p;
  u8 idx;
  p = (s32*)*(void**)(o + 136);
  idx = o[147];
  p = func_001e3650(p);  // ptr_add4
  s32 n = *p++;
  s32 i;
  for (i = 0; i < n; i++, p++) {
    if (idx == i) { s32 v = *p; *(s32*)(o + 140) = v; r = v + 272; }
  }
  s32* q;
  q = func_001e3660_x(p, 4);
  if (q[0] == -1) goto none;
  if (q[0] < 12288) assert_fail_1e3690(D_0036eb60, D_0036e9d0, 822);
  s32 a, b;
  a = (q[1] - 12161) / 128;
  if (q[2] < 15872) assert_fail_1e3690(D_0036eb90, D_0036e9d0, 827);
  if (!(q[3] <= 16384)) assert_fail_1e3690(D_0036ebc8, D_0036e9d0, 828);
  b = (q[3] - 15841) / 32;
  if (!(a < 35)) assert_fail_1e3690(D_0036ebf0, D_0036e9d0, 833);
  if (!(b < 21)) assert_fail_1e3690(D_0036ec18, D_0036e9d0, 834);
  o[145] = a;
  o[146] = b;
  return r;
none:
  o[145] = 0; o[146] = 0;
  return r;
}
}  // namespace n001e3690

// 001e3898 (was src/anon/batch_w41.cpp)
namespace n001e3898 {
s32* func_001e3650(u32) asm("func_001e3650");
/*TARGET 001e3898*/
// ptr_add4
void func_001e3898(u32 a, s32 d) asm("func_001e3898");
// ptr_add4
void func_001e3898(u32 a, s32 d) {
    s32* v = func_001e3650(a);  // ptr_add4
    for (s32 k = 0; k < 5; k++) {
        s32 n = *v++;
        for (s32 j = 0; j < n; j++) {
            v[0] += d;
            v++;
        }
    }
}
}  // namespace n001e3898

// 001e38f8 (was src/anon/batch_w1899_nsa.cpp)
namespace n001e38f8 {
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036ec40[] asm("D_0036ec40");
extern char D_0036ec58[] asm("D_0036ec58");
extern char D_0036ec70[] asm("D_0036ec70");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e3040(void*, void*, s16, s16) asm("func_001e3040");
#define ASSERT_FAIL(e, f, l) do { func_002fdfc8(D_0036e978, e); func_002fdfc8(D_0036e998, f, l); asm volatile("break"); } while (0)
/*TARGET 001e38f8*/
s32* func_001e38f8(s32* a, u8* bits, s16 x, s16 y) asm("func_001e38f8");
s32* func_001e38f8(s32* a, u8* bits, s16 x, s16 y) {
    s32 n = *a++;
    s32 i;
    u8 cur = 0;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)*a++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        if ((u32)e & 0xf) ASSERT_FAIL(D_0036ec40, D_0036e9d0, 910);
        if (!(byte < 16)) ASSERT_FAIL(D_0036ec58, D_0036e9d0, 911);
        if (!(byte >= 0)) ASSERT_FAIL(D_0036ec70, D_0036e9d0, 911);
        if (bit == 0) cur = bits[byte];
        if (cur & 1) {
            func_001e3040(e + 16, e, x, y);
            if (x) *(s16*)(e + 2) = x;
            if (y) *(s16*)(e + 4) = y;
        }
        cur >>= 1;
    }
    return a;
}
}  // namespace n001e38f8

// 001e3a88 (was src/anon/batch_w1899_nsa.cpp)
namespace n001e3a88 {
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036ec40[] asm("D_0036ec40");
extern char D_0036ec58[] asm("D_0036ec58");
extern char D_0036ec70[] asm("D_0036ec70");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
#define ASSERT_FAIL(e, f, l) do { func_002fdfc8(D_0036e978, e); func_002fdfc8(D_0036e998, f, l); asm volatile("break"); } while (0)
void func_001e2c90(void*, void*, s16, s16) asm("func_001e2c90");
/*TARGET 001e3a88*/
s32* func_001e3a88(s32* a, u8* bits, s16 x, s16 y) asm("func_001e3a88");
s32* func_001e3a88(s32* a, u8* bits, s16 x, s16 y) {
    s32 n = *a++;
    s32 i;
    u8 cur = 0;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)*a++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        if ((u32)e & 0xf) ASSERT_FAIL(D_0036ec40, D_0036e9d0, 949);
        if (!(byte < 16)) ASSERT_FAIL(D_0036ec58, D_0036e9d0, 950);
        if (!(byte >= 0)) ASSERT_FAIL(D_0036ec70, D_0036e9d0, 950);
        if (bit == 0) cur = bits[byte];
        if (cur & 1) {
            func_001e2c90(e + 16, e, x, y);
            if (x) *(s16*)(e + 2) = x;
            if (y) *(s16*)(e + 4) = y;
        }
        cur >>= 1;
    }
    return a;
}
}  // namespace n001e3a88

// 001e3c18 (was src/anon/batch_w3712.cpp)
namespace n001e3c18 {
/* ---- 001e3c18 ---- */
struct E1e3c18 { u8 pad[0x88]; void* x88; u8* x8c; u8 pad2[0xc]; s16 x9c; s16 x9e; };
struct NoTail1e3c18 { ~NoTail1e3c18() {} };
// 001cd548: static init of the prize work object, moved to src/anon/unit_001cd548.cpp

void* func_001e3650(void*) asm("func_001e3650");
void* f_001e3660(void*, s32) asm("_Z13func_001e3660ji");
void* func_001e38f8(void*, void*, s32, s32) asm("func_001e38f8");
void* func_001e3a88(void*, void*, s32, s32) asm("func_001e3a88");
/*TARGET 001e3c18*/
void func_001e3c18(E1e3c18* p) asm("func_001e3c18");
void func_001e3c18(E1e3c18* p) {
    NoTail1e3c18 nt;
    register s32 a asm("$18");
    register s32 b asm("$17");
    void* v;
    /* hand-written loads: x9e must be read last, through the saved copy of p in s0 */
    asm("lh %0,156(%1)" : "=r"(a) : "r"(p));
    v = p->x88;
    asm("lh %0,158($16)" : "=r"(b) : "r"(p), "r"(v));
    v = func_001e3650(v);
    v = f_001e3660(v, 2);
    v = func_001e38f8(v, p->x8c + 0xc0, a, b);
    func_001e3a88(v, p->x8c + 0xd0, a, b);
}
}  // namespace n001e3c18

// 001e3c98 (was src/anon/batch_w325.c)
namespace n001e3c98 {
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[];
extern "C" char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ec80[], D_0036ec98[];
typedef struct { u32 a; u32 b; } W325E8;
extern W325E8 D_00353e48[] asm("D_00353e48");
/* RyjAssert: "RyjAssertion failed: %s\n" then "   File %s, Line %u\n", break. */
static inline void ryjAssert5(const char* a, const char* e, const char* b, const char* f, s32 l) {
    func_002fdfc8(a, e);  // device_vprintf_va
    func_002fdfc8(b, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define RYJ_ASSERT(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)
/*TARGET 001e3c98*/
u32* func_001e3c98(s32* p, u8* bits) asm("func_001e3c98");
u32* func_001e3c98(s32* p, u8* bits) {
    s32 n = *p++;
    s32 i;
    u8 m = 0;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)*p++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        RYJ_ASSERT(!((u32)e & 0xf), D_0036ec40, 1014);
        RYJ_ASSERT(byte < 16, D_0036ec58, 1015);
        RYJ_ASSERT(byte >= 0, D_0036ec70, 1015);
        if (bit == 0) m = bits[byte];
        if (m & 1) {
            s32 id = *(s16*)e;
            if (id >= 128) func_001e2ad8(D_0036ec80, D_0036e9d0, 1027, D_0036ec98);
            D_00353e48[id].a = (u32)(e + 16);
            D_00353e48[id].b = *(u32*)(e + 8);
        }
        m >>= 1;
    }
    return (u32*)p;
}
}  // namespace n001e3c98

// 001e3e48 (was src/anon/batch_w328.c)
namespace n001e3e48 {
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ecb0[], D_0036ecc8[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
static inline void ryjTail(const char* f, s32 l) {
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERTM(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); ryjTail(D_0036e9d0, l); }
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
typedef union { s32 a; u8* p; u8 c; } U;
typedef struct { U a, b, c, d, e; U f; U g; U h; U k; } T;
extern T D_00352c48[] asm("D_00352c48");
/*TARGET 001e3e48*/
u32* func_001e3e48(s32* p, u8* bits) asm("func_001e3e48");
u32* func_001e3e48(s32* p, u8* bits) {
    s32 n;
    u32* q;
    s32 i;
    u32 m;
    u32 v;
    s32 byte, bit;
    q = (u32*)p;
    n = *q++;
    i = 0;
    m = 0;
    for (; i < n; i++) {
        v = *q++;
        byte = i >> 3;
        bit = i & 7;
        ASSERTM(!(v & 0xf), D_0036ec40, 1053);
        ASSERT(byte < 16, D_0036ec58, 1054);
        ASSERT(byte >= 0, D_0036ec70, 1054);
        if (bit == 0) m = bits[byte];
        if ((u8)(m & 1)) {
            s32 k = *(s16*)v;
            u8* d = (u8*)v + 16;
            T* t;
            if (!(k < 128)) func_001e2ad8(D_0036ecb0, D_0036e9d0, 1068, D_0036ecc8);
            t = &D_00352c48[k];
            t->h.p = d;
            t->a.a = *(s16*)(d + 18);
            t->b.a = *(s16*)(d + 20);
            t->c.a = *(s16*)(d + 16);
            t->f.p = d + *(s32*)(d + 8);
            t->g.p = d + *(s32*)(d + 12);
            t->k.a = *(u32*)(v + 8);
        }
        m >>= 1;
    }
    return q;
}
}  // namespace n001e3e48

// 001e4028 (was src/anon/batch_w331.c)
namespace n001e4028 {
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ece0[], D_0036ecf0[];
typedef union { u16 h; void* p; u8 c; } U2_331;
typedef struct T331 { u16 a, b; void* p; } T331;
extern T331 D_00354248[] asm("D_00354248");
static inline void rb331(const char* f, s32 l) { func_002fdfc8(D_0036e998, f, l); asm volatile("break"); }
#define ASSERTD331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); rb331(D_0036e9d0, l); }
#define ASSERT331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); func_002fdfc8(D_0036e998, D_0036e9d0, l); asm volatile("break"); }
/*TARGET 001e4028*/
u32* func_001e4028(u32* p, u8* bits) asm("func_001e4028");
u32* func_001e4028(u32* p, u8* bits) {
    s32 n = *p++;
    s32 i;
    u32 m = 0;
    for (i = 0; i < n; i++) {
        u32 v = *p++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        ASSERT331(!(v & 0xf), D_0036ec40, 1100);
        ASSERT331(byte < 16, D_0036ec58, 1101);
        ASSERTD331(byte >= 0, D_0036ec70, 1101);
        if (bit == 0) m = bits[byte];
        if ((u8)(m & 1)) {
            s32 id = *(s32*)v;
            T331* t;
            if (id >= 128) func_001e2ad8(D_0036ece0, D_0036e9d0, 1111, D_0036ecf0);
            t = &D_00354248[id];
            t->a = *(u16*)(v + 4);
            t->b = *(u16*)(v + 8);
            ((U2_331*)((u8*)t + 4))->p = (void*)(v + 12);
        }
        m >>= 1;
    }
    return p;
}
}  // namespace n001e4028

// 001e41e0 (was src/anon/batch_w326.c)
namespace n001e41e0 {
void* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
void* func_001e3660(void*, s32) asm("func_001e3660");
void* func_001e3c98(void*, void*) asm("func_001e3c98");
void* func_001e3e48(void*, void*) asm("func_001e3e48");
u8 func_001e4028(void*, void*) asm("func_001e4028");
/*TARGET 001e41e0*/
s32 func_001e41e0(u8* p) asm("func_001e41e0");
s32 func_001e41e0(u8* p) {
    void* q = *(void**)(p + 0x88);
    void* t;
    q = func_001e3650(q);  // ptr_add4
    t = func_001e3660(q, 2);
    t = func_001e3c98(t, *(u8**)(p + 0x8c) + 0xc0);
    t = func_001e3e48(t, *(u8**)(p + 0x8c) + 0xd0);
    return func_001e4028(t, *(u8**)(p + 0x8c) + 0xe0);
}
}  // namespace n001e41e0

// .rodata 0x36eb5c-0x36ed04 (strings the code reads as extern D_)
extern const u32 R_0036eb5c[1] asm("D_0036eb5c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_0036eb60[12] asm("D_0036eb60") __attribute__((aligned(4))) = { 0x504d4954, 0x545f534f, 0x4f4e5845, 0x4c414d52, 0x4154535f, 0x3c205452, 0x4870203d, 0x45646165, 0x3e2d6374, 0x6e694d6e, 0x56786554, 0x6d6172 };
extern const u32 R_0036eb90[14] asm("D_0036eb90") __attribute__((aligned(4))) = { 0x504d4954, 0x435f534f, 0x4e54554c, 0x414d524f, 0x54535f4c, 0x20545241, 0x70203d3c, 0x64616548, 0x2d637445, 0x694d6e3e, 0x756c436e, 0x61725674, 0x6d, 0x0 };
extern const u32 R_0036ebc8[10] asm("D_0036ebc8") __attribute__((aligned(4))) = { 0x61654870, 0x63744564, 0x4d6e3e2d, 0x6c437861, 0x72567475, 0x3c206d61, 0x4c43203d, 0x455f5455, 0x444e, 0x0 };
extern const u32 R_0036ebf0[10] asm("D_0036ebf0") __attribute__((aligned(4))) = { 0x7865546e, 0x6d617256, 0x636f6c42, 0x3d3c206b, 0x58455420, 0x4d524f4e, 0x425f4c41, 0x4b434f4c, 0x4d554e5f, 0x0 };
extern const u32 R_0036ec18[10] asm("D_0036ec18") __attribute__((aligned(4))) = { 0x756c436e, 0x61725674, 0x6f6c426d, 0x3c206b63, 0x4c43203d, 0x4f4e5455, 0x4c414d52, 0x4f4c425f, 0x4e5f4b43, 0x4d55 };
extern const u32 R_0036ec40[6] asm("D_0036ec40") __attribute__((aligned(4))) = { 0x3d3d2030, 0x6e692820, 0x63702974, 0x66754268, 0x31202520, 0x36 };
extern const u32 R_0036ec58[6] asm("D_0036ec58") __attribute__((aligned(4))) = { 0x7864496e, 0x50203c20, 0x5f435445, 0x49455355, 0x454c5f44, 0x4e };
extern const u32 R_0036ec70[4] asm("D_0036ec70") __attribute__((aligned(4))) = { 0x3d3c2030, 0x64496e20, 0x78, 0x0 };
extern const u32 R_0036ec80[6] asm("D_0036ec80") __attribute__((aligned(4))) = { 0x7068536e, 0x3c206f4e, 0x58414d20, 0x5048535f, 0x0, 0x0 };
extern const u32 R_0036ec98[6] asm("D_0036ec98") __attribute__((aligned(4))) = { 0x70616873, 0x61642065, 0x69206174, 0x766f2073, 0x217265, 0x0 };
extern const u32 R_0036ecb0[6] asm("D_0036ecb0") __attribute__((aligned(4))) = { 0x73526873, 0x206f4e64, 0x414d203c, 0x53525f58, 0x44, 0x0 };
extern const u32 R_0036ecc8[6] asm("D_0036ecc8") __attribute__((aligned(4))) = { 0x20647372, 0x61746164, 0x20736920, 0x7265766f, 0x21, 0x0 };
extern const u32 R_0036ece0[4] asm("D_0036ece0") __attribute__((aligned(4))) = { 0x6e667376, 0x203c206f, 0x5f58414d, 0x465356 };
extern const u32 R_0036ecf0[5] asm("D_0036ecf0") __attribute__((aligned(4))) = { 0x20667376, 0x61746164, 0x20736920, 0x7265766f, 0x21 };

// 001e4248 (was src/anon/batch_w244.cpp)
namespace n001e4248 {
// 002cef80: moved to src/taito/minigame_base.cpp (linked unit)
// register pins reproduce the original's counter/temp allocation
struct Hdr1e { s16 a; s16 b; s16 c; s16 fmt; u8 pad[16]; s32 off; };
/*TARGET 001e4248*/
Hdr1e** func_001e4248(s32* p) asm("func_001e4248");
Hdr1e** func_001e4248(s32* p) {
  register s32 n asm("$15") = p[0];
  Hdr1e** h = (Hdr1e**)(p + 1);
  register s32 i asm("$10");
  if (n > 0) for (i = n; i != 0; i--) {
    s32 cnt = 0;
    Hdr1e* t = *h++;
    u8* d = (u8*)t + t->off + 32;
    if (t->b == 0) continue;
    switch (t->fmt) {
    case 19: cnt = 256; break;
    case 20: cnt = 16; break;
    }
    for (; cnt != 0; cnt--) {
      s32 v = (s32)(d[0] * 0.3f + d[1] * 0.59f + d[2] * 0.11f);
      d[2] = v; d[1] = v; d[0] = v;
      d += 4;
    }
  }
  return h;
}
}  // namespace n001e4248

// .rodata 0x36ed10-0x36ed28 (strings the code reads as extern D_)
extern const u32 R_0036ed10[6] asm("D_0036ed10") __attribute__((aligned(4))) = { 0x3d3d2030, 0x6e692820, 0x6f6d2974, 0x206c6564, 0x36312025, 0x0 };

// 001e4320 (was src/anon/batch_w3849_nsa.c)
namespace n001e4320 {
typedef struct { u8 r, g, b, a; } RGBA;
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[12]; } PartPrim;
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036ea98[] asm("D_0036ea98");
extern char D_0036eaa0[] asm("D_0036eaa0");
extern char D_0036ed10[] asm("D_0036ed10");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
static inline void ryj001e5a00(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT(c, s, line) if (!(c)) ryj001e5a00(s, D_0036e9d0, line)
#define MONO(c) { fGray = (c).r * 0.3f + (c).g * 0.59f + (c).b * 0.11f; { s32 m = (s32)fGray; (c).r = m; (c).g = m; (c).b = m; } }
#define LOOP3(sz) nSize = sz; for (j = 0; j < nNum; j++) { f32 fGray; MONO(((RGBA*)v)[0]); MONO(((RGBA*)v)[1]); MONO(((RGBA*)v)[2]); v += sz; } break;
#define LOOP4(sz) nSize = sz; for (j = 0; j < nNum; j++) { f32 fGray; MONO(((RGBA*)v)[0]); MONO(((RGBA*)v)[1]); MONO(((RGBA*)v)[2]); MONO(((RGBA*)v)[3]); v += sz; } break;
/*TARGET 001e4320*/
// 001e4320: turn every model's vertex colours to grey; returns the end of the model list.
s32* func_001e4320(s32* pData) asm("func_001e4320");
// 001e4320: turn every model's vertex colours to grey; returns the end of the model list.
s32* func_001e4320(s32* pData)
{
    s32 nModel = *pData++;
    s32 i, j, nNum, nSize, nType;
    u8* model;
    u8* base;
    u8* v;
    PartPrim* p;
    for (i = 0; i < nModel; i++) {
        model = (u8*)*pData++;
        nSize = 0;
        base = model + 16;
        p = (PartPrim*)(base + ((s32*)base)[1]);
        ASSERT(0 == (int)model % 16, D_0036ed10, 1196);
        while (p->type != -1) {
            nType = p->type;
            nNum = p->count;
            p++;
            asm("" : "+r"(p));
            v = (u8*)p;
            switch (nType) {
            case 0: LOOP3(20)
            case 1: LOOP3(28)
            case 2: LOOP3(32)
            case 3: LOOP3(40)
            case 4: LOOP4(24)
            case 5: LOOP4(32)
            case 6: LOOP4(40)
            case 7: LOOP4(48)
            default:
                func_001e2ad8(D_0036ea98, D_0036e9d0, 1332, D_0036eaa0);
                break;
            }
            p = (PartPrim*)((u8*)p + nSize * nNum);
        }
    }
    return pData;
}
}  // namespace n001e4320

// 001e4e18 (was src/anon/batch_w331.c)
namespace n001e4e18 {
typedef struct Px { u8 r, g, b, a; u32 x4; } Px;
typedef struct Sub { s16 x0; s16 n; s32 off; } Sub;
typedef struct Ent { s16 off; s16 x2; s32 x4; } Ent;
typedef struct Hd { s16 x0, x2; s32 x4:16; s32 n:16; u32 x8, xc; Ent e[1]; } Hd;
/*TARGET 001e4e18*/
s32* func_001e4e18(s32* p) asm("func_001e4e18");
s32* func_001e4e18(s32* p) {
    s32 n = *p++;
    s32 i, j, k;
    for (i = 0; i < n; i++) {
        u8* t = (u8*)*p++;
        Hd* h = (Hd*)(t + 16);
        s32 m = h->n;
        for (j = 0; j < m; j++) {
            Sub* s = (Sub*)((u8*)h + h->e[j].off); Px* px = (Px*)((u8*)s + s->off); for (k = 0; k < s->n; k++, px++) { s32 v = (s32)(px->r * 0.3f + px->g * 0.59f + px->b * 0.11f); px->r = v; px->g = v; px->b = v; }
        }
    }
    return p;
}
}  // namespace n001e4e18

// 001e4f00 (was src/anon/batch_w16.cpp)
namespace n001e4f00 {
void* func_001e3650(void) asm("func_001e3650");
// ptr_add4
void* func_001e3660(void*, u32) asm("func_001e3660");
void* func_001e4248(void*) asm("func_001e4248");
void* func_001e4e18(void*) asm("func_001e4e18");
void func_001e4320(void*) asm("func_001e4320");
/*TARGET 001e4f00*/
// 0x001d23e0: definition moved into src/anon/unit_001d14e0.cpp

void func_001e4f00(void) asm("func_001e4f00");
// 0x001d23e0: definition moved into src/anon/unit_001d14e0.cpp

void func_001e4f00(void) {
    func_001e4320(func_001e4e18(func_001e4248(func_001e3660(func_001e3650(), 1))));
}
}  // namespace n001e4f00

// 001e4f40 (was src/anon/batch_w273.cpp)
namespace n001e4f40 {
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036ed60[] asm("D_0036ed60");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036ed78[] asm("D_0036ed78");
extern char D_0036ed98[] asm("D_0036ed98");
extern u8 D_00354bf0[] asm("D_00354bf0");
extern s32 D_00352c38 asm("D_00352c38");
#define ASSERT(c, s, l) if (!(c)) assert_fail_1e4f40(s, D_0036e9d0, l)
s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
void func_001e3898(void*, void*) asm("func_001e3898");
s32* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
void func_001e8180(s32, void*) asm("func_001e8180");
void func_001e4f00(void*) asm("func_001e4f00");
static inline void assert_fail_1e4f40(const char* e, const char* f, s32 l) {
  func_002fdfc8(D_0036e978, e);  // device_vprintf_va
  func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
  asm volatile("break");
}
void func_001e4f40(void* p) asm("_Z13func_001e4f40Pv");
/*TARGET 001e4f40*/
void func_001e4f40(void* p) asm("_Z13func_001e4f40Pv");
void func_001e4f40(void* p) {
  struct NoTail { ~NoTail(){} } nt;
  ASSERT(p, D_0036ed60, 1389);
  ASSERT(((u32)p & 0xf) == 0, D_0036ed78, 1390);
  func_001e3898(p, p);
  s32* q = func_001e3650(p);  // ptr_add4
  s32 n = *q;
  s32 i;
  q++;
  for (i = 0; i < n; i++) {
    s32 x = *q++;
    ASSERT((x & 0xf) == 0, D_0036ed98, 1422);
    func_001e8180(x, D_00354bf0);
  }
  if (D_00352c38) func_001e4f00(p);
}
}  // namespace n001e4f40

// 001e50a8 (was src/anon/batch_w268.cpp)
namespace n001e50a8 {
// 0x002881c0: definition moved into src/anon/unit_002880b8.cpp

s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036ed60[], D_0036e998[], D_0036e9d0[], D_0036ed78[], D_0036ed98[];
void func_001e3898(void*, s32) asm("func_001e3898");
s32* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
void func_001e8288(s32, s32) asm("func_001e8288");
static inline void assert_fail_1e50a8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e50a8*/
void func_001e50a8(s32* a0, s32 a1) asm("func_001e50a8");
void func_001e50a8(s32* a0, s32 a1) {
    s32 v;
    if (!a0) assert_fail_1e50a8(D_0036ed60, D_0036e9d0, 1441);
    if ((u32)a0 & 0xf) assert_fail_1e50a8(D_0036ed78, D_0036e9d0, 1442);
    func_001e3898(a0, a1);
    a0 = func_001e3650(a0);  // ptr_add4
    s32 n = *a0++;
    for (s32 i = 0; i < n; i++) {
        v = *a0++;
        if (v & 0xf) assert_fail_1e50a8(D_0036ed98, D_0036e9d0, 1460);
        func_001e8288(v, a1);
    }
}
}  // namespace n001e50a8

// 001e51f0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n001e51f0 {
u32 func_001e4f40(u32, u32, u32, u32) asm("_Z13func_001e4f40jjjj");
/*TARGET 001e51f0*/
// 0x001d7c00: definition moved into src/anon/unit_001d7458.cpp

u32 func_001e51f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e51f0jjjj");
// 0x001d7c00: definition moved into src/anon/unit_001d7458.cpp

u32 func_001e51f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001e4f40(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(17992)) = r16;
    return r2;
}
}  // namespace n001e51f0

// 001e5220 (was src/anon/batch_w3727.cpp)
namespace n001e5220 {
// Empty-destructor local: keeps the last call a jal (no sibling call), as in the original.
struct NoTail_w3727 { ~NoTail_w3727() {} };
void sceGsSetDefLoadImage(void*, s16, s16, s16, s16, s16, s16, s16) asm("sceGsSetDefLoadImage");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(void*, void*) asm("sceGsExecLoadImage");
extern u8 D_01d9e3f0 asm("D_01d9e3f0");
/*TARGET 001e5220*/
// Draws an entry: the first value is shifted by d and rebased (12288 or 10752) before the call.
void func_001e5220(s16* p, s16 d) asm("func_001e5220");
// Draws an entry: the first value is shifted by d and rebased (12288 or 10752) before the call.
void func_001e5220(s16* p, s16 d) {
    NoTail_w3727 nt;
    s16 a = p[0];
    if (a >= 12288) a = a + d - 12288; else a = a + d - 10752;
    sceGsSetDefLoadImage(&D_01d9e3f0, a, p[2], p[3], p[4], p[5], p[6], p[7]);
    func_003058a0(0);
    sceGsExecLoadImage(&D_01d9e3f0, p + 16);
}
}  // namespace n001e5220

// 001e52b8 (was src/anon/batch_w109.cpp)
namespace n001e52b8 {
// 0x001a9560: definition moved into src/anon/unit_001a9130.cpp

// ---- f5.cpp
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036edb0[] asm("D_0036edb0");
extern char D_0036edc0[] asm("D_0036edc0");
extern char D_0036ede0[] asm("D_0036ede0");
extern u8 D_01d9e450[] asm("D_01d9e450");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(void*, void*) asm("sceGsExecLoadImage");
static inline void assert_fail_1e52b8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
struct NoTail52b8 { ~NoTail52b8() {} };
/*TARGET 001e52b8*/
void func_001e52b8(u8* p, s16 off) asm("func_001e52b8");
void func_001e52b8(u8* p, s16 off) {
    NoTail52b8 nt;
    s16 v = *(s16*)(p + 2);
    if (!p) assert_fail_1e52b8(D_0036edb0, D_0036e9d0, 1511);
    if (v == 0) return;
    if (v >= 15872) v = v + off - 15872;
    else v = v + off - 11776;
    if (v < 15616) assert_fail_1e52b8(D_0036edc0, D_0036e9d0, 1532);
    if (v + *(s16*)(p + 30) > 16384) assert_fail_1e52b8(D_0036ede0, D_0036e9d0, 1533);
    switch (*(s16*)(p + 6)) {
    case 19:
        sceGsSetDefLoadImage(D_01d9e450, v, 1, 0, 0, 0, 16, 16);
        break;
    case 20:
        sceGsSetDefLoadImage(D_01d9e450, v, 1, 0, 0, 0, 8, 2);
        break;
    default:
        return;
    }
    func_003058a0(0);
    sceGsExecLoadImage(D_01d9e450, p + *(s32*)(p + 24) + 32);
}
}  // namespace n001e52b8

// 001e5458 (was src/anon/batch_w330.c)
namespace n001e5458 {
/* partMng.c asserts (file name string D_0036e9d0) */
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);        /* "RyjAssertion failed: %s\n" */
    func_002fdfc8(D_0036e998, f, l);     /* "   File %s, Line %u\n" */
    asm volatile("break");
}
static inline void ryjAssert5(const char* f1, const char* e, const char* f2, const char* f, s32 l) {
    func_002fdfc8(f1, e);  // device_vprintf_va
    func_002fdfc8(f2, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
#define ASSERT5(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)
void* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
s32* func_001e3660(void*, s32) asm("_Z13func_001e3660ji");
/*AMBIG-MULTI*/ /* func_001e5458 */
extern "C" char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ed60[];
void func_001e5220(u32, s32) asm("func_001e5220");
/*TARGET 001e5458*/
void func_001e5458(u32* p, u8* bits, s16 k) asm("func_001e5458");
void func_001e5458(u32* p, u8* bits, s16 k) {
    s32 n, i;
    u32 m = 0;
    ASSERT(p != 0, D_0036ed60, 1565);
    p = (u32*)func_001e3660(func_001e3650(p), 1);
    n = *p++;
    for (i = 0; i < n; i++) {
        u32 v = *p++;
        s32 by = i >> 3;
        s32 bi = i & 7;
        ASSERT5(!(v & 0xf), D_0036ec40, 1578);
        ASSERT5(by < 16, D_0036ec58, 1579);
        ASSERT5(by >= 0, D_0036ec70, 1579);
        if (bi == 0) m = bits[by];
        if ((u8)(m & 1)) func_001e5220(v, k);
        m >>= 1;
    }
}
}  // namespace n001e5458

// 001e5610 (was src/anon/batch_w252.cpp)
namespace n001e5610 {
s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036ed60[], D_0036e998[], D_0036e9d0[], D_0036ec40[];
void* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
s32* func_001e3660(void*, s32) asm("func_001e3660");
void func_001e5220(s32, s32) asm("func_001e5220");
static inline void assert_fail_1e5610(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e5610*/
void func_001e5610(s32* p) asm("func_001e5610");
void func_001e5610(s32* p) {
    s32 v;
    if (!p) assert_fail_1e5610(D_0036ed60, D_0036e9d0, 1596);
    p = func_001e3660(func_001e3650(p), 1);
    s32 n = *p++;
    for (s32 i = 0; i < n; i++) {
        v = *p++;
        if (v & 0xf) assert_fail_1e5610(D_0036ec40, D_0036e9d0, 1607);
        func_001e5220(v, 0x2800);
    }
}
}  // namespace n001e5610

// 001e5718 (was src/anon/batch_w330.c)
namespace n001e5718 {
/* partMng.c asserts (file name string D_0036e9d0) */
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[];
static inline void ryjAssert5(const char* f1, const char* e, const char* f2, const char* f, s32 l) {
    func_002fdfc8(f1, e);  // device_vprintf_va
    func_002fdfc8(f2, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERT5(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)
void* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
s32* func_001e3660(void*, s32) asm("_Z13func_001e3660ji");
/*AMBIG-MULTI*/ /* func_001e5458 */
extern "C" char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ed60[];
/* func_001e5718 */
void func_001e52b8(u32, s32) asm("func_001e52b8");
/*TARGET 001e5718*/
void func_001e5718(u32* p, u8* bits, s16 k) asm("func_001e5718");
void func_001e5718(u32* p, u8* bits, s16 k) {
    s32 n, i;
    u32 m = 0;
    if (p) {
        p = (u32*)func_001e3660(func_001e3650(p), 1);
        n = *p;
        asm("" : "+r"(p)); /* keeps the count pointer and the loop pointer apart */
        p++;
        for (i = 0; i < n; i++) {
            u32 v = *p++;
            s32 by = i >> 3;
            s32 bi = i & 7;
            ASSERT5(!(v & 0xf), D_0036ec40, 1638);
            ASSERT5(by < 16, D_0036ec58, 1639);
            ASSERT5(by >= 0, D_0036ec70, 1639);
            if (bi == 0) m = bits[by];
            if ((u8)(m & 1)) func_001e52b8(v, k);
            m >>= 1;
        }
    }
}
}  // namespace n001e5718

// 001e5898 (was src/anon/batch_w330.c)
namespace n001e5898 {
/* partMng.c asserts (file name string D_0036e9d0) */
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*AMBIG-MULTI*/ // device_vprintf_va
extern "C" char D_0036e978[], D_0036e998[], D_0036e9d0[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);        /* "RyjAssertion failed: %s\n" */
    func_002fdfc8(D_0036e998, f, l);     /* "   File %s, Line %u\n" */
    asm volatile("break");
}
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
void* func_001e3650(void*) asm("func_001e3650");
// ptr_add4
s32* func_001e3660(void*, s32) asm("_Z13func_001e3660ji");
/*AMBIG-MULTI*/ /* func_001e5458 */
extern "C" char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ed60[];
/* func_001e5718 */
void func_001e52b8(u32, s32) asm("func_001e52b8");
/*TARGET 001e5898*/
/* func_001e5898 */
void func_001e5898(u32* p) asm("func_001e5898");
/* func_001e5898 */
void func_001e5898(u32* p) {
    s32 n, i;
    if (p) {
        p = (u32*)func_001e3660(func_001e3650(p), 1);
        n = *p;
        asm("" : "+r"(p)); /* keeps the count pointer and the loop pointer apart */
        p++;
        for (i = 0; i < n; i++) {
            u32 v = *p++;
            ASSERT(!(v & 0xf), D_0036ec40, 1669);
            func_001e52b8(v, 0x3d00);
        }
    }
}
}  // namespace n001e5898

// 001e5970 (was src/anon/auto80_199_queue.cpp)
namespace n001e5970 {
/*TARGET 001e5970*/
void func_001e5970(u32 a0) asm("_Z13func_001e5970j");
void func_001e5970(u32 a0) {  // obj_clear_header
    struct VC { u32 dpd; u32 pad4; u64 mask; s8 start; u8 num; u8 used; };
    VC* p = (VC*)a0;
    p->used = 0;
    p->dpd = 0;
    p->mask = 0;
    p->num = 0;
    p->start = -1;
}
}  // namespace n001e5970

// 001e5990 (was src/anon/auto80_199_queue.cpp)
namespace n001e5990 {
void func_001e5970(u32 a0) asm("_Z13func_001e5970j");
/*TARGET 001e5990*/
void func_001e5990(u32 a0) asm("_Z13func_001e5990j");
void func_001e5990(u32 a0) {
    s32 s0 = (s32)a0;
    s32 s1 = (s32)a0 + 816;
    s32 s2 = (s32)a0;
    while (1) {
        func_001e5970((u32)s0);  // obj_clear_header
        s0 += 24;
        if (s0 < s1) {
            continue;
        }
        break;
    }

    s0 = s2 + 816;
    s1 = 19;
    do {
        u32 a0_call = (u32)s0;
        s1 -= 1;
        func_001e5970(a0_call);  // obj_clear_header
        s0 += 24;
    } while ((s32)s1 >= 0);
}
}  // namespace n001e5990

// 001e5a00 (was src/anon/batch_w3849_nsa.c)
namespace n001e5a00 {
typedef struct { char* pchDpd; u32 pad4; u64 mask; s8 chBlockStart; s8 chBlockNum; u8 used; u8 pad[5]; } VCache;
typedef struct { u8 pad[136]; char* pchDpd; u8 pad2[7]; u8 nParId; } ParInfo;
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
extern char D_0036ea98[] asm("D_0036ea98");
extern char D_0036ee10[] asm("D_0036ee10");
extern char D_0036ee28[] asm("D_0036ee28");
extern char D_0036ee38[] asm("D_0036ee38");
extern char D_0036ee58[] asm("D_0036ee58");
extern char D_0036ee80[] asm("D_0036ee80");
extern char D_0036ee98[] asm("D_0036ee98");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e2ad8(const char*, const char*, s32, const char*) asm("func_001e2ad8");
void func_001e5970(VCache*) asm("func_001e5970");
static inline void ryj001e5a00(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT(c, s, line) if (!(c)) ryj001e5a00(s, D_0036e9d0, line)
#define BLOCK_MAX 40
/*TARGET 001e5a00*/
s32 func_001e5a00(VCache* pVcache, s32 nBlockMax, ParInfo* pPar, u8 nBlock) asm("func_001e5a00");
s32 func_001e5a00(VCache* pVcache, s32 nBlockMax, ParInfo* pPar, u8 nBlock)
{
    s32 nMax = BLOCK_MAX;
    u8 abUse[nMax];
    char* pchDpd = pPar->pchDpd;
    s32 nParId = pPar->nParId;
    s32 i, j, nCnt, nStartBlock, nBest;
    VCache* pBest;
    VCache* pV;
    VCache* pE;
    VCache* pB;
    ASSERT(nBlockMax <= BLOCK_MAX, D_0036ee10, 1765);
    ASSERT(0 != pchDpd, D_0036ee28, 1766);
    ASSERT(0 <= nParId && nParId < 64, D_0036ee38, 1767);
    for (i = 0; i < nBlockMax; i++) {
        if (pVcache[i].used && pchDpd == pVcache[i].pchDpd) {
            s32 bit = (pVcache[i].mask >> nParId) & 1;
            if (bit) return -1;
            pVcache[i].mask |= (u64)1 << nParId;
            return pVcache[i].chBlockStart;
        }
    }
    for (i = 0; i < BLOCK_MAX; i++) abUse[i] = 0;
    for (i = 0; i < nBlockMax; i++) {
        pV = &pVcache[i];
        if (pV->used) {
            for (j = 0; j < pV->chBlockNum; j++) {
                ASSERT((pV->chBlockStart + j) < BLOCK_MAX, D_0036ee58, 1795);
                abUse[pV->chBlockStart + j] = 1;
            }
        }
    }
    nCnt = 0;
    nStartBlock = -1;
    for (i = 0; i < nBlockMax; i++) {
        if (abUse[i]) {
            nCnt = 0;
        } else {
            nCnt++;
            if (nCnt == nBlock) {
                nStartBlock = i - nBlock + 1;
                ASSERT(0 <= nStartBlock, D_0036ee98, 1812);
                break;
            }
        }
    }
    pBest = 0;
    if (nStartBlock > 0) {
        for (i = 0; i < nBlockMax; i++) {
            if (!pVcache[i].used) {
                pVcache[i].used = 1;
                pVcache[i].pchDpd = pchDpd;
                pVcache[i].mask = (u64)1 << nParId;
                pVcache[i].chBlockNum = nBlock;
                pVcache[i].chBlockStart = nStartBlock;
                return nStartBlock;
            }
        }
        func_001e2ad8(D_0036ea98, D_0036e9d0, 1835, D_0036ee80);
        pBest = 0;
    }
    nBest = -1;
    for (i = 0; i < nBlockMax; i++) {
        pB = &pVcache[i];
        if (pB->used) {
            if (nBlock == pB->chBlockNum) {
                pB->pchDpd = pchDpd;
                pB->mask = (u64)1 << nParId;
                return pB->chBlockStart;
            }
            if (nBlock < pB->chBlockNum) {
                if (pBest == 0 || pB->chBlockNum - nBlock < nBest) {
                    nBest = pB->chBlockNum - nBlock;
                    pBest = pB;
                }
            }
        }
    }
    if (pBest) {
        pBest->pchDpd = pchDpd;
        pBest->chBlockNum = nBlock;
        pBest->mask = (u64)1 << nParId;
        return pBest->chBlockStart;
    }
    for (i = 0; i < nBlockMax; i++) {
        pE = &pVcache[i];
        if (pE->used && pE->chBlockStart < nBlock) func_001e5970(pE);
    }
    for (i = 0; i < nBlockMax; i++) {
        if (!pVcache[i].used) {
            pVcache[i].used = 1;
            pVcache[i].pchDpd = pchDpd;
            pVcache[i].mask = (u64)1 << nParId;
            pVcache[i].chBlockNum = nBlock;
            pVcache[i].chBlockStart = 0;
            return 0;
        }
    }
    ASSERT(0, D_0036ea98, 1903);
    return -1;
}
}  // namespace n001e5a00

// 001e5f40 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e5f40 {
s32 func_001e5a00(...) asm("func_001e5a00");
/*TARGET 001e5f40*/
void func_001e5f40(u32 a0, u32 a1) asm("_Z13func_001e5f40jj");
void func_001e5f40(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 a3 = (u32)(*(u8*)((u32)a1 + (s32)(145)));
    s32 v0 = func_001e5a00(a0, 34u, s0, a3);
    if (v0 < 0) {
        *(u16*)((u32)s0 + (s32)(156)) = (u16)0u;
        return;
    }
    u32 t7 = (u32)(v0 << 7);
    t7 = (u32)((s32)t7 + (11264));
    *(u16*)((u32)s0 + (s32)(156)) = (u16)t7;
}
}  // namespace n001e5f40

// 001e5f88 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e5f88 {
s32 func_001e5a00(...) asm("func_001e5a00");
/*TARGET 001e5f88*/
void func_001e5f88(u32 a0, u32 a1) asm("_Z13func_001e5f88jj");
void func_001e5f88(u32 a0, u32 a1) {
    a0 = (u32)((s32)a0 + (816));
    u32 s0 = a1;
    u32 a3 = (u32)(*(u8*)((u32)a1 + (s32)(146)));
    s32 v0 = func_001e5a00(a0, 20u, s0, a3);
    if (v0 < 0) {
        *(u16*)((u32)s0 + (s32)(158)) = (u16)0u;
        return;
    }
    u32 t7 = (u32)(v0 << 5);
    t7 = (u32)((s32)t7 + (15744));
    *(u16*)((u32)s0 + (s32)(158)) = (u16)t7;
}
}  // namespace n001e5f88

// 001e5fd8 (was src/anon/batch_w1726_g.cpp)
namespace n001e5fd8 {
/*TARGET 001e5fd8*/
void func_001e5fd8(void) asm("func_001e5fd8");
void func_001e5fd8(void) {
  *(volatile u32*)0x10000010 |= 0x83;
  *(volatile u32*)0x10000000 = 0;
}
}  // namespace n001e5fd8

// 001e6000 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e6000 {
/*TARGET 001e6000*/
void func_001e6000(u32 a0) asm("_Z13func_001e6000j");
void func_001e6000(u32 a0) {  // obj_dec_timer
    u32 t6 = (u32)(*(u8*)((u32)a0 + (s32)(12)));
    *(u32*)((u32)a0 + (s32)(4)) = 0u;
    t6 = (u32)((s32)t6 + (-1));
    *(u32*)((u32)a0 + (s32)(0)) = 0u;
    *(u8*)((u32)a0 + (s32)(12)) = (u8)t6;
    t6 = (u32)(t6 & 0xffu);
    *(u8*)((u32)a0 + (s32)(13)) = (u8)0u;
    if (t6 == 255u) {
        *(u32*)((u32)a0 + (s32)(8)) = 0u;
        *(u8*)((u32)a0 + (s32)(12)) = (u8)60u;
    }
}
}  // namespace n001e6000

// 001e6038 (was src/anon/batch_w49.cpp)
namespace n001e6038 {
// 00199468: moved to src/anon/unit_001991a8.cpp

struct NoTail { ~NoTail() {} };
void func_001e6000(u8*) asm("func_001e6000");
/*TARGET 001e6038*/
// obj_dec_timer
void func_001e6038(u8* p) asm("func_001e6038");
// obj_dec_timer
void func_001e6038(u8* p) {
    NoTail g;
    func_001e6000(p + 176);  // obj_dec_timer
    func_001e6000(p + 192);  // obj_dec_timer
    func_001e6000(p + 208);  // obj_dec_timer
    func_001e6000(p + 224);  // obj_dec_timer
    func_001e6000(p + 240);  // obj_dec_timer
    func_001e6000(p + 256);  // obj_dec_timer
    func_001e6000(p + 272);  // obj_dec_timer
    func_001e6000(p + 288);  // obj_dec_timer
    func_001e6000(p + 304);  // obj_dec_timer
    func_001e6000(p + 320);  // obj_dec_timer
}
}  // namespace n001e6038

// 001e60b0 (was src/anon/batch_w34.cpp)
namespace n001e60b0 {
// alloc_336_align_171
void func_001e6000(void*) asm("func_001e6000");
struct Pair72 {
    u32 a;
    s32 id;
    u8 pad[32];
    u8 x[16];
    u8 y[16];
};
extern Pair72 D_00354bf0[] asm("D_00354bf0");
/*TARGET 001e60b0*/
// 0x001d18c0: definition moved into src/anon/unit_001d14e0.cpp

void func_001e60b0(void) asm("func_001e60b0");
// 0x001d18c0: definition moved into src/anon/unit_001d14e0.cpp

void func_001e60b0(void) {
    for (Pair72* e = D_00354bf0; e->id >= 0; e++) {
        func_001e6000(e->x);  // obj_dec_timer
        func_001e6000(e->y);  // obj_dec_timer
    }
}
}  // namespace n001e60b0

// 001e6100 (was src/anon/batch_w3743.cpp)
namespace n001e6100 {
void func_002fee78(char*, char*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_002fee78");
extern char D_0036eeb0[] asm("D_0036eeb0");
extern char D_01d9e4b0[] asm("D_01d9e4b0");
/*TARGET 001e6100*/
/* Empty asm ties keep the two lo_sum addresses of the buffer apart and place the second one before the load. */
char* func_001e6100(u8* p) asm("func_001e6100");
/* Empty asm ties keep the two lo_sum addresses of the buffer apart and place the second one before the load. */
char* func_001e6100(u8* p) {
    char* a = D_01d9e4b0; asm("" : "+r"(a));
    char* r = D_01d9e4b0;
    u8* q = *(u8**)(p + 0x8c);
    asm("" : "+r"(r) : "r"(p));
    func_002fee78(a, D_0036eeb0,
        *(s32*)(p + 0x114) + *(s32*)(p + 0x104),
        *(s32*)(p + 0x118) + *(s32*)(p + 0x108),
        *(s32*)(p + 0xc4), *(s32*)(p + 0xd4), *(s32*)(p + 0xe4), *(s32*)(p + 0xf4),
        *(s32*)(p + 0x144), *(s32*)(q + 0xf0) / 1024);
    return r;
}
}  // namespace n001e6100

// .rodata 0x36ed60-0x36ef1c (strings the code reads as extern D_)
extern const u32 R_0036ed60[6] asm("D_0036ed60") __attribute__((aligned(4))) = { 0x4c4c554e, 0x203d2120, 0x44686370, 0x61446470, 0x6174, 0x0 };
extern const u32 R_0036ed78[8] asm("D_0036ed78") __attribute__((aligned(4))) = { 0x3d3d2030, 0x6e692820, 0x63702974, 0x64704468, 0x61746144, 0x31202520, 0x36, 0x0 };
extern const u32 R_0036ed98[6] asm("D_0036ed98") __attribute__((aligned(4))) = { 0x3d3d2030, 0x6e692820, 0x63702974, 0x61645068, 0x25206174, 0x363120 };
extern const u32 R_0036edb0[4] asm("D_0036edb0") __attribute__((aligned(4))) = { 0x4c4c554e, 0x203d2120, 0x78655470, 0x0 };
extern const u32 R_0036edc0[8] asm("D_0036edc0") __attribute__((aligned(4))) = { 0x54554c43, 0x4d4d4f43, 0x535f4e4f, 0x54524154, 0x203d3c20, 0x6c436873, 0x70624474, 0x0 };
extern const u32 R_0036ede0[12] asm("D_0036ede0") __attribute__((aligned(4))) = { 0x6c436873, 0x70624474, 0x6554702b, 0x733e2d78, 0x746c4368, 0x6d617256, 0x657a6953, 0x203d3c20, 0x54554c43, 0x444e455f, 0x0, 0x0 };
extern const u32 R_0036ee10[6] asm("D_0036ee10") __attribute__((aligned(4))) = { 0x6f6c426e, 0x614d6b63, 0x3d3c2078, 0x4f4c4220, 0x4d5f4b43, 0x5841 };
extern const u32 R_0036ee28[4] asm("D_0036ee28") __attribute__((aligned(4))) = { 0x4c4c554e, 0x203d2120, 0x44686370, 0x6470 };
extern const u32 R_0036ee38[8] asm("D_0036ee38") __attribute__((aligned(4))) = { 0x3d3c2030, 0x61506e20, 0x20644972, 0x6e202626, 0x49726150, 0x203c2064, 0x3436, 0x0 };
extern const u32 R_0036ee58[10] asm("D_0036ee58") __attribute__((aligned(4))) = { 0x63567028, 0x65686361, 0x68633e2d, 0x636f6c42, 0x6174536b, 0x6a2b7472, 0x203c2029, 0x434f4c42, 0x414d5f4b, 0x58 };
extern const u32 R_0036ee80[6] asm("D_0036ee80") __attribute__((aligned(4))) = { 0x20746f4e, 0x646e6966, 0x41525620, 0x4341434d, 0x214548, 0x0 };
extern const u32 R_0036ee98[6] asm("D_0036ee98") __attribute__((aligned(4))) = { 0x3d3c2030, 0x74536e20, 0x42747261, 0x6b636f6c, 0x0, 0x0 };
extern const u32 R_0036eeb0[16] asm("D_0036eeb0") __attribute__((aligned(4))) = { 0x30252e41, 0x252f6432, 0x20643230, 0x30252e54, 0x43206432, 0x3230252e, 0x2e442064, 0x64323025, 0x252e4f20, 0x20643230, 0x30252e50, 0x206b6432, 0x30252e4d, 0xa6b6433, 0x0, 0x0 };
extern const u32 R_0036eef0[11] asm("D_0036eef0") __attribute__((aligned(4))) = { 0x253a3450, 0x64252f64, 0x33502020, 0x2f64253a, 0x20206425, 0x3a504853, 0x252f6425, 0x57202064, 0x3a4b524f, 0x66322e25, 0xa2525 };

// 001e6188 (was src/anon/batch_w325.c)
namespace n001e6188 {
extern s32 D_01da8cd0[8] asm("D_01da8cd0");
extern "C" s32 D_00352c40, D_01d9e6c4;
extern "C" char D_01d9e5b0[], D_0036eef0[];
u64 func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 wsprintf_002fee78(char*, const char*, ...) asm("_Z16wtarget_002fee78jjjj");
/*TARGET 001e6188*/
char* func_001e6188(void) asm("func_001e6188");
char* func_001e6188(void) {
    char* buf = D_01d9e5b0;
    s32* s = D_01da8cd0;
    u64 d = func_00313b80((f32)D_01d9e6c4 / (f32)D_00352c40 * 100.0f);  // float_to_double
    wsprintf_002fee78(buf, D_0036eef0, s[4], s[0], s[5], s[1], s[6], s[2], d);
    return buf;
}
}  // namespace n001e6188

// 001e6230 (gap, written for the unit)
namespace n001e6230 {
extern "C" s32 D_01d9e6c4, D_00352c40;
void func_001e6230(s32* a, s32* b) asm("func_001e6230");
void func_001e6230(s32* a, s32* b) { *a = D_01d9e6c4; *b = D_00352c40; }
}  // namespace n001e6230

// 001e6250 (was src/anon/batch_w8.cpp)
namespace n001e6250 {
void func_001e60b0(void) asm("func_001e60b0");
struct S354690 { u32 a; s32 b; };
extern S354690 D_00354690 asm("D_00354690");
/*TARGET 001e6250*/
void func_001e6250(void) asm("func_001e6250");
void func_001e6250(void) {
    func_001e60b0();
    D_00354690.a = 0;
    D_00354690.b = -1;
}
}  // namespace n001e6250

// 001e6280 (was src/anon/batch_wcx2_nsi.c)
namespace n001e6280 {
/* 001e6280: partMng particle update (assert line 2137). */
typedef struct { s32 start; s32 cur; s32 max; } PartTime1e6280;
typedef struct { u8 pad0[248]; u8 hide; } PartOwn1e6280;
typedef struct {
    u8 pad0[88];
    void* p88;
    u8 pad1[96 - 92];
    s32 steps;
    u8 pad2[134 - 100];
    u16 flags;
    s32 id;
    PartOwn1e6280* own;
    u8 on;
    u8 pad3[147 - 145];
    u8 sub;
    u8 pad4[152 - 148];
    f32 acc;
    u8 pad5[164 - 156];
    f32 wait;
    u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24;
    u8 pad6[208 - 176];
    PartTime1e6280 tUpdate;
    u8 pad7[256 - 220];
    PartTime1e6280 tTotal;
    u8 pad8[288 - 268];
    PartTime1e6280 tDraw;
} Part1e6280;
typedef struct { s32 id; s32 sub; } PartLast1e6280;
extern Part1e6280* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern f32 D_00352be0 asm("D_00352be0");
extern PartLast1e6280 D_00354690 asm("D_00354690");
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9c0[] asm("D_0036e9c0");
extern char D_0036e9d0[] asm("D_0036e9d0");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e6038(Part1e6280*) asm("func_001e6038");
void func_001e41e0(Part1e6280*) asm("func_001e41e0");
void func_001e8bb8(Part1e6280*) asm("func_001e8bb8");
s32 func_001e8c28(Part1e6280*, s32) asm("func_001e8c28");
void func_001e7cc0(Part1e6280*) asm("func_001e7cc0");
static inline void timeEnd1e6280(PartTime1e6280* t)
{
    t->cur += *(volatile s32*)0x10000000 - t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void timeSub1e6280(PartTime1e6280* t)
{
    t->cur -= t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void ryjAssert1e6280(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap */
}
/*TARGET 001e6280*/
s32 func_001e6280(Part1e6280* p, s32 force) asm("func_001e6280");
s32 func_001e6280(Part1e6280* p, s32 force)
{
    s32 ret = 1;
    s32 stop;
    s32 same;
    if (!p) ryjAssert1e6280(D_0036e9c0, D_0036e9d0, 2137);
    D_01d9e6e0 = p;
    func_001e6038(p);
    if (!D_01d9ea9c && !D_01d9e6e0->stopA && !D_01d9e6e0->stopB && !(p->flags & 8)) {
        if (0.0f < p->wait) p->wait -= D_00352be0;
    }
    if (0.0f < p->wait) return ret;
    if (p->p88 && !p->dead && force) p->on = 1;
    else p->on = 0;
    if (p->on && p->own->hide) goto done;
    p->tDraw.start = 0;
    p->tTotal.start = *(volatile s32*)0x10000000;
    p->tUpdate.start = *(volatile s32*)0x10000000;
    same = 0;
    if (D_00354690.id == p->id) same = D_00354690.sub == p->sub;
    if (!same) func_001e41e0(p);
    p->acc += D_00352be0;
    if (2.0f <= p->acc) {
        p->stopB = 0;
        stop = 0;
        while (__builtin_expect(p->steps > 0, 0)) {
            func_001e8bb8(p);
            if (func_001e8c28(p, 0)) {
                func_001e7cc0(p);
                stop = 1;
                ret = 0;
                break;
            }
            p->steps--;
        }
        if (!stop) {
            for (p->acc -= 2.0f; 2.0f <= p->acc; p->acc -= 2.0f) {
                func_001e8bb8(p);
                if (func_001e8c28(p, 0)) {
                    func_001e7cc0(p);
                    stop = 1;
                    ret = 0;
                    break;
                }
            }
        }
        if (!stop) func_001e8bb8(p);
    } else {
        p->stopB = 1;
        func_001e8bb8(p);
    }
    D_00354690.id = p->id;
    D_00354690.sub = p->sub;
    timeEnd1e6280(&p->tUpdate);
    timeEnd1e6280(&p->tTotal);
    timeSub1e6280(&p->tDraw);
done:
    D_01d9e6e0 = 0;
    return ret;
}
}  // namespace n001e6280

// 001e65c8 (was src/anon/misc_1.cpp)
namespace n001e65c8 {
/*TARGET 001e65c8*/
void func_001e65c8(void* self) asm("_Z13func_001e65c8Pv");
void func_001e65c8(void* self) {}
}  // namespace n001e65c8

// 001e65d0 (was src/anon/batch_w42.cpp)
namespace n001e65d0 {
// 001e65d0
extern u8 D_00354698[] asm("D_00354698");
extern u32 D_00354648 asm("D_00354648");
extern u32 D_003591c8 asm("D_003591c8");
extern u8 D_00354650[] asm("D_00354650");
void func_001e5990(void*) asm("func_001e5990");
void func_001e5610(u32) asm("func_001e5610");
void func_001e5898(u32) asm("func_001e5898");
void sceGsSyncPath(u32, u32) asm("sceGsSyncPath");
void FlushCache(s32) asm("FlushCache");
void func_002f3918(u32, void*) asm("func_002f3918");
/*TARGET 001e65d0*/
void func_001e65d0(void) asm("func_001e65d0");
void func_001e65d0(void)
{
    func_001e5990(D_00354698);
    func_001e5610(D_00354648);
    func_001e5898(D_00354648);
    sceGsSyncPath(0, 0);
    FlushCache(0);
    func_002f3918(D_003591c8, D_00354650);
}
}  // namespace n001e65d0

// 001e6630 (was src/anon/tiny.cpp)
namespace n001e6630 {
// alloc_aligned16
void func_0020dff0(void*) asm("_Z13func_0020dff0Pv");
/*TARGET 001e6630*/
void func_001e6630(BD_VALUE* bd) asm("_Z13func_001e6630P8BD_VALUE");
void func_001e6630(BD_VALUE* bd) { func_0020dff0(bd); }
}  // namespace n001e6630

// 001e6648 (was src/anon/batch_w17.cpp)
namespace n001e6648 {
extern u32 D_01d9e6b4 asm("D_01d9e6b4");
extern u8 D_01d9e6b0 asm("D_01d9e6b0");
void func_001e65d0(void) asm("func_001e65d0");
void func_001e6630(void) asm("func_001e6630");
void func_0021c9b0(void) asm("func_0021c9b0");
/*TARGET 001e6648*/
void func_001e6648(void) asm("func_001e6648");
void func_001e6648(void) {
    func_001e65d0();
    func_001e6630();
    func_0021c9b0();
    D_01d9e6b4 = 0;
    D_01d9e6b0 = 0;
}
}  // namespace n001e6648

// 001e6688 (was src/anon/batch_w330.c)
namespace n001e6688 {
/* func_001e6688 */
typedef struct { s32 a, b, c, d, e, f, g, h; } S8_01da8cd0;
typedef struct { s32 x, y; } S2_00354690;
extern S8_01da8cd0 D_01da8cd0 asm("D_01da8cd0");
extern S2_00354690 D_00354690 asm("D_00354690");
void func_001e6648(void) asm("func_001e6648");
void func_001e2b68(void) asm("func_001e2b68");
/*TARGET 001e6688*/
void func_001e6688(void) asm("func_001e6688");
void func_001e6688(void) {
    D_01da8cd0.b = 0; D_01da8cd0.f = 0; D_01da8cd0.e = 0; D_01da8cd0.c = 0;
    D_01da8cd0.g = 0; D_01da8cd0.a = 0; D_01da8cd0.d = 0; D_01da8cd0.h = 0;
    D_00354690.y = -1; D_00354690.x = 0;
    func_001e6648();
    func_001e2b68();
    asm volatile(""); /* keeps the call a jal (no sibcall), as the original */
}
}  // namespace n001e6688

// 001e66e8 (was src/anon/batch_w2333_gnsa.c)
namespace n001e66e8 {
/* Plain C (partMng.c), built with -g and without strict aliasing (-g makes no difference here). */

/* 001e66e8: partMng particle draw (assert line 2311): timers, record setup, GS flush, update and draw. */
typedef struct { s32 start; s32 cur; s32 max; } PartTime1e66e8;
typedef struct { u8 pad0[176]; u8 m176[72]; u8 hide; } PartOwn1e66e8;
typedef struct {
    u8 pad0[134];
    u16 flags;
    s32 id;
    PartOwn1e66e8* own;
    u8 on;
    u8 b145;
    u8 pad146;
    u8 sub;
    u8 pad148[4];
    union { u64 gs; struct { u32 lo; s16 h156; s16 h158; } h; } u;
    u8 pad160[4];
    f32 wait;
    u8 pad168[192 - 168];
    PartTime1e66e8 tSetup;
    u8 pad204[224 - 204];
    PartTime1e66e8 tUpdate;
    u8 pad236[4];
    PartTime1e66e8 tDraw2;
    u8 pad252[272 - 252];
    PartTime1e66e8 tTotal;
    u8 pad284[304 - 284];
    PartTime1e66e8 tDraw;
    u8 pad316[4];
    PartTime1e66e8 tPacket;
} Part1e66e8;
typedef struct { s32 id; s32 sub; } PartLast1e66e8;
extern Part1e66e8* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern s32 D_01d9eaa8 asm("D_01d9eaa8");
extern s32 D_01d9eaac asm("D_01d9eaac");
extern PartLast1e66e8 D_00354690 asm("D_00354690");
extern u8 D_00354698[] asm("D_00354698");
extern u8 D_00354650[] asm("D_00354650");
extern s32 D_003591c8 asm("D_003591c8");
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9c0[] asm("D_0036e9c0");
extern char D_0036e9d0[] asm("D_0036e9d0");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e41e0(Part1e66e8*) asm("func_001e41e0");
s32 func_001e8c28(Part1e66e8*, s32) asm("func_001e8c28");
void func_001e7cc0(Part1e66e8*) asm("func_001e7cc0");
void func_001e5f40(u8*, Part1e66e8*) asm("func_001e5f40");
void func_001e5f88(u8*, Part1e66e8*) asm("func_001e5f88");
void func_001e5458(s32, u8*, s32) asm("func_001e5458");
void func_001e5718(s32, u8*, s32) asm("func_001e5718");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void func_003058a0(s32) asm("func_003058a0");
void func_002f3918(s32, u8*) asm("func_002f3918");
void func_001e3c18(Part1e66e8*) asm("func_001e3c18");
void func_001e2b90() asm("func_001e2b90");
static inline void timeEnd1e66e8(PartTime1e66e8* t)
{
    t->cur += *(volatile s32*)0x10000000 - t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void timeStart1e66e8(PartTime1e66e8* t)
{
    t->start = *(volatile s32*)0x10000000;
}
static inline void timeSub1e66e8(PartTime1e66e8* t)
{
    t->cur -= t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void ryjAssert1e66e8(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap */
}
/*TARGET 001e66e8*/
s32 func_001e66e8(Part1e66e8* p) asm("func_001e66e8");
s32 func_001e66e8(Part1e66e8* p)
{
    s32 ret = 1;
    PartTime1e66e8* td;
    PartTime1e66e8* tt;
    PartTime1e66e8* t;
    PartTime1e66e8* tp;
    if (!p) ryjAssert1e66e8(D_0036e9c0, D_0036e9d0, 2311);
    D_01d9e6e0 = p;
    td = &p->tDraw;
    tt = &p->tTotal;
    td->start = 0;
    tt->start = *(volatile s32*)0x10000000;
    if (0.0f < p->wait) {
        timeSub1e66e8(td);
        timeEnd1e66e8(tt);
        p->flags &= ~8;
        return 1;
    }
    if (p->on) {
        if (p->own->hide) goto done;
        s32 same = 0;
        if (D_00354690.id == p->id) same = D_00354690.sub == p->sub;
        if (!same) func_001e41e0(p);
        if (func_001e8c28(p, 0)) {
            func_001e7cc0(p);
            ret = 0;
        }
        D_00354690.id = p->id;
        D_00354690.sub = p->sub;
    } else {
        s32 same = 0;
        if (D_00354690.id == p->id) same = D_00354690.sub == p->sub;
        if (!same) func_001e41e0(p);
        if (p->b145) {
            func_001e5f40(D_00354698, p);
            func_001e5f88(D_00354698, p);
            PartTime1e66e8* ts = &p->tSetup;
            timeStart1e66e8(ts);
            if (p->u.h.h156) func_001e5458(p->id, p->own->m176, p->u.h.h156);
            if (p->u.h.h158) func_001e5718(p->id, p->own->m176, p->u.h.h158);
            timeEnd1e66e8(ts);
            if (p->u.gs & 0xffffffff00000000ULL) {
                sceGsSyncPath(0, 0);
                func_003058a0(0);
                func_002f3918(D_003591c8, D_00354650);
            }
        } else {
            p->u.h.h156 = 0;
            p->u.h.h158 = 0;
        }
        func_001e3c18(p);
        t = &p->tUpdate;
        timeStart1e66e8(t);
        D_01d9eaa8 = 0;
        D_01d9eaa4 = D_01d9eaac;
        if (func_001e8c28(p, 1)) {
            func_001e7cc0(p);
            ret = 0;
        }
        timeEnd1e66e8(t);
        t = &p->tDraw2;
        timeStart1e66e8(t);
        func_001e2b90();
        timeEnd1e66e8(t);
        D_00354690.id = p->id;
        D_00354690.sub = p->sub;
    }
done:
    timeEnd1e66e8(&p->tTotal);
    timeSub1e66e8(&p->tDraw);
    tp = &p->tPacket;
    tp->start = 0;
    tp->cur += (D_01d9eaa4 - D_01d9eaac) >> 10;
    if (tp->max < tp->cur) tp->max = tp->cur;
    p->flags &= ~8;
    D_01d9e6e0 = 0;
    return ret;
}
}  // namespace n001e66e8

// 001e6af8 (was src/global/misc.cpp)
namespace n001e6af8 {
/*TARGET 001e6af8*/
// 001024a8: printf(void*) (kills a task), moved to src/global/unit_001022c0.cpp

void pppPartDrawEnd() asm("_Z14pppPartDrawEndv");
// 001024a8: printf(void*) (kills a task), moved to src/global/unit_001022c0.cpp

void pppPartDrawEnd() {}
}  // namespace n001e6af8

// 001e6b00 (was src/anon/batch_w63.cpp)
namespace n001e6b00 {
void func_002fde18(void*, s32, s32) asm("func_002fde18");
/*TARGET 001e6b00*/
// 0x001d7f80: definition moved into src/anon/unit_001d7458.cpp

void func_001e6b00(u8* p) asm("func_001e6b00");
// 0x001d7f80: definition moved into src/anon/unit_001d7458.cpp

void func_001e6b00(u8* p) {
    func_002fde18(p, 0, 336);
    f32* f = (f32*)p;
    u32* w = (u32*)p;
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    *(u16*)(p + 134) = 8;
    f[3] = 1.0f;
    f[8] = 1.0f;
    f[9] = 1.0f;
    f[10] = 1.0f;
    f[11] = 1.0f;
    w[4] = 0;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0;
    f[12] = 1.0f;
    f[13] = 1.0f;
    f[14] = 1.0f;
    f[15] = 1.0f;
    f[16] = 1.0f;
    f[17] = 1.0f;
    f[18] = 1.0f;
    f[19] = 1.0f;
}
}  // namespace n001e6b00

// 001e6b90 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e6b90 {
extern u32 D_01d9e6e4 asm("D_01d9e6e4");
void func_001e6b00(...) asm("func_001e6b00");
u32 func_001e7698(...) asm("func_001e7698");
/*TARGET 001e6b90*/
u32 func_001e6b90(void) asm("_Z13func_001e6b90v");
u32 func_001e6b90(void) {
    u32 a0 = D_01d9e6e4;
    u32 s0 = func_001e7698(a0, 336u);  // alloc_aligned16
    if (s0 != 0u) {
        func_001e6b00(s0);
    }
    return s0;
}
}  // namespace n001e6b90

// 001e6bd8 (gap, written for the unit)
namespace n001e6bd8 {
struct Fl { u16 a : 1; u16 b : 1; u16 rest : 14; };
struct Obj86 { u8 pad[134]; Fl f; };
void func_001e6bd8(Obj86* o) asm("func_001e6bd8");
void func_001e6bd8(Obj86* o) { if (o->f.a) { o->f.a = 0; o->f.b = 1; } }
}  // namespace n001e6bd8

// 001e6c00 (was src/anon/batch_w18.cpp)
namespace n001e6c00 {
extern void* D_01d9e6e4 asm("D_01d9e6e4");
void func_002fde18(void*, u32, u32) asm("func_002fde18");
u8 func_001e7798(void*, void*) asm("func_001e7798");
/*TARGET 001e6c00*/
u8 func_001e6c00(void* p) asm("func_001e6c00");
u8 func_001e6c00(void* p) {  // alloc_336_align_171
    func_002fde18(p, 171, 336);
    return func_001e7798(D_01d9e6e4, p);
}
}  // namespace n001e6c00

// 001e6c40 (was src/anon/batch_w65.cpp)
namespace n001e6c40 {
// Assertion "pMng"-style failure prints the message and file/line, then breaks.
extern char D_0036e978[] asm("D_0036e978");
extern char D_0036ef28[] asm("D_0036ef28");
extern char D_0036e998[] asm("D_0036e998");
extern char D_0036e9d0[] asm("D_0036e9d0");
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
u32 func_001e3690(void*) asm("func_001e3690");
void func_001e8048(void*, u32, s32) asm("func_001e8048");
/*TARGET 001e6c40*/
s32 func_001e6c40(u8* p, u32 a, u32 b, u32 c, f32 f) asm("func_001e6c40");
s32 func_001e6c40(u8* p, u32 a, u32 b, u32 c, f32 f) {
    *(u32*)(p + 136) = a;
    p[147] = b;
    *(u32*)(p + 148) = c;
    *(f32*)(p + 164) = f;
    *(u32*)(p + 160) = 0;
    u32 r = func_001e3690(p);
    if (!r) {
        func_002fdfc8(D_0036e978, D_0036ef28);  // device_vprintf_va
        func_002fdfc8(D_0036e998, D_0036e9d0, 2563);  // device_vprintf_va
        asm volatile("break");
        return 0;
    }
    func_001e8048(p, r, 1);
    return 1;
}
}  // namespace n001e6c40

// 001e6cd0 (was src/anon/batch_w1665.cpp)
namespace n001e6cd0 {
/*TARGET 001e6cd0*/
u32 func_001e6cd0(u32 a) asm("func_001e6cd0");
u32 func_001e6cd0(u32 a) { return a; }
}  // namespace n001e6cd0

// 001e6cd8 (was src/anon/tiny.cpp)
namespace n001e6cd8 {
/*TARGET 001e6cd8*/
u32 func_001e6cd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e6cd8jjjj");
u32 func_001e6cd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (32));
}
}  // namespace n001e6cd8

// 001e6ce8 (was src/anon/tiny.cpp)
namespace n001e6ce8 {
/*TARGET 001e6ce8*/
u32 func_001e6ce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e6ce8jjjj");
u32 func_001e6ce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (16));
}
}  // namespace n001e6ce8

// 001e6cf8 (was src/anon/tiny.cpp)
namespace n001e6cf8 {
/*TARGET 001e6cf8*/
u32 func_001e6cf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e6cf8jjjj");
u32 func_001e6cf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (48));
}
}  // namespace n001e6cf8

// 001e6d08 (was src/anon/auto200_999.cpp)
namespace n001e6d08 {
/*TARGET 001e6d08*/
// 0x001b6038: definition moved into src/anon/unit_001b2780.cpp

u32 func_001e6d08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e6d08jjjj");
// 0x001b6038: definition moved into src/anon/unit_001b2780.cpp

u32 func_001e6d08(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (*(f32 *)(a0 + 164u) > 0.0f) ? 1u : 0u;
}
}  // namespace n001e6d08

// 001e6d28 (was src/anon/tiny.cpp)
namespace n001e6d28 {
/*TARGET 001e6d28*/
void func_001e6d28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e6d28jjjj");
void func_001e6d28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01dau << 16);
    *(u32*)((u32)b + (-5476)) = (u32)a0;
}
}  // namespace n001e6d28

// .rodata 0x36ef28-0x36ef38 (strings the code reads as extern D_)
extern const u32 R_0036ef28[4] asm("D_0036ef28") __attribute__((aligned(4))) = { 0x4c4c554e, 0x203d2120, 0x74616470, 0x61 };

// 001e6d38 (was src/anon/batch_w110.cpp)
namespace n001e6d38 {
struct Arg4 { u32 v; };
struct Obj6 { u8 pad[16]; void* f16; void* f20; void* f24; };
extern "C" u32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf4, D_00352bf8, D_00352bfc;
union C64 { u64 v; struct { u64 lo : 32; u64 hi : 32; } b; };
extern C64 D_00352c00 asm("D_00352c00");
extern "C" u64 D_00352c08, D_00352c10, D_00352c18, D_00352c20, D_00352c28, D_00352c30;
extern "C" u32 D_00352c40, D_00352c44;
extern "C" u8 D_00352c48[], D_00353e48[], D_00354248[];
extern Obj6 D_01d9e6b8 asm("D_01d9e6b8");
extern Obj6* D_01d9e6e4 asm("D_01d9e6e4");
extern "C" u32 D_01d9ea9c, D_01d9eaa0;
extern u8 D_01d9ea40[] asm("D_01d9ea40");
union QU { u128 q; f32 f[4]; };
extern QU D_01d9ea80 asm("D_01d9ea80");
struct NoTail { ~NoTail() {} };
void func_001e2bc8(u32, u32, u32, u32) asm("func_001e2bc8");
void func_001e7650(Obj6*, u32, u32) asm("func_001e7650");
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void func_001e2b50(u32, u32) asm("func_001e2b50");
void func_001e5fd8(void) asm("func_001e5fd8");
/*TARGET 001e6d38*/
// Stores the draw parameters into the global state block, then resets and starts the pass.
void func_001e6d38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, Arg4 s0, u32 s1, u32 s2, u64 c,
                      u64 d0, u64 d1, u64 d2, u64 d3, u64 d4, u64 d5) asm("func_001e6d38");
// Stores the draw parameters into the global state block, then resets and starts the pass.
void func_001e6d38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, Arg4 s0, u32 s1, u32 s2, u64 c,
                      u64 d0, u64 d1, u64 d2, u64 d3, u64 d4, u64 d5) {
    NoTail nt;
    D_00352c00.v = c;
    D_00352be4 = t0;
    D_00352be8 = t1;
    D_00352bec = t2;
    D_00352bf0 = t3;
    D_00352bf4 = s0.v;
    D_00352bf8 = s1;
    D_00352bfc = s2;
    D_00352c08 = d0;
    D_00352c10 = d1;
    D_00352c18 = d2;
    D_00352c20 = d3;
    D_00352c28 = d4;
    *(volatile u64*)&D_00352c30 = d5;
    D_00352c00.b.hi = 0xff000000;
    func_001e2bc8(a0, a1, a2, a3);
    D_01d9ea9c = 0;
    D_00352c40 = a1;
    D_00352c44 = a3;
    func_001e7650(&D_01d9e6b8, a0, a1);
    D_01d9e6b8.f16 = D_00352c48;
    D_01d9e6b8.f20 = D_00353e48;
    D_01d9e6b8.f24 = D_00354248;
    D_01d9e6e4 = &D_01d9e6b8;
    D_01d9eaa0 = 0;
    sceVu0UnitMatrix(D_01d9ea40);  // vu_store_w_splat
    D_01d9ea80.q = 0;
    D_01d9ea80.f[3] = 1.0f;
    func_001e2b50(a2, a3);
    func_001e5fd8();
}
}  // namespace n001e6d38

// 001e6ed8 (was src/anon/batch_w330.c)
namespace n001e6ed8 {
/* func_001e6ed8 */
void f3f98(void*, void*) asm("_Z16sceVu0CopyMatrixjjjj");
void f3d08(void*, void*, void*) asm("_Z15sceVu0MulMatrixjjjj");
void sceVu0InversMatrix(void*, void*) asm("sceVu0InversMatrix");
/*AMBIG-MULTI*/ // convert_vectors_to_scalar
extern "C" u128 D_01d9e730, D_01d9e740, D_01d9e750, D_01d9e760;
extern u128 D_01d9e770[4] asm("D_01d9e770");
extern u128 D_01d9e7b0[4] asm("D_01d9e7b0");
extern "C" u128 D_01d9e7f0, D_01d9e800, D_01d9e810, D_01d9e820;
typedef union { f32 f; u128 q; } FQ;
extern FQ D_01d9e830 asm("D_01d9e830");
extern "C" u128 D_01d9e8c0, D_01d9e8d0, D_01d9e8e0, D_01d9e8f0;
extern u8 D_01d9ea00[] asm("D_01d9ea00");
/*TARGET 001e6ed8*/
void func_001e6ed8(u128* a, u128* b, u128* c, u128* d) asm("func_001e6ed8");
void func_001e6ed8(u128* a, u128* b, u128* c, u128* d) {
    f3f98(D_01d9e770, &D_01d9e730);
    D_01d9e730 = a[0];
    D_01d9e740 = a[1];
    D_01d9e750 = a[2];
    D_01d9e760 = a[3];
    D_01d9e8c0 = b[0];
    D_01d9e8d0 = b[1];
    D_01d9e8e0 = b[2];
    D_01d9e8f0 = b[3];
    D_01d9e810 = D_01d9e7f0;
    D_01d9e820 = D_01d9e800;
    D_01d9e7f0 = *c;
    D_01d9e800 = *d;
    D_01d9e830.f = 53.0f;
    sceVu0InversMatrix(D_01d9e7b0, &D_01d9e730);  // convert_vectors_to_scalar
    f3d08(D_01d9ea00, &D_01d9e8c0, &D_01d9e730);
}
}  // namespace n001e6ed8

// 001e7008 (was src/anon/tiny.cpp)
namespace n001e7008 {
extern u32 D_00352be0 asm("D_00352be0");
/*TARGET 001e7008*/
void func_001e7008(f32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e7008fjjj");
void func_001e7008(f32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(f32*)&D_00352be0 = a0;
}
}  // namespace n001e7008

// 001e7018 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e7018 {
u32 func_0020e9f8(u32, u32, u32, u32) asm("_Z13func_0020e9f8jjjj");
/*TARGET 001e7018*/
u32 func_001e7018(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e7018jjjj");
u32 func_001e7018(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0020e9f8(a0, a1, a2, a3);
}
}  // namespace n001e7018

// 001e7030 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e7030 {
u32 func_001e7030(u32, u32, u32, u32) asm("_Z13func_001e7030jjjj");
u32 func_0020ea48(u32, u32, u32, u32) asm("_Z13func_0020ea48jjjj");
/*TARGET 001e7030*/
u32 func_001e7030(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e7030jjjj");
u32 func_001e7030(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0020ea48(((u32)(a0) & 0xffu), ((u32)(a1) & 0xffu), ((u32)(a2) & 0xffu), a3);
}
}  // namespace n001e7030

// 001e7050 (was src/anon/tiny_wrappers_more.cpp)
namespace n001e7050 {
u32 func_001e7050(u32, u32, u32, u32) asm("_Z13func_001e7050jjjj");
u32 func_0020ea70(u32, u32, u32, u32) asm("_Z13func_0020ea70jjjj");
/*TARGET 001e7050*/
u32 func_001e7050(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e7050jjjj");
u32 func_001e7050(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0020ea70(((u32)(a0) & 0xffu), ((u32)(a1) & 0xffu), a2, a3);
}
}  // namespace n001e7050

// 001e7070 (was src/anon/tiny_more2.cpp)
namespace n001e7070 {
extern u32 D_00354680 asm("D_00354680");
extern u32 D_00354684 asm("D_00354684");
/*TARGET 001e7070*/
void func_001e7070(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e7070jjjj");
void func_001e7070(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_00354680 = a0; D_00354684 = a1; }
}  // namespace n001e7070

// 001e7088 (was src/anon/tiny_more2.cpp)
namespace n001e7088 {
extern u32 D_00354688 asm("D_00354688");
extern u32 D_0035468c asm("D_0035468c");
/*TARGET 001e7088*/
void func_001e7088(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001e7088jjjj");
void func_001e7088(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_00354688 = a0; D_0035468c = a1; }
}  // namespace n001e7088

// 001e70a0 (was src/anon/tiny.cpp)
namespace n001e70a0 {
/*TARGET 001e70a0*/
void func_001e70a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001e70a0jjjj");
void func_001e70a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u32*)((u32)b + (11320)) = (u32)a0;
}
}  // namespace n001e70a0

// 001e70b0 (gap, written for the unit)
namespace n001e70b0 {
// VU0 random seed: R = 0x4325de5e ^ -1 (macro-mode VU0 instructions have no C form)
void func_001e70b0(void) asm("func_001e70b0");
void func_001e70b0(void)
{
    asm volatile("qmtc2 %0, $vf1\n\tvrinit R, $vf1x\n\tqmtc2 %1, $vf2\n\tvrxor R, $vf2x\n\tvrget.x $vf1, R\n\tqmfc2 $8, $vf1" : : "r"(0x4325de5e), "r"(-1) : "$8");
}
}  // namespace n001e70b0

// 001e70e0 (gap, written for the unit)
namespace n001e70e0 {
u32* func_001e70e0(u32* d, u32* s, s32 n) asm("func_001e70e0");
u32* func_001e70e0(u32* d, u32* s, s32 n) { while (n--) *d++ = *s++; return d; }
}  // namespace n001e70e0

// 001e7118 (gap, written for the unit)
namespace n001e7118 {
u64* func_001e7118(u64* d, u64* s, s32 n) asm("func_001e7118");
u64* func_001e7118(u64* d, u64* s, s32 n) { while (n--) *d++ = *s++; return d; }
}  // namespace n001e7118

// 001e7150 (gap, written for the unit)
namespace n001e7150 {
u128* func_001e7150(u128* d, u128* s, s32 n) asm("func_001e7150");
u128* func_001e7150(u128* d, u128* s, s32 n) { while (n--) *d++ = *s++; return d; }
}  // namespace n001e7150

// 001e7188 (was src/anon/tiny_auto80_queue.cpp)
namespace n001e7188 {
/*TARGET 001e7188*/
u32 func_001e7188(u32 a0, u32 a1, s32 a2) asm("_Z13func_001e7188jji");
u32 func_001e7188(u32 a0, u32 a1, s32 a2) {  // fill_words
    a2 = (s32)(a2 - 1);
    u32 t7 = (u32)((s32)0u + (-1));
    u32 v0 = a0;
    if ((u32)a2 != t7) {
        do {
            *(u32*)((u32)v0 + (s32)(0)) = a1;
            a2 = (s32)(a2 - 1);
            v0 = (u32)((s32)v0 + (4));
        } while ((u32)a2 != t7);
    }
    return v0;
}
}  // namespace n001e7188

// 001e71c0 (gap, written for the unit)
namespace n001e71c0 {
u64* func_001e71c0(u64* d, u64 v, s32 n) asm("func_001e71c0");
u64* func_001e71c0(u64* d, u64 v, s32 n) { while (n--) *d++ = v; return d; }
}  // namespace n001e71c0

// 001e71f8 (gap, written for the unit)
namespace n001e71f8 {
u128* func_001e71f8(u128* d, u128 v, s32 n) asm("func_001e71f8");
u128* func_001e71f8(u128* d, u128 v, s32 n) { while (n--) *d++ = v; return d; }
}  // namespace n001e71f8

// 001e7230 (was src/anon/batch_w47.cpp)
namespace n001e7230 {
void wtarget_001e7230(u32, u32, u32, u32) asm("_Z16wtarget_001e7230jjjj");
/*TARGET 001e7230*/
// Zero-fill: words then bytes. The nops reproduce the R5900 short-loop padding.
void wtarget_001e7230(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001e7230jjjj");
// Zero-fill: words then bytes. The nops reproduce the R5900 short-loop padding.
void wtarget_001e7230(u32 a, u32 b, u32, u32) {
    u32* p = (u32*)a;
    s32 n = (s32)b >> 2;
    if (n-- != 0) do { *p = 0; n--; asm volatile("nop\n\tnop\n\tnop"); p++; } while (n != -1);
    u8* q = (u8*)p;
    n = b & 3;
    if (n-- != 0) do { *q = 0; n--; asm volatile("nop\n\tnop\n\tnop"); q++; } while (n != -1);
}
}  // namespace n001e7230

// 001e7298 (gap, written for the unit)
namespace n001e7298 {
extern "C" void (*D_00352c3c)(void);
void func_001e7298(void (*cb)(void)) asm("func_001e7298");
void func_001e7298(void (*cb)(void)) { D_00352c3c = cb; }
}  // namespace n001e7298

// 001e72a8 (was src/anon/batch_w98.cpp)
namespace n001e72a8 {
// 0x001b5460: definition moved into src/anon/unit_001b2780.cpp

void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
extern u32 D_01d9e6b4 asm("D_01d9e6b4");
static inline s32 PathBusy1e7(void) {
    u32 m = *(volatile u32*)0x10009000 & 0x100;
    s32 r = m != 0;
    if (*(volatile u32*)0x1000a000 & 0x100) r = 2;
    if (*(volatile u32*)0x10003c00 & 0x1f000003) r = 4;
    u32 v;
    asm volatile("cfc2.ni %0, $vi29" : "=r"(v));
    if (v & 0x100) r = 8;
    return r;
}
/*TARGET 001e72a8*/
// Kicks a GIF PATH3 transfer of the given packet once all paths are idle (skips if already sent).
void func_001e72a8(u32 addr) asm("func_001e72a8");
// Kicks a GIF PATH3 transfer of the given packet once all paths are idle (skips if already sent).
void func_001e72a8(u32 addr) {
    sceGsSyncPath(0, 0);
    if (D_01d9e6b4 != addr) {
        while (PathBusy1e7()) {}
        *(volatile u32*)0x10009020 = 0;
        *(volatile u32*)0x10009030 = addr;
        *(volatile u32*)0x1000e010 = 2;
        D_01d9e6b4 = addr;
        *(volatile u32*)0x10009000 = 325;
    } else {
        while (PathBusy1e7()) {}
    }
}
}  // namespace n001e72a8

// 001e73e8 (gap, written for the unit)
namespace n001e73e8 {
extern "C" void func_002fdfc8(const char*, ...);
extern "C" char D_0036e978[], D_0036e998[];
// out-of-line copy of the file's assert helper
void func_001e73e8(const char* e, const char* f, s32 l) asm("func_001e73e8");
void func_001e73e8(const char* e, const char* f, s32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break");
}
}  // namespace n001e73e8

// 001e7440 (was src/anon/batch_w1669.cpp)
namespace n001e7440 {
/*TARGET 001e7440*/
void func_001e7440(void) asm("func_001e7440");
void func_001e7440(void) {
    u32 x;
    do { x = *(volatile u32*)0x1000a000 & 0x100; __asm__ volatile("nop\n\tnop\n\tnop"); } while (x);
}
}  // namespace n001e7440

// 001e7470 (was src/anon/batch_owner1021_g.cpp)
namespace n001e7470 {
/*TARGET 001e7470*/
void func_001e7470(u32 a) asm("func_001e7470");
void func_001e7470(u32 a) {
    volatile u32* p = (volatile u32*)0x1000a000;
    u32 t;
    do {
        t = *p & 0x100;
        asm volatile("nop\n\tnop\n\tnop");  // hazard nops
    } while (t);
    *(volatile u32*)0x1000a020 = 0;
    *(volatile u32*)0x1000a030 = a | 0x80000000;
    *(volatile u32*)0x1000e010 = 2;
    *(volatile u32*)0x1000a000 = 0x145;
}
}  // namespace n001e7470

// 001e74d8 (was src/anon/auto80_199_queue.cpp)
namespace n001e74d8 {
/*TARGET 001e74d8*/
void func_001e74d8(u32 a0) asm("_Z13func_001e74d8j");
void func_001e74d8(u32 a0) {
    u32 s0 = a0;
    volatile u32* st = (volatile u32*)0x10003c00;
    while ((*st & 3) != 0) {
    }

    func_002f3bb8(0x10009000, 0, 0);
    func_002f3918(0x10009000, s0);
}
}  // namespace n001e74d8

// 001e7538 (was src/anon/batch_w48.cpp)
namespace n001e7538 {
/*TARGET 001e7538*/
/* wait until VIF0/VIF1/GIF are idle and VU0 has stopped */
void func_001e7538(void) asm("func_001e7538");
/* wait until VIF0/VIF1/GIF are idle and VU0 has stopped */
void func_001e7538(void) {  // hw_regs_setup
    do {
        s32 busy;
        u32 m = *(volatile u32*)0x10009000 & 0x100;
        busy = m != 0;
        if (*(volatile u32*)0x1000a000 & 0x100) busy = 2;
        if (*(volatile u32*)0x10003c00 & 0x1f000003) busy = 4;
        u32 st;
        asm volatile("cfc2.ni %0, $vi29" : "=r"(st));
        if (st & 0x100) busy = 8;
        if (!busy) break;
    } while (1);
}
}  // namespace n001e7538

// 001e75a8 (was src/anon/batch_wcx2.cpp)
namespace n001e75a8 {
/*TARGET 001e75a8*/
// --------------------
// Wait for VIF1 DMA / GIF DMA / VIF1 / VU1 idle, then start VIF1 DMA (chain mode) at tadr.
void func_001e75a8(u32 tadr) asm("func_001e75a8");
// --------------------
// Wait for VIF1 DMA / GIF DMA / VIF1 / VU1 idle, then start VIF1 DMA (chain mode) at tadr.
void func_001e75a8(u32 tadr)
{
    s32 busy;
    do {
        u32 m = *(volatile u32*)0x10009000 & 0x100;
        busy = m != 0;
        if (*(volatile u32*)0x1000a000 & 0x100) busy = 2;
        if (*(volatile u32*)0x10003c00 & 0x1f000003) busy = 4;
        u32 st;
        asm volatile("cfc2.ni %0, $vi29" : "=r"(st));  // VPU_STAT
        if (st & 0x100) busy = 8;
    } while (busy);
    *(volatile u32*)0x10009020 = 0;
    *(volatile u32*)0x10009030 = tadr;
    *(volatile u32*)0x1000e010 = 2;
    *(volatile u32*)0x10009000 = 0x145;
    asm volatile(".set noreorder\n\t.set reorder");  // original leaves the return delay slot empty
}
}  // namespace n001e75a8

// 001e7648 (gap, written for the unit)
namespace n001e7648 {
void func_001e7648(void) asm("func_001e7648");
void func_001e7648(void) {}
}  // namespace n001e7648

// 001e7650 (was src/anon/auto200_999.cpp)
namespace n001e7650 {
/*TARGET 001e7650*/
void func_001e7650(u32 a0, u32 a1, u32 a2) asm("_Z13func_001e7650jjj");
void func_001e7650(u32 a0, u32 a1, u32 a2) {
    u32 t0 = a2;
    a2 = (u32)(a1 + t0);
    *(u32 *)((u32)a0 + (s32)(4)) = a1;
    a2 = (u32)((s32)a2 + (-16));
    *(u32 *)((u32)a0 + (s32)(0)) = 0u;
    *(u32 *)((u32)a0 + (s32)(8)) = a2;

    *(u32 *)((u32)a1 + (s32)(4)) = 0u;
    u32 t7 = *(u32 *)((u32)a0 + (s32)(8));
    *(u32 *)((u32)a1 + (s32)(8)) = 0u;
    *(u32 *)((u32)a1 + (s32)(0)) = t7;

    u32 t6 = *(u32 *)((u32)a0 + (s32)(8));
    u32 t7b = 1u;
    u32 t5 = *(u32 *)((u32)a0 + (s32)(4));
    *(u32 *)((u32)t6 + (s32)(8)) = t7b;
    *(u32 *)((u32)t6 + (s32)(4)) = t5;
    *(u32 *)((u32)t6 + (s32)(0)) = 0u;
    *(u32 *)((u32)a0 + (s32)(12)) = 0u;
}
}  // namespace n001e7650

// 001e7698 (was src/anon/batch_w2381_nsa.c)
namespace n001e7698 {
/* ---- 001e7698: pppAlloc - first-fit allocation of 16-byte-headed blocks, walking back from the
   last allocation; splits the block from its tail when the remainder is at least one header. */
typedef struct W2381Blk { struct W2381Blk* next; struct W2381Blk* prev; s32 used; s32 pad; } W2381Blk;
typedef struct { W2381Blk* cur; W2381Blk* first; W2381Blk* last; s32 total; } W2381Heap;
extern "C" char D_0036ef40[]; /* "pppAlloc error size=%d\n" */
extern "C" void (*D_00352c3c)(void);
extern "C" void func_002fdfc8(const char*, ...);
void* w2381_pppAlloc(W2381Heap* h, s32 size) asm("_Z13func_001e7698Pv");
void* w2381_pppAlloc(W2381Heap* h, s32 size)
{
    s32 one;
    W2381Blk* b;
    W2381Blk* nx;
    W2381Blk* nb;
    size = ((size + 15) & ~15) + 16;
    one = 1;
    if (h->cur) b = h->cur->next;
    else { W2381Blk* f = h->first; b = f->next; h->cur = f; }
    for (;;) {
        W2381Blk* p = b->prev;
        if (p == 0) {
            if (h->cur == 0) {
                func_002fdfc8(D_0036ef40, size);
                if (D_00352c3c) D_00352c3c();
                return 0;
            }
            h->cur = 0;
            b = h->last;
            continue;
        }
        b = p;
        if (b->used) continue;
        nx = b->next;
        if ((s32)nx - (s32)b >= size) break;
    }
    h->total += size;
    nb = (W2381Blk*)((u8*)b->next - size);
    if (nb != b && (u32)((u8*)nb - (u8*)b) >= 16) {
        h->cur = b;
        nb->next = nx; nb->prev = b;
        b->next = nb; nx->prev = nb;
        b = nb;
    } else h->cur = 0;
    b->used = one;
    b++;
    return b;
}
}  // namespace n001e7698

// 001e7798 (was src/anon/batch_w328.c)
namespace n001e7798 {
/*TARGET 001e7798*/
void func_001e7798(u32* h, u32 q) asm("func_001e7798");
void func_001e7798(u32* h, u32 q) {  // heap_free
    u32* t = (u32*)(q - 16);
    u32* n;
    t[2] = 0;
    h[0] = (u32)t;
    h[3] -= t[0] - (u32)t;
    n = (u32*)t[1];
    if (n && n[2] == 0) {
        n[0] = *(u32*)(q - 16);
        q = *(u32*)(q - 16);
        ((u32*)q)[1] = (u32)n;
        t = n;
    }
    q = t[0];
    if (((u32*)q)[2] == 0) {
        t[0] = ((u32*)q)[0];
        q = ((u32*)q)[0];
        ((u32*)q)[1] = (u32)t;
    }
}
}  // namespace n001e7798

// 001e7810 (was src/anon/batch_w49.cpp)
namespace n001e7810 {
// Runs every registered handler's optional callback (slot +16).
typedef void (*Fn1e7810)(u8*);
struct O1e7810 { u8 pad[100]; s32 n; u8 pad2[16]; u8** tbl; };
/*TARGET 001e7810*/
void func_001e7810(O1e7810* p) asm("func_001e7810");
void func_001e7810(O1e7810* p) {
    for (s32 i = 0; i < p->n; i++) {
        u8* x = p->tbl[i];
        if (*(Fn1e7810*)(x + 16)) (*(Fn1e7810*)(x + 16))((u8*)p);
    }
}
}  // namespace n001e7810

// 001e7878 (was src/anon/batch_w36.cpp)
namespace n001e7878 {
typedef void (*VFn)(void*);
// 0x001d6ec8: definition moved into src/anon/unit_001d68e0.cpp

struct Comp { u8 pad[20]; VFn f; };
struct Mgr { u8 pad[100]; s32 n; u8 pad2[16]; Comp** c; };
/*TARGET 001e7878*/
// Runs every component's optional update hook.
void func_001e7878(Mgr* p) asm("func_001e7878");
// Runs every component's optional update hook.
void func_001e7878(Mgr* p) {
    s32 i;
    for (i = 0; i < p->n; i++) {
        if (p->c[i]->f) p->c[i]->f(p);
    }
}
}  // namespace n001e7878

// 001e78e0 (was src/anon/batch_w37.cpp)
namespace n001e78e0 {
typedef void (*VFnP)(void*);
struct Obj1e7 { u8 _0[24]; VFnP fn; };
struct Mgr1e7 { u8 _0[100]; s32 n; u8 _68[16]; Obj1e7** objs; };
/*TARGET 001e78e0*/
void func_001e78e0(Mgr1e7* p) asm("func_001e78e0");
void func_001e78e0(Mgr1e7* p) {
    for (s32 i = 0; i < p->n; i++) {
        Obj1e7* o = p->objs[i];
        if (o->fn) o->fn(p);
    }
}
}  // namespace n001e78e0

// 001e7948 (was src/anon/batch_w332.c)
namespace n001e7948 {
/* particle effect slot table: copy each slot's value out and run its callback */
typedef struct PartVt { u8 pad[0x1c]; void (*f1c)(void*, void*); void (*f20)(void*, void*); } PartVt;
typedef union { PartVt* v; s32 w[4]; } PartEnt;
typedef struct { u8 pad[0x20]; s32 off; s32 x24:16; s32 n:16; PartEnt ent[1]; } PartHdr;
typedef struct { s32 x0, x4; PartHdr** x8; } PartObj;
/*TARGET 001e7948*/
void func_001e7948(PartObj* a) asm("func_001e7948");
void func_001e7948(PartObj* a) {
  PartHdr* h = *a->x8;
  s32* out = (s32*)((u8*)a + h->off);
  s32 i;
  for (i = 0; i < h->n; i++) {
    PartEnt* e = &h->ent[i];
    PartVt* v = e->v;
    *out++ = e->w[2];
    if (v && v->f20) v->f20(a, e);
  }
}
}  // namespace n001e7948

// 001e79f0 (was src/anon/batch_w332.c)
namespace n001e79f0 {
/* particle effect slot table: copy each slot's value out and run its callback */
typedef struct PartVt { u8 pad[0x1c]; void (*f1c)(void*, void*); void (*f20)(void*, void*); } PartVt;
typedef union { PartVt* v; s32 w[4]; } PartEnt;
typedef struct { u8 pad[0x20]; s32 off; s32 x24:16; s32 n:16; PartEnt ent[1]; } PartHdr;
typedef struct { s32 x0, x4; PartHdr** x8; } PartObj;
/*TARGET 001e79f0*/
void func_001e79f0(PartObj* a) asm("func_001e79f0");
void func_001e79f0(PartObj* a) {
  PartHdr* h = *a->x8;
  s32* out = (s32*)((u8*)a + h->off);
  s32 i;
  for (i = 0; i < h->n; i++) {
    PartEnt* e = &h->ent[i];
    PartVt* v = e->v;
    *out++ = e->w[2];
    if (v && v->f1c) v->f1c(a, e);
  }
}
}  // namespace n001e79f0

// 001e7a98 (was src/anon/batch_w268.cpp)
namespace n001e7a98 {
// 0x002881c0: definition moved into src/anon/unit_002880b8.cpp

s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
extern "C" char D_0036ef58[], D_0036ef70[], D_0036ef98[], D_0036ef88[];
extern void* D_01d9e6e4 asm("D_01d9e6e4");
struct W268Item;
struct W268Desc { u8 pad[0x20]; s32* tbl; s16 pri; s16 idx; };
struct W268Owner { W268Desc* desc; W268Item* last; u8 pad8[4]; u16 count; };
struct W268Item { W268Item* next; u8 p4[4]; W268Owner* owner; s32 f0c; u8 p10[0x80]; s32 f90; s32 f94; u8 p98[4]; u8 b9c; u8 b9d; u8 b9e; };
struct W268Mgr { u8 pad[0x74]; W268Item* head; };
W268Item* func_001e7698(void*, s32*) asm("func_001e7698");
// alloc_aligned16
void func_001e79f0(W268Item*) asm("func_001e79f0");
static inline void assert_fail_1e7a98(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
/*TARGET 001e7a98*/
W268Item* func_001e7a98(W268Mgr* mgr, W268Owner* own) asm("func_001e7a98");
W268Item* func_001e7a98(W268Mgr* mgr, W268Owner* own) {
    W268Desc* d = own->desc;
    W268Item* it = func_001e7698(D_01d9e6e4, &d->tbl[d->idx]);  // alloc_aligned16
    if ((u32)it & 0xf) assert_fail_1e7a98(D_0036ef70, D_0036ef88, 222);
    it->f0c = 0;
    it->b9c = 1;
    it->f90 = 0;
    it->f94 = 0;
    it->owner = own;
    asm volatile("" ::: "memory");
    it->b9d = 0;
    it->b9e = 0;
    W268Item* n = mgr->head;
    if (n == 0) {
        own->last = it;
        mgr->head = it;
        it->next = 0;
    } else if (own->last) {
        it->next = own->last->next;
        own->last->next = it;
    } else {
        s16 pri = d->pri;
        W268Item** pp = &mgr->head;
        for (;;) {
            if (n->owner->desc->pri >= pri) {
                own->last = it;
                *pp = it;
                it->next = n;
                goto done;
            }
            pp = &n->next;
            n = n->next;
            if (!n) break;
        }
        own->last = it;
        *pp = it;
        it->next = 0;
    }
done:
    own->count++;
    func_001e79f0(it);
    return it;
}
}  // namespace n001e7a98

// 001e7be0 (was src/anon/batch_w89.cpp)
namespace n001e7be0 {
struct E7Ent { u8 pad[36]; void (*fn)(void*, void*); };
struct E7Slot { E7Ent* e; u8 pad[12]; };
struct E7Def { u8 pad[38]; s16 count; E7Slot slots[1]; };
struct E7Obj { E7Def* def; void* cur; u32 f8; u16 refs; };
struct E7Ctx { void* next; u32 f4; E7Obj* obj; };
extern u32 D_01d9e6e4 asm("D_01d9e6e4");
void func_001e7798(u32, E7Ctx*) asm("func_001e7798");
/*TARGET 001e7be0*/
void func_001e7be0(E7Ctx* c) asm("func_001e7be0");
void func_001e7be0(E7Ctx* c) {
    E7Obj* ob = c->obj;
    E7Def* d = ob->def;
    for (s32 i = 0; i < d->count; i++) {
        E7Slot* s = &d->slots[i];
        if (s->e && s->e->fn) s->e->fn(c, s);
    }
    if (--ob->refs == 0) ob->cur = 0;
    else if (ob->cur == c) ob->cur = c->next;
    func_001e7798(D_01d9e6e4, c);
}
}  // namespace n001e7be0

// 001e7cc0 (was src/anon/batch_w43.cpp)
namespace n001e7cc0 {
void func_001e7be0(void*) asm("func_001e7be0");
void func_001e7798(u32, u32) asm("func_001e7798");
extern u32 D_01d9e6e4 asm("D_01d9e6e4");
/*TARGET 001e7cc0*/
void func_001e7cc0(u8* p) asm("func_001e7cc0");
void func_001e7cc0(u8* p) {
    u8* o = *(u8**)(p + 116);
    while (o) {
        u8* n = *(u8**)o;
        func_001e7be0(o);
        o = n;
    }
    *(u32*)(p + 116) = 0;
    if (*(u32*)(p + 128)) {
        func_001e7798(D_01d9e6e4, *(u32*)(p + 128));
        *(u32*)(p + 128) = 0;
    }
}
}  // namespace n001e7cc0

// .rodata 0x36ef40-0x36efb0 (strings the code reads as extern D_)
extern const u32 R_0036ef40[6] asm("D_0036ef40") __attribute__((aligned(4))) = { 0x41707070, 0x636f6c6c, 0x72726520, 0x7320726f, 0x3d657a69, 0xa6425 };
extern const u32 R_0036ef58[6] asm("D_0036ef58") __attribute__((aligned(4))) = { 0x65737341, 0x6f697472, 0x6166206e, 0x64656c69, 0x7325203a, 0xa };
extern const u32 R_0036ef70[6] asm("D_0036ef70") __attribute__((aligned(4))) = { 0x6e692828, 0x70612974, 0x206a626f, 0x78302026, 0x3d202966, 0x30203d };
extern const u32 R_0036ef88[4] asm("D_0036ef88") __attribute__((aligned(4))) = { 0x50707070, 0x2e747261, 0x63, 0x0 };
extern const u32 R_0036ef98[6] asm("D_0036ef98") __attribute__((aligned(4))) = { 0x46202020, 0x20656c69, 0x202c7325, 0x656e694c, 0xa752520, 0x0 };

// 001e7d20 (was src/anon/batch_w60.cpp)
namespace n001e7d20 {
f32 sceVu0InnerProduct(void*) asm("sceVu0InnerProduct");
// vec3_dot
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
/*TARGET 001e7d20*/
// Normalised direction (xyz) and length (w); +z when the length is zero.
void func_001e7d20(f32* out, void* v) asm("func_001e7d20");
// Normalised direction (xyz) and length (w); +z when the length is zero.
void func_001e7d20(f32* out, void* v) {
    f32 l = sceVu0InnerProduct(v);  // vec3_dot
    if (0.0f < l) {
        f32 s = __builtin_sqrtf(l);
        sceVu0Normalize(out, v);  // vec4_normalize
        out[3] = s;
    } else {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[3] = 0.0f;
        out[2] = 1.0f;
    }
}
}  // namespace n001e7d20

// 001e7da8 (was src/anon/batch_w3716_nsa.c)
namespace n001e7da8 {
// w3716 _nsa, partial asm: empty asm keeps the offset base live to the end of the if block (no load gets its REG_DEAD), f4/f2 pins fix FP allocation.
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1e7da8;
typedef struct { V1e7da8 r[4]; } M1e7da8;
typedef struct { u8 pad0[128]; f32 tx, ty, tz; u8 pad1[144 - 140]; u8 m144[16]; f32 sx, sy, sz; u8 pad2[249 - 172]; u8 big; } Own1e7da8;
typedef struct {
    f32 x, y, z;
    u8 pad0[16 - 12];
    f32 rz, rx, ry;
    u8 pad1[32 - 28];
    f32 sx, sy, sz;
    u8 pad2[64 - 44];
    f32 bx, by, bz;
    u8 pad3[140 - 76];
    Own1e7da8* own;
    u8 pad4[170 - 144];
    u8 offset;
} Part1e7da8;
extern M1e7da8 D_01d9e6f0 asm("D_01d9e6f0");
extern V1e7da8 D_01d9e7f0 asm("D_01d9e7f0");
extern f32 D_00354be0[3] asm("D_00354be0");
extern f32 D_00354bd0[3] asm("D_00354bd0");
extern u8 D_00354bc0[] asm("D_00354bc0");
extern u8 D_01d9e720[] asm("D_01d9e720");
void sceVu0UnitMatrix(M1e7da8*) asm("sceVu0UnitMatrix");
void sceVu0RotMatrixX(M1e7da8*, M1e7da8*, f32) asm("sceVu0RotMatrixX");
void sceVu0RotMatrixY(M1e7da8*, M1e7da8*, f32) asm("sceVu0RotMatrixY");
void sceVu0RotMatrixZ(M1e7da8*, M1e7da8*, f32) asm("sceVu0RotMatrixZ");
void func_001e8fe0(M1e7da8*, void*) asm("func_001e8fe0");
void sceVu0MulMatrix(M1e7da8*, M1e7da8*, M1e7da8*) asm("sceVu0MulMatrix");
void func_001e7d20(V1e7da8*, V1e7da8*) asm("func_001e7d20");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_002f8ab8(f32) asm("func_002f8ab8");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
/* libvu0 sceVu0ScaleVectorXYZ (VU0 macro code) */
static inline void scale1e7da8(V1e7da8* d, V1e7da8* v, f32 s)
{
    asm volatile("qmtc2 %2, $vf9\n\tlqc2 $vf10, 0(%1)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(d), "r"(v), "r"(s) : "memory");
}
/*TARGET 001e7da8*/
void func_001e7da8(Part1e7da8* p) asm("func_001e7da8");
void func_001e7da8(Part1e7da8* p)
{
    M1e7da8* m = &D_01d9e6f0;
    M1e7da8 o;
    f32 ang[3];
    s32 i;
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, p->rz);
    sceVu0RotMatrixY(m, m, p->rx);
    sceVu0RotMatrixZ(m, m, p->ry);
    scale1e7da8(&m->r[0], &m->r[0], p->sx);
    scale1e7da8(&m->r[1], &m->r[1], p->sy);
    scale1e7da8(&m->r[2], &m->r[2], p->sz);
    if (p->own->big) {
        scale1e7da8(&m->r[0], &m->r[0], p->bx);
        scale1e7da8(&m->r[1], &m->r[1], p->by);
        scale1e7da8(&m->r[2], &m->r[2], p->bz);
    }
    m->r[3].x = p->x;
    m->r[3].y = p->y;
    m->r[3].z = p->z;
    func_001e8fe0(&o, p->own->m144);
    scale1e7da8(&o.r[0], &o.r[0], p->own->sx);
    scale1e7da8(&o.r[1], &o.r[1], p->own->sy);
    scale1e7da8(&o.r[2], &o.r[2], p->own->sz);
    o.r[3].x = p->own->tx;
    o.r[3].y = p->own->ty;
    o.r[3].z = p->own->tz;
    sceVu0MulMatrix(m, m, &o);
    if (p->offset) {
        V1e7da8* off = &D_01d9e7f0;
        f32 mx;
        f32 ox;
        f32 my;
        f32 mz;
        register f32 oz asm("$f4");
        register f32 oy asm("$f2");
        mx = m->r[3].x;
        ox = off->x;
        my = m->r[3].y;
        mz = m->r[3].z;
        oz = off->z;
        oy = off->y;
        mx += ox; mz += oz; my += oy;
        m->r[3].x = mx; m->r[3].z = mz; m->r[3].y = my;
        asm("" : : "r"(off));
    }
    for (i = 0; i < 3; i++) {
        func_001e7d20(&o.r[i], (V1e7da8*)((i << 4) + (u32)&D_01d9e6f0));
        D_00354be0[i] = o.r[i].w;
        o.r[i].w = 0.0f;
    }
    ang[0] = func_002f8ad0(-o.r[1].z, o.r[0].z);
    ang[1] = func_002f8ab8(-o.r[2].z);
    ang[2] = func_002f8ad0(o.r[2].y, o.r[2].x);
    for (i = 0; i < 3; i++) D_00354bd0[i] = ang[i];
    sceVu0CopyVector(D_00354bc0, D_01d9e720);
}
}  // namespace n001e7da8

// 001e8048 (was src/anon/batch_w3775_nsa.c)
namespace n001e8048 {
struct Node { Node* next; u32 pad[3]; s32 v10; };
struct Ent { Node* n; s32 w4; s32 v8; u16 h12; u8 b14; u8 pad; };
struct Obj {
    u8 pad0[0x54]; s32 w54; s32 w58;
    u8 pad1[0x64 - 0x5c]; s32 w64; s32 n68; s32 pad6c; Node* list70; s32 w74; s32* p78; s32* p7c; Ent* ents;
    u8 b84; u8 b85;
    u8 pad2[0x98 - 0x86]; s32 w98;
};
extern Obj* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9e6e4 asm("D_01d9e6e4");
Ent* func_001e7698(s32, s32) asm("func_001e7698");
void func_001e7810(Obj*) asm("func_001e7810");
/*TARGET 001e8048*/
void func_001e8048(Obj* o, s32* d, s32 go) asm("func_001e8048");
void func_001e8048(Obj* o, s32* d, s32 go) {
    s32* p = d + 1;
    asm("" : "+r"(p));
    D_01d9e6e0 = o;
    o->w54 = d[0];
    s32 fl = *p++;
    s32* a = (s32*)((u8*)d + *p++);
    s32* b = (s32*)((u8*)d + *p++);
    s32 f1 = fl & 1; if (f1) o->b84 = 1; else o->b84 = 0;
    o->w64 = *a++;
    o->p78 = a;
    o->n68 = *b++;
    o->p7c = b;
    if (o->n68) o->ents = func_001e7698(D_01d9e6e4, o->n68 << 4);
    else o->ents = 0;
    Node* n = (Node*)p;
    if (n->next) o->list70 = 0;
    o->list70 = o->n68 ? n : 0;
    o->w58 = 0;
    o->b85 = 0;
    o->w74 = 0;
    register Ent* e asm("$11") = o->ents;
    u8 i = 0;
    for (; n; n = n->next) {
        e->n = n;
        e->v8 = n->v10;
        e->b14 = i++;
        e->w4 = 0;
        e->h12 = 0;
        e++;
    }
    if (go) func_001e7810(o);
    o->w98 = 0;
}
}  // namespace n001e8048

// 001e8180 (was src/anon/batch_w331.c)
namespace n001e8180 {
typedef union { s32 w; u8* p; s16 h[2]; u8 c; } U331;
/*TARGET 001e8180*/
void func_001e8180(u8* p, u8* base) asm("func_001e8180");
void func_001e8180(u8* p, u8* base) {
    s32* A;
    s32* B;
    u8* node;
    u8* next;
    s32 na, nb, i, j, k;
    p += 0x110;
    A = (s32*)(p + *(s32*)(p + 8));
    B = (s32*)(p + *(s32*)(p + 12));
    node = p + 16;
    na = *A++;
    nb = *B++;
    if (*(s32*)(p + 16) == 0) return;
    for (;;) { ((U331*)node)->p = p + ((U331*)node)->w; for (i = 0; i < ((U331*)(node + 36))->h[1]; i++) { U331* e = (U331*)(node + 40 + i * 16); e[0].w = (s32)(base + e[0].w * 72); e[2].w = (s32)(p + e[2].w); e[3].w = (s32)(p + e[3].w); } next = ((U331*)node)->p; if (((U331*)next)->w == 0) { ((U331*)node)->w = 0; break; } node = next; }
    for (j = 0; j < na; j++) A[j] = (s32)(base + A[j] * 72);
    for (k = 0; k < nb; k++) B[k] = B[k] + (s32)p;
}
}  // namespace n001e8180

// 001e8288 (was src/anon/batch_w328.c)
namespace n001e8288 {
typedef union W { s32 w; u8 c; } W;
typedef struct E { s32 x, y; W a; W b; } E;
/*TARGET 001e8288*/
void func_001e8288(u8* p, s32 d) asm("func_001e8288");
void func_001e8288(u8* p, s32 d) {
    u8* b;
    u32* q;
    s32* t;
    s32 n;
    s32 i;
    u8* e;
    p += 0x110;
    b = p;
    p += 12;
    t = (s32*)(b + *(u32*)p);
    p += 4;
    n = *t++;
    for (;;) {
        for (i = 0; i < *(s16*)(p + 0x26); i++) {
            ((E*)(p + 0x28))[i].a.w = d + ((E*)(p + 0x28))[i].a.w;
            ((E*)(p + 0x28))[i].b.w = d + ((E*)(p + 0x28))[i].b.w;
        }
        if (*(u32*)p == 0) break;
        p = (u8*)(*(u32*)p = d + *(u32*)p);
    }
    if (n > 0) {
        s32* a = t;
        s32 k = n;
        do { *a++ += d; } while (--k);
    }
}
}  // namespace n001e8288

// 001e8330 (was src/anon/batch_w3901_nsa.c)
namespace n001e8330 {
struct Node_e { Node_e* next; u8 pad4[8]; s32 val; u8 pad10[0x9c - 0x10]; u8 b9c; u8 b9d; u8 b9e; };
struct Hnd_e { u8 pad0[4]; void (*fn)(Node_e*, s32*, void*); u8 pad8[4]; s32 off; u8 pad10[0x28 - 0x10]; s32 start; s32 sum; s32 max; };
struct Slot_e { Hnd_e* h; u16 add; u8 pad[10]; };
struct Grp_e { u8 pad0[0x20]; s32 off; u8 pad24[2]; s16 nslots; Slot_e slot[1]; };
struct Ent_e { Grp_e* g; Node_e* first; u8 pad8[4]; u16 n; u8 pade[2]; };
struct Self_e { u8 pad0[0x68]; s32 count; u8 pad6c[0x80 - 0x6c]; Ent_e* ents; };
struct Dev_e { u8 pad[0xa8]; u64 flags; };
extern Dev_e* D_01d9e6e0 asm("D_01d9e6e0");
extern Node_e* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
void func_001e7948(Node_e*) asm("func_001e7948");
/*TARGET 001e8330*/
void func_001e8330(Self_e* self) asm("func_001e8330");
void func_001e8330(Self_e* self)
{
    s32 i;
    for (i = 0; i < self->count; i++) {
        Ent_e* e = &self->ents[i];
        Grp_e* g = e->g;
        s32 j;
        if (e->n == 0)
            continue;
        for (j = 0; j < g->nslots; j++) {
            Slot_e* sl = &g->slot[j];
            register Hnd_e* h asm("$19") = sl->h;
            Node_e* nd = e->first;
            void (*fn)(Node_e*, s32*, void*) = h->fn;
            s32 off = h->off;
            register s32 k asm("$20");
            if (fn == 0 || off != 0)
                continue;
            k = e->n;
            do {
                Node_e* next = nd->next;
                s32** pp0 = (s32**)((u8*)nd + g->off + j * 4);
                if (!nd->b9c) {
                    s32** pp = pp0;
                    register s32* p asm("$18") = *pp;
                    register s32* q asm("$22") = (s32*)((u8*)p + sl->add);
                    register s32* t asm("$16");
                    D_01d9e6e8 = nd;
                    if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL) && nd->b9e) {
                        nd->val = 0;
                        nd->b9d = 1;
                        func_001e7948(nd);
                        nd->b9e = 0;
                    }
                    if (*q == nd->val) {
                        *pp = q;
                        p = q;
                    }
                    t = &h->start;
                    h->start = *(volatile s32*)0x10000000;
                    fn(nd, p, sl);
                    t[1] += *(volatile s32*)0x10000000 - h->start;
                    if (t[2] < t[1])
                        t[2] = t[1];
                }
                nd = next;
            } while (--k);
            {
            register s32 ph asm("$21");
            asm volatile("" : "=r"(ph));
            asm("" :: "r"(fn), "r"(ph));
            }
        }
    }
}
}  // namespace n001e8330

// 001e8558 (was whole asm in src/anon/batch_w3951.s): per-group callback pass over the node lists (two handler
// callbacks per node, each timed with the EE timer at 0x10000000), then the restart / free / relink pass.
// Plain C++: the globals of loops 1-2 are read through reference-returning inline accessors and the restart is an
// inline with value parameters (loop-invariant motion, see notes); the j loop is a natural for loop.
namespace n001e8558 {
typedef struct Tm { s32 start; s32 sum; s32 max; s32 pad; } Tm;
typedef struct Hd Hd;
struct Hd { u8 pad0[0x14]; u32 x14; s32 x18; s32 x1c; s32 off20; u8 pad24[2]; s16 nslots; };
typedef struct Node Node;
struct Node { Node* next; u8 pad4[4]; Hd** hd; s32 val; u8 pad10[0x9c - 0x10]; u8 b9c; u8 b9d; u8 b9e; };
typedef struct Hnd Hnd;
struct Hnd { u8 pad0[4]; void (*fn1)(Node*, s32*, void*); u8 pad8[4]; void (*fn2)(Node*, s32*, void*); u8 pad10[0x28 - 0x10]; Tm t1; Tm t2; };
typedef struct Slot { Hnd* h; u16 add; u8 pad[10]; } Slot;
typedef struct Grp { u8 pad0[0x20]; s32 off; u8 pad24[2]; s16 nslots; Slot slot[1]; } Grp;
typedef struct Ent { Grp* g; Node* first; u8 pad8[4]; u16 n; u8 pade[2]; } Ent;
typedef struct Self { u8 pad0[0x68]; s32 count; u8 pad6c[0x74 - 0x6c]; Node* list; u8 pad78[0x80 - 0x78]; Ent* ents; u8 b84; u8 b85; } Self;
typedef struct Dev { u8 pad[0xa8]; u64 flags; } Dev;
extern Dev* D_01d9e6e0 asm("D_01d9e6e0");
extern Node* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern s32 D_01d9eab4 asm("D_01d9eab4");
void func_001e7948(Node*) asm("func_001e7948");
void func_001e7be0(Node*) asm("func_001e7be0");
void func_001e8e28(Self*, Node*) asm("func_001e8e28");
static inline s32& GStop() { return D_01d9ea9c; }
static inline Dev*& GDev() { return D_01d9e6e0; }
static inline Node*& GCur() { return D_01d9e6e8; }
static inline u64 Tst(u64 m) { return GDev()->flags & m; }
static inline void Restart(Node* n, s32 v, u8 f) { n->val = v; n->b9d = f; func_001e7948(n); }
#define T0_8558 (*(volatile s32*)0x10000000)
/*TARGET 001e8558*/
void func_001e8558(Self* self, s32 flag) asm("func_001e8558");
void func_001e8558(Self* self, s32 flag)
{
    s32 i;
    Ent* e;
    s32 j;
    Slot* sl;
    void (*fn1)(Node*, s32*, void*);
    void (*fn2)(Node*, s32*, void*);
    Grp* g;
    Hnd* h;
    s32 k;
    Node* nd;
    Node* next;
    s32** pp;
    s32* p;
    s32* q;
    Tm* t; u8* w;
    s32** pp2;
    s32* p2;
    s32* q2;
    u32 acc;
    Node** link;
    Hd* hd;
    Node* cur;
    Node* nx;
    Node* n2;
    Node* n3;
    s32 k2;

    for (i = 0; i < self->count; i++) {
        e = &self->ents[i];
        g = e->g;
        if (e->n == 0)
            continue;
        for (j = 0; j < g->nslots; j++) {
            sl = &g->slot[j];
            h = sl->h;
            nd = e->first;
            fn1 = h->fn1;
            fn2 = h->fn2;
            if (fn2 == 0)
                continue;
            if (fn1 != 0) {
                k = e->n;
                do {
                    next = nd->next;
                    w = (u8*)nd + g->off + j * 4;
                    if (!nd->b9c) {
                        p = *(s32**)w;
                        q = (s32*)((u8*)p + sl->add);
                        GCur() = nd;
                        if (GStop() == 0 && !Tst(0xff0000ff00ULL) && nd->b9e) {
                            Restart(nd, 0, 1);
                            nd->b9e = 0;
                        }
                        if (*q == nd->val) {
                            p = q;
                            *(s32**)w = p;
                        }
                                                h->t1.start = T0_8558;
                        w = (u8*)&h->t1;
                        fn1(nd, p, sl);
                        ((Tm*)w)->sum += T0_8558 - h->t1.start;
                        if (((Tm*)w)->max < ((Tm*)w)->sum)
                            ((Tm*)w)->max = ((Tm*)w)->sum;
                        if (flag) {
                            h->t2.start = T0_8558;
                            w = (u8*)&h->t2;
                            fn2(nd, p, sl);
                            ((Tm*)w)->sum += T0_8558 - h->t2.start;
                            if (((Tm*)w)->max < ((Tm*)w)->sum)
                                ((Tm*)w)->max = ((Tm*)w)->sum;
                        }
                    }
                    nd = next;
                } while (--k);
            } else {
                k = e->n;
                do {
                    pp2 = (s32**)((u8*)nd + g->off + j * 4);
                    if (!nd->b9c) {
                        p2 = *pp2;
                        q2 = (s32*)((u8*)p2 + sl->add);
                        GCur() = nd;
                        if (*q2 == nd->val) {
                            p2 = q2;
                            *pp2 = p2;
                        }
                        if (flag) {
                            h->t2.start = T0_8558;
                            t = &h->t2;
                            fn2(nd, p2, sl);
                            t->sum += T0_8558 - h->t2.start;
                            if (t->max < t->sum)
                                t->max = t->sum;
                        }
                    }
                    nd = nd->next;
                } while (--k);
            }
        }
        if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL)) {
            n3 = e->first;
            k2 = e->n;
            do {
                if (!n3->b9c) {
                    n3->val += 0x1000;
                    if (n3->val > 0x6fffffff)
                        n3->val = 0x6ffff000;
                } else
                    n3->b9c = 0;
                n3 = n3->next;
            } while (--k2);
        }
    }
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL)) {
        acc = 0;
        link = &self->list;
        for (cur = self->list; cur; cur = nx) {
            nx = cur->next;
            hd = *cur->hd;
            if (!self->b85 && cur->val >= hd->x1c && hd->x18 <= 0x6fffffff && hd->x1c <= 0x6fffffff) {
                cur->val = 0;
                cur->b9d = 1;
                func_001e7948(cur);
                if (hd->x18 == 0) {
                    D_01d9eab4 = 1;
                    func_001e8e28(self, cur);
                    D_01d9eab4 = 0;
                    cur->b9e = 1;
                } else {
                    D_01d9eab4 = 1;
                    while (cur->val < hd->x18)
                        func_001e8e28(self, cur);
                    D_01d9eab4 = 0;
                }
            } else {
                acc |= hd->x14;
                if ((u32)cur->val >= hd->x14) {
                    *link = nx;
                    func_001e7be0(cur);
                    continue;
                }
            }
            link = &cur->next;
        }
        if (self->b84 && self->b85 && acc == 0x70000000) {
            n2 = self->list;
            while (n2) {
                cur = n2->next;
                func_001e7be0(n2);
                n2 = cur;
            }
            self->list = 0;
        }
    }
}
#undef T0_8558
}  // namespace n001e8558
