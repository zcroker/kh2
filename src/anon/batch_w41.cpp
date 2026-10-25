#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

struct Vec16 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct NoTail { ~NoTail() {} };

// delete[]-free object with a 2-element 16-byte-aligned member array (empty dtors)
struct W41Inner { u32 w[4]; ~W41Inner() {} } __attribute__((aligned(16)));
struct W41Outer { u8 pad[32]; W41Inner arr[2]; ~W41Outer() {} };
void operator delete(void*) asm("func_001e0158");

extern "C" {

// ---- externs ----
s32 func_00103b38(u32);
void func_00102080(void*);
extern u32 D_0032b984;
extern u8 D_0033cb80[];
extern u8 D_0033cbb0;
extern u32 D_0033cbac;

u8* func_001058e8(void);
u8 func_00105f98(void);
struct W41VObj { void (**vt)(W41VObj*); };
W41VObj* func_00102c80(void);

u64* func_00133ba0(u32, u32, u32);  // forward_sub24_to_1337f0
f32 func_002f8ad0(f32, f32);

struct W41Node { u32 f0; W41Node* next; u32 f8, fc; u32 key; };
struct W41List { u32 f0; W41Node* head; };
extern W41List* D_00347f80_list asm("D_00347f80");
void func_00139708(W41Node*);

struct W41Sema { u8 pad[24]; s32 sema; u8 pad2[60]; };
extern s32 D_00349e40;
extern W41Sema D_00349e7c[2];
void func_00305660(s32);
void func_00305690(s32, void*);
void func_00305640(s32);

struct W41S20 { u32 w[5]; };
extern W41S20 D_0034a9f0;
void func_00141010(f32);
u8* func_00140df0(void);

struct W41Ent16 { u16 id; u16 pad; s32 val; u32 x, y; };
struct W41Tbl { u32 f0; s32 n; u32 f8, fc; W41Ent16 e[1]; };

extern char D_004f63d8[];
extern char D_0036c450[];
extern u32 D_0033caf0;
void func_002fee78(char*, const char*, ...);

extern s8 D_01c5f4f0;
extern u128 D_01c5f500;
void func_00175540(void);
void func_002fd188(void (*)(void));  // pool_alloc_block

struct W41VObj2 { void** vt; };
extern W41VObj2* D_00361f60_obj asm("D_00361f60");
extern u32 D_00361f60;
u32 func_002cebb0(void);  // get_global_361f60

s32 func_00180cd0(u8*);
s32 func_001805a8(u8*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_00169f98(u8*);

struct W41E12 { u8 b[12]; };
extern s32 D_0034ed00;
extern W41E12 D_01c60588[];
void func_001828b8(W41E12*);
void func_001827a8(W41E12*);

void func_00198dc0(u8*);
extern u8 D_01c61b48[];

}

// Walks every node of the global list and processes the ones whose key matches.
static inline W41Node* w41NextNode(W41List* l, W41Node* n) { if (n == 0) return l->head; return n->next; }

extern "C" {

void func_00105de0(u32 a) {
    if (func_00103b38(a) == 0 && (D_0032b984 ^ 2) != 0) {
        D_0033cbb0 = 1;
        D_0033cbac = a;
        func_00102080(D_0033cb80);
    }
}

struct W41S10 { u8 a, b, c; u16 d, e, f; };
static inline void w41InitS10(W41S10* s, u16 v) { s->a = v; s->b = v; s->c = v; s->d = v; s->e = v; s->f = v; }
void func_00105fc8(void) {
    W41S10 s;
    w41InitS10(&s, 0xffff);
    func_001058e8()[12] = 15;
    s.a = 15;
    func_001058e8()[13] = 0;
    s.b = 0;
    u8* p = func_001058e8();
    u8 v = func_00105f98();
    p[14] = v;
    s.c = v;
    W41VObj* o = func_00102c80();
    o->vt[0](o);
}

// GIF tag (NLOOP=1, EOP, NREG=1, REGS=A+D) followed by one A+D pair (TEXFLUSH).
struct W41GifTag { u64 nloop:15; u64 eop:1; u64 pad:30; u64 pre:1; u64 prim:11; u64 flg:2; u64 nreg:4; u64 r0:4; u64 rr:60; u64 data; u64 addr; };
void func_00109690(u32 a) {
    W41GifTag* t = (W41GifTag*)func_00133ba0(a, 2, 0x13000000);  // forward_sub24_to_1337f0
    *(u128*)t = 0;
    t->nloop = 1;
    t->eop = 1;
    t->nreg = 1;
    t->r0 = 0xe;
    t->addr = 63;
    t->data = 0;
}

// soft-double helpers linked in the game image (float->double, double !=)
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
void func_001168c0(u8* p) {
    if (func_003142e0(func_00313b80(*(f32*)(p + 0x660)), 0.0) != 0 || func_003142e0(func_00313b80(*(f32*)(p + 0x664)), 0.0) != 0)
        *(f32*)(p + 0x65c) = func_002f8ad0(*(f32*)(p + 0x660), -*(f32*)(p + 0x664));
}

void func_00139b28(u32 key) {
    W41Node* n = 0;
    while ((n = w41NextNode(D_00347f80_list, n)) != 0) {
        if (n->key == key) func_00139708(n);
    }
}

void func_0014d478(void) {
    s32 st[8];
    func_00305660(D_00349e40);
    for (W41Sema* e = D_00349e7c; (s32)e < (s32)(D_00349e7c + 2); e++) {
        func_00305690(e->sema, st);
        if (st[3]) func_00305640(e->sema);
    }
}

// 00159130: moved to src/harata/libdk/lightcyclecamera.cpp

W41Ent16* func_00168b88(W41Tbl* t, s32 id, s32 val, s32 k) {  // find_entry16_by_half_word
    for (s32 i = 0; i < t->n; i++) {
        if (id == -1 || t->e[i].id == id) {
            if (t->e[i].val == val) {
                if (--k == -1) return &t->e[i];
            }
        }
    }
    return 0;
}

struct W41SP { u8 pad[72]; u8 flag; };
char* func_0016f4b8(W41SP* p, char* buf) {
    s32 notSet = !(p->flag & 1);
    if (notSet) {
        if (!buf) buf = D_004f63d8;
        func_002fee78(buf, D_0036c450, (u8*)p + 8, D_0033caf0);
        return buf;
    }
    return 0;
}

void func_00173918(u8** p) {
    // function-local static guard + atexit(dtor)
    if (!D_01c5f4f0) {
        D_01c5f4f0 = 1;
        func_002fd188(func_00175540);  // pool_alloc_block
    }
    u8* s = *(u8**)(p[0] + 4) + 2144;
    if ((u128*)s != &D_01c5f500)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&D_01c5f500), "r"(s) : "$8", "memory");
    *p = (u8*)&D_01c5f500;
}

