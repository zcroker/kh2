#include "cmenu_config.hpp"

namespace Tz {

extern s8* D_0035f234 asm("D_0035f234");
extern u32 D_0035f254 asm("D_0035f254");

extern "C" u32 func_00257770(...);
extern "C" u32 func_0028af88(...);
extern "C" u32 func_0028b040(...);
extern "C" void func_0028af18(...);
extern u8 D_00374168 asm("D_00374168");

// 0x0027fcc0: definition moved into src/anon/unit_0027f2b0.cpp

u32 CmConfig::GetSelSeq(s32 a0, s32 a1) {
    u32 s0 = (u32)a1;
    u32 s1 = (u32)a0;
    u32 base = func_00257770();
    u32 t = s1 + s0;
    s1 <<= 2;
    if (t != 9) {
        s1 = (u32)((s32)s1 + (s32)D_0035f234[t]);
    }
    return base + (s1 * 436) + 13840;
}

}  // namespace Tz
