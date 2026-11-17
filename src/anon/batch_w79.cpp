#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

struct Q16Pair {
    Q16 v[2];
};

struct E1a5 { f32 f; u8 b4, b5, b6, b7; };

typedef s32 (*VF4)(void*, u8, s32, s32);

typedef void (*VF0)(void*);

typedef s32 (*VF24)(void*, f32*, f32);

struct S1c2 {
    u32 w[8];
    u8 b32[5];
    u8 pad37[3];
    u32 f40;
    u8 b44, b45, b46, b47;
    u8 b48;
    u8 pad49[3];
    u32 f52;
    f32 f56, f60, f64;
    s16 h68, h70, h72, h74, h76, h78, h80, h82;
    u32 f84, f88;
    f32 f92, f96;
    u32 f100, f104;
    f32 f108, f112;
    u32 f116;
};

typedef u8* (*AllocFn)(void*, s32, s32);

struct Ent8 { u32 id; u32 v; };

struct Rec40 { struct Ent8 e[5]; };

typedef void (*DtorFn)(void*);

typedef void (*FreeFn)(void*, void*);

struct S2bb { u8 pad0[16]; u32 f16; u32 f20; u32 f24; u8 pad28[12]; s16 h40; s16 pad42; s16 h44; u8 pad46[2]; u8 state; };

struct E16 { s8 id; u8 pad[15]; };

struct T294 { u8 pad[8]; s32 n; u8 pad12[4]; struct E16 e[1]; };

struct OBv { u32 f0; volatile s32 f4; s32 f8; volatile s32 f12; u8 pad16[32]; volatile s32 f48; u8 pad52[12]; Q16 v64; s32 f80; };

struct VB { u16 a, b, c, d; };

struct K36 { s16 h0; u8 pad[18]; s16* f20; u8 pad24[12]; };

struct KE { s16 h0; s16 h2; u16* f4; };

struct KG { u8 pad[16]; struct K36* f16; u8 pad20[4]; struct KE* f24; };

