#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

u32 wtarget_001339d0(u32, u32, u32, u32, u32) asm("_Z16wtarget_001339d0jjjj");
u32 wtarget_00180828(u32, u32, u32, u32) asm("_Z16wtarget_00180828jjjj");
u32 wtarget_001d9980(u32, u32, u32, u32) asm("_Z16wtarget_001d9980jjjj");
void wtarget_002cb188(u32, u32, u32, u32) asm("_Z16wtarget_002cb188jjjj");
void wtarget_002e1878(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

extern "C" {

f32 func_001142e0(u32, u32, u32, u32);  // entry8_float_by_flags
s32 func_001917c0(void);

typedef s32 (*VFnI)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, u32);

// Scaled value: base minus half of a field, clamped to >= 1, doubled for state 3 in battle mode.
f32 func_00111808(u8* p);  // 0x00111808: definition moved into src/anon/unit_001117d8.cpp

// Copy matrix i of the table into m, then negate its Y and Z columns.
void func_0011d468(u8* p, s32 i, f32* m);  // 0x0011d468: definition moved into src/anon/unit_0011c128.cpp

// Cubic Hermite interpolation between (t0, p0, m0) and (t1, p1, m1).
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1);  // 0x001286d0: definition moved into src/anon/unit_00128480.cpp

struct Pkt { u16 h0; u8 b2; u8 b3; u32 w4; u32 w8; u32 w12; };
union PktCursor { Pkt* p; u32 u; u16 h; };

}

// Append one 16-byte packet at the cursor and advance it.
u32 wtarget_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0);  // 0x001339d0: definition moved into src/anon/unit_00131418.cpp

extern "C" {

f32 func_0013fd10(void*);
void func_0013f828(void*);
void func_0013f888(void*, void*, u32);
void func_0013f5f0(void*);  // copy_float_220_to_48
void func_0013f608(void*);
void func_0013f648(void*);

void func_0013f558(u8* p);  // 0x0013f558: definition moved into src/anon/unit_0013ef70.cpp

extern u32 D_00349394;
extern u8 D_0034939d;
extern u8 D_00349270[];
extern u32 D_00349390;
extern u32 D_00349398;
extern u8 D_0034939c;
void func_0014b208(void*, u32, u32);
void func_0013edd0(void*, f32);
void func_0014b248(void*, u32);
void func_0013ee38(void*, u32);

void func_0014a6e0(void);  // 0014a6e0: moved to src/anon/unit_00149fa8.cpp

u8* func_00168b38(void*, u32, s32);  // entry_array_find_nth
u32 func_001667d0(u16);  // ilog2
struct TexInfo { u32 w0; u16 h4; u16 h6; u16 h8; };

// Build a GS TEX0 register value.
u64 func_00166730(TexInfo* t);  // 0x00166730: definition moved into src/anon/unit_001664c0.cpp

struct Allocator;
struct AllocVt { void* (*alloc)(Allocator*, u32, void*); };
struct Allocator { AllocVt* vt; };
extern Allocator* D_0032b91c;
void func_00168958(void*, u32, u32);  // obj_init_name_string

// 001684c0: moved to src/yasui/libys/file.cpp

extern u32 D_0034d8a8;
u64 func_00312db8(u64, u64);

// Advance the LCG seed and scale it into [0, *p).
// 0016dd28: moved to src/anon/unit_0016d2e0.cpp

struct Pad10 {
    u8 a, b, c;
    u16 d, e, f;
    Pad10() { u16 m = 0xffff; a = m; b = m; c = m; d = m; e = m; f = m; }
};
Pad10 func_00199718(u32, s32);
void func_00104f58(Pad10*, u32, u32, u32, u32);
union U32x { u32 u; u16 h; u8 b; };

void func_00173008(U32x* p);  // 0x00173008: definition moved into src/anon/unit_00171e58.cpp

s32 func_0019ba60(u32);
u32 func_0016a070(void*);
s32 func_001afe70(u32, u32, u32, u32*);
void func_00198630(void*, s32, u32);

// 00176cd0: moved to src/yasui/libys/party.cpp

s32 func_0017ebc8(void*);
u32 func_001a97b8(u32, s32);
u32 func_00180408(void*, u32);
extern s32 D_0036c5b8[];
extern s32 D_0036c5cc[];

}

