#include "../common/types.h"

extern "C" {

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

extern void* D_0032b9ec;
u32 func_00102818(void*, u32, u32, u32, u32);
// 00103b78: moved to src/common/unit_001031b0.cpp

struct Obj109 { u8 pad[16]; u32 f16; };
extern Obj109* D_0033cc90[];
extern u32 D_0033cc78[];
void func_00109cc0(s32 i, u32 v);  // 00109cc0: moved to src/anon/unit_00109c30.cpp

extern u32 D_00347050;
void func_00113668(void*);
void func_00105110(void*);
void func_001153e8(void** p);  // 0x001153e8: definition moved into src/anon/unit_00114a90.cpp

extern u8 D_00347c88[];
void func_00133bb8(void*, u32, u32, u32);  // forward_sub24_to_133848
void func_001344b8(u32 a);  // 0x001344b8: definition moved into src/anon/unit_00133cf0.cpp

// 00135cc8: moved to src/naka/libkn/obj_observer.cpp

extern u8 D_00348700;
extern void* D_0032b96c;
void func_0013ef90(void);
void func_00102788(void*, u32, u32, void*);
void func_0013efe8(void);  // 0x0013efe8: definition moved into src/anon/unit_0013ef70.cpp

extern void* D_00349ef8;
void func_003058a0(u32);
void sceGsSyncPath(u32, u32);
void func_002f3918(void*, void*);
// 0014d8d0: moved to src/anon/unit_0014d680.cpp

u32 func_00139d78(void*);
void func_00151bf0(void*);
void func_0014fb00(void* p);  // 0x0014fb00: definition moved into src/anon/unit_0014ecb8.cpp

extern u8 D_0034d3c0[];
u8 func_001678f0(void*);
// 00167b60: moved to src/anon/unit_00167358.cpp

void func_0016adc8(void*, Vec4*);
void func_0016aeb8(void*, f32);
void func_0016ae18(u8* p);  // 0x0016ae18: definition moved into src/anon/unit_00169f98.cpp

typedef u32 (*VFn3)(void*, u32, void*);
extern void* D_004f6288;
// 0016c7a0: moved to src/anon/unit_0016c770.cpp

void func_0016b010(void*, Vec4*);  // obj_set_float1644_from_pair
void func_00171930(u8** p);  // 0x00171930: definition moved into src/anon/unit_00170f58.cpp

void func_0019ba60(void*);
void func_00172e48(u8** p);  // 0x00172e48: definition moved into src/anon/unit_00171e58.cpp

Vec4* func_0016c028(void*);  // obj_get_attach_or_alt
Vec4 func_0018d808(u8* b);  // 0x0018d808: definition moved into src/anon/unit_0018d050.cpp

struct Arg18f { void* a; u32 b; u32 c; f32 d; f32 e; };
void func_001a4d40(void*, u32, u32, f32, f32);
void func_0018f9b8(Arg18f* p);  // 0x0018f9b8: definition moved into src/anon/unit_0018f140.cpp

struct Node1995 { u8 pad[12]; u32 key; u32 pad2; Node1995* next; };
extern Node1995* D_01c62140;
// 001995b8: moved to src/anon/unit_001991a8.cpp

void func_001a9350(void*);
void func_001a9218(void*);
void func_001a93b0(u32* p, u32 v);  // 0x001a93b0: definition moved into src/anon/unit_001a9130.cpp

extern u8 D_01c6cd20[];
void func_002362b0(void*, u32);
void func_002367c8(void*);  // obj_dispatch_bitfield64
void func_001aadb0(u32 a);  // 0x001aadb0: definition moved into src/anon/unit_001aaa08.cpp

u32 func_001b0320(u32, u32, u32, u32);  // is_field16_set
void func_002bc358(u32, u32);
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b0330jjjj");
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b0330: definition moved into src/anon/unit_001ada38.cpp

extern u8* D_01d49320;
u32 func_001bb4a0(void);
// 001bb4b0: moved to src/yasui/libys/mission.cpp

u8 func_001bba30(void*);
// 001bba88: moved to src/yasui/libys/mission.cpp

u8* func_001bbcb0(void);
// 001bc010: moved to src/yasui/libys/mission.cpp

extern void* D_00352678;
extern void* D_00352668;
void func_001a4e30(void*);
void func_001d28f0(void** p);  // 0x001d28f0: definition moved into src/anon/unit_001d2810.cpp

// 001d3498: moved to src/anon/unit_001d30b0.cpp

struct Ent1d7 { u32 a; u32 b; };
struct Obj1d7 { u32 hdr; Ent1d7 e[4]; };
void func_001d7b10(u32, u32, u32, u32);
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001d7a50jjjj");
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001d7a50: definition moved into src/anon/unit_001d7458.cpp

extern u32 D_00352908;
void func_001980d0(void*, u32, u32, u32);
void func_001d9eb0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2548) = 0;
    *(void**)p = &D_00352908;
}

