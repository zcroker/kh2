#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
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

extern "C" {
extern u8 D_0034c750[];
extern void* D_0034c73c;
extern void* D_0034c738;
extern ObjList D_004f3b38;
void func_001614e8(void*, Obj*);
void func_0031e158(void*);
Model* func_00149308(void*, u32);
u32 func_00149320(void*, u32);
void* func_00149338(void*, u32);
void func_0011e260(void*, u32);
void func_001604f8(Obj*);
void func_001444c8(Box*, QWord*, QWord*);
void func_00144be0(Box*, void*);
void func_001605a0(Obj*, Mtx);
void func_00143348(void*);
void func_0011eb08(void*, s32);
void func_0011e880(void*, s32, s32, s32);
void func_001608c0(Obj*);
void func_00143520(QWord*, Light*);
void func_00160488(Obj*, s32, s32, s32);
void func_00161540(void*, void*);
void func_001615e8(void*, s32, f32);
void func_00160ac0(Obj*, u32);

static inline void SetColor(Obj::Col& c, u32 r, u32 g, u32 b, u32 a) { c.r = r; c.g = g; c.b = b; c.a = a; }

// Model-object constructor (vtable D_0034c750): copies pos/rot/scale, binds the model of `kind`, sets up
// bounds, colour, optional light and effect, then appends the object to the list at D_004f3b38.
// Twin of func_0015fe18 (same body).
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
}
