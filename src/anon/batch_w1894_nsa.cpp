#include "../common/types.h"

struct Pos2ee0 { s32 x, y; };
struct Col2ee0 { u8 r, g, b, a; };

static inline __attribute__((always_inline)) void Mul2ee0(Col2ee0& d, const Col2ee0& s) {
    d.r = d.r * s.r >> 7;
    d.g = d.g * s.g >> 7;
    d.b = d.b * s.b >> 7;
    d.a = d.a * s.a >> 7;
}

struct Node2ee0 {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void drawSelf(Pos2ee0, Col2ee0, s32);
    virtual void draw(Pos2ee0, Col2ee0);
    u32 flags; Node2ee0* child; u8 pad[4]; s32 x, y; Col2ee0 col; u8 pad2[4]; Node2ee0* next;
};

extern "C" {
/* Needs -fno-strict-aliasing for the colour byte stores and flag test order. */
void func_002ee0b0(Node2ee0* n, Pos2ee0 pos, Col2ee0 col);  // 0x002ee0b0: definition moved into src/anon/unit_002ecdb0.cpp
}
