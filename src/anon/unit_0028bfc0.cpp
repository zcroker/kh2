// Linked unit 0x0028bfc0-0x0028c878 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/select.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/scroll_bar.hpp"

// 0028bfc0 (was src/anon/batch_w85.cpp)
namespace n0028bfc0 {
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
void func_0028eb88(u32, s32, f32, f32) asm("func_0028eb88");
void func_0028e8b8(u32, s32, s32, s32) asm("func_0028e8b8");
struct Bar28b { u32 h; u8 p4[28]; s32 cur; s32 max; u8 p40[4]; s32 a; s32 b; };
/*TARGET 0028bfc0*/
void func_0028bfc0(Bar28b* o, s32 v) asm("func_0028bfc0");
void func_0028bfc0(Bar28b* o, s32 v) {  // int_to_float_clamp
    f32 r, s;
    o->cur = v < o->max ? o->max : v;
    r = (f32)o->max / (f32)v;
    if (func_003142e0(1.0, func_00313b80(r)) <= 0) r = 1.0f;
    s = (f32)o->a / (f32)o->b * r;
    func_0028eb88(o->h, 2, 1.0f, s);
    func_0028e8b8(o->h, 3, 0, (s32)((f32)o->b * s));

}
}  // namespace n0028bfc0

// 0028c0a0 (was src/anon/perm_0028c0a0.cpp)
namespace n0028c0a0 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
void func_00138d60(void *, s32, s32, s32, s32, s32, s32) asm("func_00138d60");
s32 func_00192048(s32) asm("func_00192048");
extern s32 D_0035f3d4 asm("D_0035f3d4");
/*TARGET 0028c0a0*/
void func_0028c0a0(u8 *p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) asm("func_0028c0a0");
void func_0028c0a0(u8 *p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1)
{
  int new_var;
  func_00138d60(p, D_0035f3d4, a2, a3, a1, 0, t1);
  *((u32 *) (p + 0xc)) |= 8;
  new_var = 1;
  if (t0 >= 0)
  {
    *((s32 *) (p + 0x198)) = func_00192048(t0);
  }
  *((u32 *) (p + 0x1a4)) = 0x80e5e5e5;
  *((s32 *) (p + 0x1ac)) = new_var;
}
}  // namespace n0028c0a0

// 0028c120 (was gap, written for the unit)
namespace n0028c120 {
struct MSub { u8 pad[184]; s32 flags; };
struct MI;
typedef void (*MFn)(MI*);
typedef void (*MCb)(s32, s32, s32, s32, MI*);
struct MI { MFn* vt; u8 p4[8]; u32 f12; u8 p16[8]; MSub sub; u8 p212[396 - 212]; void* f396; void* f400; u8 p404[436 - 404]; MCb f436; };
struct MP { u8 pad[14080]; s32 free[32]; s32 n; };
extern MP* D_0035f3c4 asm("D_0035f3c4");
extern s32 D_0035f3cc asm("D_0035f3cc");
void func_0028c120(MI* w) asm("func_0028c120");
void func_0028c120(MI* w) {
    w->f436 = 0;
    MP* p = D_0035f3c4;
    p->free[p->n++] = (MI*)w - (MI*)p;
    D_0035f3cc--;
}
}  // namespace n0028c120

// 0028c170 (was src/anon/batch_w8.cpp)
namespace n0028c170 {
void func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
/*TARGET 0028c170*/
void func_0028c170(void* p) asm("func_0028c170");
void func_0028c170(void* p) {
    func_00139d78(p);
    func_00139510(p);
}
}  // namespace n0028c170

