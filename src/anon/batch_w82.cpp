#include "../common/types.h"

// Disables sibling-call optimisation where the original keeps jal + epilogue.
struct NoTail82 { ~NoTail82() {} };

struct E0013 { u32 b; u32 a; };
struct Tbl0013 { u32 res; s32 count; E0013 e[1]; };
extern Tbl0013 D_00347fd8;
extern u8 D_004193c0[];

struct Alloc0014 { struct VT { void* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr0014 { u8 pad[20]; Alloc0014* heap; };
extern Mgr0014* D_00347f80;

extern u8 D_0034d850[];

struct Node0017 { u8 pad[40]; s32 val; u8 pad2[16]; Node0017* next; };
struct Q0017 { Node0017* head; Node0017* tail; };
extern Q0017 D_0034dcb8;
extern struct { Node0017* first; } D_0034dca0;

extern u8* D_00352130;
extern u8 D_0032bb30[];
union FU82 { f32 f; u32 u; };
// 16-byte vector whose assignment is a 128-bit copy.
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern u8 D_0032e020[];
struct V82z { f32 v[4]; } __attribute__((aligned(16)));
static inline void VZero82(void* p) { asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory"); }

extern "C" {
s32 func_00181a70(u8*);
void func_00189228(u8*, u16);
s32 func_001ba028(u32);  // list_contains_ptr
void func_00177a28(u8*);  // set_bytes_2820_2821
void func_0016bae8(u32, u8*, u16, u8*);
void func_0016bd60(u8*, s32);
u32 func_00177860(u8*);
s32 func_001c3618(u32, s32);
u8* func_001ce300(s32);  // to_1ce2a0_index_minus1
void func_0017f488(u8*, s32, f32, f32);
void func_001c97b0(u16, f32);
u32 func_001c88a8(u32, f32);
s32 func_001c9958(u8, u16);  // state_pair_check
void* func_001050d8(u32);
void func_0010c078(void*, u8*, u32, f32);
s32 func_00168aa0(void*, s32);
u8* func_00168b38(void*, s32, s32);  // entry_array_find_nth
s32 func_0013d498(void);
void func_0013b3f8(void);
void func_0013a4a8(void);
s32 func_00158450(void*);
s32 func_001584a0(void*);
void func_0013fda0(void*);
void func_0013fdc8(void*);
void func_0031bc58(void*);
void func_0014fe00(void*, u32, u32, u32, u32, u32, u32, u32, u32);
void func_001a17c8(u32);
void func_001b78b8(u32);  // to_105110
void func_002cb708(u32);
void func_00105110(u32);
void func_001b3098(void*);
void func_001a9350(void*);
void func_001a6d68(void*);
void func_00187b90(void*);
void func_0017eb98(void*);
void func_001ddd88(void*);
u32 func_0016e920(void);
u32 func_0016f470(u32, u32);
u32 func_0016f4b8(u32, u32);
u32 func_0016f520(u32, u32, u32);
s32 func_00170978(u32);
s32 func_0016f6f8(u32);  // check_flag_4000_type
s32 func_0016f770(u32);  // in_id_special_range
s32 func_0016f460(u32);
void func_0031e328(void*, Node0017*);
void func_00170188(Node0017*);

// 0013a368: moved to src/harata/libdk/field2dd.cpp

void func_0013fdf0(u8* o, u8* p, f32 s);  // 0x0013fdf0: definition moved into src/anon/unit_0013fca8.cpp

// Allocates a 6192-byte object from the global heap and constructs it.
void* func_0014f8d0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);  // 0x0014f8d0: definition moved into src/anon/unit_0014ecb8.cpp

static inline s32 FlagOff0016(u32 a) { return !(*(u8*)(a + 72) & 1); }

static inline bool Expired0017(Node0017* p) { return !(p->val < 10000); }

static inline Node0017* Step0017(Node0017* c)
{
    Node0017* n = c->next;
    func_00170188(c);
    return n;
}

// Moves nodes whose value reached 10000 to the pending queue, then processes them.
void func_001705a8(void);  // 0x001705a8: definition moved into src/anon/unit_0016e8f8.cpp

static inline bool Reacts0017(u8* a1) { return (*(u32*)(*(u8**)(a1 + 12) + 8) & 2) || (*(u32*)(a1 + 352) & 0x40); }

// 0017a9e8: moved to src/anon/unit_0017a8f8.cpp

// 0017cd20: moved to src/anon/unit_0017c400.cpp

// 0017e418: moved to src/yasui/libys/friend.cpp

// 00178bf0: moved to src/yasui/libys/player.cpp

void u_call4_0016a358(u32, u32, u32, u32) asm("_Z16u_call4_0016a358jjjj");
u32 ctarget_0016f7d0(u32, u32, u32, u32) asm("_Z16ctarget_0016f7d0jjjj");
}

void u_call4_0016a358(u32 a0, u32, u32, u32);  // 0x0016a358: definition moved into src/anon/unit_00169f98.cpp

u32 ctarget_0016f7d0(u32 a0, u32 a1, u32, u32);  // 0x0016f7d0: definition moved into src/anon/unit_0016e8f8.cpp

extern const f32 D_0036cd18;

static inline f32 Dot82(const void* a, const void* b)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}

extern "C" {
void func_0018a958(u8*, u32, f32, f32);
s32 func_0019ba60(u32);
u32 func_00190208(u8*, u32);
void func_0018a818(u8*, u32, u32);
Vec82* func_0016c028(u32);  // obj_get_attach_or_alt
s32 func_001b9d40(u8*, u8*);  // vtable_call_slot64_flags
void func_0016af58(void*, u8*);

void func_001902a8(u8* a0, u8* a1);  // 0x001902a8: definition moved into src/anon/unit_001900d0.cpp

// True when a0 is active and both its facing vectors point along a1 (cos >= 0.7).
s32 func_0019c778(u8* a0, u8* a1);  // 0x0019c778: definition moved into src/anon/unit_0019ba60.cpp
}

struct Mat82 { f32 m[16]; } __attribute__((aligned(16)));
struct Lst001b { u8 pad[4]; s32 count; struct { u32 item; u32 x; } e[1]; };
struct Bones001b { Lst001b* t; u8* arr; s32 idx; };

// 64-byte quadword copy (four lq then four sq).
static inline void Copy64_82(void* d, const void* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}

extern "C" {
void func_0016b0e0(u32, u32, u8*);
void func_00165830(u32, Mat82*);

// Updates each bone matrix into the current double-buffer half, then flips halves.
void func_001b3118(Bones001b* b, u32 a1);  // 0x001b3118: definition moved into src/anon/unit_001b2780.cpp
}

extern f32 D_00349e10;
union FU001d { f32 f; s32 i; };
struct Q001d { u32 a; FU001d f; };
struct S001d { s32 end; s32 cur; Q001d e[3]; u32 cur_a; f32 cur_f; f32 timer; };

extern "C" {
void func_001bc778(u8*);
u8* func_001bc780(u8*, s32, s32, s32);
s32 func_001cf998(void);
void func_001cf9e0(u8*, s32);
s32 func_001d8898(s32);
void func_00190128(void*);
void func_00190878(void*, u8*, s32);
void func_001bd3e0(u32, s32, s32, void*, s32, s32);
void func_00178888(u8*);
s32 func_00197920(S001d*);
void func_001d2668(S001d*, u32, f32);

void func_001cf7d8(u8* a0);  // 0x001cf7d8: definition moved into src/anon/unit_001cf0b0.cpp

// Advances a 3-entry ring of queued requests once the current one's timer has run out.
void func_001d2750(S001d* a0);  // 0x001d2750: definition moved into src/anon/unit_001d14e0.cpp
}

extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
struct Ev001f { u8 pad[4]; s16 f4; u8 pad2[6]; u8 f12; u8 f13; u8 f14; u8 pad3; s32 f16; s32 f20; s32 f24; };

extern "C" {
void func_001e0e40(u8*);
s32 func_00222568(void);  // vu_const_5f_d
void func_001f5cc8(void);
void func_0021ee48(u8*, Ev001f*, void*, u8*, s16, u8, u8);

// Drains queued entries in 0.25 steps of the accumulated time.
void func_001e1d20(u8* a0);  // 0x001e1d20: definition moved into src/anon/unit_001e0cb8.cpp

void func_001f5df8(u8* a0, Ev001f* e, u8* a2);  // 0x001f5df8: definition moved into src/anon/unit_001f5978.cpp
}

extern f32 D_00354be0[3];
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
extern f32 D_00354bd0[3];
extern f32 D_00354bc0[3];
extern u8* D_01d9e6e8;

extern "C" {
void sceVu0ScaleVector(u8*, u8*, f32);  // vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, u8*, u8*);
void sceVu0CopyMatrix(u8*, u8*);
void sceVu0MulMatrix(u8*, u8*, u8*);
void func_0021ec80(u8*, s32*);

void func_001fcb90(u8* a0, u32, u8* a2);  // 0x001fcb90: definition moved into src/anon/unit_001fcaf8.cpp

// Converts the global euler angles (radians) to 16-bit fixed angles and applies them.
void func_00200fd8(u8* a0, u8* a1);  // 0x00200fd8: definition moved into src/anon/unit_00200578.cpp

}

struct VObj82 { struct VT { void* f[8]; }* vt; };
extern VObj82* D_0035edb0;
extern VObj82* D_0035edb8;
extern VObj82* D_0035edb4;
extern u8* D_0035eda8;
extern u8* D_0035edac;
extern u8 D_00373110[];
extern u8* D_0035f01c;
static inline void VCall5_82(VObj82* o) { ((void (*)(VObj82*))o->vt->f[5])(o); }
extern "C" {
s32 func_00139d78(void*);
s32 func_0028acc8(u8*);
void func_0028abe0(u8*);
void func_0024c828(void);
void func_0028ce38(void);
s32 func_00287cd0(void);
s32 func_002b4fb8(void);
s32 func_00287c10(void);
void func_00233e70(s32);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32);
s32 func_00287bc0(void);
void func_002b5188(u8*, s32);
void func_00287cc0(s32);
void func_00240bb0(s32);  // global_store_half2
void func_002417a0(void);
void func_002b4ee0(void);
void func_00287c00(s32);
u8* func_00257770(void);
void func_002634d8(s32);
void func_00257140(s32);
u32 func_00257130(void);
u32 func_00281f30(u32);
s32 func_00281f18(u32);
void func_002827f0(u32, s32, s32);
void func_00138c10(u8*, u32);
void func_00139510(u8*);

void func_0024bcb8(void);  // 0x0024bcb8: definition moved into src/anon/unit_0024ba58.cpp

void func_0025e370(void);  // 0x0025e370: definition moved into src/anon/unit_0025da20.cpp

void func_002655e8(void);  // 0x002655e8: definition moved into src/anon/unit_00265580.cpp
}

