#include "cmenu_item.hpp"
#include "cmenu_slbase.hpp"
#include "cmenu_top.hpp"

namespace Tz {

extern u8 D_0035f314 asm("D_0035f314");

u32 CmItem::isPadHelpVisible() {
    (void)D_0035f314;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-3308)));
}

// 0x0025f6b8: definition moved into src/anon/unit_0025f6b8.cpp

// 0x0025f750: definition moved into src/anon/unit_0025f6b8.cpp

}  // namespace Tz
