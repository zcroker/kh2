#include "jiminy.hpp"

namespace dk {
class Sprite;
}

namespace Tz {

extern u8 D_00360000 asm("D_00360000");

extern u32 D_0035f158 asm("D_0035f158");
extern u32 D_0035f204 asm("D_0035f204");
extern u32 D_0035f200 asm("D_0035f200");
extern u32 D_0035f144 asm("D_0035f144");
extern u32 D_0035f138 asm("D_0035f138");
extern u32 D_0035f140 asm("D_0035f140");
extern u32 D_0035f1fc asm("D_0035f1fc");
extern u8 D_0035f220 asm("D_0035f220");
extern u32 D_0035f21c asm("D_0035f21c");
extern u32 D_0035f20c asm("D_0035f20c");
extern u32 D_0035f214 asm("D_0035f214");
extern u32 D_0035f218 asm("D_0035f218");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u32 D_00373d88 asm("D_00373d88");
extern u32 D_00373d80 asm("D_00373d80");
extern u32 D_00373da0 asm("D_00373da0");
extern "C" void func_00293bd0(u32, u32, u32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00274db8();
extern "C" u32 func_00274e50(...);
extern "C" void func_00274e08();
extern "C" void func_00275d10();
extern "C" u32 func_0028acc8(...);
extern "C" void func_0028abe0(...);
extern "C" u32 func_0028be58(...);
extern "C" void func_0028be18(...);
extern "C" void func_002766e0();
extern "C" void func_00293e00(u32);
extern "C" void func_0028d980(...);
extern "C" void func_00293fc0();
extern "C" void func_00294020(u32);
extern "C" u32 func_0028d6e8(...);
extern "C" void func_0028d1c0(...);
extern "C" void func_0028d660(...);  // record_set_value_refresh
extern "C" void func_00293eb0() asm("_ZN2Tz6JmInfo4ExitEv");
extern "C" u32 func_00293d80(...);

extern "C" u32 func_00289310() asm("_ZN2Tz6Select12isCursorMoveEv");
extern "C" void func_00296ed0() asm("_ZN2Tz8JmReport10DrawUpdateEPNS_6SelectEii");
extern "C" u32 func_002ad018(...);

void Jiminy::DrawSelector(Select*, s32, s32) {
    if (func_00289310() != 0u) {
        func_00296ed0();
    }
}

// 0x00274ac8: definition moved into src/anon/unit_002748a0.cpp

// 0x002759e8: definition moved into src/anon/unit_002748a0.cpp

// 0x00275a80: definition moved into src/anon/unit_002748a0.cpp

// 0x00276fd0: definition moved into src/anon/unit_002748a0.cpp

// 0x00274ea0: definition moved into src/anon/unit_002748a0.cpp

// 0x00274f50: definition moved into src/anon/unit_002748a0.cpp

// 0x00274ee8: definition moved into src/anon/unit_002748a0.cpp


// 0x00274f98: definition moved into src/anon/unit_002748a0.cpp

// 0x00276588: definition moved into src/anon/unit_002748a0.cpp

// 0x002766b0: definition moved into src/anon/unit_002748a0.cpp

// 0x00276690: definition moved into src/anon/unit_002748a0.cpp

// 0x002765e8: definition moved into src/anon/unit_002748a0.cpp

// 0x00276348: definition moved into src/anon/unit_002748a0.cpp

// 0x00276358: definition moved into src/anon/unit_002748a0.cpp

// 0x00276568: definition moved into src/anon/unit_002748a0.cpp

// 0x00276608: definition moved into src/anon/unit_002748a0.cpp

// 0x00276620: definition moved into src/anon/unit_002748a0.cpp

// 0x00276638: definition moved into src/anon/unit_002748a0.cpp

// 0x002766d0: definition moved into src/anon/unit_002748a0.cpp

// 0x00276678: definition moved into src/anon/unit_002748a0.cpp

// 0x00276c38: definition moved into src/anon/unit_002748a0.cpp

}  // namespace Tz
