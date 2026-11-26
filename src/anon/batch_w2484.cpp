#include "../common/types.h"

extern "C" {

typedef struct V4 { f32 x, y, z, w; } V4;

void YS__PLAYER___OVR_exec(void*);
void func_00183768(f32, void*, void*);
u8* func_002dc7c8(s32);
f32 func_002dc808(s32);
f32 fabsf(f32);
extern s32 D_00361f60;

// Applies a push along the owner's direction vector, then eases the value at +0xc00 within the param range.
void Ti__MGJumpPlayer___OVR_exec(u8* p);  // 0x002dd7d0: definition moved into src/anon/unit_002dd650.cpp

}
