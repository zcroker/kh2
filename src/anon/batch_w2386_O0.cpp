#include "../common/types.h"

extern "C" {
u32 func_002fdfc8(const char*, ...);
s32 func_002b803c(s32 a);
extern s32 D_01e22080[512][16];  // sound play slots, 64 bytes each

// 002b807c: with a == 0, print every active sound play slot; then forward a to func_002b803c.
void func_002b807c(s32 a)
{
    if (a) {
        // nothing extra here: the original jumps straight to the final call
    } else {
        func_002fdfc8("--- sound play list ---\n");
        for (s32 i = 0; i < 512; i++) {
            if (D_01e22080[i][0]) {
                func_002fdfc8("%03d com%2d bank%2d no%6d id%6d %x %x\n", i, D_01e22080[i][0], D_01e22080[i][1],
                              D_01e22080[i][2], D_01e22080[i][3], D_01e22080[i][4], D_01e22080[i][5]);
            }
        }
    }
    func_002b803c(a);
}
}
