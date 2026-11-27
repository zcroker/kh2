#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" {
struct W1833GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct W1833AD { u64 data; u64 addr; };
struct W1833Pkt { W1833GifTag tag; W1833AD ad[13]; };

void func_001081c8(W1833Pkt* p);  // 001081c8: moved to src/anon/unit_00108068.cpp
struct W1833Vec { f32 x, y, z, w; };
struct W1833Mgr { u8 pad[0x80]; u8* tbl; };
struct W1833Cam { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; };
struct W1833Ent { u8 pad[4]; void* owner; };
struct W1833Prm { u8 pad[8]; f32 scale; u8 padc[4]; s32 idx; s32 o20; u8 pad18[4]; s32 o28; };
extern W1833Mgr* D_01d9e6e0;
extern W1833Cam* D_01d9e6e8;
W1833Ent* func_001e7a98(W1833Mgr*, u8*);
void sceVu0ApplyMatrix(W1833Vec*, void*, W1833Vec*);
void func_002226b8(void*, W1833Vec*);
void sceVu0SubVector(W1833Vec*, W1833Vec*, void*);
void sceVu0Normalize(W1833Vec*, W1833Vec*);
void sceVu0ScaleVector(W1833Vec*, W1833Vec*, f32);

void pppKeBornRnd2_Born(void* owner, W1833Prm* prm, s16* pos);  // 0x001f5cc8: definition moved into src/anon/unit_001f5978.cpp
void pppKeBornRnd5_Born(void* owner, W1833Prm* prm, s16* pos);  // 0x001f6648: definition moved into src/anon/unit_001f6298.cpp
}
