#include "../common/types.h"
extern "C" {
extern char D_004f3608[];
extern void* D_0034aaa0;
s32 func_0019eeb8(void*, void*);
char* func_0019f880(void*, void*);
char* func_00192048(s32);
s32 func_00192c40(char*, char*);
void func_0015aa98(void*, char*, s32, f32);
// Builds a message in the shared text buffer (optionally appending message 0x8add) and shows it.
void func_0015b1b0(void* a, void* b, u8 c) {
    s32 n;
    if (func_0019eeb8(b, a)) {
        n = func_00192c40(func_0019f880(a, b), D_004f3608);
    } else {
        n = func_00192c40(func_00192048(0x82b8), D_004f3608);
    }
    if (c) {
        n += func_00192c40(func_00192048(0x8add), D_004f3608 + n);
    }
    D_004f3608[n] = 0;
    func_0015aa98(D_0034aaa0, D_004f3608, 16, 0.0f);
}
}
