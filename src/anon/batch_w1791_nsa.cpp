#include "../common/types.h"
extern "C" {
struct Bx;
struct BxVt { void* f[5]; void (*get)(Bx*, f32*, f32*); };
struct Bx { BxVt* vt; };
struct Ob {
    u8 pad0[0xc];
    Bx* box;
    u8 pad10[0x20];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0xd8 - 0x3c];
    f32 mn[3];
    f32 mx[3];
};
// 0017eee8: moved to src/yasui/libys/motion.cpp
}
