// Linked unit 0x0029f938-0x002a0908 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_diagram.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/jm_treasure.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0029f938 (was src/anon/batch_wcx2.cpp)
namespace n0029f938 {
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
// 0x002618d8: definition moved into src/anon/unit_0025f6b8.cpp

// --------------------
extern s32 D_0035f200_29f asm("D_0035f200");
s32 func_00289380_x9795(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_00276368() asm("func_00276368");
s32 func_0028acc8_x9799(s32) asm("func_0028acc8");
s32 func_00276888() asm("func_00276888");
void func_00287f90(s32) asm("func_00287f90");
void func_0029ee38() asm("func_0029ee38");
void func_00287c30() asm("func_00287c30");
void func_0028af18_x9804(s32, s32) asm("func_0028af18");
s32 func_00276358() asm("func_00276358");
void func_00276220(s32, s32) asm("func_00276220");
void func_00276690(s32) asm("func_00276690");
void func_002766b0(s32) asm("func_002766b0");
void func_0028b1e8(s32, s32) asm("func_0028b1e8");
void func_0029ee68() asm("func_0029ee68");
void func_0029f520() asm("func_0029f520");
s32 func_00289310_x9812(s32) asm("func_00289310");
s32 func_00276398() asm("func_00276398");
void func_00275b60() asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
void func_002a0518() asm("func_002a0518");
s32 func_00287df0_29f(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0029fee8(s32) asm("func_0029fee8");
void func_0029ee30() asm("func_0029ee30");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002891e8_x9823(s32) asm("func_002891e8");
s32 func_0028b038_x9824(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_00287da0() asm("func_00287da0");
void func_00276dc0() asm("func_00276dc0");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0029f938*/
void func_0029f938() asm("func_0029f938");
void func_0029f938() {
    s32 r = func_00289380_x9795(D_0035f200_29f);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_00276368() || func_0028acc8_x9799(D_0035f200_29f) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_0029ee38();
            }
            return;
        }
        func_0029ee38();
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x9804(D_0035f200_29f, 115);
        func_00276220(func_00276358(), 0);
        func_00276690(0);
        func_002766b0(1);
        if (s == 24) {
            func_0028b1e8(D_0035f200_29f, 1);
            func_0029ee68();
        } else if (s == 25) {
            func_0029f520();
        }
        return;
    }
    if (r != -1 || func_00289310_x9812(D_0035f200_29f)) {
        if (!func_00276398()) {
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_29f(r, func_00289310_x9812(D_0035f200_29f), 1, func_002a0518, 1))) {
        switch (r) {
        case -4: {
            s32 s = func_00287bc0();
            s32 n = func_002891e8_x9823(D_0035f200_29f);
            func_002765e8(s, n, func_0028b038_x9824(D_0035f200_29f));
            func_00287da0();
            break;
        }
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            func_0029fee8(r);
            func_0029ee30();
            func_00276220(r != -10, 1);
            func_00287c00(25);
            func_00287cc0(2);
            break;
        case -2:
            func_0029ee30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(24);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029f938
#undef QCOPY

// 0029fbf0 (was src/anon/batch_wcx2.cpp)
namespace n0029fbf0 {
// ---- 00295158
u8* func_00294000(u32) asm("func_00294000");
s32 func_00276c18() asm("func_00276c18");
// 0x00295158: definition moved into src/anon/unit_00292e60.cpp
// ---- 0029fbf0
s32 func_002943e8(u8*) asm("func_002943e8");
extern u8* D_0035f5d0 asm("D_0035f5d0");
/*TARGET 0029fbf0*/
void func_0029fbf0() asm("func_0029fbf0");
void func_0029fbf0() {
    s32 i = 0;
    s32 n = 0;
    u8* t = func_00294000(4);
    D_0035f5d0[0] = 0;
    u8* base = t + 16;
    for (; i < *(s32*)(t + 8); i++) {
        if (func_002943e8(base + i * 8) || func_00276c18()) {
            D_0035f5d0[n + 6] = i;
            n++;
        }
    }
    D_0035f5d0[0] = n;
}
}  // namespace n0029fbf0

// 0029fcb0 (was src/anon/batch_w3840_mam.cpp)
namespace n0029fcb0 {
struct E { u8 b[64]; };
struct W { u8 pad[0x110a0]; E e[10]; };
struct L { s8 n; u8 pad[5]; s8 id[1]; };
W* func_002766d0(void) asm("func_002766d0");
s32 func_0028b038(s32) asm("func_0028b038");
void func_0028be78(s32, s32) asm("func_0028be78");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_002892f8(s32) asm("func_002892f8");
void func_00138c10(u8*, s32) asm("func_00138c10");
u8* func_002a01c8(s32) asm("func_002a01c8");
s32 func_002943e8(u8*) asm("func_002943e8");
s32 func_00192048(s32) asm("func_00192048");
void func_00192c90(s32, E*) asm("func_00192c90");
void func_0028de08(s32, E*, s32) asm("func_0028de08");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_002aa2f8(s32) asm("func_002aa2f8");
s32 func_002aa378(s32) asm("func_002aa378");
extern s32 D_0035f200 asm("D_0035f200");
extern s32 D_0035f214 asm("D_0035f214");
extern L* D_0035f5d0 asm("D_0035f5d0");
extern s32 D_00374b1c asm("D_00374b1c");
extern s32 D_00374b20 asm("D_00374b20");
/*TARGET 0029fcb0*/
// Rebuilds the menu entry list from D_0035f5d0 (up to 10 entries) and their highlight colours.
void func_0029fcb0(void) asm("func_0029fcb0");
// Rebuilds the menu entry list from D_0035f5d0 (up to 10 entries) and their highlight colours.
void func_0029fcb0(void) {
    W* w = func_002766d0();
    s32 m = func_0028b038(D_0035f200);
    func_0028be78(D_0035f214, m);
    func_002fde18(w->e, 0, 640);
    s32 c = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < c; i++) {
        func_00138c10((u8*)w + 0xa998 + i * 0x198, 2);
    }
    s32 n = 0;
    s32 cnt = D_0035f5d0->n;
    s32 k = 0;
    i = 0;
    for (; i < cnt && n < 10; i++) {
        if (i < m) continue;
        u16 id = *(u16*)(func_002a01c8(D_0035f5d0->id[i]) + 2);
        s32 f = func_002943e8(func_002a01c8(D_0035f5d0->id[i]));
        if (f) {
            func_00192c90(func_00192048(id), &w->e[n]);
        } else {
            func_0028de08(id, &w->e[n], 64);
        }
        *(E**)(func_002891b8(D_0035f200, n) + 0x198) = &w->e[n]; n++;
        if (f && func_002aa2f8(D_0035f5d0->id[i])) {
            func_00138c10((u8*)w + 0xa998 + k * 0x198, func_002aa378(D_0035f5d0->id[i]) ? D_00374b20 : D_00374b1c);
        }
        k++;
        asm("" :: "r"(cnt));
    }
}
}  // namespace n0029fcb0

// 0029fee8 (was src/anon/batch_w1605.cpp)
namespace n0029fee8 {
// 0x0026e638: definition moved into src/anon/unit_0026c450.cpp
// ---- 0029fee8
struct List29f {
    s8 count;
    u8 pad[5];
    s8 items[1];
};
s32 func_00276620(s32) asm("func_00276620");
s32 func_00276638(s32) asm("func_00276638");
s32 func_002a01c8(s32) asm("func_002a01c8");
s32 func_002943e8(s32) asm("func_002943e8");
extern List29f* D_0035f5d0 asm("D_0035f5d0");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002a03d0(void) asm("func_002a03d0");
/*TARGET 0029fee8*/
void func_0029fee8(s32 dir) asm("func_0029fee8");
void func_0029fee8(s32 dir)
{
    s32 top = func_00276620(24);
    s32 cur = func_00276638(24);
    s32 i;

    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5d0->count; i++) {
            if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
        }
        if (i >= D_0035f5d0->count) {
            for (i = 0; i < cur; i++) {
                if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
            }
        }
        if (i < D_0035f5d0->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i++)  /* sic: original counts up here */ {
            if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
        }
        if (i < 0) {
            for (i = D_0035f5d0->count - 1; i > cur; i--) {
                if (func_002943e8(func_002a01c8(D_0035f5d0->items[i]))) break;
            }
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5d0->count - 1;
            top = D_0035f5d0->count - 11;
        }
    }
    if (cur - top >= 10) {
        top += cur - top - 9;
    } else if (cur - top < 0) {
        top += cur - top;
    }
    func_002765e8(24, cur - top, top);
    func_002a03d0();
}
}  // namespace n0029fee8

// 002a00f0 (was src/anon/batch_w47.cpp)
namespace n002a00f0 {
// 0x00292eb0: definition moved into src/anon/unit_00292e60.cpp

extern s8* D_0035f5d0 asm("D_0035f5d0");
s32 func_002a01c8(s32) asm("func_002a01c8");
// obj4_entry_by_index
s32 func_002943e8(s32) asm("func_002943e8");
/*TARGET 002a00f0*/
s32 func_002a00f0(void) asm("func_002a00f0");
s32 func_002a00f0(void) {
    s32 n = 0;
    for (s32 i = 0; i < D_0035f5d0[0]; i++) {
        if (func_002943e8(func_002a01c8(D_0035f5d0[i + 6]))) n++;
    }
    return n;
}
}  // namespace n002a00f0

// 002a0168 (was src/anon/batch_w48.cpp)
namespace n002a0168 {
// 0x002953c8: definition moved into src/anon/unit_00292e60.cpp

void func_0029fcb0(void*) asm("func_0029fcb0");
void func_002a03d0(void) asm("func_002a03d0");
s32 func_0028b038(void*) asm("func_0028b038");
void func_0028be78(void*, s32) asm("func_0028be78");
extern void* D_0035f200 asm("D_0035f200");
extern void* D_0035f214 asm("D_0035f214");
/*TARGET 002a0168*/
void func_002a0168(void* o, s32 msg) asm("func_002a0168");
void func_002a0168(void* o, s32 msg) {
    switch (msg) {
    case 24:
        func_0029fcb0(o);
        func_002a03d0();
        break;
    case 25:
        func_0028be78(D_0035f214, func_0028b038(D_0035f200));
        break;
    }
}
}  // namespace n002a0168

// 002a01c8 (was src/anon/batch_w18.cpp)
namespace n002a01c8 {
// 0x0029e3a0: definition moved into src/anon/unit_0029d008.cpp

u8* func_00294000(u32) asm("func_00294000");
/*TARGET 002a01c8*/
u8* func_002a01c8(s32 i) asm("func_002a01c8");
u8* func_002a01c8(s32 i) {  // obj4_entry_by_index
    u8* b = func_00294000(4) + 16;
    return b + i * 8;
}
}  // namespace n002a01c8

// 002a0200 (was src/anon/batch_w1600.cpp)
namespace n002a0200 {
u8 *func_002766d0(void) asm("func_002766d0");
s32 func_0028b040(s32) asm("func_0028b040");
extern s32 D_0035f200 asm("D_0035f200");
extern u8 *D_0035f224 asm("D_0035f224");
extern u8 *D_0035f5d0 asm("D_0035f5d0");
void func_0014b950(u8 *, s16, s16, u16, u16) asm("func_0014b950");
void func_0014b9a8(u8 *) asm("func_0014b9a8");
s32 func_0023aa58(u8 *) asm("func_0023aa58");
s32 func_0023aa78(u8 *) asm("func_0023aa78");
u8 *func_001aae68(s32) asm("func_001aae68");
s32 func_00192048(s32) asm("func_00192048");
void func_001a98e8(void *, s32, s32, s32, s32) asm("func_001a98e8");
void func_001aa6d0(void *, s32) asm("func_001aa6d0");
void func_001a9ae8(void *, s32, s32, s32) asm("func_001a9ae8");
/*TARGET 002a0200*/
void func_002a0200(s32 a0, s32 a1, s32 a2) asm("func_002a0200");
void func_002a0200(s32 a0, s32 a1, s32 a2)
{
  u8 buf[96];
  s32 h = 15;
  u8 *p = func_002766d0() + 24;
  s32 w = func_0028b040(D_0035f200);
  u16 x2 = 512 - a0;
  s32 *new_var;
  s32 n;
  s32 m;
  s32 y;
  u8 *q;
  func_0014b950(D_0035f224 + 32, a0, a1, x2, (*((s8 *) (D_0035f5d0 + 2))) * 9);
  func_0014b9a8(D_0035f224 + 32);
  n = func_0023aa58(p);
  m = func_0023aa78(p);
  if (n)
  {
    h = n;
  }
  w = w * m;
  y = m;
  a1 -= w;
  q = func_001aae68(3);
  y = (y - h) - (*((s32 *) (q + 20)));
  y = (y < 0) ? 0 : y;
  func_001a98e8(buf, 3, func_00192048(*((u16 *) (D_0035f5d0 + 4))), h, 0);
  new_var = &a1;
  func_001aa6d0(buf, y);
  func_001a9ae8(buf, a0, *new_var, a2);
  func_0014b9a8(D_0035f224);
}
}  // namespace n002a0200

// 002a0360 (was src/anon/batch_w19.cpp)
namespace n002a0360 {
// clear_global_flag_return_m1
s32 func_00276c18(void) asm("func_00276c18");
extern s8* D_0035f5d0 asm("D_0035f5d0");
/*TARGET 002a0360*/
// 0x00287d68: definition moved into src/anon/unit_00286d28.cpp

s32 func_002a0360(void) asm("func_002a0360");
// 0x00287d68: definition moved into src/anon/unit_00286d28.cpp

s32 func_002a0360(void) {
    s8 c = *D_0035f5d0;
    if (func_00276c18()) return 1;
    return c != 0;
}
}  // namespace n002a0360

// 002a03a0 (was src/anon/batch_w17.cpp)
namespace n002a03a0 {
// 0x0029e2f8: definition moved into src/anon/unit_0029d008.cpp

u32 func_00287bc0(void) asm("func_00287bc0");
void func_00276c50(u32, u32) asm("func_00276c50");
/*TARGET 002a03a0*/
void func_002a03a0(void) asm("func_002a03a0");
void func_002a03a0(void) {
    func_00276c50(func_00287bc0() == 24 ? 18668 : 18669, 0);
}
}  // namespace n002a03a0

// 002a03d0 (was src/anon/batch_w3724_g.cpp)
namespace n002a03d0 {
extern s32 D_0035f200 asm("D_0035f200");
extern s8 *D_0035f5d0 asm("D_0035f5d0");
struct Sram { u8 pad[316]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void) asm("func_002a9d68");
Seq *func_002766d0(void) asm("func_002766d0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00276638(s32) asm("func_00276638");
s32 func_002a01c8(s32) asm("func_002a01c8");
s32 func_002943e8(s32) asm("func_002943e8");
void func_002aa450(s32) asm("func_002aa450");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00139d78(Ent *) asm("func_00139d78");
void func_00138c10(Ent *, s32) asm("func_00138c10");
/*TARGET 002a03d0*/
// Register pin: idx in s1 (the original keeps the D_0035f5d0 %hi in s0).
void func_002a03d0(void) asm("func_002a03d0");
// Register pin: idx in s1 (the original keeps the D_0035f5d0 %hi in s0).
void func_002a03d0(void)
{
  register s32 idx asm("$17");
  Sram *a = func_002a9d68();
  Seq *b = func_002766d0();
  s32 c = func_00287bc0();
  if (c == 24) idx = func_0028b040(D_0035f200);
  else idx = func_00276638(24);
  if (!func_002943e8(func_002a01c8(D_0035f5d0[idx + 6]))) return;
  s32 k = D_0035f5d0[idx + 6];
  u32* q = &a->bits[(u32)k >> 5]; if (*q & (1 << (k & 31))) return;
  func_002aa450(k);
  if (c != 24) return;
  s32 m = 408;
  m = func_002891e8(D_0035f200) * m;
  Ent *p = (Ent*)((u8*)b + m + 0xa998);
  if (func_00139d78(p)) func_00138c10(p, 93);
}
}  // namespace n002a03d0

// 002a0518 (gap: diagram select-check callback)
namespace g002a0518 {
extern u8* D_0035f5d0 asm("D_0035f5d0");
u32 func_00287bc0(void) asm("func_00287bc0");
void* func_002a01c8(s32) asm("func_002a01c8");
s32 func_002943e8(void*) asm("func_002943e8");
s32 cb(s32 a0) asm("D_002a0518");
s32 cb(s32 a0) {
    s32 r;
    u32 m;
    if (a0 < 0) return 1;
    m = func_00287bc0();
    if (m == 24) goto c24;
    r = 1;
    if (m != 25) goto zero;
done:
    return r;
c24:
    r = func_002943e8(func_002a01c8(((s8*)D_0035f5d0)[a0 + 6])) != 0;
    goto done;
zero:
    r = 0;
    goto done;
}
}  // namespace g002a0518

// 002a0588 (was src/anon/perm_002a0588.cpp)
namespace n002a0588 {
typedef unsigned char u8;
typedef signed int s32;
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern void *D_0035f5d4 asm("D_0035f5d4");
extern void *D_0035f5d8 asm("D_0035f5d8");
extern void *D_0035f5dc asm("D_0035f5dc");
extern u8 D_0035f5e0 asm("D_0035f5e0");
extern u8 D_0035f5e1 asm("D_0035f5e1");
s32 func_00103570(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void *func_001063c0(s32, s32) asm("_ZN2Tz13LoadDataAllocEjj");
void func_00239700(void *) asm("func_00239700");
void func_0031a838(void *) asm("_Z10ErrorRaisePv");
void func_0023f800(void *) asm("_ZN2Tz7LayFileC1Ev");
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
/*TARGET 002a0588*/
void func_002a0588(void) asm("func_002a0588");
void func_002a0588(void)
{
  u8 (*new_var)[];
  D_0035f5d4 = func_001063c0(0x150, func_00103570());
  u8 *p = (u8 *) func_001063c0(0x67c, func_00103570());
  *((u8 **) p) = D_00347e60;
  *((s32 *) (p + 0xc)) = 0;
  new_var = &D_00347f98;
  func_00239700(p + 0x18);
  *((u8 **) (p + 0x198)) = *new_var;
  func_0031a838(p + 0x1a4);
  *((u8 **) (p + 0x198)) = D_00347e60;
  func_00239700(p + 0x1b0);
  *((u8 **) (p + 0x330)) = D_00347f98;
  func_0031a838(p + 0x33c);
  *((u8 **) (p + 0x330)) = D_00347e60;
  func_00239700(p + 0x348);
  u8 *c = p + 0x4c8;
  *((u8 **) (p + 0x4c8)) = D_00347f98;
  func_0031a838(p + 0x4d4);
  *((u8 **) (p + 0x4c8)) = D_00347e60;
  func_00239700(p + 0x4e0);
  *((s32 *) (c + 0x198)) = 0;
  D_0035f5d8 = p;
  *((u8 **) c) = D_00347e40;
  void *q = func_001063c0(0x1c, func_00103570());
  func_0023f800(q);
  void *h = D_0035f5d4;
  D_0035f5dc = q;
  D_0035f5e0 = 0;
  D_0035f5e1 = 0;
  func_002fde18(h, 0, 0x150);
}
}  // namespace n002a0588

// 002a06b8 (was src/anon/batch_w1594.cpp)
namespace n002a06b8 {
struct V2a { u8 pad[4]; void (*f)(void*); };
// 0x002588e8: definition moved into src/anon/unit_002588e8.cpp

void func_00106420(void*) asm("func_00106420");
void func_0031acc0(u8*) asm("func_0031acc0");
void func_0031abd8(u8*) asm("func_0031abd8");
void func_00239870(u8*) asm("func_00239870");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
extern void* D_0035f5d4 asm("D_0035f5d4");
extern u8* D_0035f5d8 asm("D_0035f5d8");
extern V2a** D_0035f5dc asm("D_0035f5dc");
extern u8 D_0035f5e0 asm("D_0035f5e0");
extern u8 D_0035f5e1 asm("D_0035f5e1");
/*TARGET 002a06b8*/
// Frees the three globals and clears two flags; the middle object's destructor is inlined.
void func_002a06b8(void) asm("func_002a06b8");
// Frees the three globals and clears two flags; the middle object's destructor is inlined.
void func_002a06b8(void) {
    if (D_0035f5d4) {
        func_00106420(D_0035f5d4);
        D_0035f5d4 = 0;
    }
    u8* p = D_0035f5d8;
    if (p) {
        func_0031acc0(p + 1224);
        func_0031abd8(p + 816);
        func_0031abd8(p + 408);
        *(u32*)p = (u32)&D_00347e60;
        func_00239870(p + 24);
        *(u32*)p = (u32)&D_00347f98;
        func_00106420(p);
        D_0035f5d8 = 0;
    }
    if (D_0035f5dc) {
        (*D_0035f5dc)->f(D_0035f5dc);
        D_0035f5dc = 0;
    }
    D_0035f5e0 = 0;
    D_0035f5e1 = 0;
}
}  // namespace n002a06b8

// 002a0780 (was src/tozawa/jm_diagram.cpp)
namespace Tz { // method 002a0780
extern u32 D_0035f5d8 asm("D_0035f5d8");
u32 func_00139d78(u32) asm("func_00139d78");
void func_00139510(u32) asm("func_00139510");
u32 func_00287bc0() asm("func_00287bc0");
/*TARGET 002a0780*/
void JmDiagram_FadeOutAll(void) asm("_ZN2Tz9JmDiagram10FadeOutAllEv");
void JmDiagram_FadeOutAll(void) {
    u32 v0 = func_00287bc0();
    if (v0 == 6 || v0 == 12 || v0 == 40) {
        u32* s0 = &D_0035f5d8;
        if (func_00139d78(*s0 + 816) != 0) {
            func_00139510(*s0 + 816);
        }
    }
}
}  // Tz

// 002a07f0 (was src/anon/auto80_199_queue.cpp)
namespace n002a07f0 {
/*TARGET 002a07f0*/
void func_002a07f0(u32 a0) asm("_Z13func_002a07f0j");
void func_002a07f0(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_00287bc0();

    if (v0 == 6 || v0 == 12 || v0 == 40) {
        func_002a1c68();
        func_00274ac8();
        if (s0 != 16) {
            func_0028f7e8(0);
        }
        func_002a0860();
    }
}
}  // namespace n002a07f0

// 002a0860 (was src/anon/batch_wcx.cpp)
namespace n002a0860 {
// 0x00273180: definition moved into src/anon/unit_00271e08.cpp
extern u8* D_0035f5d8 asm("D_0035f5d8");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(u8*) asm("func_00139510");
/*TARGET 002a0860*/
void func_002a0860(void) asm("func_002a0860");
void func_002a0860(void)
{
    if (!D_0035f5d8) return;
    if (u_call4_00139d78(D_0035f5d8)) func_00139510(D_0035f5d8);
    if (u_call4_00139d78(D_0035f5d8 + 408)) func_00139510(D_0035f5d8 + 408);
    if (u_call4_00139d78(D_0035f5d8 + 816)) func_00139510(D_0035f5d8 + 816);
    if (u_call4_00139d78(D_0035f5d8 + 1224)) func_00139510(D_0035f5d8 + 1224);
}
}  // namespace n002a0860

