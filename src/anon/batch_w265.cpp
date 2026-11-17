#include "../common/types.h"
struct V265q { f32 v[4]; ~V265q() {} } __attribute__((aligned(16)));
extern "C" {
extern u8* D_0035f5b0;
s32 func_00139d78(void*);
void func_00139510(void*);
struct W265Sub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); u8 pad[432]; };
struct W265Big { u8 pad[1744]; W265Sub arr[10]; };
void func_0029ac00(void);  // 0x0029ac00: definition moved into src/anon/unit_00299920.cpp
struct I265 { s32 id; s32 b; s32 c; s32 n; s32 x; s32 y; };
struct O265 { u8 pad[64]; s32 h; u8 pad2[260]; s32 x; s32 y; u8 pad3[8]; };
struct P265 { u8 pad[16]; u8* tbl; u8* recs; u8 pad2[24]; O265* objs; s32 cnt; s32 st; u8 padx[4]; f32 lim; u8 pad3[8]; s32 sel; u8 pad4[4]; s32 dx; s32 dy; };
void func_00236d60(void);  // clear_64_entries_24
void func_00236830(s32);
void func_0023ade0(O265*);
void func_002367a0(void);
void func_0023cc18(P265* p);  // 0x0023cc18: definition moved into src/anon/unit_0023c968.cpp
extern char D_0036cbc0[];
void func_0017f488(u8*, s32, f32, f32);
s32 func_0019ba60(u8*);
s32 func_001b0498(u8*);  // obj_check_ready_flags
void func_001b0700(u8*, f32);
void func_0018c438(u8*);
s32 func_001883d8(u8*, const char*);
void func_001880b0(u8*, const char*);
struct Q265g { u8 pad[8]; u8* t; u8 pad1[2620]; s32 a; u8 pad2[180]; f32 f2816; u32 b0 : 1; u32 rest : 31; Q265g* o; };
void func_0018b338(Q265g* p, f32 x);  // 0x0018b338: definition moved into src/yasui/libys/npc.cpp
extern u8 D_00361aa0[];
extern u8* D_00361a90;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_00347f80;
void func_00170950(u32);
void func_00239870(u8*);
void func_0023c098(u8*);  // set_vtbl_36eae8_then_call
void func_002369f0(u8*);  // set_vtbl_36eac8_then_call
typedef void (*VF265)(u8*);
typedef void (*VF265b)(u8*, u8*);
void func_002c1320(u8* p);  // 0x002c1320: definition moved into src/anon/unit_002c10e0.cpp
struct N265q { u8 pad[208]; u8 d[40]; u32 fl; V265q* mp; u8 pad2[16]; N265q* next; };
struct Y265q { u8 pad[44]; N265q* head; };
void func_001471d8(u8*, N265q*);
void func_00147210(u8*, N265q*);
void func_00144b38(u8*, V265q*);
s32 func_001466b0(u8*, V265q*);  // mat4_transform_vecs
void func_00146250(u8* a, Y265q* y);  // 0x00146250: definition moved into src/anon/unit_00145600.cpp
}
