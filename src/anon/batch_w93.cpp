#include "../common/types.h"

// VU0 quadword vector helpers (16-byte aligned xyzw).
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator-(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator+(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
static inline __attribute__((always_inline)) void W93Normalize(W93Vec* v)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v) : "$8", "$f0", "memory");
}

extern "C" {

void func_0011b6a8(f32* m);

struct ProjCam {
    u8 pad0[64];
    f32 scale;      // 0x40
    u8 pad1[8];
    f32 aspectX;    // 0x4c
    f32 aspectY;    // 0x50
    u8 pad2[24];
    f32 nearZ;      // 0x6c
    f32 farZ;       // 0x70
};

// Builds a perspective projection matrix from the camera's near/far planes.
void func_00106af0(ProjCam* c, f32* m, f32 w, f32 h)
{
    f32 sx = c->nearZ * w / (c->scale * c->aspectX);
    f32 sy = c->nearZ * h / (c->scale * c->aspectY);
    func_0011b6a8(m);
    m[0] = c->nearZ * 2.0f / (sx * 2.0f);
    m[5] = c->nearZ * 2.0f / (sy * 2.0f);
    m[10] = (c->farZ + c->nearZ) / (c->farZ - c->nearZ);
    m[14] = c->farZ * c->nearZ * -2.0f / (c->farZ - c->nearZ);
    m[11] = 1.0f;
    m[15] = 0;
}

s32 func_0019ba60(u32);
extern u32 D_00341788[8];
extern s32 D_003417a8;

// Drops dead entries from the 8-slot list, compacting the survivors.
void func_001127c0(void)
{
    u32 tmp[8];
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_003417a8; i++) {
        if (func_0019ba60(D_00341788[i])) tmp[n++] = D_00341788[i];
    }
    D_003417a8 = n;
    for (i = 0; i < D_003417a8; i++) D_00341788[i] = tmp[i];
    for (i = D_003417a8; i < 8; i++) D_00341788[i] = 0;
}

s16* func_001aec40(u32);
u32 func_002ba0b0(s32);
u32 func_002ba0f8(s32);
u32 func_00136790(u32, u32*);
void func_001367e0(u32, u32, u32);
void func_001367c8(u32);
void func_002ba7c8(u32);
void func_002ba3e8(u32, u32, u32, u32, u32, s32*, u32, u32);
struct W93Pair { u32 pad; s16 b; s16 a; };
extern W93Pair D_003b8b20;
extern s32 D_003b8b38;

// Loads and binds the two resources named by the entry unless already current.
void func_001363a0(u32 p)
{
    u32 sz[2];
    s16* v = func_001aec40(p);
    if (v[3] == D_003b8b20.a && v[2] == D_003b8b20.b) return;
    if (v[3] == -1) return;
    if (v[2] == -1) return;
    u32 h0 = func_002ba0b0(v[3]);
    u32 d0 = func_00136790(h0, &sz[0]);
    func_001367e0(p, h0, d0);
    u32 h1 = func_002ba0f8(v[2]);
    u32 d1 = func_00136790(h1, &sz[1]);
    func_001367e0(p, h1, d1);
    func_002ba3e8(20, d0, sz[0], d1, sz[1], &D_003b8b38, 0, 0);
    func_002ba7c8(p);
    func_001367c8(d1);
    func_001367c8(d0);
}

struct W93Task { u32 f0; void* owner; u8 pad[40]; void* fn; };
struct W93G { u32 f0; u32 f4; u32 f8; u8 pad[8]; u32 f20; };
extern W93G* D_00347f80;
void func_00139dc0(s32);
W93Task* func_00105d78(u32, u32, void*);
W93Task* func_00103b48(u32, u32, void*);
u32 func_001024b0(u32);
W93Task* func_00102788(u32, u32, u32, void*);
void func_00139390(); void func_001393e0(); void func_001394c0(); void func_001394d8(); void func_00139308();

