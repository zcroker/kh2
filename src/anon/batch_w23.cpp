#include "../common/types.h"

extern "C" {
void AREA_DestroyAllocator(void) asm("_ZN4AREA16DestroyAllocatorEv");
void wtarget_00182720(u32, u32, u32, u32) asm("_Z16wtarget_00182720jjjj");
void wtarget_001c4080(u32, u32, u32, u32) asm("_Z16wtarget_001c4080jjjj");
void LeadDataInit(void*) asm("_ZN2Tz12LeadDataInitEPv");
void trap_peterpan_receive_notify_player_target(u32**) asm("_ZN2kn42trap_peterpan_receive_notify_player_targetEP8BD_VALUE");
void trap_chickenlittle_set_shoot_target(u32**) asm("_ZN2kn35trap_chickenlittle_set_shoot_targetEP8BD_VALUE");

extern void* D_0032bb1c;
void func_00109280(void*);
void func_00170c00(void*);
void func_00170320(void*);
void AREA_DestroyAllocator(void) {
    func_00109280(D_0032bb1c);
    func_00170c00(D_0032bb1c);
    func_00170320(0);
    D_0032bb1c = 0;
}

extern u32 D_003461e8;
void func_00113668(void*);
void func_00105110(void*);
void func_00114850(void** p) {
    *p = &D_003461e8;
    func_00113668(p);
    func_00105110(p);
}

extern u32 D_00347808;
void func_0011a340(void** p) {
    *p = &D_00347808;
    func_00113668(p);
    func_00105110(p);
}

void func_0011d440(void*);
void func_0011c4b0(u8* p) {
    func_0011d440(p);
    void* o = *(void**)(p + 20);
    (*(void (**)(void*, void*))((*(u8**)o) + 44))(o, p);
}

struct Node135 { void* vt; u32 pad; Node135* next; };
extern u32 D_00347d00;
extern Node135* D_00347cf0;
void func_00135aa0(void*);
void func_001358c0(Node135* p) {
    p->vt = &D_00347d00;
    func_00135aa0(p);
    p->next = D_00347cf0;
    D_00347cf0 = p;
}

extern u8 D_0034926a;
extern u32 D_0032b91c;
void func_0014a248(void);  // zero_global_byte_b
void func_0014a310(void);
void func_00102788(u32, u32, u32, void (*)(void));
void func_0014a470(void) {
    D_0034926a = 0;
    func_0014a248();  // zero_global_byte_b
    func_00102788(D_0032b91c, 0, 0x1c908, func_0014a310);
}

struct E24 { u8 pad[20]; u8 a, b, c, d; };
extern E24* D_0034a778;
void func_00153540(void*, u32, u32, u32, u32);
void func_001535b0(u8* p, s32 i) {
    E24* e = (E24*)(i * 24 + (u32)D_0034a778);
    func_00153540(p + 32, e->a, e->b, e->c, e->d);
}

s32 func_001a1de0(void*);
void func_00138c10(void*, s32);
void func_00157aa0(u8* p) {
    if (!func_001a1de0(*(void**)(*(u8**)(p + 52) + 1164))) func_00138c10(p + 10000, 117);
    else func_00138c10(p + 10000, 111);
}

struct E16 { u16 id; u8 pad[14]; };
struct T168 { u32 pad; s32 n; u32 pad2[2]; E16 e[1]; };
s32 func_00168aa0(T168* t, u32 id) {
    s32 c = 0;
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == id) c++;
    }
    return c;
}

void func_001b0798(void*, void*, s32, f32);
void func_001727c8(u8** p) {
    func_001b0798(*(u8**)(p[0] + 4) + 1184, *(void**)(p[1] + 4), 1, *(f32*)(p + 2));
}

s32 func_00184780(void*, void*, f32, f32, f32);
struct P174 { s32 r; u8* b; f32 x, y; };
void func_00174518(P174* p) {
    p->r = func_00184780(*(void**)(*(u8**)p + 4), p->b, *(f32*)(p->b + 12), p->x, p->y);
}

