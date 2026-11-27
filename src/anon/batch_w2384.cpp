#include "../common/types.h"

extern "C" {

s32 func_00120800(void*);

// Size of one packed table: header count at +0x1c, 32-byte entries from +0x34,
// each pointing at a list whose negative entries take two slots.
static inline __attribute__((always_inline)) s32 tableSize(u8* p) {
    s32 n = *(s32*)(p + 0x1c);
    s32 c = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        s32* q = (s32*)(p + *(s32*)(p + 0x34 + i * 32));
        s32 m = *q;
        c++;
        if (m > 0) {
            s32 k = c;
            s32* e = q + 1;
            s32 j = m;
            do {
                if (*e < 0) k += 2; else k += 1;
                e++;
            } while (--j);
            c = k;
        }
        c += 2;
    }
    return c * 16 + ((n * 4 + 15) & ~15);
}

// Total size of the object's main table plus its optional second table.
s32 kn__ModelSKL__getDMATagBufferSize(void* a0);  // 0x001208f8: definition moved into src/anon/unit_00120520.cpp

struct PadState { s32 a; s32 b; s32 c; u32 f; };
void func_00136b78(s32, s32);
s32 func_002b7148(s32);
void func_002ba2b0(s32, s32);
s32 func_002bd250();
extern PadState D_00347d30[];
extern s32 D_00347d44;
extern s8 D_00347d54;

// Push the two requested pad states to the driver when they changed.
// 00137058: moved to src/harata/libdk/bgm.cpp

}
