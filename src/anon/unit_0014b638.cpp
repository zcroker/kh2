// Linked unit 0x0014b638-0x0014b7a8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int W1820u128 __attribute__((mode(TI)));
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/timer.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/clock.hpp"

// 0014b638 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0014b638 {
u32 func_0014b290(u32, u32, u32, u32) asm("_Z13func_0014b290jjjj");
extern u8 D_00349dd8 asm("D_00349dd8");
/*TARGET 0014b638*/
// 0x0013ee88: definition moved into src/anon/unit_0013dfb8.cpp

u32 func_0014b638(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014b638jjjj");
// 0x0013ee88: definition moved into src/anon/unit_0013dfb8.cpp

u32 func_0014b638(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0014b638

// 0014b668 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0014b668 {
u32 func_0014b290(u32, u32, u32, u32) asm("_Z13func_0014b290jjjj");
extern u8 D_00349dd8 asm("D_00349dd8");
/*TARGET 0014b668*/
u32 func_0014b668(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014b668jjjj");
u32 func_0014b668(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0014b668

// 0014b698 (was src/anon/batch_w1820_nsa.cpp)
namespace n0014b698 {
// Object with a 16-qword GS register packet at +0x20 (two GIF tags + A+D pairs).
struct W1820Gs {
    u8 pad[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 b0, b1, b2, b3;
    u8 pad2[12];
    u64 g[22];
    u64 g2[2];
};
// DMA packet builder: 3 words, write cursor at +8.
struct W1820Pkt {
    u32 a, b;
    W1820u128* p;
    W1820Pkt() { p = 0; b = 0; a = 0; }
};
void func_001b7e68(W1820Pkt*, s32) asm("func_001b7e68");
void func_001b80d8(W1820Pkt*) asm("func_001b80d8");
void func_001b7f30(W1820Pkt*) asm("func_001b7f30");
/*TARGET 0014b698*/
// 0x0013e940: definition moved into src/anon/unit_0013dfb8.cpp

void func_0014b698(W1820Gs* p) asm("func_0014b698");
// 0x0013e940: definition moved into src/anon/unit_0013dfb8.cpp

void func_0014b698(W1820Gs* p)
{
    p->g[21] = (u64)p->b0 | ((u64)p->b1 << 8) | ((u64)p->b2 << 16) | ((u64)p->b3 << 24) | (1ULL << 32);
    ((u64*)p)[27] = (s32)((p->x << 4) + 0x7000) | ((u64)(s32)((p->y << 4) + 0x7300) << 16) | ((u64)p->z << 32);
    ((u64*)p)[29] = (s32)(((p->x + p->w) << 4) + 0x7000) | ((u64)(s32)(((p->y + p->h) << 4) + 0x7300) << 16) | ((u64)p->z << 32);
    W1820Pkt pkt;
    func_001b7e68(&pkt, 0xd0);
    W1820Pkt* pp = &pkt;
    W1820u128* s = (W1820u128*)p->g;
    for (s32 i = 12; i >= 0; i--) { *pp->p = *s; s++; pp->p++; }
    func_001b80d8(&pkt);
    func_001b7f30(&pkt);
}
}  // namespace n0014b698

