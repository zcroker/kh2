// Linked unit 0x001fa1b8-0x001fb350 (ppp programs and sprite wrappers; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
struct BD_VALUE;
#include "./auto80_199_queue_decls.hpp"
#include "./auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 001fa1b8 (gap, written for the unit)
namespace n001fa1b8 {
struct S { u64 a, b, c, d, e, f; u8 pad[496 - 48]; s32 w; s16 h; u8 p2[2]; s16 r; u8 b6; };
s32 func_002fea18(void) asm("func_002fea18");
void func_001fa1b8(u8* self, u8* t) asm("func_001fa1b8");
void func_001fa1b8(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    S* s = (S*)(b + 0xa0);
    s->b6 = 0;
    s->h = 0;
    s->w = 0;
    s->r = func_002fea18();
    *(u64*)(b + 160) = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
}
}  // namespace n001fa1b8

// 001fa218 (gap, written for the unit)
namespace n001fa218 {
struct S { u64 a, b, c, d, e, f; };
void func_001fa218(u8* self, u8* t) asm("func_001fa218");
void func_001fa218(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    S* s = (S*)(b + 0xa0);
    *(u64*)(b + 160) = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
}
}  // namespace n001fa218

// 001fa248 (gap, written for the unit)
namespace n001fa248 {
void func_001fa248(void) asm("func_001fa248");
void func_001fa248(void) {}
}  // namespace n001fa248

// 001fa250 (gap, written for the unit)
namespace n001fa250 {
void func_001fa250(void) asm("func_001fa250");
void func_001fa250(void) {}
}  // namespace n001fa250

// 001fa258 (gap, written for the unit)
namespace n001fa258 {
void func_001fa258(void) asm("func_001fa258");
void func_001fa258(void) {}
}  // namespace n001fa258

// 001fa260 (gap, written for the unit)
namespace n001fa260 {
void func_001fa260(void) asm("func_001fa260");
void func_001fa260(void) {}
}  // namespace n001fa260

// 001fa268 (gap, written for the unit)
namespace n001fa268 {
void func_001fa268(void) asm("func_001fa268");
void func_001fa268(void) {}
}  // namespace n001fa268

// 001fa270 (gap, written for the unit)
namespace n001fa270 {
void func_001fa270(void) asm("func_001fa270");
void func_001fa270(void) {}
}  // namespace n001fa270

// 001fa278 (gap, written for the unit)
namespace n001fa278 {
struct S { u8 a, b; s16 c, d; u8 p[2]; u8 e; };
void func_001fa278(u8* self, u8* t) asm("func_001fa278");
void func_001fa278(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->a = 31;
    s->c = 0;
    s->d = 0;
    s->b = 0;
    s->e = 0;
}
}  // namespace n001fa278

// 001fa2a8 (gap, written for the unit)
namespace n001fa2a8 {
void func_001fa2a8(void) asm("func_001fa2a8");
void func_001fa2a8(void) {}
}  // namespace n001fa2a8

