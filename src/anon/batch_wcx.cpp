#include "../common/types.h"

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));

extern "C" {

void func_001396b0(u8*);
void func_0031a260(u8*, s32);
void func_0031ac78(u8*, s32);

// 00138748: reset the state block and run the two settle passes
void func_00138748(u8* p);  // 0x00138748: definition moved into src/anon/unit_00138480.cpp

void func_00138d60(u8*, s32, u32, u32, u32, u32, u32);
void func_00139620(u8*);
void func_00239988(u8*, u32, u32);
void func_0013ac60(u8*, u32, u32);

void func_0013aa78(u8* p, u32 x, u32 y, u32 z, u32 w, u32 v, u32 u);  // 0x0013aa78: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_0013d390(void);
void func_00139a38(s32);
void func_001399c0(s32);
void func_00139ab0(s32);
void func_00139948(s32);
void func_0013b2d8(f32);
f32 func_0013b2a8(u8*);  // mul_float684_692
void func_00138d48(u8*, f32, f32, f32, f32);

void func_0013d3f8(u8* p);  // 0x0013d3f8: definition moved into src/anon/unit_0013a8b8.cpp

f32 fabsf(f32);  // fabsf
void func_0013fda0(u8*);
void func_0013fdc8(u8*);

// 00140150: step the value at +72 towards the target at +200
void func_00140150(u8* p, f32 x);  // 0x00140150: definition moved into src/anon/unit_0013fca8.cpp

s32 func_0015b4f8(void*, u32, s32*);
void func_00239c38(void*, s32);
s32 func_0023aa98(void*);
extern u8 D_0034a5e8[];
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };

// 00151d48: load up to 7 entries and keep a running total of their sizes
void func_00151d48(S151* p);  // 0x00151d48: definition moved into src/anon/unit_0014ecb8.cpp

extern void* D_0034aaa8;
extern void* D_0034aaa4;
extern void* D_0034aa9c;
extern void* D_0034aaa0;
typedef void (*VFn)(void*);
#define VDEL(o) if (o) { (*(VFn*)(*(u8**)o + 16))(o); o = 0; }
void func_0015b100(void*) asm("_Z13func_0015b100Pv");
// 0015b100: destroy the four global singletons
void func_0015b100(void*);  // 0x0015b100: definition moved into src/anon/unit_0015b100.cpp

extern u8 D_0034af40[];
extern u8 D_0034b0e0[];
void func_002361a0(u8*);
void func_00239700(u8*);
void func_00239870(u8*);
void func_002361d0(u8*);
void wtarget_0015d730(u32, u32, u32, u32) asm("_Z16wtarget_0015d730jjjj");
// 0015d730: static initialiser, now made by gcc in src/anon/unit_0015d440.cpp

extern u8 D_003502d8[];
extern u8 D_0032bae0[];
void func_001980d0(u8*, u32, s32, u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_0016a020(u8*);
s32 func_00196388(u8, u8);
void func_001963c8(s32);

void func_00195e28(u8* p, u32 a, u32 b);  // 0x00195e28: definition moved into src/anon/unit_00195d00.cpp

extern u8 D_00350e8c;
extern u32 D_0034f240;
s32 func_0019c590(void);
s32 func_0019c768(u8*);
s32 func_002be5f8(void);

s32 func_0019c650(u8* p);  // 0x0019c650: definition moved into src/anon/unit_0019ba60.cpp

u8* func_001ba158(void);
s32 func_0019ba60(u8*);

// 001a2200: scale a count by the party size (divide when the flag is set)
s32 func_001a2200(u8* p, s32 n);  // 0x001a2200: definition moved into src/anon/unit_0019fb70.cpp

struct Rd { u32 a; u32 obj; u32 buf; u32 size; u32 e; };
extern Rd D_00350cb0;
extern u8 D_00350ca8[];
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, u32, u8*);
void func_001ae678(void);  // to_306698_arg10

// 001ae8d8: record a read request and retry until the drive accepts it
void func_001ae8d8(u8* p, u32 buf, u32 size, u32 a, u32 e);  // 0x001ae8d8: definition moved into src/anon/unit_001ada38.cpp

V4* func_0016c028(u8*);  // obj_get_attach_or_alt
f32 func_001849d8(u8*);

s32 func_001b2d10(u8* p, f32* q);  // 0x001b2d10: definition moved into src/anon/unit_001b2780.cpp

struct Bits { u32 a, b; u64 on; u64 off; };
extern u8* D_01d49978;
extern u8 D_00321058[];
Bits* func_002fd248(u32, u8*, u32, s32, u8*);
void func_0015ee90(s32);
void func_0015ee10(s32);

void func_001c8ec0(u32 a0);  // 0x001c8ec0: definition moved into src/anon/unit_001c8e80.cpp

struct B32 { f32 a, y, c; u32 d; V4 pos; };
struct It { u8* cur; u8 pad[28]; };
void func_00190128(It*);
u8* func_00190730(It*, u8*);
void func_001cdbc8(u32, B32*, s32);
void func_0018a818(B32*, u8*, u8*);

// 001cddb8: moved to src/anon/unit_001cd660.cpp
void func_001cddb8(u32 a);

void func_001d1720(u8*, s32);
void func_001d17b0(u8*, s32);

// 001d1da0: clamp the gauge value to [0, max], firing the empty/full events
void func_001d1da0(u8* p, f32 x);  // 0x001d1da0: definition moved into src/anon/unit_001d14e0.cpp

extern u8* D_0035ed4c;
extern s8 D_0035ed69;
extern u8* D_0035ed64;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);

void func_002493c8(void);  // 0x002493c8: definition moved into src/anon/unit_00247ff0.cpp

extern u8* D_0035edcc;
extern u8* D_0035edd0;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);

void func_0024dea8(void);  // 0x0024dea8: definition moved into src/anon/unit_0024cda8.cpp

}

extern "C" {

u8* func_00294000(s32);
s32 func_00276c18(void);
struct Ent16 { u16 id; u8 pad[14]; };
s32 func_002a99c8(Ent16*);

// 002a9b88: is there a matching table-8 entry (id < 0 = any) that accepts?
s32 func_002a9b88(s32 id);  // 0x002a9b88: definition moved into src/anon/unit_002a99c8.cpp

// Tz::CmSLBase::GetCurrentListItem: release every live item in the 3x4 slot grid
extern u8* D_0035f690[3][4];
void CmSLBase_GetCurrentListItem(void) asm("_ZN2Tz8CmSLBase18GetCurrentListItemEv");
void CmSLBase_GetCurrentListItem(void);  // 0x002b5a50: definition moved into src/anon/unit_002b3ac8.cpp

f32 func_00106558(f32);
s32 func_001064a8(s32);  // int_to_float_scaled
typedef void (*Fn84)(u8*, s32, s32);

// 002e7568: with probability x pick a random entry of the table and apply it
s32 func_002e7568(u8* obj, s32 n, u8* tbl, f32 x);  // 0x002e7568: definition moved into src/anon/unit_002e5f70.cpp

u32 func_002eaf40(u8*);
s32 func_001c0cd8(u32);
void func_0017f488(u8*, s32, f32, f32);
s32 func_0019c090(u8*);  // obj_is_enabled
void func_0017c430(u8*, s32, f32);
void func_0016bd60(u8*, s32);

// 002eb3b8: moved to src/anon/unit_002eaf38.cpp

}

extern "C" {
// 002ffc50: newlib __sbprintf: print through an unbuffered stream via a stack buffer
struct SFile {
    u8* p; s32 r; s32 w; u16 flags; s16 file; u8* base; s32 size; s32 lbfsize;
    void* cookie; void* read; void* write; void* seek; void* close;
    u8 pad[36]; void* data; u8 pad2[8];
};
s32 func_002ffd00(SFile*, const char*, void*);  // fprintf_stream_va
s32 fflush(SFile*);
s32 func_002ffc50(SFile* fp, const char* fmt, void* ap);  // 0x002ffc50: definition moved into src/newlib/libc/vfprintf.c
}

