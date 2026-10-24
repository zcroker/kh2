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
void func_002d6518(s32 obj) {
    s32 fx = obj + 0xb38;
    s32 owner = D_00361f60;
    if (owner != 0) {
        func_0017f540(0.0f, 0.0f, obj + 0x140, 0);
        func_001c0d38(obj, func_002d1260(), 0x43, 0);
        func_002e7568(1.0f, obj, 2, D_00362380);
        u8* p = func_002d1878(owner);
        u8* q = func_002d1878(owner);
        func_002e7340(*(f32*)(p + 0x100), *(f32*)(q + 0x104), fx, obj, 3, D_00362388);
    }
}

}
