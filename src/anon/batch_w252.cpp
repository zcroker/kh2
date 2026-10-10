#include "../common/types.h"
extern "C" {
s32 func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036e978[], D_0036ed60[], D_0036e998[], D_0036e9d0[], D_0036ec40[];
void* func_001e3650(void*);  // ptr_add4
s32* func_001e3660(void*, s32);
void func_001e5220(s32, s32);
static inline void assert_fail_1e5610(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
void func_001e5610(s32* p) {
    s32 v;
    if (!p) assert_fail_1e5610(D_0036ed60, D_0036e9d0, 1596);
    p = func_001e3660(func_001e3650(p), 1);
    s32 n = *p++;
    for (s32 i = 0; i < n; i++) {
        v = *p++;
        if (v & 0xf) assert_fail_1e5610(D_0036ec40, D_0036e9d0, 1607);
        func_001e5220(v, 0x2800);
    }
}
// newlib __multadd
struct Bigint_w252 { Bigint_w252* next; s32 k, maxwds, sign, wds; u32 x[1]; };
Bigint_w252* func_00303b70(void*, s32);
void* memcpy_w252(void*, const void*, u32) asm("func_002fdd68");
void func_00303c18(void*, Bigint_w252*);  // push_entry_onto_slot_list
Bigint_w252* func_00303c48(void* ptr, Bigint_w252* b, s32 m, s32 a) {
    s32 i, wds;
    u32* x;
    u32 carry, y, z, xi;
    Bigint_w252* b1;
    wds = b->wds;
    x = b->x;
    i = 0;
    carry = a;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + carry;
        z = (xi >> 16) * m + (y >> 16);
        carry = z >> 16;
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (carry) {
        if (wds >= b->maxwds) {
            b1 = func_00303b70(ptr, b->k + 1);
            memcpy_w252((char*)&b1->sign, (char*)&b->sign, b->wds * sizeof(s32) + 2 * sizeof(s32));
            func_00303c18(ptr, b);  // push_entry_onto_slot_list
            b = b1;
        }
        b->x[wds++] = carry;
        b->wds = wds;
    }
    return b;
}
}

extern "C" {
extern u8 D_00347e60[];
extern u8 D_0035f3e0[];
extern void* D_0035f3c4;
extern void* D_0035f3c8;
extern s32 D_0035f3cc;
extern s32 D_0035f3d0;
void* func_001063c0(u32, s32);
void func_00239700(void*);
}
struct W252Sub { W252Sub() { func_00239700(this); } u8 pad[0x180]; };
struct W252Base {
    void* vt; u32 a, b; s32 c; u32 d, e;
    inline W252Base() __attribute__((always_inline));
};
struct W252Item : W252Base {
    W252Sub m;
    s32 f; u32 pad[7];
    inline W252Item() __attribute__((always_inline));
};
struct W252Pool {
    W252Item items[32];
    s32 ids[32];
    s32 count;
    inline W252Pool() __attribute__((always_inline));
    void* operator new(unsigned int sz, s32 h) { return func_001063c0(sz, h); }
};
inline W252Base::W252Base() { c = 0; vt = D_00347e60; }
inline W252Item::W252Item() { f = 0; vt = D_0035f3e0; }
inline W252Pool::W252Pool() { for (s32 i = 0; i < 32; i++) ids[i] = i; count = 32; }
extern "C" {
void func_0028c3f0(s32 h) {
    if (D_0035f3c4) {
        D_0035f3c8 = D_0035f3c4;
        D_0035f3d0 = D_0035f3cc;
    }
    D_0035f3cc = 0;
    *(s32*)&D_0035f3c4 = (s32)new (h) W252Pool;
}
}
