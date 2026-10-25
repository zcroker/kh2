#include "../common/types.h"

// 0x1d30b0-0x1d35e0: a registry of up to three 96-byte-entry tables (searched by key), plus a
// camera-matrix follower and its command setter.

typedef unsigned int Q1d3148 __attribute__((mode(TI)));
struct V1d3148 {
    union { Q1d3148 q; f32 f[4]; };
    V1d3148& operator=(const V1d3148& o) {
        // 128-bit lq/sq copy: hand-written asm in the original
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct M1d3148 {
    Q1d3148 r[3];
    V1d3148 t;
    M1d3148& operator=(const M1d3148& o) {
        // 128-bit lq/sq matrix copy: hand-written asm in the original
        if (this != &o) {
            asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
};
struct O1d3148 { s32 state; u8* obj; u8 pad[8]; M1d3148 m; };

struct Registry {
    u8* slot[3];
    Registry();
};

extern "C" {
u8 func_002fd248_u8(u32, void*, u32, u32, void*) asm("func_002fd248");  // bsearch
u32 func_002fd248(u32, u8*, u32, u32, void*);
extern u32 D_003216a8;
extern u8 D_003216b8[];
extern u8* D_00350cc8;
extern u8* D_00350ccc;
s32 func_0019ba60(u8*);
V1d3148* func_0016c028(u8*);
s32 func_001dc9e0(u8*);
V1d3148* func_001dc5f8(u8*);
}

static u8* D_01d5ba0c __attribute__((aligned(4)));
static Registry D_01d5ba10 __attribute__((aligned(4)));

extern "C" {

void func_001d30b0(u8* d) { D_01d5ba0c = d; }

u8 func_001d30c0(u32 a) {
    u8* d = D_01d5ba0c;
    return func_002fd248_u8(a, d + 8, *(u32*)(d + 4), 8, &D_003216a8);
}

void func_001d30f8(u32* p, u32 a, u32 b) {
    p[0] = a;
    p[1] = b;
}

struct Cmd1d3108 { s32 type; u8 pad[12]; M1d3148 m; };
void func_001d3108(Cmd1d3108* c, const M1d3148* m) {
    c->type = 6;
    c->m = *m;
}

void func_001d3148(O1d3148* o) {
    switch (o->state) {
    case 2:
        if (func_0019ba60(o->obj)) o->m = *(M1d3148*)(o->obj + 1712);
        o->state = 0;
        break;
    case 3:
        if (func_0019ba60(o->obj)) o->m = *(M1d3148*)(o->obj + 64);
        o->state = 7;
    case 7:
        if (!func_0019ba60(o->obj)) {
            o->state = 0;
            break;
        }
        (o->m.t = *func_0016c028(o->obj)).f[3] = 1.0f;
        break;
    case 4:
        if (func_0019ba60(D_00350cc8)) o->m = *(M1d3148*)(D_00350cc8 + 64);
        o->state = 8;
    case 8:
        if (!D_00350ccc || !func_001dc9e0(D_00350ccc)) {
            o->state = 0;
            break;
        }
        (o->m.t = *func_001dc5f8(D_00350ccc)).f[3] = 1.0f;
        break;
    }
}

void func_001d32e8(u8* a0, u32 a1, u32 a2) {
    if (*(u32*)(a0 + 4) == a1) *(u32*)(a0 + 4) = a2;
}

}

Registry::Registry() {
    u8** p = slot;
    s32 i = 2;
    do {
        *p = 0;
        i--;
        p++;
    } while (i >= 0);
}

extern "C" {

u8** func_001d3350(Registry* r, u8* v) {
    u8** p = r->slot;
    for (s32 i = 0; i < 3; i++) {
        if (*p == v) return p;
        p++;
    }
    return 0;
}

void func_001d3380(void*) {}
void func_001d3388(void*) {}

u8* func_001d3390(u8* a) {
    u8** r = func_001d3350(&D_01d5ba10, 0);
    func_001d3388(a);
    *r = a;
    return a;
}

void func_001d33e0(u8* a) {
    *func_001d3350(&D_01d5ba10, a) = 0;
}

u32 func_001d3408(u32 key) {
    u8** pp = D_01d5ba10.slot;
    for (s32 i = 0; i < 3; i++) {
        u8* e = *pp++;
        if (e) {
            u32 v = func_002fd248(key, e + 8, *(u32*)(e + 4), 96, D_003216b8);
            if (v) return v;
        }
    }
    return 0;
}

u8* func_001d3498(u8* p, u8* cur) {
    if (!cur) return p + 8;
    if (cur == p + 8 + (*(s32*)(p + 4) - 1) * 96) return 0;
    return cur + 96;
}

s32 func_001d3558(u8* t, u8* p);

u8* func_001d34d0(u8* p) {
    u8** t = D_01d5ba10.slot;
    s32 i;
    for (i = 0; i < 3; i++, t++) {
        if (*t && (!p || func_001d3558(*t, p))) {
            p = func_001d3498(*t, p);
            if (p) return p;
        }
    }
    return 0;
}

s32 func_001d3558(u8* t, u8* p) {
    if (p < t + 8) return 0;
    return p < t + *(s32*)(t + 4) * 96 + 8;
}

}
