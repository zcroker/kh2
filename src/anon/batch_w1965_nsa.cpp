#include "../common/types.h"
// 0019a808: -fno-strict-aliasing keeps the u16 load after the v.xyz stores; integer address math gives the idx-first addu.
#define W1965cQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965cV {
    f32 x, y, z, w;
    W1965cV() {}
    W1965cV(const W1965cV& o) { W1965cQCOPY(this, &o); }
    W1965cV& operator=(const W1965cV& o) { if (this != &o) W1965cQCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1965cHdr { u8 pad[24]; u8 type; u8 mode; u16 id; };
struct W1965cEnt { s32 a; f32 x, y, z; u8 pad[12]; u8 type; u8 mode; u16 id; u8 pad2[10]; u16 delay; u8 pad3[2]; u16 r; u8 lvl; u8 pad4[15]; };
struct W1965cTbl { u8 pad[4]; u16 count; u8 pad2[38]; W1965cEnt ent[1]; };
struct W1965cObj { u8 pad[8]; W1965cTbl* tbl; u8 pad2[8]; f32 timer; u8 pad3[8]; u8 level; };
extern "C" {
extern u8 D_0034f250[];
s32 func_0016b7a0(u16);
s32 func_00195700(u8*, u16);
s32 func_00199890(W1965cEnt*, W1965cObj*, W1965cV*);
s32 func_00199938(W1965cEnt*, W1965cObj*);
s32 func_0019ac80(W1965cObj*);
W1965cV YS__UNIT_GROUP__RandomPosPlayer(s32);
W1965cV func_0019b0e8(s32, W1965cV*, f32, f32);
void func_0019a808(W1965cObj* o);  // 0x0019a808: definition moved into src/anon/unit_00199688.cpp
}
