#include "../common/types.h"

// 128-bit vector with the engine's self-checking quadword copy
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// local with an empty destructor: keeps the final call a jal
struct NoTail { ~NoTail() {} };

struct Slot117 { u32 a, b; void* p; u8 pad[52]; ~Slot117() {} } __attribute__((aligned(16)));
struct SlotArr117 { Slot117 s[24]; };
struct Obj117 {
    void* vtbl; u8 pad[28];
    SlotArr117 slots;
    void* f1568;
};

extern "C" {

void func_001617c8(void);
void func_00106998(s32);
void func_001069f8(s32);
u8* func_00102c18(s32, s32, void (*)(void));
void func_00161818(void);
void func_001433e8(void);
void func_00107888(void);
void func_001dd2b8(void);
void func_00144250(void);
void func_00161880(void);
void func_001618a0(void);
void func_001dd920(void);
void func_00167228(void);
void func_0015de18(void);
// registers this module's handlers
void func_001618f0(void) {
    func_001617c8();
    func_00106998(0);
    func_001069f8(0);
    func_00102c18(3, 6000, func_00161818);
    func_00102c18(3, 6001, func_001433e8);
    func_00102c18(3, 30000, func_00107888);
    func_00102c18(3, 41000, func_001dd2b8);
    func_00102c18(3, 43000, func_00144250);
    func_00102c18(3, 49999, func_00161880);
    func_00102c18(3, 50000, func_001618a0);
    func_00102c18(3, 60001, func_001dd920);
    func_00102c18(3, 71000, func_00167228)[4] = 0;
    func_00102c18(3, 65000, func_0015de18);
}

void func_00102788(u32, s32, s32, void (*)(void));
u8* func_00102c80(void);
void func_00111f50(void);
void func_001122a0(void);
void func_00112388(void);
void func_001127b0(void);
void func_00190128(void*);
void func_001357c8(void);
void func_00135d78(void);
extern u32 D_00351214;
extern u32 D_00341708[3];
extern Vec4 D_00341720[3];
extern Vec4 D_00341750[3];
extern u8 D_00341700;
extern u32 D_00341780;
extern u8 D_003417b0[];
void func_001123f0(void) {
    s32 i;
    func_00102788(D_00351214, 0, 4, func_00111f50);
    func_00102788(D_00351214, 0, 6, func_001122a0);
    func_00102788(*(u32*)(func_00102c80() + 4), 1, 20500, func_00112388);
    for (i = 0; i < 3; i++) {
        D_00341708[i] = 0;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&D_00341720[i]) : "memory");
        D_00341750[i] = D_00341720[i];
    }
    D_00341700 = 0;
    D_00341780 = 2;
    func_001127b0();
    func_00190128(D_003417b0);
    func_001357c8();
    func_00135d78();
}

void func_001dc920(void*);
void func_00117910(void*, s32);  // entry64_clear_fields
void func_0018f028(void*);
void func_00113668(void*);
extern u8 D_003476f0[];
// destructor body: release the 24 slots, then the base part
void func_00117dd8(Obj117* o) {
    NoTail g;
    s32 i;
    o->vtbl = D_003476f0;
    for (i = 0; i < 24; i++) {
        if (o->slots.s[i].p) func_001dc920(o->slots.s[i].p);
        func_00117910(o, i);  // entry64_clear_fields
    }
    if (o->f1568) { func_0018f028(o->f1568); o->f1568 = 0; }
    o->slots.~SlotArr117();
    func_00113668(o);
}

void func_0011ee18(void*);  // obj_ctor_347940
void func_0011f2f0(void*);
extern u8 D_00347a90[];
typedef s32 (*PartFn)(void*);
struct Obj123 { void* vtbl; u8* data; u8 pad[8]; s32 n; s32 a[3]; s32 b[3]; };
// constructor: walks the part offset table, accumulating running sizes
void func_001239d8(Obj123* o) {
    s32 s3, s4;
    u8* d;
    s32* list;
    s4 = 0; s3 = 0;
    func_0011ee18(o);  // obj_ctor_347940
    d = o->data;
    o->n = 0;
    o->vtbl = D_00347a90;
    list = (s32*)(d + 16);
    while (*list) {
        s32* p = (s32*)(d + *list);
        list++;
        func_0011f2f0(p);
        s4 += ((PartFn*)*p)[2](p);
        o->a[o->n] = s4;
        s3 += ((PartFn*)*p)[12](p);
        o->b[o->n] = s3;
        o->n++;
    }
}

