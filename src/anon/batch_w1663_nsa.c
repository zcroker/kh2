#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef union A64 { u64 v; u8 c; } A64;
typedef union A32 { u32 v; s32 s; u8 c; } A32;
typedef union A128 { u128 v; u8 c; } A128;
typedef union APtr { u8* p; void* v; u8 c; } APtr;

/* Model header (the object the draw command list belongs to). */
typedef struct MdlHdr {
    u32 flags;   /* 0x00: bit 2 = no fog */
    s32 cmdOfs;  /* 0x04: offset of the draw command list */
    s32 posOfs;  /* 0x08: offset of the positions (s16 x3) */
    s32 nrmOfs;  /* 0x0c: offset of the normals (s16 x3) */
    u16 f10;
    s16 nVtx;    /* 0x12 */
    s16 nNrm;    /* 0x14 */
    u8 tex0;     /* 0x16 */
    u8 tex1;     /* 0x17 */
} MdlHdr;

/* One draw command (16 bytes header, followed by the primitives). */
typedef struct DrawCmd {
    u8 f0;
    s8 type;     /* 0..7: primitive kind, odd = invalid */
    s16 count;
    u32 f4;
    u32 tex;
    u32 clut;
} DrawCmd;

/* Draw parameters, copied to scratchpad 0x300 (5 qwords). */
typedef struct DrawParam {
    u32 flags;      /* 0x00: bit 3 = alternate fog colour */
    u8* vtxBuf;     /* 0x04 */
    union { s16 texSet; struct { u8 tex0, tex1; } t; } tx; /* 0x08 */
    u16 f0a;
    u16 texOfs;     /* 0x0c */
    u16 clutOfs;    /* 0x0e */
    s32 texW;       /* 0x10 */
    s32 texH;       /* 0x14 */
    union { u8 rgba[4]; u32 word; } color;  /* 0x18 */
    u32 color2;     /* 0x1c */
    void* mtx0;     /* 0x20 */
    void* mtx1;     /* 0x24 */
    void* mtx2;     /* 0x28 */
    void* mtx3;     /* 0x2c */
    u32 f30;
    A32 pktEnd;     /* 0x34 */
    APtr pos;       /* 0x38 */
    APtr nrm;       /* 0x3c */
    u32 f40;
    APtr mtxSave;   /* 0x44 */
    u32 f48[2];
} DrawParam;

/* Scratchpad work area. */
typedef struct SprWork {
    u8 pad000[0x100];
    A64 tag100, tag108, tag110, tag118;
    A32 tex, clut; A64 tag128;
    A32 tex0, tex1; A64 tag138;
    A128 q140, q150;
    A64 tag160, tag168;
    u8 pad170[0x10];
    APtr f180;
    u8 pad184[0x1e0 - 0x184];
    union { u128 q; u32 w[4]; } cnt;
    A64 tag1f0, tag1f8;
    u8 pad200[0x2e0 - 0x200];
    A64 tag2e0, tag2e8;
    u8 pad2f0[0x10];
    DrawParam dp;
    u8 pad350[0x44];
    APtr vtxBase;   /* 0x394 */
    u8 pad398[4];
    APtr fogBase;   /* 0x39c */
} SprWork;

#define QCOPY(d, s) asm volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(d), "r"(s) : "$2", "memory")

extern A32 D_00359780;
extern SprWork* D_00359788[];
extern A32 D_00352c38;
extern u8 D_00359110[];
extern u8 D_00359180[];
extern u8 D_00359970[];
extern u128 D_01da8bb0[];
extern u128 D_01da8c40[];
extern A32 D_01da8cd0[];
extern u8 D_01dac550[];

u32 func_00215f28(MdlHdr* mdl, u128* param);  // 0x00215f28: definition moved into src/anon/unit_00213ea8.cpp
