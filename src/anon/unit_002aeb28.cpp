// Linked unit 0x002aeb28-0x002aeba0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_newinfo.hpp"
#include "../tozawa/jm_complete.hpp"
#include "../tozawa/jm_puzzle.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002aeb28 (was src/tozawa/jm_puzzle.cpp)
namespace Tz { // method 002aeb28
extern volatile u8* volatile D_0035f638 asm("D_0035f638");
void func_002fde18(void*, u32, u32) asm("func_002fde18");
void JmPuzzle::InitInfo() {
    u32 s0 = 0x00360000;
    (void)s0;
    func_002fde18((void*)D_0035f638, 0, 152);

    {
        volatile u8* p = D_0035f638;
        s32 m = -1;
        *(volatile s8*)(p + 52) = (s8)m;
    }

    {
        s32 m = -257;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }

    {
        s32 m = -513;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }

    {
        s32 m = -2049;
        volatile u8* p = D_0035f638;
        u32 w = *(volatile u32*)(p + 52);
        w = w & (u32)m;
        *(volatile u32*)(p + 52) = w;
    }
}
}  // Tz