void func_00188340(void*, s32, s32, s32);
void func_0016cce8(void*, s32, s32, s32, s32);
struct Obj184;
struct Obj184vt { u8 pad[44]; void (*f44)(Obj184*); };
struct Sub184vt { u8 pad[16]; void (*f16)(void*, Obj184*); };
struct Sub184 { Sub184vt* vt; };
struct Obj184 { Obj184vt* vt; u8 p4[8]; Sub184* f12; u8 p16[248]; u32 flags; u8 p268[500]; u8 f768[388]; void* f1156; };
void func_001841f0(Obj184* o) {
    o->flags &= ~0x04000000;
    func_00188340(o->f768, 1, 0, 0);
    if (!(o->flags & 0x04000000) && o->f1156) func_0016cce8(o->f1156, 13, 0, 0, 0);
    if (!(o->flags & 0x04000000)) o->f12->vt->f16(o->f12, o);
    if (!(o->flags & 0x04000000)) o->vt->f44(o);
}

u32 func_001a80c8(u32);  // table24_find_by_id
u8* func_001a8190(u32);
void func_001c3150(void*, u16);
struct St1a2 { u8 pad[392]; u16 s[4]; u8 p400[24]; u8 r[8]; u8 p432[28]; u8 f460[4]; };
void func_001a24a0(St1a2* o, u32 id) {
    u8* v;
    s32 i;
    if (!id) return;
    v = func_001a8190(func_001a80c8(id));
    if (!v) return;
    o->s[0] += v[4];
    o->s[1] += v[5];
    o->s[2] += v[6];
    o->s[3] += v[7];
    for (i = 0; i < 7; i++) o->r[i] = (o->r[i] * v[8 + i] + 99) / 100;
    func_001c3150(o->f460, *(u16*)(v + 2));
}

s32 func_00181500(u32);
u8* func_001947c0(u32, u32);
struct Cond1a8 { u16 id, need, without; u8 lv; };
// checks an entry's requirements (id, required/forbidden flags, level)
s32 func_001a8930(Cond1a8* c, u32 id, u32 a2) {
    s32 r = 0;
    if (c->id == 0 || c->id == id) {
        if (c->need == 0 || func_00181500(c->need)) {
            if (c->without == 0 || !func_00181500(c->without)) {
                if (c->lv == 0 || func_001947c0(a2, id)[52] == c->lv - 1) r = 1;
            }
        }
    }
    return r;
}

extern s32 D_00350f18;
extern u32 D_00350f1c;
extern char D_0036d9a8[];
extern u8 D_01d44440[];
extern u32 D_01d44400;
extern u32 D_01d48c44;
void func_00102448(void*, s32);
void func_002fee78(char*, const char*, ...);
void func_001688c8(char*);
void func_00168388(char*, void*, s32, s32);
s32 func_001688b8(void);
void func_001b1ee8(u8* o) {
    char buf[48];
    u32 v;
    while (D_00350f18) func_00102448(o, 0);
    D_00350f18 = 1;
    v = *(u32*)(o + 4);
    func_002fee78(buf, D_0036d9a8, v);
    func_001688c8(buf);
    func_00168388(buf, D_01d44440, 0, 0);
    while (func_001688b8()) func_00102448(o, 0);
    D_00350f1c = v;
    D_00350f18 = 0;
    D_01d44400 = 0;
    D_01d48c44 = 0;
}

