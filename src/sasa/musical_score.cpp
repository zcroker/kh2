// sa::MUSICAL_SCORE: the score counters of the musical (Atlantica) minigame (vtables 0x35e168, 0x35e190).
// Linked unit 0x228f18-0x229840.
#include "../common/types.h"

struct AVT228f18 { void* (*alloc)(struct Alc228f18*, u32, u32); };
struct Alc228f18 { AVT228f18* vt; };
struct Mgr228f18 { u8 pad[20]; Alc228f18* a; };

typedef u8* (*AllocFn)(u8*, u32, u32);

extern "C" {
extern Mgr228f18* D_00347f80;
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0035e190[];
extern u8 D_0035e168[];
void func_0031a838(void*);
void func_00239700(void*);
void* func_00224870();
void* func_00224880();
s32 func_00224860(void);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
void func_001386e0(void*, s32, s32, s32, s32, s32);
void func_001396b0(void*);
void func_0031a260(void*, s32);
s32 func_00139d78(void*);
void func_00138c10(void*, s32);
void func_00139660(void*);
void func_00139688(void*);
s32 func_0023aa98(void*);
void func_00138c68(void*, s32, s32);
u8* func_0014aba8(void*);
void func_00139b28(s32);
void func_00139ba0(s32);
void func_001391f0(void*);
void func_00150260(u8*, u32, s32, u32*);
void func_001395a8(u8*);
}
u32 dk_Obj2D_create(void*, s32, s32) asm("_ZN2dk5Obj2D6createEii");

s32 D_0035e070[14] = { 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x3e, 0x3f, 0 };
s32 D_0035e0a8[14] = { 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x4c, 0x4d, 0 };
s32 D_0035e0e0[13] = { 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x30, 0x31 };
s32 D_0035e114[1] __attribute__((aligned(4))) = { 5 };
s32 D_0035e118[6] __attribute__((aligned(4))) = { 1, 5, 9, 13, 17, 0 };
s32 D_0035e130[6] = { 2, 6, 10, 14, 18, 0 };
s32 D_0035e148[6] = { 3, 7, 11, 15, 19, 0 };

struct Nd94 { u8 p0[0x18c]; struct Nd94* parent; s32 x190; u8 p194[4]; };
struct Desc94 { u8 p0[0x2c]; s32 x2c; };
struct Ow94 { u8 p0[0x18]; Nd94 root; Nd94 elems[6]; u8 pad[0xb40 - 0x18 - 408*7]; s32 xb40; s32 xb44; s32 xb48; u32 xb4c; };

void func_002294c8(Ow94* o, s32 n, s32 b, Desc94* d);
void func_00229430(void* a0, s32 a1);
void func_00229830(Ow94* o);

static inline void* w1992_kalloc(u32 n) { Alc228f18* a = D_00347f80->a; return a->vt->alloc(a, n, 0); }
struct B228f18 { u32 vt; u8 pad[8]; u8 m12[12]; B228f18() { vt = (u32)D_00347f98; func_0031a838(m12); } };
struct Sub228f18 : B228f18 { u8 m24[408 - 24]; Sub228f18() { vt = (u32)D_00347e60; func_00239700(m24); } };
struct Mid228f18 : B228f18 { Mid228f18() { vt = (u32)D_0035e190; } };
struct Outer228f18 : Mid228f18 { Sub228f18 subs[7]; u8 tail[20];
  void* operator new(unsigned int n) { return w1992_kalloc(n); } };
struct B0228f18 { u32 vt; u8 pad[8]; u32 f12; u8 pad2[8]; B0228f18() { vt = (u32)D_0035e190; f12 = 0; } };
struct Outer0228f18 : B0228f18 { Sub228f18 subs[7]; u8 tail[20];
  void* operator new(unsigned int n) { return w1992_kalloc(n); } };

void func_00228f18() {
    Outer0228f18* a = new Outer0228f18;
    func_002294c8((Ow94*)a, 3, (s32)func_00224870(), (Desc94*)D_0035e070);
    Outer228f18* b = new Outer228f18;
    func_002294c8((Ow94*)b, 3, (s32)func_00224880(), (Desc94*)D_0035e0a8);
    Outer228f18* c = new Outer228f18;
    func_002294c8((Ow94*)c, 3, (s32)D_0035e114, (Desc94*)D_0035e0e0);
}

struct S229 { u8 pad[392]; s32 f392; u32 f396; u32 f400; };
static inline void init229(S229* s, u32 x, u32 y) { func_001386e0((u8*)s, 2800, x, y, 21, 11); s->f396 = 0; s->f392 = 22; }

void func_00229120(u8* p) {
    func_00229430(p, 2800);
    *(u32*)(p + 2472) = func_00224860();
    u32 x = func_0022b9e0();
    u32 y = func_0022b720();
    S229* s = (S229*)(p + 24);
    init229(s, x, y);
    func_001396b0((u8*)s);
    if (!s->f396) return;
    s->f400 = 0;
    func_001396b0((u8*)s);
    if (!s->f400) return;
    func_0031a260((u8*)s, 0);
}

