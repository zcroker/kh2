#include "sheet.hpp"

namespace YS {



extern u32 D_00352130 asm("D_00352130");

void SHEET::start_drive(s32 a1, s32 a2) {
    a2 += 3;
    *(u8*)((u32)this + 0x1AF) = (u8)a1;
    *(u8*)((u32)this + 0x1B3) = (u8)a2;
    f32 v = *(f32*)(D_00352130 + 0x68) * (f32)a2;
    *(f32*)((u32)this + 0x1B8) = v;
    *(f32*)((u32)this + 0x1B4) = v;
}

// 00187728 SHEET::mpdrive: moved to src/anon/unit_00185d10.cpp


}  // namespace YS
