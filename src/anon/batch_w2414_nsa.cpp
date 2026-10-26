#include "../common/types.h"
// Built with -fno-strict-aliasing.
extern "C" {
struct W1621Rec20 { u32 w[5]; };
struct W1621Msg { u16 id; u16 arg; u32 flags; W1621Rec20 rec; };
struct W1621Obj;
struct W1621Ent { u16 a; u16 kind; };
typedef s32 (*W1621Fn)(...);
typedef void (*W1621VFn)(...);
struct W1621Obj { W1621Fn* vt; };
s32 func_00176868(u8*, W1621Msg*);
void func_00176dd8(u8*, W1621Ent*, W1621Rec20*, s32);
u8* p175c88_get_ability(u8*) asm("_ZN2YS5PARTY11get_abilityEv");
s32 func_00177ab8(u8*, u8);
void func_00178a50(u8*, W1621Ent*);
void func_0017a590(u8*, u16);
W1621Ent* p175c88_lookup(u16) asm("_Z16u_call4_001b8e88jjjj");

static inline u32 W1621A(u8* p) { return *(u32*)(p + 0x160) & 4; }
static inline u32 W1621B(u8* p) { return *(u32*)(p + 0x160) & 8; }
static inline u32 W1621C(u8* p) { return *(u32*)(p + 0x160) & 0x10; }
static inline bool W1621Any(u8* p) { return W1621A(p) || W1621B(p) || W1621C(p); }
W1621Ent* func_00175c88(u8* p, W1621Msg* m)
{
    u8 buf[16];  /* unused local: the original frame has 16 bytes of locals (debug buffer?) */
    *(u32*)(p + 0x10c) &= ~0x40000;
    if (m->flags & 2) {
        if (W1621Any(p) || *(s32*)(p + 0x154) == 5) {
            W1621Obj* o = *(W1621Obj**)(p + 12);
            ((W1621VFn)o->vt[8])(o, p, 1);
        }
    }
    if (*(u32*)(p + 0x108) & 0x20000) {
        if ((m->flags & 1) == 0)
            *(u32*)(p + 0x108) = (*(u32*)(p + 0x108) & ~0x20000) | 0x40000;
    }
    if (*(u32*)(p + 0x10c) & 4) {
        if (!(m->flags & 4))
            *(u32*)(p + 0x10c) &= ~4;
    }
    if (func_00176868(p, m)) return 0;
    if (m->flags & 8) {
        if (((W1621Obj*)p)->vt[32](p)) return 0;
    }
    W1621Ent* r = p175c88_lookup(m->id);
    if (r->kind == 0) return 0;
    *(W1621Rec20*)(p + 0x9f4) = m->rec;
    if (*(u32*)(p + 0x588) & 0x80) func_00178a50(p, r);
    switch (r->kind) {
    case 1: {
        u8 x = (*(u32*)(p + 0x108) & 0x2000000) || (*(u32*)(p175c88_get_ability(p) + 0x14) & 0x2000);
        if (func_00177ab8(p, x)) { ((W1621VFn)((W1621Obj*)p)->vt[31])(p); break; }
        return 0;
    }
    case 0x16d:
        if (func_00177ab8(p, 1)) { ((W1621VFn)((W1621Obj*)p)->vt[31])(p); break; }
        return 0;
    case 3:
        func_00176dd8(p, r, &m->rec, 1);
        break;
    case 2:
        if (!func_00177ab8(p, 1)) return 0;
        *(u32*)(p + 0x490) = m->arg;
        p[0xaf4] = ((u8*)m)[5];
        func_0017a590(p, m->id);
        break;
    default:
        ((W1621VFn)((W1621Obj*)p)->vt[38])(p, r);
        break;
    }
    *(u32*)(p + 0x108) &= ~0x2000000;
    return r;
}
}

