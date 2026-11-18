#include "../common/types.h"

struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);

extern "C" {
u32 u_call4_00194830(u32, u32, u32, u32) asm("_Z16u_call4_00194830jjjj");
void u_call0_00233c98(void) asm("_Z16u_call0_00233c98v");
void LayFileReset(void) asm("_ZN2Tz12LayFileResetEv");

// Signed LEB128 decode; returns the pointer past the encoded value.
u8* func_00100468(u8* p, s64* val);  // 0x00100468: definition moved into src/libgcc/unwind-dw2-fde.c

extern void* D_003484a0;
extern u8 D_003484a4;
s32 func_0013c738(void*);
s32 func_0013c7d0(void);  // 0x0013c7d0: definition moved into src/anon/unit_0013a8b8.cpp

void func_0013d620(void);
void func_0013b128(void*);
void func_0013d7c0(void);
void func_001024a8(u32);
void func_0013d750(u32 a);  // 0x0013d750: definition moved into src/anon/unit_0013a8b8.cpp

struct E20 { u8 pad[16]; u8 flag; u8 id; u8 pad2[2]; };
// Flags every 20-byte entry whose id matches.
void func_00141928(u8* o, u8 id);  // 0x00141928: definition moved into src/anon/unit_00141458.cpp

struct S384 { u8 d[384]; };
extern S384 D_0034d3c0[];
void sceDbcInit(void);
void func_002f5c70(u32);
void func_00167728(S384*, s32);
// 00167b98: moved to src/anon/unit_00167358.cpp

void* func_0016abf8(u32, u32, u32, u32);
void* func_001dc5f8(void*);
void* func_0016ac80(u32 a, u32 b, void* src, u32 c, u32 d);  // 0x0016ac80: definition moved into src/anon/unit_00169f98.cpp

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
extern Q16 D_004f62a0;
void func_0017d5e8(Q16*, u32, float);
// 0016d640: moved to src/anon/unit_0016d2e0.cpp

s32 func_00170cd0(void);
void func_00102448(void*, u32);
void func_00170dd0(void* a);  // 0x00170dd0: definition moved into src/anon/unit_0016e8f8.cpp

extern u8 D_01c5f480;
void func_00185138(u32, void*, s32, float);
void func_00171640(u32* p);  // 0x00171640: definition moved into src/anon/unit_00170f58.cpp

// bsearch over 8-byte entries; returns p + entry offset.
extern u8 D_0031eec8;
u8* func_002fd248(u32, void*, u32, u32, void*);
// 00191f20: moved to src/yasui/libys/message.cpp

u32* func_001947c0(u32, u32, u32, u32);
u32 u_call4_00194830(u32 a, u32 b, u32 c, u32 d);  // 0x00194830: definition moved into src/anon/unit_00194790.cpp

extern u8 D_00350388;
void func_00169398(u8*, u32, u32*, u32, u32);
// 00197fe0: moved to src/anon/unit_00197fe0.cpp

struct O19b { u8 pad[8]; u8* hdr; u8 pad2[32]; u8* first; };
// Walks variable-length records (12-byte units) looking for id.
u8* func_0019b380(O19b* o, u32 id);  // 0x0019b380: definition moved into src/anon/unit_00199688.cpp

void func_001bc688(void*);
void func_00190128(void*);
void func_0019da20(u8* o, u32 a);  // 0x0019da20: definition moved into src/anon/unit_0019ba60.cpp

void func_00239700(void*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(void*, u32, u32);
// 001abfd8: moved to src/anon/unit_001abb28.cpp

void func_001d5370(u32*, u32, s32);
void func_002534e0(u32, u32);
// 001bba30: moved to src/yasui/libys/mission.cpp

s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
// 001bc0e0: moved to src/yasui/libys/mission.cpp

struct O1bc { u16 f0; u16 f2; u8 f4; u8 f5; u16 pad; u32 f8; };
u8 func_001bc2a8(u16*, u32, u32);
void func_001bc6a8(O1bc* o, u16* a, u32 b, u32 c, u32 d);  // 0x001bc6a8: definition moved into src/anon/unit_001bc568.cpp

extern u8 D_00351d38;
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32);
// 001c6ea0: moved to src/anon/unit_001c6e58.cpp (linked unit)

extern s32 D_00351f30;
extern u32 D_01d49980[];
// Returns 1 if x is in the registered list.
s32 func_001c9db0(u32 x);  // 0x001c9db0: definition moved into src/yasui/libys/sacrifice.cpp

s32 func_00197920(void);
s32 func_0017a6c8(void*);
void func_001c9e50(void* a);  // 0x001c9e50: definition moved into src/yasui/libys/sacrifice.cpp

extern u8 D_003524b8;
extern u8 D_0036e3a8;
void func_00177dc8(u8*, u32, u32, u32, u32);
void func_001befd8(u32, void*, u32);
void func_001d14e0(u8* o, u32 a, u32 b, u32 c);  // 0x001d14e0: definition moved into src/anon/unit_001d14e0.cpp

u8 func_001ddef0(u32**, u8*);
u32 func_001de168(u32** o, u32 id);  // 0x001de168: definition moved into src/anon/unit_001ddcf0.cpp

extern u8 D_00354bc0;
extern u8 D_00354be0;
u8 sceVu0CopyVector(void*, void*);  // memcpy16
s32 func_002006b0(u8* a, u8* b);  // 0x002006b0: definition moved into src/anon/unit_00200578.cpp

// Clears a 256-entry u64 table; the original has a 3-nop pad in the loop (asm).
extern u64 D_01dadc00[];
void sceMcInit(void);
void func_00233ce0(void);
void u_call0_00233c98(void);  // 0x00233c98: definition moved into src/anon/unit_002335e8.cpp

// Sets a 2-bit mode field (bits 9-10).
u8* func_001058e8(void);
void func_00242df0(s32 m);  // 0x00242df0: definition moved into src/anon/unit_00242478.cpp

u8* func_001d56c8(u32);
s32 func_00276c18(void);
s32 func_00244a10(void);  // 0x00244a10: definition moved into src/anon/unit_00242478.cpp

extern u32 D_0035f2c0;
void func_002bd7d8(void);
VObj* func_00103580(void);
void func_00284ea8(void);  // 0x00284ea8: definition moved into src/anon/unit_00284220.cpp

s32 func_00181500(u16);
s32 func_001a3570(u16);
s32 func_00294480(u16* o);  // 0x00294480: definition moved into src/anon/unit_00292e60.cpp

extern u8 D_0035f5a2;
extern u32 D_0035f59c;
s32 func_0023f900(u32);
void func_0023fad0(u32);
void func_00293d80(u32);
void LayFileReset(void);  // 0x00298f90: definition moved into src/anon/unit_002982f0.cpp

extern u32 D_003616f8[];
void func_002b6adc(u32, u32);
void func_002b6ab8(void);
void func_002bd1c0(void);  // 0x002bd1c0: definition moved into src/anon/unit_002bc978.cpp

// Calls each object's virtual slot 32 while iterating the list.
VObj* func_002be908(VObj*);
void func_002be960(void);  // 0x002be960: definition moved into src/anon/unit_002be020.cpp

void func_002cf2d0(void*);
void func_002cff50(u8* o);  // 0x002cff50: definition moved into src/anon/unit_002cf260.cpp

extern u8 D_003637e0;
struct C4 { u8 r, g, b, a; };
struct O2ed { void* vt; u32 a, b, c, d, e; C4 col; u32 f; };
// Constructor: zeroed fields, colour 128/128/128/128.
void func_002edf28(O2ed* o);  // 0x002edf28: definition moved into src/anon/unit_002ecdb0.cpp

extern u8 D_00347e60;
extern u8 D_00347e40;
extern u8* D_00347f80;
void func_00239870(void*);
void func_0031a840(void*);
void func_0031cd50(void*);
void func_0031c928(u32* o);  // 0x0031c928: definition moved into src/anon/unit_0031b9e0.cpp

void func_0031c9a8(u32* o);  // 0x0031c9a8: definition moved into src/anon/unit_0031b9e0.cpp

extern u8 D_0034c720;
extern VObj* D_0034c738;
void func_00160268(void*);
void func_0031e110(u32* o);  // 0x0031e110: definition moved into src/anon/unit_0031b9e0.cpp
}