struct W1572_Obj { u8 pad[388]; s32 id; s32 val; u8 pad2[12]; };
struct W1572_Vt { u8 pad[28]; void (*fn)(void*); };
struct W1572_Mgr { W1572_Vt* vt; u8 pad[428]; W1572_Obj objs[5]; u8 pad3[2472 - 432 - 5 * 408]; s32 cur; };

void func_002291d0(W1572_Mgr* m) {
    m->vt->fn(m);
    s32 v = func_00224860();
    if (m->cur != v) {
        s32 a = func_0022b9e0();
        s32 b = func_0022b720();
        s32 i;
        s32 n = 6 - v;
        i = 1;
        if (i < n) {
            W1572_Obj* o = m->objs;
            s32 j = 0;
            i = n - 1;
            do {
                if (func_00139d78(o) == 0) {
                    func_001386e0(o, 0xaf0, a, b, D_0035e118[j], 11);
                    o->val = D_0035e130[j];
                } else if (o->id == D_0035e148[j]) {
                    func_00138c10(o, D_0035e118[j]);
                    o->val = D_0035e130[j];
                }
                j++; o++;
            } while (--i != 0);
        }
        s32 k;
        for (k = m->cur; k < v; k++) {
            if (k >= 5) break;
            func_00138c10(&m->objs[4 - k], D_0035e148[4 - k]);
        }
    }
    m->cur = v;
}

void func_00229370() {
    u8* h = *(u8**)((u8*)D_00347f80 + 20);
    u8* o = (**(AllocFn**)h)(h, 2476, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_0035e168;
    u8* e = o + 24;
    s32 i = 5;
    do {
        *(u8**)e = D_00347f98;
        func_0031a838(e + 12);
        *(u8**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    } while (--i != -1);
    func_00229120(o);
}

void func_00229430(void* a0, s32 a1) { dk_Obj2D_create(a0, a1, 11); }

void func_00229448(void* a0) {
    u8* p = func_0014aba8(a0);
    if (*(u32*)(p + 252) != 0) {
        func_00139b28(11);
    } else {
        func_00139ba0(11);
    }
    func_001391f0(a0);
}

void func_00229498(u8* p) {
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
    }
}

static inline void setParent_2294c8(Nd94* n, Nd94* p) {
    n->parent = p;
    func_001396b0(n);
    if (n->parent) {
        n->x190 = 0;
        func_001396b0(n);
        if (n->x190) func_0031a260(n, 0);
    }
}

void func_002294c8(Ow94* o, s32 n, s32 b, Desc94* d) {
    s32 i = 0;
    s32 r1 = func_0022b9e0();
    s32 r2 = func_0022b720();
    o->xb48 = n;
    o->xb40 = b;
    o->xb4c = (u32)d;
    func_001386e0(&o->root, 2800, r1, r2, d->x2c, 11);
    s32 k = o->xb48 - 1;
    for (; i < o->xb48; i++, k--) {
        Nd94* e = &o->elems[i];
        func_001386e0(e, 2800, r1, r2, *(s32*)o->xb4c, 11);
        setParent_2294c8(e, &o->root);
        func_001396b0(e);
        func_00139660(e);
        func_00139688(e);
        func_00138c68(e, k * func_0023aa98((u8*)o + 456), 0);
    }
    func_00229430(o, 2800);
    setParent_2294c8(&o->root, 0);
    func_00229830(o);
    o->xb44 = -1;
}

namespace dk { struct Sprite; }
namespace sa {
struct MUSICAL_SCORE { void setBaseParent(dk::Sprite*, int); };

void MUSICAL_SCORE::setBaseParent(dk::Sprite* parent, int base) {
    u8* self = (u8*)this;
    u8* s = self + 24;
    *(dk::Sprite**)(s + 396) = parent;
    func_001396b0(s);
    if (*(u32*)(s + 396) != 0) {
        *(u32*)(s + 400) = 0;
        func_001396b0(s);
        if (*(u32*)(s + 400) != 0) {
            func_0031a260(s, 0);
        }
    }
    *(s32*)(self + 2896) = base;
    *(u8**)(self + 2880) = self + 2896;
}
}  // namespace sa

void func_002296f8(u8* p) {
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
    }
}

void func_00229728(u8* o) {
    u32 buf[6];
    s32 i;
    s32 j;
    u32 cur = **(u32**)(o + 2880);
    if (*(u32*)(o + 2884) != cur) {
        func_00150260(*(u8**)(o + 2892), cur, 6, buf);
        for (i = *(s32*)(o + 2888) - 1; i >= 0; i--) {
            u8* e = o + 432 + i * 408;
            func_00138c10(e, buf[i]);
            func_001395a8(e);
        }
        for (j = *(s32*)(o + 2888) - 1; j > 0; j--) {
            u8* t = *(u8**)(o + 2892);
            if (buf[j] != *(u32*)t) break;
            func_00138c10(o + 432 + j * 408, *(u32*)(t + 40));
        }
    }
    *(u32*)(o + 2884) = cur;
}

void func_00229830(Ow94* o) {
    *(u32*)((u8*)o + 416) = *(u32*)(o->xb4c + 48);
}
