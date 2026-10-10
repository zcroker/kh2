#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

/* func_001e6688 */
typedef struct { s32 a, b, c, d, e, f, g, h; } S8_01da8cd0;
typedef struct { s32 x, y; } S2_00354690;
extern S8_01da8cd0 D_01da8cd0;
extern S2_00354690 D_00354690;
void func_001e6648(void);
void func_001e2b68(void);
void func_001e6688(void) {
    D_01da8cd0.b = 0; D_01da8cd0.f = 0; D_01da8cd0.e = 0; D_01da8cd0.c = 0;
    D_01da8cd0.g = 0; D_01da8cd0.a = 0; D_01da8cd0.d = 0; D_01da8cd0.h = 0;
    D_00354690.y = -1; D_00354690.x = 0;
    func_001e6648();
    func_001e2b68();
    asm volatile(""); /* keeps the call a jal (no sibcall), as the original */
}

/* func_001e6ed8 */
void f3f98(void*, void*) asm("_Z16u_call4_002f3f98jjjj");
void f3d08(void*, void*, void*) asm("_Z16wtarget_002f3d08jjjj");
void func_002f3e20(void*, void*);
extern u128 D_01d9e730, D_01d9e740, D_01d9e750, D_01d9e760;
extern u128 D_01d9e770[4];
extern u128 D_01d9e7b0[4];
extern u128 D_01d9e7f0, D_01d9e800, D_01d9e810, D_01d9e820;
typedef union { f32 f; u128 q; } FQ; extern FQ D_01d9e830;
extern u128 D_01d9e8c0, D_01d9e8d0, D_01d9e8e0, D_01d9e8f0;
extern u8 D_01d9ea00[];
void func_001e6ed8(u128* a, u128* b, u128* c, u128* d) {
    f3f98(D_01d9e770, &D_01d9e730);
    D_01d9e730 = a[0];
    D_01d9e740 = a[1];
    D_01d9e750 = a[2];
    D_01d9e760 = a[3];
    D_01d9e8c0 = b[0];
    D_01d9e8d0 = b[1];
    D_01d9e8e0 = b[2];
    D_01d9e8f0 = b[3];
    D_01d9e810 = D_01d9e7f0;
    D_01d9e820 = D_01d9e800;
    D_01d9e7f0 = *c;
    D_01d9e800 = *d;
    D_01d9e830.f = 53.0f;
    func_002f3e20(D_01d9e7b0, &D_01d9e730);
    f3d08(D_01d9ea00, &D_01d9e8c0, &D_01d9e730);
}

/* partMng.c asserts (file name string D_0036e9d0) */
void func_002fdfc8(const char*, ...);
extern char D_0036e978[], D_0036e998[], D_0036e9d0[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);        /* "RyjAssertion failed: %s\n" */
    func_002fdfc8(D_0036e998, f, l);     /* "   File %s, Line %u\n" */
    asm volatile("break");
}
static inline void ryjAssert5(const char* f1, const char* e, const char* f2, const char* f, s32 l) {
    func_002fdfc8(f1, e);
    func_002fdfc8(f2, f, l);
    asm volatile("break");
}
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
#define ASSERT5(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)
void* func_001e3650(void*);
s32* func_001e3660(void*, s32) asm("_Z13func_001e3660ji");

/* func_001e5458 */
extern char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ed60[];
void func_001e5220(u32, s32);
void func_001e5458(u32* p, u8* bits, s16 k) {
    s32 n, i;
    u32 m = 0;
    ASSERT(p != 0, D_0036ed60, 1565);
    p = (u32*)func_001e3660(func_001e3650(p), 1);
    n = *p++;
    for (i = 0; i < n; i++) {
        u32 v = *p++;
        s32 by = i >> 3;
        s32 bi = i & 7;
        ASSERT5(!(v & 0xf), D_0036ec40, 1578);
        ASSERT5(by < 16, D_0036ec58, 1579);
        ASSERT5(by >= 0, D_0036ec70, 1579);
        if (bi == 0) m = bits[by];
        if ((u8)(m & 1)) func_001e5220(v, k);
        m >>= 1;
    }
}

/* func_001e5718 */
void func_001e52b8(u32, s32);
void func_001e5718(u32* p, u8* bits, s16 k) {
    s32 n, i;
    u32 m = 0;
    if (p) {
        p = (u32*)func_001e3660(func_001e3650(p), 1);
        n = *p;
        asm("" : "+r"(p)); /* keeps the count pointer and the loop pointer apart */
        p++;
        for (i = 0; i < n; i++) {
            u32 v = *p++;
            s32 by = i >> 3;
            s32 bi = i & 7;
            ASSERT5(!(v & 0xf), D_0036ec40, 1638);
            ASSERT5(by < 16, D_0036ec58, 1639);
            ASSERT5(by >= 0, D_0036ec70, 1639);
            if (bi == 0) m = bits[by];
            if ((u8)(m & 1)) func_001e52b8(v, k);
            m >>= 1;
        }
    }
}

/* func_001e5898 */
void func_001e5898(u32* p) {
    s32 n, i;
    if (p) {
        p = (u32*)func_001e3660(func_001e3650(p), 1);
        n = *p;
        asm("" : "+r"(p)); /* keeps the count pointer and the loop pointer apart */
        p++;
        for (i = 0; i < n; i++) {
            u32 v = *p++;
            ASSERT(!(v & 0xf), D_0036ec40, 1669);
            func_001e52b8(v, 0x3d00);
        }
    }
}
