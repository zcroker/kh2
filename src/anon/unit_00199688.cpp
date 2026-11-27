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

// 00199688 (from src/anon/batch_w51.cpp)
namespace n00199688 {
u8* func_00168b38(void*, u32, s32) asm("func_00168b38");
u32 YS__DATABUFF__ReadBar(u32) asm("YS__DATABUFF__ReadBar");
extern u32 D_0035043c asm("D_0035043c");
extern u32 D_01c62148[19] asm("D_01c62148");
static inline bool hasValue8(u8* r) { return r && *(u32*)(r + 8); }
void func_00199688(void) asm("func_00199688");
void func_00199688(void) {
    u32 o = YS__DATABUFF__ReadBar(D_0035043c);
    for (s32 i = 0; i < 19; i++) {
        u8* r = func_00168b38((void*)o, 2, i);
        bool ok = hasValue8(r);
        u32 v = 0;
        if (ok) v = *(u32*)(r + 8);
        D_01c62148[i] = v;
    }
}
} // n00199688

// 00199718 (from src/anon/batch_w66.cpp)
namespace n00199718 {
extern u8 D_0032bae0 asm("D_0032bae0");
extern u8* D_01c62148[] asm("D_01c62148");
extern u8 D_0031f148[] asm("D_0031f148");
u8* func_002fd248(u32, u8*, u32, s32, u8*) asm("func_002fd248");
struct Sub199b { u16 a, b, c; };
struct S199b { u8 b0, b1, b2, b3; Sub199b s; };
static inline void init199(Sub199b* s, u32 a, u32 m) { s->a = a; s->b = m; s->c = m; }
S199b* func_00199718(S199b* p, u32 a, s32 k) asm("func_00199718");
S199b* func_00199718(S199b* p, u32 a, s32 k) {
    if (k < 0) k = D_0032bae0;
    u8* t = D_01c62148[k];
    u8* v = func_002fd248(a, t + 8, *(u32*)(t + 4), 4, D_0031f148);
    u16 h = *(u16*)(v + 2);
    p->b0 = k;
    p->b1 = h;
    p->b2 = 0;
    init199(&p->s, a, 0xffff);
    p->s.b = a;
    p->s.c = a;
    return p;
}
} // n00199718

// 001997c0 (from src/anon/batch_w34.cpp)
namespace n001997c0 {
u8* func_0016e920(u32) asm("func_0016e920");
s32 func_001997c0(u32* p) asm("func_001997c0");
s32 func_001997c0(u32* p) {
    switch (func_0016e920(*p)[4]) {
    case 4: case 13: case 21: case 23: return 1;
    }
    return 0;
}
} // n001997c0

// 00199810 (from src/anon/batch_w1767.cpp)
namespace n00199810 {
struct W1767D { s32 x0; u8 pad[0x18]; u8 b1c; u8 b1d; };
struct W1767V { u8 pad[4]; u8 b4; };
extern u8 D_00350378 asm("D_00350378");
extern u8 D_0032bae2 asm("D_0032bae2");
W1767V* func_0016e920(s32) asm("func_0016e920");
s32 func_0016f448(u8) asm("func_0016f448");
s32 func_00199810(W1767D* p) asm("func_00199810");
s32 func_00199810(W1767D* p) {
    s32 r = 0;
    W1767V* v = func_0016e920(p->x0);
    if (v == 0) return r;
    if (D_00350378 != 0 && func_0016f448(v->b4) >= 2000) return r;
    if (p->b1c == 1 && p->b1d != D_0032bae2) return r;
    return 1;
}
} // n00199810

// 00199890 (from src/anon/batch_wcx.cpp)
namespace n00199890 {
f32 func_0017ce10(f32) asm("func_0017ce10");
u8* func_0016f000(u32, u32, f32) asm("func_0016f000");
s32 func_001997c0(u8*) asm("func_001997c0");
void func_001956d0(u8*, u16) asm("func_001956d0");
extern u8 D_0034f250[] asm("D_0034f250");
typedef void (*Fn56)(u8*, u32, u8*);
u8* func_00199890(u8* p, u32 a, u32 b) asm("func_00199890");
u8* func_00199890(u8* p, u32 a, u32 b)
{
    f32 r = func_0017ce10(3.14159274f - *(f32*)(p + 20));
    u8* o = func_0016f000(*(u32*)p, b, r);
    if (o) {
        (*(Fn56*)(*(u8**)o + 56))(o, a, p);
        if (func_001997c0(p)) func_001956d0(D_0034f250, *(u16*)(p + 30));
    }
    return o;
}
} // n00199890

// 00199938 (from src/anon/tiny_auto80_queue.cpp)
namespace n00199938 {
u32 func_00199890(...) asm("func_00199890");
void func_00199938(u32 a0, u32 a1) asm("func_00199938");
void func_00199938(u32 a0, u32 a1) {
    V4_00199938 v;
    v.w = 0;
    f32 x = *(f32*)(a0 + 4);
    f32 y = *(f32*)(a0 + 8);
    f32 z = *(f32*)(a0 + 12);
    v.x = x;
    v.y = y;
    v.z = z;
    func_00199890(a0, a1, (u32)&v);
}
} // n00199938

