#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
struct V16 { u128 q; };

// Disables sibling calls (empty destructor keeps a cleanup pending).
struct NoTail { ~NoTail() {} };

extern "C" {

typedef void (*VFn)(void*);
typedef s32 (*IFn)(void*);

// Quadword copy, skipped when source and destination are the same.
static inline void vcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// ---------------------------------------------------------------------------
u8* func_00102788(void*, u32, u32, u32);
typedef u8* (*AllocFn)(void*, u32, void*);

// Allocates a block (size + 256) from the heap, tagged with the caller's address,
// then builds the object via func_00102788 and links the block to it.
u8* func_00102818(void** heap, u32 a1, u32 a2, u32 a3, u32 size) {
    u8* blk = (*(AllocFn*)*heap)(heap, size + 256, __builtin_return_address(0));
    u8* r = func_00102788(heap, a1, a2, a3);
    *(u32*)(blk + 252) = size;
    blk[240] = 0;
    *(u32*)(blk + 244) = 0;
    *(u32*)(blk + 248) = 0;
    *(u32*)(r + 52) = (u32)blk;
    return r;
}

// ---------------------------------------------------------------------------
s32 func_002ff3fc(void*);  // strlen
s32 func_002ff538(void*, u32, s32);
extern u32 D_0033cbb8[];

// Returns the index of the first of 19 table entries the check rejects (0 if none).
s32 func_00105f00(void* p) {
    if (func_002ff3fc(p) == 2) {  // strlen
        for (s32 i = 0; i < 19; i++) {
            if (func_002ff538(p, D_0033cbb8[i], 2) == 0) return i;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
s32 func_0010f6f8(u8* p, f32 f) {  // count_reached_threshold_b
    if (*(u32*)(p + 2040) & 4) return 0;
    u8* q = *(u8**)(p + 1164);
    if (q) {
        s32 lim = (s32)((f32)*(s32*)(q + 388) * f);
        if (*(s32*)(q + 384) < lim) return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
void func_0011ee18(void*);  // obj_ctor_347940
extern char D_00347a28[];
struct Entry20648 { u32 b0 : 1; u32 m : 28; u32 b29 : 1; u32 hi : 2; u32 pad[7]; };
struct Hdr20648 { u8 pad[0x1c]; s32 n; Entry20648 e[1]; };

// Constructor: base ctor, vtable, then collect flag bits from the entry list.
void func_00120648(u8* self) {
    func_0011ee18(self);  // obj_ctor_347940
    Hdr20648* h = *(Hdr20648**)(self + 4);
    *(u32*)self = (u32)D_00347a28;
    for (s32 i = 0; i < h->n; i++) {
        if (h->e[i].b0) *(u32*)(self + 12) |= 1;
        if (h->e[i].b29) *(u32*)(self + 12) |= 2;
    }
}

// ---------------------------------------------------------------------------
u16* func_001a9130(void);
struct Pair36fd0 { u32 a; u32 b; };
struct Flag36fd0 { u32 pad[3]; u32 f0 : 1; u32 f1 : 1; u32 rest : 30; };
extern Flag36fd0 D_00347d30[];
void func_00137058(Pair36fd0*);
void func_00137180(Pair36fd0*);
union Half36fd0 { u16 h[2]; u32 w; };

void func_00136fd0(void) {
    Half36fd0* v = (Half36fd0*)func_001a9130();
    union { u32 w[2]; u16 h; } s;
    s.w[0] = v->h[0];
    s.w[1] = v->h[1];
    for (s32 i = 0; i < 2; i++) {
        D_00347d30[i].f0 = 0;
        D_00347d30[i].f1 = 0;
    }
    if (s.w[0] == s.w[1]) func_00137058((Pair36fd0*)&s);
    else func_00137180((Pair36fd0*)&s);
}

// ---------------------------------------------------------------------------
void func_00139598(u8*);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_00138840(u8*);
extern f32 D_00349e14;

void func_00137560(u8* p) {
    if (0.0f < *(f32*)(p + 436)) {
        *(f32*)(p + 436) = *(f32*)(p + 436) - D_00349e14;
        func_00139598(p);
        return;
    }
    f32 lim = -20000.0f;
    if (lim < *(f32*)(p + 436)) {
        func_002ba2e8(10, 0);
        *(f32*)(p + 436) = lim;
    }
    func_001395a8(p);
    func_00138840(p);
}

// ---------------------------------------------------------------------------
void func_0014fcd8(u8*);
s32 func_00139538(u8*);
void func_00138c40(u8*, s32, u32);
void func_0023acd8(u8*);

void func_00152318(u8* p) {
    func_0014fcd8(p);
    if (func_00139538(p + 48)) {
        (*(VFn*)(*(u8**)p + 20))(p);
        return;
    }
    func_00138c40(p + 48, 0, *(u32*)(p + 36));
    for (s32 i = 0; i < *(s32*)(p + 2896); i++) func_0023acd8(p + 456 + i * 344);
}

// ---------------------------------------------------------------------------
f32 func_0017ce10(f32);

s32 func_00155830(s32 a0, f32* a1, f32* a2, f32* a3) {
    if (a0 < 60) return 1;
    f32 t = (f32)(a0 - 60) * 3.0f;
    *a2 = t;
    *a1 = t / 100.0f;
    *a3 = -4.71238852f;
    *a3 = func_0017ce10(-4.71238852f);
    return 0;
}

// ---------------------------------------------------------------------------
void func_00239f18(u8*);  // obj_set_float312_and_flags
void func_00138c68(u8*, s32, s32);

void func_00155b58(u8* p, s32 idx, f32 f) {
    func_00239f18(p + idx * 412 + 6728);  // obj_set_float312_and_flags
    if (idx == 9) func_00138c68(p + 11236, -(s32)(f * 100.0f), 0);
}

// ---------------------------------------------------------------------------
extern V16 D_0034a9c0;
extern V16 D_0034a9d0;
extern f32 D_0034a9e0;
extern f32 D_0034a9e4;

void func_00158ac8(u8* p) {
    vcopy(&D_0034a9c0, p + 144);
    vcopy(&D_0034a9d0, p + 112);
    D_0034a9e0 = *(f32*)(p + 72);
    D_0034a9e4 = *(f32*)(p + 80);
}

// ---------------------------------------------------------------------------
extern u8* D_004f3b38;
void func_00160488(u8*, u8, u8, u8);  // mix_color_channels
static inline u8* next_611a8(u8* n) {
    if (!n) return D_004f3b38;
    return *(u8**)(n + 128);
}

// Applies func_00160488 to every node of the list.
void func_001611a8(u8 a, u8 b, u8 c) {
    u8* n = 0;
    while ((n = next_611a8(n))) func_00160488(n, a, b, c);  // mix_color_channels
}

// ---------------------------------------------------------------------------
// Sphere overlap: |a - b| <= a.r + b.r (radius in word 4).
s32 func_00163210(f32* a, f32* b) {
    u32 t[4] __attribute__((aligned(16)));
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(t), "r"(a), "r"(b) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(t) : "$8", "memory");
    if (d <= a[4] + b[4]) return 1;
    return 0;
}

// ---------------------------------------------------------------------------
void func_0017d698(V16*, u32, u32, f32);
extern V16 D_004f62a0;

void func_0016d8d0(u32* p) {
    V16 tmp;
    func_0017d698(&tmp, p[0], p[1], *(f32*)(p + 2));
    vcopy(&D_004f62a0, &tmp);
    *(V16**)p = &D_004f62a0;
}

// ---------------------------------------------------------------------------
s32 func_00170c38(void);
extern u8* D_0034dca0;
static inline u8* next_70c50(u8* n) {
    if (!n) return D_0034dca0;
    return *(u8**)(n + 60);
}

s32 func_00170c50(void) {
    if (func_00170c38()) return 1;
    u8* n = 0;
    while ((n = next_70c50(n))) {
        bool dead = !(*(s32*)(n + 40) < 10000);
        if (dead) continue;
        u8 k = n[1];
        if (!k) continue;
        if (k != 3) return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
s32 func_00190140(u8*);
void func_00159130(u8*);

void func_00178a50(u8* p, u8* q) {
    if (!func_00190140(*(u8**)(p + 2884) + 12)) return;
    switch (q[29]) {
    case 1:
        func_00159130(*(u8**)(p + 2884) + 12);
        break;
    case 3:
        if (*(u8**)(p + 2880) && func_00190140(*(u8**)(p + 2880) + 4))
            func_00159130(*(u8**)(p + 2880) + 4);
        break;
    }
}

// ---------------------------------------------------------------------------
struct Ent82e08 { u32 a, b, c; };
extern Ent82e08 D_01c60588[];
extern s32 D_0034ed00;
u32 func_0019b328(u32, u32);

u32 func_00182e08(u32 a0) {
    for (s32 i = 0; i < D_0034ed00; i++) {
        u32 r = func_0019b328(D_01c60588[i].c, a0);
        if (r) return r;
    }
    return 0;
}

// ---------------------------------------------------------------------------
void func_0016bd60(u8*, s32);
void ys_obj_fly_to_jump(u8* self) asm("_ZN2YS3OBJ11fly_to_jumpEv");

// Sets up a ballistic jump: time from distance, initial height offset, target copy.
void ys_obj_fly_to_jump(u8* self) {
    func_0016bd60(self, 1);
    f32 t = *(f32*)(self + 2148) / 0.408163249f;
    *(u32*)(self + 220) = 0;
    *(u32*)(self + 212) = 0;
    *(f32*)(self + 208) = t;
    *(f32*)(self + 216) = *(f32*)(self + 1348) - t * 0.408163249f * t * 0.5f;
    vcopy(self + 32, self + 2144);
}

// ---------------------------------------------------------------------------
void func_001dcb98(u32, u8*);

void func_001942b8(u8* p) {
    for (s32 i = 0; i < 16; i++) {
        u32 x = *(u32*)(p + 1976 + i * 4);
        if (x) func_001dcb98(x, p + 1880);
    }
}

// ---------------------------------------------------------------------------
s32 func_00199810(u8*);
void func_0016ed50(u32, s32, s32);

void func_00199d38(u8* p) {
    for (s32 i = 0; i < *(u16*)(*(u8**)(p + 8) + 4); i++) {
        if (func_00199810(*(u8**)(p + 8) + i * 64 + 44))
            func_0016ed50(*(u32*)(*(u8**)(p + 8) + i * 64 + 44), -1, 30);
    }
}

// ---------------------------------------------------------------------------
s32 func_0019ad58(u8*);
void func_0019ae60(u8*);
s32 func_0019ad00(u8*, u8);

s32 func_0019ac80(u8* p) {
    if (p[32] >= 200) return 0;
    s32 n = func_0019ad58(p);
    if ((*(u8**)(p + 8))[34] < n) return 0;
    while (1) {
        func_0019ae60(p);
        if (func_0019ad00(p, p[32])) return 1;
        if (p[32] >= 200) return 0;
    }
}

// ---------------------------------------------------------------------------
s32 func_001c8ab0(u8*);
extern u32 D_0034f240;
void func_0019cc20(u8*);
void func_0019cd40(u8*);
void func_0019ce48(u8*);
void func_0019d260(u8*);

void func_0019d188(u8* p) {
    u8* o;
    if (func_001c8ab0(p) == 1 || (D_0034f240 & 0x4000) || !(o = *(u8**)(p + 40)) ||
        (*(u32*)(*(u8**)(o + 12) + 8) & 0x20000)) {
        func_0019cc20(p);
        return;
    }
    if ((*(IFn*)(*(u8**)o + 64))(o)) {
        func_0019cd40(p);
        func_0019ce48(p);
    }
    func_0019d260(p);
}

// ---------------------------------------------------------------------------
struct LightPool { u8 ent[16][40]; s32 idx[16]; s32 count; };
extern LightPool D_01d44108;
struct LightList { u8* head; u8* tail; };
extern LightList D_01d44100;
void func_001b1a30(u8*, s32);
u8* ys_light_create(s32 t) asm("_ZN2YS5LIGHT6CreateEi");

// Takes a light from the free pool, initialises it and appends it to the active list.
u8* ys_light_create(s32 t) {
    s32 n = --D_01d44108.count;
    u8* l = D_01d44108.ent[D_01d44108.idx[n]];
    func_001b1a30(l, t);
    if (!D_01d44100.tail) {
        D_01d44100.tail = l;
        D_01d44100.head = l;
    } else {
        *(u8**)(D_01d44100.tail + 4) = l;
        D_01d44100.tail = l;
    }
    *(u8**)(l + 4) = 0;
    return l;
}

// ---------------------------------------------------------------------------
extern u8 D_003511c0;
extern u32 D_003511b8;
extern u32 D_01d48cb8;
void func_002f25a0(s32, s32);

void func_001b7f88(void) {
    if (D_003511c0) {
        func_002f25a0(0, 0);
        D_01d48cb8 = D_003511b8;
    }
    D_003511c0 = 0;
}

// ---------------------------------------------------------------------------
s32 func_001d5460(u32);
extern u32 D_01d49324;
void func_001d7940(void);
void func_001ada38(s32);
void func_001bb468(void);
void func_00199098(u8*, s32);
void func_0019f070(u8*, u32);

void func_001bbba8(s32 m) {
    s32 id = -1;
    u8 buf[48];
    switch (m) {
    case 3:
        if (func_001d5460(D_01d49324)) func_001d7940();
        id = 139;
        break;
    case 4:
        func_001ada38(9);
        id = 141;
        break;
    }
    func_001bb468();
    func_00199098(buf, id);
    func_0019f070(buf, 0x40000000);
}

// ---------------------------------------------------------------------------
extern char D_00352360[];
extern char D_0034e8b8[];
extern char D_0034ee08[];
extern char D_00351eb8[];
extern char D_00351ec0[];
void func_001c8d98(void*, s32);
void func_001c9b90(void);
void func_001d2710(u8*);
void func_00319f88(u8*);
void func_0019f9a8(u8*);  // array8_free_slots
void func_001c0248(u8*);
void func_00319fb0(u8*);  // big_obj_dtor
void func_00105110(u8*);

// Deleting destructor.
void func_001cff48(u8* p) {
    *(void**)p = D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(p + 2932);
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

// ---------------------------------------------------------------------------
struct B4 { u8 b[4]; };
extern B4 D_01d5ba58[];
extern B4 D_0036e4d0[];
void func_0013d550(u32, u32);

void func_001d4818(u32* p, s32 a1, u32 a2, u32 a3, u32 a4) {
    p[0] = a1;
    func_0013d550(a2, a3);
    p[1] = a4;
    if (a1 == 3) {
        for (u32 i = 0; i < 3; i++) D_01d5ba58[i] = D_0036e4d0[i];
    }
}

// ---------------------------------------------------------------------------
u8* func_00102788_p(void*, u32, u32, void*) asm("func_00102788");
extern char D_001dd2b8[];
extern char D_001dd920[];
extern char D_001dda78[];
extern char D_001ddb30[];

u8* func_001ddb78(void* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    func_00102788_p(a0, a1, a2, D_001dd2b8);
    func_00102788_p(a0, a1, a3, D_001dd920);
    u8* r = func_00102788_p(a0, a1, a4, D_001dda78);
    *(void**)(r + 48) = D_001ddb30;
    return r;
}

// ---------------------------------------------------------------------------
union Word1fb928 { f32 f; u16 h[2]; u32 w; };
void func_001fab48(u8*, u32*, u8*);

void func_001fb928(u8* p, u32* q, u8* r) {
    Word1fb928* d = (Word1fb928*)(p + **(s32**)(r + 12) + 160);
    func_001fab48(p, q, r);
    Word1fb928* s = (Word1fb928*)q;
    if (s[0].w == *(u32*)(p + 12)) {
        d[8].f = s[3].f;
        d[10].f = s[4].h[0];
        d[11].f = s[4].h[1];
    }
}

// ---------------------------------------------------------------------------
extern u8* D_01d9e6e8;
extern char D_01d9e730[];
extern char D_01d9e8c0[];
void func_002f3d08(void*, void*, void*);
void func_002f3f98(void*, void*);

void func_00209df0(u8* p, u32 a1, u8* r) {
    NoTail nt;
    u8* b = p + *(s32*)(*(u8**)(r + 12) + 4);
    func_002f3d08(D_01d9e6e8 + 80, b + 224, D_01d9e6e8 + 16);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e730, D_01d9e6e8 + 80);
    func_002f3f98(b + 160, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}

// ---------------------------------------------------------------------------
extern f32 D_00359a20[];

// Rotation matrix about X from a 16-bit angle (sine table lookup).
void func_0021e9d0(f32* m, u32 a) {  // table_float_pair_lookup_c
    f32 s = D_00359a20[(a >> 4) & 0xfff];
    f32 c = D_00359a20[((a + 0x4000) >> 4) & 0xfff];
    m[0] = 1.0f; m[4] = 0; m[8] = 0; m[12] = 0;
    m[1] = 0; m[5] = c; m[9] = -s; m[13] = 0;
    m[2] = 0; m[6] = s; m[10] = c; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}

// ---------------------------------------------------------------------------
struct Bits239f78 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };

// Sets the scale z and flags whether the scale differs from (1,1,1).
void func_00239f78(u8* p, f32 f) {
    *(f32*)(p + 316) = f;
    s32 b = 0;
    if (!(*(f32*)(p + 308) == 1.0f && *(f32*)(p + 312) == 1.0f && f == 1.0f)) b = 1;
    ((Bits239f78*)(p + 184))->b1 = b;
}

// ---------------------------------------------------------------------------
void func_0023d2b0(void);
void func_00253638(void);
void func_00257000(void);
extern u8 D_00349e20;
extern u32 D_00349e1c;
extern u8 D_0035eb50;
extern u32 D_0035eb54;

void func_0023d260(void) {
    func_0023d2b0();
    func_00253638();
    func_00257000();
    D_0035eb50 = D_00349e20 == 0;
    D_0035eb54 = D_00349e1c;
}

// ---------------------------------------------------------------------------
struct Ent253330 { s16 id; u8 pad[14]; };
extern Ent253330 D_003726d0[];

// Returns the last table entry with the given id (table ends at a negative id).
Ent253330* func_00253330(s32 key) {
    Ent253330* r = 0;
    for (s32 i = 0; D_003726d0[i].id >= 0; i++)
        if (D_003726d0[i].id == key) r = &D_003726d0[i];
    return r;
}

// ---------------------------------------------------------------------------
u8* func_00257770(void);
s32 func_00139d78(void*);
s32 func_0028acc8(u32);
extern u32 D_0035f020;
extern u32 D_0035f024;
void func_0027e920(void);

void func_002630d8(void) {
    NoTail nt;
    u8* o = func_00257770();
    if (func_00139d78(o + 408)) return;
    if (func_00139d78(o + 2068)) return;
    if (func_00139d78(o + 1224)) return;
    if (func_0028acc8(D_0035f020)) return;
    if (func_0028acc8(D_0035f024)) return;
    func_0027e920();
}

// ---------------------------------------------------------------------------
u8* func_00167f18(s32);
extern u8* D_0035f2cc;
void func_00242618(s32, s32);
void func_002854d8(s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);

void func_00284fd8(void) {
    u8* v = func_00167f18(0);
    if (*(s32*)(D_0035f2cc + 824) != 8) return;
    u64 fl = *(u64*)(v + 8);
    if (fl & 4) {
        func_00242618(8, 1);
        func_002854d8(0xceca, 0);
        func_00287bd0(1, 0);
        func_00287cc0(0);
    } else if (fl & 8) {
        func_00242618(8, 1);
        func_002854d8(0xcecb, 1);
        func_00287bd0(2, 0);
        func_00287cc0(0);
    }
}

// ---------------------------------------------------------------------------
extern u8* D_0035f3fc;
extern u32 D_0035f410;

void func_0028cdb8(s32 i) {  // record408_alloc_init
    if (func_00139d78(D_0035f3fc + i * 408)) {
        u8* o = (u8*)(i * 408 + (u32)D_0035f3fc);
        (*(VFn*)(*(u8**)o + 20))(o);
        D_0035f410 |= 1 << i;
    }
}

// ---------------------------------------------------------------------------
void func_0028ff68(u8** p) {
    if (p[0] && func_00139d78(p[0])) (*(VFn*)(*(u8**)p[0] + 20))(p[0]);
    if (p[1] && func_00139d78(p[1])) (*(VFn*)(*(u8**)p[1] + 20))(p[1]);
}

// ---------------------------------------------------------------------------
extern char D_00361e38[];
extern char D_00347f98[];
extern char D_0035eb98[];
extern u8* D_00361e28;
void func_0031a838(u8*);
void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
void func_0028d140(u8*);
void func_00167f38(s32);
void func_002c5f48(void);

// Constructor; registers itself as the global instance.
void func_002ca0e0(u8* p) {
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00361e38;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 24) = 0;
    func_0031a838(p + 40);
    *(void**)(p + 28) = D_0035eb98;
    func_002369a0(p + 52);  // obj_ctor_36eac8
    func_0023c008(p + 76);  // obj_ctor_36eae8
    *(u32*)(p + 188) = 0;
    func_0028d140(p + 192);
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 640) = 0;
    *(u32*)(p + 644) = 0;
    *(u32*)(p + 648) = 0;
    *(u32*)&D_00361e28 = (u32)p;
    func_00167f38(3);
    func_002c5f48();
}

// ---------------------------------------------------------------------------
u8* func_001050d8(u32);
void func_002cb5d8(u8*, f32);
void func_002cd290(u8*, u32, u32);

u8* func_002cd1d8(u32 a, u32 b) {
    u8* o = func_001050d8(160);
    func_002cb5d8(o, 8.0f);
    o[134] = 0;
    *(u32*)(o + 12) = 32;
    *(u8**)(o + 128) = func_001050d8(1024);
    o[135] = 1;
    func_002cd290(o, a, b);
    return o;
}

// ---------------------------------------------------------------------------
extern u32 D_00361f60;
void func_00184540(V16*, u32, f32, f32);
void func_002e10d0(V16*, u32);

// Builds a vector, sets w = 0 and transforms it by the current view matrix.
V16* func_002e1908(V16* out, u32 a1, u32 a2) {
    V16 m[4];
    V16 t;
    func_00184540(out, a2, 0.800000012f, 0.800000012f);
    func_002e10d0(m, D_00361f60);
    ((u32*)out)[3] = 0;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&t), "r"(out), "r"(m) : "memory");
    vcopy(out, &t);
    return out;
}

// ---------------------------------------------------------------------------
struct Words9 { u32 w[9]; };
extern Words9 D_00363630;
void wt_002ed268(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002ed268jjjj");

void wt_002ed268(u32 a, u32 b, u32 c, u32 d) {
    D_00363630 = *(Words9*)a;
}

// ---------------------------------------------------------------------------
s32 func_002feac0(u32*);
u32 wt_002feb28(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002feb28jjjj");

// signal()-style handler install: returns the previous handler, -1 (errno 22) on bad signal.
u32 wt_002feb28(u32 a, u32 sig, u32 h, u32 d) {
    u32* p = (u32*)a;
    if (sig >= 32) {
        p[0] = 22;
        return (u32)-1;
    }
    if (!p[117]) {
        if (func_002feac0(p)) return (u32)-1;
    }
    u32* t = (u32*)p[117];
    u32 old = t[sig];
    t[sig] = h;
    return old;
}

// ---------------------------------------------------------------------------
extern char D_0034a548[];
extern char D_00347e80[];
void func_00239870(u8*);
void func_002361d0(u8*);

// Destructor: destroys the 13-element member array (408 bytes each) back to front.
void func_0031c1b0(u8* p) {
    *(u32*)p = (u32)D_0034a548;
    if (p != (u8*)-840) {
        u8* e = p + 6144;
        for (;;) {
            if (p + 840 == e) break;
            e -= 408;
            (*(VFn*)(*(u8**)e + 12))(e);
        }
    }
    func_00239870(p + 496);
    *(void**)(p + 48) = D_00347e80;
    func_002361d0(p + 80);
    *(void**)(p + 48) = D_00347f98;
    *(void**)p = D_00347f98;
}

}
