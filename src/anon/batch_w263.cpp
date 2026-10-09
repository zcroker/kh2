#include "../common/types.h"
extern "C" {
extern u8 D_0032e020[];
void* func_00189200(void*, u8);
void* func_00188fe0(void*, u8);
void func_00188958(void*, u8);
void func_001891b8(void*, u16);
void func_001a3188(u32, u8, u32);

void func_001c2d88(u8* p) {
    u8* s1;
    void* s2;
    s1 = 0;
    s2 = 0;
    if (p[2] & 0x80) {
        s2 = func_00189200(D_0032e020, p[2] % 128);
    } else {
        s1 = (u8*)func_00188fe0(D_0032e020, p[2]);
    }
    if (s1) {
        s1[5] = s1[4] = p[3];
        s1[7] = s1[6] = p[4];
        s1[8] = p[5];
        s1[9] = p[6];
        s1[10] = p[7];
        s1[11] = p[8];
        s1[16] = p[9];
        s1[17] = p[10];
        func_00188958(s1, p[11]);
    }
    for (s32 n = 0; n < 32; n++) {
        u16 v = ((u16*)(p + 12))[n];
        if (v) {
            if (s2 == 0) func_001a3188(v & 0xffff7fff, p[2], v >> 15);
            else func_001891b8(s2, v);
        }
    }
}

extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_00347e40[];
void func_00239700(void*);
void func_0031a838(void*);
}

struct W263A {
    u8* vt; u32 f4, f8, f12, f16, f20; u8 m24[384];
    W263A() { f12 = 0; vt = D_00347e60; func_00239700(m24); }
};
struct W263B {
    u8* vt; u32 f4, f8; u8 m12[12]; u8 m24[384]; u32 f408; u8 pad[24];
    W263B() {
        vt = D_00347f98; func_0031a838(m12);
        vt = D_00347e60; func_00239700(m24);
        vt = D_00347e40; f408 = 0;
    }
};
struct W263S : W263A {
    W263A a[4]; W263B b[4]; u8 pad[32]; W263B c[5];
    inline W263S() __attribute__((always_inline));
};
inline W263S::W263S() {}
inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
void func_00323408(W263S* p) { new (p) W263S; }

}