// 0028c198 (was src/anon/batch_wcx2.cpp)
namespace n0028c198 {
// copy_3halfwords_50
u8* func_0023f1b0(u32) asm("func_0023f1b0");
// 0x002c10e0: definition moved into src/anon/unit_002c10e0.cpp

// --------------------
struct S28c198 { u8 pad[184]; u32 flags; void Set() { flags |= 8; } void Clr() { flags &= ~8; } };
struct W28c198 { u8 pad[24]; S28c198 sub; u8 pad2[436 - 24 - 188]; u32 f436; };
struct P28c198 { u8 pad[14080]; s32 free[32]; s32 n; };
extern P28c198* D_0035f3c4 asm("D_0035f3c4");
union C28c198 { s32 i; u32 u; };
extern C28c198 D_0035f3cc asm("D_0035f3cc");
u32 func_0023c4b8_28c198(u8*, u32) asm("func_0023c4b8");
u8* func_00236ca8_28c198(u32, u32) asm("func_00236ca8");
void func_0028c0a0(W28c198*, u32, u32, u8*, u32, u32) asm("func_0028c0a0");
/*TARGET 0028c198*/
W28c198* func_0028c198(u32 id, u32 a, u32 b, u32 bank, u32 c, u32 d) asm("func_0028c198");
W28c198* func_0028c198(u32 id, u32 a, u32 b, u32 bank, u32 c, u32 d)
{
    P28c198* p = D_0035f3c4;
    p->n--;
    W28c198* w = (W28c198*)((u8*)p + p->free[p->n] * 440);
    u32 h = func_0023c4b8_28c198(func_0023f1b0(bank), a);
    u8* z = func_00236ca8_28c198(*(u32*)(func_0023f1b0(bank) + 40), b);
    func_0028c0a0(w, id, h, z, c, d);
    if (z[400]) w->sub.Set();
    else w->sub.Clr();
    w->f436 = 0;
    D_0035f3cc.i++;
    return w;
}
}  // namespace n0028c198

// 0028c2c8 (was src/anon/batch_w1593.cpp)
namespace n0028c2c8 {
// ---- 0028c2c8
struct S28c2c8 { u8 pad[184]; u32 flags; void Set() { flags |= 8; } void Clr() { flags &= ~8; } };
struct W28c2c8 { u8 pad[24]; S28c2c8 sub; u8 pad2[436 - 24 - 188]; u32 f436; };
struct P28c2c8 { u8 pad[14080]; s32 free[32]; s32 n; };
extern P28c2c8* D_0035f3c4 asm("D_0035f3c4");
union C28c2c8 { s32 i; u32 u; };
extern C28c2c8 D_0035f3cc asm("D_0035f3cc");
void func_0028c0a0(W28c2c8*, u32, u32, u8*, u32, u32) asm("func_0028c0a0");
/*TARGET 0028c2c8*/
W28c2c8* func_0028c2c8(u32 h, u8* z, u32 id, u32 c, u32 d) asm("func_0028c2c8");
W28c2c8* func_0028c2c8(u32 h, u8* z, u32 id, u32 c, u32 d)
{
    P28c2c8* p = D_0035f3c4;
    p->n--;
    W28c2c8* w = (W28c2c8*)((u8*)p + p->free[p->n] * 440);
    func_0028c0a0(w, id, h, z, c, d);
    if (z[400]) w->sub.Set();
    else w->sub.Clr();
    w->f436 = 0;
    D_0035f3cc.i++;
    return w;
}
}  // namespace n0028c2c8

// 0028c380 (was gap, written for the unit)
namespace n0028c380 {
struct MSub { u8 pad[184]; s32 flags; };
struct MI;
typedef void (*MFn)(MI*);
typedef void (*MCb)(s32, s32, s32, s32, MI*);
struct MI { MFn* vt; u8 p4[8]; u32 f12; u8 p16[8]; MSub sub; u8 p212[396 - 212]; void* f396; void* f400; u8 p404[436 - 404]; MCb f436; };
struct MP { u8 pad[14080]; s32 free[32]; s32 n; };
extern MP* D_0035f3c4 asm("D_0035f3c4");
extern s32 D_0035f3cc asm("D_0035f3cc");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028c380(MI* w) asm("func_0028c380");
void func_0028c380(MI* w) {
    if (func_00139d78(w)) w->vt[5](w);
    MP* p = D_0035f3c4;
    p->free[p->n++] = (MI*)w - (MI*)p;
}
}  // namespace n0028c380

