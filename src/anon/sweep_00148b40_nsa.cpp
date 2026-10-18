#include "../common/types.h"
typedef struct G48 { u32 flags; u32 x4; s8 c[4]; } G48;
extern G48 D_00457480;
extern s32 D_00457478;
void func_0011de88(s32, G48*, s16*, s32, s32);
void func_00148b40(s32 u, s32* p) {
    s16 buf[32];
    s32 i;
    s32 n;
    for (i = 0; i < 32; i++) buf[i] = i;
    D_00457480.flags |= 2;
    buf[31] = -1;
    D_00457480.c[2] = -128;
    D_00457480.c[1] = -128;
    D_00457480.c[0] = -128;
    D_00457480.c[3] = -1;
    n = D_00457478;
    func_0011de88(*p, &D_00457480, buf, n, 0);
}