// 00180828: moved to src/anon/unit_00180408.cpp

extern "C" {

// 00183768: moved to src/anon/unit_00183088.cpp

u32 func_00185da8(u32);
void func_0016c568(u32, u32, f32);

// 00185e20: moved to src/anon/unit_00185d10.cpp
void func_00185e20(u32 a0);

void func_001ba028(u32);  // list_contains_ptr
u32 func_0018db38(u32, void*, u32, u32);
void func_0018ca10(u32);  // alloc_from_pool_magic

void func_0018fab0(u32* p);  // 0x0018fab0: definition moved into src/anon/unit_0018f140.cpp

struct Slot88 { s32 a; s32 b; u8 pad[80]; };
extern Slot88 D_01c61b48[16];
void func_00198dc0(Slot88*);

// 00198c28: moved to src/anon/unit_00198b88.cpp

u32 func_001b1490(u32);
extern u32 D_0035043c;
extern u32 D_01c62148[19];

static inline bool hasValue8(u8* r) { return r && *(u32*)(r + 8); }

void func_00199688(void);  // 0x00199688: definition moved into src/anon/unit_00199688.cpp

struct LNode { u8 pad[12]; LNode* next; };
extern LNode* D_01c6cb20;
void func_001a5d48(LNode*);
void func_00105110(void*);
struct Ent44 { u32 w0; u8 pad[40]; };
extern Ent44 D_0035080c[6];
void func_001de450(Ent44*);

// 001a5e38: moved to src/yasui/libys/magic.cpp

void func_001b3b70(void*, u32, u32, u32);
extern u8 D_00351078[];
extern void* D_00351068;

void func_001b3a90(u8* p, u32 a1, u32 a2);  // 0x001b3a90: definition moved into src/anon/unit_001b2780.cpp

s32 func_0018a550(void*, u32);  // state_dispatch_0_1_3

void* func_001b7998(s32* p, u32 a1);  // 0x001b7998: definition moved into src/anon/unit_001b6a50.cpp

s32 func_001bb4a0(u32);
u8* func_001bbcb0(void);
void func_001d4fa8(void*, u32);

// 001bbdb8: moved to src/yasui/libys/mission.cpp

struct LItem { u8 pad[12]; LItem* head; LItem* tail; u8 pad2[8]; LItem* owner; u32 pad3; LItem* next; };
struct LItemList { LItem* head; LItem* tail; };
struct NoTail { ~NoTail() {} };
void func_001db8b8(void*, LItem*);

// Unlink n from its owner's list.
// 001c1808: moved to src/anon/unit_001c0638.cpp
void func_001c1808(LItem* n);

void func_002beb28(void);
void func_00188c10(u32, u32);
u32 func_00188fe0(void*, u32);
extern u8 D_0032e020[];

void func_001d7380(s32 a0);  // 0x001d7380: definition moved into src/anon/unit_001d68e0.cpp

s32 func_00105868(void*);
s32 func_00276fd0(void);
extern u8 D_0032bb30[];

}

u32 wtarget_001d9980(u32, u32, u32, u32);  // 0x001d9980: definition moved into src/anon/unit_001d7458.cpp

