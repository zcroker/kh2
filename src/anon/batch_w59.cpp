#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// Same layout, but copy-constructible (used for by-value returns).
struct Vec4c {
    f32 x, y, z, w;
    Vec4c() {}
    Vec4c(const Vec4c& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));

extern "C" {

void* create_task(void* self, int a, int b, void* fn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void setHideGroup(u32 g) asm("_ZN2dk3Map12setHideGroupEj");
void wtarget_00180d40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00180d40jjjj");
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002eda40jjjj");

// 00101ce0: __do_global_ctors_aux, now in src/libgcc/crtend.c

// --- 00102788
// Allocate a 72-byte task through the manager's allocator (tagged with the
// caller's return address), construct it and link it in.
void func_001022c0(void*, void*, int, int, void*);
void func_00102528(void*, void*);
// 00102788: TASK_MANAGER::create_task, moved to src/global/unit_001022c0.cpp

// --- 00109140
void func_00133de8(void);
void func_00109330(void);  // set_global_3756_return
void func_00109340(void);  // to_109450_zero
void func_0010a7d8(int, int, int);  // store_triple_bytes
void func_0010a828(f32, f32);
void func_0010a8a8(f32, f32);  // store_global_float_pair
extern u64 D_003a8e10;
extern u8 D_00340eb0;
void func_00109140(void);  // 00109140: moved to src/anon/unit_001085a8.cpp

// --- 0010cce0
// Advance the object iterator until an object passing the check is found.
void* func_001b9bc8p(void*) asm("YS__OBJ__Each");
bool func_00112d28(void*);
void* func_0010cce0(void* p);  // 0x0010cce0: definition moved into src/anon/unit_0010b978.cpp

// --- 0013e2d8
u32 func_0013a7e8(u32);
void dk__Sprite__create(u8*, u32, u32, u32, u32, u32);
void func_00139598(u8*);
void func_00139708(u8*);
void dk__LockOn__start(u8* p, u32 a, u32 b);  // 0x0013e2d8: definition moved into src/anon/unit_0013dfb8.cpp

// --- 00141850
// Clear every entry's flag, then apply each bit set in the 64-bit mask.
void func_00141928(u8*, u8);  // mark_records_by_index
struct E141 { u8 pad[16]; u8 f; u8 p2[3]; };
void func_00141850(u8* p, u64 mask);  // 0x00141850: definition moved into src/anon/unit_00141458.cpp

// --- 0014ed28
u32 func_0014ecf8(u32);
u32 func_00136958(void);
u32 func_002bc2e8(u32, u32, u32);
extern s32 D_0034a400;
extern u32 D_0034a408[];
void func_0014ed28(u32 a, u32 b);  // 0x0014ed28: definition moved into src/anon/unit_0014ecb8.cpp

// --- 00152508
u32 func_0013d7e0(void);
void func_00138d60(u8*, u32, u32, u32, u32, u32, u32);
void func_0023aa78(u8*);
void func_00152508(u8* p, u32 a, u32 b, u32 c, u32 d);  // 0x00152508: definition moved into src/anon/unit_0014ecb8.cpp

// --- 00157160
u8* func_0017df58(u32);
void func_001574a0(u32);
void func_001024a8(u8*);
// 00157160: moved to src/anon/unit_00153ea0.cpp
void func_00157160(u8* p);

// --- 0015ee10
// Clear the group's bit in the hidden-group mask and refresh.
void func_00143060(void);
void func_001538d8(u8);
void func_0015c4a0(u32);
void func_001de3d8(void*, u32);
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
// 0015ee10: moved to src/harata/libdk/map.cpp

// --- 00167cd0
u32 func_00167c90(u8*, void*);
extern u8 D_0036b628[];
extern void* D_0034d7ac;
// 00167cd0: moved to src/anon/unit_00167358.cpp

// --- 0016d3c8
// p[0] = &(static vector = *p[0] - *p[1]); the static's guard/atexit is open-coded.
extern s8 D_004f62d0;
extern Vec4 D_004f62e0;
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_0016e880(void);
// 0016d3c8: moved to src/anon/unit_0016d2e0.cpp

// --- 00173f68
f32 func_00184a90(u32);
f32* YS__OBJ__get_pos(u32);  // obj_get_attach_or_alt
void YS__trap_obj_float_height(u8* p);  // 0x00173f68: definition moved into src/anon/unit_00171e58.cpp

// --- 00176b58
u32 func_00176b20(s32);
s32 func_0016a070(u32);
u32 func_001d14a0(void);
// 00176b58: moved to src/yasui/libys/party.cpp

// --- 00180d40
// Add b to the 16-slot table unless present (stored in the last free slot).
struct T180 { u8 pad[332]; s32 t[16]; };
// 00180d40: moved to src/anon/unit_00180408.cpp

// --- 00188ac8
s32 func_001a3570(u16);
void func_001a34e0(u16, u32);
struct S188 { u8 pad[18]; bool n; };
void func_00188ac8(S188* p);  // 0x00188ac8: definition moved into src/anon/unit_00188848.cpp

// --- 00190388
struct Buf190 { u32 a, b, c, d; Vec4c v; };
void YS__TARGET__make_collision(u32, Buf190*);
Vec4c func_00190388(u32 a);  // 0x00190388: definition moved into src/anon/unit_001900d0.cpp

// --- 001b55e8
u32 YS__OBJENTRY__GetCacheBuffStatus(u32, u32);
u32 func_001d1ca8(u8*);
u32 YS__MISSION_GAUGE__is_open(u8*);
u32 func_001c9df8(void);
u32 YS__LIMIT__can_end(u8* p);  // 0x001b55e8: definition moved into src/anon/unit_001b2780.cpp

// --- 001b9ee8
extern u8* D_01d48da0;
static inline u8* Next1b9(u8* o) {
    if (!o) return D_01d48da0;
    return *(u8**)(o + 2228);
}
void func_001b9ee8(s32 lim);  // 0x001b9ee8: definition moved into src/anon/unit_001b9880.cpp

// --- 001bdcd0
u32 func_001819c0(u32);
u32 func_001bd590(u32);
u32 func_001bdcd0(u32 a);  // 0x001bdcd0: definition moved into src/anon/unit_001bc568.cpp

// --- 001cffe0
void func_001780d8(u8*);
void func_00198860(u8*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_0017f5e0(u8*, u32, u32, f32, f32);
void YS__STDOBJ__start_camera(u8*, void*, u8*);
extern u8 D_0036e368[];
void func_001cffe0(u8* p);  // 0x001cffe0: definition moved into src/anon/unit_001cf0b0.cpp

// --- 001d5068
// bsearch the 2-byte-entry table for key, then use the entry's id.
extern u8* D_01d5ba68;
extern u8 D_00321790[];
extern u32 D_00352768;
u8* func_002fd248(u32, u8*, u32, u32, void*);
u8* func_00168b38(u32, u32, u8);  // entry_array_find_nth
void YI__VIBRATION__Create(u32);
void func_001d5068(u32 key);  // 0x001d5068: definition moved into src/anon/unit_001d4f40.cpp

// --- 001d6d00
// 1-based index of the entry with the given id, 0 if none.
struct Ent1d6 { u8 d[64]; };
struct Tbl1d6 { u8 hdr[8]; Ent1d6 e[1]; };
extern Tbl1d6* D_01d5ba98;
u16* func_001d6cc8(u16*);
s32 func_001d6d00(u32 id);  // 0x001d6d00: definition moved into src/anon/unit_001d68e0.cpp

// --- 001d8ad8
u8* func_001bbcb0(void);
u32 func_001bb4a0(void);
void YS__MISSION__WarningCount(s32 idx, u8 flag);  // 0x001d8ad8: definition moved into src/anon/unit_001d7458.cpp

// --- 001da458
struct P1da { u32 a; u32 b; u32 cur; };
void func_001da3d8(P1da*, u32*);  // stream_append_unaligned
void func_001da458(P1da* p, u32 a, u32* arr, s32 n);  // 0x001da458: definition moved into src/anon/unit_001d9d00.cpp

// --- 001e0de8
Vec4* func_001e0cc8(Vec4*);  // entry64_by_field32
Vec4* func_001e0ce8(Vec4*);  // entry64_by_field32_b
void func_001e0de8(Vec4* p);  // 0x001e0de8: definition moved into src/anon/unit_001e0cb8.cpp

// --- 001ea458
extern u8* D_01d9e6e0;
u8* func_001e7a98(u8*, u8*);
void func_001ea458(u32 a, u8* b, u16 c);  // 0x001ea458: definition moved into src/anon/unit_001e8ac8.cpp

// --- 0022b898
u32 func_0022b7f0(void);
void func_0023fa90(u8*, u32);
u32 func_0023f908(u8*, u32);
u32 func_0023f948(u8*, u32);
u32 func_001050c8(void);
void func_00236a58(u8*, u32, u32);
void func_0023c100(u8*, u32, u8*, u32);
extern u8* D_0035e2e8;
void func_0022b898(void);  // 0022b898: moved to src/sasa/musical_2d.cpp (linked unit)

// --- 00263960
// Store the parameters, then allocate and construct the 460-byte object.
extern u32 D_0035f0b8;
extern u32 D_0035f0bc;
extern u32 D_0035f0c0;
extern u8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_0035f360[];
extern u32* volatile D_0035f0dc;
void func_00263bb0(u32, u32);
void func_00239700(u32*);
void Tz__CMenuHelp__Init(u32 a, u32 b, u32 c, u32 d, u32 e);  // 0x00263960: definition moved into src/anon/unit_002632d0.cpp

// --- 0027db58
u8* func_00167f18(u32);
u32 func_00287db0(void);
u32 func_00290740(u32);
void func_001039f8(void);
void func_00242618(u32, u32);
void func_00287da0(void);
extern u32 D_0035f238;
u32 func_0027db58(void);  // 0x0027db58: definition moved into src/anon/unit_0027d2e8.cpp

// --- 002a6718
u32 func_00276368(void);
u32 func_0028acc8(u32);
u32 func_00276888(void);
u32 func_00139d78(u8*);
extern u32 D_0035f200;
extern u8* D_0035f5f0;
void func_002a6718(void);  // 0x002a6718: definition moved into src/anon/unit_002a5a90.cpp

// --- 002bc608
extern u8* D_01e2aa80;
void func_002bbf68(u8*, u32);
static inline u8* Next2bc(u8* o) {
    if (!o) return D_01e2aa80;
    return *(u8**)(o + 28);
}
void func_002bc608(u32 key);  // 0x002bc608: definition moved into src/anon/unit_002bb8b0.cpp

// --- 002c1aa0
// Constructor: base init, then vtable and flags.
void func_002be770(u8*);
extern u8 D_00361b20[];
void func_002c1aa0(u8* p);  // 0x002c1aa0: definition moved into src/anon/unit_002c10e0.cpp

// --- 002eda40
// Count the timer down by one; fire event 151 when it runs out.
extern f32 D_00349e10;
void func_001991a8(u32, u32);
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d);  // 0x002eda40: definition moved into src/anon/unit_002ecdb0.cpp

// --- 002edca0
u32 YS__OBJ__Each(u32);
u32 func_001c0cd8(u32);
void func_001c1020(u32, u32);
void func_002edca0(u32 key, u32 arg);  // 0x002edca0: definition moved into src/anon/unit_002ecdb0.cpp

// --- 002f4888
// Hand-written VU0 routine: compares the point's x/y against (0,0) and
// (4096,4096) and returns the x/y sign bits of the MAC flags.
u32 func_002f4888(void* p);  // 0x002f4888: definition moved into src/sdk/libvu0_002f4840.s

// --- 00313bc0
// libgcc fp-bit: float -> unsigned int.
struct FpNum { u32 cls; s32 sign; s32 exp; u32 frac; };
void func_00314640(f32*, FpNum*);
static inline int fp_iszero(FpNum* x) { return x->cls == 2; }
static inline int fp_isnan(FpNum* x) { return x->cls < 2; }
static inline int fp_isinf(FpNum* x) { return x->cls == 4; }
u32 __fixunssfsi(f32 f);  // 0x00313bc0: definition moved into src/libgcc/_sf_to_usi.c

// --- 0031c7a8
// Destructor: destroy the 7-element member array (344-byte elements, virtual
// dtor) back to front, then the base subobjects.
extern u8 D_0034a660[];
extern u8 D_00347f98[];
void func_00239870(u8*);
void func_0031c7a8(u8* p);  // 0x0031c7a8: definition moved into src/anon/unit_0031b9e0.cpp

}
