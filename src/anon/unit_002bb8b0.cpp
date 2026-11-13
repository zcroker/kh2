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

// 002bb8b0 (from src/anon/batch_w228.cpp)
namespace n002bb8b0 {
void func_002b740c(u32, u32, u32, u32) asm("func_002b740c");
s32 func_002bb8b0(u8* p) asm("func_002bb8b0");
s32 func_002bb8b0(u8* p) {
    if (p[49] == 3) return *(s16*)(p + 40);
    func_002b740c(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20), 0);
    u32 fl = *(u32*)(p + 36);
    s32 v;
    if (fl & 4) v = (s32)((f32)*(s16*)(p + 40) * 0.8f);
    else v = *(s16*)(p + 40);
    if (fl & 8) {
        func_002b740c(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20), 1);
        return 0;
    }
    return v;
}
} // n002bb8b0

// 002bb950 (from src/anon/auto80_199_queue.cpp)
namespace n002bb950 {
void func_002bb950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bb950");
void func_002bb950(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u8 tmp;

    u32 ok = func_0014ee28(*(u16*)(s16 + 46), s16, (u32)&tmp);
    if (ok != 0) {
        func_002bb5f8(s16);
        if (tmp == 1) {
            *(u16*)(s16 + 44) = 64;
        }
        return;
    }

    *(u16*)(s16 + 40) = 0;
    *(u16*)(s16 + 44) = 64;
}
} // n002bb950

// 002bb9b8 (from src/anon/batch_w1997.cpp)
namespace n002bb9b8 {
struct Snd9b8 { u8 pad[0x10]; s32 f10; s32 f14; s32 f18; u8 pad1[8]; u32 f24; u8 pad2[4]; s16 f2c; u8 pad3[2]; u8 b30; u8 b31; };
void func_002b726c(s32, s32, s32, s32, s32) asm("func_002b726c");
void wt72e4(u32, u32, u32) asm("_Z16wtarget_002b72e4jjjj");
void func_002b7334(s32, s32, s32, s32, s32) asm("func_002b7334");
void func_002b73ac(s32, s32, s32, s32, s32) asm("func_002b73ac");
s32 func_002bb510(Snd9b8*) asm("func_002bb510");
void func_002bb5f8(Snd9b8*) asm("func_002bb5f8");
s32 func_002bb8b0(Snd9b8*) asm("func_002bb8b0");
void func_002bb950(Snd9b8*) asm("func_002bb950");
void StopBg9b8(s32, s32) asm("_ZN2Tz9MenuSound14StopBgSeHandleEz");
void func_002bb9b8(Snd9b8* s) asm("func_002bb9b8");
void func_002bb9b8(Snd9b8* s) {
    s32 r;
    switch (s->b30) {
    case 0:
        return;
    case 1:
        switch (s->b31) {
        case 1: case 2: case 3: func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        case 4: func_002bb950(s); func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        default: func_002bb5f8(s); func_002b726c(s->f18, s->f10, s->f14, func_002bb8b0(s), s->f2c); s->b30 = 2; break;
        }
        break;
    case 2:
        if ((s->f24 & 2) && func_002bb510(s) == 0) {
            StopBg9b8(s->f14, 1);
            return;
        }
        switch (s->b31) {
        case 2:
            func_002b73ac(s->f18, s->f10, s->f14, func_002bb8b0(s), 30);
            return;
        case 4:
            func_002bb950(s);
            r = func_002bb8b0(s);
            if (r == 0) {
                if (func_002bb510(s)) wt72e4(s->f18, s->f10, s->f14);
                return;
            }
            if (func_002bb510(s)) func_002b7334(s->f18, s->f10, s->f14, r, s->f2c);
            else func_002b726c(s->f18, s->f10, s->f14, r, s->f2c);
            return;
        default:
            func_002bb5f8(s);
        case 1: case 3:
            r = func_002bb8b0(s);
            func_002b7334(s->f18, s->f10, s->f14, r, s->f2c);
            return;
        }
    case 3:
        StopBg9b8(s->f14, 1);
        return;
    }
}
} // n002bb9b8