void func_001786e0(u8* p) {
    Vec16 t;
    u8* d = p + 16;
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d) : "memory");
    if (func_002cebb0()) {  // get_global_361f60
        W41VObj2* o = D_00361f60_obj;
        ((void (*)(Vec16*, W41VObj2*, u32))o->vt[9])(&t, o, *(u32*)(p + 0xb38) + 48);
        if (d != (u8*)&t)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&t) : "$8", "memory");
    }
}

}

// 00182d80: moved to src/anon/unit_00182780.cpp

extern "C" {

void func_00198450(u8* p) {
    u8* q = p + 320;
    if (func_00180cd0(q) && func_001805a8(q, 0))
        func_0017f488(q, 0, 0.0f, 0.0f);
    func_00169f98(p);
}

}

void wtarget_00199120(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u8* p = D_01c61b48;
        for (s32 i = 15; i != -1; i--) {
            func_00198dc0(p);
            p += 88;
        }
    }
}

extern "C" {

struct W41S19 { u32 f0; s32 id; u32 res; };
void func_0019d548(W41S19*);
u32 func_0013e610(u32);
extern u32 D_0036d3b8[];
void func_0019d588(W41S19* p, s32 id) {
    if (id != p->id) func_0019d548(p);
    if (id != 0 && p->res == 0) p->res = func_0013e610(D_0036d3b8[id - 1]);
    p->id = id;
}

struct W41BF { u32 lo:3; u32 mode:4; };
void func_001b3b70(u8*, u32, u32, u32);
extern void* D_00350910[];
void func_001a6bc8(u8* p, u32 a, u32 b) {
    func_001b3b70(p, a, 4, b);
    *(void**)p = D_00350910;
    *(u32*)(p + 0x588) |= 0x100;
    *(u32*)(p + 0x3b0) = 3;
    ((W41BF*)(p + 0x600))->mode = 1;
    *(u32*)(p + 0xabc) |= 4;
}

struct W41Rect { u32 f0, x, y; u8 pad[0x50]; u32 w, h, mode; };
void func_001acdc0(W41Rect*, u32, u32, u32, u32, u32);
void func_001acf38(W41Rect* r) {
    u32 dummy;  // dead store after the second call keeps it from being a tail call
    if (r->mode == 2) {
        func_001acdc0(r, r->x, r->y + r->h / 2, r->x + r->w / 2, r->y + r->h, 0);
        return;
    }
    func_001acdc0(r, r->x, r->y, r->x + r->w / 2, r->y + r->h / 2, 0);
    dummy = 0;
}

void func_001bd370(u8*);  // clear_4words_plus2240
void func_001bc720(u8*);
void func_001bd3a0(u8*);
void func_001bdf68(u8*);
void func_001bdff0(void);
void func_001d6da8(u8*);
void func_001bded8(u8* p) {
    func_001bd370(p);  // clear_4words_plus2240
    func_001bc720(p + 36);
    func_001bc720(p + 732);
    *(u32*)(p + 2528) = 0;
    func_001bd3a0(p);
    func_001bdf68(p);
    func_001bdff0();
    func_001d6da8(p + 2642);
    *(u32*)(p + 2728) = 0;
    *(u32*)(p + 2736) = 0;
}

}

