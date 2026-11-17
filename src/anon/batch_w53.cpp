#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Local with a non-trivial destructor: keeps the final call a jal instead of a sibcall.
struct NoTail { ~NoTail() {} };

struct Slot88 { u32 f0; u32 key; u32 pad8[2]; u32 f16; u8 pad20[60]; u32 f80; u32 f84; };
struct Node12 { u32 pad[3]; Node12* next; };
struct Pair { u32 a; u32 b; };
struct S349 { u8 pad[736]; u8 a[16]; u8 b[480]; u8 c; };
struct E16 { u32 a; u32 b; u32 c; u8* obj; };

typedef void (*Fn0)(u8*);
typedef void (*Fn1)(void*, void*);
typedef void (*Fn3)(u32, u32, u32);
typedef u32 (*Fn8)(u8*, u32, u32, u32, u32, u32, u8, u32);
typedef void* (*AllocFn)(void*, u32, u32);
typedef void (*VFn)(u8*);
typedef void (*VFn0)(void);
struct Blk { Blk* next; s32 n; VFn0 fns[1]; };

extern "C" {
void wtarget_0011e9a8(u32, u32, u32, u32, f32) asm("_Z16wtarget_0011e9a8jjjj");
void func_0014e1f0(s32, s32) asm("_Z13func_0014e1f0ii");
void ctarget0_00187b90(u8*) asm("_Z17ctarget0_00187b90v");

extern u32 D_0033cc60;
extern u32 D_0033cc68;
extern Slot88* D_0033cc6c;
extern s32 D_00348704;
extern S349 D_00349f00;
extern f32 D_00349e10;
extern u32 D_0034f240;
extern u32 D_01c61960;
extern f32 D_01c6195c;
extern f32 D_01c61964;
extern u8* D_01c6cb20;
extern u32 D_01d49328[];
extern s32 D_01d49348;
extern volatile u32 D_01dae6a0;
extern u32 D_0035ecac;
extern u32 D_0035ecb0;
extern u32 D_0035ecb4;
extern u32 D_0035ee58;
extern u32 D_0035ee7c;
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00372650[];
extern s8 D_00372958[];
extern u8* D_00361e00;
extern u8* D_00347f80;
extern u32 D_00361f60;
extern u8 D_00362908[];
extern f32 D_00363440;
extern u8* D_00365c48;

void func_0011e350(u8*, u32);
void func_0011c438(u8*);
void* func_0011e7e0(u32, void*, u32, u32, u32);
void func_00132370(void*, f32);
u8* func_00124748(u32, u32);  // list_nth_node_rel
void func_00239988(u8*);
void func_00138c10(u8*, u32);
void func_0013f230(void);
void func_0015d540(void);
void func_0013f378(void);
void func_0013f498(void);
void func_0014df88(void);
void func_0014e0d8(void);
u8* func_0014aba8(void);
void func_0014aa58(u8*, u32, u32);
void func_00102448(u8*, u32);
u8* func_00103070(void);
void func_00166930(u8*);
void func_0014dc08(u8*);
void func_0014dd10(u8*);
u32 func_001050c8(void);
u32 func_00190140(u8*);
void func_00190f80(u8*, u8*, f32);
void func_0019ca90(u32, u32, u8*);
void func_0019d358(u32);
void func_00184540(Q16*, u8*);
f32 func_0017c930(u8*, u8*);
u32 func_00187ab8(u32);
void func_0031cc28(u32*);
void func_00191938(u32);
void func_00191bf0(f32);
u32 func_0019ba60(u8*);
void func_0016bd60(u8*, u32);
void func_0017f540(u8*, u32, f32, f32);
void func_001c39d0(u8*, u8*);
void func_001c6320(void);
void func_00224828(s32);
void func_0022afe8(s32);
s32 func_001319d8(s32, f32);
s32 func_00105c30(void);
u32 func_002891e8(u32);
s32 func_00252110(u32);
void func_0028dac8(u32, s32);
s32 func_00287bc0(void);
u32 func_00139d78(u8*);
void func_00239bf8(u32, u32);
u32 func_001708f8(u32, s32);
void func_00290960(u8*, u32, u32);
u32 func_002cab58(u32);
void func_002c9f20(u8*);
void func_002c90c8(void*, u32);
u8* func_00102c80(void);
u8* func_00102788(u32, u32, u32, u32);
void func_002cfeb0(u8*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002e7308(u8*);
void func_002def70(u8*);
u8* func_002dc7c8(u32);
void func_002deac0(u8*, f32, f32);  // set_float24_scaled
void func_002deba0(u8*, u32, f32, f32);
void func_001002a0(s32) __attribute__((noreturn));

// Find the first free slot whose key matches the current key and clear it.
Slot88* func_00109c30(void);  // 00109c30: moved to src/anon/unit_00109c30.cpp

// Release the pending entry and every node of the list through the owner's vtable slot 1.
void func_0011c3b0(u8* p);  // 0x0011c3b0: definition moved into src/anon/unit_0011c128.cpp

void wtarget_0011e9a8(u32 a, u32 b, u32 c, u32 d, f32 x);  // 0x0011e9a8: definition moved into src/anon/unit_0011c128.cpp

u32 func_00124578(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u8 t2, u32 t3);  // 0x00124578: definition moved into src/anon/unit_00123990.cpp

void func_001387f8(u8* p, u32 a1, u32 a2, u32 a3);  // 0x001387f8: definition moved into src/anon/unit_00138480.cpp

void func_0013f050(s32 a);  // 0x0013f050: definition moved into src/anon/unit_0013ef70.cpp

static inline bool ready_14a0a0() { return *(u32*)(func_0014aba8() + 252) == 4; }
void func_0014a0a0(u8* p);  // 0014a0a0: moved to src/anon/unit_00149fa8.cpp

// 0014e1f0: moved to src/anon/unit_0014d680.cpp

// Split a gauge into segments: *outB = size per segment, *outA = fill of the current one.
// 001560a8: moved to src/anon/unit_00153ea0.cpp
u8 func_001560a8(u8* o, s32* outA, s32* outB);

void func_0016c358(u8* p) {
    if (*(u32*)(p + 2224)) {
        u32 v = func_001050c8();
        u32 o = *(u32*)(p + 2224);
        (*(Fn3*)(**(u8***)(p + 2224) + 40))(o, v, *(u32*)(p + 1648));
        *(u32*)(p + 2224) = 0;
    }
}

// 0017a600: moved to src/yasui/libys/player.cpp

// 0017c870: moved to src/anon/unit_0017c400.cpp

// Push a new entry onto the 16-slot ring buffer at +8.
// 001882a8: moved to src/anon/unit_00185d10.cpp
void func_001882a8(u8* p);

// 00191758: moved to src/yasui/libys/status.cpp

// Add d to a 0..99 sub-counter at +432, carrying into the level at +433 (capped by +434).
void func_001a1aa0(u8* p, s32 d);  // 0x001a1aa0: definition moved into src/anon/unit_0019fb70.cpp

// 001a6850: moved to src/yasui/libys/magic.cpp

// Allocate an id 1..255 from a 256-bit bitmap, round-robin.
u32 func_001bffd8(void);  // 0x001bffd8: definition moved into src/anon/unit_001bff88.cpp

void func_001c3aa0(u8* a, u8* b);  // 0x001c3aa0: definition moved into src/anon/unit_001c2b58.cpp

// VU0 vector scale (v * 30) into p+64.
void func_001c6400(u8* p, Q16* v);  // 0x001c6400: definition moved into src/anon/unit_001c5b90.cpp

void func_0022afa0(s32 a);  // 0022afa0: moved to src/sasa/musical_input.cpp (linked unit)

void func_002368e8(u8* p, f32 x);  // 0x002368e8: definition moved into src/anon/unit_00236180.cpp

u32 func_002402e0(void) {
    switch (func_00105c30()) {
    case 1:
    case 8:
        D_01dae6a0 = D_0035ecac;
        break;
    case 2:
        D_01dae6a0 = D_0035ecb0;
        break;
    default:
        D_01dae6a0 = D_0035ecb4;
        break;
    }
    return D_01dae6a0;
}

void func_00252618(void);  // 0x00252618: definition moved into src/anon/unit_00250fb8.cpp

// Look the current id up in a -1 terminated table.
void func_00258080(s32* a, s32* b) {
    s32 v = func_00287bc0();
    bool found = false;
    for (s32 i = 0; D_00372958[i] >= 0; i++) {
        if (v == D_00372958[i]) {
            found = true;
            break;
        }
    }
    if (!found) {
        *a = 25;
        *b = 23;
    } else {
        *a = 22;
        *b = 21;
    }
}

void func_0028e438(u8* p, s32 i, u32 v, u32 w);  // 0028e438: moved to src/anon/unit_0028c878.cpp

void func_00290a10(u8* p, u32 a, u32 b);  // 00290a10: moved to src/anon/unit_0028f1e0.cpp

void func_002ca010(u32 a);  // 0x2ca010: moved to src/anon/unit_002c9998.cpp


void func_002cedd0(s32 n, E16* e);  // 002cedd0: moved to src/taito/minigame_base.cpp (linked unit)

// Wrap an angle into [-pi, pi].
f32 func_002d48b8(f32 x);  // 0x002d48b8: definition moved into src/anon/unit_002d4548.cpp

void func_002db808(u8* p, u32 a, u32 b);  // 0x002db808: definition moved into src/anon/unit_002da040.cpp

void func_002df7d8(u8* p, u32 b);  // 0x002df7d8: definition moved into src/anon/unit_002de3c8.cpp

// Returns (o+16) scaled by D_00363440 (VU0).
Q16* func_002eaba8(Q16* ret, u32, u8* o);  // 002eaba8: moved to src/anon/unit_002eaa68.cpp

// Run all registered exit handlers (newest first), then the final hook, then exit.
void func_002fd348(s32 code) {
    for (Blk* b = *(Blk**)(D_00365c48 + 328); b; b = b->next) {
        s32 i = b->n;
        while (--i >= 0) b->fns[i]();
    }
    VFn f = *(VFn*)(D_00365c48 + 60);
    if (f) f(D_00365c48);
    func_001002a0(code);
}
}
