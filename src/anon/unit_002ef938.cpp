#include "../common/types.h"

// 0x2ef938-0x2efbb8: the "KH2S" save header (magic, region code, version, a random key and
// flags, then 152 words OR-ed from the save RAM). Linked unit.

s32 REGION_Get(void) asm("_ZN6REGION3GetEv");
u8* getSaveRam(void) asm("_Z10getSaveRamv");
s32 rand_n(s32) asm("_Z13func_001064a8Pv");
void memset_w(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");

struct SaveHeader2ef938 {
    u32 magic;        // 'KH2S'
    u16 region;
    u16 version;
    u8 key[8];
    u32 flags;        // bit 0: done, bits 1-31: seed
    u32 data[152];
};

extern "C" {

u16 func_002ef988(void);

void func_002ef938(SaveHeader2ef938* h) {
    h->magic = 0x5332484b;
    h->region = func_002ef988();
    h->version = 1;
    memset_w((u8*)h + 16, 0, 612);
}

u16 func_002ef988(void) {
    u16 r = 0x5355;
    switch (REGION_Get()) {
    case 2: break;
    case 1: case 8: r = 0x504a; break;
    default: r = 0x5545; break;
    }
    return r;
}

s32 func_002ef9e0(SaveHeader2ef938* h) {
    s32 r = 0;
    if (h->magic == 0x5332484b && h->region == func_002ef988())
        r = h->version == 1;
    return r;
}

s32 func_002efa40(SaveHeader2ef938* h) {
    s32 r = 0;
    if (func_002ef9e0(h))
    {
        u32 t = h->flags & 1;
        r = t != 0;
    }
    return r;
}

void func_002efa88(SaveHeader2ef938* h) {
    h->flags |= 1;
}

void func_002efa98(SaveHeader2ef938* h) {
    u8* k = h->key;
    s32 i = 7;
    do {
        *k = rand_n(255);
        i--;
        k++;
    } while (i >= 0);
    u32 v = rand_n(-1);
    h->flags = (h->flags & 1) | (v << 1);
}

void func_002efb08(SaveHeader2ef938* h) {
    u32* s = (u32*)(getSaveRam() + 7312);
    u32* d = h->data;
    u32 i;
    for (i = 0; i < 152; i++)
        *d++ |= *s++;
}

void func_002efb60(SaveHeader2ef938* h) {
    func_002efb08(h);
    func_002efa98(h);
}

void func_002efb88(SaveHeader2ef938* h, u32* out) {
    u32* s = h->data;
    s32 i;
    for (i = 151; i >= 0; i--)
        *out++ |= *s++;
}

}
