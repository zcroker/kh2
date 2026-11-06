#include "../common/types.h"

/* Two 64-bit words of 16-bit fields at +0xd0 / +0xe0: swap field 0, field 1 or the whole word. */
typedef struct { u64 a:16; u64 b:16; u64 c:16; u64 d:16; } W3841Bf;
typedef struct { u8 pad[0xd0]; W3841Bf x; u8 p2[8]; W3841Bf y; } W3841Pair;

void func_0014b518(W3841Pair* p, u32 m) {
    W3841Bf x, y; u16 a;
    switch (m) {
    case 1: x = p->x; y = p->y; a = (u64)x.a; x.a = (u16)(u64)y.a; y.a = a; p->x = x; p->y = y; break;
    case 2: x = p->x; y = p->y; a = (u64)x.b; x.b = (u16)(u64)y.b; y.b = a; p->x = x; p->y = y; break;
    case 3: { W3841Bf t = p->x; p->x = p->y; p->y = t; break; }
    }
}
