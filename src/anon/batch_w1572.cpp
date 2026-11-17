#include "../common/types.h"
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W1572_C8 { u8 r, g, b, a; };
struct W1572_Arg8 { s32 id; s32 idx; W1572_C8 add; u8 flag; };
union W1572_FU { f32 f; u8 c; };
struct W1572_C16 { u16 r, g, b, a; };
struct W1572_Arg16 { s32 id; s32 idx; W1572_C16 add; u8 flag; };
struct W1572_Obj { u8 pad[388]; s32 id; s32 val; u8 pad2[12]; };
struct W1572_Vt { u8 pad[28]; void (*fn)(void*); };
struct W1572_Mgr { W1572_Vt* vt; u8 pad[428]; W1572_Obj objs[5]; u8 pad3[2472 - 432 - 5 * 408]; s32 cur; };
extern "C" {
extern char D_0036e490[]; extern char D_0036e4e0[]; extern char D_0036e4e8[]; extern char D_0036e4f8[];
extern char D_0036e500[]; extern char D_0036e508[]; extern char D_0036e510[]; extern char D_0036e520[];
extern char D_01d5ba58[];
void func_00190878(void*, s32, s32);
s32 func_0019ba60(s32);
void func_001bc778(void*);
void func_001bce90(void*, const char*, s32, void*);
s32 func_001d4ae0(void*, void*, void*);
s32 func_001d4bd8(void*, void*, void*);
struct S { u32 type; s32 id; s32 pad; char buf[1]; };
struct NoTail { ~NoTail(){} };
s32 func_001d4940(S* p, void* a1, void* a2);  // 0x001d4940: definition moved into src/anon/unit_001d3c08.cpp
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_01d9e360[];
u8 func_001edce0(s32, f32);
u8 func_001edea8(s32, f32);
u16 func_001ee238(s32, f32);
u16 func_001ee400(s32, f32);
void func_001edd08(u8* a0, W1572_Arg8* a1, u8* a2);  // 0x001edd08: definition moved into src/anon/unit_001ec098.cpp
void func_001eded0(u8* a0, W1572_Arg8* a1, u8* a2);  // 0x001eded0: definition moved into src/anon/unit_001ec098.cpp
void func_001ee260(u8* a0, W1572_Arg16* a1, u8* a2);  // 0x001ee260: definition moved into src/anon/unit_001ec098.cpp
void func_001ee428(u8* a0, W1572_Arg16* a1, u8* a2);  // 0x001ee428: definition moved into src/anon/unit_001ec098.cpp
extern s32 D_0035e118[];
extern s32 D_0035e130[];
extern s32 D_0035e148[];
s32 func_00224860(void);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
s32 func_00139d78(W1572_Obj*);
void func_001386e0(W1572_Obj*, s32, s32, s32, s32, s32);
void func_00138c10(W1572_Obj*, s32);
void func_002291d0(W1572_Mgr* m);  // 002291d0: moved to src/sasa/musical_score.cpp (linked unit)
}
