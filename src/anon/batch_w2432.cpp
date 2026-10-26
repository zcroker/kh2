#include "../common/types.h"
extern "C" {
void func_002eb6f8(u8*, s32, f32);
#define W2432_AI static inline __attribute__((always_inline))
W2432_AI bool w2432_c5(u32 f) { bool r = false; if (f & 4) goto y; if (f & 8) goto y; if (!(f & 0x10)) goto n; y: r = true; n: return r; }
// 002eb778: the f32 argument passes through in $f12 to func_002eb6f8 (callee takes p, id, f32).
void func_002eb778(u8* p, s32 a1, bool a2, f32 x)
{
    if (!a2) {
        u32 f = *(u32*)(p + 0x160);
        if (!w2432_c5(f) && !(f & 0x10)) return;
        if (*(s32*)(p + 0x154) == a1) return;
    }
    func_002eb6f8(p, a1, x);
}
}
