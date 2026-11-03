// Partial asm in func_001980d0: three small asm statements only fix sched2 order of the member re-init.
#include "../common/types.h"
extern "C" {
void func_00169398(void*, u32, void*, s32, s32, f32);
void* func_00168b38(s32, s32, s32);
s32 func_00170d18(s32);
void func_0017ebe8(void*, s32);
void func_00195858(void*, u32);
void func_001b2f38(void*, s32, u32);
void func_001d56f0(void*);
void func_001dddd0(void*, s32);
extern u8 D_003503e0[];
extern u8 D_00350e48[];

void func_001980d0(u8* p, u32* a1, s32 a2, s32 a3, f32 f) {
    u8* s0 = p + 0x9BC;
    u8* s2 = p + 0x7A0;
    func_00169398(p, *a1, a1, a2, a3, f);
    *(s32*)(p + 0x9B4) = 0;
    *(u32*)(p + 0x9B8) = 0;
    *(u32*)(p + 0) = (u32)D_003503e0;
    *(s32*)(s0 + 8) = -1;
    *(s32*)(s0 + 0x14) = 0x1800;
    *(s32*)(s0 + 4) = 0;
    *(s32*)(s0 + 0xC) = 0;
    *(s32*)(s0 + 0x10) = 0;
    *(u32*)(p + 0x9BC) = (u32)D_00350e48;
    func_001d56f0(p + 0x9DC);
    func_001d56f0(p + 0x9E8);
    *(s32*)(p + 0x588) |= 1;
    if (*(s32*)(s2 + 0x10) != 0) {
        u8* v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x12, 0);
        if (v != 0 && *(s32*)(v + 8) != 0) {
            func_001dddd0(p + 0x80, *(s32*)(v + 8));
        }
        v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x22, 0);
        if (v != 0) {
            s32 t = *(s32*)(v + 8);
            if (t != 0) {
                *(s32*)(s0 + 0xC) = 0;
                *(s32*)(s0 + 8) = -1;
                *(s32*)(s0 + 0x14) = 0x1800;
                *(s32*)(s0 + 0x10) = 0;
                u32 vt; asm("" : "=r"(vt) : "0"(D_00350e48));
                asm("sw %2,28(%1)" : "=m"(*(s32*)(s0 + 0x1C)) : "r"(s0), "r"(t), "r"(vt));
                *(u32*)(p + 0x9BC) = vt;
                s32 two; asm("li %0,2" : "=r"(two) : "m"(*(u32*)(p + 0x9BC)));
                *(s32*)(s0 + 4) = two;
                *(u32*)(p + 0x9B8) = (u32)s0;
            }
        }
        *(s32*)(p + 0x9B4) = func_00170d18(*(s32*)(s2 + 0x10));
        v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x26, 0);
        if (v != 0 && *(s32*)(v + 8) != 0) {
            u8* q = p + 0x800;
            func_001b2f38(q, *(s32*)(v + 8), (u8)((*(u16*)((u8*)a1 + 0x48) >> 6) & 1));
            *(s32*)(p + 0x60C) = *(s32*)(q + 0xC);
        }
    }
    if (*(s32*)(s2 + 0x14) != 0) {
        func_0017ebe8(p + 0x140, *(s32*)(s2 + 0x14));
    }
    u16 h = *(u16*)(*(u8**)(p + 8) + 0x4E);
    if (h != 0) {
        func_00195858(p + 0x110, h);
    }
}
}
