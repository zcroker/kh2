#include "../common/types.h"
typedef struct { f32 x, y, z, w; } W2417Vec;
typedef struct { s16 x, y, z; } W2417Pt;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } W2417Mgr;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; u8 pad50[0x40]; W2417Pt* pts; } W2417Cam;
typedef struct { u8 pad[4]; void* owner; } W2417Ent;
typedef struct { s16 a; s16 cnt; u16* list; } W2417Grp;
typedef struct { u8 pad[0x14]; W2417Pt* pts; u8 pad18[0xc]; } W2417Mdl;
typedef struct { u8 pad[0x10]; W2417Mdl* mdl; u8 pad14[4]; W2417Grp* grp; } W2417Tab;
typedef struct { u8 pad[4]; s16 g0; s16 g1; u8 n; u8 mask; u8 rnd; u8 padb; s32 idx; s32 o10; s32 o14; s32 o18; } W2417Prm;
typedef struct { u8 pad[0xc]; s32* ofs; } W2417Ctx;
extern s32 D_01d9ea9c;
extern W2417Mgr* D_01d9e6e0;
extern W2417Tab* D_01d9e6e4;
extern W2417Cam* D_01d9e6e8;
s32 func_00222568(void);
W2417Ent* func_001e7a98(W2417Mgr*, u8*);
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0ApplyMatrix(void*, void*, W2417Vec*);
void func_00222730(void*, W2417Vec*, void*);

// 001f59b0: particle emitter variant (partMng): picks a point index (random or sequential), spawns an
// object per point, transforms the s16 point pairs by two matrices and stores the result.
// Partial asm (no extra code): the lui/lw of D_01d9e6e8 are single-instruction asms pinned to t7/a1 so
// sched2 keeps them after the arg setup like the original; the empty asm ties only add sched2 readers
// (t: idx so idx++ is issued before move v0,zero; a/q inputs place the lui after addiu s0 and before addu t6).
void pppKeBornRnd(void* owner, W2417Prm* prm_, W2417Ctx* c);  // 0x001f59b0: definition moved into src/anon/unit_001f5978.cpp
