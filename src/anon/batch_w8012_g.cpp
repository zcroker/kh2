#include "../common/types.h"
extern "C" {
struct V4_2cf998 { f32 x, y, z, w; };
static inline __attribute__((always_inline)) void set4_2cf998(V4_2cf998* v, f32 x, f32 y, f32 z, f32 w) {
    v->w = w;
    v->x = x;
    v->y = y;
    v->z = z;
}
struct E2cf998 { s32 on; u8 flags[12]; f32* pos; u8 pad[20]; };
s32 func_002ceb28(void);
s32 func_00197920(void);
s32 func_002cf270(void*, s32);
void func_002cf280(void*, s32, s32);
void func_002cf2b0(void*, s32);
void func_001444c8(void*, V4_2cf998*, V4_2cf998*);
s32 func_002cec20(s32, void*);
extern s32 D_00361fa0;
extern E2cf998* D_00361fa4;
extern s32 D_00361f60;
void func_002cf998(void);  // 0x002cf998: definition moved into src/anon/unit_002cf260.cpp
}
