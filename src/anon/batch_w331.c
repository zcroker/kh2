#include "../common/types.h"

typedef struct Px { u8 r, g, b, a; u32 x4; } Px;
typedef struct Sub { s16 x0; s16 n; s32 off; } Sub;
typedef struct Ent { s16 off; s16 x2; s32 x4; } Ent;
typedef struct Hd { s16 x0, x2; s32 x4:16; s32 n:16; u32 x8, xc; Ent e[1]; } Hd;
s32* func_001e4e18(s32* p) {
    s32 n = *p++;
    s32 i, j, k;
    for (i = 0; i < n; i++) {
        u8* t = (u8*)*p++;
        Hd* h = (Hd*)(t + 16);
        s32 m = h->n;
        for (j = 0; j < m; j++) {
            Sub* s = (Sub*)((u8*)h + h->e[j].off); Px* px = (Px*)((u8*)s + s->off); for (k = 0; k < s->n; k++, px++) { s32 v = (s32)(px->r * 0.3f + px->g * 0.59f + px->b * 0.11f); px->r = v; px->g = v; px->b = v; }
        }
    }
    return p;
}
typedef union { s32 w; u8* p; s16 h[2]; u8 c; } U331;
void func_001e8180(u8* p, u8* base) {
    s32* A;
    s32* B;
    u8* node;
    u8* next;
    s32 na, nb, i, j, k;
    p += 0x110;
    A = (s32*)(p + *(s32*)(p + 8));
    B = (s32*)(p + *(s32*)(p + 12));
    node = p + 16;
    na = *A++;
    nb = *B++;
    if (*(s32*)(p + 16) == 0) return;
    for (;;) { ((U331*)node)->p = p + ((U331*)node)->w; for (i = 0; i < ((U331*)(node + 36))->h[1]; i++) { U331* e = (U331*)(node + 40 + i * 16); e[0].w = (s32)(base + e[0].w * 72); e[2].w = (s32)(p + e[2].w); e[3].w = (s32)(p + e[3].w); } next = ((U331*)node)->p; if (((U331*)next)->w == 0) { ((U331*)node)->w = 0; break; } node = next; }
    for (j = 0; j < na; j++) A[j] = (s32)(base + A[j] * 72);
    for (k = 0; k < nb; k++) B[k] = B[k] + (s32)p;
}
void func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_001e2ad8(const char*, const char*, s32, const char*);
extern char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ece0[], D_0036ecf0[];
typedef union { u16 h; void* p; u8 c; } U2_331;
typedef struct T331 { u16 a, b; void* p; } T331;
extern T331 D_00354248[];
static inline void rb331(const char* f, s32 l) { func_002fdfc8(D_0036e998, f, l); asm volatile("break"); }
#define ASSERTD331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); rb331(D_0036e9d0, l); }
#define ASSERT331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); func_002fdfc8(D_0036e998, D_0036e9d0, l); asm volatile("break"); }
u32* func_001e4028(u32* p, u8* bits) {
    s32 n = *p++;
    s32 i;
    u32 m = 0;
    for (i = 0; i < n; i++) {
        u32 v = *p++;
        s32 byte = i >> 3;
        s32 bit = i & 7;
        ASSERT331(!(v & 0xf), D_0036ec40, 1100);
        ASSERT331(byte < 16, D_0036ec58, 1101);
        ASSERTD331(byte >= 0, D_0036ec70, 1101);
        if (bit == 0) m = bits[byte];
        if ((u8)(m & 1)) {
            s32 id = *(s32*)v;
            T331* t;
            if (id >= 128) func_001e2ad8(D_0036ece0, D_0036e9d0, 1111, D_0036ecf0);
            t = &D_00354248[id];
            t->a = *(u16*)(v + 4);
            t->b = *(u16*)(v + 8);
            ((U2_331*)((u8*)t + 4))->p = (void*)(v + 12);
        }
        m >>= 1;
    }
    return p;
}
