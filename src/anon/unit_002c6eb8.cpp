// Linked unit 0x2c6eb8-0x2c7e68: world map landing info window (dk::WM_LANDING_INFO), first part:
// two helpers and the C2/C1 ctor pair. The rest of the file is unit_002c7e68.cpp.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 002c6eb8 (from batch_w285.cpp)
namespace n002c6eb8 {
struct Vq285 {
    f32 x, y, z, w;
    Vq285& operator=(const Vq285& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq285 lerp285(const Vq285& a, const Vq285& b, f32 t) {
    Vq285 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct Loc285 { f32 a, b, c; s32 d; Vq285 v; };
struct Obj285 { Vq285 v0, v10, v20, v30, v40; s32 f50; f32 f54; };
void YS__TARGET__make_collision(void*, Loc285*) asm("YS__TARGET__make_collision");
Vq285* YS__OBJ__get_pos(s32) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
void func_001a7610(Vq285*, Vq285*, s32, f32, f32) asm("func_001a7610");
void func_0016bd60(s32, s32) asm("func_0016bd60");

void worldmap__Warp__start(Obj285* o, s32 id, void* p) asm("worldmap__Warp__start");
void worldmap__Warp__start(Obj285* o, s32 id, void* p) {
    Loc285 l;
    l.d = 0;
    YS__TARGET__make_collision(p, &l);
    o->v40 = l.v;
    o->v0 = *YS__OBJ__get_pos(id);  // obj_get_attach_or_alt
    o->v30 = l.v;
    o->v30.z -= l.b;
    func_001a7610(&o->v30, &o->v30, 0, 5000.0f, 1000.0f);
    o->v10 = lerp285(o->v0, o->v30, 0.1f);
    o->v10.y -= 1000.0f;
    o->v20 = lerp285(o->v0, o->v30, 0.9f);
    o->f50 = 0;
    o->v20.y -= 500.0f;
    o->f54 = 30.0f;
    func_0016bd60(id, 58);
}
}  // namespace n002c6eb8

// ---- 002c7060 (from batch_w1781_nsa.cpp)
namespace n002c7060 {
// FVector-style 16-byte vector; the subtraction is a VU0 macro sequence (asm only for lqc2/vsub/sqc2)
struct W1781Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void w1781_sub(W1781Vec* r, const W1781Vec* a, const W1781Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct W1781Obj {
    u8 pad[0x30];
    W1781Vec p30;
    W1781Vec p40;
    f32 time;
    f32 dur;
};
void w1781_set_pos(void* obj, const W1781Vec* v) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
extern f32 D_00349e10 asm("D_00349e10");
void func_0017d748(W1781Vec* out, W1781Obj* self, f32 t) asm("func_0017d748");


void worldmap__Warp__exec(W1781Obj* self, void* obj) asm("worldmap__Warp__exec");
void worldmap__Warp__exec(W1781Obj* self, void* obj) {
    W1781Vec v;
    f32 dur;
    self->time += D_00349e10;
    dur = self->dur;
    if (self->time < dur) {
        func_0017d748(&v, self, self->time / dur);
        w1781_set_pos(obj, &v);
    } else {
        w1781_set_pos(obj, &self->p30);
        w1781_sub(&v, &self->p40, &self->p30);
        self->dur = 0.0f;
    }
}
}  // namespace n002c7060

// ---- 002c7108: C2 copy of the ctor at 0x2c77b8 (never written before; same body)
namespace n002c7108 {
struct W1722LayFile { u8 pad[0x1c]; };
struct W1722Sprite {
    void* vptr;          /* 0x000 */
    u8 pad04[0x8];
    s32 m0c;             /* 0x00c */
    u8 pad10[0x8];
    u8 seq[0x170];       /* 0x018 */
    s32 m188;            /* 0x188 */
    W1722Sprite* parent; /* 0x18c */
    s32 m190;            /* 0x190 */
    u8 pad194[0x4];
};
struct W1722SpriteMsg {
    W1722Sprite s;
    s32 m198;            /* 0x198 */
    u8 pad19c[0x14];
    s32 m1b0;            /* 0x1b0 */
};
struct W1722Lay {
    void* vptr;          /* 0x00 */
    u8 pad04[0x8];
    u8 m0c[0xc];         /* 0x0c */
    u8 m18[0x18];        /* 0x18 */
    u8 m30[0x70];        /* 0x30 */
};
struct W1722Menu {
    void* vptr;              /* 0x000 */
    u8 pad04[0x8];
    s32 m0c;                 /* 0x00c */
    u8 pad10[0x8];
    s32 m18;                 /* 0x018 */
    W1722Lay lay;            /* 0x01c */
    s32 cache;               /* 0x0bc */
    s32 kind;                /* 0x0c0 */
    W1722SpriteMsg title;    /* 0x0c4 */
    W1722Sprite icons[3];    /* 0x278 */
    W1722Sprite frame;       /* 0x740 */
    W1722Sprite base;        /* 0x8d8 */
    W1722Sprite numA[2];     /* 0xa70 */
    W1722Sprite numB[3];     /* 0xda0 */
    W1722Sprite sep;         /* 0x1268 */
    W1722Sprite numC[2];     /* 0x1400 */
    s32 image;               /* 0x1730 */
    s32 unit;                /* 0x1734 */
};
extern u8 D_00361de8[] asm("D_00361de8");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern W1722Menu* D_00361dd8 asm("D_00361dd8");
void func_0031a838(void*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(void*) asm("YI__LAYOUT__LAYOUT");
void func_00239700(void*) asm("func_00239700");
s32 worldmap__Manager__get2ldFile(void) asm("worldmap__Manager__get2ldFile");
s32 func_001708f8(s32, s32) asm("func_001708f8");
void func_0023f800(W1722LayFile*) asm("func_0023f800");
void func_0023f848(W1722LayFile*) asm("func_0023f848");
void func_0023fa08(W1722LayFile*, s32) asm("func_0023fa08");
s32 func_0023f948(W1722LayFile*, s32) asm("func_0023f948");
s32 func_0023f908(W1722LayFile*, s32) asm("func_0023f908");
s32 func_002c83a8(W1722Menu*, s32) asm("func_002c83a8");
void Tz__Layout__create(W1722Lay*, s32, s32, s32, s32, s32) asm("Tz__Layout__create");
void Tz__Layout__SetImageCache(W1722Lay*) asm("Tz__Layout__SetImageCache");
void func_0023f0c8(W1722Lay*, s32) asm("func_0023f0c8");
void func_00139570(W1722Lay*) asm("func_00139570");
void* func_0023f1b0(W1722Lay*) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_00181500(s32) asm("func_00181500");
s32 func_00105f80(s32) asm("func_00105f80");
s32 func_00192048(s32) asm("func_00192048");
void func_00138d60(W1722Sprite*, s32, s32, s32, s32, s32, s32) asm("func_00138d60");
void func_00139620(W1722Sprite*) asm("func_00139620");
s32 func_002c22b8(s32) asm("func_002c22b8");
void dk__WM_LANDING_INFO__setupKey(W1722Menu*, s32) asm("dk__WM_LANDING_INFO__setupKey");
void dk__Sprite__create(W1722Sprite*, s32, s32, s32, s32, s32) asm("dk__Sprite__create");
u8* func_001c0c18(void) asm("func_001c0c18");
s32 func_002c5238(s32, s32, s32*) asm("func_002c5238");
void func_001396b0(W1722Sprite*) asm("func_001396b0");
void func_0031a260(W1722Sprite*, s32) asm("func_0031a260");
void func_00139660(W1722Sprite*) asm("func_00139660");
void func_00139688(W1722Sprite*) asm("func_00139688");
void func_00138c68(W1722Sprite*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_0014cc40(s32*, s32*, s32*, s32*, s32) asm("func_0014cc40");
void func_001391c8(W1722Menu*, s32, s32) asm("func_001391c8");
static inline void W1722InitSprite(W1722Sprite* s) {
    s->m0c = 0;
    s->vptr = D_00347e60;
    func_00239700(s->seq);
}
#define W1722_INIT(o) ((o).m0c = 0, (o).vptr = D_00347e60, func_00239700((o).seq))
static inline void W1722InitArray(W1722Sprite* s, s32 n) {
    do {
        W1722InitSprite(s);
        n--;
        s++;
    } while (n != -1);
}
static inline void W1722CreateMsg(W1722Sprite* s, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_00138d60(s, a, b, c, d, e, f);
}
static inline void W1722SetParent(W1722Sprite* s, W1722Sprite* p) {
    s->parent = p;
    func_001396b0(s);
    if (s->parent != 0) {
        s->m190 = 0;
        func_001396b0(s);
        if (s->m190 != 0) {
            func_0031a260(s, 0);
        }
    }
}


void func_002c7108(W1722Menu* self, s32 kind) asm("func_002c7108");
void func_002c7108(W1722Menu* self, s32 kind) {
    W1722LayFile lf;
    s32 digA[4];
    s32 digB[4];
    s32 p0, p1, p2, p3;
    s32 n;
    s32 ofs;
    s32 gra, mes, msg, r;
    W1722SpriteMsg* title;
    W1722Sprite* frame;
    W1722Sprite* base;
    W1722Sprite* sep;
    W1722Menu* m;

    self->m0c = 0;
    *(u32*)&self->vptr = (u32)D_00361de8;
    *(u32*)&self->lay.vptr = (u32)D_00347f98;
    self->m18 = 0;
    title = &self->title;
    func_0031a838(self->lay.m0c);
    self->lay.vptr = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(self->lay.m18);
    YI__LAYOUT__LAYOUT(self->lay.m30);
    self->cache = func_001708f8(worldmap__Manager__get2ldFile(), -1);
    title->s.vptr = D_00347f98;
    self->kind = kind;
    func_0031a838(&title->s.m0c);
    title->s.vptr = D_00347e60;
    func_00239700(title->s.seq);
    title->m198 = 0;
    title->s.vptr = D_00347e40;
    W1722InitArray(self->icons, 2);
    W1722_INIT(self->frame);
    frame = &self->frame;
    W1722_INIT(self->base);
    base = &self->base;
    W1722InitArray(self->numA, 1);
    W1722InitArray(self->numB, 2);
    W1722_INIT(self->sep);
    sep = &self->sep;
    W1722InitArray(self->numC, 1);

    D_00361dd8 = self;
    func_0023f800(&lf);
    func_0023fa08(&lf, self->cache);
    gra = func_0023f948(&lf, 0);
    mes = func_0023f908(&lf, 0);
    Tz__Layout__create(&self->lay, 0x7581, gra, mes, func_002c83a8(self, 0), 0);
    Tz__Layout__SetImageCache(&self->lay);
    func_0023f0c8(&self->lay, func_002c83a8(self, 2));
    func_00139570(&self->lay);
    self->unit = func_0023c4b8(func_0023f1b0(&self->lay), 1);
    self->image = func_00236ca8(*(s32*)((u8*)func_0023f1b0(&self->lay) + 0x28), 1);
    if (kind == 4 && func_00181500(0x1077) != 0) {
        msg = 0x8ae9;
    } else {
        msg = func_00105f80(kind);
    }
    msg = func_00192048(msg);
    W1722CreateMsg(&title->s, 0x7585, self->unit, self->image, 0x98, msg, 0xc9);
    title->m1b0 = 2;
    func_00139620(&title->s);
    title->s.m188 = 0x99;
    r = func_002c22b8(kind);
    if (r != 0) {
        dk__WM_LANDING_INFO__setupKey(self, r);
    }
    dk__Sprite__create(frame, 0x7585, self->unit, self->image, 0x48, 0xc9);
    frame->m188 = 0x49;
    dk__Sprite__create(base, 0x7585, self->unit, self->image, 0x41, 0xc9);
    base->m188 = 0x42;

    func_002c5238(func_001c0c18()[kind], 2, digA);
    {
        s32 x = 0;
        s32 j;
        for (j = 0; j < 2; j++) {
            dk__Sprite__create(&self->numA[j], 0x7585, self->unit, self->image, digA[j] + 0x12, 0xc9);
            W1722SetParent(&self->numA[j], base);
            func_00139660(&self->numA[j]);
            func_00139688(&self->numA[j]);
            func_00138c68(&self->numA[j], x, 0);
            func_001396b0(&self->numA[j]);
            x += func_0023aa98(self->numA[j].seq);
        }
    }

    func_0014cc40(&p0, &p1, &p2, &p3, kind);
    ofs = 0;
    n = func_002c5238(p0, 3, digB);
    for (s32 i = 0; i < n; i++) {
        dk__Sprite__create(&self->numB[i], 0x7585, self->unit, self->image, digB[3 - n + i] + 0x1c, 0xc9);
        W1722SetParent(&self->numB[i], frame);
        func_00139660(&self->numB[i]);
        func_00139688(&self->numB[i]);
        func_00138c68(&self->numB[i], ofs, 0);
        func_001396b0(&self->numB[i]);
        ofs += func_0023aa98(self->numB[i].seq);
    }

    dk__Sprite__create(sep, 0x7585, self->unit, self->image, 0x26, 0xc9);
    W1722SetParent(sep, frame);
    func_00139660(sep);
    func_00139688(sep);
    func_00138c68(sep, ofs, 0);
    func_001396b0(sep);
    m = self;
    ofs += func_0023aa98(m->sep.seq);

    func_002c5238(p1, 2, digA);
    for (s32 i = 0; i < 2; i++) {
        dk__Sprite__create(&m->numC[i], 0x7585, m->unit, m->image, digA[i] + 0x1c, 0xc9);
        W1722SetParent(&m->numC[i], frame);
        func_00139660(&m->numC[i]);
        func_00139688(&m->numC[i]);
        func_00138c68(&m->numC[i], ofs, 0);
        func_001396b0(&m->numC[i]);
        ofs += func_0023aa98(m->numC[i].seq);
    }

    func_001391c8(m, 0x7582, 0xc9);
    func_0023f848(&lf);
}
#undef W1722_INIT
}  // namespace n002c7108
// ---- 002c77b8 (from batch_w3686_nsa.cpp)
namespace n002c77b8 {
struct W1722LayFile { u8 pad[0x1c]; };
struct W1722Sprite {
    void* vptr;          /* 0x000 */
    u8 pad04[0x8];
    s32 m0c;             /* 0x00c */
    u8 pad10[0x8];
    u8 seq[0x170];       /* 0x018 */
    s32 m188;            /* 0x188 */
    W1722Sprite* parent; /* 0x18c */
    s32 m190;            /* 0x190 */
    u8 pad194[0x4];
};
struct W1722SpriteMsg {
    W1722Sprite s;
    s32 m198;            /* 0x198 */
    u8 pad19c[0x14];
    s32 m1b0;            /* 0x1b0 */
};
struct W1722Lay {
    void* vptr;          /* 0x00 */
    u8 pad04[0x8];
    u8 m0c[0xc];         /* 0x0c */
    u8 m18[0x18];        /* 0x18 */
    u8 m30[0x70];        /* 0x30 */
};
struct W1722Menu {
    void* vptr;              /* 0x000 */
    u8 pad04[0x8];
    s32 m0c;                 /* 0x00c */
    u8 pad10[0x8];
    s32 m18;                 /* 0x018 */
    W1722Lay lay;            /* 0x01c */
    s32 cache;               /* 0x0bc */
    s32 kind;                /* 0x0c0 */
    W1722SpriteMsg title;    /* 0x0c4 */
    W1722Sprite icons[3];    /* 0x278 */
    W1722Sprite frame;       /* 0x740 */
    W1722Sprite base;        /* 0x8d8 */
    W1722Sprite numA[2];     /* 0xa70 */
    W1722Sprite numB[3];     /* 0xda0 */
    W1722Sprite sep;         /* 0x1268 */
    W1722Sprite numC[2];     /* 0x1400 */
    s32 image;               /* 0x1730 */
    s32 unit;                /* 0x1734 */
};
extern u8 D_00361de8[] asm("D_00361de8");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern W1722Menu* D_00361dd8 asm("D_00361dd8");
void func_0031a838(void*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(void*) asm("YI__LAYOUT__LAYOUT");
void func_00239700(void*) asm("func_00239700");
s32 worldmap__Manager__get2ldFile(void) asm("worldmap__Manager__get2ldFile");
s32 func_001708f8(s32, s32) asm("func_001708f8");
void func_0023f800(W1722LayFile*) asm("func_0023f800");
void func_0023f848(W1722LayFile*) asm("func_0023f848");
void func_0023fa08(W1722LayFile*, s32) asm("func_0023fa08");
s32 func_0023f948(W1722LayFile*, s32) asm("func_0023f948");
s32 func_0023f908(W1722LayFile*, s32) asm("func_0023f908");
s32 func_002c83a8(W1722Menu*, s32) asm("func_002c83a8");
void Tz__Layout__create(W1722Lay*, s32, s32, s32, s32, s32) asm("Tz__Layout__create");
void Tz__Layout__SetImageCache(W1722Lay*) asm("Tz__Layout__SetImageCache");
void func_0023f0c8(W1722Lay*, s32) asm("func_0023f0c8");
void func_00139570(W1722Lay*) asm("func_00139570");
void* func_0023f1b0(W1722Lay*) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_00181500(s32) asm("func_00181500");
s32 func_00105f80(s32) asm("func_00105f80");
s32 func_00192048(s32) asm("func_00192048");
void func_00138d60(W1722Sprite*, s32, s32, s32, s32, s32, s32) asm("func_00138d60");
void func_00139620(W1722Sprite*) asm("func_00139620");
s32 func_002c22b8(s32) asm("func_002c22b8");
void dk__WM_LANDING_INFO__setupKey(W1722Menu*, s32) asm("dk__WM_LANDING_INFO__setupKey");
void dk__Sprite__create(W1722Sprite*, s32, s32, s32, s32, s32) asm("dk__Sprite__create");
u8* func_001c0c18(void) asm("func_001c0c18");
s32 func_002c5238(s32, s32, s32*) asm("func_002c5238");
void func_001396b0(W1722Sprite*) asm("func_001396b0");
void func_0031a260(W1722Sprite*, s32) asm("func_0031a260");
void func_00139660(W1722Sprite*) asm("func_00139660");
void func_00139688(W1722Sprite*) asm("func_00139688");
void func_00138c68(W1722Sprite*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_0014cc40(s32*, s32*, s32*, s32*, s32) asm("func_0014cc40");
void func_001391c8(W1722Menu*, s32, s32) asm("func_001391c8");
static inline void W1722InitSprite(W1722Sprite* s) {
    s->m0c = 0;
    s->vptr = D_00347e60;
    func_00239700(s->seq);
}
#define W1722_INIT(o) ((o).m0c = 0, (o).vptr = D_00347e60, func_00239700((o).seq))
static inline void W1722InitArray(W1722Sprite* s, s32 n) {
    do {
        W1722InitSprite(s);
        n--;
        s++;
    } while (n != -1);
}
static inline void W1722CreateMsg(W1722Sprite* s, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_00138d60(s, a, b, c, d, e, f);
}
static inline void W1722SetParent(W1722Sprite* s, W1722Sprite* p) {
    s->parent = p;
    func_001396b0(s);
    if (s->parent != 0) {
        s->m190 = 0;
        func_001396b0(s);
        if (s->m190 != 0) {
            func_0031a260(s, 0);
        }
    }
}


void func_002c77b8(W1722Menu* self, s32 kind) asm("func_002c77b8");
void func_002c77b8(W1722Menu* self, s32 kind) {
    W1722LayFile lf;
    s32 digA[4];
    s32 digB[4];
    s32 p0, p1, p2, p3;
    s32 n;
    s32 ofs;
    s32 gra, mes, msg, r;
    W1722SpriteMsg* title;
    W1722Sprite* frame;
    W1722Sprite* base;
    W1722Sprite* sep;
    W1722Menu* m;

    self->m0c = 0;
    *(u32*)&self->vptr = (u32)D_00361de8;
    *(u32*)&self->lay.vptr = (u32)D_00347f98;
    self->m18 = 0;
    title = &self->title;
    func_0031a838(self->lay.m0c);
    self->lay.vptr = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(self->lay.m18);
    YI__LAYOUT__LAYOUT(self->lay.m30);
    self->cache = func_001708f8(worldmap__Manager__get2ldFile(), -1);
    title->s.vptr = D_00347f98;
    self->kind = kind;
    func_0031a838(&title->s.m0c);
    title->s.vptr = D_00347e60;
    func_00239700(title->s.seq);
    title->m198 = 0;
    title->s.vptr = D_00347e40;
    W1722InitArray(self->icons, 2);
    W1722_INIT(self->frame);
    frame = &self->frame;
    W1722_INIT(self->base);
    base = &self->base;
    W1722InitArray(self->numA, 1);
    W1722InitArray(self->numB, 2);
    W1722_INIT(self->sep);
    sep = &self->sep;
    W1722InitArray(self->numC, 1);

    D_00361dd8 = self;
    func_0023f800(&lf);
    func_0023fa08(&lf, self->cache);
    gra = func_0023f948(&lf, 0);
    mes = func_0023f908(&lf, 0);
    Tz__Layout__create(&self->lay, 0x7581, gra, mes, func_002c83a8(self, 0), 0);
    Tz__Layout__SetImageCache(&self->lay);
    func_0023f0c8(&self->lay, func_002c83a8(self, 2));
    func_00139570(&self->lay);
    self->unit = func_0023c4b8(func_0023f1b0(&self->lay), 1);
    self->image = func_00236ca8(*(s32*)((u8*)func_0023f1b0(&self->lay) + 0x28), 1);
    if (kind == 4 && func_00181500(0x1077) != 0) {
        msg = 0x8ae9;
    } else {
        msg = func_00105f80(kind);
    }
    msg = func_00192048(msg);
    W1722CreateMsg(&title->s, 0x7585, self->unit, self->image, 0x98, msg, 0xc9);
    title->m1b0 = 2;
    func_00139620(&title->s);
    title->s.m188 = 0x99;
    r = func_002c22b8(kind);
    if (r != 0) {
        dk__WM_LANDING_INFO__setupKey(self, r);
    }
    dk__Sprite__create(frame, 0x7585, self->unit, self->image, 0x48, 0xc9);
    frame->m188 = 0x49;
    dk__Sprite__create(base, 0x7585, self->unit, self->image, 0x41, 0xc9);
    base->m188 = 0x42;

    func_002c5238(func_001c0c18()[kind], 2, digA);
    {
        s32 x = 0;
        s32 j;
        for (j = 0; j < 2; j++) {
            dk__Sprite__create(&self->numA[j], 0x7585, self->unit, self->image, digA[j] + 0x12, 0xc9);
            W1722SetParent(&self->numA[j], base);
            func_00139660(&self->numA[j]);
            func_00139688(&self->numA[j]);
            func_00138c68(&self->numA[j], x, 0);
            func_001396b0(&self->numA[j]);
            x += func_0023aa98(self->numA[j].seq);
        }
    }

    func_0014cc40(&p0, &p1, &p2, &p3, kind);
    ofs = 0;
    n = func_002c5238(p0, 3, digB);
    for (s32 i = 0; i < n; i++) {
        dk__Sprite__create(&self->numB[i], 0x7585, self->unit, self->image, digB[3 - n + i] + 0x1c, 0xc9);
        W1722SetParent(&self->numB[i], frame);
        func_00139660(&self->numB[i]);
        func_00139688(&self->numB[i]);
        func_00138c68(&self->numB[i], ofs, 0);
        func_001396b0(&self->numB[i]);
        ofs += func_0023aa98(self->numB[i].seq);
    }

    dk__Sprite__create(sep, 0x7585, self->unit, self->image, 0x26, 0xc9);
    W1722SetParent(sep, frame);
    func_00139660(sep);
    func_00139688(sep);
    func_00138c68(sep, ofs, 0);
    func_001396b0(sep);
    m = self;
    ofs += func_0023aa98(m->sep.seq);

    func_002c5238(p1, 2, digA);
    for (s32 i = 0; i < 2; i++) {
        dk__Sprite__create(&m->numC[i], 0x7585, m->unit, m->image, digA[i] + 0x1c, 0xc9);
        W1722SetParent(&m->numC[i], frame);
        func_00139660(&m->numC[i]);
        func_00139688(&m->numC[i]);
        func_00138c68(&m->numC[i], ofs, 0);
        func_001396b0(&m->numC[i]);
        ofs += func_0023aa98(m->numC[i].seq);
    }

    func_001391c8(m, 0x7582, 0xc9);
    func_0023f848(&lf);
}
#undef W1722_INIT
}  // namespace n002c77b8

