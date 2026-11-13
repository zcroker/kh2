#include "gauge.hpp"

namespace dk {

extern u32 D_00348638 asm("D_00348638");
extern "C" u32 wtarget_0013dbe0(u32, u32, u32, u32) asm("_Z16wtarget_0013dbe0jjjj");

u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk5GAUGE4initEv");
u32 GAUGE_init_raw(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013dd28: definition moved into src/anon/unit_0013a8b8.cpp

// 0x0013d7e0 GAUGE_DRAW::getImage, 0x0013d7f0 getFriend1, 0x0013dbb0 checkAlertOff: moved into src/anon/unit_0013a8b8.cpp

// 00158290, 001581a8, 001581d0 (GAUGE_PARTY getGroup, isAlertStart, isAlertEnd): moved to src/anon/unit_00158050.cpp

}  // namespace dk
