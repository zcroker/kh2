#include "../common/types.h"

// YS::SHEET-like status sheet (src/yasui/libys/sheet.*). Only the fields used here.
struct W1635SheetData;
struct W1635Obj;

struct W1635Gauge {
    s32 cur;               // +0
    s32 max;               // +4
    s32 x8;                // +8
};

struct W1635FormInfo {
    u8 pad0[4];
    u8 str, mag, def;      // 0x4..0x6
};

struct W1635Drive {
    u8 pad0[0x1038];
    u8 c[4];               // 0x1038
    f32 f0, f1;            // 0x103c
};

union W1635Int { s32 v; f32 f; };

struct W1635Sheet {
    W1635Gauge g[1];       // 0x000 hp/maxhp/..., 12-byte entries indexed by the caller
    u8 pad0c[0x180 - 0xc];
    s32 x180;              // 0x180
    s32 x184;              // 0x184
    u16 stat[4];           // 0x188
    u16 stat2[4];          // 0x190
    s32 lo;                // 0x198 upper clamp source
    s32 hi;                // 0x19c lower clamp source
    s32 x1a0;              // 0x1a0
    s32 x1a4;              // 0x1a4
    u8 rate[7];            // 0x1a8 percentages (reset to 100)
    u8 pad1af;
    u8 c[4];               // 0x1b0
    f32 f1b4, f1b8;        // 0x1b4
    f32 f1bc, f1c0;        // 0x1bc
    u8 pad1c4[0x1cc - 0x1c4];
    u8 sub[0x1fc - 0x1cc]; // 0x1cc
    u8 b1fc;               // 0x1fc
    u8 pad1fd[0x240 - 0x1fd];
    f32 f240;              // 0x240
    W1635SheetData* data;  // 0x244
    u16* extra;            // 0x248
    u8 pad24c[0x254 - 0x24c];
    s32 form;              // 0x254
    u8 pad258[0x25c - 0x258];
    W1635Obj* owner;       // 0x25c
    W1635Drive* drive;     // 0x260
};

struct W1635SheetData {
    u16 ability[2];        // 0x00
    u8 b4, b5, b6, b7;     // 0x04
    u8 b8, b9, b10, b11;   // 0x08
    u8 b12, b13, b14, b15; // 0x0c
    u8 n10, n11;           // 0x10
    u8 pad12[2];
    u16 list10[8];         // 0x14
    u16 list11[8];         // 0x24
};

struct W1635Obj {
    u8 pad0[0x48c];
    W1635Sheet* sheet;     // 0x48c
    u8 pad490[0x588 - 0x490];
    u32 flags;             // 0x588
    u8 pad58c[0xb50 - 0x58c];
    s32 xb50;              // 0xb50
};

struct W1635Attack {
    u8 pad0[8];
    s32 x8;                // 0x8
    W1635Obj* obj;         // 0xc
};

struct W1635AttackData {
    u8 pad0[4];
    u8 type;               // 0x4
    u8 kind;               // 0x5
    u16 power;             // 0x6
    u8 pad8;
    u8 elem;               // 0x9
};

struct W1635Default {
    u8 pad0[2];
    u16 v;                 // 0x2
    u8 pad4[2];
    u16 lo;                // 0x6
    u16 hi;                // 0x8
};

struct W1635Info {
    u8 pad0[0x52];
    u16 bonus;             // 0x52
};

struct W1635Param {
    u8 pad0[0x94];
    f32 f94;               // 0x94
    u8 pad98[0x178 - 0x98];
    s32 x178;              // 0x178
};

extern "C" {
W1635FormInfo* YS__LEVELUP__Get(s32, u8);
s32 func_001b73e8(W1635FormInfo*, s32);
void func_001c2f90(void*, W1635Sheet*);
void YS__ABILITY__check(void*);
void func_001a24a0(W1635Sheet*, u16);
extern W1635Int D_01c6cabc;
extern W1635Param* D_00352130;
W1635Info* func_00177860(W1635Obj*);
s32 YS__OBJ__is_exist(W1635Obj*);
s32 YS__SHEET__is_mpdrive(W1635Sheet*);
s32 func_001a2108(W1635Sheet*, s32, s32);
s32 func_001a2200(W1635Sheet*, s32);
s32 func_001a22b0(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*);
s32 func_001a2340(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*);
s32 func_001a2478(W1635Sheet*);
// pure: keeps the call heuristic from marking the fallback path as unlikely
W1635Default* func_001c0cc8(void) __attribute__((pure));

// Set the sheet up from its data record (null = keep the current one).
void YS__SHEET__load(W1635Sheet* s, W1635SheetData* d);  // 0x001a11e0: definition moved into src/anon/unit_0019fb70.cpp

static inline bool W1635_is6(W1635Obj* o) { return o->xb50 == 6; }

// Damage/amount for an attack against this sheet (idx picks the gauge used for the low-gauge bonus).
s32 func_001a1e20(W1635Sheet* s, W1635Attack* a, W1635AttackData* ad, s32 idx);  // 0x001a1e20: definition moved into src/anon/unit_0019fb70.cpp
}
