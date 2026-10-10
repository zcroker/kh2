#include "../common/types.h"

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Words6 { u32 w[6]; };

void u_tail0_0014d008(void) asm("_Z16u_tail0_0014d008v");
void f17f488(s32, s32, f32, f32) asm("_Z13func_0017f488iiff");
void MISSION_Activate2d(void*) asm("_ZN2YS7MISSION10Activate2dEv");
void EFFECT_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
u32 wtarget_002342f0(u32, u32, u32, u32) asm("_Z16wtarget_002342f0jjjj");
void Layout_setNum(void*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
void u_tail4_002e2d88(u32, u32, u32, u32) asm("_Z16u_tail4_002e2d88jjjj");

extern "C" {
s32 func_00103b38(s32);
s32 func_0010cc80(void*);
void func_0014cfc8(void);
void func_0014c908(void);
void func_002f33f0(void*);
void func_0014d308(void);
void func_0014cf18(void);
void func_0014cf88(void);
void func_00102788(u32, u32, u32, void*);
u8 func_00242ce8(void*);
void func_00160e50(u32);
void func_0015c2a0(u32, u64);
void func_0011c4e8(u32, void*, u32, u32, u32, u32, f32);
void func_0011c4b0(u32, void*);
f32 func_0017d160(Vec4*, Vec4*);  // vec3_dot_clamped
void func_002fee78(char*, const char*, void*);
s32 func_0016a070(void*);
void func_0017f380(s32);  // obj_walk_children
void func_0017f268(s32, s32, f32, f32);
void func_001802d8(u32, u32, u32, u32, u32, u32);
void* func_00185da8(void*);
void func_001b7df0(u32, u32);
u8* func_0016e920(u32);

extern s32 D_0032ba20;
extern s32 D_003a6a50;
extern u32 D_0032b91c;
extern u64 D_0034a970[];
extern u64 D_0034af30;
extern u32 D_0034af28;
extern char D_004f63b0[];
extern const char D_0036c440[];

// Selects the current id; falls back to a saved slot when the id is unknown.
void func_00103500(s32 id) {
    if (func_00103b38(id)) {
        if (D_0032ba20 != id) D_0032ba20 = id;
    } else {
        D_003a6a50 = id;
        D_0032ba20 = -1;
    }
}

s32 func_0010f600(u8* p) {
    u32* q = *(u32**)(p + 12);
    if (q == 0) return 0;
    if (q[1] != 0) return 0;
    if (!(*(u32*)(p + 352) & 4)) return 0;
    return func_0010cc80(p) != 0;
}

u32 func_00158548(u64* p) {
    u8 i = func_00242ce8(p) ^ 1;
    return (*p & D_0034a970[i + 2]) != 0;
}

void func_0015c450(u32 n) {
    if ((u8)((D_0034af30 >> n) & 1)) func_00160e50(n);
    else func_0015c2a0(D_0034af28, 1ull << n);
}

void func_00161598(u8* p) {
    u8* o = *(u8**)(p + 68);
    u32 t = *(u32*)(p + 72);
    u32 h = *(u32*)(o + 448);
    if (t) func_0011c4e8(h, o + 512, t, 0, 0, 0, *(f32*)(p + 76));
    else func_0011c4b0(h, o + 512);
}

void func_0016d920(Vec4** p) {
    Vec4 b;
    Vec4 a;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&b), "r"(p[1]) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&a), "r"(p[0]) : "$8", "memory");
    *(f32*)p = func_0017d160(&a, &b);
}

// Formats the model path "obj/%s.mdlx" for an entry into buf (or a shared buffer).
char* func_0016f470(u8* e, char* buf) {
    if (!buf) buf = D_004f63b0;
    func_002fee78(buf, D_0036c440, e + 8);
    return buf;
}

static inline s32 inRange(s32 v) {
    if (v == 0) return 0;
    if (v < 7) return 1;
    return 0;
}

s32 func_0017a538(u8* p) {
    s32 r = 0;
    if (func_0016a070(p) == 1) r = inRange(*(s32*)(p + 2896));
    return r;
}

