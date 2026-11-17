#include "../common/types.h"

/* VIF packet header built in front of a run of 48-byte items. */
typedef struct VifPkt_w2370 {
    u32 w0, w4, w8, wc;
    u32 self;       /* 0x10 */
    u32 w14, w18;
    u16 h1c; u8 b1e; u8 b1f;
    u16 qwc;        /* 0x20 DMA tag */
    u8 b22; u8 id;
    u32 w24;
    u32 vif0;       /* 0x28 */
    u32 w2c, w30;
    u16 h34; u8 b36; u8 count;
    u16 h38; u16 h3a; u16 h3c; u16 h3e;
    u8 pad40[0xc];
    f32 scale;      /* 0x4c */
    u32 w50, w54, w58;
} VifPkt_w2370;
typedef struct { u8 d[48]; } VifItem_w2370;
typedef struct { VifPkt_w2370* pkt; u8 count; } VifOwner_w2370;

void func_00221e28(VifOwner_w2370* o);  // 0x00221e28: definition moved into src/anon/unit_00221e28.cpp

/* ---- 001fc5b8 (partMng) ---- */
typedef unsigned int u128_w2370 __attribute__((mode(TI)));
typedef struct { s32 x, y, z; } PVec_w2370;
typedef PVec_w2370 PVec8_w2370 __attribute__((aligned(8)));
typedef struct {
    u8 pad[0x40];
    u8 work[0x30];       /* 0x40 */
    u128_w2370 m70;      /* 0x70 */
    PVec8_w2370 pos;     /* 0x80 */
} PartEnt_w2370;
typedef struct { u8 pad[0xc]; s32* offs; } PartCmd_w2370;
extern PartEnt_w2370* D_01d9ea94;
extern u128_w2370 D_0035da80;
void func_001e8fe0(void*, PVec_w2370*);

/* Moves entry 0 to entry 1's position, passing the move delta on. */
void func_001fc5b8(u8* base, s32 a1, PartCmd_w2370* cmd);  // 0x001fc5b8: definition moved into src/anon/unit_001fb350.cpp
