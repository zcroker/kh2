#include "../common/types.h"

struct W1786Q4 { u8 pad[8]; s32 x; };
struct W1786S350 { void (*fn)(s32, u32, s32); W1786Q4* p; s32 a; u32 b; s32 c; };
struct W1786Vn { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1786A1fb { u8 pad[0xc]; s32* p; };

extern "C" {
void FlushCache(s32);
s32 func_002f7dc8();
extern W1786S350 D_00350cb0;
void func_001adc48(s32 x) {
    if (x == 1 && D_00350cb0.fn) {
        FlushCache(0);
        if (func_002f7dc8()) {
            D_00350cb0.c = -1;
            D_00350cb0.fn(D_00350cb0.a, D_00350cb0.b, -1);
            D_00350cb0.fn = 0;
        } else {
            D_00350cb0.c = 0;
            D_00350cb0.fn(D_00350cb0.a, D_00350cb0.b, 0);
            D_00350cb0.fn = 0;
            D_00350cb0.p->x += (D_00350cb0.b + 0x7ff) >> 11;
        }
    }
}

void func_001fa668(u8*, s32, void*);
void W1786_wtarget(W1786Vn*, void*, W1786Vn*) asm("_Z16wtarget_002f3cd8jjjj");
void func_002f3f40(void*, W1786Vn*, f32);
void func_001faea8(void*, s32, s32);
extern u8* D_01d9e6e8;
void func_001fb3c8(u8* a0, s32 a1, W1786A1fb* a2) {
    func_001fa668(a0, a1, a2);
    u8* base = a0 + *a2->p;
    u8* pb = base + 0x150;
    u8* pa = base + 0xa0;
    W1786Vn v;
    f32 one = 1.0f;
    v.x = 0; v.y = 0; v.z = 0; v.w = one;
    W1786_wtarget(&v, D_01d9e6e8 + 0x50, &v);
    func_002f3f40(pb, &v, one / v.w);
    func_001faea8(pa, 0, 0);
}
}
