#include "../common/types.h"
extern "C" {

/* 0029e430 (matches only with -g) */
s32 Tz_LoadDataIsFlushing(void) asm("_ZN2Tz18LoadDataIsFlushingEv");
void* Tz_MenuBase_GetMenuObj(void) asm("_ZN2Tz8MenuBase10GetMenuObjEv");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0023d820(void*);
void Tz_JMData_Clear(s32) asm("_ZN2Tz6JMData5ClearEi");
void Tz_JMData_Destroy(s32) asm("_ZN2Tz6JMData7DestroyEi");
extern void* D_0035f5bc;
extern s16 D_0035f5b6;
extern s8 D_0035f228;
void func_0029e430(void) {
    Tz_LoadDataIsFlushing();
    void* o = Tz_MenuBase_GetMenuObj();
    if (u_call4_00139d78(o)) func_0023d820(o);
    if (u_call4_00139d78(D_0035f5bc)) func_0023d820(D_0035f5bc);
    D_0035f5b6 = -1;
    if (D_0035f228 == 1) Tz_JMData_Destroy(5103);
    else Tz_JMData_Clear(5103);
}

}
