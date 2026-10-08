#include "../common/types.h"
extern "C" {
// ---- f2.cpp
s32 func_002282f0(u16);
void func_00225530(void);
s32 func_002ba200(void);
void func_002259f0(void);
void func_00225a00(void);
void func_00102448(s32, s32);
void func_002ba220(u8, s32, s32, s32, s32, s32);
void func_002ba830(u8, s32, s32);
s32 func_002b7148(s32);
void func_00136b78(u8, s32);
extern s32 D_00370d88[];
extern s32 D_00370d78[];
void func_002253a0(u8* p, s32 arg) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    if (*(u16*)(p + 6)) func_00225530();
    u16 m = *(u16*)(p + 8);
    if (m == 0) {
        while (func_002ba200()) {
            func_002259f0();
            func_00102448(arg, 0);
        }
        func_00225a00();
        func_002ba220(p[11], 12288, 12288, 0, 0, 0);
        func_00136b78(p[11], 12288);
    } else if (m == 257) {
        while (func_002ba200()) {
            func_002259f0();
            func_00102448(arg, 0);
        }
        func_00225a00();
        if (func_002b7148(0)) func_002ba830(p[11], 6144, 6144);
        else func_002ba220(p[11], 6144, 6144, 0, 0, 0);
        func_00136b78(p[11], 6144);
    } else {
        s32 a = D_00370d88[p[9]];
        func_002ba830(p[11], a, D_00370d78[p[10]]);
        func_00136b78(p[11], a);
    }
}

// ---- f3.cpp
u8* func_001a1658(s32, s32);
void func_001a17c8(u8*);
bool func_001a1de0(u8*);
bool func_001a2758(u8*);
bool func_001a2778(u8*);
bool func_001a2798(u8*);
bool func_001a27b8(u8*);
static inline bool IsFullA(u8* p) { return *(s32*)(p + 0) >= *(s32*)(p + 4); }
static inline bool HasC(u8* p) { return p[433] < p[434]; }
static inline bool IsFullB(u8* p) { return !func_001a1de0(p) && *(s32*)(p + 384) >= *(s32*)(p + 388); }
bool func_001a2e50(u16* req, s32 id) {
    bool r = false;
    u8* p = func_001a1658(id, -1);
    if (!p) return false;
    switch (*req) {
    case 1: case 2: case 5:
        r = !IsFullA(p);
        break;
    case 3: case 6:
        r = !IsFullB(p);
        break;
    case 4: case 7: case 131:
        r = !(IsFullA(p) && IsFullB(p));
        break;
    case 274: case 275:
        r = HasC(p);
        break;
    case 276: r = !func_001a2758(p); break;
    case 277: r = !func_001a2778(p); break;
    case 278: r = !func_001a2798(p); break;
    case 279: r = !func_001a27b8(p); break;
    }
    func_001a17c8(p);
    return r;
}

