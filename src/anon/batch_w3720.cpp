#include "../common/types.h"
// 00232738: the D_0035de2c increment is hand-written (4 insns) so its address is not hoisted out of the loop.
extern "C" {
s32 sa__EVENT__isJumpMode(s16);
s32 func_00225b50(s16);
s32 func_00225e48(void);
void func_002278e0(void*);
void func_002326d0(void*);
void func_00232718(void);
s32 func_002baa20(s32);
void func_002baa48(s32);
typedef struct Obj_w { s32 a; s32 type; u8 pad[0xc]; s32 h; } Obj_w;
typedef struct Ent_w { Obj_w* obj; s16 time; s8 state; u8 pad[0x19]; } Ent_w;
typedef struct Hdr_w { s32 a; s16 n; s16 b; Ent_w e[1]; } Hdr_w;
extern Hdr_w* D_0035de4c;
extern s32 D_0035de20;
extern s32 D_0035de2c;
void sa__EVENT__audio_ctrl(void);  // 0x00232738: definition moved into src/anon/unit_00231500.cpp
/* 0015c880: partial asm (register pins plus scheduling dependencies). The li and the y store are hand-written so sched2
   issues the stores in the original order; the empty asm holds the a store back until the float stores are done. */
struct S4f3694 { u8 r, g, b, a; f32 x, y, z, w; };
extern u8 D_00340eb0;
extern struct S4f3694 D_004f3694;
void func_0010a8a8(f32, f32);
void func_0010a828(f32, f32);
void func_0010a7d8(u8, u8, u8);
void func_001dd1e8(u8, u8);
void func_001dd1b0(f32, f32);
void func_001dd1c8(u8, u8, u8);
static inline __attribute__((always_inline)) void init_4f3694(f32 z, f32 w, f32 y) {
    s32 t;
    register f32 yy asm("$f2") = y;
    asm("swc1 %1,%0" : "=m"(D_004f3694.y) : "f"(yy), "m"(D_00340eb0));
    asm("li %0,128" : "=r"(t) : "m"(D_004f3694.y), "m"(D_004f3694.x), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.r = 0;
    D_004f3694.g = 0;
    D_004f3694.x = z;
    D_004f3694.z = z;
    D_004f3694.w = w;
    asm("" : "+r"(t) : "m"(D_004f3694.x), "m"(D_004f3694.y), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.a = t;
    D_004f3694.b = 0;
    func_0010a8a8(z, w);
}
void func_0015c880(f32 arg0);  // 0x0015c880: definition moved into src/anon/unit_0015bab8.cpp
}