s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001d1b60(void*, s32);
struct Dig1d8 { u8 p0[12]; u32 flags; u8 p16[28]; s32 cur; };
static inline u32 dig1d8_on(Dig1d8* e) { return e->flags & 1; }
// replaces one decimal digit of an entry's value
void func_001d89e8(s32 digit, s32 val, s32 idx) {
    Dig1d8* e;
    s32 m, n, cur;
    if (!func_001bb4a0()) return;
    if (!(u8)dig1d8_on((Dig1d8*)(func_001bbcb0() + idx * 56 + 232))) return;
    e = (Dig1d8*)(func_001bbcb0() + idx * 56 + 232);
    m = 1;
    cur = e->cur;
    if (digit > 0) { n = digit; do { m *= 10; } while (--n); }
    func_001d1b60(e, cur + (val - cur / m % 10) * m);
}

u8* func_001e09a0(void*, s32, s32, s32);  // entry64_by_3index
f32 func_001e09d0(void* o) {
    f32 sum = 0.0f, cnt = 0.0f;
    s32 i, j;
    for (j = 0; j < 9; j++)
        for (i = 1; i < 4; i++) {
            cnt += 100.0f;
            sum += *(f32*)(func_001e09a0(o, j, i, 0) + 32);  // entry64_by_3index
        }
    return sum / cnt * 100.0f;
}

struct V3f { f32 x, y, z; };
extern V3f D_00354bd0;
extern V3f D_00354bc0;
void func_0021ebe8(void*, s32*);
// converts the current rotation (radians) to fixed-point angles and applies it
void func_00201668(u8* o, u8* a1) {
    s32 r[3];
    u8* t;
    f32 x = D_00354bd0.x * 32768.0f / 3.1415927f;
    f32 y = D_00354bd0.y * 32768.0f / 3.1415927f;
    f32 z = D_00354bd0.z * 32768.0f / 3.1415927f;
    t = o + *(s32*)(*(u8**)(a1 + 12) + 12) + 160;
    r[0] = (s32)x;
    r[2] = (s32)z;
    r[1] = (s32)y;
    func_0021ebe8(t, r);
    *(f32*)(t + 48) = D_00354bc0.x;
    *(f32*)(t + 52) = D_00354bc0.y;
    *(f32*)(t + 56) = D_00354bc0.z;
}

char* func_00227120(void);  // get_data_1dbd8f8
s32 func_002ff538(const char*, const char*, s32);
extern char D_00370cd8[];
extern char D_00370ce8[];
extern char D_00370cf8[];
extern char D_00370d08[];
extern char D_00370d18[];
s32 func_00224c20(void) {
    if (!func_002ff538(func_00227120(), D_00370cd8, 12)) return 1;
    if (!func_002ff538(func_00227120(), D_00370ce8, 12)) return 2;
    if (!func_002ff538(func_00227120(), D_00370cf8, 12)) return 3;
    if (!func_002ff538(func_00227120(), D_00370d08, 12)) return 4;
    if (!func_002ff538(func_00227120(), D_00370d18, 12)) return 5;
    return -1;
}

