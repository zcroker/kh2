#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Same, kept out of the assembler's delay-slot filling.
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte aligned vector: copy-construct = quadword copy, assignment skips self.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Mtx {
    Vec4 r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}

// Squared distance of two points (xyz) on VU0.
static inline f32 vu0DistSq(const void* a, const void* b) {
    f32 d;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(d) : "r"(a), "r"(b) : "$2");
    return d;
}

typedef void (*VFn)(void*);

extern "C" {

void func_0017c4c8(void*, Vec4);
void func_0017f488(void*, s32, f32, f32);

static inline bool stateIsOne(u8* c) { return *(s32*)(c + 4) == 1; }

// 0010c940
void func_0010c940(u8* p, s32 n, f32 t);  // 0x0010c940: definition moved into src/anon/unit_0010b978.cpp

// 00124b10: obj->matrix = m * obj->matrix (VU0)
void func_00124b10(u8* p, Mtx* m);  // 0x00124b10: definition moved into src/anon/unit_00123990.cpp

s16* func_001aec40(void*);  // get_global_1c9408c
void func_002b9ab8(s32);
void func_002bc458(s32);
void func_001369d0(void);
void func_001369f0(void);
void func_002b9ed0(void);
void func_00136a60(void);
void func_001363a0(void*);
void func_00136560(void*);
extern u8 D_0032bae0;
extern u32 D_00347d20;

// 001366b8
// 001366b8: moved to src/harata/libdk/bgse.cpp

s32 func_00165db8(s32, s32, s32*, s32, s32, s32, s32*, s32, s32);
void func_00141c18(u32, s32, s32, s32, s32);
s32 func_00141ff0(u32, s32, s32, s32*, s32);
extern u32 D_00348804;

// 00143c68
s32 func_00143c68(s32 a, s32 b);  // 0x00143c68: definition moved into src/anon/unit_00142c90.cpp

struct Sphere { Vec4 c; f32 r; };
struct PointList { Vec4* v[4]; s32 n; };

// 00163168: the list point nearest to the sphere centre, if inside it
s32 func_00163168(Sphere* s, PointList* l, Vec4* out);  // 0x00163168: definition moved into src/anon/unit_001614e8.cpp

// 001ef398: random float, averaged with a second one when asked
f32 func_001ef398(u8 a);  // 0x001ef398: definition moved into src/anon/unit_001ec098.cpp

// 001ef5a0: negative random float, averaged with a second one when asked
f32 func_001ef5a0(u8 a);  // 0x001ef5a0: definition moved into src/anon/unit_001ec098.cpp

s32 func_0016c028(void*);  // obj_get_attach_or_alt
void func_002bc188(s32, s32);

// 00198580: moved to src/anon/unit_00197fe0.cpp

extern f32 D_00349e10;
Vec4 func_00184540(u8*, f32, f32);

// 001b2170
// 001b2170: moved to src/anon/unit_001b1d20.cpp

s32 func_001818e8(void*);
s32 func_001bd590(void*);
s32 func_001bdb10(void*, s32);
void func_001bc720(u32);

// 001be410
void func_001be410(u8* o);  // 0x001be410: definition moved into src/anon/unit_001bc568.cpp

s32 func_001818a0(void*);
s32 func_00177870(void*);
void func_001bc780(void*, s32, s32, s32);

// 001be540
void func_001be540(u8* o, void* x);  // 0x001be540: definition moved into src/anon/unit_001bc568.cpp

s32 func_00242dc8(u32);
extern u32 D_01d49970[];

// 001c8788: test-and-set of a flag bit
// 0x1c8788: moved to src/yasui/libys/summon.cpp

extern void* D_0035ed70;
extern void* D_0035ed74;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);

// 0024ab00
void func_0024ab00(void);  // 0x0024ab00: definition moved into src/anon/unit_00249ef0.cpp

void* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00272b60(s32);
void func_0028dac8(void*, s32);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
struct Entry373 { s16 a; s16 b; s16 c; };
extern Entry373 D_00373a30[];
extern u32 D_0035f04c;

// 00272340
void func_00272340(void);  // 0x00272340: definition moved into src/anon/unit_00271e08.cpp

s32 func_00103570(void);
u8* func_001063c0(s32, s32);
void func_00239700(u8*);
extern u8* D_0035f608;
extern u8* D_0035f60c;
extern u8 D_00347e60[];
extern u8 D_00347e40[];

// 002a8948: allocate the work buffers (ten 436-byte objects)
void func_002a8948(void);  // 0x002a8948: definition moved into src/anon/unit_002a8748.cpp

f32 __kernel_cosf(f32, f32);  // float_to_int_b
f32 func_002fb460(f32, f32, s32);  // float_to_int
s32 __ieee754_rem_pio2f(f32, f32*);
union FloatWord { f32 f; s32 i; };

// 002f87c0: cosf (fdlibm, without the inf/nan check)
f32 cosf(f32 x);  // 0x002f87c0: definition moved into src/newlib/libm/sf_cos.c

}

extern "C" {
extern void* D_0034a434;
extern void* D_0034a430;
extern void* D_0034a42c;
extern void* D_0034a428;
}
#define RELEASE_GLOBAL(g) if (g) { (*(VFn*)(*(u8**)g + 16))(g); g = 0; }
// 0014f428: release four global objects
void func_0014f428(void*);  // 0x0014f428: definition moved into src/anon/unit_0014ecb8.cpp

