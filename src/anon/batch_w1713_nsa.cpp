#include "../common/types.h"
/* 00277d20: builds the save/load slot menu (rows of labels, frames and icons). */
/* Needs -fno-strict-aliasing (built from a *_nsa.cpp file). */
extern "C" {

struct W1713Sub { u8 pad[1]; };
struct W1713Item {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b0 - 0x19];
    s32 mode;                  /* 0x1b0 */
};
struct W1713Item2 { u8 pad[0x198]; };
struct W1713Obj {
    u8 pad0[0x18];
    W1713Sub sub;              /* 0x18 */
    u8 pad19[0x1b4 - 0x19];
    void* callback;            /* 0x1b4 */
};
struct W1713Menu {
    u8 pad0[0xd30];
    W1713Item tabs[24];        /* 0x0d30 */
    W1713Item frames[24];      /* 0x3610 */
    W1713Item labels[24];      /* 0x5ef0 */
    W1713Item2 icons[24];      /* 0x87d0 */
};
struct W1713Slot { s8 a; s8 flag; u8 pad[6]; };
struct W1713Save {
    u8 pad0[7];
    s8 count;                  /* 0x07 */
    u8 pad8[8];
    W1713Slot slots[1];        /* 0x10 */
};
struct W1713Tex { u8 pad[0x28]; s32 id; };

extern s32 D_0035ef64;
extern s32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s32 D_0035f03c;
extern s32 D_0035f04c;
extern W1713Save* D_0035f230;
extern s32 D_0035f3d4;
extern s16 D_01e21ee0[2][4];

W1713Menu* func_00257770(void);
s32 func_0028f930(s32);
void func_0028f4d8(s32, s32, s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, s16*, s16*);
W1713Obj* func_002891b8(s32, s32);
void func_00138c10(void*, s32);
void func_00138c68(void*, s32, s32);
s32 func_0023aa78(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_0028dcc0(void*, void*);
void func_00139620(void*);
void func_001395f8(void*);
s32 func_00257140(s32);
void func_0027b960(void);
W1713Tex* func_0023f1b0(s32);
s32 func_0023c4b8(W1713Tex*, s32);
s32 func_00236ca8(s32, s32);
void func_00257708(s32);
s32 func_002570f0(void);
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, W1713Menu*, s32);
void Tz__Select__SetSelectMax(s32, s32);
void func_0027c2f8(void);
void Tz__Select__SetPageMode(s32, s32);
void func_0028b248(s32, s32);
void func_00257050(s32, s32, s32);
s32 func_0028af88(s32);
s32 func_00258068(s32);
s32 func_0028b040(s32);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
s32 func_00283ab8(s32);
void Tz__CmTop__CreatePadHelp(s32, s32, s32);
void func_0027b0f8(void);
void Tz__CmAbility__UpdateNew(void);
void func_0027a208(void);
void func_00287cc0(s32);

/* The original passes the colour before the shared screen globals. */
static inline __attribute__((always_inline)) void W1713InitIcon(void* p, s32 id, s32 color, s32 w, s32 h, s32 tex) {
    func_0028d8c0(p, id, w, h, tex, color, -1, 0);
}

void Tz__CmAbility__SetupSel(void);  // 0x00277d20: definition moved into src/anon/unit_00277708.cpp

}
