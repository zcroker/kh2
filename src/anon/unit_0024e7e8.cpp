// Linked unit 0x0024e7e8-0x0024f710 (one namespace per old matched source; class methods in their own namespace).
#include "../tozawa/smenu_ttpt.hpp"
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/smenu_ttmy.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/smenu_lm.hpp"

// 0024e7e8 (was src/tozawa/smenu_ttmy.cpp)
namespace Tz { // method 0024e7e8
extern u32 D_0035ee00 asm("D_0035ee00");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void func_0024e850() asm("func_0024e850");
u32 func_0024ebc0() asm("func_0024ebc0");
void func_0024edd8() asm("func_0024edd8");
/*TARGET 0024e7e8*/
void TTMY::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee00);
    func_00102448(s0, 1);
    func_0024e850();
    while (1) {
        if (func_0024ebc0() != 0) {
            return;
        }
        func_0024edd8();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 0024e850 (was src/anon/perm_0024e850.cpp)
namespace n0024e850 {
struct Heap24e850;
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct Heap24e850Vt
{
  u8 *(*alloc)(Heap24e850 *, s32, s32);
};
struct Heap24e850
{
  Heap24e850Vt *vt;
};
struct Sys24e850
{
  u8 pad[20];
  Heap24e850 *heap;
};
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8 *D_0035ee08 asm("D_0035ee08");
extern u8 *D_0035ee0c asm("D_0035ee0c");
extern u32 D_0035ee04 asm("D_0035ee04");
extern Sys24e850 *D_00347f80 asm("D_00347f80");
extern u8 D_00372380 asm("D_00372380");
extern u8 D_00372388 asm("D_00372388");
u8 *func_0023ee30(s32) asm("func_0023ee30");
void func_002369a0(u8 *) asm("func_002369a0");
void func_0023c008(u8 *) asm("func_0023c008");
void func_0028d7f0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d7f0");
void func_00288ce0(u32, s32, s32, s32, s32) asm("func_00288ce0");
void func_002891f0(u32, s32, s32, s32, s32) asm("func_002891f0");
s32 func_002891e8(u32) asm("_ZN2Tz6Select10GetCurrentEv");
void func_0024f348(void) asm("func_0024f348");
void func_0023f1e0(u8 *, s32, u8 *, void *, void *, s32, s32, s32) asm("func_0023f1e0");
void func_0023f6c0(u8 *, s32) asm("func_0023f6c0");
void func_00287cc0(s32) asm("_ZN2Tz8Selector8SetStateEi");
/*TARGET 0024e850*/
void func_0024e850(void) asm("func_0024e850");
void func_0024e850(void)
{
  u8 *o;
  u8 *p;
  s32 i;
  o = func_0023ee30(160);
  *((u32 *) (o + 12)) = 0;
  *((u8 **) o) = D_0035eb98;
  func_002369a0(o + 24);
  func_0023c008(o + 48);
  p = o;
  D_0035ee08 = o;
  func_0028d7f0(p, 30002, 0, 0, 0, 1, 0, 0, 0);
  for (i = 0; i < 5; i++)
  {
    func_00288ce0(D_0035ee04, 0, i, 0, 0);
  }

  func_002891f0(D_0035ee04, 0, 0, -1, -1);
  func_0024f348();
  func_002891f0(D_0035ee04, func_002891e8(D_0035ee04), 0, -1, -1);
  p = D_00347f80->heap->vt->alloc(D_00347f80->heap, 76, 0);
  *((u32 *) (p + 12)) = 0;
  *((u8 **) p) = D_0035ebb8;
  D_0035ee0c = p;
  func_0023f1e0(p, 30003, D_0035ee08, &D_00372380, &D_00372388, -1, 0, 0);
  func_0023f6c0(D_0035ee0c, 2);
  func_00287cc0(0);
}
}  // namespace n0024e850

// 0024e9c0 (was src/anon/batch_w87.cpp)
namespace n0024e9c0 {
// 0x0024bbb0: definition moved into src/anon/unit_0024ba58.cpp

// ---- 0x24e9c0 ----
s32 func_001a6d08(s32) asm("func_001a6d08");
union UP { u8* p; s32 i; };
extern s32 D_00372308[] asm("D_00372308");
extern UP D_0035ee18[] asm("D_0035ee18");
extern s32 D_0035ee08 asm("D_0035ee08");
u8* func_0028c198(s32, s32, s32, s32, s32, s32) asm("func_0028c198");
s32 func_0024efc0(s32) asm("func_0024efc0");
// to_28dbf8_entry6
void func_001396b0(void*) asm("func_001396b0");
void func_0031ac78(void*, s32) asm("func_0031ac78");
/*TARGET 0024e9c0*/
void func_0024e9c0(void) asm("func_0024e9c0");
void func_0024e9c0(void) {
    for (s32 i = 0; i < 5; i++) {
        s32 id = D_00372308[i];
        if (id == 0 || func_001a6d08(id)) {
            D_0035ee18[i].p = func_0028c198(0, 2, 2, D_0035ee08, -1, 0);
            ((UP*)(D_0035ee18[i].p + 392))->i = 1;
            u8* o = D_0035ee18[i].p;
            *(s32*)(o + 400) = func_0024efc0(i);
            func_001396b0(o);
            if (*(s32*)(o + 400)) {
                *(s32*)(o + 396) = 0;
                func_001396b0(o);
                if (*(s32*)(o + 396)) func_0031ac78(o, 0);
            }
        }
    }
}
}  // namespace n0024e9c0

// 0024eac0 (was src/anon/batch_w54.cpp)
namespace n0024eac0 {
s32 func_00139d78(void*) asm("func_00139d78");
extern u8* D_0035ee18[5] asm("D_0035ee18");
void func_00138c10(void*, s32) asm("func_00138c10");
/*TARGET 0024eac0*/
void func_0024eac0(void) asm("func_0024eac0");
void func_0024eac0(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_0035ee18[i]) {
            if (func_00139d78(D_0035ee18[i])) {
                if (*(s32*)(D_0035ee18[i] + 388) != 2) {
                    func_00138c10(D_0035ee18[i], 2);
                    *(s32*)(D_0035ee18[i] + 392) = -1;
                }
            } else {
                D_0035ee18[i] = 0;
            }
        }
    }
}
}  // namespace n0024eac0

