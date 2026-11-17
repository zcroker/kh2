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
void func_001e5610(s32* p);  // 0x001e5610: definition moved into src/anon/unit_001e0cb8.cpp
// newlib __multadd
struct Bigint_w252 { Bigint_w252* next; s32 k, maxwds, sign, wds; u32 x[1]; };
Bigint_w252* _Balloc(void*, s32);
void* memcpy_w252(void*, const void*, u32) asm("memcpy");
void _Bfree(void*, Bigint_w252*);  // push_entry_onto_slot_list
Bigint_w252* __multadd(void* ptr, Bigint_w252* b, s32 m, s32 a);  // 0x00303c48: definition moved into src/newlib/libc/mprec.c
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
void func_0028c3f0(s32 h);  // 0x0028c3f0: definition moved into src/anon/unit_0028bfc0.cpp
}
