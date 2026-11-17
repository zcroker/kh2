#include "../common/types.h"
extern "C" {
// ---- 002331a0
struct Wk { s32 a; s32 b; u8 c; u8 pad[3]; s32 d; s32 e; s32 f; u8 pad2[8]; char n1[16]; char n2[16]; };
Wk* func_00227a28();
char* func_0022f4f0(s32);
char* func_002ff2e8(char*, const char*);
char* func_002330c8(char*, char*);
s32 readBuffAlloc_w8010(char*, Wk*, s32) asm("_ZN2sa5EVENT13readBuffAllocEPcPNS_7READ_WKENS_11EVENT_ALLOC10ALLOC_TYPEE");
void func_002330b0();
void func_001684c0(char*, s32, void (*)(), Wk*);
void func_002331a0(char* name, s32 type, s32 id, s32 d, s32 flag);  // 0x002331a0: definition moved into src/anon/unit_00232f08.cpp

// ---- 00246328
extern s32 D_0035ed20; extern s32 D_0035ed24; extern s32 D_0035ed28; extern s32 D_0035ed2c;
extern s32 D_0035ed30; extern s32 D_0035ed40;
s32 func_00287bc0(void);
s32 func_00287db0(void);
s32 func_002887c8(void);
void func_0028dae0(s32, s32);
void func_0028dac8(s32, s32);
s32 func_0028acc8(s32);
s32 func_0028acb8(s32);
void func_0028aa40(s32);
s32 func_00139d78(s32);
s32 func_002891e8(s32);
s16* func_002468a0(s32);
void func_00247bb0(void);
void func_00246708(void);
void func_00246490(s32, s32, s32);
struct NoTail246328 { ~NoTail246328() {} };
void func_00246328(void);  // 0x00246328: definition moved into src/anon/unit_00242478.cpp

// ---- 00251d80
s32 func_00289310(void*);
s32 func_0028d008(s32);
s32 func_00251e90(s32);
void func_0028cf98(s32, s32);
void func_00251ec8(s32);
void func_00252660(s32);
void func_00252540();
s32 func_00252000();
void func_00251fe0();
void func_002890e0(void*, s32, s32, s32, s32);
void func_00289038(void*, s32, s32, s32, s32, s32, s32);
s32 func_002891d0(void*);
void func_0028cf28(s32, s32);
void func_00251d80(void* obj, s32 mode, s32 h);  // 0x00251d80: definition moved into src/anon/unit_00250fb8.cpp

// ---- 002657a8
struct Rec { u16 id; u16 x; s16 idx; };
struct Row { Rec r[10]; };
struct Elem { u8 pad[0x18]; u8 sub[0x180]; s32 v; u8 pad2[0x18]; };
struct Big { u8 pad[0x3610]; Elem e[20]; };
struct Info { u8 pad[0x18]; u32 mask; };
struct Tex { s16 h; s16 pad; };
Big* func_00257770(void);
void func_002fde18(void*, s32, s32);
void func_00138c10(Elem*, s32);
void func_00138c68(Elem*, s32, s32);
s32 func_0023aa98(void*);
s32 func_0023aa78(void*);
s32 func_00192048(u16);
s32 func_0028b040(s32);
u32 func_002670a0(s32);
void func_00266df8(u32);
void func_00265c78(void);
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern u8* D_0035f0e4;
extern Tex D_00373500[];
extern Row D_00373530[2];
extern Row D_003735a8[2];
extern Row D_00373620[2];

void func_002657a8(void);  // 0x002657a8: definition moved into src/anon/unit_00265580.cpp
}
