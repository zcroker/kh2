#include "obj2d.hpp"

namespace dk {
extern u32 D_00347f80 asm("D_00347f80");
extern "C" u32 TASK_MANAGER_create_task_raw(u32, u32, u32, u32)
    asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
extern u8 dk_Obj2D_ExecTask asm("_ZN2dk5Obj2D8ExecTaskEP4TASK");

// 0x0013a1d8: definition moved into src/anon/unit_001393c8.cpp

// 0x001391c8: definition moved into src/anon/unit_001391c8.cpp

// 0x00139280: definition moved into src/anon/unit_001391c8.cpp

// 0x00139510: definition moved into src/anon/unit_001393c8.cpp

// 0x00139520: definition moved into src/anon/unit_001393c8.cpp

// 0x00139538: definition moved into src/anon/unit_001393c8.cpp

// 0x00139548: definition moved into src/anon/unit_001393c8.cpp

// 0x00139570: definition moved into src/anon/unit_001393c8.cpp

// 0x00139580: definition moved into src/anon/unit_001393c8.cpp

// 0x00139598: definition moved into src/anon/unit_001393c8.cpp

// 0x001395a8: definition moved into src/anon/unit_001393c8.cpp

// 0x001395d0: definition moved into src/anon/unit_001393c8.cpp

// 0x001395e8: definition moved into src/anon/unit_001393c8.cpp

// 0x001395f8: definition moved into src/anon/unit_001393c8.cpp

// 0x00139610: definition moved into src/anon/unit_001393c8.cpp

// 0x00139620: definition moved into src/anon/unit_001393c8.cpp

// 0x00139638: definition moved into src/anon/unit_001393c8.cpp

// 0x00139648: definition moved into src/anon/unit_001393c8.cpp

// 0x00139660: definition moved into src/anon/unit_001393c8.cpp

// 0x00139688: definition moved into src/anon/unit_001393c8.cpp

void Obj2D::DoubleSuicideOn() {
    u32 v = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c);
    *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + 0x0c) = v | 0x0800u;
}

// 0x001396c0: definition moved into src/anon/unit_001393c8.cpp
}  // namespace dk