// 001fa2b0 (was src/anon/batch_w2331_gnsa.c)
namespace n001fa2b0 {
/* Plain C (partMng family), built without strict aliasing. -g makes no difference here; the name is _gnsa
   only because batch_wcx2_nsa.c / _gnsa.c would share an object name with the workspace .cpp files. */

/* 001fa2b0: particle position integrate, then build and submit a sprite render request. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1fa2b0;
typedef struct {
    V1fa2b0 a;
    V1fa2b0 col;
    void* p32;
    u32 w36;
    void* p40;
    s32 w44;
    V1fa2b0 b;
    u64 q64;
    u64 q72;
    u64 q80;
    f32 f88;
    f32 f92;
} Req1fa2b0;
typedef struct { s32 f0; f32 f4, f8, f12, f16, f20; u8 b24; u8 b25; } Ent1fa2b0;
typedef struct { u8 pad0[12]; s32* off; } Ctx1fa2b0;
typedef struct { u8 pad0[168]; u64 flags; } Cur1fa2b0;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Cur1fa2b0* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u32 D_01d9eaa4 asm("D_01d9eaa4");
extern u32 D_01d9eaa8 asm("D_01d9eaa8");
extern f32 D_00354be0[] asm("D_00354be0");
extern "C" s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18 asm("D_00352c18");
void sceVu0ApplyMatrix(V1fa2b0*, V1fa2b0*, V1fa2b0*) asm("sceVu0ApplyMatrix");
void func_00222f88(Req1fa2b0*) asm("func_00222f88");
s32 func_002231b8(Req1fa2b0*) asm("func_002231b8");
void func_0020e7a8(u32, u32, s32, s32) asm("func_0020e7a8");
void func_0020e858(u32, u32, s32, s32) asm("func_0020e858");
/*TARGET 001fa2b0*/
void func_001fa2b0(u8* base, Ent1fa2b0* e, Ctx1fa2b0* c) asm("func_001fa2b0");
void func_001fa2b0(u8* base, Ent1fa2b0* e, Ctx1fa2b0* c)
{
    f32* pos = (f32*)(base + c->off[0] + 160);
    V1fa2b0* m = (V1fa2b0*)(base + c->off[2] + 160);
    u8* col;
    Req1fa2b0 r;
    if (D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
        f32 ax = pos[2];
        f32 vx = pos[1] + ax;
        f32 x = pos[0] + vx;
        pos[1] = vx;
        pos[0] = x;
        if (*(s32*)(base + 12) == e->f0) {
            pos[0] = x + e->f4;
            pos[1] = vx + e->f8;
            pos[2] = ax + e->f12;
        }
    }
    col = base + c->off[1] + 160;
    r.col.x = col[8];
    r.col.y = col[9];
    r.col.z = col[10];
    r.col.w = col[11];
    if (e->b25 & 2) {
        f32* q = (f32*)(base + c->off[3] + 160);
        r.a.x = q[0];
        r.a.y = q[1];
        r.a.z = 512.0f;
        r.a.w = 1.0f;
        r.p40 = D_01d9e8c0;
    } else {
        r.a = m[3];
        r.p40 = D_01d9e8c0;
    }
    r.f88 = e->f16 * D_00354be0[0];
    r.p32 = D_01d9e8c0;
    r.w36 = D_01d9eaa4 + 16;
    r.f92 = e->f20 * D_00354be0[1];
    if (e->b24 == 0) {
        r.q64 = (D_00352bf8 << 5) | ((u64)(D_00352bec / 64) << 14) | ((u64)85 << 27);
        r.q80 = ((2048 - D_00352bec / 2) << 4) | ((u64)(2048 - D_00352bf0 / 2) << 36);
    } else {
        r.q64 = (D_00352bfc << 5) | ((u64)(D_00352be4 / 64) << 14) | ((u64)85 << 27);
        r.q80 = ((2048 - D_00352be4 / 2) << 4) | ((u64)(2048 - D_00352be8 / 2) << 36);
    }
    r.q72 = D_00352c18;
    r.b.x = r.b.z = r.b.w = 0.0f;
    r.b.y = -pos[0];
    sceVu0ApplyMatrix(&r.b, m, &r.b);
    *(s32*)&r.b.w = e->b25;
    func_00222f88(&r);
    if (func_002231b8(&r)) {
        if (e->b25 & 2) func_0020e7a8(D_01d9eaa4, (r.w36 - D_01d9eaa4) >> 4, 4, 0);
        else func_0020e858(D_01d9eaa4, (r.w36 - D_01d9eaa4) >> 4, r.w44 / 12288, 0);
        D_01d9eaa8 += r.w36 - D_01d9eaa4;
        D_01d9eaa4 = r.w36;
    }
}
}  // namespace n001fa2b0

// 001fa5f8 (gap, written for the unit)
namespace n001fa5f8 {
void func_001fa5f8(u8* self, u8* t) asm("func_001fa5f8");
void func_001fa5f8(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    *(u64*)(b + 160) = 0;
    *(u32*)(b + 168) = 0;
}
}  // namespace n001fa5f8

// 001fa610 (was src/anon/batch_w1671.cpp)
namespace n001fa610 {
/*TARGET 001fa610*/
void func_001fa610(u8* a0, u8* a1, u8* a2) asm("func_001fa610");
void func_001fa610(u8* a0, u8* a1, u8* a2) {
    u8* p = a0 + **(s32**)(a2 + 0xc) + 160;
    if (*(s32*)a1 == *(s32*)(a0 + 0xc)) {
        *(f32*)(p + 0xa8) += *(f32*)(a1 + 8);
        p[0x8e] = a1[0xc];
        *(f32*)(p + 0x9c) += *(f32*)(a1 + 4);
        p[0x8f] = a1[0xd];
    }
}
}  // namespace n001fa610

