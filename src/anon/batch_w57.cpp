#include "../common/types.h"

struct NoTail { ~NoTail() {} };

void func_001008d0(BD_VALUE*) __attribute__((weak));

extern "C" {

// Run the static constructors once (crt-style).
extern u8 D_0037aa00;
extern void (**D_0032b914)();
extern BD_VALUE D_00378ae8;
void func_001002b0(void) {
    if (!D_0037aa00) {
        void (**p)();
        void (*f)();
        while ((f = *(p = D_0032b914)) != 0) {
            D_0032b914 = p + 1;
            f();
        }
        u32 r = 1;
        if (func_001008d0) {
            func_001008d0(&D_00378ae8);
        }
        D_0037aa00 = r;
    }
}

// Sum a virtual query over the objects referenced by an offset table.
u32 func_00124748(void*);  // list_nth_node_rel
typedef s32 (*VFn124)(u8*);
s32 func_00124788(u8* a) {
    s32 sum = 0;
    u8* end = (u8*)func_00124748(a);  // list_nth_node_rel
    u8* base = *(u8**)(a + 4);
    s32* p = (s32*)(base + 16);
    while (*p) {
        u8* o = base + *p;
        if (o == end) break;
        p++;
        sum += (*(VFn124*)((*(u8**)o) + 48))(o);
    }
    return sum;
}

// Allocate and construct an object that points back at its owner slot.
void* func_001050d8(u32);
void func_00135e50(void*);
void func_00135dc8(void** out) {
    u8* o = (u8*)func_001050d8(272);
    func_00135e50(o);
    *(void**)(o + 4) = out;
    *out = o;
}

u32 func_0013a7e8(u32);
u32 func_0013d7e0(void);
void func_00138d60(void*, u32, u32, u32, u32, u32, u32);
void func_001374c8(u8* t, f32 f, u32 a, u32 b, u32 c) {
    u32 x = func_0013a7e8(1);
    u32 y = func_0013d7e0();
    func_00138d60(t, 11100, x, y, a, b, 13);
    *(u32*)(t + 424) = 16;
    *(f32*)(t + 436) = f;
    *(u32*)(t + 440) = c;
}

// Constructor: reset state.
struct T13a {
    void* vtbl; u8 p4[8]; u32 f0c; u8 p10[0xdc]; s32 fec; u32 ff0; s32 ff4; s32 ff8; u8 b0, b1, b2, b3; u32 f100; void* f104; u8 p108[8]; u32 f110; u8 p114[8]; u8 f11c[0x180]; u32 f29c, f2a0, f2a4; u8 b2a8, b2a9, p2aa[2]; f32 f2ac; u32 f2b0; f32 f2b4;
};
extern u8 D_00348590, D_00347e60;
u32 func_00239700(void*);
void func_0013afe8(T13a* t) {
    t->vtbl = &D_00348590;
    t->fec = -1;
    t->ff4 = -1;
    t->ff8 = -1;
    t->f104 = &D_00347e60;
    t->f0c = 0;
    t->ff0 = 0;
    t->b0 = 0; t->b1 = 0; t->b2 = 0; t->b3 = 0;
    t->f100 = 0;
    t->f110 = 0;
    func_00239700(&t->f11c);
    t->f29c = 0;
    t->f2a0 = 0;
    t->f2a4 = 0;
    t->b2a8 = 0;
    t->b2a9 = 0;
    t->f2ac = 1.0f;
    t->f2b0 = 0;
    t->f2b4 = 1.0f;
}

extern u32 D_00348804;
void func_00141c18(u32, u32, u32, u32, u32);
u32 func_00141ff0(u32, u32, u32, u32, u32);
void func_00143dd0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    NoTail g;
    func_00141c18(D_00348804, 15, d, 0, 0);
    func_00141ff0(D_00348804, a, b, c, e);
}

void func_00166618(u32, u32, u32, u32, u32, u32, u32);
struct P14d { u32 pad; s16 w; u16 h; };
void func_0014de30(P14d* p, u8* q, s32 n) {
    func_00166618((u32)q, 1, (s16)(n << 5), p->w, (u32)p->h >> 1, 0, 0);
    func_00166618((u32)(q + 0x4e000), 1, (s16)(n << 5), p->w, (u32)p->h >> 1, (u32)p->h >> 1, 1);
}


