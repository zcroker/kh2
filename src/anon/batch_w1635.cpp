#include "../common/types.h"

// YS::SHEET-like status sheet (src/yasui/libys/sheet.*). Only the fields used here.
struct W1635SheetData;
struct W1635Obj;

struct W1635Gauge {
    s32 cur;               // +0
    s32 max;               // +4
    s32 x8;                // +8
};

struct W1635FormInfo {
    u8 pad0[4];
    u8 str, mag, def;      // 0x4..0x6
};

struct W1635Drive {
    u8 pad0[0x1038];
    u8 c[4];               // 0x1038
    f32 f0, f1;            // 0x103c
};

union W1635Int { s32 v; f32 f; };

struct W1635Sheet {
    W1635Gauge g[1];       // 0x000 hp/maxhp/..., 12-byte entries indexed by the caller
    u8 pad0c[0x180 - 0xc];
    s32 x180;              // 0x180
    s32 x184;              // 0x184
    u16 stat[4];           // 0x188
    u16 stat2[4];          // 0x190
    s32 lo;                // 0x198 upper clamp source
    s32 hi;                // 0x19c lower clamp source
    s32 x1a0;              // 0x1a0
    s32 x1a4;              // 0x1a4
    u8 rate[7];            // 0x1a8 percentages (reset to 100)
    u8 pad1af;
    u8 c[4];               // 0x1b0
    f32 f1b4, f1b8;        // 0x1b4
    f32 f1bc, f1c0;        // 0x1bc
    u8 pad1c4[0x1cc - 0x1c4];
    u8 sub[0x1fc - 0x1cc]; // 0x1cc
    u8 b1fc;               // 0x1fc
    u8 pad1fd[0x240 - 0x1fd];
    f32 f240;              // 0x240
    W1635SheetData* data;  // 0x244
    u16* extra;            // 0x248
    u8 pad24c[0x254 - 0x24c];
    s32 form;              // 0x254
    u8 pad258[0x25c - 0x258];
    W1635Obj* owner;       // 0x25c
    W1635Drive* drive;     // 0x260
};

struct W1635SheetData {
    u16 ability[2];        // 0x00
    u8 b4, b5, b6, b7;     // 0x04
    u8 b8, b9, b10, b11;   // 0x08
    u8 b12, b13, b14, b15; // 0x0c
    u8 n10, n11;           // 0x10
    u8 pad12[2];
    u16 list10[8];         // 0x14
    u16 list11[8];         // 0x24
};

struct W1635Obj {
    u8 pad0[0x48c];
    W1635Sheet* sheet;     // 0x48c
    u8 pad490[0x588 - 0x490];
    u32 flags;             // 0x588
    u8 pad58c[0xb50 - 0x58c];
    s32 xb50;              // 0xb50
};

struct W1635Attack {
    u8 pad0[8];
    s32 x8;                // 0x8
    W1635Obj* obj;         // 0xc
};

struct W1635AttackData {
    u8 pad0[4];
    u8 type;               // 0x4
    u8 kind;               // 0x5
    u16 power;             // 0x6
    u8 pad8;
    u8 elem;               // 0x9
};

struct W1635Default {
    u8 pad0[2];
    u16 v;                 // 0x2
    u8 pad4[2];
    u16 lo;                // 0x6
    u16 hi;                // 0x8
};

struct W1635Info {
    u8 pad0[0x52];
    u16 bonus;             // 0x52
};

struct W1635Param {
    u8 pad0[0x94];
    f32 f94;               // 0x94
    u8 pad98[0x178 - 0x98];
    s32 x178;              // 0x178
};

