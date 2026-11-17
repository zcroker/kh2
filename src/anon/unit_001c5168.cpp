// 0x1c5168-0x1c51d8: C2 (gap, 0x1c5168) and C1 (0x1c51a0) constructors of the spawner group
// (base ctor 0x1db8f8, vtable 0x351cd8). The file starts here, after the previous file's
// _GLOBAL__D_ stub at 0x1c5148. The whole-asm spawner 0x1c51d8 (src/anon/batch_w3933.s) follows; the rest of the
// file is src/anon/unit_001c5b90.cpp and src/anon/unit_001c6c60.cpp.
#include "../common/types.h"

// ---- 001c5168 gap: C2 copy of the ctor 0x1c51a0 (same body)
namespace n001c5168 {
u32 func_001db8f8(u32, u32, u32, u32) asm("_Z13func_001db8f8jjjj");
extern u8 D_00351cd8 asm("D_00351cd8");
u32 func_001c5168(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c5168");
u32 func_001c5168(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r6 = 0u;
    r7 = (u32)((s32)0u + (2000));
    r16 = r4;
    r2 = func_001db8f8(r4, r5, r6, r7);
    r15 = (u32)&D_00351cd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n001c5168

// ---- 001c51a0 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001c51a0 {
u32 func_001db8f8(u32, u32, u32, u32) asm("_Z13func_001db8f8jjjj");
extern u8 D_00351cd8 asm("D_00351cd8");
u32 func_001c51a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c51a0jjjj");
u32 func_001c51a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r6 = 0u;
    r7 = (u32)((s32)0u + (2000));
    r16 = r4;
    r2 = func_001db8f8(r4, r5, r6, r7);
    r15 = (u32)&D_00351cd8;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n001c51a0

