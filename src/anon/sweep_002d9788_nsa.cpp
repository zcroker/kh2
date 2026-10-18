#include "../common/types.h"
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct O4s { u8 pad[8]; u32 fl; } O4s;
typedef struct O4 { u8 pad[0xc]; O4s* s; u8 pad2[0x108 - 0x10]; u32 fl; } O4;
void func_001780d8(O4*);
void func_00198860(O4*, s32);
void func_0016bd60(O4*, s32);
void func_0016b070(O4*, V4*);
void func_0017a7d8(O4*);
static inline void vset(V4* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void func_002d9788(O4* p) {
    V4 v;
    func_001780d8(p);
    func_00198860(p, 7);
    func_0016bd60(p, 3);
    if (p->s) p->s->fl |= 0x800;
    vset(&v, 0.0f, 0.0f, 0.0f, 0.0f);
    p->fl |= 3;
    func_0016b070(p, &v);
    func_0017a7d8(p);
}
