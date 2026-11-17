#include "../common/types.h"

struct u128 { u32 w[4]; } __attribute__((aligned(16)));
extern "C" {
void func_00135dc8(void*);
void func_00113668(void*);
void func_00105110(void*);
void func_0011e350(void*, u32);
void func_0011e450(void*, u32);
void func_0013efe8(void);
u8* func_00102c80(void);
void func_00102788(u32, u32, u32, void*);
void func_0013f428(void);
void func_0014b638(void*);
void func_0014a988(void*);  // clear_fields_244_260
void func_0014acf8(void);
void func_0014ac18(void);
void func_00167e28(void*);
void func_0019ba60(u32);
void func_0016c018(u32, u32, u32);
void func_00177a38(void*);
u32 func_001b58f0(u32, u32, u32, u32);
void func_001902a8(void*, void*);
void func_0018a970(void*, void*);
void func_001de450(void*);
void func_001dde40(void*);
void func_00170950(u32);
s32 func_002f71b0(s32);
void func_001ae678(void);  // to_306698_arg10
void func_001d2180(void*);
void func_001d20a8(void*);
void func_0017c4c8(void*, void*);
void func_001bc778(void*);
void func_001bc990(void*, void*);
void func_001dc920(u32);
void func_001db7d0(void*);
void func_001a4e30(void*);
void func_00190920(void*, s32, void*);
void func_00198450(void*);
void func_0023f8c8(void*);
void func_00106420(void*);
u8* func_001058e8(void);
void* func_00192048(s32);
void func_00263a90(void*, u8);
void func_0028da70(void*, s32);
s32 func_00287bc0(void);
u8* func_00294000(s32);
void func_002cff98(void*);
void func_002e7328(void*);  // to_2e7458
void* func_0010c7e8(u32);
void func_00118d10(void*, u32);
u32 func_00114438(void*, u32);
void func_0018d420(void*);
void func_002eec58(void*);

extern void** D_0032bb1c;
extern u32 D_0032b91c;
extern u32 D_00347550;
extern u32 D_00349b28;
extern void** D_0034a6f0;
extern u8 D_0034d6c0[];
extern u8 D_01c6cae0[];
extern u32 D_01c6cafc;
extern u8 D_00351248[];
extern u32 D_003527f0;
extern void* D_003527e4;
extern u32 D_0035ebd8;
extern u8* D_0035f264;
extern void** D_0035f34c;
extern u32 D_00362858;
extern u32 D_00362908;
extern u32 D_00350778;
extern u32 D_00361bf0;

void* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void YS_trap_obj_jump_direct(BD_VALUE*) asm("_ZN2YS20trap_obj_jump_directEP8BD_VALUE");
void YS_EFFECT_Ensure(void) asm("_ZN2YS6EFFECT6EnsureEv");
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
u32 YS_LIMIT_reset_hit_counter(u8*) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
void Tz_CMenuHelp_Create(s32, bool) asm("_ZN2Tz9CMenuHelp6CreateEib");
void kn_trap_friend_get_player_attacker(BD_VALUE*) asm("_ZN2kn31trap_friend_get_player_attackerEP8BD_VALUE");
void kn_trap_friend_get_action_param(BD_VALUE*) asm("_ZN2kn28trap_friend_get_action_paramEP8BD_VALUE");
void worldmap_ObjWidget_D0(void**) asm("_ZN8worldmap9ObjWidgetD0Ev");

// 00104cf0: moved to src/common/area.cpp

typedef void* (*AllocFn)(void*, u32, void*);
// 001050d8: moved to src/common/area.cpp

u32 func_0010c7b0(u8* p);  // 0x0010c7b0: definition moved into src/anon/unit_0010b978.cpp

void func_001157d0(void** p);  // 0x001157d0: definition moved into src/anon/unit_00114a90.cpp

void func_0011e410(u8* p, u32 a);  // 0x0011e410: definition moved into src/anon/unit_0011c128.cpp

void func_0013f498(void);  // 0x0013f498: definition moved into src/anon/unit_0013ef70.cpp

void func_0014a950(void** p);  // 0x0014a950: definition moved into src/harata/libdk/fade.cpp

void func_0014ad20(void);  // 0x0014ad20: definition moved into src/harata/libdk/fade.cpp

// Release the object held in D_0034a6f0 (virtual slot 4) and clear the pointer.
void func_00153100(void);  // 0x00153100: definition moved into src/anon/unit_0014ecb8.cpp

// 00154288: moved to src/anon/unit_00153ea0.cpp
s32 func_00154288(u32, s32 a);

// 00167ee0: moved to src/anon/unit_00167358.cpp

typedef void (*JumpFn)(void*, void*, s32);
void YS_trap_obj_jump_direct(BD_VALUE* bd);  // 0x001721d8: definition moved into src/anon/unit_00171e58.cpp

void func_00172a10(u32* p);  // 0x00172a10: definition moved into src/anon/unit_00171e58.cpp

// 00177a78: moved to src/yasui/libys/party.cpp

void func_0018fe48(u32* p);  // 0x0018fe48: definition moved into src/anon/unit_0018f140.cpp

void func_001906f0(void* a, u128* v);  // 0x001906f0: definition moved into src/anon/unit_001900d0.cpp

void func_001940b8(u8* p, u32 a, u32 b, u32 c, f32 x, f32 y);  // 0x001940b8: definition moved into src/anon/unit_00193be8.cpp

// 001a3b08: moved to src/yasui/libys/effect.cpp

void func_001ad990(u32 p, f32 a, f32 b, f32 t);  // 0x001ad990: definition moved into src/anon/unit_001ad990.cpp

void func_001ae620(void);  // 0x001ae620: definition moved into src/anon/unit_001ada38.cpp

u32 YS_LIMIT_reset_hit_counter(u8* self);  // 0x001b5c78: definition moved into src/anon/unit_001b2780.cpp

void func_001b6dd0(u8* p, u128* v);  // 0x001b6dd0: definition moved into src/anon/unit_001b6a50.cpp

void func_001be900(u8* p);  // 0x001be900: definition moved into src/anon/unit_001bc568.cpp

void func_001bf0c8(u8* p);  // 0x001bf0c8: definition moved into src/anon/unit_001bc568.cpp

// Destructor-shaped: the member at +20 is destroyed last (as a cleanup, so no tail call).
struct Member20Dtor { u32* self; ~Member20Dtor() { func_001db7d0(self + 5); } };
// 001c13a8: moved to src/anon/unit_001c0638.cpp
void func_001c13a8(u32* p);

void func_001d74f8(void** p);  // 0x001d74f8: definition moved into src/anon/unit_001d7458.cpp

void func_001d7e00(u8* p);  // 0x001d7e00: definition moved into src/anon/unit_001d7458.cpp

// Fill the index table with 0..n-1 and reset the count.
void func_001db850(u8* p) {
    s32 i;
    for (i = 0; i < *(s32*)(p + 24); i++) ((s32*)*(u32*)(p + 16))[i] = i;
    *(s32*)(p + 8) = *(s32*)(p + 24);
}

void func_0023f870(void** p);  // 0x0023f870: definition moved into src/anon/unit_0023f5b8.cpp

struct Flags { u32 a; u32 on : 1; };
void func_00242a28(u8 on);  // 0x00242a28: definition moved into src/anon/unit_00242478.cpp

void Tz_CMenuHelp_Create(s32 i, bool b);  // 0x00263a58: definition moved into src/anon/unit_002632d0.cpp

void func_002803e0(void);  // 0x002803e0: definition moved into src/anon/unit_0027f2b0.cpp

typedef void (*Slot1Fn)(void*, void*);
void func_00288c20(void* a);  // 0x00288c20: definition moved into src/anon/unit_00288b00.cpp

s32 func_002a43f0(void);  // 0x002a43f0: definition moved into src/anon/unit_002a40c8.cpp

u8* func_002a92a0(s32 i);  // 0x002a92a0: definition moved into src/anon/unit_002a92a0.cpp

void func_002dab30(void** p);  // 0x002dab30: definition moved into src/anon/unit_002da040.cpp

// Destructor-shaped: base teardown runs last as a cleanup (no tail call).
struct BaseDtor { void** self; ~BaseDtor() { func_002cff98(self); } };
void func_002db8e8(void** p);  // 0x002db8e8: definition moved into src/anon/unit_002da040.cpp

void func_002df160(f32* p);  // 0x002df160: definition moved into src/anon/unit_002de3c8.cpp

// 002f0da8: moved to src/naka/libkn/trapfunctions.cpp

// 002f0e60: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f238(void** p) {
    *p = &D_00350778;
    func_0018d420(p);
    func_00105110(p);
}

void worldmap_ObjWidget_D0(void** p) {
    *p = &D_00361bf0;
    func_002eec58(p);
    func_00105110(p);
}

struct E24 { u8 a; u32 b; u32 pad[4]; };
extern E24 D_0035e440[64];
// Clear the 64-entry table at D_0035e440.
void func_00236d60(void);  // 0x00236d60: definition moved into src/anon/unit_00236180.cpp

// 001e0958: moved to src/rikeda/saveram_gumibattle.cpp
}
