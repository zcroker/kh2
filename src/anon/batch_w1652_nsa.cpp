#include "../common/types.h"
extern "C" {
struct W1652M21fa28 { f32 m[4][4]; };
struct W1652C21fa28 { u8 r, g, b, a; };
struct W1652S21fa28 { s32 n; u8* p; u8 pad8[8]; u16 f16; s16 f18; W1652C21fa28 col; s32 f24; s32 f28; W1652M21fa28* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct W1652H21fa28 { u8* obj; s32 n; };
struct W1652A21fa28 { W1652H21fa28* h; s32 col; s32 f8; f32 scale; f32* rot; };
void W1652_ucall4(W1652M21fa28*, u8*) asm("_Z16u_call4_002f3f98jjjj");
void func_002f4000(W1652M21fa28*);
void func_002f3f40(f32, f32*, f32*);
void W1652_wtarget(W1652M21fa28*, s32, W1652M21fa28*) asm("_Z16wtarget_002f3d08jjjj");
void func_0021efc0(W1652S21fa28*);
void func_0021f060(W1652S21fa28*);
extern u8 D_01d9e360;
extern W1652M21fa28 D_01d9e840;
void func_0021fa28(W1652A21fa28* a, s32 id) {
    W1652M21fa28 m;
    W1652S21fa28 st;
    W1652H21fa28* h;
    u8* o;
    h = a->h;
    o = h->obj;
    if (o == &D_01d9e360) return;
    if (h->n == 0) return;
    if (*(f32*)(o + 124) == 0.0f) return;
    if (*(u8*)(o + 143)) {
        W1652_ucall4(&m, o);
    } else {
        func_002f4000(&m);
        m.m[3][0] = D_01d9e840.m[3][0] + *(f32*)(o + 128);
        m.m[3][1] = D_01d9e840.m[3][1] + *(f32*)(o + 132);
        m.m[3][2] = D_01d9e840.m[3][2] + *(f32*)(o + 136);
    }
    m.m[0][0] *= a->scale;
    m.m[1][1] *= a->scale;
    func_002f3f40(a->rot[0], m.m[0], m.m[0]);
    func_002f3f40(a->rot[1], m.m[1], m.m[1]);
    func_002f3f40(a->rot[2], m.m[2], m.m[2]);
    W1652_wtarget(&m, a->f8, &m);
    *(s32*)&st.col = a->col;
    st.col.a = (s32)((f32)st.col.a * *(f32*)(o + 124));
    st.n = h->n;
    st.p = (u8*)h + 8;
    func_0021efc0(&st);
    st.f18 = id;
    st.mtx = &m;
    st.f44 = 0;
    st.f24 = 0;
    st.f28 = 0;
    func_0021f060(&st);
}
}