// Either of two registered lookups is missing: fall back to the default entry.
extern u32 D_0034aaac, D_0034aaa8, D_0034aaa4;
u32 func_001492f8(u32);
u32 func_00149300(u32);
u32 func_0019f880(s32, s32);
void func_0015aa98(u32, u32, u32, f32);
void func_0015aba8(u32, u32, u32);
void func_0015b2d0(void) {
    u32 a = func_001492f8(D_0034aaac);
    u32 b = func_00149300(D_0034aaac);
    if (!a || !b) {
        func_0015aa98(D_0034aaa8, func_0019f880(-1, -1), 20, 120.0f);
    } else {
        func_0015aba8(D_0034aaa4, a, b);
    }
}

s32 func_0014aba8(void);
void func_0014aa80(u32, u32, u32);
void func_0016e048(f32* p) {
    s32 n = (s32)(p[0] * 0.5f);
    u32 v = func_0014aba8();
    func_0014aa80(v, n, 0);
}

// CACHE_BUFF::Clear(int): walk the list and release the entries selected by the sign of n.
void func_00170018(void*);
struct CacheNode { u8 p[40]; s32 v; u8 q[16]; CacheNode* next; };
extern CacheNode* D_0034dca0;
static inline CacheNode* CacheNext(CacheNode* n) { if (!n) return D_0034dca0; return n->next; }
void CacheBuffClear(s32 n) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void CacheBuffClear(s32 n) {
    CacheNode* cur = 0;
    while ((cur = CacheNext(cur))) {
        if (n >= 0 ? cur->v >= n : cur->v <= n) func_00170018(cur);
    }
}

void* func_001050c8(void);
void func_00127c70(u32, void*, u32);
void func_0017ee68(u8* t) {
    u32 s = *(u32*)(*(u8**)(t + 8) + 1648);
    if (*(u32*)(t + 208)) {
        func_00127c70(s, func_001050c8(), *(u32*)(t + 208));
        *(u32*)(t + 208) = 0;
    }
    if (*(u32*)(t + 212)) {
        func_00127c70(s, func_001050c8(), *(u32*)(t + 212));
        *(u32*)(t + 212) = 0;
    }
}

struct B156 { u8 p[156]; u32 bit:1; };
u32 func_00187e20(void);
u32 func_00187e58(void*);
u32 func_00188758(B156* t) {
    u32 r = 0;
    if (*(u32*)((u8*)t + 140)) {
        u8 b = t->bit;
        if (!b) {
            if (!func_00187e20()) {
                if (*(s32*)((u8*)t + 152) >= 300 || !func_00187e58(t)) r = 1;
            }
        }
    }
    return r;
}

// Fetch a 16-byte result; copy it out when the lookup succeeds.
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void* func_001d35e0(void*, void*, u32);
u32 func_001a7588(void* p, u32 a1, Q16* out) {
    u32 tmp[8] __attribute__((aligned(16)));
    if (func_001d35e0(tmp, p, a1)) {
        if (out != (Q16*)tmp) { QCOPY(out, tmp); }
    }
    return tmp[5];
}

// Out-of-range test against the 0x7000/0x9000/0x7300/0x8d00 screen limits.
u32 func_001aaf98(u32 z, s32 a, s32 b, s32 c, s32 d) {  // bounds_check_ranges
    u32 r = 0;
    if (a + c < 0x7000 || a > 0x9000 || b < 0x7300 || b - d > 0x8d00) r = 1;
    return r;
}

// OBJOCC::disable_all(): flag every occupant entry as disabled.
struct OccHdr { s32 f0; s32 count; };
struct OccObj { u32 a, b, flags; };
struct OccEnt { u8 p[128]; OccObj* obj; u8 q[12]; };
struct OccSelf { union { OccHdr* h; u32 uh; }; union { OccEnt* arr; u32 uarr; }; };
void OccDisableAll(OccSelf* t) asm("_ZN2YS6OBJOCC11disable_allEv");
void OccDisableAll(OccSelf* t) {
    if (t->uh) {
        for (s32 i = 0; i < ((OccHdr*)t->uh)->count; i++) {
            ((OccEnt*)t->uarr)[i].obj->flags |= 2;
        }
    }
}

