#include "../common/types.h"

// 001051a0: moved to src/common/area.cpp

u32 func_00112720(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00112720: definition moved into src/anon/unit_001117d8.cpp

u32 func_00120800(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00120800: definition moved into src/anon/unit_00120520.cpp

void func_00132cb8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00132cb8: definition moved into src/anon/unit_00131418.cpp

u32 func_0013dce8(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013dce8: definition moved into src/anon/unit_0013a8b8.cpp

u32 func_0018ac80(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0018ac80: definition moved into src/yasui/libys/npc.cpp

u32 func_0019f550(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0019f550: definition moved into src/anon/unit_0019ee80.cpp

u32 func_0019ff78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0019ff78: definition moved into src/anon/unit_0019fb70.cpp

u32 func_0021e9a8(u32 a0, u32 a1, u32 a2, u32 a3) {  // select_vif_regs
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r13 = (u32)(0x01dau << 16);
    r14 = (u32)(0x7000u << 16);
    r15 = (u32)(*(u8*)((u32)r13 + (s32)(-6480)));
    r2 = (u32)(0x7000u << 16);
    r14 = (u32)(r14 | 0x1e00u);
    r2 = (u32)(r2 | 0x2f00u);
    r15 = (u32)(r15 ^ 0x0001u);
    *(u8*)((u32)r13 + (s32)(-6480)) = (u8)r15;
    if (r15 == 0u) r2 = r14;
    return r2;
}

u32 func_002bc978(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bc978: definition moved into src/anon/unit_002bc978.cpp
