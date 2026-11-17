#include "../common/types.h"

// 001be778
struct W22Menu { u8 pad[1]; };
struct W22PC { u8 pad[0x2dc]; W22Menu menu; u8 pad2[0x358 - 0x2dd]; s32 f358; };

extern "C" {

s32 PC_is_override_top(W22PC*) asm("_ZN2YS14PLAYER_COMMAND15is_override_topEv");
void Menu_clear(W22Menu*) asm("_ZN2YS12COMMAND_MENU5clearEv");
s32 Summon_GetMode() asm("_ZN2YS6SUMMON7GetModeEv");
s32 Summon_GetCurrent() asm("_ZN2YS6SUMMON10GetCurrentEv");
s32 func_001819c0();
s32 func_00181a18();
void func_001be890(W22PC*, W22Menu*);
void func_001bf010(W22PC*);
void func_001be540(W22PC*, W22Menu*);
void func_001bc780(W22Menu*, s32, s32, s32);

void func_001be778(W22PC* p);  // 0x001be778: definition moved into src/anon/unit_001bc568.cpp

}
