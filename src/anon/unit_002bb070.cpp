#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002bb070 (from src/anon/batch_w8.cpp)
namespace n002bb070 {
void func_002baf48(u32, u32, u32, u32, u32, u32) asm("func_002baf48");
void func_002bb070(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002bb070");
void func_002bb070(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_002baf48(a, 3, b, c, d, e);
}
} // n002bb070

// 002bb0a0 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bb0a0 {
void func_002bb0a0(s32 a0, s32* a1, s32* a2) asm("func_002bb0a0");
void func_002bb0a0(s32 a0, s32* a1, s32* a2) {                
    s32 q = a0 / 1000;
    s32 r = a0 % 1000;
    *a2 = r;
    *a1 = q;
}
} // n002bb0a0

// 002bb0c8 (from src/anon/tiny_auto80_solver.cpp)
namespace n002bb0c8 {
void func_002bb0c8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb0c8");
void func_002bb0c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb0c8");
void func_002bb0c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r13 = ~a0;
    u32 r15 = 100u;
    if (r13 == 0u) {
        a0 = r15;
    }
    u32 r14 = (u32)(0x0036u << 16);
    *(volatile u32*)((u32)r14 + (s32)(5868)) = a0;
}
} // n002bb0c8

// 002bb0e0 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bb0e0 {
void func_002bb0e0(u32 a0) asm("func_002bb0e0");
void func_002bb0e0(u32 a0) {
    if (*(u32*)(a0 + 24) == 0xffffffffu) {
        *(u8*)(a0 + 48) = 3;
    }
}
} // n002bb0e0

// 002bb100 (from src/anon/batch_w58.cpp)
namespace n002bb100 {
struct Nd28 { u8 pad[20]; s32 id; u8 pad2[4]; Nd28* next; u8 pad3[4]; s32 f36; u16 h40 : 16; u8 pad4[2]; u16 h44 : 16; u8 pad5[2]; u8 b48; u8 b49; };
struct L28 { Nd28* head; Nd28* tail; };
extern L28 D_01e2aa80 asm("D_01e2aa80");
extern s32 D_003616e8 asm("D_003616e8");
void func_002bb100(Nd28* n, s32 a1, s32 a2) asm("func_002bb100");
void func_002bb100(Nd28* n, s32 a1, s32 a2) {                   
    s32 id = D_003616e8;
    n->id = id;
    D_003616e8 = ++id;
    if (id == 0) D_003616e8 = 1;
    n->b49 = a2;
    n->f36 = 0;
    n->b48 = 1;
    if (a1 == 1) n->f36 = 2;
    n->h40 = 16383;
    n->h44 = 64;
    L28* L = &D_01e2aa80;
    if (!L->tail) { L->tail = n; L->head = n; n->next = 0; } else { L->tail->next = n; n->next = 0; L->tail = n; }
}
} // n002bb100

// 002bb180 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bb180 {
u32 func_002ba810(...) asm("func_002ba810");
void func_002bb0a0(s32 a0, s32* a1, s32* a2) asm("func_002bb0a0");
void func_002bb180(u32 a0, u32 a1) asm("func_002bb180");
void func_002bb180(u32 a0, u32 a1) {                              
    *(u16*)(a0 + 42) = 0;

    u32 s0 = a0;
    u32 out0;
    u32 out1;

    ((void(*)(u32, u32*, u32*))func_002bb0a0)(a1, &out0, &out1);
    u32 v0 = func_002ba810(out0);
    u32 t7 = out1;

    *(u32*)(s0 + 16) = t7;
    *(u32*)(s0 + 24) = v0;
}
} // n002bb180

// 002bb1c8 (from src/anon/auto80_199_queue.cpp)
namespace n002bb1c8 {
u32 func_002bb1c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb1c8");
u32 func_002bb1c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s18 = a1;
    u32 s17 = a2;

    func_002bb100(s16, 1, 0);                   
    func_002bb5a8(s16, s17);
    func_002bb180(s16, s18);                              
    return func_002bb0e0(s16);
}
} // n002bb1c8

