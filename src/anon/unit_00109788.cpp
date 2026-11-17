#include "../common/types.h"

// One function between the whole-asm functions 0x109708 and 0x1097e8.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00109788 (from src/anon/batch_w2367.cpp)
namespace n00109788 {
s32 func_001094e0(s32, s32) asm("func_001094e0");
void func_00133c60(s32, s32, s32, s32, s32) asm("func_00133c60");
s32 func_00109788(s32 a, s32 b) asm("func_00109788");
s32 func_00109788(s32 a, s32 b) {
    if (func_001094e0(b, b) == 0) {
        func_00133c60(a, b, 0, 0, 0);
        return 1;
    }
    return 0;
}
}  // namespace n00109788

