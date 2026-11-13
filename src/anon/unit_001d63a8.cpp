#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// 001d63a8 (from src/anon/batch_w1262.cpp)
namespace n001d63a8 {
s32 func_001a3570(u32) asm("func_001a3570");
s32 func_001c99b0(u32) asm("func_001c99b0");
s32 func_00181500(u32) asm("func_00181500");
u8* func_001b90c8(u32) asm("func_001b90c8");
u8* func_00189200(void *, u32) asm("func_00189200");
f32 func_002f8b30(f32, f32) asm("func_002f8b30");
extern u8 D_0032e020[] asm("D_0032e020");
extern u8 *D_00352130 asm("D_00352130");
extern u32 D_003638d0 asm("D_003638d0");
s32 func_001d63a8(u8 *a0) asm("func_001d63a8");
s32 func_001d63a8(u8 *a0)
{
  float new_var;
  u8 *q;
  u8 *g;
  f32 f;
  f32 lim;
  f32 r;
  if (func_001a3570(29) > 0)
  {
    return 0;
  }
  if (func_001c99b0(5) != 0)
  {
    return 0;
  }
  if (func_00181500(0x4842) == 0)
  {
    return 0;
  }
  q = func_001b90c8(5);
  if ((*((u8 **) (a0 + 1164)))[433] < q[28])
  {
    return 0;
  }
  q = func_00189200(D_0032e020, 5);
  g = D_00352130;
  new_var = 100.0f;
  f = (*((f32 *) (g + 152))) * func_002f8b30(*((f32 *) (g + 156)), (f32) (*((s32 *) (q + 4))));
  lim = *((f32 *) (D_00352130 + 160));
  if (lim < f)
  {
    f = lim;
  }
  D_003638d0 *= 0x10dcd;
  r = ((f32) D_003638d0) * 2.3283064365386963e-10f;
  (*((s32 *) (q + 4)))++;
  r = r * new_var;
  if (f <= r)
  {
    return 0;
  }
  *((s32 *) (q + 4)) = 0;
  return 1;
}
} // n001d63a8

// 001d64f8 (never written before)
namespace n001d64f8 {
void func_001ce378(u8* p) asm("func_001ce378");
extern u8 D_01d5ba78[] asm("D_01d5ba78");
extern u8 D_00352780[] asm("D_00352780");
void func_001d64f8(u8* p) asm("func_001d64f8");
void func_001d64f8(u8* p) {
    func_001ce378(p);
    *(u8**)p = D_00352780;
    *(u8**)(p + 2552) = D_01d5ba78;
}
} // n001d64f8

// 001d6538 (from src/anon/batch_w20.cpp)
namespace n001d6538 {
void func_001ce378(void*) asm("func_001ce378");
extern void* D_01d5ba78[] asm("D_01d5ba78");
extern void* D_00352780[] asm("D_00352780");
void func_001d6538(void** p) asm("func_001d6538");
void func_001d6538(void** p) {
    func_001ce378(p);
    *p = D_00352780;
    *(void**)((u8*)p + 0x9f8) = D_01d5ba78;
}
} // n001d6538

// 001d6578 (from src/anon/auto80_199_queue.cpp)
namespace n001d6578 {
u32 func_001d6578(u32 a0, u32 a1, f32 a2) asm("func_001d6578");
u32 func_001d6578(u32 a0, u32 a1, f32 a2) {
    f32 f20 = a2;
    u32 s19 = a1;
    u32 s18 = a0;
    u32 s17 = func_001db9a8(a0, 0, 6000);
    u32 s16 = func_001050d8(2560);
    func_001d6538(s16, s17, s18, s19, f20);
    return s16;
}
} // n001d6578

