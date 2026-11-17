#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

typedef void (*VFnF)(void*, f32);
typedef u32 (*VFn4)(void*, u32, u32, u32);

struct E16 { u32 w[4]; ~E16() {} } __attribute__((aligned(16)));
struct LimitEntry { u8 pad[40]; u16 id; u8 pad2[22]; };
struct LimitTbl { u32 f0; s32 count; LimitEntry e[1]; };
struct Flag250 { u8 pad[592]; u32 on:1; u32 rest:31; };
struct Tri { u32 a, b, c; };
struct W3 { u32 w[3]; };
struct FPParts { u32 w[8]; };

extern "C" {
void createTask(void) asm("_ZN2dk9ObjCamera10createTaskEv");
void camera_task(void) asm("_ZN2dk11camera_taskEP4TASK");
u32 isManual(u64* pad) asm("_ZN2dk12CameraConfig8isManualEPN2YS3PADE");
u32 isCameraAuto(void) asm("_ZN2Tz6Config12isCameraAutoEv");
void* anim_getNext(void* w) asm("_ZNK2kn13AnimationWork7getNextEv");
u32* party_get_ability(u32 p) asm("_ZN2YS5PARTY11get_abilityEv");
u32 trap_obj_add_hp(u32* v) asm("_ZN2YS15trap_obj_add_hpEP8BD_VALUE");
void wtarget_00146730(u32 a, u32 b) asm("_Z16wtarget_00146730jjjj");
u32 progress_CheckFlag(s32 f) asm("_ZN2YS8PROGRESS9CheckFlagEi");
u8* ctarget_00198bd0(s32 a, s32 b) asm("_Z16ctarget_00198bd0jjjj");
LimitEntry* GetLimitEntry(s32 id) asm("_ZN2Tz6JmInfo13GetLimitEntryEz");
u32 ctarget_001d9228(s32 i) asm("_Z16ctarget_001d9228jjjj");
void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) asm("_Z16ctarget_001db8f8jjjj");
void ItemStat_ctor(u32* p) asm("_ZN2Tz8ItemStatC1Ev");
s32 SelCheck(s32 i) asm("_ZN2Tz10JmWorldSel8SelCheckEi");
void ctarget_002cf3f8(void) asm("_Z16ctarget_002cf3f8jjjj");
void wtarget_002eb460(u8* o, Q16* q) asm("_Z16wtarget_002eb460jjjj");

void func_0015ce90(void);  // zero_global_byte_g
void func_001069b8(u32);  // swap_global_word
void func_0013f558(void*);
u8* func_00102c80(void);
void func_00102788(u32, u32, u32, void*);
void func_00139858(u32);
void func_00139ab0(u32);
void func_00144b38(u32, E16*);
void func_001466b0(u32, E16*);  // mat4_transform_vecs
void func_0016bda8(Q16*, u32);
void func_0013dad0(void*);
void func_00192f78(void*);  // obj_init_float_const
void func_001ab750(u32, void*);
u8 func_001aafe8(u32, u32*, u32, u32, u32, u32, f32, f32);
void func_001acdc0(void*, u32, u32, u32, u32, u32);
void func_001ac310(void*);
u32 func_001dc9d0(u32);
void func_001d7cd0(void*);
u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001c23a8(u8*, u32, u32, u32, u32, u32, u32);
void func_00223e98(u32, u8*, u32, u32, f32, f32, u32);
u32 func_0022b688(u32);
void func_001391a8(u32, Q16*);  // vec_copy_at416_if_diff
void func_002251c8(u32);
u32 func_00139d78(u32);
void func_00239700(void*);
void func_0028d188(void*);
u8* func_00294000(u32);
s32 func_00295158(s32);
u8 func_002941a8(u8*);
void func_00292630(void);
void func_0029e430(void);
void func_00293c40(s32, u32);
void func_002925c0(void);
u8* func_002a9d68(void);
void func_002be340(u32);
u32 func_002be4a0(void);
void func_00102448(u32, u32);
void func_00106450(u32);
void func_001d86a0(u32, u32);
void func_002cfeb0(u32*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002cf280(void*, u32, u32);
void func_002e70b0(void*);
void func_00106420(void*);
u8 func_002cea28(void*);
void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
u32 __sfvwrite(u32, u32*);
void func_003147a0(void*, void*);
void* func_003141e8(void*, void*);
u64 func_003146c8(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);

extern u8 D_00348710[];
extern Q16 D_01c5f480;
extern u32 D_0032d7c0[][8];
extern u8 D_01c61b48[];
extern u32 D_01d49530[];
extern u8 D_00351468[];
extern LimitTbl* D_01d5ba28;
extern u8 D_00352a78[];
extern u32 D_00354688;
extern s32 D_0035468c;
extern u8* D_0035ec94;
extern u16 D_0035ef70;
extern u32 D_0035f07c;
extern u32 D_0035f078;
extern u8 D_00347e60[];
extern u8 D_0035f420[];
extern s8 D_0035f228;
extern s16 D_0035f5b6;
extern u32 D_00361fa4;
extern u32 D_00361fa0;
extern W3 D_00375a40;
extern u8 D_00362858[];
extern u8 D_00362dc8[];
extern u8 D_0034ee08[];

// Calls a virtual method (slot 5) with t on every animation work in o's list.
void func_0011ea40(u8* o, f32 t);  // 0x0011ea40: definition moved into src/anon/unit_0011c128.cpp

void createTask(void);  // 0x00140ce8: definition moved into src/anon/unit_0013fca8.cpp

void wtarget_00146730(u32 a, u32 b);  // 0x00146730: definition moved into src/anon/unit_00145600.cpp

void func_0014f4d8(void);  // 0x0014f4d8: definition moved into src/anon/unit_0014ecb8.cpp

// 00154ee8: moved to src/anon/unit_00153ea0.cpp
u32 func_00154ee8(u8* p);

// 001585a0: moved to src/harata/libdk/cameraconfig.cpp

// Ability bit test: v[0] = party's ability bit v[1] is set.
void func_00171a70(u32* v);  // 0x00171a70: definition moved into src/anon/unit_00170f58.cpp

u32 trap_obj_add_hp(u32* v);  // 0x00172ae0: definition moved into src/anon/unit_00171e58.cpp

void func_00173dc0(u32* v);  // 0x00173dc0: definition moved into src/anon/unit_00171e58.cpp

// Story progress flag test (0xffff = none).
// 00181500: moved to src/yasui/libys/progress.cpp

// 00198bd0: moved to src/anon/unit_00198b88.cpp

void func_001a2710(Flag250* p);  // 0x001a2710: definition moved into src/anon/unit_0019fb70.cpp

void func_001aa790(u32* p, u32 a);  // 0x001aa790: definition moved into src/anon/unit_001a9130.cpp

u8 func_001aa8a8(u32* p, u32 a, u32 b, u32 c, u32 d);  // 0x001aa8a8: definition moved into src/anon/unit_001a9130.cpp

// 001ad3e0: moved to src/anon/unit_001abb28.cpp

void func_001c2ba8(void);  // 0x001c2ba8: definition moved into src/anon/unit_001c2b58.cpp

void func_001c2ce8(u8* p);  // 0x001c2ce8: definition moved into src/anon/unit_001c2b58.cpp

// 0x001d44d8 GetLimitEntry: definition moved into src/anon/unit_001d3c08.cpp

u32 ctarget_001d9228(s32 i);  // 0x001d9228: definition moved into src/anon/unit_001d7458.cpp

void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c);  // 0x001db8f8: definition moved into src/anon/unit_001d9d00.cpp

