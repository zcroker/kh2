/* 001f46f8: partMng particle colour/size update (C, -fno-strict-aliasing). Parameter and particle colours share struct type C46 so gcc lets parameter loads pass stores of other fields. fdiv46 is a non-volatile "nop;nop;div.s" asm helper (partial asm): non-volatile so it is not a scheduling barrier, which fixes the last lhu/addu order. */
#include "../common/types.h"
typedef unsigned int u128_46 __attribute__((mode(TI)));
asm("dpmul = func_00313f40");
asm("litodp = func_00314330");
asm("dptofp = __truncdfsf2");

typedef struct { u16 r, g, b, a; } C46;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } M46;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; } K46;

/* emitter parameters */
typedef struct {
    s32 id;          /* 0x00 */
    s32 tex;         /* 0x04 */
    s32 texofs;      /* 0x08 */
    C46 col[4];      /* 0x0c */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u16 angle;       /* 0x50 */
    u8 b52;          /* 0x52 */
    u8 b53;          /* 0x53 */
    u8 pad54;
    u8 fl55;         /* 0x55 */
    u8 fl56;         /* 0x56 */
    u8 fl57;         /* 0x57 */
    u8 fl58;         /* 0x58 */
} P46;

/* particle state at owner + ofs + 160 */
typedef struct {
    u8 pad0[4];
    u8 flags;        /* 0x04 */
    u8 pad5[0x10 - 5];
    u8 c0[8];        /* 0x10 */
    u8 pad18[4];
    f32 f1c;         /* 0x1c */
    s8 c1[8];        /* 0x20 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u8 b50;          /* 0x50 */
    u8 b51;          /* 0x51 */
    u8 n;            /* 0x52 */
    u8 pad53[0x60 - 0x53];
    u8* data;        /* 0x60 */
    void* tex;       /* 0x64 */
    f32 f68;         /* 0x68 */
    f32 f6c;         /* 0x6c */
    C46 col[4];      /* 0x70 */
} E46;

typedef struct {
    u8 c0[8];        /* 0x00 */
    u8 pad8[4];
    f32 size;        /* 0x0c */
    s8 c1[8];        /* 0x10 */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1c */
    f32 f20;         /* 0x20 */
    f32 f24;         /* 0x24 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    u8 b40;          /* 0x40 */
    u8 b41;          /* 0x41 */
    u8 n;            /* 0x42 */
} S46;
typedef struct { u8 pad[0xc]; s32 id; } O46;
typedef struct { u8 pad[0xc]; s32* ofs; } X46;
typedef struct { E46* e; void* tex; void* c0; u8* data; f32* v80; f32* v64; } A46;

extern s32 D_01d9ea9c;
extern M46* D_01d9e6e0;
extern K46* D_01d9e6e8;
extern u8 D_01d9e360[];
extern s32 D_00352c38;
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0ApplyMatrix(f32*, f32*, void*);
void sceVu0Normalize(f32*, f32*);
void sceVu0CopyVector(f32*, f32*);
void func_00222080(E46*, u8*, f32*, f32*);
void func_00222170(A46*);

static inline f32 fdiv46(f32 a, f32 b)
{
    f32 r;
    asm(".set noreorder\n\tnop\n\tnop\n\tdiv.s %0,%1,%2\n\t.set reorder" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
void func_001f46f8(O46* owner, P46* prm, X46* ctx);  // 0x001f46f8: definition moved into src/anon/unit_001f45f8.cpp
