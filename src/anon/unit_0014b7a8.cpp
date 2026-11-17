// Linked unit 0x0014b7a8-0x0014b838 (one namespace per old matched source; class methods in their own namespace).
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

// 0014b7a8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0014b7a8 {
u32 func_0014b290(u32, u32, u32, u32) asm("_Z13func_0014b290jjjj");
extern u8 D_00349dc0 asm("D_00349dc0");
/*TARGET 0014b7a8*/
u32 func_0014b7a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014b7a8jjjj");
u32 func_0014b7a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dc0;
    r13 = (u32)((s32)r16 + (256));
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r14 = (u32)((s32)r16 + (32));
    r15 = (u32)((s32)0u + (13));
    *(u32*)((u32)r13 + (s32)(4)) = r14;
    *(u16*)((u32)r16 + (s32)(256)) = (u16)r15;
    *(u8*)((u32)r13 + (s32)(3)) = (u8)0u;
    return r2;
}
}  // namespace n0014b7a8

// 0014b7f0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n0014b7f0 {
u32 func_0014b290(u32, u32, u32, u32) asm("_Z13func_0014b290jjjj");
extern u8 D_00349dc0 asm("D_00349dc0");
/*TARGET 0014b7f0*/
u32 func_0014b7f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014b7f0jjjj");
u32 func_0014b7f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014b290(r4, r5, r6, r7);
    r15 = (u32)&D_00349dc0;
    r13 = (u32)((s32)r16 + (256));
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r14 = (u32)((s32)r16 + (32));
    r15 = (u32)((s32)0u + (13));
    *(u32*)((u32)r13 + (s32)(4)) = r14;
    *(u16*)((u32)r16 + (s32)(256)) = (u16)r15;
    *(u8*)((u32)r13 + (s32)(3)) = (u8)0u;
    return r2;
}
}  // namespace n0014b7f0

