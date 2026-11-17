#include "../common/types.h"
// 0019f2a8: -g keeps the nop after the case-3 b; goto labels for the return blocks stop ifcvt from hoisting the return value into a pseudo.
struct W1965dV3 { u16 x, y, z; };
struct W1965dItem { u8 a, b, c; W1965dV3 v; };
struct W1965dSrc { s32 type; W1965dItem it; };
static inline void W1965dv3set(W1965dV3* p, s32 v) { p->x = v; p->y = v; p->z = v; }
extern "C" {
extern W1965dItem D_0032bb00;
s32 func_00181500(s32);
W1965dItem func_00199718(s32, s32);
s32 func_0019f2a8(W1965dSrc* s, W1965dItem* out);  // 0x0019f2a8: definition moved into src/anon/unit_0019ee80.cpp
}
