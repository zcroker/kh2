// Linked unit 0x001f5978-0x001f6298 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"

// 001f5978 (gap, written for the unit)
namespace n001f5978 {
struct S { u64 a, b, c, d; s32 e, f, g, h; };
void func_001f5978(u8* self, u8* t) asm("func_001f5978");
void func_001f5978(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    S* s = (S*)(b + 0xa0);
    s->g = 0;
    s->e = 0;
    s->f = 0;
    s->h = 0;
    *(u64*)(b + 160) = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
}
}  // namespace n001f5978

// 001f59b0 (was src/anon/batch_w3829b_nsa.c)
namespace n001f59b0 {
typedef struct { f32 x, y, z, w; } W2417Vec;
typedef struct { s16 x, y, z; } W2417Pt;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } W2417Mgr;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; u8 pad50[0x40]; W2417Pt* pts; } W2417Cam;
typedef struct { u8 pad[4]; void* owner; } W2417Ent;
typedef struct { s16 a; s16 cnt; u16* list; } W2417Grp;
typedef struct { u8 pad[0x14]; W2417Pt* pts; u8 pad18[0xc]; } W2417Mdl;
typedef struct { u8 pad[0x10]; W2417Mdl* mdl; u8 pad14[4]; W2417Grp* grp; } W2417Tab;
typedef struct { u8 pad[4]; s16 g0; s16 g1; u8 n; u8 mask; u8 rnd; u8 padb; s32 idx; s32 o10; s32 o14; s32 o18; } W2417Prm;
typedef struct { u8 pad[0xc]; s32* ofs; } W2417Ctx;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern W2417Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern W2417Tab* D_01d9e6e4 asm("D_01d9e6e4");
extern W2417Cam* D_01d9e6e8 asm("D_01d9e6e8");
s32 func_00222568(void) asm("func_00222568");
W2417Ent* func_001e7a98(W2417Mgr*, u8*) asm("func_001e7a98");
void sceVu0CopyMatrix(f32*, f32*) asm("sceVu0CopyMatrix");
void sceVu0ApplyMatrix(void*, void*, W2417Vec*) asm("sceVu0ApplyMatrix");
void func_00222730(void*, W2417Vec*, void*) asm("func_00222730");
/*TARGET 001f59b0*/
// 001f59b0: particle emitter variant (partMng): picks a point index (random or sequential), spawns an
// object per point, transforms the s16 point pairs by two matrices and stores the result.
// Partial asm (no extra code): the lui/lw of D_01d9e6e8 are single-instruction asms pinned to t7/a1 so
// sched2 keeps them after the arg setup like the original; the empty asm ties only add sched2 readers
// (t: idx so idx++ is issued before move v0,zero; a/q inputs place the lui after addiu s0 and before addu t6).
void func_001f59b0(void* owner, W2417Prm* prm_, W2417Ctx* c) asm("func_001f59b0");
// 001f59b0: particle emitter variant (partMng): picks a point index (random or sequential), spawns an
// object per point, transforms the s16 point pairs by two matrices and stores the result.
// Partial asm (no extra code): the lui/lw of D_01d9e6e8 are single-instruction asms pinned to t7/a1 so
// sched2 keeps them after the arg setup like the original; the empty asm ties only add sched2 readers
// (t: idx so idx++ is issued before move v0,zero; a/q inputs place the lui after addiu s0 and before addu t6).
void func_001f59b0(void* owner, W2417Prm* prm_, W2417Ctx* c)
{
    W2417Prm* prm = prm_;
    register s32 r asm("$17");
    W2417Grp* g;
    W2417Grp* g2;
    u8* base;
    u16* slot;
    W2417Pt* p0;
    W2417Pt* p1;
    s32 rnd;
    s32 idx;
    s32 n;
    f32 m[16];
    W2417Vec v;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    r = func_00222568();
    if (prm->mask == 255) return;
    if ((r >> 8) & prm->mask) return;
    if (prm->idx == -1) return;
    if (prm->o14 == -1) return;
    g = &D_01d9e6e4->grp[prm->g0];
    g2 = (W2417Grp*)((u32)(prm->g1 * 8) + (u32)D_01d9e6e4->grp);
    base = (u8*)owner + *c->ofs;
    slot = (u16*)(base + 160);
    p0 = D_01d9e6e8->pts;
    p1 = D_01d9e6e4->mdl[g2->a].pts;
    if (g->cnt != g2->cnt) return;
    if (p0 == 0) p0 = D_01d9e6e4->mdl[g->a].pts;
    rnd = prm->rnd;
    v.w = 1.0f;
    sceVu0CopyMatrix(m, D_01d9e6e8->m0);
    if (rnd != 0) idx = r % g->cnt;
    else idx = *slot;
    for (n = prm->n; n > 0; n--) {
        W2417Mgr* st; s32 k; u8* t; W2417Ent* e; u8* a; u8* q;
        { register u16* lp asm("$13") = (u16*)(idx * 2); lp = (u16*)((u8*)lp + (u32)g->list); idx++; k = *lp; }
        st = D_01d9e6e0;
        t = st->tbl + prm->idx * 16;
        asm("" : "+r"(t) : "r"(idx));
        e = 0;
        if (t != 0) {
            e = func_001e7a98(st, t);
            e->owner = owner;
        }
        k *= 6;
        a = (u8*)e + prm->o10 + 160;
        q = (u8*)e + prm->o18 + 160;
        {
        register u32 h asm("$15");
        register W2417Cam* cam asm("$5");
        u8* pp = (u8*)p0 + k;
        asm("lui %0,%%hi(D_01d9e6e8)" : "=r"(h) : "r"(a));
        asm("lw %0,%%lo(D_01d9e6e8)(%2)" : "=r"(cam), "+r"(pp) : "r"(h), "r"(q));
        v.x = *(s16*)(pp + 0);
        v.y = *(s16*)(pp + 2);
        v.z = *(s16*)(pp + 4);
        sceVu0ApplyMatrix(a, cam->m0, &v);
        }
        v.x = *(s16*)((u8*)p1 + k + 0);
        v.y = *(s16*)((u8*)p1 + k + 2);
        v.z = *(s16*)((u8*)p1 + k + 4);
        sceVu0ApplyMatrix(&v, m, &v);
        func_00222730(q, &v, D_01d9e6e8->m1);
        if (rnd != 0) {
            idx = func_00222568() % g->cnt;
        } else {
            if (!(idx < g->cnt)) idx = 0;
        }
    }
    *slot = idx;
}
}  // namespace n001f59b0

