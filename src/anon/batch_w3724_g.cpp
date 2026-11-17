#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern s8 *D_0035f5d0;
struct Sram { u8 pad[316]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void);
Seq *func_002766d0(void);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_00276638(s32);
s32 func_002a01c8(s32);
s32 func_002943e8(s32);
void func_002aa450(s32);
s32 func_002891e8(s32);
s32 func_00139d78(Ent *);
void func_00138c10(Ent *, s32);
// Register pin: idx in s1 (the original keeps the D_0035f5d0 %hi in s0).
void func_002a03d0(void);  // 0x002a03d0: definition moved into src/anon/unit_0029f938.cpp
}
