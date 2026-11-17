#include "../common/types.h"

/* partMng (C): add an event's vector to a part's per-object vector work area.
 * The work vector and the event vector share one struct type, so gcc can tell
 * that different fields never overlap (needed for the original load order). */
typedef struct { f32 x, y, z; } PVec3;
typedef struct { PVec3 v; s32 init; } PAddWork;
typedef struct { s32 id; PVec3 v; } PAddArg;
typedef struct { u8 pad[0xc]; s32* offs; } PAddDesc;
typedef struct { u8 pad[0xc]; s32 id; } PObj;
typedef struct { u8 pad[0xa8]; u64 flags; } PSys;
extern s32 D_01d9ea9c;
extern PSys* D_01d9e6e0;
void func_001eff30(PAddArg*, PAddWork*);
void func_001f02b0(PAddArg*, PAddWork*);

/* 001effa8 */
void func_001effa8(PObj* obj, PAddArg* arg, PAddDesc* desc);  // 0x001effa8: definition moved into src/anon/unit_001ef780.cpp

/* 001f0328: same as 001effa8 with its own init helper */
void func_001f0328(PObj* obj, PAddArg* arg, PAddDesc* desc);  // 0x001f0328: definition moved into src/anon/unit_001ef780.cpp
