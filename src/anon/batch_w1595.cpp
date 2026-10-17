#include "../common/types.h"
extern "C" {
static inline bool w1595_TestBit(u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }

s32 func_00258048();
s32 func_00283ab8(s32);
s32 func_00181500(u16);
struct W1595Rec { s32 a; u16 id; u16 b; };
extern W1595Rec D_003742c8[];

s32 func_00283b78(void) {
    s32 r = 0;
    u8* st = (u8*)func_00258048();
    if (!func_00283ab8(-1)) return 0;
    for (u32 i = 0; D_003742c8[i].id != 0; i++) {
        if (func_00181500(D_003742c8[i].id) && !w1595_TestBit((u32*)(st + 200), i)) { r = 1; break; }
    }
    return r;
}

void func_001039f8();
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0024ffe0();
void func_00250130();
void func_00252ba8();
void func_00252bf0();
void func_00252c20();
s32 func_00287bc0();
void func_00287d68();
s32 func_00287db0();
extern void* D_0035ee34;
extern void* D_0035ee38;
extern void* D_0035ee3c;
extern void* D_0035ee40;
extern void* D_0035ee44;
extern void* D_0035eea4;
extern void* D_0035eea8;

// The || chain with a single "return 0" keeps the result in v0 (separate returns put it in t7).
s32 func_0024ff08(void) {
    s32 s = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (func_0028acc8(D_0035ee34) || func_0028acc8(D_0035ee38) || func_00139d78(D_0035ee3c)
            || func_00139d78(D_0035ee40) || func_00139d78(D_0035ee44)) return 0;
        func_001039f8();
        return 1;
    }
    switch (s) {
    case 0: func_0024ffe0(); return 0;
    case 1: func_00250130(); return 0;
    }
    return 0;
}

s32 func_00252ad8(void) {
    s32 s = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if ((D_0035eea4 && func_00139d78(D_0035eea4)) || func_00139d78(D_0035eea8)) return 0;
        func_001039f8();
        return 1;
    }
    switch (s) {
    case 0: func_00252ba8(); break;
    case 1: case 2: case 3: func_00252c20(); break;
    case 4: func_00252bf0(); break;
    }
    return 0;
}

s32 func_00281100(s32);
s32 func_002811b0(s32, s32);
s32 func_001058e8();
u16* func_00188fe0(s32, s32);
void func_00293500(s32, s32, u32);
s32 func_00281480(s32, s32);
s32 func_002815b8();
s32 func_00281388(s32);
u32 func_002814b0(s32);
extern s32 D_0035f010;

void func_00254568(void) {
    s32 i = 0;
    s32 n = func_00281100(D_0035f010);
    for (; i < n; i++) {
        s32 e = func_002811b0(D_0035f010, i);
        func_00293500(e, 0, *func_00188fe0(func_001058e8() + 9456, e));
        if (func_00281480(D_0035f010, i)) {
            s32 o = func_002815b8();
            if (func_00281388(o)) func_00293500(e, 1, func_002814b0(o));
        }
    }
}
}