struct Blk225 { Blk225* next; Blk225* prev; u8 used; u32 size; u8 pad[48]; };
struct Heap225 { u8 pad[8]; Blk225* head; };
// first-fit (mode 1: last fit, carved from the top) block allocator
void* func_00225eb8(Heap225* h, u32 size, s32 mode) {
    Blk225* b;
    Blk225* best = 0;
    Blk225* nb;
    Blk225* nx;
    u32 rem;
    size += 63;
    size &= ~63;
    size += 64;
    for (b = h->head; b; b = b->next) {
        if (b->used) continue;
        if (size < b->size) {
            best = b;
            if (mode != 1) break;
        }
    }
    if (!best) return 0;
    rem = best->size - size;
    if (rem >= 128) {
        if (mode != 1) {
            nb = (Blk225*)((u8*)best + size);
            nx = best->next;
            nb->size = rem;
            nb->next = nx;
            nb->prev = best;
            nb->used = 0;
            if (nx) nx->prev = nb;
            best->next = nb;
            best->used = 1;
            best->size = size;
        } else {
            Blk225* old = best;
            nx = best->next;
            best = (Blk225*)((u8*)best + rem);
            best->used = mode;
            best->size = size;
            best->next = nx;
            best->prev = old;
            if (nx) nx->prev = best;
            old->size = rem;
            old->used = 0;
            old->next = best;
        }
    } else {
        best->used = 1;
    }
    return best + 1;
}
struct Obj22f;
struct Obj22fvt { u8 pad[40]; void (*f40)(Obj22f*); };
struct Obj22f { Obj22fvt* vt; };
void func_001ba028(Obj22f*);  // list_contains_ptr
void func_00232db0(u32);
struct Ent22f { s32 id; u32 f4; Obj22f* obj; u8 pad[28]; };
union Tbl22f { Ent22f* p; u8 c; };
extern Tbl22f D_0035dcfc;
// releases every live entry; returns whether any was released
s32 func_0022f5e8(void) {
    s32 r = 0;
    s32 i;
    if (!D_0035dcfc.p) return 0;
    for (i = 0; i < 96; i++) {
        if (D_0035dcfc.p[i].obj) {
            func_001ba028(D_0035dcfc.p[i].obj);  // list_contains_ptr
            D_0035dcfc.p[i].obj->vt->f40(D_0035dcfc.p[i].obj);
            D_0035dcfc.p[i].obj = 0;
            func_00232db0(D_0035dcfc.p[i].f4);
            D_0035dcfc.p[i].id = -1;
            r = 1;
        }
    }
    return r;
}

f32 func_002f8960(f32);
f32 func_002f87c0(f32);
struct Rot237 { u8 p0[28]; f32 m28, m32, m36, m40; u8 p44[68]; f32 x, y, z; };
// sets euler angles and rebuilds the matrix rows that depend on them
void func_00237740(Rot237* r, f32 x, f32 y, f32 z) {
    f32 sx, cx, sy, cy, sz, cz, sxsy;
    r->y = y;
    r->z = z;
    r->x = x;
    sx = func_002f8960(r->x);
    cx = func_002f87c0(r->x);
    sy = func_002f8960(r->y);
    cy = func_002f87c0(r->y);
    sz = func_002f8960(r->z);
    cz = func_002f87c0(r->z);
    sxsy = sx * sy;
    r->m28 = cy * cz;
    r->m36 = sxsy * cz + cx * sz;
    r->m32 = cy * -sz;
    r->m40 = sxsy * -sz + cx * cz;
}

extern void* D_0035ed54;
extern void* D_0035ed4c;
extern void* D_0035ed5c;
extern void* D_0035ed58;
struct Pair248 { s16 a, b, c; };
extern Pair248 D_00371d40[];
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
s32 func_002891e8(void*);
void func_00248720(void) {
    if (func_00139d78(D_0035ed54) && func_0023f0c0(D_0035ed54) != 32)
        func_0023f070(D_0035ed54, 32, -1);
    if (func_0028acc8(D_0035ed4c)) {
        s32 v;
        func_0028ab20(D_0035ed4c);
        v = func_002891e8(D_0035ed4c);
        if (func_00139d78(D_0035ed5c) && func_0023f0c0(D_0035ed5c) != D_00371d40[v].c)
            func_0023f070(D_0035ed5c, D_00371d40[v].c, -1);
    }
    if (func_00139d78(D_0035ed58) && func_0023f0c0(D_0035ed58) != 35)
        func_0023f070(D_0035ed58, 35, -1);
}

extern void* D_0035f01c;
struct Ent273 { u16 id; u8 pad[6]; };
extern Ent273 D_00373af8[];
s32 func_00287bc0(void);
s32 func_0028b160(void*, u8*);  // find_index_in_array
u32 func_00192048(u16);
void func_001a98e8(void*, s32, u32, u32, s32);
s32 func_0023aa98(void*);
u32 func_0023a918(void*);
void func_001a9ae8(void*, u8*, u32, u32);
void func_00273078(u8* base, u32 a1, u32 a2, u32 a3, u8* p) {
    u8 buf[96];
    s32 v;
    u32 x;
    if (func_00287bc0() != 31) return;
    v = func_0028b160(D_0035f01c, p);  // find_index_in_array
    x = *(u32*)(p + 424);
    func_001a98e8(buf, 1, func_00192048(D_00373af8[v / 2].id), x, 0);
    func_001a9ae8(buf, base + func_0023aa98(p + 24), a1, func_0023a918(p + 24));
}

