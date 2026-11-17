#include "../common/types.h"

extern "C" {
void func_00102818(u32, u32, u32, u32, u32);
void func_0016bd60(void*, s32);
void func_00113668(void*);
void func_00105110(void*);
u32 func_001688c8(char*);
void* func_00170b30(u32);  // alloc_align128
void func_0013f030(void);
void func_0013f048(void);
void* func_0014aba8(void);
void func_0014aa80(void*, s32, s32);
void func_00150dc0(u32, u32, u32, u32, u32, u32);
u8 func_00139d78(void*);
void func_00151c70(void*);
u8 func_00167d68(void*);
void* func_0016f610(const void*, s32);
void* func_00185890(u32, void*);
u32 func_001a8258(u32);
u32 func_001a8418(u32);
u32 func_001a8510(void);  // mod8_of_difference
void func_001382b8(u32);
void func_001940f0(void*, s32);
void func_00186740(u32, u32, u32, u32, f32, f32);
void func_001991a8(u32, u32);
u8 func_00239d10(void*);
s32 func_001bb4a0(void);
void* func_001bbcb0(void);
void* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_001980d0(void*, u32, s32, u32);
void func_0021fa10(void*);
void func_00240360(void);
void func_00234590(s32, u32, s32, u32, s32);
void func_0014aa58(void*, s32, s32);
void func_002bd760(s32);
void func_00287cc0(s32);
void func_00287c78(void);
void func_00287c20(void);  // clear_global_flag_return_m1
s32 func_00276c18(void);
u8* func_00294000(s32);
u8 func_0028acc8(u32);
u8 func_002cff98(void*);
u8 func_002e7328(void*);  // to_2e7458
void func_002e7670(void*);
void func_002e76b0(void*);
void func_002e77a8(void*);
void func_002ee730(void*);
s32 func_002bc1e8(s32);
u32 func_0010c7e8(u32);
void func_00119830(u32, u32);
void func_00239848(void*);  // set_vtbl_36eb28_then_call
void func_00106420(void*);
void func_001d48b0(void*);
u8 func_00108698(void*);
u8 func_001ddd10(void*);

extern u32 D_0032ba94;
extern u8 D_00347220[];
extern u32 D_0034a428;
extern u8 D_0034d6c0[];
extern void* D_0034dc98;
extern u32 D_00352768;
extern u32 D_01d5ba68;
extern u8 D_00352908[];
extern s8* D_0035ec94;
extern u32 D_0035ec9c;
extern u32 D_0035ec88;
extern s32 D_0035f2f8;
extern s32 D_0035f2fc;
extern s32 D_0035f304;
extern s32 D_0035f308;
extern s32 D_0035f30c;
extern s32 D_0035f310;
extern s8* D_0035f5d0;
extern void* D_0035f654;
extern u32 D_0035f650;
extern u8 D_00362230[];
extern u8 D_00362428[];
extern u8 D_01e2c088[];
extern u8 D_0034e8a8[];
extern u8 D_00351228[];
struct Trio { s32 a, b, c; };
extern Trio D_01c94090[3];
struct Slot8 { u32 a; s16 b, c; };
extern Slot8 D_01dad9c0[32];

u32 bgse_alloc(char* name, u32& size) asm("_ZN2dk4BGSE5allocEPcRj");
void jumpeffect_outclear(void) asm("_ZN2dk10JumpEffect8outClearEv");
void force_leave_mission_gauge(void* g) asm("_ZN2dk11INFORMATION22forceLeaveMissionGaugeEPNS_13MISSION_GAUGEE");
void* get_weapon_entry(const void* self, s32 i) asm("_ZNK2YS8OBJENTRY16get_weapon_entryEi");
void trap_treasure_get(u32* v) asm("_ZN2YS17trap_treasure_getEP8BD_VALUE");
void trap_stitch_shot_effect(u32* v) asm("_ZN2kn23trap_stitch_shot_effectEP8BD_VALUE");

// 001045b8: moved to src/common/gumimenu.cpp

void func_0010f960(u8* p);  // 0x0010f960: definition moved into src/anon/unit_0010f338.cpp

void func_00115560(void** p);  // 0x00115560: definition moved into src/anon/unit_00114a90.cpp

// 00136790: moved to src/harata/libdk/bgse.cpp

void jumpeffect_outclear(void);  // 0x0013f160: definition moved into src/anon/unit_0013ef70.cpp

void func_0014f688(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_00150dc0(D_0034a428, a, b, c, d, e);
}

void force_leave_mission_gauge(void* g) {
    if (func_00139d78(g)) func_00151c70(g);
}

// 00167e70: moved to src/anon/unit_00167358.cpp

void* get_weapon_entry(const void* self, s32 i);  // 0x0016f6a0: definition moved into src/anon/unit_0016e8f8.cpp

u32 func_0016fac8(u32 a);  // 0x0016fac8: definition moved into src/anon/unit_0016e8f8.cpp

void trap_treasure_get(u32* v);  // 0x001754d0: definition moved into src/anon/unit_00171e58.cpp

// 001775f8: moved to src/yasui/libys/party.cpp

struct Args18 { u32* a; u32 b, c, d; f32 e, f; };
void func_0018f248(Args18* p);  // 0x0018f248: definition moved into src/anon/unit_0018f140.cpp

void func_0019af98(u8* p);  // 0x0019af98: definition moved into src/anon/unit_00199688.cpp

// 001abf00: moved to src/anon/unit_001abb28.cpp

struct Ref0498 { u8* o; u32 x; bool f; };
// 001b0498: moved to src/yasui/libys/lookat.cpp

// 001bbcc0: moved to src/yasui/libys/mission.cpp

struct Flags1bc { u16 a : 14; u16 b : 1; u16 c : 1; };
// 001bc050: moved to src/yasui/libys/mission.cpp

void func_001d4dc0(u32* p, u32 a, u32 b, u32 c);  // 0x001d4dc0: definition moved into src/anon/unit_001d3c08.cpp

void func_001d5030(u32 a);  // 0x001d5030: definition moved into src/anon/unit_001d4f40.cpp

void func_001d9ef0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x9f4) = 0;
    *(void**)p = D_00352908;
}

