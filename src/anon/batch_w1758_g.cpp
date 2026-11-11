#include "../common/types.h"

extern u8* D_01d49320;

extern "C" {
s32 w1758_ys_mission_isexec(void) asm("_ZN2YS7MISSION6IsExecEv");
u32 w1758_tail4_192048(s32) asm("_Z16u_tail4_00192048jjjj");
void func_0014f578(u32);
s32 func_00133f80(void);
s32 func_00133f60(void);
void func_00133ea8(void);
void func_00109330(void);
void func_00109340(void);

// 001bb958: moved to src/yasui/libys/mission.cpp
}

s32 func_00109e30(int a) {
    s32 r;
    if ((u8)a) r = func_00133f80();
    else r = func_00133f60();
    func_00133ea8();
    func_00109330();
    func_00109340();
    return r;
}
