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
void func_00159ce0(u8* a0, u128* a1) {
    u128* r = (u128*)func_0016c028(*(u32*)(a0 + 68));  // obj_get_attach_or_alt
    if (a1 != r) asm("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(a1), "r"(r) : "$8", "memory");
    ((f32*)a1)[1] -= 170.0f;
}

void func_0018f0b0(s32 a, s32 b) {
    if (b == 0xffff) { if (a == 1) { D_01c60cd0.f = 0.7853981256484985f; } }
    if (b == 0xffff) { if (a == 1) { D_01c60cd0.p.clr(); } }
}

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
