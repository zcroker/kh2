// dk::BgObj (0x15f7f0-0x1610c0; the file goes on in unit_001611a8.cpp): the map's background objects. A small derived class (ctor
// C2/C1 0x15f7f0/0x15f8d8, empty draw 0x15f9c0) and dk::BgObj itself: ctor C2/C1, dtor D2/D1/D0,
// motion, bounding box, colour, the exec/draw/destroy tasks, the object lists (all objects,
// the draw list, the destroy list), show/hide by group or number. The unwritten re-light loop
// 0x1610c0 stays outside: its colour stores schedule differently here.
// Each matched function keeps the struct view it was matched with (one namespace per view);
// every symbol is bound by asm label. The vtables (0x34c718, 0x34c748) stay retail data.
#include "../../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")

// ---- file globals

s32 D_0034c738 asm("D_0034c738");     // the allocator (dk::BgObj::init)
s32 D_0034c73c asm("D_0034c73c");     // the map file
u8 D_0034c740 asm("D_0034c740");
// The object lists (static, .bss 0x4f3b30) are defined in unit_001611a8.cpp with the static init.

// ---- 16-byte vector with a qword copy
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// ---- derived object ctor (C2 0x15f7f0, C1 0x15f8d8)
namespace n0015f8d8 {
extern u8 D_0034c720[] asm("D_0034c720");
void func_0015f9c8(u8*, u32, u32, QWord, QWord, QWord, u32, s32, u32, u32, u32) asm("func_0015f9c8");
void func_001433c0(u8*, u32) asm("func_001433c0");
void func_0015f7f0(u8* o, u32 a1, const QWord& a, const QWord& b, const QWord& c, u32 t1, u32 t2) asm("func_0015f7f0");
void func_0015f8d8(u8* o, u32 a1, const QWord& a, const QWord& b, const QWord& c, u32 t1, u32 t2) asm("func_0015f8d8");
void func_0015f7f0(u8* o, u32 a1, const QWord& a, const QWord& b, const QWord& c, u32 t1, u32 t2) {
    func_0015f9c8(o, 0, a1, a, b, c, t1, -1, 0, 0, 0);
    *(u32*)o = (u32)D_0034c720;
    if (!t2) {
        *(u32*)(o + 456) |= 2;
        o[466] = 0x80;
        o[465] = 0x80;
        o[464] = 0x80;
        o[467] = 0xff;
    }
    func_001433c0(o + 448, t2);
    *(u32*)(o + 500) = 0;
    *(u32*)(o + 432) = 1;
    *(u32*)(o + 696) &= ~0x80;
    *(u32*)(o + 696) &= ~0x100;
}
void func_0015f8d8(u8* o, u32 a1, const QWord& a, const QWord& b, const QWord& c, u32 t1, u32 t2) {
    func_0015f9c8(o, 0, a1, a, b, c, t1, -1, 0, 0, 0);
    *(u32*)o = (u32)D_0034c720;
    if (!t2) {
        *(u32*)(o + 456) |= 2;
        o[466] = 0x80;
        o[465] = 0x80;
        o[464] = 0x80;
        o[467] = 0xff;
    }
    func_001433c0(o + 448, t2);
    *(u32*)(o + 500) = 0;
    *(u32*)(o + 432) = 1;
    *(u32*)(o + 696) &= ~0x80;
    *(u32*)(o + 696) &= ~0x100;
}
// The derived class's draw: nothing.
void func_0015f9c0(void) asm("func_0015f9c0");
void func_0015f9c0(void) {}
}

