#include "../common/types.h"

struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Vi { f32 x, y, z; u32 w; Vi(f32 a, f32 b, f32 c, u32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline Vq vsubn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq vsub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen2(const Vq& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
static inline f32 vlen(const Vq& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
static inline Vq vscale(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}

extern "C" {

// ---- 00105c68
void func_00167ea8(u32);
void func_0014c9d8(s32);
void func_0014df88(void);
void func_0014e0d8(void);
struct S32b968 { u8 pad[28]; s32 f28; };
extern S32b968 D_0032b968;
extern char D_00369f50[];
void func_00168548(char*, s32, s32);
s32 func_001688b8(void);
void func_00102448(u32, s32);
void func_003058a0(s32, s32);
extern u8 D_0033cb80[];
void func_01f18014(s32, void*);
// 00105c68: moved to src/common/shop.cpp
// ---- 0010a4d0
struct E10a { u32 f0; u32 f4; u32 f8; u32 pad; u8 v16[64]; u8 v80[64]; u8 v144[64]; u8 v208[64]; u32 f272; u32 pad2[3]; };
extern u32 D_0033cc68;
extern E10a* D_0033cc70;
void func_0011d740(u32, void*, void*, u32, void*, void*, u32, u32);
void func_0010a4d0(void);  // 0010a4d0: moved to src/anon/unit_00109c30.cpp
// ---- 0010b568
void func_0010b468(u8*, Vq*);
void wtarget_0010b568(u8* a, Vq* b, f32 r) asm("_Z16wtarget_0010b568jjjj");
void wtarget_0010b568(u8* a, Vq* b, f32 r);  // 0x0010b568: definition moved into src/anon/unit_0010b450.cpp
// ---- 0013793c
s32 func_00139d78(u8*);
void func_00139510(u8*);
struct VObj { void (**vt)(VObj*); };
extern VObj* D_00347d5c;
extern s32 D_00347d58;
extern u32 D_00347d60;
void func_001b2028(u32);
void func_00137930(u8* p);  // 0x00137930: definition moved into src/anon/unit_001374c8.cpp
// ---- 001435a0
// Looks up an entry's 2-bit attribute (bits 14-15) in the current table.
struct E143 { u8 pad[14]; u16 h14; };
struct T143 { u8 pad[12]; E143* f12; u8 pad2[4]; u32* f20; };
extern T143* D_00348814;
void func_00141980(T143*, u8*);
u32 func_00142848(T143*, u32);
u32 func_00142688(T143*, u32*, u32, u32);
u32 func_001435a0(u32 a);  // 0x001435a0: definition moved into src/anon/unit_00142c90.cpp
// ---- 00159b40
void func_00141010(f32);
u8* func_00140df0(void);
void func_00162058(f32);  // to_161f48_arg1
struct S20 { u32 w[5]; };
extern S20 D_0034aa18;
extern u8 D_0034aa11;
extern u8 D_0034aa10;
// 00159b40: moved to src/harata/libdk/talkcamera.cpp
// ---- 00178100
extern s32 D_0034ece8;
u32 func_00194898(void);
void func_00140d38(u32, s32);
void func_001586b8(void);
void func_00159700(void);
// 00178100: moved to src/yasui/libys/player.cpp
// ---- 00187a18
u8* func_00187ab8(u32, u32);
u8* func_00187b30(u32);
struct S187 { u32 f0; s16 lo; s16 hi; s16 d; u16 v[11]; };
// Finds (or allocates) a record and fills it.
// 00187a18: moved to src/anon/unit_00185d10.cpp
void func_00187a18(u32 a, u32 b, s32 c, s32 d, u32* src);

// ---- 00314930: packs an unpacked float (class/sign/exp/fraction) into an f32.
struct Fpn { u32 cls; s32 sign; s32 exp; u32 frac; };
union FU { f32 f; struct { u32 frac : 23; u32 exp : 8; u32 sign : 1; } b; };
static inline int fpn_isnan(Fpn* x) { return x->cls < 2; }
static inline int fpn_isinf(Fpn* x) { return x->cls == 4; }
static inline int fpn_iszero(Fpn* x) { return x->cls == 2; }
f32 func_00314930(Fpn* s) {  // dbl_cmp
    FU dst;
    u32 frac = s->frac;
    s32 sign = s->sign;
    s32 exp = 0;
    if (fpn_isnan(s)) {
        exp = 255;
        frac = 0x7fffff;
    } else if (fpn_isinf(s)) {
        exp = 255;
        frac = 0x7fffff;
    } else if (fpn_iszero(s)) {
        frac = 0;
    } else if (frac == 0) {
    } else if (s->exp < -126) {
        frac = 0;
    } else {
        exp = s->exp + 127;
        if (exp < 256) frac >>= 7;
        else { exp = 255; frac = 0x7fffff; }
    }
    dst.b.frac = frac;
    dst.b.exp = exp;
    dst.b.sign = sign;
    return dst.f;
}

// ---- 0018bd50
// Builds a descriptor for (a, b) and for the global object, then compares them.
struct S18b { u8 pad[12]; u32 f12; u8 pad2[16]; S18b() { f12 = 0; } };
u32 func_0016bc20(u32, u32, s32);
void func_0018a818(S18b*, u32, u32);
s32 func_0018a550(S18b*, S18b*);  // state_dispatch_0_1_3
extern u32 D_0034e948;
s32 func_0018bd50(u32 a, u32 b);  // 0x0018bd50: definition moved into src/yasui/libys/npc.cpp

// ---- 00192a80
s32 func_00192440(u8*, s32);  // is_byte_lt25
u8* func_00192388(u8*);  // skip_control_codes
// 00192a80: moved to src/yasui/libys/message.cpp
// ---- 00196908
struct E196 { u32 f0; u8* f4; };
extern E196 D_00350338[8];
u8* func_0016d080(u32, s32);
void func_0016cce8(u8*, s32, s32, s32, s32);
void func_0016cbc8(u8*, s32, s32, s32);
u32 func_0016cb88(u8*, s32);
s32 func_00196908(u32 a);  // 0x00196908: definition moved into src/anon/unit_00195d00.cpp
// ---- 00199718
extern u8 D_0032bae0;
extern u8* D_01c62148[];
extern u8 D_0031f148[];
u8* func_002fd248(u32, u8*, u32, s32, u8*);
struct Sub199b { u16 a, b, c; };
struct S199b { u8 b0, b1, b2, b3; Sub199b s; };
static inline void init199(Sub199b* s, u32 a, u32 m) { s->a = a; s->b = m; s->c = m; }
S199b* func_00199718(S199b* p, u32 a, s32 k);  // 0x00199718: definition moved into src/anon/unit_00199688.cpp
// ---- 001b1ab8
struct N1b { u32 f0; N1b* next; u8 pad[32]; };
struct Pool1b { N1b items[16]; s32 freeIdx[16]; s32 nfree; };
struct List1b { N1b* head; N1b* tail; };
extern Pool1b D_01d44108;
extern List1b D_01d44100;
// 001b1ab8: moved to src/anon/unit_001b14d8.cpp
// ---- 001b9380
struct O1b9 { u8 pad[2228]; O1b9* next; u8 pad2[245]; u8 prio; };
struct List1b9 { O1b9* head; O1b9* tail; };
extern List1b9 D_01d48da0;
static inline O1b9* Next1b9(O1b9* n) { if (!n) return D_01d48da0.head; return n->next; }
void func_001b9380(O1b9* o);  // 0x001b9380: definition moved into src/anon/unit_001b87a0.cpp
// ---- 001b9c90
u32 func_0016a040(u8*);
s32 func_00105300(void);
extern u32 D_01d48db8[];
s32 func_001b9c90(u8* p);  // 0x001b9c90: definition moved into src/anon/unit_001b9880.cpp
// ---- 001bf930
u32 func_0016c028(u8*);  // obj_get_attach_or_alt
void func_002bc188(s32, u32);
void func_001bf930(u32, u8* p);  // 0x001bf930: definition moved into src/anon/unit_001bc568.cpp
// ---- 001c38c0
extern f32 D_00349e10;
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
void func_001c38c0(u32, u8* p);  // 0x001c38c0: definition moved into src/anon/unit_001c2b58.cpp
// ---- 001c5e88
s32 func_001dbd68(u8*);
extern Vq D_01d49880;
struct Sub1c5 { u32 a; s32 cnt; u8 pad[8]; };
struct E1c5 { u8 pad[16]; Sub1c5 sub; };
extern E1c5 D_00351680[];
void func_001c5e18(void);
static inline void dec1c5(Sub1c5* s) { s->cnt--; }
void func_001c5e88(u8* p);  // 0x001c5e88: definition moved into src/anon/unit_001c5b90.cpp
// ---- 001cbc50
u8* func_001db888(u8*, s32, void*);  // record_index_calc
void func_001ca988(u8*, u8*, u32, u32, void*, u32);
void func_001cab08(void);
u8* func_001cbc50(u8* p, u32 a, u32 b, u32 c);  // 0x001cbc50: definition moved into src/anon/unit_001ca8e0.cpp
// ---- 001eed88
static inline f32 rnd01(void) {
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                 : "=r"(r) : : "$8");
    return r;
}
f32 func_001eed88(u8 a);  // 0x001eed88: definition moved into src/anon/unit_001ec098.cpp
f32 func_001eef90(u8 a);  // 0x001eef90: definition moved into src/anon/unit_001ec098.cpp
// ---- 00229120
void func_00229430(u8*, s32);  // to_1391c8_arg11
u32 func_00224860(void);  // get_global_36daf4
u32 func_0022b9e0(void);
u32 func_0022b720(void);
void func_001386e0(u8*, s32, u32, u32, s32, s32);
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
struct S229 { u8 pad[392]; s32 f392; u32 f396; u32 f400; };
static inline void init229(S229* s, u32 x, u32 y) { func_001386e0((u8*)s, 2800, x, y, 21, 11); s->f396 = 0; s->f392 = 22; }
void func_00229120(u8* p);  // 00229120: moved to src/sasa/musical_score.cpp (linked unit)
// ---- 0022cae8
s32 func_002282f0(s16);
s32 func_00225b00(s16);  // flag_query_by_index
u32 func_002282d8(void);  // limit_15000_or_25000
u8* func_00102c18(s32, u32, void*);
void func_0022cba0(void);
void func_0022cc08(void);
u32 func_001050c8(void);
u8* func_001063c0(s32, u32);
void func_0023cd68(u8*);
void func_0023cde8(u8*);
void func_0022cae8(u8* p);  // 0022cae8: moved to src/sasa/event_layout.cpp (linked unit)
// ---- 00249098 / 002b6418
s32 func_002892f8(u32);
s32 func_0028acc8(u32);
void func_00288e88(u32);
extern u32 D_0035ed4c;
extern u32 D_0035ed50;
void func_00249098(void);  // 0x00249098: definition moved into src/anon/unit_00247ff0.cpp
extern u32 D_0035f64c;
extern u32 D_0035f650;
void func_002b6418(void);  // 0x002b6418: definition moved into src/anon/unit_002b60e8.cpp
// ---- 0026e140
extern u8* D_0035f104;
extern u32 D_0035f3d4;
extern u32 D_0035f100;
void func_0028d980(u8*, u32, s32, s32, u32, u32, s32, s32, s32);
u32 func_00192048(s32);
void func_0026e140(s32 i, u32 b, s32 c);  // 0x0026e140: definition moved into src/anon/unit_0026c450.cpp
// ---- 0027a7e0
u8* func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(u8*, s32);
void func_0027b4e8(void);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f04c;
extern u32 D_0035f01c;
void func_0027a7e0(u8 a);  // 0x0027a7e0: definition moved into src/anon/unit_0027a6d8.cpp
// ---- 0027ad80
s32 func_002577b0(void);
s32 func_0027ad80(void);  // 0x0027ad80: definition moved into src/anon/unit_0027a6d8.cpp
// ---- 0027c118
u32 func_002570a0(s32);
void func_0027aed8(u32, s32*, s32*);
u8* func_00281180(u32, s32);
extern u32 D_0035f010;
extern u8* D_0035f230;
struct H27c { u16 v : 15; u16 flag : 1; };
struct W27c { u8 pad[4]; H27c h; };
struct E27d { u8 pad[14]; u8 b14; s8 b15; };
void func_0027c118(s32 i, u8 f);  // 0x0027c118: definition moved into src/anon/unit_0027a6d8.cpp
// ---- 002a7d10
struct E2a7 { s16 a, b; };
struct T2a7 { s32 n; E2a7 e[1]; };
extern T2a7* D_0035f600;
extern u32 D_0035f200;
s8* func_00276568(void);
s32 func_0028afa8(u32);
void func_0028afd0(u32, s32);  // obj_set_signed18
void func_002a7d10(void);  // 0x002a7d10: definition moved into src/anon/unit_002a7308.cpp
// ---- 002a8258
struct VObj436 { void** vt; u8 pad[432]; };
extern VObj436 (*D_0035f604)[2];
void func_00276a18(void);
void func_00276b10(void);
void func_002a8258(void);  // 0x002a8258: definition moved into src/anon/unit_002a7308.cpp
// ---- 002a8870
struct E2a8 { u16 h0; u16 h2; u16 h4; u16 h6; };
struct T2a8 { u32 pad[2]; s32 n; u32 pad2; E2a8 e[1]; };
T2a8* func_00294000(s32);
u8* func_001d56c8(u16);
s32 func_00276c18(void);
static inline s32 ok2(u8* v) { return *v < 2; }
static inline s32 bad2(u8* v) { return ok2(v) ^ 1; }
s32 func_002a8870(s32 a);  // 0x002a8870: definition moved into src/anon/unit_002a8748.cpp
// ---- 002d56a0
u8* func_0016bc20p(u32, s32, s32) asm("func_0016bc20");
Vq* func_0016c028v(u32) asm("func_0016c028");
s32 func_002d56a0(u8* p);  // 0x002d56a0: definition moved into src/anon/unit_002d4548.cpp
// ---- 002e7e58
void func_0016bd60(u8*, s32);
void func_002e7e58(u8** p);  // 0x002e7e58: definition moved into src/anon/unit_002e7b10.cpp

}

// ---- destructors and others (C++ part)

struct E16 { u8 d[16]; ~E16() {} };

extern "C" {
void func_00134d10(void*);
void func_00134d58(void*);
extern u8 D_00347cc0[];
struct V4 { f32 x, y, z, w; };
extern V4 D_00347ce0;
void func_001e18d8(void*);
void func_0023d7c8(void*);
void func_001ddd88(void*);
void func_001070e8(void*);
void func_00106ac8(void*);
extern void* D_0034a820[];
extern void* D_00347f98[];
extern void* D_0035eb60[];
extern void* D_00348698[];
}

void func_00135690(int a, int b) asm("_Z13func_00135690ii");
// 00135690: moved to src/anon/unit_00134668.cpp

struct Obj1e2 {
    E16 a[10];
    E16 b[10];
    E16 c[200];
    ~Obj1e2() { func_001e18d8(this); }
};

struct E408 { void** vt; u8 pad[404]; ~E408() { ((void (*)(E408*))vt[3])(this); } };
struct Base31 { u32 vt; ~Base31() { *(void**)this = D_00347f98; } };
struct Obj31c : Base31 {
    u8 pad[44];
    E408 a[6];
    E408 b[32];
    ~Obj31c() { *(void**)this = D_0034a820; }
};

struct E320 { u8 pad[192]; u8 m[128]; ~E320() { func_001ddd88(m); } };
struct E400 { u8 pad[256]; u8 m[144]; ~E400() { func_001070e8(m); func_00106ac8(this); } };
struct M784 { u32 vt; u8 pad[780]; ~M784() { *(void**)this = D_00348698; } };
struct Obj322 : Base31 {
    u8 pad[28];
    E400 a[4];
    E320 b[4];
    u8 pad2[32];
    M784 m0;
    M784 m1;
    M784 m2;
    ~Obj322() { *(void**)this = D_0035eb60; func_0023d7c8(this); }
};

extern "C" {
void func_001e2898(Obj1e2* p);  // 0x001e2898: definition moved into src/anon/unit_001e0cb8.cpp
void func_0031cf88(Obj31c* p) { p->~Obj31c(); }
void func_00322be0(Obj322* p) { p->~Obj322(); }
}
