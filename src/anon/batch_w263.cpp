#include "../common/types.h"
extern "C" {
extern u8 D_0032e020[];
void* func_00189200(void*, u8);
void* func_00188fe0(void*, u8);
void func_00188958(void*, u8);
void func_001891b8(void*, u16);
void func_001a3188(u32, u8, u32);

void func_001c2d88(u8* p);  // 0x001c2d88: definition moved into src/anon/unit_001c2b58.cpp

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
