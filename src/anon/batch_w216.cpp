#include "../common/types.h"
extern "C" {
struct W216Obj { char p[0x24]; s32 cnt; char q[0x30]; float f58; };
struct W216Holder { s32 p0; W216Obj* o; };
s32 func_001317a8(W216Holder* a, float x);  // 0x001317a8: definition moved into src/anon/unit_00131418.cpp

struct W216Pair { s16 k; s16 v; };
extern W216Pair D_00374a08[];
s32 func_0029e7b0(s32 k);  // 0x0029e7b0: definition moved into src/anon/unit_0029d008.cpp
}
