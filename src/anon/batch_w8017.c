#include "../common/types.h"

typedef struct T8 { u8 pad[0x2c]; s32 w2c; } T8;
f32 f_powf(f32, f32);
void _Z16wtarget_001d1b60jjjj(T8*, s32);

void func_001d4f40(T8* a0, s32 a1, s32 a2) {
    a1 = (s32)(a1 * f_powf(0.5f, a2));
    if (a1 == 0) a1 = 1;
    _Z16wtarget_001d1b60jjjj(a0, a0->w2c + a1);
}
