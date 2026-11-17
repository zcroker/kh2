#include "../common/types.h"
namespace n002450c8 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[404];
};
struct Ek {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ek();
    u8 pad[432];
};
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern "C" AH* D_00347f80;
struct El2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El2();
    u8 pad[404];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern "C" void func_0031acc0(void*);
extern "C" void func_00239870(void*);
extern "C" void func_00106420(void*);
extern "C" void func_0031a840(void*);
struct B0 { ~B0() { func_0031a840(this); } };
extern "C" u8 D_00347e60[];
struct M24 { ~M24() { func_00239870(this); } };
struct B : B0 { u8 pad[24]; M24 m; u8 pad2[411]; ~B() { *(u8**)this = D_00347e60; } };
struct M436 { u8 pad[436]; ~M436() { func_0031acc0(this); } };
struct Big {
    B b; M436 m; Ek a[4]; Ek b2[4]; Ek c[4]; Ek d[4]; El e[4]; El f[4]; El g[4]; El h[4];
    static void operator delete(void* p) { func_00106420(p); }
};
extern "C" {
extern void* D_0035ed20;
extern void* D_0035ed24;
extern DO* D_0035ed28;
extern DO* D_0035ed2c;
extern DO* D_0035ed30;
extern El2* D_0035ed34;
extern void* D_0035ed38;
extern Big* D_0035ed40;
extern AO* D_0032ba14;
void func_00288b00(void*);
void func_00288c20(void*);
void func_002b3fb0(void*);
// Frees the module's globals; the big object's destructor and the array delete are inlined.
void func_002450c8(void);  // 0x002450c8: definition moved into src/anon/unit_00242478.cpp
}
}
namespace n0027f4a8 {
struct Sub { u8 pad[184]; u32 flags; void set8() { flags |= 8; } };
struct Win { u8 pad[24]; Sub sub; };
struct E { u8 pad[408]; s32 f408; u8 pad2[20]; s32 f432; };
extern "C" {
extern s32 D_0035f250;
extern void* D_0035f254;
extern Win* D_0035f258;
union UE { E* p; s32 i; };
extern UE D_0035f25c;
extern s32 D_0035f3d4;
extern u16 D_003740f8[2][9];
extern u16 D_00374130[];
extern u16 D_00374158[][2];
extern s8 D_00374168[];
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00288d80(void*, s32, s32, s32, s32, s32, u16*, u16*);
E* func_002891b8(void*, s32);
void func_00139620(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa98(void*);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
void func_001395f8(void*);
s32 func_00192048(u16);
void func_0028af28(void*, s32);
s32 func_001041c0(void);
void func_0028b1b0(void*, s32);
void func_0027fd38(void);
void func_002891f0(void*, s32, s32, s32, s32);
void func_00287bd0(s32, s32);

// Builds the menu window and its 9 rows, then the per-row sub-items.
void func_0027f4a8(void);  // 0x0027f4a8: definition moved into src/anon/unit_0027f2b0.cpp
}
}
namespace n0025f7f0 {
struct E { u8 pad[408]; s32 f408; };
struct F { u8 pad[408]; };
struct Base { u8 pad[0x87d0]; F e[8]; };
extern "C" {
extern s32 D_0035f3d4;
extern void* D_0035f010;
extern void* D_0035f01c;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0037327c;
extern s32 D_00373278;
Base* func_00257770(void);
void func_0028f4d8(s32, s32, s32);
s32 func_00281180(void*, s32);
s32 func_00281140(void*, s32);
s32 func_00257100(s32);
void func_00288d80(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00288e08(void*, s32, s32, s32);
E* func_002891b8(void*, s32);
void func_00139620(void*);
void func_001395f8(void*);
s32 func_00192048(s32);
s32 func_00285d58(s32);
s32 func_00285e30(s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00138c68(void*, s32, s32);
s32 func_00257070(s32);
void func_00257050(s32, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
u32 func_0028af88(void*);
s32 func_00258068(s32);
void func_0028af18(void*, u32);
void func_0025f7d8(void);
void func_00261b30(void);
void func_00261d48(void);
void func_00262af8(void);
void func_00256cc0(s32, s32, s32);
void func_00287cc0(s32);

void func_0025f7f0(s32 sel);  // 0x0025f7f0: definition moved into src/anon/unit_0025f6b8.cpp
}
}
