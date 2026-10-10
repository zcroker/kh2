#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 16-byte vector whose copy constructor is a 128-bit lq/sq (used for by-value passing).
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));

static inline Vq vsub46(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq vsub46n(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void vaddto46(Vq& a, const Vq& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&a), "r"(&b) : "memory");
}
static inline f32 vdot46(const Vq& a, const Vq& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}

struct VObj { void (**vt)(VObj*); };

void func_00239870(void*);
// 380-byte element destroyed by func_00239870 (array new/delete with a 4-byte count cookie).
struct Elem28e {
    u8 d[380];
    ~Elem28e() { func_00239870(this); }
};
void operator delete[](void*) asm("func_00106450");

extern "C" {

void wtarget_0011c828(u8* o, u32 a1, u32, u32) asm("_Z16wtarget_0011c828jjjj");
void wtarget_00160de0(u32 id, u32, u32, u32) asm("_Z16wtarget_00160de0jjjj");
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) asm("_Z16ctarget_001947c0jjjj");
void wtarget_001e0750(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001e0750jjjj");
void ctarget_0028e350(u8* p, u32, u32, u32) asm("_Z16ctarget_0028e350jjjj");
void func_001397d8_i(s32 id) asm("_Z13func_001397d8i");
f32 FixRadian46(f32 x) asm("_ZN2YS4MATH9FixRadianEf");
void Activate46(char*) asm("_ZN2YS4UNIT8ActivateEPc");

// ---- 00106048
struct Col106 { u8 a, b, c; u8 pad; u16 d, e, f; };
u8* func_001058e8(void);
VObj* func_00102c80(void);
void func_00106048(void) {
    Col106 c;
    u16 v = 0xffff;
    c.a = v; c.b = v; c.c = v; c.d = v; c.e = v; c.f = v;
    func_001058e8()[12] = 15; c.a = 15;
    func_001058e8()[13] = 0; c.b = 0;
    func_001058e8()[14] = 0; c.c = 0;
    VObj* o = func_00102c80();
    o->vt[0](o);
}

// ---- 0011c828
struct VObj11c { void (**vt)(VObj11c*, u32, u32); };
s32 func_0011f078(VObj11c*, u32);
void wtarget_0011c828(u8* o, u32 a1, u32, u32) {
    VObj11c* x = *(VObj11c**)(o + 20);
    x->vt[17](x, *(u32*)(o + 260), a1);
    if (func_0011f078(*(VObj11c**)(o + 20), *(u32*)(o + 260)))
        *(u32*)(o + 12) |= 2;
    else
        *(u32*)(o + 12) &= ~2;
}

// ---- 00132ec0
u8* func_00132c68(u8*, u32);
s32 func_001325c8(u8*, u32, u32);
void func_00132ec0(u8* p, u32 id) {
    u8* d = func_00132c68(p, id);
    if (d) {
        s32 i = func_001325c8(p, 0xffff, id);
        if (i >= 0) {
            s32* tbl = (s32*)(d + *(s32*)(d + 0x1c));
            *(u8**)(p + 628) = d + tbl[i];
        }
    }
}

// ---- 001367e0
void func_00168388(u32, u32, u32, u32);
s32 func_00170cd0(void);
void func_00102448(u32, u32);
void func_001367e0(u32 p, u32 a, u32 b) {
    func_00168388(a, b, 0, 0);
    while (func_00170cd0()) func_00102448(p, 0);
}

// ---- 001397d8: call slot 5 of every listed node with this id
struct Node139 { void (**vt)(Node139*); Node139* next; u32 pad[2]; s32 id; };
struct Head139 { u32 pad; Node139* first; };
extern Head139* D_00347f80;
static inline Node139* Next139(Node139* n) {
    Head139* h = D_00347f80;
    if (!n) return h->first;
    return n->next;
}
void func_001397d8_i(s32 id) {
    Node139* n = 0;
    while ((n = Next139(n))) if (n->id == id) n->vt[5](n);
}

// ---- 0013e5a8
s32 func_00139d78(void*);
void func_00139510(void*);
void func_0013e610(u32);
struct O13e { void (**vt)(O13e*); u8 pad[432]; u32 f1b4; u32 pad2[2]; u8 sub[16]; };
static inline void upd13e(u8* s) { if (func_00139d78(s)) func_00139510(s); }
void func_0013e5a8(O13e* p) {
    if (func_00139d78(p)) p->vt[5](p);
    upd13e(p->sub);
    func_0013e610(p->f1b4);
}

// ---- 00143a48
extern u32 D_00348804;
void func_00141c18(u32, u32, u32, u32, u32);
void func_00141ff0(u32, u32, u32, void*, u32);
void func_00143a48(u32 a, u32 b, u32 c) {
    u8 buf[16];
    func_00141c18(D_00348804, 15, 4, 1, 1);
    func_00141ff0(D_00348804, a, b, buf, c);
}

// ---- 00160de0: run func_00160d28 on every listed node with this id
struct Node160 { u8 pad[128]; Node160* next; u8 pad2[292]; u32 id; };
extern Node160* D_004f3b38;
void func_00160d28(Node160*);
static inline Node160* Next160(Node160* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
void wtarget_00160de0(u32 id, u32, u32, u32) {
    Node160* n = 0;
    while ((n = Next160(n))) {
        if (n->id == id) func_00160d28(n);
    }
}

// ---- 00172a80
struct Fl172 { u32 pad; u32 on : 1; };
void func_0019ae60(u8*);
void func_0019a1a0(u8*, u32);
void func_00172a80(u8*** p) {
    Fl172* o = *(Fl172**)((*p)[1] + 2072);
    if (o && !(u8)o->on) {
        func_0019ae60((u8*)o);
        func_0019a1a0((u8*)o, 0);
    }
}

// ---- 0017a418
void func_001d6ae0(u32);
void func_001d6b40(u32);
void func_0017a418(u8* p, s32 m) {
    switch (m) {
    case 1: func_001d6ae0(*(u32*)(p + 2876)); break;
    case 2: func_001d6b40(*(u32*)(p + 2876)); break;
    }
    p[2916] = m;
}

// ---- 0017ce10: wrap an angle into [-pi, pi] (func_002f8b00 = fmodf)
f32 func_002f8b00(f32, f32);  // to_2f9a38
f32 FixRadian46(f32 x) {
    if (0.0f < x) return func_002f8b00(x + 3.1415927f, 6.2831855f) - 3.1415927f;
    return 3.1415927f - func_002f8b00(3.1415927f - x, 6.2831855f);  // to_2f9a38
}

// ---- 0017fef0: move to the new position, accumulating the delta into rot and wrapping rot.w
struct Obj17f { u8 pad[160]; Vq pos; Vq rot; };
Vq func_0017fe10(Obj17f*);
void func_0017fef0(Obj17f* p) {
    Vq t = func_0017fe10(p);
    Vq* rot = &p->rot;
    Vq d = vsub46(t, p->pos);
    vaddto46(*rot, d);
    p->rot.w = FixRadian46(p->rot.w);
    p->pos = t;
}

// ---- 00182f38
struct E182 { u32 a, b, c; };
extern s32 D_0034ed00;
extern E182 D_01c60588[];
void func_0019a308(u32);
void func_00182f38(void) {
    for (s32 i = 0; i < D_0034ed00; i++) func_0019a308(D_01c60588[i].c);
}

// ---- 0018a4d8: do two spheres overlap?
struct Sph18a { u32 pad; f32 r; u32 pad2[2]; Vq c; };
s32 func_0018a4d8(Sph18a* a, Sph18a* b) {
    Vq d;
    d = vsub46n(b->c, a->c);
    f32 dd = vdot46(d, d);
    f32 rr = a->r + b->r;
    return dd < rr * rr;
}

// ---- 001947c0
struct E194 { u16 n; u16 off; };
struct T194 { u32 pad; s32 n; E194 e[1]; };
extern u8 D_0032bae0;
extern T194* D_01c61af0;
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) {
    u8* g = &D_0032bae0;
    if (a < 0) a = g[1];
    if (b < 0) b = g[0];
    if (b >= 0) {
        T194* t = D_01c61af0;
        if (b < t->n && a >= 0 && a < t->e[b].n) return (u8*)t + t->e[b].off + a * 64;
    }
    return 0;
}

// ---- 0019eb60: activate every unit whose bit is set
extern u64 D_0034ecc8;
void func_0015ee90(s32);
void Activate46(char*) {
    for (s32 i = 0; i < 64; i++) {
        if ((u8)((D_0034ecc8 >> i) & 1)) func_0015ee90(i);
    }
}

// ---- 001a81f0: find a free entry matching (a, b, c)
struct E1a8 { u8 pad[4]; u8 used, a, b, c; u8 pad2[4]; };
struct T1a8 { u16 pad; u16 n; E1a8 e[1]; };
extern T1a8* D_01c6cb98;
E1a8* func_001a81f0(u32 a, u32 b, u32 c) {
    s32 i;
    E1a8* e = D_01c6cb98->e;
    for (i = 0; i < D_01c6cb98->n; i++, e++) {
        if (!e->used && e->a == a && e->b == b && e->c == c) return e;
    }
    return 0;
}

// ---- 001b1360
u8* func_001b9bc8(u8*);
void func_001b1360(s32 from, s32 to) {
    u8* o = 0;
    while ((o = func_001b9bc8(o))) {
        if (*(s32*)(o + 1188) == 2 && *(s32*)(o + 1232) == from) *(s32*)(o + 1232) = to;
    }
}

// ---- 001b2380: init a buffer and append it to the global list
struct Buf1b2 { u32 n; u32 f4; u32 f8; u32 fc; f32 f10; void* data; Buf1b2* next; };
struct List1b2 { Buf1b2* head; Buf1b2* tail; };
extern List1b2 D_01d48c80;
void* func_001050d8(u32);
void func_001b2380(Buf1b2* p, u32 n) {
    p->f4 = 0;
    p->n = n;
    p->f10 = 50.0f;
    p->f8 = 0;
    p->fc = 0;
    p->data = func_001050d8(n << 4);
    asm volatile("" ::: "memory");
    if (!D_01d48c80.tail) { D_01d48c80.tail = p; D_01d48c80.head = p; p->next = 0; }
    else { D_01d48c80.tail->next = p; p->next = 0; D_01d48c80.tail = p; }
}

// ---- 001b27f0
Vc func_0017c030(u8*, u32*, u8);
void func_001b6dd0(u8*, Vc);
void func_0017f488(u8*, u32, f32, f32);
void func_001b27f0(u32, u8* p, u8 f) {
    u32 x;
    Vc v = func_0017c030(p, &x, f);
    func_001b6dd0(p, v);
    p[1300] = 4;
    func_0017f488(p + 320, x, 0.0f, 0.0f);
    *(u32*)(p + 256) = 4;
    *(u32*)(p + 260) = 5;
}

// ---- 001cd4c0
s32 func_001bbf00(void);
s32 func_001bb4a0(void);
extern u8 D_00350378;
s32 func_001cd4c0(void) {
    s32 r;
    u8* g = &D_0032bae0;
    if (func_001bbf00()) r = 1;
    else if (*(u16*)(g + 4) < 51 && !D_00350378 && !func_001bb4a0()) r = 1;
    else r = 0;
    return r;
}

// ---- 001df9c8
void func_001dc840(u32);
void func_001dc978(u32, f32);
void func_001df9c8(u8* p) {
    u32 f = *(u32*)(p + 92);
    if (f & 0x20) return;
    *(u32*)(p + 92) = f | 0x20;
    u8* x = *(u8**)(p + 68);
    u32 g = *(u32*)(x + 16);
    if (g & 0x80) func_001dc840(*(u32*)(p + 64));
    else if (g & 0x40) func_001dc978(*(u32*)(p + 64), (f32)x[5]);
}

// ---- 001e0750
extern u8 D_00352b60[];
void func_001e03b0(u8*);
void func_001e03d0(u8*);
void wtarget_001e0750(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) func_001e03b0(D_00352b60);
    if (b == 0xffff && a == 0) func_001e03d0(D_00352b60);
}