extern u32 D_0035f0ec;
extern u32 D_0035f264;
extern u32 D_0035f250;

extern "C" {
u32 func_00257130(void);
u8* func_00281f20(u32);
u8* func_001a80c8(u32);  // table24_find_by_id
s32 func_00281f18(u32);
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
u32 func_00192048(s32);
void wt82(u8*, u32, u32) asm("_Z16wtarget_002fde18jjjj");

// Looks up entry idx of the current table (mode 2 = active slot) and returns its item record.
u8* func_0026a178(s32 idx, s32 mode);  // 0x0026a178: definition moved into src/anon/unit_00269a60.cpp

void func_00280148(void);  // 0x00280148: definition moved into src/anon/unit_0027f2b0.cpp
}

extern u32* D_0035f2e4;
extern s16 D_00374410[][5];

extern "C" {
s32 func_00286058(u8);
u32 func_0023f9c8(u8*, s32);
void func_001386e0(u32, s32, u32, u32, s32, s32);
void func_0028d8c0(u8*, u32, u32, u32, u32, u32, s32, s32);
void func_0028b4c0(u8*, u32);  // copy_3halfwords_416
void func_0028b4f0(u8*, u32);  // copy_3halfwords_422
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s16, s32);
void func_0028dd28(u8*, u32);

