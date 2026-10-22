#include "../common/types.h"

extern u8* D_0035f230;
extern s32 D_0035f01c;
extern s32 D_0035f010;
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
u8* func_00281180(s32, s32);
u8* func_001a80c8(u16);
s32 func_001145b0(u16);

typedef struct E8 { u32 a, b; } E8;
typedef struct H { u8 p[8]; s32 n; u32 pad; E8 e[1]; } H;
H* func_00294000(s32);
s32 func_002944d0(E8*);
s32 func_00276c18(void);

void func_00279860(void) {
    s32 i;
    s32 v;
    s32 a, b;
    s32 k;
    s32 r;
    for (i = 0; i < (s8)D_0035f230[7]; i++) {
        D_0035f230[i * 8 + 0x12] = 0xff;
    }
    if (func_00287bc0() == 15) {
        v = func_0028b040(D_0035f01c);
    } else {
        v = func_002570a0(15);
    }
    func_0027aed8(v, &a, &b);
    k = 0;
    if (a == 0) k = b;
    if (k != 0) {
        s32 base = *(s32*)(func_00281180(D_0035f010, k) + 0x244);
        for (i = 0; i < (s8)D_0035f230[7]; i++) {
            if (func_001a80c8(*(u16*)(D_0035f230 + i * 8 + 0xc))[6] == 2) {
                v = func_001145b0(*(u16*)(D_0035f230 + i * 8 + 0xc));
                D_0035f230[i * 8 + 0x12] = *(u8*)(v + base + 0xf5);
            }
        }
    }
}

s32 func_002a6500(void) {
    s32 i; s32 r = 0;
    H* h = func_00294000(6);
    E8* e = h->e;
    for (i = 0; i < h->n; i++) if (func_002944d0(&e[i])) { r = 1; break; }
    if (func_00276c18()) r = 1;
    return r;
}
