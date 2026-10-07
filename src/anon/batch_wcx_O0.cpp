#include "../common/types.h"

extern "C" {

void func_003058a0(s32);
struct E104 { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[16]; s32 val; u8 pad4[64]; };
extern E104 D_01e2a080[];

// 002b8534: look up the value of the live slot with this id
s32 func_002b8534(s32 id)
{
    func_003058a0(0);
    E104* e = D_01e2a080;
    for (s32 i = 0; i < 8; i++, e++) {
        if (e->used && e->id == id) return e->val;
    }
    return 0;
}

}

extern "C" {

struct E104b { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[4]; s32 val; u8 pad4[76]; };
extern E104b D_01e2a080b[] asm("D_01e2a080");

// 002b85e4: same lookup as 002b8534, other field
s32 func_002b85e4(s32 id)
{
    func_003058a0(0);
    E104b* e = D_01e2a080b;
    for (s32 i = 0; i < 8; i++, e++) {
        if (e->used && e->id == id) return e->val;
    }
    return 0;
}

}

namespace w71_c0 {
extern "C" {
s32 func_002b9404(u32, u32, u32*, u16*);
s32 func_002b6708(s32, s32, s32, s32, u32);
s32 func_002b9728(u32 a, u32 b, s32 c, u32 d)
{
    s32 r;
    u32 x;
    u16 f;
    r = func_002b9404(a, b, &x, &f);
    if (r < 0) return -1;
    if (f & 1) c = 16383;
    return func_002b6708(4, 27, r, c, d);
}
}

}
