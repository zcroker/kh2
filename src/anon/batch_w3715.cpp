#include "../common/types.h"
extern "C" {

// --------------------
// 0031b130: constructor of a big object (0x3cf0 bytes) built from many embedded
// sub-objects and arrays. Each element constructor is written out inline; vtables
// are stored as plain words (the classes' vtables live in the original binary).
//   Elem408 (vt 00347e60): word at +12 cleared, sub-object at +24 (func_00239700)
//   Elem848 : 00347f98 base (func_0031a838 at +12) -> 00347e60 -> 0034a800, YI::IMAGE at +416
//   Elem412 : same chain ending in vt 0034a958
//   Elem592 : 00347f98 base -> vt 00348658, sub-objects at +32 (func_0013ee88), +320 (func_0014b668)
void func_00239700(void*);
void func_002361a0(void*);
void func_0031a838(void*);
void func_0013ee88(void*);
void func_0014b668(void*);
extern u8 D_00347f98[], D_00347e60[], D_00348608[], D_0034a800[], D_0034a920[], D_0034a958[],
    D_00348678[], D_00348658[];

void func_0031b130(u8* t)
{
    *(u32*)(t + 64) = (u32)D_00347f98;
    *(u32*)t = (u32)D_00348608;
    *(u32*)(t + 12) = 0;
    func_0031a838(t + 76);
    *(u32*)(t + 64) = (u32)D_00347e60;
    func_00239700(t + 88);
    *(u32*)(t + 64) = (u32)D_0034a800;
    func_002361a0(t + 480);
    *(u32*)(t + 928) = 0;
    *(u32*)(t + 916) = (u32)D_00347e60;
    *(u32*)t = (u32)D_0034a920;
    func_00239700(t + 940);
    *(u32*)(t + 1336) = 0;
    *(u32*)(t + 1324) = (u32)D_00347e60;
    func_00239700(t + 1348);
    {
        u8* e = t + 1732;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 2548;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 3364;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 4180;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    {
        u8* e = t + 5008;
        s32 i = 1;
        for (; i != -1; i--, e += 848) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_0034a800; func_002361a0(e + 416);
        }
    }
    {
        u8* e = t + 6704;
        s32 i = 14;
        for (; i != -1; i--, e += 412) {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
            *(u32*)e = (u32)D_0034a958;
        }
    }
    *(u32*)(t + 12908) = 0;
    *(u32*)(t + 12896) = (u32)D_00348678;
    {
        u8* e = t + 13232;
        s32 i = 3;
        func_0013ee88(t + 12928);
        // The original loads the loop bound right after this call, ahead of the vtable addresses.
        s32 n; asm volatile("li %0,-1" : "=r"(n));
        do {
            *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
            *(u32*)e = (u32)D_00348658; func_0013ee88(e + 32);
            func_0014b668(e + 320);
            i--; e += 592;
        } while (i != n);
    }
}

}
