#include "../common/types.h"

struct W1962QV {
    f32 x, y, z, w;
    W1962QV() {}
    W1962QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1962QV& operator=(const W1962QV& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    W1962QV operator*(f32 s) const { W1962QV r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory"); return r; }
    W1962QV& operator+=(const W1962QV& o) { asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1962Pt { W1962QV v0, pos, vel, acc, frc, imp; };
struct W1962Sys { W1962Pt p[41]; };
struct W1962QVb {
    f32 x, y, z, w;
    W1962QVb& operator=(const W1962QVb& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1962OcF;
struct W1962Tri { u32 a; W1962OcF* f; };
struct W1962Hit { W1962Tri* t; };
struct W1962Cnt { u32 n; };
struct W1962Inf { u8 p[11]; u8 lv; };
struct W1962Pl { u8 p[0x588]; u32 fl; };
struct W1962Ob;
typedef void (*W1962VF)(void*, W1962Ob*);
struct W1962Hd { W1962VF* vt; };
struct W1962Ob { u32 f0; u32 fl; u32 f8; W1962Hd* hd; W1962Pl* pl; u8 p14[0x10]; W1962Cnt* cnt; W1962Inf* inf; u8 p2c[0x84]; W1962QVb pos; };
struct W1962Cmd { u8 op; u8 a; u8 b; u8 c; };
struct W1962S24 { u32 w[6]; };
struct W1962S8 { u32 a, b; };
struct W1962Tgt;
typedef void (*W1962TF1)(W1962Tgt*, u8);
typedef void (*W1962TF3)(W1962Tgt*, u8, u8, u8);
struct W1962Tgt { void** vt; s32 f4; s32 f8; };
struct W1962Ob2 { u32 f0; u32 f4; u32 f8; W1962Cmd* cur; W1962S8 f10; W1962Tgt* tg; u32 f1c; u32 f20; W1962S24 s; u8 p3c[0x10]; f32 f4c; u8 p50[0xc]; f32 f5c; };
extern "C" {
// ---- func_002e5350
void func_002e4d30(W1962Sys*);

void func_002e5350(W1962Sys* s, f32 t, s32 n) {
    f32 h = t / (f32)n;
    f32 k = 1.0f / (f32)n;
    s32 i, j, k2, m;
    for (i = 0; i < n; i++) {
        for (k2 = 0; k2 < 41; k2++) s->p[k2].imp = s->p[k2].frc * k;
        func_002e4d30(s);
        for (j = 0; j < 41; j++) {
            W1962Pt* e = &s->p[j]; W1962QV& f = e->imp; W1962QV& p = e->pos; W1962QV& a = e->acc; a = f * 100.0f; e->vel += a * h; p += e->vel * h;
        }
    }
    for (m = 0; m < 41; m++) s->p[m].frc = W1962QV(0.0f, 0.0f, 0.0f, 0.0f);
}

// ---- func_0018ddc0
W1962QVb oc_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
s32 oc_get_attr_kind(u16, bool) asm("_ZN2dk6Octree11getAttrKindEtb");
u32* ocf_get_attr(W1962OcF*, u16) asm("_ZN2dk11OctCollFile7getAttrEt");
W1962QVb* w1962_effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
W1962QVb func_001422a0(W1962OcF*, u16);
void* func_001a3b48(W1962Cnt*, u64, W1962QVb*, s32, s32, s32);
W1962QVb func_0017d050(const W1962QVb&);
void func_001c2c00(void*);
void func_00198580(W1962Pl*, s32);
void func_0018ddc0(W1962Ob* o, u16 id, W1962QVb* pos, W1962Hit* h) {
    W1962QVb n;
    s32 kind;
    if (h->t == 0) {
        n = oc_get_normal(id, 0);
        kind = oc_get_attr_kind(id, 0);
    } else {
        n = func_001422a0(h->t->f, id);
        kind = *ocf_get_attr(h->t->f, id) & 0xf;
    }
    u64 t;
    if (kind == 1) { o->fl |= 0x10; t = 0x100; }
    else { o->fl |= 8; t = 2; }
    o->pos = *pos;
    if (o->cnt->n != 0) {
        u8 lv = o->inf->lv;
        if (lv != 0) {
            t |= (1ULL << 32) << (lv - 1);
            void* e = func_001a3b48(o->cnt, t, pos, 1, 1, 10000);
            if (e != 0) {
                *w1962_effect_angle(e) = func_0017d050(n);
                func_001c2c00(e);
            }
        }
    }
    if (o->pl->fl & 0x40) func_00198580(o->pl, 0x7a12a);
    if (!(o->fl & 0x100)) o->hd->vt[28](o->hd, o);
}

// ---- _Z16wtarget_001aa388jjjj
void func_00192940(W1962Cmd*, u32, W1962S24, W1962S8*);
s32 func_00192440(W1962Cmd*, s32);
W1962Cmd* func_00192388(W1962Cmd*);
s32 func_00192498(W1962Cmd*, s32);
void func_001991a8(s32, s32);
void wt_001aa388(W1962Ob2* o, W1962Cmd* c, u32, u32) asm("_Z16wtarget_001aa388jjjj");
void wt_001aa388(W1962Ob2* o, W1962Cmd* c, u32, u32) {
    W1962Cmd* p = c;
    o->f0 = 0;
    func_00192940(c, o->f4, o->s, &o->f10);
    o->f1c = 0;
    o->f20 = 0;
    while (p != 0) {
        if (func_00192440(p, 0)) {
            switch (p->op) {
            case 0: case 16:
                p = 0;
                break;
            case 6:
                if (o->tg) ((W1962TF1)o->tg->vt[9])(o->tg, p->a);
                break;
            case 8:
                if (o->tg) ((W1962TF3)o->tg->vt[10])(o->tg, p->a, p->b, p->c);
                break;
            case 18:
                func_001991a8(func_00192498(p, 1), 0);
                break;
            case 19: {
                W1962Tgt* t = o->tg;
                if (t) {
                    s32 x = func_00192498(p, 1);
                    s32 y = func_00192498(p, 3);
                    t->f4 = x;
                    t->f8 = y;
                }
                break;
            }
            case 21:
                o->f20++;
                break;
            case 23:
                o->f5c = p->a;
                o->f4c = p->b;
                break;
            }
        }
        if (p == 0) break;
        p = func_00192388(p);
    }
    o->cur = c;
}
}
