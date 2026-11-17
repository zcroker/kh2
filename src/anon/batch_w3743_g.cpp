#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
struct L { u8 pad[6]; s8 items[1]; };
extern L *D_0035f5ec;
struct Sram { u8 pad[132]; u32 bits[8]; };
struct Ent { u8 pad[408]; };
struct Seq { u8 pad[0xa998]; Ent e[4]; };
Sram *func_002a9d68(void);
Seq *func_002766d0(void);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_00276638(s32);
s32 func_002a6368(s32);
s32 func_002944d0(s32);
void func_002aab90(s32);
s32 func_002891e8(s32);
s32 func_00139d78(Ent *);
void func_00138c10(Ent *, s32);

static inline __attribute__((always_inline)) Ent* at(Seq* b, s32 sz, s32 i) { return (Ent*)((u8*)b + i*sz + 0xa998); }
static inline __attribute__((always_inline)) Ent* at2(Seq* b, s32 i, s32 sz) { return (Ent*)((u8*)b + i*sz + 0xa998); }

void func_002a65d0(void);  // 0x002a65d0: definition moved into src/anon/unit_002a5a90.cpp
}
