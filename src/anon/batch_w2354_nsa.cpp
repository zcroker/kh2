#include "../common/types.h"
/* Soft-double libcalls bind to the game's own copies. */
asm("fptodp = func_00313b80");
asm("dpmul = func_00313f40");
asm("dpadd = func_00313e80");
asm("dptoul = func_00314508");
extern "C" {
struct M21f620 { f32 m[4][4]; };
struct C21f620 { u8 r, g, b, a; };
struct E21f620 { s32 f0; f32 t; };
struct H21f620 { u8* obj; s32 n; u8 cnt; u8 pad9; s16 sx; s16 sy; u8 flip; u8 pad15; E21f620 e[1]; };
struct S21f620 { s32 n; E21f620* p; u8 pad8[8]; u16 f16; s16 f18; C21f620 col; s32 f24; s16 h28; s16 h30; M21f620* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct A21f620 { H21f620* h; s32 col; s32 f8; f32 scale; f32 fade; f32* rot; };
void U21f620_ucall4(M21f620*, u8*) asm("_Z16u_call4_002f3f98jjjj");
void func_002f4000(M21f620*);
void U21f620_wtarget(M21f620*, s32, M21f620*) asm("_Z16wtarget_002f3d08jjjj");
void func_0021efc0(S21f620*);
void func_0021f060(S21f620*);
extern u8 D_01d9e360;
extern M21f620 D_01d9e840;
/* Draw a strip of sprites along a line: per entry, step the position, fade the alpha
   and scale the sprite matrix, then submit it (sibling of func_0021fa28). */
void func_0021f620(A21f620* a, s32 id) {
    M21f620 m;
    M21f620 w;
    S21f620 st;
    H21f620* h;
    u8* o;
    h = a->h;
    o = h->obj;
    if (o == &D_01d9e360) return;
    if (h->n == 0) return;
    if (*(f32*)(o + 124) == 0.0f) return;
    if (*(u8*)(o + 143)) {
        U21f620_ucall4(&m, o);
    } else {
        func_002f4000(&m);
        m.m[3][2] = D_01d9e840.m[3][2] + *(f32*)(o + 136);
    }
    *(s32*)&st.col = a->col;
    st.n = h->n;
    st.f18 = id;
    st.mtx = &w;
    st.f44 = 0;
    st.f24 = 0;
    st.h28 = 0;
    st.h30 = 0;
    f32 bx, by;
    if (*(u8*)(o + 143)) {
        bx = by = 0.0f;
    } else {
        bx = D_01d9e840.m[3][0];
        by = D_01d9e840.m[3][1];
    }
    f32 sy = h->sy;
    f32 sx = h->sx;
    f32 al = *(f32*)(o + 112);
    bx += al * sy;
    f32 dx = al * sx;
    al = *(f32*)(o + 116);
    by += al * sy;
    f32 dy = al * sx;
    al = *(f32*)(o + 164);
    al -= *(u8*)(o + 142);
    if (al <= 0.0f) al = 0.0f;
    else {
        al = al / (a->fade * *(f32*)(o + 120));
        if (1.0f < al) al = 1.0f;
    }
    if (h->flip) al = 1.0f - al;
    al *= (f32)st.col.a * *(f32*)(o + 124);
    E21f620* e = h->e;
    s32 n = h->cnt;
    while (n > 0) {
        f32 t = e->t;
        st.p = e;
        n--;
        func_0021efc0(&st);
        e++;
        bx += dx * t;
        by += dy * t;
        m.m[3][0] = bx;
        m.m[3][1] = by;
        st.col.a = (u8)(al * (t * 0.75 + 0.25));
        t *= a->scale;
        m.m[0][0] = *(f32*)o * t * a->rot[0];
        m.m[1][1] = *(f32*)(o + 20) * t * a->rot[1];
        U21f620_wtarget(&w, a->f8, &m);
        func_0021f060(&st);
    }
}
}