extern "C" {
typedef struct V2cdcd8 { f32 x, y, z, w; } __attribute__((aligned(16))) V2cdcd8;
typedef struct Path2cdcd8 { u8 pad0[8]; s32 count; u8 pad1[12]; f32 pos; u8 pad2[132 - 28]; u8 forward; } Path2cdcd8;
V2cdcd8* func_002cb890(Path2cdcd8*, s32);
f32 func_002cdb60(Path2cdcd8*, f32*, V2cdcd8*, V2cdcd8*, V2cdcd8*, f32, f32);
static inline f32 vdist(V2cdcd8* a, V2cdcd8* b)
{
    V2cdcd8 r;
    f32 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(d) : "r"(&r) : "$8");
    return d;
}
f32 func_002cdcd8(Path2cdcd8* p, s32* idx, f32* t, V2cdcd8* pos, f32 maxDist)
{
    V2cdcd8* v;
    s32 last;
    *idx = (s32)p->pos;
    *t = p->pos - (f32)*idx;
    if (p->forward && 0.9999f < *t) {
        (*idx)++;
        *t = 0.0f;
    } else if (!p->forward && *t < 0.0001f) {
        (*idx)--;
        *t = 1.0f;
    }
    last = p->count - 1;
    if (*idx >= last) {
        *idx = last;
        v = func_002cb890(p, last);
    } else if (*idx < 0) {
        *idx = 0;
        *t = 0.0f;
        v = func_002cb890(p, *idx);
    } else {
        f32 lo, hi, bestT, best;
        s32 bestIdx, n;
        if (p->forward) {
            lo = *t;
            hi = 1.0f;
        } else {
            hi = *t;
            lo = 0.0f;
        }
        bestT = *t;
        best = -1.0f;
        bestIdx = *idx;
        for (n = 0; n < 2; n++) {
            V2cdcd8* a = func_002cb890(p, *idx);
            V2cdcd8* b = func_002cb890(p, (*idx + 1) % p->count);
            f32 d = func_002cdb60(p, t, pos, a, b, lo, hi);
            if (best < 0.0f || d < best) {
                best = d;
                bestIdx = *idx;
                bestT = *t;
            }
            if (p->forward) *idx = *idx + 1; else *idx = *idx - 1;
            if (*idx < 0 || *idx >= p->count - 1) break;
            *t = 0.0f;
            hi = 1.0f;
            lo = *t;
        }
        *idx = bestIdx;
        *t = bestT;
        if (best < maxDist) return best;
        return -1.0f;
    }
    return vdist(pos, v);
}
}

