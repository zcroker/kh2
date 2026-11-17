#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {
void* func_00170b30(u32);  // alloc_align128
void* func_00106178(void*, u32);
void func_001091c8(void*, u32, u32);
extern void* D_0032bb1c;

// Allocates a heap of `size` bytes and installs it.
// 00105370: moved to src/common/area.cpp

f32 func_001142e0(u8* p, s32 i, u8 a, u8 b);  // 0x001142e0: definition moved into src/anon/unit_001142a0.cpp

extern u32 D_00348804;
u8 func_001652c8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_00143470(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);  // 0x00143470: definition moved into src/anon/unit_00142c90.cpp

extern u8 D_00349f00[];
void* func_0014e648(void*);  // ptr_add752
void func_0014dd60(void*, u8, u8, u8);  // store_3bytes_470
// 0014e140: moved to src/anon/unit_0014d680.cpp

extern Q16 D_0034aa50[2];
Q16* func_0016c028(u32);  // obj_get_attach_or_alt
// 00159ef8: moved to src/harata/libdk/targetcamera.cpp

// Scales the base colour at +420 by (r, g, b)/128 into +680.
// 00160488: moved to src/harata/libdk/bgobj.cpp

// Plane test: d = dot(a.xyz, b.xyz) + b.w -> *out; 1 when 0 <= d <= a[4].
s32 func_00162b18(f32* a, f32* b, f32* out);  // 0x00162b18: definition moved into src/anon/unit_001614e8.cpp

void func_0017d050(void*, u32);
extern u8 D_004f62a0[];
// 0016dad8: moved to src/anon/unit_0016d2e0.cpp

u32 func_00180378(u32, u32, u32, f32);
void func_00172440(u8* p);  // 0x00172440: definition moved into src/anon/unit_00171e58.cpp

s32 func_00181500(s32);
// 001819c0: moved to src/yasui/libys/progress.cpp

void func_0016af58(void*, u32);
// 001860b0: moved to src/anon/unit_00185d10.cpp
s32 func_001860b0(u32 a, f32* b);

// Puts an ability (15-bit id + enabled bit) into the first free slot of the 80-entry list.
struct AbilitySlot { u16 id : 15; u16 on : 1; };
void partram_add_ability(u8* self, s32 id, u8 on) asm("_ZN2YS7PARTRAM11add_abilityEib");
void partram_add_ability(u8* self, s32 id, u8 on);  // 0x00188b68: definition moved into src/anon/unit_00188848.cpp

struct S24 { u32 w[6]; };
void func_00192868(u32, u32, S24);
// 00192940: moved to src/yasui/libys/message.cpp

struct E56 { u32 a, b; u16* p; u8 pad[44]; };
extern s32 D_00350440;
extern E56 D_01c62198[];
u32 ctarget_0019b260(u32 id, u32, u32, u32) asm("_Z16ctarget_0019b260jjjj");
u32 ctarget_0019b260(u32 id, u32, u32, u32);  // 0x0019b260: definition moved into src/anon/unit_00199688.cpp

// Adds n to a counter capped at 100, and to two halfword totals.
void func_001a2668(u8* p, s32 n);  // 0x001a2668: definition moved into src/anon/unit_0019fb70.cpp

s32 func_001a8f10(s32 x);  // 0x001a8f10: definition moved into src/anon/unit_001a8618.cpp

void func_001ac378(void*, u32, u32, u32, u32, u32, u32);
void func_001aa668(void*, void*);
extern u8 D_00350bf0[];
// 001ac8b0: moved to src/anon/unit_001abb28.cpp

u32 func_001b1400(void*);
void func_00168328(void*, u32);
// 001b1490: moved to src/yasui/libys/databuff.cpp

void func_001bc720(u8*);
void func_001bc730(u8* p, s32 i);  // 0x001bc730: definition moved into src/anon/unit_001bc568.cpp

// Pops the stack pointer at +2240 (clearing the top slot).
void func_002ba2e8(u32, u32);
void func_001bd618(u8* p, u8 flag);  // 0x001bd618: definition moved into src/anon/unit_001bc568.cpp

void func_00177dc8(void*, u32, u32, u32, u32);
void func_001d56f0(void*);  // zero_three_words
extern u8 D_003521e0[];
void func_001ced68(u8* p, u32 a1, u32 a2, u32 a3);  // 0x001ced68: definition moved into src/anon/unit_001ce6e8.cpp

void func_001d2110(void*, s32);
void func_001d2248(void*, s32);
void func_001d2130(u8* p, s32 n, f32 f);  // 0x001d2130: definition moved into src/anon/unit_001d14e0.cpp

