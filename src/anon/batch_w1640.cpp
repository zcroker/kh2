#include "../common/types.h"
extern "C" {
void func_0014b290(u8*);
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
void func_0014bd50(W1640ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d90;
    W1640_SetEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    W1640_SetEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    W1640_SetEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    W1640_SetEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    W1640_SetEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    W1640_SetEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    W1640_SetEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    W1640_SetEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    W1640_SetEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    W1640_SetEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    W1640_SetEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    W1640_SetEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    W1640_SetEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    W1640_SetEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    W1640_SetEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    W1640_SetEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    W1640_SetEnt(&p->e[16], 48, D_00349c50); p->e[16].type = 2;
    W1640_SetEnt(&p->e[17], 48, &p->pad[28]); p->e[17].type = 13;
    W1640_SetEnt(&p->e[18], 48, D_00349c70); p->e[18].type = 2;
    W1640_SetEnt(&p->e[19], 48, &p->pad[28]); p->e[19].type = 13;
    W1640_SetEnt(&p->e[20], 48, D_00349c90); p->e[20].type = 2;
    W1640_SetEnt(&p->e[21], 48, &p->pad[28]); p->e[21].type = 13;
    W1640_SetEnt(&p->e[22], 48, D_00349cb0); p->e[22].type = 2;
    W1640_SetEnt(&p->e[23], 48, &p->pad[28]); p->e[23].type = 13;
    W1640_SetEnt(&p->e[24], 48, D_00349cd0); p->e[24].type = 2;
    W1640_SetEnt(&p->e[25], 48, &p->pad[28]); p->e[25].type = 13;
    W1640_SetEnt(&p->e[26], 48, D_00349cf0); p->e[26].type = 2;
    W1640_SetEnt(&p->e[27], 48, &p->pad[28]); p->e[27].type = 13;
    W1640_SetEnt(&p->e[28], 48, D_00349d10); p->e[28].type = 2;
    W1640_SetEnt(&p->e[29], 48, &p->pad[28]); p->e[29].type = 13;
    W1640_SetEnt(&p->e[30], 48, D_00349d30); p->e[30].type = 2;
    W1640_SetEnt(&p->e[31], 48, &p->pad[28]); p->e[31].type = 13;
    W1640_SetEnt(&p->e[32], 0, D_00349d50); p->e[32].type = 2;
}