// ---- 001fcb18
extern u8* D_01d9e6e8;
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
void func_002f3d08(u8*, u8*, u8*);
void func_002f3f98(u8*, u8*);
void func_001fcb18(u8* p, u32, u8* const q) {
    u8* s = p + *(u32*)(*(u8**)(q + 12) + 4) + 160;
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e840, D_01d9e6e8 + 16);
    func_002f3f98(s, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}

// ---- 002256c8
s32 func_00224e90(u8*, u32);
u32 func_00227870(u32, u8*, u32);
u32 func_00225640(u32, u8*, u32);
extern u32 D_0035db18;
void func_002256c8(u8* p, u32 b) {
    if (func_00224e90(p, b) || D_0035db18 != 0x400000) *(u32*)(p + 20) = func_00227870(b, p, 0);
    else *(u32*)(p + 20) = func_00225640(b, p, 0);
}

// ---- 0022d1d8
s32 func_002282f0(s32);
u32 func_00227ca8(u8*);
void func_0015c958(u32, u32, u32, u32, u32, u32);
void func_0022d1d8(u8* p) {
    if (func_002282f0(*(s16*)(p + 4))) return;
    u32 v = func_00227ca8(p + 8);
    func_0015c958(v, p[12], p[13], p[14], p[6], p[7]);
}

