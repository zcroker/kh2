#include "../common/types.h"
struct W1530_V4 {
    f32 x, y, z, w;
    W1530_V4() {}
    W1530_V4& operator=(const W1530_V4& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct W1530_H;
struct W1530_HC { virtual void f0(); virtual void f1(); virtual void f2(W1530_H*, W1530_V4*); };
struct W1530_H { u8 pad[0xc]; W1530_HC* xc; u8 pad2[0x860 - 0x10]; W1530_V4 v; };
extern "C" {
void func_00195c80(W1530_H* p);  // 0x00195c80: definition moved into src/anon/unit_00195c80.cpp
}
