#include "../common/types.h"

/* Plain C (partMng / pppPart range), built with -fno-strict-aliasing. */

/* ---- 001f01b8: add an offset vector to a part's position, then refresh it */
typedef struct { s32 x, y, z, w; } W2381Vec;
typedef struct { u8 pad[0xa0]; W2381Vec pos; } W2381Part;
typedef struct { s32 id; W2381Vec d; } W2381Move;
typedef struct { u32 p0, p4, p8; s32 id; } W2381Owner;
typedef struct { u32 p0, p4, p8; s32* off; } W2381Desc;
typedef struct { u64 f0:8; u64 f1:8; u64 f2:16; u64 f4:8; u64 f5:24; } W2381Bits;
typedef struct { u8 pad[0xa8]; W2381Bits b; } W2381Mng;
extern s32 D_01d9ea9c;
extern W2381Mng* D_01d9e6e0;
void func_001f0080(W2381Move*, W2381Vec*);
void func_001f00f8(W2381Vec*);

void func_001f01b8(W2381Owner* o, W2381Move* m, W2381Desc* d);  // 0x001f01b8: definition moved into src/anon/unit_001ef780.cpp

/* 0x001e7698 (pppAlloc): definition moved into src/anon/unit_001e0cb8.cpp */