// ---- 0022e0a8
u32 func_001de4b0(u8*, u32, u32);
s32 func_0022e0a8(u8* p) {
    u32 v = 0;
    while ((v = func_001de4b0(p + 16, 0, v))) {
        if (*(u32*)(p + 12) == v) return 1;
    }
    return 0;
}

// ---- 00232498: build "voice/<dir>/event/<name>.vag" in a static buffer
extern char D_01dadbb0[];
extern char D_003712d8[];
extern char D_003712e8[];
u32 func_00232348(char*);
void func_002fee78(char*, char*, u32);
void func_002feee8(char*, char*);
void func_002ff3fc(char*);  // strlen
char* func_00232498(char* name) {
    D_01dadbb0[0] = 0;
    u32 v = func_00232348(name);
    func_002fee78(D_01dadbb0, D_003712d8, v);
    func_002feee8(D_01dadbb0, name);
    func_002feee8(D_01dadbb0, D_003712e8);
    func_002ff3fc(D_01dadbb0);  // strlen
    return D_01dadbb0;
}

// ---- 0024eb50
extern VObj* D_0035ee18[5];
void func_0024eb50(void) {
    for (s32 i = 0; i < 5; i++) {
        if (D_0035ee18[i]) {
            if (func_00139d78(D_0035ee18[i])) D_0035ee18[i]->vt[5](D_0035ee18[i]);
            else D_0035ee18[i] = 0;
        }
    }
}

