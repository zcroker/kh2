#include "../common/types.h"

extern "C" {
f32 func_00106558(f32);
u32 func_001c8cd8(void);
void kn__Genie__changeForm(u32, u32);
void func_001391c8(u32, u32, u32);
void func_0013b128(u32);
u32 func_00140df0(u32);
void func_00140e30(u32, u32);
void func_001a9350(u32);
void func_0016c358(u32);
f32 func_002f8ad0(f32, f32);
u32 func_0016b740(u32);
void func_00188470(u32, u32, f32);
void func_001d6a80(u32);
void func_00176ec8(u32);
void func_00180ce0(u32);
u8 func_0017ee68(u32);
void func_001b50e0(u32, u32, f32, u32);
void func_00191c30(f32);
u8 func_0019f2a8(u32, u32);
void func_002f7e60(void);
void func_002f71b0(u32);
void func_002f79c8(u32);
void YS__OBJ__prepare_jump_height(u32);
void func_0016bd60(u32, u32);
u32 func_001a36e0(u32);
u32 func_001a80c8(u32);  // table24_find_by_id
void YS__COMMAND_ELEM__Get(u32);
void func_001dc9e0(u32);
u32 func_001e6cd0(u32);
void func_001dcdb8(void);
void ryj__PAX__TaskStart(void);
void sa__MUSICAL_COMBO__createCircle(u32, u32, u32, u32, f32);
void func_002340f0(u32, u32, u32, u32, u32, u32);
u32 func_002f35e8(u32);
void func_002f3918(u32, void*);
u32 func_002537c8(u32);
void func_0023fa08(u32, u32);
void func_00257388(u32, u32);
void func_002571e0(u32);
void func_00287cc0(u32);
u8 func_00139d78(u32);
void func_002ba3e8(u32, u32, u32, u32, u32, s32*, u32, u32);
void func_002b70b8(u32, u32, u32);
u32 func_0010c7e8(u32);
void func_002eb990(u32, u32, f32);

extern u8* D_00352130;
extern f32 D_01c61968;
extern u32 D_0035037c;
extern u32 D_01d48db8[];
extern s32 D_01d4934c;
struct Blob10 { u16 h[5]; };
extern Blob10 D_01d5a970;
extern u32 D_01d9e340;
struct ZeroPair { u32 a, b; };
extern ZeroPair D_01d9e348;
extern char D_0035e3f0[];
extern u8* D_0035ec94;
extern u32 D_003718d0[11];
extern u32 D_0035f074;
extern u32 D_0035f334;
extern char D_0035f3a8[];
extern u32 D_0035f21c;

struct VObj { void** vtbl; };
// Script-style argument block: {ptr, int, float, int}
struct Args { u32 a; u32 b; f32 c; u32 d; };

// Symbol table names this with eight u32 params; the body takes floats in f12/f13.
f32 func_001065a8(f32 a, f32 b) asm("_Z13func_001065a8jjjjjjjj");
// 001065a8: moved to src/anon/unit_00106490.cpp

void func_00119c88(u32 a0);  // 0x00119c88: definition moved into src/anon/unit_00119bf8.cpp

// Virtual call (slot 15) on the object at +20, forwarding the field at +260.
void func_0011c7c8(u8* a0, u32 a1);  // 0x0011c7c8: definition moved into src/anon/unit_0011c128.cpp

void func_0013b1a0(u32 a0);  // 0x0013b1a0: definition moved into src/anon/unit_0013a8b8.cpp

// 001586b8: moved to src/harata/libdk/cannoncamera.cpp

void YS__OBJ___OVR__destroy(u32 a0);  // 0x0016a328: definition moved into src/anon/unit_00169f98.cpp

// Stores f(x, z) of the vector at a1 into +1644 (e.g. a heading angle).
void YS__OBJ__set_wish_dir(u8* a0, f32* a1);  // 0x0016b010: definition moved into src/anon/unit_00169f98.cpp

// trap_obj_hide: virtual slot 17 on the trap object.
void trap_obj_hide_impl(u32* bd) asm("_ZN2YS13trap_obj_hideEP8BD_VALUE");
void trap_obj_hide_impl(u32* bd);  // 0x00171348: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_search_by_entry_impl(u32* bd) asm("_ZN2gm24trap_obj_search_by_entryEP8BD_VALUE");
void trap_obj_search_by_entry_impl(u32* bd);  // 0x00172ba8: definition moved into src/anon/unit_00171e58.cpp

void func_00173e38(u32* a0);  // 0x00173e38: definition moved into src/anon/unit_00171e58.cpp

// 00179e18: moved to src/yasui/libys/player.cpp

// 0017eb68: moved to src/yasui/libys/motion.cpp

// True when the entry at +320 is set and its id (+20) is in [140, 151).
// 00186d18: moved to src/anon/unit_00185d10.cpp
bool func_00186d18(u8* a0);

void func_0018fde0(Args* a);  // 0x0018fde0: definition moved into src/anon/unit_0018f140.cpp

// 00191bf0: moved to src/yasui/libys/status.cpp

u32 func_001979d8(u32 a0);  // 0x001979d8: definition moved into src/anon/unit_00195d00.cpp

void func_001ae650(void);  // 0x001ae650: definition moved into src/anon/unit_001ada38.cpp

void YS__ACTION_CARPETJUMP__jump_height(u32 a0, u32 a1);  // 0x001b2c18: definition moved into src/anon/unit_001b2780.cpp

// COMMAND_ELEM GetForm
void command_elem_get_form(u32 a0) asm("_ZN2YS12COMMAND_ELEM7GetFormEi");
void command_elem_get_form(u32 a0);  // 0x001b90c8: definition moved into src/anon/unit_001b87a0.cpp

// Sets control-off bit i in the global bitset.
void control_off(s32 i) asm("_ZN2YS3OBJ10ControlOffEi");
void control_off(s32 i);  // 0x001b9c28: definition moved into src/anon/unit_001b9880.cpp

// Hands out a new combo group id, wrapping back to 256.
s32 new_combo_group(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
s32 new_combo_group(void);  // 0x001c0090: definition moved into src/anon/unit_001bff88.cpp

void YS__ACTION_CARPETBLOW__jump_height(u32 a0, u32 a1);  // 0x001c90c0: definition moved into src/anon/unit_001c8e80.cpp

// 001cd520: moved to src/anon/unit_001cd078.cpp

// Pops one entry: --count; return base + scale * table[count].
s32 func_001db888(s32* a0);  // 0x001db888: definition moved into src/anon/unit_001d9d00.cpp

u32 effect_pos(u32 self) asm("_ZN3ryj6EFFECT3posEv");
u32 effect_pos(u32 self);  // 0x001dc5f8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de7d8(u32 a0);  // 0x001de7d8: definition moved into src/anon/unit_001ddcf0.cpp

void func_001e01b8(u32 a0);  // 0x001e01b8: definition moved into src/anon/unit_001deb58.cpp

void func_00229d40(u8* a0);  // 00229d40: moved to src/sasa/musical_combo.cpp (linked unit)

void func_00234590(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0);  // 0x00234590: definition moved into src/anon/unit_002335e8.cpp

void func_002367a0(void);  // 0x002367a0: definition moved into src/anon/unit_00236180.cpp

// ORs bits into the flags of entry i (32-byte records); i < 0 means current.
void func_00240fd8(s32 i, u32 bits);  // 0x00240fd8: definition moved into src/anon/unit_0023f5b8.cpp

// Index of v in an 11-entry table, or 11.
u32 func_00243190(u32 v);  // 0x00243190: definition moved into src/anon/unit_00242478.cpp

void func_00258a88(void);  // 0x00258a88: definition moved into src/anon/unit_002588e8.cpp

void func_002691c8(void);  // 0x002691c8: definition moved into src/anon/unit_00268b30.cpp

void func_00276410(void);  // 0x00276410: definition moved into src/anon/unit_002748a0.cpp

u32 func_00276df8(void);  // 0x00276df8: definition moved into src/anon/unit_002748a0.cpp

void func_00288610(void);  // 0x00288610: definition moved into src/anon/unit_002880b8.cpp

void func_002ba3b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2);  // 0x002ba3b8: definition moved into src/anon/unit_002b9ab8.cpp

void func_002ba948(void);  // 0x002ba948: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e8220(Args* a);  // 0x002e8220: definition moved into src/anon/unit_002e7b10.cpp

// 002f0798: moved to src/naka/libkn/trapfunctions.cpp

// d = m translated by v: copies rows 0-2, row 3 = m.row3 + v (xyz).
// 128-bit moves and the VU0 macro op are written as asm.
void sceVu0TransMatrix(void* d, void* m, void* v);  // 0x002f3f58: definition moved into src/sdk/libvu0_002f3cd8.s
}
