// Linked unit 0x001ff0e0-0x001ff110: ring init (was part of the whole-asm blob at 0x1fe8d8).
#include "../common/types.h"
namespace n001ff080 {
struct E2 { u8 n; u8 cur; u16 f2; u16 f4; u16 f6; };
struct A2 { u8 p[12]; s32* fc; };
void func_001ff0e0(u8* a, A2* b) asm("func_001ff0e0");
void func_001ff0e0(u8* a, A2* b)
{
    E2* e = (E2*)(a + *b->fc + 160);
    e->n = 31;
    e->f2 = 0;
    e->f4 = 0;
    e->f6 = 0;
    e->cur = 0;
}
}  // namespace n001ff080