// 001f5cb0 (gap, written for the unit)
namespace n001f5cb0 {
void func_001f5cb0(u8* self, u8* t) asm("func_001f5cb0");
void func_001f5cb0(u8* self, u8* t) {
    *(s16*)(self + **(s32**)(t + 12) + 0xa0) = 0;
}
}  // namespace n001f5cb0

// 001f5cc8 (was src/anon/batch_w1833_nsa.cpp)
namespace n001f5cc8 {
// 001081c8: moved to src/anon/unit_00108068.cpp
struct W1833Vec { f32 x, y, z, w; };
struct W1833Mgr { u8 pad[0x80]; u8* tbl; };
struct W1833Cam { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; };
struct W1833Ent { u8 pad[4]; void* owner; };
struct W1833Prm { u8 pad[8]; f32 scale; u8 padc[4]; s32 idx; s32 o20; u8 pad18[4]; s32 o28; };
extern W1833Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern W1833Cam* D_01d9e6e8 asm("D_01d9e6e8");
W1833Ent* func_001e7a98(W1833Mgr*, u8*) asm("func_001e7a98");
void sceVu0ApplyMatrix(W1833Vec*, void*, W1833Vec*) asm("sceVu0ApplyMatrix");
void func_002226b8(void*, W1833Vec*) asm("func_002226b8");
void sceVu0SubVector(W1833Vec*, W1833Vec*, void*) asm("sceVu0SubVector");
void sceVu0Normalize(W1833Vec*, W1833Vec*) asm("sceVu0Normalize");
void sceVu0ScaleVector(W1833Vec*, W1833Vec*, f32) asm("sceVu0ScaleVector");
/*TARGET 001f5cc8*/
void func_001f5cc8(void* owner, W1833Prm* prm, s16* pos) asm("func_001f5cc8");
void func_001f5cc8(void* owner, W1833Prm* prm, s16* pos) {
    W1833Ent* e = 0;
    u8* t = D_01d9e6e0->tbl + prm->idx * 16;
    if (t != 0) {
        e = func_001e7a98(D_01d9e6e0, t);
        e->owner = owner;
    }
    u8* p1 = (u8*)e + prm->o28 + 160;
    u8* p0 = (u8*)e + prm->o20 + 160;
    W1833Vec v;
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    sceVu0ApplyMatrix(&v, D_01d9e6e8->m0, &v);
    func_002226b8(p0, &v);
    sceVu0SubVector(&v, &v, D_01d9e6e8->m1);
    sceVu0Normalize(&v, &v);
    sceVu0ScaleVector(&v, &v, prm->scale);
    func_002226b8(p1, &v);
}
}  // namespace n001f5cc8

