#include "../common/types.h"

void* func_001e3650(void*);  // ptr_add4
void* func_001e3660(void*, s32);
void* func_001e3c98(void*, void*);
void* func_001e3e48(void*, void*);
u8 func_001e4028(void*, void*);
s32 func_001e41e0(u8* p) {
    void* q = *(void**)(p + 0x88);
    void* t;
    q = func_001e3650(q);  // ptr_add4
    t = func_001e3660(q, 2);
    t = func_001e3c98(t, *(u8**)(p + 0x8c) + 0xc0);
    t = func_001e3e48(t, *(u8**)(p + 0x8c) + 0xd0);
    return func_001e4028(t, *(u8**)(p + 0x8c) + 0xe0);
}

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

s32 func_001e8c28(u8* p, void* b) {
    s32 v, nv;
    if (!p) ryjAssert(D_0036efc8, D_0036ef88, 1000);
    func_001e8558(p, b);
    func_001e78e0(p);
    if (D_01d9ea9c != 0 || (*(u64*)(D_01d9e6e0 + 0xa8) & 0xff0000ff00ULL)) return 0;
    v = *(s32*)(p + 0x58);
    nv = v + 0x1000;
    *(s32*)(p + 0x5c) = v;
    *(s32*)(p + 0x58) = nv;
    if (p[0x84]) {
        if (p[0x85]) return *(s32*)(p + 0x74) == 0;
        if (nv > 0x6fffffff) {
            *(s32*)(p + 0x58) = 0x70000000;
            *(s32*)(p + 0x5c) = 0x6ffff000;
        }
        return 0;
    }
    return !(nv < *(s32*)(p + 0x54));
}
