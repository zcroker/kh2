// Linked unit 0x001f45f8-0x001f5010 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
// gcc 3.2 soft-float double helpers in this toolchain: bind them to the retail libgcc copies.
asm("dpmul = func_00313f40");
asm("litodp = func_00314330");
asm("dptofp = __truncdfsf2");

// 001f45f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001f45f8 {
extern u8  D_01da0000 asm("D_01da0000");
// alloc_aligned16
extern "C" void func_001e7798(...) asm("func_001e7798");
/*TARGET 001f45f8*/
void func_001f45f8(u32 a0, u8* a1) asm("_Z13func_001f45f8jPh");
void func_001f45f8(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 12) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}
}  // namespace n001f45f8

// 001f4640 (was src/anon/batch_w2438.c)
namespace n001f4640 {
extern s32 D_00352bec asm("D_00352bec");
extern s32 D_00352bf0 asm("D_00352bf0");
static inline int inr_001f4640(s32 v, s32 lo, s32 hi)
{
    if (v < lo) return 0;
    if (v > hi) return 0;
    return 1;
}
/*TARGET 001f4640*/
/* VU0 project + screen clip test. The __builtin_expect on the y < ymin test sets the block
   frequencies that make global-alloc give ymin<<4 t2 and ymax<<4 t3 like the original. */
s32 func_001f4640(f32* v, s32* o, f32* m) asm("func_001f4640");
/* VU0 project + screen clip test. The __builtin_expect on the y < ymin test sets the block
   frequencies that make global-alloc give ymin<<4 t2 and ymax<<4 t3 like the original. */
s32 func_001f4640(f32* v, s32* o, f32* m)
{
    s32 cx = D_00352bec;
    s32 cy = D_00352bf0;
    s32 xmin, ymin, xmax, ymax, r;
    xmax = cx + 2048;
    xmin = 2048 - cx;
    ymax = cy + 2048;
    ymin = 2048 - cy;
    asm volatile(
        "lqc2 $vf12,0(%0)\n"
        "lqc2 $vf4,0(%2)\n"
        "lqc2 $vf5,16(%2)\n"
        "lqc2 $vf6,32(%2)\n"
        "lqc2 $vf7,48(%2)\n"
        "vmulax.xyzw ACC,$vf4,$vf12x\n"
        "vmadday.xyzw ACC,$vf5,$vf12y\n"
        "vmaddaz.xyzw ACC,$vf6,$vf12z\n"
        "vmaddw.xyzw $vf14,$vf7,$vf12w\n"
        "vdiv Q,$vf0w,$vf14w\n"
        "vmove.xyzw $vf15,$vf14\n"
        "vsub.w $vf15,$vf15,$vf15\n"
        "vwaitq\n"
        "vmulq.xyz $vf15,$vf15,Q\n"
        "vftoi4.xyz $vf15,$vf15\n"
        "sqc2 $vf15,0(%1)\n"
        : : "r"(v), "r"(o), "r"(m) : "memory");
    r = inr_001f4640(o[0], xmin << 4, xmax << 4);
    if (__builtin_expect(o[1] < (ymin << 4), 1)) r = 0;
    else if (o[1] > (ymax << 4)) r = 0;
    if (o[2] <= 0) r = 0;
    return r;
}
}  // namespace n001f4640

