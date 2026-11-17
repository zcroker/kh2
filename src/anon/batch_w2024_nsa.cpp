#include "../common/types.h"
struct W2024c_V4 { f32 x, y, z, w; W2024c_V4() {} W2024c_V4(const W2024c_V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
struct W2024c_Ent { u8 pad[8]; s32 h; };
struct W2024c_P3 { s32 a; s32 b; f32 c; };
struct W2024c_Tk { u8 pad[4]; s32 f4; W2024c_P3* p0; W2024c_P3* p1; W2024c_P3* p2; u8 pad2[0x1c]; void* f30; };
struct W2024c_Ev { u8 pad[4]; s16 id; u16 key; u8 v0[0x24]; u16 n; };
f32 W2024c_ev_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
W2024c_Ent* W2024c_ev_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
W2024c_Tk* W2024c_field_create_task(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* W2024c_area_get_alloc(void) asm("_ZN4AREA12GetAllocatorEv");
W2024c_P3* W2024c_tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
extern "C" {
s32 func_002282f0(u16);
s32 func_00225b00(u16);
void func_001ba028(s32);
void func_0016adc8(s32, W2024c_V4);
void func_0022f6b8(s32, W2024c_V4*);
s32 func_002282d8(void);
void func_002309c8(void*);
void func_00230ae8(void*);
void func_0014f030(W2024c_P3*, f32, f32, f32);
void func_00230b50(W2024c_Ev* e);  // 0x00230b50: definition moved into src/anon/unit_002302c0.cpp
}
