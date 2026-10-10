#include "../common/types.h"

void func_001e7798(u32* h, u32 q) {
    u32* t = (u32*)(q - 16);
    u32* n;
    t[2] = 0;
    h[0] = (u32)t;
    h[3] -= t[0] - (u32)t;
    n = (u32*)t[1];
    if (n && n[2] == 0) {
        n[0] = *(u32*)(q - 16);
        q = *(u32*)(q - 16);
        ((u32*)q)[1] = (u32)n;
        t = n;
    }
    q = t[0];
    if (((u32*)q)[2] == 0) {
        t[0] = ((u32*)q)[0];
        q = ((u32*)q)[0];
        ((u32*)q)[1] = (u32)t;
    }
}

typedef union W { s32 w; u8 c; } W;
typedef struct E { s32 x, y; W a; W b; } E;
void func_001e8288(u8* p, s32 d) {
    u8* b;
    u32* q;
    s32* t;
    s32 n;
    s32 i;
    u8* e;
    p += 0x110;
    b = p;
    p += 12;
    t = (s32*)(b + *(u32*)p);
    p += 4;
    n = *t++;
    for (;;) {
        for (i = 0; i < *(s16*)(p + 0x26); i++) {
            ((E*)(p + 0x28))[i].a.w = d + ((E*)(p + 0x28))[i].a.w;
            ((E*)(p + 0x28))[i].b.w = d + ((E*)(p + 0x28))[i].b.w;
        }
        if (*(u32*)p == 0) break;
        p = (u8*)(*(u32*)p = d + *(u32*)p);
    }
    if (n > 0) {
        s32* a = t;
        s32 k = n;
        do { *a++ += d; } while (--k);
    }
}

void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ecb0[], D_0036ecc8[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
static inline void ryjTail(const char* f, s32 l) {
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERTM(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); ryjTail(D_0036e9d0, l); }
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
void func_001e2ad8(const char*, const char*, s32, const char*);
typedef union { s32 a; u8* p; u8 c; } U;
typedef struct { U a, b, c, d, e; U f; U g; U h; U k; } T;
extern T D_00352c48[];
u32* func_001e3e48(s32* p, u8* bits) {
    s32 n;
    u32* q;
    s32 i;
    u32 m;
    u32 v;
    s32 byte, bit;
    q = (u32*)p;
    n = *q++;
    i = 0;
    m = 0;
    for (; i < n; i++) {
        v = *q++;
        byte = i >> 3;
        bit = i & 7;
        ASSERTM(!(v & 0xf), D_0036ec40, 1053);
        ASSERT(byte < 16, D_0036ec58, 1054);
        ASSERT(byte >= 0, D_0036ec70, 1054);
        if (bit == 0) m = bits[byte];
        if ((u8)(m & 1)) {
            s32 k = *(s16*)v;
            u8* d = (u8*)v + 16;
            T* t;
            if (!(k < 128)) func_001e2ad8(D_0036ecb0, D_0036e9d0, 1068, D_0036ecc8);
            t = &D_00352c48[k];
            t->h.p = d;
            t->a.a = *(s16*)(d + 18);
            t->b.a = *(s16*)(d + 20);
            t->c.a = *(s16*)(d + 16);
            t->f.p = d + *(s32*)(d + 8);
            t->g.p = d + *(s32*)(d + 12);
            t->k.a = *(u32*)(v + 8);
        }
        m >>= 1;
    }
    return q;
}

