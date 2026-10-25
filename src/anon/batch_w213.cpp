#include "../common/types.h"

extern "C" {

extern float D_004f35a4;
extern float D_004f35a8;
void wtarget_00158fd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00158fd8jjjj");
// 00158fd8 (static initialiser, now made by gcc): moved to src/harata/libdk/bookcamera.cpp

struct S146 { u8 pad[235]; u8 b; u8 pad2[12]; u32 w; };
u32 func_00146ed8(void* a0, S146* p) {
    u8 b = p->b;
    if (b) { if ((s8)p->b >= 0) { if (p->w & 0x10) { p->w &= ~0x800; return 1; } } }
    p->w |= 0x800;
    return 0;
}

struct E197 { u8 pad[48]; s32 st; };
extern E197* D_0035037c;
extern s32 func_002283f8();
float GetRestTime_00197b98() asm("_ZN2YS5EVENT11GetRestTimeEv");
float GetRestTime_00197b98() {
    float r;
    E197* p = D_0035037c;
    if (p) {
        r = 3600.0f;
        if (p->st == 8) r = (float)func_002283f8();
    } else r = 0.0f;
    return r;
}

struct S1b0 { u32 a; u32 pad[2]; u32 b; };
struct R16 { u8 pad[6]; u16 h; };
extern R16* func_0016bc20(u32, u32, s32);
void func_001b0448(S1b0* a0, u32 a1) {
    R16* v = func_0016bc20(a1, 12, -1);
    if (v) { a0->a = a1; asm volatile("" ::: "memory"); a0->b = v->h; }
}

}