static inline s32 Bit0028(s32 i) { return (D_0035f2e4[(u32)i >> 5] & (1 << (i & 31))) != 0; }

// id >= 0: whether item id is flagged and usable; id < 0: whether any of the 640 is.
s32 func_00286068(s32 id);  // 0x00286068: definition moved into src/anon/unit_002853b8.cpp
void func_002877a0(u8* a0, s32 a1, s32 a2);  // 0x002877a0: definition moved into src/anon/unit_00286d28.cpp


void func_0028b300(u8* a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3);  // 0x0028b300: definition moved into src/anon/unit_00288b00.cpp
}

extern u8 D_00347e60[];

extern "C" {
void func_00239700(u8*);
void func_0028dfe8(void*);  // obj_ctor_36f440
void func_00258d40(u32, u32);

static inline void* Alloc82(u32 n) { Alloc0014* h = D_00347f80->heap; return h->vt->alloc(h, n, 0); }

void func_0028fc78(Mgr0014** a0, u32 a1, u32 a2, u16* a3);  // 0028fc78: moved to src/anon/unit_0028f1e0.cpp

}

static inline void QCopy82(void* d, const void* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void VSub82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline f32 VLen82(const void* v)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
union PU82 { u8* p; u32 u; f32 f; };
extern u8 D_00361da8[];
extern u8 D_00361dc8[];
extern u8 D_01e2bdd0[];
extern u8 D_01e2bdc0[];
extern PU82 D_00361db8;

extern "C" {
void func_002c6420(u8*);
u8* func_002d1260(u8*);
u8* func_0016bc20(u32, s32, s32);
void func_0017f540(u8*, s32, f32, f32);
s32 func_001c0cd8(u32);

// 002c66b8: moved to src/anon/unit_002c6420.cpp (linked unit)

// Returns the target in slot a1 if it is within its own reach radius of this object.
u32 func_002d2660(u8* a0, s32 a1);  // 0x002d2660: definition moved into src/anon/unit_002d2498.cpp

void func_002da040(u8* a0);  // 0x002da040: definition moved into src/anon/unit_002da040.cpp
}

static inline void VAdd82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }

