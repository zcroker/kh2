#include "../common/types.h"

struct Q1615 { u8 v[16] __attribute__((aligned(16))); Q1615() {} ~Q1615() {} };
struct B1615 { u64 a, b, c, d; Q1615 q[2]; f32 f; B1615() {} };

extern "C" {
struct P1615 { u64 a, b, c, d; };
struct G1615 {
    u8 p0[28];
    s16 y[2];
    s16 x[2];
    s16 ny;
    s16 nx;
    u8 p28[52 - 40];
    u32 p0b : 10;
    u32 moved : 1;
    u32 sel : 1;
    u32 p1b : 2;
    u32 mode : 4;
};
union GU1615 { G1615* p; s16 h; };
extern GU1615 D_0035f638;
void* func_00167f18(s32);
void func_00323af8(B1615*, void*);
s32 func_00288040(void);
P1615* func_00288008(void);
u32* func_002b23e0(s32);

s32 func_002b0950(void);  // 0x002b0950: definition moved into src/anon/unit_002b0950.cpp
}
