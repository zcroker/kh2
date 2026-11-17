#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

/* Model header, copied from the caller into the work area (0x50 bytes). */
typedef struct MdlHdr {
    u32 flags;                      /* 0x00 */
    u8* vtx;                        /* 0x04 transformed vertex/normal buffer */
    union { s16 h; u8 b[2]; } alpha; /* 0x08 */
    u16 pad0a;                      /* 0x0a */
    u16 tex12;                      /* 0x0c */
    u16 tex14;                      /* 0x0e */
    s32 uvScaleU;                   /* 0x10 */
    s32 uvScaleV;                   /* 0x14 */
    union { u32 w; u8 b[4]; } col;  /* 0x18 */
    u32 col2;                       /* 0x1c */
    void* mtx32;                    /* 0x20 */
    void* mtx36;                    /* 0x24 */
    void* m40;                      /* 0x28 */
    void* m44;                      /* 0x2c */
    u32 m48;                        /* 0x30 */
    u32 ret;                        /* 0x34 */
    u8* pos;                        /* 0x38 */
    u8* nrm;                        /* 0x3c */
    u32 m64;                        /* 0x40 */
    void* m68;                      /* 0x44 */
    u32 m72;                        /* 0x48 */
    u32 m76;                        /* 0x4c */
} MdlHdr;

typedef struct Mdl {
    u32 flags;      /* 0x00 */
    s32 primOff;    /* 0x04 */
    s32 posOff;     /* 0x08 */
    s32 nrmOff;     /* 0x0c */
    u16 m16;        /* 0x10 */
    s16 nvtx;       /* 0x12 */
    s16 nnrm;       /* 0x14 */
    u8 alpha0;      /* 0x16 */
    u8 alpha1;      /* 0x17 */
} Mdl;

typedef struct Prim {
    u8 b0;          /* 0x00 */
    s8 type;        /* 0x01 */
    s16 count;      /* 0x02 */
    u32 m4;         /* 0x04 */
    s32 tex0;       /* 0x08 */
    s32 tex1;       /* 0x0c */
    u32 m16;        /* 0x10 */
    u32 m20;        /* 0x14 */
    u64 d24;        /* 0x18 */
} Prim;

typedef struct MdlWork {
    u8 pad0[0x100];
    u64 dmaTag;     /* 0x100 */
    u64 d264;       /* 0x108 */
    u64 gifTag;     /* 0x110 */
    u64 gifRegs;    /* 0x118 */
    u32 tex0lo;     /* 0x120 */
    u32 tex0hi;     /* 0x124 */
    u64 r296;       /* 0x128 */
    u32 alpha0;     /* 0x130 */
    u32 alpha1;     /* 0x134 */
    u64 r312;       /* 0x138 */
    u128 q320;      /* 0x140 */
    u64 d336;       /* 0x150 */
    u64 d344;       /* 0x158 */
    u32 m352;       /* 0x160 */
    u32 m356;       /* 0x164 */
    u64 d360;       /* 0x168 */
    u8 pad370[0x1e0 - 0x170];
    union { u128 q; u32 w[4]; } cnt; /* 0x1e0 */
    u64 primTag;    /* 0x1f0 */
    u64 primRegs;   /* 0x1f8 */
    u8 pad200[0x300 - 0x200];
    MdlHdr hdr;     /* 0x300 */
    u128 colScale;  /* 0x350 */
    u128 uvScale;   /* 0x360 */
    u128 col2;      /* 0x370 */
    u8 pad380[0x10];
    u8* nrmOut;     /* 0x390 */
    u8* vtxOut;     /* 0x394 */
} MdlWork;

typedef struct MdlCounters { s32 c[6]; } MdlCounters;

extern s32 D_00359780;
extern u8* D_00359788[];
extern s32 D_00352c38;
extern u32 D_00359180[];
extern u128 D_00359970[];
extern MdlCounters D_01da8cd0;
extern u128 D_01da8c40[];
extern u128 D_01da8bb0[];
void func_00224600(void*, void*, void*);

#define QCOPY(d, s) asm volatile("lq $2,0(%1)\n\tsq $2,0(%0)" : : "r"(d), "r"(s) : "$2", "memory")

u32 func_00217d80(Mdl* m_, u128* src);  // 0x00217d80: definition moved into src/anon/unit_00213ea8.cpp
