#include "../common/types.h"
extern "C" {

/* 0011f1a8: unpack high nibbles in place (u64 at a time, then bytes) */
struct O5_0011f1a8;
struct O5vt_0011f1a8 { u8 pad[0x30]; s32 (*fn)(O5_0011f1a8*); };
struct O5_0011f1a8 { O5vt_0011f1a8* vt; };
void func_0011f1a8(O5_0011f1a8* o, s8* p) {
    s32 n = o->vt->fn(o);
    s32 r = n & 7;
    s32 i;
    u64 m = 0xf0f0f0f0f0f0f0f0ULL;
    n >>= 3;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) { *q = (*q & m) >> 4; q++; }
    p = (s8*)q;
    for (i = 0; i < r; i++) { *p = (*p & 0xf0) >> 4; p++; }
}

}
