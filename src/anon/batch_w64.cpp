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
// 00102818: moved to src/global/unit_001022c0.cpp

// ---------------------------------------------------------------------------
s32 strlen(void*);  // strlen
s32 strncmp(void*, u32, s32);
extern u32 D_0033cbb8[];

// Returns the index of the first of 19 table entries the check rejects (0 if none).
// 00105f00: moved to src/common/world.cpp

// ---------------------------------------------------------------------------
s32 func_0010f6f8(u8* p, f32 f);  // 0x0010f6f8: definition moved into src/anon/unit_0010f338.cpp

// ---------------------------------------------------------------------------
void func_0011ee18(void*);  // obj_ctor_347940
extern char D_00347a28[];
struct Entry20648 { u32 b0 : 1; u32 m : 28; u32 b29 : 1; u32 hi : 2; u32 pad[7]; };
struct Hdr20648 { u8 pad[0x1c]; s32 n; Entry20648 e[1]; };

// Constructor: base ctor, vtable, then collect flag bits from the entry list.
void func_00120648(u8* self);  // 0x00120648: definition moved into src/anon/unit_00120648.cpp

// ---------------------------------------------------------------------------
u16* func_001a9130(void);
struct Pair36fd0 { u32 a; u32 b; };
struct Flag36fd0 { u32 pad[3]; u32 f0 : 1; u32 f1 : 1; u32 rest : 30; };
extern Flag36fd0 D_00347d30[];
void func_00137058(Pair36fd0*);
void func_00137180(Pair36fd0*);
union Half36fd0 { u16 h[2]; u32 w; };

// 00136fd0: moved to src/harata/libdk/bgm.cpp

// ---------------------------------------------------------------------------
void func_00139598(u8*);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_00138840(u8*);
extern f32 D_00349e14;

void func_00137560(u8* p);  // 0x00137560: definition moved into src/anon/unit_001374c8.cpp

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

// 00155830: moved to src/anon/unit_00153ea0.cpp
s32 func_00155830(s32 a0, f32* a1, f32* a2, f32* a3);

// ---------------------------------------------------------------------------
void func_00239f18(u8*);  // obj_set_float312_and_flags
void func_00138c68(u8*, s32, s32);

// 00155b58: moved to src/anon/unit_00153ea0.cpp
void func_00155b58(u8* p, s32 idx, f32 f);

// ---------------------------------------------------------------------------
extern V16 D_0034a9c0;
extern V16 D_0034a9d0;
extern f32 D_0034a9e0;
extern f32 D_0034a9e4;

// 00158ac8: moved to src/harata/libdk/bookcamera.cpp

// ---------------------------------------------------------------------------
extern u8* D_004f3b38;
void func_00160488(u8*, u8, u8, u8);  // mix_color_channels
static inline u8* next_611a8(u8* n) {
    if (!n) return D_004f3b38;
    return *(u8**)(n + 128);
}

// Applies func_00160488 to every node of the list.
// 001611a8: moved to src/anon/unit_001611a8.cpp

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

// 0016d8d0: moved to src/anon/unit_0016d2e0.cpp

// ---------------------------------------------------------------------------
s32 func_00170c38(void);
extern u8* D_0034dca0;
static inline u8* next_70c50(u8* n) {
    if (!n) return D_0034dca0;
    return *(u8**)(n + 60);
}

s32 func_00170c50(void);  // 0x00170c50: definition moved into src/anon/unit_0016e8f8.cpp

// ---------------------------------------------------------------------------
s32 func_00190140(u8*);
void func_00159130(u8*);

// 00178a50: moved to src/yasui/libys/player.cpp

// ---------------------------------------------------------------------------
struct Ent82e08 { u32 a, b, c; };
extern Ent82e08 D_01c60588[];
extern s32 D_0034ed00;
u32 func_0019b328(u32, u32);

// 00182e08: moved to src/anon/unit_00182780.cpp

// ---------------------------------------------------------------------------
void func_0016bd60(u8*, s32);
void ys_obj_fly_to_jump(u8* self) asm("_ZN2YS3OBJ11fly_to_jumpEv");

// 001846f8: moved to src/anon/unit_00183088.cpp

// ---------------------------------------------------------------------------
void func_001dcb98(u32, u8*);

void func_001942b8(u8* p);  // 0x001942b8: definition moved into src/anon/unit_00193be8.cpp