// ---- dk::BgObj ctor (C2 0x15f9c8, C1 0x15fe18)
namespace w3841 {
struct Mtx {
    QWord r[4];
    Mtx() {}
    Mtx(const Mtx& o) { MCOPY(this, &o); }
    Mtx& operator=(const Mtx& o) {
        if (this != &o) MCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Light {
    QWord dir;
    QWord neg;
    u8 rgb[4];
    u32 mask;
    u32 a, b, c;
    u8 d;
    Light() { mask = 0xffff; a = 0; b = 0; c = 0; d = 0; }
};

#define LIGHT_INIT(l) do { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&(l).dir) : "memory"); \
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(&(l).neg), "r"(&(l).dir) : "memory"); } while (0)
struct Box { QWord a, b; };
struct Ent { u32 mask; u8 c[4]; };
struct Model;
struct ModelVt { void* f[16]; };
struct Model { ModelVt* vt; s32* p4; };

struct Obj;
struct ObjList { Obj* head; Obj* tail; };

struct Obj {
    void* vt;               // 0
    Model* model;           // 4
    u8 pad8[8];
    Mtx mtx;                // 16
    QWord pos;              // 80
    QWord rot;              // 96
    QWord scale;            // 112
    Obj* next;              // 128
    u8 pad132[12];
    u8 bound[128];          // 144
    u8 sub[112];            // 272
    u32 f384;               // 384
    Ent ent[4];             // 388
    u8 pad420[0];
    struct Col { u32 r:8; u32 g:8; u32 b:8; u32 a:8; } color; // 420
    u32 f424, f428, f432;   // 424
    u8 pad436[12];
    void* gfx;              // 448
    u8 pad452[4];
    u32 f456;               // 456
    u8 pad460[32];
    u32 f492;               // 492
    u8 pad496[4];
    Ent* ents;              // 500
    u8 pad504[8];
    Mtx mtx2;               // 512
    Mtx pad576;
    QWord pos2;             // 640
    u8 pad656[40];
    u32 flags;              // 696
    void* pbound;           // 700
    u8 pad704[20];
    u32 f724;               // 724
};

extern u8 D_0034c750[] asm("D_0034c750");
extern void* D_0034c73c asm("D_0034c73c");
extern void* D_0034c738 asm("D_0034c738");
extern ObjList D_004f3b38 asm("D_004f3b38");
void func_001614e8(void*, Obj*) asm("func_001614e8");
void func_0031e158(void*) asm("func_0031e158");
Model* func_00149308(void*, u32) asm("func_00149308");
u32 func_00149320(void*, u32) asm("func_00149320");
void* func_00149338(void*, u32) asm("func_00149338");
void func_0011e260(void*, u32) asm("func_0011e260");
void func_001604f8(Obj*) asm("func_001604f8");
void func_001444c8(Box*, QWord*, QWord*) asm("func_001444c8");
void func_00144be0(Box*, void*) asm("func_00144be0");
void func_001605a0(Obj*, Mtx) asm("func_001605a0");
void func_00143348(void*) asm("func_00143348");
void func_0011eb08(void*, s32) asm("func_0011eb08");
void func_0011e880(void*, s32, s32, s32) asm("func_0011e880");
void func_001608c0(Obj*) asm("func_001608c0");
void func_00143520(QWord*, Light*) asm("func_00143520");
void func_00160488(Obj*, s32, s32, s32) asm("func_00160488");
void func_00161540(void*, void*) asm("func_00161540");
void func_001615e8(void*, s32, f32) asm("func_001615e8");
void func_00160ac0(Obj*, u32) asm("func_00160ac0");

static inline void SetColor(Obj::Col& c, u32 r, u32 g, u32 b, u32 a) { c.r = r; c.g = g; c.b = b; c.a = a; }

void func_0015f9c8(Obj* o, u32 a1, u32 kind, QWord pos, QWord rot, QWord scale, u32 t2, s32 t3, s32 a8, u32 a9, u32 a10) asm("func_0015f9c8");
void func_0015fe18(Obj* o, u32 a1, u32 kind, QWord pos, QWord rot, QWord scale, u32 t2, s32 t3, s32 a8, u32 a9, u32 a10) asm("func_0015fe18");

// Model-object constructor (vtable D_0034c750): copies pos/rot/scale, binds the model of `kind`, sets up
// bounds, colour, optional light and effect, then appends the object to the list at D_004f3b38.
void func_0015f9c8(Obj* o, u32 a1, u32 kind, QWord pos, QWord rot, QWord scale, u32 t2, s32 t3, s32 a8, u32 a9, u32 a10)
{
    *(u32*)o = (u32)D_0034c750;
    QCOPY(&o->pos, &pos);
    QCOPY(&o->rot, &rot);
    QCOPY(&o->scale, &scale);
    func_001614e8(o->sub, o);
    o->f384 = 0;
    {
        // Pinned to t6 so cse2 cannot share this 128 with the light alpha below (the original keeps two SImode li 128).
        register u32 c asm("$14") = 128;
        Obj::Col& k = o->color;
        k.r = c; k.g = c; k.b = c; k.a = c;
    }
    o->f424 = a9;
    o->f428 = a10;
    o->f432 = 0;
    func_0031e158(&o->gfx);
    o->model = func_00149308(D_0034c73c, kind);
    o->gfx = ((void* (*)(Model*, void*))o->model->vt->f[9])(o->model, D_0034c738);
    func_0011e260(o->gfx, func_00149320(D_0034c73c, kind));
    o->f492 = func_00149320(D_0034c73c, kind);
    func_001604f8(o);
    o->mtx2 = o->mtx;
    o->pos2 = o->pos;
    QWord mn, mx;
    Box box;
    {
        ((void (*)(Model*, QWord*, QWord*))o->model->vt->f[4])(o->model, &mn, &mx);
        func_001444c8(&box, &mn, &mx);
        o->pbound = o->bound;
        func_00144be0(&box, o->bound);
    }
    func_001605a0(o, o->mtx);
    func_00143348(&o->gfx);
    o->flags = (o->flags & ~8) | 0x20;
    func_0011eb08(o->gfx, 0);
    func_0011e880(o->gfx, 2, 0, 0);
    if ((u8)(a10 & 1)) {
        o->flags |= 1;
        func_001608c0(o);
    }
    if (__builtin_expect(a10 & 2, 0)) {
        Light l; LIGHT_INIT(l);
        func_00143520(&o->pos, &l);
        SetColor(o->color, l.rgb[0], l.rgb[1], l.rgb[2], 128);
        func_00160488(o, 128, 128, 128);
    }
    if (o->scale.f[0] * o->scale.f[1] * o->scale.f[2] < 0.0f) o->f456 |= 8;
    if (t3 != -1) {
        void* e = func_00149338(D_0034c73c, kind);
        if (e) {
            o->f384 |= 2;
            func_00161540(o->sub, e);
            func_001615e8(o->sub, t3, (f32)a8 * 2.0f);
        }
    }
    Model* m = o->model;
    if (*m->p4 == -1) {
        o->f724 = a1;
        o->flags |= 0x80;
    }
    o->ents = 0;
    if (((u32 (*)(Model*))m->vt->f[14])(m) & ~1) {
        o->f724 = a1;
        o->flags |= 0x100;
        o->ents = o->ent;
        for (s32 i = 0; i < 4; i++) {
            o->ent[i].mask = 1 << (i + 1);
            o->ent[i].c[0] = 0x80;
            o->ent[i].c[1] = 0x80;
            o->ent[i].c[2] = 0x80;
            o->ent[i].c[3] = 0x80;
        }
        o->ent[3].mask = 0;
    }
    ObjList* L = &D_004f3b38;
    if (!L->tail) {
        L->tail = o;
        L->head = o;
        o->next = 0;
    } else {
        L->tail->next = o;
        o->next = 0;
        L->tail = o;
    }
    func_00160ac0(o, t2);
}

void func_0015fe18(Obj* o, u32 a1, u32 kind, QWord pos, QWord rot, QWord scale, u32 t2, s32 t3, s32 a8, u32 a9, u32 a10)
{
    *(u32*)o = (u32)D_0034c750;
    QCOPY(&o->pos, &pos);
    QCOPY(&o->rot, &rot);
    QCOPY(&o->scale, &scale);
    func_001614e8(o->sub, o);
    o->f384 = 0;
    {
        register u32 c asm("$14") = 128;
        Obj::Col& k = o->color;
        k.r = c; k.g = c; k.b = c; k.a = c;
    }
    o->f424 = a9;
    o->f428 = a10;
    o->f432 = 0;
    func_0031e158(&o->gfx);
    o->model = func_00149308(D_0034c73c, kind);
    o->gfx = ((void* (*)(Model*, void*))o->model->vt->f[9])(o->model, D_0034c738);
    func_0011e260(o->gfx, func_00149320(D_0034c73c, kind));
    o->f492 = func_00149320(D_0034c73c, kind);
    func_001604f8(o);
    o->mtx2 = o->mtx;
    o->pos2 = o->pos;
    QWord mn, mx;
    Box box;
    {
        ((void (*)(Model*, QWord*, QWord*))o->model->vt->f[4])(o->model, &mn, &mx);
        func_001444c8(&box, &mn, &mx);
        o->pbound = o->bound;
        func_00144be0(&box, o->bound);
    }
    func_001605a0(o, o->mtx);
    func_00143348(&o->gfx);
    o->flags = (o->flags & ~8) | 0x20;
    func_0011eb08(o->gfx, 0);
    func_0011e880(o->gfx, 2, 0, 0);
    if ((u8)(a10 & 1)) {
        o->flags |= 1;
        func_001608c0(o);
    }
    if (__builtin_expect(a10 & 2, 0)) {
        Light l; LIGHT_INIT(l);
        func_00143520(&o->pos, &l);
        SetColor(o->color, l.rgb[0], l.rgb[1], l.rgb[2], 128);
        func_00160488(o, 128, 128, 128);
    }
    if (o->scale.f[0] * o->scale.f[1] * o->scale.f[2] < 0.0f) o->f456 |= 8;
    if (t3 != -1) {
        void* e = func_00149338(D_0034c73c, kind);
        if (e) {
            o->f384 |= 2;
            func_00161540(o->sub, e);
            func_001615e8(o->sub, t3, (f32)a8 * 2.0f);
        }
    }
    Model* m = o->model;
    if (*m->p4 == -1) {
        o->f724 = a1;
        o->flags |= 0x80;
    }
    o->ents = 0;
    if (((u32 (*)(Model*))m->vt->f[14])(m) & ~1) {
        o->f724 = a1;
        o->flags |= 0x100;
        o->ents = o->ent;
        for (s32 i = 0; i < 4; i++) {
            o->ent[i].mask = 1 << (i + 1);
            o->ent[i].c[0] = 0x80;
            o->ent[i].c[1] = 0x80;
            o->ent[i].c[2] = 0x80;
            o->ent[i].c[3] = 0x80;
        }
        o->ent[3].mask = 0;
    }
    ObjList* L = &D_004f3b38;
    if (!L->tail) {
        L->tail = o;
        L->head = o;
        o->next = 0;
    } else {
        L->tail->next = o;
        o->next = 0;
        L->tail = o;
    }
    func_00160ac0(o, t2);
}
}