// 0028c3f0 (was src/anon/batch_w252.cpp)
namespace n0028c3f0 {
extern void* D_0035f3c4 asm("D_0035f3c4");
extern void* D_0035f3c8 asm("D_0035f3c8");
extern s32 D_0035f3cc asm("D_0035f3cc");
extern s32 D_0035f3d0 asm("D_0035f3d0");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f3e0[] asm("D_0035f3e0");
void* func_001063c0(u32, s32) asm("func_001063c0");
void func_00239700(void*) asm("func_00239700");
struct W252Sub { W252Sub() { func_00239700(this); } u8 pad[0x180]; };
struct W252Base {
    void* vt; u32 a, b; s32 c; u32 d, e;
    inline W252Base() __attribute__((always_inline));
};
struct W252Item : W252Base {
    W252Sub m;
    s32 f; u32 pad[7];
    inline W252Item() __attribute__((always_inline));
};
struct W252Pool {
    W252Item items[32];
    s32 ids[32];
    s32 count;
    inline W252Pool() __attribute__((always_inline));
    void* operator new(unsigned int sz, s32 h) { return func_001063c0(sz, h); }
};
inline W252Base::W252Base() { c = 0; vt = D_00347e60; }
inline W252Item::W252Item() { f = 0; vt = D_0035f3e0; }
inline W252Pool::W252Pool() { for (s32 i = 0; i < 32; i++) ids[i] = i; count = 32; }
/*TARGET 0028c3f0*/
void func_0028c3f0(s32 h) asm("func_0028c3f0");
void func_0028c3f0(s32 h) {
    if (D_0035f3c4) {
        D_0035f3c8 = D_0035f3c4;
        D_0035f3d0 = D_0035f3cc;
    }
    D_0035f3cc = 0;
    *(s32*)&D_0035f3c4 = (s32)new (h) W252Pool;
}
}  // namespace n0028c3f0

// 0028c4f8 (was src/anon/batch_w86.cpp)
namespace n0028c4f8 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[436]; };
extern Elem* D_0035f3c4 asm("D_0035f3c4");
extern Elem* D_0035f3c8 asm("D_0035f3c8");
extern s32 D_0035f3cc asm("D_0035f3cc");
extern s32 D_0035f3d0 asm("D_0035f3d0");
void func_00106420(void*) asm("func_00106420");
void menuitem_update(void) asm("_ZN2Tz8MenuItem6updateEv");
static inline void Release()
{
    Elem* a = D_0035f3c4;
    if (a) {
        Elem* e = a + 32;
    next:
        if (a != e) {
            --e;
            e->vt[3](e);
            goto next;
        }
        func_00106420(a);
        D_0035f3c4 = 0;
    }
}
/*TARGET 0028c4f8*/
void menuitem_update(void) asm("_ZN2Tz8MenuItem6updateEv");
void menuitem_update(void)
{
    if (D_0035f3c8) {
        Release();
        D_0035f3c4 = D_0035f3c8;
        D_0035f3cc = D_0035f3d0;
        D_0035f3c8 = 0;
        D_0035f3d0 = 0;
    } else {
        Release();
        D_0035f3c4 = 0;
    }
}
}  // namespace n0028c4f8

// 0028c5d8 (was gap, written for the unit)
namespace n0028c5d8 {
struct MSub { u8 pad[184]; s32 flags; };
struct MI;
typedef void (*MFn)(MI*);
typedef void (*MCb)(s32, s32, s32, s32, MI*);
struct MI { MFn* vt; u8 p4[8]; u32 f12; u8 p16[8]; MSub sub; u8 p212[396 - 212]; void* f396; void* f400; u8 p404[436 - 404]; MCb f436; };
struct MP { u8 pad[14080]; s32 free[32]; s32 n; };
extern MP* D_0035f3c4 asm("D_0035f3c4");
extern s32 D_0035f3cc asm("D_0035f3cc");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00239d10(void*) asm("func_00239d10");
void func_001390a8(void*) asm("func_001390a8");
void func_00139570(void*) asm("func_00139570");
void func_0028c5d8(MI* o) asm("func_0028c5d8");
void func_0028c5d8(MI* o) {
    if ((o->f396 && !func_00139d78(o->f396)) || (o->f400 && !func_00239d10(o->f400))) {
        if (o->f12 & 0x80) func_00139570(o);
        else o->vt[5](o);
        return;
    }
    func_001390a8(o);
}
}  // namespace n0028c5d8

