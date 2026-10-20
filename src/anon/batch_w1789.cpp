#include "../common/types.h"

struct W1789Ent { s16 id; u8 f; u8 pad; u32 x; };
struct W1789Tbl { u32 a; s8 n; u8 pad[3]; W1789Ent e[1]; };
struct W1789Rec { u32 a; u16 id; };

extern "C" {
extern W1789Tbl* D_0035f12c;
W1789Rec* func_00273140();
void func_001a6510(s32);
void func_001a6548(s32);
s32 func_001a6598(s32);

void func_00273760(s32 idx, u8 on) {
    s32 id = func_00273140()->id;
    if (on) func_001a6510(id);
    else func_001a6548(id);
    u8 v = func_001a6598(id) != 0;
    id = D_0035f12c->e[idx].id;
    for (s32 i = 0; i < D_0035f12c->n; i++)
        if (D_0035f12c->e[i].id == id) D_0035f12c->e[i].f = v;
}
}
