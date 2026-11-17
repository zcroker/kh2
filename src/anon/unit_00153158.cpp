// Linked unit 0x00153158-0x00153678 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../harata/libdk/information.hpp"
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }

// 00153158 (was src/anon/batch_w2369.cpp)
namespace n00153158 {
struct CallSub { f32 a; u32 b; u32 c; u32 d; u32 e; };
struct CallMgr { u8 pad[24]; CallSub s0; u8 pad2[9644 - 44]; CallSub s1; u8 pad3[12064 - 9664]; CallSub s2; };
extern u32 D_0034a6f0 asm("D_0034a6f0");
// CallMgr*, kept as an integer (it is reloaded after the u32 stores)
void func_001398d0(s32) asm("func_001398d0");
void func_001397d8(s32) asm("func_001397d8");
/*TARGET 00153158*/
// Reset three sub-records of the manager and set bit 0 of each one's c word.
void u_call0_00153158(void) asm("_Z16u_call0_00153158v");
// Reset three sub-records of the manager and set bit 0 of each one's c word.
void u_call0_00153158(void) {
    func_001398d0(14);
    func_001397d8(14);
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s0;
        *(f32*)((u8*)m + 24) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 32) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 40) = 0;
    }
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s1;
        *(f32*)((u8*)m + 9644) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 9652) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 9660) = 0;
    }
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s2;
        *(f32*)((u8*)m + 12064) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 12072) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 12080) = 0;
    }
}
}  // namespace n00153158

// 001531f8 (was src/anon/perm_001531f8.cpp)
namespace n001531f8 {
typedef unsigned char u8;
typedef signed int s32;
struct M64
{
  u8 d[64];
};
struct Ent
{
  u8 pad[0x1c4];
  s32 p2;
  s32 a0;
  s32 z;
  s32 a3;
  s32 a4;
  M64 m1;
  M64 m2;
  u8 pad2[0x258 - 0x258];
};
struct Q
{
  s32 head;
  s32 tail;
  Ent e[16];
};
struct Mgr
{
  u8 pad[0x24];
  Q q;
};
extern Mgr *D_0034a6f0 asm("D_0034a6f0");
void func_00192c90(s32, M64 *) asm("_ZNK2YS7MESSAGE3dupEPc");
void func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
inline int inline_fn(s32 arg0, Q *arg1)
{
  return ((arg0 - arg1->tail) + 16) % 16;
}
/*TARGET 001531f8*/
void func_001531f8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) asm("func_001531f8");
void func_001531f8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
  Q *q = &D_0034a6f0->q;
  s32 h = q->head;
  if (inline_fn(h, q) < 15)
  {
    q->head = (h + 1) % 16;
    Ent *e = &q->e[h];
    func_00192c90(a1, &e->m1);
    func_00192b30(a1);
    if (a2)
    {
      func_00192c90(a2, &e->m2);
      func_00192b30(a2);
    }
    e->a4 = a4;
    e->a0 = a0;
    e->p2 = a2;
    e->a3 = a3;
    e->z = 0;
  }
}
}  // namespace n001531f8

