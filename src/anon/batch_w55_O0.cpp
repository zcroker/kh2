#include "../common/types.h"
// -O0 frame-pointer helpers.
extern "C" {
s32 func_002b6708(s32, s32, s32, s32);
void func_002b78ec(u8*);
s32 func_002b83ec(s32 a, s32 b) {
    return func_002b6708(3, 38, a, b);
}
void func_002b8a70(u8* p) {
    func_002b78ec(p + 0x8000);
    *(u32*)(p + 0x48000) = 0;
}
}
