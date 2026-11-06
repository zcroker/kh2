// Built with -fno-strict-aliasing (_nsa rule).
// 002c90c8: world-map course menu constructor. Partial inline asm, no code emitted:
// asm("" : : "r"(row)) keeps the 2-D row pointer live a little longer (register order of the
// d[3][3] init loop), and asm("" : "+r"(t)) stops gcse reusing the early t+648 for title.seq.
// No register pins, no hand-written instructions.
#include "../common/types.h"
// Local layout-file handle (ctor/dtor in the game).
extern "C" {
void LayFile2c90c8_ctor(void*) asm("_ZN2Tz7LayFileC1Ev");
void LayFile2c90c8_dtor(void*) asm("_ZN2Tz7LayFileD1Ev");
}
struct LayFile2c90c8 {
    u8 pad[32];
    LayFile2c90c8() { LayFile2c90c8_ctor(this); }
    ~LayFile2c90c8() { LayFile2c90c8_dtor(this); }
};
extern "C" {
// 2D-object widget, 408 bytes; member at +24 is its sequence.
struct W2c90c8 {
    u32 vt; u8 pad0[8]; s32 f12; u8 pad1[8]; u8 seq[368];
    s32 f392; W2c90c8* parent; s32 f400; u8 pad2[4];
};
struct WP2c90c8 { W2c90c8 w; s32 f408; s32 f412; s32 f416; u8 pad[12]; s32 f432; };
struct Rec2c90c8 { u8 pad[27]; u8 icon; u8 pad1[2]; u8 flag; u8 pad2; f32 f32_; };
struct M2c90c8 {
    u32 vt; u8 pad0[8]; s32 f12; u8 pad1[8]; s32 f24;
    u8 lay[160];
    WP2c90c8 head;
    W2c90c8 title;
    W2c90c8 a[3];
    W2c90c8 b[3];
    W2c90c8 c[3];
    W2c90c8 d[3][3];
    W2c90c8 e[3];
    s32 img;
    s32 cache;
    s32 course;
    s32 mode;
};
extern u8 D_00361e10[], D_00347f98[], D_0035eb98[], D_00347e60[], D_00347e40[];
extern M2c90c8* D_00361e00;
extern u8 D_0033bc10[];
extern s16 D_003757d8[], D_003757e8[], D_003757f0[];
void func_0031a838(void*);
void func_002369a0(void*);
void func_0023c008(void*);
void func_00239700(void*);
s32 func_002beb90(void);
s32 func_001708f8(s32, s32);
void func_0023fa08(LayFile2c90c8*, s32);
s32 func_0023f948(LayFile2c90c8*, s32);
s32 func_0023f908(LayFile2c90c8*, s32);
s32 func_002c9e90(M2c90c8*, s32);
void func_0023eea0(void*, s32, s32, s32, s32, s32);
void func_0023ef50(void*);
void func_0023f0c8(void*, s32);
void func_00139570(void*);
u8* func_0023f1b0(void*);
s32 func_0023c4b8(u8*, s32);
s32 func_00236ca8(s32, s32);
Rec2c90c8* func_001e09a0(u8*, s32, s32, s32);
s32 func_002c1c88(s32);
void func_00138d60(WP2c90c8*, s32, s32, s32, s32, s32, s32);
void func_00139620(WP2c90c8*);
void func_001386e0(W2c90c8*, s32, s32, s32, s32, s32);
void func_001396b0(W2c90c8*);
void func_0031a260(W2c90c8*, s32);
void func_00139660(W2c90c8*);
void func_00139688(W2c90c8*);
void func_00138c68(W2c90c8*, s32, s32);
s32 func_0023aa18(void*);
s32 func_0023aa58(void*);
s32 func_0023aa78(void*);
s32 func_0023aa98(void*);
s32 func_002c5238(s32, s32, s32*);
void func_001391c8(M2c90c8*, s32, s32);

static inline void Attach2c90c8(W2c90c8* w, W2c90c8* parent)
{
    w->parent = parent;
    func_001396b0(w);
    if (w->parent) {
        w->f400 = 0;
        func_001396b0(w);
        if (w->f400) func_0031a260(w, 0);
    }
}

void func_002c90c8(M2c90c8* t, s32 course)
{
    t->f12 = 0;
    t->vt = (u32)D_00361e10;
    t->f24 = 0;
    *(u32*)t->lay = (u32)D_00347f98;
    WP2c90c8* head = &t->head;
    W2c90c8* title = &t->title;
    func_0031a838(t->lay + 12);
    *(u32*)t->lay = (u32)D_0035eb98;
    func_002369a0(t->lay + 24);
    func_0023c008(t->lay + 48);
    t->head.w.vt = (u32)D_00347f98;
    func_0031a838((u8*)&t->head + 12);
    t->head.w.vt = (u32)D_00347e60;
    func_00239700(t->head.w.seq);
    head->f408 = 0;
    t->title.f12 = 0;
    t->title.vt = (u32)D_00347e60;
    t->head.w.vt = (u32)D_00347e40;
    func_00239700(title->seq);
    W2c90c8* p;
    s32 i;
    { W2c90c8* q; s32 n; for (q = t->a, n = 2; n != -1; n--, q++) { q->f12 = 0; q->vt = (u32)D_00347e60; func_00239700(q->seq); } }
    { W2c90c8* q; s32 n; for (q = t->b, n = 2; n != -1; n--, q++) { q->f12 = 0; q->vt = (u32)D_00347e60; func_00239700(q->seq); } }
    { W2c90c8* q; s32 n; for (q = t->c, n = 2; n != -1; n--, q++) { q->f12 = 0; q->vt = (u32)D_00347e60; func_00239700(q->seq); } }
    W2c90c8 (*row)[3] = t->d;
    { for (s32 j = 2; j != -1; j--, row++) { W2c90c8* q; s32 n; for (q = *row, n = 2; n != -1; n--, q++) { q->f12 = 0; q->vt = (u32)D_00347e60; func_00239700(q->seq); } } }
    { W2c90c8* q; s32 n; for (q = t->e, n = 2; n != -1; n--, q++) { q->f12 = 0; q->vt = (u32)D_00347e60; func_00239700(q->seq); } }

    asm("" : : "r"(row));
    t->cache = func_001708f8(func_002beb90(), -1);
    t->course = course;
    s32 cm1 = course - 1;
    D_00361e00 = t;
    LayFile2c90c8 lf;
    func_0023fa08(&lf, t->cache);
    s32 gra = func_0023f948(&lf, 0);
    s32 mes = func_0023f908(&lf, 0);
    func_0023eea0(t->lay, 0x7581, gra, mes, func_002c9e90(t, 0), 0);
    func_0023ef50(t->lay);
    func_0023f0c8(t->lay, func_002c9e90(t, 2));
    func_00139570(t->lay);
    course = func_0023c4b8(func_0023f1b0(t->lay), 1);

    t->img = func_00236ca8(*(s32*)(func_0023f1b0(t->lay) + 40), 1);
    Rec2c90c8* rec[3];
    Rec2c90c8* rec2[3];
    for (s32 r = 0; r < 3; r++) rec[r] = func_001e09a0(D_0033bc10, cm1, r + 1, 0);
    for (s32 r = 0; r < 3; r++) rec2[r] = func_001e09a0(D_0033bc10, cm1, r + 1, 1);
    t->mode = 0;
    if (rec[0]->flag) t->mode = rec[2]->flag ? 2 : 1;
    func_00138d60(head, 0x7585, course, t->img, D_003757d8[t->mode], func_002c1c88(t->course), 201);
    head->f432 = 2;
    func_00139620(head);
    head->w.f392 = D_003757e8[t->mode];
    func_001386e0(title, 0x7586, course, t->img, t->mode ? 150 : 149, 201);
    Attach2c90c8(title, &head->w);
    asm("" : "+r"(t));
    func_00139660(title);
    func_00139688(title);
    func_00138c68(title, func_0023aa18(t->title.seq), 0);
    func_001396b0(title);
    s32 h = -func_0023aa58(t->title.seq);
    head->f416 = 0;
    head->f412 = h / 2;
    if (t->mode) {
        s32 n = 2;
        if (t->mode != 1) n = 3;
        s32 y = 0;
        for (s32 k = 0; k < n; k++) {
            func_001386e0(&t->a[k], 0x7587, course, t->img, D_003757f0[rec[k]->icon], 201);
            Attach2c90c8(&t->a[k], &head->w);
            func_00139660(&t->a[k]);
            func_00139688(&t->a[k]);
            func_00138c68(&t->a[k], 0, y);
            func_001396b0(&t->a[k]);
            if (rec2[k]->flag) {
                func_001386e0(&t->b[k], 0x7587, course, t->img, 120, 201);
                Attach2c90c8(&t->b[k], &head->w);
                func_00139660(&t->b[k]);
                func_00139688(&t->b[k]);
                func_00138c68(&t->b[k], 0, y);
                func_001396b0(&t->b[k]);
                func_001386e0(&t->c[k], 0x7587, course, t->img, D_003757f0[rec2[k]->icon], 201);
                Attach2c90c8(&t->c[k], &head->w);
                func_00138c68(&t->c[k], 90, y);
                func_00139660(&t->c[k]);
                func_00139688(&t->c[k]);
                func_001396b0(&t->c[k]);
            }
            s32 xs[3];
            s32 cnt = func_002c5238((s32)rec[k]->f32_, 3, xs);
            func_001386e0(&t->e[k], 0x7588, course, t->img, 144, 201);
            Attach2c90c8(&t->e[k], &head->w);
            func_00139660(&t->e[k]);
            func_00139688(&t->e[k]);
            func_00138c68(&t->e[k], 0, y);
            func_001396b0(&t->e[k]);
            s32 ex = func_0023aa98(t->e[k].seq);
            s32 x = -ex;
            if (cnt > 0) {
                W2c90c8* d = (W2c90c8*)(k * 1224 + (u32)t + 4704);
                s32* xp = &xs[2];
                for (s32 m = cnt; m != 0; m--) {
                    func_001386e0(d, 0x7588, course, t->img, *xp-- + 134, 201);
                    Attach2c90c8(d, &head->w);
                    func_00139660(d);
                    func_00139688(d);
                    func_00138c68(d, x, y);
                    x -= ex;
                    func_001396b0(d);
                    d++;
                }
            }
            y += func_0023aa78(t->a[k].seq);
        }
    }
    func_001391c8(t, 0x7582, 201);
}
}
