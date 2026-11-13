#include "../common/types.h"

// PRIZE file tail (0x1cd548-0x1cd660): the static initialiser / teardown of the prize work object
// (0x1d499b0: member constructors, then the two 0xffff-filled id structs at 0x1d5a970/0x1d5a974)
// and its _GLOBAL__I_ / _GLOBAL__D_ stubs. The object stays data; the rest of the file is
// unit_001cc048.cpp, unit_001cc868.cpp and unit_001cd078.cpp.

struct G1cd548 { u8 pad0[12]; u8 a; u8 pad1[9456 - 13]; u8 b; u8 pad2[16364 - 9457]; u8 c;
    u8 pad3[16796 - 16365]; u8 d; u8 pad4[21920 - 16797]; u8 e; u8 pad5[0x100e0 - 21921]; u8 f; };
extern G1cd548 D_01d499b0;

extern "C" {
void func_00319bd0(void*);
void func_00188e08(void*);
void func_00319870(void*);
void func_00321068(void*);
void func_002e7768(void*);
void func_001e0868(void*);
void f_002e77a0(void*) asm("_Z13func_002e77a0Pv");
void wt_001cd548(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_001cd548jjjj");
void wt_001cd548(u32 init, u32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        /* member constructors */
        G1cd548* g = &D_01d499b0;
        asm("" : "+r"(g));
        func_00319bd0(&g->a);
        func_00188e08(&g->b);
        func_00319870(&g->c);
        func_00321068(&g->d);
        func_002e7768(&g->e);
        func_001e0868(&g->f);
        /* the two id structs' ctors fill a, b, c with 0xffff (prio); the store
           order (c, c, a, a, b, b) needs hand-written instructions */
        register u32 t4 asm("$12");
        register u32 t5 asm("$13");
        register u32 t6 asm("$14");
        register u32 t7 asm("$15");
        asm volatile("lui %0,%%hi(D_01d5a970)" : "=r"(t6));
        asm volatile("lui %0,%%hi(D_01d5a974)" : "=r"(t7));
        asm volatile("addiu %0,%1,%%lo(D_01d5a970)" : "=r"(t5) : "r"(t6));
        asm volatile("addiu %0,%1,%%lo(D_01d5a974)" : "=r"(t4) : "r"(t7));
        asm volatile("sb %0,2(%1)" : : "r"(prio), "r"(t5) : "memory");
        asm volatile("sh %0,4(%1)" : : "r"(prio), "r"(t4) : "memory");
        asm volatile("sh %0,%%lo(D_01d5a974)(%1)" : : "r"(prio), "r"(t7) : "memory");
        asm volatile("sb %0,%%lo(D_01d5a970)(%1)" : : "r"(prio), "r"(t6) : "memory");
        asm volatile("sb %0,1(%1)" : : "r"(prio), "r"(t5) : "memory");
        asm volatile("sh %0,2(%1)" : : "r"(prio), "r"(t4) : "memory");
    }
    struct NoTail { ~NoTail() {} } nt;
    if (prio == 0xffff && init == 0) {
        G1cd548* g = &D_01d499b0;
        asm("" : "+r"(g));
        f_002e77a0(&g->e);
    }
}

// 0x1cd620: the _GLOBAL__I_ stub.
u32 func_001cd548_u(u32, u32, u32, u32) asm("_Z16wtarget_001cd548jjjj");
u32 func_001cd620(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001cd548_u(0x00000001u, 0x0000ffffu, a2, a3);
}

// 0x1cd640 (not in the layout): the _GLOBAL__D_ stub.
u32 func_001cd640(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001cd548_u(0x00000000u, 0x0000ffffu, a2, a3);
}
}
