#include "../common/types.h"

/* particle effect slot table: copy each slot's value out and run its callback */
typedef struct PartVt { u8 pad[0x1c]; void (*f1c)(void*, void*); void (*f20)(void*, void*); } PartVt;
typedef union { PartVt* v; s32 w[4]; } PartEnt;
typedef struct { u8 pad[0x20]; s32 off; s32 x24:16; s32 n:16; PartEnt ent[1]; } PartHdr;
typedef struct { s32 x0, x4; PartHdr** x8; } PartObj;

void func_001e7948(PartObj* a);  // 0x001e7948: definition moved into src/anon/unit_001e0cb8.cpp

void func_001e79f0(PartObj* a);  // 0x001e79f0: definition moved into src/anon/unit_001e0cb8.cpp
