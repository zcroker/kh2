#include "../common/types.h"
struct NoTail { ~NoTail() {} };
extern "C" {
extern f32 D_01d498c0;
extern f32 D_01d498c4;
extern u8 D_01d498d0;
void func_0031b9e0(u8*);
/* static initializer (initialize, priority) */
void wtarget_001c7ab8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c7ab8jjjj");
void wtarget_001c7ab8(u32 a, u32 b, u32, u32) {
    NoTail nt;
    if (b == 0xffff) { if (a == 1) D_01d498c0 = 0.52359873f; }
    if (b == 0xffff) { if (a == 1) D_01d498c4 = 0.5934119f; }
    if (b == 0xffff) { if (a == 1) func_0031b9e0(&D_01d498d0); }
}
}
