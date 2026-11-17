// Linked unit 0x00241e18-0x00241f20: Tz::MCard tail.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 00241e18 (was src/anon/auto80_199_queue.cpp)
namespace n00241e18 {
/*TARGET 00241e18*/
u32 func_00241e18(void) asm("_Z13func_00241e18v");
u32 func_00241e18(void) {
    u32 picks[8];
    u16* s16 = D_003717a8;
    s32 s17 = 0;
    u32* s18 = picks;
    u32 s19 = 0;

    do {
        u32 v0;
        u16 t7 = s16[0];
        if (t7 != 0) {
            v0 = func_00181500(t7);
            if (v0 == 0) {
                v0 = 1;
                goto decided;
            }
        }
        v0 = func_00181500(s16[1]);
decided:
        if (v0 != 0) {
            *s18 = s17;
            s19 += 1;
            s18 += 1;
        }
        s17 += 1;
        s16 = (u16*)((u8*)s16 + 4);
    } while (s17 < 8);

    u32 v0 = func_0014cba0();
    u32 t7 = v0 % s19;
    return picks[t7];
}
}  // namespace n00241e18

// 00241ed8 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00241ed8
u32 func_00181500(...) asm("func_00181500");
/*TARGET 00241ed8*/
u32 MCard::ChgWorldName(s32 world) {
    u32 r14 = (u32)world;
    u32 r2 = 0u;
    u32 r15 = 4u;
    u32 r4 = 4235u;
    if (r14 == r15) {
        r2 = func_00181500(r4);
        r2 = ((u32)0u < (u32)r2);
    }
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // Tz

// 00241f10 (was src/tozawa/mcard.cpp)
namespace Tz { // method 00241f10
extern u32 D_0035ec94 asm("D_0035ec94");
/*TARGET 00241f10*/
void* MCard::GetMCInfo() { return reinterpret_cast<void*>(D_0035ec94); }
}  // Tz