// 001f5df8 (was src/anon/batch_w82.cpp)
namespace n001f5df8 {
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
struct Ev001f { u8 pad[4]; s16 f4; u8 pad2[6]; u8 f12; u8 f13; u8 f14; u8 pad3; s32 f16; s32 f20; s32 f24; };
s32 func_00222568(void) asm("func_00222568");
// vu_const_5f_d
void func_001f5cc8(void) asm("func_001f5cc8");
void func_0021ee48(u8*, Ev001f*, void*, u8*, s16, u8, u8) asm("func_0021ee48");
/*TARGET 001f5df8*/
// 0x001e1d20: definition moved into src/anon/unit_001e0cb8.cpp

void func_001f5df8(u8* a0, Ev001f* e, u8* a2) asm("func_001f5df8");
// 0x001e1d20: definition moved into src/anon/unit_001e0cb8.cpp

void func_001f5df8(u8* a0, Ev001f* e, u8* a2)
{
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (e->f13 == 255) return;
    if ((func_00222568() >> 8) & e->f13) return;
    if (e->f16 == -1) return;
    if (e->f24 == -1) return;
    func_0021ee48(a0, e, (void*)func_001f5cc8, a0 + **(u32**)(a2 + 12) + 160, e->f4, e->f14, e->f12);
}
}  // namespace n001f5df8

// 001f5ef8 (gap, written for the unit)
namespace n001f5ef8 {
void func_001f5ef8(u8* self, u8* t) asm("func_001f5ef8");
void func_001f5ef8(u8* self, u8* t) {
    *(s16*)(self + **(s32**)(t + 12) + 0xa0) = 0;
}
}  // namespace n001f5ef8

// 001f5f10 (was src/anon/batch_w1828_nsa.cpp)
namespace n001f5f10 {
struct S1f5 { s16 x, y, z; };
struct A1f5 { u8 pad[0xc]; s32 idx; s32 off10; s32 pad14; s32 off18; };
struct M1f5 { u8 pad[0x80]; u8* tbl; };
struct R1f5 { s32 f0; s32 f4; };
extern M1f5* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
R1f5* func_001e7a98(M1f5*, u8*) asm("func_001e7a98");
void func_002226b8(void*, f32*) asm("func_002226b8");
void sceVu0ApplyMatrix(f32*, void*, f32*) asm("sceVu0ApplyMatrix");
void sceVu0SubVector(f32*, f32*, void*) asm("sceVu0SubVector");
void sceVu0Normalize(f32*, f32*) asm("sceVu0Normalize");
/*TARGET 001f5f10*/
// 0x001bc568: definition moved into src/anon/unit_001bc568.cpp

void func_001f5f10(s32 id, A1f5* a, S1f5* s) asm("func_001f5f10");
// 0x001bc568: definition moved into src/anon/unit_001bc568.cpp

void func_001f5f10(s32 id, A1f5* a, S1f5* s) {
    f32 v[4] __attribute__((aligned(16)));
    R1f5* r = 0;
    u8* p = D_01d9e6e0->tbl + a->idx * 16;
    if (p) {
        r = func_001e7a98(D_01d9e6e0, p);
        r->f4 = id;
    }
    u8* d0 = (u8*)r + a->off10 + 0xa0;
    u8* d1 = (u8*)r + a->off18 + 0xa0;
    v[0] = s->x;
    v[1] = s->y;
    v[2] = s->z;
    v[3] = 1.0f;
    sceVu0ApplyMatrix(v, D_01d9e6e8 + 16, v);
    func_002226b8(d0, v);
    sceVu0SubVector(v, v, D_01d9e6e8 + 64);
    sceVu0Normalize(v, v);
    func_002226b8(d1, v);
}
}  // namespace n001f5f10

