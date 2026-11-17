#include "../common/types.h"
extern "C" {
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_0023f800(s32);
void func_002369a0(s32);
void func_00239700(void*);
void func_0023c008(s32);
u8* func_00103eb0(void);
void func_00102818(s32, s32, s32, void*, s32);
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, s32, s32); };
struct Alloc { AllocVt* vt; };
struct Holder { u8 pad[0x14]; s32 a; };
extern Holder* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00288308[];
extern s16 D_0035f32c;
extern s16 D_0035f32e;
extern u8 D_0035f328;
extern s32 D_0035f334;
extern void* D_0035f338;
extern s32 D_0035f33c;
extern s32 D_0035f340;

// Startup: creates the managers kept in D_0035f334..D_0035f340 and starts a thread.
void func_002880b8(void);  // 0x002880b8: definition moved into src/anon/unit_002880b8.cpp

}
