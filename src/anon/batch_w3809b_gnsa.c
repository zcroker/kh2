// Builds the entry list at D_0035f230 from 80 source slots (filtered by category/flag), finds each entry's position, then counts entries per category.
// Partial inline asm: an empty memory barrier after the hi-bit test and an empty asm use of n after the loop (register order).
#include "../common/types.h"
u8* func_002859a0(void);
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
u8* func_00281180(u32, s32);
u8* func_001a80c8(s32);
s32 func_002811b0(u32, s32);
s32 func_001b7818(s32);
void func_00279620(void);
void func_002793b0(void);
void func_00279860(void);
void func_002799b0(void);
void func_00279a10(void);
typedef struct Ent_00279040 { u16 id; u8 hi; u8 idx; s8 cat; u8 b5; s8 b6; s8 pos; } Ent_00279040;
typedef struct Hdr_00279040 { u16 h0; u16 h2; u8 pad4[3]; s8 count; u8 cnt[4]; Ent_00279040 e[1]; } Hdr_00279040;
extern Hdr_00279040* D_0035f230;
extern u32 D_0035f010;
extern u32 D_0035f01c;

void func_00279040(void) {
    s32 sp0, sp4;
    u8* base = func_002859a0();
    s32 v;
    s32 who;
    u16* src;
    s32 i, n, k;
    if (func_00287bc0() == 15) v = func_0028b040(D_0035f01c);
    else v = func_002570a0(15);
    func_0027aed8(v, &sp0, &sp4);
    who = 0;
    if (sp0 == 0) who = sp4;
    n = 0;
    i = 0;
    src = (u16*)(*(u32*)(func_00281180(D_0035f010, who) + 580) + 80);
    D_0035f230->h2 = *(u16*)(func_00281180(D_0035f010, who) + 398);
    for (i = 0; i < 80; i++, src++) {
        u16 id = src[2] & 0x7fff;
        u8* info;
        Ent_00279040* e;
        if (id == 0) continue;
        info = func_001a80c8(id);
        if (sp0 != 0) {
            if (info[6] != 0) continue;
            if (!(src[2] >> 15)) continue;
            asm("" ::: "memory");
        }
        D_0035f230->e[n].id = src[2] & 0x7fff;
        D_0035f230->e[n].hi = src[2] >> 15;
        D_0035f230->e[n].idx = i;
        if (who == 0) {
            u16* t = (u16*)(base + 208);
            for (k = 0; k < 80; k++) {
                if (t[k] == D_0035f230->e[n].id) break;
            }
            if (k < 80) D_0035f230->e[n].pos = k; else D_0035f230->e[n].pos = -1;
        } else {
            s32 row = func_001b7818(func_002811b0(D_0035f010, who)) - 2;
            u16* t = (u16*)(row * 96 + (u32)base + 368);
            for (k = 0; k < 48; k++) {
                if (t[k] == D_0035f230->e[n].id) break;
            }
            if (k < 48) D_0035f230->e[n].pos = k; else D_0035f230->e[n].pos = -1;
        }
        switch (info[6]) {
        case 0: D_0035f230->e[n].cat = 2; break;
        case 1: case 2: D_0035f230->e[n].cat = 0; break;
        case 3: D_0035f230->e[n].cat = 1; break;
        }
        D_0035f230->e[n].b5 = info[7];
        D_0035f230->e[n].b6 = -1;
        n++;
    }
    asm("" :: "r"(n));
    D_0035f230->count = n;
    func_00279620();
    func_002793b0();
    func_00279860();
    func_002799b0();
    for (i = 0; i < 4; i++) D_0035f230->cnt[i] = 0;
    for (i = 0; i < D_0035f230->count; i++) D_0035f230->cnt[D_0035f230->e[i].cat]++;
    func_00279a10();
}

