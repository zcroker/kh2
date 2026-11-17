#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"


// 00165db8 (from src/anon/batch_w3681.cpp)
namespace n00165db8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Ctx { u16 id; QWord* obj; s32 found; };
union PU { s32* p; u16 h; };
s32* func_00165ef0(s32*) asm("func_00165ef0");
s32 func_00142b70(s32) asm("func_00142b70");
void func_00141c18(s32, s32, s32, u32, s32) asm("func_00141c18");
s32 func_00141ff0(s32, QWord*, QWord*, Ctx*, s32) asm("func_00141ff0");
s32 func_00165db8(QWord* a0, QWord* out, u16* outId, s32 a3, s32 t0, u8 t1, s32** outP, s32 t3, s32 skip) asm("func_00165db8");
s32 func_00165db8(QWord* a0, QWord* out, u16* outId, s32 a3, s32 t0, u8 t1, s32** outP, s32 t3, s32 skip) {
    QWord tmp;
    Ctx c;
    s32* p = 0;
    *(s32* volatile*)outP = 0;
    *(volatile u16*)outId = 0xffff;
    c.id = 0xffff;
    *(QWord* volatile*)&c.obj = a0;
    *(volatile s32*)&c.found = 0;
    while ((p = func_00165ef0(p)) != 0) {
        if (p[0] == skip) continue;
        if (func_00142b70(p[1])) continue;
        func_00141c18(p[1], a3, t0, t1, 0);
        if (func_00141ff0(p[1], c.obj, &tmp, &c, t3)) {
            c.found = 1;
            *out = tmp;
            { register QWord* o asm("$14") = c.obj; register QWord* o1 asm("$15") = o + 1; if (o1 != out) QCOPY(o1, out); }
            ((PU*)outP)->p = p;
            *outId = c.id;
        }
    }
    return c.found;
}
} // n00165db8

// 00165ef0 (from src/anon/batch_w13.cpp)
namespace n00165ef0 {
extern u8* D_004f41c0 asm("D_004f41c0");
u8* func_00165ef0(u8* p) asm("func_00165ef0");
u8* func_00165ef0(u8* p) {
    do {
        p = p ? *(u8**)(p + 12) : D_004f41c0;
    } while (p && (*(u32*)(p + 8) & 2));
    return p;
}
} // n00165ef0

// 00165f28 (gap: static initialiser of the list head at 0x4f41c0, kept as a plain function)
namespace n00165f28 {
struct LIST2 { u32 head; u32 tail; void init() { head = 0; tail = 0; } };
extern LIST2 D_004f41c0 asm("D_004f41c0");
void func_00165f28(u32 init, u32 prio) asm("_Z16wtarget_00165f28jjjj");
void func_00165f28(u32 init, u32 prio) {
    if (prio == 0xffff && init == 1) {
        LIST2* l = &D_004f41c0;
        l->tail = 0;
        D_004f41c0.head = 0;
    }
}
} // n00165f28

// 00165f50 (from src/anon/tiny_wrappers_more.cpp)
namespace n00165f50 {
u32 func_00165f28(u32, u32, u32, u32) asm("_Z16wtarget_00165f28jjjj");
u32 func_00165f50(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00165f50");
u32 func_00165f50(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00165f28(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n00165f50