extern "C" {
void func_002e2a30(u8*, Vec82*, u8*, u8*);
f32 func_002edd20(u32);
f32 fabsf(f32);  // fabsf
double func_00313b80(f32);  // float_to_double
double func_00313e80(double, double);  // double_div
s32 func_003142e0(double, double);  // double_compare

// 002e2940: moved to src/anon/unit_002e1908.cpp

// Copies a2 into a0 and nudges its y toward the target height by one step.
Vec82* func_002ede48(Vec82* a0, u32 a1, Vec82* a2, f32 f12, f32 f13);  // 0x002ede48: definition moved into src/anon/unit_002ecdb0.cpp
}

typedef union { f32 value; u32 word; } ieee_float_shape82;
#define GET_FLOAT_WORD82(i,d) do { ieee_float_shape82 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD82(d,i) do { ieee_float_shape82 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const f32 huge82 = 9.9999994e29f; // 1.0e30 as stored in the original

extern "C" {
typedef s32 (*Cmp82)(const void*, const void*);

// floorf (newlib, no-denormal / largest-exponent-is-normal configuration).
f32 floorf(f32 x);  // 0x002f8888: definition moved into src/newlib/libm/sf_floor.c

// bsearch
void* func_002fd248(const void* key, const u8* base, u32 n, u32 size, Cmp82 cmp)
{
    u32 lo = 0;
    u32 hi = n;
    if (n == 0 || size == 0) return 0;
    while (lo < hi) {
        u32 mid = (lo + hi) >> 1;
        const u8* p = base + mid * size;
        s32 c = cmp(key, p);
        if (c < 0) hi = mid;
        else if (c > 0) lo = mid + 1;
        else return (void*)p;
    }
    return 0;
}

}