// 00199970 (from src/anon/tiny_auto80_solver.cpp)
namespace n00199970 {
extern u8 D_01c62198 asm("D_01c62198");
u32 func_00199970(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00199970");
u32 func_00199970(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 base = 0x0035u << 16;
    u32 idx = *(u32*)(base + 1088);
    u32 ret = (u32)&D_01c62198 + idx * 56;
    *(u32*)(base + 1088) = idx + 1;
    return ret;
}
} // n00199970

// 00199998 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n00199998 {
void func_00199998(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00199998");
void func_00199998(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r14 = (u32)(0x0035u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(1088));
    r15 = (u32)((s32)r15 + (-1));
    *(u32*)((u32)r14 + (s32)(1088)) = r15;
}
} // n00199998

// 001999b0 (gap: twin of 0x199aa0)
namespace n001999b0 {
struct W2380Hdr { u8 kind; u8 opts; u16 pad; u16 n0; u16 n1; u16 n2; u16 n3; u8 p10[0x10]; u16 h1c; };
struct W2380Rec { u16 a; u16 n; };
struct W2380Blk {
    int a0; u32 flags; W2380Hdr* volatile hdr; int c; int d; float f; u8 p18[8]; u8 b20; u8 p21[3];
    u8* p24; u8* p28; u8* p2c; u8* p30; u8* p34;
};
void func_00199b90(W2380Blk*) asm("func_00199b90");
void func_001999b0(W2380Blk* b, int a, W2380Hdr* h) asm("func_001999b0");
void func_001999b0(W2380Blk* b, int a, W2380Hdr* h)
{
    b->hdr = h;
    W2380Hdr* t = b->hdr;
    b->a0 = a;
    b->flags = 0;
    u8* p = (u8*)t + 0x2c;
    b->p24 = p;
    b->d = 0;
    b->c = 0;
    b->f = 0;
    b->b20 = 0;
    p += t->n0 << 6;
    b->p28 = p;
    p += t->n1 << 6;
    b->p2c = p;
    u8* q = p;
    for (int i = 0; i < t->n2; i++) {
        q = q + ((W2380Rec*)q)->n * 12 + 8;
    }
    b->p30 = q;
    b->p34 = q + t->n3 * 16;
    if (h->kind != 2) {
        if (h->kind == 5) b->flags |= 1;
    } else {
        b->f = t->h1c;
    }
    s32 m = 1;
    if (h->opts & m) b->flags |= 1;
    func_00199b90(b);
}
} // n001999b0

// 00199aa0 (from src/anon/batch_w2380_nsa.cpp)
namespace n00199aa0 {
struct W2380Hdr { u8 kind; u8 opts; u16 pad; u16 n0; u16 n1; u16 n2; u16 n3; u8 p10[0x10]; u16 h1c; };
struct W2380Rec { u16 a; u16 n; };
struct W2380Blk {
    int a0; u32 flags; W2380Hdr* volatile hdr; int c; int d; float f; u8 p18[8]; u8 b20; u8 p21[3];
    u8* p24; u8* p28; u8* p2c; u8* p30; u8* p34;
};
void func_00199b90(W2380Blk*) asm("func_00199b90");
void func_00199aa0(W2380Blk* b, int a, W2380Hdr* h) asm("func_00199aa0");
void func_00199aa0(W2380Blk* b, int a, W2380Hdr* h)
{
    b->hdr = h;
    W2380Hdr* t = b->hdr;
    b->a0 = a;
    b->flags = 0;
    u8* p = (u8*)t + 0x2c;
    b->p24 = p;
    b->d = 0;
    b->c = 0;
    b->f = 0;
    b->b20 = 0;
    p += t->n0 << 6;
    b->p28 = p;
    p += t->n1 << 6;
    b->p2c = p;
    u8* q = p;
    for (int i = 0; i < t->n2; i++) {
        q = q + ((W2380Rec*)q)->n * 12 + 8;
    }
    b->p30 = q;
    b->p34 = q + t->n3 * 16;
    if (h->kind != 2) {
        if (h->kind == 5) b->flags |= 1;
    } else {
        b->f = t->h1c;
    }
    s32 m = 1;
    if (h->opts & m) b->flags |= 1;
    func_00199b90(b);
}
} // n00199aa0

// 00199b90 (from src/anon/batch_w1673.cpp)
namespace n00199b90 {
struct E9b90 { u16 id; u16 sub; u8 kind; u8 pad[3]; };
struct H9b90 { u8 pad[2]; u16 x; u8 pad2[8]; u16 n; };
struct O9b90 { u8 pad[8]; H9b90* h; u8 pad2[0x34-0xc]; E9b90* e; };
s32 func_00198c28(u16, s32) asm("func_00198c28");
void func_00198e70(s32, u16) asm("func_00198e70");
void func_00198ea8(s32, u16) asm("func_00198ea8");
void func_00199b90(O9b90* o) asm("func_00199b90");
void func_00199b90(O9b90* o) {
    for (s32 i = 0; i < o->h->n; i++) {
        u16 id = ((E9b90*)(i*8 + (u8*)o->e))->id;
        s32 sub = -1;
        if (id != 0x4a) sub = ((E9b90*)(i*8 + (u8*)o->e))->sub;
        s32 r = func_00198c28(id, sub);
        switch (((E9b90*)(i*8 + (u8*)o->e))->kind) {
        case 0: func_00198e70(r, o->h->x); break;
        case 1: func_00198ea8(r, o->h->x); break;
        }
    }
}
} // n00199b90

// 00199c68 (gap: twin of 0x199cd0)
namespace n00199c68 {
struct P199 { u32 f0; u32 flag : 1; u32 rest : 31; u32 f8; u8* o; u32 f16; };
void func_00199c68(P199* p) asm("func_00199c68");
void func_00199c68(P199* p) {
    p->flag = 1;
    u8* o = p->o;
    while (o) {
        u8* n = *(u8**)(o + 96);
        if (o) (*(void (**)(void*))(*(u8**)o + 4))(o);
        o = n;
    }
    p->f16 = 0;
    p->o = 0;
}
} // n00199c68

// 00199cd0 (from src/anon/batch_w43.cpp)
namespace n00199cd0 {
struct P199 { u32 f0; u32 flag : 1; u32 rest : 31; u32 f8; u8* o; u32 f16; };
void func_00199cd0(P199* p) asm("func_00199cd0");
void func_00199cd0(P199* p) {
    p->flag = 1;
    u8* o = p->o;
    while (o) {
        u8* n = *(u8**)(o + 96);
        if (o) (*(void (**)(void*))(*(u8**)o + 4))(o);
        o = n;
    }
    p->f16 = 0;
    p->o = 0;
}
} // n00199cd0

// 00199d38 (from src/anon/batch_w64.cpp)
namespace n00199d38 {
s32 func_00199810(u8*) asm("func_00199810");
void YS__OBJENTRY__ReadRequest(u32, s32, s32) asm("YS__OBJENTRY__ReadRequest");
void func_00199d38(u8* p) asm("func_00199d38");
void func_00199d38(u8* p) {
    for (s32 i = 0; i < *(u16*)(*(u8**)(p + 8) + 4); i++) {
        if (func_00199810(*(u8**)(p + 8) + i * 64 + 44))
            YS__OBJENTRY__ReadRequest(*(u32*)(*(u8**)(p + 8) + i * 64 + 44), -1, 30);
    }
}
} // n00199d38

// 00199dc0 (from src/anon/batch_w1962_nsa.cpp)
namespace n00199dc0 {
struct W1962Nd { u8 p[0x60]; W1962Nd* next; };
struct W1962Ent { u16 f0; u16 kind; u8 p4[0x3c]; };
struct W1962Ev { u32 id; u8 p4[0x18]; u8 mode; u8 p1d; u16 arg; u8 p20[0x20]; };
struct W1962Hdr { u8 type; u8 p1; u16 n2; u16 nev; u16 nent; };
struct W1962Chr { u8 p[4]; u8 kind; };
struct W1962Lst { W1962Nd* head; W1962Nd* tail; };
struct W1962Obj { u32 f0; u32 fl; W1962Hdr* hdr; W1962Lst lst; u32 f14; u32 f18; u32 f1c; u32 f20; W1962Ev* ev; W1962Ent* ent; };
W1962Nd* YS__ZONE__Create(W1962Ent*) asm("YS__ZONE__Create");
s32 func_00199810(W1962Ev*) asm("func_00199810");
W1962Chr* GetCharaData_0016e920(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 Ti__MGObj__IsInitAppear(W1962Chr*) asm("Ti__MGObj__IsInitAppear");
void func_00199f90(W1962Obj*, W1962Ev*) asm("func_00199f90");
void func_0019ab30(W1962Obj*, u16) asm("func_0019ab30");
void func_00199dc0(W1962Obj* o) asm("func_00199dc0");
void func_00199dc0(W1962Obj* o) {
    s32 i;
    W1962Ev* e = o->ev;
    o->fl |= 2;
    for (i = 0; i < o->hdr->nent; i++) {
        if (o->hdr->type == 6 || (u32)(o->ent[i].kind - 3) >= 2) {
            W1962Lst* l = &o->lst;
            W1962Nd* n = YS__ZONE__Create(&o->ent[i]);
            if (l->tail == 0) {
                l->tail = n;
                o->lst.head = n;
                n->next = 0;
            } else {
                l->tail->next = n;
                n->next = 0;
                l->tail = n;
            }
        }
    }
    o->f1c = 0;
    o->f18 = 0;
    if (o->hdr->type != 9) {
        for (s32 j = 0; j < o->hdr->nev; j++, e++) {
            if (func_00199810(e)) {
                W1962Chr* c = GetCharaData_0016e920(e->id);
                if (c->kind != 16 || Ti__MGObj__IsInitAppear(c)) {
                    switch (e->mode) {
                    case 0: case 1: case 3:
                        func_00199f90(o, e);
                        break;
                    case 2:
                        switch (c->kind) {
                        case 4: case 21:
                            func_0019ab30(o, e->arg);
                            break;
                        case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
                        case 15: case 16: case 17: case 18: case 19: case 20: case 22: case 23:
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }
}
} // n00199dc0

// 00199f90 (from src/anon/batch_w242.cpp)
namespace n00199f90 {
char* func_0016e920(u32) asm("func_0016e920");
u32 func_00199810(char*) asm("func_00199810");
u32 func_0019ab30(char*, u32) asm("func_0019ab30");
void func_00199938(char*, char*) asm("_ZNK2YS13UNIT_DATA_OBJ6appearEPNS_10UNIT_GROUPE");
void func_00199f90(char* t, char* s) asm("func_00199f90");
void func_00199f90(char* t, char* s) {
    u32 w = *(u32*)(t + 4);
    u8 fl = w & 1;
    if (!fl) {
        char* r = func_0016e920(*(u32*)s);
        if (func_00199810(s)) {
            u32 v = *(u8*)(r + 4);
            if (v == 4 || v == 21) {
                if (func_0019ab30(t, *(u16*)(s + 30)))
                    func_00199938(s, t);
            } else {
                func_00199938(s, t);
                asm volatile("" ::: "memory");
            }
        }
    }
}
} // n00199f90

// 0019a048 (from src/anon/batch_w100.cpp)
namespace n0019a048 {
struct Sub15 { void** vt; u8 pad[92]; Sub15* next; u8 pad2[8]; u8* info; };
struct Obj15 { u32 f0; u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1; u32 b4 : 1; u32 rest : 27; u8* type; Sub15* head; u32 pad; f32 timer; };
static inline bool Off15(Obj15* o) { return o->b0; }
static inline Sub15* Next15(Obj15* o, Sub15* p) {
    if (!p) return o->head;
    return p->next;
}
extern f32 D_00349e10 asm("D_00349e10");
void func_0019b180(Obj15*, u32) asm("func_0019b180");
s32 func_00191a50(Obj15*, u32) asm("func_00191a50");
s32 func_0019a1a0(Obj15*, Sub15*) asm("func_0019a1a0");
void func_0019a048(Obj15* o, u32 arg) asm("func_0019a048");
void func_0019a048(Obj15* o, u32 arg) {
    Sub15* p;
    o->b3 = 0;
    o->b4 = 0;
    if (Off15(o)) return;
    if (*o->type == 4) {
        func_0019b180(o, arg);
        return;
    }
    if (func_00191a50(o, arg)) return;
    if (o->timer > 0.0f) o->timer -= D_00349e10;
    p = 0;
    while ((p = Next15(o, p)) != 0) {
        if (*o->type == 6 && *(u16*)(p->info + 44) != 1) continue;
        if (((s32 (*)(Sub15*, u32))p->vt[2])(p, arg)) {
            o->b3 = 1;
            if (func_0019a1a0(o, p)) return;
        }
    }
}
} // n0019a048

// 0019a1a0 (from src/anon/batch_w1809_nsa.cpp)
namespace n0019a1a0 {
struct W1809S19a1 { u8 type; u8 pad; u16 h2; };
struct W1809O19a1 { u8 pad[8]; W1809S19a1* p; };
s32 func_0019a480() asm("func_0019a480");
void func_0019a808() asm("func_0019a808");
void func_0019af98() asm("func_0019af98");
void func_0019b4d0() asm("func_0019b4d0");
void func_0019b500() asm("func_0019b500");
void func_0019b5d8() asm("func_0019b5d8");
void Ti__ACTION_PO_JUMP__exec_jump() asm("Ti__ACTION_PO_JUMP__exec_jump");
extern u8* D_0034e948 asm("D_0034e948");
s32 func_0019a1a0(W1809O19a1* o, s32 a1) asm("func_0019a1a0");
s32 func_0019a1a0(W1809O19a1* o, s32 a1) {
    W1809S19a1* p = o->p;
    switch (p->type) {
    case 1:
        if (a1 == 0 || func_0019a480() == 0) return 0;
        break;
    case 2: func_0019a808(); break;
    case 3: func_0019af98(); break;
    case 6: func_0019b500(); break;
    case 7:
        if (a1 == 0) break;
        func_0019b4d0(); return 0;
    case 8:
        if (a1 == 0) break;
        func_0019b5d8();
        break;
    case 9: Ti__ACTION_PO_JUMP__exec_jump(); break;
    case 10: *(s32*)(D_0034e948 + 0xb4c) = p->h2; break;
    }
    return 1;
}
} // n0019a1a0

// 0019a288 (gap, never written before)
namespace n0019a288 {
struct N { u8 pad[96]; N* next; };
struct O { u32 id; u32 x; u32 y; N* head; };
s32 func_002cebb0(O*) asm("func_002cebb0");
s32 func_002ceb08(void) asm("func_002ceb08");
s32 func_002cebc8(u32) asm("func_002cebc8");
void func_002cec50(N*) asm("func_002cec50");
static inline N* Next(O* o, N* p) { return !p ? o->head : p->next; }
static inline void Each(O* o, N* p) {
    while ((p = Next(o, p)) != 0) func_002cec50(p);
}
void func_0019a288(O* o) asm("func_0019a288");
void func_0019a288(O* o) {
    if (!func_002cebb0(o)) return;
    if (func_002ceb08() == 4) return;
    N* p = 0;
    if (!func_002cebc8(o->id)) return;
    Each(o, p);
}
} // n0019a288

// 0019a308 (from src/anon/batch_wcx2.cpp)
namespace n0019a308 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct Hdr39 { u8 pad[4]; u16 nb; u16 na; };
struct Ref39 { u8 pad[44]; u16 k; };
struct It40 { u8 pad[16]; Ref39* r; u8 pad2[16]; s32 cnt; };
struct Ent39 { u8 pad[32]; s32 k; };
struct Obj39 { u32 p0; u32 pad; u32 hh; u8 pad2[28]; u8* p40; };
s32 func_002ceb08(Obj39*) asm("func_002ceb08");
s32 func_002cebc8(u32) asm("func_002cebc8");
u8* Ti__MGObj__find_free_member_buffer(u32) asm("Ti__MGObj__find_free_member_buffer");
It40* func_002cf8c0(u8*, u32, Obj39*, u8*) asm("func_002cf8c0");
void func_002cf750__39(u32, Obj39*, Ent39*, It40*, It40*) asm("func_002cf750");
void func_0019a308(Obj39* o) asm("func_0019a308");
void func_0019a308(Obj39* o)
{
    if (func_002ceb08(o) == 4) return;
    if (!func_002cebc8(o->p0)) return;
    It40* first = 0;
    u8* base = Ti__MGObj__find_free_member_buffer(((Hdr39*)o->hh)->na);
    for (s32 i = 0; i < ((Hdr39*)o->hh)->na; i++) {
        It40* it = func_002cf8c0(base + i, o->p0, o, o->p40 + i * 64);
        it->cnt = 1;
        if (i == 0) first = it;
    }
    for (s32 i = 0; i < ((Hdr39*)o->hh)->nb; i++) {
        Ent39* e = (Ent39*)((u8*)o->hh + i * 64 + 44);
        It40* a = 0;
        It40* b = 0;
        if (first && e->k) {
            a = &first[e->k - 1];
            if (a->r->k) b = &first[a->r->k - 1];
        }
        func_002cf750__39(o->p0, o, e, a, b);
    }
    for (s32 i = 0; i < ((Hdr39*)o->hh)->na; i++) first[i].cnt--;
}
} // n0019a308

// 0019a480 (from src/anon/batch_w1568.cpp)
namespace n0019a480 {
struct Key_w1568 { u8 a, b, c; u8 pad; u16 d, e, f; };
struct Info_w1568 { u8 pad[0x1c]; u8 kind; u8 sub; u8 id; };
struct Obj_w1568_9a { u32 pad; union { u32 flags; struct { u32 b0:1; u32 :31; }; }; Info_w1568* info; };
struct Sub_w1568 { u16 a; u16 type; };
struct Ctx_w1568 { u8 pad[0x6c]; Sub_w1568* sub; };
extern u8 D_0032bae0 asm("D_0032bae0");
s32 func_001917b0(void) asm("func_001917b0");
s32 func_00196768(u8, u8) asm("func_00196768");
void func_0019a610(Obj_w1568_9a*, Key_w1568*, s32) asm("func_0019a610");
s32 YS__UNIT_GROUP__jump_area(Obj_w1568_9a*, Key_w1568*, Sub_w1568*, s32, s32) asm("YS__UNIT_GROUP__jump_area");
s32 func_001db198(Ctx_w1568*, u8) asm("func_001db198");
s32 func_0019a480(Obj_w1568_9a* p, Ctx_w1568* c) asm("func_0019a480");
s32 func_0019a480(Obj_w1568_9a* p, Ctx_w1568* c)
{
    s32 two = 0;
    Key_w1568 k;
    u16 m = 0xffff;
    k.a = m; k.b = m; k.c = m; k.d = m; k.e = m; k.f = m;
    s32 v = func_001917b0() ^ 2;
    if (v == 0 && p->info->id != 0) return 0;
    Info_w1568* info = p->info;
    switch (info->kind) {
    case 100: k.a = 18; k.b = 1; break;
    case 101: k.a = 2; k.b = 40; break;
    default: k.a = D_0032bae0; k.b = info->kind; break;
    }
    k.c = info->sub;
    s32 r = func_00196768(k.a, k.b);
    switch (c->sub->type) {
    case 0: {
        u8 bb = p->b0;
        if (!bb && r == 0 && func_001db198(c, p->info->id)) {
            func_0019a610(p, &k, 0);
            p->flags |= 1;
        }
        break;
    }
    case 2:
        two = 1;
    case 1:
        if (!(p->flags & 0x10) && YS__UNIT_GROUP__jump_area(p, &k, c->sub, r == 0, two)) p->flags |= 0x10;
        break;
    }
    return 0;
}
} // n0019a480

// 0019a610 (from src/anon/batch_w68.cpp)
namespace n0019a610 {
struct Rec5 { s16 h[5]; };
extern Rec5 D_0032bb00 asm("D_0032bb00");
extern u8 D_0032bae0 asm("D_0032bae0");
s32 func_001991a8(u32, u32) asm("func_001991a8");
void AREA__MapJump(void*, u32, u32, u32, u32) asm("AREA__MapJump");
union Obj5b { struct { u32 f0, f4; u16* info; } s; s16 h[6]; };
void func_0019a610(Obj5b* o, Rec5* src) asm("func_0019a610");
void func_0019a610(Obj5b* o, Rec5* src) {
    D_0032bb00 = *src;
    if (func_001991a8(1, o->s.info[1]) == 0) {
        u32 a = 0, b = 0;
        if (D_0032bae0 != *(u8*)src) { a = 1; b = 1; }
        AREA__MapJump(&D_0032bb00, a, 0, 0, b);
    }
    o->s.f4 |= 1;
}
} // n0019a610

// 0019a6c0 (from src/anon/batch_w1879_nsa.cpp)
namespace n0019a6c0 {
struct V4 { f32 x, y, z, w; V4() {} V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
extern void* D_0034e948 asm("D_0034e948");
V4* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
void YS__OBJ__get_dir(V4*, void*) asm("YS__OBJ__get_dir");
void func_0015b1b0(u8, u8, u8) asm("func_0015b1b0");
void func_0015b268(f32, s32) asm("func_0015b268");
s32 func_001967f0(u8, u8, s32) asm("func_001967f0");
static inline f32 vnorm(V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
s32 YS__UNIT_GROUP__jump_area(void* self, u8* ids, f32* pos, u8 flag, u8 arg) asm("YS__UNIT_GROUP__jump_area");
s32 YS__UNIT_GROUP__jump_area(void* self, u8* ids, f32* pos, u8 flag, u8 arg) {
    f32 z = 0.0f;
    void* obj = D_0034e948;
    V4 v(pos[1], z, pos[3], z);
    V4* r = YS__OBJ__get_pos(obj);
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "r"(r) : "memory");
    v.y = z;
    vnorm(&v);
    V4 w;
    YS__OBJ__get_dir(&w, obj);
    f32 dot;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(dot) : "r"(&v), "r"(&w) : "$8", "memory");
    if (dot >= z) {
        if (flag) func_0015b1b0(ids[1], ids[0], arg);
        else func_0015b268(6.0f, func_001967f0(ids[0], ids[1], 0));
        return 1;
    }
    return 0;
}
} // n0019a6c0

// 0019a808 (from src/anon/batch_w1965_nsa.cpp)
namespace n0019a808 {
#define W1965cQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965cV {
    f32 x, y, z, w;
    W1965cV() {}
    W1965cV(const W1965cV& o) { W1965cQCOPY(this, &o); }
    W1965cV& operator=(const W1965cV& o) { if (this != &o) W1965cQCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1965cHdr { u8 pad[24]; u8 type; u8 mode; u16 id; };
struct W1965cEnt { s32 a; f32 x, y, z; u8 pad[12]; u8 type; u8 mode; u16 id; u8 pad2[10]; u16 delay; u8 pad3[2]; u16 r; u8 lvl; u8 pad4[15]; };
struct W1965cTbl { u8 pad[4]; u16 count; u8 pad2[38]; W1965cEnt ent[1]; };
struct W1965cObj { u8 pad[8]; W1965cTbl* tbl; u8 pad2[8]; f32 timer; u8 pad3[8]; u8 level; };
extern u8 D_0034f250[] asm("D_0034f250");
s32 func_0016b7a0(u16) asm("func_0016b7a0");
s32 func_00195700(u8*, u16) asm("func_00195700");
s32 func_00199890(W1965cEnt*, W1965cObj*, W1965cV*) asm("func_00199890");
s32 func_00199938(W1965cEnt*, W1965cObj*) asm("func_00199938");
s32 func_0019ac80(W1965cObj*) asm("func_0019ac80");
W1965cV YS__UNIT_GROUP__RandomPosPlayer(s32) asm("YS__UNIT_GROUP__RandomPosPlayer");
W1965cV func_0019b0e8(s32, W1965cV*, f32, f32) asm("func_0019b0e8");
void func_0019a808(W1965cObj* o) asm("func_0019a808");
void func_0019a808(W1965cObj* o)
{
    s32 i;
    do {
        do {
            for (i = 0; i < o->tbl->count; i++) {
                if (0.0f < o->timer) return;
                W1965cHdr* s = (W1965cHdr*)((i << 6) + (u32)o->tbl + 48);
                u8 type = s->type;
                u16 id = s->id;
                if (type == 2) {
                    s32 r;
                    if (func_0016b7a0(id)) continue;
                    if (func_00195700(D_0034f250, id)) continue;
                    if (o->level < o->tbl->ent[i].lvl) continue;
                    W1965cV v;
                    switch (o->tbl->ent[i].mode) {
                    case 1:
                        v = YS__UNIT_GROUP__RandomPosPlayer(o->tbl->ent[i].a);
                        r = func_00199890(&o->tbl->ent[i], o, &v);
                        break;
                    case 2:
                        v.x = o->tbl->ent[i].x;
                        v.y = o->tbl->ent[i].y;
                        v.z = o->tbl->ent[i].z;
                        v = func_0019b0e8(o->tbl->ent[i].a, &v, (f32)o->tbl->ent[i].r, 0.0f);
                        r = func_00199890(&o->tbl->ent[i], o, &v);
                        break;
                    case 0:
                    default:
                        r = func_00199938(&o->tbl->ent[i], o);
                        break;
                    }
                    if (r) o->timer = (f32)o->tbl->ent[i].delay;
                }
            }
        } while (!(o->timer <= 0.0f));
    } while (func_0019ac80(o));
}
} // n0019a808

// 0019a9e0 (from src/anon/tiny_auto80_queue.cpp)
namespace n0019a9e0 {
u32 func_0019a9e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0019a9e0");
u32 func_0019a9e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(u32*)((u32)r5 + (s32)(2076));
    r2 = 0u;
    if (r14 != 0u) {
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(48)));
        r15 = ((u32)r15 < 0x00000064u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
} // n0019a9e0

// 0019aa00 (from src/anon/batch_w45.cpp)
namespace n0019aa00 {
struct BF { u32 f0; u32 flag : 1; };
s32 func_0019a9e0(u8*, u8*) asm("func_0019a9e0");
void func_0019ab80(u8*) asm("func_0019ab80");
void func_0019aa00(BF* a0, u8* a1) asm("func_0019aa00");
void func_0019aa00(BF* a0, u8* a1) {
    if ((u8)a0->flag) return;
    if (!(*(u32*)(a1 + 1416) & 0x800)) return;
    if (func_0019a9e0((u8*)a0, a1)) return;
    func_0019ab80((u8*)a0);
}
} // n0019aa00

// 0019aa60 (from src/anon/batch_w89.cpp)
namespace n0019aa60 {
extern u8 D_0034f250 asm("D_0034f250");
s32 func_0019a9e0(u8*, u8*) asm("func_0019a9e0");
u32 func_0016bff0(u8*) asm("func_0016bff0");
void func_001956e8(u8*, u32) asm("func_001956e8");
s32 func_0016bf20(u8*) asm("func_0016bf20");
void func_0019ab80(u8*) asm("func_0019ab80");
void func_0019aa60(u8* o, u8* e) asm("func_0019aa60");
void func_0019aa60(u8* o, u8* e) {
    if (*(u32*)(e + 2040) & 4) {
        if (func_0019a9e0(o, e)) func_001956e8(&D_0034f250, func_0016bff0(e));
    } else {
        func_001956e8(&D_0034f250, func_0016bff0(e));
        s32 r = func_0016bf20(e);
        if (r >= 0 && (r < 2 || r == 3) && (*(u32*)(e + 1416) & 0x800)) func_0019ab80(o);
    }
    *(f32*)(o + 20) = *(u16*)(*(u8**)(o + 8) + 32);
}
} // n0019aa60

// 0019ab30 (from src/anon/batch_w24.cpp)
namespace n0019ab30 {
s32 func_00195700(void*) asm("func_00195700");
extern u8 D_0034f250 asm("D_0034f250");
s32 func_0019ab30(s32* p) asm("func_0019ab30");
s32 func_0019ab30(s32* p) {
    if (!func_00195700(&D_0034f250)) {
        s32 v = p[7] + 1;
        p[7] = v;
        p[6] = v;
        return 1;
    }
    return 0;
}
} // n0019ab30

// 0019ab80 (from src/anon/auto80_199_queue.cpp)
namespace n0019ab80 {
void func_0019ab80(u32 a0) asm("func_0019ab80");
void func_0019ab80(u32 a0) {
    u32 t7 = *(u32*)(a0 + 4);
    u8 t6 = (u8)(t7 & 1);
    if (t6 != 0) {
        return;
    }

    t7 = *(u32*)(a0 + 24);
    t7 = t7 - 1;
    *(u32*)(a0 + 24) = t7;
    if (t7 == 0) {
        func_001991a8(3, *(u16*)(*(u32*)(a0 + 8) + 2));
    }

    if (func_0019abe8() != 0) {
        return;
    }

    func_001991a8(2, 0);
}
} // n0019ab80

// 0019abe8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0019abe8 {
extern u8 D_00350440 asm("D_00350440");
extern u8 D_01c62198 asm("D_01c62198");
u32 func_0019abe8(void) asm("func_0019abe8");
u32 func_0019abe8(void) {
    u32 t7 = *(u32*)((u32)&D_00350440 + (s32)(0));
    u32 v0 = 0u;
    if ((s32)t7 > 0) {
        u32 t6 = t7;
        t7 = (u32)&D_01c62198;
        u32 t5 = (u32)((s32)t7 + (24));
        do {
            t7 = *(u32*)((u32)t5 + (s32)(0));
            t6 = (u32)((s32)t6 + (-1));
            v0 = (u32)(v0 + t7);
            t5 = (u32)((s32)t5 + (56));
        } while (t6 != 0u);
    }
    return v0;
}
} // n0019abe8

// 0019ac30 (from src/anon/tiny_auto80_queue.cpp)
namespace n0019ac30 {
u32 func_00195700(...) asm("func_00195700");
u32 func_0016b7a0(...) asm("func_0016b7a0");
extern u8 D_0034f250 asm("D_0034f250");
u32 func_0019ac30(u32 a0, u32 a1) asm("func_0019ac30");
u32 func_0019ac30(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = 0u;
    if (func_00195700((u32)&D_0034f250) != 0u) {
        u32 v0 = func_0016b7a0(s0);
        s1 = (u32)(v0 < 1u);
    }
    return s1;
}
} // n0019ac30

// 0019ac80 (from src/anon/batch_w64.cpp)
namespace n0019ac80 {
s32 func_0019ad58(u8*) asm("func_0019ad58");
void func_0019ae60(u8*) asm("func_0019ae60");
s32 func_0019ad00(u8*, u8) asm("func_0019ad00");
s32 func_0019ac80(u8* p) asm("func_0019ac80");
s32 func_0019ac80(u8* p) {
    if (p[32] >= 200) return 0;
    s32 n = func_0019ad58(p);
    if ((*(u8**)(p + 8))[34] < n) return 0;
    while (1) {
        func_0019ae60(p);
        if (func_0019ad00(p, p[32])) return 1;
        if (p[32] >= 200) return 0;
    }
}
} // n0019ac80

// 0019ad00 (from src/anon/batch_w2365.cpp)
namespace n0019ad00 {
struct W2365_Ent { u8 type; u8 pad1[0x13]; u8 id; u8 pad2[0x2b]; };
struct W2365_Tbl { u8 pad0[4]; u16 count; u8 pad1[0x42]; W2365_Ent e[1]; };
struct W2365_Own { u8 pad0[8]; W2365_Tbl* tbl; };
s32 func_0019ad00(W2365_Own* o, s32 id) asm("func_0019ad00");
s32 func_0019ad00(W2365_Own* o, s32 id)
{
    for (s32 i = 0; i < o->tbl->count; i++) {
        if (o->tbl->e[i].type == 2 && o->tbl->e[i].id == id) return 1;
    }
    return 0;
}
} // n0019ad00

// 0019ad58 (from src/anon/batch_w88.cpp)
namespace n0019ad58 {
struct E19ad58 { u8 pad[12]; u32 obj; u8 pad2[24]; u8 kind; u8 pad3; u16 id; u8 pad4[16]; u8 lv; u8 pad5[3]; };
struct T19ad58 { u8 pad[4]; u16 n; u8 pad2[26]; E19ad58 e[1]; };
s32 func_0019ac30(u8*, u16) asm("func_0019ac30");
u8* func_0016e920(u32) asm("func_0016e920");
#define TAB19ad58 (*(T19ad58**)(p + 8))
s32 func_0019ad58(u8* p) asm("func_0019ad58");
s32 func_0019ad58(u8* p) {
    s32 sum = 0;
    for (s32 i = 0; i < TAB19ad58->n; i++) {
        switch (TAB19ad58->e[i].kind) {
        case 2:
            if (p[32] < TAB19ad58->e[i].lv) continue;
            break;
        case 0:
        case 3:
            break;
        default:
            continue;
        }
        if (!func_0019ac30(p, TAB19ad58->e[i].id)) sum += *(u8*)(func_0016e920(TAB19ad58->e[i].obj) + 84);
    }
    return sum;
}
} // n0019ad58

// 0019ae60 (from src/anon/batch_w26.cpp)
namespace n0019ae60 {
void func_0019aec0(void*, u8) asm("func_0019aec0");
void func_0019ae60(u8* p) asm("func_0019ae60");
void func_0019ae60(u8* p) {
    if (p[32] < 200) {
        p[32]++;
        u8* d = *(u8**)(p + 8);
        if (d[35] && p[32] >= d[35]) func_0019aec0(p, d[36]);
    }
}
} // n0019ae60

// 0019aec0 (from src/anon/batch_w77.cpp)
namespace n0019aec0 {
extern u8 D_0034f250 asm("D_0034f250");
s32 func_0019ac30(void*, u16) asm("func_0019ac30");
void func_001956e8(void*, u16) asm("func_001956e8");
struct Rec { u8 pad[30]; u16 id; u8 pad2[16]; u8 lv; u8 pad3[15]; };
struct Def { u8 pad[72]; u8 kind; u8 pad2[63]; };
struct Tbl { u8 pad[4]; u16 count; u8 pad2[2]; Def d[1]; };
struct Own { u8 pad[8]; Tbl* tbl; u8 pad2[20]; u8 lv; u8 pad3[3]; Rec* recs; };
void func_0019aec0(Own* p, s32 lv) asm("func_0019aec0");
void func_0019aec0(Own* p, s32 lv)
{
    for (s32 i = 0; i < p->tbl->count; i++) {
        if (*((u8*)p->tbl + i * 64 + 72) != 2) continue;
        if (p->recs[i].lv < lv) continue;
        if (func_0019ac30(p, p->recs[i].id))
            func_001956e8(&D_0034f250, p->recs[i].id);
    }
    p->lv = lv;
}
} // n0019aec0

// 0019af98 (from src/anon/batch_w19.cpp)
namespace n0019af98 {
void func_001991a8(u32, u32) asm("func_001991a8");
void func_0019af98(u8* p) asm("func_0019af98");
void func_0019af98(u8* p) {
    u8* t = *(u8**)(p + 8);
    func_001991a8(*(u32*)(t + 28), *(u16*)(t + 2));
    *(u32*)(p + 4) |= 1;
}
} // n0019af98

// 0019afd8 (from src/anon/batch_w97.cpp)
namespace n0019afd8 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Unit19b { u8 pad[72]; u16 f0 : 3; u16 big : 1; u16 rest : 12; bool isBig() { return big; } };
extern u32 D_0034e948 asm("D_0034e948");
const Vq* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
Unit19b* func_0016e920(u32) asm("func_0016e920");
Vq func_001a78c0(const Vq*, u32, f32, f32, f32, f32) asm("func_001a78c0");
Vq func_001a7888(const Vq*, u32, f32, f32) asm("func_001a7888");
Vq YS__UNIT_GROUP__RandomPosPlayer(u32 u) asm("YS__UNIT_GROUP__RandomPosPlayer");
Vq YS__UNIT_GROUP__RandomPosPlayer(u32 u) {
    Vq r;
    r = *YS__OBJ__get_pos(D_0034e948);
    r.y += -200.0f;
    if (func_0016e920(u)->isBig()) {
        r = func_001a78c0(&r, 0x10002, 150.0f, 450.0f, -100.0f, 100.0f);
    } else {
        r = func_001a7888(&r, 0x10001, 150.0f, 450.0f);
    }
    return r;
}
} // n0019afd8

// 0019b0e8 (from src/anon/batch_w55.cpp)
namespace n0019b0e8 {
u8* func_0016e920(u32) asm("func_0016e920");
void func_001a78c0(u8*, u32, s32, f32, f32, f32, f32) asm("func_001a78c0");
void func_001a7888(u8*, u32, s32, f32, f32, f32, f32) asm("func_001a7888");
u8* func_0019b0e8(u8* a, u32 b, u32 c, f32 f, f32 g) asm("func_0019b0e8");
u8* func_0019b0e8(u8* a, u32 b, u32 c, f32 f, f32 g) {
    u8* o = func_0016e920(b);
    if ((u8)((*(u16*)(o + 72) >> 3) & 1)) func_001a78c0(a, c, 2, 0.0f, f, -g, g);
    else func_001a7888(a, c, 1, 0.0f, f, -g, g);
    return a;
}
} // n0019b0e8

// 0019b180 (from src/anon/batch_w83.cpp)
namespace n0019b180 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
s32 func_0016bff0(void*) asm("func_0016bff0");
struct VTest { virtual void f0(); virtual void f4(); virtual s32 test(QWord*); u8 pad[92]; VTest* next; };
u8* func_00186078(u8*) asm("func_00186078");
QWord* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_001991a8(s32, u32) asm("func_001991a8");
void func_0019b180(u8* p) asm("func_0019b180");
void func_0019b180(u8* p) {
    QWord v;
    u8* it = 0;
    while ((it = func_00186078(it))) {
        v = *YS__OBJ__get_pos(it);
        VTest* o = 0;
        while ((o = !o ? *(VTest**)(p + 12) : o->next)) {
            if (o->test(&v)) {
                if ((*(u32*)(it + 2728) & ~0x10000) != *(u16*)(*(u8**)(p + 8) + 2)) {
                    func_001991a8(*(s32*)(*(u8**)(p + 8) + 28), func_0016bff0(it));
                }
                *(u32*)(it + 2728) = *(u16*)(*(u8**)(p + 8) + 2);
                break;
            }
        }
    }
}
} // n0019b180

// 0019b260 (from src/anon/batch_w35.cpp)
namespace n0019b260 {
struct E56 { u32 a, b; u16* p; u8 pad[44]; };
extern s32 D_00350440 asm("D_00350440");
extern E56 D_01c62198[] asm("D_01c62198");
u32 ctarget_0019b260(u32 id, u32, u32, u32) asm("_Z16ctarget_0019b260jjjj");
u32 ctarget_0019b260(u32 id, u32, u32, u32) {
    for (s32 i = 0; i < D_00350440; i++) {
        E56* e = &D_01c62198[i];
        if (e->p[1] == id) return (u32)e;
    }
    return 0;
}
} // n0019b260

// 0019b2b0 (from src/yasui/libys/unitgroup.cpp, YS::UNIT_GROUP::Disable)
namespace n0019b2b0 {
u32 func_0019b260(u32) asm("func_0019b260");
u32 UG_Disable(s32 group) asm("_ZN2YS10UNIT_GROUP7DisableEi");
u32 UG_Disable(s32 group) {
    u32 r2 = func_0019b260((u32)group);
    u32 r15 = *(u32*)((u32)r2 + (s32)(4));
    r15 = (u32)(r15 | 0x0001u);
    *(u32*)((u32)r2 + (s32)(4)) = r15;
    return r2;
}
} // n0019b2b0

// 0019b2d8 (from src/anon/batch_w9.cpp)
namespace n0019b2d8 {
u8* func_0019b260(void*, s32) asm("func_0019b260");
void group_enable(void* g, s32 i) asm("_ZN2YS10UNIT_GROUP6EnableEi");
void group_enable(void* g, s32 i) {
    u8* u = func_0019b260(g, i);
    *(u32*)(u + 4) &= ~1;
}
} // n0019b2d8

// 0019b308 (from src/yasui/libys/unitgroup.cpp, YS::UNIT_GROUP::get_rtn_param)
namespace n0019b308 {
u32 UG_get_rtn_param(u8* self) asm("_ZN2YS10UNIT_GROUP13get_rtn_paramEv");
u32 UG_get_rtn_param(u8* self) {
    u32 r15 = *(u32*)((u32)self + (s32)(8));
    u32 r14 = 6u;
    u32 r13 = (u32)(*(u8*)((u32)r15 + (s32)(0)));
    u32 r2 = 0u;
    if (r13 == r14) {
        r2 = *(u32*)((u32)self + (s32)(48));
    }
    return r2;
}
} // n0019b308

// 0019b328 (from src/anon/batch_w28.cpp)
namespace n0019b328 {
u8* func_0019b328(u8* p, s32 id) asm("func_0019b328");
u8* func_0019b328(u8* p, s32 id) {
    u16* e = *(u16**)(p + 0x2c);
    for (s32 i = 0; i < *(u16*)(*(u8**)(p + 8) + 8); i++) {
        if (id < 0 || e[0] == id) return (u8*)e;
        e = (u16*)((u8*)e + e[1] * 12 + 8);
    }
    return 0;
}
} // n0019b328

// 0019b380 (from src/anon/batch_w25.cpp)
namespace n0019b380 {
struct O19b { u8 pad[8]; u8* hdr; u8 pad2[32]; u8* first; };
u8* func_0019b380(O19b* o, u32 id) asm("func_0019b380");
u8* func_0019b380(O19b* o, u32 id) {
    s32 i;
    u8* e = o->first;
    for (i = 0; i < *(u16*)(o->hdr + 8); i++) {
        if (e[5] == id) return e;
        e = e + *(u16*)(e + 2) * 12 + 8;
    }
    return 0;
}
} // n0019b380

// 0019b3d0 (from src/anon/batch_w2436.c)
namespace n0019b3d0 {
struct N19b3d0;
struct Vt19b3d0 { void* f0; void* f4; s32 (*f8)(struct N19b3d0*, void*); };
struct I19b3d0 { u8 pad[0x2c]; u16 h2c; };
struct N19b3d0 { struct Vt19b3d0* vt; u8 pad[0x5c]; struct N19b3d0* next; u8 pad2[8]; struct I19b3d0* info; };
struct T19b3d0 { u8 type; };
struct O19b3d0 { u8 pad[8]; struct T19b3d0* t; struct N19b3d0* first; };
static inline struct N19b3d0* Next19b3d0(struct O19b3d0* o, struct N19b3d0* p) {
    return !p ? o->first : p->next;
}
struct N19b3d0* func_0019b3d0(struct O19b3d0* o, void* arg) asm("func_0019b3d0");
struct N19b3d0* func_0019b3d0(struct O19b3d0* o, void* arg) {
    struct N19b3d0* r;
    struct N19b3d0* p;
    if (o->t->type == 6) goto L;
    r = 0;
RET:
    return r;
L:
    p = 0;
    while ((p = Next19b3d0(o, p)) != 0) {
        if (p->info->h2c == 0 && p->vt->f8(p, arg)) { r = p; goto RET; }
    }
    r = 0;
    goto RET;
}
} // n0019b3d0

// 0019b478 (gap)
namespace n0019b478 {
struct S16 { u32 a, b, c, d; void reset() { c = d; } };
struct E56 { u8 pad[16]; S16 s; u8 pad2[24]; };
extern s32 D_00350440 asm("D_00350440");
extern E56 D_01c62198[] asm("D_01c62198");
extern u8 D_0034f250 asm("D_0034f250");
void func_00195720(void*) asm("func_00195720");
void func_0019b478(void) asm("func_0019b478");
void func_0019b478(void) {
    for (s32 i = 0; i < D_00350440; i++) {
        E56* e = &D_01c62198[i];
        S16* p = &e->s;
        p->c = p->d;
    }
    func_00195720(&D_0034f250);
}
} // n0019b478

// 0019b4d0 (from src/anon/tiny_wrappers_more.cpp)
namespace n0019b4d0 {
u32 func_001cec70(u32, u32, u32, u32) asm("func_001cec70");
u32 func_0019b4d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0019b4d0");
u32 func_0019b4d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001cec70(a1, ((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 8u)))) + 28u))), ((u32)(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a1) + 108u)))) + 40u)))) & 0x1u), a3);
}
} // n0019b4d0