// 0024eb50 (was src/anon/batch_w46.cpp)
namespace n0024eb50 {
struct VObj { void (**vt)(VObj*); };
// 0x001397d8: definition moved into src/anon/unit_001393c8.cpp

// ---- 0013e5a8
s32 func_00139d78(void*) asm("func_00139d78");
// 0x00232498: definition moved into src/anon/unit_00231500.cpp

// ---- 0024eb50
extern VObj* D_0035ee18[5] asm("D_0035ee18");
/*TARGET 0024eb50*/
void func_0024eb50(void) asm("func_0024eb50");
void func_0024eb50(void) {
    for (s32 i = 0; i < 5; i++) {
        if (D_0035ee18[i]) {
            if (func_00139d78(D_0035ee18[i])) D_0035ee18[i]->vt[5](D_0035ee18[i]);
            else D_0035ee18[i] = 0;
        }
    }
}
}  // namespace n0024eb50

// 0024ebc0 (was src/anon/batch_w55.cpp)
namespace n0024ebc0 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_00287d68(void) asm("func_00287d68");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
void func_0024ec50(void) asm("func_0024ec50");
extern u8* D_0035ee04 asm("D_0035ee04");
extern void* D_0035ee08 asm("D_0035ee08");
extern void* D_0035ee10 asm("D_0035ee10");
void func_0024eb50(void) asm("func_0024eb50");
void func_0024f2d0(void) asm("func_0024f2d0");
void func_001039f8(void) asm("func_001039f8");
s32 Select_isCreated(u8*) asm("_ZN2Tz6Select9isCreatedEz");
/*TARGET 0024ebc0*/
// 0x001eeb90: definition moved into src/anon/unit_001ec098.cpp

