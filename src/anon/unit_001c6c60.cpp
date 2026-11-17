// 0x1c6c60-0x1c6e58: end of the spawner file: state setter, static init (plain function), its
// _GLOBAL__I_ stub and the _GLOBAL__D_ stub 0x1c6e38. The objects stay retail data.
#include "../common/types.h"

// ---- 001c6c60 from src/anon/auto200_999.cpp
namespace n001c6c60 {
void func_001c6c60(u32 a0) asm("_Z13func_001c6c60j");
void func_001c6c60(u32 a0) {
    s32 t7 = 0x001c0000;
    *(volatile u8 *)(a0 + 21) = 0;
    asm volatile("" : "+r"(t7)::"memory");
    t7 += 27176;
    *(u32 *)(a0 + 84) = t7;
}
}  // namespace n001c6c60

// ---- 001c6c78 from src/anon/batch_w1571.cpp
namespace n001c6c78 {
void func_0031e2b8(void*) asm("func_0031e2b8");
struct V4f1c6c78 { f32 x, y, z, w; };
struct V3i1c6c78 { s32 a, b; f32 c; };
extern V4f1c6c78 D_01d497c0 asm("D_01d497c0");
extern V3i1c6c78 D_01d497d0 asm("D_01d497d0");
extern V3i1c6c78 D_01d497e0 asm("D_01d497e0");
struct E1680 { u8 v[16]; u32 a10, a14; u32 pad; u8 m[4]; ~E1680() { asm volatile(""); } };
extern E1680 D_00351680[50] asm("D_00351680");
void wtarget_001c6c78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001c6c78jjjj");
void wtarget_001c6c78(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        f32 k = 1000.0f; f32 z = 0.0f;
        D_01d497c0.x = k; D_01d497c0.y = z; D_01d497c0.z = k; D_01d497c0.w = z;
    }
    if (a1 == 0xffff && a0 == 1) {
        D_01d497d0.a = 0; D_01d497d0.b = 1468; D_01d497d0.c = 115.2f;
    }
    if (a1 == 0xffff && a0 == 1) {
        D_01d497e0.a = a0;
        D_01d497e0.b = 1469;
        D_01d497e0.c = 115.2f;
    }
    if (a1 == 0xffff && a0 == 1) {
        E1680* p = D_00351680;
        s32 i = 49;
        do {
            func_0031e2b8(p->m);
            func_0031e2b8(p->m);
            p->a10 = 0;
            p->a14 = 0;
            asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" :: "r"(p) : "memory");
            i--;
            p++;
        } while (i != -1);
    }
    if (a1 == 0xffff && a0 == 0) {
        if (D_00351680) {
            E1680* e = D_00351680 + 50;
            for (;;) { e->~E1680(); if (e == D_00351680) break; --e; }
        }
    }
}
}  // namespace n001c6c78

// ---- 001c6e18 from src/anon/tiny_wrappers_more.cpp
namespace n001c6e18 {
u32 func_001c6c78(u32, u32, u32, u32) asm("_Z13func_001c6c78jjjj");
u32 func_001c6e18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c6e18jjjj");
u32 func_001c6e18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c6c78(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001c6e18

// ---- 001c6e38 gap: _GLOBAL__D_ stub of the static init 0x1c6c78
namespace n001c6e38 {
u32 func_001c6c78(u32, u32, u32, u32) asm("_Z13func_001c6c78jjjj");
u32 func_001c6e38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c6e38");
u32 func_001c6e38(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c6c78(0, 0xffff, a2, a3);
}
}  // namespace n001c6e38

