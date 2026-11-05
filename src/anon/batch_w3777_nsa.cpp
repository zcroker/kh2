#include "../common/types.h"
extern "C" {
struct M2da670 { f32 m[4][4]; } __attribute__((aligned(16)));
struct Pr2da670 { f32 x, w; };
struct O2da670 { u8 pad[3056]; void* pot; u8 pad2[4]; Pr2da670 pos; };
extern void* D_00361f60;
s32 o2da670_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
M2da670 func_002d8120(void*, Pr2da670*, f32);
void func_002da520(O2da670*, const M2da670&);
f32 func_002dbf50(void*);
void func_002d8d40(void*, f32*, f32*);
bool o2da670_is_separate_blow(void*) asm("_ZN2Ti14MGHachimitsuPo16is_separate_blowEv");
f32 o2da670_get_vertical_pos(void*) asm("_ZN2Ti14MGHachimitsuPo16get_vertical_posEv");
void func_002dc140(void*, const M2da670&);
}
// Clamp p into [lo, hi].
static inline __attribute__((always_inline)) void Clamp2da670(Pr2da670& p, const f32& lo, const f32& hi)
{
    if (p.x < lo) p.x = lo;
    if (hi < p.x) p.x = hi;
}
// Clamp a, then push b out so the two stay at least a.w + b.w apart.
static inline __attribute__((always_inline)) void Fix2da670(Pr2da670& a, Pr2da670& b, const f32& lo, const f32& hi)
{
    if (a.x < lo) a.x = lo;
    if (hi < a.x) a.x = hi;
    f32 w = a.w + b.w;
    if (a.x < b.x) {
        if (b.x < a.x + w) b.x = a.x + w;
    }
    if (b.x < a.x) {
        if (a.x < b.x + w) b.x = a.x - w;
    }
}
// MGHachimitsuPo position update: when attached, place at its own position; otherwise clamp both
// pieces into the [lo, hi] range, push them at least 40 + 30 apart, and build both matrices.
extern "C" {
void func_002da670(O2da670* o)
{
    void* g = D_00361f60;
    if (!g) return;
    if (!o->pot || o2da670_is_attach(o->pot)) {
        func_002da520(o, func_002d8120(g, &o->pos, 0.0f));
        return;
    }
    Pr2da670 pr[2];
    pr[0].x = o->pos.x;
    pr[0].w = 40.0f;
    pr[1].x = func_002dbf50(o->pot);
    pr[1].w = 30.0f;
    f32 lo, hi;
    func_002d8d40(g, &lo, &hi);
    bool ns = !o2da670_is_separate_blow(o->pot);
    if (ns) {
        Fix2da670(pr[0], pr[1], lo, hi);
        Fix2da670(pr[1], pr[0], lo, hi);
    } else {
        for (s32 i = 0; i < 2; i++) Clamp2da670(pr[i], lo, hi);
    }
    {
    const M2da670& m0 = func_002d8120(g, &pr[0], 0.0f);
    func_002da520(o, m0);
    }
    const M2da670& m1 = func_002d8120(g, &pr[1], o2da670_get_vertical_pos(o->pot));
    func_002dc140(o->pot, m1);
}
}
