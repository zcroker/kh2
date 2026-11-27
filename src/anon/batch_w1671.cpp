#include "../common/types.h"

extern "C" {
void dk__ObjCamera__cancelSubjective(float);
void* func_00140df0(void);
void func_00140dc0(void);
extern u8 D_0034a9e8;
// 00158f40: moved to src/harata/libdk/bookcamera.cpp

struct LNode_w1671 { u8 pad[0x7c]; LNode_w1671* next; };
struct LList_w1671 { LNode_w1671* head; LNode_w1671* tail; };
void func_0031fdb0(LList_w1671* l, LNode_w1671* after, LNode_w1671* n);  // 0x0031fdb0: definition moved into src/anon/unit_0031f2f8.cpp

void func_001fa610(u8* a0, u8* a1, u8* a2);  // 0x001fa610: definition moved into src/anon/unit_001fa1b8.cpp

struct RE_w1671 { s32 type; s32 id; s32 a; s32 b; s32 c; s32 pad[3]; };
extern s32 D_0035e360;
extern s32 D_0035e368;
extern RE_w1671 D_01dadc00[];
s32 func_00234240(s32 a0, s32 a1, s32 a2);  // 0x00234240: definition moved into src/anon/unit_002335e8.cpp

void func_002bc1e8(void*);
void YS__MISSION2D__set_warning(u8* a0);  // 0x001d1820: definition moved into src/anon/unit_001d14e0.cpp

extern s32 D_0035de5c;
extern u8 D_0035de54;
extern f32 D_0035de1c;
extern s32 D_0035de20;
void func_00226f20(s32 a0);  // 0x00226f20: definition moved into src/anon/unit_00224780.cpp

extern s32 D_00361a50;
extern u8* D_0034e948;
void func_001c1130(s32);
void func_00197760(void);
void func_00197c90(void);
void func_001398d0(s32);
void func_002bfa98(s32* a0, s32 a1, s32 a2);  // 0x002bfa98: definition moved into src/anon/unit_002bebd0.cpp

void func_001e1500(void*);
extern f32 D_00349e10;
void func_001e1638(u8* a0);  // 0x001e1638: definition moved into src/anon/unit_001e0cb8.cpp

struct C105_w1671 { void* vt; s32 f4; u8 f8; u8 p9[0xb]; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; };
extern C105_w1671 D_0033cb80;
extern u8 D_0032b930;
void wt_00105e68(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_00105e68jjjj");
// 00105e68: static initialiser, now made by gcc in src/common/shop.cpp

extern s32 D_003417a8;
extern s32 D_00341788[];
s32 func_00112a58(s32 a0);  // 0x00112a58: definition moved into src/anon/unit_001117d8.cpp

extern s32 D_00351eb8;
extern s32 D_00351ec0;
extern s32 D_00351ec8;
// 001c8e00 static initialiser: moved to src/yasui/libys/mutex.cpp (linked unit).

struct VObj_w1671 { void** vt; };
s32 func_0011f078(void*, s32);
void func_0011c890(u8* a0, s32 a1);  // 0x0011c890: definition moved into src/anon/unit_0011c128.cpp
}
