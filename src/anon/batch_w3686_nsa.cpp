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
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*);
void YI__LAYOUT__LAYOUT(void*);
void func_00239700(void*);
s32 worldmap__Manager__get2ldFile(void);
s32 func_001708f8(s32, s32);
void func_0023f800(W1722LayFile*);
void func_0023f848(W1722LayFile*);
void func_0023fa08(W1722LayFile*, s32);
s32 func_0023f948(W1722LayFile*, s32);
s32 func_0023f908(W1722LayFile*, s32);
s32 func_002c83a8(W1722Menu*, s32);
void Tz__Layout__create(W1722Lay*, s32, s32, s32, s32, s32);
void Tz__Layout__SetImageCache(W1722Lay*);
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
void dk__WM_LANDING_INFO__setupKey(W1722Menu*, s32);
void dk__Sprite__create(W1722Sprite*, s32, s32, s32, s32, s32);
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
    dk__Sprite__create(s, a, b, c, d, e);
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

void func_002c77b8(W1722Menu* self, s32 kind);  // 0x2c77b8: moved to src/anon/unit_002c6eb8.cpp



}