// 001fa668 (was src/anon/batch_w1807_nsa.cpp)
namespace n001fa668 {
typedef unsigned int w1807_u128 __attribute__((mode(TI)));
// ---- 001fa668
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void func_002226b8(u8*, void*) asm("func_002226b8");
void func_0021f0d8(void*) asm("func_0021f0d8");
struct W1807V4 { f32 x, y, z, w; };
struct W1807Arg { u8* s; u8* m; void* a; void* b; };
/*TARGET 001fa668*/
void func_001fa668(u8* a, u32 a1, u8* c) asm("func_001fa668");
void func_001fa668(u8* a, u32 a1, u8* c) {
    u8* d = a + **(u32**)(c + 12);
    u8* s = d + 160;
    W1807V4 v;
    if (s[143]) {
        *(w1807_u128*)&v = 0;
        v.w = v.z = 1.0f;
        sceVu0ApplyMatrix(&v, D_01d9e6e8 + 16, &v);
        func_002226b8(d + 304, &v);
    }
    *(f32*)(s + 128) = *(f32*)(D_01d9e6e8 + 64);
    *(f32*)(s + 132) = *(f32*)(D_01d9e6e8 + 68);
    *(f32*)(s + 136) = *(f32*)(D_01d9e6e8 + 72);
    W1807Arg g;
    g.a = D_01d9e840; g.m = D_01d9e6e8 + 64; g.b = D_01d9e8c0; g.s = s;
    func_0021f0d8(&g);
}
}  // namespace n001fa668

// 001fa750 (gap, written for the unit)
namespace n001fa750 {
struct S { u8 pad[156]; s32 a; u8 p2[8]; s32 b; };
void func_0021f5d8(S*) asm("func_0021f5d8");
void func_001fa750(u8* self, u8* t) asm("func_001fa750");
void func_001fa750(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    func_0021f5d8(s);
    s->a = 0;
    s->b = 0;
}
}  // namespace n001fa750

// 001fa790 (gap, written for the unit)
namespace n001fa790 {
struct S { u8 pad[156]; s32 a; u8 p2[8]; s32 b; };
void func_001fa790(u8* self, u8* t) asm("func_001fa790");
void func_001fa790(u8* self, u8* t) {
    S* s = (S*)(self + **(s32**)(t + 12) + 0xa0);
    s->a = 0;
    s->b = 0;
}
}  // namespace n001fa790

// 001fa7b0 (was src/anon/auto80_199_queue.cpp)
namespace n001fa7b0 {
/*TARGET 001fa7b0*/
void func_001fa7b0(u32 a0, u32 a1, u32 a2) asm("_Z13func_001fa7b0jjj");
void func_001fa7b0(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 t7c = 0x01da0000;
    volatile u32* gp = (volatile u32*)t7c;
    u32 t4p = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == t4p) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}
}  // namespace n001fa7b0

// 001fa830 (was src/anon/tiny.cpp)
namespace n001fa830 {
void func_001fa7b0(void*) asm("_Z13func_001fa7b0Pv");
/*TARGET 001fa830*/
// 0x001e6630: definition moved into src/anon/unit_001e0cb8.cpp
void func_001fa830(BD_VALUE* bd) asm("_Z13func_001fa830P8BD_VALUE");
// 0x001e6630: definition moved into src/anon/unit_001e0cb8.cpp
void func_001fa830(BD_VALUE* bd) { func_001fa7b0(bd); }
}  // namespace n001fa830