extern "C" {
void func_001ae590(void*, u32);
void func_001ae4c0(u32, u32, void*);
char** func_00105c48(s32);  // entry12_34cae4
s32 strncmp(const void*, const void*, u32);
void func_00105af8(s32);
extern u32 D_0033caf8;
void func_0013a6f8(void);
void func_00103bb0(s32);
u32 func_001050c8(void);
void func_00139f38(u32);
extern u32 D_0034b278;
void func_00153c60(void);
void func_001385c0(void);
void func_00109e18(void);
void func_0015df68(void);
void func_00140ce8(void);
void func_00161ee8(void);
void func_001618f0(void);
void func_001618b8(void);
void func_0015a810(void);
extern u8 D_00348d68[];
void func_0014f268(void*);
void func_0014f1c8(void*);
void func_0014f208(void);
void func_0014f118(void);
void func_0013d7d0(void);
extern char D_0032bae0[];
extern char D_0032bb10[];
s32 func_001051a0(const char*, const char*);
s32 func_001bc130(void);
void func_0015b2d0(void);
void func_0013d7c0(void);
void func_00192290(u8, s32);
void func_001ac778(void);
void func_001b8348(void);
void func_0016c750(u32);
void func_001900d0(void);
void func_001b9230(void);
void func_0017dec0(void);
void func_00185d98(void);
void func_001aeae0(void);
void func_00196a40(void);
void func_001a0bc0(void);
void func_0018d738(void);
void func_001a5f50(void);
void func_00199548(void);
void func_001a6a10(void);
void func_001b14d8(void);
void func_0019ec20(void);
void func_001b4300(void);
void func_00179be8(void);
void func_001c8a90(void);
void func_001d3b60(void);
void func_001d5a48(void);
void func_001a3a88(void);
void func_001ba718(void);
void func_001a5928(void);
void func_001b24c0(void);
void func_00182b18(void);
s32 func_00143d10(Q16Pair*, Q16*, void*, s32*);
Q16* func_0016c028(void*);  // obj_get_attach_or_alt
s32 func_0019b3d0(void*, Q16*);
void func_0018c438(void*);
s32 func_0019b308(void*);
void func_0018c650(void*, Q16*, u32, s32, s32, f32, f32);
extern s32 D_0035037c;
s32 func_00197028(s32);
void func_00196e00(void*);
void func_00105110(void*);
extern s32 D_01c61b40;
s32 func_001991a8(s32, s32);
void func_001024a8(void*);
extern struct E1a5 D_0036d578[];
void func_00176be0(void*, f32);
void func_00187650(void*, u8, s32);
void func_00179a68(void*, f32);
void func_001d6110(u8, void*);
void func_0014f668(u8);
void func_00242500(u8);
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, void*, void*);
void func_001ae678(void);  // to_306698_arg10
void func_001ae620(void);
s32 func_002f7dc8(void);
void func_001ae650(void);
extern u8 D_00350ca0[];
extern s32 D_00350c88;
s32 func_00139d78(u32);
extern u32 D_0035ed00;
extern u8* D_0035ed10;
extern u32 D_0035ece8;
void func_002fde18(void*, s32, u32);
u32 func_002891e8(u32);
s32 func_00244ee8(u32);
void func_00139858(s32);
void func_001398d0(s32);
u8* func_001d56c8(s32);
u32 func_00192cc0(u8*, void*, u32);
s32 func_00192b30(u32);
u32 func_00192048(u16);
void func_00192c90(u32, u8*);
extern u8 D_00371958[];
s32 func_00257070(s32);
s32 func_00257088(s32);
s32 func_0028afa8(u32);
s32 func_002892f8(u32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0028afd0(u32, s32);  // obj_set_signed18
extern u32 D_0035f01c;
void func_00178cf8(void*, void*);  // clear_vecs_three
void func_00178cf8_1(void*) asm("func_00178cf8");
u32 func_0016a020(u32);
s32 func_002c5d38(void*, u32);
void func_002c8648(void);
void func_002ca0a8(void);
void func_00190388(Q16*, void*);  // vec4_from_arg
void func_0016aef0(void*, Q16*);
void func_002c5190(void*);
void func_002c17a0(void);
extern void* D_00361f60;
u8* func_002d1878(void*);
void func_00187750(void*);
extern f32 D_00349e10;
f32 fabsf(f32);  // fabsf
void func_00144450(f32*);
void func_001b7c80(void*, f32*);
void func_0016af58(Q16*, void*);
s32 func_00180cd0(void*);
f32 func_002f8ad0(f32, f32);
extern u8* D_00347f80;
extern u8 D_0035e050[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
void func_0031a838(void*);
void func_00239700(void*);
void func_00228ab0(void*);
extern u8 D_0035e340[];
extern u8 D_00347e80[];
void func_002361a0(void*);
void func_0022bda0(void*, s32, s32);
extern s32 D_0035de64;
extern s32 D_0035f680[];
extern struct Rec40* D_0035f660;
u32* func_002b6118(u32);
void func_001a98e8(void*, s32, u32, s32, u32);
void func_001a9ae8(void*, s32, s32, s32);
extern u8 D_0035e238[];
void func_00239870(void*);
void func_0031a840(void*);
void func_002bb8b0(void*);
void func_002b7c34(u32, u32, s16, s16);
s32 func_002bb510(void*);
void func_002bb5f8(void*);
void func_002b7cec(u32, u32, s16, s16);
void func_002bc358(u32, s32);
extern s32 D_0034dcc0[];
extern s32 D_0034dcc8[];
s32 func_0016ffc8(void*);
u8* func_00189200(void*, s32);
s32 func_001d62b0(void*, void*);
s32 func_001917c0(void);
s32 func_001d63a8(void*);
void func_001a32c8(s32, s32);
extern u8* D_00352130;
extern u8 D_0032e020[];
struct T294* func_00294000(s32);
s32 func_002941a8(void*);
s32 func_00276c18(void);
void* func_0016bc20(u32, s32, s32);
void func_001ad990(void*, f32, f32, f32);
extern struct KG* D_01d9e6e4;
union FH { f32 f; s16 h; };
void sceVu0ApplyMatrix(union FH*, void*, union FH*);
void* func_0014e638(void*);
void* func_0014e648(void*);  // ptr_add752
void func_00166968(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0014db78(void*, s32, s32, s32, s32, s32, s32);
void func_0014dd60(void*, s32, s32, s32);  // store_3bytes_470
void func_0014dda0(void*, s32);  // store_byte_473
void func_0014dd18(void*);
void func_0014e2c0(void*);
void func_00102788(u32, s32, s32, void (*)(void));
void func_0014df48(void);
extern u8 D_00349f00[];
extern u32 D_0032b91c;
void func_00157990(u32);
void func_00138c10(u32, u32);
u32 func_00155d58(u32, s32);  // table_word_indexed_by_3
void func_001543a0(u32, s32, u32);
s32 func_001581a8(u32);
s32 func_002ba358(void);
void func_002ba368(void);

static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}

static inline void vu0_sub(Q16& r, const Q16& a, const Q16& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}

static inline void vu0_normalize_f1(Q16& v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f1\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v) : "$8", "$f1", "memory");
}

