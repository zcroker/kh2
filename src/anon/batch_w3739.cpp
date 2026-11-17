#include "../common/types.h"
extern "C" {
struct Ent { s32 idx; s32 one; s32 v; u8* p; };
extern Ent D_0035eee0[7];
extern s32 D_0035ef50;
extern s32 D_0035ef54;
extern u8 D_0035ef58;
extern u8 D_01dae6c0[];
extern s32 D_0035eec0[];
void func_002fde18(void*, s32, s32);
s32 strlen(s32);
char* func_00253b30(char*, s32);
s32 func_00168328(char*, u8*);
s32 func_00253948(s32);
s32 func_001688b8(void);

// Loads up to two entries (handles from D_0035eec0) into the D_01dae6c0 buffer and records them.
// The empty asm (no code) keeps total's add after dst's (sched2 order).
void func_00253638(void);  // 0x00253638: definition moved into src/anon/unit_002530c8.cpp
}