// Creates the scene's two worker tasks and its root object, all owned by the global context.
// (Raw pointer-typed stores reproduce the original's reloads of the context pointer.)
void func_00139e00(u32 a, u8 flag)
{
    W93Task* t;
    func_00139dc0(1);
    *(W93G**)((u8*)D_00347f80 + 20) = (W93G*)a;
    D_00347f80->f8 = 0;
    D_00347f80->f4 = 0;
    if (flag) t = func_00105d78(0, 0x186a0, (void*)func_00139390);
    else t = func_00103b48(0, 0x186a0, (void*)func_00139390);
    t->fn = (void*)func_001393e0;
    t->owner = D_00347f80;
    if (flag) t = func_00105d78(0, 0x1944c, (void*)func_001394c0);
    else t = func_00103b48(0, 0x1944c, (void*)func_001394c0);
    *(W93G**)((u8*)t + 4) = D_00347f80;
    *(W93G**)((u8*)t + 48) = (W93G*)func_001394d8;
    *(W93G**)D_00347f80 = (W93G*)func_001024b0(a);
    t = func_00102788(D_00347f80->f0, 0, 0x19258, (void*)func_00139308);
    t->owner = D_00347f80;
}

struct W93Q16 { u8 v[16]; } __attribute__((aligned(16)));
static inline void W93Copy(W93Q16* d, const W93Q16* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93A { u64 p0; u64 flags; u8 pad[44 - 16]; f32 speed; };
struct W93B { u8 pad[16]; W93Q16 cur; u8 p2[68 - 32]; u32 f68; u32 f72; f32 val; f32 out; u8 p3[96 - 84]; W93Q16 tgt; };
extern f32 D_004f35a4;
extern f32 D_00349e10;
f32 func_0013fd10(W93B*);
void func_0013fd78(W93B*);
s32 func_0019c4d0(u32);
void func_0013fdf0(W93B*, W93A*, f32);
s32 func_001584f8(W93A*);
s32 func_00158548(W93A*);
f32 func_0017ce10(f32);
void func_00158c88(W93B*);

// Steps the value toward its target (or snaps it while the hold flag is set).
void func_00158b78(W93A* a, W93B* b)
{
    f32 k = D_00349e10;
    if (a->flags & 0x20000) {
        b->out = func_0013fd10(b);
        func_0013fd78(b);
        W93Copy(&b->cur, &b->tgt);
    } else if (func_001584f8(a)) {
        b->val += D_004f35a4 * a->speed * k;
        b->out = b->val = func_0017ce10(b->val);
    } else if (func_00158548(a)) {
        b->val -= D_004f35a4 * a->speed * k;
        b->out = b->val = func_0017ce10(b->val);
    }
    if (!func_0019c4d0(b->f68)) func_0013fdf0(b, a, k);
    func_00158c88(b);
}

struct W93Orb { u8 pad[4]; f32 dist; f32 radius; u8 p2[4]; W93V center; };
struct W93Pos { u8 pad[32]; W93V pos; };
f32 func_002f8870(f32);
// Places a point on the orb around o->center at the height of p, clamped to the radius.
W93V func_0018e160(const W93Pos* p, const W93Orb* o)
{
    W93V d;
    W93V tmp;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&tmp), "r"(&p->pos), "r"(&o->center) : "memory");
    W93Set(&d, &tmp);
    f32 r = o->radius;
    f32 y;
    if (d.y < -r) y = -r;
    else if (r < d.y) y = r;
    else y = d.y;
    f32 c = func_002f8870(y / r);
    f32 s = __builtin_sqrtf(1.0f - c * c);
    d.y = 0;
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f2\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&d) : "$8", "$f2", "memory");
    f32 k = o->dist * s;
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "f"(k) : "$8", "memory");
    d.y = y;
    W93V out;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&out), "r"(&o->center), "r"(&d) : "memory");
    return out;
}

struct W93Hdr { u32 p0; u32 flags; };
struct W93Act { W93Hdr* h; u8 pad[16]; f32 f20; u8 p2[8]; W93Vec pos; };
void* func_001de168(u32, u32, s32, s32, s32, s32);
W93Vec* func_001dc5f8(void*);
void func_001c2c00(void*);
void func_0018efe8(W93Hdr*);
// Pushes b out of a's radius along the line between them.
void func_0018e8f0(W93Act* a, u32 x, u32 y, W93Act* b)
{
    if (a->h->flags & 0x80) return;
    if (b->h->flags & 0x80) return;
    void* r = func_001de168(x, y, 1, 1, 10000, 0);
    if (r) {
        W93Vec d;
        d = b->pos - a->pos;
        W93Normalize(&d);
        *func_001dc5f8(r) = a->pos + d * a->f20;
        func_001c2c00(r);
    }
    func_0018efe8(a->h);
    func_0018efe8(b->h);
}

