#include "../common/types.h"

extern "C" {
struct Ent64 { s32 h[3]; u8 pad[52]; };
extern Ent64 D_01e22080[512];
void func_003058a0(s32);
}

// Count live entries of kind 29 (matching a/b) or kind 25 (matching c).
extern "C" {
s32 ctarget_002b79cc(s32 a, s32 b, s32 c) asm("_Z16ctarget_002b79ccjjjj");
}
s32 ctarget_002b79cc(s32 a, s32 b, s32 c)
{
    s32 i;
    s32 cnt = 0;
    func_003058a0(0);
    if (c == 0) {
        if (b < 0) {
            for (i = 0; i < 512; i++)
                if (D_01e22080[i].h[0] == 29 && D_01e22080[i].h[1] == a) cnt++;
        } else {
            for (i = 0; i < 512; i++)
                if (D_01e22080[i].h[0] == 29 && D_01e22080[i].h[1] == a && D_01e22080[i].h[2] == b) cnt++;
        }
    } else if (c < 0) {
        for (i = 0; i < 512; i++)
            if (D_01e22080[i].h[0] == 25) cnt++;
    } else {
        for (i = 0; i < 512; i++)
            if (D_01e22080[i].h[0] == 25 && D_01e22080[i].h[1] == c) cnt++;
    }
    return cnt;
}
