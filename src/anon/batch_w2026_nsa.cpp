#include "../common/types.h"
extern "C" {
struct V30 { u8 pad[8]; f32 f8; u8 pad2[8]; f32 f14; };
struct R30 { V30* p; f32 a, b, c, d, e, f; };
void func_001f0430(V30* v, R30* r);  // 0x001f0430: definition moved into src/anon/unit_001ef780.cpp
}
