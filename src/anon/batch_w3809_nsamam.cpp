// Menu/list setup: builds 9 rows (labels, boxes, icons) then positions the cursor/top of the list.
// Partial inline asm: an s3 placeholder register (ph) live across loop 2 and a pinned move to $4 for one call argument.
#include "../common/types.h"
struct Node { u8 pad[392]; s32 f392; u8 pad2[40]; void (*cb)(void); };
struct Cfg { u8 pad[4]; s8 count; };
extern "C" {
extern u8 D_0035f128;
extern s8 D_0035f129;
extern u32 D_0035ef64, D_0035ef68, D_0035ef6c, D_0035f03c;
extern s32 D_0035f3d4;
extern u16 D_01e21ec0[2][4];
extern void* D_0035f01c;
extern void* D_0035f04c;
extern Cfg* D_0035f12c;
u8* func_00257770(void);
void func_0028d068(s32, s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00288d80(void*, s32, u32, u32, u32, s32, u16*, u16*);
Node* func_002891b8(void*, s32);
void func_00138c10(void*, u32);
s32 func_0023aa78(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00288e08(void*, s32, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
s32 func_00257140(s32);
void func_001395f8(void*);
void func_00138c68(void*, s32, s32);
void func_00272f48(void);
s32 func_00257070(s32);
s32 func_00257088(s32);
void* func_0023f1b0(u32);
s32 func_0023c4b8(void*, u32);
s32 func_00236ca8(u32, u32);
s32 func_002570f0(void);
void func_0028bae0(void*, s32, s32, s32, s32, s32, s32, u8*, s32);
void func_0028af90(void*, s32);
s32 func_002892f8(void*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028afd0(void*, s32);
void func_0028b218(void*, s32);
void func_0028b248(void*, s32);
s32 func_0028b040(void*);
s32 func_00272b60(s32);
void func_0028af40(void*, s32);
u32 func_0028af88(void*);
void func_0028af18(void*, u32);
void func_002713c8(void);
void func_00272ae0(void);
void func_00271ee8(void);
s32 func_00283ab8(s32);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);

void func_0026f388(void);  // 0x0026f388: definition moved into src/anon/unit_0026f0a0.cpp
}