// 001fa848 (gap, written for the unit)
namespace n001fa848 {
struct Mgr { u8 pad[48]; f32 s[4]; };
struct Prm { u8 pad[8]; u8 c[4]; f32 f; };
struct Ctx { u8 pad[12]; s32* off; };
struct Spr { u8* p; u8 c[4]; void* tex; f32 f; void* uv; };
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_00354be0[] asm("D_00354be0");
void func_0021fa28(Spr*, s32) asm("func_0021fa28");
void func_001fa848(u8* o, Prm* prm, Ctx* c) asm("func_001fa848");
void func_001fa848(u8* o, Prm* prm, Ctx* c) {
    Spr s;
    Mgr* m = D_01d9e6e0;
    s.c[0] = (s32)((f32)prm->c[0] * m->s[0]);
    s.c[1] = (s32)((f32)prm->c[1] * m->s[1]);
    s.c[2] = (s32)((f32)prm->c[2] * m->s[2]);
    s.c[3] = (s32)((f32)prm->c[3] * m->s[3]);
    s.f = prm->f;
    s.tex = D_01d9e8c0;
    s.uv = D_00354be0;
    s.p = o + *c->off + 160;
    func_0021fa28(&s, 0);
}
}  // namespace n001fa848

// 001fa928 (was src/anon/batch_w4.cpp)
namespace n001fa928 {
void func_0021fbc0(void*) asm("func_0021fbc0");
/*TARGET 001fa928*/
void func_001fa928(u8* p, u8* q) asm("func_001fa928");
void func_001fa928(u8* p, u8* q) {
    func_0021fbc0(p + *(s32*)*(u32*)(q + 12) + 160);
}
}  // namespace n001fa928

// 001fa950 (was src/anon/auto80_199_queue.cpp)
namespace n001fa950 {
/*TARGET 001fa950*/
void func_001fa950(u32 a0, u32 a1, u32 a2) asm("_Z13func_001fa950jjj");
void func_001fa950(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 s1 = t4 + 160;

    if (t5 == t6) {
        u32 t7b = *(u32*)(t3 + 4);
        u32 t7p = a0 + t7b + 160;
        *(u32*)(t4 + 160) = t7p;

        u32 t6b = *(u32*)(a1 + 4);
        if (t6b == 0xFFFF) {
            *(u32*)(s1 + 4) = 0;
        } else {
            u32 t3off = t6b << 3;
            u32 k = 0x01da0000;
            volatile u32* gp = (volatile u32*)k;
            u32 oldp = *(u32*)(s1 + 4);
            u32 t6c = gp[-1607];
            u32 t5c = *(u32*)(t6c + 20);
            u32 t7c = t5c + t3off;
            if (t7c != oldp) {
                u32 a2c = *(u8*)(s0 + 22);
                func_0021f908(s1, t7c, a2c);
            }
        }

        u16 t7h = *(u16*)(s0 + 18);
        *(u16*)(s1 + 10) = t7h;
        u16 t6h = *(u16*)(s0 + 16);
        *(u16*)(s1 + 12) = t6h;
        u8 t7u = *(u8*)(s0 + 23);
        *(u8*)(s1 + 14) = t7u;
    }
}
}  // namespace n001fa950

// 001faa00 (gap, written for the unit)
namespace n001faa00 {
void func_001fa950(u8*, u8*, u8*) asm("_Z13func_001fa950jjj");
void func_001faa00(u8* a, u8* b, u8* c) asm("func_001faa00");
void func_001faa00(u8* a, u8* b, u8* c) { func_001fa950(a, b, c); }
}  // namespace n001faa00

// 001faa18 (gap, written for the unit)
namespace n001faa18 {
struct Mgr { u8 pad[48]; f32 s[4]; };
struct Prm { u8 pad[8]; u8 c[4]; f32 f; u8 p2[4]; u16 h; };
struct Ctx { u8 pad[12]; s32* off; };
struct Spr { u8* p; u8 c[4]; void* tex; f32 f; f32 h; void* uv; };
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_00354be0[] asm("D_00354be0");
void func_0021f620(Spr*, s32) asm("func_0021f620");
void func_001faa18(u8* o, Prm* prm, Ctx* c) asm("func_001faa18");
void func_001faa18(u8* o, Prm* prm, Ctx* c) {
    Spr s;
    Mgr* m = D_01d9e6e0;
    s.h = prm->h;
    s.c[0] = (s32)((f32)prm->c[0] * m->s[0]);
    s.c[1] = (s32)((f32)prm->c[1] * m->s[1]);
    s.c[2] = (s32)((f32)prm->c[2] * m->s[2]);
    s.c[3] = (s32)((f32)prm->c[3] * m->s[3]);
    s.f = prm->f;
    s.tex = D_01d9e8c0;
    s.p = o + *c->off + 160;
    s.uv = D_00354be0;
    func_0021f620(&s, 0);
}
}  // namespace n001faa18

