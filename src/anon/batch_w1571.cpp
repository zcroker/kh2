#include "../common/types.h"
extern "C" {
void func_0031a838(void*);
void func_00239700(void*);
extern u8 D_00347e40[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
static inline void c3237e0_A(u8* p) { *(void**)p = D_00347f98; func_0031a838(p + 0xc); }
static inline void cB(u8* p) { c3237e0_A(p); *(void**)p = D_00347e60; func_00239700(p + 0x18); }
static inline void cC(u8* p) { cB(p); *(void**)p = D_00347e40; *(u32*)(p + 0x198) = 0; }
static inline void cD(u8* p) { *(u32*)(p + 0xc) = 0; *(void**)p = D_00347e60; func_00239700(p + 0x18); }
void func_003237e0(u8* p);  // 0x003237e0: definition moved into src/anon/unit_00321728.cpp
// Static init/destroy (priority 0xffff); the empty destructor loop gets the r5900 short-loop nop padding.
void func_0031e2b8(void*);
struct V4f1c6c78 { f32 x, y, z, w; };
struct V3i1c6c78 { s32 a, b; f32 c; };
extern V4f1c6c78 D_01d497c0;
extern V3i1c6c78 D_01d497d0;
extern V3i1c6c78 D_01d497e0;
struct E1680 { u8 v[16]; u32 a10, a14; u32 pad; u8 m[4]; ~E1680() { asm volatile(""); } };
extern E1680 D_00351680[50];
void wtarget_001c6c78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001c6c78jjjj");
void wtarget_001c6c78(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001c6c78: definition moved into src/anon/unit_001c6c60.cpp

}