// 002bbbc8 (from src/anon/batch_w79.cpp)
namespace n002bbbc8 {
struct S2bb { u8 pad0[16]; u32 f16; u32 f20; u32 f24; u8 pad28[12]; s16 h40; s16 pad42; s16 h44; u8 pad46[2]; u8 state; };
void func_002bb8b0(void*) asm("func_002bb8b0");
void func_002b7c34(u32, u32, s16, s16) asm("func_002b7c34");
s32 func_002bb510(void*) asm("func_002bb510");
void func_002bb5f8(void*) asm("func_002bb5f8");
void func_002b7cec(u32, u32, s16, s16) asm("func_002b7cec");
void func_002bc358(u32, s32) asm("func_002bc358");
void func_002bbbc8(struct S2bb* p) asm("func_002bbbc8");
void func_002bbbc8(struct S2bb* p) {
    switch (p->state) {
    case 0:
        break;
    case 1:
        func_002bb8b0(p);
        func_002b7c34(p->f24, p->f16, p->h40, p->h44);
        p->state = 2;
        break;
    case 2:
        if (func_002bb510(p) == 0) {
            func_002bc358(p->f20, 1);
            break;
        }
        func_002bb5f8(p);
        func_002bb8b0(p);
        func_002b7cec(p->f24, p->f16, p->h40, p->h44);
        break;
    case 3:
        func_002bc358(p->f20, 1);
        break;
    }
}
} // n002bbbc8

// 002bbc90 (from src/anon/batch_w80.cpp)
namespace n002bbc90 {
struct U20_Fade { u8 pad[16]; u32 f16; u32 f20; u32 f24; u8 pad2[12]; s16 f40; u8 pad3[2]; s16 f44; u8 pad4[2]; u8 state; };
s32 func_002bb510(U20_Fade*) asm("func_002bb510");
void func_002bb5f8(U20_Fade*) asm("func_002bb5f8");
void func_002bb8b0(U20_Fade*) asm("func_002bb8b0");
void func_002b9728(u32, u32, s32, s32) asm("func_002b9728");
void func_002b95e8(u32, u32, s32, s32) asm("func_002b95e8");
void func_002bc358(u32, u32) asm("func_002bc358");
void func_002bbc90(U20_Fade* f) asm("func_002bbc90");
void func_002bbc90(U20_Fade* f) {
    switch (f->state) {
    case 0:
        break;
    case 1:
        func_002bb8b0(f);
        func_002b95e8(f->f24, f->f16, f->f40, f->f44);
        f->state = 2;
        break;
    case 2:
        if (!func_002bb510(f)) {
            func_002bc358(f->f20, 1);
            break;
        }
        func_002bb5f8(f);
        func_002bb8b0(f);
        func_002b9728(f->f24, f->f16, f->f40, f->f44);
        break;
    case 3:
        func_002bc358(f->f20, 1);
        break;
    }
}
} // n002bbc90

// 002bbd58 (from src/anon/batch_w26.cpp)
namespace n002bbd58 {
u8 func_002bb9b8(void*) asm("func_002bb9b8");
s32 func_002bbc90(void*) asm("func_002bbc90");
s32 func_002bbbc8(void*) asm("func_002bbbc8");
s32 func_002bbd58(u8* o) asm("func_002bbd58");
s32 func_002bbd58(u8* o) {
    switch (o[49]) {
    case 5: return func_002bbbc8(o);
    case 6: return func_002bbc90(o);
    }
    return func_002bb9b8(o);
}
} // n002bbd58

// 002bbda0 (from src/anon/batch_w23.cpp)
namespace n002bbda0 {
struct L2b { u8 pad[20]; s32 key; u8 pad2[4]; L2b* next; };
extern L2b* D_01e2aa80 asm("D_01e2aa80");
static inline L2b* list2b_next(L2b* n) { if (!n) return D_01e2aa80; return n->next; }
L2b* func_002bbda0(s32 key) asm("func_002bbda0");
L2b* func_002bbda0(s32 key) {
    L2b* n = 0;
    while ((n = list2b_next(n)) != 0) {
        if (n->key == key) return n;
    }
    return 0;
}
} // n002bbda0