// 0019b500 (from src/anon/batch_w78.cpp)
namespace n0019b500 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
struct W78Sub { u8 pad[24]; u8 kind; u8 p25; u16 id; u8 pad2[12]; };
struct W78Ent64 { u32 x0; W78Sub s; u8 pad[20]; };
struct W78List { u8 pad[4]; u16 n; u8 pad2[38]; W78Ent64 e[1]; };
s32 func_0016b7a0(u16) asm("func_0016b7a0");
u8* func_00199938(W78Ent64*, void*) asm("func_00199938");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
void func_0019b500(u8* o) asm("func_0019b500");
void func_0019b500(u8* o) {
    for (s32 i = 0; i < (*(W78List**)(o + 8))->n; i++) {
        W78Sub* s = (W78Sub*)((u8*)(i * 64) + (u32)*(W78List**)(o + 8) + 48);
        if (s->kind == 2 && !func_0016b7a0(s->id)) {
            u8* r = func_00199938(&(*(W78List**)(o + 8))->e[i], o);
            if (!(*(u32*)(r + 2040) & 0x10)) func_001ad990(r + 2092, 0.0f, 1.0f, 10.0f);
        }
    }
}
} // n0019b500

// 0019b5d8 (from src/anon/auto80_199_queue.cpp)
namespace n0019b5d8 {
void func_0019b5d8(u32 a0, u32 a1) asm("func_0019b5d8");
void func_0019b5d8(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    u32 t6 = *(u32*)(a1 + 0x6c);
    u32 t7 = *(u8*)(t6 + 0x2e);
    if (t7 != 0) {
        if (func_0015f718(t7 - 1) == 0) {
            u32 t7b = *(u32*)(s0 + 0x6c);
            func_0015ee90(*(u8*)(t7b + 0x2e) - 1);
        }
        t6 = *(u32*)(s0 + 0x6c);
    }

    t7 = *(u8*)(t6 + 0x2f);
    if (t7 != 0) {
        if (func_0015f718(t7 - 1) != 0) {
            u32 t7b = *(u32*)(s0 + 0x6c);
            func_0015ee10(*(u8*)(t7b + 0x2f) - 1);
            return;
        }
    }
}
} // n0019b5d8