// ---- 002535d0
extern s8 D_003726c8[];
s32 func_00102fa0(void);
s32 func_002535d0(s32 a) {
    s32 r = -1;
    for (s32 i = 0; D_003726c8[i] >= 0; i++) {
        if (a == D_003726c8[i]) { r = 2; break; }
    }
    if (func_00102fa0()) r = 2;
    return r;
}

// ---- 00263c60
s32 func_00263cc0(void);
void func_00138c10(u8*, s32);
extern s16 D_0035f0d8;
extern u8* D_0035f0dc;
void func_00263c60(void) {  // sync_global_index_if_changed
    if (func_00263cc0()) {
        s16 v = D_0035f0d8;
        if (*(s32*)(D_0035f0dc + 388) != v) {
            func_00138c10(D_0035f0dc, v);
            *(s32*)(D_0035f0dc + 392) = -1;
        }
    }
}

// ---- 0028e350
void ctarget_0028e350(u8* p, u32, u32, u32) {
    if (*(Elem28e**)(p + 56)) {
        delete[] *(Elem28e**)(p + 56);
        *(Elem28e**)(p + 56) = 0;
    }
}

// ---- 00293148
struct E293 { s32 id; u32 on : 1; u32 pad; u32 val; };
extern s32 D_0035f4d0;
extern E293* D_0035f4d4;
u32 func_00293148(s32 id) {
    for (s32 i = 0; i < D_0035f4d0; i++) {
        E293* e = &D_0035f4d4[i];
        if ((u8)e->on && e->id == id) return e->val;
    }
    return 0;
}

