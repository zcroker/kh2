#include "../common/types.h"
extern "C" {
u32 func_001bb4a0();
u32 func_001bbcb0();
extern s8* D_0035f12c;
void func_00181d30(s16*, s16*, s16*);

struct W1519E38 { u8 pad[0xf4]; u32 on : 1; u32 : 31; };
u32 func_001d8898(s32 i) {
    if (func_001bb4a0()) {
        u32 b = func_001bbcb0();
        u32 o = i * 0x38;
        if ((u8)((W1519E38*)(b + o))->on) { u32 m = *(u32*)(func_001bbcb0() + o + 0xf4) & 8; return m != 0; }
    }
    return 0;
}

struct W1519E34 { u8 pad[0x19c]; u32 on : 1; u32 : 31; };
u32 IsGaugeWarning_w1519(s32 i) asm("_ZN2YS7MISSION14IsGaugeWarningEi");
u32 IsGaugeWarning_w1519(s32 i) {
    if (func_001bb4a0()) {
        u32 b = func_001bbcb0();
        u32 o = i * 0x34;
        if ((u8)((W1519E34*)(b + o))->on) { u32 m = *(u32*)(func_001bbcb0() + o + 0x19c) & 8; return m != 0; }
    }
    return 0;
}

s32 func_00272c20(u32 i) {
    s32 r = -1;
    switch (i) {
    case 0: return 4;
    case 1: return D_0035f12c[0];
    case 2: return D_0035f12c[1];
    case 3: return 1;
    case 4: r = D_0035f12c[2]; break;
    }
    return r;
}

void func_00181cc0(s16* base, s32 id) {  // chunk_find
    s16* p = base;
    while (*p != -1) {
        s16* n = (s16*)((u8*)p + p[1]);
        if (*p == id) { func_00181d30(base, p + 2, n); return; }
        p = n;
    }
}
}