// 0019b668 (from src/anon/batch_w1647.cpp)
namespace n0019b668 {
struct W1647V4 {
    f32 x, y, z, w;
    W1647V4() {}
    W1647V4(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1647V4& operator=(const W1647V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1647V4 operator-(const W1647V4& o) const {
        W1647V4 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1647V4& operator-=(const W1647V4& o) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    f32 dot(const W1647V4& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1647V3 { f32 x, y, z; };
struct W1647Unit { u8 pad0[4]; W1647V3 pos; u8 pad10[0xe]; u16 id; u8 pad20[0x20]; };
struct W1647UnitHdr { u8 pad0[4]; u16 count; u8 pad6[0x16]; f32 range; u8 pad20[0xc]; W1647Unit units[1]; };
struct W1647Group { u8 pad0[8]; W1647UnitHdr* hdr; };
struct W1647Obj;
struct W1647ObjVt { void* f[8]; void (*kill)(W1647Obj*); };
struct W1647Obj { W1647ObjVt* vt; };
W1647Obj* func_0016b7a0(u16) asm("func_0016b7a0");
W1647V4* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
void YS__OBJ__get_dir(W1647V4*, void*) asm("YS__OBJ__get_dir");
s32 func_00195700(void*, u16) asm("func_00195700");
f32 fabsf(f32) asm("fabsf");
void W1647_appear(W1647Unit*, W1647Group*) asm("_ZNK2YS13UNIT_DATA_OBJ6appearEPNS_10UNIT_GROUPE");
extern void* D_0034e948 asm("D_0034e948");
extern u8 D_0034f250[] asm("D_0034f250");
void Ti__ACTION_PO_JUMP__exec_jump(W1647Group* g) asm("Ti__ACTION_PO_JUMP__exec_jump");
void Ti__ACTION_PO_JUMP__exec_jump(W1647Group* g)
{
    s32 i = 0;
    W1647UnitHdr* h = g->hdr;
    void* player = D_0034e948;
    W1647Unit* u = h->units;
    for (; i < h->count; i++, u++) {
        W1647V4 d;
        W1647Obj* o = func_0016b7a0(u->id);
        if (o != 0) {
            d = *YS__OBJ__get_pos(o) - *YS__OBJ__get_pos(player);
            f32 dist = fabsf((fabsf(d.x) > fabsf(d.z)) ? d.x : d.z);
            if (g->hdr->range < dist) {
                o->vt->kill(o);
            } else if (1000.0f < dist) {
                d.normalize();
                W1647V4 t;
                YS__OBJ__get_dir(&t, player);
                if (d.dot(t) < -0.7f) o->vt->kill(o);
            }
        } else if (func_00195700(D_0034f250, u->id) == 0) {
            f32 px = u->pos.x, py = u->pos.y, pz = u->pos.z;
            d.x = px; d.y = py; d.z = pz; d.w = 0.0f;
            d -= *YS__OBJ__get_pos(player);
            if (fabsf(d.x) > fabsf(d.z)) {
                if (!(fabsf(d.x) < g->hdr->range)) goto next;
            } else {
                if (!(fabsf(d.z) < g->hdr->range)) goto next;
            }
            {
                d.normalize();
                W1647V4 t;
                YS__OBJ__get_dir(&t, player);
                if (-0.7f < d.dot(t)) W1647_appear(u, g);
            }
        }
    next:
        h = g->hdr;
    }
}
} // n0019b668

// 0019b970 (from src/anon/batch_w1785.cpp)
namespace n0019b970 {
struct Sub19 { u32 a; u32 b; u32 c; u32 d; };
struct Elem19 { u32 x0; Sub19 s; u8 pad[36]; ~Elem19(); };
void func_00199cd0(Elem19*) asm("func_00199cd0");
inline Elem19::~Elem19() { func_00199cd0(this); }
extern Elem19 D_01c62198[64] asm("D_01c62198");
void wt19(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void wt19(u32 init, u32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        Elem19* e = D_01c62198;
        Sub19* p = &e->s;
        for (int i = 63; i != -1; i--) {
            p->a = 0;
            p->d = 0;
            p->c = 0;
            p = (Sub19*)((u8*)p + 56);
        }
    }
    if (prio == 0xffff && init == 0) {
        Elem19* a = D_01c62198;
        if (a) {
            Elem19* p = a + 64;
            Elem19* base = a;
        top:
            if (p == base) goto out;
            p--;
            func_00199cd0(p);
            goto top;
        out:;
        }
    }
}
} // n0019b970


// 0019ba20 (from src/anon/tiny_wrappers_more.cpp)
namespace n0019ba20 {
u32 func_0019b970(u32, u32, u32, u32) asm("func_0019b970");
u32 func_0019ba20(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0019ba20");
u32 func_0019ba20(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0019b970(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n0019ba20

// 0019ba40 (gap: _GLOBAL__D_ stub)
namespace n0019ba40 {
u32 func_0019b970(u32, u32, u32, u32) asm("func_0019b970");
u32 func_0019ba40(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0019ba40");
u32 func_0019ba40(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0019b970(0, 0x0000ffffu, a2, a3);
}
} // n0019ba40
