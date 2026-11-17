// Built with -fno-sched-interblock (_nsi).
#include "../common/types.h"

extern "C" {
struct E1 { u32 p; u8 b[3]; u8 f; };
extern E1 D_003742c8[];
extern s8 D_00374268[];
extern char D_00374270[];
s32 func_00283a58(s32, s32);
void func_002fee78(char*, const char*, ...);

// Formats entry a1 of the D_003742c8 table into a0.
void func_00283eb8(char* a0, s32 a1);  // 0x00283eb8: definition moved into src/anon/unit_00283eb8.cpp
}