static inline bool is_up(u8* o) { return *(f32*)(o + 52) > 0.0f; }

static inline u8* alloc_obj(s32 size) {
    u8* a = *(u8**)(D_00347f80 + 20);
    return (**(AllocFn**)a)(a, size, 0);
}

static inline bool is_big(s32 id) { return id >= 10000; }

static inline void sub_clamp(u8* e, s32 d) {
    s32 x = *(s32*)(e + 4) - d;
    if (x < 0) x = 0;
    *(s32*)(e + 4) = x;
}

// 00105b58: moved to src/common/region.cpp

// 00149cb8: moved to src/harata/libdk/area.cpp

void func_00169210(void) {
    func_00192290(D_0032bae0[0], 2);
    func_001ac778();
    func_001b8348();
    func_0016c750(func_001050c8());
    func_001900d0();
    func_001b9230();
    func_0017dec0();
    func_00185d98();
    func_001aeae0();
    func_00196a40();
    func_001a0bc0();
    func_0018d738();
    func_001a5f50();
    func_00199548();
    func_001a6a10();
    func_001b14d8();
    func_0019ec20();
    func_001b4300();
    func_00179be8();
    func_001c8a90();
    func_001d3b60();
    func_001d5a48();
    func_001a3a88();
    func_001ba718();
    func_001a5928();
    func_001b24c0();
    func_00182b18();
}

// 00159240: moved to src/anon/unit_00159240.cpp

void func_0018b7f8(u8* p);  // 0x0018b7f8: definition moved into src/yasui/libys/npc.cpp

void func_00197a00(void* a);  // 0x00197a00: definition moved into src/anon/unit_00195d00.cpp

// 001a52a8: moved to src/anon/unit_001a4db0.cpp

void func_001ae4c0(u32 a, u32 b, void* c);  // 0x001ae4c0: definition moved into src/anon/unit_001ada38.cpp

void func_00244b38(void) {
    u8* buf;
    u8* p;
    if (func_00139d78(D_0035ed00) == 0) return;
    func_002fde18(D_0035ed10, 0, 32);
    if (func_00244ee8(func_002891e8(D_0035ece8)) == 0) func_001398d0(100);
    else func_00139858(100);
    buf = D_0035ed10;
    p = func_001d56c8(8);
    if (*p != 3) {
        func_00192c90(func_00192048(0xcb9b), buf);
    } else {
        s32 n = func_00192b30(func_00192cc0(buf, D_00371958, *(u32*)(p + 4)));
        func_00192c90(func_00192048(0xcb98), buf + n);
    }
}

void func_0027c2f8(void);  // 0x0027c2f8: definition moved into src/anon/unit_0027a6d8.cpp

void func_002c5c50(void* a, u32* b);  // 0x002c5c50: definition moved into src/anon/unit_002c53c8.cpp

