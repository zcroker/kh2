#include "../common/types.h"
extern "C" {

void sceGsSyncPath(s32, s32);
s32 func_00133d38(void);
void func_003058a0(s32);
s32 func_00133f60(void);
u32 func_001336f8(void*);
void func_002f3918(s32, u32);
extern s32 D_00347cac;
extern volatile u8 D_00347cb4;
extern u8 D_00347c88[];

/* sync.p is the EE pipeline barrier; gcc has no C form for it. */
s32 func_00133f80(void);  // 0x00133f80: definition moved into src/anon/unit_00133cf0.cpp

}
