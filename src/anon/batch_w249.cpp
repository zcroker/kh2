#include "../common/types.h"
extern "C" {
void func_00190128(u32*);
void* func_00111e38(s32);
s32 func_0010f6b8(void*, f32);  // count_reached_threshold
u32 func_00190140(u32*);
void func_00190878(u32*, void*, s32);
void func_0010cbc8(u32, s32, void*, s32);
static inline __attribute__((always_inline)) u8 valid(u32* t) {
    u8 ok = 0;
    if (func_00190140(t)) ok = *t != 0;
    return ok;
}
u32 func_00119d70(u32* a0, u32 a1, u32* a2, u32* a3, u8 t0) {
    if (t0) {
        *a3 = 0;
        func_00190128(a2);
        void* p = func_00111e38(0);
        if (func_0010f6b8(p, 0.25f)) {  // count_reached_threshold
            if (!valid(a2)) func_00190878(a2, p, 0);
        }
        if (valid(a2)) goto one;
        return 0;
    } else {
        func_0010cbc8(a0[1], 1, func_00111e38(0), 0);
        goto one;
    }
one:
    return 1;
}
struct S24 { u32 w[6]; };
struct P2 { u32 x, y; };
void* func_00192868(void*, void*, S24*, P2*);
void func_00192990(void* a0, void* a1, S24 c, P2* a3) {
    P2 l;
    l.x = 0; l.y = 0;
    a3->x = 0; a3->y = 0;
    while (a0) {
        a0 = func_00192868(a0, a1, &c, &l);
        a3->x = l.x < a3->x ? a3->x : l.x;
        a3->y = l.y < a3->y ? a3->y : l.y;
    }
    a3->x = (a3->x + 1) & ~1;
    a3->y = (a3->y + 1) & ~1;
}
struct Ent292 { s32 a; s32 b; s32 c; s32 d; };
union G292p { Ent292* p; s32* q; void* v; s32 i; u8 c; };
extern G292p D_0035f4e4;
extern G292p D_0035f4dc;
extern G292p D_0035f4d4;
extern G292p D_0035f4c0;
extern G292p D_0035f4c8;
extern u8 D_0035f4e2;
void func_002ff3fc(void*);  // strlen
void func_00168410(void*, s32, s32, u16, void*, void*);
void func_00292e60(void);
s32 func_00292fe8(void) {
    func_002ff3fc(D_0035f4e4.v);  // strlen
    s32 v = *D_0035f4dc.q;
    s32 hi = v >> 16;
    s32 lo = v & 0xffff;
    D_0035f4d4.p[hi].a = lo;
    D_0035f4d4.p[hi].b = 2;
    D_0035f4d4.p[hi].d = D_0035f4c8.i + hi * D_0035f4c0.i;
    D_0035f4d4.p[hi].c = 0;
    func_00168410(D_0035f4e4.v, D_0035f4d4.p[hi].d, lo * D_0035f4c0.i / 2048, D_0035f4c0.i / 2048, (void*)func_00292e60, &D_0035f4d4.p[hi]);
    D_0035f4e2 = 1;
    return 0;
}
}