// ---- f4.cpp
s32 func_001a9528(u8*);
void func_001dddd0(s32, s32);
s32 func_001de168(s32, s32, s32, s32, s32, s32);
void func_001a9560(u8* self, s32 a1, s32 a2, s32* out) {
    s32 v = func_001a9528(self);
    if (!v) return;
    func_001dddd0(a2, v);
    u8* o = *(u8**)(self + 8);
    s32 i;
    switch (*(u16*)(o + 76)) {
    case 5013:
        for (i = 0; i < 3; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    case 1016:
    case 5002:
        *out = func_001de168(a2, 0, 0, 1, 0, a1);
        break;
    case 5026:
        for (i = 0; i < 9; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    case 5066:
        for (i = 0; i < 14; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
        break;
    default:
        switch (*(u32*)o) {
        case 2184: case 2186: case 2187: case 2188: case 2428:
            *out = func_001de168(a2, 0, 0, 1, 0, a1);
            break;
        case 2185:
            for (i = 0; i < 4; i++) out[i] = func_001de168(a2, i, 0, 1, 0, a1);
            break;
        }
        break;
    }
}

// ---- f5.cpp
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036edb0[];
extern char D_0036edc0[];
extern char D_0036ede0[];
extern u8 D_01d9e450[];
u32 func_002fdfc8(const char*, ...);
void func_002f28b8(void*, s32, s32, s32, s32, s32, s32, s32);
void func_003058a0(s32);
void func_002f2be0(void*, void*);
static inline void assert_fail_1e52b8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break");
}
struct NoTail52b8 { ~NoTail52b8() {} };
void func_001e52b8(u8* p, s16 off) {
    NoTail52b8 nt;
    s16 v = *(s16*)(p + 2);
    if (!p) assert_fail_1e52b8(D_0036edb0, D_0036e9d0, 1511);
    if (v == 0) return;
    if (v >= 15872) v = v + off - 15872;
    else v = v + off - 11776;
    if (v < 15616) assert_fail_1e52b8(D_0036edc0, D_0036e9d0, 1532);
    if (v + *(s16*)(p + 30) > 16384) assert_fail_1e52b8(D_0036ede0, D_0036e9d0, 1533);
    switch (*(s16*)(p + 6)) {
    case 19:
        func_002f28b8(D_01d9e450, v, 1, 0, 0, 0, 16, 16);
        break;
    case 20:
        func_002f28b8(D_01d9e450, v, 1, 0, 0, 0, 8, 2);
        break;
    default:
        return;
    }
    func_003058a0(0);
    func_002f2be0(D_01d9e450, p + *(s32*)(p + 24) + 32);
}

// ---- f8.cpp
void func_00236d60(u8*);
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_00139538(u8*);
void func_0014cbe0(s32*, s32*, s32*, s32*);
s32 func_002c5238(s32, s32, s32*);
s32 func_0023aa98(u8*);
s32 func_001396c0(u8*);
void func_00138c10(u8*, s32);
void func_00138c68(u8*, s32, s32);
void func_00139580(u8*);
void func_00139570(u8*);
void func_0023f0c0(u8*);
void func_002c1460(u8*, s32);
typedef void (*VFn2c14e8)(u8*);
struct F2c14e8 { u32 f : 1; };
void func_002c14e8(u8* self) {
    s32 ids[3];
    s32 ids2[2];
    s32 a, b, c, d;
    func_00236d60(self);
    if (((F2c14e8*)(self + 24))->f) {
        if (func_00139d78(self + 28)) func_00139510(self + 28);
        (*(VFn2c14e8*)(*(u8**)self + 20))(self);
        return;
    }
    if (func_00139538(self + 192)) {
        ((F2c14e8*)(self + 24))->f = 1;
        return;
    }
    func_0014cbe0(&a, &b, &c, &d);
    s32 pos = 0;
    s32 n = func_002c5238(a, 3, ids);
    s32 step = func_0023aa98(self + 624);
    if (!func_001396c0(self + 192)) {
        for (s32 i = 0; i < 3; i++) {
            u8* o = self + 600 + i * 408;
            func_00138c10(o, ids[i] + 39);
            func_00138c68(o, pos, 0);
            if (2 - i < n) {
                func_00139580(o);
                pos += step;
            } else {
                func_00139570(o);
            }
        }
    }
    func_00138c68(self + 1824, pos, 0);
    pos += func_0023aa98(self + 1848);
    func_002c5238(b, 2, ids2);
    u8* o = self + 2232;
    for (s32 i = 0; i < 2; i++) {
        func_00138c10(o, ids2[i] + 39);
        func_00138c68(o, pos, 0);
        pos += step;
        o += 408;
    }
    func_0023f0c0(self + 28);
    func_002c1460(self, 2);
}

// ---- f9.cpp
extern void* D_0034a920[];
extern void* D_00348678[];
extern void* D_003486d8[];
extern void* D_00347f98[];
extern void* D_00347e60[];
extern void* D_00348608[];
void func_0031d6b0(u8*);
void func_00239870(u8*);
void func_0031cec0(u8*);
typedef void (*Dtor31d290)(u8*);
#define DestroyArr31d290(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor31d290*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Body31d290(u8* p) {
    *(void***)p = D_0034a920;
    DestroyArr31d290(p + 13232, p + 15600, 592);
    *(void***)(p + 12896) = D_00348678;
    *(void***)(p + 12928) = D_003486d8;
    func_0031d6b0(p + 12928);
    *(void***)(p + 12896) = D_00347f98;
    DestroyArr31d290(p + 6704, p + 12884, 412);
    DestroyArr31d290(p + 5008, p + 6704, 848);
    DestroyArr31d290(p + 4180, p + 4996, 408);
    DestroyArr31d290(p + 3364, p + 4180, 408);
    DestroyArr31d290(p + 2548, p + 3364, 408);
    DestroyArr31d290(p + 1732, p + 2548, 408);
    *(void***)(p + 1324) = D_00347e60;
    func_00239870(p + 1348);
    *(void***)(p + 1324) = D_00347f98;
    *(void***)(p + 916) = D_00347e60;
    func_00239870(p + 940);
    *(void***)(p + 916) = D_00347f98;
    *(void***)p = D_00348608;
    func_0031cec0(p + 64);
    *(void***)p = D_00347f98;
}
// Destructor: resets vtables and destroys the member object arrays (last to first).
void func_0031d290(u8* p) {
    Body31d290(p);
}
typedef void (*Free31d290)(u8*, u8*);
extern u8* D_00347f80;
// Deleting destructor: same, then frees through the global allocator.
void func_0031d490(u8* p) {
    Body31d290(p);
    asm volatile("" ::: "memory");  // keeps the final vtable store ahead of the allocator lookup
    u8* a = *(u8**)(D_00347f80 + 20);
    (*(Free31d290*)(*(u8**)a + 4))(a, p);
}

// ---- f12.cpp
struct List27ff00 {
    u8 pad[4];
    u8 count;
    u8 b5;
    s8 b6;
    s8 b7;
    s8 ids[40];
    s8 keys[40];
};
struct Ent27ff00 {
    s32 id;
    s32 flag;
    u8 pad[12];
    s32 key;
};
extern List27ff00* D_0035f260;
void func_002fde18(void*, s32, s32);
s32 func_002f1ab8(void);
Ent27ff00* func_002f1ac8(s32);
s32 func_002f1ae0(s32);
void func_0027ff00(void) {
    s32 n = 0;
    s32 i, j;
    func_002fde18(D_0035f260, 0, 88);
    D_0035f260->b6 = -1;
    D_0035f260->b7 = -1;
    D_0035f260->b5 = 0;
    s32 cnt = func_002f1ab8();
    for (i = 0; i < cnt; i++) {
        Ent27ff00* e = func_002f1ac8(i);
        if (e->flag != 0 && !func_002f1ae0(e->id)) continue;
        for (j = 0; j < n; j++) {
            if (D_0035f260->keys[j] == e->key) break;
        }
        if (j < n) continue;
        D_0035f260->ids[n] = e->id;
        D_0035f260->keys[n] = e->key;
        n++;
    }
    D_0035f260->count = n;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (D_0035f260->keys[i] > D_0035f260->keys[j]) {
                s8 t = D_0035f260->ids[i];
                D_0035f260->ids[i] = D_0035f260->ids[j];
                D_0035f260->ids[j] = t;
                t = D_0035f260->keys[i];
                D_0035f260->keys[i] = D_0035f260->keys[j];
                D_0035f260->keys[j] = t;
            }
        }
    }
}

