#include "../common/types.h"
// batch w1760 functions that need -fno-strict-aliasing

inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
extern u8* D_01c61b04;
void func_002223e0(void*);

struct W1760Q6 {
    u16 x, y, z;
    W1760Q6(int v) : x(v), y(v), z(v) {}
};
struct W1760C3 {
    u8 r, g, b, a;
    W1760Q6 q;
    W1760C3(int v) : r(v), g(v), b(v), q(v) {}
};

W1760C3* func_00196328(W1760C3* p, s32 i);  // 0x00196328: definition moved into src/anon/unit_00195d00.cpp

struct W1760S2 { u8 pad[0x6c]; s32 a; u64 b, c, d, e; };
struct W1760S3 { u8 pad[0xc]; s32 a; u8 p2[0x24 - 0x10]; s32 b; u8 p3[4]; s32 c; };

void func_001f4e18(u8* self, u8* t);  // 0x001f4e18: definition moved into src/anon/unit_001f45f8.cpp
}
