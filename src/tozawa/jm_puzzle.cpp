#include "jm_puzzle.hpp"

namespace Tz {

extern volatile u8* volatile D_0035f638 asm("D_0035f638");
extern s8 D_00374cd0[] asm("D_00374cd0");
extern "C" void func_002fde18(void*, u32, u32);

// 0x002aeb28: definition moved into src/anon/unit_002aeb28.cpp

u32 JmPuzzle::CalcMaxPiece(s32 a0) {
    s8* p = (s8*)((u8*)&D_00374cd0 + (a0 << 2));
    return (s32)p[0] * (s32)p[1];
}

}  // namespace Tz