// 00281c50: Tz CmItem LeavePopup
extern "C" {
s32 func_00139d78(void*);
extern u32 D_0035f274;
extern u8 D_0035f299;
extern void* D_0035f28c;
extern void* D_0035f290;
extern s16 D_0035f280;
extern u32 D_0035f294;
extern u8 D_0035f298;
void cmItemLeavePopup(void) asm("_ZN2Tz6CmItem10LeavePopupEv");
}
void cmItemLeavePopup(void);  // 0x00281c50: definition moved into src/anon/unit_0027f2b0.cpp

extern "C" {

// Word accessed through a union: aliases everything, as the original assumes.
union Word { f32 f; u32 u; };
// Global accessed through a union with a byte member: not assumed distinct
// from struct fields.
union GWord { s32 v; u8 c; };
typedef void (*VFn2)(void*, void*);

extern u8 D_00361e38[];
extern u8* D_00361e28;
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8* D_00347f80;
void func_002c1750(u8*);
void func_00239870(u8*);
void func_0023c098(u8*);  // set_vtbl_36eae8_then_call
void func_002369f0(u8*);  // set_vtbl_36eac8_then_call


void func_002ca320(u8* o);  // 0x2ca320: moved to src/anon/unit_002ca0e0.cpp


u32* func_002859a0(void);
u8* func_001a8110(u8*);
s32 func_00286058(u8);
s32 func_001a3570(u16);
extern u32* D_0035f2e4;

}
// 00285fa0
void u_call0_00285fa0(void);  // 0x00285fa0: definition moved into src/anon/unit_002853b8.cpp
extern "C" {

struct BitInfo { u32 a, b; s32 n; };
u32* func_002a9d68(void);
void func_00294020(u32*);
BitInfo* func_00294000(s32);
union PtrWord { u32* p; u32 u; };
extern PtrWord D_0035f610;

// 002a9df0: clear the bits that are also set in the other set
void func_002a9df0(void);  // 0x002a9df0: definition moved into src/anon/unit_002a99c8.cpp

extern u32* D_0035f620;
extern GWord D_0035f628;
extern GWord D_0035f62c;

// 002ad110: count set bits
void func_002ad110(void);  // 0x002ad110: definition moved into src/anon/unit_002a99c8.cpp

extern u8 D_0034ab80[];

// 0031da48: destructor (seven 344-byte members with virtual destructors)
void func_0031da48(u8* o);  // 0x0031da48: definition moved into src/anon/unit_0031b9e0.cpp

extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
void func_00105110(u8*);

// 0031f590: destructor (four 344-byte members with virtual destructors)
void func_0031f590(u8* o);  // 0x0031f590: definition moved into src/anon/unit_0031f2f8.cpp

void func_002d0718(void*);
void func_0011b6a8(Mtx*);
void func_0011b720(Mtx*, f32);
void func_001449a8(void*, Mtx*);
s32 func_002cec08(void*, void*);

// 002cee58
s32 func_002cee58(void* a, u8* o);  // 002cee58: moved to src/taito/minigame_base.cpp (linked unit)

Vec4 func_0016af58(u8*);
Vec4 func_002cba88(u32, s32, const Vec4&, f32, f32);
extern Vec4 D_01e2be20;

// 002e3540
// 002e3540: moved to src/anon/unit_002e2f08.cpp

s32 func_00253918(void);
s32 func_002537c8(s32);
void func_00236c38(u32);
void func_00236a58(u32, s32, s32);
void func_002805d0(void);
struct State280 { s32 v; s8 pad[2]; s8 b6; s8 b7; };
union StatePtr { State280* p; u8 c; };
extern StatePtr D_0035f260;
extern u32 D_0035f264;

// 00280528
void func_00280528(void);  // 0x00280528: definition moved into src/anon/unit_0027f2b0.cpp

void func_0010b978(void*);
void func_001e02a0(u8*, u8*);
void func_0010c7f0(void*);
extern u8 D_00351e18[];
extern u8* D_01d49960[2];

// 001c7f10: constructor; registers itself in a two-slot table
// 0x1c7f10: moved to src/yasui/libys/summon.cpp

void func_002cfeb0(u8*, void*, s32, s32);  // obj_init_field1416_bit800
extern u8 D_00362b68[];

// 002dd9e0: constructor
void func_002dd9e0(u8* o, Word* p, s32 c);  // 0x002dd9e0: definition moved into src/anon/unit_002dd650.cpp

extern s32 D_01e2bfb0;
extern u8 D_01e2bfc0[];
extern void* D_0034e948;
s32 func_0019ba60(void*);
void* func_0016bba8(void*, s32, void*);
void func_0018a818(u8*, void*, void*);

// 002e9248: collect the list entries into 32-byte records
// 002e9248: moved to src/sugi/flare.cpp

Vec4 func_0017c030(u8*, s32*, u8);

// 001c96c8
void func_001c96c8(void* a, u8* o, u8 f);  // 0x001c96c8: definition moved into src/anon/unit_001c91c8.cpp

s32 func_002282f0(s16);
void func_0014a768(u8);
void func_0014a788(u16, u16);
f32 func_00227c78(u8*);
void func_0014a7b8(s16, f32);
void func_0014a7e8(s32);
void func_0014a7f8(s32);

// 0022cd48
void func_0022cd48(u8* o);  // 0022cd48: moved to src/sasa/event_layout.cpp (linked unit)

}
