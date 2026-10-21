#include "../common/types.h"
extern s32 D_0035ec84;
extern u8* D_0035ec88;
extern u8* D_0035ec8c;
extern u8* D_0035ec90;
extern u8* D_0035ec94;
extern u8* D_0035ec98;
extern u8* D_0035ec9c;
extern u8* D_0035eca0;
extern void* D_0035eca4;
u8* func_001063f0(s32, s32);
u8* func_001063c0(s32, s32);
void* memset(void*, int, unsigned int) asm("_Z16wtarget_002fde18jjjj");
s32 func_00240440(s32);
void func_00241fd0(void*, s32);
typedef struct W1949_Hd { s8 a; u8 pad; s16 b; } W1949_Hd;
void func_0023fe60(void) {
    D_0035ec88 = func_001063f0(0x50, D_0035ec84); memset(D_0035ec88, 0, 0x50);
    D_0035ec8c = func_001063f0(0x1a, D_0035ec84); memset(D_0035ec8c, 0, 0x1a);
    s32 a = func_00240440(0x8a58);
    s32 sz;
    if (a > func_00240440(0x10fc0)) sz = func_00240440(0x8a58); else sz = func_00240440(0x10fc0);
    sz = sz << 10;
    D_0035ec90 = func_001063f0(sz, D_0035ec84); memset(D_0035ec90, 0, sz);
    D_0035ec94 = func_001063c0(0xc68, D_0035ec84); memset(D_0035ec94, 0, 0xc68);
    ((W1949_Hd*)D_0035ec94)->a = -1;
    ((W1949_Hd*)D_0035ec94)->b = -1;
    D_0035ec98 = func_001063c0(0xf80, D_0035ec84); memset(D_0035ec98, 0, 0xf80);
    D_0035eca0 = func_001063f0(0x1900, D_0035ec84); memset(D_0035eca0, 0, 0x1900);
    u8* p = D_0035eca0;
    u32 m = (u32)p & 0x3f;
    if (m != 0) p = p - m + 0x40;
    D_0035ec9c = p;
    void* q = func_001063c0(8, D_0035ec84);
    func_00241fd0(q, D_0035ec84);
    D_0035eca4 = q;
}

typedef struct W1949_Flags { u8 pad[80]; u32 f80[3]; u32 f92[8]; } W1949_Flags;
static inline s32 W1949_Bit(u32* a, u32 n) { return (a[n >> 5] & (1 << (n & 31))) != 0; }
extern W1949_Flags* D_0035f2e4;
s32 func_00258108(void);
s32 func_002811b0(s32, s32);
s32 func_001b7818(s32);
s32 func_00286d28(s32 a, s32 b) {
    s32 r = 0;
    s32 ctx = func_00258108();
    s32 i;
    if (a <= 0) {
        if (b < 0) {
            for (i = 0; i < 80; i++) {
                r = W1949_Bit(D_0035f2e4->f80, i);
                if (r) break;
            }
        } else {
            r = W1949_Bit(D_0035f2e4->f80, b);
        }
        if (r || a == 0) return r;
    }
    for (i = 1; i < 4; i++) {
        if (a < 0 || i == a) {
            s32 v = func_002811b0(ctx, i);
            if (v) {
                s32 g = func_001b7818(v) - 2;
                s32 j;
                for (j = 0; j < 48; j++) {
                    if (b < 0 || j == b) {
                        v = g * 48 + j; r = W1949_Bit(D_0035f2e4->f92, v);
                        if (r) break;
                    }
                }
                if (r) break;
            }
        }
    }
    return r;
}
