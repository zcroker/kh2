#include "../common/types.h"

extern "C" {
struct Ent64 { s32 hdr[2]; u8 pad[56]; };
extern Ent64 D_01e22080[512];
s32 func_002b9404(s32, s32, s32*, s32*);
void func_003058a0(s32);

// Count type-25 entries whose id matches the looked-up handle.
s32 func_002b986c(s32 a, s32 b) {
    s32 i;
    s32 cnt = 0;
    s32 r;
    s32 x;
    s32 y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return 0;
    func_003058a0(0);
    for (i = 0; i < 512; i++) {
        if (D_01e22080[i].hdr[0] == 25 && D_01e22080[i].hdr[1] == r) cnt++;
    }
    return cnt;
}
}
