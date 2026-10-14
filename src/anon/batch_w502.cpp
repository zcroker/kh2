#include "../common/types.h"
extern "C" {
void func_0014a9a0(char* p, u32 n);

// Sets the flag byte at 0xf4, marks 0xf8/0xfc dirty and reapplies via func_0014a9a0.
void func_0014aa80(char* p, u32 n, u8 c) {
    *(u32*)(p + 252) = 1;
    *(u8*)(p + 244) = c;
    *(u32*)(p + 248) = 1;
    func_0014a9a0(p, n);
}
}
