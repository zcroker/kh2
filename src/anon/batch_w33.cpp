#include "../common/types.h"

extern "C" {

struct NoTail { ~NoTail() {} };

struct KeyVal { s16 key; s16 val; };
extern KeyVal D_00369da8[];
s32 lookup_001033d8(void* k) asm("_Z13func_001033d8Pv");
// 001033d8: moved to src/common/unit_001031b0.cpp

struct Buf256 { u8 b[256]; };
extern Buf256 D_003a7b70[];
extern Buf256 D_003a7d70[];
extern s32 D_0033cc40;
extern u8 D_0033cc44;
// 00106a18: moved to src/naka/libkn/camera.cpp

extern u32 D_003a99f0[];
struct Obj148 { u8 pad[287]; u8 slot; };
// Put o into the first free slot at or after its preferred index; bump the owner's count.
void func_00148a68(s32* owner, Obj148* o);  // 0x00148a68: definition moved into src/anon/unit_00147140.cpp

u8 func_00242d58(void);
u32 func_00242ce8(void);
extern u64 D_0034a970[];
// 001584a0, 001584f8: moved to src/harata/libdk/cameraconfig.cpp

void* func_00167f18(s32);
// 0016dbe0: moved to src/anon/unit_0016d2e0.cpp

struct Lim177 { u8 pad[45]; s8 max; };
struct Obj177 { u8 pad[2820]; u8 n; };
Lim177* func_00177860(Obj177*);
// 00177bf8: moved to src/yasui/libys/party.cpp

struct Cfg17d { u8 pad[88]; f32 scale; };
extern Cfg17d* D_00352130;
struct Val17d { s32 a; s32 b; };
struct Obj17d { void** vt; u8 pad[1160]; Val17d* v; };
// 0017de70: moved to src/yasui/libys/friend.cpp

struct Node17f { u8 pad[60]; s32 a; s32 b; u8 pad2[148 - 68]; Node17f* child; u8 pad3[4]; Node17f* next; };
// 0017f380: moved to src/yasui/libys/motion.cpp

s32 func_00181500(void*);
void func_00181178(void*);
// 00181570: moved to src/yasui/libys/progress.cpp

struct Sub1a2 { u8 pad[10]; u8 v; };
struct Obj1a2 { u8 pad[394]; u16 a; u8 pad2[6]; u16 b; u8 pad3[580 - 404]; Sub1a2* s; };
// Add n to two counters, and to a sub-value capped at 100.
void func_001a25c8(Obj1a2* o, s32 n);  // 0x001a25c8: definition moved into src/anon/unit_0019fb70.cpp

struct Ent1a8 { u16 id; u16 pad; u8 type; u8 pad2[7]; };
struct Tbl1a8 { u16 pad; u16 count; Ent1a8 e[1]; };
extern Tbl1a8* D_01c6cb98;
// 001a8258: moved to src/anon/unit_001a8098.cpp

void func_00239bf8(u8*, u32);
void wtarget_001ac078(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001ac078jjjj");
// 001ac078: moved to src/anon/unit_001abb28.cpp

struct St32 { u8 pad[13604]; u8 a; u8 b; };
extern St32 D_0032bb30;
void* func_001a15d0(s32, s32);
void func_001a1c70(void*);
void func_001a17c8(void*);
void func_001adbc0(void);  // 0x001adbc0: definition moved into src/anon/unit_001ada38.cpp

extern void* D_00350dec;
void* func_001708f8(void*, s32);
void* func_001af7c0(void*, void*);
struct Obj1af { u8 pad[4]; void* a; u8 pad2[40]; void* b; void* c; };
void func_001af778(Obj1af* o);  // 0x001af778: definition moved into src/anon/unit_001ada38.cpp

struct Obj1b4 { u8 pad[64]; u32 flags; };
extern Obj1b4* D_01d48cb0;
void func_001b5460(Obj1b4*);
void func_001b4f40(Obj1b4*);
void func_00105110(void*);
// Destroy and free the singleton at D_01d48cb0.
void func_001b43e0(void);  // 0x001b43e0: definition moved into src/anon/unit_001b2780.cpp
void u_call0_001b5400(void) asm("_Z16u_call0_001b5400v");
void u_call0_001b5400(void);  // 0x001b5400: definition moved into src/anon/unit_001b2780.cpp

s32 func_001dc738(void*);  // state_gate_flags
s32 func_001dc790(u32* p);  // 0x001dc790: definition moved into src/anon/unit_001dbfd8.cpp

// VU0 random: five vrnext steps seeded with -1, plus 1.0 (hand-written VU0 macro code).
f32 func_00203a40(void);  // 0x00203a40: definition moved into src/anon/unit_002039c0.cpp

struct A207 { u8 pad[16]; s32 a; s32 b; s32 c; };
struct B207 { u8 pad[257]; u8 x; u8 pad2[4]; u8 y; };
s32 func_00207308(A207* a, B207* b);  // 0x00207308: definition moved into src/anon/unit_00206be8.cpp

struct Ev234 { s32 type; s32 id; u32 a, b, c, d; u32 pad[2]; };
extern Ev234 D_01dadc00[];
extern s32 D_0035e360;
extern s32 D_0035e368;
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00234298jjjj");
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d);  // 0x00234298: definition moved into src/anon/unit_002335e8.cpp

struct Slot236 { u8 used; u8 pad[3]; s32 a; s32 b; s32 pad2; s32 x; s32 y; };
extern Slot236 D_0035e440[];
extern s32 D_0035ea40;
void init_00236d10(void*) asm("_Z13func_00236d10Pv");
void init_00236d10(void*);  // 0x00236d10: definition moved into src/anon/unit_00236180.cpp

void func_00242408(void);  // set_global_crc_m1
u32 func_00242418(void*, u32);  // crc_byte_update
extern void* D_0035ec90;
s32 func_00241670(void* a);  // 0x00241670: definition moved into src/anon/unit_0023f5b8.cpp

struct Bits242 { u32 pad; u32 lo : 6; u32 off : 1; };
void* func_001058e8(void);
void func_00242ca0(u8 on);  // 0x00242ca0: definition moved into src/anon/unit_00242478.cpp

struct Pad267 { u8 pad[28]; u16 mask; };
extern Pad267* D_0035f0e4;
// Index among the set bits of a 10-bit mask: how many set bits precede bit n (-1 if none).
s32 func_002670f8(s32 n);  // 0x002670f8: definition moved into src/anon/unit_00265580.cpp

void func_00257708(s32);
extern s32* D_0035f2b4;
void func_00283d00(void*);
void func_00283f50(void);
void func_002833f8(void);
void func_002831e0(void* a, s32 b);  // 0x002831e0: definition moved into src/anon/unit_00282c68.cpp

extern u8 D_003617e8;
extern s32 D_003617e4;
void func_002b8434(s32);
void ResetPauseImpl_002bd6d0(void) asm("_ZN2Tz9MenuSound14ResetPauseImplEv");
void ResetPauseImpl_002bd6d0(void);  // 0x002bd6d0: definition moved into src/anon/unit_002bc978.cpp

extern void* D_00362908[];
void func_002e7328(void*);  // to_2e7458
void func_002cff98(void*);
void func_002db928(u8* p);  // 0x002db928: definition moved into src/anon/unit_002da040.cpp

extern void* D_00361f60;
void func_002cf280(void*, s32, s32);
u8* func_002dc7c8(void*);
void func_002de698(u8* p);  // 0x002de698: definition moved into src/anon/unit_002de3c8.cpp

struct Own2e8 { u8 pad[4]; void* h; };
struct Obj2e8 { Own2e8* o; void* v; f32 a; f32 b; };
void func_001b2210(void*, void*, f32, f32);
void func_0016bd60(void*, s32);
void func_002e8390(Obj2e8* o);  // 0x002e8390: definition moved into src/anon/unit_002e7b10.cpp

void func_001c23a8(void*, void*, s32, s32, s32, s32, void*);
extern void* D_00363758[];
extern void* D_00363748;
void func_002ed300(void** p, void* a, void* b);  // 0x002ed300: definition moved into src/anon/unit_002ecdb0.cpp

s32 func_00105c30(void);
// Region code from the build/region id: 'SU', 'JP' or 'EU'.
// 002ef988: moved to src/anon/unit_002ef938.cpp

const u8* func_00316f70(const u8* p, s64* out);  // 0x00316f70: definition moved into src/libgcc/unwind-dw2.c

struct VObj31d { void** vt; };
struct Mgr31d { u8 pad[20]; VObj31d* o; };
extern void* D_00347f80;
extern void* D_00347f98[];
void func_0031d7c0(void** p) {
    *p = D_00347f98;
    VObj31d* o = ((Mgr31d*)D_00347f80)->o;
    ((void (*)(VObj31d*, void*))o->vt[1])(o, p);
}

extern void* D_0034ee08[];
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00324980(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}


}
