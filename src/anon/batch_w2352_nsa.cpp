/* batch w2352, built with -fno-strict-aliasing (_nsa). */
#include "../common/types.h"

struct Ent { u8 pad[0x28]; u16 id; };
struct Res { u8 pad[8]; s32 v; };
struct Sub {
    u32 vt;
    s32 f4, f8, fc, f10, f14, f18, f1c;
};
struct Obj {
    Ent* ent;       /* 0x00 */
    s32 h;          /* 0x04 */
    s32 f8;         /* 0x08 */
    u8 pad0c[0x0c];
    u8 s18[0x1c];   /* 0x18 */
    s32 f34;        /* 0x34 */
    u8 pad38[0x0c];
    Sub* psub;      /* 0x44 */
    Sub sub;        /* 0x48 */
    u8 s68[4];      /* 0x68 */
    u8 s6c[0x3c];   /* 0x6c */
    u8 sa8[4];      /* 0xa8 */
    u8 sac[4];      /* 0xac */
};

extern "C" {
extern u8 D_00350e48[];
extern u8 D_0036da78[];
extern u8 D_0036da80[];
Res* func_00168b38(s32, s32, s32);
void func_0016cbc8(s32, s32, void*, s32);
s32 func_0016d080(s32, s32);
s32 func_001708f8(s32, s32);
void func_001b4c48(Obj*, void*, void*);
void func_001b5708(Obj*, s32);
void func_001d1698(void*, s32, s32, s32);
void func_001d16e8(void*, s32, s32);
void func_001d1a18(void*, s32, s32, s32);
void func_001d1d00(void*);
void func_001d1da0(void*, f32);
void func_001d20a8(void*);
void func_001d2248(void*, s32);
s32 func_001d3f98(Ent*);
s32 func_001d4550(Ent*);
void func_001dddd0(void*, s32);

static inline bool valid(Res* r) { return r && r->v; }

/* 001b4a00: set-up step of an entity: reads its parameters (0x14, 0x12, 3, 0x22) and initialises the sub-objects. */
void func_001b4a00(Obj* self, f32 f);  // 0x001b4a00: definition moved into src/anon/unit_001b2780.cpp
}

/* ---- 00222d40 ---- */

struct Ent24 { u8 pad[0x1c]; u32* data; s32 f20; };
struct Tbl { u8 pad[0x10]; Ent24* ents; };
struct Ctx { u8 pad[0x10]; u8 a[0x40]; u8 b[0x40]; s32 f90; s32 f94; };
struct Param {
    u32 flags;      /* 00 */
    void* p04;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s16 h0c;        /* 0c */
    s16 h0e;        /* 0e */
    s32 x;          /* 10 */
    s32 y;          /* 14 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* p20;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    s32 f44;        /* 44 */
    u8 pad48[0x18];
};

extern "C" {
extern Tbl* D_01d9e6e4;
extern Ctx* D_01d9e6e8;
extern u8 D_01d9e840[];
extern u8 D_01d9e980[];
extern u8 D_01d9e9c0[];
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
void sceVu0MulMatrix(void*, void*, void*);
s32 func_0020f1e0(u32*, Param*, s32);

/* 00222d40: builds a draw parameter block for sprite idx (colour col, position x/y, flags fl) and submits it. */
void func_00222d40(s32 idx, u16* col, s32 z, s32 x, s32 y, u8 fl, s32 extra);  // 0x00222d40: definition moved into src/anon/unit_00222aa8.cpp
}