// "Assertion failed: %s\n" / "   File %s, Line %u\n" then break.
extern char D_0036e978[];
extern char D_0036e9c0[];
extern char D_0036e9d0[];
extern char D_0036e998[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
static inline void assert_fail_1e2c00(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
u8 func_001e7cc0(void*);
u8 func_001e2c00(void* pMng);  // 0x001e2c00: definition moved into src/anon/unit_001e0cb8.cpp

u8 func_00209178(void*, void*);
void func_002092e0(u8* a, u32* b, u8* c);  // 0x002092e0: definition moved into src/anon/unit_002090c0.cpp

extern u32 D_0035dae4;
u32 func_00227818(u32);
u32 func_00225eb8(u32, u32, u32);
u32 func_00227858(u32, u32, u32);
u32 func_00225640(u32 a, u32 b, u32 c);  // 0x00225640: definition moved into src/anon/unit_00224780.cpp

extern char D_01dad938[];
extern char D_00371138[];
extern u32 D_0033caf4;
void func_002fee78(char*, const char*, ...);
void strlen(char*);  // strlen
char* func_0022b7f0(void);  // 0022b7f0: moved to src/sasa/musical_2d.cpp (linked unit)

// Appends a type-9 record to the 64-entry ring buffer; returns its serial.
struct REnt { u32 type, id, a, b, c, d; u32 pad[2]; };
extern s32 D_0035e360;
extern u32 D_0035e368;
extern REnt D_01dadc00[];
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002343a8jjjj");
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d);  // 0x002343a8: definition moved into src/anon/unit_002335e8.cpp

extern u8* D_0035ec90;
void func_00242408(void);  // set_global_crc_m1
void func_00242418(void*, u32);  // crc_byte_update
void func_002409b8(u8* p);  // 0x002409b8: definition moved into src/anon/unit_0023f5b8.cpp

struct BF242 { u32 lo : 8; u32 f : 1; u32 hi : 23; };
struct X242 { u32 a; BF242 b; };
u8* func_001058e8(void);
void func_00242d80(u8 f);  // 0x00242d80: definition moved into src/anon/unit_00242478.cpp

extern char D_01e2bba0[];
extern char D_00374fa8[];
char* func_002bd260(u32 a);  // 0x002bd260: definition moved into src/anon/unit_002bc978.cpp

extern u8 D_00361980[];
extern u8 D_003637e0[];
typedef void (*VFn)(void*);
void func_002bee58(u8* p);  // 0x002bee58: definition moved into src/anon/unit_002bebd0.cpp

void func_00143e50(void*, u16, u32);
void func_00186a90(void*, void*, f32);
void func_002c5ff8(u8* p, u32 a);  // 0x002c5ff8: definition moved into src/anon/unit_002c53c8.cpp

extern u8 D_003629e8[];
void func_002e4a90(void*);  // in_even_range
void func_002cea28(void*);
void func_00105110(void*);
void func_002dc788(u8* p);  // 0x002dc788: definition moved into src/anon/unit_002da040.cpp

void func_00108398(void*);  // clear_quads_set_flags
void func_002e5f70(u8* p) {
    func_00108398(p + 16);  // clear_quads_set_flags
    func_00108398(p + 288);  // clear_quads_set_flags
    *(u32*)(p + 544) = 0;
    *(u32*)(p + 548) = 0;
    *(u32*)(p + 552) = 0;
    *(u32*)(p + 556) = 0;
    *(u64*)(p + 560) = 0;
}

void func_001c1748(void*, u32, u32, u32);  // obj_init_from_src
void func_00190128(void*);
void func_002ed558(u8* p, u8* q, u32 a2, u32 a3, u32 a4);  // 0x002ed558: definition moved into src/anon/unit_002ecdb0.cpp

void func_00103bb0(u32);
void func_00103590(u32, void*);
extern void* D_003638c4;
extern u8 D_003638c0;
extern u8 D_003638c8;
// 002ef6b0: moved to src/anon/unit_002ef6b0.cpp

extern u32 D_00363c20;
extern u32 D_00363c24;
extern u32 D_01e2c0d0;
u32 func_001708f8(u32, s32);
u8* func_00168b38(u32, u32, u32);  // entry_array_find_nth
void func_002f1808(void) {
    u32 v = func_001708f8(D_00363c20, -1);
    D_01e2c0d0 = v;
    D_00363c24 = *(u32*)(func_00168b38(v, 2, 0) + 8);  // entry_array_find_nth
}

extern u8 D_0034a800[];
extern u8 D_00347e60[];
extern void* D_00347f98[];
void func_002361d0(void*);
void func_00239870(void*);
void func_0031cec0(u8* p) {
    *(void**)p = D_0034a800;
    func_002361d0(p + 416);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(void***)p = D_00347f98;
}

extern void*** D_00347f80;
typedef void (*VFn2)(void*, void*);
void func_00322e18(u8* p) {
    *(void***)p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    ((VFn2)((void**)*o)[1])(o, p);
}

extern u8 D_00363880[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
void func_00325aa0(u8* p) {
    *(void**)p = D_00363880;
    func_0023c098(p + 64);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 40);  // set_vtbl_36eac8_then_call
    *(void**)p = D_003637e0;
}
}

// Sets bit `i` in the bitset returned by func_002859a0 (if not already set).
extern "C" u32* func_002859a0(void);
void func_00285f50(void* a);  // 0x00285f50: definition moved into src/anon/unit_002853b8.cpp
