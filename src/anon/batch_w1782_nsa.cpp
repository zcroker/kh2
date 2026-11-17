#include "../common/types.h"
// batch w1782 functions that need -fno-strict-aliasing

struct P106d40 { u8 pad[0x4c]; f32 f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78; };
struct S196430 {
    u8 a, b, c;
    u16 d, e, f;
    S196430() { u16 m = 0xffff; a = m; b = m; c = m; d = m; e = m; f = m; }
};

extern "C" {
void func_00106fe8(P106d40*, f32);
void func_00106c08(P106d40*);
S196430 func_00196328(u32);
s32 func_00196768(u8, u8);
extern u32 D_0032da20[];

// 00106d40: moved to src/naka/libkn/camera.cpp

s32 func_00196430(u32 x);  // 0x00196430: definition moved into src/anon/unit_00195d00.cpp
}
