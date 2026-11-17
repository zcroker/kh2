#include "../common/types.h"
extern "C" {
typedef struct R3_w { u8 pad[4]; u16 id; u8 pad2[0x1e]; } R3_w;
typedef struct E5_w { u16 id; u8 pad[6]; } E5_w;
typedef struct R5_w { u8 pad[5]; s8 n; u8 pad2[2]; s32 off; } R5_w;
typedef struct T_w { u8 pad[8]; s32 n; u8 pad2[4]; } T_w;
T_w* func_00294000(s32);
s32 func_00294368(R3_w*);
s32 func_00294480(R5_w*);
extern u32* D_0035f578;
void func_00294020(u32* bits);  // 0x00294020: definition moved into src/anon/unit_00292e60.cpp
}
