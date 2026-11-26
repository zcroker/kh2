// w3736 batch.
#include "../common/types.h"
extern "C" {
void dk__Sprite__create(void*, s32, s32, void*, s32, s32);
void func_00139620(void*);
s32 func_00139d78(void*);
void YI__IMAGE__Init(void*, s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f1b0(s32);
s32 func_0023f988(s32, s32);
u8* func_002766d0(void);
void func_0028dcc0(void*, void*);
s8* func_002a1bc0(u16);
struct S2a1d38 { s16 a, b, c; };
struct T2a1d38 { s8 n; s8 p1; s8 kind; u8 pad[0x4d]; struct { u16 id; u8 p[6]; } e[1]; };
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern T2a1d38* D_0035f5d4;
struct G1 { s32 dc; u8 e0; };
extern G1 D_0035f5dc;
extern u8 D_0035f5e0;
extern S2a1d38 D_00374b60[];
// Per-entry setup loop. Partial asm (step 4): the in-loop lui of D_0035f5d4 is hand-written (pinned to t7,
// ordered after p) so loop/cse2 do not hoist it and give it a register; the empty asm around the pre-loop
// load keeps t6 busy so its high half lands in t7. No code is emitted by the empty asm statements.
void Tz__JmDiagram__UpdateGra(void);  // 0x002a1d38: definition moved into src/anon/unit_002a1d38.cpp

struct S1b5108 { u8 pad[0x198]; void* x198; };
extern S1b5108* D_0035f654;
extern void* D_0035f6c8;
char* func_00192048(s32);
void func_002b6338(void*, s32, s32, s32);
// Sets the current message: a non-negative b loads it into D_0035f6c8, otherwise a message string by id.
void func_002b5108(s32 a, s32 b);  // 0x002b5108: definition moved into src/anon/unit_002b3ac8.cpp

}
