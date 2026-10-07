#include "../common/types.h"

extern "C" {
void func_003058a0(s32);
s32 func_002b9404(s32, s32, s32*, s32*);
s32 func_002b6708(s32, s32, s32, s32, s32);
struct Ent64 { s32 kind; u8 pad[60]; };
extern Ent64 D_01e22080[];

// Counts table entries of kind 11..14.
s32 func_002b6f78(void) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    for (i = 0; i < 512; i++) {
        switch (D_01e22080[i].kind) { case 11: case 12: case 13: case 14: n++; }
    }
    return n;
}

s32 func_002b97d8(s32 a, s32 b, s32 c, s32 d) {
    s32 r;
    s32 x, y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return -1;
    return func_002b6708(4, 28, r, c, d);
}
}
