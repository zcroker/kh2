#include "cmenu_stat.hpp"

namespace Tz {

extern u8 D_0035f0e8 asm("D_0035f0e8");

// 0x00267270: definition moved into src/anon/unit_00265580.cpp

extern "C" u32 func_00287bc0(...);
extern "C" u32 func_00287db0(...);
extern "C" u32 func_00257070(...);
extern "C" void func_00257050(...);
extern "C" u32 func_002670f8(...);
extern "C" u32 func_002674b8(...);
extern "C" u32 func_002670a0(...);
extern "C" u32 func_00267408(...);
extern "C" u32 func_0028fb28(...);
extern "C" u32 func_00266b58(...);
extern "C" void func_00256e80(...);
extern "C" void func_0027a108(...);
extern "C" void func_0027a7e0(...);
extern "C" void func_0027ac38(...);
extern "C" void func_0027b4e8(...);

// 0x002674f8: definition moved into src/anon/unit_00265580.cpp

void CmStat::FadeOutAll() {
    u32 mode = func_00287bc0();
    if ((u32)(mode - 15) >= 5) {
        return;
    }

    func_0027a108();
    func_0027a7e0(1);
    func_0027ac38();

    if (func_00287db0() != 0) {
        func_00256e80();
    }

    if (func_00287db0() == 0) {
        return;
    }

    func_00256e80();
    func_0027b4e8();
}

}  // namespace Tz
