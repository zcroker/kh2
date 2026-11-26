#include "../common/types.h"
extern "C" {
struct W1649Ob {
    u8 pad0[44];
    s32 group;          // 44
    u8 pad1[248 - 48];
    u32 flags;   // 248 (union: read after float stores)
    u8 pad2[12];
    f32 fadeDist;       // 264
    u8 alpha;           // 268
};
struct W1649Ent { W1649Ob* obj; u32 flags; };
struct W1649Eff { u8 pad[864]; s32 active; u8 pad1[12]; };
struct W1649Pos { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1649Mgr {
    u8 pad0[1912];
    u8 drawExtra;           // 1912
    u8 grouped;             // 1913
    u8 pad1[2];
    s32 extraOn[(1936 - 1916) / 4];   // 1916, per slot
    u8 extraEff[3152 - 1936];         // 1936
    s32 effCount[4];        // 3152, per slot
    W1649Eff effs[16];      // 3168
    W1649Ent ents[512];     // 17248
    s32 entCount;           // 21344
    u8 pad2[8];
    s32 slot;               // 21356
    void* pending0;         // 21360
    void* pending1;         // 21364
};
s32 func_00106a08(void);
void* func_00106a60(s32);
void kn__Camera__getPosition(void*, W1649Pos*);
void func_00148598(W1649Mgr*, void*);
void func_001b81e8(void);
void func_001b8218(void);
void func_00148a30(W1649Mgr*);
void func_00148ac0(W1649Mgr*);
void dk__OctDrawFile__calcCameraRelative(W1649Mgr*, W1649Ob*);
f32 func_00148890(W1649Mgr*, W1649Ob*, W1649Pos*);
void func_001472b8(void*, void*, s32, s32);
void func_00148e40(W1649Mgr*, W1649Ob*, W1649Ob** out, s32* n);
void func_00148ef0(W1649Mgr*, W1649Ob**, s32);
s32 func_00147a68(W1649Mgr*, s32*, s32*);
void func_00147aa8(W1649Mgr*, W1649Ob*, f32);
void W1649_effCreate(void*) asm("_ZN3ryj6EFFECT6CreateEPN2dk10UserEffectE");

// Scratchpad sort arrays (see func_001472b8): keys are floats, the carried values are entry pointers.
union W1649FI { f32 f; W1649Ent* e; };
#define W1649_KEYS ((W1649FI*)0x70000000)
#define W1649_DIST ((f32*)0x70000800)
#define W1649_SORTED ((W1649FI*)0x70001000)

// Built with -fno-strict-aliasing (_nsa file).
// Per-frame update of all entries: measures their distance to the camera, sorts the visible ones
// (nearest first, in scratchpad), fades out far ones, and updates them (by group when grouped).
void dk__OctDrawFile__drawObjectAll(W1649Mgr* m);  // 0x001473e8: definition moved into src/anon/unit_00147140.cpp
}
