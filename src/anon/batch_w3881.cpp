#include "../common/types.h"

extern "C" {

u8* func_002a9d68();
extern u8* D_0035f610;
u8* func_001a82b0(u8*);
s32 func_002764b0(u8);

// Walks every entry and checks that each one selected (not hidden, kind not 0 or 0x800, matching key
// when key >= 0) whose bit is set in the global flag set is also set in the save data's flag set.
s32 func_002ab620(s32 key)
{
    u8* e = 0;
    s32 i = 0;
    s32 r = 1;
    u8* save = func_002a9d68();
    u32* sb = (u32*)(save + 236);
    for (;;) {
        e = func_001a82b0(e);
        if (e == 0) break;
        if (e[4] == 0 && *(u16*)(e + 8) != 0 && *(u16*)(e + 8) != 0x800
            && (key < 0 || func_002764b0(e[5]) == key)) {
            u32* gb = (u32*)(D_0035f610 + 236);
            u32 m = 1 << (i & 31);
            if (gb[(u32)i >> 5] & m) {
                r = (sb[(u32)i >> 5] & m) != 0;
                if (!r) break;
            }
        }
        i++;
    }
    return r;
}

}
