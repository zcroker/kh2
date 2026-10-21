#include "../common/types.h"
struct Alloc878 { virtual void* Alloc(int, int); virtual void Free(void*); };
struct Heap878 { u8 pad[20]; Alloc878* a; };
extern "C" Heap878* D_00347f80;
extern "C" u8 D_00347e60[];
extern "C" void func_00239700(void*);
struct MCObj878 {
    void* vt; u8 p4[8]; u32 f0c; u8 p10[8]; u8 m[384];
    MCObj878() { f0c = 0; vt = D_00347e60; func_00239700(m); }
    ~MCObj878() {}
    static void* operator new[](unsigned int n) { return D_00347f80->a->Alloc(n, 0); }
};
union F878 { s32 i; void* p; MCObj878* o; s32* q; u8 c; };
struct MCSave878 { F878 a0, a4, a8, ac, a10, a14, a18; };
extern "C" {
extern s32 D_0035f3f8;
extern MCObj878* D_0035f3fc;
extern s32* D_0035f400;
extern s32 D_0035f404;
extern s32* D_0035f408;
union G40c { s32* p; s32 i; };
extern G40c D_0035f40c;
extern s32 D_0035f410;
union G414 { MCSave878* p; s32 i; };
extern G414 D_0035f414;
void* func_001063c0(s32, s32);
s32* func_001063f0(s32, s32);
void func_0028c878(s32 heap, s32 n)
{
    if (D_0035f3f8) {
        D_0035f414.p = (MCSave878*)func_001063c0(28, heap);
        D_0035f414.p->a10.i = ((F878*)&D_0035f3f8)->i;
        D_0035f414.p->a8.i = ((F878*)&D_0035f404)->i;
        D_0035f414.p->a0.o = ((F878*)&D_0035f3fc)->o;
        D_0035f414.p->a4.q = ((F878*)&D_0035f400)->q;
        D_0035f414.p->ac.q = ((F878*)&D_0035f408)->q;
        D_0035f414.p->a14.q = ((F878*)&D_0035f40c)->q;
        D_0035f414.p->a18.i = ((F878*)&D_0035f410)->i;
    }
    D_0035f3f8 = heap;
    D_0035f404 = n;
    D_0035f3fc = new MCObj878[n];
    D_0035f400 = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    D_0035f408 = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    D_0035f40c.p = func_001063f0(D_0035f404 * 4, D_0035f3f8);
    for (s32 i = 0; i < D_0035f404; i++) D_0035f40c.p[i] = -1;
    D_0035f410 = 0;
}
}

extern "C" {
struct E818 { s16 id; s8 a; s8 b; s32 pad; };
struct T818 { u8 pad0[4]; s8 x4; u8 pad5[3]; E818 e[1]; };
struct O818 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; u8 pad3[161]; u8 c[1]; };
struct H818 { u8 pad[580]; O818* o; };
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_002570a0(s32);
H818* func_00281180(u32, s32);
s32 func_001145b0(s32);
void func_0026b5a0(s32);
void func_00270c70(s32);
void func_002713c8(void);
void func_00273a28(void);
extern u32 D_0035f01c;
extern u32 D_0035f010;
extern T818* D_0035f12c;
static inline s32 tf(s32 x) { return x != 0; }
void func_00273818(void) {
    s32 m = func_00287bc0();
    s32 idx;
    if ((u32)(m - 26) < 3) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(26);
    s32 v = func_002570a0(25);
    if (v) idx--;
    s16 id = D_0035f12c->e[idx].id;
    s32 flag;
    s32 r;
    if (!v) {
        flag = D_0035f12c->e[idx].a == 0;
    } else {
        if (m == 31) {
            r = func_0028b040(D_0035f01c);
        } else {
            r = tf(D_0035f12c->e[idx].b);
            r <<= 1;
            r |= D_0035f12c->e[idx].a;
            r++;
            if (r >= 4) r = 0;
        }
        D_0035f12c->e[idx].a = r & 1;
        D_0035f12c->e[idx].b = tf(r & 2) << 1;
        flag = D_0035f12c->e[idx].a != 0;
    }
    O818* o = func_00281180(D_0035f010, v)->o;
    s32 i;
    for (i = 0; i < o->n; i++) {
        if (o->a[i] == id || o->b[i] == id) o->b[i] = flag ? id : 0;
    }
    if (v) {
        r = func_001145b0(D_0035f12c->e[idx].id);
        o->c[r] = D_0035f12c->e[idx].b;
    }
    func_0026b5a0(25);
    if ((u32)(m - 26) < 3) {
        s32 old = D_0035f12c->x4;
        func_00270c70(v);
        func_002713c8();
        if (old != D_0035f12c->x4) func_00273a28();
    }
}
}
