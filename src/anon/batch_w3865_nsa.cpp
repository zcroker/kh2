#include "../common/types.h"
// Built with -fno-strict-aliasing.
extern "C" {
typedef struct V2cdfb0 { f32 x, y, z, w; } __attribute__((aligned(16))) V2cdfb0;
typedef struct Path2cdfb0 { u8 pad0[8]; s32 count; u8 pad1[4]; u8 loop; u8 pad1b[7]; f32 pos; u8 pad2[132 - 28]; u8 forward; } Path2cdfb0;
V2cdfb0* func_002cb890(Path2cdfb0*, s32);
f32 func_002cdb60(Path2cdfb0*, f32*, V2cdfb0*, V2cdfb0*, V2cdfb0*, f32, f32);
f32 func_002cdcd8(Path2cdfb0*, s32*, f32*, V2cdfb0*, f32);
/* Nearest point on a looping path: like func_002cdcd8 but indices wrap. Searches the
   current segment and the next one in the travel direction, keeps the closer one.
   Returns the distance, or -1 when it is not below maxDist. */
f32 func_002cdfb0(Path2cdfb0* p, s32* idx, f32* t, V2cdfb0* pos, f32 maxDist)
{
    f32 lo, hi, best;
    s32 firstIdx, nextIdx;
    f32 nextT, lo2, hi2;
    V2cdfb0* a;
    V2cdfb0* b;
    V2cdfb0* c;
    V2cdfb0* e;
    if (!p->loop) return func_002cdcd8(p, idx, t, pos, maxDist);
    *idx = (s32)p->pos;
    *t = p->pos - (f32)*idx;
    if (p->forward && 0.9999f < *t) {
        *idx = (*idx + 1) % p->count;
        *t = 0.0f;
    } else if (!p->forward && *t < 0.0001f) {
        *idx = (*idx + p->count - 1) % p->count;
        *t = 1.0f;
    }
    if (p->forward) {
        lo = *t;
        hi = 1.0f;
    } else {
        hi = *t;
        lo = 0.0f;
    }
    a = func_002cb890(p, *idx);
    b = func_002cb890(p, (*idx + 1) % p->count);
    lo = func_002cdb60(p, t, pos, a, b, lo, hi);  /* lo/hi reused: first distance and its t */
    firstIdx = *idx;
    hi = *t;
    *t = 0.0f;
    lo2 = 0.0f;
    hi2 = 1.0f;
    if (p->forward) *idx = (*idx + 1) % p->count;
    else *idx = (*idx + p->count - 1) % p->count;
    c = func_002cb890(p, *idx);
    e = func_002cb890(p, (*idx + 1) % p->count);
    best = func_002cdb60(p, t, pos, c, e, lo2, hi2);
    nextIdx = *idx;
    nextT = *t;
    if (lo < best) {
        best = lo;
        *idx = firstIdx;
        *t = hi;
    } else {
        *idx = nextIdx;
        *t = nextT;
    }
    if (best < maxDist) return best;
    return -1.0f;
}
}