// Replaces value a with b on every list node not flagged 0x200.
void func_001e01e8(u8* list, u32 a, u32 b);  // 0x001e01e8: definition moved into src/anon/unit_001deb58.cpp

void func_0020cf60(u32 a, u8* e);  // 0x0020cf60: definition moved into src/anon/unit_0020c580.cpp

u32 func_0022aef0(Q16* q);  // 0022aef0: moved to src/sasa/musical_input.cpp (linked unit)

// Any of the 99 32-byte entries has flag 0x10 set.
u32 func_00241a00(void);  // 0x00241a00: definition moved into src/anon/unit_0023f5b8.cpp

// Rank of bit n among the set bits of D_0035ef70 (-1 if not set).
s32 func_00257ff8(s32 n);  // 0x00257ff8: definition moved into src/anon/unit_00254020.cpp

u32 func_00258a30(void);  // 0x00258a30: definition moved into src/anon/unit_002588e8.cpp

// 0028d140: moved to src/anon/unit_0028c878.cpp

s32 SelCheck(s32 i);  // 0x002956c0: definition moved into src/anon/unit_00292e60.cpp

void func_0029e3e0(u32 a);  // 0x0029e3e0: definition moved into src/anon/unit_0029d008.cpp

// Sets bit n in the bitset at +136 (only if not already set).
void func_002ab258(u32 n);  // 0x002ab258: definition moved into src/anon/unit_002a99c8.cpp

void func_002bfd48(u32* p, u32 a);  // 0x002bfd48: definition moved into src/anon/unit_002bebd0.cpp

void ctarget_002cf3f8(void);  // 0x002cf3f8: definition moved into src/anon/unit_002cf260.cpp

void func_002d28f8(u32 x, u32 m, s32 i);  // 0x002d28f8: definition moved into src/anon/unit_002d2498.cpp

void func_002daa50(u32* p, u32 a, u32 b);  // 0x002daa50: definition moved into src/anon/unit_002da040.cpp

u8 func_002e0ec8(u8* p);  // 0x002e0ec8: definition moved into src/anon/unit_002de3c8.cpp

// 002eb460: moved to src/anon/unit_002eaf38.cpp

u32 func_002ffc08(u32 a, u32* p) {
    if (p[2] == 0) {
        p[1] = 0;
        return 0;
    }
    u32 r = __sfvwrite(a, p);
    p[2] = 0;
    p[1] = 0;
    return r;
}

// Soft-float double binary op (libgcc dp-bit style): unpack both, combine, pack.
u64 func_00314190(u64 a, u64 b) {  // double_add
    FPParts x, y;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_003141e8(&x, &y));
}

void func_00320290(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}
