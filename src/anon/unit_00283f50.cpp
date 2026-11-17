// Linked unit 0x00283f50-0x00284088 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
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
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 00283f50 (was src/anon/auto80_199_queue.cpp)
namespace n00283f50 {
// 0x0016fba0: definition moved into src/anon/unit_0016e8f8.cpp

void func_00170888(u32 a0) asm("_Z13func_00170888j");
u32 func_00253b30(u32 a0, u32 a1) asm("_Z13func_00253b30jj");
/*TARGET 00283f50*/
void func_00283f50(void) asm("_Z13func_00283f50v");
void func_00283f50(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;
    p += (s32)(s8)p[14];

    func_00283eb8((u32)work1, (s32)(s8)p[4]);
    func_00253b30((u32)work0, (u32)work1);
    func_00170518((u32)work0, 5100, 0);
    func_00170888(0);
}
}  // namespace n00283f50

// 00283fb0 (was src/anon/auto80_199_queue.cpp)
namespace n00283fb0 {
u32 func_00253b30(u32 a0, u32 a1) asm("_Z13func_00253b30jj");
/*TARGET 00283fb0*/
void func_00283fb0(void) asm("_Z13func_00283fb0v");
void func_00283fb0(void) {
    u8 work0[128];
    u8 work1[32];
    u8* p = (u8*)D_0035f2b4;

    func_00283eb8((u32)work1, (s32)(s8)p[(s32)(s8)p[14] + 4]);
    func_00253b30((u32)work0, (u32)work1);

    func_00290a10(D_0035f2b0, (u32)work0, 24);
    func_002362b0(D_0035f2b8, func_00290948(D_0035f2b0, 0));

    *(u8*)(D_0035f2b8 + 400) = 1;
}
}  // namespace n00283fb0

// 00284048 (was src/tozawa/chg_member.cpp)
namespace Tz { // method 00284048
extern u32 D_0035f2b0 asm("D_0035f2b0");
u32 func_00170320(...) asm("func_00170320");
u32 func_00290940(...) asm("func_00290940");
void func_00290a60(...) asm("func_00290a60");
/*TARGET 00284048*/
u32 ChgMember::Load() {
    if (func_00290940(*(u32*)(u32)&D_0035f2b0) != 0u) {
        func_00290a60(*(u32*)(u32)&D_0035f2b0);
    }
    return func_00170320(5100u);
}
}  // Tz

