#include "../common/types.h"

extern "C" {
void* func_00294000(s32);
s32 func_002ab100(s32);
extern u8* D_0035f610;
s32 func_002ab2b0(s32 id) {
    s32 r = 0;
    s32* p = (s32*)func_00294000(7);
    u16* base = (u16*)((u8*)p + 16);
    if (id < 0) {
        r = func_002ab100(-1);
    } else {
        s32 n = p[2];
        s32 i = 0;
        if (n > 0) {
            u16* e = base;
            do {
                u16 v = *e;
                e += 4;
                if (v == id) {
                    u32* bits = (u32*)(D_0035f610 + 136);
                    if (bits[(u32)i >> 5] & (1 << (i & 31))) { r = 1; break; }
                }
                i++;
            } while (i < n);
        }
    }
    return r;
}

void func_001ad990(u32, f32, f32, f32);
void* func_0017e668(void);
s32 func_0019ba60(void*);
void* func_001a8f10(void*);
extern s32 D_00351f30;
extern u32 D_01d49980[];
void func_001c97b0(void* a, f32 f) asm("_Z13func_001c97b0Pvf");
void func_001c97b0(void* a, f32 f) {
    u8* s0 = (u8*)func_0017e668();
    if (func_0019ba60(s0)) {
        if (!(*(volatile u32*)(s0 + 2040) & 0x10)) {
            func_001ad990((u32)(s0 + 2092), 1.0f, 0.0f, f);
        }
        *(u32*)(s0 + 2040) |= 0x10;
    }
    D_01d49980[D_00351f30++] = (u32)func_001a8f10(a);
}

void func_00108698(void*);
void func_00144450(void*);
void func_0011b6a8(void*);
void func_0031e158(u32* a) {
    u8* s = (u8*)a;
    a[0] = 0;
    func_00108698(s + 8);
    func_00144450(s + 208);
    *(u32*)(s + 244) = 0;
    *(u32*)(s + 240) = 0;
    *(f32*)(s + 264) = 2100.0f;
    s[232] = 0x80;
    s[233] = 0x80;
    s[234] = 0x80;
    s[235] = 0x80;
    *(u32*)(s + 248) = 0;
    *(u32*)(s + 252) = 0;
    *(u32*)(s + 256) = 0;
    *(u32*)(s + 260) = 0;
    s[269] = 0;
    *(u32*)(s + 272) = 0;
    *(u32*)(s + 276) = 0;
    *(u16*)(s + 280) = 0;
    *(u16*)(s + 282) = 0;
    s[286] = 0;
    s[287] = 0;
    *(u32*)(s + 288) = 0;
    s[271] = 0;
    s[270] = 0;
    func_0011b6a8(s + 64);
    func_0011b6a8(s + 128);
    *(u32*)(s + 248) = 2060;
}

void* func_001063c0(s32, s32);
void func_002907c0(void*, s32, s32);
extern s32 D_0035f570;
extern void* D_0035f574;
extern u32* D_0035f578;
void func_00293e00(s32 a) {
    D_0035f570 = a;
    void* p = func_001063c0(24, D_0035f570);
    func_002907c0(p, D_0035f570, 10);
    D_0035f574 = p;
    u32* q = (u32*)func_001063c0(64, D_0035f570);
    u32* t = q;
    for (s32 i = 15; i >= 0; i--) *t++ = 0;
    s32 j = 15;
    D_0035f578 = q;
    asm volatile("" ::: "memory");
    u32* r = D_0035f578;
    for (; j >= 0; j--) *r++ = 0;
}

f32 func_002f8420(f32);
void func_00106fe8(u8* a, f32 x) {
    f32 k = 0.5f;
    *(f32*)(a + 64) = x;
    *(f32*)(a + 68) = func_002f8420(512.0f / *(f32*)(a + 76) * k / x) * 2.0f;
    *(f32*)(a + 72) = func_002f8420(416.0f / *(f32*)(a + 80) * k / x) * 2.0f;
}
}
