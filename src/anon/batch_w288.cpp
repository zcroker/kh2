#include "../common/types.h"
extern "C" {
struct Blk_d7128 { u32 a; u32 b; u32 data; };
extern char D_003625a8[];
extern char D_00375b68[];
extern char D_00362570[];
void func_002ce958(void*, s32, u32, s32);
void f2e34b8(void*) asm("_Z13func_002e34b8Pv");
void mg_make_data_path(void*, char*, char*) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
void* cb_alloc(char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Blk_d7128* func_00168b38(void*, s32, s32);  // entry_array_find_nth
void f2e34c0(void*, u32) asm("_Z13func_002e34c0Pvi");
void* func_002e34c8(void*);  // obj_get_field8_by_vtable
void* area_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
void* tz_load_data_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void Ti__Afp__Afp(void*, u32);
char* getFieldMode_(void) asm("_Z12getFieldModev");
void func_002d7630(void*);
void Ti__MiniGame__create_task(s32, void*);
struct MG_d7128 {
    u32 vt; u8 p0[88]; u32 f5c; void* f60; f32 f64; u32 f68; u8 p1[40]; void* f94; u32 f98; u32 f9c; void* fa0;
    u8 p2[24]; u32 fbc; u8 p3[12]; u32 fcc; u8 p4[256]; u8 f1d0; u8 f1d1; u8 f1d2; u8 p5[9]; u32 f1dc;
};
void Ti__MGHachimitsu__MGHachimitsu(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z30Ti__MGHachimitsu__MGHachimitsujjjj");
void Ti__MGHachimitsu__MGHachimitsu(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002d7128: definition moved into src/anon/unit_002d6f70.cpp

// --- 0028f4d8
struct Lay { u8 p[40]; void* f28; };
extern u32 D_0035f480;
#define BASE ((u8*)D_0035f480)
extern u32 D_0035f460;
extern s32 D_0035f45c;
extern s32 D_0035f458;
extern s32 D_0035f3d4;
extern s16 D_0035f470[];
extern s16 D_0035f468[];
extern u8 D_0035f478[];
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
Lay* tz_getLayout(void*) asm("_ZN2Tz6Layout9getLayoutEv");
void* yi_GetSequenceUnit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
void* yi_GetImage(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void dk_SpriteMessage_create(void*, s32, void*, void*, s32, void*, s32) asm("_ZN2dk13SpriteMessage6createEiPvPN2YI5IMAGEEiPKN2YS7MESSAGEEii");
s32 yi_GetParamEx(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void dk_setOffsetPos(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void dk_getSeqPraramXYOff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void tz_SetMsgId(s32, s32) asm("_ZN2Tz7SelHist8SetMsgIdEii");
void Tz__LightCur__Create(void*, s32, s32, s32, void*, void*, s32);
void func_0028d660(void*, void*);  // record_set_value_refresh
struct Ent884 { u8 p[436]; u8 sub[444]; u32 f880; };
void func_0028f4d8(s32 idx, s32 msg, u8 sel);  // 0028f4d8: moved to src/anon/unit_0028f1e0.cpp
}
