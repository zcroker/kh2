// Linked unit 0x001f6b68-0x001f6eb8 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"

// 001f6b68 (was src/anon/batch_w76.cpp)
namespace n001f6b68 {
// 0x001eadf8: definition moved into src/anon/unit_001e8ac8.cpp

extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u32 D_01d9eab4 asm("D_01d9eab4");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f69c0(void) asm("func_001f69c0");
void func_0021ee48(u8*, u8*, void*, u8*, s16, u8, u8) asm("func_0021ee48");
/*TARGET 001f6b68*/
void func_001f6b68(u8* base, u8* in, u8* desc) asm("func_001f6b68");
void func_001f6b68(u8* base, u8* in, u8* desc)
{
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in[7] == 0) return;
    u8* q = base + **(u32**)(desc + 12) + 160;
    if (q[2] == 0) {
        q[2] = in[7];
        if (*(s32*)(in + 12) == -1) return;
        if (*(s32*)(in + 20) == -1) return;
        func_0021ee48(base, in, (void*)func_001f69c0, q, *(s16*)(in + 4), in[8], in[6]);
    }
    q[2]--;
}
}  // namespace n001f6b68

// 001f6c40 (gap, written for the unit)
namespace n001f6c40 {
struct S { s16 a; u8 b; };
void func_001f6c40(u8* self, u8* t) asm("func_001f6c40");
void func_001f6c40(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->a = 0;
    s->b = 0;
}
}  // namespace n001f6c40

// 001f6c58 (was src/anon/batch_w1970.cpp)
namespace n001f6c58 {
struct V4_w1970 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct El_w1970 { u8 p[16]; };
struct Mgr_w1970 { u8 p[0x80]; El_w1970* arr; };
extern "C" Mgr_w1970* D_01d9e6e0;
extern Mgr_w1970* D_01d9e6e0_b asm("D_01d9e6e0");
struct Obj_w1970 { u8 p[4]; s32 owner; };
struct X_w1970 { u8 p[4]; u8 n; u8 q[3]; s32 idx; s32 off; };
struct Cf_w1970 { s32 o0; s32 o4; };
struct Y_w1970 { u8 p[0xc]; Cf_w1970* c; };
struct Sl_w1970 { void* p; u8 q[4]; f32 f; };
Obj_w1970* func_001e7a98(Mgr_w1970*, El_w1970*) asm("func_001e7a98");
void func_002226b8(void*, void*) asm("func_002226b8");
void func_00222750(void*, V4_w1970*, V4_w1970*) asm("func_00222750");
void sceVu0SubVector(V4_w1970*, void*, V4_w1970*) asm("sceVu0SubVector");
void sceVu0ScaleVector(f32, V4_w1970*, V4_w1970*) asm("sceVu0ScaleVector");
void sceVu0CopyVector(V4_w1970*, void*) asm("sceVu0CopyVector");
static inline u8* getp_w1970(Mgr_w1970* m, s32 a, X_w1970* x) {
    Obj_w1970* v = 0;
    El_w1970* el = &m->arr[x->idx];
    if (el) { v = func_001e7a98(m, el); v->owner = a; }
    return (u8*)v + x->off + 0xa0;
}
/*TARGET 001f6c58*/
void func_001f6c58(s32 a, X_w1970* x, Y_w1970* y) asm("func_001f6c58");
void func_001f6c58(s32 a, X_w1970* x, Y_w1970* y) {
    u8* s3 = getp_w1970(D_01d9e6e0, a, x);
    func_002226b8(s3, (u8*)a + y->c->o4 + 0xa0);
    Sl_w1970* s = (Sl_w1970*)((u8*)a + y->c->o0 + 0xa0);
    if (s->p == 0) {
        s->f = 1.0f / (f32)(x->n + 1);
    } else {
        V4_w1970 m; V4_w1970 b; V4_w1970 c;
        sceVu0CopyVector(&m, s->p);
        sceVu0SubVector(&b, s3, &m);
        f32 t = (f32)x->n;
        f32 f = s->f;
        while (0.0f < t) {
            u8* p = getp_w1970(D_01d9e6e0_b, a, x);
            sceVu0ScaleVector(f * t, &c, &b);
            t -= 1.0f;
            func_00222750(p, &m, &c);
        }
    }
    s->p = s3;
}
}  // namespace n001f6c58

// 001f6e38 (gap, written for the unit)
namespace n001f6e38 {
struct Mgr { u8 pad[0xa8]; u64 flags; };
struct In { u8 pad[8]; s32 a; u8 p2[4]; s32 b; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f6c58(u8*, In*, u8*) asm("func_001f6c58");
void func_001f6e38(u8* o, In* in, u8* c) asm("func_001f6e38");
void func_001f6e38(u8* o, In* in, u8* c) {
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (in->a == -1) return;
    if (in->b == -1) return;
    func_001f6c58(o, in, c);
}
}  // namespace n001f6e38

// 001f6ea0 (gap, written for the unit)
namespace n001f6ea0 {
void func_001f6ea0(u8* self, u8* t) asm("func_001f6ea0");
void func_001f6ea0(u8* self, u8* t) {
    *(u32*)(self + **(s32**)(t + 12) + 0xa0) = 0;
}
}  // namespace n001f6ea0