extern s16 D_00373d60[];
extern s16 D_00373d68[];
extern u8* D_0035f204;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern s32 D_0035f144;
s32 func_00276368(void);
void func_00138c10(void*, s32);
void func_0028d8c0(void*, s32, u32, u32, u32, s32, s32, s32);
// plays the selected entry's cue (mode picks the table)
void func_00276220(s32 mode, s32 idx) {
    s16* t;
    if (!mode) t = D_00373d60; else t = D_00373d68;
    if (!func_00276368())
        func_0028d8c0(D_0035f204, 30041, D_0035f14c, D_0035f148, D_0035f210, t[idx], -1, 0);
    else
        func_00138c10(D_0035f204, t[idx]);
    if (idx == 0) *(s32*)(D_0035f204 + 392) = t[2]; else *(s32*)(D_0035f204 + 392) = -1;
    D_0035f144 = mode;
}

extern f32 D_0035f294;
extern f32 D_00349e10;
extern u8 D_0035f298;
struct Snd281 { s16 id; };
extern Snd281 D_0035f280;
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
s32 func_001688b8(void);
s32 func_00292a90(s16);
void func_00292b40(Snd281*, s32);
void func_00281d48(void) {
    if (D_0035f294 <= 0.0f) return;
    if (0.0f < D_0035f294) D_0035f294 = D_0035f294 - D_00349e10;
    if (func_003142e0(func_00313b80(D_0035f294), 0.0) < 0) D_0035f294 = 0.0f;
    if (func_003142e0(func_00313b80(D_0035f294), 0.0) > 0) return;
    if (func_001688b8()) return;
    if (!func_00292a90(D_0035f280.id)) func_00292b40(&D_0035f280, 1);
    D_0035f298 = 1;
}

struct Item282 { u16 id; u8 a, b; u16 pad; };
struct List282 { union { s32 n; u16 h; } u; Item282 e[1]; };
u8* func_001058e8(void);
// appends each nonzero id from the 8-entry table that is not already listed
void func_00282620(List282* l) {
    s32 i, j;
    for (i = 0; i < 8; i++) {
        u16 id = ((u16*)(func_001058e8() + 14056))[i];
        if (id) {
            for (j = 0; j < l->u.n; j++) {
                u16 x = l->e[j].id;
                if (x && id == x) break;
            }
            if (j >= l->u.n) {
                l->e[l->u.n].id = id;
                l->e[l->u.n].a = 0;
                l->e[l->u.n].b = 0;
                l->u.n++;
            }
        }
    }
}

extern u8 D_003741e8[];
u32 func_00259618(u16, u8*, s32);
void func_00192b30(u32);
void func_00192cc0(u8*, u8*, u8);
void func_00282858(List282* l, s32 first, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        Item282* e;
        u8* row;
        if (i + first >= l->u.n) break;
        e = &l->e[first + i];
        row = (u8*)l + i * 80;
        func_00192b30(func_00259618(e->id, row + 1556, e->b != 0));
        if (e->a != 1) func_00192cc0(row + 1540, D_003741e8, e->a);
        else row[1540] = 0;
    }
}
void func_0028af18(void*, s32);
void func_0028b1b0(void*, s32);
void func_0028b218(void*, s32);  // obj_set_flag39_bits3000
void func_0028b248(void*, s32);  // set_field28_half
union S16U { s16 s; u8 c; };
union U32U { u32 w; u8 c; };
struct Obj288 { u8 p0[4]; s16 n; u8 p6[8]; s16 h14; u8 p16[2]; s16 h18; u8 p20[2]; s16 h22; u8 p24[16]; U32U* a; S16U* b; S16U* c; };
void func_00288e88(Obj288* o) {
    s32 i, k;
    for (i = 0; i < o->n; i++) {
        o->a[i].w = 0;
        for (k = 0; k < 4; k++) {
            o->b[i * 4 + k].s = -1;
            o->c[i * 4 + k].s = -1;
        }
    }
    o->n = 0;
    o->h22 = 0;
    o->h18 = 0;
    o->h14 = 0;
    func_0028af18(o, 115);
    func_0028b1b0(o, 0);
    func_0028b218(o, 0);  // obj_set_flag39_bits3000
    func_0028b248(o, 1);  // set_field28_half
}

