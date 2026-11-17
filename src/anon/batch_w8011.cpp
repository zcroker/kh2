#include "../common/types.h"
extern "C" {

struct E27bb { u8 a; s8 f1; u8 q[6]; };
void func_00279ec8(void);
void func_0027b6b8(void);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void func_0027a6d8(void);
void func_0027a208(void);
void func_0027b248(s32);
u32 func_0028af88(s32);
s32 func_0028b040(s32);
extern E27bb* D_0035f230;
s32 func_00283ab8(s32);
s32 func_00258068(s32);
void func_00256cc0(s32, s32, s32);
void func_0028af18(s32, u32);
void func_0027aaa0(void);

void func_0027bbe0(s32 a0, s32 a1);  // 0x0027bbe0: definition moved into src/anon/unit_0027a6d8.cpp

struct Sub283790 { u8 pad[184]; u32 flags; };
struct Obj283790 { u8 pad[24]; Sub283790 sub; u8 pad2[392 - 24 - 188]; s32 mode; u8 pad3[405 - 396]; u8 on; u8 pad4[2]; };
struct Ent283790 { u8 pad[6]; u8 g; u8 pad7; };
struct St283790 { u8 pad[4]; s8 list[9]; s8 n; s8 cur; };
extern u8* D_0035f2b8;
extern St283790* D_0035f2b4;
extern u32 D_0035f03c;
extern Ent283790 D_003742c8[];
s32 func_00139d78(void*);
static inline void SetFlag283790(u8* p) { ((Sub283790*)p)->flags |= 8; }
u32 func_0023f1b0(u32);
u32 func_0023c4b8(u32, s32);
void func_001386e0(void*, s32, u32, u8*, s32, s32);
void func_00283790(void);  // 0x00283790: definition moved into src/anon/unit_00282c68.cpp
}
