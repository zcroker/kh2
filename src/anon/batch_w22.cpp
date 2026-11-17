#include "../common/types.h"

struct TASK;

extern "C" {

// --- 00104da0
extern u8 D_003a7b00;
extern u32 D_0032b96c;
void func_001052a8(void);
void func_00104a48(void);
void func_00102818(u32, u32, u32, void (*)(void), u32);
void GUMIMENU_CreateThread(int, int, void (*)(TASK*), int) asm("_ZN8GUMIMENU12CreateThreadEiiPFvP4TASKEi");
// 00104da0: moved to src/common/area.cpp

// --- 0010c7f0
void func_0017dbb8(void*);
struct VObj { void (**vt)(VObj*); };
typedef void (*VFn)(void*);
void func_0010c7f0(u8* p);  // 0x0010c7f0: definition moved into src/anon/unit_0010b978.cpp

// --- 0010f9f0
void func_0010f9f0(u8* p, u8* src, u8 flag);  // 0x0010f9f0: definition moved into src/anon/unit_0010f338.cpp

// --- 00119d08
extern u32 D_003477a0;
void func_00113668(void*);
void func_00105110(void*);
void func_00119d08(void** p);  // 0x00119d08: definition moved into src/anon/unit_00119bf8.cpp

// --- 00124748
u8* func_00124748(u8* a, s32 n);  // 0x00124748: definition moved into src/anon/unit_00123990.cpp

// --- 0013f608
f32 func_0017ce10(f32);
void func_0013f608(f32* p);  // 0x0013f608: definition moved into src/anon/unit_0013ef70.cpp

// --- 0014d910
extern u32 D_00349ef8;
void sceGsSyncPath(u32, u32);
void func_002f3918(u32, u32);
// 0014d910: moved to src/anon/unit_0014d680.cpp

// --- 00153310
extern u8* D_0034a6f0;
void func_0031cc30(u8*, u32, u32, u32, u32, u32, u32);
void func_00153310(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_0031cc30(D_0034a6f0 + 24, 1, a, b, c, d, e);
}

// --- 00154b40
u32 func_0013d810(void);
void func_00154450(u32, u32, u32);
// 00154b40: moved to src/anon/unit_00153ea0.cpp
void func_00154b40(u32 a, u32 b);

// --- 00157068
u32 func_00155f40(void*);
void func_00138c10(void*, u32);
void func_00156408(void*);
void GAUGE_PLAYER_update(u8*) asm("_ZN2dk12GAUGE_PLAYER6updateEv");
// 00157068: moved to src/anon/unit_00153ea0.cpp

// --- 00168008
extern s32 D_0034d780;
extern u32 D_004f5258[];
void func_00167f38(u32);
// 00168008: moved to src/anon/unit_00167358.cpp

// --- 00172368
void func_001a0710(u32, void*, f32);
void func_00172368(u32** p);  // 0x00172368: definition moved into src/anon/unit_00171e58.cpp

// --- 00173518
// Spawn a task and seed its float parameter.
void func_001734b0(void);
u8* func_00102c18(u32, u32, void (*)(void));
struct T173 { u32 pad; f32 a; f32 b; };
void func_00173518(f32* p);  // 0x00173518: definition moved into src/anon/unit_00171e58.cpp

// --- 0017a1c8
void func_001762f8(void*);
void func_00112ab8(u32, void*);
// 0017a1c8: moved to src/yasui/libys/player.cpp

// --- 00192290
u32 func_001921d8(void);
u32 func_001708f8(u32, s32);
void func_00191f78(int, u32);
void MESSAGE_Init(int, int) asm("_ZN2YS7MESSAGE4InitEii");
// Init: moved to src/yasui/libys/message.cpp

// --- 00192388
// Advance past one message token (control codes < 0x20 have table lengths).
extern u8 D_0036cea0[];
// 00192388: moved to src/yasui/libys/message.cpp

// --- 00195468
s32 ctarget_00195468(u32, u32, u32, u32) asm("_Z16ctarget_00195468jjjj");
s32 ctarget_00195468(u32 a, u32 key, u32, u32);  // 0x00195468: definition moved into src/anon/unit_00194790.cpp

// --- 001aae28
struct S1aae28 { u32 a, b, c, d; u8 e, f, g, h; u32 j; u32 i; };
void func_001aae28(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i);  // 0x001aae28: definition moved into src/anon/unit_001aaa08.cpp

// --- 001af328
void* func_001050d8(u32);
void func_001aedf8(void*, u32, u32);
void func_001af328(u32 a);  // 0x001af328: definition moved into src/anon/unit_001ada38.cpp

// --- 001b6d00
extern u8* D_00351184;
extern u32 D_00351214;
void func_00102670(u32, u32);  // to_1025f8
void func_001b6d00(void);  // 0x001b6d00: definition moved into src/anon/unit_001b6a50.cpp

// --- 001b8228
extern u8 D_003a99f0[];
extern u8* D_01d48cb8;
extern u8* D_003511bc;
extern u8* D_003511b8;
extern u8 D_003511c2;
void func_001b8228(void);  // 0x001b8228: definition moved into src/anon/unit_001b6a50.cpp

// --- 001b86e0
// Push an entry's index onto the free list.
struct E20 { u32 w[5]; };
struct G1d48cc8 { E20 e[8]; s32 list[8]; s32 n; };
extern G1d48cc8 D_01d48cc8;
// 001b86e0: moved to src/anon/unit_001b82d8.cpp

// --- 001c0458
// Clear bit o->id in the bitset at bits+4.
void func_001c0458(u8* bits, u8* o);  // 0x001c0458: definition moved into src/anon/unit_001bff88.cpp

// --- 001c13e8
void func_001dc920(u32);
u8 func_001db7d0(void*);
// 001c13e8: moved to src/anon/unit_001c0638.cpp
u32 func_001c13e8(u32* p);

// --- 001c1708
// Walk a linked list (next at +36) and process each node.
void func_001c1890(u8*);
// 001c1708: moved to src/anon/unit_001c0638.cpp
void func_001c1708(u8* p);

// --- 001d7e78
void func_0019aa00(u32, void*);
void func_001b40e0(void*);
void func_001d7e78(u8* p);  // 0x001d7e78: definition moved into src/anon/unit_001d7458.cpp

// --- 001d9688
// Increment a [n][3] byte counter, capped at 99.
struct R3 { u8 v[3]; };
u8 wtarget_001d9688(R3*, u32, u32, u32) asm("_Z16wtarget_001d9688jjjj");
u8 wtarget_001d9688(R3* a, u32 b, u32 c, u32);  // 0x001d9688: definition moved into src/anon/unit_001d7458.cpp

// --- 001e0f90
extern u32 D_00352bd0;
u32 func_001e0cc8(void*);  // entry64_by_field32
void func_001e26b8(u32, u32);
void func_001e0f90(u8* p) {
    func_001e26b8(D_00352bd0, func_001e0cc8(p));
    *(u32*)(p + 36) = 5;
    *(u32*)(p + 40) = 0;
}

// --- 002247e8
extern s32 D_0035de20;
extern s32 D_0035dad8;
extern s32 D_0035dad4;
void func_002247e8(void) {
    if (D_0035dad8 != D_0035de20) {
        s32 n = D_0035dad4;
        if (n < 5) {
            D_0035dad4 = n + 1;
            D_0035dad8 = D_0035de20;
        }
    }
}

// --- 00227a28
extern u8* D_0035dcf0;
u8* func_00227a28(void) {
    u8* p = D_0035dcf0;
    for (s32 i = 0; i < 128; i++) {
        if (*(u32*)(p + 4) == 0) return p;
        p += 84;
    }
    return 0;
}

// --- 0022be28
void func_00226e60(u32);
void func_001024a8(u32);
void func_0022be28(u32 a);  // 0022be28: moved to src/sasa/event_countdown.cpp (linked unit)

// --- 00237508
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
s32 func_00237508(T237* t, s32 i, s32 j) {  // entry20_field8_minus0
    E237* e = &t->ent[t->idx[i * 2] + j];
    return e->c - e->a;
}

// --- 00243150
// Last table entry whose id matches (table ends with a negative id).
struct E243 { s16 id; s16 pad; u32 a, b; };
extern E243 D_00371840[];
E243* func_00243150(s32 id) {
    E243* r = 0;
    for (s32 i = 0; D_00371840[i].id >= 0; i++) {
        if (D_00371840[i].id == id) r = &D_00371840[i];
    }
    return r;
}

// --- 00276c50
// Tz JmReport DrawMessage
u32 func_00192048(u32);
u32 func_00276c88(u32, u8);
u32 JmReport_DrawMessage(s32, u8) asm("_ZN2Tz8JmReport11DrawMessageEjj");
u32 JmReport_DrawMessage(s32 a, u8 b);  // 0x00276c50: definition moved into src/anon/unit_002748a0.cpp

// --- 002811f8
// Index of the entry with the given id, or -1.
struct E281 { s16 id; s16 pad; u32 x[4]; };
struct T281 { s32 n; E281 e[1]; };
s32 func_002811f8(T281* t, s32 key);  // 0x002811f8: definition moved into src/anon/unit_0027f2b0.cpp

// --- 0028b750
extern u32 D_0035f3a0;
void func_0023f7e0(void*);
void func_0028b870(void*);
void func_0028b750(void** p);  // 0x0028b750: definition moved into src/anon/unit_00288b00.cpp

// --- 002ba8a8
void func_002b7078(u32);
void func_002b72e4(s32, s32, u32);
void func_002baa60(void);
void func_002b83b4(void);
void func_002ba8a8(void) {
    func_002b7078(0);
    func_002b7078(1);
    func_002b72e4(-100, -1, 0);
    func_002baa60();
    func_002b83b4();
}

// --- 002bc358
u32 func_002bbda0(u32);
void func_002bbf68(u32, u32);
void MenuSound_StopBgSeHandle(u32, u32) asm("_ZN2Tz9MenuSound14StopBgSeHandleEz");
// 0x002bc358: definition moved into src/anon/unit_002bb8b0.cpp

// --- 002bca10
struct E2bc { s32 b; s32 a; s32 c; };
s32 func_002bca10(E2bc* t, s32 a, s32 b);  // 0x002bca10: definition moved into src/anon/unit_002bc978.cpp

// --- 002dad40
extern u32 D_003627c8;
void func_002cff98(void*);
void func_002dad40(void** p) {
    *p = &D_003627c8;
    func_002cff98(p);
    func_00105110(p);
}

// --- 002dc708
extern u32 D_003629e8;
void func_002e4a90(void*);  // in_even_range
u8 func_002cea28(void*);
u32 func_002dc708(void** p) {
    *p = &D_003629e8;
    func_002e4a90(p + 64);  // in_even_range
    return func_002cea28(p);
}

// --- 002efb60
void func_002efb08(void*);
void func_002efa98(void*);
// 002efb60: moved to src/anon/unit_002ef938.cpp

// --- 002f10c0
u32 func_0010c7e8(u32);
void func_0011a938(u32, u32, f32, f32);
struct P2f1 { u32* a; u32 b; f32 x; f32 y; };
// 002f10c0: moved to src/naka/libkn/trapfunctions.cpp

// --- 002f1130
u32 func_0010c7b0(u32);
u32 func_00136158(u32, u32);
u32 trap_btlobj_is_reflect_motion(u32**) asm("_ZN2kn29trap_btlobj_is_reflect_motionEP8BD_VALUE");
// 002f1130: moved to src/naka/libkn/trapfunctions.cpp

// --- 0031f4b8
extern u32 D_00350bf0;
void func_001ac5b8(void*);
void func_0031f4b8(void** p) {
    *p = &D_00350bf0;
    func_001ac5b8(p);
    func_00105110(p);
}

// --- 00325408
extern u32 D_003622c0;
void func_002d0f38(void*);
void func_00325408(void** p) {
    *p = &D_003622c0;
    func_002d0f38(p);
    func_00105110(p);
}

}
