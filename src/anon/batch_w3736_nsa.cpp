// w3736 batch (-fno-strict-aliasing).
#include "../common/types.h"
struct G { f32 x, y, z, pad0; f32 ox, ry, oz, pad1; f32 sx, pad2, sz, pad3; s32 nx, ny, ix, iy; };
struct V4 { f32 x, y, z, w; };
extern u32 D_003638d0;
static inline f32 frand(f32 max) { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f * max; }
extern "C" {
// Grid point iterator with optional random jitter. Partial asm (step 4): FP register pins (iy f7, sz f4,
// dz f2, y f3) reproduce the original local-alloc numbering, and an empty asm ties the y store after
// the w store (no code emitted).
// 001c28f8: moved to src/anon/unit_001c0638.cpp
s32 func_001c28f8(G* g, V4* o, u8 jit);

}
