#include "../common/types.h"
typedef struct { s16 a, b, c; } EmitPt1e9e48;
typedef struct { s16 set; s16 count; u16* idx; } EmitTbl1e9e48;
typedef struct { u8 pad0[16]; u8* sets; u8 pad1[4]; EmitTbl1e9e48* tbls; } EmitRes1e9e48;
typedef struct { u8 pad0[144]; EmitPt1e9e48* pts; } EmitOvr1e9e48;
typedef struct { u8 pad0[4]; s16 tbl; u8 num; u8 wait; u8 mode; } Emit1e9e48;
typedef struct { u16 cur; u16 wait; } EmitSt1e9e48;
typedef struct { u8 pad0[12]; s32* off; } EmitCtx1e9e48;
typedef struct { u8 pad0[168]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1e9e48;
extern s32 D_01d9ea9c;
extern Part1e9e48* D_01d9e6e0;
extern s32 D_01d9eab4;
extern EmitRes1e9e48* D_01d9e6e4;
extern EmitOvr1e9e48* D_01d9e6e8;
void func_001e9d48(u8*, Emit1e9e48*, EmitPt1e9e48*);
void func_001ea100(u8*, Emit1e9e48*, EmitPt1e9e48*);
/* VU0 random number in [0,1) (hand-written VU0 macro code) */
static inline f32 rand1e9e48(void)
{
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
/* partMng particle emitter: spawn e->num points per tick (sequential or VU0-random pick) */
void func_001e9e48(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c);  // 0x001e9e48: definition moved into src/anon/unit_001e8ac8.cpp

/* twin of func_001e9e48 with a different spawn callee */
void func_001ea1b0(u8* base, Emit1e9e48* e, EmitCtx1e9e48* c);  // 0x001ea1b0: definition moved into src/anon/unit_001e8ac8.cpp