void func_0028eb88(u32, s32, f32, f32);
void func_0028e8b8(u32, s32, s32, s32);
struct Bar28b { u32 h; u8 p4[28]; s32 cur; s32 max; u8 p40[4]; s32 a; s32 b; };
void func_0028bfc0(Bar28b* o, s32 v) {  // int_to_float_clamp
    f32 r, s;
    o->cur = v < o->max ? o->max : v;
    r = (f32)o->max / (f32)v;
    if (func_003142e0(1.0, func_00313b80(r)) <= 0) r = 1.0f;
    s = (f32)o->a / (f32)o->b * r;
    func_0028eb88(o->h, 2, 1.0f, s);
    func_0028e8b8(o->h, 3, 0, (s32)((f32)o->b * s));

}

extern s32 D_0035f4c4;
extern s32 D_0035f4bc;
extern s32 D_0035f4c0;
extern s32 D_0035f4c8;
extern s32 D_0035f4cc;
extern s32 D_0035f4d0;
extern void* D_0035f4d4;
extern void* D_0035f4dc;
extern void* D_0035f4e4;
extern s8 D_00374590[][2];
u32 func_00103570(void);
void* func_001063f0(s32, u32);
void func_002fde18(void*, s32, s32);
void func_002926c0(s32 idx) {
    D_0035f4c4 = idx;
    D_0035f4bc = D_00374590[idx][0];
    D_0035f4c0 = D_00374590[idx][1] << 11;
    D_0035f4c8 = 0;
    D_0035f4cc = 0;
    D_0035f4d0 = 0;
    D_0035f4d4 = func_001063f0(D_0035f4bc * 16, func_00103570());
    func_002fde18(D_0035f4d4, 0, D_0035f4bc * 16);
    D_0035f4dc = func_001063f0(D_0035f4bc * 4, func_00103570());
    func_002fde18(D_0035f4dc, 0, D_0035f4bc * 4);
    D_0035f4e4 = func_001063f0(128, func_00103570());
    func_002fde18(D_0035f4e4, 0, 128);
}

extern void* D_0035f200;
s32 func_0028afa8(void*);
s32 func_0028b040(void*);
u8* func_002891b8(void*, s32);
void func_00138c10(void*, s32);
void func_002955a8(void) {
    s32 i = 0;
    s32 n = func_0028afa8(D_0035f200);
    s32 cur = func_0028b040(D_0035f200);
    for (; i < n; i++) {
        if (*(s32*)(func_002891b8(D_0035f200, i) + 388) == 172) func_00138c10(func_002891b8(D_0035f200, i), 173);
        if (i == cur) func_00138c10(func_002891b8(D_0035f200, i), 172);
    }
}

struct Ev2ad { u8 p0[4]; u8 done; u8 p5[3]; u16 id; };
Ev2ad* func_001a82b0(Ev2ad*);