// 002bbde0 (from src/anon/batch_w2363.cpp)
namespace n002bbde0 {
struct SeList2363 { s32 head; s32 tail; };
extern s32 D_003616f4 asm("D_003616f4");
extern s32 D_003616e8 asm("D_003616e8");
extern SeList2363 D_01e2aa80 asm("D_01e2aa80");
extern SeList2363 D_01e2aa88 asm("D_01e2aa88");
void func_002bb0c8(s32) asm("func_002bb0c8");
void se3d_enable_w2363() asm("_ZN5SOUND10SE3DEnableEv");
void func_002bbde0() asm("func_002bbde0");
void func_002bbde0()
{
    D_003616f4 = 0;
    D_003616e8 = 1;
    func_002bb0c8(100);
    SeList2363* a = &D_01e2aa80;
    SeList2363* b = &D_01e2aa88;
    a->tail = 0;
    b->tail = 0;
    a->head = 0;
    *(volatile s32*)&b->head = 0;                                                          
    se3d_enable_w2363();
}
} // n002bbde0

namespace SE3D {
void exit() {}
}  // namespace SE3D

// 002bbe38 (from src/anon/batch_w1736_nsa.cpp)
namespace n002bbe38 {
struct w1736_Node { u8 p0[0x1c]; w1736_Node* next; u8 p1[4]; u32 flags; u8 p2[9]; u8 type; };
extern w1736_Node* D_01e2aa80 asm("D_01e2aa80");
static inline w1736_Node* w1736_next(w1736_Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}
void func_002bbe38(void) asm("func_002bbe38");
void func_002bbe38(void) {
    w1736_Node* p = 0;
    while ((p = w1736_next(p)) != 0) {
        if (p->type == 2) p->flags |= 4;
    }
}
} // n002bbe38

// 002bbe80 (from src/anon/batch_w31.cpp)
namespace n002bbe80 {
extern u32 D_01e2aa80 asm("D_01e2aa80");
static inline u8* nextNode(u8* n) {
    if (!n) return (u8*)D_01e2aa80;
    return *(u8**)(n + 28);
}
void func_002bbe80(void) asm("func_002bbe80");
void func_002bbe80(void) {
    u8* n = 0;
    while ((n = nextNode(n)) != 0) {
        if (n[49] == 2) *(u32*)(n + 36) &= ~4;
    }
}
} // n002bbe80

// 002bbed0 (from src/anon/batch_w1736_nsa.cpp)
namespace n002bbed0 {
struct w1736_Node { u8 p0[0x1c]; w1736_Node* next; u8 p1[4]; u32 flags; u8 p2[9]; u8 type; };
extern w1736_Node* D_01e2aa80 asm("D_01e2aa80");
static inline w1736_Node* w1736_next(w1736_Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}
void func_002bbed0(void) asm("func_002bbed0");
void func_002bbed0(void) {
    w1736_Node* p = 0;
    while ((p = w1736_next(p)) != 0) {
        if (p->type == 2) p->flags |= 8;
    }
}
} // n002bbed0

// 002bbf18 (from src/anon/batch_w1746_nsa.cpp)
namespace n002bbf18 {
struct W1746Node { u8 pad[28]; W1746Node* next; u32 pad2; u32 flags; u8 pad3[9]; u8 type; };
extern W1746Node* D_01e2aa80 asm("D_01e2aa80");
static inline W1746Node* w1746_next(W1746Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}
void func_002bbf18(void) asm("func_002bbf18");
void func_002bbf18(void) {
    W1746Node* p = 0;
    while ((p = w1746_next(p)) != 0) {
        if (p->type == 2) p->flags &= ~8;
    }
}
} // n002bbf18

