// Built with -g (the original leaves the first jal delay slot empty).
#include "../common/types.h"
extern "C" {
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_00323fd8(s32);
void func_0023d4f8(s32, u32);
typedef s32 (*VFn)(u32, s32, s32);
extern u32 D_00347f80;
extern s32 D_0035f5ac;
extern s32 D_0035f5b0;
extern s8 D_0035f5b4;
extern s16 D_0035f5b6;
extern s32 D_0035f5b8;
extern s32 D_0035f5bc;
extern s32 D_0035f5c0;
extern s8 D_0035f5c4;
// Allocates two work buffers, then asks the manager object (D_00347f80 + 20) for entry 0x14f0.
void func_0029a820(void) {
    D_0035f5ac = func_001063c0(0x388, func_00103570());
    s32 p = func_001063c0(0x1b3c, func_00103570());
    func_00323fd8(p);
    // Partial asm: the original issues the lui of D_00347f80 (in t6) above the store to
    // D_0035f5b0, sets a2 right after that store and loads D_00347f80 into t5 last.
    // gcc rematerialises the lui next to its load, reusing t7, and sinks the a2 move.
    register u32 h asm("$14"); asm volatile("lui %0,%%hi(D_00347f80)" : "=r"(h));
    D_0035f5b0 = p;
    register s32 z asm("$6"); asm volatile("move %0,$0" : "=r"(z));
    register u32 g asm("$13"); asm volatile("lw %0,%%lo(D_00347f80)(%1)" : "=r"(g) : "r"(h));
    u32 obj = *(u32*)(g + 20);
    s32 q = ((VFn)**(u32**)obj)(obj, 0x14f0, z);
    func_0023d4f8(q, 1);
    s32 m = -1;
    D_0035f5b4 = 0; D_0035f5bc = q; D_0035f5b6 = m; D_0035f5c4 = m; D_0035f5b8 = 0; D_0035f5c0 = 0;
}
}
