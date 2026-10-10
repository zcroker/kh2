#include "../common/types.h"
struct T318 { u32 a, b, c, d, e; };
struct A318 { u8 pad[2548]; T318 t; u8 pad2[2924-2568]; int idx; u8 pad3[12]; u32 fl; };
typedef void (A318::*P318)(T318*, void*);
struct E318 { P318 f; } __attribute__((aligned(8)));
struct R318 { u32 pfn; int d; } __attribute__((aligned(8)));
extern E318 D_00345b28[];
typedef void (*F318)(void*, T318*, void*);
#define QCOPY318(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Q318 {
    union { u32 v[4]; f32 f[4]; };
    Q318() {}
    Q318(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    Q318(const Q318& o) { QCOPY318(this, &o); }
    Q318& operator=(const Q318& o) {
        if (this != &o) QCOPY318(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct E318c { u8 b0, b1, b2, b3; union { f32 x; s32 ix; }; f32 y, z; };
struct H318 { u16 h0, h2; };
struct O318 { u8 pad[108]; H318* h; };
struct R318c { s32 a; s32 b; s32 c; s32 d; Q318 q; O318* obj; u8 b36; u8 pad[3]; f32 f40; f32 f44; u8 pad2[32]; f32 f80; };
struct K318 { u8 pad[388]; s32 f388; };
struct L318 { u8 pad[396]; void* f396; s32 f400; u8 pad2[4]; };
extern "C" {
void func_00190128(void*);
int func_00190140(void*);
int func_00190680(void*, T318*);
int func_001b58a8(void);
int func_00112720(void*);
void func_0010df18(A318* p) {
    T318* s = &p->t;
    T318 t = p->t;
    func_00190128(s);
    if (func_001b58a8()) {
        (p->*D_00345b28[11].f)(&t, s);
    } else if (func_00112720(p)) {
        (p->*D_00345b28[p->idx - 8].f)(&t, s);
    } else {
        int i = (*(int (**)(void*))(*(u32*)p + 152))(p);
        E318 ee = D_00345b28[i];
        R318& e = *(R318*)&ee;
        int d = e.d;
        char* q = (char*)p + (d >> 1);
        F318 fn;
        if ((u8)(d & 1)) fn = *(F318*)(((e.pfn >> 2) << 2) + *(u32*)q);
        else fn = (F318)e.pfn;
        fn(q, &t, s);
    }
    u32 ok = 0;
    if (func_00190140(s)) ok = p->t.a != 0;
    if (!(u8)ok) func_00190128(s);
    if (!func_00190680(s, &t)) p->fl |= 8;
}

u32 func_001064a8(int);
void func_0018c438(R318c*);
int func_0018c528(int);
int func_0016b740(s32);
f32 func_00106558(f32);
f32 func_001db510(O318*, Q318);
f32 func_001065a8(f32, f32);
int func_0018c650(R318c* o, Q318* v, int n, E318c* tab, O318* obj, f32 fa, f32 fb) {
    E318c* sel = 0;
    int acc = 0;
    E318c* sp5 = 0;
    int r = (int)func_001064a8(100);
    for (int i = 0; i < n; i++) {
        if (tab[i].b0 == obj->h->h2) {
            if (tab[i].b1 == 3) sp5 = &tab[i];
            else {
                int w = tab[i].b2;
                if (r >= acc && r < acc + w) sel = &tab[i];
                acc += w;
            }
        }
    }
    if (sel) {
    func_0018c438(o);
    o->a = sel->b1 == 1 ? 6 : 2;
    o->c = func_0018c528(sel->b1);
    switch (sel->b3) {
    case 1:
        o->b = 1;
        o->d = func_0016b740(sel->ix);
        break;
    case 2:
        o->b = 2;
        break;
    case 3: {
        o->b = 3;
        o->q = Q318(sel->x, sel->y, sel->z, 0.0f);
        break;
    }
    case 0:
    default:
        o->b = 0;
    }
    o->b36 = 0;
    if (sp5 && func_001064a8(100) < sp5->b2) o->b36 = 1;
    o->obj = obj;
    o->f40 = func_00106558(1.0f);
    o->f44 = func_001db510(o->obj, *v);
    o->f80 = func_001065a8(fa, fb);
    return 1;
    }
    return 0;
}

s32 func_0013dda0(int);
s32 func_00158290(void*);
s32 func_0013a7e8(int);
s32 func_0013d7e0(void);
int func_00156030(void*);
s32 func_00155f40(void*);
s32 func_00155ee8(void*);
s32 func_00155fc0(void*);
int func_00139c18(void*);
void func_001386e0(void*, int, s32, s32, int, s32);
void func_001396b0(void*);
void func_0031a260(void*, int);
int func_001396c0(void*);
void func_00139570(void*);
int func_00156058(void*);
int func_00156080(void*);
void func_00138c10(void*, s32);
void func_00156d20(void*);
void func_00156408(void*);
void func_001581f8(void*);
void func_001542c8(void*, s32, s32);
void func_001575c0(void*);
void func_00156e48(u8* p) {
    L318* t;
    s32 a = func_0013dda0(0);
    s32 b = func_00158290(p);
    s32 c = func_0013a7e8(1);
    s32 d = func_0013d7e0();
    K318* k;
    if (func_00156030(p)) goto out;
    k = (K318*)(p + 11648);
    {
    s32 v1 = k->f388;
    if (v1 == func_00155f40(p)) goto out;
    }
    {
    s32 v2 = k->f388;
    if (v2 == func_00155ee8(p)) goto out;
    }
    {
        if (p[15611] == 1) {
            int i = func_00139c18(p + 3364);
            void* q = p + 6704;
            t = &((L318*)(p + 3364))[i];
            func_001386e0(t, 7000, c, d, 130, b);
            t->f396 = q;
            func_001396b0(t);
            if (t->f396) {
                t->f400 = 0;
                func_001396b0(t);
                if (t->f400) func_0031a260(t, 0);
            }
            if (func_001396c0(q)) func_00139570(&((L318*)(p + 3364))[i]);
        }
        if (func_00156058(p) || func_00156080(p)) {
            func_00138c10(k, func_00155f40(p));
            func_00138c10(p + 12060, func_00155fc0(p));
            p[15607] = 1;
        } else {
            func_00156d20(p);
        }
    }
out:
    func_00156408(p);
    *(s32*)(p + 52) = a;
    func_001581f8(p);
    func_001542c8(p + 64, a, *(s32*)(p + 24));
    if (*(s32*)(p + 52)) func_001575c0(p);
}
}
