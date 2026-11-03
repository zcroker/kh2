#include "../common/types.h"
extern "C" {
struct W1649Ob {
    u8 pad0[44];
    s32 group;          // 44
    u8 pad1[248 - 48];
    u32 flags;   // 248 (union: read after float stores)
    u8 pad2[12];
    f32 fadeDist;       // 264
    u8 alpha;           // 268
};
struct W1649Ent { W1649Ob* obj; u32 flags; };
struct W1649Eff { u8 pad[864]; s32 active; u8 pad1[12]; };
struct W1649Pos { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1649Mgr {
    u8 pad0[1912];
    u8 drawExtra;           // 1912
    u8 grouped;             // 1913
    u8 pad1[2];
    s32 extraOn[(1936 - 1916) / 4];   // 1916, per slot
    u8 extraEff[3152 - 1936];         // 1936
    s32 effCount[4];        // 3152, per slot
    W1649Eff effs[16];      // 3168
    W1649Ent ents[512];     // 17248
    s32 entCount;           // 21344
    u8 pad2[8];
    s32 slot;               // 21356
    void* pending0;         // 21360
    void* pending1;         // 21364
};
s32 func_00106a08(void);
void* func_00106a60(s32);
void func_00107368(void*, W1649Pos*);
void func_00148598(W1649Mgr*, void*);
void func_001b81e8(void);
void func_001b8218(void);
void func_00148a30(W1649Mgr*);
void func_00148ac0(W1649Mgr*);
void func_00147810(W1649Mgr*, W1649Ob*);
f32 func_00148890(W1649Mgr*, W1649Ob*, W1649Pos*);
void func_001472b8(void*, void*, s32, s32);
void func_00148e40(W1649Mgr*, W1649Ob*, W1649Ob** out, s32* n);
void func_00148ef0(W1649Mgr*, W1649Ob**, s32);
s32 func_00147a68(W1649Mgr*, s32*, s32*);
void func_00147aa8(W1649Mgr*, W1649Ob*, f32);
void W1649_effCreate(void*) asm("_ZN3ryj6EFFECT6CreateEPN2dk10UserEffectE");

// Scratchpad sort arrays (see func_001472b8): keys are floats, the carried values are entry pointers.
union W1649FI { f32 f; W1649Ent* e; };
#define W1649_KEYS ((W1649FI*)0x70000000)
#define W1649_DIST ((f32*)0x70000800)
#define W1649_SORTED ((W1649FI*)0x70001000)

// Built with -fno-strict-aliasing (_nsa file).
// Per-frame update of all entries: measures their distance to the camera, sorts the visible ones
// (nearest first, in scratchpad), fades out far ones, and updates them (by group when grouped).
void func_001473e8(W1649Mgr* m)
{
    W1649Pos cam;
    W1649Ob* buf[32];
    s32 state[512];
    s32 nb;
    s32 last;
    f32* dist;
    W1649FI* sorted;
    W1649FI* keys;
    s32 n, cnt;

    m->slot = func_00106a08();
    if (m->pending0) func_00148598(m, m->pending0);
    if (m->pending1) func_00148598(m, m->pending1);
    dist = W1649_DIST;
    keys = W1649_KEYS;
    sorted = W1649_SORTED;
    cnt = 0;
    m->extraOn[m->slot] = 0;
    m->effCount[m->slot] = 0;
    func_001b81e8();
    func_00148a30(m);
    func_00107368(func_00106a60(1), &cam);
    n = m->entCount;
    {
        for (s32 i = 0; i < n; i++) {
            W1649Ent* e = &m->ents[i];
            W1649Ob* o = e->obj;
            func_00147810(m, o);
            f32 r = func_00148890(m, o, &cam);
            W1649_DIST[i] = r;
            if (o->flags & 4) {
                if (!(o->flags & 0x40)) {
                    keys[cnt].f = r;
                    sorted[cnt].e = e;
                    cnt++;
                }
            }
        }
    }
    last = cnt - 1;
    if (cnt >= 2) {
        // The original loads 0x70001000 with one unsplit `li` (gas expands it to lui+ori after
        // scheduling); gcc splits a C constant before sched1 and pairs the two luis instead.
        void* p;
        asm("li %0,0x70001000" : "=r"(p));
        func_001472b8(p, keys, 0, last);
    }
    for (s32 i = 0; i < n; i++) {
        W1649Ent* e = &m->ents[i];
        if (__builtin_expect(!(e->flags & 2), 1)) continue;
        W1649Ob* o = e->obj;
        if (!(o->flags & 0x2000)) {
            if (!(o->flags & 0x40)) {
                if (o->fadeDist != 0.0f) {
                    f32 dd = dist[i];
                    if (o->fadeDist < dd) continue;
                    f32 near = o->fadeDist - 400.0f;
                    if (near < dd) o->alpha = (s32)(o->alpha * (1.0f - (dd - near) / 400.0f));
                }
            }
        }
        nb = 0;
        func_00148e40(m, e->obj, buf, &nb);
        if (nb) {
            buf[nb] = 0;
            func_00148ef0(m, buf, nb);
        }
    }
    if (!m->grouped) {
        for (s32 i = last; i >= 0; i--) {
            W1649Ent* e = sorted[i].e;
            if (e->flags & 2) func_00147aa8(m, e->obj, keys[i].f);
        }
    } else {
        for (s32 i = last; i >= 0; i--) state[i] = sorted[i].e->obj->group;
        s32 k = last;
        for (;;) {
            s32 j = k;
            s32 g = func_00147a68(m, &k, state);
            if (g == 1) break;
            for (; j >= 0; j--) {
                W1649Ent* e = sorted[j].e;
                if (state[j] != 1 && state[j] == g) {
                    state[j] = 1;
                    if (e->flags & 2) func_00147aa8(m, e->obj, 0.0f);
                }
            }
        }
    }
    func_00148ac0(m);
    func_001b8218();
    s32 ec = m->effCount[m->slot];
    for (s32 i = 0; i < ec; i++) {
        W1649Eff* f = &m->effs[i];
        if (f->active) W1649_effCreate(f);
    }
    if (m->drawExtra && m->extraOn[m->slot]) W1649_effCreate(m->extraEff);
}
}
