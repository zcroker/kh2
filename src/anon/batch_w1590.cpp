#include "../common/types.h"
extern "C" {
struct W1590Obj;
struct W1590VT { void* f[5]; void (*fn)(W1590Obj*); };
struct W1590Obj { W1590VT* vt; };
s32 func_00139d78(W1590Obj*);
extern W1590Obj* D_0035f078;
extern W1590Obj* D_0035f07c;
void func_00281f48(s32, s32, s32);
s32 func_00281fe0(s32, s32, s32);
void func_002822c0(s32, s32, s32);
void func_002823b0(s32, s32, s32);

void func_002589b0(void);  // 0x002589b0: definition moved into src/anon/unit_002588e8.cpp

void func_00282240(s32 a, s32 b, s32 c);  // 0x00282240: definition moved into src/anon/unit_00281cf0.cpp
}
