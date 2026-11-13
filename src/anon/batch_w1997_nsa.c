#include "../common/types.h"
typedef struct Alloc8 { struct AllocVt8* vt; } Alloc8;
typedef struct AllocVt8 { void* (*alloc)(Alloc8*, s32, s32); } AllocVt8;
typedef struct Mgr8 { u8 pad[20]; Alloc8* a; } Mgr8;
typedef struct Arg8 { u8 pad[4]; s16 id; } Arg8;
typedef struct Elem8 { void* vt; u8 pad[8]; u8 err[12]; u8 m[0x198 - 24]; } Elem8;
typedef struct Big8 { void* vt; u8 pad[8]; u8 err[16]; Elem8 e[3]; } Big8;
typedef struct Obj8 { void* vt; u8 pad[8]; s32 f0c; u8 pad2[8]; u8 m18[0x1a0 - 0x18]; void* vt2; u8 pad3[8]; u8 err[0x1c0 - 0x1ac]; u8 img[0x370 - 0x1c0]; } Obj8;
s32 func_002282f0(s16);
s32 func_00225b00(s16);
void func_00239700(void*);
void ErrorRaise8(void*) asm("_Z10ErrorRaisePv");
void Image8(void*) asm("_ZN2YI5IMAGEC1Ev");
void Create8(void*, s32, s32) asm("_ZN2sa9COUNTDOWN6createEib");
void func_0022c1f8(void*, s32, void*);
extern Mgr8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_0035e320[];
extern u8 D_0035e340[];
extern s32 D_0035de64;
extern u32 D_0035de68;
extern s32 D_0035de6c;
void func_0022bef8(Arg8* arg);  // 0022bef8: moved to src/sasa/event_countdown.cpp (linked unit)