void func_00180c88(u8* p, u32 a, f32 x) {
    u32 t = *(u32*)(p + 256);
    if (!t) f17f488((s32)p, a, x, 0.0f);
    else func_001802d8(*(u32*)(p + 252), t, *(u32*)(p + 240), *(u32*)(p + 8), a, 0);
}

void func_00185e78(u32 a) {
    u8* e = 0;
    while ((e = (u8*)func_00185da8(e)) != 0) {
        u32 t = *(u32*)(e + 2088);
        if (t) func_001b7df0(t, a);
    }
}

s32 func_001997c0(u32* p) {
    switch (func_0016e920(*p)[4]) {
    case 4: case 13: case 21: case 23: return 1;
    }
    return 0;
}

void func_001a2618(u8* p, s32 n) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        if (q[11] + n > 100) n = 100 - q[11];
        q[11] += n;
    }
    *(u16*)(p + 396) += n;
    *(u16*)(p + 404) += n;
}

void func_00192800(u32, u32, Words6*);  // to_192528
s32 func_001c9db0(u32);
void func_001ac378(void*, u32, u32, u32, u32, u32, u32);
void func_001aa668(void*, void*);
u32 func_001b1400(u32);
void func_001682b8(u32, u32);
s32 func_001b5cb8(u8*);
void func_001b8450(void*, u32, u32);
s32 func_001bb4a0(void);
void func_001c11a8(u32);
void func_00177dc8(void*, u32, u32, u32, u32);
void func_001d56f0(void*);  // zero_three_words
void func_001d16f8(void*);
void func_0014f688(u32, u32, u32, u32, u32);
void func_001d1950(void*, u32);
void func_001e2c00(u32);
void func_001e6c00(u32);  // alloc_336_align_171
void func_001e6000(void*);  // obj_dec_timer

extern void* D_00350bf0[];
extern u8* D_01d48cb0;
extern u8* D_01d49320;
extern void* D_003521e0[];

struct Slot20 { u8 b[20]; };
struct SlotPool {
    Slot20 slot[8];
    s32 free[8];
    s32 nfree;
};
extern SlotPool D_01d48cc8;

struct Pair72 {
    u32 a;
    s32 id;
    u8 pad[32];
    u8 x[16];
    u8 y[16];
};
extern Pair72 D_00354bf0[];


void func_00192818(u32 a, u32 b, Words6 s) {
    func_00192800(a, b, &s);  // to_192528
}

s32 func_001a8c78(u8* p, s32 n) {
    s32 r = 0;
    u8* q = p + n;
    if (n == 0 || (*q & 0x80) || func_001c9db0(*q & 0x1f)) r = 1;
    return r;
}

void func_001ac858(u8* p, u32 a) {
    func_001ac378(p, 4, 3, a, 0, 256, 365);
    *(u32*)(p + 100) = 4;
    *(void**)p = D_00350bf0;
    func_001aa668(p + 12, p);
}

u32 func_001b1448(u32 a) {
    u32 r = func_001b1400(a);
    if (r) func_001682b8(a, r);
    return r;
}

void* func_001b5a10(void) {
    if (!D_01d48cb0) return 0;
    if (func_001b5cb8(D_01d48cb0)) return *(u8**)(D_01d48cb0 + 12) + 128;
    return D_01d48cb0 + 24;
}

// Takes a slot from the free list and initialises it.
void* func_001b8680(u32 a, u32 b) {
    SlotPool* pool = &D_01d48cc8;
    Slot20* s = &pool->slot[pool->free[--pool->nfree]];
    func_001b8450(s, a, b);
    return s;
}

void func_001ced10(u8* p, u32 a, u32 b, u32 c) {
    func_00177dc8(p, a, 0, b, c);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2928) = 0;
    *(void**)p = D_003521e0;
    func_001d56f0(p + 2932);  // zero_three_words
    *(u32*)(p + 1420) |= 4;
}

