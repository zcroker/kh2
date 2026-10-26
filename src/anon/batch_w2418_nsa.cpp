#include "../common/types.h"
extern "C" {
struct W2418Seq { u8 pad[344]; };
struct W2418Sprite {
    u8 pad0[24];
    W2418Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W2418Menu3 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W2418Sprite root;       // 48
    u8 pad2[40];
    W2418Seq title;         // 496
    W2418Sprite spr[5];     // 840
    union { f32 f; u8 c; } f2880;
    union { u32 u; u8 c; } p2884;
    f32 f2888;
    f32 f2892;
    union { s32 i; u8 c; } f2896;
};
void func_00138650(W2418Sprite*, u32, u32, u32);
void func_001386e0(W2418Sprite*, u32, u32, void*, u32, u32);
s32 func_0013a9d0(void);
void func_002368e8(void*, f32);
void func_002367c8(void*);
void func_001396b0(W2418Sprite*);
void func_0031a260(W2418Sprite*, u32);
void func_00139660(W2418Sprite*);
void func_00139688(W2418Sprite*);
void func_00138c68(W2418Sprite*, s32, s32);
void func_00138c40(W2418Sprite*, s32, s32);
void func_00239988(W2418Seq*, u32, void*);
void func_00239c38(W2418Seq*, s32);
void func_0023acd8(W2418Seq*);
s32 func_0023a950(W2418Seq*);
s32 func_0023a988(W2418Seq*);
s32 func_0023aa18(W2418Seq*);
s32 func_0023aa38(W2418Seq*);
s32 func_0023aa78(W2418Seq*);
void func_0014fc40(W2418Menu3*, u32, s32, u32, u32, s32);
void func_001519f8(W2418Menu3*);
void func_00151bd8(W2418Menu3*);

static inline void W2418_setParent(W2418Sprite* obj, W2418Sprite* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

void func_001516b0(W2418Menu3* self, u32 a1, u32 a2, s32 mode, f32* pv, u32 a5, f32 f) {
    s32 num;
    void* s5;
    s32 cr, i;
    self->p2884.u = (u32)pv;
    self->f2880.f = f;
    self->f2896.i = 0;
    self->f2888 = *pv;
    func_00138650(&self->root, 3400, a1, 10);
    s32 r = func_0013a9d0();
    if (__builtin_expect(r, 0)) {
        s5 = (u8*)&self->root + 32;
        func_002368e8(s5, 0.8f);
        func_002367c8(s5);
    } else {
        s5 = (u8*)&self->root + 32;
    }
    num = 0;
    switch (mode) {
    case 0: num = 16; break;
    case 2: num = 15; break;
    case 1: num = 17; break;
    }
    func_00239988(&self->title, a2, s5);
    func_00239c38(&self->title, num);
    func_0023acd8(&self->title);
    self->x = func_0023a950(&self->title);
    func_001386e0(&self->spr[0], 3400, a2, s5, 3, 10);
    func_001386e0(&self->spr[1], 3400, a2, s5, 12, 10);
    func_001386e0(&self->spr[2], 3400, a2, s5, 13, 10);
    func_001386e0(&self->spr[3], 3400, a2, s5, 14, 10);
    func_001386e0(&self->spr[4], 3400, a2, s5, 9, 10);
    cr = func_0023aa78(&self->spr[0].seq);
    func_0014fc40(self, a5, cr, 3400, 10, mode);
    func_001519f8(self);
    for (i = 0; i < 5; i++) {
        W2418_setParent(&self->spr[i], &self->spr[0]);
        func_00139660(&self->spr[i]);
        func_00139688(&self->spr[i]);
        func_00138c68(&self->spr[i], func_0023a950(&self->spr[0].seq), func_0023a988(&self->spr[0].seq));
    }
    func_00138c68(&self->spr[2], func_0023aa18(&self->spr[0].seq), func_0023aa38(&self->spr[0].seq));
    W2418_setParent(&self->spr[0], 0);
    func_00138c40(&self->spr[0], self->x, self->y);
    func_00151bd8(self);
    self->f2892 = -1.0f;
}
}

extern "C" {

typedef struct W2418Pk { u16 a0; u16 flags; u8 c[4]; u64 f8; void* f10; s32 f14; u8 f18; u32 f1c; u8 pad[16]; } W2418Pk;
typedef struct W2418It { u8 p0[0x24]; u16 f24; u16 f26; s8 c[4]; u8 p2c[0x54 - 0x2c]; f32 f54; u64 f58; } W2418It;
typedef struct W2418Vc { f32 x, y, z, w; u8 p10[16]; } W2418Vc;
typedef struct W2418Q { W2418It* it; W2418Vc* v; s32 n; f32 scale; u8 p10[2]; u8 f12; } W2418Q;
typedef struct W2418T { s32 a; s32 b; s32 c; } W2418T;
typedef struct W2418A2 { u8 p0[0xc]; W2418T* fc; } W2418A2;
typedef struct W2418A1 { u32 p0; s32 f4; u8 p8[4]; u8 fc; u8 p0d[0x94 - 0xd]; f32 f94; f32 f98; } W2418A1;
typedef struct W2418E { u8* data; s32 x; } W2418E;
typedef struct W2418O { u8 p0[0x14]; W2418E* f14; } W2418O;
typedef struct W2418Ent { s16 off; u8 p[6]; } W2418Ent;
typedef struct W2418H { u8 p[16]; W2418Ent e[1]; } W2418H;
extern W2418O* D_01d9e6e4;
extern s32 D_01d9eaa4;
s32 func_0021d048(u8*, W2418Pk*, s32);
s32 func_0020a060(W2418Q*, W2418A1*);
void func_0020aec0(void*, W2418A1*, W2418Q*);
f32 func_0020aec8(void*, f32 (*)[4], W2418A1*, W2418Q*, W2418It*);

void func_0020aff8(u8* a0, W2418A1* a1, W2418A2* a2) {
    W2418Q* q = (W2418Q*)(a0 + a2->fc->c + 0xa0);
    W2418It* it = q->it;
    W2418Vc* v = q->v;
    u8* col = a0 + a2->fc->b + 0xa0;
    s32 n = q->n;
    if (func_0020a060(q, a1) && q->f12) {
        s32 id = a1->f4;
        if (__builtin_expect(id != 0xffff, 1)) {
            u8 bufA[64];
            f32 m[4][4] __attribute__((aligned(16)));
            W2418Pk p;
            W2418E* e;
            s32 cr, cg, cb, ca;
            u8* data;
            s32 i;
            func_0020aec0(bufA, a1, q);
            e = &D_01d9e6e4->f14[id];
            p.flags = 16;
            if (a1->fc) p.flags = 0x810;
            p.f1c = 0;
            p.f8 = 0;
            p.f18 = 0;
            p.f10 = m;
            data = e->data;
            cr = col[8];
            cg = col[9];
            cb = col[10];
            ca = col[11];
            for (i = 0; i < n; i++) {
                if (it->f26 != 0 && !(it->f58 & 0x100)) {
                    f32 d = func_0020aec8(bufA, m, a1, q, it);
                    f32 nr = a1->f94;
                    f32 w = a1->f98;
                    s32 r, g, b, al;
                    u8* a;
                    if (d < nr - w) {
                        it->f54 = 0.0f;
                    } else if (d < nr) {
                        it->f54 *= 1.0f - (nr - d) / w;
                    }
                    { s32 o = it->f24 * 8; a = data + *(s16*)(data + o + 16); }
                    r = cr + it->c[0];
                    g = cg + it->c[1];
                    b = cb + it->c[2];
                    al = ca + it->c[3];
                    if (v) {
                        r += (s32)v->x;
                        g += (s32)v->y;
                        b += (s32)v->z;
                        al += (s32)v->w;
                    }
                    if (r < 0) r = 0; else if (r >= 256) r = 255;
                    if (g < 0) g = 0; else if (g >= 256) g = 255;
                    if (b < 0) b = 0; else if (b >= 256) b = 255;
                    if (al < 0) al = 0; else if (al >= 128) al = 127;
                    p.c[3] = al;
                    p.c[0] = r;
                    p.c[1] = g;
                    p.c[2] = b;
                    p.c[3] = (s32)((f32)p.c[3] * it->f54 * q->scale);
                    if (p.c[3]) {
                        p.f14 = D_01d9eaa4;
                        D_01d9eaa4 = func_0021d048(a, &p, e->x);
                    }
                }
                it++;
                if (v) v++;
            }
        }
    }
}
}