void func_001b7f88(void);
void func_00170c00(void*);
extern u8 D_003511c3;
void func_001b7f30(u32* t) {
    if (t[0]) {
        if (D_003511c3 == 1) {
            func_001b7f88();
            func_00170c00((void*)t[0]);
        }
    }
    t[2] = 0;
    t[1] = 0;
    t[0] = 0;
}


// Destructor: release the array member and trailing sub-object.
void func_00161530(void*);  // noop_ret_b
extern u8 D_0034c750, D_0034c738;
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
void func_00160268(C160* t) { t->~C160(); }

// Destructor with a base chain and a 2-element array member.
void func_001d5718(void*);  // list_free_nodes
void func_0031e7f8(void*);
void func_0016a358(void*);
extern u8 D_003507a0, D_003503e0;
extern union DU { void* p; u8 c; } D_00350790;
struct Base4 { void* vt; ~Base4() { func_0016a358(this); } };
struct M2492 { u8 d[32]; ~M2492() { func_0031e7f8(this); } };
struct E12 { u8 d[12]; ~E12() { func_001d5718(this); } };
struct C4 : Base4 {
    u8 p[2492 - 4]; M2492 m; E12 arr[2];
    ~C4() {
        vt = &D_003507a0;
        if (D_00350790.p == this) D_00350790.p = 0;
        vt = &D_003503e0;
    }
};
void u_call4_001a4e30(u32 a, u32, u32, u32) asm("_Z16u_call4_001a4e30jjjj");
void u_call4_001a4e30(u32 a, u32, u32, u32) { ((C4*)a)->~C4(); }

// Release every live entry of the 32-slot table.
struct Ent22 { void** obj; u32 x; };
extern Ent22 D_01dad9c0[32];
void func_0022d820(void) {
    for (s32 i = 0; i < 32; i++) {
        if (D_01dad9c0[i].obj) {
            (*(void (**)(void*))((u8*)*D_01dad9c0[i].obj + 32))(D_01dad9c0[i].obj);
            D_01dad9c0[i].obj = 0;
        }
    }
}

u32 func_00138470(void);
u32 func_00138440(void);
void func_001382e0(void);
u32 func_00287db0(void);
void func_001039f8(void);
void func_0017a798(void);
void func_00287da0(void);
u32 func_00263e18(void) {
    if (!func_00138470()) {
        if (!func_00138440()) func_001382e0();
    }
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    if (func_00138470()) {
        func_0017a798();
        func_00287da0();
    }
    return 0;
}

// Does any of the 32 records satisfy the predicate?
u32 func_00139d78(u32);
extern u8* D_0035f21c;
u32 func_00276a90(void) {
    u32 r = 0;
    for (s32 i = 0; i < 32; i++) {
        if (func_00139d78((u32)D_0035f21c + i * 408 + 30360)) { r = 1; break; }
    }
    return r;
}

void func_0028d6e8(void*);
void func_001396b0(void*);
void func_0031a260(void*, u32);
struct T28d { u8 p[396]; u32 f396; u32 f400; u8 p2[9]; u8 b413; };
void func_0028d660(T28d* t, u32 v) {  // record_set_value_refresh
    func_0028d6e8(t);
    if (t->f396 != v) {
        t->f396 = v;
        t->b413 = 1;
        func_001396b0(t);
        if (t->f396) {
            t->f400 = 0;
            func_001396b0(t);
            if (t->f400) func_0031a260(t, 0);
        }
    }
}

void func_002bc470(u32);
void func_002b6e24(u32, u32, u32);
void func_002ba1b8(u32 a, u32 b, u32 c) {
    func_002bc470(a);
    func_002b6e24(a, b, c);
}

extern u32 D_003617ec, D_003617f4;
extern u8 D_003617f8;
extern u32 D_0032b91c;
void func_002b871c(void);
u32 func_00102788(u32, u32, u32, u32);
void func_002bd870(void);
void func_002bd788(u32 a) {
    D_003617f8 = 0;
    D_003617ec = a;
    func_002b871c();
    D_003617f4 = func_00102788(D_0032b91c, 0, 0x5cc60, (u32)func_002bd870);
}

