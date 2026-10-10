#include "../common/types.h"
namespace w320_b {
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QWord& operator=(const QWord& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline QWord Cross(QWord& a, QWord& b) {
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot(QWord& a, QWord& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Sub2884 { u32 f0; u32 f4; u32 f8; };
struct Cfg { u8 pad[172]; f32 f172; u8 pad176[12]; f32 f188; };
struct Ob {
    u8 p0[16]; QWord q16; QWord q32; u8 p48[268 - 48]; u32 flags; u8 p272[320 - 272];
    u8 sub[32]; u32 f352; u8 p356[380 - 356]; s32 f380; s32 f384; u8 p388[2884 - 388]; Sub2884* p2884;
};
}
using namespace w320_b;
extern Cfg* D_00352130;
extern "C" {
s32 func_001c90f0(void);  // id_in_201_204
void func_001c9110(void*, Ob*);
void func_0017f540(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_0016bd60(Ob*, s32);
void func_001c92a0(void* x, Ob* o)
{
    QWord v;
    v = o->q32;
    Normalize(&v);
    QWord c;
    c = Cross(v, o->q16);
    u32 fl = o->flags;
    if (fl & 0x10) {
        f32 d = Dot(v, o->q16);
        if (func_001c90f0() && !(o->p2884->f8 & 4)) {  // id_in_201_204
            o->flags &= ~0x10;
            func_0017f540(o->sub, 202, 0.0f, 0.0f);
            if (c.f[1] <= 0.0f) func_0017f5e0(o->sub, 203, 0, 0.0f, 0.0f);
            else func_0017f5e0(o->sub, 204, 0, 0.0f, 0.0f);
            return;
        }
        if (!(o->flags & 0x20)) {
            void* s = o->sub;
            if (o->f352 & 4) {
                if (D_00352130->f188 < d) {
                    func_0017f540(s, 201, 8.0f, 0.0f);
                } else {
                    f32 z = 0.0f; s32 id = 203; if (!(c.f[1] <= z)) id = 204; func_0017f540(s, id, 12.0f, z);
                }
                return;
            }
        }
    } else if ((fl & 0x20) && o->f384 == o->f380) {
        u32 t = o->f352;
        if (t & 0x10) goto call;
        if (t & 4) {
        call:
            func_0016bd60(o, 0);
            return;
        }
    }
    func_001c9110(x, o);
}
}
namespace w320_c {
struct V4r { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4r { V4r r[4]; };
struct Model {
    u8 pad0[124];
    f32 scale;
    f32 off[3];
    u8 pad140[3];
    u8 noOffset;
    u8 pad144[20];
    f32 size;
};
struct DrawSrc { Model* model; u32 tex; u8 data[1]; };
struct DrawArg { DrawSrc* src; u32 color; void* mtx; f32 len; u16 div; u8 mx; u8 my; f32* scl; };
struct DrawReq {
    u32 tex;
    u32 data;
    u8 pad8[10];
    u16 id;
    union { u32 color; u8 c[4]; };
    u32 f24;
    u16 f28;
    u16 f30;
    M4r* mtx;
    u8 pad36[8];
    u32 f44;
    u8 pad48[16];
};
struct CamBlk { u8 pad[48]; f32 pos[3]; };
}
using namespace w320_c;
extern "C" {
extern Model D_01d9e360;
extern CamBlk D_01d9e840;
void func_002f3f98(M4r*, Model*);
void func_002f4000(M4r*);  // vu_store_w_splat
void func_002f3f40(V4r*, V4r*, f32);  // vec_scale_by_f12
void func_002f3d08(M4r*, void*, M4r*);
void func_0021efc0(DrawReq*);
void func_0021f060(DrawReq*);
void func_0021fe40(DrawArg* a, u32 id) {
    M4r m;
    DrawReq req;
    DrawSrc* src = a->src;
    Model* md = src->model;
    if (md == &D_01d9e360) return;
    if (!src->tex) return;
    if (md->scale == 0.0f) return;
    f32 lim = 0.0f;
    f32 k = md->size / (f32)a->div;
    if (!(1.0f < k)) lim = 1.0f - k;
    if (md->noOffset) {
        func_002f3f98(&m, md);
    } else {
        func_002f4000(&m);  // vu_store_w_splat
        m.r[3].x = D_01d9e840.pos[0] + md->off[0];
        m.r[3].y = D_01d9e840.pos[1] + md->off[1];
        m.r[3].z = D_01d9e840.pos[2] + md->off[2];
    }
    f32 s = a->len;
    m.r[0].x = s;
    switch (a->mx) {
    case 1: m.r[0].x = s * lim; break;
    case 2: m.r[0].x = s * (k + 1.0f); break;
    }
    m.r[1].y = s;
    switch (a->my) {
    case 1: m.r[1].y = s * lim; break;
    case 2: m.r[1].y = s * (k + 1.0f); break;
    }
    func_002f3f40(&m.r[0], &m.r[0], a->scl[0]);  // vec_scale_by_f12
    func_002f3f40(&m.r[1], &m.r[1], a->scl[1]);  // vec_scale_by_f12
    func_002f3d08(&m, a->mtx, &m);
    req.color = a->color;
    req.c[3] = (s32)(req.c[3] * md->scale * lim);
    req.tex = src->tex;
    req.data = (u32)src->data;
    func_0021efc0(&req);
    req.id = id;
    req.mtx = &m;
    req.f44 = 0;
    req.f24 = 0;
    req.f28 = 0;
    req.f30 = 0;
    func_0021f060(&req);
}
}
extern "C" {
extern u16* D_0035f230;
extern u32 D_0035f01c;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
u16* func_0026b850(void);
s32 func_002813b8(void);
s32 func_00257118(s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s32, s32);
void func_00288e08(u32, s32, s32, s32);
u8* func_002891b8(u32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
s32 func_00192048(u32);
s32 func_0027aa78(void);
s32 func_00277708v0(s32 start)
{
    s32 j = start;
    u16* t0 = func_0026b850();
    s32 mask = func_002813b8();
    *D_0035f230 = mask;
    s32 n = 0;
    u16* tbl = t0;
    for (s32 i = 0; i < 7; i++, tbl++) {
        if (i == 6) continue;
        u8 on = (mask >> i) & 1;
        if (!on) continue;
        n++;
        s32 a = func_00257118(0);
        s32 b = func_00257118(1);
        func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
        func_00288e08(D_0035f01c, j, 0, -1);
        func_00139620(func_002891b8(D_0035f01c, j));
        u8* nd = func_002891b8(D_0035f01c, j);
        *(s32*)(nd + 408) = func_00192048(*tbl);
        func_001395f8(func_002891b8(D_0035f01c, j++));
    }
    if (!func_0027aa78()) return n;
    n++;
    s32 a = func_00257118(0);
    s32 b = func_00257118(1);
    func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    func_00288e08(D_0035f01c, j, 0, -1);
    func_00139620(func_002891b8(D_0035f01c, j));
    u8* nd = func_002891b8(D_0035f01c, j);
    *(s32*)(nd + 408) = func_00192048(0xb2ec);
    func_001395f8(func_002891b8(D_0035f01c, j));
    *D_0035f230 |= 0x80;
    return n;
}

s32 func_00277708v1(s32 start)
{
    s32 j = start;
    u16* t0 = func_0026b850();
    s32 mask = func_002813b8();
    *D_0035f230 = mask;
    s32 n = 0;
    u16* tbl = t0;
    for (s32 i = 0; i < 7; i++, tbl++) {
        if (i == 6) continue;
        bool off = !((mask >> i) & 1);
        if (off) continue;
        n++;
        s32 a = func_00257118(0);
        s32 b = func_00257118(1);
        func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
        func_00288e08(D_0035f01c, j, 0, -1);
        func_00139620(func_002891b8(D_0035f01c, j));
        u8* nd = func_002891b8(D_0035f01c, j);
        *(s32*)(nd + 408) = func_00192048(*tbl);
        func_001395f8(func_002891b8(D_0035f01c, j++));
    }
    if (!func_0027aa78()) return n;
    n++;
    s32 a = func_00257118(0);
    s32 b = func_00257118(1);
    func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    func_00288e08(D_0035f01c, j, 0, -1);
    func_00139620(func_002891b8(D_0035f01c, j));
    u8* nd = func_002891b8(D_0035f01c, j);
    *(s32*)(nd + 408) = func_00192048(0xb2ec);
    func_001395f8(func_002891b8(D_0035f01c, j));
    *D_0035f230 |= 0x80;
    return n;
}

s32 func_00277708w0(s32 start)
{
    s32 j = start;
    u16* t0 = func_0026b850();
    s32 mask = func_002813b8();
    *D_0035f230 = mask;
    s32 n = 0;
    u16* tbl = t0;
    for (s32 i = 0; i < 7; i++, tbl++) {
        if (i == 6) continue;
        u8 off = ~(mask >> i) & 1;
        if (off) continue;
        n++;
        s32 a = func_00257118(0);
        s32 b = func_00257118(1);
        func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
        func_00288e08(D_0035f01c, j, 0, -1);
        func_00139620(func_002891b8(D_0035f01c, j));
        u8* nd = func_002891b8(D_0035f01c, j);
        *(s32*)(nd + 408) = func_00192048(*tbl);
        func_001395f8(func_002891b8(D_0035f01c, j++));
    }
    if (!func_0027aa78()) return n;
    n++;
    s32 a = func_00257118(0);
    s32 b = func_00257118(1);
    func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    func_00288e08(D_0035f01c, j, 0, -1);
    func_00139620(func_002891b8(D_0035f01c, j));
    u8* nd = func_002891b8(D_0035f01c, j);
    *(s32*)(nd + 408) = func_00192048(0xb2ec);
    func_001395f8(func_002891b8(D_0035f01c, j));
    *D_0035f230 |= 0x80;
    return n;
}


s32 func_00277708(s32 start)
{
    u16* t0 = func_0026b850();
    s32 mask = func_002813b8();
    *D_0035f230 = mask;
    s32 n = 0;
    s32 j = start;
    u16* tbl = t0;
    for (s32 i = 0; i < 7; i++, tbl++) {
        if (i == 6) continue;
        u8 off = ((mask >> i) ^ 1) & 1;
        if (off) continue;
        n++;
        s32 a = func_00257118(0);
        s32 b = func_00257118(1);
        func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
        func_00288e08(D_0035f01c, j, 0, -1);
        func_00139620(func_002891b8(D_0035f01c, j));
        u8* nd = func_002891b8(D_0035f01c, j);
        *(s32*)(nd + 408) = func_00192048(*tbl);
        func_001395f8(func_002891b8(D_0035f01c, j++));
    }
    if (!func_0027aa78()) return n;
    n++;
    s32 a = func_00257118(0);
    s32 b = func_00257118(1);
    func_00288d80(D_0035f01c, j, D_0035ef68, D_0035ef64, D_0035f03c, -1, a, b);
    func_00288e08(D_0035f01c, j, 0, -1);
    func_00139620(func_002891b8(D_0035f01c, j));
    u8* nd = func_002891b8(D_0035f01c, j);
    *(s32*)(nd + 408) = func_00192048(0xb2ec);
    func_001395f8(func_002891b8(D_0035f01c, j));
    *D_0035f230 |= 0x80;
    return n;
}



}
struct E1e21ef0 { s32 f0; s16 h4; };
extern "C" {
extern u32 D_0035f01c;
extern s32 D_0035f3d4;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u8* D_0035f050;
extern E1e21ef0* D_01e21ef0;
u8* func_00257770(void);
s32 func_00287cd0(void);
s32 func_0028acc8(u32);
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_002891e8(u32);
s32 func_0028b038(u32);
E1e21ef0* func_0027d4f0(s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
s32 func_0027d488(s32, s32);
void func_0028dcc0(u8*, s32);
s32 func_00289358(u32);
void func_00138c10(u8*, s32);
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
u8* func_002891d0(u32);
void func_0028d660(u8*, s32);  // record_set_value_refresh
void func_0027d5d8(void)
{
    u8* base = func_00257770();
    s32 mode = func_00287cd0();
    if (!func_0028acc8(D_0035f01c)) return;
    if (mode == 1) {
        u8* w = base + 816;
        s32 a = func_002891e8(D_0035f01c);
        s32 b = func_0028b038(D_0035f01c);
        D_01e21ef0 = func_0027d4f0(a + b);
        if (!func_00139d78(w)) {
            func_0028d8c0(w, D_0035f3d4 + 1, D_0035ef68, D_0035ef64, D_0035f03c, D_01e21ef0->h4, -1, 0);
            func_0028dcc0(w, func_0027d488(a, b));
            return;
        }
        s32 cur = *(s32*)(w + 396);
        if (cur == func_0027d488(a, b) && !func_00289358(D_0035f01c)) return;
        func_00138c10(w, D_01e21ef0->h4);
        *(s32*)(w + 396) = func_0027d488(a, b);
        func_001396b0(w);
        if (*(s32*)(w + 396)) {
            *(s32*)(w + 400) = 0;
            func_001396b0(w);
            if (*(s32*)(w + 400)) func_0031a260(w, 0);
        }
        if (!func_00139d78(D_0035f050)) return;
        s32 v = *(s32*)(D_0035f050 + 396);
        if (v == *(s32*)(func_002891d0(D_0035f01c) + 396)) return;
        func_0028d660(D_0035f050, *(s32*)(func_002891d0(D_0035f01c) + 396));  // record_set_value_refresh
    } else {
        u8* w = base + 816;
        if (func_00139d78(w)) func_00139510(w);
    }
}
}
struct Heap2bd310;
struct Heap2bd310Vt { void* (*alloc)(Heap2bd310*, u32, s32); void (*free)(Heap2bd310*, void*); };
struct Heap2bd310 { Heap2bd310Vt* vt; };
struct Ctx2bd310 { u32 f0; void* file; u32 f8; void* f12; Heap2bd310* heap; };
extern "C" {
void func_002ba298(void*);
s32 func_001688c8(void*);
void func_00168388(void*, void*, s32, s32);
s32 func_00170cd0(void);
void func_00102448(Ctx2bd310*, s32);
void func_002baf48(void*, s32, void*, s32, s32, s32);
s32 func_002ba200(void);
void* func_002bd2f0(void*, s32*);
s32 func_002bd230(s32, u32);
void func_002bd310(Ctx2bd310* c)
{
    Heap2bd310* h = c->heap;
    void* fh = c->file;
    void* x = c->f12;
    u32 y = c->f8;
    func_002ba298(x);
    s32 sz = func_001688c8(fh);
    void* raw = h->vt->alloc(h, (sz + 2111) & ~2047, 0);
    void* buf = (void*)(((u32)raw + 63) & ~63);
    func_00168388(fh, buf, 0, 0);
    while (func_00170cd0()) func_00102448(c, 0);
    func_002baf48(x, 2, buf, sz, 0, 0);
    while (func_002ba200()) func_00102448(c, 0);
    s32 out = 0;
    void* r = func_002bd2f0(buf, &out);
    h->vt->free(h, raw);
    if (func_002bd230(out, y)) return;
    s32 sz2 = func_001688c8(r);
    void* raw2 = h->vt->alloc(h, (sz2 + 2111) & ~2047, 0);
    void* buf2 = (void*)(((u32)raw2 + 63) & ~63);
    func_00168388(r, buf2, 0, 0);
    while (func_00170cd0()) func_00102448(c, 0);
    func_002baf48(0, 1, buf2, sz2, 0, 0);
    while (func_002ba200()) func_00102448(c, 0);
    h->vt->free(h, raw2);
}

}
namespace w320_d {
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QWord& operator=(const QWord& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline QWord Cross(QWord& a, QWord& b) {
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot(QWord& a, QWord& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline void ScaleIn(QWord* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(s) : "$8", "memory");
}
struct P300 { u8 pad[36]; f32 f36; };
struct Ob {
    u8 p0[16]; QWord q16; QWord q32; u8 p48[240 - 48]; f32 f240; u8 p244[272 - 244]; f32 f272; u8 p276[300 - 276]; P300* p300;
    u8 p304[320 - 304]; u8 sub[32]; u32 f352; u8 p356[2208 - 356]; QWord q2208;
};
struct Ob2 { u8 pad[320]; u8 sub[32]; };
extern "C" {
extern Ob2* D_00351068;
extern f32 D_00349e10;
void func_0016af58(QWord*);
s32 func_001b2b58(Ob*);
void func_0017f540(void*, s32, f32, f32);
void func_001b2860(void* self, Ob* o)
{
    QWord v;
    s32 id = 0;
    v = o->q2208;
    f32 len = Normalize(&v);
    v.f[3] = len;
    if (8.0f < len) {
        QWord t;
        func_0016af58(&t);
        if (Dot(v, t) < -0.865999996662f) o->f240 = 0;
        ScaleIn(&o->q32, 0.5f);
    }
    v = o->q32;
    v.f[1] = 0.0f;
    Normalize(&v);
    if (o->q16.f[3] > o->f272) {
        if (func_001b2b58(o)) {
            id = 2;
            o->q16.f[3] = o->p300->f36;
        } else {
            f32 d = Dot(v, o->q16);
            if (D_00352130->f172 < d) o->f240 += D_00349e10;
            else o->f240 = 0;
        }
    } else {
        o->f240 = 0;
    }
    void* sb = o->sub;
    if (o->f352 & 4) {
        f32 k = 12.0f, z = 0.0f;
        func_0017f540(sb, id, k, z);
        func_0017f540(D_00351068->sub, id, k, z);
    }
}
}
}
