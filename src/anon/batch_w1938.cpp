#include "../common/types.h"
struct W1938Obj { u8 pad[0xd0]; f32 mn[3]; f32 mx[3]; };
struct W1938V4 { f32 x, y, z, w; };
extern "C" {
void func_0011dd08(W1938V4* out, W1938Obj** list);  // 0x0011dd08: definition moved into src/anon/unit_0011c128.cpp
}
