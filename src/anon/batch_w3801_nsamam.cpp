#include "../common/types.h"
extern "C" {
struct Pk120a20 { u32 addr; };
struct Ent120a20 { u16 qwc; u8 pad[2]; s32 off; s32 a; s32 b; };
struct Lst120a20 { s32 n; s32 ids[1]; };
struct Grp120a20 { u8 pad[16]; s32 ent; s32 lst; u8 pad2[8]; };
struct Mdl120a20 { u8 pad[28]; s32 count; Grp120a20 grp[1]; };
struct Obj120a20 { u8 pad[4]; Mdl120a20* mdl; };
struct Tx120a20 { u8 pad[44]; u32 addr[1]; };
Mdl120a20* func_00120800(Obj120a20*);
void func_001339d0(Pk120a20*, u32, s32, s32, s32);
void func_00133848(Pk120a20*, s32, u32, s32);
void func_00133898(Pk120a20*, s32, u32, s32);
/* Builds the DMA packet for a model and its second model group list. */
u32 func_00120a20(Obj120a20* o, Tx120a20* tx, u32* outs, u32 addr, s32 n);  // 0x00120a20: definition moved into src/anon/unit_00120520.cpp
}
