#include "../common/types.h"
extern "C" {
struct W1821B38 { s64 d[7]; };
struct W1821In { s32 a; s32 b; };
struct W1821Ctx { s32 x; W1821In* in; };
struct W1821N { s32 a0; W1821Ctx* ctx; s32 a3; s32 a4; u8 pad[8]; W1821B38 b; };
W1821N* func_00109c30();
void func_00109cc0(s32, W1821N*);
extern s32 D_0033cca4;

W1821N* kn__VU1Draw__draw(s32 a0, W1821B38* b, W1821Ctx* c, s32 a3, s32 a4);  // 00109d00: moved to src/anon/unit_00109c30.cpp
}