extern "C" {
W1635FormInfo* func_001b6fb0(s32, u8);
s32 func_001b73e8(W1635FormInfo*, s32);
void func_001c2f90(void*, W1635Sheet*);
void func_001c3060(void*);
void func_001a24a0(W1635Sheet*, u16);
extern W1635Int D_01c6cabc;
extern W1635Param* D_00352130;
W1635Info* func_00177860(W1635Obj*);
s32 func_0019ba60(W1635Obj*);
s32 func_001a1de0(W1635Sheet*);
s32 func_001a2108(W1635Sheet*, s32, s32);
s32 func_001a2200(W1635Sheet*, s32);
s32 func_001a22b0(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*);
s32 func_001a2340(W1635Sheet*, s32, W1635Sheet*, W1635AttackData*);
s32 func_001a2478(W1635Sheet*);
// pure: keeps the call heuristic from marking the fallback path as unlikely
W1635Default* func_001c0cc8(void) __attribute__((pure));

// Set the sheet up from its data record (null = keep the current one).
void func_001a11e0(W1635Sheet* s, W1635SheetData* d) {
    if (d == 0) {
        W1635SheetData* p = s->data;
        if (p == 0) return;
        d = p;
    }
    W1635FormInfo* fi = func_001b6fb0(s->form, d->b15);
    s32 v = d->b5;
    s->g[0].cur = v;
    s->g[0].max = v;
    s->g[0].x8 = 0;
    s32 m = d->b4;
    if (v < m) m = v;
    s->g[0].cur = m;
    s->x180 = (u32)d->b6 < (u32)d->b7 ? d->b6 : d->b7;
    s->x184 = d->b7;
    s->stat[0] = s->stat2[0] = fi->str + d->b9;
    s->stat[1] = s->stat2[1] = fi->mag + d->b10;
    s->stat[2] = s->stat2[2] = fi->def + d->b11;
    s32 r = func_001b73e8(fi, s->form);
    s->stat[3] = s->stat2[3] = d->b8 + r;
    s->f1bc = d->b12 * 60.0f;
    s->f1c0 = d->b13 * 60.0f;
    W1635Drive* dr = s->drive;
    if (dr) {
        s->c[0] = dr->c[0];
        s->c[1] = dr->c[1];
        s->c[2] = dr->c[2];
        s->c[3] = dr->c[3];
        s->f1b4 = dr->f0;
        s->f1b8 = dr->f1;
        s->g[0].x8 = D_01c6cabc.v;
    }
    void* sub = s->sub;
    func_001c2f90(sub, s);
    for (s32 j = 0; j < 7; j++) s->rate[j] = 100;
    s32 i;
    for (i = 0; i < 2; i++) func_001a24a0(s, d->ability[i]);
    if (s->extra) func_001a24a0(s, *s->extra);
    for (i = 0; i < d->n10; i++) func_001a24a0(s, d->list10[i]);
    for (i = 0; i < d->n11; i++) func_001a24a0(s, d->list11[i]);
    func_001c3060(sub);
}

static inline bool W1635_is6(W1635Obj* o) { return o->xb50 == 6; }

// Damage/amount for an attack against this sheet (idx picks the gauge used for the low-gauge bonus).
s32 func_001a1e20(W1635Sheet* s, W1635Attack* a, W1635AttackData* ad, s32 idx) {
    s32 v = 0;
    W1635Sheet* sh = 0;
    s32 lo, hi;
    W1635Obj* o = a->obj;
    if (o && (sh = o->sheet)) {
        switch (ad->kind) {
        case 0:
            v = sh->stat[0];
            if ((o->flags & 4) && func_001a1de0(sh)) v += func_00177860(a->obj)->bonus;
            break;
        case 1:
            v = sh->stat[1];
            break;
        }
        lo = sh->lo;
        hi = sh->hi;
    } else {
        W1635Default* dft = func_001c0cc8();
        v = dft->v;
        lo = dft->lo;
        hi = dft->hi;
    }
    switch (ad->type) {
    case 5:
        v = (s->g[idx].max * v * ad->power + 9999) / 10000;
        break;
    case 6:
        v = (v * ad->power + 99) / 100;
        break;
    default: {
        v -= s->stat[2];
        if (func_001a2478(s)) v -= s->b1fc;
        s32 mx = lo < s->x1a0 ? lo : s->x1a0;
        s32 mn = s->x1a4 < hi ? hi : s->x1a4;
        v = v < mx ? v : mx;
        v = mn < v ? v : mn;
        s32 rate = s->rate[ad->elem] * s->rate[6];
        v = (v * ad->power * rate + 999999) / 1000000;
        v = func_001a2108(s, v, a->x8);
        v = func_001a2200(s, v);
        if (func_0019ba60(s->owner)) {
            W1635Obj* ow = s->owner;
            if ((ow->flags & 0x80) && W1635_is6(ow)) v = (s32)(v * D_00352130->f94);
        }
        v = func_001a22b0(s, v, sh, ad);
        v = func_001a2340(s, v, sh, ad);
        break;
    }
    }
    if ((s32)(s->g[idx].max * s->f240) >= s->g[idx].cur) v = (v * D_00352130->x178 + 99) / 100;
    return v;
}
}
