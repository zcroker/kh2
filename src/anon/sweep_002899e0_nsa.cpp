#include "../common/types.h"
extern "C" {
typedef struct S2899 S2899;
typedef struct M2899 M2899;
struct S2899 { u16 x; s16 pad2; s16 pad4; s16 m6; s16 m8; s16 pad[4]; u16 y; s16 p20; s16 h22; };
struct M2899 { u64 a; u64 b; u64 c; u64 d; };
s32 func_0028af78(S2899*, s32);
s32 func_00289d28(S2899*, u16*, u16*);
s32 func_00289b30(S2899*, u16*, u16*);
s32 func_0028a5a8(S2899*, M2899*);
s32 func_002899e0(S2899* a0, M2899* a1)
{
    u16 l[2];
    s32 r = 0;
    s16 v;
    u16 x = a0->x, y = a0->y;
    v = x + y;
    l[0] = x;
    l[1] = y;
    if (a1->d & a0->m6) {
        if (func_0028af78(a0, 1)) {
            if (v != 0 || (a1->b & a0->m6)) v = func_00289d28(a0, &l[0], &l[1]);
            goto done;
        }
    }
    if (a1->d & a0->m8) {
        if (func_0028af78(a0, 2)) {
            if (v < a0->h22 - 1 || (a1->b & a0->m8)) v = func_00289b30(a0, &l[0], &l[1]);
            goto done;
        }
    }
    r = func_0028a5a8(a0, a1);
done:
    if (r == 0) {
        if (v != (s16)a0->x + (s16)a0->y) {
            r = 1;
            a0->x = l[0];
            a0->y = l[1];
        }
    }
    return r;
}
}
