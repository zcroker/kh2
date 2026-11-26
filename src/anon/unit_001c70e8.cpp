// Linked unit 0x001c70e8-0x001c7148.
#include "../common/types.h"

// 001c70e8 (was src/anon/batch_w3719_nosched.cpp)
namespace n001c70e8 {
struct Vq { f32 x, y, z, w; } __attribute__((aligned(16)));
struct G { Vq a, b, c, res; u8 pad40[0x2c]; f32 v; u64 flags; };
extern G D_01d498d0 asm("D_01d498d0");
extern u32 D_w asm("D_01d49940");
/*TARGET 001c70e8*/
void func_001c70e8(void) asm("func_001c70e8");
// D_w is the low word of D_01d498d0.flags (0x1d498d0 + 0x70), declared apart so gcc does not merge the two
// updates. Built with -fno-strict-aliasing: retail keeps the float stores behind the D_w and flags accesses.
void func_001c70e8(void) {
    u32 w = D_w;
    f32 k = 55.0f;
    Vq* c = &D_01d498d0.c;
    G* g = &D_01d498d0;
    D_w = (w & ~0x78) | 0x30;
    c->z = k;
    u64 f = g->flags;
    g->v = 60.0f;
    c->x = k;
    g->flags = f | 1;
    c->y = k;
    c->w = 0.0f;
}
}  // namespace n001c70e8

