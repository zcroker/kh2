#include "../common/types.h"
extern "C" {
struct V2cfb30 {
    f32 x, y, z, w;
    V2cfb30() {}
    V2cfb30(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));
struct Obj2cfb30 { u8 pad[1416]; u32 flags; u8 pad2[2800 - 1420]; u8 lflag[32]; s32 balloons; };
struct Ref2cfb30 { u8 pad[16]; u16* id; u8 pad2[16]; s32 refs; };
struct Item2cfb30 { s32 kind; f32 px, py, pz; f32 rx, ry, rz; };
struct Ent2cfb30 {
    s32 id;
    u8 lflag[4];
    s32 arg;
    Item2cfb30* item;
    u8 pad[8];
    Ref2cfb30* ref0;
    Ref2cfb30* ref1;
    f32 timer;
    u8 pad2[4];
};
struct Cnt2cfb30 { s32 n; Ent2cfb30* ent; s32 spawned; };
struct Game2cfb30;
struct Game2cfb30Vt { void* f[6]; s32 (*check)(Game2cfb30*, Ent2cfb30*); };
struct Game2cfb30 { Game2cfb30Vt* vt; u8 pad[88]; s32 table; };
struct Rec2cfb30 { u8 pad[16]; s16 time; };
extern s32 D_00361fa0;
extern Ent2cfb30* D_00361fa4;
extern s32 D_00361fa8;
extern Game2cfb30* D_00361f60;
extern f32 D_00349e10;
s32 g2cfb30_be_ready(void) asm("_ZN2Ti8MiniGame8be_readyEv");
s32 g2cfb30_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
Obj2cfb30* g2cfb30_next(Obj2cfb30*) asm("_Z13YS__OBJ__Eachjjjj");
s32 g2cfb30_is_ghost(Obj2cfb30*) asm("_ZN2YS3OBJ8is_ghostEv");
s32 g2cfb30_check(void*, u32) asm("_ZN2Ti5LFlag5checkEj");
void g2cfb30_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
Obj2cfb30* func_002cf4a8(Ent2cfb30*);
Obj2cfb30* func_0016f000(s32, V2cfb30*, f32);
void g2cfb30_set_balloon(Obj2cfb30*, Obj2cfb30*) asm("_ZN2Ti18MGHachimitsuGopher11set_balloonEPNS_5MGObjE");
void func_001cbcf0(V2cfb30*, V2cfb30*, s32);
s32 g2cfb30_type(void) asm("_ZN2Ti8MiniGame4typeEv");
Rec2cfb30* func_002e3260(s32, s32, u16);
s32 g2cfb30_001c0d38s(Obj2cfb30*, Obj2cfb30*, s32, s32) asm("_Z15YS__OBJ__attachjjjj");
void func_002cfb30(void);  // 0x002cfb30: definition moved into src/anon/unit_002cf260.cpp
}
