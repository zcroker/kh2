#include "../common/types.h"

// Element mode byte at +0x2c and its derived mask at +0x2d.
struct W2361Mode { u8 pad[44]; u8 mode; u8 mask; };

// 64-byte table entries after an 8-byte header (count at +4).
struct W2361Ent { u8 d[64]; };
struct W2361Tab { u32 x; s32 n; W2361Ent e[1]; };

extern "C" {
extern W2361Tab* D_01d5ba98;

// Mode 3 is stored as 4; the mask clears bit 0 and the mode's bit. The u8 ?: keeps the branch.
void func_0018e0d8(W2361Mode* p, s32 mode);  // 0x0018e0d8: definition moved into src/anon/unit_0018d050.cpp

// Iterator: first entry for 0, else the next entry, 0 past the end.
W2361Ent* func_001d6cc8(W2361Ent* e);  // 0x001d6cc8: definition moved into src/anon/unit_001d68e0.cpp

}
