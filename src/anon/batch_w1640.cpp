#include "../common/types.h"
extern "C" {
void dk__RectBase__createPacket(u8*);
}
struct W1640ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct W1640ParamObj { void* vt; u8 pad[28]; u8 data[224]; W1640ParamEnt e[33]; };
extern "C" {
extern void* D_00349d90[];
extern u8 D_00349b50[]; extern u8 D_00349b70[]; extern u8 D_00349b90[]; extern u8 D_00349bb0[]; extern u8 D_00349bd0[]; extern u8 D_00349bf0[]; extern u8 D_00349c10[]; extern u8 D_00349c30[]; extern u8 D_00349c50[]; extern u8 D_00349c70[]; extern u8 D_00349c90[]; extern u8 D_00349cb0[]; extern u8 D_00349cd0[]; extern u8 D_00349cf0[]; extern u8 D_00349d10[]; extern u8 D_00349d30[]; extern u8 D_00349d50[];
}
static inline void W1640_SetEnt(W1640ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
extern "C" {
void func_0014bd50(W1640ParamObj* p);
}
// constructor (second copy, same vtable as func_0014c050): fills a 33-entry parameter table
void func_0014bd50(W1640ParamObj* p);  // 0x0014bd50: definition moved into src/anon/unit_0014b838.cpp