// 002bb228 (from src/anon/tiny_auto80_solver.cpp)
namespace n002bb228 {
u32 func_002bb0e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb0e0");
u32 func_002bb100(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb100");
u32 func_002bb180(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb180");
u32 func_002bb228(u32 a0, u32 a1) asm("func_002bb228");
u32 func_002bb228(u32 a0, u32 a1) {
    ((u32(*)(u32, u32, u32))func_002bb100)(a0, 1, 1);
    ((u32(*)(u32, u32))func_002bb180)(a0, a1);
    return ((u32(*)(u32))func_002bb0e0)(a0);
}
} // n002bb228

// 002bb270 (from src/anon/tiny_auto80_solver.cpp)
namespace n002bb270 {
u32 func_002bb0e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb0e0");
u32 func_002bb100(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb100");
u32 func_002bb180(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002bb180");
u32 func_002bb270(u32 a0, u32 a1) asm("func_002bb270");
u32 func_002bb270(u32 a0, u32 a1) {
    ((u32(*)(u32, u32, u32))func_002bb100)(a0, 1, 3);
    ((u32(*)(u32, u32))func_002bb180)(a0, a1);
    return ((u32(*)(u32))func_002bb0e0)(a0);
}
} // n002bb270

// 002bb2b8 (from src/anon/auto80_199_queue.cpp)
namespace n002bb2b8 {
u32 func_002bb2b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb2b8");
u32 func_002bb2b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;

    func_002bb100(s16, a3, 2);                   
    func_002bb180(s16, s17);                              
    *(u32*)(s16 + 24) = s18;
    return func_002bb0e0(s16);
}
} // n002bb2b8

// 002bb310 (from src/anon/auto80_199_queue.cpp)
namespace n002bb310 {
u32 func_002bb310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb310");
u32 func_002bb310(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;
    u32 s19 = a3;

    func_002bb100(s16, 0, 4);                   
    func_002bb180(s16, s17);                              
    *(u32*)(s16 + 24) = s18;
    *(u16*)(s16 + 46) = (u16)s19;
    return func_002bb0e0(s16);
}
} // n002bb310

// 002bb378 (from src/anon/auto80_199_queue.cpp)
namespace n002bb378 {
u32 func_002bb378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb378");
u32 func_002bb378(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s18 = a1;
    u32 s19 = a2;
    u32 s17 = a3;
    u32 s20 = a4;

    func_002bb100(s16, 1, 5);                   
    func_002bb5a8(s16, s17);
    *(u32*)(s16 + 24) = s18;
    *(u32*)(s16 + 16) = s19;
    *(u16*)(s16 + 42) = (u16)s20;
    return func_002bb0e0(s16);
}
} // n002bb378

// 002bb3f0 (from src/anon/batch_w47.cpp)
namespace n002bb3f0 {
void func_002bb100(u8*, s32, s32) asm("func_002bb100");
void func_002bb5a8(u8*, u32) asm("func_002bb5a8");
void func_002bb3f0(u8* p, u32 a, u32 b, u32 c, u32 d) asm("func_002bb3f0");
void func_002bb3f0(u8* p, u32 a, u32 b, u32 c, u32 d) {
    func_002bb100(p, 1, 6);                   
    func_002bb5a8(p, c);
    *(u32*)(p + 24) = a;
    *(u32*)(p + 16) = b;
    *(u16*)(p + 42) = d;
}
} // n002bb3f0

// 002bb468 (from src/anon/batch_w1783.cpp)
namespace n002bb468 {
struct CT {
    u8 _00[0x10];
    u32 _10;
    u32 _14;
    u32 _18;
    CT* next;          
    u8 _20[0x11];
    u8 kind;           
};
extern CT* D_01e2aa80 asm("D_01e2aa80");
u8 f73_u8(u32, u32, u32, s32, u32) asm("func_002b73ac");
s32 f7d_s(u32, u32, s32, u32) asm("func_002b7d5c");
s32 f97_s(u32, u32, s32, u32) asm("func_002b97d8");
static inline CT* ct_next(CT* p) { return p ? p->next : D_01e2aa80; }
s32 ctarget_002bb468(CT* self, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_002bb468jjjj");
s32 ctarget_002bb468(CT* self, u32 a1, u32 a2, u32 a3) {
    CT* p = 0;
    while ((p = ct_next(p)) != 0) {
        if (p == self) break;
    }
    switch (self->kind) {
    case 5: return f7d_s(self->_18, self->_10, -1, a1);
    case 6: return f97_s(self->_18, self->_10, -1, a1);
    default: return f73_u8(self->_18, self->_10, self->_14, -1, a1);
    }
}
} // n002bb468

// 002bb510 (from src/anon/batch_w51.cpp)
namespace n002bb510 {
extern u8 D_01e2aa80[] asm("D_01e2aa80");
void func_00324718(void*, void*) asm("func_00324718");
u32 func_002b79cc(u32, u32, u32) asm("func_002b79cc");
u32 func_002b986c(u32, u32) asm("func_002b986c");
u32 func_002b7440(u32, u32, u32) asm("func_002b7440");
u32 func_002bb510(u8* p) asm("func_002bb510");
u32 func_002bb510(u8* p) {
    func_00324718(D_01e2aa80, p);
    if (p[48] == 1) return 1;
    switch (p[49]) {
    case 5:
        return func_002b79cc(*(u32*)(p + 24), *(u32*)(p + 16), 0) != 0;
    case 6:
        return func_002b986c(*(u32*)(p + 24), *(u32*)(p + 16)) != 0;
    default:
        return func_002b7440(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20)) != 0;
    }
}
} // n002bb510

// 002bb5a8 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bb5a8 {
extern u8  D_01e2aa80 asm("D_01e2aa80");
void func_00324718(...) asm("func_00324718");
void func_002bb5a8(void* a0, void* a1) asm("func_002bb5a8");
void func_002bb5a8(void* a0, void* a1) {
    u32 s0 = (u32)a0;
    u32 s1 = (u32)a1;

    func_00324718((u32)&D_01e2aa80, s0);

    if (s0 != s1) {
        *(kn::FVector*)s0 = *(kn::FVector*)s1;
    }
}
} // n002bb5a8

