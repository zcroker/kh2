#include "../common/types.h"

// ---- 002bc0f0
extern "C" {
extern u8 D_003616f0;
extern s32 D_003616f4;
typedef struct Ent64 { u8 d[64]; } Ent64;
typedef struct Pool { Ent64 e[64]; s32 idx[64]; s32 n; } Pool;
extern Pool D_01e2aa90;
static inline Ent64* pop_w8004(Pool* p) { p->n--; return &p->e[p->idx[p->n]]; }
// Pops a 64-byte entry from the pool when the counter is below 25.
Ent64* func_002bc0f0(void) {
    if (D_003616f0 != 0 || D_01e2aa90.n == 0) return 0;
    if (D_003616f4 >= 25) return 0;
    D_003616f4++;
    return pop_w8004(&D_01e2aa90);
}
}

// ---- 0028f878
extern "C" {
extern u8* D_0035f480;
union GPi_w8004 { u8* p; s32 i; };
extern GPi_w8004 D_0035f480u_w8004 asm("D_0035f480");
s32 func_00139d78(void*);
void func_00139510(void*);
s32 func_0028d6e8(void*);
}
// The exit test inside a for(;;) with break keeps the loop counting up (slti 4).
void func_0028f878(void*) {
    s32 i;
    if (D_0035f480) {
        for (i = 0;;) {
            if (func_00139d78(D_0035f480 + i * 884)) func_00139510(D_0035f480 + i * 884);
            *(u32*)(i * 884 + D_0035f480 + 880) = 0;
            if (func_0028d6e8(D_0035f480u_w8004.p + i * 884 + 436)) func_00139510(D_0035f480u_w8004.p + i * 884 + 436);
            i++;
            if (i >= 4) break;
        }
    }
}

// ---- 00286298
struct Bits_w8004 {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct BitsC8_w8004 { u8 pad[0xc8]; Bits_w8004 bits; };
struct BitsCC_w8004 { u8 pad[0xcc]; Bits_w8004 bits; };
extern "C" {
extern BitsC8_w8004* D_0035f2e4;
extern s16 D_003743d8[];
extern s16 D_003743e8[];
BitsCC_w8004* func_002859a0(void);
s32 func_001a3570(s32);
s32 func_001a36e0(s32);
void u_call0_00286298(void) asm("_Z16u_call0_00286298v");
// Separate counters per loop give each loop its own PRE copy of i*2.
void u_call0_00286298(void)
{
    u32 i = 0;
    BitsCC_w8004* cur = func_002859a0();
    for (; D_003743d8[i] >= 0; i++) {
        if (func_001a3570(func_001a36e0(D_003743d8[i])) && !cur->bits.Test(i)) D_0035f2e4->bits.Set(i);
    }
    for (u32 j = 0; D_003743e8[j] >= 0; j++) {
        if (func_001a3570(D_003743e8[j]) && !cur->bits.Test(j + 5)) D_0035f2e4->bits.Set(j + 5);
    }
}
}
