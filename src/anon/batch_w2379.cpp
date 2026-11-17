#include "../common/types.h"

extern "C" {

// ---- 002d6518: when the global owner D_00361f60 exists, reset the object's pose, attach it,
// play its effect and place it at the owner's position.
void func_0017f540(f32, f32, s32, s32);
s32 func_001c0d38(s32, s32, s32, s32);
s32 func_002d1260();
u8* func_002d1878(s32);
void func_002e7340(f32, f32, s32, s32, s32, void*);
void func_002e7568(f32, s32, s32, void*);
extern s32 D_00361f60;
extern u8 D_00362380[8];
extern u8 D_00362388[8];
void func_002d6518(s32 obj);  // 0x002d6518: definition moved into src/anon/unit_002d62d0.cpp

}
