#include "../common/types.h"

struct WHdr_w2370 { u8 pad[12]; s32 count; };
void func_001e4f40(u32);

// Relocates a loaded data block: patches the non-null offsets in its 32-byte
// entries to absolute addresses, then hands each listed offset to 001e4f40.
void wtarget_001dc098(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 base = a0;
    WHdr_w2370* h = (WHdr_w2370*)a0;
    u32* p = (u32*)(a0 + 16);
    s32 i;
    for (i = 0; i < h->count; i++) {
        base = a0;
        if (*p) *p += base;
        p += 8;
    }
    s32 n = *p++;
    for (i = 0; i < n; i++) {
        func_001e4f40(*p++ + base);
    }
}