// ---------------------------------------------------------------------------
s32 func_00199810(u8*);
void func_0016ed50(u32, s32, s32);

void func_00199d38(u8* p);  // 0x00199d38: definition moved into src/anon/unit_00199688.cpp

// ---------------------------------------------------------------------------
s32 func_0019ad58(u8*);
void func_0019ae60(u8*);
s32 func_0019ad00(u8*, u8);

s32 func_0019ac80(u8* p);  // 0x0019ac80: definition moved into src/anon/unit_00199688.cpp

// ---------------------------------------------------------------------------
s32 func_001c8ab0(u8*);
extern u32 D_0034f240;
void func_0019cc20(u8*);
void func_0019cd40(u8*);
void func_0019ce48(u8*);
void func_0019d260(u8*);

void func_0019d188(u8* p);  // 0x0019d188: definition moved into src/anon/unit_0019ba60.cpp

// ---------------------------------------------------------------------------
struct LightPool { u8 ent[16][40]; s32 idx[16]; s32 count; };
extern LightPool D_01d44108;
struct LightList { u8* head; u8* tail; };
extern LightList D_01d44100;
void func_001b1a30(u8*, s32);
u8* ys_light_create(s32 t) asm("_ZN2YS5LIGHT6CreateEi");

// Takes a light from the free pool, initialises it and appends it to the active list.
// 001b1928: YS::LIGHT::Create, moved to src/anon/unit_001b14d8.cpp

// ---------------------------------------------------------------------------
extern u8 D_003511c0;
extern u32 D_003511b8;
extern u32 D_01d48cb8;
void sceGsSyncPath(s32, s32);

void func_001b7f88(void);  // 0x001b7f88: definition moved into src/anon/unit_001b6a50.cpp

// ---------------------------------------------------------------------------
s32 func_001d5460(u32);
extern u32 D_01d49324;
void func_001d7940(void);
void func_001ada38(s32);
void func_001bb468(void);
void func_00199098(u8*, s32);
void func_0019f070(u8*, u32);

// 001bbba8: moved to src/yasui/libys/mission.cpp

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
void func_001cff48(u8* p);  // 0x001cff48: definition moved into src/anon/unit_001cf0b0.cpp

// ---------------------------------------------------------------------------
struct B4 { u8 b[4]; };
extern B4 D_01d5ba58[];
extern B4 D_0036e4d0[];
void func_0013d550(u32, u32);

void func_001d4818(u32* p, s32 a1, u32 a2, u32 a3, u32 a4);  // 0x001d4818: definition moved into src/anon/unit_001d3c08.cpp

// ---------------------------------------------------------------------------
u8* func_00102788_p(void*, u32, u32, void*) asm("func_00102788");
extern char D_001dd2b8[];
extern char D_001dd920[];
extern char D_001dda78[];
extern char D_001ddb30[];

u8* func_001ddb78(void* a0, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x001ddb78: definition moved into src/anon/unit_001dd920.cpp

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
void sceVu0MulMatrix(void*, void*, void*);
void sceVu0CopyMatrix(void*, void*);

void func_00209df0(u8* p, u32 a1, u8* r) {
    NoTail nt;
    u8* b = p + *(s32*)(*(u8**)(r + 12) + 4);
    sceVu0MulMatrix(D_01d9e6e8 + 80, b + 224, D_01d9e6e8 + 16);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e730, D_01d9e6e8 + 80);
    sceVu0CopyMatrix(b + 160, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
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

void func_0028cdb8(s32 i);  // 0028cdb8: moved to src/anon/unit_0028c878.cpp

// ---------------------------------------------------------------------------
void func_0028ff68(u8** p);  // 0028ff68: moved to src/anon/unit_0028f1e0.cpp

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
void func_002ca0e0(u8* p);  // 0x2ca0e0: moved to src/anon/unit_002ca0e0.cpp


// ---------------------------------------------------------------------------
u8* func_001050d8(u32);
void func_002cb5d8(u8*, f32);
void func_002cd290(u8*, u32, u32);

u8* func_002cd1d8(u32 a, u32 b);  // 0x002cd1d8: definition moved into src/taito/path.cpp

// ---------------------------------------------------------------------------
extern u32 D_00361f60;
void func_00184540(V16*, u32, f32, f32);
void func_002e10d0(V16*, u32);

// Builds a vector, sets w = 0 and transforms it by the current view matrix.
// 002e1908: moved to src/anon/unit_002e1908.cpp

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
