#include "../common/types.h"
extern "C" {
void func_002eb6f8(u8*, s32, f32);
#define W2432_AI static inline __attribute__((always_inline))
W2432_AI bool w2432_c5(u32 f) { bool r = false; if (f & 4) goto y; if (f & 8) goto y; if (!(f & 0x10)) goto n; y: r = true; n: return r; }
// 002eb778: moved to src/anon/unit_002eaf38.cpp
}
