#include "../common/types.h"
extern "C" {
s32 func_00289310(void);
void func_002a8768(void);
void func_002a8330(void);
void func_002a98a8(void);
void func_002a95a8(void);
void func_00106420(void*);
void* func_00103570(void);
void* func_001063c0(u32, void*);
void func_002fde18(void*, s32, u32);
u32 func_002b64c8(void);
void func_00253b30(char*, u32);
void func_00170518(char*, s32, s32);
u32 func_002b6c04(u32);
extern void* D_0035f5d0;
extern void* D_0035f0e4;
extern u8 D_0035f0e8;
extern s32 D_003616e0;
extern u32 D_01e2a400[];
extern s8 D_003743c0[];

void func_002a82f8(void) {
    if (func_00289310()) {
        func_002a8768();
        func_002a8330();
    }
}

void func_002a9570(void) {
    if (func_00289310()) {
        func_002a98a8();
        func_002a95a8();
    }
}

void func_0029edf8(void) {  // release_global_obj
    if (D_0035f5d0) {
        func_00106420(D_0035f5d0);
        D_0035f5d0 = 0;
    }
}

void func_0029edb8(void) {  // alloc_global_obj
    D_0035f5d0 = func_001063c0(20, func_00103570());
    func_002fde18(D_0035f5d0, 0, 20);
}

void func_00264388(void) {  // alloc_global_buffer
    void* p = func_001063c0(2116, func_00103570());
    D_0035f0e4 = p;
    func_002fde18(p, 0, 2116);
    D_0035f0e8 = 0;
}

s32 func_00285d18(s32 x) {  // byte_list_contains
    s32 r = 0;
    s32 i;
    for (i = 0; D_003743c0[i] >= 0; i++) {
        if (D_003743c0[i] == x) {
            r = 1;
            break;
        }
    }
    return r;
}

u32 ResetVoiceState() asm("_ZN2Tz9MenuSound15ResetVoiceStateEv");
u32 ResetVoiceState() {
    s32 t = D_003616e0;
    u32 a = 0;
    if (t) {
        s32 n = t - 1;
        D_003616e0 = n;
        if (n > 0) {
            u32 k = t - 2;
            a = D_01e2a400[k];
        }
    }
    return func_002b6c04(a);
}
}
