#include "../common/types.h"
extern "C" {

extern "C" void func_0014b220x(void*, u32, u32, u32, u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");
extern "C" void func_0014b620x(void*, u64) asm("_ZN2dk8RectBase10setGsAlphaEy");
void func_0016c028x() asm("func_0016c028");
void func_001cc3b8(void*, u32);
extern u8 D_0032bae0;
char* func_0016e920(u32);
u32 func_00199810(char*);
u32 func_0019ab30(char*, u32);
void func_00199938(char*, char*) asm("_ZNK2YS13UNIT_DATA_OBJ6appearEPNS_10UNIT_GROUPE");

void func_0014a9a0(char* p, u32 n) {
    if (!n) n = 1;
    float f = (float)(n << 1);
    *(float*)(p + 256) = f;
    *(float*)(p + 260) = 128.0f / f;
    if (*(u8*)(p + 244) == 0) {
        func_0014b220x(p, 0, 0, 0, 0);
        func_0014b620x(p, 68);
    } else {
        func_0014b220x(p, 255, 255, 255, 0);
        func_0014b620x(p, 72);
    }
}

void func_0016bf38(char* a, u32 a1, char* c) {
    *(u32*)(a + 0x81c) = (u32)c;
    *(u32*)(a + 0x818) = a1;
    u32 h = *(u16*)(c + 40);
    if (h) *(u32*)(a + 0x500) = h;
    for (int i = 0; i < 2; i++) *(u32*)(a + 0x820 + i * 4) = *(u32*)(c + 32 + i * 4);
    u32 b = *(u8*)(c + 49);
    if (b) {
        u32 g = D_0032bae0;
        if (g != 14) {
            if (g == 16) {
                if (*(u32*)(a + 0x588) & 2) {
                    *(u32*)(a + 0xac8) = b;
                } else {
                    void* r = ((void*(*)())func_0016c028x)();
                    func_001cc3b8(r, *(u8*)(c + 49));
                }
            }
        } else {
            *(u32*)(a + 0xacc) = b;
        }
    }
}

void func_00199f90(char* t, char* s) {
    u32 w = *(u32*)(t + 4);
    u8 fl = w & 1;
    if (!fl) {
        char* r = func_0016e920(*(u32*)s);
        if (func_00199810(s)) {
            u32 v = *(u8*)(r + 4);
            if (v == 4 || v == 21) {
                if (func_0019ab30(t, *(u16*)(s + 30)))
                    func_00199938(s, t);
            } else {
                func_00199938(s, t);
                asm volatile("" ::: "memory");
            }
        }
    }
}

struct S6 { u32 a[6]; };
void func_00192990(u32, u32, S6*, char*);
void func_001aa388(char*, u32);
void func_001a9970(char* t, int n) {
    float f;
    if (n) {
        f = (float)n / (float)*(u8*)(*(u32*)(t + 4) + 17);
    } else {
        f = 1.0f;
    }
    *(float*)(t + 56) = f;
    *(float*)(t + 40) = f;
    u32 o = *(u32*)(t + 8);
    if (o) {
        S6 s = *(S6*)(t + 36);
        func_00192990(o, *(u32*)(t + 4), &s, t + 80);
        func_001aa388(t, *(u32*)(t + 8));
    }
}

}