// 001f46f8 (was src/anon/batch_w3856_nsa.c)
namespace n001f46f8 {
typedef unsigned int u128_46 __attribute__((mode(TI)));
typedef struct { u16 r, g, b, a; } C46;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } M46;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; } K46;
/* emitter parameters */
typedef struct {
    s32 id;          /* 0x00 */
    s32 tex;         /* 0x04 */
    s32 texofs;      /* 0x08 */
    C46 col[4];      /* 0x0c */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u16 angle;       /* 0x50 */
    u8 b52;          /* 0x52 */
    u8 b53;          /* 0x53 */
    u8 pad54;
    u8 fl55;         /* 0x55 */
    u8 fl56;         /* 0x56 */
    u8 fl57;         /* 0x57 */
    u8 fl58;         /* 0x58 */
} P46;
/* particle state at owner + ofs + 160 */
typedef struct {
    u8 pad0[4];
    u8 flags;        /* 0x04 */
    u8 pad5[0x10 - 5];
    u8 c0[8];        /* 0x10 */
    u8 pad18[4];
    f32 f1c;         /* 0x1c */
    s8 c1[8];        /* 0x20 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u8 b50;          /* 0x50 */
    u8 b51;          /* 0x51 */
    u8 n;            /* 0x52 */
    u8 pad53[0x60 - 0x53];
    u8* data;        /* 0x60 */
    void* tex;       /* 0x64 */
    f32 f68;         /* 0x68 */
    f32 f6c;         /* 0x6c */
    C46 col[4];      /* 0x70 */
} E46;
typedef struct {
    u8 c0[8];        /* 0x00 */
    u8 pad8[4];
    f32 size;        /* 0x0c */
    s8 c1[8];        /* 0x10 */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1c */
    f32 f20;         /* 0x20 */
    f32 f24;         /* 0x24 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    u8 b40;          /* 0x40 */
    u8 b41;          /* 0x41 */
    u8 n;            /* 0x42 */
} S46;
typedef struct { u8 pad[0xc]; s32 id; } O46;
typedef struct { u8 pad[0xc]; s32* ofs; } X46;
typedef struct { E46* e; void* tex; void* c0; u8* data; f32* v80; f32* v64; } A46;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern M46* D_01d9e6e0 asm("D_01d9e6e0");
extern K46* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e360[] asm("D_01d9e360");
extern s32 D_00352c38 asm("D_00352c38");
void sceVu0CopyMatrix(f32*, f32*) asm("sceVu0CopyMatrix");
void sceVu0ApplyMatrix(f32*, f32*, void*) asm("sceVu0ApplyMatrix");
void sceVu0Normalize(f32*, f32*) asm("sceVu0Normalize");
void sceVu0CopyVector(f32*, f32*) asm("sceVu0CopyVector");
void func_00222080(E46*, u8*, f32*, f32*) asm("func_00222080");
void func_00222170(A46*) asm("func_00222170");
static inline f32 fdiv46(f32 a, f32 b)
{
    f32 r;
    asm(".set noreorder\n\tnop\n\tnop\n\tdiv.s %0,%1,%2\n\t.set reorder" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
/*TARGET 001f46f8*/
void func_001f46f8(O46* owner, P46* prm, X46* ctx) asm("func_001f46f8");
void func_001f46f8(O46* owner, P46* prm, X46* ctx)
{
    f32 m[16];
    f32 dir[4];
    f32 pos[4];
    A46 arg;
    E46* e;
    S46* s;
    u8 n;
    f32 sz;
    s32* ofs = ctx->ofs;
    e = (E46*)((u8*)owner + ofs[0] + 160);
    s = (S46*)((u8*)owner + ofs[0] + 176);
    {
    void* src = (u8*)owner + ofs[2] + 160;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    sceVu0CopyMatrix(m, D_01d9e6e8->m0);
    *(u128_46*)&m[12] = 0;
    m[15] = 1.0f;
    sceVu0ApplyMatrix(dir, m, src);
    }
    sceVu0Normalize(dir, dir);
    sceVu0CopyVector(pos, D_01d9e6e8->m1);
    if (owner->id == prm->id) {
        if (owner->id == 0) {
            u8* d = (u8*)owner + ctx->ofs[1] + 160;
            void* t;
            if (prm->tex != -1) t = *(u8**)(D_01d9e6e0->tbl + prm->tex * 16 + 4) + prm->texofs + 160;
            else t = D_01d9e360;
            if (e->tex == D_01d9e360) return;
            e->tex = t;
            e->data = d;
            if (prm->fl56 == 0) e->flags |= 8;
            if (prm->fl55 != 0) e->flags |= 4;
            if (prm->fl58 != 0) e->flags |= 0x10;
            if (prm->fl57 != 0) e->flags |= 0x20;
            func_00222080(e, e->data, pos, dir);
        }
        e->col[0].r += prm->col[0].r;
        e->col[0].g += prm->col[0].g;
        e->col[0].b += prm->col[0].b;
        e->col[0].a += prm->col[0].a;
        e->col[1].r += prm->col[1].r;
        e->col[1].g += prm->col[1].g;
        e->col[1].b += prm->col[1].b;
        e->col[1].a += prm->col[1].a;
        e->col[2].r += prm->col[2].r;
        e->col[2].g += prm->col[2].g;
        e->col[2].b += prm->col[2].b;
        e->col[2].a += prm->col[2].a;
        e->col[3].r += prm->col[3].r;
        e->col[3].g += prm->col[3].g;
        e->col[3].b += prm->col[3].b;
        e->col[3].a += prm->col[3].a;
        e->f68 = prm->f2c;
        e->f6c += prm->f48;
        s->n = e->data[1] - 1;
        { f32 t2c = s->f2c;
        sz = s->size + prm->f30;
        s->size = sz;
        s->f30 = prm->f38;
        s->f38 = prm->f3c;
        s->f3c = prm->f40;
        s->f24 += prm->f44;
        s->f2c = t2c + prm->f4c; }
        s->f28 = (f32)(prm->angle * 3.141592654 * 0.017453292522222223);
        s->b40 = prm->b52;
        s->b41 = prm->b53;
        s->f1c = fdiv46(-(sz - sz * prm->f34), (f32)s->n);
    }
    s->f20 = fdiv46(e->f68, (f32)s->n);
    s->f34 = fdiv46(e->f6c, s->f20);
    s->c0[0] = (s16)e->col[0].r >> 7;
    s->c0[1] = (s16)e->col[0].g >> 7;
    s->c0[2] = (s16)e->col[0].b >> 7;
    s->c0[3] = (s16)e->col[0].a >> 7;
    s->c0[4] = (s16)e->col[1].r >> 7;
    s->c0[5] = (s16)e->col[1].g >> 7;
    s->c0[6] = (s16)e->col[1].b >> 7;
    s->c0[7] = (s16)e->col[1].a >> 7;
    s->c1[0] = (s16)e->col[2].r >> 7;
    s->c1[1] = (s16)e->col[2].g >> 7;
    s->c1[2] = (s16)e->col[2].b >> 7;
    s->c1[3] = (s16)e->col[2].a >> 7;
    s->c1[4] = (s16)e->col[3].r >> 7;
    s->c1[5] = (s16)e->col[3].g >> 7;
    s->c1[6] = (s16)e->col[3].b >> 7;
    s->c1[7] = (s16)e->col[3].a >> 7;
    if (D_00352c38 != 0) {
        f32 y; s32 i;
        y = (f32)s->c0[0] * 0.3f + (f32)s->c0[1] * 0.59f + (f32)s->c0[2] * 0.11f;
        s->c0[0] = s->c0[1] = s->c0[2] = (s32)y;
        y = (f32)s->c0[4] * 0.3f + (f32)s->c0[5] * 0.59f + (f32)s->c0[6] * 0.11f;
        s->c0[4] = s->c0[5] = s->c0[6] = (s32)y;
        y = (f32)s->c1[0] * 0.3f + (f32)s->c1[1] * 0.59f + (f32)s->c1[2] * 0.11f;
        s->c1[0] = s->c1[1] = s->c1[2] = (s32)y;
        y = (f32)s->c1[4] * 0.3f + (f32)s->c1[5] * 0.59f + (f32)s->c1[6] * 0.11f;
        s->c1[4] = s->c1[5] = s->c1[6] = (s32)y;
    }
    arg.tex = e->tex;
    arg.data = e->data;
    arg.c0 = e->c0;
    arg.v80 = pos;
    arg.v64 = dir;
    arg.e = e;
    func_00222170(&arg);
}
}  // namespace n001f46f8

// 001f4d90 (gap, written for the unit)
namespace n001f4d90 {
struct UV { f32 u, v; };
extern UV D_00354be0 asm("D_00354be0");
extern u8 D_01d9e900[] asm("D_01d9e900");
extern u8 D_01d9eaa4[] asm("D_01d9eaa4");
struct Ctx { u8 pad[12]; s32* off; };
void func_002222b8(u8* p, u8* list, UV* uv, u8* q, u8* pp, u64 tag, u64 mode) asm("func_002222b8");
void func_001f4d90(u8* obj, u8* in, Ctx* ctx) asm("func_001f4d90");
void func_001f4d90(u8* obj, u8* in, Ctx* ctx) {
    u8* p = obj + *ctx->off + 160;
    UV uv;
    uv.u = D_00354be0.u;
    uv.v = D_00354be0.v;
    u64 tag = 72;
    u64 mode = 0x51801;
    switch (in[84]) {
    case 0:
        break;
    case 1:
        tag = 66;
        break;
    default:
        tag = 0x80000000a8ULL;
        mode = 0x70000;
        break;
    }
    func_002222b8(p, D_01d9e900, &uv, p + 16, D_01d9eaa4, tag, mode);
}
}  // namespace n001f4d90

// 001f4e18 (was src/anon/batch_w1760_nsa.cpp)
namespace n001f4e18 {
void func_002223e0(void*) asm("func_002223e0");
// 0x00196328: definition moved into src/anon/unit_00195d00.cpp

struct W1760S2 { u8 pad[0x6c]; s32 a; u64 b, c, d, e; };
struct W1760S3 { u8 pad[0xc]; s32 a; u8 p2[0x24 - 0x10]; s32 b; u8 p3[4]; s32 c; };
/*TARGET 001f4e18*/
void func_001f4e18(u8* self, u8* t) asm("func_001f4e18");
void func_001f4e18(u8* self, u8* t) {
    u8* q = self + **(s32**)(t + 12);
    W1760S2* s = (W1760S2*)(q + 0xa0);
    W1760S3* r = (W1760S3*)(q + 0xb0);
    func_002223e0(s);
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->a = 0;
    r->a = 0;
    r->b = 0;
    r->c = 0;
}
}  // namespace n001f4e18

// 001f4e78 (gap, written for the unit)
namespace n001f4e78 {
struct W1760S2 { u8 pad[0x6c]; s32 a; u64 b, c, d, e; };
struct W1760S3 { u8 pad[0xc]; s32 a; u8 p2[0x24 - 0x10]; s32 b; u8 p3[4]; s32 c; };
void func_001f4e78(u8* self, u8* t) asm("func_001f4e78");
void func_001f4e78(u8* self, u8* t) {
    u8* q = self + **(s32**)(t + 12);
    W1760S2* s = (W1760S2*)(q + 0xa0);
    W1760S3* r = (W1760S3*)(q + 0xb0);
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->a = 0;
    r->a = 0;
    r->b = 0;
    r->c = 0;
}
}  // namespace n001f4e78

// 001f4eb0 (gap, written for the unit)
namespace n001f4eb0 {
void func_001f4eb0(void) asm("func_001f4eb0");
void func_001f4eb0(void) {}
}  // namespace n001f4eb0

// 001f4eb8 (was src/anon/batch_w1805_nsa.cpp)
namespace n001f4eb8 {
struct Sub { u8 pad[16]; f32 a; f32 c; f32 b; Sub* link; };
struct Ent { s32 x; u8* base; s32 y; s32 z; };
struct Mgr { u8 pad[0x80]; Ent* ents; u8 pad2[0xa8 - 0x84]; u64 flags; };
struct In { s32 id; f32 f4; f32 f8; f32 f12; s32 idx; s32 off; };
struct Obj { u8 pad[12]; s32 id; };
struct Ctx { u8 pad[12]; s32* off; };
// 0x001ae6a8: definition moved into src/anon/unit_001ada38.cpp

extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern Sub D_01d9e360 asm("D_01d9e360");
void func_002226b8(Sub*, u8*) asm("func_002226b8");
/*TARGET 001f4eb8*/
void func_001f4eb8(Obj* obj, In* in, Ctx* ctx) asm("func_001f4eb8");
void func_001f4eb8(Obj* obj, In* in, Ctx* ctx) {
    Sub* s = (Sub*)((u8*)obj + *ctx->off + 0xa0);
    if (obj->id == in->id) {
        s->a = in->f8;
        s->b = in->f4;
        s->c = in->f12;
        Sub* l;
        if (in->idx != -1) l = (Sub*)(D_01d9e6e0->ents[in->idx].base + in->off + 0xa0);
        else l = &D_01d9e360;
        s->link = l;
        if (l == &D_01d9e360) s->link = 0;
    }
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL))
        func_002226b8(s, D_01d9e6e8 + 0x40);
}
}  // namespace n001f4eb8

// 001f4f98 (gap, written for the unit)
namespace n001f4f98 {
struct S { u8 pad[12]; s32 a; u8 p2[12]; s32 b; };
void func_001f4f98(u8* self, u8* t) asm("func_001f4f98");
void func_001f4f98(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->b = 0;
    s->a = 0;
}
}  // namespace n001f4f98

// 001f4fb8 (gap, written for the unit)
namespace n001f4fb8 {
struct S { u8 pad[12]; f32 a; u8 p2[12]; s32 b; };
void func_001f4fb8(u8* self, u8* t) asm("func_001f4fb8");
void func_001f4fb8(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->b = 0;
    s->a = 1.0f;
}
}  // namespace n001f4fb8

// 001f4fe0 (was src/anon/tiny_wrappers_more.cpp)
namespace n001f4fe0 {
u32 func_00221fb8(u32, u32, u32, u32) asm("_Z13func_00221fb8jjjj");
/*TARGET 001f4fe0*/
u32 func_001f4fe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001f4fe0jjjj");
u32 func_001f4fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00221fb8(((u32)(((u32)(a0) + (u32)(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a1) + 12u)))) + 0u)))))) + 160u), 0x00000001u, 0x00000003u, a3);
}
}  // namespace n001f4fe0

