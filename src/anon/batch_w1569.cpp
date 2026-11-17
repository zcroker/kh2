#include "../common/types.h"
extern "C" {
struct Ob1a8778 {
    u8 pad0[320];
    u8 sub[2548 - 320];
    u8 flag;
    u8 pad1[3];
    s32 p;
};
extern char D_0036d610[];
void func_0017f488(void*, s32, f32, f32);
void func_00180378(void*, Ob1a8778*, s32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void wt_1c0d38(Ob1a8778*, Ob1a8778*, u32, u32) asm("_Z16u_tail4_001c0d38jjjj");
void wt_1987a8(Ob1a8778*, char*, Ob1a8778*) asm("_Z16wtarget_001987a8jjjj");
s32 func_001a81f0(s32, s32, s32);
void func_001a8418(s32);
void func_001a8678(Ob1a8778*);
void func_001a8548(void);
void func_001a8778(Ob1a8778* a, Ob1a8778* b);  // 0x001a8778: definition moved into src/anon/unit_001a8618.cpp
}