// ---- 0029c9d8
s32 func_0028b040(u32);
extern u32 D_0035f200;
extern s32* D_0035f5ac;
s32 func_0029c9d8(s32 n) {
    if (n < 0) n = func_0028b040(D_0035f200);
    s32 m = *D_0035f5ac;
    s32 c = 0;
    s32 i;
    for (i = 0; i < 19; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) break;
            c++;
        }
    }
    return i ? i - 1 : 16;
}

// ---- 002a74c0: is any of the 64 flag bits set?
s32 func_002a74c0(void) {
    u32* bits = (u32*)(func_001058e8() + 18932);
    s32 r = 0;
    for (s32 i = 0; i < 64; i++) {
        if (bits[(u32)i >> 5] & (1 << (i & 31))) { r = 1; break; }
    }
    return r;
}

// ---- 002c6420
u8* func_00106a60(u32);  // buffer_get_by_index
void func_00107368(u8*, u8*);  // vec_copy_at80_if_diff
void func_00107478(u8*, u8*);  // vec_copy_at96_if_diff
u8* func_00106a18(u32);  // buffer_get_256
f32 func_00106f30(u8*, u32);
void func_002c6420(u8* p) {
    *(u32*)(p + 84) = 0;
    u8* v = func_00106a60(1);  // buffer_get_by_index
    func_00107368(v, p + 16);  // vec_copy_at80_if_diff
    func_00107478(v, p + 32);  // vec_copy_at96_if_diff
    f32 f = func_00106f30(func_00106a18(1), 0);
    *(f32*)(p + 80) = f;
    *(u32*)(p + 88) = 0;
}

// ---- 002ceb48: release and delete the global object
struct Obj2ce { void (**vt)(Obj2ce*); u8 pad[92]; u32 f60; };
extern Obj2ce* D_00361f60;
void func_00170950(u32);
void func_002ceb48(void) {
    if (!D_00361f60) return;
    if (D_00361f60->f60) {
        func_00170950(D_00361f60->f60);
        D_00361f60->f60 = 0;
        asm volatile("" ::: "memory");
    }
    if (D_00361f60) D_00361f60->vt[1](D_00361f60);
    D_00361f60 = 0;
}

// ---- 002dd730
void func_001780d8(u8*);
void func_00198860(u8*, u32);
void func_0017a7d8(u8*);
void func_002dd730(u8* p) {
    func_001780d8(p);
    func_00198860(p, 8);
    *(Vq*)(p + 3056) = *(Vq*)(p + 1344);
    func_0017a7d8(p);
    *(f32*)(p + 3072) = 1.0f;
}

// ---- 002e3ce8
extern Vq D_01e2be20;
Vq* func_002cb8b8(u32);
void func_002e3ce8(u8** p) {
    u8* a = *(u8**)(*p + 4);
    if (a && *(u32*)(a + 1288)) {
        D_01e2be20 = *func_002cb8b8(*(u32*)(a + 1288));
        *(Vq**)p = &D_01e2be20;
    }
}

// ---- 002eecd0: destructor body (derived vtable, cleanup, base vtable)
extern u8 D_00363860[];
extern u8 D_003637e0[];
struct VObj2ee { void (**vt)(VObj2ee*, u32, u32); };
VObj2ee* func_001a93e8(u8*);
void func_00106ac8(u8*);
void func_001a9350(u8*);
void func_002eecd0(u8* p) {
    *(u32*)p = (u32)D_00363860;
    VObj2ee* v = func_001a93e8(p + 44);
    v->vt[10](v, *(u32*)(p + 40), *(u32*)(p + 68));
    func_00106ac8(p + 80);
    func_001a9350(p + 44);
    *(u32*)p = (u32)D_003637e0;
}

// ---- 0031e520
s32 func_002ee6d8(u8*);
void func_002edfd8(VObj*, u8*);  // list_unlink_and_clear
s32 func_0031e520(VObj* p) {
    if (func_002ee6d8((u8*)p + 36)) {
        func_002edfd8(p, (u8*)p + 36);  // list_unlink_and_clear
        if (p) p->vt[1](p);
        return 0;
    }
    return 1;
}

}
