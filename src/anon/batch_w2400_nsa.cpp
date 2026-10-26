#include "../common/types.h"
struct V4q {
    f32 x, y, z, w;
    V4q() {}
    V4q(const V4q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4q& operator=(const V4q& o) {
        if (this == &o) return *this;
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct EntQ { u8 b0; u8 b1; u8 pad[14]; };
struct MgrQ { u8 pad[12]; EntQ* tbl; };
struct InfQ { s16 h0; s16 h2; };
struct ObjQ { u8 pad[48]; V4q pos; u8 pad2[32]; u16 h96; u8 pad3[10]; f32 f108; u8 pad4[8]; MgrQ** p120; };
struct OutQ { V4q v0; V4q v16; u8 sub[4]; u32 f36; u32 f40; u32 f44; u32 f48; u8 b52; };
extern "C" {
extern MgrQ* D_0034880c;
extern MgrQ* D_00348804;
void func_0015cb78(u8*, s32);
void func_00141980(MgrQ*, u8*);
s32 func_00142848(MgrQ*, ObjQ*);
u16 func_00142688(MgrQ*, u32*, s32, ObjQ*);
void func_001539c0(u8*, V4q*);
u32 func_001435a0(ObjQ*);
V4q func_00143e50(u16, s32);
V4q func_001422a0(MgrQ*, u16);
InfQ* func_00142398(MgrQ*, u16);
InfQ* func_00143ee8(u16, s32);
void func_00141988(MgrQ*, EntQ*, V4q*);
static inline void negq(V4q* d, const V4q* s) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(s) : "memory");
}
void func_00143648(ObjQ* o, OutQ* out) {
    out->f40 = 0;
    out->b52 = 0;
    out->f44 = 0;
    out->f48 = 0;
    func_0015cb78(out->sub, 0);
    if (D_0034880c) {
        u8 buf[2048];
        func_00141980(D_0034880c, buf);
        s32 n = func_00142848(D_0034880c, o);
        u32 r = 0;
        u16 h = func_00142688(D_0034880c, &r, n, o);
        if (h != 0xffff) {
            EntQ* e = &D_0034880c->tbl[h];
            u8 b0 = e->b0;
            out->f44 = e->b1;
            func_0015cb78(out->sub, b0);
        }
    }
    V4q p = o->pos;
    p.y -= o->f108;
    func_001539c0(out->sub, &p);
    out->f48 = func_001435a0(o);
    out->f36 = o->h96;
    if (o->h96 == 0xffff) {
        out->v0.x = 0.0f;
        out->v0.y = -1.0f;
        out->v0.z = 0.0f;
        out->v0.w = 1.0f;
        out->v16.x = 0.0f;
        out->v16.y = 1.0f;
        out->v16.z = 0.0f;
        out->v16.w = 1.0f;
        return;
    }
    MgrQ* m;
    InfQ* inf;
    MgrQ** pp = o->p120;
    if (!pp) {
        m = D_00348804;
        out->v0 = func_00143e50(o->h96, 0);
        inf = func_00143ee8(o->h96, 0);
        { s32 fl = inf->h2; out->b52 = fl & 1; }
    } else {
        m = o->p120[1];
        out->v0 = func_001422a0(m, o->h96);
        inf = func_00142398(o->p120[1], o->h96);
        { s32 fl = inf->h2; out->b52 = fl & 1; }
    }
    EntQ* e = &m->tbl[o->h96];
    V4q hit;
    func_00141988(m, e, &hit);
    out->f40 = e->b0;
    negq(&out->v16, &out->v0);
}
}