// 001d65f8 (from src/anon/batch_w1948.cpp)
namespace n001d65f8 {
struct V1d65f8 {
    f32 x, y, z, w;
    V1d65f8() {}
    V1d65f8& operator=(const V1d65f8& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_001a7610(unsigned int, unsigned int, unsigned int, float, float) asm("func_001a7610");
static inline V1d65f8 sub_1d65f8(const V1d65f8& a, const V1d65f8& b) {
    V1d65f8 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern u32 D_003638d0 asm("D_003638d0");
static inline s32 rnd_1d65f8(s32 n) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return ((u64)D_003638d0 * n) >> 32;
}
struct O1d65f8 { u8 p0[64]; V1d65f8 v40; u8 p50[4]; void* cb; void* owner; u8 p5c[4]; };
struct T1d65f8 { u8 p0[2548]; T1d65f8* p9f4; };
V1d65f8* func_0016c028(void*) asm("func_0016c028");
void func_001c2858(void*, V1d65f8*, void*, void*) asm("func_001c2858");
s32 func_001c28f8(void*, V1d65f8*, s32) asm("func_001c28f8");
O1d65f8* func_001db888(void*, s32, void*) asm("func_001db888");
void func_001dbc58(O1d65f8*, T1d65f8*, V1d65f8*, V1d65f8*) asm("func_001dbc58");
void func_001ce618(void) asm("func_001ce618");
extern V1d65f8 D_01d5ba78 asm("D_01d5ba78");
extern V1d65f8 D_01d5ba88 asm("D_01d5ba88");
void func_001d65f8(T1d65f8* self, void* a, void* b) asm("func_001d65f8");
void func_001d65f8(T1d65f8* self, void* a, void* b) {
    u8 obj[80];
    V1d65f8 v;
    func_001c2858(obj, func_0016c028(self), a, b);
    T1d65f8* s = self->p9f4->p9f4;
    while (func_001c28f8(obj, &v, 1)) {
    V1d65f8* sel = rnd_1d65f8(2) == 0 ? &D_01d5ba78 : &D_01d5ba88;
    func_001a7610((u32)&v, (u32)&v, 4, 1000.0f, 200.0f);
    v.y -= sel->z;
    O1d65f8* o = func_001db888((u8*)s + 20, 96, __builtin_return_address(0));
    func_001dbc58(o, s, &v, sel);
    o->v40 = sub_1d65f8(v, *func_0016c028(self));
    o->v40.w = 1.0f;
    o->owner = self;
    o->cb = (void*)func_001ce618;
    }
}
} // n001d65f8

// 001d6790 (from src/anon/batch_w83.cpp)
namespace n001d6790 {
struct Trig { f32 x, y, z; u8 pad[8]; u8 cnt; u8 pad2[2]; u8 flag; u8 pad3[68]; s32* ref; };
void* func_0016e920(s32) asm("func_0016e920");
u8* func_001dba18(void*) asm("func_001dba18");
Trig* func_001c16f0(void*, Trig*) asm("func_001c16f0");
void func_001d6790(f32* box) asm("func_001d6790");
void func_001d6790(f32* box) {
    void* list = *(void**)(func_001dba18(func_0016e920(2120)) + 2548);
    Trig* it = 0;
    while ((it = func_001c16f0(list, it))) {
        if (it->cnt != *it->ref) continue;
        if (box[0] <= it->x && it->x <= box[3] && box[2] <= it->z && it->z <= box[5]) {
            it->flag = 0;
            it->cnt++;
        }
    }
}
} // n001d6790

// 001d6850 (from src/anon/batch_w1672.cpp)
namespace n001d6850 {
struct W3w1672 { u32 a; u32 b; f32 c; };
extern W3w1672 D_01d5ba78 asm("D_01d5ba78");
extern W3w1672 D_01d5ba88 asm("D_01d5ba88");
void wt_001d6850(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001d6850jjjj");
void wt_001d6850(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d5ba78.a = 0;
        D_01d5ba78.b = 0;
        D_01d5ba78.c = 108.8f;
    }
    if (b == 0xffff && a == 1) {
        D_01d5ba88.a = 3;
        D_01d5ba88.b = 0;
        D_01d5ba88.c = 112.0f;
    }
}
} // n001d6850

// 001d68c0 (from src/anon/tiny_wrappers_more.cpp)
namespace n001d68c0 {
u32 func_001d6850(u32, u32, u32, u32) asm("func_001d6850");
u32 func_001d68c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d68c0");
u32 func_001d68c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d6850(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n001d68c0