extern "C" {
struct P2dff60;
struct P2dff60Vt { void* f[15]; void (*land)(P2dff60*, void*, bool); };
struct P2dff60 {
    P2dff60Vt* vt;
    u8 pad0[20];
    f32 vx, vy, vz, f36;
    s32 f40;
    f32 f44;
    u8 pad1;
    u8 fell;
    u8 pad2[22];
    void* gim;
    f32 f76;
    s32 lane;
    u8 f84;
    u8 pad3[3];
    f32 f88;
    u8 pad4[4];
    f32 f96;
};
struct H2dff60 { u8 pad[264]; u32 flags; };
struct G2dff60 { u8 pad[128]; s32 mode; u8 pad2[0x8000 + 108 - 132]; u8 alt; };
extern G2dff60* D_00361f60;
extern const f32 D_00375d40;
extern f32 D_00349e10;
s32 func_002ddbb8(void*);
f32 func_002dd2b0(G2dff60*);
s32 p2dff60_reset_stage(void*) asm("_ZN2Ti12MGJumpGimObj18get_reset_stage_idEv");
void func_002dd530(G2dff60*, s32);
f32 func_002de6e8(void*);
f32 func_002dd250(G2dff60*, s32);
f32 func_002dd280(G2dff60*, s32);
void func_002e0870(P2dff60*, f32*, f32*, f32*);
void func_002de3e0(void*);
void func_002dd4a8(G2dff60*, s32);
void p2dff60_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void p2dff60_ready(P2dff60*, H2dff60*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
void func_002dff60(P2dff60* p, H2dff60* h)
{
    G2dff60* g = D_00361f60;
    s32 hit = 0;
    if (!func_002ddbb8(p->gim) && (h->flags & 0x10000)) {
        p->fell = 1;
        hit = 1;
    }
    if (func_002dd2b0(g) <= p->f44 || p->fell) {
        if (g->alt && p->lane == 3 && p2dff60_reset_stage(p->gim) > 0) func_002dd530(g, p2dff60_reset_stage(p->gim));
        f32 t = func_002de6e8(p->gim);
        f32 d[1];
        s32 lane;
        if (func_002ddbb8(p->gim)) {
            p->fell = 1;
            p->f84 = 1;
            lane = g->alt ? 11 : 10;
            f32 a = func_002dd250(g, lane) * 0.01f;
            d[0] = a - (-t - D_00375d40) * 0.01f;
            p->vx = a;
        } else {
            lane = p->lane * 2 + (!p->fell ? 2 : 3);
            f32 e = -(p->f76 - t);
            f32 a = (func_002dd250(g, lane) + e) * 0.01f;
            d[0] = a;
            p->vx = -(t + D_00375d40) * 0.01f + a;
        }
        f32 z = func_002dd280(g, lane);
        f32 y = -(t + D_00375d40) * 0.01f;
        p->vz = z;
        p->vy = y;
        func_002e0870(p, &p->f88, &p->vz, d);
        p->f36 = p->vy;
        p->f40 = 0;
        p->f44 = 0.0f;
        p->f96 = p->vz / p->f88;
        func_002de3e0(p->gim);
        p->vt->land(p, h, hit);
        p->gim = 0;
        func_002dd4a8(g, 1);
        if (g->mode == 1) p2dff60_AddCount(1, 0);
    } else {
        p2dff60_ready(p, h);
        p->f36 = -D_00375d40 * 0.01f;
        p->f44 += D_00349e10;
    }
}
}

extern "C" {
struct V165ad8 {
    f32 x, y, z, w;
    V165ad8& operator=(const V165ad8& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ent165ad8 { s32 id; void* body; };
struct Hit165ad8 {
    V165ad8 v0, v1, v2, v3, v4, v5;
    u16 s0, s1, s2, s3;
    f32 dist;
    f32 f108;
    struct { u32 b0 : 1; u32 b1 : 2; u32 b3 : 4; u32 rest : 25; } a;
    struct { u32 c0 : 1; u32 c1 : 1; u32 c2 : 1; u32 rest : 29; } fl;
    Ent165ad8* ent;
    s32 owner;
    f32 f128;
};
void func_0031b9e0(Hit165ad8*);
Ent165ad8* func_00165ef0(Ent165ad8*);
s32 func_00142b70(void*);
s32 func_001424c0(void*, Hit165ad8*);
s32 func_00165ad8(Hit165ad8* h, f32* minDist)
{
    Ent165ad8* e = 0;
    s32 found = 0;
    f32 bestD = 10000000.0f;
    *minDist = bestD;
    Hit165ad8 best;
    func_0031b9e0(&best);
    f32 saved = h->v3.y;
    u64 mask = (u64)1 << 32;  /* fl.c0 tested as a 64-bit word: the original keeps this mask in s4 */
    while ((e = func_00165ef0(e)) != 0) {
        if (e->id == h->owner) continue;
        if (func_00142b70(e->body)) continue;
        if (!func_001424c0(e->body, h)) continue;
        h->ent = e;
        if (!(*(u64*)&h->a & mask)) {
            if (h->v3.y < bestD) {
                bestD = h->v3.y;
                best = *h;
                found = 1;
            }
        } else if (*minDist > h->dist) *minDist = h->dist;
        h->v3.y = saved;
    }
    if (found == 1) *h = best;
    return found;
}
}