s32 func_002a4390(Ev2ad*);
extern s32 D_0035f628;
extern s32 D_0035f62c;
extern u8* D_0035f620;
// counts unlocked entries and marks the ones that pass in the bitmask
void func_002ad9f8(void) {
    Ev2ad* p = 0;
    u32 idx = 0;
    for (;;) {
        p = func_001a82b0(p);
        if (!p) break;
        if (!p->done && p->id && p->id != 2048 && func_00181500(p->id)) {
            D_0035f628++;
            if (func_002a4390(p)) {
                { u32 o = (idx >> 5) * 4; u32 m = 1 << (idx & 31); u8* b = D_0035f620 + 236; *(u32*)(b + o) |= m; }
                D_0035f62c++;
            }
        }
        idx++;
    }
}
s32 func_002d5578(u8*);  // is_field340_eq151
void func_00178d28(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
#define TAIL     func_00178d28(o); \
        if (*(u8**)(o + 3096)) { f32 z = 0.0f; \
            func_0017f488(*(u8**)(o + 3096) + 320, 151, z, z); \
            func_0017f5e0(*(u8**)(o + 3096) + 320, 0, 0, z, z); }
void func_002d54a8(u8* o) {
    if (!func_002d5578(o) || (*(u32*)(o + 352) & 0x10)) {  // is_field340_eq151
        if (*(f32*)(o + 3116) == 0.0f) {
            if (0.0f <= *(f32*)(o + 1360)) *(f32*)(o + 3104) = 1.0f;
            else *(f32*)(o + 3104) = -1.0f;
        }
        TAIL
    }
}
struct Buf302 { u8* base; s32 size; };
struct File302 {
    u8* p; s32 r; s32 w; s16 flags; s16 file; Buf302 bf; s32 lbfsize;
    u8 p28[20]; Buf302 ub; u8 p56[12]; Buf302 lb; u8 p76[8]; void* data;
};
struct Glue302 { Glue302* next; s32 niobs; File302* iobs; };
struct Ctx302 { s32 err; u8 p4[52]; s32 inited; u8 p60[412]; Glue302 glue; };
void func_00302e10(Ctx302*);
Glue302* func_00302c88(Ctx302*, s32);
// newlib __sfp: find (or make room for) a free FILE slot
File302* func_00302cf8(Ctx302* d) {
    File302* fp;
    s32 n;
    Glue302* g;
    if (!d->inited) func_00302e10(d);
    for (g = &d->glue;; g = g->next) {
        for (fp = g->iobs, n = g->niobs; --n >= 0; fp++)
            if (fp->flags == 0) goto found;
        if (g->next == 0 && (g->next = func_00302c88(d, 4)) == 0) break;
    }
    d->err = 12;
    return 0;
found:
    fp->flags = 1;
    fp->p = 0;
    fp->w = 0;
    fp->r = 0;
    fp->bf.base = 0;
    fp->bf.size = 0;
    fp->lbfsize = 0;
    fp->file = -1;
    fp->ub.base = 0;
    fp->ub.size = 0;
    fp->lb.base = 0;
    fp->lb.size = 0;
    fp->data = d;
    return fp;
}


}