struct Flags3 { u8 a[3]; u8 pad; u16 h[3]; };
extern Flags3 D_01c60530;
void wtarget_00182720(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u16* h = D_01c60530.h;
        u8* c = D_01c60530.a;
        c[1] = b; c[0] = b; c[2] = b;
        h[0] = b; h[1] = b; h[2] = b;
    }
}

extern u8* D_0035037c;

void func_001d32e8(void*, s32, s32);
void func_00197e08(s32 a, s32 b) {
    if (D_0035037c) func_001d32e8(D_0035037c + 64, a, b);
}

void* func_001050d8(u32);
void func_001aedf8(void*, void*, s32);
void func_001af360(void* a) {
    func_001aedf8(func_001050d8(80), a, 3);
}

struct L1b { u8 pad[2228]; L1b* next; };
extern L1b* D_01d48da0;
static inline L1b* list1b_next(L1b* n) { if (!n) return D_01d48da0; return n->next; }
static inline bool list1b_has(L1b* o) {
    L1b* n = 0;
    while ((n = list1b_next(n)) != 0) {
        if (n == o) return true;
    }
    return false;
}
// Is o in the list?
u8 func_001ba028(L1b* o) {  // list_contains_ptr
    return list1b_has(o);
}

extern u8* D_01d49360;
extern u32 D_00320888;
u8 func_002fd248(void*, void*, u32, s32, void*);
s32 func_001c0c38(void* a) {
    return func_002fd248(a, D_01d49360 + 8, *(u32*)(D_01d49360 + 4), 32, &D_00320888);
}

struct E64 { u16 h; u8 pad[62]; };
extern E64 D_01d49388[6];
void func_001c10c8(void) {
    s32 i;
    E64* e = D_01d49388;
    for (i = 5; i >= 0; i--) {
        e->h = 0;
        e++;
    }
}

void func_003208a8(void*, void*);
u8 func_001db8b8(void*, void*);
s32 func_001c1890(u8* p) {
    func_003208a8(*(u8**)(p + 28) + 12, p);
    return func_001db8b8(*(u8**)(p + 28) + 20, p);
}

extern Flags3 D_01d49570;
void wtarget_001c4080(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u16* h = D_01d49570.h;
        u8* c = D_01d49570.a;
        c[1] = b; c[0] = b; c[2] = b;
        h[0] = b; h[1] = b; h[2] = b;
    }
}

struct E68 { u8 id; u8 pad[67]; };
struct T1d7 { s32 n; E68 e[1]; };
s32 func_001d7f40(T1d7* t, u32 id) {  // find_slot_by_byte
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == id) return i;
    }
    return -1;
}

s32 func_001d9c68(u8* p) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (p[i] != 1) return 0;
    }
    return 1;
}

extern s32 D_00359780;
extern s32 D_00359788[];
void func_0020ebd8(s32 v) {
    s32 n = D_00359780;
    if (n > 0 && D_00359788[n] - D_00359788[n - 1] == v) {
        D_00359780 = n - 1;
        return;
    }
    *(u32*)0 = 0;
}

