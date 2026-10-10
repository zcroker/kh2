#include "../common/types.h"
struct Alloc278 { virtual void* Alloc(int, int); virtual void Free(void*); };
struct Heap278 { u8 pad[20]; Alloc278* a; };
extern "C" Heap278* D_00347f80;
struct MCObj278 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~MCObj278();
    static void operator delete[](void* p) { D_00347f80->a->Free(p); }
    u8 pad[404];
};
union F278 { s32 i; void* p; MCObj278* o; u8 c; };
struct MCSave278 { F278 a0, a4, a8, ac, a10, a14, a18; };
extern "C" {
extern s32 D_0035f3f8;
extern MCObj278* D_0035f3fc;
extern void* D_0035f400;
extern s32 D_0035f404;
extern void* D_0035f408;
extern void* D_0035f40c;
extern s32 D_0035f410;
extern MCSave278* D_0035f414;
void func_0028cdb8(s32);
void DelArr278(void*) asm("_ZdaPv");
void LoadDataFree278(...) asm("_ZN2Tz12LoadDataFreeEz");
void Exit278() asm("_ZN2Tz10MenuCursor4ExitEv");
void Exit278() {
    s32 i;
    for (i = 0; i < D_0035f404; i++) func_0028cdb8(i);
    if (D_0035f3fc) {
        delete[] D_0035f3fc;
        D_0035f3fc = 0;
    }
    if (D_0035f400) { DelArr278(D_0035f400); D_0035f400 = 0; }
    if (D_0035f408) { DelArr278(D_0035f408); D_0035f408 = 0; }
    if (D_0035f40c) { DelArr278(D_0035f40c); D_0035f40c = 0; }
    D_0035f3f8 = 0;
    D_0035f404 = 0;
    if (D_0035f414) {
        MCSave278* s = D_0035f414;
        ((F278*)&D_0035f3f8)->i = s->a10.i;
        ((F278*)&D_0035f404)->i = s->a8.i;
        ((F278*)&D_0035f3fc)->o = s->a0.o;
        ((F278*)&D_0035f400)->p = s->a4.p;
        ((F278*)&D_0035f408)->p = s->ac.p;
        ((F278*)&D_0035f40c)->p = s->a14.p;
        ((F278*)&D_0035f410)->i = s->a18.i;
        LoadDataFree278(s);
        D_0035f414 = 0;
    }
}
}
struct CurItem278 { u8 pad[388]; s32 num; u8 pad2[16]; };
struct CurOwn278 { u8 pad[19584]; CurItem278 item[4]; };
struct CurTbl278 { s16 a, b, c; };
struct CurSt278 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern "C" {
extern CurOwn278* D_0035f634;
extern CurTbl278 D_00374cd8[];
CurSt278* func_002b23e0(s32);
void Call4_278(CurItem278*) asm("_Z16u_call4_00139d78jjjj");
s32 IsHide278(CurItem278*) asm("_ZN2dk5Obj2D6isHideEv");
void Show278(CurItem278*) asm("_ZN2dk5Obj2D4showEv");
void SetNum278(CurItem278*, s32) asm("_ZN2dk6Sprite6setNumEi");
void Attach278(CurItem278*, CurItem278*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002b2da8(s32 idx) {
    CurSt278* st = func_002b23e0(-1);
    CurItem278* o = &D_0035f634->item[idx + 1];
    Call4_278(o);
    if (IsHide278(o)) Show278(o);
    if (idx != 0) {
        o = &D_0035f634->item[idx];
        if (IsHide278(o)) Show278(o);
        SetNum278(o, D_00374cd8[st->bit].c);
        o = &D_0035f634->item[3];
        if (IsHide278(o)) Show278(o);
    } else {
        o = &D_0035f634->item[1];
        s16 n = D_00374cd8[st->bit].a;
        if (o->num != n) SetNum278(o, n);
    }
    o = &D_0035f634->item[0];
    if (IsHide278(o)) Show278(o);
    Attach278(o, &D_0035f634->item[idx + 1]);
}
}
struct Big278 { Big278* next; s32 k, maxwds, sign, wds; u32 x[1]; };
extern "C" {
s32 func_00304468(Big278*, Big278*);
Big278* func_00303b70(void*, s32);
Big278* func_003044d0(void* ptr, Big278* a, Big278* b) {
    Big278* c;
    s32 i, wa, wb;
    s32 borrow, y, z;
    u32 *xa, *xae, *xb, *xbe, *xc;
    i = func_00304468(a, b);
    if (!i) {
        c = func_00303b70(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a; a = b; b = c;
        i = 1;
    } else
        i = 0;
    c = func_00303b70(ptr, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16*)xc)[0] = y; ((u16*)xc)[1] = z; xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((u16*)xc)[0] = y; ((u16*)xc)[1] = z; xc++;
    }
    while (!*--xc) wa--;
    c->wds = wa;
    return c;
}
}
struct Vq278 {
    f32 x, y, z, w;
    Vq278& operator=(const Vq278& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Res278 { Vq278 v; u64 id:16; u64 flag:1; u64 rest:47; };
struct Src278 { u8 pad[4]; s32 type; u8 pad2[4]; u16 id; u8 pad3[2]; f32 t; u8 pad4[12]; Vq278 v; };
extern "C" {
extern s8 D_01c940c0;
extern Res278 D_01c940d0;
void func_001b13d0();
void func_002fd188(void (*)());
s32 func_001b0498(Src278*);
f32 func_002f87c0(f32);
Res278* func_001b0580(Src278* s) {
    if (!D_01c940c0) {
        D_01c940c0 = 1;
        func_002fd188(func_001b13d0); /* static local dtor registration */
    }
    if (!func_001b0498(s)) return 0;
    switch (s->type) {
    case 0:
        return 0;
    case 1:
    case 2:
        D_01c940d0.v = s->v;
        D_01c940d0.v.w = (1.0f - func_002f87c0(s->t * 3.1415927f)) * 0.5f;
        asm volatile("" ::: "memory");
        D_01c940d0.id = s->id;
        D_01c940d0.flag = 0;
        break;
    case 3:
        D_01c940d0.v = s->v;
        D_01c940d0.v.w = (1.0f - func_002f87c0(s->t * 3.1415927f)) * 0.5f;
        asm volatile("" ::: "memory");
        D_01c940d0.id = s->id;
        D_01c940d0.flag = 1;
        break;
    }
    return &D_01c940d0;
}
}
struct ITbl278 { s16 max; u8 pad[18]; };
extern "C" {
extern s32 D_0035f01c;
extern s8* D_0035f234;
extern ITbl278 D_00373f10[];
s32 func_0028b040(s32);
void func_0023d1d0();
void func_0023d1e0();
void func_002b6bc4(s32);
void func_0027d868(u8 dir) {
    s32 k = func_0028b040(D_0035f01c);
    s32 v = D_0035f234[k];
    if (dir) {
        v--;
        if (v < 0) v = D_00373f10[k].max - 1;
    } else {
        v++;
        if (!(v < D_00373f10[k].max)) v = 0;
    }
    D_0035f234[k] = v;
    if (k == 6) {
        if (D_0035f234[6] == 0) func_0023d1d0();
        else func_0023d1e0();
    } else if (k == 7) {
        s8 m = D_0035f234[7];
        if (m == 2) v = 0;
        else v = (m == 1) ? 2 : 1;
        func_002b6bc4(v);
    }
    if (k == 0) {
        s8* p = D_0035f234;
        if (p[0] == 1 && p[1] == 1) p[1] = 0;
    } else if (k == 1) {
        s8* p = D_0035f234;
        if (p[0] == 1 && p[1] == 1) p[0] = 0;
    }
}
}
/* VU0 random float in [0,1): vrnext chain seeded by vf2 = -1 (hand-written asm macro) */
#define VRAND278(out) asm volatile( \
    "addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" \
    : "=r"(out) : : "$8")
union JF278 { f32 f; s32 i; u8 c; };
struct JEnt278 { s32 id; s32 off; void* a; void* b; void* c; u8 flag; };
struct JOwn278 { u8 pad[12]; s32 id; };
struct JSt278 { u8 pad[168]; u64 bits; };
struct JRef278 { u8 pad[12]; s32* off; };
extern "C" {
extern s32 D_01d9ea9c;
extern JSt278* D_01d9e6e0;
extern s32 D_01d9e360[];
s32 func_001ed638(f32, void*);
void func_001ed658(u8* o, JEnt278* e, JRef278* r) {
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->bits & 0xff0000ff00ULL) return;
    if (e->id != ((JOwn278*)o)->id) return;
    f32 f, g;
    VRAND278(f);
    if (e->flag) {
        VRAND278(g);
        f += g;
    } else {
        f += f;
    }
    JF278* pf = (JF278*)(o + *r->off + 160);
    pf->f = f;
    s32* d;
    if (e->off != -1) d = (s32*)(o + e->off + 160);
    else d = D_01d9e360;
    d[0] += func_001ed638(pf->f, e->a);
    d[1] += func_001ed638(pf->f, e->b);
    d[2] += func_001ed638(pf->f, e->c);
}
}