// ---- dk::BgObj dtor: D2 0x160268, D1 0x1602f8, D0 0x160388
namespace w57 {
void func_00161530(void*) asm("func_00161530");
extern u8 D_0034c750 asm("D_0034c750");
extern u8 D_0034c738 asm("D_0034c738");
struct E16 { u8 d[16]; ~E16() {} };
struct M272 { u8 d[8]; ~M272() { func_00161530(this); } };
typedef void (*VF160)(void*, void*, u32);
struct C160 {
    void* vt; void** owner; u8 p[0x88]; E16 arr[8]; M272 m;
    ~C160() {
        vt = &D_0034c750;
        (*(VF160*)((u8*)*owner + 40))(owner, *(void**)&D_0034c738, *(u32*)((u8*)this + 448));
    }
};
void func_00160268(C160* t) asm("func_00160268");
void func_00160268(C160* t) { t->~C160(); }
}

namespace w1771 {
extern u8 D_0034c750[] asm("D_0034c750");
extern s32 D_0034c738 asm("D_0034c738");
void func_00161530(void*) asm("func_00161530");
struct I1602 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void fa(s32, s32); };
struct E1602 { u8 pad[16]; ~E1602() {} } __attribute__((aligned(16)));
struct M1602 { u8 pad[16]; ~M1602() { func_00161530(this); } };
struct O1602 {
    u32 vt; I1602* x; u8 pad[0x88]; E1602 arr[8]; M1602 m; u8 pad2[0xa0]; s32 v;
    ~O1602() { vt = (u32)D_0034c750; x->fa(D_0034c738, v); }
};
void func_001602f8(O1602* o) asm("func_001602f8");
void func_001602f8(O1602* o) { o->~O1602(); }
}

