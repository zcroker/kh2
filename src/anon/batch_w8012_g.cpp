#include "../common/types.h"
extern "C" {
struct V4_2cf998 { f32 x, y, z, w; };
static inline __attribute__((always_inline)) void set4_2cf998(V4_2cf998* v, f32 x, f32 y, f32 z, f32 w) {
    v->w = w;
    v->x = x;
    v->y = y;
    v->z = z;
}
struct E2cf998 { s32 on; u8 flags[12]; f32* pos; u8 pad[20]; };
s32 func_002ceb28(void);
s32 func_00197920(void);
s32 func_002cf270(void*, s32);
void func_002cf280(void*, s32, s32);
void func_002cf2b0(void*, s32);
void func_001444c8(void*, V4_2cf998*, V4_2cf998*);
s32 func_002cec20(s32, void*);
extern s32 D_00361fa0;
extern E2cf998* D_00361fa4;
extern s32 D_00361f60;
void func_002cf998(void) {
    V4_2cf998 lo;
    V4_2cf998 hi;
    u8 box[32];
    s32 i;
    E2cf998* e;
    f32* p;
    f32 z;
    f32 r;
    s32* g;
    u8* b;
    if (!func_002ceb28()) return;
    if (func_00197920()) return;
    i = 0;
    if (D_00361fa0 <= 0) return;
    do {
        e = &D_00361fa4[i];
        if (e->on == 0) goto next;
        if (e->pos == 0) goto next;
        if (!func_002cf270(e->flags, 16)) goto next;
        p = e->pos;
        b = box;
        r = 1.0f;
        z = 0.0f;
        set4_2cf998(&lo, p[1] - r, p[2] - r, p[3] - r, z);
        set4_2cf998(&hi, p[1] + r, p[2] + r, p[3] + r, z);
        g = &D_00361f60;
        func_001444c8(b, &lo, &hi);
        if (func_002cec20(*g, b)) func_002cf280(e->flags, 32, 0);
        else func_002cf2b0(e->flags, 32);
    next:
        i++;
    } while (i < D_00361fa0);
}
}