// 001fab08 (was src/anon/batch_w19.cpp)
namespace n001fab08 {
void func_0021fa10(void*) asm("func_0021fa10");
/*TARGET 001fab08*/
void func_001fab08(u8* p, u8* q) asm("func_001fab08");
void func_001fab08(u8* p, u8* q) {
    u8* s = p + **(s32**)(q + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}
}  // namespace n001fab08

// 001fab48 (was src/anon/batch_w60.cpp)
namespace n001fab48 {
extern u8* D_01d9e6e4 asm("D_01d9e6e4");
// vec4_normalize
void func_0021fe08(void*, u32) asm("func_0021fe08");
// 0x001e7d20: definition moved into src/anon/unit_001e0cb8.cpp

void func_001fab48(u8* a, u32* b, u8* c) asm("_Z13func_001fab48Pv");
/*TARGET 001fab48*/
void func_001fab48(u8* a, u32* b, u8* c) asm("_Z13func_001fab48Pv");
void func_001fab48(u8* a, u32* b, u8* c) {
    u32* offs = *(u32**)(c + 12);
    u8* t = a + offs[0];
    u8* q = t + 160;
    if (b[0] != *(u32*)(a + 12)) return;
    *(u32*)(t + 160) = (u32)(a + offs[1] + 160);
    if (b[1] == 0xffff) {
        *(u32*)(q + 4) = 0;
        return;
    }
    u32 x = *(u32*)(D_01d9e6e4 + 20) + b[1] * 8;
    if (x != *(u32*)(q + 4)) func_0021fe08(q, x);
}
}  // namespace n001fab48

// 001fabc8 (was src/anon/tiny.cpp)
namespace n001fabc8 {
void func_001fab48(void*) asm("_Z13func_001fab48Pv");
/*TARGET 001fabc8*/
void func_001fabc8(BD_VALUE* bd) asm("_Z13func_001fabc8P8BD_VALUE");
void func_001fabc8(BD_VALUE* bd) { func_001fab48(bd); }
}  // namespace n001fabc8

// 001fabe0 (gap, written for the unit)
namespace n001fabe0 {
struct Mgr { u8 pad[48]; f32 s[4]; };
struct Prm { u8 pad[8]; u8 c[4]; f32 f; u16 h0, h1; };
struct Ctx { u8 pad[12]; s32* off; };
struct Spr { u8* p; u8 c[4]; void* tex; f32 f; u16 h0, h1; void* uv; };
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_00354be0[] asm("D_00354be0");
void func_0021fbd8(Spr*, s32) asm("func_0021fbd8");
void func_001fabe0(u8* o, Prm* prm, Ctx* c) asm("func_001fabe0");
void func_001fabe0(u8* o, Prm* prm, Ctx* c) {
    Spr s;
    Mgr* m = D_01d9e6e0;
    s.c[0] = (s32)((f32)prm->c[0] * m->s[0]);
    s.c[1] = (s32)((f32)prm->c[1] * m->s[1]);
    s.c[2] = (s32)((f32)prm->c[2] * m->s[2]);
    s.c[3] = (s32)((f32)prm->c[3] * m->s[3]);
    s.h0 = prm->h0;
    s.h1 = prm->h1;
    s.f = prm->f;
    s.tex = D_01d9e8c0;
    s.p = o + *c->off + 160;
    s.uv = D_00354be0;
    func_0021fbd8(&s, 0);
}
}  // namespace n001fabe0

// 001facd0 (was src/anon/batch_w5.cpp)
namespace n001facd0 {
// 0x1c8a90: moved to src/yasui/libys/summon.cpp

void func_0021fe28(u8*) asm("func_0021fe28");
/*TARGET 001facd0*/
void func_001facd0(u8* base, u8* o) asm("func_001facd0");
void func_001facd0(u8* base, u8* o) {
    func_0021fe28(base + **(s32**)(o + 12) + 160);
}
}  // namespace n001facd0

// 001facf8 (was src/anon/auto80_199_queue.cpp)
namespace n001facf8 {
/*TARGET 001facf8*/
void func_001facf8(u32 a0, u32 a1, u32 a2) asm("_Z13func_001facf8jjj");
void func_001facf8(u32 a0, u32 a1, u32 a2) {
    u32 t3 = *(u32*)(a2 + 12);
    u32 t5 = *(u32*)(a1 + 0);
    u32 t7 = *(u32*)(t3 + 0);
    u32 t6 = *(u32*)(a0 + 12);
    u32 t4 = a0 + t7;
    u32 t2 = t4 + 160;

    if (t5 != t6) {
        return;
    }

    u32 t7b = *(u32*)(t3 + 4);
    u32 t7p = a0 + t7b + 160;
    *(u32*)(t4 + 160) = t7p;

    u32 t6b = *(u32*)(a1 + 4);
    if (t6b == 0xFFFF) {
        *(u32*)(t2 + 4) = 0;
        return;
    }

    u32 t3off = t6b << 3;
    u32 k = 0x01da0000;
    volatile u32* gp = (volatile u32*)k;
    u32 oldp = *(u32*)(t2 + 4);
    u32 t6c = gp[-1607];
    u32 t5c = *(u32*)(t6c + 20);
    u32 t5ptr = t5c + t3off;
    if (t5ptr == oldp) {
        return;
    }

    *(u32*)(t2 + 4) = t5ptr;
    u32 t7d = *(u32*)(t5ptr + 0);
    u16 t6h = *(u16*)(t7d + 18);
    *(u8*)(t2 + 10) = 0;
    *(u16*)(t2 + 8) = t6h;
}
}  // namespace n001facf8

// 001fad78 (was src/anon/tiny.cpp)
namespace n001fad78 {
void func_001facf8(void*) asm("_Z13func_001facf8Pv");
/*TARGET 001fad78*/
void func_001fad78(BD_VALUE* bd) asm("_Z13func_001fad78P8BD_VALUE");
void func_001fad78(BD_VALUE* bd) { func_001facf8(bd); }
}  // namespace n001fad78

// 001fad90 (gap, written for the unit)
namespace n001fad90 {
struct Mgr { u8 pad[48]; f32 s[4]; };
struct Prm { u8 pad[8]; u8 c[4]; f32 f; u16 h0, h1; };
struct Ctx { u8 pad[12]; s32* off; };
struct Spr { u8* p; u8 c[4]; void* tex; f32 f; u16 h0, h1; void* uv; };
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_00354be0[] asm("D_00354be0");
void func_0021fe40(Spr*, s32) asm("func_0021fe40");
void func_001fad90(u8* o, Prm* prm, Ctx* c) asm("func_001fad90");
void func_001fad90(u8* o, Prm* prm, Ctx* c) {
    Spr s;
    Mgr* m = D_01d9e6e0;
    s.c[0] = (s32)((f32)prm->c[0] * m->s[0]);
    s.c[1] = (s32)((f32)prm->c[1] * m->s[1]);
    s.c[2] = (s32)((f32)prm->c[2] * m->s[2]);
    s.c[3] = (s32)((f32)prm->c[3] * m->s[3]);
    s.f = prm->f;
    s.h0 = prm->h0;
    s.h1 = prm->h1;
    s.tex = D_01d9e8c0;
    s.p = o + *c->off + 160;
    s.uv = D_00354be0;
    func_0021fe40(&s, 0);
}
}  // namespace n001fad90

// 001fae80 (was src/anon/batch_w1.cpp)
namespace n001fae80 {
void func_00220070(void*) asm("func_00220070");
/*TARGET 001fae80*/
// 0x0018f2d0: definition moved into src/anon/unit_0018f140.cpp

// 001a8548: moved to src/anon/unit_001a82f0.cpp

// 001ac778: moved to src/anon/unit_001abb28.cpp

// 001c8de0 func_001c8de0: moved to src/yasui/libys/mutex.cpp (linked unit).

void func_001fae80(u8* p, u8* q) asm("func_001fae80");
// 0x0018f2d0: definition moved into src/anon/unit_0018f140.cpp

// 001a8548: moved to src/anon/unit_001a82f0.cpp

// 001ac778: moved to src/anon/unit_001abb28.cpp

// 001c8de0 func_001c8de0: moved to src/yasui/libys/mutex.cpp (linked unit).

void func_001fae80(u8* p, u8* q) {
    func_00220070(p + **(s32**)(q + 12) + 160);
}
}  // namespace n001fae80


// 001faea8 (was whole asm src/anon/asm_001faea8.s; C since 2026-11-19)
// partMng: builds the GS draw-environment packet (sceGsDrawEnv1 layout), then every (step+1) frames projects the
// object's position, clips a w*h box to the scissor rectangle, reads that part of the z-buffer back
// (sceGsSetDefStoreImage / sceGsExecStoreImage shapes) and counts the pixels nearer than the object:
// vis = count / (w*h), alpha *= vis.
// Matching notes: the three store-image calls return int (unused); the scissor Y0 temp reuses the loop counter k
// and is read first; the loop walks its own pointer q so the buffer pointer p stays cold.
namespace n001faea8 {
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct { u64 FBP:9; u64 p0:7; u64 FBW:6; u64 p1:2; u64 PSM:6; u64 p2:2; u64 FBMSK:32; } GsFrame4ea8;
typedef struct { u64 ZBP:9; u64 p0:15; u64 PSM:4; u64 p1:4; u64 ZMSK:1; u64 p2:31; } GsZbuf4ea8;
typedef struct { u64 OFX:16; u64 p0:16; u64 OFY:16; u64 p1:16; } GsXyoffset4ea8;
typedef struct { u64 SCAX0:11; u64 p0:5; u64 SCAX1:11; u64 p1:5; u64 SCAY0:11; u64 p2:5; u64 SCAY1:11; u64 p3:5; } GsScissor4ea8;
typedef struct {
    union { u128 q; struct { GsFrame4ea8 v; u64 addr; } r; } frame;
    union { u128 q; struct { GsZbuf4ea8 v; u64 addr; } r; } zbuf;
    union { u128 q; struct { GsXyoffset4ea8 v; u64 addr; } r; } xyoffset;
    union { u128 q; struct { GsScissor4ea8 v; u64 addr; } r; } scissor;
    union { u128 q; struct { u64 v; u64 addr; } r; } prmodecont;
    union { u128 q; struct { u64 v; u64 addr; } r; } colclamp;
    union { u128 q; struct { u64 v; u64 addr; } r; } dthe;
    union { u128 q; struct { u64 v; u64 addr; } r; } test;
} Env4ea8;
typedef struct { s32 x, y, z, w; } Pt4ea8;
typedef struct { s32 x0, y0, x1, y1; } Rect4ea8;
typedef struct {
    u8 pad0[124]; f32 alpha;        /* 0x7c */
    u8 pad80[12]; u8 phase;         /* 0x8c */
    u8 step;                        /* 0x8d */
    u8 pad8e[30]; f32 vis;          /* 0xac */
    f32 pos[4];                     /* 0xb0 */
    u8 w, h;                        /* 0xc0 */
} Obj4ea8;
extern u64 D_00352c00 asm("D_00352c00");
extern u64 D_00352c08 asm("D_00352c08");
extern u64 D_00352c10 asm("D_00352c10");
extern u64 D_00352c18 asm("D_00352c18");
extern u64 D_00352c20 asm("D_00352c20");
extern u64 D_00352c28 asm("D_00352c28");
extern u64 D_00352c30 asm("D_00352c30");
extern Env4ea8 D_01da8ad0 asm("D_01da8ad0");
void* func_0020eaf8(s32) asm("func_0020eaf8");
void func_0020ebd8(s32) asm("func_0020ebd8");
void func_002f3fc0(Pt4ea8*, f32*) asm("func_002f3fc0");
int func_002f2aa0(void*, s16, s16, s16, s16, s16, s16, s16) asm("func_002f2aa0");
void func_003058a0(s32) asm("func_003058a0");
int func_002f2d60(void*, u8*) asm("func_002f2d60");
int func_002f25a0(s32, s32) asm("func_002f25a0");
void func_001faea8(Obj4ea8* o, s32 unused, s32 frame) asm("func_001faea8");
void func_001faea8(Obj4ea8* o, s32 unused, s32 frame)
{
    Env4ea8* e;
    Pt4ea8 scr;
    Rect4ea8 r;
    Rect4ea8 c;
    u8 work[112];
    s32 a, n, nx, ny, sx, sy, bw, k, w, h;
    u32 zlim;
    u8* p;
    u8* q;
    GsScissor4ea8 sc;
    s32 sx0, sx1, sy1;
    f32 sum;
    *(u128*)((u32)&D_01da8ad0 + 0) = D_00352c00;
    *(u128*)((u32)&D_01da8ad0 + 16) = D_00352c08;
    *(u128*)((u32)&D_01da8ad0 + 32) = D_00352c10;
    *(u128*)((u32)&D_01da8ad0 + 48) = D_00352c18;
    *(u128*)((u32)&D_01da8ad0 + 64) = 0;
    *(u128*)((u32)&D_01da8ad0 + 80) = D_00352c30;
    *(u128*)((u32)&D_01da8ad0 + 96) = D_00352c28;
    *(u128*)((u32)&D_01da8ad0 + 112) = D_00352c20;
    D_01da8ad0.frame.r.addr = 0x4c;
    D_01da8ad0.zbuf.r.addr = 0x4e;
    D_01da8ad0.xyoffset.r.addr = 0x18;
    D_01da8ad0.scissor.r.addr = 0x40;
    D_01da8ad0.prmodecont.r.addr = 0x1a;
    D_01da8ad0.colclamp.r.addr = 0x46;
    D_01da8ad0.dthe.r.addr = 0x45;
    D_01da8ad0.test.r.addr = 0x47;
    if (o->alpha == 0.0f) return;
    n = o->step + 1;
    if (o->phase % n != frame % n) {
        o->alpha = o->alpha * o->vis;
        return;
    }
    e = &D_01da8ad0;
    sx = e->xyoffset.r.v.OFX;
    sy = e->xyoffset.r.v.OFY;
    sc = e->scissor.r.v;
    k = sc.SCAY0;
    sx0 = sc.SCAX0;
    sx1 = sc.SCAX1;
    sy1 = sc.SCAY1;
    c.x0 = sx + (sx0 << 4);
    c.y0 = sy + (k << 4);
    c.x1 = sx + ((sx1 + 1) << 4);
    c.y1 = sy + ((sy1 + 1) << 4);
    func_002f3fc0(&scr, o->pos);
    w = o->w;
    h = o->h;
    r.x0 = scr.x - w * 8;
    r.y0 = scr.y - h * 8;
    r.x1 = scr.x + w * 8;
    r.y1 = scr.y + h * 8;
    if (r.x0 < c.x0) r.x0 = c.x0; else if (r.x0 > c.x1) r.x0 = c.x1;
    if (r.y0 < c.y0) r.y0 = c.y0; else if (r.y0 > c.y1) r.y0 = c.y1;
    if (r.x1 < c.x0) r.x1 = c.x0; else if (r.x1 > c.x1) r.x1 = c.x1;
    if (r.y1 < c.y0) r.y1 = c.y0; else if (r.y1 > c.y1) r.y1 = c.y1;
    nx = (r.x1 - r.x0 + 15) >> 4;
    ny = (r.y1 - r.y0 + 15) >> 4;
    if (nx <= 0 || ny <= 0) {
        o->alpha = 0.0f;
        o->vis = 0.0f;
        return;
    }
    sum = 0.0f;
    sx = (r.x0 - sx) >> 4;
    sy = (r.y0 - sy) >> 4;
    bw = (nx + 7) & ~7;
    a = (ny + 3) & ~3;
    p = (u8*)func_0020eaf8(0x3060);
    func_002f2aa0(work, (*(u16*)&e->zbuf & 0x1ff) << 5, e->frame.r.v.FBW, 49, sx, sy, bw, a);
    p += 96;
    func_003058a0(0);
    func_002f2d60(work, p);
    func_002f25a0(0, 0);
    zlim = scr.z >> 4;
    q = p;
    for (n = 0; n < ny; n++) {
        for (k = 0; k < nx; k++) {
            if ((u32)(q[0] | (q[1] << 8) | (q[2] << 16)) < zlim) sum += 1.0f;
            q += 3;
        }
        q += (bw - nx) * 3;
    }
    func_0020ebd8(0x3060);
    sum = sum / (f32)(w * h);
    o->vis = sum;
    o->alpha = o->alpha * sum;
}
}  // namespace n001faea8
