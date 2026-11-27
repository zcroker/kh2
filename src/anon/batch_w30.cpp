#include "../common/types.h"

extern "C" {
void func_00139858(s32);
void func_00139ab0(s32);
extern u8* D_003484a0;
s16 func_00147050(u32, u32, void*, u32, void*);  // entry48_process_5args
extern u32 D_00348800;
void func_001398d0(s32);
void func_00139a38(s32);
void YS__OBJ__get_lightcycle_movement(void*, u32, u32, f32);
extern u8 D_01c5f480[16];
u32 func_00106a60(s32);  // buffer_get_by_index
void func_00107478(u32, void*);  // vec_copy_at96_if_diff
u32 func_002cd1d8(void*, u32);
void Ti__Path__reset_active_path(u32, void*, u32);
void func_00192f78(void*);  // obj_init_float_const
void func_001ab750(u32, void*);
extern s32* D_01c94040[];
extern void* D_01c9408c;
s32 func_001a4ff8(void*, void*);
u8* func_00321728(void*, s32, u32);
void func_001d4f40(void*, u32, u32);
void func_001d7b10(u32, u32);
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32);
extern u8 D_00352a78[];
extern u64 D_01da8bb0[];
extern u64 D_00359940[];
extern u32 D_003591c8;
void sceGsSyncPath(u32, u32);
u8 func_002f3918(u32, void*);
extern u8 D_0035de54;
extern s32 D_0035de20;
extern s32 D_0035de5c;
void* func_0022b688(u32);
void func_001391a8(void*, void*);  // vec_copy_at416_if_diff
void func_002251c8(u32);
u32 func_001064a8(s32);  // int_to_float_scaled
extern u16 D_0035f0a8[3];
void YS__SHEET__Free(u32);
u8* func_00103eb0(void);
u8* TASK_MANAGER__create_thread(u32, u32, u32, void*, u32);
void func_00292608(void*) asm("_ZN2Tz8LoadData9FlushTaskEP4TASK");
void func_00292620(void);
u32* func_002a9d68(void);
void func_002b7fbc(u32);
void func_002bce40(void*);
void SE_BANK__clearField(void*);
void func_002b9b78(void);
void func_002ba390(void);
void func_002b9ed0(void);
extern u8 D_01e2a410[];
void func_002baa78(void);
void func_002bcfe8(void*);
void func_002bd030(void*);
void func_002bd078(void*);
void func_002bd0b8(void*);
void func_002bd100(void*);
void func_002bd140(void*);
extern u8 D_01e2a568[];
extern u8 D_00374f70[];
void func_002fee78(void*, void*, u32);
void strlen(void*);  // strlen
extern u8 D_0034ee08[];
void YS__OBJ_ATTACK__clear(void*);  // array8_free_slots
void func_001c0248(void*);
u8 func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);
void* func_001050d8(u32);
void* Ti__MGOarashi__MGOarashi(void*, u32, u32);
void func_002cfeb0(void*, u32, u32, u32);  // obj_init_field1416_bit800
extern u8 D_00362858[];
void func_002cf280(void*, u32, u32);
extern u8 D_00362eb8[];
void func_002e70b0(void*);
void func_00106420(void*);
u8 func_002cea28(void*);
void func_00195858(void*, u32);
extern void* D_00347f98[];
extern void** D_00347f80;
extern u8 D_0035eb98[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
void func_0023ee68(void*);
}

extern "C" {
void dk__COMMAND_DRAW__on(u32, u32, u32, u32) asm("_Z20dk__COMMAND_DRAW__onjjjj");
void wtarget_00185050(u32, u32, u32, u32) asm("_Z16wtarget_00185050jjjj");
void wtarget_001d7a08(u32, u32, u32, u32) asm("_Z16wtarget_001d7a08jjjj");
// YS::trap_camera_at(BD_VALUE*)
void trap_camera_at(void**) asm("_ZN2YS14trap_camera_atEP8BD_VALUE");
void func_00281008_impl(void*) asm("_Z13func_00281008Pv");
}

void dk__COMMAND_DRAW__on(u32, u32, u32, u32);  // 0x0013b4b0: definition moved into src/anon/unit_0013a8b8.cpp

// 00185050: moved to src/anon/unit_00183088.cpp

// Clears the first of four slots whose id matches.
void wtarget_001d7a08(u32 a, u32 b, u32, u32);  // 0x001d7a08: definition moved into src/anon/unit_001d7458.cpp

void trap_camera_at(void** v);  // 0x00174d98: definition moved into src/anon/unit_00171e58.cpp

void func_00281008_impl(void* p);  // 0x00281008: definition moved into src/anon/unit_0027f2b0.cpp

namespace Tz {
void LoadDataFlush();
}
// 002925c0: moved to src/anon/unit_00290f78.cpp

