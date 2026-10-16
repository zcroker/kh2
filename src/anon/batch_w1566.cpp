#include "../common/types.h"

struct W1566E32 { u32 a, b, c, d; u32 pad[4]; };
struct W1566H { u8 hdr[16]; W1566E32 arr[4]; };
struct W1566E16 { u32 w[4]; };

extern W1566H D_01e2bfb0;
extern u8 D_00345c08[], D_0034e8b8[], D_0034ee08[];

extern "C" {
void func_00319f88(void*);
void func_0019f9a8(void*);
void func_001c0248(void*);
void func_00319fb0(void*);
void func_00105110(void*);

// static init/destruction of a 4-element array of 32-byte objects (ctor clears +0xc, empty dtor)
void wtarget_002e98f0(u32 a, u32 b) asm("_Z16wtarget_002e98f0jjjj");
void wtarget_002e98f0(u32 a, u32 b) {
    if (b == 0xffff && a == 1) {
        W1566H* h = &D_01e2bfb0;
        W1566E32* p = h->arr;
        s32 n = 3;
        do { p->d = 0; n--; p++; } while (n != -1);
    }
    if (b == 0xffff && a == 0) {
        W1566H* h = &D_01e2bfb0;
        if (h->arr) {
            W1566E32* p = h->arr + 4;
            for (;;) { if (p == h->arr) break; p--; }
        }
    }
}

// deleting destructor: three vtable levels, member array of 16-byte objects, then operator delete
void func_00319df8(u8* p) {
    *(void**)p = D_00345c08;
    if ((W1566E16*)(p + 3184)) {
        W1566E16* e = (W1566E16*)(p + 3280);
        for (;;) { if ((W1566E16*)(p + 3184) == e) break; e--; }
    }
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);
    func_001c0248(p + 2640);
    func_00319fb0(p);
    func_00105110(p);
}
}