namespace w1780 {
struct Alloc;
struct AllocVt { void* a; void (*free)(Alloc*, void*); };
struct Alloc { AllocVt* vt; };
extern Alloc* D_0034c738 asm("D_0034c738");
extern u8 D_0034c750[] asm("D_0034c750");
struct Mgr;
struct MgrVt { void* s[10]; void (*rel)(Mgr*, Alloc*, u32); };
struct Mgr { MgrVt* vt; };
void func_00161530(void*) asm("func_00161530");
struct __attribute__((aligned(16))) V16 { u32 x[4]; ~V16() {} };
struct Obj {
    u32 vt; Mgr* mgr; u8 pad[0x88]; V16 arr[8]; u8 m110[0xb0]; u32 h1c0;
};

void func_00160388(Obj* o) asm("func_00160388");
void func_00160388(Obj* o) {
    o->vt = (u32)D_0034c750;
    Mgr* m = o->mgr; m->vt->rel(m, D_0034c738, o->h1c0);
    func_00161530(o->m110);
    if (o->arr) {
        V16* p = o->arr + 8;
        for (;;) { p->~V16(); if (o->arr == p) break; --p; }  // gcc pads this empty dtor loop with nops
    }
    D_0034c738->vt->free(D_0034c738, o);
}
}

// ---- motion / colour
namespace w1752 {
void func_00161598(void*) asm("func_00161598");
void func_00161668(void*, f32) asm("func_00161668");
void func_0011ea40(f32, u32) asm("func_0011ea40");
extern f32 D_00349e10 asm("D_00349e10");

void func_00160430(u8* p) asm("func_00160430");
void func_00160430(u8* p) {
    func_00161598(p + 0x110);
    func_00161668(p + 0x110, D_00349e10);
    func_0011ea40(D_00349e10, *(u32*)(p + 0x1c0));
}
}

