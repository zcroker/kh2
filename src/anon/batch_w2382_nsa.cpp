// batch w2382 (built with -fno-strict-aliasing)
#include "../common/types.h"

// ---- 0016c060
struct W2382Res { u32 f0; u32 f4; u32 data; };
struct W2382Dict { u8 pad[0x10]; void* h; };
extern s8 D_0036c1f0[8];
// Four-character tag read from a byte string (little endian).
static inline u32 W2382Tag(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
extern "C" {
W2382Res* func_00168b88(void*, s32, s32, s32);

// Reads entries 24 and 25 (tagged by the name at D_0036c1f0) from the dictionary at o+0x7a0.
// Returns 1 when both are present and non-zero. The handle goes through a pointer local so its
// null test gets the pointer branch heuristic (that sets the original's s-register order).
s32 func_0016c060(u8* o, u32* first, u32* second)
{
    W2382Dict* dict = (W2382Dict*)(o + 0x7a0);
    W2382Res* r;
    u32 d;
    *first = 0;
    *second = 0;
    void* h = dict->h;
    if (h && (r = func_00168b88(dict->h, 24, W2382Tag(D_0036c1f0), 0)) && (d = r->data)) {
        *first = d;
        if ((r = func_00168b88(dict->h, 25, W2382Tag(D_0036c1f0), 0)) && (d = r->data)) {
            *second = d;
            return 1;
        }
    }
    return 0;
}
}
