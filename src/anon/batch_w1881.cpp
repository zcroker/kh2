#include "../common/types.h"
struct V5748 {
    f32 x, y, z, w;
    V5748() {}
    V5748& operator=(const V5748& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Mg5748 { u8 pad[0x140]; u8 f140; };
struct Act5748 {
    u8 pad[0xc14]; void* c14; u8 p2[4]; s32 c1c; u8 p3[0x10]; void* c30; void* c34;
};
s32 st_eff5748(Act5748*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
V5748* epos5748(void*) asm("_ZN3ryj6EFFECT3posEv");
void ekill5748(void*) asm("_ZN3ryj6EFFECT4killEv");
V5748 getpos5748(void*) asm("_Z16ctarget_0016bda8jjjj");
void tornado5748(Act5748*) asm("_ZN2Ti15MGOarashiPlayer20start_tornado_attackEv");
extern "C" {
extern Mg5748* D_00361f60;
void func_002d6518(void*);
void func_001991a8(s32, s32);
void func_002d4868(s32);

void func_002d5748(Act5748* self, u16* msg);  // 0x002d5748: definition moved into src/anon/unit_002d4548.cpp
}