static inline bool in_1_6(s32 a) { return a != 0 && a < 7; }

extern "C" {

void func_00143348(u8* p);  // 0x00143348: definition moved into src/anon/unit_00142c90.cpp

// GS SCISSOR register value from x/y/w/h.
void func_0014b950(u8* p, s16 x, s16 y, u16 w, u16 h);  // 0x0014b950: definition moved into src/anon/unit_0014b838.cpp

void dk__INFORMATION__off(void);  // 0x0014f528: definition moved into src/anon/unit_0014ecb8.cpp

// dot(a.xyz, b.xyz) + b.w -> *out; returns 1 when it is <= a[4].
s32 func_00162b68(f32* a, f32* b, f32* out);  // 0x00162b68: definition moved into src/anon/unit_001614e8.cpp

void func_00171ea8(u8* p);  // 0x00171ea8: definition moved into src/anon/unit_00171e58.cpp

struct E19f740 {
    u32 a;
    s32 b;
    u8 c;
};

// 1 if one of the 8 entries matches a and b (-1 = any b) and is not flagged.
s32 func_0019f740(E19f740* e, u32 a, s32 b);  // 0x0019f740: definition moved into src/anon/unit_0019ee80.cpp

struct Q3 {
    u32 a, b, c;
};

void func_001aa7f0(u32* p, u32 a);  // 0x001aa7f0: definition moved into src/anon/unit_001a9130.cpp

void func_001aebf0(u8* a);  // 0x001aebf0: definition moved into src/anon/unit_001ada38.cpp

struct F28 {
    u8 pad[0x28];
    u32 on : 1;
};

// 001c7950: moved to src/anon/unit_001c7148.cpp (linked unit)

u8 func_001c9958(s32 a, s32 b);  // 0x001c9958: definition moved into src/yasui/libys/sacrifice.cpp

void func_001d4ef0(u8* p, u8* a);  // 0x001d4ef0: definition moved into src/anon/unit_001d3c08.cpp

void func_001db950(u8* p, u32 a, u32 b, u32 c);  // 0x001db950: definition moved into src/anon/unit_001d9d00.cpp

s32 func_0020f188(void);  // 0x0020f188: definition moved into src/anon/unit_0020f118.cpp

u8 sa__EVENT__isJumpMode(s32 n);  // 0x00225b00: definition moved into src/anon/unit_00224780.cpp

void* sa__MUSICAL_INPUT__BadPrint(u8* p);  // 0022af48: moved to src/sasa/musical_input.cpp (linked unit)

void func_00242088(u8* p);  // 0x00242088: definition moved into src/anon/unit_00241fd0.cpp

void func_00258ce8(u16* a);  // 0x00258ce8: definition moved into src/anon/unit_002588e8.cpp

// Sets bit n in the bitmap returned by func_002a9d68.
void func_002aa048(u32 n);  // 0x002aa048: definition moved into src/anon/unit_002a99c8.cpp

void func_002b9e80(void);  // 0x002b9e80: definition moved into src/anon/unit_002b9ab8.cpp

void func_002b9ed0(void);  // 0x002b9ed0: definition moved into src/anon/unit_002b9ab8.cpp

void* func_002ba0b0(u32 a);  // 0x002ba0b0: definition moved into src/anon/unit_002b9ab8.cpp

// Deleting destructor.
void func_002d0028(u8* p);  // 0x002d0028: definition moved into src/anon/unit_002cf260.cpp

void* func_002d1270(u32 a, u32 b);  // 0x002d1270: definition moved into src/anon/unit_002cf260.cpp

void Ti__MGHachimitsuGimObj__MGHachimitsuGimObj(u8* p, u32 a, u32 b);  // 0x002daa98: definition moved into src/anon/unit_002da040.cpp

// 002e2240: moved to src/anon/unit_002e1908.cpp

void func_002ecdf8(u8* p, u8* a);  // 0x002ecdf8: definition moved into src/anon/unit_002ecdb0.cpp

struct FpNum {
    s32 cls;
    u32 sign;
    s32 exp;
    u64 frac;
};
void func_003147a0(void*, FpNum*);
f32 func_00314698(s32, u32, s32, u32);

// Software double -> float (libgcc fp-bit __truncdfsf2).
f32 __truncdfsf2(u64 a);  // 0x003144b0: definition moved into src/libgcc/_df_to_sf.c

void func_0031ae18(void** p);  // 0x0031ae18: definition moved into src/anon/unit_003197d0.cpp

s32 func_0031eb68(u8* p);  // 0x0031eb68: definition moved into src/anon/unit_0031e268.cpp

void func_00320bc0(u8* p);  // 0x00320bc0: definition moved into src/anon/unit_00320528.cpp

void func_00322db8(u8* p);  // 0x00322db8: definition moved into src/anon/unit_00321728.cpp

}
