#include "../common/types.h"
// func_002405a8: build the memory-card save title (Shift-JIS) for slot `slot`:
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
s32 func_002ff3fc(const char*);
void func_002fdd68(void*, const void*, u32);
s32 func_00240108(void);
s32 W3800_GetGameLevel(W3800_SaveRam*) asm("_ZN7SAVERAM12GetGameLevelEPv");
W3800_SaveRam* W3800_getSaveRam(void) asm("_Z10getSaveRamv");
s32 W3800_isGameComplete(W3800_SaveRam*) asm("_ZN7SAVERAM14isGameCompleteEv");
W3800_Item* W3800_ctarget(void*, u32) asm("_Z16ctarget_00188fe0jjjj");
void W3800_getPlayTime(u32*, u32*, u32*, u32*) asm("_ZN2dk5Clock18getPlayTimeToHMSMSERjS1_S1_S1_");

extern W3800_SaveRam D_0032bb30;
extern const char* D_0035ec0c;
extern const char* D_0035ec10;
extern const char* D_0035ec14;
extern const char* D_0035ec18[];
extern const char* D_0035ec28;
extern const char* D_0035ec2c;

void func_002405a8(char* buf, s32 slot)
{
    W3800_SaveRam* save = &D_0032bb30;
    W3800_memset(buf, 0, 0x40);
    s32 r = func_002ff3fc(D_0035ec0c);
    s32 len;
    {
        // Partial asm: argument pins plus a hand-written copy of the length so the
        // copy into its saved register fills the call's delay slot like the original.
        register char* a0 asm("$4") = buf;
        register s32 a2 asm("$6") = r;
        asm("" : "+r"(a2) : "r"(a0));
        asm("move %0,$2" : "=r"(len) : "r"(a0), "r"(a2));
        func_002fdd68(a0, D_0035ec0c, a2);
    }
    if (func_00240108() == 0) {
        func_002fdd68(buf + len - 4, D_0035ec18[W3800_GetGameLevel(save)], 2);
        if (W3800_isGameComplete(W3800_getSaveRam())) {
            func_002fdd68(buf + len - 2, D_0035ec2c, 2);
        }
    }
    if (func_00240108()) {
        func_002fdd68(buf + len, D_0035ec14, len);
        return;
    }
    register char* line asm("$16") = buf + len; // pin: keeps the digit cursor in s1
    func_002fdd68(line, D_0035ec10, len);
    char* p = line + 3;
    s32 v;
    u32 u;
    v = slot / 10; if (v) { *p = v + *p; }
    p += 2;
    v = slot % 10; if (v) { *p = v + *p; }
    p += 8;
    W3800_Item* item;
    if ((u8)save->flag0) item = W3800_ctarget(save->items, 14);
    else item = W3800_ctarget(save->items, 1);
    s32 n = item->count;
    v = n / 10; if (v) { *p = v + *p; }
    p += 2;
    v = n % 10; if (v) { *p = v + *p; }
    u32 h, m, s, ms;
    W3800_getPlayTime(&h, &m, &s, &ms);
    p += 4;
    u32 hour = h;
    s32 big = 0;
    u = hour / 100; if (u) { *p = u + *p; big = 1; } else { func_002fdd68(p - 1, D_0035ec28, 2); }
    hour %= 100;
    p += 2;
    u = hour / 10; if (u || big) { *p = u + *p; } else { func_002fdd68(p - 1, D_0035ec28, 2); }
    p += 2;
    v = hour % 10; if (v) { *p = v + *p; }
    p += 4;
    v = m / 10; if (v) { *p = v + *p; }
    p += 2;
    v = m % 10; if (v) { *p = v + *p; asm("" : "+r"(p)); } // empty asm: register-allocation nudge only
}

}
