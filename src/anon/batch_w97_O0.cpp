#include "../common/types.h"

extern "C" {
// ---- 002b871c
struct Clip2b8 { s32 a, b, c, d, e, f, g; s32 xmax; s32 step; s32 ymax; s32 flag; };
struct Ctx2b8 { u8 pad[0x48000]; Clip2b8 clip; };
void func_002b871c(Ctx2b8* p);  // 0x002b871c: definition moved into src/anon/unit_002b8274.cpp

}
