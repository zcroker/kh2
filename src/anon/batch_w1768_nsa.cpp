#include "../common/types.h"
extern "C" {
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct O3 { void* vt; u8 pad[0x20c]; V4 a; V4 b; } O3;
void* func_001050c8(void);
void func_002ee8a8(O3*, void*, u32);
extern u8 D_00361bf0[];
static inline void vset(V4* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void func_002c1f08(O3* p, u32 a) {
    func_002ee8a8(p, func_001050c8(), a);
    p->vt = D_00361bf0;
    vset(&p->a, 0.0f, 0.0f, 0.0f, 0.0f);
    vset(&p->b, 0.0f, 0.0f, 0.0f, 1.0f);
}
}
