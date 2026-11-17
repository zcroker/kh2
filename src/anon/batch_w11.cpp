#include "../common/types.h"

extern "C" {

struct HasF4 { s32 limit; s32 base; };
struct P10f6b8 { u8 pad[1164]; HasF4* lim; };
// Is base*scale over the limit?
s32 func_0010f6b8(P10f6b8* p, f32 scale);  // 0x0010f6b8: definition moved into src/anon/unit_0010f338.cpp

extern u32 D_003464b0;
void func_00113668(void*);
void func_00105110(void*);
void func_00114968(void** p);  // 0x00114968: definition moved into src/anon/unit_001142a0.cpp

extern u32 D_00347848;
void func_0011a510(void** p);  // 0x0011a510: definition moved into src/anon/unit_0011a260.cpp

typedef u8* (*GetFn)(void*);
s16 func_0011f238(void* o, s32 i);  // 0x0011f238: definition moved into src/anon/unit_0011c128.cpp

struct Node135 { void* vt; u32 pad; Node135* next; };
extern u32 D_00347d00;
extern Node135* D_00347cf0;
void func_00135aa0(void*);
// 00135900: moved to src/naka/libkn/obj_observer.cpp

extern u32 D_004574b8;
extern u32 D_0032b91c;
void func_0014f030(void*, f32, f32, f32);  // obj_set_lerp_params
void func_00102788(u32, u32, u32, void (*)(void));
void func_0014cd98(void);
void Vsync_setGameSpeed(f32, f32, f32) asm("_ZN2dk5Vsync12setGameSpeedEfff");
void Vsync_setGameSpeed(f32 a, f32 b, f32 c);  // 0x0014cde0: definition moved into src/anon/unit_0014c7f0.cpp

void func_00138c10(void*, s32);
void func_00150578(u8* p);  // 0x00150578: definition moved into src/anon/unit_0014ecb8.cpp

void func_001581f8(void*);
s32 func_00154ee8(void*);  // field24_state_code
void GAUGE_FRIEND_reload(u8*) asm("_ZN2dk12GAUGE_FRIEND6reloadEv");
// 00155528: moved to src/anon/unit_00153ea0.cpp

extern f32 D_0034aa44;
f32 func_0015a098(void*);
f32 func_0017ce10(f32);
struct P15a { u8 pad[80]; f32 v; };
// 0015a118: moved to src/harata/libdk/targetcamera.cpp

struct RadarS { u8 pad[2928]; void* data; s32 n; };
void func_0015b7f8(void*);
void func_0015bab8(void*);
void Radar_create(RadarS*, void*) asm("_ZN2dk5Radar6createEPv");
void Radar_create(RadarS* self, void* data);  // 0x0015b7c0: definition moved into src/anon/unit_0015b100.cpp

extern u32 D_0032e020;
void* func_00189200(void*, u32);
void func_001891b8(void*, u32);
void trap_saveram_set_form_ability(u32*) asm("_ZN2YS29trap_saveram_set_form_abilityEP8BD_VALUE");
// 0016e130: moved to src/anon/unit_0016d2e0.cpp

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct P173 { u8** a; Q16* q; f32 f; };
void func_0019fdc0(u8*, Q16*, f32);
void func_00173808(P173* p);  // 0x00173808: definition moved into src/anon/unit_00171e58.cpp

void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
// 0017a8f8: moved to src/anon/unit_0017a8f8.cpp

s32 func_001860b0(void*);
void func_001c1b08(void*, u32, s32);
// 00186948: moved to src/anon/unit_00185d10.cpp
void func_00186948(void* a, u8* b);

struct Obj198 { u8 pad[1416]; u32 active : 1; };
Obj198* func_001b9bc8(Obj198*);
// 00198700: moved to src/anon/unit_00197fe0.cpp


struct G19d { u32 pad0; s32 a; u8 pad8[24]; s32 v; s32 b; };
extern G19d* D_00350444;
s32 func_0019d380(s32 a, s32 b);  // 0x0019d380: definition moved into src/anon/unit_0019ba60.cpp

void func_001991a8(s32, u32);
struct P1ac { u8 pad[112]; s32 st; u8 pad2[12]; u32 id; };
// 001ac700: moved to src/anon/unit_001abb28.cpp

struct E1af { u32 a; s32 key; u32 c; };
extern E1af D_01c94090[3];
s32 func_001afe30(s32 key);  // 0x001afe30: definition moved into src/anon/unit_001ada38.cpp

extern u32 D_00350e78;
void func_001b0330(void*);
void func_00106420(void*);
void func_001b01d8(void** p);  // 0x001b01d8: definition moved into src/anon/unit_001ada38.cpp

void* func_001b77a8(s32);
void func_00153468(void*, u32, void*);
void func_001b7768(u32* a, void* b);  // 0x001b7768: definition moved into src/anon/unit_001b6a50.cpp

struct P1be { u8 pad[2728]; u32 a; u32 b; };
void func_001bd668(void*);
void func_001bd5b0(void*, s32, s32);
void func_001befd8(P1be* p, u32 a, u32 b);  // 0x001befd8: definition moved into src/anon/unit_001bc568.cpp

extern u8* D_01d49508;
extern u32 D_00320898;
u8 func_002fd248(void*, void*, u32, s32, void*);
// 001c10f8: moved to src/anon/unit_001c0638.cpp
s32 func_001c10f8(void* a);

struct E1c5 { u8 pad[20]; s32 n; u8 pad2[8]; };
extern E1c5 D_00351680[];
void func_001c5e88(void*);
s32 func_001c5f38(u8* p);  // 0x001c5f38: definition moved into src/anon/unit_001c5b90.cpp

extern u16 D_0032fafe[];
// Bump a saturating counter (max 999).
void func_001d97f0(s32 i);  // 0x001d97f0: definition moved into src/anon/unit_001d7458.cpp

extern u32 D_00352970;
extern void* D_00352960;
void func_001a4e30(void*);
void func_001da278(void** p);  // 0x001da278: definition moved into src/anon/unit_001d9d00.cpp

typedef void (*VFn)(void*);
void func_001dba98(u8* p);  // 0x001dba98: definition moved into src/anon/unit_001d9d00.cpp

extern u32 D_0035dd08[64];
void func_00226050(u32 v);  // 0x00226050: definition moved into src/anon/unit_00224780.cpp

struct E22e { u32 a; s32 key; u8 pad[44]; };
extern E22e* D_0035dcf4;
E22e* func_0022e330(s32 key);  // 0x0022e330: definition moved into src/anon/unit_0022d358.cpp

struct V2 { f32 a[4]; f32 b[4]; };
extern V2 D_0035db20;
void func_002314c0(f32* s);  // 0x002314c0: definition moved into src/anon/unit_002302c0.cpp

struct E237 { u32 a; s32 lo; u32 b; s32 hi; u32 c; };
struct P237 { u32 pad[2]; E237* e; u16* idx; };
s32 func_00237578(P237* p, s32 i, s32 j);  // 0x00237578: definition moved into src/anon/unit_00237068.cpp

typedef void (*VFn2)(void*, void*);
extern void* D_0035ec84;
void func_0023fe28(void* a);  // 0x0023fe28: definition moved into src/anon/unit_0023f5b8.cpp

extern u8* D_0035f20c;
void func_00139d78(void*);
void func_00275ec8(u32 v);  // 0x00275ec8: definition moved into src/anon/unit_002748a0.cpp

void func_00281008(void*, void*);
void func_00280ef8(void*, void*);
void func_002810c8(void* a, void* b);  // 0x002810c8: definition moved into src/anon/unit_0027f2b0.cpp

void func_00281f40(void*, s32);
void func_00281f48(void*);  // memset_1920
void func_00281f70(void*);
void func_00281f90(void*);
void func_00281ec8(void* p);  // 0x00281ec8: definition moved into src/anon/unit_00281cf0.cpp

typedef s32 (*VFn3)(void*, void*, void*);
extern void* D_0035f3f8;
s32 func_0028cc08(void* a);  // 0028cc08: moved to src/anon/unit_0028c878.cpp

u8* func_00103eb0(void);
u8 func_00102a38(u32, void (*)(void));  // list_contains_id
void func_00293b08(void);
u32 ChgMember_isExec(void) asm("_ZN2Tz9ChgMember18isExecChangeMemberEv");
u32 ChgMember_isExec(void);  // 0x00293b70: definition moved into src/anon/unit_00292e60.cpp

struct E2bc { s32 v; s32 key; u32 c; };
s32 func_002bc9d8(u8* p, s32 key);  // 0x002bc9d8: definition moved into src/anon/unit_002bc978.cpp

void func_001780d8(void*, void*, void*);
void func_002c6c60(void*, u32);
void ObjCamera_start(u8*, void*, void*) asm("_ZN8worldmap9ObjCamera5startEPNS_6PlayerEPN2YS3PADE");
void ObjCamera_start(u8* self, void* pl, void* pad);  // 0x002c58c8: definition moved into src/anon/unit_002c53c8.cpp

extern u32 D_003626a8;
void func_002db530(void*);
void func_002db730(void** p);  // 0x002db730: definition moved into src/anon/unit_002da040.cpp

void func_002d10a0(void*);
void func_002dd790(u8* p);  // 0x002dd790: definition moved into src/anon/unit_002dd650.cpp

extern u32 D_00363c2c;
extern u32 D_00363c28;
extern u32 D_01e2c100;
void func_002f1a68(void);
void func_00168388(u32, void*, void (*)(void), s32);
void func_002f1a80(void) {
    D_00363c2c = 0;
    func_00168388(D_00363c28, &D_01e2c100, func_002f1a68, 0);
}

extern u32 D_00347e60;
void func_00239870(void*);
u8 func_0031a840(void*);
s32 func_0031a508(u8* p) {
    *(void**)p = &D_00347e60;
    func_00239870(p + 24);
    return func_0031a840(p);
}

void func_0031f940(u8* p) {
    void* o = *(void**)(p + 24);
    (*(VFn*)((*(u8**)o) + 16))(o);
}

extern u32 D_00351100;
void func_0031fec0(void*);
void func_0031fe88(void** p) {
    *p = &D_00351100;
    func_0031fec0(p);
    func_00105110(p);
}

extern u32 D_00362cc8;
void func_002dea80(void*);  // set_vtbl_362d20
void func_003255b8(void** p) {
    *p = &D_00362cc8;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}

}