void func_001d18c0(u8* p) {
    func_001d16f8(p);
    u32 t = *(u32*)(p + 4);
    if (t) func_0014f688(t, *(u32*)(p + 8), *(u32*)(p + 32), *(u32*)(p + 36), *(u32*)(p + 28));
    func_001d1950(p, *(u32*)(p + 20));
}

void func_001e60b0(void) {
    for (Pair72* e = D_00354bf0; e->id >= 0; e++) {
        func_001e6000(e->x);  // obj_dec_timer
        func_001e6000(e->y);  // obj_dec_timer
    }
}

void func_002f4000(void*);  // vu_store_w_splat
s32 func_00139d78(void*);
void func_0023f0c8(void*, s32);
u8* func_001058e8(void);
s32 func_0024ac88(void);
void func_002839f0(s32);  // entry416_by_masked_index
void* func_002be908(void*);
void func_002c1dc0(void);
s32 func_00190140(void*);
void func_002c04c8(void*, void*, void*);
void func_002c6490(void*);
void* func_001050d8(u32);
void func_002dc4e0(void*, u32, u32);
void func_002ceb08(void);
void func_002cc620(u32, u8*, u32);
void func_002eb6f8(u8*, s32);
void func_001c1748(void*, u32, u32, u32);  // obj_init_from_src
void func_00190128(void*);
void func_00103748(void);
void func_00170c00(u32);
void func_00103bb0(s32);
s32 func_00105c30(void);
void func_00239870(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);

extern u8* D_01d9e6e0;
extern s32 D_0035e360;
extern s32 D_0035e368;
struct Event32 {
    u32 type;
    u32 id;
    u32 a, b, c, d;
    u32 pad[2];
};
extern Event32 D_01dadc00[];
extern u8 D_00371eb8[];
struct Entry6 { u8 b[6]; };
extern Entry6 D_00371ea8[];
extern s16* D_0035f230;
extern u8* D_0035f2b8;
extern u8* D_01e2aa80;
extern u8* D_00361f60;
extern u32 D_003638c4;
extern u8 D_003638c0;
extern u8 D_003638c8;
extern void* D_003485b0[];
extern void* D_00347e60[];
extern void* D_00347f98[];
extern void** D_00347f80;
extern void* D_0034ee08[];