void func_001fab08(u8* p, u8* q) {
    u8* s = p + **(s32**)(q + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}

void func_0023f6c0(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x48) = a;
}

void func_00240e10(void) {
    func_00240360();
    func_00234590(*D_0035ec94, D_0035ec9c, 99, D_0035ec88, 0);
}

void func_0025cd40(void);  // 0x0025cd40: definition moved into src/anon/unit_002588e8.cpp

void func_00287b98(void);  // 0x00287b98: definition moved into src/anon/unit_00286d28.cpp

void func_00287d68(void);  // 0x00287d68: definition moved into src/anon/unit_00286d28.cpp

s32 func_002a0360(void) {
    s8 c = *D_0035f5d0;
    if (func_00276c18()) return 1;
    return c != 0;
}

u8* func_002a6368(s32 i) {
    u8* b = func_00294000(6) + 16;
    return b + i * 8;
}

u32 func_002b4fb8(void) {
    void* o = D_0035f654;
    u32 v = 0;
    if (o) v = func_00139d78(o);
    if (v) v = func_0028acc8(D_0035f650);
    return v;
}

void func_002d2a58(void** p);  // 0x002d2a58: definition moved into src/anon/unit_002d2498.cpp

u32 func_002d5dd0(u8* p);  // 0x002d5dd0: definition moved into src/anon/unit_002d4548.cpp

// 002e7738: moved to src/anon/unit_002e7658.cpp

// Returns the callee's result when p[2] == 8 (result undefined otherwise, as in the original).
// 002ef1b8: moved to src/anon/unit_002ee8a8.cpp

// 002f09d8: moved to src/naka/libkn/trapfunctions.cpp

void func_0031e630(void** p) {
    *p = D_0034e8a8;
    func_00239848(p);  // set_vtbl_36eb28_then_call
    func_00106420(p);
}

void func_00320768(u8* p) {
    *(void**)p = D_00351228;
    func_001d48b0(p + 0x9c0);
    func_00106420(p);
}

u32 func_00322ba8(u8* p) {
    func_00108698(p + 56);
    return func_001ddd10(p + 192);
}

void func_0022d7e8(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        D_01dad9c0[i].a = 0;
        D_01dad9c0[i].b = -1;
        D_01dad9c0[i].c = -1;
    }
}
}

void wtarget_001afa50(u32, u32, u32, u32);  // 0x001afa50: definition moved into src/anon/unit_001ada38.cpp

struct KeyVal { u32 k, v; };
// Looks up key in a zero-terminated {key, value} table at (*a)+28.
u32 wtarget_001da420(u32 a, u32 key, u32, u32) {
    KeyVal* e = (KeyVal*)(*(u32*)a + 28);
    for (; e->v; e++)
        if (e->k == key) return e->v;
    return 0;
}

// 002ee850: static initialiser, now made by gcc in src/menu/tutorial_widget.cpp
