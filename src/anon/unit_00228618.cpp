// Musical (Atlantica) minigame gauges and selectors (vtables 0x35e028, 0x35e050). Linked unit 0x228618-0x228f18.
#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct W_w {
    u8 pad[0x188];
    s32 x188;
    void* x18c;
    s32 x190;
    u8 pad2[4];
};
struct O_w3 {
    u8 pad[0x18];
    W_w w[3];
};
struct C8BD8Sel {
    u8 pad[0x188];
    s32 f188;
    void* f18c;
    s32 f190;
};
struct C8BD8O {
    u8 pad0[0x1b0];
    C8BD8Sel s1b0;
    u8 pad[0x348 - 0x1b0 - sizeof(C8BD8Sel)];
    C8BD8Sel s348;
    u8 padb[0x4e0 - 0x348 - sizeof(C8BD8Sel)];
    f32 f4e0;
    f32 f4e4;
    s32 f4e8;
};
struct W78Alloc;
typedef u8* (*W78AllocFn)(W78Alloc*, s32, s32);
struct W78Alloc { W78AllocFn* vt; };
struct W78Item { void* vt; u8 p4[8]; u8 m1[12]; u8 m2[384]; };
typedef u8* (*AF)(void*, s32, s32);

extern "C" {
void func_0031a838(void*);
void func_00239700(void*);
void* func_00224930(void);
void func_002294c8(void*, s32, void*, void*);
void func_00229430(void*, s32);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
void func_001386e0(void*, s32, s32, s32, s32, s32);
void func_001396b0(void*);
void func_0031a260(void*, s32);
s32 func_00224910(void);
void func_00239f18(void* p, f32 v);
void func_00224920(s32);
QV func_0013f6e8(QV, QV, QV, f32, f32, f32, f32);
void func_00138c68(void*, s32, s32);
void func_00138c10(void*, s32);
s32 func_00139d78(void*);
void func_00139570(void*);
void func_00139580(void*);
}