struct W93Map { u8 pad[4]; u16 flags; };
struct W93Res { u8 pad[8]; W93Map* map; };
struct W93Fld { u8 pad[8]; W93Map* map; u8 p2[40 - 12]; u8 f40[32]; u32 f72; };
u32 func_001708f8(void*, s32);
W93Res* func_00168b38(u32, s32, s32);
void func_001d5458(W93Map*);
void func_00191990(void);
union W93UM { W93Map* p; u32 u; };
extern W93UM D_01d49324;
extern W93UM D_0034f240;
// Loads the field's map resource, publishes it, and folds its flags into the global field state.
void func_001bacd0(W93Fld* f)
{
    f->f72 = func_001708f8(f->f40, -1);
    W93Map* m = func_00168b38(f->f72, 2, 0)->map;
    func_001d5458(m);
    f->map = m;
    D_01d49324.p = m;
    if (f->map->flags & 1) func_00191990();
    if (f->map->flags & 0x20) D_0034f240.u |= 4;
    if (f->map->flags & 0x40) D_0034f240.u |= 0x200;
    if (f->map->flags & 0x80) D_0034f240.u |= 0x400;
    if (f->map->flags & 0x100) D_0034f240.u |= 0x8000;
}

struct W93Ob;
struct W93ObVt { u8 pad[40]; void (*kill)(W93Ob*); u8 p2[60 - 44]; s32 (*prio)(W93Ob*); };
struct W93Ob { W93ObVt* vt; u8 pad[264 - 4]; u32 flags; u8 p2[768 - 268]; u8 f768[2228 - 768]; W93Ob* next; };
void func_001a58f8(void); void func_001bf6a8(void); void func_001c1060(void); void func_001b5400(void);
void func_001b6038(void); void func_001b6d00(void); void func_001c8d08(void); void func_001a5e38(void);
void func_001ba740(void); void func_0018d790(void); void func_001d6c58(void);
extern W93Ob* D_01d48da0;
extern u8 D_0036dbd8[];
void func_00188120(void*, void*);
s32 func_001c0cd8(W93Ob*);
void func_0016ae18(W93Ob*);
static inline W93Ob* W93Next(W93Ob* o) { if (!o) return D_01d48da0; return o->next; }
// Runs the per-frame subsystem updates, then culls or refreshes every live object by priority.
void func_001b9db0(s32 lim)
{
    W93Ob* o = 0;
    func_001a58f8(); func_001bf6a8(); func_001c1060(); func_001b5400();
    func_001b6038(); func_001b6d00(); func_001c8d08(); func_001a5e38();
    func_001ba740(); func_0018d790(); func_001d6c58();
    while ((o = W93Next(o))) {
        if (o->flags & 0x80000) continue;
        if (o->vt->prio(o) >= lim) {
            o->vt->kill(o);
        } else {
            func_00188120(o->f768, D_0036dbd8);
            if (!func_001c0cd8(o)) func_0016ae18(o);
        }
    }
}

struct W93Gold { u8 pad[14048]; s32 munny; };
extern W93Gold D_0032bb30;
extern u8 D_0032bae0;
extern u8 D_0032e020[];
s32 func_001a8b68(s32);
u32 func_00188fe0(void*, s32);
u32 func_00176b58(s32);
void func_001b71e8(s32, u32, u32);
void func_00188bb0(u32, s32);
// Adds munny (capped at 9,999,999) and refreshes the thirteen status panels.
void func_001b70d0(s32 add)
{
    s32 v = D_0032bb30.munny + add;
    D_0032bb30.munny = v > 9999999 ? 9999999 : v;
    for (s32 i = 1; i < 14; i++) {
        s32 id = i;
        switch (i) {
        case 1: id = func_001a8b68(0); break;
        case 6: if (D_0032bae0 == 8) id = func_001a8b68(3); break;
        }
        u32 x = func_00188fe0(D_0032e020, id);
        func_001b71e8(id, x, func_00176b58(id));
    }
    func_00188bb0(func_00188fe0(D_0032e020, 1), 1);
}

