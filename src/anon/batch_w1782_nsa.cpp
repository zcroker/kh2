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

void func_00106d40(P106d40* o, f32 p0, f32 p1, f32 p2, f32 p3, f32 p4, f32 a, f32 b, f32 c, f32 p8, f32 p9, f32 p10) {
    o->f54 = c * 4000000.0f * (b - a) / (4000000.0f - c);
    o->f60 = (-b * c + a * 4000000.0f) / (4000000.0f - c);
    o->f4c = p1;
    o->f50 = p2;
    o->f58 = p3;
    o->f5c = p4;
    o->f64 = a;
    o->f68 = b;
    o->f6c = c;
    o->f70 = p8;
    o->f74 = p9;
    o->f78 = p10;
    func_00106fe8(o, p0);
    func_00106c08(o);
}

s32 func_00196430(u32 x) {
    S196430 s;
    s32 r = 0;
    if (D_0032da20[x >> 5] & (1 << (x & 0x1f))) {
        s = func_00196328(x);
        r = func_00196768(s.a, s.b) == 0 ? 1 : 2;
    }
    return r;
}
}
