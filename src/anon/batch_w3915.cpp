#include "../common/types.h"

// 002986e0: register pins (i in s0, a in s7, the loop count in t7)
// and one empty asm tie reproduce the original allocation; see asm_review.tsv.
extern "C" {
struct Cnt { s32 n; s16 id[1]; };
u8* func_00276348(void);
u8* func_002766d0(void);
void func_00288e88(s32);
void func_00276690(s32);
void func_00298fe8(s32);
void func_00276e78(void);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_001395f8(u8*);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(s32, s32);
s32 func_002983d8(s32);
void func_00294348(s32);
s32 func_0028af88(s32);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
void func_00298e48(void);
void func_00299260(void);
void func_00287cc0(s32);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f200;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s8 D_0035f5a0;
extern Cnt* D_0035f598;

void func_002986e0(void);  // 0x002986e0: definition moved into src/anon/unit_002982f0.cpp
}

extern "C" {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 pad11; u16 f12; u8 pad14[16]; };
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
Ent36* func_00246868(void);
s32 func_00246968(s32);
s32 func_00246840(void);
s32 func_002431d0(s32, s32);
void func_00288d80_b(void*, s32, s32, s32, u8*, s32, Ent36*, u8*) asm("func_00288d80");
u8* func_002891b8_b(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
s32 func_002892f8(void*);
void func_00138c68(u8*, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_002467f0(void);
s32 func_002891e8(void*);
s32 func_002469a0(s32);
s16* func_002468a0(s32);
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32);
s32 func_00246a08(void);
void func_0028af40(void*, s32);
void func_0028d980_b(u8*, s32, s32, s32, u8*, s32, s32, s32, s32) asm("func_0028d980");
void func_00246ab8(void);
void func_00247198(void);
void func_00247580(s32);
void func_00245968(void);
void func_00287bd0(s32, s32);
s32 func_002887c8(void);
void func_00245be8(void);
void func_00245dc0(void);
void func_00288750(void (*)(void));
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_0035ed20;
extern u8* D_0035ed28;
extern u8* D_0035ed2c;
extern u8* D_0035ed30;
extern void* D_0035ed38;
extern u8 D_0035ed3c;
extern u8* D_0035ed40;
extern u8 D_0035ed44;
extern u8 D_00371ad0[];
extern u8 D_00371b08[];
extern u8 D_00371b10[];
extern u8 D_00371b18[];
extern u8 D_00371b20[];
extern u8 D_00371b28[];

static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}

// 00245488: pure C++ (-O2). Loop 1 keeps the func_0023aa98 result in its own pointer p, and
// the tail block uses its own local, which gives the original register copies before loop 2.
void func_00245488(void);  // 0x00245488: definition moved into src/anon/unit_00242478.cpp
}
