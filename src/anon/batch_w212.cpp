#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" {
extern u8* YS__OBJ__get_pos(u32);  // obj_get_attach_or_alt
extern s32 func_001a6d08(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
extern void func_002dea00(f32, f32);  // obj_init_with_floats

struct W212P { u32 a, b; void clr() { this->a = 0; this->b = 0; } };
struct W212R { f32 f; u32 pad; W212P p; };
extern W212R D_01c60cd0;
extern u32 D_01d49328[8];
extern u32 D_01d49348, D_01d4934c;
extern W212P D_01d49350;
extern u32 D_00362c18;

// 16-byte copy done with lq/sq through t0, as the original
// 00159ce0: moved to src/harata/libdk/targetcamera.cpp

void func_0018f0b0(s32 a, s32 b);  // 0x0018f0b0: definition moved into src/anon/unit_0018d050.cpp

void func_001bff88();  // 0x001bff88: definition moved into src/anon/unit_001bff88.cpp

u32 func_00244938(u32 x);  // 0x00244938: definition moved into src/anon/unit_00242478.cpp

void func_002dfac0(u32* t);  // 0x002dfac0: definition moved into src/anon/unit_002de3c8.cpp

void func_002dfb10(u32* t);  // 0x002dfb10: definition moved into src/anon/unit_002de3c8.cpp
}
