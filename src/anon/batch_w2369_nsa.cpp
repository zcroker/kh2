#include "../common/types.h"

struct ListEnt12 { u32 a; u32 b; f32 c; };

extern "C" {
extern ListEnt12 D_01d49658[30];
extern s32 D_00351600;

// Insert (a, 0, f) at idx into a 30-entry list, shifting later entries up; count capped at 30.
void func_001c4200(u32 a, s32 idx, f32 f);  // 0x001c4200: definition moved into src/anon/unit_001c4120.cpp
}
