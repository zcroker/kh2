#include "../common/types.h"
struct V2c {
  f32 x, y, z, w;
  V2c() {}
  V2c(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  V2c& operator=(const V2c& o) {
    if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    return *this;
  }
} __attribute__((aligned(16)));
struct Box2c { V2c a, b; };
struct Mat2c { V2c r[4]; };
extern "C" {
void func_001444c8(Box2c*, V2c*, V2c*);
void func_0011b6a8(Mat2c*);
void dk__Aabbox__mulMatrix(Box2c*, Mat2c*);
s32 func_002cec08(void*, Box2c*);
extern void* D_00361f60;
u8 func_002cef80(void* a0, V2c* pos);  // 002cef80: moved to src/taito/minigame_base.cpp (linked unit)
// register pins reproduce the original's counter/temp allocation
struct Hdr1e { s16 a; s16 b; s16 c; s16 fmt; u8 pad[16]; s32 off; };
Hdr1e** func_001e4248(s32* p);  // 0x001e4248: definition moved into src/anon/unit_001e0cb8.cpp
}