// Destructor: tear down the layered members and chain to the base.
void func_00319f88(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
extern u8 D_00345c08, D_0034e8b8, D_0034ee08;
struct G0 { u8* t; ~G0() { func_00319fb0(t); } };
struct G1 { u8* t; ~G1() { *(void**)t = &D_0034ee08; func_0019f9a8(t + 2568); func_001c0248(t + 2640); } };
struct G2 { u8* t; ~G2() { *(void**)t = &D_0034e8b8; func_00319f88(t + 2824); } };
struct B319 {
    void* vt;
    ~B319() {
        G0 g0 = { (u8*)this };
        G1 g1 = { (u8*)this };
        G2 g2 = { (u8*)this };
    }
};
struct C319 : B319 {
    u8 p[3184 - 4];
    E16 arr[6];
    ~C319() { vt = &D_00345c08; }
};
void func_00319d68(C319* t) { t->~C319(); }

void func_00239870(void*);
void func_002361d0(void*);
void func_0031a840(void*);
extern u8 D_00347d90, D_00347e60, D_00347f98, D_00347e80;
void func_0031a5a0(u8* t) {
    NoTail g;
    *(void**)t = &D_00347d90;
    *(void**)(t + 896) = &D_00347e60;
    func_00239870(t + 920);
    *(void**)(t + 896) = &D_00347f98;
    *(void**)(t + 448) = &D_00347e80;
    func_002361d0(t + 480);
    *(void**)(t + 448) = &D_00347f98;
    *(void**)t = &D_00347e60;
    func_00239870(t + 24);
    func_0031a840(t);
}


// Notify every attached listener, then clear the busy flag.
void func_001d8070(u8* t) {
    for (s32 i = 0; i < *(s32*)(t + 712); i++) {
        void** o = ((void***)(t + 676))[i];
        (*(void (**)(void*))(*(u8**)o + 8))(o);
    }
    *(u32*)(t + 4) &= ~1u;
}

// Drop every list entry whose owner is still valid.
u32 func_001dca20(void*);  // get_bit20_of_field8
void func_00321ce8(void*, void*);  // list_unlink_node
void func_001e0058(void*);
void func_001de610(u8* t) {
    u8* n = *(u8**)(t + 12);
    while (n) {
        u8* a = *(u8**)(n + 64);
        u8 bit = (*(s32*)(a + 8) >> 26) & 1;
        u8* nx = *(u8**)(n + 96);
        if (!bit) {
            if (func_001dca20(a)) {  // get_bit20_of_field8
                func_00321ce8(t + 12, n);  // list_unlink_node
                func_001e0058(n);
            }
        }
        n = nx;
    }
}

u32 func_001c5f38(void*);
void func_001c6760(void*);
u32 func_001dbd68(void*);
void func_001c6748(void*);
struct T1c6 { u8 p[4]; f32 f4; u8 p2[13]; u8 b21; u8 p3[30]; f32 f52; u8 p4[20]; f32 f76; u8 b80; };
void func_001c6850(T1c6* t) {
    if (func_001c5f38(t)) return;
    if (t->f76 > 0.0f) {
        func_001c6760(t);
        return;
    }
    t->f4 = t->f52;
    t->b21 = 0;
    if (t->b80) {
        t->b80--;
        return;
    }
    if (func_001dbd68(t)) func_001c6748(t);
}

// OR the pending bitset (640 bits) into the destination set, then free it.
u32* func_002859a0(void);
void func_00106420(void*);
extern union { u32* p; u8 c; } D_0035f2e4;
void func_00285910(void) {
    u32* dst = func_002859a0();
    s32 i = 0;
    do {
        u8* s = (u8*)D_0035f2e4.p;
        u32 off = ((u32)i >> 5) << 2;
        if (*(u32*)(s + off + 204) & (1 << (i & 31))) *(u32*)((u8*)dst + off) |= 1 << (i & 31);
        i++;
    } while (i < 640);
    if (D_0035f2e4.p) {
        func_00106420(D_0035f2e4.p);
        D_0035f2e4.p = 0;
    }
}

}
