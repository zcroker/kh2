#include "../common/types.h"

extern "C" {
void func_003058a0(u32);
struct E64 { u32 used; u8 pad[60]; };
extern E64 D_01e22080[512];

// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void) {
    func_003058a0(0);
    for (s32 i = 0; i < 512; i++) {
        if (D_01e22080[i].used == 0) return i;
    }
    return -1;
}
}
