#include "../common/types.h"
extern "C" {

struct E436 { u8 pad[408]; u32 x; u8 pad2[24]; };
struct B0f4 { u8 pad[2040]; E436 e[8]; };
union U0f4 { B0f4* p; u32 u; };
extern U0f4 D_0035f0f4;
extern u32 D_0035f010;
extern u32 D_0035f01c;
extern u32 D_0035f024;
s32 func_002891e8(u32);
u32 func_00293bc0();
void func_001a8ff8(u32, s32, s32);
void func_002810c8(u32, u32);
u32 func_00287dc0();
void func_0023ebe0(u32, s32, s32);

void func_0026d748(void) {
    s32 a = func_002891e8(D_0035f01c);
    s32 b = func_002891e8(D_0035f024);
    u32 o = func_00293bc0();
    u32 t;
    func_001a8ff8(o, a, b);
    func_002810c8(D_0035f010, o);
    E436* pa = &D_0035f0f4.p->e[a];
    t = pa->x;
    E436* pb0 = &D_0035f0f4.p->e[b];
    pa->x = pb0->x;
    E436* pb = &D_0035f0f4.p->e[b];
    pb->x = t;
    func_0023ebe0(func_00287dc0(), a, b);
}

void func_001a9a28(u32 m, u32* p, u32* x, u32* y) {
    switch (m) {
    case 1: *x -= p[0]; break;
    case 2: *x -= p[0] >> 1; break;
    case 3: *x -= p[0] >> 1; *y -= p[1] >> 1; break;
    case 4: *x -= p[0] >> 1; *y -= p[1]; break;
    case 5: *y -= p[1]; break;
    }
}

}
