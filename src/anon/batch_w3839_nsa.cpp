#include "../common/types.h"
// w3839: 0010f448 and 00270c70 (both need -fno-strict-aliasing for 00270c70; 0010f448 matches either way).
struct QWf44 { f32 x, y, z, w;
    QWf44() {}
    QWf44(const QWf44& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline f32 Dotf44(const QWf44& a, const QWf44& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Kf44 { s32 i0; s32 i4; };
struct Tf44 { s32 i0; s32 i4; s32 i8; u32 flags; };
struct Hf44 { s32 i0; s32 i4; s32 i8; };
struct Of44 {
    u8 p0[12]; Kf44* k; u8 p1[352 - 16]; u32 f160; u8 p2[1164 - 356]; Hf44* h;
    u8 p3[1360 - 1168]; QWf44 v550; u8 p4[2940 - 1376]; u32 fb7c; u8 p5[2992 - 2944]; QWf44 vbb0;
    u8 p6[3024 - 3008]; QWf44 vbd0; u8 p7[3056 - 3040]; f32 fbf0;
};
struct Af44 { u32 flags; s32 i4; s32 i8; s32 ic; Tf44* t; s32 i14; s32 i18; s32 i1c; };
extern "C" {
u8* getFSR_f44(Of44*) asm("_ZN2kn6Friend16getFriendSaveRamEv");
s32 ct_10f7b0_f44(Of44*, s32, s32) asm("_Z16ctarget_0010f7b0jjjj");
s32 uc_1a1de0_f44(Hf44*) asm("_Z16u_call4_001a1de0jjjj");
s32 func_0010cc80(Of44*);
s32 func_0010f340(Of44*, QWf44*, Tf44*, f32);
// Checks whether an action entry may be used now (party member, flags, save state, target, facing).
// The ==3 return shares its block with the failed ctarget call (goto zero) so if-conversion keeps it,
// and the function ends on return 1, which makes cross-jumping keep that early return-0 block.
s32 func_0010f448(Of44* o, Af44* a, u8 c1, u8 c2);  // 0x0010f448: definition moved into src/anon/unit_0010f338.cpp
}


struct W1712Entry {
    s16 id;
    s8 flag;
    u8 level;
    u8 pad[4];
};

struct W1712List {
    s8 numDrive;
    s8 numParty;
    s8 numSummon;
    u8 b3;
    s8 total;
    u8 pad[3];
    W1712Entry e[18];
};

struct W1712Sheet {
    u8 pad0[0x12];
    u8 count;
    u8 pad13[0x34 - 0x13];
    u16 a34[8];
    u16 a44[8];
    struct { u16 id : 15; u16 on : 1; } a54[80];
    u8 xf4;
    u8 xf5[1];
};

struct W1712Item {
    u16 id;
    u8 type;
};

struct W1712Rec {
    u8 pad[6];
    u8 kind;
};

extern "C" {
void func_002713a0(s32, s8**, s32*);
s16 func_00271870(u16);
s32 func_001a36f8(s32);
W1712Rec* func_001a80c8(s32);
s32 func_001145b0(s16, s32);
u8* W1712_getSaveRam(void) asm("_Z10getSaveRamv");
void W1712_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
u8* W1712_GetSheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 W1712_HasAnsemEntry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
W1712Item* W1712_ItemEach(W1712Item*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
u8 W1712_GetMpDriveStatus(s32) asm("_ZN2YS5MAGIC16GetMpDriveStatusEi");
extern void* D_0035f010;
extern W1712List* D_0035f12c;

void W1712_func(s32 arg0) asm("_Z17ctarget0_00270c70v");
void W1712_func(s32 arg0);  // 0x00270c70: definition moved into src/anon/unit_0026f0a0.cpp
}
