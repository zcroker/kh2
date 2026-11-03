#include "../common/types.h"
extern "C" {
typedef struct W1722LayFile W1722LayFile;
typedef struct W1722Sprite W1722Sprite;
typedef struct W1722SpriteMsg W1722SpriteMsg;
typedef struct W1722Lay W1722Lay;
typedef struct W1722Menu W1722Menu;

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

extern u8 D_00361de8[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern W1722Menu* D_00361dd8;

void func_0031a838(void*);
void func_002369a0(void*);
void func_0023c008(void*);
void func_00239700(void*);
s32 func_002beb90(void);
s32 func_001708f8(s32, s32);
void func_0023f800(W1722LayFile*);
void func_0023f848(W1722LayFile*);
void func_0023fa08(W1722LayFile*, s32);
s32 func_0023f948(W1722LayFile*, s32);
s32 func_0023f908(W1722LayFile*, s32);
s32 func_002c83a8(W1722Menu*, s32);
void func_0023eea0(W1722Lay*, s32, s32, s32, s32, s32);
void func_0023ef50(W1722Lay*);
void func_0023f0c8(W1722Lay*, s32);
void func_00139570(W1722Lay*);
void* func_0023f1b0(W1722Lay*);
s32 func_0023c4b8(void*, s32);
s32 func_00236ca8(s32, s32);
s32 func_00181500(s32);
s32 func_00105f80(s32);
s32 func_00192048(s32);
void func_00138d60(W1722Sprite*, s32, s32, s32, s32, s32, s32);
void func_00139620(W1722Sprite*);
s32 func_002c22b8(s32);
void func_002c8680(W1722Menu*, s32);
void func_001386e0(W1722Sprite*, s32, s32, s32, s32, s32);
u8* func_001c0c18(void);
s32 func_002c5238(s32, s32, s32*);
void func_001396b0(W1722Sprite*);
void func_0031a260(W1722Sprite*, s32);
void func_00139660(W1722Sprite*);
void func_00139688(W1722Sprite*);
void func_00138c68(W1722Sprite*, s32, s32);
s32 func_0023aa98(void*);
void func_0014cc40(s32*, s32*, s32*, s32*, s32);
void func_001391c8(W1722Menu*, s32, s32);

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

static inline void W1722Create(W1722Sprite* s, s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_001386e0(s, a, b, c, d, e);
}
static inline void W1722CreateMsg(W1722Sprite* s, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_00138d60(s, a, b, c, d, e, f);
}
#define W1722_SET_PARENT(s, p) do { \
    (s)->parent = (p); \
    func_001396b0(s); \
    if ((s)->parent != 0) { \
        (s)->m190 = 0; \
        func_001396b0(s); \
        if ((s)->m190 != 0) { \
            func_0031a260((s), 0); \
        } \
    } \
} while (0)

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

    self->m0c = 0;
    *(u32*)&self->vptr = (u32)D_00361de8;
    *(u32*)&self->lay.vptr = (u32)D_00347f98;
    self->m18 = 0;
    title = &self->title;
    func_0031a838(self->lay.m0c);
    self->lay.vptr = D_0035eb98;
    func_002369a0(self->lay.m18);
    func_0023c008(self->lay.m30);
    self->cache = func_001708f8(func_002beb90(), -1);
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
    func_0023eea0(&self->lay, 0x7581, gra, mes, func_002c83a8(self, 0), 0);
    func_0023ef50(&self->lay);
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
        func_002c8680(self, r);
    }
    func_001386e0(frame, 0x7585, self->unit, self->image, 0x48, 0xc9);
    frame->m188 = 0x49;
    func_001386e0(base, 0x7585, self->unit, self->image, 0x41, 0xc9);
    base->m188 = 0x42;

    func_002c5238(func_001c0c18()[kind], 2, digA);
    {
        s32 x = 0;
        s32 j;
        for (j = 0; j < 2; j++) {
            func_001386e0(&self->numA[j], 0x7585, self->unit, self->image, digA[j] + 0x12, 0xc9);
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
        func_001386e0(&self->numB[i], 0x7585, self->unit, self->image, digB[3 - n + i] + 0x1c, 0xc9);
        W1722SetParent(&self->numB[i], frame);
        func_00139660(&self->numB[i]);
        func_00139688(&self->numB[i]);
        func_00138c68(&self->numB[i], ofs, 0);
        func_001396b0(&self->numB[i]);
        ofs += func_0023aa98(self->numB[i].seq);
    }

    func_001386e0(sep, 0x7585, self->unit, self->image, 0x26, 0xc9);
    /* empty asm: self is opaque to GCSE, so self->sep.seq below is recomputed instead of reloaded */
    asm("" : "+r"(self));
    W1722SetParent(sep, frame);
    func_00139660(sep);
    func_00139688(sep);
    func_00138c68(sep, ofs, 0);
    func_001396b0(sep);
    ofs += func_0023aa98(self->sep.seq);

    func_002c5238(p1, 2, digA);
    for (s32 i = 0; i < 2; i++) {
        func_001386e0(&self->numC[i], 0x7585, self->unit, self->image, digA[i] + 0x1c, 0xc9);
        W1722SetParent(&self->numC[i], frame);
        func_00139660(&self->numC[i]);
        func_00139688(&self->numC[i]);
        func_00138c68(&self->numC[i], ofs, 0);
        func_001396b0(&self->numC[i]);
        ofs += func_0023aa98(self->numC[i].seq);
    }

    func_001391c8(self, 0x7582, 0xc9);
    func_0023f848(&lf);
}


}