namespace w35 {
// Scales the base colour at +420 by (r, g, b)/128 into +680.
void func_00160488(u8* p, u8 r, u8 g, u8 b) asm("func_00160488");
void func_00160488(u8* p, u8 r, u8 g, u8 b) {
    u8 out[3];
    u8* c = p + 420;
    out[0] = (r * c[0]) >> 7;
    out[1] = (g * c[1]) >> 7;
    out[2] = (b * c[2]) >> 7;
    p[680] = out[0];
    p[681] = out[1];
    p[682] = out[2];
}
}

namespace tw {
u32 func_00161538(u32, u32, u32, u32) asm("func_00161538");
u32 func_0011e9a8(u32, u32, u32, u32) asm("func_0011e9a8");
u32 func_001604d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001604d8");
u32 func_001604d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00161538(((u32)(a0) + 272u), a1, a2, a3);
}
void func_001604f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001604f0");
void func_001604f0(u32 a0, u32 a1, u32 a2, u32 a3) {}
}

namespace w75_h2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
static inline void VCopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
void func_0011b6a8(M4*) asm("func_0011b6a8");
M4* func_0011b7b0(M4*, u8*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_001604f8(u8* p) asm("func_001604f8");
void func_001604f8(u8* p)
{
    M4* m = (M4*)(p + 16);
    func_0011b6a8(m);
    VCopyM(m, func_0011b7b0(m, p + 96));
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(p + 80) : "memory");
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(m), "r"(p + 112) : "memory");
}
}

