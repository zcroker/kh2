// Linked unit 0x00120520-0x001205c0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
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
#include "tiny_auto80_solver_structs.hpp"

// 00120520 (gap function, not written before)
namespace g00120520 {
u32 func_0011f7a8(u32, u32, u32, u32, u32, u8, u32) asm("func_0011f7a8");
u32 func_00120520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) asm("func_00120520");
struct NoTail { ~NoTail() {} };
u32 func_00120520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) {
    NoTail nt;
    return func_0011f7a8(a0, a1, a3, a4, a5, a6, a7);
}
}  // namespace g00120520

// 00120550 (was src/anon/tiny_auto80_solver.cpp)
namespace n00120550 {
u32 func_0011f7a8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0011f7a8jjjjjjjj");
/*TARGET 00120550*/
u32 func_00120550(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00120550jjjjjjjj");
u32 func_00120550(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r6 = r7;
    r7 = r8;
    r9 = (u32)(r9 & 0x00ffu);
    r8 = 0u;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0011f7a8)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2 != 0) {
        return r2;
    }
    return r2;
}
}  // namespace n00120550

// 00120578 (gap function, not written before)
namespace g00120578 {
struct E { u32 a; u16 b; u16 fl; u32 c; u16 d; u16 e; };
struct H { u8 pad[16]; u16 cnt; u8 pad2[6]; u32 f24; u8 pad3[4]; E e[1]; };
struct O { void* vt; H* h; };
// Sum of the part sizes of the visible parts.
u32 func_00120578(O* o, s8* vis) asm("func_00120578");
u32 func_00120578(O* o, s8* vis) {
    H* h = o->h;
    u32 r = 0;
    for (s32 i = 0; i < h->cnt; i++)
        if (vis[i]) r += h->e[i].e;
    return r;
}
}  // namespace g00120578

