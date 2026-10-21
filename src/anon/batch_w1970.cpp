#include "../common/types.h"
struct V4_w1970 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct El_w1970 { u8 p[16]; };
struct Mgr_w1970 { u8 p[0x80]; El_w1970* arr; };
extern Mgr_w1970* D_01d9e6e0;
extern Mgr_w1970* D_01d9e6e0_b asm("D_01d9e6e0");
struct Obj_w1970 { u8 p[4]; s32 owner; };
struct X_w1970 { u8 p[4]; u8 n; u8 q[3]; s32 idx; s32 off; };
struct Cf_w1970 { s32 o0; s32 o4; };
struct Y_w1970 { u8 p[0xc]; Cf_w1970* c; };
struct Sl_w1970 { void* p; u8 q[4]; f32 f; };
extern "C" Obj_w1970* func_001e7a98(Mgr_w1970*, El_w1970*);
extern "C" void func_002226b8(void*, void*);
extern "C" void func_00222750(void*, V4_w1970*, V4_w1970*);
extern "C" void func_002f3f10(V4_w1970*, void*, V4_w1970*);
extern "C" void func_002f3f40(f32, V4_w1970*, V4_w1970*);
extern "C" void func_002f3f88(V4_w1970*, void*);
static inline u8* getp_w1970(Mgr_w1970* m, s32 a, X_w1970* x) {
    Obj_w1970* v = 0;
    El_w1970* el = &m->arr[x->idx];
    if (el) { v = func_001e7a98(m, el); v->owner = a; }
    return (u8*)v + x->off + 0xa0;
}
extern "C" {
void func_001f6c58(s32 a, X_w1970* x, Y_w1970* y) {
    u8* s3 = getp_w1970(D_01d9e6e0, a, x);
    func_002226b8(s3, (u8*)a + y->c->o4 + 0xa0);
    Sl_w1970* s = (Sl_w1970*)((u8*)a + y->c->o0 + 0xa0);
    if (s->p == 0) {
        s->f = 1.0f / (f32)(x->n + 1);
    } else {
        V4_w1970 m; V4_w1970 b; V4_w1970 c;
        func_002f3f88(&m, s->p);
        func_002f3f10(&b, s3, &m);
        f32 t = (f32)x->n;
        f32 f = s->f;
        while (0.0f < t) {
            u8* p = getp_w1970(D_01d9e6e0_b, a, x);
            func_002f3f40(f * t, &c, &b);
            t -= 1.0f;
            func_00222750(p, &m, &c);
        }
    }
    s->p = s3;
}
}
