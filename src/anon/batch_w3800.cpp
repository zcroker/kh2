#include "../common/types.h"
// Tz__MCard__MakeTitle: build the memory-card save title (Shift-JIS) for slot `slot`:
// header text, game level / completion marks, slot number, item count and play time
// (hours, minutes) added into the template's fullwidth digit characters.

struct W3800_SaveRam {
    u8 pad0[0x249c];
    u32 flag0 : 1;
    u32 : 31;
    u8 pad24a0[0x24f0 - 0x24a0];
    u8 items[1];
};

struct W3800_Item {
    u8 pad0[0xf];
    u8 count;
};

extern "C" {
void W3800_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
s32 strlen(const char*);
void memcpy(void*, const void*, u32);
s32 func_00240108(void);
s32 W3800_GetGameLevel(W3800_SaveRam*) asm("_ZN7SAVERAM12GetGameLevelEPv");
W3800_SaveRam* W3800_getSaveRam(void) asm("_Z10getSaveRamv");
s32 W3800_isGameComplete(W3800_SaveRam*) asm("_ZN7SAVERAM14isGameCompleteEv");
W3800_Item* W3800_ctarget(void*, u32) asm("_Z31YS__SAVERAM_BATTLE__get_partramjjjj");
void W3800_getPlayTime(u32*, u32*, u32*, u32*) asm("_ZN2dk5Clock18getPlayTimeToHMSMSERjS1_S1_S1_");

extern W3800_SaveRam D_0032bb30;
extern const char* D_0035ec0c;
extern const char* D_0035ec10;
extern const char* D_0035ec14;
extern const char* D_0035ec18[];
extern const char* D_0035ec28;
extern const char* D_0035ec2c;

void Tz__MCard__MakeTitle(char* buf, s32 slot);  // 0x002405a8: definition moved into src/anon/unit_0023f5b8.cpp

}