extern void* D_01d9e6e4;
void func_002fde18(void*, u32, u32);
u8 func_001e7798(void*, void*);
u8 func_001e6c00(void* p);  // 0x001e6c00: definition moved into src/anon/unit_001e0cb8.cpp

extern u32 D_0035db10;
extern u8 D_0035de27;
extern u32 D_0035de30;
extern u32 D_0035de34;
extern u32 D_0035de38;
extern u32 D_0035de3c;
void func_00226a78(void);  // 0x00226a78: definition moved into src/anon/unit_00224780.cpp

void func_0023f688(u8* p, u32 v);  // 0x0023f688: definition moved into src/anon/unit_0023f5b8.cpp

void* func_001708f8(const char*, s32);
void func_0023fa08(void*, void*);
void LayFile_alloc(u8* self, const char* name) asm("_ZN2Tz7LayFile5allocEPKc");
void LayFile_alloc(u8* self, const char* name);  // 0x0023fa90: definition moved into src/anon/unit_0023f5b8.cpp

u8 func_0031acc0(void*);
u8 func_00258158(u8* p);  // 0x00258158: definition moved into src/anon/unit_00254020.cpp

u8* func_00103eb0(void);
void func_00263db0(void);
void func_00263d70(void);  // 0x00263d70: definition moved into src/anon/unit_002632d0.cpp


extern u8 D_0035f3a8[];
void* func_002537c8(u32);
void PauseTaskSetup(...) asm("_ZN2Tz14PauseTaskSetupEz");
void PauseTaskSetup(...);  // 0x0026ec70: definition moved into src/anon/unit_0026c450.cpp

extern void* D_0035f574;
void func_00290940(void*);
u32 func_00293db8(u32, u32);
void func_00290960(void*, u32, u32);
void func_00293fc0(void);  // 0x00293fc0: definition moved into src/anon/unit_00292e60.cpp

u8* func_002766d0(void);
void func_0028da70(void*, u32);
void func_0029e3a0(s32 i);  // 0x0029e3a0: definition moved into src/anon/unit_0029d008.cpp

u8* func_00294000(u32);
u8* func_002a01c8(s32 i);  // 0x002a01c8: definition moved into src/anon/unit_0029f938.cpp


extern u32 D_00362158;
void func_002cea28(void*);
void func_002d1840(void** p);  // 0x002d1840: definition moved into src/anon/unit_002cf260.cpp

extern u32 D_00362428;
void func_002cfeb0(void*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002e7308(void*);
void func_002d5d50(u8* p, u32 a, u32 b);  // 0x002d5d50: definition moved into src/anon/unit_002d4548.cpp

extern u8* D_00361f60;
void func_002ceb08(void);
u32 GetCurrentPoint(void* self) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");
// 002e2e18: moved to src/anon/unit_002e2d18.cpp

void* func_001050d8(u32);
void* func_0016e920(u32);
void func_002ed300(void*, void*, u32);
void TrinityShot_Init(void* self) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");
void TrinityShot_Init(void* self) {
    void* v = func_001050d8(2560);
    func_002ed300(v, func_0016e920(1475), 256);
}

void* func_0010c7e8(void*);
void func_00119e60(void*, u32);
void trap_genie_change_form(u8** v) asm("_ZN2kn22trap_genie_change_formEP8BD_VALUE");
// 002f08d8: moved to src/naka/libkn/trapfunctions.cpp

extern u32 D_003677b8;
void func_00315768(void*);
void func_00106420(void*);
void func_003158c8(void** p) {
    *p = &D_003677b8;
    func_00315768(p);
    func_00106420(p);
}

extern u32 D_00351228;
void func_001d48b0(void*);
void func_003206f0(u8* p) {
    *(void**)p = &D_00351228;
    func_001d48b0(p + 2496);
    func_00106420(p);
}

struct Node321 { u8 pad[20]; Node321* next; };
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_00321cb0jjjj");
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    Node321* n = 0;
    while ((n = !n ? *(Node321**)a0 : n->next) != 0) {
        if (n == (Node321*)a1) return 1;
    }
    return 0;
}

}