// 00153310 (was src/anon/batch_w22.cpp)
namespace n00153310 {
// 0014d910: moved to src/anon/unit_0014d680.cpp

// --- 00153310
extern u8* D_0034a6f0 asm("D_0034a6f0");
void func_0031cc30(u8*, u32, u32, u32, u32, u32, u32) asm("func_0031cc30");
/*TARGET 00153310*/
void func_00153310(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_00153310");
void func_00153310(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_0031cc30(D_0034a6f0 + 24, 1, a, b, c, d, e);
}
}  // namespace n00153310

// 00153350 (was src/anon/perm_00153350.cpp)
namespace n00153350 {
typedef unsigned char u8;
typedef signed int s32;
struct M64
{
  u8 d[64];
};
struct Ent
{
  u8 pad[0x1c4];
  s32 p2;
  s32 a0;
  s32 z;
  s32 a3;
  s32 a4;
  M64 m1;
  M64 m2;
  u8 pad2[0x258 - 0x258];
};
struct Q
{
  s32 head;
  s32 tail;
  Ent e[4];
};
struct Mgr
{
  u8 pad[0x25b8];
  Q q;
};
extern Mgr *D_0034a6f0 asm("D_0034a6f0");
void func_00192c90(s32, M64 *) asm("_ZNK2YS7MESSAGE3dupEPc");
void func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
/*TARGET 00153350*/
void func_00153350(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) asm("func_00153350");
void func_00153350(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
  int new_var;
  Q *q = &D_0034a6f0->q;
  s32 h = q->head;
  new_var = ((h - q->tail) + 4) % 4;
  if (new_var < 3)
  {
    q->head = (h + 1) % 4;
    Ent *e = &q->e[h];
    func_00192c90(a1, &e->m1);
    func_00192b30(a1);
    if (a2)
    {
      func_00192c90(a2, &e->m2);
      func_00192b30(a2);
    }
    e->a4 = a4;
    e->a0 = a0;
    e->p2 = a2;
    e->a3 = a3;
    e->z = 0;
  }
}
}  // namespace n00153350

// 00153468 (was src/anon/batch_w83.cpp)
namespace n00153468 {
struct Entry600 {
    u8 pad[452];
    s32 f452;
    s32 f456;
    s32 f460;
    s32 f464;
    s32 f468;
    char name[128];
};
struct Ring600 {
    s32 head;
    s32 tail;
    Entry600 e[4];
};
extern u8* D_0034a6f0 asm("D_0034a6f0");
void func_00192c90(char*, char*) asm("func_00192c90");
void func_00192b30(char*) asm("func_00192b30");
/*TARGET 00153468*/
// Push an entry into a 4-slot ring buffer if there is room.
void func_00153468(s32 a, char* name, s32 b) asm("func_00153468");
// Push an entry into a 4-slot ring buffer if there is room.
void func_00153468(s32 a, char* name, s32 b) {
    Ring600* r = (Ring600*)(D_0034a6f0 + 12076);
    s32 idx = r->head;
    s32 n = (idx - r->tail + 4) % 4;
    if (n < 3) {
        r->head = (idx + 1) % 4;
        Entry600* e = &r->e[idx];
        func_00192c90(name, e->name);
        func_00192b30(name);
        e->f456 = a;
        e->f464 = b;
        e->f452 = 0;
        e->f460 = 0;
        e->f468 = 0;
    }
}
}  // namespace n00153468

// 00153540 (was src/anon/batch_w38.cpp)
namespace n00153540 {
/*TARGET 00153540*/
// 0x00166808: definition moved into src/anon/unit_001664c0.cpp

// RGBA bytes to a float colour normalised by 255 (VU0).
void func_00153540(f32* v, u8 r, u8 g, u8 b, u8 a) asm("func_00153540");
// 0x00166808: definition moved into src/anon/unit_001664c0.cpp

// RGBA bytes to a float colour normalised by 255 (VU0).
void func_00153540(f32* v, u8 r, u8 g, u8 b, u8 a) {
    v[0] = r;
    v[1] = g;
    v[2] = b;
    v[3] = a;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyzw $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(v), "f"(255.0f) : "$8", "memory");
}
}  // namespace n00153540

// 001535b0 (was src/anon/batch_w23.cpp)
namespace n001535b0 {
// 0014a470: moved to src/anon/unit_00149fa8.cpp

struct E24 { u8 pad[20]; u8 a, b, c, d; };
extern E24* D_0034a778 asm("D_0034a778");
void func_00153540(void*, u32, u32, u32, u32) asm("func_00153540");
/*TARGET 001535b0*/
void func_001535b0(u8* p, s32 i) asm("func_001535b0");
void func_001535b0(u8* p, s32 i) {
    E24* e = (E24*)(i * 24 + (u32)D_0034a778);
    func_00153540(p + 32, e->a, e->b, e->c, e->d);
}
}  // namespace n001535b0

// 001535f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001535f0 {
extern u32 D_0034a780 asm("D_0034a780");
extern u32 D_0034a784 asm("D_0034a784");
extern u32 D_0034a788 asm("D_0034a788");
/*TARGET 001535f0*/
void func_001535f0(f32 a0, f32 a1, f32 a2) asm("_Z13func_001535f0fff");
void func_001535f0(f32 a0, f32 a1, f32 a2) {
    *(f32*)&D_0034a780 = a0;
    *(f32*)&D_0034a784 = a1;
    *(f32*)&D_0034a788 = a2;
}
}  // namespace n001535f0

// 00153610 (was src/anon/batch_w36.cpp)
namespace n00153610 {
extern f32 D_0034a780 asm("D_0034a780");
extern f32 D_0034a784 asm("D_0034a784");
extern f32 D_0034a788 asm("D_0034a788");
/*TARGET 00153610*/
// 0x00142208: definition moved into src/anon/unit_00141458.cpp

// 00149c40: moved to src/harata/libdk/area.cpp

f32 func_00153610(f32 x) asm("func_00153610");
// 0x00142208: definition moved into src/anon/unit_00141458.cpp

// 00149c40: moved to src/harata/libdk/area.cpp

f32 func_00153610(f32 x) {
    f32 r = 1.0f / (D_0034a780 + D_0034a784 * x + D_0034a788 * x * x);
    if (1.0f < r) r = 1.0f;
    if (r < 0.0f) r = 0.0f;
    return r;
}
}  // namespace n00153610

