#include "../common/types.h"

struct V4_w1983 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub_w1983 { f32 f0; char* p4; };
struct Tbl_w1983 { s32 o0; s32 o4; s32 o8; };
struct A0_w1983 { char pad[0xc]; s32 id; char pad2[0x9d - 0x10]; u8 b9d; };
struct A1_w1983 { s32 id; f32 f4; s32 idx; s32 off; };
struct A2_w1983 { char pad[0xc]; Tbl_w1983* t; };
struct Ent_w1983 { s32 a; char* p; s32 c, d; };
struct G_w1983 { char pad[0x80]; Ent_w1983* e; char pad2[0xa8 - 0x84]; u64 fl; };

struct H_w1983 { char p[0x8064]; s32 h; char p2[0x8074 - 0x8068]; s32 v74; char p3[0x8090 - 0x8078]; u8 b90; };
struct O_w1983 {
    char p0[0x58]; u8 b58; char p1[0x88 - 0x59]; s32 v88; s32 v8c; s32 arr[17]; f32 fd4; f32 fd8;
};
struct Q_w1983 { char p[0x8c]; s32 v8c; };

extern "C" {
s32 func_00222568(void);
void func_002226b8(void*, void*);
f32 func_002229a0(void*);
void func_002f3d98(void*, void*);
void func_002f3ed0(void*, void*, void*, f32);
void func_002f3ef8(void*, void*, void*);
void func_002f3f10(void*, void*, void*);
void func_002f3f40(void*, void*, f32);
void func_002f3f88(void*, void*);
extern char D_01d9e360[];
extern G_w1983* D_01d9e6e0;
extern s32 D_01d9ea9c;

Q_w1983* func_002dc7c8(void*);
s32 func_002ceb28(void);
s32 func_00197920(void);
s32 func_002e33d8(s32, s32, s32);
s32 func_002e33f8(s32, s32, s32);
s32 func_002e3318(s32, s32*, s32, s32, s32, s32);
void func_002cf938(s32);
void func_002cfb30(void);
extern f32 D_00349e10;

void func_001fbd78(A0_w1983* a0, A1_w1983* a1, A2_w1983* a2) {
    V4_w1983 v;
    struct { s64 a, b; } r;
    V4_w1983 u;
    Sub_w1983* s = (Sub_w1983*)((char*)a0 + a2->t->o8 + 0xa0);
    if (a0->id == a1->id) {
        s32 idx;
        char* p;
        s->f0 = a1->f4;
        idx = a1->idx;
        if (idx != -1) {
            p = D_01d9e6e0->e[idx].p + a1->off + 0xa0;
        } else {
            p = D_01d9e360;
        }
        s->p4 = p;
        if (a0->id == 0 && a0->b9d == 0) return;
    }
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->fl & 0xFF0000FF00ULL) return;
    if (s->p4 == D_01d9e360) return;
    {
        Tbl_w1983* t = a2->t;
        char* p2 = (char*)a0 + t->o4 + 0xa0;
        func_002f3f10(&v, s->p4, (char*)a0 + t->o0 + 0xa0);
        func_002f3d98(&v, &v);
        func_002f3f88(&u, p2);
        f32 len = func_002229a0(&u);
        func_002f3d98(&u, &u);
        func_002f3ef8(&r, &u, &v);
        if (r.a == 0 && r.b == 0) {
            (&v.x)[func_00222568() % 3] += 0.05f;
        }
        func_002f3ed0(&v, &v, &u, s->f0);
        func_002f3d98(&v, &v);
        func_002f3f40(&v, &v, len);
        func_002226b8(p2, &v);
    }
}
}

#define HH_w1983(o) ((H_w1983*)(o))
void func_002dcc90(int arg)
{
    O_w1983* o = (O_w1983*)arg;
    o->b58 = 1;
    if (HH_w1983(o)->v74 >= func_002dc7c8(o)->v8c) o->v88 = 1;
    else o->v88 = 0;
    if (!func_002ceb28()) return;
    if (func_00197920()) return;
    {
        f32 k = 60.0f;
        s32 idx = (s32)(o->fd4 / k);
        if (o->fd8 / k < (f32)idx) {
            s32 r = func_002e33d8(HH_w1983(o)->h, idx, o->v8c);
            if (r >= 0) {
                idx = r;
                o->fd4 = (f32)r * k;
            }
            r = func_002e33f8(HH_w1983(o)->h, idx, o->v8c);
            if (r >= 0) {
                idx = r;
                o->v8c = 0;
                HH_w1983(o)->b90 = 0;
                o->fd4 = (f32)r * k;
            }
            s32 n = func_002e3318(HH_w1983(o)->h, o->arr, 16, idx, o->v88, o->v8c);
            o->arr[n] = 0;
            if (n) {
                if (HH_w1983(o)->b90) {
                    s32 j;
                    for (j = 0; j < n; j++) {
                        s32 w = o->arr[j];
                        if (w != 0 && (w & 0xffffff) != 0x315f6d) {
                            HH_w1983(o)->b90 = 0;
                            break;
                        }
                    }
                }
                func_002cf938(0);
            }
            o->arr[0] = 0;
        }
        func_002cfb30();
        o->fd8 = o->fd4;
        o->fd4 += D_00349e10;
    }
}
