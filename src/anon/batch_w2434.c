#include "../common/types.h"

typedef struct O_0016f610 {
    u8 pad[0x4c];
    u16 h4c;
    u16 h4e;
    u8 p50[7];
    s8 b57;
} O_0016f610;

extern u8 D_0032e020[];
u16* func_00189200(void*, s32);
u16* func_00188fe0(void*, u16);

static inline __attribute__((always_inline)) u16 getK_0016f610(O_0016f610* o) { return o->h4c; }

u16 func_0016f610(O_0016f610* o, s32 a1) {
    u16 r;
    u16* p;
    if (o->h4e == 0) r = 0;
    else {
        if ((getK_0016f610(o) == 1 || getK_0016f610(o) == 14) && a1 == 1) {
            p = func_00189200(D_0032e020, o->b57);
            r = 0; if (p) r = *p;
        } else {
            p = func_00188fe0(D_0032e020, getK_0016f610(o));
            r = 0; if (p) r = p[a1];
        }
    }
    return r;
}

extern s32 D_0035f12c;
extern u8 D_0035f130;
extern s8 D_0035f129;
extern u8 D_0035f128;
extern s16 D_01e21ec0[2][4];
void func_0026ed48(void);

void func_0026ec98(void) {
    s32 i, j;
    D_0035f12c = 0;
    D_0035f130 = 0;
    D_0035f128 = 0;
    D_0035f129 = -1;
    for (i = 0; i < 2; i++) {
        s32 k = (i != 0);
        for (j = 0; j < 4; j++) {
            D_01e21ec0[i][j] = 0x130 - k;
        }
    }
    func_0026ed48();
}

/* 0011efe8: clear low nibbles in place (u64 at a time, then bytes); twin of 0011f1a8 */
struct O_0011efe8;
struct Ovt_0011efe8 { u8 pad[0x30]; s32 (*fn)(struct O_0011efe8*); };
struct O_0011efe8 { struct Ovt_0011efe8* vt; };

void func_0011efe8(struct O_0011efe8* o, u8* p) {
    s32 n = o->vt->fn(o);
    s32 r = n & 7;
    s32 i;
    u64 m = 0xf0f0f0f0f0f0f0f0ULL;
    n >>= 3;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) { *q = *q & m; q++; }
    p = (u8*)q;
    for (i = 0; i < r; i++) { *p = *p & 0xf0; p++; }
}