struct W93Pl { u8 pad[2896]; s32 state; };
s32 func_001bb7f8(void);
void func_00179e18(W93Pl*);
s32 func_0017a538(W93Pl*);
void func_001d0eb8(W93Pl*);
void func_001991a8(s32, s32);
void func_001b6c60(W93Pl*);
s32 func_001c8b48(void);
s32 func_001bbb50(void);
s32 func_001c8ab0(void);
void func_001d1408(W93Pl*);
void func_001af328(W93Pl*);
void func_001af360(W93Pl*);
void func_001af290(W93Pl*);
static inline bool W93Dead(W93Pl* p) { return p->state == 12; }
// Per-frame player state dispatch (event lock, death, field/battle transitions).
void func_001d0d60(W93Pl* p)
{
    if (D_0034f240.u & 0x20000) {
        if (func_001bb7f8()) {
            func_001991a8(90, 0);
            return;
        }
        func_00179e18(p);
        if (func_0017a538(p) || W93Dead(p)) {
            func_001b6c60(p);
            return;
        }
        func_001d0eb8(p);
        func_001991a8(90, 0);
        return;
    }
    func_00179e18(p);
    if (func_001c8b48()) {
        if (W93Dead(p)) { func_001b6c60(p); return; }
        func_001d0eb8(p);
        func_001af328(p);
        return;
    }
    if (func_001bbb50()) {
        func_001d0eb8(p);
        func_001af360(p);
        return;
    }
    if (func_0017a538(p) || W93Dead(p)) {
        func_001b6c60(p);
        return;
    }
    if (func_001c8ab0() == 2) func_001d1408(p);
    func_001d0eb8(p);
    func_001af290(p);
}

struct W93Spec { u32 f0; u32 f4; u32 kind; u32 f12; u32 f16; u32 f20; u32 f24; };
struct W93Ef { u32 flags; u8 pad[4]; u32 f8; u8 p2[64 - 12]; u8 f64[148 - 64]; u32 f148; u32 f152; u32 f156; u32 f160; };
void* func_001050d8(u32);
void func_00196ca8(W93Ef*, u32, u32);
u32 func_0016b740(u32);
void func_00196e98(W93Ef*, u32);
void func_00196f00(W93Ef*);
void func_001d30f8(void*, s32, s32);
u32 func_00185de0(void);
extern u32 D_00350438;
// Spawns an effect object from its spec and attaches the kind-specific resource.
void func_001d5518(W93Spec* s, u32 a, u8 flag)
{
    if (s->f4 == 0) return;
    W93Ef* o = (W93Ef*)func_001050d8(176);
    func_00196ca8(o, s->f0, s->f4);
    o->f8 = a;
    if (flag) o->flags |= 8;
    o->f148 = s->f12;
    o->f152 = s->f16;
    if (s->f24) {
        o->f156 = 2;
        o->f160 = s->f24;
    } else if (s->f20) {
        o->f156 = s->f20;
    }
    switch (s->kind) {
    case 0: break;
    case 902: func_00196e98(o, func_00185de0()); break;
    case 1679: func_001d30f8(o->f64, 4, 0); break;
    case 1726: func_00196e98(o, D_00350438); break;
    default: func_00196e98(o, func_0016b740(s->kind)); break;
    }
    func_00196f00(o);
}

struct W93Dr;
struct W93DrVt { void* a; void* b; void (*draw)(W93Dr*); };
struct W93Dr { W93DrVt* vt; };
struct W93Sp { u8 pad[4]; s32 type; s32 flags; u8 p2[20 - 12]; W93Dr* dr; u8 p3[28 - 24]; u32 tex; u8 p4[40 - 32]; W93Sp* next; };
extern u8 D_00352af0;
extern u8 D_00352af1;
extern W93Sp* D_00352ae0;
void func_001dd6a0(void); void func_001b81e8(void); void func_001e6688(void);
s32 func_001dc9d0(W93Sp*); void func_001dc878(W93Sp*); s32 func_001dcc60(W93Sp*);
void func_001e6648(void); void func_001dca70(W93Sp*); void func_001e3330(u32); s32 func_001e66e8(u32); void func_001e6c00(u32);
void func_001e6af8(void); void func_001b8218(void);
struct W93NoTail { ~W93NoTail() {} };
// Draws every visible sprite: direct draws batch together, textured ones flush the batch first.
// (The empty-destructor local keeps the final call a jal, as in the original.)
void func_001dd920(void)
{
    W93NoTail keep;
    if (D_00352af1) return;
    if (!D_00352af0) return;
    s32 any = 0;
    func_001dd6a0();
    func_001b81e8();
    func_001e6688();
    W93Sp* next;
    for (W93Sp* o = D_00352ae0; o; o = next) {
        next = o->next;
        if (!func_001dc9d0(o)) continue;
        if ((u8)((o->flags >> 26) & 1)) continue;
        if (o->type == 4) {
            o->dr->vt->draw(o->dr);
            any = 1;
            func_001dc878(o);
        } else {
            if (!o->tex) continue;
            if (!func_001dcc60(o)) continue;
            if (any) {
                func_001e6648();
                any = 0;
            }
            func_001dca70(o);
            func_001e3330(o->tex);
            if (func_001e66e8(o->tex)) continue;
            func_001e6c00(o->tex);
            o->tex = 0;
            o->flags |= 0x10000;
        }
    }
    func_001e6af8();
    func_001b8218();
}

