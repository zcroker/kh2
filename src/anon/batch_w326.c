#include "../common/types.h"

void* func_001e3650(void*);  // ptr_add4
void* func_001e3660(void*, s32);
void* func_001e3c98(void*, void*);
void* func_001e3e48(void*, void*);
u8 func_001e4028(void*, void*);
s32 func_001e41e0(u8* p);  // 0x001e41e0: definition moved into src/anon/unit_001e0cb8.cpp

void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036ef58[], D_0036efc8[], D_0036ef88[], D_0036ef98[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
void func_001e8558(void*, void*);
void func_001e78e0(void*);
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;

s32 func_001e8c28(u8* p, void* b);  // 0x001e8c28: definition moved into src/anon/unit_001e8ac8.cpp
