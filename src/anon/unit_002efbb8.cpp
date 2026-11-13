#include "../common/types.h"

// 0x2efbb8-0x2efcc0: the "COM" save header (magic, region code, version, flags). Linked unit.

s32 REGION_Get(void) asm("_ZN6REGION3GetEv");

struct SaveHeader2efbb8 {
    u32 magic;        // "COM"
    u16 region;
    u16 version;
    u8 pad[8];
    u32 flags;
};

extern "C" {

u16 func_002efbb8(void) {
    u16 r = 0x5355;
    switch (REGION_Get()) {
    case 2: break;
    case 1: case 8: r = 0x504a; break;
    default: r = 0x5545; break;
    }
    return r;
}

s32 func_002efc10(SaveHeader2efbb8* h) {
    s32 r = 0;
    if (h->magic == 0x004d4f43 && h->region == func_002efbb8())
        r = h->version == 1;
    return r;
}

s32 func_002efc70(SaveHeader2efbb8* h) {
    s32 r = 0;
    if (func_002efc10(h))
        r = (h->flags & 3) == 3;
    return r;
}

}