union W93IF { s32 i; f32 f; };
// Quicksort (descending by key), permuting the index array alongside the keys.
void func_00205040(W93IF* idx, f32* key, s32 lo, s32 hi)
{
    s32 i = lo;
    s32 j = hi;
    f32 p = key[(lo + hi) / 2];
    for (;;) {
        while (p < key[i]) i++;
        while (key[j] < p) j--;
        if (i >= j) break;
        f32 tf = key[i]; key[i] = key[j]; key[j] = tf;
        s32 ti = idx[i].i; idx[i].i = idx[j].i; idx[j].i = ti;
        i++;
        j--;
    }
    if (lo < i - 1) func_00205040(idx, key, lo, i - 1);
    if (j + 1 < hi) func_00205040(idx, key, j + 1, hi);
}

struct W93Ver { u32 a, b, c; };
void* func_00105c30(void);
W93Ver* func_00105c48(void*);
u32 func_002402e0(void);
void func_002fee78(char*, const char*, ...);
extern char D_00371658[]; extern char D_00371668[]; extern char D_00371678[]; extern char D_00371680[];
extern u32 D_0035ec04;
// Formats the version/build string for the given mode.
void func_00240118(char* buf, s32 a, s32 mode)
{
    W93Ver* v = func_00105c48(func_00105c30());
    if (a < 0) {
        func_002fee78(buf, D_00371658, func_002402e0(), v->a, v->b, v->c);
    } else if (mode == 1) {
        func_002fee78(buf, D_00371668, func_002402e0(), v->a, v->b, v->c);
    } else if (mode == 2) {
        func_002fee78(buf, D_00371678, func_002402e0(), D_0035ec04);
    } else {
        func_002fee78(buf, D_00371680, func_002402e0(), v->a, v->b, v->c, a);
    }
}

struct W93Mdl { u8 pad[392]; s32 f392; u8 p2[408 - 396]; u32 f408; u8 p3[432 - 412]; s32 f432; };
struct W93Six { s16 id; s16 pad; s16 val; };
extern s32 D_0035ee2c;
extern s32 D_0035ee18[];
extern u32 D_003723b8[];
union W93MdlP { W93Mdl* p; s32 i; };
extern W93MdlP D_0035ee10;
extern W93Six D_00372390[];
extern u32 D_0035ee08;
s32 func_0024f2b8(void);
s32 func_00139d78(W93Mdl*);
W93Mdl* func_0028c198(s32, s32, s32, u32, u32, u32);
void func_00138c10(W93Mdl*, s32);
u32 func_00192048(u32);
// Switches the displayed model slot and reloads/rebinds the model for it.
void func_0024f070(s32 idx)
{
    s32 prev = D_0035ee2c;
    D_0035ee2c = idx;
    s32 r = func_0024f2b8();
    u32 res = D_003723b8[D_0035ee18[idx] ? idx + 5 : idx];
    if (!func_00139d78(D_0035ee10.p)) {
        W93Six* e = &D_00372390[r];
        D_0035ee10.p = func_0028c198(e->id, 2, 2, D_0035ee08, res, 0);
        D_0035ee10.p->f392 = e->val;
        D_0035ee10.p->f432 = 2;
    } else if (prev != D_0035ee2c) {
        W93Six* e = &D_00372390[r];
        func_00138c10(D_0035ee10.p, e->id);
        D_0035ee10.p->f392 = e->val;
        D_0035ee10.p->f408 = func_00192048(res);
    }
}

}
