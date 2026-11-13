#include "../common/types.h"

struct C34e0 { u8 v:8; };
typedef struct E34e0 { u8 b0, b1, b2, b3; u8 pad[0xe]; u16 h12; } E34e0;
extern u8 D_0032e020[];

extern "C" {
E34e0* func_001a80c8(s32);

/* The mask goes through a variable so gcc keeps the test in SImode (no extra andi 0xff). */
// 001a34e0: moved to src/anon/unit_001a2a50.cpp
}
