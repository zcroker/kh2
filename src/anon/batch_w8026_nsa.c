#include "../common/types.h"

/* 00147140 */
struct E30 { u8 pad[0x30]; };
struct H147 { u32 x0; struct E30* tab; };
struct O147 { u8 pad[0xd0]; u8 m[0x48]; u16 a; u16 b; };
s32 func_00144d90(void*, void*);
u16 func_00147050(struct H147*, u16, struct O147*, u16, s32*);
void func_00147140(struct H147* h, struct O147* o) {
    s32 n; u16 r = o->a;
    if (!func_00144d90((u8*)&h->tab[r] + 0x10, o->m)) {
        n = 0;
        r = func_00147050(h, 0, o, 0, &n);
    } else {
        n = o->b;
        r = func_00147050(h, o->a, o, o->b, &n);
    }
    o->a = r;
    o->b = n;
}