extern "C" {

// VU0 random float (hand-written VU0 asm).
f32 func_0020b410(void);  // 0x0020b410: definition moved into src/anon/unit_0020ad28.cpp

// Transform v by matrix m, project, store to out; returns screen clip flags (hand-written VU0 asm).
u32 func_00222898(void* out, void* m, void* v);  // 0x00222898: definition moved into src/anon/unit_00222548.cpp

u32* func_00227a28(u32);
void func_002ff2e8(void*, u32);
u32 func_0022e188(u32);
u32 func_00227870(u32, void*, u32);
void func_00168388(u32, u32, void*, void*);
void func_0022e160(void);

void func_0022e1f8(u32 a0, u32 a1);  // 0x0022e1f8: definition moved into src/anon/unit_0022d358.cpp

u32 func_002282f0(u16);
u32* func_00227d10(s16);
u32 func_0016f000(u32, void*, f32);
void func_00233280(u32);

void func_00233410(u8* p);  // 0x00233410: definition moved into src/anon/unit_00232f08.cpp

void func_00239558(u8* p, u16* a, u16* b);  // 0x00239558: definition moved into src/anon/unit_002384f8.cpp

extern u8 D_0032bad8;
s32 func_00103b38(void);
u32 func_00103550(void);
s32 func_00103428(u32);
u8* func_00243150(u32);
void func_00103500(s16);
void func_00253538(s16);

void func_00243020(u32 a0);  // 0x00243020: definition moved into src/anon/unit_00242478.cpp

struct Ent36 { u8 pad[32]; s8 ids[4]; };
extern Ent36 D_00371d90[];
s32 func_001a6d08(s32);

s32 func_00249480(s32 idx);  // 0x00249480: definition moved into src/anon/unit_00247ff0.cpp

s32 func_002576d0(void);
s32 func_00139d78(void*);
extern u8* D_0035f0f4;

s32 func_0026d180(void);  // 0x0026d180: definition moved into src/anon/unit_0026c450.cpp

void func_00290060(void*);
void func_00138c10(void*, s32);
struct SprRef { u8* o; u32 pad[2]; s16 h12; };

void func_0028ff18(SprRef* p);  // 0028ff18: moved to src/anon/unit_0028f1e0.cpp

extern u16 D_00374aa8[];

// Is id in the zero-terminated list?
s32 func_0029ec98(u32 id);  // 0x0029ec98: definition moved into src/anon/unit_0029d008.cpp

extern u8* D_0035f610;
static inline u32 flagTest(u32 n) {
    u32* f = (u32*)(D_0035f610 + 316);
    return (f[n >> 5] & (1 << (n & 31))) != 0;
}

// Test flag n, or any of flags 0..12 when n < 0.
u32 func_002aa2f8(s32 n);  // 0x002aa2f8: definition moved into src/anon/unit_002a99c8.cpp

extern u8 D_01e2aa80[];
void func_00324718(void*, void*);
u32 func_002b79cc(u32, u32, u32);
u32 func_002b986c(u32, u32);
u32 func_002b7440(u32, u32, u32);

u32 func_002bb510(u8* p);  // 0x002bb510: definition moved into src/anon/unit_002bb070.cpp

void func_002edfd8(void*, void*);  // list_unlink_and_clear
s32 func_002be5b8(void*);
void func_0015f548(void);
void func_001c8e90(void);
void func_002be9b0(void);

void func_002be0b0(u8* p, s32 i);  // 0x002be0b0: definition moved into src/anon/unit_002be020.cpp

extern f32 D_01e2be10;
extern f32 D_01e2be14;

}

// wtarget_002cb188 (0x2cb188): moved to src/anon/unit_002cac58.cpp


extern "C" {

extern u32 D_00361f60;

s32 func_002cf1f8(u8* a, u8* b);  // 002cf1f8: moved to src/taito/minigame_base.cpp (linked unit)

struct Vec4f { f32 x, y, z, w; };
extern Vec4f D_00362d80;

}

void wtarget_002e1878(u32 a, u32 b, u32, u32);  // 0x002e1878: definition moved into src/anon/unit_002de3c8.cpp

extern "C" {

s32 func_001b9bc8(u32);

// Call slot 17 on every other object with the same part number as this one.
void func_002e8a28(u32** p) {
    u32 me = (*p)[1];
    u32 type = func_0016a070((void*)me);
    u32 o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (func_0016a070((void*)o) == type && o != me) (*(VFn*)(*(u8**)o + 68))((void*)o);
    }
}

}