s32 func_0024ebc0(void) asm("func_0024ebc0");
// 0x001eeb90: definition moved into src/anon/unit_001ec098.cpp

s32 func_0024ebc0(void) {
    func_00287d68();  // copy_globals_3words
    if (func_00287db0()) {
        if (!Select_isCreated(D_0035ee04) && !func_00139d78(D_0035ee08) && !func_00139d78(D_0035ee10)) {
            func_0024eb50();
            func_0024f2d0();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    func_0024ec50();
    return 0;
}
}  // namespace n0024ebc0

// 0024ec50 (was src/anon/batch_wcx2.cpp)
namespace n0024ec50 {
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
// 0x0024a348: definition moved into src/anon/unit_00249ef0.cpp

// --------------------
extern u32 D_0035ee04 asm("D_0035ee04");
extern u32 D_0035ee08 asm("D_0035ee08");
s32 func_00289380_x9516(s32) asm("func_00289380");
void func_00287bc0_x9517() asm("func_00287bc0");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289310_x9519(s32) asm("func_00289310");
s32 func_0023f0c0_x9520(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32) asm("func_0023f070");
void func_00287f90(s32) asm("func_00287f90");
s32 func_002891e8_x9523(s32) asm("func_002891e8");
void func_0024e9c0() asm("func_0024e9c0");
void func_0024eff8(s32) asm("func_0024eff8");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0_x9527(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_0024f240() asm("func_0024f240");
void func_00287da0() asm("func_00287da0");
void func_0024f1a0() asm("func_0024f1a0");
void func_0024f070(s32) asm("func_0024f070");
s32 func_00288040() asm("func_00288040");
void func_00288018() asm("func_00288018");
/*TARGET 0024ec50*/
void func_0024ec50() asm("func_0024ec50");
void func_0024ec50() {
    s32 r = func_00289380_x9516(D_0035ee04);
    func_00287bc0_x9517();
    s32 a = func_00287cd0();
    if (r != -1 || func_00289310_x9519(D_0035ee04)) {
        if (func_0023f0c0_x9520(D_0035ee08) != 1) {
            func_0023f070(D_0035ee08, 1, -1);
            func_00287f90(0);
            return;
        }
    }
    if (!a && func_0023f0c0_x9520(D_0035ee08) == 1) {
        s32 n = func_002891e8_x9523(D_0035ee04);
        func_0024e9c0();
        func_0024eff8(n);
        func_00287c90(1);
    }
    func_00287df0_x9527(r, func_00289310_x9519(D_0035ee04), 1, 0, 1);
    switch (r) {
    case -2:
        if (!func_0024f240()) goto f1a0;
    case -4:
        func_00287da0();
        break;
    case -3: case -1:
        break;
    f1a0:
        func_0024f1a0();
        break;
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        func_0024f070(r);
        break;
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0024ec50

// 0024edd8 (was src/anon/batch_w296.cpp)
namespace n0024edd8 {
// 0x0018d238: definition moved into src/anon/unit_0018d050.cpp

extern u8* D_0035ee04 asm("D_0035ee04");
extern u8* D_0035ee08 asm("D_0035ee08");
extern u8* D_0035ee0c asm("D_0035ee0c");
extern u8* D_0035ee10 asm("D_0035ee10");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_00139d78(u8*) asm("func_00139d78");
s32 func_0023f0c0(u8*) asm("func_0023f0c0");
void func_0023f070(u8*, s32, s32) asm("func_0023f070");
void func_00288e88(u8*) asm("func_00288e88");
void func_0024eac0(void) asm("func_0024eac0");
void func_0024f1a0(void) asm("func_0024f1a0");
void func_0028cdb8(s32) asm("func_0028cdb8");
// record408_alloc_init
void func_0024f2d0(void) asm("func_0024f2d0");
s32 func_002891e8(u8*) asm("func_002891e8");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028cc78(s32, s32, s32, u8*, s32, s32) asm("func_0028cc78");
s32 func_0024efc0(s32) asm("func_0024efc0");
// to_28dbf8_entry6
void func_0028cf98(s32, s32) asm("func_0028cf98");
s32 func_00289310(u8*) asm("func_00289310");
void func_0024eff8(s32) asm("func_0024eff8");
typedef void (*VFn)(u8*);
/*TARGET 0024edd8*/
void func_0024edd8(void) asm("func_0024edd8");
void func_0024edd8(void) {
    if (func_00287db0()) {
        if (!func_00139d78(D_0035ee08)) return;
        if (func_0023f0c0(D_0035ee08) == 2) return;
        if (func_00139d78(D_0035ee08)) {
            if (func_0023f0c0(D_0035ee08) != 2) func_0023f070(D_0035ee08, 2, -1);
        }
        if (D_0035ee0c && func_00139d78(D_0035ee0c)) {
            (*(VFn*)(*(u8**)D_0035ee0c + 20))(D_0035ee0c);
        }
        if (D_0035ee10 && func_00139d78(D_0035ee10)) {
            (*(VFn*)(*(u8**)D_0035ee10 + 20))(D_0035ee10);
        }
        func_00288e88(D_0035ee04);
        func_0024eac0();
        func_0024f1a0();
        func_0028cdb8(0);  // record408_alloc_init
    } else {
        s32 r;
        func_0024f2d0();
        r = func_002891e8(D_0035ee04);
        if (func_00139d78(D_0035ee08) && func_00287cd0() == 1 && func_0028d008(0) == 0) {
            func_0028cc78(0, 2, 2, D_0035ee08, 4, 4);
            func_0028cf98(0, func_0024efc0(r));
        }
        if (!func_00289310(D_0035ee04)) return;
        if (!func_0028d008(0)) return;
        func_0024f1a0();
        func_0028cf98(0, func_0024efc0(r));
        func_0024eff8(r);
    }
}
}  // namespace n0024edd8

// 0024efc0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0024efc0 {
u32 func_0028dbf8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0028dbf8jjjjjjjj");
extern u8 D_0035ee08 asm("D_0035ee08");
extern u8 D_00372348 asm("D_00372348");
extern u8 D_00372380 asm("D_00372380");
/*TARGET 0024efc0*/
u32 func_0024efc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0024efc0jjjjjjjj");
u32 func_0024efc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // to_28dbf8_entry6
    a2 = a0 * 6;
    u32 r14 = (u32)&D_0035ee08;
    a1 = (u32)&D_00372380;
    u32 tmp = *(volatile u32*)r14;
    u32 tbl = (u32)&D_00372348;
    a0 = tmp;
    a2 += tbl;
    return ((u32(*)(...))func_0028dbf8)(a0, a1, a2, a3, a4, a5, a6, a7);
}
}  // namespace n0024efc0

// 0024eff8 (was src/anon/batch_w48.cpp)
namespace n0024eff8 {
// vec_copy_at416_if_diff
s32 func_00139d78(void*) asm("func_00139d78");
// 0x00232db0: definition moved into src/anon/unit_00231500.cpp

extern void* D_0035ee0c asm("D_0035ee0c");
extern u32 D_003723a0[] asm("D_003723a0");
void func_0023f5b8(void*, u32, s32) asm("func_0023f5b8");
/*TARGET 0024eff8*/
void func_0024eff8(s32 i) asm("func_0024eff8");
void func_0024eff8(s32 i) {
    if (!D_0035ee0c) return;
    if (!func_00139d78(D_0035ee0c)) return;
    u32 v = D_003723a0[i];
    func_0023f5b8(D_0035ee0c, v, 0);
}
}  // namespace n0024eff8

// 0024f070 (was src/anon/batch_w93.cpp)
namespace n0024f070 {
struct W93Mdl { u8 pad[392]; s32 f392; u8 p2[408 - 396]; u32 f408; u8 p3[432 - 412]; s32 f432; };
struct W93Six { s16 id; s16 pad; s16 val; };
extern s32 D_0035ee2c asm("D_0035ee2c");
extern s32 D_0035ee18[] asm("D_0035ee18");
extern u32 D_003723b8[] asm("D_003723b8");
union W93MdlP { W93Mdl* p; s32 i; };
extern W93MdlP D_0035ee10 asm("D_0035ee10");
extern W93Six D_00372390[] asm("D_00372390");
extern u32 D_0035ee08 asm("D_0035ee08");
s32 func_0024f2b8(void) asm("func_0024f2b8");
// word_table_372368
s32 func_00139d78(W93Mdl*) asm("func_00139d78");
W93Mdl* func_0028c198(s32, s32, s32, u32, u32, u32) asm("func_0028c198");
void func_00138c10(W93Mdl*, s32) asm("func_00138c10");
u32 func_00192048(u32) asm("func_00192048");
/*TARGET 0024f070*/
// Switches the displayed model slot and reloads/rebinds the model for it.
void func_0024f070(s32 idx) asm("func_0024f070");
// Switches the displayed model slot and reloads/rebinds the model for it.
void func_0024f070(s32 idx)
{
    s32 prev = D_0035ee2c;
    D_0035ee2c = idx;
    s32 r = func_0024f2b8();  // word_table_372368
    u32 res = D_003723b8[D_0035ee18[idx] ? idx + 5 : idx];
    if (!func_00139d78(D_0035ee10.p)) {
        W93Six* e = &D_00372390[r];
        D_0035ee10.p = func_0028c198(e->id, 2, 2, D_0035ee08, res, 0);
        D_0035ee10.p->f392 = e->val;
        D_0035ee10.p->f432 = 2;
    } else if (prev != D_0035ee2c) {
        W93Six* e = &D_00372390[r];
        func_00138c10(D_0035ee10.p, e->id);
        D_0035ee10.p->f392 = e->val;
        D_0035ee10.p->f408 = func_00192048(res);
    }
}
}  // namespace n0024f070

// 0024f1a0 (was src/anon/batch_wcx.cpp)
namespace n0024f1a0 {
// 0x00244888: definition moved into src/anon/unit_00242478.cpp
struct E6 { s16 a, b, c; };
extern s32 D_0035ee2c asm("D_0035ee2c");
extern u8* D_0035ee10 asm("D_0035ee10");
extern E6 D_00372390[] asm("D_00372390");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0024f2b8(s32) asm("func_0024f2b8");
// word_table_372368
void func_00138c10(u8*, s32) asm("func_00138c10");
/*TARGET 0024f1a0*/
void func_0024f1a0(void) asm("func_0024f1a0");
void func_0024f1a0(void)
{
    if (D_0035ee2c < 0) return;
    if (!D_0035ee10) return;
    if (!u_call4_00139d78(D_0035ee10)) return;
    s32 k = func_0024f2b8(D_0035ee2c);  // word_table_372368
    s16 v = D_00372390[k].b;
    if (*(s32*)(D_0035ee10 + 388) == v) return;
    D_0035ee2c = -1;
    func_00138c10(D_0035ee10, v);
    *(s32*)(D_0035ee10 + 392) = -1;
}
}  // namespace n0024f1a0

// 0024f240 (was src/anon/batch_w49.cpp)
namespace n0024f240 {
extern u8* D_0035ee10 asm("D_0035ee10");
extern u32 D_0035ee2c asm("D_0035ee2c");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0024f2b8(u32) asm("func_0024f2b8");
// word_table_372368
struct E372390 { s16 a, b, c; };
extern E372390 D_00372390[] asm("D_00372390");
/*TARGET 0024f240*/
s32 func_0024f240(void) asm("func_0024f240");
s32 func_0024f240(void) {
    if (D_0035ee10 == 0 || !func_00139d78(D_0035ee10)) return 1;
    s32 i = func_0024f2b8(D_0035ee2c);  // word_table_372368
    return *(s32*)(D_0035ee10 + 388) == D_00372390[i].b;
}
}  // namespace n0024f240

// 0024f2b8 (was src/anon/tiny_more2.cpp)
namespace n0024f2b8 {
extern u32 D_00372368 asm("D_00372368");
/*TARGET 0024f2b8*/
u32 func_0024f2b8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0024f2b8jjjj");
u32 func_0024f2b8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00372368 + ((u32)a0 << 2) + (0)); }
}  // namespace n0024f2b8

// 0024f2d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024f2d0 {
extern u32 D_0035ee10 asm("D_0035ee10");
// 0x002251c8: definition moved into src/anon/unit_00224780.cpp

extern "C" u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 0024f2d0*/
void func_0024f2d0() asm("_Z13func_0024f2d0v");
void func_0024f2d0() {
    u32 s0 = D_0035ee10;
    if (s0 != 0) {
        u32 v0 = func_00139d78(s0);
        u32 t7 = D_0035ee10;
        t7 = (v0 != 0) ? t7 : 0;
        D_0035ee10 = t7;
    }
}
}  // namespace n0024f2d0

