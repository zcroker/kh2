#include "../common/types.h"
void func_0018d050(void*, s32, s32, s32, s32, s32, s32);
void func_001a4530(void*);
extern u8 D_00350778[];
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct A1 { u32 vt; u32 flags; u8 pad[0xc4 - 8]; s32 c4; f32 c8; s32 cc; u8 pad2[0x100 - 0xd0]; V4 v; u8 m110[4]; } A1;
void func_001a4498(A1* p, s32 a, s32 b, s32 c, s32 d, s32 e) {
    V4* v;
    f32 f;
    func_0018d050(p, a, a, b, d, e, c);
    p->c4 = 0;
    p->c8 = 0.0f;
    p->vt = (u32)D_00350778;
    p->cc = 0;
    v = &p->v;
    f = p->c8;
    v->x = f; v->y = f; v->z = f; v->w = f;
    func_001a4530(p->m110);
    p->flags |= 0x100;
}