// Interpolates between two keys by the current time.
f32 func_002d60e8(u8* p);  // 0x002d60e8: definition moved into src/anon/unit_002d4548.cpp

void func_002daee8(u8* p) {
    f32 v;
    func_00187750(p);
    if (p[2840] == 0) return;
    *(f32*)(p + 2864) += *(f32*)(p + 2848) * D_00349e10;
    *(f32*)(p + 2868) += *(f32*)(p + 2852) * D_00349e10;
    v = *(f32*)(p + 2852) - D_00349e10 * 0.16666666f;
    *(f32*)(p + 2852) = v;
    if (v < 0.0f) {
        if (fabsf(*(f32*)(p + 2868) < 0.1f ? 1.0f : 0.0f) == 0.0f) return;
        p[2840] = 0;
        (*(VF0*)(*(u8**)p + 32))(p);
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 2864) : "memory");
    }
}

Q16* func_002d38e8(Q16* out, u8* o);  // 0x002d38e8: definition moved into src/anon/unit_002d2498.cpp

// Flat (y = 0) unit direction from the target to the actor, or the reversed facing.
Q16* func_0018d840(Q16* out, u8* o, void* a);  // 0x0018d840: definition moved into src/anon/unit_0018d050.cpp

// 0017fe10: moved to src/yasui/libys/motion.cpp

void func_001c2f90(struct S1c2* p, u32 a);  // 0x001c2f90: definition moved into src/anon/unit_001c2b58.cpp

void func_00228e58(void);  // 00228e58: moved to src/anon/unit_00228618.cpp (linked unit)

void func_0022c108(void);  // 0022c108: moved to src/sasa/event_countdown.cpp (linked unit)

void func_002b6138(s32 x, s32 y, s32 a2, s32 a3, s32 key) {
    u8 buf[96];
    s32 i;
    s32 n = -1;
    struct Ent8* e;
    for (i = 0; i < 4; i++) {
        if (D_0035f680[i] == key) {
            n = i;
            break;
        }
    }
    e = D_0035f660[n].e;
    for (i = 0; i < 5; i++, e++) {
        u32* s;
        if (e->v == 0) break;
        s = func_002b6118(e->id);
        func_001a98e8(buf, 1, e->v, 14, s[2]);
        func_001a9ae8(buf, s[0] + x, s[1] + y, a3);
    }
}

// Deleting destructor: tears down the member arrays, then frees through the allocator.
void func_00322608(u8* p) {
    u8* q;
    u8* a;
    *(u32*)p = (u32)D_0035e238;
    *(u32*)(p + 5072) = (u32)D_00347e60;
    q = p + 5072;
    func_00239870(p + 5096);
    *(u32*)(p + 5072) = (u32)D_00347f98;
    if (p + 1680 != 0) {
        u8* b = p + 1680;
    l1:
        if (b == q) goto d1;
        q -= 848;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l1;
    }
d1:
    if (p + 440 != 0) {
        u8* b;
        q = p + 1676;
        b = p + 440;
    l2:
        if (b == q) goto d2;
        q -= 412;
        (*(DtorFn*)(*(u8**)q + 12))(q);
        goto l2;
    }
d2:
    *(u32*)p = (u32)D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    a = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)a + 4))(a, p);
}

void func_002bbbc8(struct S2bb* p);  // 0x002bbbc8: definition moved into src/anon/unit_002bb8b0.cpp

void func_00170018(u8* p);  // 0x00170018: definition moved into src/anon/unit_0016e8f8.cpp

s32 func_001d61b8(void* a, s32 b);  // 0x001d61b8: definition moved into src/anon/unit_001d4f40.cpp

s32 func_002952f8(s32 id);  // 0x002952f8: definition moved into src/anon/unit_00292e60.cpp

// 001b0798: moved to src/yasui/libys/lookat.cpp

void func_001e9c28(u8* base, u8* a1, u8* a2);  // 0x001e9c28: definition moved into src/anon/unit_001e8ac8.cpp

}

// 0014dfa8: moved to src/anon/unit_0014d680.cpp

// 001574f8: moved to src/anon/unit_00153ea0.cpp