// 0024f310 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024f310 {
extern u32 D_0035ee04 asm("D_0035ee04");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 0024f310*/
void func_0024f310() asm("_Z13func_0024f310v");
void func_0024f310() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ee04);
    func_0023fc40(&v0, 4);
}
}  // namespace n0024f310

// 0024f348 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024f348 {
extern u32 D_0035ee04 asm("D_0035ee04");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void func_002891f0(...) asm("func_002891f0");
/*TARGET 0024f348*/
void func_0024f348() asm("_Z13func_0024f348v");
void func_0024f348() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ee04, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n0024f348

// 0024f398 (was src/anon/batch_w8022_nsa.cpp)
namespace n0024f398 {
struct W8022_Al { virtual void* alloc(u32, void*); };
}  // namespace n0024f398
inline void* operator new[](unsigned int sz, n0024f398::W8022_Al* a) { return a->alloc(sz, 0); }
namespace n0024f398 {
void func_00239700(void*) asm("func_00239700");
extern u8 D_00347e60 asm("D_00347e60");
struct W8022_T {
    u32 vt; u8 p4[8]; u32 f12; u8 p16[8]; u8 sub[384];
    W8022_T() { f12 = 0; vt = (u32)&D_00347e60; func_00239700(sub); }
    ~W8022_T();
};
void func_00287b18(s32, s32) asm("func_00287b18");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(void*) asm("func_002b3df8");
void func_0028d068(s32, s32) asm("func_0028d068");
u8* func_00103eb0(void) asm("func_00103eb0");
void func_00102818(u32, s32, s32, void*, s32) asm("func_00102818");
void func_0024f698(void) asm("func_0024f698");
typedef void* (*AllocFn)(void*, u32, void*);
extern void** D_0032ba14 asm("D_0032ba14");
extern u8* D_00347f80 asm("D_00347f80");
extern void* D_0035ee34 asm("D_0035ee34");
extern void* D_0035ee38 asm("D_0035ee38");
extern "C" s32 D_0035ee3c;
extern "C" s32 D_0035ee40;
extern "C" s32 D_0035ee44;
extern W8022_T* D_0035ee48 asm("D_0035ee48");
extern void* D_0035ee4c asm("D_0035ee4c");
extern "C" u8 D_0035ee50;
extern "C" u8 D_0035ee51;
/*TARGET 0024f398*/
void func_0024f398(void) asm("func_0024f398");
void func_0024f398(void) {
    void* o;
    func_00287b18(5, 3);
    o = func_00288be8(56);
    func_002889f0(o, 5, 1);
    D_0035ee34 = o;
    o = func_00288be8(56);
    func_002889f0(o, 2, 0);
    D_0035ee38 = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035ee3c = 0;
    D_0035ee40 = 0;
    D_0035ee44 = 0;
    o = (**(AllocFn**)D_0032ba14)(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(o);
    D_0035ee4c = o;
    D_0035ee50 = 0;
    D_0035ee48 = new (*(W8022_Al**)(D_00347f80 + 20)) W8022_T[5];
    D_0035ee51 = 0;
    func_0028d068(30026, -1);
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, (void*)func_0024f698, 4096);
}
}  // namespace n0024f398

