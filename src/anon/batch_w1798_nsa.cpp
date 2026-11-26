#include "../common/types.h"
// Built with -fno-strict-aliasing (the *_nsa rule in the Makefile).

struct Ent_2bf468 { s32 id; u8 b4; u8 pad[3]; };
struct Sub_2bf468 { u8 a, b, c; };
struct Obj_2bf468 {
    void* vt;           // 0x000
    u8 p0[0x584];
    u32 flags;          // 0x588
    u8 p1[0xAE4 - 0x58C];
    Sub_2bf468 sub;     // 0xAE4
    u8 ae7;             // 0xAE7
    u8 p2[8];
    f32 af0;            // 0xAF0
    f32 af4;            // 0xAF4
    Ent_2bf468* ent;    // 0xAF8
    s32 afc, b00, b04, b08;
};
extern u8 D_003619c8[];
extern Ent_2bf468 D_00375420[];

struct Node_165898 { s32 a, b; u8 c[8]; };
struct Pool_165898 { Node_165898 n[64]; s32 idx[64]; s32 cnt; };
struct Pair_165898 { s32 a, b; };

extern "C" {
void func_002be770(Obj_2bf468*);
s32 func_001b6d70(u8);
void worldmap__Symbol__setState(Obj_2bf468*, s32);

void func_002bf468(Obj_2bf468* p, s32* key);  // 0x002bf468: definition moved into src/anon/unit_002bebd0.cpp

void* tz_alloc_165898(u32, u32) asm("_ZN2Tz13LoadDataAllocEjj");
void lst_165898(void*) asm("_Z13func_0031a830Pv");
extern Pair_165898 D_004f41c0;
extern s32 D_0034c7a4;
extern Pool_165898* D_0034c7a0;

void func_00165898(u32 arg);  // 0x00165898: definition moved into src/anon/unit_001656b8.cpp
}
