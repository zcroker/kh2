// w3902 (helper). Built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"

extern "C" {

struct Ent26b { s32 a; s32 b; s32 c; };
struct Obj26b { u8 p0[0x12]; u8 n; u8 p13[0x34 - 0x13]; u16 x[8]; u16 y[8]; };
extern s32 D_0035f010;
s32 func_00257070(s32);
u8* func_00281180(s32, s32);
void func_002fde18(void*, s32, s32);
u16* func_001a8110(u16*);


// Sorts the object's (x, y) id pairs by the order in which the ids appear in
// the func_001a8110 list. Reusing v for the func_00257070 result gives v the
// v0 preference; the explicit goto reproduces the original's jump threading.
void func_0026b5a0(s32 arg);  // 0x0026b5a0: definition moved into src/anon/unit_0026a900.cpp

}