// VU0 helpers
static inline void vu_scale(void* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(s) : "$8", "memory");
}
static inline f32 vu_len(void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void vu_scale_to(void* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void vu_zero(void* d) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory");
}
static inline void vu_mulmv(void* out, const void* m, const void* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
static inline f32 vu_normalize(void* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void vu_mcopy(f32 (*d)[4], const u8* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void vu_qcopy(f32* d, const f32* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void vu_unit(f32* d) {
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(d) : "memory");
}
// inverse of a rigid (rotation + translation) matrix
static inline void vu_minv(f32 (*d)[4], f32 (*s)[4]) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%1)\n\t"
                 "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                 "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                 "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
static inline void vu_sub_to(void* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vu_dot(const void* a, const void* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}

// position trail: records a new point once it moved 45 units from the last one
struct Trail10b { u8 moved; u8 changed; u8 p2[2]; s32 cur; u8 p8[8]; Vec4 pts[32]; };
u8 wtarget_0010b468(u32 a0, u32 a1, u32, u32) {
    Trail10b* t = (Trail10b*)a0;
    const Vec4* v = (const Vec4*)a1;
    t->changed = 0;
    if (t->cur < 0) {
        s32 i;
        Vec4* p = t->pts;
        for (i = 31; i >= 0; i--) { *p = *v; p++; }
        t->cur = 0;
    } else {
        Vec4 d;
        vu_sub_to(&d, v, &t->pts[t->cur]);
        if (!(2025.0f <= vu_dot(&d, &d))) return t->changed;
        t->cur = (t->cur + 1) % 32;
        t->pts[t->cur] = *v;
        t->moved = 1;
    }
    t->changed = 1;
    asm volatile("" ::: "memory");
    return t->changed;
}

extern "C" {

// inverse(M) * M.translation, negated
f32* func_00107388(f32* out, u8* o) {
    f32 m[4][4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32* row3 = m[3];
    vu_mcopy(m, o + 16);
    vu_qcopy(t, row3);
    vu_unit(row3);
    vu_minv(m, m);
    vu_mulmv(r, m, t);
    vu_scale_to(out, r, -1.0f);
    return out;
}

struct Obj180 { u8 p0[8]; void* f8; u8 p12[396]; u16 ids[16]; s32 n; };
struct It180 { u8 p0[16]; u32 flags; u8 p20[12]; };
static inline u32 it180_on(It180* e) { return e->flags & 1; }
s32 func_0011c230(It180*);
u16 func_0011c228(It180*);
void func_0016c698(void*, u16, It180*);
void func_00180a10(Obj180* o, It180* it) {
    u16 old[16];
    s32 i, j, n = o->n;
    for (i = 0; i < n; i++) old[i] = o->ids[i];
    o->n = 0;
    while (!func_0011c230(it)) {
        if ((u8)it180_on(it)) {
            u16 id = func_0011c228(it);
            o->ids[o->n++] = id;
            for (j = 0; j < n; j++) if (old[j] == id) goto next;
            func_0016c698(o->f8, id, it);
        }
    next:
        it++;
    }
}

extern u8* D_00352130;
u32 func_0019fdb0(u8*);
void func_001a2a18(u8*);
void func_001a2910(u32, u8* o) {
    u8* v = o + 32;
    vu_scale(v, *(f32*)(D_00352130 + 60));
    if (vu_len(v) < *(f32*)(o + 244)) {
        f32 z = 0.0f;
        func_0017f488(o + 320, func_0019fdb0(o), z, z);
        func_0017f5e0(o + 320, 0, 0, z, z);
        func_001a2a18(o);
    }
}

// transforms a point into the volume's space and tests it against the ellipse/height bounds
s32 func_001db368(u8* o, const Vec4* in) {
    Vec4 v;
    Vec4 t;
    f32 one;
    s32 r;
    v = *in;
    one = 1.0f;
    v.w = one;
    vu_mulmv(&t, o + 16, &v);
    v = t;
    r = 0;
    if (!(v.y < -*(f32*)(o + 84)) && !(*(f32*)(o + 84) < v.y)) {
        r = 1;
        v.x = v.x / *(f32*)(o + 80);
        v.z = v.z / *(f32*)(o + 88);
        if (!(v.x * v.x + v.z * v.z <= one)) r = 0;
    }
    return r;
}

f32 func_002f8b30(f32, f32);
static inline u32 pos186(f32 f) { return 0.0f < f; }
// decaying knockback velocity
Vec4* func_00186b90(Vec4* out, u8* o) {
    f32 f = *(f32*)(o + 2780);
    if ((u8)pos186(f)) {
        if (f < 1.0f) {
            *(f32*)(o + 2780) = 0.0f;
        } else {
            Vec4 t;
            vu_scale_to(&t, o + 2768, f * D_00349e10);
            *out = t;
            *(f32*)(o + 2780) *= func_002f8b30(0.9f, D_00349e10);
            return out;
        }
    }
    vu_zero(out);
    return out;
}

void func_0017c400(u8*, s32);
// launches along a direction: flattened, normalised, with the given speed and height
void func_001b2210(u8* o, Vec4* dir, f32 speed, f32 h) {
    f32 y = dir->y;
    f32 w = dir->w;
    f32 g;
    dir->y = 0.0f;
    vu_normalize(dir);
    g = (y + y) / (speed * speed);
    *(f32*)(o + 240) = h;
    *(f32*)(o + 244) = g;
    func_0017c400(o, 2);
    {
        Vec4* dst = (Vec4*)(o + 192);
        Vec4 t;
        vu_scale_to(&t, dir, w);
        *dst = t;
    }
    *(f32*)(o + 204) = 1.0f;
    *(f32*)(o + 196) = -g * speed;
}

}
