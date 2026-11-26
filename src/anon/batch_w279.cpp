#include "../common/types.h"
struct W279Vq {
    f32 x, y, z, w;
    W279Vq& operator=(const W279Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern "C" {
// ---- Tz__HEFT__DrawSelector
s32 func_00287cd0(void*);
s32 func_00289310(void*);
s32 func_002891e8(void*);
void func_002890e0(void*, s32, s32, s32, s32);
void func_00289038(void*, s32, s32, s32, s32, s32, s32);
s32 func_00244ee8(s32);
void func_0023f070(void*, s32, s32);
s32 func_0028d008(void*);
s32 func_002891d0(void*);
void Tz__MenuCursor__SetParent(void*, s32);  // record408_set_and_refresh
void func_002b4388(void*, void*, s32);
void Tz__HEFT__UpdateNewMark(void);
void func_00244b38(void);
extern void* D_0035ecf8;
extern void* D_0035ed08;
struct W279S6 { s16 a; s16 b; s16 c; };
extern W279S6 D_00371968[];
struct W279S36 { u8 x[36]; };
extern W279S36 D_003719a0[];
extern W279S36 D_003719e8[];
void Tz__HEFT__DrawSelector(void* a0, s32 a1, void* a2);  // 0x00244708: definition moved into src/anon/unit_00242478.cpp

// ---- func_0026b2c0
u8* item_get_info(void*) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 menu_get_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cmtop_get_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 cmtop_get_cur_pos(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
s32 jm_report_get_data(u32) asm("_ZN2Tz8JmReport7GetDataEj");
u8* party_get_sheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
u16* Tz__CmEquip__GetItemTbl(s32, s32);
u8* func_001a80c8(s32);  // table24_find_by_id
u8* YS__ITEM_TABLE__get_param(u8*);
extern void* D_0035f0ec;
extern u32 D_0035f01c;
extern void* D_0035f010;
union W279Slot { u16 raw; struct { u16 id : 15; u16 on : 1; } b; };
static inline u8 w279_stat(u16 id) {
    if (id == 0) return 0;
    return YS__ITEM_TABLE__get_param(func_001a80c8(id))[7];
}
s32 func_0026b2c0(void);  // 0x0026b2c0: definition moved into src/anon/unit_0026a900.cpp

// ---- YS__PLAYER__exec_barrier_effect
s32 map_is_pax_exist(void) asm("_ZN2dk3Map10isPaxExistEv");
void* map_get_pax(void) asm("_ZN2dk3Map6getPaxEv");
s32 effect_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
void effect_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
W279Vq* effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
W279Vq* effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
s32 pax_search_id(void*, u64) asm("_ZN3ryj3PAX9search_idEy");
void* ryj__PAX__start(void*, s32, s32, s32, s32, s32);  // scan_list_by_half
W279Vq octree_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
W279Vq YS__MATH__VectorToAngle(const W279Vq&);
extern f32 D_00349e10;
typedef void (*W279VFn1)(u8*, s32);
// 00179718: moved to src/yasui/libys/player.cpp

// ---- sa__EVENT__set_scale_seq
s32 sa__EVENT__checkStart(s32);
s32 sa__EVENT__getEventPriority(void);  // limit_15000_or_25000
u8* sa_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
void YS__OBJ__is_valid(u32);  // list_contains_ptr
s32 sa__EVENT__isJumpMode(s32);  // flag_query_by_index
u8* field_create_task(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* area_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
f32* tz_load_data_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
f32 sa_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
void func_0014f030(f32*, f32, f32, f32);  // obj_set_lerp_params
void func_0022e6b0(s32, u32, f32);
void func_0022e7e8(void*);
void func_0022e728(void*);
union W279H { s16 h; u8 c; };
union W279P { f32* p; u8 c; };
void sa__EVENT__set_scale_seq(u8* s);  // 0x0022e818: definition moved into src/anon/unit_0022d358.cpp

// ---- func_00100ec8
s32 func_001009a0(u8*);
s32 func_00100920(u8, void*);  // classify_subtype
void func_001004c0(u8, s32, u32*, u32*);
u32 func_001003c8(u8);  // classify_arg_masked3
struct W279Obj { u32 min; u32 pad[3]; u64 lo : 2; u64 dirty : 1; u64 id : 8; u64 rest : 53; };
s32 func_00100ec8(W279Obj* obj, u32* list);  // 0x00100ec8: definition moved into src/libgcc/unwind-dw2-fde.c

// ---- __d2b
struct W279Big { W279Big* next; s32 k, maxwds, sign, wds; u32 x[1]; };
W279Big* w279_balloc(void*, s32) asm("_Z7_Ballocjjjj");
s32 func_00303e80(u32);  // count_leading_zeros
s32 func_00303f00(u32*);
union W279Dbl { double d; u32 w[2]; };
W279Big* __d2b(void* ptr, double dd, s32* e, s32* bits);  // 0x003048b8: definition moved into src/newlib/libc/mprec.c
}