struct E40 { s32 id; u8 pad[36]; };
extern E40* D_0035dcfc;
E40* func_00227cd8(s32 id) {
    E40* e = D_0035dcfc;
    s32 i;
    for (i = 0; i < 96; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}

struct E20 { s32 a; s32 pad; s32 c; u8 pad2[8]; };
struct I4 { u16 idx; u16 pad; };
struct T237 { u32 pad[2]; E20* e; I4* ix; };
void func_00237540(T237* t, s32 i, s32 off, s32 add) {
    E20* e = &t->e[t->ix[i].idx + off];
    e->c = e->a + add;
}

extern void* D_0035ebe0;
void func_0023fb90(void* a) {
    if (a) {
        void* o = D_0035ebe0;
        (*(void (**)(void*, void*))((*(u8**)o) + 4))(o, a);
    }
}

// Round up to a multiple of 64
s32 func_00253948(s32 x) {
    if (x & 63) x = x / 64 * 64 + 64;
    return x;
}

extern u8* D_0035f20c;
void func_0028dac8(void*, s32);
void func_00275dd0(void);
void func_00275c78(void) {
    func_0028dac8(D_0035f20c + 872, 55);
    func_0028dac8(D_0035f20c + 1308, 46);
    func_00275dd0();
}

void func_00281f40(void*, s32);
void func_00281f48(void*);  // memset_1920
void func_00281f70(void*);
void func_00281f90(void*);
void func_00281e88(void* p) {
    func_00281f40(p, 0);
    func_00281f48(p);  // memset_1920
    func_00281f70(p);
    func_00281f90(p);
}

extern u32 D_0035f3a0;
void func_0023f7e0(void*);
void func_0028b870(void*);
void LeadDataInit(void* p) {
    func_0023f7e0(p);
    *(void**)p = &D_0035f3a0;
    func_0028b870(p);
}

struct L2b { u8 pad[20]; s32 key; u8 pad2[4]; L2b* next; };
extern L2b* D_01e2aa80;
static inline L2b* list2b_next(L2b* n) { if (!n) return D_01e2aa80; return n->next; }
L2b* func_002bbda0(s32 key) {
    L2b* n = 0;
    while ((n = list2b_next(n)) != 0) {
        if (n->key == key) return n;
    }
    return 0;
}

extern u8 D_01e2bc40[];
extern u8 D_00375400[];
extern u32 D_0033caf4;
void func_002fee78(void*, void*, u32);
void* func_002beb90(void) {
    func_002fee78(D_01e2bc40, D_00375400, D_0033caf4);
    return D_01e2bc40;
}

void func_00184540(void*, void*, f32, f32);
void* func_002bec38(void* a, void*, u8* c) {
    u8* t = *(u8**)(c + 300);
    func_00184540(a, c, *(f32*)(t + 40), *(f32*)(t + 44));
    return a;
}

extern u32 D_00362738;
void func_002cff98(void*);
void func_002db580(void** p) {
    *p = &D_00362738;
    func_002cff98(p);
    func_00105110(p);
}

extern u32 D_003629e8;
u8 func_002e4a90(void*);  // in_even_range
u8 func_002cea28(void*);
s32 func_002dc748(void** p) {
    *p = &D_003629e8;
    func_002e4a90((u8*)p + 256);  // in_even_range
    return func_002cea28(p);
}

void* func_0010c7e8(u32);
u32 func_0011a408(void*);
void func_0011a918(void*, u32);
void trap_peterpan_receive_notify_player_target(u32** bd) {
    *(u32*)bd = func_0011a408(func_0010c7e8(bd[0][1]));
}

void trap_chickenlittle_set_shoot_target(u32** bd) {
    func_0011a918(func_0010c7e8(bd[0][1]), (u32)bd[1]);
}

// Normalise a 3-vector (VU0 macro code)
void func_002f3d98(f32* d, const f32* s) {  // vec4_normalize
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "vmul.xyz $vf5, $vf4, $vf4\n\t"
        "vaddy.x $vf5, $vf5, $vf5y\n\t"
        "vaddz.x $vf5, $vf5, $vf5z\n\t"
        "vsqrt Q, $vf5x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf5, $vf0, Q\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf5x\n\t"
        "vsub.xyzw $vf6, $vf0, $vf0\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf6, $vf4, Q\n\t"
        "sqc2 $vf6, 0(%0)"
        : : "r"(d), "r"(s) : "memory");
}

typedef union { f32 value; u32 word; } ieee_float_shape_type;
// copysignf
f32 func_002fb900(f32 x, f32 y) {
    u32 ix, iy;
    { ieee_float_shape_type gf_u; gf_u.value = x; ix = gf_u.word; }
    { ieee_float_shape_type gf_u; gf_u.value = y; iy = gf_u.word; }
    { ieee_float_shape_type sf_u; sf_u.word = (ix & 0x7fffffff) | (iy & 0x80000000); x = sf_u.value; }
    return x;
}

void func_001acd78(void*);
void func_0031fd78(void* p) {
    func_001acd78(p);
    (*(void (**)(void*))((*(u8**)p) + 32))(p);
}

extern u32 D_00362a20;
void func_002d0f38(void*);
void func_00325550(void** p) {
    *p = &D_00362a20;
    func_002d0f38(p);
    func_00105110(p);
}
}