// 001f6030 (was src/anon/batch_w83.cpp)
namespace n001f6030 {
extern s32 D_01d9eab4 asm("D_01d9eab4");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001f5f10() asm("func_001f5f10");
s32 func_00222568(void) asm("func_00222568");
// vu_const_5f_d
void func_0021ee48(void*, void*, void (*)(), void*, s32, u32, u32) asm("func_0021ee48");
/*TARGET 001f6030*/
void func_001f6030(u8* p, u8* e, u8* c) asm("func_001f6030");
void func_001f6030(u8* p, u8* e, u8* c) {
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ull) return;
    if (e[7] == 255) return;
    if ((func_00222568() >> 8) & e[7]) return;
    if (*(s32*)(e + 12) == -1) return;
    if (*(s32*)(e + 20) == -1) return;
    func_0021ee48(p, e, func_001f5f10, p + **(s32**)(c + 12) + 160, *(s16*)(e + 4), e[8], e[6]);
}
}  // namespace n001f6030

// 001f6130 (gap, written for the unit)
namespace n001f6130 {
void func_001f6130(u8* self, u8* t) asm("func_001f6130");
void func_001f6130(u8* self, u8* t) {
    *(s16*)(self + **(s32**)(t + 12) + 0xa0) = 0;
}
}  // namespace n001f6130

// 001f6148 (was src/anon/batch_w3713_nsa.cpp)
namespace n001f6148 {
struct V6148 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct St6148 { u8 pad[0x80]; u8* tbl; };
struct A6148 { u8 pad[8]; f32 f8; u8 p0[4]; s32 f10; s32 f14; u8 p1[4]; s32 f1c; u8 p2[4]; s32 f24; };
struct R6148 { u8 pad[4]; s32 f4; };
extern St6148* D_01d9e6e0 asm("D_01d9e6e0");
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
R6148* func_001e7a98(St6148*, u8*) asm("func_001e7a98");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void func_002226b8(void*, void*) asm("func_002226b8");
void sceVu0SubVector(void*, void*, void*) asm("sceVu0SubVector");
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
/*TARGET 001f6148*/
// Spawns an effect object from the manager table and runs a point through three matrix stages,
// storing results into three of the object's slots.
void func_001f6148(s32 a0, A6148* a, s16* pos) asm("func_001f6148");
// Spawns an effect object from the manager table and runs a point through three matrix stages,
// storing results into three of the object's slots.
void func_001f6148(s32 a0, A6148* a, s16* pos)
{
    St6148* st = D_01d9e6e0;
    u8* e = st->tbl + a->f10 * 16;
    R6148* r = 0;
    if (e) { r = func_001e7a98(st, e); r->f4 = a0; }
    V6148 v; v.x = pos[0]; v.y = pos[1]; v.z = pos[2]; v.w = 1.0f;
    u8* p0 = (u8*)r + a->f14 + 160;
    u8* p2 = (u8*)r + a->f1c + 160;
    u8* p1 = (u8*)r + a->f24 + 160;
    sceVu0ApplyMatrix(&v, D_01d9e6e8 + 16, &v);
    func_002226b8(p0, &v);
    sceVu0SubVector(&v, &v, D_01d9e6e8 + 64);
    sceVu0Normalize(&v, &v);
    func_002226b8(p1, &v);
    sceVu0ScaleVector(&v, &v, a->f8);
    func_002226b8(p2, &v);
}
}  // namespace n001f6148