// ---- f14.cpp
extern s32 D_0035f200;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
void func_00297010(void);
s32 func_00292630(void);
void func_00276690(s32);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028b1e8(s32, s32);
void func_00274cf0(s32);
void func_002925c0(void);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_002958b0(void);
s32 func_00289310(s32);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);
void func_0028f6f0(s32);
void func_00297008(void);
void func_00276dc0(void);
void func_00287c00(s32);
void func_00287cc0(s32);
void func_00297630(void) {
    s32 a = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (a != -1) {
                func_00287f90(0);
                func_00297010();
            }
            return;
        }
        if (func_00292630()) return;
        func_00276690(0);
        func_00297010();
        func_00287c30();
        s32 b = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_0028b1e8(D_0035f200, 1);
        func_00274cf0(b);
        func_002925c0();
        func_00276220(func_00276358(), 0);
        if (b == st) func_002958b0();
        return;
    }
    if (a != -1 || func_00289310(D_0035f200)) {
        if (!func_00276398()) {
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0(a, func_00289310(D_0035f200), 1, 0, 1))) {
        switch (a) {
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            func_0028f6f0(0);
            func_00297008();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(2);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- f17.cpp
struct G139f38 { s32 x0; s32 x4; s32 x8; u8 pad[8]; G139f38* x20; };
union U139f38 { G139f38* p; void* q; };
extern U139f38 D_00347f80_u asm("D_00347f80");
struct T139f38 { u8 pad[4]; void* x4; u8 pad2[40]; void* x48; };
void func_00139dc0(s32);
s32 func_00102c80(void);
s32 func_00103070(void);
s32 func_001045f0(void);
void func_00102180(s32*);
T139f38* func_00102c18(s32, s32, void*);
T139f38* func_00102f08(s32, s32, void*);
T139f38* func_00104588(s32, s32, void*);
s32 func_001024b0(G139f38*);
T139f38* func_00102788(s32, s32, s32, void*);
void func_00139de8(void);
void func_00139390(void);
void func_001393c8(void);
void func_001394c0(void);
void func_001394d8(void);
void func_00139308(void);
void func_00139f38(G139f38* arg) {
    T139f38* o;
    s32 mode;
    func_00139dc0(0);
    D_00347f80_u.p->x20 = arg;
    G139f38* g = D_00347f80_u.p;
    g->x8 = 0;
    g->x4 = 0;
    s32 m0 = func_00102c80();
    s32 m1 = func_00103070();
    s32 m2 = func_001045f0();
    func_00102180(&mode);
    if (mode == m0) {
        func_00102c18(1, 6010, (void*)func_00139de8);
        o = func_00102c18(1, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00102c18(1, 103500, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 103000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    } else if (mode == m1) {
        o = func_00102f08(0, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00102f08(0, 125000, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 120000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    } else if (mode == m2) {
        o = func_00104588(0, 100000, (void*)func_00139390);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001393c8;
        o = func_00104588(0, 127500, (void*)func_001394c0);
        o->x4 = D_00347f80_u.p;
        o->x48 = (void*)func_001394d8;
        D_00347f80_u.p->x0 = func_001024b0(arg);
        func_00102788(D_00347f80_u.p->x0, 0, 110000, (void*)func_00139308)->x4 = D_00347f80_u.p;
    }
}

// ---- f18.cpp
struct D1ddef0 { u16 id; u8 pad[14]; u32 flags; f32 radius; u8 pad2[4]; f32 v[12]; };
u8* func_001dcff0(u8*, u16, f32);
f32* func_001dc5f8(u8*);
f32* func_001dc648(u8*);
f32* func_001dc620(u8*);
u8* func_001de948(s32);
void func_001dea80(u8*, u8*, D1ddef0*, u8*, f32);
void func_001df670(u8*);
void func_00180df8(u8*, u8*);
extern s32 D_00352b50;
// Builds an entry from a descriptor and pushes its node onto the owner list head.
u8* func_001ddef0(u8* self, D1ddef0* d, s32 a2, s32 a3, s32 a4, u8* w) {
    f32 r = d->radius;
    if (d->flags & 1) r += 0.1f;
    u8* o = func_001dcff0(self + 8, d->id, r);
    *(u8**)(o + 12) = self;
    func_001dc5f8(o)[0] = d->v[0];
    func_001dc5f8(o)[1] = d->v[1];
    func_001dc5f8(o)[2] = d->v[2];
    func_001dc648(o)[0] = d->v[3];
    func_001dc648(o)[1] = d->v[4];
    func_001dc648(o)[2] = d->v[5];
    func_001dc620(o)[0] = d->v[6];
    func_001dc620(o)[1] = d->v[7];
    func_001dc620(o)[2] = d->v[8];
    u8* n = func_001de948(112);
    func_001dea80(n, o, d, w, r);
    u8** list = (u8**)(self + 12);
    if (list[0] == 0) {
        list[1] = n;
        list[0] = n;
        *(u8**)(n + 96) = 0;
    } else {
        *(u8**)(n + 96) = list[0];
        list[0] = n;
    }
    if (d->flags & 1) {
        func_001df670(n);
        if ((d->flags & 0x20) && D_00352b50 == 1) func_00180df8(w + 320, o);
    }
    return o;
}

// ---- f19.cpp
extern s32 D_0035f01c;
extern s32 D_0035ef6c;
extern s32 D_0035f04c;
extern s32 D_00373278;
extern s32 D_0037327c;
u8* func_00257770(void);
s32 func_00257130(void);
s32 func_00281f18(s32);
s32 func_002892f8(s32);
u8* func_002891b8(s32, s32);
void func_00138c10(u8*, s32);
s32 func_00192048(s32);
void func_00262af8(void);
s32 func_0028b038(s32);
void func_002827f0(s32, s32, s32);
u8* func_00281f30(s32);
struct E262820 { u16 id; u16 pad[2]; };
E262820* func_00281f20(s32);
void func_0028be78(s32, s32);
s32 func_00285d58(u16);
s32 func_00285e30(u16);
void func_00262820(void) {
    s32 i;
    u8* g = func_00257770();
    s32 cnt = func_00281f18(func_00257130());
    s32 n = func_002892f8(D_0035f01c);
    for (i = 0; i < n; i++) {
        *(s32*)(func_002891b8(D_0035f01c, i) + 408) = 0;
        func_00138c10(g + 0x87d0 + i * 408, D_0035ef6c);
    }
    if (cnt == 0) {
        func_00138c10(func_002891b8(D_0035f01c, 0), 302);
        u8* p = func_002891b8(D_0035f01c, 0);
        *(s32*)(p + 408) = func_00192048(0x845a);
        *(s32*)(func_002891b8(D_0035f01c, 0) + 432) = 2;
    } else {
        s32 sel = func_0028b038(D_0035f01c);
        func_002827f0(func_00257130(), sel, 18);
        u8* b = func_00281f30(func_00257130());
        E262820* l = func_00281f20(func_00257130());
        func_0028be78(D_0035f04c, sel / 2);
        u8* q = g + 0x87d0;
        for (i = 0; i < 18; i++) {
            if (i + sel >= cnt) break;
            *(u8**)(func_002891b8(D_0035f01c, i) + 408) = b + 16 + i * 80;
            if (func_00285d58(l[sel + i].id)) func_00138c10(q, func_00285e30(l[sel + i].id) ? D_0037327c : D_00373278);
            q += 408;
        }
    }
    func_00262af8();
}

// ---- f20.cpp
extern u8* D_0035f60c;
extern s32 D_0035f3d4;
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
u8* func_002766d0(void);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00139620(u8*);
void func_00138c68(u8*, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138c10(u8*, s32);
void func_002a92d8(void) {
    u8* g = func_002766d0();
    s32 id = D_0035f3d4;
    u8* q = g + 0xa998;
    for (s32 i = 0; i < 10; i++) {
        u8* p = D_0035f60c + i * 436;
        u8* b = p + 24;
        func_0028d980(p, id, D_0035f14c, D_0035f148, D_0035f210, 106, -1, -1, 0);
        s32 h = func_0023aa78(b);
        s32 x = func_0023aa18(b);
        s32 y = func_0023aa38(b);
        func_00139620(p);
        func_00138c68(p, 0, h * i);
        func_0028dcc0(p, g);
        *(u32*)(p + 420) = 0x60000008;
        *(s32*)(p + 428) = 3;
        func_00138c10(p, 2);
        func_0028d8c0(q, id + 1, D_0035f14c, D_0035f148, D_0035f210, 2, -1, 0);
        func_0028dcc0(q, p);
        func_00138c68(q, x, y);
        q += 408;
    }
}

// ---- f21.cpp
struct V4dcf90 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct V3dcf90 { f32 x, y, z; };
void func_002dcf90_i(u8* self) asm("_Z13func_002dcf90i");
void func_002dcf18(u8*);
s32 func_002dc7f8(u8*);
s32 func_00106a18(s32);
void func_00106de8(s32, s32, f32);
void func_00106c08(s32);
s32 func_00106a60(s32);
V4dcf90* func_0016c028(s32);
u8* func_002dc7c8(u8*);
f32 func_002dceb0(u8*);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_00107340_c(s32, f32, f32, f32) asm("_ZN2kn6Camera12setReferenceEfff");
void func_00107330_c(s32, f32, f32, f32) asm("_ZN2kn6Camera11setPositionEfff");
// Sets the view reference point and orbit position from the interpolated angle.
void func_002dcf90_i(u8* self) {
    V3dcf90 ref;
    V3dcf90 pos;
    func_002dcf18(self);
    if (self[0x8000 + 96]) return;
    if (!func_002dc7f8(self)) return;
    V4dcf90 v;
    V4dcf90* dst = &v;
    s32 m = func_00106a18(1);
    func_00106de8(m, 1, *(f32*)(self + 100));
    func_00106c08(m);
    s32 cam = func_00106a60(1);
    pos.z = 0.0f;
    V4dcf90* src = func_0016c028(func_002dc7f8(self));
    // 128-bit copy of the source position (lq/sq through t0).
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    ref.z = 0.0f;
    f32 y = v.y + 300.0f;
    ref.y = y - 80.0f;
    u8* p1 = func_002dc7c8(self);
    u8* p0 = func_002dc7c8(self);
    f32 t = func_002dceb0(self);
    f32 lo = *(f32*)(p0 + 168);
    f32 ang = (*(f32*)(p1 + 164) - lo) * t + lo;
    pos.y = y - func_002f8960(ang) * *(f32*)(self + 104);
    pos.z = -func_002f87c0(ang) * *(f32*)(self + 104);
    ref.x = pos.x = v.x * *(f32*)(self + 108);
    ref.y -= 300.0f;
    pos.y -= 300.0f;
    func_00107340_c(cam, ref.x, ref.y, ref.z);
    func_00107330_c(cam, pos.x, pos.y, pos.z);
}

}
