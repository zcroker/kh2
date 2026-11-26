#include "../common/types.h"
extern "C" {

void func_002d0ea8(void*);
extern u8 D_003622c0[];

typedef struct V4_w3717 { f32 x, y, z, w; } V4_w3717;
typedef struct O2d4_w3717 {
    void* vt;
    u8 pad[0xbec];
    union { s32 i; f32 f; } bf0;
    u8 pad2[0xc];
    V4_w3717 c00;
    f32 c10;
    f32 c14, c18, c1c;
    u8 pad3[0x10];
    f32 c30, c34;
} O2d4_w3717;

// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d49c0(O2d4_w3717* o);  // 0x002d49c0: definition moved into src/anon/unit_002d4548.cpp

u8* func_002766d0(void);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(s32, s32);
void YI__IMAGE__Init(u8*, s32);
void dk__Sprite__create(u8*, s32, s32, u8*, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_00138c68(u8*, s32, s32);
extern u8 D_0035f590;
extern u8 D_0035f591;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern s32 D_0035f58c;
extern s32 D_00374738;
extern s32 D_0037473c;
extern s32 D_00374740;
extern s32 D_00374744;
extern s32 D_00374748;
extern s32 D_0037474c;

// Sets up the two party-member panels (i = 0, 1) once, then marks D_0035f591.
// Register pins (p in s7, d in t7, the constant 1 in t6) and the empty asms reproduce the
// original's register choice and scheduling; the else arm reads D_00374738 through a hidden
// high half (0x370000 + 0x4738) so its lui is issued before id = d + 1.
void Tz__JmReport__CreateGra(u8 flag);  // 0x00296b80: definition moved into src/anon/unit_00295d28.cpp

}
