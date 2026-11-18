#include "../common/types.h"

typedef s32 (*IFn)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, u32, u32);
typedef u32 (*AllocFn)(void*, u32, s32);

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

// A local whose (empty) destructor keeps the final call from becoming a sibcall.
struct NoTail { ~NoTail() {} };

extern "C" {
void MENU_DestoryAllocator(void) asm("_ZN4MENU16DestoryAllocatorEv");
u32 wtarget_00127d40(u32, u32, u32, u32) asm("_Z16wtarget_00127d40jjjj");
void f1340e8(void*) asm("_Z13func_001340e8Pv");
void wtarget_0013a820(u32, u32, u32, u32) asm("_Z16wtarget_0013a820jjjj");
void wtarget_001ac2a8(u32, u32, u32, u32) asm("_Z16wtarget_001ac2a8jjjj");
u32 u_call4_002ed830(u32, u32, u32, u32) asm("_Z16u_call4_002ed830jjjj");
s32 LoadDataIsFlushing(void) asm("_ZN2Tz18LoadDataIsFlushingEv");
s32 LoadDataIsFlushing_at(void) asm("func_00292630");  // same function, by its fixed address

void func_00170c00(void*);
s32 func_0019ba60(void*);
void func_0011f3b8(void*);
void func_0011ee58(void*);  // set_vtbl_347940
void func_00127f40(u32, u32);
void func_001316f0(u32, u32);
s32 func_001341e8(void*);
s32 func_00134020(void);
void func_00134030(void);  // poll_timer_status
void* func_001b9bc8(void*);
s32 func_0016f930(s32);
void func_0016fb00(void*);
s32 func_0019c5d0(void*);
void func_00177638(void*);
void func_001dc978(void*, f32);
void* func_001de168(u32, u32, u32, u32, u32, void*);  // scan_list_by_half
s32 func_001b58a8(void);
s32 func_001a6850(void);
void* func_00102c18(u32, u32, void*);
void func_00196888(void);
void func_00196a08(void);
void func_0019d228(void*);
void func_0019cbe8(void*);
void func_0019d480(void*);
void func_00190128(void*);
s32 func_00239bf8(void*, u32);
void func_001ac970(void*, u32, u32, u32, u32, u32, u32, u32);
void func_001ac078(void*, u32, u32, u32);
void func_001aa388(void*, u32);
void func_001ad990(void*, f32, f32, f32);
u8 func_00181500(u16);
u8 func_001b8958(u16);
u8 func_001a6d08(u16);
void func_001e2c00(void*);
void func_001e6c00(void*);  // alloc_336_align_171
void func_00321c50(void*, void*);
void func_001dc4b8(void*);
void* func_00106a18(s32);  // buffer_get_256
void* func_00106a60(s32);  // buffer_get_by_index
void func_001dd320(void*, void*, s32);
void sceVu0UnitMatrix(void*);  // vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*);
void func_002247e8(s32);
s32 func_002249b8(void);  // get_global_36dac0
void func_002248f8(s32);
s32 func_002ef7b8(void);
void* func_0014abd8(void);
void func_0014aa58(void*, s32, s32);
void func_002ef7a0(s32, void*);
void func_002fde18(void*, s32, s32);
u8* func_001058e8(void);
s32 func_00139d78(void*);
void func_002579e0(void);
s32 func_0028be58(void*);
void func_0028be18(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void* func_00103580(void);
void func_002bd788(u32);
void func_002bd730(void*, s32, s32, s32);
void func_00139570(void*);
u8* func_00103eb0(void);
s32 func_00102a38(void*, void*);  // list_contains_id
void func_00292608(void);
void func_002933b8(void);
s32 func_00170cd0(void);
s32 func_0023f900(void*);
void func_0023fad0(void*);
void func_00293d80(s32);
void func_0017f540(void*, s32, f32, f32);
void func_0017d8c0(void*, void*, void*);
void func_00182f38(void);
void func_00182f28(s32);  // store_global_35ed04
void func_00319f88(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);
void func_002cbed8(void*, void*);
void func_0017f5f8(void*, s32, s32, f32, f32);
u8* func_002eaf40(void*);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_002ed630(void*);
void func_002ed720(void*);
void func_001991a8(s32);
void func_00239870(void*);

extern u8 D_0032ba30;
extern s32 D_0032ba24;
extern void* D_0032ba14;
extern u32 D_0032ba18;

// Frees the menu allocator unless it is locked or the menu mode is 1, 2 or 6.
// 00103748: MENU::DestoryAllocator, moved to src/common/unit_001031b0.cpp

s32 func_00112d28(u8* p);  // 0x00112d28: definition moved into src/anon/unit_001117d8.cpp

// Any of the first count() flag bytes has bit 2 set.
s32 func_0011f078(void** o, u8* flags);  // 0x0011f078: definition moved into src/anon/unit_0011c128.cpp

// Destructor: release each offset-listed entry of the attached table.
extern u32 D_00347a90;
void func_00123ba8(u32* self);  // 0x00123ba8: definition moved into src/anon/unit_00123990.cpp

u32 wtarget_00127d40(u32 a, u32, u32, u32);  // 0x00127d40: definition moved into src/anon/unit_00127a88.cpp

extern volatile u8 D_00347cb4;
// 0x001340e8: definition moved into src/anon/unit_00133cf0.cpp

struct Pair { u32 a, b; };
struct S347fb0 { u32 x, y; Pair e[4]; };
extern S347fb0 D_00347fb0;
extern Pair D_00347fd8[2];
// 0013a820: static initialiser, now made by gcc in src/harata/libdk/field2dd.cpp

// Default material check: no alpha offset, 255 scale, neutral 0x808080 colour.
extern u8 D_00340eb0;
s32 func_0015cc80(u8* p);  // 0x0015cc80: definition moved into src/anon/unit_0015cb18.cpp

// Calls virtual slot 13 on every object of the iterator.
void func_0016bb38(u32 a, u32 b);  // 0x0016bb38: definition moved into src/anon/unit_00169f98.cpp

extern void* D_004f63a8;
extern void* D_004f63ac;
void func_0016f8d0(void* p);  // 0x0016f8d0: definition moved into src/anon/unit_0016e8f8.cpp

// Unlinks a node from the global singly linked list, then releases it.
struct Node { u8 pad[60]; Node* next; };
struct List { Node* head; Node* tail; };
extern List D_0034dca0;
void func_001700e8(Node* n);  // 0x001700e8: definition moved into src/anon/unit_0016e8f8.cpp

// 00176258: moved to src/yasui/libys/party.cpp

// 00177540: moved to src/yasui/libys/party.cpp

// 001877a0: moved to src/anon/unit_00185d10.cpp
void func_001877a0(u8* o, u32 a, u32 b);

extern void* D_0034e948;
extern u32 D_01c61960;
extern u32 D_0034f240;
// 001918c8: moved to src/yasui/libys/status.cpp

extern Pair D_00350338[8];
void func_00196a40(void);  // 0x00196a40: definition moved into src/anon/unit_00195d00.cpp

void func_0019cc20(s32* p);  // 0x0019cc20: definition moved into src/anon/unit_0019ba60.cpp

// 001ac2a8: moved to src/anon/unit_001abb28.cpp

// Only the first arm is a tail call: the function falls off the end otherwise.
struct B3 { u8 a, b, c; };
extern B3 D_00350a38[];
// 001acfb0: moved to src/anon/unit_001abb28.cpp

extern u8 D_00350b30[];
// 001ad4a8: moved to src/anon/unit_001abb28.cpp

// 001b0728: moved to src/yasui/libys/lookat.cpp

u8 func_001d5868(u16* p);  // 0x001d5868: definition moved into src/anon/unit_001d4f40.cpp

extern u8 D_00352ae0[];
extern s32 D_00352ae8;
extern u8 D_00352b48[];
void func_001dc418(u8* o);  // 0x001dc418: definition moved into src/anon/unit_001dbfd8.cpp

extern u8 D_00352af0;
extern u8 D_00352af1;
void func_001dd2b8(void);  // 0x001dd2b8: definition moved into src/anon/unit_001dd2b8.cpp

extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
void func_001eb140(void*, f32* v);  // 0x001eb140: definition moved into src/anon/unit_001e8ac8.cpp

void func_001eb1b0(void*, f32* v);  // 0x001eb1b0: definition moved into src/anon/unit_001e8ac8.cpp

s32 func_0022b028(s32 n);  // 0022b028: moved to src/sasa/musical_input.cpp (linked unit)

void func_0022bb60(void* p);  // 0022bb60: moved to src/sasa/event_movie.cpp (linked unit)

struct B8 { u8 b[8]; };
extern u8* D_0035ec9c;
extern u8* D_0035ec94;
void func_00241850(s32 i, s32 clear);  // 0x00241850: definition moved into src/anon/unit_0023f5b8.cpp

// Bit test in the flag array at +18904.
s32 func_002431d0(s32 a, s32 b);  // 0x002431d0: definition moved into src/anon/unit_00242478.cpp

extern u8* D_0035ed8c;
void func_0024b078(void);  // 0x0024b078: definition moved into src/anon/unit_00249ef0.cpp

extern void* D_0035f04c;
extern void* D_0035f01c;
void func_00269ef8(void);  // 0x00269ef8: definition moved into src/anon/unit_00269a60.cpp

extern u32 D_0035f2c0;
extern u8 D_00374348[];
void func_00284e40(void);  // 0x00284e40: definition moved into src/anon/unit_00284220.cpp

void func_0028a908(u8* o);  // 0x0028a908: definition moved into src/anon/unit_00288b00.cpp

extern u8 D_0035f4b8;
// Tz::LoadDataIsFlushing(): true while load data is still being flushed.
// 00292630: moved to src/anon/unit_00292620.cpp

extern s16* D_0035f4e8;
s32 func_00293668(void);  // 0x00293668: definition moved into src/anon/unit_00292e60.cpp

extern u8 D_0035f5e0;
extern u8 D_0035f5e1;
extern void* D_0035f5dc;
void func_002a1c68(void);  // 0x002a1c68: definition moved into src/anon/unit_002a0908.cpp

void func_002bebd0(void*, u8* o);  // 0x002bebd0: definition moved into src/anon/unit_002bebd0.cpp

struct M64 { Q16 r[4]; };
extern Q16 D_01e2bcb0;
extern Q16 D_01e2bca0;
extern M64 D_01e2bcc0;
void func_002c2168(Q16* q);  // 0x002c2168: definition moved into src/anon/unit_002c1e80.cpp

extern s32 D_00361fa0;
extern u8* volatile D_00361fa4;
void func_002cf938(u8 on);  // 0x002cf938: definition moved into src/anon/unit_002cf260.cpp

// Destructor chain: vtables reset as each base is torn down.
extern u8 D_00362060[];
extern void* D_00362050;
extern u8 D_0034e8b8[];
extern u8 D_0034ee08[];
void func_002d1028(u8* o);  // 0x002d1028: definition moved into src/anon/unit_002cf260.cpp

extern Q16 D_01e2be20;
// 002e3a18: moved to src/anon/unit_002e2f08.cpp

// 002eb7f0: moved to src/anon/unit_002eaf38.cpp

u32 u_call4_002ed830(u32 a, u32, u32, u32);  // 0x002ed830: definition moved into src/anon/unit_002ecdb0.cpp

void func_002eda90(f32* p, f32 f);  // 0x002eda90: definition moved into src/anon/unit_002ecdb0.cpp

// Constructor: primary and secondary vtables, then registers with the manager.
extern u8 D_00348590[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern void* D_00347f80;
void func_0031b0c0(u8* o);  // 0x0031b0c0: definition moved into src/anon/unit_003197d0.cpp
}