extern "C" {
// 0031f820 / 0031c518: destructors (member arrays destroyed back to front)
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
void func_00105110(u8*);
void func_0031f820(u8* p);  // 0x0031f820: definition moved into src/anon/unit_0031f2f8.cpp
extern u8 D_0034a5d0[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_002361d0(u8*);
typedef void (*FreeFn)(u8*, u8*);
void func_0031c518(u8* p);  // 0x0031c518: definition moved into src/anon/unit_0031b9e0.cpp
}

extern "C" {
// 0016d760: pos += normalize(dir) * speed * dt (VU0 macro code, hand-written asm)
extern f32 D_00349e10;
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Mv { V4* pos; V4* dir; f32 speed; };
// 0016d760: moved to src/anon/unit_0016d2e0.cpp
}
namespace w70_p {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct M4 { V4 r[4]; };
extern M4 D_003478f0;
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }

typedef void (*Fn52)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel

void func_00138988(u8*);
void func_00138de0(u8*);
extern s32 D_0034805c;
void func_0023a9c0(u8*, s32*, s32*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0023ade0(u8*);

extern u8* D_003484a0;
extern u32 D_00348050;
struct P2 { u32 a, b; };
extern P2 D_00348578;
void func_0013b348(s32);
void func_00138698(u32, u32);
void func_0013d4c8(void);
u8* func_0013cb80(void);  // get_global_358050
void func_001387f8(u8*, u32, u8*, u32);
void func_0013b2d8(f32);
void func_0013d6b0(u32 a, u32 b);  // 0x0013d6b0: definition moved into src/anon/unit_0013a8b8.cpp

void sceVu0ApplyMatrix(f32*);

extern u8* D_00348808;
void func_00141c18(u8*, s32, s32, s32, s32);
s32 func_00141ff0(u8*, u32, u32, u16*, s32);

void func_00144860(f32* d, f32* a, f32* b) asm("_Z13func_00144860Pv");

void func_0014d8d0(u8*);

s32 func_0015b4f8(void*, u32, s32*);
void func_00239c38(void*, s32);
s32 func_0023aa98(void*);
extern u8 D_0034a630[];
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };
void func_00152120(S151* p);  // 0x00152120: definition moved into src/anon/unit_0014ecb8.cpp
}

}
namespace w70_q {
extern "C" {
typedef void (*Fn52)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001241b8(u8* p, s32 base, u32 c);  // 0x001241b8: definition moved into src/anon/unit_00123990.cpp
void func_00138988(u8*);
void func_00138de0(u8*);
extern s32 D_0034805c;
void func_0023a9c0(u8*, s32*, s32*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0023ade0(u8*);
union FI { f32 f; s32 i; s16 h; };
void sceVu0ApplyMatrix(FI*);
void func_0013ea50(u8* p, u32, FI* v, s32* ox, s32* oy);  // 0x0013ea50: definition moved into src/anon/unit_0013dfb8.cpp
static inline f32 Mn(f32 a, f32 b) { return a < b ? a : b; }
static inline f32 Mx(f32 a, f32 b) { return b < a ? a : b; }
}

}
namespace w70_r {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef u8* (*AllocFn)(u8*, s32, void*);
extern u8* D_0032b91c;
void func_00168958(u8*, s32, u32);  // obj_init_name_string

extern u8 D_0032bae0;
u8* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001cc3b8(u8*, u8);

extern u8* D_0034dca0;
s32 strcmp(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* ctarget_00170240(u32, u32, u32, u32) asm("_Z16ctarget_00170240jjjj");
u8* ctarget_00170240(u32 name, u32 id, u32, u32);  // 0x00170240: definition moved into src/anon/unit_0016e8f8.cpp

struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182c60(void);
void func_00102c18(s32, s32, void (*)(void));
void func_00182940(E12*);

V4* func_0016c028v(u8*) asm("func_0016c028");
void func_0018b008(u8*, V4*, u32, V4*);

extern u8 D_003502d8[];
extern u8 D_0032bae0a[] asm("D_0032bae0");
void func_001980d0(u8*, u32, s32, u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_0016a020(u8*);
s32 func_00196388(u8, u8);
void func_001963c8(s32);
void func_00195ed8(u8* p, u32 a, u32 b);  // 0x00195ed8: definition moved into src/anon/unit_00195d00.cpp

f32 func_0017ce10(f32);
u8* func_0016f000(u32, u32, f32);
s32 func_001997c0(u8*);
void func_001956d0(u8*, u16);
extern u8 D_0034f250[];
typedef void (*Fn56)(u8*, u32, u8*);
u8* func_00199890(u8* p, u32 a, u32 b);  // 0x00199890: definition moved into src/anon/unit_00199688.cpp

void func_0019cbe8(u8*);
u32* func_00177860(u8*);
s32 func_0019ba60(u8*);
u32 func_00154b40(u32, u32);

struct S20 { u32 w[5]; };
struct Job { u32 b; S20 s; };
extern Job D_01c6cb78;
u32 func_001b8680(u32, u32);
u8* func_00102c48(s32, s32, u32, s32);
// 001a6dd8: moved to src/anon/unit_001a6a10.cpp
}

}
namespace w70_s2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef u8* (*AllocFn)(u8*, s32, void*);
extern u8* D_0032b91c;
void func_00168958(u8*, s32, u32);  // obj_init_name_string
// 00168410: moved to src/yasui/libys/file.cpp
struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182c60(void);
void func_00102c18(s32, s32, void (*)(void));
void func_00182940(E12*);
// 00182b18: moved to src/anon/unit_00182780.cpp
struct B32 { f32 a, y, c; u32 d; V4 pos; };
void func_0019cbe8(u8*);
u32* func_00177860(u8*);
s32 func_0019ba60(u8*);
u32 func_00154b40(u32, u32);
}

}
namespace w70_u {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
extern u8 D_0036da70[];
s32 func_001883d8(u8*, u8*);
void func_001880b0(u8*, u8*);
struct Tmp48 { u8 d[16]; };
void func_0016c2b0(Tmp48*, u8*);
void func_001b4198(u8*, u32, Tmp48*);
void func_0016be00(u8*, u16);
void func_00187850(u8*);
void func_001b40e0(u8* p);  // 0x001b40e0: definition moved into src/anon/unit_001b2780.cpp

extern u8* D_01d48da0;
static inline u8* NextB(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
typedef s32 (*Fn60)(u8*);
void func_001b9f80(s32 lv);  // 0x001b9f80: definition moved into src/anon/unit_001b9880.cpp

extern u8* D_01d5ba20;
extern f32 D_00349e10;
static inline u8* NextC(u8* n) { if (!n) return D_01d5ba20; return *(u8**)(n + 48); }
void func_001d38a0(u8*, V4*, u32);
// 001d3ac0: moved to src/anon/unit_001d35e0.cpp

struct E8 { u16 id; u8 v[3]; u8 pad; u16 res; };
extern E8 D_0036e568[4];
s32 func_00181500(u16);
u32 ctarget_001d52c0(u32, u32, u32, u32) asm("_Z16ctarget_001d52c0jjjj");
u32 ctarget_001d52c0(u32 a, u32 b, u32, u32);  // 0x001d52c0: definition moved into src/anon/unit_001d4f40.cpp

u8* func_00168b38(u32, s32, u8);  // entry_array_find_nth
void func_001d5370(u32*, u32, s32);
union UH { u32 w; u16 h; };

typedef void (*VF0)(u8*, u8);
typedef void (*VF5)(u8*, u32, u32, u32);
void func_001d5370b(u8*, u32, s32) asm("func_001d5370");
void func_001d16e8(u8*, u8, s32);
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");

extern u32 D_003638d0;
u64 func_00312db8(u64, u64);

extern u8* D_0035dcf0;
s32 strcmp(u8*, u32);  // strcmp
}

}
namespace w70_w {
extern "C" {
typedef void (*VF0)(u8*, u8);
typedef void (*VF5)(u8*, u32, u32, u32);
void func_001d5370b(u8*, u32, s32) asm("func_001d5370");
void func_001d16e8(u8*, u8, s32);
struct Ow { u8 pad[72]; u32 k; u8 pad2[600]; u8* arr[9]; s32 n; };
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");
void u_tail4_001d8190(u32 a, u32 b, u32 c, u32);  // 0x001d8190: definition moved into src/anon/unit_001d7458.cpp
extern u8* D_0035dcf0;
s32 strcmp(u8*, u32);  // strcmp
struct E84 { s32 id; u32 used; u8 pad[40]; u8 name[36]; };
extern E84* D_0035dcf0b asm("D_0035dcf0");
E84* func_00227a60(u32 name, s32 id);  // 0x00227a60: definition moved into src/anon/unit_00224780.cpp
}

}
namespace w70_x {
extern "C" {
void func_001991a8(s32, s32);
void func_002249f8(s32);
u32 func_002282d8(void);  // limit_15000_or_25000
void func_0022c840(void);
u8* func_00102c18(s32, u32, void (*)(void));
void func_0022c8f8(s32 a);  // 0022c8f8: moved to src/sasa/event_layout.cpp (linked unit)

struct E40 { u32 a; u32 b; u8* o; u8 pad[28]; };
extern E40* volatile D_0035dcfc;
void func_001ba028(u8*);  // list_contains_ptr
void func_00232db0(u32);
typedef void (*VFn)(u8*);

extern u8* D_0035ed70;
extern s8 D_0035ed9c;
extern u8* D_0035ed8c;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_0024b0e8(void);  // 0x0024b0e8: definition moved into src/anon/unit_00249ef0.cpp

extern u8* D_0035ee34;
extern u8* D_0035ee38;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00250698(void);  // 0x00250698: definition moved into src/anon/unit_0024fbd0.cpp

extern u8* D_0035f01c;
extern u8* D_0035f024;
u32 func_0028b1b8(u8*);
void func_0028b1b0(u8*, u32);
s32 func_0028b1c0(u8*, s32);  // test_bit_field32
void func_002891f0(u8*, s32, s32, s32, s32);
void func_00287cc0(s32);
void func_0026cb38(void);
void func_0026c760(void);  // 0x0026c760: definition moved into src/anon/unit_0026c450.cpp

// Tz::Jiminy::Init
extern u8* D_0035f010;
s32 func_00257070(s32);
s32 func_00281100(u8*);
void func_00257050(s32, s32, s32);
u32 func_00281140(u8*, s32);
void func_0028fb68(s32, u32);
s32 Jiminy_Init(u8, u8) asm("_ZN2Tz6Jiminy4InitEv");
s32 Jiminy_Init(u8 fwd, u8 apply);  // 0x00273de0: definition moved into src/anon/unit_00271e08.cpp

u32 func_0013a1d8(void);
u32* func_001063f0(s32, u32);
void func_00239700(u8*);
}

}
namespace w70_y {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
union GP { s16* p; s16 h; };
extern GP D_0035f4e8;
extern GP D_0035f4ec;
u32 func_00103570(void);
s16* func_001063f0(s32, u32);
void func_002936e8(void);
void func_00293240(void);  // 0x00293240: definition moved into src/anon/unit_00292e60.cpp

u32 func_00287bc0(void);
void func_00276150(u32, s32*, s32*);
s8* func_00276568(void);
s32 func_0029a5f0(s32);
s32 func_0029a780(s32 a);  // 0x0029a780: definition moved into src/anon/unit_00299920.cpp

u8* func_00294000(s32);
extern u32* D_0035f610;
s32 func_002a9e98(s32 id);  // 0x002a9e98: definition moved into src/anon/unit_002a99c8.cpp

struct D8 { u32 a, b; };
extern D8 D_01e2a5e8;
extern D8 D_01e2a5f0;
struct T32 { u8 pad[1024]; s32 v[32]; s32 n; };
extern T32 D_01e2a5f8;
void wtarget_002bafb0(u32, u32, u32, u32) asm("_Z16wtarget_002bafb0jjjj");
// 002bafb0: static initialiser, now made by gcc in src/anon/unit_002bac78.cpp

s32 func_00197920(u8*);
void func_002e2728(u8*, s32, u8);
void func_002e24e0(u8*);
extern V4 D_00362e70;
extern u8* D_0034e948;
void func_0016ace0(u8*, V4*);
void wtarget_002e2440(u32, u32, u32, u32) asm("_Z16wtarget_002e2440jjjj");
// 002e2440: moved to src/anon/unit_002e1908.cpp

u8* func_001b9bc8(u8*);
s32 func_0019c6f0(u32);
void func_0016c568(u8*, u32, f32);
void func_002e8400(u8* p);  // 0x002e8400: definition moved into src/anon/unit_002e7b10.cpp

s32* func_00316e10(void);  // get_data_369928
s32 DIntr(void);
void EIntr(void);  // ee_intr_get_enable
s32 func_00316c68(s32* out, s32 flag);  // 0x00316c68: definition moved into src/libsupc++/eh_globals.cpp
}

}
namespace w70_z {
extern "C" {
s32 func_00224910(u8*);  // get_global_36dac4
void func_00239f18(u8*, f32);  // obj_set_float312_and_flags
static inline f32 Clamp(f32 v, f32 lo, f32 hi) { return v < lo ? lo : (hi < v ? hi : v); }
f32 func_0028f1e0(f32* a, f32* b, f32 x);  // 0028f1e0: moved to src/anon/unit_0028f1e0.cpp
}
extern "C" {
}

}
namespace w70_a2 {
extern "C" {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
void func_00105110(u8*);
// same shape as 0031f820
void func_0031fa18(u8* p);  // 0x0031fa18: definition moved into src/anon/unit_0031f2f8.cpp
f32 func_001142a0(u32);
f32 func_0010f660(void);  // cvt_20001_scaled
void func_001111c8(u8* p);  // 0x001111c8: definition moved into src/anon/unit_00110b00.cpp
}

}
namespace w71_b1 {
extern "C" {
void func_001025f8(u8*, u8*);
void wtarget_00102688(u32, u32, u32, u32) asm("_Z16wtarget_00102688jjjj");
typedef void (*Fn60)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_00124278(u8* p, s32 base, u32 c);  // 0x00124278: definition moved into src/anon/unit_00123990.cpp
f32* func_001333c8(u8*);
f32 fabsf(f32);  // fabsf
void func_0013fda0(u8*);
void func_0013fdc8(u8*);
void func_001400b0(u8* p, f32 x);  // 0x001400b0: definition moved into src/anon/unit_0013fca8.cpp
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_00144e30(Seg*);  // zero_6_halfwords
u32 func_00141970(u8*);  // vtable_get12
void func_00144e50(Seg*, Seg*, u32);
void func_00141c18(u8*, s32, s32, s32, s32);
void func_00141c38(u8*, s32, Seg*, u16*, s32);
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
struct S10 { u8 a, b, c; u16 d, e, f; };
void func_001991a8(s32, s32);
u8* func_001058e8(void);
u8 func_00149fa8(s32);
void func_00104f58(S10*, u32, s32, s32, s32);
void func_00239f18(u8*, f32);  // obj_set_float312_and_flags
void func_00138c68(u8*, s32, s32);
// 00155ab0: moved to src/anon/unit_00153ea0.cpp
void func_00155ab0(u8* p, s32 v, s32 i);
}

}
namespace w71_b3 {
extern "C" {
void func_001025f8(u8*, u8*);
void wtarget_00102688(u32, u32, u32, u32) asm("_Z16wtarget_00102688jjjj");
f32* func_001333c8(u8*);
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_00144e30(V4*);  // zero_6_halfwords
u32 func_00141970(u8*);  // vtable_get12
void func_00144e50(V4*, Seg*, u32);
void func_00141c18(u8*, s32, s32, s32, s32);
void func_00141c38(u8*, s32, V4*, u16*, s32);
u16 func_00142848(u8* o, u8* p);  // 0x00142848: definition moved into src/anon/unit_00141458.cpp
void func_00144b38(f32* b, f32* v);  // 0x00144b38: definition moved into src/anon/unit_00144450.cpp
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
void func_00148e40(u32 ctx, u8* n, u8** out, s32* cnt);  // 0x00148e40: definition moved into src/anon/unit_00148c50.cpp
struct S10 { u8 a, b, c; u16 d, e, f; };
void func_001991a8(s32, s32);
u8* func_001058e8(void);
u8 func_00149fa8(s32);
void func_00104f58(S10*, u32, s32, s32, s32);
void func_00149fe0(s32 a, u32 b);  // 00149fe0: moved to src/anon/unit_00149fa8.cpp
}

}
namespace w71_b4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct B32 { f32 a, y, c; u32 d; V4 pos; };
u8* func_001b9bc8(u8*);
u32 func_0016bba8(u8*, s32, u32);
void func_0018a818(B32*, u8*, u32);
extern u8* D_0034dca0;
extern u32 D_0034dcb0;
void func_001700e8(u8*, s32);
void func_0016fc10(u8*);
void func_001707d8(void);  // 0x001707d8: definition moved into src/anon/unit_0016e8f8.cpp
s32 strcmp(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* func_0018bc60(u8*, s32);
u32 func_0018bae8(u8*, u8*);
// YS::STDOBJ::hook_command_image
extern s8 D_0036d0c8[4];
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_0013d6b0(u32, u32);
static inline u32 Key4(s8* k) { return k[0] | k[3] << 24 | (k[2] << 16 | k[1] << 8); }
void STDOBJ_hook_command_image(u8*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
typedef s32 (*Fn8)(u8*, u32);
static inline u8* NextR(u8* p, u8* n) { if (!n) return *(u8**)(p + 12); return *(u8**)(n + 96); }
struct E56 { u32 a; u32 b; u8 pad[4]; u32 c; u32 d; u8 pad2[36]; };
extern E56 D_01c62198[64];
void func_00199cd0(E56*);
void wtarget_0019b970(u32, u32, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void func_0019e210(u8**, u32);
void func_0019e170(u8** p);  // 0x0019e170: definition moved into src/anon/unit_0019ba60.cpp
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
// 001ad280: moved to src/anon/unit_001abb28.cpp
}

}
namespace w71_b6 {
extern "C" {
void func_001d02c8(u32);
u8* func_00176b58(u32);
s32 func_0019ba60(u8*);
u8* func_00177860(u8*);
s32 func_001a2a50(u32, u32, u32, s32);
void func_001d97c8(void);
// 001ba598: moved to src/yasui/libys/itemeffect.cpp
u32 func_001050c8(void);
void func_001db710(u32*, u32, u32, u32);
u32 func_001050d8(s32);
struct E4 { u8 used; u8 cnt; u16 id; };
void func_001d4f40(u8*, u16, u8);
void func_0019d188(u8*);
void func_001bd6a8(u8*);
void func_001d6ab0(u8*);
typedef s32 (*Fn64)(u8*);
void func_001d6ba0(u8* p);  // 0x001d6ba0: definition moved into src/anon/unit_001d68e0.cpp
extern u8 D_01dad990[];
s32 func_002282f0(s16);
s32 func_00225b00(s16);  // flag_query_by_index
void func_002f1460(u8*, s32, f32, f32, f32, f32);
void func_0022cf18(void);
void func_00102c18(s32, s32, void (*)(void));
void func_0022cf60(s16* p);  // 0022cf60: moved to src/sasa/event_layout.cpp (linked unit)
struct R32 { u32 a; u32 id; u8 pad[24]; };
extern R32 D_01dadc00[64];
extern s32 D_0035e364;
extern s32 D_0035e360;
extern u32 D_0035e370;
extern u32 D_0035e36c;
}

}
namespace w71_b7 {
extern "C" {
void func_0023f168(u8*);
void func_0023ca80(u8*);
s32 func_0023c900(u8*);
void func_0023f108(u8*);
typedef void (*VFn)(u8*);
void func_0023efb8(u8* p);  // 0x0023efb8: definition moved into src/anon/unit_0023e5d0.cpp
extern u8* D_0035eda8;
extern s8 D_0035edc5;
extern u8* D_0035edbc;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_0024c898(void);  // 0x0024c898: definition moved into src/anon/unit_0024ba58.cpp
u8* func_001058e8(void);
extern u8* D_0035ee70;
void func_00252660(s32 i);  // 0x00252660: definition moved into src/anon/unit_00250fb8.cpp
extern u8* D_0035f264;
extern u32 D_0035f250;
void func_002806a0(void);
u32 func_0023f1b0(u32);
u32 func_0023c4b8(u32, s32);
u32 func_00236ca8(u8*, s32);
void func_001386e0(u8*, s32, u32, u32, s32, s32);
void func_002805d0(void);  // 0x002805d0: definition moved into src/anon/unit_0027f2b0.cpp
// Tz::CmItem::FadeOutHelp
extern u8 D_0035f299;
extern u32 D_0035f274;
extern u8* D_0035f28c;
extern u8* D_0035f290;
extern s16 D_0035f2a2;
extern s16 D_0035f2aa;
extern s16 D_0035f280;
void func_0028dac8(u8*, s32);
s32 func_00281c30(void);
void CmItem_FadeOutHelp(void) asm("_ZN2Tz6CmItem11FadeOutHelpEv");
void CmItem_FadeOutHelp(void);  // 0x00281b30: definition moved into src/anon/unit_0027f2b0.cpp
// Tz::Select::Destroy
s32 func_0028acc8(u8*);
void Select_Destroy(u8*) asm("_ZN2Tz6Select7DestroyEz");
// Tz::Selector::CreateHelpGra
void func_00290740(u8*);
void func_002362b0(u8*, u32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void Selector_CreateHelpGra(u8*, u32, u32, u32) asm("_ZN2Tz8Selector13CreateHelpGraEz");
extern s8* D_0035f5d4;
void func_002a18d0(void);
s32 func_002a9e98(s32);
s32 func_002a9f50(s32);
u8* func_00294000(s32);
s32 func_002aacd8(s32);  // test_bit_global_d
extern u8* D_0035f610;
}

}
namespace w71_b8 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
u8* func_001d9e30(u8*);  // record_range_check_or_first
s32 func_002764b0(u8);
extern u8* D_0035f610;
s32 func_002b7d5c(u32, u32, s32, u32);
s32 func_002b97d8(u32, u32, s32, u32);
u8 func_002b73ac(u32, u32, u32, s32, u32);
extern u8* D_01e2aa80;
s32 ctarget_002bb468(u32, u32, u32, u32) asm("_Z16ctarget_002bb468jjjj");
void func_002b740c(u32, u32, u32, s32);
void func_002e34c8(u8*);  // obj_get_field8_by_vtable
s32* func_002e34d8(u8*, s32);  // list_walk_stride12
void func_001d14b0(u8*, s32);
u8 func_002cd008(u8*, u32);
extern u32 D_00363560;
extern u8 D_01e2c064;
extern u32 D_003637d0;
extern f32 D_0036354c;
void func_002eda90(u32, s32, f32);
void func_002edaf8(u32, s32, f32);
extern u8* D_00352130;
void func_0017f488(u8*, s32, f32, f32);
void func_0016bd60(u8*, s32);
// 002f04e0: moved to src/anon/unit_002efd68.cpp
extern u8 D_00347d70[];
extern u8 D_00347f98[];
void func_0031a508(u8*);
void func_0031a3d8(u8*);
}

}
namespace w71_c1 {
extern "C" {
u32 func_00317138(u32);
u32 func_00317130(u32);
u32 func_00317128(u32);
void func_002fd160(void) __attribute__((noreturn));
// libgcc unwind-pe.h base_of_encoded_value
u32 func_00316e88(u8 enc, u32 ctx);  // 0x00316e88: definition moved into src/libgcc/unwind-dw2.c
extern u8* D_0035f5e4;
s32 func_002a4990(u8*);
s32 func_002a4ad8(s32 a);  // 0x002a4ad8: definition moved into src/anon/unit_002a40c8.cpp
}

}
namespace w72_d2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*Fn64)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_00124338(u8* p, s32 base, u32 c);  // 0x00124338: definition moved into src/anon/unit_00123990.cpp
u32 __fixunssfsi(f32);
u32 func_001333f8(u8* p, u32 a, u32 b);  // 0x001333f8: definition moved into src/anon/unit_00131418.cpp
void func_00144908(f32* b, V4* out);  // 0x00144908: definition moved into src/anon/unit_00144450.cpp
void func_00148a68(u32, u8*);
void func_00147f08(u32, u8*);
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
s32 func_001541d8(u8*, u32*, u32);
u32 func_00154288(u8*, u32, u32);  // state_index_0_1_2
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
void func_001391c8(u8*, u32);
void func_00138748(u8*);
// 00153fa0: moved to src/anon/unit_00153ea0.cpp
void func_00153fa0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern s8 D_004f3590;
extern f32 D_004f3598;
f32 func_0017ce10(f32);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s32, s32);
// 00155cb0: moved to src/anon/unit_00153ea0.cpp
void func_00155cb0(u8* p, s32 a, s32 b);
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
struct DotArg { V4* a; V4* b; };
// 0016da20: moved to src/anon/unit_0016d2e0.cpp
u32 func_0016a070(u32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
}

}
namespace w72_d3 {
extern "C" {
extern u8 D_0032bae0[];
void func_00198450(u8*);
u32 func_0016c008(u8*, s32);
u32 func_001d9dd0(u8, u8, u32);
s32 func_001d9d48(u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
typedef void (*VFn)(u8*);
void func_001d9f30(u8* p);  // 0x001d9f30: definition moved into src/anon/unit_001d9d00.cpp
extern u8* D_00352ae0;
s32 func_001dc9d0(u8*);
s32 func_001dc738(u8*);  // state_gate_flags
void func_001dda78(void);  // 0x001dda78: definition moved into src/anon/unit_001dd920.cpp
typedef void (*Fn32)(u8*, u8*);
extern u8* D_01d9e6e0;
u8* func_001e7a98(u8*, u8*);
union HF { s16 h; f32 f; };
void func_001ea100(u32 x, u8* d, HF* v);  // 0x001ea100: definition moved into src/anon/unit_001e8ac8.cpp
s32 func_002282f0(s16);
u8* func_00227d10(s16);
void func_001ba028(u8*);  // list_contains_ptr
s32 func_001c0cd8(u8*);
void func_001c0e60(u8*);
void func_00232db0(s16);
void func_00227950(void);
u8* func_00102c18(s32, s32, void (*)(void));
union HP { s16 h[4]; u8* q; };
void func_0022f308(HP* hp);  // 0x0022f308: definition moved into src/anon/unit_0022d358.cpp
extern u32 D_0035eb88;
void func_001391c8(u8*, u32, u32);
void func_00236a58(u8*, u32, u32);
void func_0023c100(u8*, u32, u8*, u32);
void func_0023f070(u8*, u32, s32);
void func_0023f168(u8*);
void func_0023eea0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e);  // 0x0023eea0: definition moved into src/anon/unit_0023e5d0.cpp
extern char D_00371698[];
void func_002ff2e8(char*, const char*);
s32 strlen(const char*);  // strlen
void func_00240118(char*, u32, u32);
extern u8* D_0035ee34;
extern s8 D_0035ee51;
extern u8* D_0035ee48;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_00250998(void);  // 0x00250998: definition moved into src/anon/unit_0024fbd0.cpp
struct S36 { u32 w[9]; };
extern u8 D_00352770;
extern u8 D_00350379;
s32 func_001bb4a0(void);
S36 func_00199098(void);
}

}
namespace w72_e1 {
extern "C" {
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
// 001ad330: moved to src/anon/unit_001abb28.cpp
}

}
namespace w72_e2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
struct NoTail { ~NoTail() {} };
void func_0031e590(u8* p);  // 0x0031e590: definition moved into src/anon/unit_0031e268.cpp
s32 func_00168aa0(u32, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_0031ae58(u32* p, u32 a);  // 0x0031ae58: definition moved into src/anon/unit_003197d0.cpp
u8* func_001b9bc8(u8*);
s32 func_0016a070(u8*);
s32 func_0016c008(u8*, s32);
u8* ctarget_002edbf8(u32, u32, u32, u32) asm("_Z16ctarget_002edbf8jjjj");
u8* ctarget_002edbf8(u32 want, u32, u32, u32);  // 0x002edbf8: definition moved into src/anon/unit_002ecdb0.cpp
extern u8* D_0034e948;
extern u8 D_00362698[];
void func_001c0d38(u8*, u8*, s32, s32);
void func_002cf2b0(u8*, s32);
void func_0016ace0(u8*, V4*);
void func_0016b070(u8*, V4*);
s32 func_002e7568(u8*, s32, u8*, f32);
void func_002dae38(u8* p);  // 0x002dae38: definition moved into src/anon/unit_002da040.cpp
extern V4 D_01e2be20;
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016af58(V4*, u8*);
void func_002cba88(V4*, u32, V4*, V4*, f32, f32);
// 002e35e8: moved to src/anon/unit_002e2f08.cpp
typedef s32 (*Fn8)(u8*);
void func_002c65f8(u8*, s32);
void func_002c6280(u8*, s32);
struct S20 { u32 w[5]; };
extern u8 D_00361da8[];
extern u8 D_00361a80[];
extern u8* D_00361a70;
void func_0031cc28(u8*);
void func_002c6420(u8*);
}

}
namespace w72_e5 {
extern "C" {
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Spr { u8 pad[4]; u16 w, h; s16 x, y; u32 z; u8 r, g, b, a; u8 pad2[180]; u64 rgbaq; u8 pad3[8]; u64 xyz0; u8 pad4[8]; u64 xyz1; u8 pad5[16]; u8 next[4]; };
void func_0014d8d0(u8*);
void func_0014b838(Spr* p);  // 0x0014b838: definition moved into src/anon/unit_0014b838.cpp

void func_0014c350(Spr* p);  // 0x0014c350: definition moved into src/anon/unit_0014b838.cpp

void func_0014c738(Spr* p);  // 0x0014c738: definition moved into src/anon/unit_0014b838.cpp

}

}
namespace w73_f1 {
extern "C" {
typedef void (*Fn68)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001243f8(u8* p, s32 base, u32 c);  // 0x001243f8: definition moved into src/anon/unit_00123990.cpp
u32 __fixunssfsi(f32);
u32 func_001334a8(u8* p, u32 a, u32 b);  // 0x001334a8: definition moved into src/anon/unit_00131418.cpp
void func_0014b220(u8*, s32, s32, s32, s32);
void func_0014b620(u8*, s32);
extern u8* D_00347f80;
typedef u8* (*AllocFn)(u8*, s32, s32);
void func_0031bcf8(u8*);
void func_001516b0(u8*, u32, u32, u32, u32, u32, f32);
struct T96 { u8 pad[80]; s32 v; u8 pad2[12]; };
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_001a98e8(T96*, s32, u32, s32, s32);
s32 func_0023aa18(u8*);
void func_001508a0(u8* p, u32 a);  // 0x001508a0: definition moved into src/anon/unit_0014ecb8.cpp
void func_00139598(u8*);
}

}
namespace w73_f2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
typedef void (*VFn)(u8*);
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void CopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ApplyM(V4* d, M4* m, V4* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
s32 func_00197920(u8*);
void func_00138c10(u8*, s32);
void func_001390a8(u8*);
extern f32 D_00349e14;
void func_0017c430(u8*, V4*, f32);
void func_0011b6a8(M4*);
M4* func_0011b6d8(M4*, f32);
M4* func_0011b720(M4*, f32);
f32 func_0017ce10(f32);
// 0017d5e8: moved to src/anon/unit_0017c400.cpp
// 0017d538: moved to src/anon/unit_0017c400.cpp
typedef void (*Fn20)(u8*, f32*, f32*);
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
s32 func_002bc420(u8*);
s32 func_0019c6f0(u8*);
void func_002bc3f0(u8*, V4*);
void func_002bc398(u8*, V4*);
struct E8b { u32 a; u8* p; };
extern E8b D_01c61970[];
u32 func_00191f20(u8*, u32);
void func_001920f0(u32);
void u_tail4_00192048(u32, u32, u32, u32) asm("_Z16u_tail4_00192048jjjj");
struct NoTail { ~NoTail() {} };
// 00192048: moved to src/yasui/libys/message.cpp
extern u8 D_01c62fb8[];
extern u8 D_0032e020[];
u8* func_0031f168(u8*, u8*);
void func_001a1840(u8*);
u8* func_001a0e78(void);
u32 func_00188fe0(u8*, s32);
u8* func_001a1490(s32 k);  // 0x001a1490: definition moved into src/anon/unit_0019fb70.cpp
s32 func_001de2e0(u32, u32);
u8* func_001de168(u32, s32, u32, u32, u32, s32);  // scan_list_by_half
V4* func_001dc5f8(u8*);
// 001a3b48: moved to src/yasui/libys/effect.cpp
s32 func_001d35e0(V4*, V4*, V4*, u32);
s32 func_001a7610(V4*, V4*, u32, f32, f32) asm("_Z13func_001a7610jjjff");
}

}
namespace w73_f3 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_0023acd8(u8*);
void func_0023ade0(u8*);
void func_001abba8(u8*, u32, u32);
// 001abf38: moved to src/anon/unit_001abb28.cpp
typedef void (*CbFn)(u32, u32, s32);
struct Rd { CbFn volatile cb; u8* obj; u32 buf; u32 size; s32 e; };
extern Rd D_00350cb0;
void func_003058a0(s32);
s32 func_002f7dc8(void);
void func_001c1748(u8*, u32, u32, u32);  // obj_init_from_src
struct Hit { u8 pad[16]; u32 a; s32 id; };
s32 func_00143b88(V4*, Hit*, u16*, u32*, u32);
s32 func_00143ae0(V4*, Hit*, u16*);
s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001d1b60(u8*, s32);
void func_001d8718(s32 base, s32 i);  // 0x001d8718: definition moved into src/anon/unit_001d7458.cpp
extern f32 D_00349e10;
V4* func_001e0cc8(u8*);  // entry64_by_field32
V4* func_001e0ce8(u8*);  // entry64_by_field32_b
void func_001e0d08(u8*, V4*);
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
void func_001e1500(u8* p);  // 0x001e1500: definition moved into src/anon/unit_001e0cb8.cpp
extern u8* D_01d9e6e8;
void func_001fa668(u8*, u32, u8*);
void sceVu0ApplyMatrix(V4*, u8*, V4*);
void sceVu0ScaleVector(u8*, V4*, f32);  // vec_scale_by_f12
void func_001faea8(u8*, s32, s32);
}

}
namespace w73_f4 {
extern "C" {
extern s32 D_0035ece0;
extern s32 D_003718d0[];
void func_0023d320(s32);
void func_00242740(s32);
void func_00287910(s32, s32, s32);
u32 func_00103570(void);
void func_0028c878(u32, s32);
void func_002425d0(s32);
void func_00242fa0(void);
typedef void (*KFn)(s32);
u8* func_00243150(void);
extern u8* D_0035eea4;
extern s16 D_0035eea0;
extern s16* D_0035ee9c;
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0023f100(u8*);
s32 func_0023f0c0(u8*);
void func_0023f0c8(u8*, s32);
void func_00252ce0(void);  // 0x00252ce0: definition moved into src/anon/unit_00250fb8.cpp
u8* func_00257770(void);
s32 func_002570a0(s32);
u8* func_002632d0(s32);
u32 tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
u32 func_002594b8(u8);
void func_00192e50(u32, u8*, s32, u32, u32);
void func_00257458(u8*, s32);
void func_002571e0(s32);
void func_00287cc0(s32);
void func_001391c8(u8*, u32, u32);
void func_0028e2a8(u8*, s32);
void func_0028e190(u8*, s32);
void func_0028e3b8(u8*, s32, u32, u32, s16);
void func_0028e0d8(u8* p, u32 a1, u32 a2, u32 a3, s16* list, s32 n, u32 t2);  // 0028e0d8: moved to src/anon/unit_0028c878.cpp
extern u8* D_0035f480;
s16* func_0028f690(s32);  // record884_type_index
void func_00138c10(u8*, s32);
void func_0028d5d0(u8*);
s32 func_0028d6e8(u8*);
union GPi { u8* p; s32 i; };
extern GPi D_0035f480u asm("D_0035f480");
s32 func_0028f930(s32 k);  // 0028f930: moved to src/anon/unit_0028f1e0.cpp
struct E16c { s8 id; u8 pad[3]; u16 a, b; u8 pad2[2]; u16 c, d; u8 pad3[2]; };
u8* func_00294000(s32);
s32 func_002941d8(E16c*);
}

}
namespace w73_f5 {
extern "C" {
u32 func_00317138(u32);
u32 func_00317130(u32);
u32 func_00317128(u32);
void func_002fd160(void) __attribute__((noreturn));
// libgcc unwind-pe.h base_of_encoded_value (second copy)
u32 func_00314a50(u8 enc, u32 ctx);  // 0x00314a50: definition moved into src/libsupc++/eh_personality.cpp
void func_002f1900(u8*, s32, u8*);
void func_002f19c8(u8*);
void func_002c6050(u8* p, s32 k);  // 0x002c6050: definition moved into src/anon/unit_002c53c8.cpp
u8* func_00294000(s32);
s32 func_002944d0(u8*);
s32 func_00276c18(void);
union U52 { u8 b; s8 c; u32 w; };
extern u8* D_0035f638;
s32 func_00292630(void);
void func_002b2840(void);
void func_00293bd0(s32, u8*, s32);
void func_002925c0(void);
void func_002b2428(u32 v);  // 0x002b2428: definition moved into src/anon/unit_002b1db8.cpp
extern u8 D_01e2a410[];
extern u32 D_003616e0;
extern u32 D_01e2a400[3];
void func_002b7fbc(s32);
void func_002b6bc4(s32);
void func_002b9ab8(s32);
void func_002ba298(s32);
void func_002ba390(void);
void func_002bce40(u8*);
void func_002bce50(u8*);
void func_002b9b78(void);
void func_002bd218(void);
void u_tail0_002b9ad0(void) asm("_Z16u_tail0_002b9ad0v");
void u_tail0_002b9ad0(void);  // 0x002b9ad0: definition moved into src/anon/unit_002b9ab8.cpp
extern f32 D_00349e10;
void func_00187750(u8*);
f32 fabsf(f32);  // fabsf
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_002ef180(u32*, f32, f32);
typedef s32 (*Fn8)(u8*);
extern u8 D_0034a548[];
extern u8 D_00347e80[];
extern u8 D_00347e60[];
void func_002361a0(u8*);
void func_00239700(u8*);
}

}
namespace w74_g1 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*Fn72)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001244b8(u8* p, s32 base, u32 c);  // 0x001244b8: definition moved into src/anon/unit_00123990.cpp
extern f32 D_00349e10;
f32 func_0017ce10(f32);
f32 fabsf(f32);  // fabsf
s32 func_00116d08(u8* p);  // 0x00116d08: definition moved into src/anon/unit_00114a90.cpp
void func_00136200(u8*, u32);
void func_00136020(u8*);
u32 func_001dc5f0(u32);
// 00136158: moved to src/naka/libkn/effect_observer.cpp
extern u8 D_003495c0[];
extern u8 D_003496d0[];
extern u8 D_003497e0[];
extern u8 D_003498f0[];
void func_0014b1e0(u8*, s32, s32);
void func_0014b208(u8*, s32, s32);
void func_0014ad58(void);  // 0x0014ad58: definition moved into src/harata/libdk/fade.cpp
extern u8 D_0034a6b8[];
u32 func_00152598(u8*, u32, u32, u8*);
void func_00152508(u8*, u32, u32, u32, u32);
void func_00152990(u8* p, u32 a1, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);  // 0x00152990: definition moved into src/anon/unit_0014ecb8.cpp
extern u8 D_0035eb98[];
extern u8 D_0034a7c0[];
u8* func_0023ee30(s32);
void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
void func_00153cc8(u8*, u32, s32, u32, s32);
s32 func_0013a9d0(void);
void func_00236bb8(u8*, f32);
u8* func_00153d70(u32 a, u32 b);  // 0x00153d70: definition moved into src/anon/unit_00153678.cpp
extern u8 D_0034af40[];
extern u8 D_0034b0e0[];
void func_00236788(u8*);  // to_236830
u8 func_00239d30(u8*, u32);
s32 func_00239d10(u8*);
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_0013f020(void);
void func_0023acd8(u8*);
void func_0023ade0(u8*);
}

}
namespace w74_g2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline void CopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ApplyM(V4* d, M4* m, V4* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_001431c0(void);
void func_00161228(void);
u8* func_001de4b0(u8*, s32, u8*);
s32 func_001dc9e0(u8*);
void func_001dc698(u8*, s32);
// 0015f298: moved to src/harata/libdk/map_effect.cpp
struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182940(E12*);
// 00182bc0: moved to src/anon/unit_00182780.cpp
f32 func_0017ce10(f32);
void func_0017d1d8(M4*, u32, f32);
struct B32 { f32 a, y, c; u32 d; V4 pos; };
f32 fabsf(f32);  // fabsf
s32 func_0018a420(B32* a, B32* b);  // 0x0018a420: definition moved into src/anon/unit_00189d38.cpp
typedef void (*PosFn)(V4*, u8*);
V4* func_0018df90(V4* out, u8* p, u8* o);  // 0x0018df90: definition moved into src/anon/unit_0018d050.cpp
struct S36 { u32 w[9]; };
u8* func_001050d8(s32);
u32 func_00181c80(u32);
void func_00196ca8(u8*, u32, u32);
void func_00196f00(u8*);
void func_00197930(u32 a, u32 b, S36* c);  // 0x00197930: definition moved into src/anon/unit_00195d00.cpp
s32 func_00181500(s32);
s32 func_001afee8(s32 a, s32 b);  // 0x001afee8: definition moved into src/anon/unit_001ada38.cpp
}

}
namespace w74_g3 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
typedef void (*Fn20)(u8*, u8*);
void func_0017c870(V4*, f32, f32);
s32 func_001b2d10(u8*, V4*);
u8* func_001b9bc8(u8*);
u8* func_0016b800(s32);
s32 func_0019ba60(u8*);
void func_00190878(u8*, u8*, s32);
void func_001bc778(u8*);
s32 func_001c8bb8(s8*);
u32 func_001c8cc0(s8);
void func_001bc780(u8*, u32, u8*, s32);
u8* func_001bf010(u8* p);  // 0x001bf010: definition moved into src/anon/unit_001bc568.cpp
extern f32 D_00349e10;
f32* func_001dc670(u8*);
void func_001dc878(u8*);
void func_001dcae0(u8* p);  // 0x001dcae0: definition moved into src/anon/unit_001dbfd8.cpp
u8* func_00102c80(void);
u8* func_00104190(void);
void func_00102180(u8**);
void func_001e02f8(s32);
void func_001de8a8(u32, s32, s32, s32);
extern f32 D_00354be0[3];
extern u8* D_01d9e6e8;
extern u8 D_01d9e940[];
extern u8 D_01d9e900[];
void sceVu0ScaleVector(u8*, u8*, f32);  // vec_scale_by_f12
void sceVu0MulMatrix(u8*, u8*, u8*);
void sceVu0ApplyMatrix(u8*, u8*, u8*);
union GPV { u8* p; V4 v; };
extern GPV D_01d9e6e8u asm("D_01d9e6e8");
void func_001eb460(void);  // 0x001eb460: definition moved into src/anon/unit_001e8ac8.cpp
}

}
namespace w74_g4 {
extern "C" {
extern u8* D_0035ece8;
extern u8* D_0035ecec;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00244888(void);  // 0x00244888: definition moved into src/anon/unit_00242478.cpp
struct E6 { s16 a, b, c; };
extern s32 D_0035ee2c;
extern u8* D_0035ee10;
extern E6 D_00372390[];
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0024f2b8(s32);  // word_table_372368
void func_00138c10(u8*, s32);
void func_0024f1a0(void);  // 0x0024f1a0: definition moved into src/anon/unit_0024e7e8.cpp
extern u8* D_0035f02c;
extern u8 D_0035f056;
void func_0028dac8(u8*, s32);
s32 func_00256b80(s32);
u8* func_00256b68(s32);
u32 func_00287dc0(void);
void func_0023d820(u32);
void func_00254e60(void);  // 0x00254e60: definition moved into src/anon/unit_00254020.cpp
extern E6 D_00373798[];
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00269508(s32);
s32 func_00269fc0(void);  // 0x00269fc0: definition moved into src/anon/unit_00269a60.cpp
extern u32 D_0035f4bc, D_0035f4c0, D_0035f4c4, D_0035f4c8, D_0035f4cc, D_0035f4d0;
extern u16 D_0035f4d8, D_0035f4e0;
extern u8 D_0035f4e2;
extern void* D_0035f4d4;
extern void* D_0035f4dc;
extern void* D_0035f4e4;
void func_00106450(void*);
void func_002927b8(void);  // 002927b8: moved to src/anon/unit_00292620.cpp
extern u32 D_0035f570;
extern u8* D_0035f574;
extern u32* D_0035f578;
u8* func_001063c0(s32, u32);
void func_002907c0(u8*, u32, s32);
void func_00276150(u32, s32*, s32*);
s32 func_00276568(void);
s32 func_002956c0(s32);
s32 func_00295710(s32 a);  // 0x00295710: definition moved into src/anon/unit_00292e60.cpp
extern u32 D_0035f59c;
extern s16* D_0035f598;
extern s8 D_0035f5a1;
extern u8 D_0035f5a2;
void func_0023f900(u32);
s32 func_00292630(void);
s8* func_002983d8(s16);
char* func_00293de8(s8);
void func_002ff2e8(char*, const char*);
void func_002feee8(char*, const char*);
u32 func_00293db8(s32, char*);
void func_0023fa08(u32, u32);
void func_00298ee0(void);  // 0x00298ee0: definition moved into src/anon/unit_002982f0.cpp
extern u8* D_0035f5f4;
extern u8* D_0035f5f8;
extern s8 D_0035f5fc;
extern s8 D_0035f5fd;
void func_00106420(u8*);
typedef void (*VFn)(u8*);
void func_002a6970(void);  // 0x002a6970: definition moved into src/anon/unit_002a5a90.cpp
}

}
namespace w74_g6 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(u8*);
extern u8* D_01e2aa80;
void func_002bbf68(u8*, s32);
static inline u8* NextZ(u8* n) { if (!n) return D_01e2aa80; return *(u8**)(n + 28); }
void func_002bc470(u32 id);  // 0x002bc470: definition moved into src/anon/unit_002bb8b0.cpp
extern u8* D_0034e948;
extern s8 D_01e2bc20;
extern V4 D_01e2bc30;
u32 func_0016b740(s32);
void func_001c0d38(u8*, u32, s32, s32);
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_002be6e8(void);
void func_0016b070(u8*, V4*);
void func_0017f488(u8*, s32, f32, f32);
extern f32 D_00349e18;
extern f32 D_00349e10;
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
// 002c6610: moved to src/anon/unit_002c6420.cpp (linked unit)
extern u32 D_00361f60;
void func_001780d8(u8*);
void func_00198860(u8*, s32);
u8* func_002d1f00(u32);  // ptr_add160
void func_0016ace0(u8*, V4*);
void func_0016aef0(u8*, V4*);
void func_0016bd60(u8*, s32);
void func_002d4aa0(u8* p);  // 0x002d4aa0: definition moved into src/anon/unit_002d4548.cpp
struct HT { u8* head; u8* tail; };
extern HT D_01e2c080;
extern u8 D_00363808[];
extern u32 D_003637f8;
void func_002edf28(u8*);  // obj_ctor_3637e0
u8* func_002ee840(void);  // get_data_1e2c088
void func_002ee498(void);
u32 func_00102788(u32, s32, s32, void (*)(void));
void func_002ee220(u8* p);  // 0x002ee220: definition moved into src/anon/unit_002ecdb0.cpp
extern s8 D_003638c8;
s32 func_002ef7b8(void);
void func_002ef7a0(s32, s32);
extern u8 D_00347dd0[];
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_00239870(u8*);
void func_002361d0(u8*);
void func_0031a840(u8*);
typedef void (*FreeFn)(u8*, u8*);
void func_0031a460(u8* p);  // 0x0031a460: definition moved into src/anon/unit_003197d0.cpp
extern u8 D_0034a618[];
void func_0031c6f8(u8* p);  // 0x0031c6f8: definition moved into src/anon/unit_0031b9e0.cpp
}

}
namespace w74_b4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct B32 { f32 a, y, c; u32 d; V4 pos; };
u8* func_001b9bc8(u8*);
u32 func_0016bba8(u8*, s32, u32);
void func_0018a818(B32*, u8*, u32);
extern u8* D_0034dca0;
extern u32 D_0034dcb0;
void func_001700e8(u8*, s32);
void func_0016fc10(u8*);
s32 strcmp(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* func_0018bc60(u8*, s32);
u32 func_0018bae8(u8*, u8*);
// YS::STDOBJ::hook_command_image
extern s8 D_0036d0c8[4];
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_0013d6b0(u32, u32);
static inline u32 Key4(s8* k) { return k[0] | k[1] << 8 | k[2] << 16 | k[3] << 24; }
void STDOBJ_hook_command_image(u8*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
// image: moved to src/anon/unit_00197fe0.cpp
typedef s32 (*Fn8)(u8*, u32);
static inline u8* NextR(u8* p, u8* n) { if (!n) return *(u8**)(p + 12); return *(u8**)(n + 96); }
struct E56 { u32 a; u32 b; u8 pad[4]; u32 c; u32 d; u8 pad2[36]; };
extern E56 D_01c62198[64];
void func_00199cd0(E56*);
void wtarget_0019b970(u32, u32, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void func_0019e210(u8**, u32);
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
}

}
namespace w75_h1 {
extern "C" {
typedef void* (*AllocFn)(u8*, u32, void*);
extern s32 D_0033cc68;
extern void* D_0033cc64;
extern void* D_0033cc6c;
extern void* D_0033cc70;
void func_00133cf0(void*, u32);
void func_00109070(void);
struct E6 { s16 a, b, c; };
extern E6 D_00347770[6];
void func_00194108(u32, s16);
void func_001940f0(u32, s16);
void func_001c8cf8(s32);
void func_00119e60(u8* p, s32 v);  // 0x00119e60: definition moved into src/anon/unit_00119bf8.cpp
u32* func_002f35e8(s32);
void func_003058a0(s32);
extern u8* D_00347d64;
void func_00192c90(u8*, u8*);
void func_00192b30(u8*);
void func_002362b0(u8*, u32);
s32 func_0013a9d0(void);
void func_002368e8(u8*, f32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
// 00154048: moved to src/anon/unit_00153ea0.cpp
void func_00154048(u8* p, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1);
s32 func_0013c7d0(void);
s32 func_00155d58(u8*, s32);  // table_word_indexed_by_3
s32 func_00155f40(u8*);
s32 func_00155fc0(u8*);
void func_00138c10(u8*, s32);
void func_00157aa0(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 001578d8: moved to src/anon/unit_00157688.cpp
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_00143228(void);
void func_0015c4a0(s32);
void func_001de3d8(u8*, s32);
// 0015f4a0: moved to src/harata/libdk/map_effect.cpp
}

}
namespace w75_h2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
static inline void VCopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
void func_0011b6a8(M4*);
M4* func_0011b7b0(M4*, u8*);
// 001604f8: moved to src/harata/libdk/bgobj.cpp
s32 func_0019c5d0(u8*);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_001dc9e0(u32);
void func_001dc818(u32);
// 00185988: moved to src/anon/unit_001855e0.cpp
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016aef0(u8*, V4*);
s32 func_0019ba60(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0018b288(u8* p, V4* v, f32 x);  // 0x0018b288: definition moved into src/yasui/libys/npc.cpp
s32 func_0018bd50(u32, s32);
s32 u_call4_0018c598(u32, u32, u32, u32) asm("_Z16u_call4_0018c598jjjj");
extern u8* D_0034e948;
extern u8 D_01c60d10[];
u8* func_001cd7a8(u8*);
s32 func_0016a090(u8*);  // get_byte74
void func_00190878(u8*, u8*, s32);
s32 func_0019f528(u8*, u32);  // test_bit_by_index
s32 func_0019f550(u8*, u32);  // test_bit_addressable
void func_0019f490(u8*, u32);
typedef void (*Fn80)(u8*, u32, u32, u8*, u32);
// 00198ae0: moved to src/anon/unit_00197fe0.cpp
extern u32 D_0034f240;
extern u8 D_0036d8b8[];
void func_001c8ba8(void);
u8* func_001050d8(s32);
u32 func_0016e920(s32);
f32 func_0016afe0(u8*);
void func_001c7fb8(u8*, u32, V4*, f32);
void func_001880b0(u8*, u8*);
void func_001373d8(void);
extern u32 D_01d48cb0;
extern u8 D_00351eb8[];
typedef s32 (*Fn64)(u8*);
void func_001b5250(u32, s32);
u8 func_001c8db8(u8*, s32);
void func_001d4180(void);
}

}
namespace w75_h4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
void func_001bd668(u8*);
void func_001d4818(u8*, u32, u32, u32, u32);
void func_001d48e8(u8*, u32, u8*);
void func_001bd5b0(u8*, s32, s32);
void func_001bdb70(u8* p, u32 a, u32 b, u32 c, u32 d);  // 0x001bdb70: definition moved into src/anon/unit_001bc568.cpp
extern u32 D_01d49960;
extern u32 D_01d49968;
extern u8 D_0036e068[];
u8* func_001d6d88(void);
u8* func_001050d8(s32);
u32 func_0016e920(u32);
void func_001c7fb8(u8*, u32, V4*, f32);
void func_00188120(u8*, u8*);
// 0x1c88a8: moved to src/yasui/libys/summon.cpp
void func_001ddef0(u8**, u8*, u32, u32, u32, u32);
void func_001de228(u8** p, u32 k, u32 c, u32 d, u32 e, u32 f);  // 0x001de228: definition moved into src/anon/unit_001ddcf0.cpp
union UF { u32 i; f32 f; };
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
f32 func_001ee7a8(u8 two);  // 0x001ee7a8: definition moved into src/anon/unit_001ec098.cpp
f32 func_001ee988(u8 two);  // 0x001ee988: definition moved into src/anon/unit_001ec098.cpp
extern u8 D_0035de24, D_0035de25, D_0035de56;
extern s32 D_0035de28, D_0035dd04;
extern u32 D_0035de4c, D_0035de50, D_0035de2c;
extern u32 D_0035dd08[64];
extern V4 D_0035de70;
void func_0022d7c8(void);
void func_00225a00(void);  // zero_global_byte_e
void func_00225a20(void);
void func_0022d7e8(void);
void func_00226fc8(void);  // 0x00226fc8: definition moved into src/anon/unit_00224780.cpp
extern f32 D_00349e10;
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_001d6790(Seg*);
void func_001024a8(u8*);
void func_0022c840(u8* p);  // 0022c840: moved to src/sasa/event_layout.cpp (linked unit)
}

}
namespace w75_h5 {
extern "C" {
extern u8* D_0035ed20;
extern u8* D_0035ed24;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00246708(void);  // 0x00246708: definition moved into src/anon/unit_00242478.cpp
extern u8 D_0035f0e8;
extern u8* D_0035f0e4;
u32 func_00267248(void);  // global_ptr_by_flag32
s32 func_0028b040(u32);
s32 func_0028afa8(u32);
void func_002891f0(u32, s32, s32, s32, s32);
u32 func_00257130(void);
s32 func_002827e0(u32, s32);  // get_indexed_word
s32 func_002813b8(void);
s32 func_00281420(void);
extern u32 D_0035f0fc;
u32 func_00293bc0(void);
s32 func_001a8bf8(u32, s32);  // get_bits5_at
s32 func_0026d8c0(s32 x);  // 0x0026d8c0: definition moved into src/anon/unit_0026c450.cpp
extern u8 D_00373ab0[];
extern u8 D_00373af8[];
extern u8 D_00373ae0[];
u8* func_00273180(s32 k, s32 id);  // 0x00273180: definition moved into src/anon/unit_00271e08.cpp
extern u8* D_0035f5d8;
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(u8*);
void func_002a0860(void);  // 0x002a0860: definition moved into src/anon/unit_0029f938.cpp
extern u8* D_0035f5f4;
typedef void (*VFn)(u8*);
void func_00276a18(void);
void func_00276b10(void);
extern u8* D_0035f604;
s32 func_00276a90(void);
void func_00276b90(void);
extern u8* D_0035f5f8;
extern u8 D_0035f5fc;
extern u8 D_0035f5fd;
void func_002b64d8(u8*);
u8* func_00290948(u8*, s32);
void func_002b6530(u8*);
void func_00293d80(s32);
void func_002a75c0(void);  // 0x002a75c0: definition moved into src/anon/unit_002a7308.cpp
extern u32* D_0035f610;
s32 func_002a9e98(s32);
u8* func_00294000(s32);
s32 func_002aa098(s32 id);  // 0x002aa098: definition moved into src/anon/unit_002a99c8.cpp
}

}
namespace w75_h7 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(u8*);
typedef void (*FreeFn)(u8*, u8*);
extern u8 D_00347d90[];
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_00239870(u8*);
void func_002361d0(u8*);
void func_0031a840(u8*);
void func_0031a628(u8* p);  // 0x0031a628: definition moved into src/anon/unit_003197d0.cpp
extern u8 D_0034a660[];
void func_0031c838(u8* p);  // 0x0031c838: definition moved into src/anon/unit_0031b9e0.cpp
extern u8 D_0034a568[];
void func_002d00a0(u8*);
void func_0016bd60(u8*, s32);
u32 func_002d1260(void);
void func_001c0d38(u8*, u32, s32, s32);
void func_0016b070(u8*, V4*);
void func_0016ace0(u8*, V4*);
s32 func_001c0cd8(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_00180378(u8*, u8*, s32, f32);
void func_002da958(u8* p);  // 0x002da958: definition moved into src/anon/unit_002da040.cpp
}

}
namespace wcx_retry_r1 {
extern "C" {
extern u8* D_0035f5f4;
typedef void (*VFn)(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00276a18(void);
void func_00276b10(void);
struct E436 { u8 d[436]; };
extern E436 (*D_0035f5f4b)[2] asm("D_0035f5f4");
void func_002a73d0(void);  // 0x002a73d0: definition moved into src/anon/unit_002a7308.cpp
}
extern "C" {
extern E436 (*D_0035f604b)[2] asm("D_0035f604");
s32 func_00276a90(void);
void func_00276b90(void);
s32 func_002a81a8(void);  // 0x002a81a8: definition moved into src/anon/unit_002a7308.cpp
}

}
namespace wcx_retry_f1 {
extern "C" {
typedef void (*Fn68)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
u32 __fixunssfsi(f32);
void func_0014b220(u8*, s32, s32, s32, s32);
void func_0014b620(u8*, s32);
extern u8* D_00347f80;
typedef u8* (*AllocFn)(u8*, s32, s32);
void func_0031bcf8(u8*);
void func_001516b0(u8*, u32, u32, u32, u32, u32, f32);
struct T96 { u8 pad[80]; s32 v; u8 pad2[12]; };
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_001a98e8(T96*, s32, u32, s32, s32);
s32 func_0023aa18(u8*);
void func_00139598(u8*);
// 001544b0: moved to src/anon/unit_00153ea0.cpp
void func_001544b0(u8* p);
}

}
namespace wcx_retry_r2 {
extern "C" {
u8* func_00294000(s32);
extern u8* D_0035f620;
s32 func_002ad7d0(s32 id);  // 0x002ad7d0: definition moved into src/anon/unit_002a99c8.cpp
s32 func_002ad950(s32 id);  // 0x002ad950: definition moved into src/anon/unit_002a99c8.cpp
}
extern "C" {
extern u8* D_0035f610;
s32 func_002aacd8(s32);  // test_bit_global_d
s32 func_002ab100(s32);  // test_bit_global_c
}

}
