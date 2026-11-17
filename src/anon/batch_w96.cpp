#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {
u32 func_001524e8(u32, u32);
void func_00152498(u32, u32);
u32 func_0013e678(void);
u32 func_0013a7e8(u32);
void func_001386e0(u32, u32, u32, u32, u32, u32);
void func_001396b0(u32);
void func_0031a260(u32, u32);
void func_00138c40(u32, u32, u32);
void func_00239988(u32, u32, u32);
void func_00239bf8(u32, u32);
void func_00152120(u32);
u32 func_0023aa78(u32);
void func_0014fc40(u32, u32, u32, u32, u32, u32);
void func_00139598(u32);
s32 func_00155758(u32, s32*, s32*, s32*, s32*, f32*);
s32 func_00139d78(u8*);
void func_0013edd0(u32, f32);
void func_0014b1e0(u32, s16, s16);
void func_0014b208(u32, u32, u32);
void func_001395a8(u32);
void func_00138d30(u32, f32);
s32 func_0015b4f8(void*, u32, s32*);
s32 func_0023aa98(u32);
extern u8 D_0034ab50[];
void func_0014b7f0(u32);
void func_0014c050(u32);
void func_0014b610(u32, u64);
void func_0014b608(u32, u64);
void func_0014b5e0(u32, u32);
void func_0014b630(u32, u32);
void func_0014b618(u32, u32);
void func_0014b5e8(u32, u64, u64);
void func_0014b468(u32, u32, u32);
void func_0014b628(u32, u64);
void func_0014b220(u32, u32, u32, u32, u32);
extern u8 D_0034c6e0[];
extern u8 D_0034c6c8[];
extern u8 D_004f3820[];
u8* func_00186078(u8*);
s32 func_0019ba60(u8*);
Q16* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00182980(void*, Q16*);
extern u8* D_0034ed04;
extern s32 D_0034ed00;
struct Ent12_w96 { u32 w[3]; };
extern Ent12_w96 D_01c60588[];
struct Vq_w96 {
    f32 x, y, z, w;
    Vq_w96& operator=(const Vq_w96& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq_w96 vsubn_w96(const Vq_w96& a, const Vq_w96& b) {
    Vq_w96 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen_w96(const Vq_w96& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
u8* func_00177860(void);
f32 fabsf(f32);  // fabsf
void func_002fee78(char*, const char*, ...);
u32 func_00170b30(u32);  // alloc_align128
void func_00168328(char*, u32);
u8* func_00168b38(u32, u32, u32);  // entry_array_find_nth
void func_001aad28(u32, u32, u32, u32, u32, u32);
void func_00170c00(u32);
extern const char* D_00350a2c;
extern u32 D_0033caf4;
void func_001ac378(u32, u32, u32, u32, u32, u32, u32);
void func_002395b8(u32);
void func_001abd90(u32);
void func_001ac028(u32);
void func_00239700(u32);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_001aa668(u32, u32);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
struct Rgb_w96 { u8 c[3]; };
extern Rgb_w96 D_00350a38[];
struct Ent_w96 { u16 id; u8 kind; u8 pad[5]; };
struct EntTbl_w96 { u32 hdr; s32 count; Ent_w96 ents[1]; };
extern EntTbl_w96* D_01d49560;
s32 func_001c3850(Ent_w96*);
union FU_w96 { f32 f; u32 u; };
struct Item36_w96 { u8 pad[8]; u8 name[8]; s8 sel; u8 pad17; u16 icon; u8 pad20[16]; };
extern Item36_w96 D_003719e8[];
extern u32 D_0035ecec;
extern u32 D_0035ecf0;
extern u32 D_0035ed08;
void func_00288d80(u32, s32, u32, u32, u32, u32, Item36_w96*, u8*);
u8* func_002891b8(u32, s32);
void func_00288e08(u32, s32, s32, u32);
u32 func_0028dd90(s32);  // mod10_classify_012
u32 func_0028ddd8(s32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, u32, u32, u32);
void func_002b4388(u32, Item36_w96*, u32);
typedef u8* (*AllocFn_w96)(void*, u32, u32);
extern u8* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_00347e60[];
void func_002361a0(u8*);
void func_0023f800(u32);
extern char D_01e21ef8[];
extern char D_003743f8[];
void func_0023fa90(u32, char*);
u32 func_0023f988(u32, u32);
void func_00138650(u8*, u32, u32, u32);
static inline u8* heap_alloc_w96(u32 size) {
    void* h = *(void**)(D_00347f80 + 20);
    return (**(AllocFn_w96**)h)(h, size, 0);
}
void func_0028e710(u8*, u32);
void func_0028ebf0(u8*, u32);
void func_0028e748(u8*, s32, u32);
struct Ch_w96 {
    u8 pad[344];
    s32 a;
    s32 b;
    u8 c;
    u8 pad2[3];
    f32 d;
    s32 e;
    s32 f;
    f32 g;
    f32 h;
    u8 pad3[4];
};
union ChU_w96 { Ch_w96* p; u32 u; u16 h; };
extern u8* D_0035f5e8;
s32 func_00103b38(void);
u32 func_00103570(void);
u32 func_00106178(u32, u32);
s32 func_00293fb0(void);
void func_00293e00(u32);
void func_00293fc0(void);
u8* func_001063c0(u32, u32);
void func_00319a60(u8*);  // clear_fixed_blocks
u8* func_001063f0(u32, u32);
extern u32 D_0035f628;
extern u32 D_0035f62c;
extern u8 D_0035f614;
extern u32 D_0035f618;
extern u32 D_0035f61c;
extern u8* D_0035f620;
extern u8* D_0035f624;
struct Pair_w96 { u32 a; u32 b; };
u8* func_002a9d68(void);
u32* func_002b23e0(s32);  // list_entry_by_index_checked
s32 func_002b3ac8(u32);
void func_002b2f28(u32);
union EU_w96 { u32 u; u16 h; };
static inline __attribute__((always_inline)) void setbit_w96(u16* bits, u32 n) { u16* p = &bits[n >> 4]; *p |= 1 << (n & 15); }
void func_002b6adc(u32, u32);
struct QEnt_w96 { u32 id; f32 len; };
struct SeqQ_w96 { s32 tail; s32 head; QEnt_w96 q[4]; };
struct Seq_w96 {
    u32 busy : 1;
    u32 rest : 31;
    u32 user;
    u8* src;
    u32 target;
    f32 t;
    f32 len;
    SeqQ_w96 queue;
};
typedef f32 (*LenFn_w96)(u8*);
void func_002ef180(Seq_w96*, f32, f32);
void func_002eef08(Seq_w96*, u32, f32);
void func_00189f20(u32, void (*)(void), u32, f32);
void func_002ef148(void);
struct Bigint_w96 { Bigint_w96* next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
Bigint_w96* _Balloc(void*, s32);
void _Bfree(void*, Bigint_w96*);  // push_entry_onto_slot_list

// Builds the widget: icons, 7 child panels, then hands off to the shared init.
void wtarget_001521c8(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_001521c8jjjj");
void wtarget_001521c8(u32 self, u32 id, u32, u32);  // 0x001521c8: definition moved into src/anon/unit_0014ecb8.cpp

// 001558b8: moved to src/anon/unit_00153ea0.cpp
void func_001558b8(u32 self, u32 a1, s32 idx);

// Sets up a row of up to 8 child panels and centres them horizontally.
void func_0015b368(u32 self, u32 a1, u32 a2, u32 a3);  // 0x0015b368: definition moved into src/anon/unit_0015b100.cpp

// Constructor: vtable + two sprite members, then their draw state.
// 0015e4e0: moved to src/anon/unit_0015e070.cpp

// Constructor: vtable + one sprite member; also sets up a shared global sprite.
// 0015e9e0: moved to src/anon/unit_0015e070.cpp

// 00182c60: moved to src/anon/unit_00182780.cpp

// Is point p within (radius r, height h) of actor o?
// 001a4ff8: moved to src/anon/unit_001a4db0.cpp

// Loads a texture archive by name and uploads its images to VRAM.
void func_001aabd8(void);  // 0x001aabd8: definition moved into src/anon/unit_001aaa08.cpp

// Constructor: base init, vtables, four child panels, colour from a kind table.
// 001ac970: moved to src/anon/unit_001abb28.cpp

// Finds the next entry of the given kind (after prev) that passes func_001c3850.
Ent_w96* func_001c3748(u32 kind, Ent_w96* e);  // 0x001c3748: definition moved into src/anon/unit_001c2b58.cpp

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.
void func_001dd568(u32* ids, FU_w96* keys, s32 lo, s32 hi);  // 0x001dd568: definition moved into src/anon/unit_001dd2b8.cpp

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.

// Builds the two-entry choice list and focuses the preselected entry.
void func_00243cd8(void);  // 0x00243cd8: definition moved into src/anon/unit_00242478.cpp

void func_002874b0(u8* self);  // 0x002874b0: definition moved into src/anon/unit_00286d28.cpp

// Resets the channel table: n channels back to defaults.
void func_0028e190(u8* self, s32 n);  // 0028e190: moved to src/anon/unit_0028c878.cpp

// Returns nonzero if any of the screen's widgets is still busy.
s32 func_002a40c8(void);  // 0x002a40c8: definition moved into src/anon/unit_002a40c8.cpp

void func_002acda8(void);  // 0x002acda8: definition moved into src/anon/unit_002a99c8.cpp

s32 func_002b3318(void);  // 0x002b3318: definition moved into src/anon/unit_002b2a18.cpp

void func_002baa78(void);  // 0x002baa78: definition moved into src/anon/unit_002b9ab8.cpp

// Advances a queued sequence by dt, pulling the next queued entry when the current one ends.
// 002ef028: moved to src/anon/unit_002ee8a8.cpp

// newlib mprec __lshift: b << k as a new Bigint (frees b).
Bigint_w96* __lshift(void* ptr, Bigint_w96* b, s32 k);  // 0x00304308: definition moved into src/newlib/libc/mprec.c

}
