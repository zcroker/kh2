// Sub-object constructors of a big manager (00322e58 family): 48+1+2+3 408-byte elements, 6 436-byte elements.
// Built with -fno-strict-aliasing. The vtable-pointer stores are volatile (keeps the original store order).
#include "../common/types.h"
extern "C" {
void func_00239700(void*);
void func_0031a838(void*);
extern u8 D_00347f98[], D_00347e60[], D_00347e40[];

static inline __attribute__((always_inline)) void W1986_ctor436(u8* e)
{
    *(volatile u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void W1986_ctor408(u8* e)
{
    *(u32*)(e + 12) = 0; *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
}

static inline __attribute__((always_inline)) void H436(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void H408(u8* e, u32 b)
{
    *(u32*)(e + 12) = 0; *(volatile u32*)e = b; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void H436b(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(volatile u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
}
void func_00324510(u8* t)
{
    {
        u8* e = t;
        s32 i = 47;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    W1986_ctor408(t + 19584);
    {
        u8* e = t + 19992;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    u32 va = (u32)D_00347f98; u32 vb = (u32)D_00347e60;
    H408(t + 20808, vb);
    H408(t + 21216, vb);
    H408(t + 21624, vb);
    u8* m0 = t + 22032;
    u8* m1 = t + 22468;
    u8* m2 = t + 22904;
    u8* m3 = t + 23340;
    u8* m4 = t + 23776;
    u8* m5 = t + 24212;
    H436(m0, va, vb);
    H436(m1, va, vb);
    H436(m2, va, vb);
    H436(m3, va, vb);
    H436(m4, va, vb);
    H436b(m5, va, vb);
}
}
