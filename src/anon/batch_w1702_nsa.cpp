#include "../common/types.h"

/* YI::SEQUENCE key (0x90 bytes): each pair is {value at start, value at end} */
struct W1702Key {
    u32 flags;          /* 0x00 */
    s32 pad04;          /* 0x04 */
    s32 start;          /* 0x08 */
    s32 end;            /* 0x0c */
    s32 x[2];           /* 0x10 */
    s32 y[2];           /* 0x18 */
    s32 w[2];           /* 0x20 */
    s32 h[2];           /* 0x28 */
    f32 rx[2];          /* 0x30 */
    f32 ry[2];          /* 0x38 */
    f32 rz[2];          /* 0x40 */
    f32 scale[2];       /* 0x48 */
    f32 sx[2];          /* 0x50 */
    f32 sy[2];          /* 0x58 */
    f32 ease[4];        /* 0x60 */
    f32 ampX[2];        /* 0x70 */
    f32 ampY[2];        /* 0x78 */
    u16 freqX;          /* 0x80 */
    u16 freqY;          /* 0x82 */
    u32 pad84;          /* 0x84 */
    u8 col[2][4];       /* 0x88 */
};

/* YI::SEQUENCE (fields used by the key evaluator) */
struct W1702Seq {
    u8 pad00[0xb8];
    u32 mode;           /* 0xb8 */
    u8 padbc[8];
    W1702Key* keys;     /* 0xc4 */
    s32 numKeys;        /* 0xc8 */
    f32 time;           /* 0xcc */
    u32 padd0;
    u8 active;          /* 0xd4 */
    f32 scaleX;         /* 0xd8 */
    f32 scaleY;         /* 0xdc */
    u32 rgba;           /* 0xe0 */
    s32 posX;           /* 0xe4 */
    s32 posY;           /* 0xe8 */
    u8 padec[0x118 - 0xec];
    f32 colScale[4];    /* 0x118 */
    f32 rot[3];         /* 0x128 */
    f32 scale;          /* 0x134 */
    f32 sx;             /* 0x138 */
    f32 sy;             /* 0x13c */
};

extern "C" {
/* the game's own __fixunssfsi (float to u32); const like the libcall */
u32 __fixunssfsi(f32) __attribute__((const));
f32 sinf(f32); /* sinf */
f32 cosf(f32); /* cosf */

/* Finds the active key at seq->time and evaluates color, scale and position. */

void YI__SEQUENCE__UpdateActive(W1702Seq* seq);  // 0x0023a0d8: definition moved into src/anon/unit_00239988.cpp
}