// YS::MISSION::WarningComboCounter
struct W41VO { void** vt; u32 f4, f8; u32 flags; };
extern "C" {
u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void WarningComboCounter(s32 i) asm("_ZN2YS7MISSION19WarningComboCounterEi");
void WarningComboCounter(s32 i) {
    u8* e = func_001bbcb0() + i * 64;
    W41VO* o = (W41VO*)(e + 608);
    if (func_001bb4a0()) {
        u32 f = *(u32*)(e + 620);
        if ((u8)(f & 1) && !(f & 8)) ((void (*)(W41VO*))o->vt[3])(o);
    }
}

u32 func_001dba18(u32, u32, u32);
u32 func_001050d8(u32);
void func_001db950(u32, u32, u32, u32);
static inline u32 w41Create(u32 a, u32 b, u32 c) {
    u32 p = func_001050d8(2560);
    func_001db950(p, a, b, c);
    return p;
}
u32 func_001db9a8(u32 a, u32 b, u32 c) {
    u32 r = func_001dba18(a, b, c);
    if (!r) return w41Create(a, b, c);
    return r;
}

extern u32 D_0034e948;
u32 func_0019ba60(u32);
u128* func_0016c028(u32);  // obj_get_attach_or_alt
extern u128 D_01d5bab0;
extern f32 D_00352ad0;
extern f32 D_00349e10;
// 001dbcd0: moved to src/anon/unit_001dbbe0.cpp

void func_001e01b8(void*);
struct W41Own { u8 pad[0x58]; W41Outer* obj; u32 flags; };
void func_001ded98(W41Own* p) {
    NoTail nt;
    if (p->flags & 4) {
        delete p->obj;
    } else if (p->flags & 8) {
        func_001e01b8(p->obj);
    }
}

s32* func_001e3650(u32);  // ptr_add4
void func_001e3898(u32 a, s32 d) {
    s32* v = func_001e3650(a);  // ptr_add4
    for (s32 k = 0; k < 5; k++) {
        s32 n = *v++;
        for (s32 j = 0; j < n; j++) {
            v[0] += d;
            v++;
        }
    }
}

void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_00370bd8[];
extern char D_00370bf8[];
extern char D_00370c10[];
void func_00223448(u32 a, u32 b, u32 c, u32 d) {
    func_002fdfc8(D_00370bd8, a);  // device_vprintf_va
    func_002fdfc8(D_00370bf8, b, c);  // device_vprintf_va
    func_002fdfc8(D_00370c10, d);  // device_vprintf_va
    asm volatile("break");
}

u32 func_0022b9e0(u8*, u32, u32);
void func_001386e0(u8*, u32, u32, u32, u32, u32);
void func_0022b558(u8* p, u32 a, u32 b) {
    func_001386e0(p, 2500, func_0022b9e0(p, a, b), b, a, 11);
    *(f32*)(p + 384) = 1.0f;
}

u32 func_002416d8(u32, u32, u32);
void func_002346f0(s32, u32, u32, u32, u32);
extern s8* D_0035ec94;
extern u32 D_0035ec88;
extern u32 D_0035ec90;
void func_00241608(u32 a, u32 b, u32 c) {
    u32 v = func_002416d8(a, b, c);
    s8* s = D_0035ec94;
    u32 x = b;
    if (!x) x = D_0035ec88;
    u32 y = c;
    if (!y) y = D_0035ec90;
    func_002346f0(*s, x, y, v, 0);
}

struct W41VO2 { void** vt; };
extern u8* D_0035ed04;
u32 func_00139d78(u8*);
void func_00244db8(void) {
    for (s32 i = 0; i < 2; i++) {
        u32 off = i * 408;
        if (func_00139d78(D_0035ed04 + off)) {
            W41VO2* o = (W41VO2*)(off + (u32)D_0035ed04);
            ((void (*)(W41VO2*))o->vt[5])(o);
        }
    }
}

struct W41KV { s16 key, val; };
extern W41KV D_00372c30[];
s32 func_00259510(s32 k) {
    s32 r = 11;
    for (s32 i = 0; D_00372c30[i].key != -1; i++) {
        if (D_00372c30[i].key == k) { r = D_00372c30[i].val; break; }
    }
    return r;
}

u32 func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(u32, u32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f01c;
void func_0027a108(void) {
    u32 o = func_00257770();
    if (func_00287bc0() == 15) {
        func_0028dac8(o, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}

struct W41VA { u32 (**vt)(W41VA*, u32, u32); };
struct W41SysA { u8 pad[0x14]; W41VA* alloc; };
extern W41SysA* D_00347f80_sys asm("D_00347f80");
void func_0028dfe8(u32);  // obj_ctor_36f440
void func_0028b9b0(u32* p) {
    W41VA* a = D_00347f80_sys->alloc;
    u32 v = a->vt[0](a, 60, 0);
    func_0028dfe8(v);  // obj_ctor_36f440
    p[0] = v;
    p[1] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
}

}

// Tz::MenuCursor::DeleteAll
extern "C" {
void DeleteAll(...) asm("_ZN2Tz10MenuCursor9DeleteAllEz");
extern s32 D_0035f404;
extern u32 D_0035f410;
void func_0028cdb8(s32);  // record408_alloc_init
void DeleteAll(...) {
    for (s32 i = 0; i < D_0035f404; i++) func_0028cdb8(i);  // record408_alloc_init
    D_0035f410 = 0;
}

u8* func_00103eb0(void);
u32* func_00102818(u32, u32, u32, void (*)(void), u32);
void func_002933b8(void);
void func_00293350(u32 a, u32 b, u32 c) {
    u32* r = func_00102818(*(u32*)(func_00103eb0() + 4), 0, 0x222e0, func_002933b8, 4096);
    r[1] = a;
    r[2] = b;
    r[3] = c;
}

}

extern "C" {
void func_002b691c(u32);
void func_002bbde0(void);
void func_002bacc0(void);
void func_002b9ad0(void);
void func_002b9c80(void);
void func_002bd538(void);
void func_00102788(u32, u32, u32, void (*)(void));
void func_002b9c60(void);
extern u32 D_0032b91c;
}
void wtarget_002b9bd0(u32, u32, u32, u32) {
    func_002b691c(0);
    func_002bbde0();
    func_002bacc0();
    func_002b9ad0();
    func_002b9c80();
    func_002bd538();
    func_00102788(D_0032b91c, 0, 0x7a12a, func_002b9c60);
}

extern "C" {

void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_002c17d8(u32, u8* p) {
    *(u32*)(p + 264) |= 2;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    f32 z = 0.0f;
    u8* q = p + 320;
    func_0017f488(q, 161, z, z);
    func_0017f5e0(q, 0, 0, z, z);
}

struct W41S24 { u32 w[6]; };
u32 func_002cec08(u32, W41S24*);
bool func_002ceef8(u32, u8* p) {
    u32 d = D_00361f60;
    W41S24* s = (W41S24*)(p + 1856);
    W41S24 t = *s;
    return func_002cec08(d, &t) != 0;
}

extern void* D_00362060[];
extern void* D_0034e8b8[];
extern void* D_0034ee08[];
extern void* D_00362050;
void func_00182f28(u32);  // store_global_35ed04
void func_00319f88(u8*);
void func_0019f9a8(u8*);  // array8_free_slots
void func_001c0248(u8*);
void func_00319fb0(u8*);  // big_obj_dtor
void func_002d0fb0(u8* p) {
    NoTail nt;
    *(void**)p = D_00362060;
    func_00182f28(0);  // store_global_35ed04
    D_00362050 = 0;
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

u8* func_002dc7c8(u8*);
f32 func_002dceb0(u8* p) {
    u8* q = p + 0x8000;
    u8* r = func_002dc7c8(p);
    f32 f = *(f32*)(q + 104) / *(f32*)(r + 160);
    if (f > 1.0f) f = 1.0f;
    if (f < 0.0f) f = 0.0f;
    return f;
}

f32 func_002e4af0(u8*);
void func_002dd2d8(u8* p, f32* a, f32* b) {
    f32 f = (func_002e4af0(p + 256) * 0.5f - 1.0f) * 100.0f;
    *b = f;
    *a = -f;
}

extern void* D_00347e80[];
extern void* D_00347f98[];
struct W41VS { void (**vt)(W41VS*, u8*); };
struct W41SysS { u8 pad[0x14]; W41VS* s; };
extern void* D_00347f80;
void func_002361d0(u8*);
void func_0031ab78(u8* p) {
    *(void**)p = D_00347e80;
    func_002361d0(p + 32);
    *(void**)p = D_00347f98;
    W41VS* s = ((W41SysS*)D_00347f80)->s;
    s->vt[1](s, p);
}

extern void* D_00347e60[];
extern void* D_0034a440[];
void func_0031a838(u8*);
void func_00239700(u8*);
void func_0014b920(u8*);
void func_0031be70(u8* p) {
    *(void**)p = D_00347f98;
    func_0031a838(p + 12);
    *(void**)p = D_00347e60;
    func_00239700(p + 24);
    *(void**)p = D_0034a440;
    *(u32*)(p + 408) = 0;
    func_0014b920(p + 448);
    func_0014b920(p + 480);
}

void func_0031e208(u32, u8* p, u32* flags, u32 v, u8* src) {  // gpr_field_update
    if (*(u64*)(p + 112) & 0x78) return;
    if (*flags & 0x800) {
        u8* d = p + 64;
        *(u16*)(p + 98) = v;
        if (d != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(src) : "$8", "memory");
        asm volatile("" ::: "memory");
    }
    if (*flags & 0x1000) {
        u8* d = p + 80;
        *(u16*)(p + 100) = v;
        if (d != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(src) : "$8", "memory");
    }
}

}
