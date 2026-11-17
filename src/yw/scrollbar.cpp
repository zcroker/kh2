#include "../tozawa/scroll_bar.hpp"

namespace Tz {

extern "C" u32 func_0028be58(...);

void ScrollBar::Leave() {
    u8* s0 = (u8*)this;
    if (func_0028be58(s0) != 0u) {
        void* obj = *(void**)s0;
        ((void (*)(void*))(*(u32*)(*(u32*)obj + 20u)))(obj);
    }
}

extern "C" u32 func_00257770();
extern "C" u32 func_00139d78(u32);
extern "C" void func_0028dac8(...);

// 0x00262538: definition moved into src/anon/unit_0025f6b8.cpp

}  // namespace Tz
