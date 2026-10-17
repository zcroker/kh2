#include "../common/types.h"
extern "C" {

void func_00239700(void*);
void func_0031a838(void*);
extern u8 D_00347f98[], D_00347e60[];

// --------------------
// 00322e58: constructor of an object made of six 436-byte elements followed by
// sixteen 408-byte elements. Element constructors written out inline:
//   Elem436: 00347f98 base (func_0031a838 at +12) -> vt 00347e60 (func_00239700 at +24)
//            -> vt 00347e40, word at +408 cleared
//   Elem408: vt 00347e60, word at +12 cleared, func_00239700 at +24
extern u8 D_00347e40[];

static inline __attribute__((always_inline)) void W1628_ctor436(u8* e)
{
    *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(u32*)e = (u32)D_00347e40;
}

void func_00322e58(u8* t)
{
    u8* m = t + 436;
    W1628_ctor436(t);
    W1628_ctor436(m);
    {
        u8* e = m + 436;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 2616;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 4360;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 6104;
        s32 i = 3;
        for (; i != -1; i--, e += 436) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
        }
    }
    {
        u8* e = t + 7848;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 9480;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 11112;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 12744;
        s32 i = 3;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
}
}
