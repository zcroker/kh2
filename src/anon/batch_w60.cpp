#include "../common/types.h"

// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte value whose copy is a single lq/sq.
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
extern s16 D_00369d98[];
extern s32 D_00348820;
extern u8 D_00348830[][80];
extern s32 D_0034a400;
extern s32 D_0034a408[];
extern char D_0036b248[];
extern u32 D_0034aa08;
extern u32 D_0034f240;
extern u32 D_0032d7c0[][8];
extern u8* D_0034e948;
extern void* D_01d49530[8];
extern s32 D_01d49550;
extern u8* D_00352668;
extern u8* D_01d9e6e4;
extern u32 D_0035f010;
extern u8 D_0035f4f8;
extern u8 D_0035f4f9;
extern u8 D_0035f4fa;
extern u8* D_0035f658;
extern void* D_0035f64c;
extern void* D_0035f678;
extern u8* D_01e2aa80;
extern u32 D_0032b96c;
extern f32 D_00363450;
extern u8* D_00365c48;
extern u8 D_01e3c780[];
extern u64 D_01e4c780;
extern s32 D_01e3c770;

void func_0016adc8(void*, void*);
void func_00176a60(void*, f32);
void kn__Stitch__calc_move_target(void*);
void func_0017f540(void*, s32, f32, f32);
void* func_001144e8(void*, u64);
void func_0010eed8(void*, void*, s32);
u32 kn__Friend__getFlag(void*);  // get_field2940
void func_00112730(void*, u32);
s32 func_001dc5f0(s32);
void func_0013f608(void*);
s32 func_001466b0(void*);  // mat4_transform_vecs
s32 func_00146cb0(void*, void*);
void func_002bc358(s32, s32);
void* func_00192cc0(void*, const char*, u32);
void YS__MESSAGEDRAW__MESSAGEDRAW(void*, s32, void*, u32, s32);
void YS__MESSAGEDRAW__draw(void*, void*, void*, void*);
s32 func_00162098(void);
void func_00162058(f32);  // to_161f48_arg1
void func_00144908(void*, void*);
void* func_0016b0d0(void);
f32* YS__OBJ__get_pos(void*);  // obj_get_attach_or_alt
void func_00167658(void*, s32);
u64 func_00167cd0(void*);
void func_001676b0(void*, u64);
void func_001b2210(void*, void*, f32, f32);
void func_0017f488(void*, s32, f32, f32);
s32 func_00187920(void*);
s32 func_00197e40(void);
void* func_001a3a78(void);
s32 ryj__PAX__start(void*, s32, s32, s32, s32, void*);  // scan_list_by_half
s32 YS__OBJ__is_exist(void*);
void func_0019d358(void*);
s32 YS__BTLOBJ___turn_to_target_range(void*, void*, f32);
s32 func_0018d940(void*, void*, s32, void*);
void* YS__ATTACK_CHECK__hit(void*, void*, void*);
u8* func_0018da18(void*, void*, void*, void*);
void func_001903d0(void*, void*);
void YS__OBJENTRY__ReadRequest(s32, s32, s32);
void YS__OBJ__get_target_pos(void*, void*);
void func_0016f000(s32, void*, f32);
void func_001991a8(s32, s32);
void func_001dc978(void*, f32);
void* func_0017df58(s32);
void* func_0016a070(void*);
s32 func_001c9958(void*, void*);  // state_pair_check
void func_001c9780(void*, f32);
u8* func_001c16f0(void*, void*);
void YS__PRIZEEFFECT__get(void*, void*, s32);
s32 YS__LINK_FLAG__is_ok(void*);
s32 func_001d58f0(void*);
void func_001d5800(void*);
void YS__ITEM__Get(u16, s32, s32);
f32 sceVu0InnerProduct(void*);  // vec3_dot
void sceVu0Normalize(void*, void*);  // vec4_normalize
void func_0021fe08(void*, u32);
s32 func_00257070(s32);
u8* func_00281180(u32, s32);
u8* func_002859a0(void);
s32 func_002938f0(void);
void func_00170320(s32);
u8* func_00103eb0(void);
void TASK_MANAGER__create_thread(u32, s32, u32, void (*)(), s32);
void func_00293848();
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
s32 func_0028be58(void*);
void func_0028be18(void*);
void func_002b5af0(void);
void func_002bbf68(void*, s32);
u8* func_00102788(u32, s32, u32, void (*)());
void func_002c53c8();
void func_0017c030(void*, void*, void*, u8);
void YS__OBJ__prepare_jump(void*, void*);
u32 func_0023a918(void*);
s32 DIntr(void);
void EIntr(void);  // ee_intr_get_enable
void func_002fd408(void*);

// Is `id` in the -1-terminated id table?
// 00103428: moved to src/common/unit_001031b0.cpp

void func_00111060(u8* p, void* v);  // 0x00111060: definition moved into src/anon/unit_00110b00.cpp

// 8-byte constant (a member-function pointer) passed by value.
struct Pmf8 { u64 v; } __attribute__((packed));
extern const Pmf8 D_0036a840;
void func_00118d10(u8* p);  // 0x00118d10: definition moved into src/anon/unit_00118958.cpp

// Follows redirect nodes (type -1) and returns the entry of a type-0 node.
u8* func_00132018(u8* p);  // 0x00132018: definition moved into src/anon/unit_00131418.cpp

struct KeyPair { s32 key; s32 val; };
struct KeyTable { u8 pad[12]; s32 n; KeyPair e[1]; };
// 001362a0: moved to src/naka/libkn/effect_observer.cpp

