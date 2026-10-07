#include "../common/types.h"

extern "C" {

u32 func_002b6708(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_002b6708_5(u32, u32, u32, u32, u32) asm("func_002b6708");

// Forward the eight caller arguments to the dispatcher with fixed ids 9/43.
u32 func_002b7db4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    return func_002b6708(9, 43, a, b, c, d, e, f, g, h);
}

struct Sub2b8 { u8 p[36]; u32 x; u32 y; };
u32 wtarget_002b89e4(u32 a, u32 b, u32 c) asm("_Z16wtarget_002b89e4jjjj");
// Record two values in the sub-block at +0x48000, then dispatch (4, 28).
u32 wtarget_002b89e4(u32 a, u32 b, u32 c) {
    ((Sub2b8*)(a + 0x48000))->x = b;
    ((Sub2b8*)(a + 0x48000))->y = c;
    return func_002b6708_5(4, 28, a + 0x8000, b, c);
}

}