// 002bbf68 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n002bbf68 {
u32 func_002bb468(u32, u32, u32, u32) asm("func_002bb468");
u32 func_002bbf68(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002bbf68");
u32 func_002bbf68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002bb468(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (4));
    *(u8*)((u32)r16 + (s32)(48)) = (u8)r15;
    return r2;
}
} // n002bbf68

// 002bbf98 (from src/anon/batch_w3741_nsa.cpp)
namespace n002bbf98 {
struct LNode { u8 pad[0x1c]; LNode* next; LNode* next2; u8 pad24[0xc]; u8 state; u8 pad31[0xf]; };
struct LList { LNode* head; LNode* tail; };
struct LPool { LNode nodes[64]; s32 free[64]; s32 count; };
extern LList D_01e2aa80 asm("D_01e2aa80");
extern LList D_01e2aa88 asm("D_01e2aa88");
extern LPool D_01e2aa90 asm("D_01e2aa90");
extern s32 D_003616f4 asm("D_003616f4");
void func_002bbd58(LNode*) asm("func_002bbd58");
static inline LNode* nextA(LNode* n) { return !n ? D_01e2aa80.head : n->next; }
static inline LNode* nextB(LNode* n) { return !n ? D_01e2aa88.head : n->next2; }
void func_002bbf98(void) asm("func_002bbf98");
void func_002bbf98(void) {
    LNode* n = 0;
    while ((n = nextA(n)) != 0) {
        func_002bbd58(n);
        if (n->state == 4) {
            if (!D_01e2aa88.tail) {
                D_01e2aa88.tail = n;
                D_01e2aa88.head = n;
                n->next2 = 0;
            } else {
                D_01e2aa88.tail->next2 = n;
                n->next2 = 0;
                D_01e2aa88.tail = n;
            }
        }
    }
    while ((n = nextB(n)) != 0) {
        LNode* p = D_01e2aa80.head;
        LNode* prev;
        if (n == p) {
            prev = 0;
            D_01e2aa80.head = n->next;
        } else {
            prev = p;
            LNode* h = p->next;
            LNode* c = h;
            p = h;
            while (p != n) { p = c->next; prev = c; c = p; }
            prev->next = n->next;
        }
        if (n == D_01e2aa80.tail) D_01e2aa80.tail = prev;
        n->next = 0;
        D_01e2aa90.free[D_01e2aa90.count++] = n - D_01e2aa90.nodes;
    }
    LList* l = &D_01e2aa88;
    l->head = 0;
    l->tail = 0;
    D_003616f4 = 0;
}
} // n002bbf98

// 002bc0f0 (from src/anon/batch_w8004.cpp)
namespace n002bc0f0 {
extern u8 D_003616f0 asm("D_003616f0");
extern s32 D_003616f4 asm("D_003616f4");
typedef struct Ent64 { u8 d[64]; } Ent64;
typedef struct Pool { Ent64 e[64]; s32 idx[64]; s32 n; } Pool;
extern Pool D_01e2aa90 asm("D_01e2aa90");
static inline Ent64* pop_w8004(Pool* p) { p->n--; return &p->e[p->idx[p->n]]; }
Ent64* func_002bc0f0(void) asm("func_002bc0f0");
Ent64* func_002bc0f0(void) {
    if (D_003616f0 != 0 || D_01e2aa90.n == 0) return 0;
    if (D_003616f4 >= 25) return 0;
    D_003616f4++;
    return pop_w8004(&D_01e2aa90);
}
} // n002bc0f0

// 002bc158 (from src/anon/batch_w9.cpp)
namespace n002bc158 {
u32 func_002bc0f0(s32) asm("func_002bc0f0");
u32 func_002bc158(s32 a) asm("func_002bc158");
u32 func_002bc158(s32 a) {
    if (a == 0) return 0;
    if (a < 0) return 0;
    return func_002bc0f0(a);
}
} // n002bc158

