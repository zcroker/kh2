#include "jm_treasure.hpp"

namespace Tz {

extern "C" u32 func_001a3570(...);
extern "C" u32 func_00287bc0(...);
extern "C" void func_002a41f0(...);
extern "C" void func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");

// 0x002a2150: definition moved into src/anon/unit_002a1d38.cpp

u32 JmTreasure::isEnableNavi(YS::TREASURE::TABLE const* entry) {
    u32 r4 = (u32)(*(u16*)((u32)entry + (s32)(2)));
    u32 r2 = func_001a3570(r4);
    r2 = ((s32)0u < (s32)r2);
    return r2;
}

}  // namespace Tz
