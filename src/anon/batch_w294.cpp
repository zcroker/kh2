#include "../common/types.h"
namespace n0023c728 {
struct Ent { union { u16 f0; u8 fx; }; u16 f2; u8 pad[16]; };
struct Seg { s32 f0; s32 f4; s32 f8; s32 pad[3]; };
// Item's constructor is func_00239700; the mangled name is equated to it below.
struct Item {
    Item();
    virtual ~Item();
    u8 pad[64];
    f32 f68;
    u8 pad2[272];
    static void* operator new[](unsigned int n, void* h) asm("_Znaj");
    static void operator delete[](void* p) asm("_ZdaPv");
};
asm(".equ _ZN9n0023c7284ItemC1Ev, func_00239700");
struct Obj {
    u32 f0; void* f4; u8* f8; u8 pad0[4]; Seg* f16; Ent* f20; s32* f24; u8 pad1[12];
    void* f40; u8 pad2[4]; Item* f48; union { s32 f52; u8 c52; }; u8 pad3[8]; f32 f64; f32 f68; f32 f72; s32 f76; u8 f80;
};
extern "C" {
u8* GetImage294(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void wtarget294_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
s32 func_0023c5a0(Obj*, s32);
void YI__SEQUENCE__Init(Item*, u8*, u8*);
u8 YI__LAYOUT__GetLoopMode(Obj*);
void func_0023c728(Obj* o, s32 idx);  // 0x0023c728: definition moved into src/anon/unit_0023bc58.cpp
}
}

namespace n002515a0 {
extern "C" {
struct Sub { u8 pad[184]; u32 f184; void set8() { f184 |= 8; } };
struct Sc { u8 pad[24]; Sub sub; u8 pad2[405-24-188]; u8 f405; };
extern Sc* D_0035ee80;
extern s32 D_0035ee60;
extern void* D_0035ee5c;
struct W { s32 v; };
extern W D_0035f3d4;
extern s32 D_003725c0[];
void func_0028d8c0(Sc*, s32, s32, s32, s32, s32, s32, s32);
void Tz__Select__SetItem(void*, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(void*, s32);
s32 func_0023aa78(u8*);
void Tz__Select__SetExOffset(void*, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, Sc*);
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32);
void func_0028af28(void*, s32);
void func_00287cc0(s32);
void Tz__CANA__SetupSel(void);  // 0x002515a0: definition moved into src/anon/unit_00250fb8.cpp
}
}