// 002bc188 (from src/anon/batch_w38.cpp)
namespace n002bc188 {
u8* func_002bc158_0(void) asm("func_002bc158");
void func_002bb1c8(void*, u32, u32) asm("func_002bb1c8");
u32 func_002bc188(u32 a, u32 b) asm("func_002bc188");
u32 func_002bc188(u32 a, u32 b) {
    u8* v = func_002bc158_0();
    if (!v) return 0;
    func_002bb1c8(v, a, b);
    return *(u32*)(v + 20);
}
} // n002bc188

// 002bc1e8 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bc1e8 {
u32 func_002bb228(...) asm("func_002bb228");
u32 func_002bc158(...) asm("func_002bc158");
u32 func_002bc1e8(u32 a0, u32 a1) asm("func_002bc1e8");
u32 func_002bc1e8(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16, r17;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_002bc158)(r4, r5);
    r17 = r2;
    r4 = r2;
    r5 = r16;
    r2 = 0u;
    if (r17 != 0u) {
        r2 = ((u32(*)(u32,u32))func_002bb228)(r4, r5);
        r2 = *(volatile u32*)((u32)r17 + (s32)(20));
    }
    return r2;
}
} // n002bc1e8

// 002bc238 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bc238 {
u32 func_002bb270(...) asm("func_002bb270");
u32 func_002bc158(...) asm("func_002bc158");
u32 func_002bc238(u32 a0, u32 a1) asm("func_002bc238");
u32 func_002bc238(u32 a0, u32 a1) {
    u32 r4 = a0, r5 = a1, r2, r16, r17;
    r16 = r4;
    r2 = ((u32(*)(u32,u32))func_002bc158)(r4, r5);
    r17 = r2;
    r4 = r2;
    r5 = r16;
    r2 = 0u;
    if (r17 != 0u) {
        r2 = ((u32(*)(u32,u32))func_002bb270)(r4, r5);
        r2 = *(volatile u32*)((u32)r17 + (s32)(20));
    }
    return r2;
}
} // n002bc238

// 002bc288 (from src/anon/auto80_199_queue.cpp)
namespace n002bc288 {
u32 func_002bc288(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bc288");
u32 func_002bc288(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = func_002bc158();

    if (s18 == 0) {
        return 0;
    }

    func_002bb2b8(s18, s16, s17, 0);
    return *(u32*)(s18 + 20);
}
} // n002bc288

// 002bc2e8 (from src/anon/batch_w38.cpp)
namespace n002bc2e8 {
u8* func_002bc158_1(u32) asm("func_002bc158");
void func_002bb310(void*, u32, u32, u32) asm("func_002bb310");
u32 func_002bc2e8(u32 a, u32 b, u32 c) asm("func_002bc2e8");
u32 func_002bc2e8(u32 a, u32 b, u32 c) {
    u8* v = func_002bc158_1(a);
    if (!v) return 0;
    func_002bb310(v, a, b, c);
    return *(u32*)(v + 20);
}
} // n002bc2e8

namespace n002bc358 {
u32 func_002bbda0(u32) asm("func_002bbda0");
void func_002bbf68(u32, u32) asm("func_002bbf68");
void MenuSound_StopBgSeHandle(u32, u32) asm("_ZN2Tz9MenuSound14StopBgSeHandleEz");
void MenuSound_StopBgSeHandle(u32 a, u32 b) {
    u32 h = func_002bbda0(a);
    if (h) func_002bbf68(h, b);
}
} // n002bc358

// 002bc398 (from src/anon/batch_w32.cpp)
namespace n002bc398 {
void* func_002bbda0(void*) asm("func_002bbda0");
void func_002bb5a8(void*, void*) asm("func_002bb5a8");
void func_002bc398(void* a, void* b) asm("func_002bc398");
void func_002bc398(void* a, void* b) {
    u8* n = (u8*)func_002bbda0(a);
    if (n) {
        func_002bb5a8(n, b);
        *(u32*)(n + 36) &= ~8;
    }
}
} // n002bc398

// 002bc3f0 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bc3f0 {
u32 func_002bbda0(...) asm("func_002bbda0");
u32 func_002bc3f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bc3f0");
u32 func_002bc3f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_002bbda0)();
    if (r2 != 0u) {
        r15 = ((u32*)(u32)r2)[9];
        r15 = (u32)(r15 | 0x0008u);
        ((u32*)(u32)r2)[9] = r15;
    }
    return r2;
}
} // n002bc3f0

