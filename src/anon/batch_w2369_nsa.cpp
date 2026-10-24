#include "../common/types.h"

struct ListEnt12 { u32 a; u32 b; f32 c; };

extern "C" {
extern ListEnt12 D_01d49658[30];
extern s32 D_00351600;

// Insert (a, 0, f) at idx into a 30-entry list, shifting later entries up; count capped at 30.
void func_001c4200(u32 a, s32 idx, f32 f) {
    for (s32 i = D_00351600 - 2; i >= idx; i--) D_01d49658[i + 1] = D_01d49658[i];
    ListEnt12* e = &D_01d49658[idx];
    e->a = a;
    (&D_01d49658[0].b)[idx * 3] = 0;
    e->c = f;
    s32 n = D_00351600 + 1;
    D_00351600 = (n < 31) ? n : 30;
}
}
