#include "../common/types.h"

struct Ent8 { u8 f0, f1, f2, f3; u16 f4, f6; };
struct EntTbl { Ent8 list[512]; Ent8 sub[15]; s32 count; s32 active; };
struct ItemRec { u8 f0, f1; u16 id; u8 f4; u8 f5; u16 f6; u16 f8; };
struct W1957Vec {
    f32 x, y, z, w;
    W1957Vec() {}
    W1957Vec& operator=(const W1957Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

void func_0017f488(int, int, float, float);

struct W1957V {
    f32 x, y, z, w;
    W1957V() {}
    W1957V(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1957V& operator=(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {

union TblPtr { EntTbl* p; u32 w; u16 h; u8 b; };
extern TblPtr D_0035f5e4;
u32 func_00276c18(void);
void func_002fde18(void*, s32, s32);
ItemRec* func_001a82b0(ItemRec*);
s32 func_00181500(u16);
s32 func_002a4390(ItemRec*);
u8 func_002764b0(u8);
void func_002a2ff8(void);
s32 func_002ab540(s32);
s32 func_002ab620(s32);
void func_002a2a80(void) {
    ItemRec* it = 0;
    s32 idx = 0;
    s32 n = 0;
    s32 cnt = 0;
    s32 r;
    u32 all = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    for (;;) {
        it = func_001a82b0(it);
        if (!it) break;
        if (it->f4 == 0 && it->f8 != 0 && it->f8 != 2048) {
            if (func_00181500(it->f8) || all) {
                r = func_002a4390(it);
                u8 v = func_002764b0(it->f5);
                D_0035f5e4.p->list[n].f0 = v;
                if (r) cnt++;
                D_0035f5e4.p->list[n].f4 = idx;
                D_0035f5e4.p->list[n].f6 = it->id;
                D_0035f5e4.p->list[n].f1 = r != 0;
                n++;
            }
        }
        idx++;
    }
    D_0035f5e4.p->count = n;
    D_0035f5e4.p->active = cnt;
    func_002a2ff8();
    for (s32 i = 0; i < 15; i++) {
        r = i * 8;
        Ent8* e = (Ent8*)(r + (u32)D_0035f5e4.p + 4096);
        if (e->f0 == 0) {
            e->f2 = 0;
            D_0035f5e4.p->sub[i].f3 = 0;
        } else {
            e->f2 = func_002ab540(i) != 0;
            D_0035f5e4.p->sub[i].f3 = func_002ab620(i) != 0;
        }
    }
}


struct W1957Range { u8 pad[12]; s16 lo, hi, z; };
struct W1957Tgt {
    virtual void v0();
    virtual void v1();
    virtual W1957Vec pos();
    u8 pad[36];
    W1957Range* range;
};
struct W1957Info { u32 f0, f4, flags; };
struct W1957Obj {
    u8 pad0[12];
    W1957Info* info;        // 0x0c
    u8 pad10[320 - 16];
    u8 sub[32];             // 0x140
    u32 flags;              // 0x160
    u8 pad164[2732 - 356];
    W1957Tgt* tgt;          // 0xaac
    f32 dist;               // 0xab0
    f32 f2740;              // 0xab4
    s32 act;                // 0xab8
};

W1957Vec func_0016be98(W1957Obj*);
void func_001c1fe0(W1957Obj*);
void w1957_change_action(W1957Obj*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern s32 D_003638d0;

static inline W1957Vec w1957_sub(const W1957Vec& a, const W1957Vec& b) {
    W1957Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline f32 w1957_len(const W1957Vec& v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}

static inline f32 w1957_frand(void) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)(u32)D_003638d0 * 2.3283064e-10f;
}

static inline bool w1957_flag(W1957Obj* o) {
    return (o->info->flags & 2) || (o->flags & 0x40);
}

void func_001c1b08(W1957Obj* self, W1957Tgt* tgt, u8 on) {
    self->tgt = tgt;
    W1957Vec d;
    d = w1957_sub(tgt->pos(), func_0016be98(self));
    f32 len = w1957_len(d);
    W1957Range* r = tgt->range;
    f32 lo = r->lo;
    f32 hi = r->hi;
    self->dist = lo + w1957_frand() * (hi - lo);
    s32 act = on ? 20 : 21;
    self->f2740 = tgt->range->z;
    self->act = act;
    func_0017f488((int)self->sub, act, 0.0f, 0.0f);
    func_001c1fe0(self);
    if (w1957_flag(self)) w1957_change_action(self, 15);
    else w1957_change_action(self, 14);
}


struct W1957Face { u8 pad[10]; u16 plane; u8 pad2[4]; };
struct W1957Hit { u8 d[32]; };
struct W1957Map {
    u8 pad0[12];
    W1957Face* faces;      // 0x0c
    u8 pad10[8];
    W1957V* planes;        // 0x18
    u8 pad1c[32];
    u16* list;             // 0x3c
};
struct W1957Who { u8 pad[48]; W1957V pos; u8 pad40[44]; f32 height; };

void func_00141988(W1957Map*, W1957Face*, W1957Hit*);
s32 func_00162408(W1957Hit*, W1957V*);
f32 func_002f8870(f32);

static inline f32 w1957_dot(const W1957V& a, const W1957V& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}

s32 func_00142688(W1957Map* map, f32* out, s32 n, W1957Who* who) {
    f32 best = 10000000.0f;
    u16 res = 0xffff;
    W1957V v;
    W1957V t;
    v = t = who->pos;
    t.y -= who->height;
    for (s32 i = 0; i < n; i++) {
        s32 id = map->list[i];
        W1957Face* f = &map->faces[id];
        W1957V* pl = &map->planes[f->plane];
        if (w1957_dot(t, *pl) + pl->w < 0.0f) continue;
        W1957Hit hit;
        func_00141988(map, f, &hit);
        if (!func_00162408(&hit, &v)) continue;
        f32 y = (-pl->w - (pl->x * v.x + pl->z * v.z)) / pl->y;
        f32 a = func_002f8870(t.y - y);
        if (a < best) {
            best = a;
            res = id;
            *out = y;
        }
    }
    return res;
}

}
