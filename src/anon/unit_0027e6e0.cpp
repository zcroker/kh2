// Linked unit 0x0027e6e0-0x0027e920 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_ability.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_tutorial.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/cmenu_config.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/simple_stat.hpp"

// 0027e6e0 (was src/tozawa/simple_stat.cpp)
namespace Tz { // method 0027e6e0
extern u32 D_0035f244 asm("D_0035f244");
extern s8 D_0035f24c asm("D_0035f24c");
extern u8 D_00374050 asm("D_00374050");
u32 func_00139d78(...) asm("func_00139d78");
u32 func_0028dac8(...) asm("func_0028dac8");
/*TARGET 0027e6e0*/
void SimpleStat_FadeOut() asm("_Z13func_0027e6e0v");
void SimpleStat_FadeOut() {
    if (func_00139d78(D_0035f244) == 0) {
        return;
    }
    s32 i = (s32)D_0035f24c;
    u32 ptab = (u32)&D_00374050 + i * 6;
    s16 target = *(s16*)(ptab + 2);
    if (func_00139d78(D_0035f244) == 0) {
        return;
    }
    u32 p = D_0035f244;
    if (*(u32*)(p + 388) == (u32)(s32)target) {
        return;
    }
    func_0028dac8(p, (s32)target);
}
}  // Tz

// 0027e770 (was src/anon/batch_w114.cpp)
namespace n0027e770 {
// ---- 0027e770
typedef void (*VFn10)(u8*);
extern u8* D_0035f244 asm("D_0035f244");
extern u8* D_0035f248 asm("D_0035f248");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
static inline void vstop(u8* o) { (*(VFn10*)((*(u8**)o) + 20))(o); }
void func_0027e770(void) asm("func_0027e770");
/*TARGET 0027e770*/
void func_0027e770(void) asm("func_0027e770");
void func_0027e770(void) {
    s32 g, j, off;
    if (func_00139d78(D_0035f244)) vstop(D_0035f244);
    for (g = 0; g < 4; g++) {
        if (func_00139d78(D_0035f248 + g * 5116)) func_00139510(D_0035f248 + g * 5116);
        if (func_00139d78(D_0035f248 + g * 5116 + 436)) func_00139510(D_0035f248 + g * 5116 + 436);
        for (j = 0, off = g * 5116; j < 2; j++, off += 408) {
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 844))) vstop((u8*)(off + (u32)D_0035f248 + 844));
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 1660))) vstop((u8*)(off + (u32)D_0035f248 + 1660));
        }
        for (j = 0, off = g * 5116; j < 3; j++, off += 436) {
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 2476))) vstop((u8*)(off + (u32)D_0035f248 + 2476));
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 3784))) vstop((u8*)(off + (u32)D_0035f248 + 3784));
        }
    }
}
}  // namespace n0027e770