namespace w1877 {
#define QCOPY1877(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1877 {
    f32 x, y, z, w;
    QV1877() {}
    QV1877(const QV1877& o) { QCOPY1877(this, &o); }
    QV1877& operator=(const QV1877& o) { if (this != &o) QCOPY1877(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1877 {
    QV1877 r[4];
    QV1877 operator*(const QV1877& v) const {
        QV1877 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Box1877 { u8 pad[0x90]; QV1877 c[8]; u8 pad2[0x290 - 0x110]; u8 box[1]; };
void func_001447e0(void*, QV1877*, QV1877*) asm("func_001447e0");

// Transform the 8 box corners in place and compute their min/max.
void func_001605a0(Box1877* self, QM1877* m) asm("func_001605a0");
void func_001605a0(Box1877* self, QM1877* m) {
    QV1877 mn, mx, p;
    for (s32 i = 0; i < 8; i++) {
        self->c[i] = *m * self->c[i];
        p = self->c[i];
        if (i == 0) {
            mn = mx = p;
        } else {
            if (p.x < mn.x) mn.x = p.x; else if (mx.x < p.x) mx.x = p.x;
            if (p.y < mn.y) mn.y = p.y; else if (mx.y < p.y) mx.y = p.y;
            if (p.z < mn.z) mn.z = p.z; else if (mx.z < p.z) mx.z = p.z;
        }
    }
    func_001447e0(self->box, &mn, &mx);
}
}

namespace w295 {
#define QCOPY295(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY295(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY295(this, &o); }
    QWord& operator=(const QWord& o) { if (this != &o) QCOPY295(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat(const QMat& o) { MCOPY295(this, &o); }
    QMat& operator=(const QMat& o) { if (this != &o) MCOPY295(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void ScaleIn2(QWord& d, QWord& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&v), "f"(s) : "$8", "memory");
}
static inline void ScaleIn(QWord& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
static inline void MulIn(QMat& a, QMat& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
        "lqc2 $vf5, 0(%1)\n\tlqc2 $vf6, 16(%1)\n\tlqc2 $vf7, 32(%1)\n\tlqc2 $vf8, 48(%1)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&a), "r"(&b) : "memory");
}
struct Box { QWord mn, mx; };
struct Src;
typedef f32 (*SF)(Src*);
struct Src { SF* vt; };
struct Ob { u32 w0; Src* src; u8 p8[8]; QMat m16; u8 p80[64]; QMat m144; u8 p208[64]; QMat m272; u8 p336[20]; f32 f[6]; u8 p380[260]; QWord v640; };
void bx_init(Box*) asm("_ZN2dk6Aabbox4initEv");
void bx_set(Box*, f32, f32, f32, f32, f32, f32) asm("_ZN2dk6Aabbox3setEffffff");
void func_00144b38(Box*, QMat*) asm("func_00144b38");
void func_001605a0(Ob*, QMat) asm("func_001605a0");
// Motion bounding box: the world matrix with y/z flipped times the motion matrix, padded by the radius.
void func_001606e0(Ob* o) asm("func_001606e0");
void func_001606e0(Ob* o) {
    Box b;
    bx_init(&b);
    QMat m;
    QWord& r1 = m.r[1]; QWord& r2 = m.r[2]; QWord& r3 = m.r[3];
    m = o->m16;
    f32 k = -1.0f;
    ScaleIn2(r1, r1, k);
    ScaleIn(r2, k);
    { QMat n = o->m272; MulIn(m, n); }
    o->v640 = r3;
    f32* f = o->f;
    f32 d = o->src->vt[3](o->src);
    bx_set(&b, f[0] - d, f[1] - d, f[2] - d, f[3] + d, f[4] + d, f[5] + d);
    func_00144b38(&b, &o->m144);
    func_001605a0(o, m);
}
}

namespace w60 {
void func_00144908(void*, void*) asm("func_00144908");
void* func_0016b0d0(void) asm("func_0016b0d0");
f32* func_0016c028(void*) asm("func_0016c028");
void func_001608c0(u8* p) asm("func_001608c0");
void func_001608c0(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_00144908(p + 656, tmp);
    if (p + 640 != (u8*)tmp) QCOPY(p + 640, tmp);
    void* r = func_0016b0d0();
    if (r) {
        f32 y = func_0016c028(r)[1];
        if (*(f32*)(p + 660) <= y && y <= *(f32*)(p + 672)) *(f32*)(p + 644) = y;
    }
}
}

namespace tw2 {
u32 func_0011e9a8(u32, u32, u32, u32) asm("func_0011e9a8");
u32 func_00160940(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00160940");
u32 func_00160940(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0011e9a8(((u32)(*(u32*)((u32)(a0) + 448u))), a1, 0x00000000u, 0x00000000u);
}
}

namespace a80 {
void func_001606e0(void*) asm("func_001606e0");
void func_001608c0(void*) asm("func_001608c0");
void func_00143398(void*) asm("func_00143398");
void func_00143328(void*) asm("func_00143328");
void func_00160960(u8* a0) asm("func_00160960");
void func_00160960(u8* a0) {
    if ((*(u32*)(a0 + 384) & 2u) != 0u) {
        func_001606e0(a0);
        u32 t = *(u32*)(a0 + 696) & 1u;
        if (t != 0u) {
            func_001608c0(a0);
        }
        return func_00143398(a0 + 448);
    }

    u32 t = *(u32*)(a0 + 696) & 1u;
    if (t != 0u) {
        func_001608c0(a0);
    }
    return func_00143328(a0 + 448);
}
}

// ---- tasks
namespace task {
struct Obj;
struct ObjVt { void (*f0)(Obj*); void (*f1)(Obj*); };
struct Obj { ObjVt* vt; u8 p4[124]; Obj* next; Obj* dnext; u8 p136[248]; u32 f384; };
struct TASK { u8 p0[4]; Obj* obj; };
struct List { Obj* head; Obj* tail; };
extern List D_004f3b40 asm("D_004f3b40");
extern u32 D_0034f240 asm("D_0034f240");
extern u8 D_0034c740 asm("D_0034c740");
void func_001024a8(TASK*) asm("func_001024a8");
void func_00160d18(Obj*) asm("func_00160d18");

// Exec task: a stopped object ends its task; otherwise move and animate it (unless paused)
// and put it on the draw list.
void func_001609e0(TASK* t) asm("func_001609e0");
void func_001609e0(TASK* t) {
    Obj* o = t->obj;
    if ((o->f384 & 1) == 1) {
        func_001024a8(t);
        return;
    }
    if (!(D_0034f240 & 0x20) && !D_0034c740) {
        o->vt->f0(o);
        o->vt->f1(o);
    }
    List* l = &D_004f3b40;
    if (!l->tail) {
        l->tail = o;
        l->head = o;
        o->dnext = 0;
    } else {
        l->tail->dnext = o;
        o->dnext = 0;
        l->tail = o;
    }
}

// Exec task finalizer: stop the object.
void func_00160a90(TASK* t) asm("func_00160a90");
void func_00160a90(TASK* t) {
    Obj* o = t->obj;
    if ((o->f384 & 1) == 0) func_00160d18(o);
}
}

namespace w50 {
void* func_00102788(void*, s32, u32, void*) asm("func_00102788");
void func_001609e0(void) asm("func_001609e0");
void func_00160a90(void) asm("func_00160a90");
extern void* D_004f3b30 asm("D_004f3b30");
void func_00160ac0(u32 a, u32 b) asm("func_00160ac0");
void func_00160ac0(u32 a, u32 b) {
    u8* v = (u8*)func_00102788(D_004f3b30, 0, b, (void*)func_001609e0);
    *(u32*)(v + 4) = a;
    *(void**)(v + 48) = (void*)func_00160a90;
}
}

namespace w37 {
struct Obj160 { void** vt; u8 _4[128]; Obj160* next; u8 _88[248]; u32 flags; };
struct L160 { Obj160* head; u32 tail; };
extern L160 D_004f3b40 asm("D_004f3b40");
typedef void (*VFn0)(void*);
static inline Obj160* nx160b(Obj160* o) { return !o ? D_004f3b40.head : o->next; }
// Draw task: draw every object on the draw list, then empty it.
void func_00160b10(void) asm("func_00160b10");
void func_00160b10(void) {
    Obj160* o = 0;
    while ((o = nx160b(o)) != 0) {
        if (!(o->flags & 4)) ((VFn0)o->vt[2])(o);
    }
    D_004f3b40.head = 0;
    D_004f3b40.tail = 0;
}
}

namespace task2 {
struct List { void* head; void* tail; };
extern List D_004f3b40 asm("D_004f3b40");
extern s32 D_004f3b30 asm("D_004f3b30");
void func_001029e8(s32) asm("func_001029e8");
void func_00102750(s32) asm("func_00102750");
void func_00160b88(void) asm("func_00160b88");
void func_00160b88(void) {
    List* l = &D_004f3b40;
    l->head = 0;
    l->tail = 0;
    func_001029e8(D_004f3b30);
}
void func_00160bb8(void) asm("func_00160bb8");
void func_00160bb8(void) { func_00102750(D_004f3b30); }
}

namespace w1673 {
struct O160bd8 { void** vt; u8 pad[0x7c]; O160bd8* next; u8 pad2[0xfc]; u32 flags : 1; };
struct L160bd8 { O160bd8* head; O160bd8* tail; };
extern L160bd8 D_004f3b38 asm("D_004f3b38");
extern L160bd8 D_004f3b48 asm("D_004f3b48");
// Destroy task: delete the objects on the destroy list, then move the stopped ones there.
void func_00160bd8() asm("func_00160bd8");
void func_00160bd8() {
    O160bd8* p = D_004f3b48.head;
    while (p) {
        O160bd8* n = p->next;
        if (p) ((void (*)(O160bd8*))p->vt[4])(p);
        p = n;
    }
    D_004f3b48.head = 0;
    D_004f3b48.tail = 0;
    for (p = D_004f3b38.head; p; ) {
        O160bd8* n = p->next;
        if (p->flags) {
            asm volatile("" ::: "memory");
            O160bd8* prev;
            if (p == D_004f3b38.head) {
                prev = 0;
                D_004f3b38.head = p->next;
            } else {
                prev = D_004f3b38.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_004f3b38.tail) D_004f3b38.tail = prev;
            p->next = 0;
            if (!D_004f3b48.tail) {
                D_004f3b48.tail = p;
                D_004f3b48.head = p;
                p->next = 0;
            } else {
                D_004f3b48.tail->next = p;
                p->next = 0;
                D_004f3b48.tail = p;
            }
        }
        p = n;
    }
}
// Destroy task finalizer: run it twice (the second pass deletes what the first one moved).
void func_00160cf0(void* t) asm("func_00160cf0");
void func_00160bd8_t(void*) asm("func_00160bd8");
void func_00160cf0(void* t) {
    func_00160bd8_t(t);
    func_00160bd8_t(t);
}
}

namespace tiny {
void func_00160d18(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00160d18");
void func_00160d18(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (384));
    t |= 0x0001u;
    *(u32*)((u32)a0 + (384)) = t;
}
void func_00160d28(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00160d28");
void func_00160d28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t = *(u32*)((u32)a0 + (384));
    t |= 0x0004u;
    *(u32*)((u32)a0 + (384)) = t;
}
void func_00160d38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00160d38");
void func_00160d38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 v = *(u32*)((u32)a0 + (384));
    v &= (u32)((s32)-5);
    *(u32*)((u32)a0 + (384)) = v;
}
bool isModelLod(u8* p) asm("_ZN2dk5BgObj10isModelLodEv");
bool isModelLod(u8* p) { u32 f = *(u32*)(p + 696) & 0x80; return f; }
bool isPartsLod(u8* p) asm("_ZN2dk5BgObj10isPartsLodEv");
bool isPartsLod(u8* p) { u32 f = *(u32*)(p + 696) & 0x100; return f; }
}

namespace w1562 {
extern u8* D_004f3b38 asm("D_004f3b38");
void func_00160d18(u8*) asm("func_00160d18");
static inline u8* w1562_next(u8* p) { if (!p) return D_004f3b38; return *(u8**)(p + 0x80); }
void func_00160d70(s32 k) asm("func_00160d70");
void func_00160d70(s32 k) {
    u8* p = 0;
    while ((p = w1562_next(p)) != 0) {
        if (*(s32*)(p + 0x1a8) == k) func_00160d18(p);
    }
}
}

namespace w46 {
struct Node160 { u8 pad[128]; Node160* next; u8 pad2[292]; u32 id; };
extern Node160* D_004f3b38 asm("D_004f3b38");
void func_00160d28(Node160*) asm("func_00160d28");
static inline Node160* Next160(Node160* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
void wtarget_00160de0(u32 id, u32, u32, u32) asm("_Z16wtarget_00160de0jjjj");
void wtarget_00160de0(u32 id, u32, u32, u32) {
    Node160* n = 0;
    while ((n = Next160(n))) {
        if (n->id == id) func_00160d28(n);
    }
}
}

namespace w47 {
struct N160 { u8 pad[128]; N160* next; u8 pad2[292]; s32 key; };
extern N160* D_004f3b38 asm("D_004f3b38");
void func_00160d38(N160*) asm("func_00160d38");
static inline N160* Next160(N160* n) { if (!n) return D_004f3b38; return n->next; }
void func_00160e50(s32 k) asm("func_00160e50");
void func_00160e50(s32 k) {
    N160* n = 0;
    while ((n = Next160(n))) {
        if (n->key == k) func_00160d38(n);
    }
}
}

namespace all {
struct N { u8 pad[128]; N* next; };
extern N* D_004f3b38 asm("D_004f3b38");
void func_00160d28(N*) asm("func_00160d28");
void func_00160d38(N*) asm("func_00160d38");
static inline N* Next(N* n) { if (!n) return D_004f3b38; return n->next; }
void func_00160ec0(void) asm("func_00160ec0");
void func_00160ec0(void) {
    N* n = 0;
    while ((n = Next(n))) func_00160d28(n);
}
}

namespace w48 {
extern u8* D_004f3b38 asm("D_004f3b38");
void func_001604d8(u8*) asm("func_001604d8");
static inline u8* next160(u8* p) {
    if (!p) return D_004f3b38;
    return *(u8**)(p + 128);
}
void func_00160f10(s32 id) asm("func_00160f10");
void func_00160f10(s32 id) {
    u8* p = 0;
    while ((p = next160(p))) {
        if (*(s32*)(p + 424) == id) func_001604d8(p);
    }
}
}

namespace all2 {
using all::N;
using all::Next;
void func_00160f80(void) asm("func_00160f80");
void func_00160f80(void) {
    N* n = 0;
    while ((n = Next(n))) all::func_00160d38(n);
}
}

namespace taq {
u32 func_00160d38(u32) asm("func_00160d38");
u32 func_00160d28(u32) asm("func_00160d28");
u32 func_00161030(void) asm("func_00161030");
void func_00160fd0() asm("func_00160fd0");
void func_00160fd0() {
    u32 v0 = func_00161030();
    if (v0 == 0u) {
        return;
    }
    func_00160d38(v0);
}
void func_00161000() asm("func_00161000");
void func_00161000() {
    u32 v0 = func_00161030();
    if (v0 == 0u) {
        return;
    }
    func_00160d28(v0);
}
}

namespace w8006 {
struct O161030 {
    u8 pad[0x80];
    O161030* next;
    u8 pad2[0x1b0 - 0x84];
    s32 f1b0;
};
extern O161030* D_004f3b38 asm("D_004f3b38");
static inline O161030* next_161030(O161030* p) {
    if (p == 0) return D_004f3b38;
    return p->next;
}
O161030* func_00161030(s32 n) asm("func_00161030");
O161030* func_00161030(s32 n) {
    O161030* p = 0;
    s32 i = 0;
    while ((p = next_161030(p)) != 0) {
        if (p->f1b0 == 0) {
            if (i == n) return p;
            i++;
        }
    }
    return 0;
}
}

namespace find {
struct Pos { u8 pad[36]; s32 id; };
struct N { u8 pad[128]; N* next; u8 pad2[592]; Pos* pos; };
extern N* D_004f3b38 asm("D_004f3b38");
static inline N* Next(N* n) { if (!n) return D_004f3b38; return n->next; }
// The object placed by this map position.
N* func_00161078(s32 id) asm("func_00161078");
N* func_00161078(s32 id) {
    N* n = 0;
    while ((n = Next(n))) {
        if (n->pos && n->pos->id == id) return n;
    }
    return 0;
}
}

