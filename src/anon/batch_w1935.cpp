#include "../common/types.h"
extern "C" {
typedef struct R3_w { u8 pad[4]; u16 id; u8 pad2[0x1e]; } R3_w;
typedef struct E5_w { u16 id; u8 pad[6]; } E5_w;
typedef struct R5_w { u8 pad[5]; s8 n; u8 pad2[2]; s32 off; } R5_w;
typedef struct T_w { u8 pad[8]; s32 n; u8 pad2[4]; } T_w;
T_w* func_00294000(s32);
s32 func_00294368(R3_w*);
s32 func_00294480(R5_w*);
extern u32* D_0035f578;
void func_00294020(u32* bits)
{
    if (bits == 0) bits = D_0035f578;
    T_w* t = func_00294000(3);
    R3_w* r3 = (R3_w*)(t + 1);
    u32* p = bits;
    for (s32 k = 15; k >= 0; k--) *p++ = 0;
    s32 i;
    u16 id;
    for (i = 0; i < t->n; i++) {
        if (func_00294368(&r3[i])) {
            id = r3[i].id;
            u32* w = bits + (id >> 5);
            *w |= 1 << (id & 0x1f);
        }
    }
    T_w* t5 = func_00294000(5);
    R5_w* r5 = (R5_w*)(t5 + 1);
    for (i = 0; i < t5->n; i++) {
        if (func_00294480(&r5[i])) {
            E5_w* e = (E5_w*)((u8*)t5 + r5[i].off);
            for (s32 j = 0; j < r5[i].n; j++) {
                id = e[j].id;
                u32* w = bits;
                w += id >> 5;
                *w |= 1 << (id & 0x1f);
            }
        }
    }
}
}
