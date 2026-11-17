#include "../common/types.h"
extern "C" {
extern s32 D_0035eebc;
extern u8 D_0035f06b;
extern u8 D_0035f0b4;
extern s32 D_0035f0f8;
extern u8 D_0035f4b8;
extern u8 D_00347d28;
extern u8 D_0034c740;
extern s8 D_00361800;
extern u8* D_00348818;
s32 func_002535c0(void) { return D_0035eebc; }
void func_00258b28(s32 a);  // 0x00258b28: definition moved into src/anon/unit_002588e8.cpp
u8 func_0025f568(void);  // 0x0025f568: definition moved into src/anon/unit_0025da20.cpp
void func_0025f578(void);  // 0x0025f578: definition moved into src/anon/unit_0025da20.cpp
s32 func_0026d818(void);  // 0x0026d818: definition moved into src/anon/unit_0026c450.cpp
void func_00292540(void);  // 00292540: moved to src/anon/unit_00290f78.cpp
void func_0010f908(u8* p);  // 0x0010f908: definition moved into src/anon/unit_0010f338.cpp
u32 func_00112c70(u8* p);  // 0x00112c70: definition moved into src/anon/unit_001117d8.cpp
// 00136a40: moved to src/harata/libdk/bgse.cpp
// 00161238: moved to src/anon/unit_001611a8.cpp
u32 func_002be750(void);  // 0x002be750: definition moved into src/anon/unit_002be020.cpp
void func_00113408(u8* p);  // 0x00113408: definition moved into src/anon/unit_001117d8.cpp
void func_00113420(u8* p);  // 0x00113420: definition moved into src/anon/unit_001117d8.cpp
u8* func_001178b8(u8* d, u8* s) {
    s += 1600;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    return d;
}
void func_001431d0(void);  // 0x001431d0: definition moved into src/anon/unit_00142c90.cpp
}