// 0028c678 (was gap, written for the unit)
namespace n0028c678 {
struct MSub { u8 pad[184]; s32 flags; };
struct MI;
typedef void (*MFn)(MI*);
typedef void (*MCb)(s32, s32, s32, s32, MI*);
struct MI { MFn* vt; u8 p4[8]; u32 f12; u8 p16[8]; MSub sub; u8 p212[396 - 212]; void* f396; void* f400; u8 p404[436 - 404]; MCb f436; };
struct MP { u8 pad[14080]; s32 free[32]; s32 n; };
extern MP* D_0035f3c4 asm("D_0035f3c4");
extern s32 D_0035f3cc asm("D_0035f3cc");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00239d10(void*) asm("func_00239d10");
s32 func_00287ec8(void) asm("func_00287ec8");
void func_00287eb8(s32) asm("func_00287eb8");
void func_00236d60(void) asm("func_00236d60");
void func_00138988(void*) asm("func_00138988");
s32 func_00138de0(void*) asm("func_00138de0");
void func_00138c90(void*, s32*, s32*) asm("func_00138c90");
s32 func_0023a918(void*) asm("func_0023a918");
void func_0028c678(MI* o) asm("func_0028c678");
void func_0028c678(MI* o) {
    if (o->f396 && !func_00139d78(o->f396)) return;
    MSub* s = &o->sub;
    if (o->f400 && !func_00239d10(o->f400)) return;
    u8 b = (s->flags >> 3) & 1;
    if (func_00287ec8()) {
        func_00236d60();
        if (!b) s->flags |= 8;
    }
    func_00138988(o);
    s32 r = func_00138de0(o);
    if (o->f436) {
        s32 x, y;
        func_00138c90(o, &x, &y);
        s32 v = 0;
        if (o->f396) v = func_0023a918((u8*)o->f396 + 24);
        else if (o->f400) v = func_0023a918(o->f400);
        o->f436(x, y, r, v, o);
    }
    if (func_00287ec8()) {
        if (!b) s->flags &= ~8;
        func_00287eb8(0);
    }
}
}  // namespace n0028c678

// 0028c7c0 (was src/anon/auto80_199_queue.cpp)
namespace n0028c7c0 {
/*TARGET 0028c7c0*/
void func_0028c7c0(s32 a0, s32 a1) asm("_Z13func_0028c7c0ii");
void func_0028c7c0(s32 a0, s32 a1) {
    s32 s0 = a1;
    s32 s1 = a0;

    if (a1 == 0xFFFF) {
        if (a0 == 1) {
            func_0023f800((u32)&D_0035f3a8);
        }
    }

    if (s0 == 0xFFFF) {
        if (s1 == 0) {
            func_0023f848((u32)&D_0035f3a8);
        }
    }
}
}  // namespace n0028c7c0

// 0028c838 (was src/anon/tiny_wrappers_more.cpp)
namespace n0028c838 {
u32 func_0028c7c0(u32, u32, u32, u32) asm("_Z13func_0028c7c0jjjj");
/*TARGET 0028c838*/
u32 func_0028c838(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0028c838jjjj");
u32 func_0028c838(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0028c7c0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0028c838

// 0028c858 (was gap, written for the unit)
namespace n0028c858 {
u32 func_0028c7c0(u32, u32, u32, u32) asm("_Z13func_0028c7c0jjjj");
u32 func_0028c858(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0028c858");
u32 func_0028c858(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0028c7c0(0, 0xffff, a2, a3);
}
}  // namespace n0028c858