void func_0013f648(QWord* p);  // 0x0013f648: definition moved into src/anon/unit_0013ef70.cpp

s32 func_00143fc8(void* a, void* b);  // 0x00143fc8: definition moved into src/anon/unit_00142c90.cpp

void func_0014eda8(void);  // 0x0014eda8: definition moved into src/anon/unit_0014ecb8.cpp

void dk__LEVEL_UP_SUMMON__draw(u8* a, void* b, void* c, void* d);  // 0x00152688: definition moved into src/anon/unit_0014ecb8.cpp

// 00159308: moved to src/anon/unit_00159240.cpp

// 001608c0: moved to src/harata/libdk/bgobj.cpp

struct Flags167 { u32 a : 1; u32 b : 1; };
static inline bool flagA167(u8* p) { return ((Flags167*)(p + 72))->a; }
// 00167d68: moved to src/anon/unit_00167358.cpp

struct Args172 { u8** a; void* pos; f32 c; f32 d; s32 e; f32 f; s32 g; };
void YS__trap_obj_hop(Args172* s);  // 0x00172260: definition moved into src/anon/unit_00171e58.cpp

// 00176a90: moved to src/yasui/libys/party.cpp

// 00176be0: moved to src/yasui/libys/party.cpp

// Clears flag bit `id` (1024 bits per row).
// 001814b8: moved to src/yasui/libys/progress.cpp

// 001874a0: moved to src/anon/unit_00185d10.cpp
s32 YS__BTLOBJ__turn_to_lockon_range(void* a, f32 f);

u8* YS__ATTACK__strike(void* a, u8* b, s32 c, void* d);  // 0x0018db38: definition moved into src/anon/unit_0018d050.cpp

struct Out1904 { u32 a[3]; u32 z; QWord q; };
QWord func_001904a8(void* x);  // 0x001904a8: definition moved into src/anon/unit_001900d0.cpp

void YS__PRIZEBOX__Read(void);  // 0x001bfbd8: definition moved into src/anon/unit_001bc568.cpp

void YS__PRIZEBOX__DropNmPresent(u8* p, s32 n);  // 0x001bfcc8: definition moved into src/anon/unit_001bc568.cpp

// 8-entry ring: releases the oldest entry and stores x in its slot.
void YS__HITMARK__Add(void* x);  // 0x001c2c00: definition moved into src/anon/unit_001c2b58.cpp

void YS__SACRIFICE__StartForm(void* p);  // 0x001c9860: definition moved into src/yasui/libys/sacrifice.cpp

void PrizeTrGetAll(void* o) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
void PrizeTrGetAll(void* o);  // 0x001d29c8: definition moved into src/anon/unit_001d2810.cpp

void func_001d5960(void* p);  // 0x001d5960: definition moved into src/anon/unit_001d4f40.cpp

void func_001d9630(u16* p, s32 n);  // 0x001d9630: definition moved into src/anon/unit_001d7458.cpp

union U16Any { u16 h; s32 i; };
struct Reader1da { u8* base; s32 idx; u32 a; u32 pad; u32 b; };
u32 func_001da4d8(Reader1da* s, u16 k);  // 0x001da4d8: definition moved into src/anon/unit_001d9d00.cpp

// 001e08c8: moved to src/rikeda/saveram_gumibattle.cpp

void func_001e2660(u8* p, u8* v);  // 0x001e2660: definition moved into src/anon/unit_001e0cb8.cpp

// Normalised direction (xyz) and length (w); +z when the length is zero.
void func_001e7d20(f32* out, void* v);  // 0x001e7d20: definition moved into src/anon/unit_001e0cb8.cpp

void func_001fab48(u8* a, u32* b, u8* c) asm("_Z13func_001fab48Pv");
void func_001fab48(u8* a, u32* b, u8* c);  // 0x001fab48: definition moved into src/anon/unit_001fa1b8.cpp

// Packs the non-zero entries to the front.
struct Slots26b { u8 pad[16]; u8 n; u8 pad2[3]; u16 a[1]; };
void func_0026b470(void);  // 0x0026b470: definition moved into src/anon/unit_0026a900.cpp

void func_00287430(s32 a, s32 b);  // 0x00287430: definition moved into src/anon/unit_00286d28.cpp

void func_002937c0(void);  // 0x002937c0: definition moved into src/anon/unit_00292e60.cpp

void func_002b5658(void);  // 0x002b5658: definition moved into src/anon/unit_002b3ac8.cpp

static inline u8* nextNode2bc(u8* n) {
    if (!n) return D_01e2aa80;
    return *(u8**)(n + 28);
}
void func_002bc708(s32 id);  // 0x002bc708: definition moved into src/anon/unit_002bb8b0.cpp

void func_002c5418(u32 x);  // 0x002c5418: definition moved into src/anon/unit_002c53c8.cpp

void Ts__ACTION_DICE__party_jump(void* self, u8* o, u8 c);  // 002eabe8: moved to src/anon/unit_002eaa68.cpp

// Unpacks a 32-bit RGBA value into bytes.
// 002ef660: moved to src/anon/unit_002ef1f8.cpp

struct Blk2fd { Blk2fd* next; s32 n; u32 items[32]; };
Blk2fd* malloc(u32);  // pool_free_block
// newlib atexit: appends x to the chain of 32-entry exit-function blocks.
s32 atexit(u32 x);  // 0x002fd188: definition moved into src/newlib/libc/atexit.c

// Frees a block: 1 KB pool blocks clear their used bit, others go to the heap.
void __cxa_free_exception(u8* p);  // 0x00316658: definition moved into src/libsupc++/eh_alloc.cpp
}