// 002bc420 (from src/anon/tiny_auto80_queue.cpp)
namespace n002bc420 {
u32 func_002bb510(...) asm("func_002bb510");
u32 func_002bbda0(...) asm("func_002bbda0");
u32 func_002bc420(u32 a0) asm("func_002bc420");
u32 func_002bc420(u32 a0) {
    u32 r4 = a0, r2, r15;
    r2 = ((u32(*)())func_002bbda0)();
    r4 = r2;
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)(u32))func_002bb510)(r4);
        r15 = r2;
    }
    r2 = r15;
    return r2;
}
} // n002bc420

// 002bc458 (from src/anon/tiny_wrappers_more.cpp)
namespace n002bc458 {
u32 func_002bb0c8(u32, u32, u32, u32) asm("func_002bb0c8");
u32 func_002bc458(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002bc458");
u32 func_002bc458(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bb0c8(a0, a1, a2, a3);
}
} // n002bc458

// 002bc470 (from src/anon/batch_wcx.cpp)
namespace n002bc470 {
extern u8* D_01e2aa80 asm("D_01e2aa80");
void func_002bbf68(u8*, s32) asm("func_002bbf68");
static inline u8* NextZ(u8* n) { if (!n) return D_01e2aa80; return *(u8**)(n + 28); }
void func_002bc470(u32 id) asm("func_002bc470");
void func_002bc470(u32 id)
{
    u8* n = 0;
    while ((n = NextZ(n))) {
        if (*(u32*)(n + 24) != id) continue;
        u8 s = n[49];
        if (s < 3 || s == 4 || s == 3) func_002bbf68(n, 1);
    }
}
} // n002bc470

// 002bc518 (from src/anon/batch_w39.cpp)
namespace n002bc518 {
struct Node2bc { u8 pad[28]; Node2bc* next; u8 pad2[17]; u8 kind; };
extern Node2bc* D_01e2aa80 asm("D_01e2aa80");
void func_002bbf68(Node2bc*, int) asm("func_002bbf68");
static inline Node2bc* next2bc(Node2bc* n) {
    if (!n) return D_01e2aa80;
    return n->next;
}
void func_002bc518(void) asm("func_002bc518");
void func_002bc518(void) {
    Node2bc* n = 0;
    while ((n = next2bc(n)) != 0) {
        if (n->kind == 3) func_002bbf68(n, 1);
    }
}
} // n002bc518

// 002bc588 (from src/anon/auto80_199_queue.cpp)
namespace n002bc588 {
u32 func_002bc588(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002bc588");
u32 func_002bc588(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    (void)a5;
    (void)a6;
    (void)a7;

    u32 s16 = a0;
    u32 s17 = a1;
    u32 s18 = a2;
    u32 s19 = a3;

    u32 s20 = func_002bc0f0();
    if (s20 == 0) {
        return 0;
    }

    func_002bb378(s20, s16, s17, s18, s19);
    return *(u32*)(s20 + 20);
}
} // n002bc588

// 002bc608 (from src/anon/batch_w59.cpp)
namespace n002bc608 {
extern u8* D_01e2aa80 asm("D_01e2aa80");
void func_002bbf68(u8*, u32) asm("func_002bbf68");
static inline u8* Next2bc(u8* o) {
    if (!o) return D_01e2aa80;
    return *(u8**)(o + 28);
}
void func_002bc608(u32 key) asm("func_002bc608");
void func_002bc608(u32 key) {
    u8* o = 0;
    while ((o = Next2bc(o))) {
        if (*(u32*)(o + 24) != key) continue;
        if (o[49] != 5) continue;
        func_002bbf68(o, 1);
    }
}
} // n002bc608

// 002bc688 (never written before)
namespace n002bc688 {
u32 func_002bc0f0() asm("func_002bc0f0");
void func_002bb3f0(u32, u32, u32, u32, u32) asm("func_002bb3f0");
u32 func_002bc688(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002bc688");
u32 func_002bc688(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s20 = func_002bc0f0();
    if (s20 == 0) {
        return 0;
    }
    func_002bb3f0(s20, a0, a1, a2, a3);
    return *(u32*)(s20 + 20);
}
} // n002bc688

// 002bc708 (from src/anon/batch_w60.cpp)
namespace n002bc708 {
extern u8* D_01e2aa80 asm("D_01e2aa80");
void func_002bbf68(void*, s32) asm("func_002bbf68");
static inline u8* nextNode2bc(u8* n) {
    if (!n) return D_01e2aa80;
    return *(u8**)(n + 28);
}
void func_002bc708(s32 id) asm("func_002bc708");
void func_002bc708(s32 id) {
    u8* n = 0;
    while ((n = nextNode2bc(n))) {
        if (*(s32*)(n + 24) == id && n[49] == 6) func_002bbf68(n, 1);
    }
}
} // n002bc708

extern u8 D_003616f0 asm("D_003616f0");
namespace SOUND {
void SE3DDisable() {
    *(u8*)&D_003616f0 = (u8)1u;
}

void SE3DEnable() {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + 5872) = (u8)0u;
}
}  // namespace SOUND

// 002bc7a8 (from src/anon/batch_w34.cpp)
namespace n002bc7a8 {
extern u8* D_01e2aa80 asm("D_01e2aa80");
static inline u8* nextNode(u8* p) {
    if (p == 0) return D_01e2aa80;
    return *(u8**)(p + 28);
}
s32 func_002bc7a8(u32 k) asm("func_002bc7a8");
s32 func_002bc7a8(u32 k) {
    s32 n = 0;
    u8* p = 0;
    while ((p = nextNode(p)) != 0) {
        if (p[49] == k) n++;
    }
    return n;
}
} // n002bc7a8

// 002bc7f0 (from src/anon/batch_w2036.cpp)
namespace n002bc7f0 {
struct L2bc7f0 { s32 a; s32 b; };
struct E2bc7f0 { u8 d[0x40]; ~E2bc7f0() {} };
struct P2bc7f0 { E2bc7f0 e[64]; s32 idx[64]; s32 n; };
extern L2bc7f0 D_01e2aa80 asm("D_01e2aa80");
extern L2bc7f0 D_01e2aa88 asm("D_01e2aa88");
extern P2bc7f0 D_01e2aa90 asm("D_01e2aa90");
void func_00324710(void*) asm("func_00324710");
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002bc7f0jjjj");
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        D_01e2aa80.a = 0;
        D_01e2aa80.b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        D_01e2aa88.a = 0;
        D_01e2aa88.b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        E2bc7f0* e = D_01e2aa90.e;
        for (s32 i = 63; i != -1; ) { i--; func_00324710(e->d + 0x24); e++; }
        P2bc7f0* b = &D_01e2aa90;
        s32* q = b->idx;
        for (s32 j = 0; j < 64; j++) *q++ = j;
        b->n = 64;
    }
    if (a1 == 0xffff && a0 == 0) {
        D_01e2aa90.~P2bc7f0();
    }
}
} // n002bc7f0

// 002bc938 (from src/anon/tiny_wrappers_more.cpp)
namespace n002bc938 {
u32 func_002bc7f0(u32, u32, u32, u32) asm("func_002bc7f0");
u32 func_002bc938(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002bc938");
u32 func_002bc938(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc7f0(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n002bc938

// 002bc958 (_GLOBAL__D_ stub, never written before)
namespace n002bc958 {
u32 func_002bc7f0(u32, u32, u32, u32) asm("func_002bc7f0");
u32 func_002bc958(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002bc958");
u32 func_002bc958(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc7f0(0, 0x0000ffffu, a2, a3);
}
} // n002bc958
