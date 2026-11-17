// func_0024ce18: smenu layout init (w3968, from ledger best w3951/w3937 _mam drafts).
// Compiled with -fmove-all-movables (_mam). Notes:
//  - n is one function-scope variable used for the D_0035edf4 index, the loop-2 half width and a final 0 arg:
//    its later uses make it cse's canonical register, so the copy n = i survives and gives move a1,s4 + movn.
//  - the loop-1 entry pointer is &tbl[i] (giv), so its init sits after the blez guard.
//  - two empty asms in loop 1 and one register pin (0xcb96 in a1 for the stack arg) remain.
#include "../common/types.h"
extern "C" {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; bool on; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
s32 func_002431d0(s32, s32);
void func_00288d80(void*, s32, s32, s32, u8*, s32, void*, u8*);
u8* func_002891b8(void*, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_001395f8(u8*);
void func_00139620(u8*);
void func_00139570(u8*);
s32 func_002892f8(void*);
void func_00138c68(u8*, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
s32 func_002891e8(void*);
void func_002b4070(u8*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32);
s32 func_001a6d08(s32);
void func_0028af40(void*, s32);
void func_0028d980(u8*, s32, s32, s32, u8*, s32, s32, s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_002887c8(void);
void func_00288750(void (*)(void));
s32 func_0024dfe0(void);
Ent36* func_0024e058(void);
void func_0024df90(void);
s16* func_0024e008(s32);
s32 func_0024e080(void);
void func_0024e158(void);
void func_0024d4a0(void);
void func_0024d6b8(void);
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035edf0;
extern s32 D_0035edf4;
extern u8 D_0035edfc;
extern u8* D_0035edd4;
extern u8* D_0035edd8;
extern u8* D_0035eddc;
extern u8* D_0035ede0;
extern u8* D_0035edec;
extern void* D_0035edcc;
extern u8 D_00372158[], D_00372190[], D_00372198[], D_003721a0[], D_003721a8[], D_003721b0[];

static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}
void func_0024ce18(void);  // 0x0024ce18: definition moved into src/anon/unit_0024cda8.cpp
}
