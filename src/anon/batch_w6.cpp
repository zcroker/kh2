#include "../common/types.h"

// Batch w6: small leaf / wrapper functions.

// Object whose first word is a vtable pointer.
struct VObj { void** vt; };

extern "C" {

void ys_area_read(void* task) asm("_ZN2YS8AreaReadEP4TASK");
void ys_prepare_scene(void) asm("_ZN2YS5EVENT12PrepareSceneEv");
u32 ys_is_mark_history(void) asm("_ZN2YS8FIELDOBJ15is_mark_historyEv");
u32 ys_can_end(void) asm("_ZN2YS9SACRIFICE6CanEndEv");

// Forward a to the global object's second virtual method.
extern VObj* D_0032b9cc;
// 00102ed8: moved to src/common/title.cpp

// True when the state at +0xb6c is 16, 12 or 15.
u32 func_00111278(u8* p);  // 0x00111278: definition moved into src/anon/unit_00110b00.cpp

void func_0011c798(u8* p, u32 a);  // 0x0011c798: definition moved into src/anon/unit_0011c128.cpp

// Set a timer (at least 15000) with a byte parameter and raise its flag.
struct S4240 { u8 flag; u8 b; u8 pad[2]; s32 time; };
extern S4240 D_004f4240;
void func_001671e8(s32 t, u8 b);  // 0x001671e8: definition moved into src/anon/unit_001664c0.cpp

void func_00170888(void*);
void func_001badd8(void);
void func_001afaf0(void*);
void ys_area_read(void* task);  // 0x00169148: definition moved into src/anon/unit_00168aa0.cpp

void func_0017f488(u32, u32, f32, f32);
void func_00171150(u32* p);  // 0x00171150: definition moved into src/anon/unit_00170f58.cpp

void func_001cfac0(u32, f32, f32, f32, f32);
struct S1a40 { u32* obj; f32 a, b, c, d; };
void func_00171a40(S1a40* p);  // 0x00171a40: definition moved into src/anon/unit_00170f58.cpp

void func_00187a18(u32, u32, u32, u32, void*);
void func_00172f00(u32* p);  // 0x00172f00: definition moved into src/anon/unit_00171e58.cpp

// 00178cf8: moved to src/yasui/libys/player.cpp

u32 func_001a6a20(u32, u32);
void func_0018fd10(u32* p);  // 0x0018fd10: definition moved into src/anon/unit_0018f140.cpp

void func_00187018(u32, u32, u32, u32, f32);
void func_0018fd40(u32* p);  // 0x0018fd40: definition moved into src/anon/unit_0018f140.cpp

void func_001b9db0(u32);
void func_00197c90(void);
void func_001ada38(u32);
void ys_prepare_scene(void);  // 0x00197738: definition moved into src/anon/unit_00195d00.cpp

u32 func_0016bff0(void);
u8 func_00195700(void*, u32);
extern u8 D_0034fa78;
// 001a6c60: moved to src/anon/unit_001a6a10.cpp

void func_0017c430(u32);
void func_0016bd60(u32, u32);
void func_001b27c0(u32, u32 a);  // 0x001b27c0: definition moved into src/anon/unit_001b2780.cpp

extern u8 D_003511c3;
extern u8 D_003511c2;
u32 func_001b7fd0(void);  // 0x001b7fd0: definition moved into src/anon/unit_001b6a50.cpp

void func_002fd248(u32, void*, u32, u32, void*);
extern u32* D_01d48cc4;
extern u8 D_00320408;
// 001b83f0: moved to src/anon/unit_001b82d8.cpp

void func_001be4e0(u8*, u32);
void func_002ba2e8(u32, u32);
void func_001be4b0(u8* p);  // 0x001be4b0: definition moved into src/anon/unit_001bc568.cpp

extern u32* D_01d49558;
extern u8 D_00320c08;
void func_001c2d48(u32 a);  // 0x001c2d48: definition moved into src/anon/unit_001c2b58.cpp

u32 func_001a8b68(void);
u32 func_0017e668(u32);
u32 ys_can_end(void);  // 0x001c9d88: definition moved into src/yasui/libys/sacrifice.cpp

// Increment a u16 counter, saturating at 999.
extern u16 D_0032fafe[];
void func_001d9820(s32 i);  // 0x001d9820: definition moved into src/anon/unit_001d7458.cpp

u32 func_001b1448(u32);
extern u32 D_003528fc;
extern u32 D_01d5baa8;
void func_001d9d00(void);  // 0x001d9d00: definition moved into src/anon/unit_001d9d00.cpp

void func_00168388(u32, void*, void (*)(void), u32);
extern u32 D_00352aec;
extern u8 D_01d5bb40;
void func_001dcd68(void);
void func_001dcd88(void);  // 0x001dcd88: definition moved into src/anon/unit_001dbfd8.cpp

struct Pair { u32 a, b; };
void func_001de690(u32);
void func_001dced0(void);
extern Pair D_01d9e348;
void func_001de910(void);  // 0x001de910: definition moved into src/anon/unit_001ddcf0.cpp

extern VObj* D_01d9e340;
u32 func_001e0188(u32 a);  // 0x001e0188: definition moved into src/anon/unit_001deb58.cpp

u32 func_002fea18(void);
// Seed the VU0 random generator.
void func_0020e138(void);  // 0x0020e138: definition moved into src/anon/unit_0020dde8.cpp

void func_00228bd8(VObj*);
void func_00228e28(VObj* o);  // 00228e28: moved to src/anon/unit_00228618.cpp (linked unit)

void func_002344c0(u32, u32, u32, u32, u32);
void func_00234720(u32 a, u32 b, u32 c, u32 d);  // 0x00234720: definition moved into src/anon/unit_002335e8.cpp

void func_0023c728(u32*);
void func_0023c598(u32*);
void func_0023c6f8(u32* p);  // 0x0023c6f8: definition moved into src/anon/unit_0023bc58.cpp

void func_0023fc08(void);
extern u32 D_0035ebe0;
extern u32 D_0035ebec;
void func_0023fb28(void);  // 0x0023fb28: definition moved into src/anon/unit_0023f5b8.cpp

u32 func_002537c8(u32);
void func_0023fa08(void*, u32);
extern u8 D_0035f3a8;
void func_00256b40(void);  // 0x00256b40: definition moved into src/anon/unit_00254020.cpp

struct S408 { u8 d[408]; };
u8 func_00139d78(S408*);
extern S408* D_0035f028;
u32 func_00256b80(s32 i);  // 0x00256b80: definition moved into src/anon/unit_00254020.cpp

// Clear four doublewords of the buffer.
extern volatile u64* volatile D_0035f324;
void func_00288018(void);  // 0x00288018: definition moved into src/anon/unit_00286d28.cpp

u32 func_00287bc0(void);
void func_00276c50(u32, u32);
void func_002a65a0(void);  // 0x002a65a0: definition moved into src/anon/unit_002a5a90.cpp

struct S16d8 { u8 pad[22012]; s32 a; u8 pad2[23292 - 22016]; s32 b; };
extern S16d8* D_0035f634;
u32 func_002b16d8(void);  // 0x002b16d8: definition moved into src/anon/unit_002b0950.cpp

void func_002e7670(u8*);
void func_002e76b0(u8*);
void func_002e77a8(u8*);
// 002e7768: moved to src/anon/unit_002e7658.cpp

void func_0016c568(u32, u32, f32);
void func_002e7c78(u32* p);  // 0x002e7c78: definition moved into src/anon/unit_002e7b10.cpp
// 002f0948: moved to src/naka/libkn/trapfunctions.cpp

// atoi: (int)strtol(s, 0, 10).
s64 strtol(const char*, char**, s32);
s32 atoi(const char* s) {  // strtol10
    return (s32)strtol(s, 0, 10);
}

}

// 00186ce8: moved to src/anon/unit_00185d10.cpp

extern Pair D_01c6ced0;
// 001ad948: moved to src/anon/unit_001abb28.cpp

// dst = mat * vec (VU0 COP2 macro sequence, written as asm).
void sceVu0ApplyMatrix(u32 a0, u32 a1, u32 a2, u32) {
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "lqc2 $vf5, 16(%1)\n\t"
        "lqc2 $vf6, 32(%1)\n\t"
        "lqc2 $vf7, 48(%1)\n\t"
        "lqc2 $vf8, 0(%2)\n\t"
        "vmulax.xyzw ACC, $vf4, $vf8x\n\t"
        "vmadday.xyzw ACC, $vf5, $vf8y\n\t"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n\t"
        "vmaddw.xyzw $vf9, $vf7, $vf8w\n\t"
        "sqc2 $vf9, 0(%0)" : : "r"(a0), "r"(a1), "r"(a2) : "memory");
}
