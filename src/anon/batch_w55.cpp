#include "../common/types.h"

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct NoTail { ~NoTail() {} };

// 128-bit copy (lq/sq through t0).
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}

static inline bool isPos(f32 f) { return f > 0.0f; }

struct HeapW55;
struct ElemW55 { u8 d[64]; ElemW55() {} ~ElemW55() {} } __attribute__((aligned(16)));
void* operator new[](unsigned int, HeapW55*) asm("func_001063f0");

struct DeadRingW55 { void* e[4]; s32 idx; };
struct EntW55 { u32 id; f32 f; };
struct RingEW55 { u32 v; f32 f; };
struct RingW55 { s32 idx; s32 pad; RingEW55 e[3]; };
struct S1967 { u8 pad[7928]; u16 t[1]; };
struct PairW55 { u16 a; u16 x; u16 b; u16 v; };
struct SecW55 { u8 k; u8 type; u16 cnt; PairW55 p[1]; };
struct ItemW55 { u8 pad[12]; s16 on; u8 pad2[74]; };
struct BlkW55 { BlkW55* next; s32 count; ItemW55* items; };
struct FpW55 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; } __attribute__((aligned(16)));
typedef void (*CbW55)(u8*, u32);

extern "C" {
void func_0016bd60(u32, s32);
extern u64 D_0036a938;
void func_00138698(u32, u32);
u32 func_0013a800(void);
void func_0013d4c8(void);
u32 func_0013a810(void);
u32 func_0013cb80(void);  // get_global_358050
void func_001387f8(u32, u32, u32, u32);
void func_0013b2d8(f32);
extern u32 D_00348050;
extern u8* D_003484a0;
extern u32 D_00348578[2];
s32 func_0015ce80(void);
void func_0015ceb8(Q16*);
void func_0015cea0(Q16*);
f32 func_0015ced0(void);
f32 func_0015cee0(void);
void func_0015ce90(void);  // zero_global_byte_g
void func_0014fcd8(u8*);
s32 func_00139d78(void*);
void func_00151c70(u8*);
void func_00138c40(u8*, u32, u32);
void func_001519f8(u8*);
void func_001904a8(void*, void*);
extern u8 D_0034aa70[];
void func_0015a260(u8*, void*, f32);
u32 func_00167f18(s32);
void func_0015a158(u32, u8*);
void func_0015a528(u8*);
void func_0014c738(u8*);
void func_0014c350(u8*);
u32 func_001b9bc8(u32);
s32 func_0016a040(u32);
void func_0016c568(u32, u32, f32);
u32 func_0014aba8(void);
void func_0014aa80(u32, s32, s32);
void func_001ada38(s32);
void func_00177710(void);
extern u8 D_0032bb30[];
u8 func_0016c008(u32, s32);
s32 func_0016a070(u32);
s32 func_0016a020(u32);
void func_00253180(s32, s32);
extern s8 D_01c60500;
extern V4 D_01c60510;
void func_0017bef8(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
s32 func_00180cd0(u8*);
s32 func_00196618(u32, u32, s32);
u32 func_001d52c0(u32, u32);
s32 func_00192048(u32);
void func_00226da8(u8*);
void func_0014c9f0(s32);
void func_001c11a8(s32);
void func_001384a0(s32);
void func_002bc798(void);
void func_002ba610(void);  // zero_global_byte_1e3
extern u32 D_0035037c;
u8* func_0016e920(u32);
void func_001a78c0(u8*, u32, s32, f32, f32, f32, f32);
void func_001a7888(u8*, u32, s32, f32, f32, f32, f32);
extern DeadRingW55 D_01c6cb00;
void func_001dc978(void*, f32);
void func_001c79a0(u32, u32, s32);
void func_001a52a8(u32, u32, u32);
s32 func_001d22a8(u32);
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
extern u8 D_00350af0[];
extern u8* D_01d48c80;
void func_001b2488(u8*);
void func_00105110(void*);
extern u32 D_01d49320;
void func_001bbe18(u32);
void func_001d5518(u8*, u8*, s32);
void func_001bb890(void);
s32 func_001bb7f8(void);
void func_001bc0d0(u8*);
void func_001bbc30(void);
u8* func_001a80c8(u32);  // table24_find_by_id
extern EntW55 D_0036dcf8[];
void* func_001050d8(u32);
void func_001bf270(void*, u8*, u32, u32, f32);
s32 func_001bc010(void);
u32 func_0017df58(s32);
s32 func_0019ba60(u32);
s32 func_0017e3b8(u32);
extern void* D_01d5ba10[];
s32 func_001d3558(void*, void*);
void* func_001d3498(void*, void*);
extern u32 D_01d9eaa0;
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
void func_0024ec50(void);
extern u8* D_0035ee04;
extern void* D_0035ee08;
extern void* D_0035ee10;
void func_0024eb50(void);
void func_0024f2d0(void);
void func_001039f8(void);
u32 func_00259460(u32, u8);
void func_002595b8(u32, u32, u8);
s32 func_00287bc0(void);
s32 func_00253578(void);  // get_global_36ee90
s32 func_002637e8(s32);
bool func_002577b0(void);
bool func_0027b528(void);
s32 func_0028be58(void*);
extern void* D_0035f04c;
extern u8* D_0035f01c;
void func_0029df98(void);
void func_0029e050(void);
void func_0029e258(s32);
extern u8* D_0035f610;
void func_001bc778(u8*);
s32 func_00190140(u8*);
u8* func_001bc780(u8*, s32, s32, s32);
void func_00178888(u8*);
u32 func_002d1260(void);
s32 func_002d5c40(u32);
void func_002d3fa8(Q16*, u32, u32);
u32 func_002e64b0(u32);
HeapW55* func_001050c8(void);
void func_002edf28(u8*);  // obj_ctor_3637e0
void func_001ad330(u8*, s32);
extern u8 D_00363828[];
u32 func_0010c7e8(u32);
void func_0011a900(Q16*, u32);
extern Q16 D_01e2c0c0;
s32 strcmp(const char*, const char*);  // strcmp
extern char D_00377cf8[];
extern char D_00377cc0[];
void func_003147a0(void*, FpW55*);
FpW55* func_00313c58(FpW55*, FpW55*, FpW55*);
double func_003146c8(FpW55*);
extern u8 D_0034a800[];
extern u8 D_00348608[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_002361d0(u8*);
void func_00239870(u8*);
}

void wtarget_0010f918(u32, u32, u32, u32) asm("_Z16wtarget_0010f918jjjj");
void wtarget_0016c5b8(u32, u32, u32, u32) asm("_Z16wtarget_0016c5b8jjjj");
Q16* ctarget_0017a968(Q16*) asm("_Z16ctarget_0017a968jjjj");
u32 ctarget_00180618(u8*) asm("_Z16ctarget_00180618jjjj");
void AddDeadEffect(void*) asm("_ZN2YS6EFFECT13AddDeadEffectEPN3ryj6EFFECTE");
void MissionFailed(void) asm("_ZN2YS7MISSION6FailedEv");
s32 Select_isCreated(u8*) asm("_ZN2Tz6Select9isCreatedEz");
s32 wtarget_002e3418(u32, u32, u32, u32) asm("_Z16wtarget_002e3418jjjj");
void TutorialWidgetCtor(u8*, s32) asm("_ZN4menu14TutorialWidgetC1Ei");
const char* wtarget_00303728(u32, u32, u32, u32) asm("_Z16wtarget_00303728jjjj");

// Clears bit 14 of the flags word unless the target kind is 32.
void wtarget_0010f918(u32 a, u32, u32, u32);  // 0x0010f918: definition moved into src/anon/unit_0010f338.cpp

extern "C" {

// Shifts packed nibbles up: whole 64-bit words, then the leftover bytes.
void func_0011f120(void* o, u8* p);  // 0x0011f120: definition moved into src/anon/unit_0011c128.cpp

// Wraps an angle into [-pi, pi].
f32 func_00127de8(f32 a);  // 0x00127de8: definition moved into src/anon/unit_00127a88.cpp

// Walks the list from a (up to b) and returns the first node whose virtual test accepts.
void* func_00132390(void* a, void* b, u32 c, u32 d, u32 e) {
    for (; a && a != b; a = *(void**)((u8*)a + 28)) {
        if ((*(s32 (**)(void*, u32, u32, u32))(*(u8**)a + 12))(a, c, d, e)) return a;
    }
    return 0;
}

void func_0013d620(void);  // 0x0013d620: definition moved into src/anon/unit_0013a8b8.cpp

void func_001407d0(u8* p);  // 0x001407d0: definition moved into src/anon/unit_0013fca8.cpp

void func_00151aa8(u8* p);  // 0x00151aa8: definition moved into src/anon/unit_0014ecb8.cpp

// 0015a5a8: moved to src/harata/libdk/targetcamera.cpp

static inline void vcall8(u8* o) { (*(void (**)(void*))(*(u8**)o + 8))(o); }

// 0015d828: moved to src/anon/unit_0015d828.cpp

}

void wtarget_0016c5b8(u32 a, u32 b, u32, u32) {
    u32 i = 0;
    while ((i = func_001b9bc8(i)) != 0) {
        if ((1 << func_0016a040(i)) & b) func_0016c568(i, a, 0.0f);
    }
}

extern "C" {

// 0016df70: moved to src/anon/unit_0016d2e0.cpp

// 00179648: moved to src/yasui/libys/player.cpp

}

// 0017a968: moved to src/anon/unit_0017a8f8.cpp

// 00180618: moved to src/anon/unit_00180408.cpp

extern "C" {

s32 func_001967f0(u32 a, u32 b, s32 c);  // 0x001967f0: definition moved into src/anon/unit_00195d00.cpp

void func_00196d78(u8* p);  // 0x00196d78: definition moved into src/anon/unit_00195d00.cpp

u8* func_0019b0e8(u8* a, u32 b, u32 c, f32 f, f32 g);  // 0x0019b0e8: definition moved into src/anon/unit_00199688.cpp

}

// Keeps the last four dead effects; the oldest is released when replaced.
// 001a3ce0: moved to src/yasui/libys/effect.cpp

extern "C" {

// 001a53d0: moved to src/anon/unit_001a4db0.cpp

// 001a8190: moved to src/anon/unit_001a8098.cpp

// 001ad228: moved to src/anon/unit_001abb28.cpp

// Destroys and frees every node of the list.
// 001b24c8: moved to src/anon/unit_001b1d20.cpp

}

#define MISSION_W55 ((u8*)D_01d49320)
// 001bb768: moved to src/yasui/libys/mission.cpp

extern "C" {

void* func_001bf620(u32 a, u32 b);  // 0x001bf620: definition moved into src/anon/unit_001bc568.cpp

s32 func_001c9ab8(void);  // 0x001c9ab8: definition moved into src/yasui/libys/sacrifice.cpp

void func_001d2690(RingW55* r, u32 b, f32 f);  // 0x001d2690: definition moved into src/anon/unit_001d14e0.cpp

// 001d34d0: moved to src/anon/unit_001d30b0.cpp

void func_001e9078(u8* a, u8* b, u8* c);  // 0x001e9078: definition moved into src/anon/unit_001e8ac8.cpp

// Sum of two VU0 randoms, or twice one.
f32 func_001eeb90(u8 a);  // 0x001eeb90: definition moved into src/anon/unit_001ec098.cpp

s32 func_0024ebc0(void);  // 0x0024ebc0: definition moved into src/anon/unit_0024e7e8.cpp

void func_00259570(u32 a, u32 b, u8 c, u8 d);  // 0x00259570: definition moved into src/anon/unit_002588e8.cpp

s32 func_0025d620(s32 a);  // 0x0025d620: definition moved into src/anon/unit_002588e8.cpp

s32 func_002638e0(s32 a);  // 0x002638e0: definition moved into src/anon/unit_002632d0.cpp

bool func_0027a908(u8 a);  // 0x0027a908: definition moved into src/anon/unit_0027a6d8.cpp

}

s32 Select_isCreated(u8* s);  // 0x0028acc8: definition moved into src/anon/unit_00288b00.cpp

extern "C" {

void func_0029aa30(void);  // 0x0029aa30: definition moved into src/anon/unit_00299920.cpp

// Tests flag n, or whether any of the 96 flags is set when n is negative.
s32 func_002ab100(s32 n);  // 0x002ab100: definition moved into src/anon/unit_002a99c8.cpp

void func_002c5900(u8* p);  // 0x002c5900: definition moved into src/anon/unit_002c53c8.cpp

Q16* func_002d2870(Q16* out, u8* b, u32 c);  // 0x002d2870: definition moved into src/anon/unit_002d2498.cpp

}

// Looks up the value stored for the key pair (b, c) in the section of kind d.
// 002e3418: moved to src/anon/unit_002e2f08.cpp

extern "C" {

void func_002e6fc0(u32* p, u32 b) {
    p[0] = b;
    p[1] = 0;
    u32 n = func_002e64b0(b);
    p[2] = n;
    p[1] = (u32) new (func_001050c8()) ElemW55[n];
}

}

// 002ee5d8: moved to src/menu/tutorial_widget.cpp

extern "C" {

// 002f07f8: moved to src/naka/libkn/trapfunctions.cpp

// ORs fn() over every active item of every block in the chain.
u32 func_00303698(u8* p, u32 (*fn)(ItemW55*)) {
    u32 r = 0;
    BlkW55* b;
    for (b = (BlkW55*)(p + 472); b; b = b->next) {
        s32 i = b->count;
        ItemW55* it = b->items;
        while (--i >= 0) {
            if (it->on) r |= fn(it);
            it++;
        }
    }
    return r;
}

}

const char* wtarget_00303728(u32 a, u32 b, u32 c, u32) {
    const char* s = (const char*)c;
    if (s) {
        if (strcmp(s, D_00377cf8) && strcmp(s, D_00377cc0)) return 0;
        *(u32*)(a + 48) = b;
        *(u32*)(a + 52) = c;
    }
    return D_00377cf8;
}

extern "C" {

// Soft-float binary op: unpack both doubles, combine, pack.
double func_00313e80(double a, double b) {  // double_div
    FpW55 x, y, t;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_00313c58(&x, &y, &t));
}

void func_0031b5c8(u8* p) {
    *(u32*)p = (u32)D_00348608;
    *(u32*)(p + 64) = (u32)D_0034a800;
    func_002361d0(p + 480);
    *(u32*)(p + 64) = (u32)D_00347e60;
    func_00239870(p + 88);
    *(u32*)(p + 64) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* o = *(u8**)(D_00347f80 + 20);
    (*(void (**)(void*, u8*))(*(u8**)o + 4))(o, p);
}

}
