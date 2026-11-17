#include "../common/types.h"
namespace n00250a50 {
struct AV { void* (*alloc)(void*, u32, s32); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern "C" {
extern AH* D_00347f80;
extern u8 D_00347e40[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035f380[];
void func_00239700(void*);
void func_0031a838(void*);
}
struct Alloc {
    static void* operator new(u32 n) { return D_00347f80->a->vt->alloc(D_00347f80->a, n, 0); }
    static void* operator new(u32 n, AH* h) { return h->a->vt->alloc(h->a, n, 0); }
    static void* operator new[](u32 n) { return D_00347f80->a->vt->alloc(D_00347f80->a, n, 0); }
};
struct X : Alloc {
    u32 vt; u8 pad[8]; s32 f12; u8 pad2[392]; s32 f408; u8 pad3[24];
    X() { vt = (u32)D_00347f98; vt = (u32)D_00347e60; f12 = 0; func_00239700(pad2 + 8); f408 = 0; vt = (u32)D_00347e40; }
};
struct Z : Alloc {
    u32 vt; u8 pad[8]; s32 f12; u8 pad2[392];
    Z() { vt = (u32)D_00347e60; f12 = 0; func_00239700(pad2 + 8); }
};
struct Y : Alloc {
    u32 vt; u8 pad[8]; u8 m12[12]; u8 pad2[408];
    Y() { vt = (u32)D_00347f98; func_0031a838(m12); vt = (u32)D_00347e60; func_00239700(m12 + 12); vt = (u32)D_0035f380; }
    ~Y();
};
extern "C" {
extern void* D_0035ee58;
extern void* D_0035ee5c;
extern s32 D_0035ee60;
extern s32 D_0035ee64;
extern X* D_0035ee68;
extern Y* D_0035ee6c;
extern Y* D_0035ee70;
extern Y* D_0035ee74;
extern Y* D_0035ee78;
extern Z* D_0035ee7c;
extern Z* D_0035ee80;
struct R { u8 pad[4]; s32 f4; };
void func_00287b18(s32, s32);
void* func_00288be8(s32);
void func_002889f0(void*, s32, s32);
void func_00288f48(void*, s32, s32, s32, s32);
R* func_00103eb0(void);
void func_00102818(s32, s32, s32, void*, s32);
void func_002510d0(void);

// Sets up two work buffers, then allocates and constructs the module objects.
void func_00250a50(void);  // 0x00250a50: definition moved into src/anon/unit_0024fbd0.cpp
}
}
