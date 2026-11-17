#include "../common/types.h"
typedef unsigned int W1820u128 __attribute__((mode(TI)));

// Object with a 16-qword GS register packet at +0x20 (two GIF tags + A+D pairs).
struct W1820Gs {
    u8 pad[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 b0, b1, b2, b3;
    u8 pad2[12];
    u64 g[22];
    u64 g2[2];
};

// DMA packet builder: 3 words, write cursor at +8.
struct W1820Pkt {
    u32 a, b;
    W1820u128* p;
    W1820Pkt() { p = 0; b = 0; a = 0; }
};

extern "C" {
void func_0013eb00(W1820Gs*);
void func_001b7e68(W1820Pkt*, s32);
void func_001b80d8(W1820Pkt*);
void func_001b7f30(W1820Pkt*);

void func_0013e940(W1820Gs* p);  // 0x0013e940: definition moved into src/anon/unit_0013dfb8.cpp

void func_0014b698(W1820Gs* p);  // 0x0014b698: definition moved into src/anon/unit_0014b638.cpp
}
