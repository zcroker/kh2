#include "../common/types.h"
extern "C" {

struct E14 { u8 a; u8 b; u8 pad[12]; };
struct Tbl { s32 x; s32 n; E14 e[1]; };
extern Tbl* D_01c940b4;
E14* func_001aff90(s32 a, s32 b);  // 0x001aff90: definition moved into src/anon/unit_001ada38.cpp

struct M2D { u8 pad[0x1c]; s32 m1c; u8 pad2[0x18]; s32 m38; };
void check_warning(M2D* self, s32 v) asm("_ZN2YS9MISSION2D13check_warningEi");
void func_001d2248(M2D* o, s32 v);  // 0x001d2248: definition moved into src/anon/unit_001d14e0.cpp

extern s16 D_0035f4e0;
struct E4 { u16 id; u16 x; };
extern E4* D_0035f4dc;
s32 func_00292af0(s32 id);  // 00292af0: moved to src/anon/unit_00292998.cpp

struct O2da { u8 pad[0xbf4]; s32 p; };
s32 YS__OBJ__get_pos(s32);
void func_002bc188(s32, s32);
void func_002daa00(O2da* o, u32 a);  // 0x002daa00: definition moved into src/anon/unit_002da040.cpp

}
