#include "flare.hpp"

// Ts::FLARE (0x2e9248-0x2e99c8): a pool of 30 flare objects with collision. A task pushes them
// apart from each other and out of the field's collision shapes every frame. The 128-bit lq/sq
// copies and VU0 vector math are hand-written inline asm (VU0 macro code), as in the original.

struct VEC {
    f32 x, y, z, w;
    VEC() {}
    VEC(const VEC& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    VEC& operator=(const VEC& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    VEC operator*(f32 s) const {
        VEC r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    VEC operator+(const VEC& b) const {
        VEC r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    VEC operator-(const VEC& b) const {
        VEC r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

// YS::COLLISION (32 bytes).
struct COLLISION {
    u8 d0[12];
    s32 f12;
    VEC pos;
    COLLISION() { f12 = 0; }
    ~COLLISION() {}
};

struct FLARE_OBJ {
    VEC pos;            // 0
    COLLISION col;      // 16
    s32 f48;            // 48
    f32 x;              // 52
    f32 y;              // 56
    void* eff;          // 60
    FLARE_OBJ();
    ~FLARE_OBJ() {}
    static void* operator new(u32, void* p) { return p; }
};

struct HEAP { void** vt; };
typedef void* (*ALLOC_FN)(HEAP*, s32, s32);
HEAP* GetAllocator(void) asm("_ZN4AREA12GetAllocatorEv");
u8* CreateTask(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
s32 EffectIsActive(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
void CollisionMake(COLLISION*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");

extern "C" void func_00106420(void*);

struct FLARE_POOL {
    FLARE_OBJ item[30];
    s32 free[30];
    s32 count;
    static void* operator new(u32 n) {
        HEAP* h = GetAllocator();
        return ((ALLOC_FN)h->vt[0])(h, n, 0);
    }
    static void operator delete(void* p) { func_00106420(p); }
};

// The field's collision shapes the flares are pushed out of.
struct FIELD_COLS {
    s32 count;
    COLLISION e[4];
};

extern "C" {
extern u8* D_003633c8;          // the task
extern void* D_0034e948;
FLARE_POOL* D_01e2bfa0;
s32 D_01e2bfa4;
s32 func_0019ba60(void*);
void* func_0016bba8(void*, s32, void*);
void func_0018a818(COLLISION*, void*, void*);
s32 func_0018a550(COLLISION*, COLLISION*);
void func_0018a7d0(COLLISION*, COLLISION*, VEC*);
double func_00313b80(f32);           // float_to_double
s32 func_003142e0(double, double);   // double_compare
u32 func_001dc9e0(void*);
VEC* func_001dc5f8(void*);
FLARE_OBJ* func_002e97b8(FLARE_OBJ*);
void func_002e9610(FLARE_OBJ*, const VEC&);
void func_002e93b0(FLARE_OBJ*);
}
FIELD_COLS D_01e2bfb0;

extern "C" {

// Collects the field's collision shapes.
void func_002e9248(void) {
    void* x = 0;
    D_01e2bfb0.count = 0;
    void* s = D_0034e948;
    if (!func_0019ba60(s)) return;
    while ((x = func_0016bba8(s, 4, x))) {
        func_0018a818(&D_01e2bfb0.e[D_01e2bfb0.count], s, x);
        D_01e2bfb0.count++;
    }
}

void func_002e92e8(void*) {
    func_002e9248();
    FLARE_OBJ* o = func_002e97b8(0);
    while (o) {
        func_002e93b0(o);
        o = func_002e97b8(o);
    }
}

void func_002e9338(void*) {
    delete D_01e2bfa0;
    D_01e2bfa0 = 0;
    D_003633c8 = 0;
}

}  // extern "C"

FLARE_OBJ::FLARE_OBJ() {
    f48 = 0;
    eff = 0;
}

extern "C" {

void func_002e93b0(FLARE_OBJ* self) {
    func_002e97b8(0);
    if (self->eff != 0 && !EffectIsActive(self->eff)) self->eff = 0;
    VEC push;
    FLARE_OBJ* o = 0;
    while ((o = func_002e97b8(o)) != 0) {
        if (o != self && func_0018a550(&self->col, &o->col)) {
            func_0018a7d0(&self->col, &o->col, &push);
            func_002e9610(o, VEC(o->pos) + push * 0.5f);
            func_002e9610(self, VEC(self->pos) + push * -0.5f);
        }
    }
    s32 i;
    for (i = 0; i < D_01e2bfb0.count; i++) {
        if (func_0018a550(&self->col, &D_01e2bfb0.e[i])) {
            func_0018a7d0(&self->col, &D_01e2bfb0.e[i], &push);
            func_002e9610(self, VEC(self->pos) - push);
        }
    }
}

void func_002e95a0(FLARE_OBJ* p, f32 x, f32 y) {
    p->y = y;
    p->x = x;
    if (func_003142e0(0.0, func_00313b80(y)) < 0) CollisionMake(&p->col, 0, x, y);
    else CollisionMake(&p->col, 3, x, x);
}

void func_002e9610(FLARE_OBJ* a, const VEC& b) {
    a->pos = b;
    a->col.pos = b;
    void* o = a->eff;
    if (o && func_001dc9e0(o)) *func_001dc5f8(a->eff) = b;
}

}  // extern "C"

namespace Ts {

void FLARE::Init() {
    if (D_003633c8 == 0) {
        u8* t = CreateTask(1, 0x501e, func_002e92e8);
        D_003633c8 = t;
        *(void (**)(void*))(t + 0x30) = func_002e9338;
        FLARE_POOL** pp = &D_01e2bfa0;
        FLARE_POOL* p = new FLARE_POOL;
        s32 i;
        for (i = 0; i < 30; i++) p->free[i] = i;
        p->count = 30;
        *pp = p;
    }
    FLARE_POOL* q = D_01e2bfa0;
    D_01e2bfa4 = 0;
    s32 j;
    for (j = 0; j < 30; j++) q->free[j] = j;
    q->count = 30;
}

}  // namespace Ts

extern "C" {

// The next object in use after p (0: the first).
FLARE_OBJ* func_002e97b8(FLARE_OBJ* p) {
    FLARE_POOL* pool = D_01e2bfa0;
    FLARE_OBJ* q = p ? p + 1 : pool->item;
    while (q < pool->item + 30) {
        s32 idx = q - pool->item;
        s32 n = pool->count;
        s32 j;
        for (j = 0; j < n; j++) if (pool->free[j] == idx) { q++; break; }
        if (j == n) return q;
    }
    return 0;
}

}  // extern "C"

namespace Ts {

u32 FLARE::IsEmpty() {
    return D_01e2bfa0->count == 30;
}

}  // namespace Ts

extern "C" {

FLARE_OBJ* func_002e9850(void) {
    D_01e2bfa4++;
    FLARE_POOL* p = D_01e2bfa0;
    p->count--;
    FLARE_OBJ* r = &p->item[p->free[p->count]];
    new (r) FLARE_OBJ;
    return r;
}

void func_002e98b0(FLARE_OBJ* e) {
    FLARE_POOL* p = D_01e2bfa0;
    D_01e2bfa4--;
    s32 n = p->count;
    u8* s = (u8*)(n * 4) + (u32)p;
    n++;
    p->count = n;
    *(s32*)(s + 1920) = e - p->item;
}

}  // extern "C"
