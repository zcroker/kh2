#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" {
extern u8* func_0016c028(u32);  // obj_get_attach_or_alt
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

void func_001bff88() {
    for (s32 i = 7; i >= 0; i--) D_01d49328[7 - i] = 0;
    D_01d4934c = 256;
    D_01d49348 = 0;
    D_01d49350.clr();
}

u32 func_00244938(u32 x) {
    u32 r = 1;
    if (x == 0) { if (func_001a6d08(1) != 0) r = func_001a6d08(118); }
    else r = func_001a6d08(1);
    return r;
}

void func_002dfac0(u32* t) {
    func_002dea00(0.0f, 50.0f);  // obj_init_with_floats
    t[2] |= 0x800;
    t[0] = (u32)&D_00362c18;
}

void func_002dfb10(u32* t) {
    func_002dea00(0.0f, 50.0f);  // obj_init_with_floats
    t[2] |= 0x800;
    t[0] = (u32)&D_00362c18;
}
}
