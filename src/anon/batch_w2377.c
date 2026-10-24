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
void func_001effa8(PObj* obj, PAddArg* arg, PAddDesc* desc)
{
    PAddWork* w = (PAddWork*)((u8*)obj + *desc->offs + 0xa0);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (w->init == 0) func_001eff30(arg, w);
    if (arg->id != obj->id) return;
    w->v.x += arg->v.x;
    w->v.y += arg->v.y;
    w->v.z += arg->v.z;
}

/* 001f0328: same as 001effa8 with its own init helper */
void func_001f0328(PObj* obj, PAddArg* arg, PAddDesc* desc)
{
    PAddWork* w = (PAddWork*)((u8*)obj + *desc->offs + 0xa0);
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (w->init == 0) func_001f02b0(arg, w);
    if (arg->id != obj->id) return;
    w->v.x += arg->v.x;
    w->v.y += arg->v.y;
    w->v.z += arg->v.z;
}
