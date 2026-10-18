#include "../common/types.h"
typedef struct E6 { u8 pad[6]; u8 b; } E6;
typedef struct S18c { u8 pad[0x18c]; u16 h; } S18c;
E6* func_002924d0(s32, s32);
s32 func_00292520(s32, u32, u32);
void func_00292258(s32 a0, s32* out, s32 a2, s32 a3, S18c* s) {
    E6* p = func_002924d0(a0, a2);
    E6* q = func_002924d0(a0, a3);
    *out = s->h - p->b + q->b;
    func_00292520(a0, p->b, q->b);
}
