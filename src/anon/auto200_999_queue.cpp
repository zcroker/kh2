#include "../common/types.h"
#include "auto200_999_queue_decls.hpp"

void func_00101d68(void) {
    u32 s1 = 1000;
    func_00105a10();
    D_0032b91c = func_00102508((u32)&D_0037aa40, 0x00010000);
    func_0016f970();
    func_002f3610(1);
    func_002f49c0();
    func_00106490(0x00875b2f);
    func_001674c8();
    func_001385f8();
    func_0016fa58();
    func_00105b58();
    func_00102e40();
    func_00168f18();
    func_00101d50();
    func_00138620();
    func_001dcd50();
    func_00226978();
    func_00233580();
    func_0011b3e0();
    func_00102e18();
    func_00102bd8();
    func_00103480();
    func_00105d50();
    func_0023d260();
    func_00104080();
    func_00104560();
    func_002cb530();
    func_00105748((u32)&D_0032bb30);
    func_00102080((u32)&D_0032b9a0);

    while (1) {
        func_001029e8(D_0032b91c);
        u32 v = D_0032b920 + 1;
        D_0032b920 = v % s1;
    }
}

// 00103a40: MENU::finalize, moved to src/common/unit_001031b0.cpp

// 00104910: moved to src/common/area.cpp

// 00105a20: moved to src/common/unit_00105a10.cpp

void func_00108ae0(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7);  // 00108ae0: moved to src/anon/unit_001085a8.cpp

void func_00108c00(u64* a0, u32 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6, u64 a7);  // 00108c00: moved to src/anon/unit_001085a8.cpp

u32 func_0010f340(u32 a0, u32 a1, u32 a2, f32 a3);  // 0x0010f340: definition moved into src/anon/unit_0010f338.cpp

u32 func_001e3660(u32 a0, s32 a1);  // 0x001e3660: definition moved into src/anon/unit_001e0cb8.cpp
