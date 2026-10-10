#include "../common/types.h"

extern s32 D_01da8cd0[8];
extern s32 D_00352c40, D_01d9e6c4;
extern char D_01d9e5b0[], D_0036eef0[];
u64 func_00313b80(f32);
s32 wsprintf_002fee78(char*, const char*, ...) asm("_Z16wtarget_002fee78jjjj");

char* func_001e6188(void) {
    char* buf = D_01d9e5b0;
    s32* s = D_01da8cd0;
    u64 d = func_00313b80((f32)D_01d9e6c4 / (f32)D_00352c40 * 100.0f);
    wsprintf_002fee78(buf, D_0036eef0, s[4], s[0], s[5], s[1], s[6], s[2], d);
    return buf;
}

typedef unsigned int u128 __attribute__((mode(TI)));
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;

Q128* func_0021c810(Q128* p, s32 a, s32 b) {
    s32 i;
    p->q = 0;
    if (a == 0) p->w[3] = 0x6c40004f; else p->w[3] = 0x6c40023f;
    p++;
    for (i = 8; i != 0; i--) {
        p[0].d[0] = b ? 0x703b400000008001ULL : 0x702b400000008001ULL;
        p[0].d[1] = 0x042412e6;
        p[1].q = 0;
        p[2].d[0] = 0;
        p[2].d[1] = 66;
        p[3].q = 0;
        p[4].q = 0;
        p[5].q = 0;
        p[6].q = 0;
        p[7].q = 0;
        p[5].w[3] = 0x8000;
        p[6].f[2] = 1.0f;
        p[3].f[2] = 1.0f;
        p += 8;
    }
    return p;
}

void func_002fdfc8(const char*, ...);
void func_001e2ad8(const char*, const char*, s32, const char*);
extern char D_0036e978[], D_0036e998[], D_0036e9d0[];
extern char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ec80[], D_0036ec98[];
typedef struct { u32 a; u32 b; } W325E8;
extern W325E8 D_00353e48[];

/* RyjAssert: "RyjAssertion failed: %s\n" then "   File %s, Line %u\n", break. */
static inline void ryjAssert5(const char* a, const char* e, const char* b, const char* f, s32 l) {
    func_002fdfc8(a, e);
    func_002fdfc8(b, f, l);
    asm volatile("break");
}
#define RYJ_ASSERT(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)

u32* func_001e3c98(s32* p, u8* bits) {
    s32 n = *p++;
    s32 i;
    u8 m = 0;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)*p++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        RYJ_ASSERT(!((u32)e & 0xf), D_0036ec40, 1014);
        RYJ_ASSERT(byte < 16, D_0036ec58, 1015);
        RYJ_ASSERT(byte >= 0, D_0036ec70, 1015);
        if (bit == 0) m = bits[byte];
        if (m & 1) {
            s32 id = *(s16*)e;
            if (id >= 128) func_001e2ad8(D_0036ec80, D_0036e9d0, 1027, D_0036ec98);
            D_00353e48[id].a = (u32)(e + 16);
            D_00353e48[id].b = *(u32*)(e + 8);
        }
        m >>= 1;
    }
    return (u32*)p;
}
