#include "../common/types.h"

extern "C" {

extern u32 D_0032b930;
struct S104298 { u32 vt; u32 a; u8 b; u8 pb[11]; u32 c, d, e, f, g, h; };
extern S104298 D_0032ba48;
void wtarget_00104298(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_00104298jjjj");
// 00104298: static initialiser, now made by gcc in src/common/gumibattle.cpp

extern f32 D_00340eb4, D_00340eb8, D_00340ebc, D_00340ec0;
void func_0010a828(f32 a, f32 b);  // 0010a828: moved to src/anon/unit_00109c30.cpp

u32* YS__OBJ__get_pos(u32);  // obj_get_attach_or_alt
void func_0013f828(u32* t);  // 0x0013f828: definition moved into src/anon/unit_0013ef70.cpp

void func_00177a58(u32*);
void YS__BTLOBJ__exec_reflect_default(u32*, u32, f32, u32, u32);
// 00176620: moved to src/yasui/libys/party.cpp

extern u32 D_00350b70;
void func_001ac970(u32*, u32, u32, u32, u32, u32, u32, u32);
// 001ad098: moved to src/anon/unit_001abb28.cpp
// 001ad0f8: moved to src/anon/unit_001abb28.cpp

// hand-written: hardware register setup (DMA/VU0 control) then lq/sq copy
extern u32 D_00363ce0[];
void func_002f49c0(void);  // 0x002f49c0: definition moved into src/sdk/libvu0_002f49c0.c

}
