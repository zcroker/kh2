#include "../common/types.h"

extern "C" {
u8* func_001bfd60(u8*, s32);
void func_001ad990(u8*, f32, f32, f32);

struct Col1945 { u8 r, g, b, a; };

// Allocates an entry from the list at +0x8e0, stores its packed RGBA colour and sets it up.
void func_001945a0(u8* a, f32 f, s32 b, u32 c) {
    u8* r = func_001bfd60(a + 2272, b);
    Col1945* q = (Col1945*)(r + 4);
    q->r = c; q->g = c >> 8; q->b = c >> 16; q->a = c >> 24;
    func_001ad990(r + 8, 0.0f, 1.0f, f);
}
}
