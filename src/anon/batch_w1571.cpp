#include "../common/types.h"
extern "C" {
void func_0031a838(void*);
void func_00239700(void*);
extern u8 D_00347e40[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
static inline void c3237e0_A(u8* p) { *(void**)p = D_00347f98; func_0031a838(p + 0xc); }
static inline void cB(u8* p) { c3237e0_A(p); *(void**)p = D_00347e60; func_00239700(p + 0x18); }
static inline void cC(u8* p) { cB(p); *(void**)p = D_00347e40; *(u32*)(p + 0x198) = 0; }
static inline void cD(u8* p) { *(u32*)(p + 0xc) = 0; *(void**)p = D_00347e60; func_00239700(p + 0x18); }
void func_003237e0(u8* p) {
    cC(p);
    cD(p + 0x1b4);
    { u8* q = p + 0x34c; s32 i = 1; do { cD(q); i--; q += 0x198; } while (i != -1); }
    { u8* q = p + 0x67c; s32 i = 1; do { cD(q); i--; q += 0x198; } while (i != -1); }
    { u8* q = p + 0x9ac; s32 i = 2; do { cC(q); i--; q += 0x1b4; } while (i != -1); }
    { u8* q = p + 0xec8; s32 i = 2; do { cC(q); i--; q += 0x1b4; } while (i != -1); }
}
// Static init/destroy (priority 0xffff); the empty destructor loop gets the r5900 short-loop nop padding.
void func_0031e2b8(void*);
struct V4f1c6c78 { f32 x, y, z, w; };
struct V3i1c6c78 { s32 a, b; f32 c; };
extern V4f1c6c78 D_01d497c0;
extern V3i1c6c78 D_01d497d0;
extern V3i1c6c78 D_01d497e0;
struct E1680 { u8 v[16]; u32 a10, a14; u32 pad; u8 m[4]; ~E1680() { asm volatile(""); } };
extern E1680 D_00351680[50];
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

}
