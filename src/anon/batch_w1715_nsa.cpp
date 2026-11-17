#include "../common/types.h"
extern "C" {

struct W1715_Sub { u8 pad[0xb8]; u32 flags; };
struct W1715_Sprite {
    u8 pad0[0x18];
    W1715_Sub sub;          /* 0x18 */
    u8 pad1[0x195 - 0x18 - 0xbc];
    u8 visible;             /* 0x195 */
    u8 pad2[2];
    s32 text;               /* 0x198 */
    u8 pad3[0x1b0 - 0x19c];
    s32 mode;               /* 0x1b0 */
};
struct W1715_Menu {
    W1715_Sprite title;         /* 0x0 */
    W1715_Sprite frame;         /* 0x1b4 */
    W1715_Sprite icon[8];       /* 0x368 */
    W1715_Sprite label[8];      /* 0x1108 */
    char buf[8][64];            /* 0x1ea8: text lines */
};
struct W1715_Pos { s8 x; s8 pad; s8 y; };

extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_0035f2c4;
extern u8* D_0035f2c8;
extern W1715_Menu* D_0035f2cc;
extern u8 D_0035f2d0;
extern W1715_Pos D_00374360[];
extern u16 D_00374388[];
extern u16 D_00374398[];
extern u16 D_003743a0[];
extern u8 D_003743b0[];
extern u16 D_003743b8[];
extern char D_00374330[];
extern char D_00374338[];
extern char D_00374340[];
void func_002854b0(void);

u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
s32 func_002854c0(void);
s32 func_0023f948(void*, s32);
s32 func_0023f908(void*, s32);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
void func_0028d980(W1715_Sprite*, s32, s32, s32, u8*, s32, s32, s32, s32);
void func_00139620(W1715_Sprite*);
void func_001395f8(W1715_Sprite*);
s32 func_00192048(u32);
void func_002fde18(void*, s32, s32);
s32 func_0023aa78(W1715_Sub*);
s32 func_0023aa18(W1715_Sub*);
s32 func_0023aa38(W1715_Sub*);
void func_00138c68(W1715_Sprite*, s32, s32);
void func_0028dcc0(W1715_Sprite*, W1715_Sprite*);
u8* func_001058e8(void);
s32 func_00105868(u8*);
void func_00192c90(s32, char*);
s32 func_00192c40(s32, char*);
char* func_00192cc0(char*, const char*, s32);
s32 func_00192b30(char*);
s32 func_00276fd0(void);
f32 func_001e09d0(u8*);
s32 func_002887c8(void);
void func_00284650(void);
void func_00288750(void (*)(void));

static inline void W1715_SetFlag(W1715_Sub* s) { s->flags |= 8; }

void func_002847e0(void);  // 0x002847e0: definition moved into src/anon/unit_00284220.cpp

}