// Returns a random float in [0,1) from the VU0 random unit (hand-written VU0 macro code).
f32 func_00207260(void) {
    f32 r;
    asm volatile(
        "addi $8, $0, -1\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\t"
        "vadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(r) : : "$8");
    return r;
}

void func_0021f5d8(u8* p) {
    D_01d9e6e0[168] = 2;
    func_002f4000(p + 64);  // vu_store_w_splat
    *(f32*)(p + 172) = 1.0f;
}

struct BitWord {
    u32 lo : 7;
    u32 flag : 1;
    u32 hi : 24;
};

void func_00242d10(u8 on) {
    u8* p = func_001058e8() + 16800;
    ((BitWord*)(p + 4))->flag = on != 0;
}

void* func_0024b1a0(s32 n) {
    if (n == 1 && func_0024ac88()) return D_00371eb8;
    return &D_00371ea8[n];
}

// Counts set bits 0-5 and 7 of the flag word.
s32 func_0027ae20(void) {
    s32 n = 0;
    for (s32 i = 0; i < 7; i++) {
        if (i != 6) {
            if (!((*D_0035f230 >> i) & 1)) continue;
            n++;
        }
    }
    if (*(u16*)D_0035f230 & 0x80) n++;
    return n;
}

// Keeps the final call from becoming a sibling call.
struct NoTail {
    ~NoTail() {}
};

void func_00283618(void) {
    NoTail g;
    if (func_00139d78(D_0035f2b8 + 852)) return;
    if (!func_00139d78(D_0035f2b8 + 416)) func_002839f0(1);
}

static inline u8* nextNode(u8* p) {
    if (p == 0) return D_01e2aa80;
    return *(u8**)(p + 28);
}

s32 func_002bc7a8(u32 k) {
    s32 n = 0;
    u8* p = 0;
    while ((p = nextNode(p)) != 0) {
        if (p[49] == k) n++;
    }
    return n;
}

typedef void (*VFn)(void*);
struct EvSub {
    u8 pad[20];
    s32 cur;
};

void func_002be9b0(void) {
    void* o = 0;
    while ((o = func_002be908(o)) != 0) (*(VFn*)(*(u8**)o + 124))(o);
    func_002c1dc0();
}

s32 func_002c0470(u8* p) {
    if (!func_00190140(p + 100)) return 0;
    func_002c04c8(p, p + 48, p + 64);
    func_002c6490(p);
    return 1;
}

void func_002dc278(u32 a, u32 b) {
    func_002dc4e0(func_001050d8(0x80a0), a, b);
}

void func_002e3c28(u8** a) {
    u8* x = *(u8**)(a[0] + 4);
    u32 y = *(u32*)(a[1] + 4);
    if (!x) return;
    u32 z = *(u32*)(x + 1288);
    if (!z) return;
    if (!y) return;
    func_002cc620(z, x, y);
}

void func_002eb9d8(u32, u8* o, s32 k) {
    u32 fl = *(u32*)(o + 352);
    EvSub* s = (EvSub*)(o + 320);
    if (!(fl & 4)) {
        if (!(fl & 0x10)) return;
        if (k == 252) return;
    }
    if (s->cur == k) return;
    func_002eb6f8(o, k);
}

void func_002ed508(u8* p, u8* q, u32 c, u32 d, u32 e) {
    func_001c1748(p, *(u32*)(q + 2548), d, e);  // obj_init_from_src
    *(u32*)(p + 80) = c;
    func_00190128(p + 100);
    *(u32*)(p + 120) = 0;
}

void func_002ef708(void) {
    func_00103748();
    func_00170c00(D_003638c4);
    D_003638c4 = 0;
    func_00103bb0(-1);
    D_003638c0 = 0;
    D_003638c8 = 0;
}

// Region code: 'US', 'JP' or 'EU'.
u32 func_002efbb8(void) {
    switch (func_00105c30()) {
    case 2: return 21333;
    case 1: case 8: return 20554;
    }
    return 21829;
}

void func_0031afa8(void** p) {
    *p = D_003485b0;
    func_00239870((u8*)p + 436);
    *p = D_00347e60;
    func_00239870((u8*)p + 24);
    *p = D_00347f98;
}

void func_0031d978(void** p) {
    *p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    ((void (*)(void*, void*))((void**)*o)[1])(o, p);
}

void func_00324b08(void** p) {
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}

void u_tail0_0014d008(void) {
    func_0014cfc8();
    func_0014c908();
    func_002f33f0((void*)func_0014cf18);
    func_0014d308();
    func_00102788(D_0032b91c, 0, 0xc3500, (void*)func_0014cf88);
}

void f17f488(s32 a, s32 b, f32 x, f32 y) {
    func_0017f380(a);  // obj_walk_children
    func_0017f268(a, b, x, y);
}

void MISSION_Activate2d(void* m) {
    if (func_001bb4a0()) {
        u8 c = *(*(u8**)(D_01d49320 + 8) + 8);
        if (c) func_001c11a8(c);
    }
}

void EFFECT_kill(void* e) {
    u8* p = (u8*)e;
    *(u32*)(p + 8) |= 0x10001;
    if (*(u32*)(p + 28)) {
        func_001e2c00(*(u32*)(p + 28));
        func_001e6c00(*(u32*)(p + 28));  // alloc_336_align_171
        *(u32*)(p + 28) = 0;
    }
}

u32 wtarget_002342f0(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Event32* e = &D_01dadc00[i];
    e->type = 7;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

void Layout_setNum(void* l, s32 n, s32 m) {
    func_00139d78(l);
    *(s32*)((u8*)l + 140) = n;
    *(s32*)((u8*)l + 152) = n;
    func_0023f0c8(l, m);
}

void u_tail4_002e2d88(u32 a, u32 b, u32, u32) {
    u8 c = b;
    u8* p = D_00361f60;
    if (p) func_002ceb08();
    *(u32*)(p + 276) = a;
    p[280] = c;
}