// 0024f528 (was src/anon/batch_wcx2.cpp)
namespace n0024f528 {
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
// 0x0024b3a0: definition moved into src/anon/unit_00249ef0.cpp

// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj0024f528 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj0024f528*); void (*del)(VObj0024f528*); }* vt; };
struct Panel0024f528 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel0024f528*); }* vt; u8 pad[404]; };
struct Alloc0024f528 { struct { void* f0; void (*free)(Alloc0024f528*, void*); }* vt; };
struct Heap0024f528 { u8 pad[20]; Alloc0024f528* a; };
extern void* D_0035ee34_x15360 asm("D_0035ee34");
extern void* D_0035ee38_x15361 asm("D_0035ee38");
extern VObj0024f528* D_0035ee3c_x15362 asm("D_0035ee3c");
extern VObj0024f528* D_0035ee40 asm("D_0035ee40");
extern VObj0024f528* D_0035ee44 asm("D_0035ee44");
extern void* D_0035ee4c_x15365 asm("D_0035ee4c");
extern Panel0024f528* D_0035ee48_x15366 asm("D_0035ee48");
extern Alloc0024f528* D_0032ba14_x15367 asm("D_0032ba14");
extern Heap0024f528* D_00347f80_x15368 asm("D_00347f80");
void func_00288b00(void* w) asm("func_00288b00");
void func_00288c20(void* w) asm("func_00288c20");
void func_002b3fb0(void* o) asm("func_002b3fb0");
/*TARGET 0024f528*/
void func_0024f528(void) asm("func_0024f528");
void func_0024f528(void)
{
    void* w;
    if ((w = D_0035ee34_x15360) != 0) { func_00288b00(w); func_00288c20(w); D_0035ee34_x15360 = 0; }
    if ((w = D_0035ee38_x15361) != 0) { func_00288b00(w); func_00288c20(w); D_0035ee38_x15361 = 0; }
    if (D_0035ee3c_x15362) { D_0035ee3c_x15362->vt->del(D_0035ee3c_x15362); D_0035ee3c_x15362 = 0; }
    if (D_0035ee40) { D_0035ee40->vt->del(D_0035ee40); D_0035ee40 = 0; }
    if (D_0035ee44) { D_0035ee44->vt->del(D_0035ee44); D_0035ee44 = 0; }
    if ((w = D_0035ee4c_x15365) != 0) { func_002b3fb0(w); D_0032ba14_x15367->vt->free(D_0032ba14_x15367, w); D_0035ee4c_x15365 = 0; }
    if (D_0035ee48_x15366) {
        Panel0024f528* e = D_0035ee48_x15366 + ((s32*)D_0035ee48_x15366)[-1];
        Panel0024f528* q;
        for (;;) {
            q = D_0035ee48_x15366;
            if (q == e) break;
            e--;
            e->vt->dtor(e);
        }
        D_00347f80_x15368->a->vt->free(D_00347f80_x15368->a, (s32*)q - 1);
        D_0035ee48_x15366 = 0;
    }
}
}  // namespace n0024f528

// 0024f698 (was src/tozawa/smenu_lm.cpp)
namespace Tz { // method 0024f698
extern u32 D_0035ee30 asm("D_0035ee30");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void func_0024f710() asm("func_0024f710");
void func_00242678(u32) asm("func_00242678");
void func_00236d60() asm("func_00236d60");
// clear_64_entries_24
extern "C" u32 func_0024ff08() asm("func_0024ff08");
void func_00250328() asm("func_00250328");
/*TARGET 0024f698*/
void LMMU::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ee30);
    func_00102448(s0, 1);
    func_0024f710();
    func_00242678(12022);
    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_0024ff08() != 0) {
            return;
        }
        func_00250328();
        func_00102448(s0, 0);
    }
}
}  // Tz

