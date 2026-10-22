#include "../common/types.h"
extern "C" {
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3);
s32 func_001d7ec8(u32);
void* func_0016a070(u8*);
s32 func_001afe30(void*);
extern u8 D_0034e8b8;
extern u8 D_00350e60;

struct TP14d358 { s32 status; void (*func)(void*); void* stack; s32 size; void* gp; s32 prio; u32 cur, attr, option; };
struct SP14d358 { s32 count, max, init, wait; u32 attr, option; };
struct E14d358 {
    s32 tid;
    TP14d358 tp;
    u8 pad[52 - 40];
    SP14d358 sp;
    s32 sema;
    void (*func)(void*);
    void* arg;
};
extern E14d358 D_00349e48[2];
void func_0014d298(void*);
s32 func_00305620(SP14d358*) asm("CreateSema");
s32 func_00305420(TP14d358*) asm("CreateThread");
void func_00306760(s32, s32);

void func_0014d358(void* stack, s32 size, void (*func)(void*), void* arg)
{
    s32 i; s32 off;
    for (i = 0, off = 0; i < 2; i++, off += 88) {
        E14d358* e = &D_00349e48[i];
        if (e->func == 0) {
            e->func = func;
            e->arg = arg;
            e->sema = func_00305620((SP14d358*)((u8*)&D_00349e48[0].sp + off));
            e->tp.func = func_0014d298;
            e->tp.stack = stack;
            e->tp.size = size;
            e->tp.prio = i + 40;
            e->tid = func_00305420(&e->tp);
            func_00306760(e->tid, i);
            return;
        }
    }
}

// The s32 return keeps v live past its store to 2852, so sched1 keeps the
// original store order (v0 already holds v on every path).
s32 func_00175670(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00185ed8(p, a1, a2, a3);
    *(s32*)(p + 2788) = 0;
    *(s32*)(p + 2796) = 0;
    *(u32*)p = (u32)&D_0034e8b8;
    s32 v = func_001d7ec8(*(u16*)(*(u8**)(p + 8) + 78));
    *(u32*)(p + 2800) = v;
    *(u8*)(p + 2804) = 0;
    *(s32*)(p + 2816) = 0;
    *(u8*)(p + 2820) = 0;
    *(u8*)(p + 2821) = 0;
    u8* s = p + 2824;
    *(s32*)(s + 4) = 0;
    *(s32*)(s + 8) = -1;
    *(s32*)(s + 12) = 0;
    *(s32*)(s + 16) = 0;
    *(s32*)(s + 20) = 6144;
    *(u32*)(p + 2824) = (u32)&D_00350e60;
    *(u32*)(p + 1416) |= 4;
    *(u32*)(p + 1536) &= ~0x78;
    *(s32*)(p + 2856) = 0;
    *(s32*)(p + 944) = 1;
    *(s32*)(p + 2808) = 0;
    *(s32*)(p + 2812) = 0;
    if (*(s32*)(p + 2488) == 0) {
        v = func_001afe30(func_0016a070(p));
        if (v >= 0) {
            *(s32*)(s + 8) = -1;
            *(s32*)(s + 20) = 6144;
            *(s32*)(s + 12) = 0;
            *(s32*)(s + 16) = 0;
            *(s32*)(s + 28) = v;
            *(u32*)(p + 2824) = (u32)&D_00350e60;
            *(s32*)(s + 4) = 1;
            *(u8**)(p + 2488) = s;
        }
    }
    return v;
}


s32 func_00175790(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00185ed8(p, a1, a2, a3);
    *(s32*)(p + 2788) = 0;
    *(s32*)(p + 2796) = 0;
    *(u32*)p = (u32)&D_0034e8b8;
    s32 v = func_001d7ec8(*(u16*)(*(u8**)(p + 8) + 78));
    *(u32*)(p + 2800) = v;
    *(u8*)(p + 2804) = 0;
    *(s32*)(p + 2816) = 0;
    *(u8*)(p + 2820) = 0;
    *(u8*)(p + 2821) = 0;
    u8* s = p + 2824;
    *(s32*)(s + 4) = 0;
    *(s32*)(s + 8) = -1;
    *(s32*)(s + 12) = 0;
    *(s32*)(s + 16) = 0;
    *(s32*)(s + 20) = 6144;
    *(u32*)(p + 2824) = (u32)&D_00350e60;
    *(u32*)(p + 1416) |= 4;
    *(u32*)(p + 1536) &= ~0x78;
    *(s32*)(p + 2856) = 0;
    *(s32*)(p + 944) = 1;
    *(s32*)(p + 2808) = 0;
    *(s32*)(p + 2812) = 0;
    if (*(s32*)(p + 2488) == 0) {
        v = func_001afe30(func_0016a070(p));
        if (v >= 0) {
            *(s32*)(s + 8) = -1;
            *(s32*)(s + 20) = 6144;
            *(s32*)(s + 12) = 0;
            *(s32*)(s + 16) = 0;
            *(s32*)(s + 28) = v;
            *(u32*)(p + 2824) = (u32)&D_00350e60;
            *(s32*)(s + 4) = 1;
            *(u8**)(p + 2488) = s;
        }
    }
    return v;
}

}