extern u8* D_00347f80;
extern u8 D_0035e190[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
s32 D_0035dfb0[14] = { 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0x94, 0x95, 0 };
s32 D_0035dfe8[13] = { 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0x91, 0x92 };
s32 D_0035e01c[1] __attribute__((aligned(4))) = { 30000 };
extern u8 D_0035e028[];
extern u8 D_0035e050[];

static inline u8* alloc(s32 n) {
    void* a = *(void**)(D_00347f80 + 20);
    return (**(AF**)a)(a, n, 0);
}
static inline void elems(u8* e) {
    s32 i;
    for (i = 6; i != -1; i--) {
        *(void**)e = D_00347f98;
        func_0031a838(e + 12);
        *(void**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
}

void func_00228618(void) {
    u8* o = alloc(2900);
    *(s32*)(o + 12) = 0;
    *(void**)o = D_0035e190;
    elems(o + 24);
    func_002294c8(o, 6, func_00224930(), D_0035dfb0);
    o = alloc(2900);
    *(void**)o = D_00347f98;
    func_0031a838(o + 12);
    *(void**)o = D_0035e190;
    elems(o + 24);
    func_002294c8(o, 6, D_0035e01c, D_0035dfe8);
}

static inline void Upd_w(W_w* w) {
    func_001396b0(w);
    if (w->x18c) {
        w->x190 = 0;
        func_001396b0(w);
        if (w->x190)
            func_0031a260(w, 0);
    }
}

void func_00228788(O_w3* o) {
    func_00229430(o, 2800);
    W_w* w1 = &o->w[1];
    W_w* w2 = &o->w[2];
    s32 a = func_0022b9e0();
    s32 b = func_0022b720();
    W_w* w0 = &o->w[0];
    func_001386e0(w0, 2800, a, b, 32, 11);
    w0->x188 = 33;
    w0->x18c = 0;
    Upd_w(w0);
    func_001386e0(w1, 2800, a, b, 30, 11);
    w1->x18c = w0;
    Upd_w(w1);
    func_001386e0(w2, 2800, a, b, 35, 11);
    w2->x188 = 36;
    w2->x18c = 0;
    Upd_w(w2);
}

static inline f32 w1781_clamp(f32 x, f32 lo, f32 hi) {
    f32 r;
    if (x < lo) r = lo;
    else if (hi < x) r = hi;
    else r = x;
    return r;
}

void func_00228918(u8* self) {
    f32 v = (f32)func_00224910() / 10000.0f;
    v = w1781_clamp(v, 0.0f, 1.0f);
    v = 1.0f - v;
    v = w1781_clamp(v, 0.0f, 1.0f);
    func_00239f18(self + 0x1c8, v);
}

void func_002289c0(void** p) {
    (*(void (**)(void*))(*(u8**)p + 28))(p);
    func_00228918((u8*)p);
}

void func_002289f0(void) {
    W78Alloc* a = *(W78Alloc**)(D_00347f80 + 20);
    u8* v = a->vt[0](a, 1248, 0);
    *(u32*)(v + 12) = 0;
    *(u8**)v = D_0035e028;
    W78Item* it = (W78Item*)(v + 24);
    s32 i = 2;
    do {
        it->vt = D_00347f98;
        func_0031a838(it->m1);
        it->vt = D_00347e60;
        func_00239700(it->m2);
        it++;
    } while (--i != -1);
    func_00228788((O_w3*)v);
}

static inline void Settle228(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}

void func_00228ab0(u8* o) {
    u8* m1 = o + 432;
    u8* m2 = o + 24;
    func_00229430(o, 2800);
    u32 a = func_0022b9e0();
    u32 b = func_0022b720();
    func_001386e0(m2, 2800, a, b, 28, 11);
    *(u32*)(m2 + 392) = 29;
    func_001386e0(m1, 2800, a, b, 23, 11);
    *(u8**)(m1 + 396) = m2;
    Settle228(m1);
    *(u32*)(m2 + 396) = 0;
    Settle228(m2);
    *(f32*)(o + 1248) = *(f32*)(o + 1252) = 0.0f;
    *(u32*)(o + 1256) = func_00224910();
}

static inline __attribute__((always_inline)) void c8bd8_setflag(C8BD8Sel* s, void* f) {
    s->f18c = f;
    func_001396b0(s);
    if (s->f18c) {
        s->f190 = 0;
        func_001396b0(s);
        if (s->f190) func_0031a260(s, 0);
    }
}

void func_00228bd8(C8BD8O* o) {
    s32 v = ((s32 (*)(C8BD8O*))func_00224910)(o);
    s32 c = v < -10000 ? -10000 : (v > 10000 ? 10000 : v);
    func_00224920(c);
    v = v / 100;
    v = v < -100 ? -100 : (v > 100 ? 100 : v);
    QV a, b, d;
    v = -v;
    a.unit(); b.unit(); d.unit();
    f32 f = o->f4e0;
    d.x = (f32)v;
    o->f4e4 = f;
    a.x = f;
    b.x = f;
    b = func_0013f6e8(b, d, a, 0.4f, 1.2f, 0.5f, 0.1f);
    o->f4e0 = b.x;
    func_00138c68(&o->s1b0, 0, (s32)b.x);
    if (o->f4e8 != c) {
        C8BD8Sel* s1 = &o->s1b0;
        func_00138c10(s1, o->f4e8 >= c ? 24 : 26);
        s1->f188 = 23;
        if (c >= 6000) {
            C8BD8Sel* s = &o->s348;
            if (!func_00139d78(s)) {
                s32 r0 = func_0022b9e0();
                s32 r1 = func_0022b720();
                func_001386e0(s, 2800, r0, r1, 25, 11);
                c8bd8_setflag(s, s1);
                func_00139580(s);
            } else {
                func_00138c10(s, 25);
                func_00139580(s);
            }
        } else {
            if (func_00139d78(&o->s348)) func_00139570(&o->s348);
        }
    }
    o->f4e8 = c;
}

void func_00228e28(void** o) {
    ((void (*)(void**))(*(void***)o)[7])(o);
    func_00228bd8((C8BD8O*)o);
}

static inline u8* alloc_obj(s32 size) {
    u8* a = *(u8**)(D_00347f80 + 20);
    return (**(AF**)a)(a, size, 0);
}

void func_00228e58(void) {
    u8* v = alloc_obj(1260);
    u8* e;
    s32 i;
    *(u32*)(v + 12) = 0;
    *(u32*)v = (u32)D_0035e050;
    e = v + 24;
    for (i = 2; i != -1; i--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    func_00228ab0(v);
}
