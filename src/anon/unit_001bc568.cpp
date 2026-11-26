#include "../common/types.h"
#include "../yasui/libys/commandmenu.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// .rodata 0x36dc48: command kind masks, read by 0x1bc9e8.
extern const u64 R_0036dc48[4] asm("D_0036dc48") = { 0x01000000ull, 0x02000000ull, 0x04000000ull, 0x08000000ull };

// ---- 001bc568 from src/anon/batch_w1828_nsa.cpp
namespace n001bc568 {
struct E1bc { u8 pad0[4]; s16 h4; u8 pad6[0x16]; u8 b1c; };
struct T1bc { u8 pad[8]; u32 f8; };
struct P1bc { u8 pad[0x1b1]; u8 b1b1; };
struct B1bc { u8 pad0[0xc]; T1bc* t; u8 pad10[0x48c - 0x10]; P1bc* p; u8 pad490[0x588 - 0x490]; u32 f588; u8 pad58c[0xb50 - 0x58c]; s32 mode; };
extern u8 D_00351eb8[] asm("D_00351eb8");
extern u8 D_00351ec0[] asm("D_00351ec0");
extern u32 D_0034f240 asm("D_0034f240");
s32 elem_is_menu(E1bc*) asm("_ZNK2YS12COMMAND_ELEM7is_menuEv");
s32 func_001c8db8(void*, s32) asm("func_001c8db8");
s32 YS__OBJ__is_exist(B1bc*) asm("YS__OBJ__is_exist");
s32 YS__SACRIFICE__GetCommandStatus(E1bc*) asm("YS__SACRIFICE__GetCommandStatus");
s32 func_001bbf40(void) asm("func_001bbf40");
s32 func_001bc568(E1bc* e, B1bc* b) asm("func_001bc568");
s32 func_001bc568(E1bc* e, B1bc* b) {
    if (elem_is_menu(e)) return 1;
    if (func_001c8db8(D_00351eb8, 0) || func_001c8db8(D_00351ec0, 0)) return 0;
    if (YS__OBJ__is_exist(b) == 0 || (b->f588 & 0x1000000) == 0) return 0;
    if (YS__SACRIFICE__GetCommandStatus(e) || (b->t->f8 & 0x20)) return 0;
    switch (b->mode) { case 7: case 12: return 0; }
    if (e->h4 == 3) {
        if (func_001bbf40()) return 0;
    }
    s32 r = 0;
    if (!(D_0034f240 & 0x40000)) { s32 lt = (b->p->b1b1 < e->b1c); r = !lt; }
    return r;
}
}  // namespace n001bc568

// ---- 001bc688 from src/yasui/libys/commandmenu.cpp
namespace n001bc688 {
void slot_clear(u8* self) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void slot_clear(u8* self) {
    u32 r4 = (u32)self, r15;
    r15 = (u32)((s32)0u + 5);
    *(u32*)(r4 + 8) = 0u;
    *(volatile u8*)(r4 + 5) = (u8)r15;
    *(volatile u16*)(r4 + 0) = (u16)0u;
    *(volatile u16*)(r4 + 2) = (u16)0u;
    *(volatile u8*)(r4 + 4) = (u8)0u;
    *(volatile u8*)(r4 + 6) = (u8)0u;
}
}  // namespace n001bc688

// ---- 001bc6a8 from src/anon/batch_w25.cpp
namespace n001bc6a8 {
struct O1bc { u16 f0; u16 f2; u8 f4; u8 f5; u16 pad; u32 f8; };
u8 YS__COMMAND_SLOT__GetStatus(u16*, u32, u32) asm("YS__COMMAND_SLOT__GetStatus");
void YS__COMMAND_SLOT__set(O1bc* o, u16* a, u32 b, u32 c, u32 d) asm("YS__COMMAND_SLOT__set");
void YS__COMMAND_SLOT__set(O1bc* o, u16* a, u32 b, u32 c, u32 d) {
    o->f2 = *a;
    o->f4 = d;
    o->f5 = YS__COMMAND_SLOT__GetStatus(a, b, c);
    o->f8 = c;
    o->f0 = 0;
}
}  // namespace n001bc6a8

// ---- 001bc700 from src/yasui/libys/commandmenu.cpp
namespace n001bc700 {
bool slot_is_exist(YS::COMMAND_SLOT_Layout* self) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
bool slot_is_exist(YS::COMMAND_SLOT_Layout* self) { return self->value != 0; }
}  // namespace n001bc700

// ---- 001bc710 from src/anon/tiny_auto80_fptr4.cpp
namespace n001bc710 {
u32 func_001bc710(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001bc710jjjj");
u32 func_001bc710(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r2 = (u32)(*(u8*)((u32)r4 + (s32)(5)));
    r2 = (u32)((s32)r2 + (-5));
    r2 = ((u32)r2 < 0x00000002u);
    return r2;
}
}  // namespace n001bc710

// ---- 001bc720 from src/yasui/libys/commandmenu.cpp
namespace n001bc720 {
void menu_reset_cursor(YS::COMMAND_MENU_Layout* m) asm("_ZN2YS12COMMAND_MENU12reset_cursorEv");
void menu_reset_cursor(YS::COMMAND_MENU_Layout* m) {
    m->cursor0 = 0;
    m->cursor1 = -1;
}
}  // namespace n001bc720

// ---- 001bc730 from src/anon/batch_w35.cpp
namespace n001bc730 {
void func_001bc720(u8*) asm("func_001bc720");
void func_001bc730(u8* p, s32 i) asm("func_001bc730");
void func_001bc730(u8* p, s32 i) {
    if (i < *(s32*)(p + 8)) {
        *(s32*)(p + 108) = i;
        *(u32*)(p + 112) = *(u16*)(i * 12 + (u32)p + 14);
    } else {
        func_001bc720(p);
    }
}
}  // namespace n001bc730

// ---- 001bc778 from src/yasui/libys/commandmenu.cpp
namespace n001bc778 {
void menu_clear(YS::COMMAND_MENU_Layout* m) asm("_ZN2YS12COMMAND_MENU5clearEv");
void menu_clear(YS::COMMAND_MENU_Layout* m) { m->value = 0; }
}  // namespace n001bc778

// ---- 001bc780 from src/anon/batch_w111.cpp
namespace n001bc780 {
struct Data1c { u16 h0; u16 kind; u8 pad[2]; s8 slot; u8 b7; };
struct Src1c { u8 pad[2]; u16 id; u8 b4; u8 pad2[7]; u8 body[1]; };
struct Ent1c { u16 flags; u8 pad[3]; u8 state; u8 pad2[6]; };
struct Slot1c { u8 pad[8]; s32 busy; };
struct Owner1c { u8 pad[2528]; void* res; };
struct Mgr1c { u8 pad[4]; Owner1c* owner; s32 n; Ent1c ent[1]; };
Data1c* YS__COMMAND_ELEM__Get(u32) asm("YS__COMMAND_ELEM__Get");
void YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
Src1c* func_001bd570(Owner1c*, s32) asm("func_001bd570");
void YS__COMMAND_SLOT__set(Ent1c*, Data1c*, void*, void*, u32) asm("YS__COMMAND_SLOT__set");
s32 func_001bc948(Slot1c*) asm("func_001bc948");
Ent1c* YS__COMMAND_MENU__add(Mgr1c* o, u32 id, void* body, u32 b) asm("YS__COMMAND_MENU__add");
Ent1c* YS__COMMAND_MENU__add(Mgr1c* o, u32 id, void* body, u32 b)
{
    Src1c* s = 0;
    s32 linked = 0;
    Data1c* d = YS__COMMAND_ELEM__Get(id);
    YS__OBJ__is_exist(o->owner->res);
    if (d->b7 == 1) s = func_001bd570(o->owner, 0);
    else if (d->h0 == 81) s = func_001bd570(o->owner, 2);
    if (s) {
        body = s->body;
        b = s->b4;
        linked = 1;
        id = s->id;
        d = YS__COMMAND_ELEM__Get(id);
    }
    YS__COMMAND_SLOT__set(&o->ent[o->n], d, o->owner->res, body, b);
    if (linked) { Ent1c* e = &o->ent[o->n]; e->flags |= 1; }
    if (d->kind == 3 && b == 0) o->ent[o->n].state = 6;
    s32 v = d->slot;
    if (v >= 0 && v != 4) {
        Slot1c* x = (Slot1c*)((u8*)o->owner + v * 116 + 36);
        if (x->busy == 0) o->ent[o->n].state = 5;
        else if (!func_001bc948(x)) o->ent[o->n].state = 1;
    }
    return &o->ent[o->n++];
}
}  // namespace n001bc780

// ---- 001bc948 from src/anon/batch_w62.cpp
namespace n001bc948 {
struct E1bc { u8 pad[5]; u8 type; u8 pad2[6]; };
struct S1bc { u8 pad[8]; s32 n; E1bc e[1]; };
static inline bool isLow(E1bc* e) { return e->type < 4; }
s32 func_001bc948(S1bc* s) asm("func_001bc948");
s32 func_001bc948(S1bc* s) {
    for (s32 i = 0; i < s->n; i++) {
        if (isLow(&s->e[i])) return 1;
    }
    return 0;
}
}  // namespace n001bc948

// ---- 001bc990 from src/anon/auto80_199_queue.cpp
namespace n001bc990 {
void YS__COMMAND_MENU__make(u32 a0, u32 a1) asm("_Z22YS__COMMAND_MENU__makejj");
void YS__COMMAND_MENU__make(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    u32 v1 = *(u16*)(s0 + 0);
    s0 += 2;
    if (v1 == 0) {
        return;
    }

    while (1) {
        YS__COMMAND_MENU__add(s1, v1, 0, 1);
        v1 = *(u16*)(s0 + 0);
        s0 += 2;
        if (v1 == 0) {
            return;
        }
    }
}
}  // namespace n001bc990

// ---- 001bc9e8 from src/anon/batch_w2045.cpp
namespace n001bc9e8 {
s32 func_001818e8() asm("func_001818e8");
u8* YS__COMMAND_ELEM__Get(u16) asm("YS__COMMAND_ELEM__Get");
void func_001bc720(void*) asm("func_001bc720");
void func_001bc730(u8*, s32) asm("func_001bc730");
void func_001bcc28(u8*) asm("func_001bcc28");
s32 YS__COMMAND_MENU__check_close(u8*) asm("YS__COMMAND_MENU__check_close");
void func_001bce00(u8*) asm("func_001bce00");
s32 func_001bcf18(void*) asm("func_001bcf18");
s32 YS__COMMAND_MENU__is_shortcut_menu(void*) asm("YS__COMMAND_MENU__is_shortcut_menu");
void func_001bd5b0(void*, s32, s32) asm("func_001bd5b0");
void func_001bd618(void*, s32) asm("func_001bd618");
void YS__PLAYER_COMMAND__decide(void*) asm("YS__PLAYER_COMMAND__decide");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
struct W2045_S2240 { u8 pad[2240]; void** sp; };
struct W2045_Elem { u8 a[2]; u16 id; u8 b; u8 kind; u8 c[6]; };
struct W2045_Menu { u8 pad[4]; u8* o; s32 n; W2045_Elem e[8]; };
static inline bool w2045_entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || YS__COMMAND_MENU__is_shortcut_menu(e)) b = true;
    return b;
}
static inline bool w2045_kind_ok(W2045_Elem* e) { return e->kind < 4; }
s32 func_001bc9e8(u8* p) asm("func_001bc9e8");
s32 func_001bc9e8(u8* p) {
    u8* s1 = *(u8**)(*(u8**)(p + 4) + 2532);
    if (YS__COMMAND_MENU__check_close(p)) return 0;
    if (YS__COMMAND_MENU__is_shortcut_menu(p)) { func_001bcc28(p); return 0; }
    if (!func_001bcf18(p)) func_001bce00(p);
    u64 f = *(u64*)(s1 + 8);
    if (f & 0x200000004ULL) {
        YS__PLAYER_COMMAND__decide(*(void**)(p + 4));
    } else if (f & 8) {
        if (func_001bcf18(*(*(W2045_S2240**)(p + 4))->sp)) {
            *(u32*)(*(u8**)(p + 4) + 8) |= 2;
        } else {
            func_001bd618(*(void**)(p + 4), 1);
            if (w2045_entry_busy(*(*(W2045_S2240**)(p + 4))->sp)) func_001bc720(*(*(W2045_S2240**)(p + 4))->sp);
        }
    } else if (func_001818e8()) {
        f = *(u64*)(s1 + 8);
        if (f & 0x200) {
            *(u32*)(*(u8**)(p + 4) + 8) |= 8;
        } else if (f & 0x4000) {
            s32 i = *(s32*)(p + 108);
            if (i > 0) func_001bc730(p, i - 1);
            else func_001bc730(p, *(s32*)(p + 8) - 1);
            func_002ba2e8(1, 0);
        } else if (f & 0x8000) {
            s32 i = *(s32*)(p + 108);
            if (i < *(s32*)(p + 8) - 1) func_001bc730(p, i + 1);
            else func_001bc730(p, 0);
            func_002ba2e8(1, 0);
        } else if (f & 0x10000000) {
            W2045_Elem* e = &((W2045_Menu*)p)->e[*(s32*)(p + 108)];
            if (w2045_kind_ok(e)) {
                s32 b = (s8)YS__COMMAND_ELEM__Get(e->id)[6];
                if (b >= 0) func_001bd5b0(*(void**)(p + 4), b, 1);
            }
        }
    }
    return 1;
}
}  // namespace n001bc9e8

// ---- 001bcc28 from src/anon/batch_w88.cpp
namespace n001bcc28 {
void YS__PLAYER_COMMAND__decide(u32) asm("YS__PLAYER_COMMAND__decide");
extern u64 D_0036dc48[] asm("D_0036dc48");
struct E1bcc28 { u16 pad; u16 id; u8 pad2[2]; u8 kind; u8 pad3[5]; };
struct T1bcc28 { u32 pad; u32 owner; s32 n; E1bcc28 e[8]; s32 sel; };
void func_001bcc28(T1bcc28* p) asm("func_001bcc28");
void func_001bcc28(T1bcc28* p) {
    u32 t1 = p->owner;
    s32 n = p->n;
    u32 a3 = *(u32*)(t1 + 2532);
    p->sel = -1;
    for (s32 i = 0; i < n; i++) {
        if (*(u64*)(a3 + 8) & D_0036dc48[p->e[i].kind - 1]) { p->sel = i; break; }
    }
    s32 idx = p->sel;
    if (idx >= 0) {
        E1bcc28* e = p->e;
        u16 v = e[idx].id;
        if (v != 0) {
            if (v == 454) { *(u32*)(t1 + 8) |= 2; return; }
            YS__PLAYER_COMMAND__decide(p->owner);
            return;
        }
    }
    u64 fl = *(u64*)(a3 + 8);
    if (fl & 0x100) *(u32*)(t1 + 8) |= 2;
    else if (fl & 0x200) *(u32*)(t1 + 8) |= 8;
}
}  // namespace n001bcc28

// ---- 001bcd08 from src/anon/batch_w87.cpp
namespace n001bcd08 {
s32 func_001bcf18(void*) asm("func_001bcf18");
s32 YS__COMMAND_MENU__is_shortcut_menu(void*) asm("YS__COMMAND_MENU__is_shortcut_menu");
void func_001bc720(void*) asm("func_001bc720");
void func_001bd618(void*, s32) asm("func_001bd618");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
struct S2240 { u8 pad[2240]; void** sp; };
static inline bool entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || YS__COMMAND_MENU__is_shortcut_menu(e)) b = true;
    return b;
}
s32 YS__COMMAND_MENU__check_close(u8* p) asm("YS__COMMAND_MENU__check_close");
s32 YS__COMMAND_MENU__check_close(u8* p) {
    void** s = (*(S2240**)(p + 4))->sp;
    while (!entry_busy(*s)) {
        if (*(s32*)((u8*)*s + 8) == 0) {
            while (!((*(S2240**)(p + 4))->sp < s)) {
                func_001bc720(*(*(S2240**)(p + 4))->sp);
                func_001bd618(*(void**)(p + 4), 0);
            }
            func_002ba2e8(4, 0);
            return 1;
        }
        s--;
    }
    return 0;
}
}  // namespace n001bcd08

// ---- 001bcde0 gap
namespace n001bcde0 {
u8 func_001bcde0(u8* p, s32 i) asm("func_001bcde0");
struct E12 { u8 b[12]; };
u8 func_001bcde0(u8* p, s32 i) {
    E12* e = (E12*)(p + 12) + i;
    s32 r = e->b[5] < 4;
    return r;
}
}  // namespace n001bcde0

// ---- 001bce00 from src/anon/batch_w56.cpp
namespace n001bce00 {
void func_001bc720(u8*) asm("func_001bc720");
void func_001bc730(u8*, s32) asm("func_001bc730");
struct E1bc { u16 a; u16 id; u32 x[2]; };
void func_001bce00(u8* p) asm("func_001bce00");
void func_001bce00(u8* p)
{
    s32 cur = *(s32*)(p + 108);
    s32 n;
    if (cur < 0 || cur >= (n = *(s32*)(p + 8))) { func_001bc720(p); return; }
    u32 id = *(u32*)(p + 112);
    E1bc* e = (E1bc*)(p + 12);
    if (e[cur].id == id) return;
    s32 i;
    for (i = 0; i < n; i++)
        if (e[i].id == id) { func_001bc730(p, i); return; }
    func_001bc730(p, *(s32*)(p + 108));
}
}  // namespace n001bce00

// ---- 001bce90 from src/anon/batch_w65.cpp
namespace n001bce90 {
struct Ent4 { u16 id; u8 b; u8 pad; };
void func_001bc778(u32) asm("func_001bc778");
u8* YS__COMMAND_MENU__add(u32, u32, u32, s32) asm("YS__COMMAND_MENU__add");
void func_001bce90(u32 a, Ent4* e, u32 n, u32 c) asm("func_001bce90");
void func_001bce90(u32 a, Ent4* e, u32 n, u32 c) {
    u32 i;
    func_001bc778(a);
    for (i = 0; i < n; i++, e++) YS__COMMAND_MENU__add(a, e->id, c, 1)[6] = e->b;
}
}  // namespace n001bce90

// ---- 001bcf18 from src/anon/tiny_auto80_queue.cpp
namespace n001bcf18 {
u32 func_001bcf18(u32* a0) asm("_Z13func_001bcf18Pj");
u32 func_001bcf18(u32* a0) {
    u32 a = *a0;
    u32 t7 = 6;
    u32 v0;
    if (a == 0) {
        goto yes;
    }
    if (a != t7) {
        v0 = 0;
        goto out;
    }
yes:
    v0 = 1;
out:
    return v0;
}
}  // namespace n001bcf18

// ---- 001bcf38 from src/anon/batch_w24.cpp
namespace n001bcf38 {
s32 YS__COMMAND_MENU__is_shortcut_menu(s32* p) asm("YS__COMMAND_MENU__is_shortcut_menu");
s32 YS__COMMAND_MENU__is_shortcut_menu(s32* p) {                             
    switch (*p) {
    case 5: case 10: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    }
    return 0;
}
}  // namespace n001bcf38

// ---- 001bcf80 from src/anon/batch_w1573.cpp
namespace n001bcf80 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W1573_Z12 { s32 a, b, c; W1573_Z12() { a = 0; b = 0; c = 0; } };
void func_00190128(void*) asm("func_00190128");
void YS__COMMAND__clear(void*) asm("YS__COMMAND__clear");
void YS__PLAYER_COMMAND__clear_override(void*) asm("YS__PLAYER_COMMAND__clear_override");
void func_00320730(void*) asm("func_00320730");
void YS__RECOM__init(void*) asm("YS__RECOM__init");
void func_001bd370(void*) asm("func_001bd370");
void func_001bd3a0(void*) asm("func_001bd3a0");
void slot_clear(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void menu_reset(void*) asm("_ZN2YS12COMMAND_MENU12reset_cursorEv");
extern u8 D_00351228[] asm("D_00351228");
void YS__PLAYER_COMMAND__PLAYER_COMMAND(u8* p) asm("YS__PLAYER_COMMAND__PLAYER_COMMAND");
void YS__PLAYER_COMMAND__PLAYER_COMMAND(u8* p) {
    u8* m;
    s32 n;
    u8* s;
    s32 k;
    s32 i;
    s32* t;
    u8* q;
    func_00190128(p + 12);
    YS__COMMAND__clear(p + 4);
    *(s32*)(p + 32) = 0;
    *(void**)p = D_00351228;
    m = p + 36;
    n = 18;
    do {
        s = m + 12;
        k = 7;
        do {
            *(u16*)s = 0;
            slot_clear(s);
            k--;
            s += 12;
        } while (k != -1);
        menu_clear(m);
        menu_reset(m);
        n--;
        m += 116;
    } while (n != -1);
    s = p + 2244;
    k = 6;
    do {
        *(u16*)s = 0;
        slot_clear(s);
        func_00190128(s + 12);
        YS__PLAYER_COMMAND__clear_override(s);
        k--;
        s += 36;
    } while (k != -1);
    new (p + 2496) W1573_Z12;
    func_00190128(p + 2508);
    *(s32*)(p + 2528) = 0;
    *(s32*)(p + 2532) = 0;
    q = p + 2552;
    *(u8**)q = p;
    func_00190128(p + 2564);
    *(s32*)(p + 2584) = 0;
    func_00320730(p + 2588);
    slot_clear(p + 2588);
    YS__RECOM__init(q);
    *(f32*)(p + 2624) = 1.0f;
    YS__COMMAND__clear(p + 4);
    i = 0;
    m = p;
    for (; i < 19; i++) {
        *(s32*)(m + 36) = i;
        menu_clear(m + 36);
        menu_reset(m + 36);
        *(u8**)(m + 40) = p;
        m += 116;
    }
    func_001bd370(p);
    func_001bd3a0(p);
}
}  // namespace n001bcf80

// ---- 001bd128 gap (C1 copy of 0x1bcf80)
namespace n001bd128 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W1573_Z12 { s32 a, b, c; W1573_Z12() { a = 0; b = 0; c = 0; } };
void func_00190128(void*) asm("func_00190128");
void YS__COMMAND__clear(void*) asm("YS__COMMAND__clear");
void YS__PLAYER_COMMAND__clear_override(void*) asm("YS__PLAYER_COMMAND__clear_override");
void func_00320730(void*) asm("func_00320730");
void YS__RECOM__init(void*) asm("YS__RECOM__init");
void func_001bd370(void*) asm("func_001bd370");
void func_001bd3a0(void*) asm("func_001bd3a0");
void slot_clear(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void menu_reset(void*) asm("_ZN2YS12COMMAND_MENU12reset_cursorEv");
extern u8 D_00351228[] asm("D_00351228");
void func_001bd128(u8* p) asm("func_001bd128");
void func_001bd128(u8* p) {
    u8* m;
    s32 n;
    u8* s;
    s32 k;
    s32 i;
    s32* t;
    u8* q;
    func_00190128(p + 12);
    YS__COMMAND__clear(p + 4);
    *(s32*)(p + 32) = 0;
    *(void**)p = D_00351228;
    m = p + 36;
    n = 18;
    do {
        s = m + 12;
        k = 7;
        do {
            func_00320730(s);
            slot_clear(s);
            k--;
            s += 12;
        } while (k != -1);
        menu_clear(m);
        menu_reset(m);
        n--;
        m += 116;
    } while (n != -1);
    s = p + 2244;
    k = 6;
    do {
        *(u16*)s = 0;
        slot_clear(s);
        func_00190128(s + 12);
        YS__PLAYER_COMMAND__clear_override(s);
        k--;
        s += 36;
    } while (k != -1);
    new (p + 2496) W1573_Z12;
    func_00190128(p + 2508);
    *(s32*)(p + 2528) = 0;
    *(s32*)(p + 2532) = 0;
    q = p + 2552;
    *(u8**)q = p;
    func_00190128(p + 2564);
    *(s32*)(p + 2584) = 0;
    func_00320730(p + 2588);
    slot_clear(p + 2588);
    YS__RECOM__init(q);
    *(f32*)(p + 2624) = 1.0f;
    YS__COMMAND__clear(p + 4);
    i = 0;
    m = p;
    for (; i < 19; i++) {
        *(s32*)(m + 36) = i;
        menu_clear(m + 36);
        menu_reset(m + 36);
        *(u8**)(m + 40) = p;
        m += 116;
    }
    func_001bd370(p);
    func_001bd3a0(p);
}
}  // namespace n001bd128

// ---- 001bd2d0 from src/anon/auto80_199_queue.cpp
namespace n001bd2d0 {
void func_001bd2d0(u32 a0, u32 a1, u32 a2) asm("_Z13func_001bd2d0jjj");
void func_001bd2d0(u32 a0, u32 a1, u32 a2) {
    *(u32*)(a0 + 2528) = a1;
    *(u32*)(a0 + 2532) = a2;
    *(u32*)(a0 + 32) = 0;
    u32 s0 = a0 + 1312;
    u32 s1 = a0;

    func_001bc778(s0);
    YS__COMMAND_MENU__add(s0, 439, 0, 1);
    func_001bd668(s1);

    u32 vt = *(u32*)(s1 + 0);
    ((void (*)(u32))(*(u32*)(vt + 12)))(s1);

    if (func_001818a0() == 0) {
        *(u32*)(s1 + 32) |= 0x8;
    }

    if (func_001bdd20(s1) != 0) {
        *(u32*)(s1 + 32) |= 0x10;
    }
}
}  // namespace n001bd2d0

// ---- 001bd370 from src/anon/tiny_auto80_queue.cpp
namespace n001bd370 {
void func_001bd370(u8* a0) asm("_Z13func_001bd370Ph");
void func_001bd370(u8* a0) {                          
    s32 t6 = 3;
    u32* p = (u32*)(a0 + 2536);
    do {
        *p = 0;
        t6 = t6 - 1;
        p = p + 1;
    } while (t6 >= 0);
    *(u32*)(a0 + 2240) = 0;
}
}  // namespace n001bd370

// ---- 001bd3a0 from src/anon/tiny_auto80_queue.cpp
namespace n001bd3a0 {
u32 YS__PLAYER_COMMAND__clear_override(...) asm("YS__PLAYER_COMMAND__clear_override");
void func_001bd3a0(u8* a0) asm("_Z13func_001bd3a0Ph");
void func_001bd3a0(u8* a0) {
    u8* s0 = a0 + 2244;
    s32 s1 = 6;
    do {
        YS__PLAYER_COMMAND__clear_override(s0);
        s1 = s1 - 1;
        s0 = s0 + 36;
    } while (s1 >= 0);
}
}  // namespace n001bd3a0

// ---- 001bd3e0 from src/anon/batch_w20.cpp
namespace n001bd3e0 {
u32 func_001bd418(u8*) asm("func_001bd418");
u32 func_001bd3e0(u8* p) asm("func_001bd3e0");
u32 func_001bd3e0(u8* p) {
    if (*(u32*)(*(u8**)(p + 0x9e0) + 0x588) & 0x2000000) return 0;
    return func_001bd418(p);
}
}  // namespace n001bd3e0

// ---- 001bd418 from src/anon/batch_w78.cpp
namespace n001bd418 {
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
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
struct W78Five { u32 w[5]; };
struct W78Slot { u16 x0; u16 cnt; u8 pad[8]; W78Five v; u8 lvl; u8 pad2[3]; };
u32 YS__COMMAND_ELEM__Get(u32) asm("YS__COMMAND_ELEM__Get");
void YS__COMMAND_SLOT__set(W78Slot*, u32, u32, W78Five*, u32) asm("YS__COMMAND_SLOT__set");
W78Slot* func_001bd418(u8* o, s32 idx, u32 key, W78Five* src, u32 arg, s32 lvl) asm("func_001bd418");
W78Slot* func_001bd418(u8* o, s32 idx, u32 key, W78Five* src, u32 arg, s32 lvl) {
    u8* base = o + idx * 36;
    W78Slot* e = (W78Slot*)(base + 2244);
    if (e->cnt != 0 && lvl < e->lvl) return 0;
    u32 v = YS__COMMAND_ELEM__Get(key);
    e->v = *src;
    YS__COMMAND_SLOT__set(e, v, *(u32*)(o + 2528), (W78Five*)(base + 2256), arg);
    e->lvl = lvl;
    return e;
}
}  // namespace n001bd418

// ---- 001bd4e8 from src/anon/batch_w50.cpp
namespace n001bd4e8 {
void func_001bdab0(void*) asm("func_001bdab0");
void func_001bd3e0(void*, s32, u32, u32, s32, s32) asm("func_001bd3e0");
void func_001bd4e8(u8* o, u32* v, u32 c) asm("func_001bd4e8");
void func_001bd4e8(u8* o, u32* v, u32 c) {
    if (*(u32*)(*(u8**)(o + 2528) + 1416) & 0x2000000) return;
    func_001bdab0(o);
    for (s32 i = 0; i < 4; i++) func_001bd3e0(o, i + 3, v[i], c, 1, 100);
}
}  // namespace n001bd4e8

// ---- 001bd570 from src/anon/tiny_auto80_solver.cpp
namespace n001bd570 {
u32 func_001bd570(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001bd570jjjjjjjj");
u32 func_001bd570(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001bd570jjjjjjjj");
u32 func_001bd570(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)((s32)0u + (36));
    r5 = (u32)(r5 * r15);
    r4 = (u32)(r4 + r5);
    r4 = (u32)((s32)r4 + (2244));
    r15 = (u32)(*(u16*)((u32)r4 + (s32)(2)));
    if (r15 == 0u) r4 = 0u;
    r2 = r4;
    return r2;
}
}  // namespace n001bd570

// ---- 001bd590 from src/anon/tiny_jal_wrappers.cpp
namespace n001bd590 {
u32 func_001bd570(u32, u32, u32, u32) asm("_Z13func_001bd570jjjj");
u32 func_001bd590(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001bd590jjjj");
u32 func_001bd590(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)((s32)0u + (3));
    r2 = func_001bd570(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n001bd590

// ---- 001bd5b0 from src/anon/batch_w48.cpp
namespace n001bd5b0 {
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
struct Obj1bd5b0 { u8 pad[2240]; u8** p; u8 pad2[2536 - 2244]; u8* q; };
void func_001bd5b0(Obj1bd5b0* o, s32 i, u8 flag) asm("func_001bd5b0");
void func_001bd5b0(Obj1bd5b0* o, s32 i, u8 flag) {
    if (o->p == 0) o->p = (u8**)&o->q;
    else o->p++;
    *o->p = (u8*)o + i * 116 + 36;
    if (flag) func_002ba2e8(3, 0);
}
}  // namespace n001bd5b0

// ---- 001bd618 from src/anon/batch_w35.cpp
namespace n001bd618 {
void func_002ba2e8(u32, u32) asm("func_002ba2e8");
void func_001bd618(u8* p, u8 flag) asm("func_001bd618");
void func_001bd618(u8* p, u8 flag) {
    void** sp = (void**)(p + 2240);
    *(void**)*sp = 0;
    if (*sp == (void*)(p + 2536)) *sp = 0;
    else *sp = (u8*)*sp - 4;
    if (flag) func_002ba2e8(4, 0);
}
}  // namespace n001bd618

// ---- 001bd668 from src/anon/batch_w20.cpp
namespace n001bd668 {
void func_001bd618(u8*, u32) asm("func_001bd618");
void func_001bd668(u8* p) asm("func_001bd668");
void func_001bd668(u8* p) {
    while (*(u32*)(p + 0x8c0)) func_001bd618(p, 0);
}
}  // namespace n001bd668

// ---- 001bd6a8 from src/anon/batch_w1975_nsa.cpp
namespace n001bd6a8 {
#define W1975_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1975_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1975V {
    f32 x, y, z, w;
    W1975V() {}
    W1975V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1975V(const W1975V& o) { W1975_QCOPY(this, &o); }
    W1975V& operator=(const W1975V& o) { if (this != &o) W1975_QCOPY(this, &o); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(this), "f"(s) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1975M {
    W1975V r[4];
    W1975M() {}
    W1975M& operator=(const W1975M& o) { if (this != &o) W1975_QCOPY4(this, &o); return *this; }
    W1975V operator*(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t.set noreorder\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1975V apply3(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
inline void* operator new(unsigned int, void* p) { return p; }
struct W1975Slot {
    u8 b0, b1; u16 id; u8 b4; u8 type; u16 pad6; s32 arg;
    bool small() { return type < 4; }
};
struct W1975Wk { u64 d0; u64 d8; u8 pad[32]; W1975V v; };
struct W1975Ai { void** vt; };
struct W1975Self {
    void** vt;
    u8 sub4[4];
    u32 f8;
    u8 pad12[20];
    u32 flags;
    bool isB0() { u32 f = flags; u8 b = f & 1; return b; }
    u8 pad36[2528 - 36];
    W1975Ai* ai;
    W1975Wk* wk;
    u8 pad2536[16];
    u8 sub2552[36];
    W1975Slot slot;
    u8 pad2600[8];
    W1975V v;
};
s32 W1975_Slot_is_exist(W1975Slot*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
s32 W1975_Slot_is_beep(const W1975Slot*) asm("_ZNK2YS12COMMAND_SLOT7is_beepEv");
s32 W1975_u_call4_001b8e88(u32) asm("_Z21YS__COMMAND_ELEM__Getjjjj");
s32 W1975_ctarget_001c8db8(void*, u32) asm("_Z16ctarget_001c8db8jjjj");
void W1975_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
typedef void (*W1975VFn)(W1975Self*);
typedef s32 (*W1975AFn)(W1975Ai*);
extern u8 D_00351ec8 asm("D_00351ec8");
void YS__COMMAND__clear(u8*) asm("YS__COMMAND__clear");
void YS__RECOM__exec(u8*) asm("YS__RECOM__exec");
void func_001bdd50(W1975Self*) asm("func_001bdd50");
void func_001bd3a0(W1975Self*) asm("func_001bd3a0");
s32 func_001bd918(W1975Self*, s32, s32) asm("func_001bd918");
void func_0013c720(void) asm("func_0013c720");
void func_001bd6a8(W1975Self* self) asm("func_001bd6a8");
void func_001bd6a8(W1975Self* self) {
    if (self->ai == 0) return;
    if (self->wk == 0) return;
    YS__COMMAND__clear(self->sub4);
    ((W1975VFn)self->vt[3])(self);
    YS__RECOM__exec(self->sub2552);
    func_001bdd50(self);
    if (((W1975AFn)self->ai->vt[16])(self->ai) == 0 || self->isB0() || W1975_ctarget_001c8db8(&D_00351ec8, 0) != 0) {
        func_001bd3a0(self);
        self->v.zero();
        return;
    }
    if (self->flags & 2) self->slot.type = 5;
    self->v = self->wk->v;
    if (!(self->flags & 2) && (self->wk->d8 & 0x400) && W1975_Slot_is_exist(&self->slot)) {
        if (self->slot.small()) {
            s32 r = W1975_u_call4_001b8e88(self->slot.id);
            if (func_001bd918(self, r, self->slot.arg)) {
                func_0013c720();
                self->f8 |= 0x10;
            }
        } else if (W1975_Slot_is_beep(&self->slot)) {
            W1975_systemSePlay(5, 0);
        }
    } else {
        ((W1975VFn)self->vt[4])(self);
    }
    if (self->wk->d0 & 0x100) self->f8 |= 1;
    if (self->wk->d0 & 0x200) self->f8 |= 4;
    func_001bd3a0(self);
}
}  // namespace n001bd6a8

// ---- 001bd898 gap
namespace n001bd898 {
void func_001bc9e8(u8*) asm("func_001bc9e8");
void func_001bd898(u8* p) asm("func_001bd898");
void func_001bd898(u8* p) {
    u8* m = **(u8***)(p + 2240);
    if (m) func_001bc9e8(m);
}
}  // namespace n001bd898

// ---- 001bd8c8 from src/anon/batch_w58.cpp
namespace n001bd8c8 {
struct NoTail { ~NoTail() {} };
u32 YS__COMMAND_ELEM__Get(u16) asm("YS__COMMAND_ELEM__Get");
void func_001bd918(u8*, u32, s32) asm("func_001bd918");
void YS__PLAYER_COMMAND___decide(u8* p) asm("YS__PLAYER_COMMAND___decide");
void YS__PLAYER_COMMAND___decide(u8* p) {
    NoTail g;
    u8* t = **(u8***)(p + 2240);
    s32 off = *(s32*)(t + 108) * 12;
    func_001bd918(p, YS__COMMAND_ELEM__Get(*(u16*)(t + off + 14)), 0);
}
}  // namespace n001bd8c8

// ---- 001bd918 from src/anon/auto80_199_queue.cpp
namespace n001bd918 {
u32 func_001bd918(u32 a0, u32 a1, u32 a2) asm("_Z13func_001bd918jjj");
u32 func_001bd918(u32 a0, u32 a1, u32 a2) {
    u32 s2 = a1;
    u32 s0 = a2;
    u32 s1 = a0;
    u32 v0 = func_001b8f10(s2, *(u32*)(a0 + 2528));
    u32 t6 = 0;
    if (v0 != 0) {
        YS__COMMAND__set(s1 + 4, *(u16*)(s2 + 0), s0, 0);
        *(u8*)(s1 + 9) = *(u8*)(s2 + 28);
        t6 = 1;
    }
    return t6;
}
}  // namespace n001bd918

// ---- 001bd988 from src/anon/batch_w100.cpp
namespace n001bd988 {
struct Ent18 { u8 b0[5]; u8 kind; u8 pad[6]; };
struct Hdr18 { u8 pad[108]; s32 cur; };
struct Obj18 { void** vt; u8 pad[28]; u32 flags; u8 pad2[2240 - 36]; Hdr18** seq; };
static inline Ent18* Cur18(Hdr18* h) { return (Ent18*)((u8*)h + h->cur * 12 + 12); }
static inline bool IsWait18(Ent18* e) { return e->kind < 4; }
s32 func_001bc710(Ent18*) asm("func_001bc710");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
s32 func_001bcf18(Hdr18*) asm("func_001bcf18");
s32 YS__COMMAND_MENU__is_shortcut_menu(Hdr18*) asm("YS__COMMAND_MENU__is_shortcut_menu");
void func_001bc730(Hdr18*, s32) asm("func_001bc730");
void func_001bd618(Obj18*, s32) asm("func_001bd618");
static inline bool Done18(Hdr18* h) {
    bool r = false;
    if (func_001bcf18(h) || YS__COMMAND_MENU__is_shortcut_menu(h)) r = true;
    return r;
}
void YS__PLAYER_COMMAND__decide(Obj18* o) asm("YS__PLAYER_COMMAND__decide");
void YS__PLAYER_COMMAND__decide(Obj18* o) {
    Ent18* e = Cur18(*o->seq);
    if (!IsWait18(e)) {
        if (func_001bc710(e) && !(o->flags & 8)) func_002ba2e8(5, 0);
        return;
    }
    if (!((s32 (*)(Obj18*))o->vt[5])(o)) return;
    for (;;) {
        if (Done18(*o->seq)) {
            func_001bc730(*o->seq, 0);
            return;
        }
        func_001bc730(*o->seq, 0);
        func_001bd618(o, 0);
    }
}
}  // namespace n001bd988

// ---- 001bdab0 from src/anon/auto80_199_queue.cpp
namespace n001bdab0 {
void func_001bdab0(u32 a0) asm("_Z13func_001bdab0j");
void func_001bdab0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 2240);
    if (t7 == 0) {
        return;
    }
    u32 s1 = a0 + 2536;
    if (!(s1 < t7)) {
        return;
    }

L001bdae0:
    func_001bd618(s0, 0);
    t7 = *(u32*)(s0 + 2240);
    if (t7 == 0) {
        return;
    }
    if (s1 < t7) {
        goto L001bdae0;
    }
}
}  // namespace n001bdab0

// ---- 001bdb10 from src/anon/auto80_199_queue.cpp
namespace n001bdb10 {
u32 func_001bdb10(u32 a0, u32 a1) asm("_Z13func_001bdb10jj");
u32 func_001bdb10(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 t7 = *(u32*)(a0 + 2536);
    if (t7 != 0) {
        if (*(u32*)(t7 + 0) == a1) {
            return 0;
        }
    }

    func_001bd668();
    func_001bd5b0(s0, s1, 0);
    return 1;
}
}  // namespace n001bdb10

// ---- 001bdb70 from src/anon/batch_wcx.cpp
namespace n001bdb70 {
void func_001bd668(u8*) asm("func_001bd668");
void func_001d4818(u8*, u32, u32, u32, u32) asm("func_001d4818");
void func_001d48e8(u8*, u32, u8*) asm("func_001d48e8");
void func_001bd5b0(u8*, s32, s32) asm("func_001bd5b0");
void YS__PLAYER_COMMAND__set_special_command(u8* p, u32 a, u32 b, u32 c, u32 d) asm("YS__PLAYER_COMMAND__set_special_command");
void YS__PLAYER_COMMAND__set_special_command(u8* p, u32 a, u32 b, u32 c, u32 d)
{
    func_001bd668(p);
    u8* q = p + 2496;
    func_001d4818(q, a, b, c, d);
    func_001d48e8(q, *(u32*)(p + 2528), p + 1660);
    func_001bd5b0(p, 14, 0);
    *(u32*)(p + 32) &= ~2;
}
}  // namespace n001bdb70

// ---- 001bdc18 from src/anon/batch_w9.cpp
namespace n001bdc18 {
void func_001d48b0(void*) asm("func_001d48b0");
void func_001bd668(void*) asm("func_001bd668");
void reset_special_command(u8* c) asm("_ZN2YS14PLAYER_COMMAND21reset_special_commandEv");
void reset_special_command(u8* c) {
    func_001d48b0(c + 2496);
    func_001bd668(c);
}
}  // namespace n001bdc18

// ---- 001bdc48 from src/anon/tiny_auto80_queue.cpp
namespace n001bdc48 {
u32 func_0013b2f8(...) asm("func_0013b2f8");
void func_001bdc48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001bdc48jjjjjjjj");
void func_001bdc48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = ((u32*)(u32)r4)[8];
    r15 = (u32)(r15 & 0x0040u);
    r16 = r4;
    if (r15 == 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013b2f8)(r4, r5, r6, r7, r8, r9, r10, r11);
        r15 = ((u32*)(u32)r16)[8];
        r15 = (u32)(r15 | 0x0040u);
        ((u32*)(u32)r16)[8] = r15;
    }
}
}  // namespace n001bdc48

// ---- 001bdc88 from src/anon/batch_w63.cpp
namespace n001bdc88 {
void func_0013b320(void*) asm("func_0013b320");
void func_001bdc88(u8* p) asm("func_001bdc88");
void func_001bdc88(u8* p) {
    if (*(u32*)(p + 32) & 0x40) {
        func_0013b320(p);
        *(u32*)(p + 32) &= ~0x40;
    }
}
}  // namespace n001bdc88

// ---- 001bdcd0 from src/anon/batch_w59.cpp
namespace n001bdcd0 {
u32 func_001819c0(u32) asm("func_001819c0");
u32 func_001bd590(u32) asm("func_001bd590");
u32 func_001bdcd0(u32 a) asm("func_001bdcd0");
u32 func_001bdcd0(u32 a) {
    u32 r = 0;
    if (!func_001819c0(a) || func_001bd590(a)) r = 1;
    return r;
}
}  // namespace n001bdcd0

// ---- 001bdd20 from src/anon/batch_w10.cpp
namespace n001bdd20 {
extern u16 D_0032f218 asm("D_0032f218");
s32 func_001bdd20(u8* p) asm("func_001bdd20");
s32 func_001bdd20(u8* p) {
    return (*(u32*)(p + 32) & 0x10) || D_0032f218 == 0;
}
}  // namespace n001bdd20

// ---- 001bdd50 from src/anon/batch_w90.cpp
namespace n001bdd50 {
void YS__OBJ__get_target_pos(void*, void*) asm("YS__OBJ__get_target_pos");
void YS__MATH__GetScreenPos(void*, void*) asm("YS__MATH__GetScreenPos");
void func_0013b2b8(f32) asm("func_0013b2b8");
void func_001bdd50(u8* self) asm("func_001bdd50");
void func_001bdd50(u8* self)
{
    if (!(*(u32*)(self + 32) & 0x40)) return;
    u8* t = *(u8**)(self + 2528);
    f32 step = 0.125f;
    f32 v = *(f32*)(self + 2624) + step;
    if (*(u32*)(*(u8**)(t + 12) + 8) & 0x10000) {
        f32 a[4];
        f32 b[4];
        YS__OBJ__get_target_pos(b, t);
        YS__MATH__GetScreenPos(a, b);
        if (a[0] < 1984.0f && 2080.0f < a[1]) v = *(f32*)(self + 2624) - step;
    }
    f32 r = v < 0.5f ? 0.5f : (1.0f < v ? 1.0f : v);
    *(f32*)(self + 2624) = r;
    func_0013b2b8(r);
}
}  // namespace n001bdd50

// ---- 001bde58 from src/anon/batch_w20.cpp
namespace n001bde58 {
void func_001bc688(u8*) asm("func_001bc688");
void func_00190128(u8*) asm("func_00190128");
void YS__PLAYER_COMMAND__clear_override(u8* p) asm("YS__PLAYER_COMMAND__clear_override");
void YS__PLAYER_COMMAND__clear_override(u8* p) {
    func_001bc688(p);
    func_00190128(p + 12);
}
}  // namespace n001bde58

// ---- 001bde88 from src/anon/tiny_auto80_queue.cpp
namespace n001bde88 {
void func_001bc720(...) asm("func_001bc720");
void YS__FIELD_COMMAND__init_field(u8* a0) asm("_Z29YS__FIELD_COMMAND__init_fieldPh");
void YS__FIELD_COMMAND__init_field(u8* a0) {
    u8* s0 = a0 + 36;
    s32 s1 = 18;
    u8* s2 = a0;
    do {
        func_001bc720(s0);
        s1 = s1 - 1;
        s0 = s0 + 116;
    } while (s1 >= 0);
    *(u32*)(s2 + 2724) = 0;
}
}  // namespace n001bde88

// ---- 001bded8 from src/anon/batch_w41.cpp
namespace n001bded8 {
void func_001bd370(u8*) asm("func_001bd370");
void func_001bc720(u8*) asm("func_001bc720");
void func_001bd3a0(u8*) asm("func_001bd3a0");
void func_001bdf68(u8*) asm("func_001bdf68");
void YS__FIELD_COMMAND__InitShortcut(void) asm("YS__FIELD_COMMAND__InitShortcut");
void func_001d6da8(u8*) asm("func_001d6da8");
void YS__FIELD_COMMAND__init_area(u8* p) asm("YS__FIELD_COMMAND__init_area");
void YS__FIELD_COMMAND__init_area(u8* p) {
    func_001bd370(p);                          
    func_001bc720(p + 36);
    func_001bc720(p + 732);
    *(u32*)(p + 2528) = 0;
    func_001bd3a0(p);
    func_001bdf68(p);
    YS__FIELD_COMMAND__InitShortcut();
    func_001d6da8(p + 2642);
    *(u32*)(p + 2728) = 0;
    *(u32*)(p + 2736) = 0;
}
}  // namespace n001bded8

// ---- 001bdf38 from src/anon/batch_w9.cpp
namespace n001bdf38 {
void func_001bd2d0(void*) asm("func_001bd2d0");
void func_001bd5b0(void*, u32, u32) asm("func_001bd5b0");
void YS__FIELD_COMMAND__initialize(u8* p) asm("YS__FIELD_COMMAND__initialize");
void YS__FIELD_COMMAND__initialize(u8* p) {
    func_001bd2d0(p);
    func_001bd5b0(p, *(u32*)(p + 2724), 0);
}
}  // namespace n001bdf38

// ---- 001bdf68 from src/anon/auto80_199_queue.cpp
namespace n001bdf68 {
void func_001bdf68(u32 a0) asm("_Z13func_001bdf68j");
void func_001bdf68(u32 a0) {
    u32 s0;
    u32 s1;
    u32 s2;
    u32 s3;
    u32 v0;

    s0 = 0;
    s1 = a0 + 2628;
    s2 = 0;
    s3 = a0;
L001bdf94:
    v0 = func_001a67b0(s0++);
    if (v0 != 0) {
        *(u16*)s1 = (u16)v0;
        s2 = s2 + 1;
        s1 = s1 + 2;
    }
    if ((s32)s0 < 6) {
        goto L001bdf94;
    }
    *(u16*)(((s2 << 1) + s3) + 2628) = 0;
}
}  // namespace n001bdf68

// ---- 001bdfe0 from src/anon/tiny_more2.cpp
namespace n001bdfe0 {
u32 func_001bdfe0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001bdfe0jjjj");
u32 func_001bdfe0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return (*(u16*)((u32)a0 + (2628)) != 0); }
}  // namespace n001bdfe0

// ---- 001bdff0 from src/anon/batch_w48.cpp
namespace n001bdff0 {
struct G32bb30 { u8 pad[13606]; u8 n; u8 pad2[14052 - 13607]; s32 total; u8 pad3[8]; u8 pad4[8]; u16 cur[4]; };
extern G32bb30 D_0032bb30 asm("D_0032bb30");
u8* YS__COMMAND_ELEM__Get(u32) asm("YS__COMMAND_ELEM__Get");
u16 func_001a67b0(s32) asm("func_001a67b0");
void YS__FIELD_COMMAND__InitShortcut(void) asm("YS__FIELD_COMMAND__InitShortcut");
void YS__FIELD_COMMAND__InitShortcut(void) {
    for (s32 i = 0; i < 4; i++) {
        u8* e = YS__COMMAND_ELEM__Get(D_0032bb30.cur[i]);
        if (*(u16*)(e + 2) == 2) D_0032bb30.cur[i] = func_001a67b0(*(s16*)(e + 4));
    }
}
}  // namespace n001bdff0

// ---- 001be060 from src/anon/batch_w91.cpp
namespace n001be060 {
struct E1be { s32 type; };
u32 func_001bc9e8(E1be*) asm("func_001bc9e8");
u32 func_001d48e8(u8*, u32, E1be*) asm("func_001d48e8");
void func_001be410(u8*) asm("func_001be410");
u32 func_001bdcd0(u8*) asm("func_001bdcd0");
void func_001be4b0(u8*) asm("func_001be4b0");
void func_001bd618(u8*, s32) asm("func_001bd618");
void func_001be060(u8* p) asm("func_001be060");
void func_001be060(u8* p) {
    E1be** cur = *(E1be***)(p + 2240);
    E1be* e = *cur;
    if (e && e->type == 10) { func_001bc9e8(e); return; }
    if (!func_001d48e8(p + 2496, *(u32*)(p + 2528), *cur)) func_001be410(p);
    e = **(E1be***)(p + 2240);
    if (!e) return;
    if (!func_001bc9e8(e)) return;
    if (!(*(u64*)(*(u8**)(p + 2532) + 8) & 0x10000)) return;
    E1be** c = *(E1be***)(p + 2240);
    s32 idx = c ? c - (E1be**)(p + 2536) + 1 : 0;
    if (idx < 2) {
        if (!func_001bdcd0(p)) func_001be4b0(p);
    } else {
        func_001bd618(p, 1);
    }
}
}  // namespace n001be060

// ---- 001be168 gap
namespace n001be168 {
void tgt_ctor(void*) asm("_ZN2YS6TARGETC1Ev");
void tgt_set_obj(void*, u32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
struct TG {
    u32 w[5];
    TG() { tgt_ctor(this); }
};
struct E12 { u8 b[12]; };
u8* elem_get(u32) asm("_Z21YS__COMMAND_ELEM__Getjjjj");
s32 func_001bd918(u8*, u8*, TG*) asm("_Z13func_001bd918jjj");
void func_001bd5b0(u8*, s32, s32) asm("func_001bd5b0");
static inline E12* cur(u8* m) { return (E12*)m + *(s32*)(m + 108); }
static inline TG* owner_tgt(u8* p) { u8* o = *(u8**)(*(u8**)(p + 2528) + 2880); return (TG*)(o + 4); }
s32 func_001be168(u8* p) asm("func_001be168");
s32 func_001be168(u8* p) {
    u8* m = **(u8***)(p + 2240);
    TG t;
    u8* e;
    switch (*(s32*)m) {
    case 4: {
        u8* pm = (*(u8***)(p + 2240))[-1];
        e = elem_get(*(u16*)(cur(pm)->b + 14));
        tgt_set_obj(&t, *(u32*)(p + *(s32*)(m + 108) * 4 + 2652), 0);
        break;
    }
    case 11: {
        u8* pm = (*(u8***)(p + 2240))[-1];
        e = elem_get(*(u16*)(cur(pm)->b + 14));
        break;
    }
    case 5:
        e = elem_get(*(u16*)(cur(m)->b + 14));
        switch (*(s8*)(e + 6)) {
        case 4:
            tgt_set_obj(&t, *(u32*)(p + 2528), 0);
            break;
        case 11:
            break;
        default:
            t = *owner_tgt(p);
            break;
        }
        break;
    default: {
        e = elem_get(*(u16*)(cur(m)->b + 14));
        if (*(s8*)(e + 6) >= 0) {
            func_001bd5b0(p, *(s8*)(e + 6), 1);
            return 0;
        }
        TG* d = *(TG**)(cur(m)->b + 20);
        if (d) t = *d;
        else t = *owner_tgt(p);
        break;
    }
    }
    return func_001bd918(p, e, &t);
}
}  // namespace n001be168

// ---- 001be358 gap
namespace n001be358 {
void func_001bce90(u8*, u32, u32, u32) asm("func_001bce90");
void func_001bec68(u8*) asm("func_001bec68");
void func_001bee78(u8*) asm("func_001bee78");
void func_001be900(u8*) asm("func_001be900");
void YS__FIELD_COMMAND__make_item(u8*) asm("YS__FIELD_COMMAND__make_item");
void func_001beb00(u8*) asm("func_001beb00");
void func_001bed30(u8*) asm("func_001bed30");
void func_001be940(u8*) asm("func_001be940");
void func_001be5f0(u8*) asm("func_001be5f0");
void func_001be778(u8*) asm("func_001be778");
void YS__FIELD_COMMAND__make_shortcut(u8*) asm("YS__FIELD_COMMAND__make_shortcut");
void func_001be358(u8* p) asm("func_001be358");
void func_001be358(u8* p) {
    u8* q = p + 1196;
    u32 t = *(u32*)(p + 2728);
    if (t) {
        func_001bce90(q, t, *(u32*)(p + 2732), 0);
        return;
    }
    if (*(u32*)(*(u8**)(p + 2528) + 1164) == 0) return;
    func_001bec68(p);
    func_001bee78(p);
    func_001be900(p);
    YS__FIELD_COMMAND__make_item(p);
    func_001beb00(p);
    func_001bed30(p);
    func_001be940(p);
    func_001be5f0(p);
    func_001be778(p);
    YS__FIELD_COMMAND__make_shortcut(p);
}
}  // namespace n001be358

// ---- 001be410 from src/anon/batch_w67.cpp
namespace n001be410 {
s32 func_001818e8(void*) asm("func_001818e8");
s32 func_001bd590(void*) asm("func_001bd590");
s32 func_001bdb10(void*, s32) asm("func_001bdb10");
void func_001bc720(u32) asm("func_001bc720");
void func_001be410(u8* o) asm("func_001be410");
void func_001be410(u8* o)
{
    if (!func_001818e8(o)) return;
    if ((**(u64**)(o + 2532) & 0x800000) && !func_001bd590(o)) {
        if (func_001bdb10(o, 5)) *(u32*)(o + 32) |= 2;
    } else if (func_001bdb10(o, *(s32*)(o + 2724))) {
        func_001bc720(**(u32**)(o + 2240));
        *(u32*)(o + 32) &= ~2;
    }
}
}  // namespace n001be410

// ---- 001be4b0 from src/anon/batch_w6.cpp
namespace n001be4b0 {
void func_001be4e0(u8*, u32) asm("func_001be4e0");
void func_002ba2e8(u32, u32) asm("func_002ba2e8");
void func_001be4b0(u8* p) asm("func_001be4b0");
void func_001be4b0(u8* p) {
    func_001be4e0(p, *(u32*)(p + 0xaa4) ? 0 : 6);
    func_002ba2e8(20, 0);
}
}  // namespace n001be4b0

// ---- 001be4e0 from src/anon/batch_w2366_nsa.cpp
namespace n001be4e0 {
struct In1be { u8 pad[0x6c]; u32 x6c; };
struct Sub1be { u8 b[116]; };
struct S1be {
    u8 pad[0x24];
    Sub1be sub[19];
    u8 pad2[0x8c0 - 0x24 - 19 * 116];
    In1be** p8c0;
    u8 pad3[0xaa4 - 0x8c4];
    u32 aa4;
};
void func_001bc730(Sub1be*, u32) asm("func_001bc730");
void func_001bd618(S1be*, u32) asm("func_001bd618");
void func_001bd5b0(S1be*, u32, u32) asm("func_001bd5b0");
void wtarget_001be4e0(u32, u32, u32, u32) asm("_Z16wtarget_001be4e0jjjj");
void wtarget_001be4e0(u32 a0, u32 a1, u32, u32) {
    S1be* s = (S1be*)a0;
    s->aa4 = a1;
    Sub1be* p = &s->sub[a1];
    u32 v = (*s->p8c0)->x6c;
    func_001bc730(p, v);
    func_001bd618(s, 0);
    func_001bd5b0(s, s->aa4, 0);
}
}  // namespace n001be4e0

// ---- 001be540 from src/anon/batch_w67.cpp
namespace n001be540 {
extern u8 D_0032bae0 asm("D_0032bae0");
s32 func_001818a0(void*) asm("func_001818a0");
s32 func_00177870(void*) asm("func_00177870");
void YS__COMMAND_MENU__add(void*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_001be540(u8* o, void* x) asm("func_001be540");
void func_001be540(u8* o, void* x)
{
    if (!func_001818a0(o)) { YS__COMMAND_MENU__add(x, 104, 0, 1); return; }
    if (D_0032bae0 == 9) { YS__COMMAND_MENU__add(x, 136, 0, 1); return; }
    u8* t = *(u8**)(o + 2528);
    if (*(s32*)(t + 2896) == 2) { YS__COMMAND_MENU__add(x, 365, 0, 1); return; }
    if (func_00177870(t)) YS__COMMAND_MENU__add(x, 541, 0, 1);
    else YS__COMMAND_MENU__add(x, 1, 0, 1);
}
}  // namespace n001be540

// ---- 001be5f0 from src/anon/batch_wcx2.cpp
namespace n001be5f0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Snd63 { u8 pad[5]; u8 pri; };
struct Obj63 { u8 pad[32]; u32 fl; u8 m[2492]; u8* pl; };
s32 func_001bd590(Obj63*) asm("func_001bd590");
void func_001be890(Obj63*, u8*) asm("func_001be890");
void func_001bc778(u8*) asm("func_001bc778");
void func_001be540(Obj63*, u8*) asm("func_001be540");
void func_001bf0c8(Obj63*) asm("func_001bf0c8");
s32 func_001bdfe0(Obj63*) asm("func_001bdfe0");
Snd63* YS__COMMAND_MENU__add(u8*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
s32 func_001bdd20(Obj63*) asm("func_001bdd20");
s32 YS__PLAYER__is_changing(u8*) asm("YS__PLAYER__is_changing");
s32 func_001917c0(void) asm("func_001917c0");
static inline bool Is63(u8* p) { return *(s32*)(p + 2896) == 6; }
void func_001be5f0(Obj63* o) asm("func_001be5f0");
void func_001be5f0(Obj63* o)
{
    u8* m = o->m;
    if (func_001bd590(o)) {
        func_001be890(o, m);
        return;
    }
    func_001bc778(m);
    func_001be540(o, m);
    if (*(s32*)(o->pl + 2896) == 3) {
        func_001bf0c8(o);
        YS__COMMAND_MENU__add(m, 707, 0, 1);
    } else {
        YS__COMMAND_MENU__add(m, func_001bdfe0(o) ? 2 : 104, 0, 1);
    }
    if (func_001bdd20(o)) YS__COMMAND_MENU__add(m, 104, 0, 1);
    else YS__COMMAND_MENU__add(m, 3, 0, 1);
    u8 pri = 5;
    if (o->fl & 0x20) {
        YS__COMMAND_MENU__add(m, 104, 0, 1);
        return;
    }
    if (YS__PLAYER__is_changing(o->pl)) {
        Snd63* s = YS__COMMAND_MENU__add(m, 5, 0, 1);
        if (Is63(o->pl) && func_001917c0()) s->pri = pri;
    } else {
        Snd63* s = YS__COMMAND_MENU__add(m, 4, 0, 1);
        if (*(s32*)(o->pl + 2896)) s->pri = pri;
    }
}
}  // namespace n001be5f0

// ---- 001be778 from src/anon/batch_w1822.cpp
namespace n001be778 {
struct W22Menu { u8 pad[1]; };
struct W22PC { u8 pad[0x2dc]; W22Menu menu; u8 pad2[0x358 - 0x2dd]; s32 f358; };
s32 PC_is_override_top(W22PC*) asm("_ZN2YS14PLAYER_COMMAND15is_override_topEv");
void Menu_clear(W22Menu*) asm("_ZN2YS12COMMAND_MENU5clearEv");
s32 Summon_GetMode() asm("_ZN2YS6SUMMON7GetModeEv");
s32 Summon_GetCurrent() asm("_ZN2YS6SUMMON10GetCurrentEv");
s32 func_001819c0() asm("func_001819c0");
s32 func_00181a18() asm("func_00181a18");
void func_001be890(W22PC*, W22Menu*) asm("func_001be890");
void func_001bf010(W22PC*) asm("func_001bf010");
void func_001be540(W22PC*, W22Menu*) asm("func_001be540");
void YS__COMMAND_MENU__add(W22Menu*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_001be778(W22PC* p) asm("func_001be778");
void func_001be778(W22PC* p)
{
    W22Menu* m = &p->menu;
    if (PC_is_override_top(p)) { func_001be890(p, m); return; }
    Menu_clear(m);
    func_001be540(p, m);
    if (Summon_GetMode() == 0) {
        if (p->f358 > 0) YS__COMMAND_MENU__add(m, 0x48, 0, 1);
        else YS__COMMAND_MENU__add(m, 0x68, 0, 1);
    } else YS__COMMAND_MENU__add(m, 0x13c, 0, 1);
    if (Summon_GetMode() == 2 && Summon_GetCurrent() == 201) {
        func_001bf010(p);
        YS__COMMAND_MENU__add(m, 0x25d, 0, 1);
    } else {
        YS__COMMAND_MENU__add(m, func_001819c0() ? 0x49 : 0x68, 0, 1);
    }
    YS__COMMAND_MENU__add(m, func_00181a18() ? 0x51 : 0x68, 0, 1);
}
}  // namespace n001be778

// ---- 001be890 from src/anon/batch_w48.cpp
namespace n001be890 {
void func_001bc778(void*) asm("func_001bc778");
u8* func_001bd570(void*, s32) asm("func_001bd570");
void YS__COMMAND_MENU__add(void*, u32, void*, u32) asm("YS__COMMAND_MENU__add");
void func_001be890(void* o, void* b) asm("func_001be890");
void func_001be890(void* o, void* b) {
    func_001bc778(b);
    for (s32 i = 0; i < 4; i++) {
        u8* e = func_001bd570(o, i + 3);
        YS__COMMAND_MENU__add(b, *(u16*)(e + 2), e + 12, *(u8*)(e + 4));
    }
}
}  // namespace n001be890

// ---- 001be900 from src/anon/batch_w21.cpp
namespace n001be900 {
void func_001bc778(void*) asm("func_001bc778");
void YS__COMMAND_MENU__make(void*, void*) asm("YS__COMMAND_MENU__make");
void func_001be900(u8* p) asm("func_001be900");
void func_001be900(u8* p) {
    func_001bc778(p + 152);
    YS__COMMAND_MENU__make(p + 152, p + 2628);
}
}  // namespace n001be900

// ---- 001be940 from src/anon/batch_w42.cpp
namespace n001be940 {
void command_menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
s32 YS__OBJ__can_control(u32) asm("YS__OBJ__can_control");
void func_001d6da8(void*) asm("func_001d6da8");
void YS__COMMAND_MENU__make(void*, void*) asm("YS__COMMAND_MENU__make");
void func_001be940(u8* p) asm("func_001be940");
void func_001be940(u8* p)
{
    if (YS__OBJ__can_control(*(u32*)(p + 2528))) func_001d6da8(p + 2642);                             
    command_menu_clear(p + 848);
    YS__COMMAND_MENU__make(p + 848, p + 2642);
}
}  // namespace n001be940

// ---- 001be9a0 from src/anon/perm_001be9a0.cpp
namespace n001be9a0 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct E
{
  u8 b0;
  u8 b1;
  u16 id;
  u8 cnt;
  u8 b5;
  u8 pad[6];
} E;
typedef struct Tbl
{
  u8 pad[8];
  s32 count;
  E e[1];
} Tbl;
typedef struct PR
{
  u8 pad[18];
  u8 n;
  u8 pad2[33];
  u16 a[8];
  u16 b[8];
} PR;
typedef struct R
{
  u8 pad[16];
  u16 id;
} R;
typedef struct Obj
{
  u8 pad[268];
  Tbl t;
  u8 pad2[(2528 - 268) - (sizeof(Tbl))];
  void *party;
} Obj;
void _ZN2YS12COMMAND_MENU5clearEv(Tbl *) asm("_ZN2YS12COMMAND_MENU5clearEv");
PR *_ZN2YS5PARTY11get_partramEv(void *) asm("_ZN2YS5PARTY11get_partramEv");
R* func_001a80c8(u32) asm("func_001a80c8");
void YS__COMMAND_MENU__add(Tbl *, u32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_001bce00(Tbl *) asm("func_001bce00");
void YS__FIELD_COMMAND__make_item(Obj *o) asm("YS__FIELD_COMMAND__make_item");
void YS__FIELD_COMMAND__make_item(Obj *o)
{
  unsigned int new_var;
  Tbl *t = &o->t;
  PR *p;
  _ZN2YS12COMMAND_MENU5clearEv(t);
  s32 k = 0;
  p = _ZN2YS5PARTY11get_partramEv(o->party);
  if (p->n != 0)
  {
    do
    {
      u32 c = p->b[k];
      if (c == 0)
      {
        c = p->a[k];
        if (c == 0)
        {
          goto next;
        }
      }
      {
        R *r = func_001a80c8(c);
        s32 i;
        for (i = 0; i < t->count; i++)
        {
          if (t->e[i].id == r->id)
          {
            if (p->a[k])
            {
              t->e[i].cnt++;
            }
            break;
          }
        }

        if (i < t->count)
        {
          goto next;
        }
        YS__COMMAND_MENU__add(t, r->id, 0, 1);
        if (p->a[k] == 0)
        {
          ((t->e + t->count) - 1)->cnt = 0;
          new_var = 6;
          ((t->e + t->count) - 1)->b5 = new_var;
        }
      }
      next:
      k++;

    }
    while (k < p->n);
  }
  func_001bce00(t);
}
}  // namespace n001be9a0

// ---- 001beb00 from src/anon/batch_wcx2.cpp
namespace n001beb00 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Snd64 { u8 pad[5]; u8 pri; };
struct Obj64 { u8 pad[32]; u32 fl; u8 pad2[348]; u8 m[2144]; u8* pl; };
extern u8 D_00351ec0[] asm("D_00351ec0");
extern u8 D_00351eb8[] asm("D_00351eb8");
void func_001bc778(u8*) asm("func_001bc778");
s32 func_001c8db8(u8*, s32) asm("func_001c8db8");
s32 func_001bbf40(void) asm("func_001bbf40");
s32 func_001a36e0(s32) asm("func_001a36e0");
s32 func_001a3570(s32) asm("func_001a3570");
u16* func_001a3868(s32) asm("func_001a3868");
s32 YS__SACRIFICE__GetCommandStatus(u16*) asm("YS__SACRIFICE__GetCommandStatus");
Snd64* func_001bc780__91789(u8*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_001beb00(Obj64* o) asm("func_001beb00");
void func_001beb00(Obj64* o)
{
    if (o->fl & 0x20) return;
    u8* m = o->m;
    func_001bc778(m);
    if (func_001c8db8(D_00351ec0, 1)) return;
    if (func_001c8db8(D_00351eb8, 0)) return;
    if (*(u32*)(*(u8**)(o->pl + 12) + 8) & 0x20) return;
    if (func_001bbf40()) return;
    o->fl |= 0x20;
    for (s32 i = 1; i < 7; i++) {
        s32 x = func_001a36e0(i);
        if (func_001a3570(x) <= 0) continue;
        u16* it = func_001a3868(x);
        s32 k = YS__SACRIFICE__GetCommandStatus(it);
        if (k != 2) {
            Snd64* s = func_001bc780__91789(m, *it, 0, 1);
            if (k == 1) s->pri = 5;
        }
        o->fl &= ~0x20;
    }
}
}  // namespace n001beb00

// ---- 001bec68 from src/anon/batch_w77.cpp
namespace n001bec68 {
void func_001bc778(u8*) asm("func_001bc778");
u8* func_00176b20(s32) asm("func_00176b20");
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
u32 func_0016a070(u8*) asm("func_0016a070");
u32 func_001b77e8(u32) asm("func_001b77e8");
void YS__COMMAND_MENU__add(u8*, u32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_001bec68(u8* p) asm("func_001bec68");
void func_001bec68(u8* p)
{
    u8* q = p + 500;
    func_001bc778(q);
    for (s32 i = 0; i < 3; i++) {
        u8* e = func_00176b20(i);
        if (!YS__OBJ__is_exist(e)) continue;
        if (*(u32*)(e + 1416) & 0x400000) continue;
        if (!*(u32*)(e + 1164)) continue;
        *(u8**)(p + *(s32*)(q + 8) * 4 + 2652) = e;
        YS__COMMAND_MENU__add(q, func_001b77e8(func_0016a070(e)), 0, 1);
    }
}
}  // namespace n001bec68

// ---- 001bed30 from src/anon/tiny_wrappers_more.cpp
namespace n001bed30 {
u32 func_001d42d0(u32, u32, u32, u32) asm("_Z13func_001d42d0jjjj");
u32 func_001bed30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001bed30jjjj");
u32 func_001bed30(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d42d0(((u32)(a0) + 1080u), a1, a2, a3);
}
}  // namespace n001bed30

// .rodata 0x36dc88: alternate command ids, read by 0x1bed48.
extern const u16 R_0036dc88[4] asm("D_0036dc88") = { 0x02ba, 0x02bd, 0x02c0, 0x02ab };

// ---- 001bed48 from src/anon/batch_w1835.cpp
namespace n001bed48 {
struct W1835Ent { u16 a; u16 type; s16 key; };
struct W1835Ctx { u8 pad[0x12]; u8 n; u8 pad2[0x34 - 0x13]; u16 ids[1]; };
struct W1835Res { u8 pad[6]; s8 idx; };
struct W1835Mode { u8 pad[0xb50]; s32 mode; };
struct W1835Self { u8 pad[0x268]; u8 sub[0x9e0 - 0x268]; W1835Mode* o; };
struct W1835Tbl { u8 pad[0x36f8]; u16 ids[4]; };
extern W1835Tbl D_0032bb30 asm("D_0032bb30");
extern u16 D_0036dc88[4] asm("D_0036dc88");
void func_001bc778(void*) asm("func_001bc778");
W1835Res* YS__COMMAND_MENU__add(void*, u16, s32, s32) asm("YS__COMMAND_MENU__add");
W1835Ent* YS__COMMAND_ELEM__Get(u16) asm("YS__COMMAND_ELEM__Get");
W1835Ctx* func_00177850(W1835Mode*) asm("func_00177850");
void YS__FIELD_COMMAND__make_shortcut(W1835Self* self) asm("YS__FIELD_COMMAND__make_shortcut");
void YS__FIELD_COMMAND__make_shortcut(W1835Self* self) {
    void* sub = self->sub;
    s32 i = 0;
    func_001bc778(sub);
    W1835Tbl* t = &D_0032bb30;
    u16* alt = D_0036dc88;
    u16* ids = t->ids;
    do {
        u16 id = *ids;
        W1835Ent* e = YS__COMMAND_ELEM__Get(id);
        s32 cnt;
        if (e->type == 3) {
            W1835Ctx* c = func_00177850(self->o);
            s32 j;
            cnt = 0;
            for (j = 0; j < c->n; j++) {
                if (c->ids[j] == e->key) cnt++;
            }
        } else {
            if (self->o->mode == 3) id = *alt;
            cnt = 1;
        }
        ids++;
        alt++;
        YS__COMMAND_MENU__add(sub, id, 0, cnt)->idx = i + 1;
        i++;
    } while (i < 4);
}
}  // namespace n001bed48

// ---- 001bee78 from src/anon/batch_w97.cpp
namespace n001bee78 {
s32 YS__CHANGEIN__CanExec(u8*) asm("YS__CHANGEIN__CanExec");
void func_001bc778(u8*) asm("func_001bc778");
u32 func_001a8bd0(s32) asm("func_001a8bd0");
u32 func_001a8c10(u32, s32) asm("func_001a8c10");
u32 func_0017e668(u32) asm("func_0017e668");
s32 YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
void func_00190878(u8*, u32, s32) asm("func_00190878");
u32 func_001b7800(u32) asm("func_001b7800");
void YS__COMMAND_MENU__add(u8*, u32, u8*, s32) asm("YS__COMMAND_MENU__add");
s32 func_0017e358(u32) asm("func_0017e358");
void func_001bee78(u8* p) asm("func_001bee78");
void func_001bee78(u8* p) {
    u8* list = p + 964;
    s32 flag = YS__CHANGEIN__CanExec(p);
    func_001bc778(list);
    u32 grp = func_001a8bd0(-1);
    for (s32 i = 1; i < 3; i++) {
        u32 m = func_001a8c10(grp, i);
        if (!m) continue;
        u32 c = func_0017e668(m);
        if (!YS__OBJ__is_exist(c)) continue;
        s32 n = *(s32*)(list + 8);
        u8* e = p + n * 20 + 2664;
        func_00190878(e, c, 0);
        YS__COMMAND_MENU__add(list, func_001b7800(m), e, 1);
        if (flag && func_0017e358(c)) continue;
        list[n * 12 + 17] = 5;
    }
}
}  // namespace n001bee78

// ---- 001befa8 from src/anon/batch_w10.cpp
namespace n001befa8 {
void func_001bdc18(void*) asm("func_001bdc18");
void func_001bd5b0(void*, u32, s32) asm("func_001bd5b0");
void YS__FIELD_COMMAND__reset_special_command(u8* p) asm("YS__FIELD_COMMAND__reset_special_command");
void YS__FIELD_COMMAND__reset_special_command(u8* p) {
    func_001bdc18(p);
    func_001bd5b0(p, *(u32*)(p + 2724), 0);
}
}  // namespace n001befa8

// ---- 001befd8 from src/anon/batch_w11.cpp
namespace n001befd8 {
struct P1be { u8 pad[2728]; u32 a; u32 b; };
void func_001bd668(void*) asm("func_001bd668");
void func_001bd5b0(void*, s32, s32) asm("func_001bd5b0");
void YS__FIELD_COMMAND__set_minigame(P1be* p, u32 a, u32 b) asm("YS__FIELD_COMMAND__set_minigame");
void YS__FIELD_COMMAND__set_minigame(P1be* p, u32 a, u32 b) {
    p->a = a;
    p->b = b;
    func_001bd668(p);
    func_001bd5b0(p, 10, 0);
}
}  // namespace n001befd8

// ---- 001bf010 from src/anon/batch_wcx.cpp
namespace n001bf010 {
u8* func_0016b800(s32) asm("func_0016b800");
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
void func_00190878(u8*, u8*, s32) asm("func_00190878");
void func_001bc778(u8*) asm("func_001bc778");
s32 func_001c8bb8(s8*) asm("func_001c8bb8");
u32 func_001c8cc0(s8) asm("func_001c8cc0");
void YS__COMMAND_MENU__add(u8*, u32, u8*, s32) asm("YS__COMMAND_MENU__add");
u8* func_001bf010(u8* p) asm("func_001bf010");
u8* func_001bf010(u8* p)
{
    u8* o = func_0016b800(201);
    YS__OBJ__is_exist(o);
    func_00190878(p + 2704, o, 0);
    u8* q = p + 384;
    func_001bc778(q);
    s8 buf[16];
    s32 n = func_001c8bb8(buf);
    for (s32 i = 0; i < n; i++) YS__COMMAND_MENU__add(q, func_001c8cc0(buf[i]), p + 2704, 1);
    return q;
}
}  // namespace n001bf010

// ---- 001bf0c8 from src/anon/batch_w21.cpp
namespace n001bf0c8 {
void func_001bc778(void*) asm("func_001bc778");
void YS__COMMAND_MENU__make(void*, void*) asm("YS__COMMAND_MENU__make");
extern u8 D_00351248[] asm("D_00351248");
void func_001bf0c8(u8* p) asm("func_001bf0c8");
void func_001bf0c8(u8* p) {
    func_001bc778(p + 1428);
    YS__COMMAND_MENU__make(p + 1428, D_00351248);
}
}  // namespace n001bf0c8

// ---- 001bf100 from src/anon/tiny_more2.cpp
namespace n001bf100 {
void func_001bf100(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001bf100jjjj");
void func_001bf100(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0 + (2736)); u32 bit=1u<<a1; v|=bit; *(u32*)((u32)a0 + (2736)) = v; }
}  // namespace n001bf100

// ---- 001bf118 from src/anon/batch_w1668.cpp
namespace n001bf118 {
void func_001bf118(u8* p, s32 b) asm("func_001bf118");
void func_001bf118(u8* p, s32 b) {
    if (b == 0) { *(u32*)(p + 0xab0) = 0; return; }
    *(u32*)(p + 0xab0) &= ~(1 << b);
}
}  // namespace n001bf118

// ---- 001bf140 from src/anon/auto200_999.cpp
namespace n001bf140 {
u32 func_001bf140(u32 a0, u32 a1) asm("_Z13func_001bf140jj");
u32 func_001bf140(u32 a0, u32 a1) {
    u32 ret = 0;
    if (a1 != 0) {
        u32 v = *(u32 *)(a0 + 2736);
        u32 mask = 1u << a1;
        v &= mask;
        ret = v != 0;
    }
    return ret;
}
}  // namespace n001bf140

// ---- 001bf168 from src/anon/batch_w94.cpp
namespace n001bf168 {
void func_00169398(u8*, u32, u32*, s32, u32, f32) asm("func_00169398");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
extern u32 D_003638d0 asm("D_003638d0");
extern u32 D_003512e8[] asm("D_003512e8");
static inline f32 frand(void) {
    u32 s = D_003638d0 * 69069;
    D_003638d0 = s;
    return (f32)s * 2.3283064e-10f;
}
static inline f32 rrange(f32 lo, f32 hi) {
    return lo + frand() * (hi - lo);
}
void func_001bf168(u8* p, u32* src, u32 arg, u32 owner, f32 f) asm("func_001bf168");
void func_001bf168(u8* p, u32* src, u32 arg, u32 owner, f32 f) {
    func_00169398(p, *src, src, 4, arg, rrange(-3.1415927f, 3.1415927f));
    *(u32*)(p + 1416) |= 0x40000;
    *(u32*)(p + 2484) = owner;
    *(f32*)(p + 2488) = f;
    *(f32*)(p + 60) = f;
    *(u32*)p = (u32)D_003512e8;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 2528) = 0;
    *(u32*)(p + 2532) = 0;
    *(u32*)(p + 2536) = 0;
    func_0016bd60(p, 12);
}
}  // namespace n001bf168

// ---- 001bf270 from src/anon/batch_w253.cpp
namespace n001bf270 {
extern u32 D_003638d0 asm("D_003638d0");
extern u32 D_003512e8 asm("D_003512e8");
void func_00169398(void*, u32, void*, s32, s32, f32) asm("func_00169398");
void func_0016bd60(void*, s32) asm("func_0016bd60");
static inline f32 rf() { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 rnd2(f32 lo, f32 w) { return lo + rf() * w; }
void func_001bf270(u8* a0, u32* a1, s32 a2, u32 a3, f32 f) asm("func_001bf270");
void func_001bf270(u8* a0, u32* a1, s32 a2, u32 a3, f32 f) {
    func_00169398(a0, *a1, a1, 4, a2, rnd2(-3.1415927f, 6.2831855f));
    *(u32*)(a0 + 1416) |= 0x40000;
    *(u32*)(a0 + 2484) = a3;
    *(f32*)(a0 + 2488) = f;
    *(f32*)(a0 + 60) = f;
    *(u32*)a0 = (u32)&D_003512e8;
    *(u32*)(a0 + 264) |= 2;
    *(u32*)(a0 + 2528) = 0;
    *(u32*)(a0 + 2532) = 0;
    *(u32*)(a0 + 2536) = 0;
    func_0016bd60(a0, 12);
}
}  // namespace n001bf270

// ---- 001bf378 from src/anon/batch_w275.cpp
namespace n001bf378 {
struct V7e {
    f32 x, y, z, w;
    V7e() {}
    V7e(const V7e& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V7e& operator=(const V7e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 len() const { f32 r; asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory"); return r; }
} __attribute__((aligned(16)));
static inline V7e operator-(const V7e& a, const V7e& b) {
    V7e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
s32 func_001bfca0(void*) asm("func_001bfca0");
void func_001991a8(s32, s32) asm("func_001991a8");
V7e* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
V7e func_0016be98(void*) asm("func_0016be98");
void func_0016bd60(void*, s32) asm("func_0016bd60");
void* func_0016a070(void*) asm("func_0016a070");
void* YS__ITEM__WhereGet(void*, void*, s32) asm("YS__ITEM__WhereGet");
void YS__ITEM__Get(void*, void*, s32) asm("YS__ITEM__Get");
void func_001bf378(u8* p, u8* t) asm("func_001bf378");
void func_001bf378(u8* p, u8* t) {
    *(u8**)(p + 2536) = t;
    if (func_001bfca0(p)) {
        if (*(u32*)(*(u8**)(p + 2536) + 1416) & 0x80) func_001991a8(81, 1);
        (*(s32*)(*(u8**)(p + 2536) + 2764))++;
    } else {
        void* r = YS__ITEM__WhereGet(*(void**)(p + 2484), func_0016a070(*(void**)(p + 2536)), 1);
        if (r) YS__ITEM__Get(*(void**)(p + 2484), r, 0);
    }
    *(u32*)(p + 2528) |= 4;
    V7e* d = (V7e*)(p + 2512);
    *d = *YS__OBJ__get_pos(p) - func_0016be98(*(void**)(p + 2536));
    f32 l = d->len() * 0.05f;
    l = l < 30.0f ? 30.0f : (l > 60.0f ? 60.0f : l);
    *(f32*)(p + 2496) = l;
    *(f32*)(p + 2492) = l;
    func_0016bd60(p, 13);
}
}  // namespace n001bf378

// ---- 001bf4e8 gap
namespace n001bf4e8 {
extern u8* D_0034e948 asm("D_0034e948");
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
s32 func_0019bb18(u8*) asm("func_0019bb18");
u32 YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
s32 func_001a4ff8(u8*, u32, f32, f32) asm("func_001a4ff8");
s32 func_001bfca0(u8*) asm("func_001bfca0");
u8* YS__ENEMY__Each(u8*) asm("YS__ENEMY__Each");
s32 func_001919d0(void) asm("func_001919d0");
s32 func_001919f8(void) asm("func_001919f8");
void func_001bf378(u8*, u8*) asm("func_001bf378");
static inline s32 hit(u8* o, u8* p) { return func_001a4ff8(o, YS__OBJ__get_pos(p), 0.0f, 0.0f); }
void func_001bf4e8(u8* p) asm("func_001bf4e8");
void func_001bf4e8(u8* p) {
    u8* o = D_0034e948;
    if (!YS__OBJ__is_exist(o)) return;
    if (*(u32*)(o + 1416) & 0x2000000) return;
    if (*(u32*)(p + 2528) & 4) return;
    if (!func_0019bb18(p)) return;
    if (!hit(o, p)) {
        if (func_001bfca0(p)) {
            for (o = 0; (o = YS__ENEMY__Each(o)) != 0;) {
                if (hit(o, p)) { func_001bf378(p, o); return; }
            }
            return;
        }
        if (!func_001919d0() && !func_001919f8()) return;
    }
    func_001bf378(p, o);
}
}  // namespace n001bf4e8

// ---- 001bf620 from src/anon/batch_w55.cpp
namespace n001bf620 {
struct EntW55 { u32 id; f32 f; };
u8* func_0016e920(u32) asm("func_0016e920");
u8* func_001a80c8(u32) asm("func_001a80c8");
extern EntW55 D_0036dcf8[] asm("D_0036dcf8");
void* func_001050d8(u32) asm("func_001050d8");
void func_001bf270(void*, u8*, u32, u32, f32) asm("func_001bf270");
void* YS__PRIZEBOX__Appear(u32 a, u32 b) asm("YS__PRIZEBOX__Appear");
void* YS__PRIZEBOX__Appear(u32 a, u32 b) {
    EntW55* e = &D_0036dcf8[func_001a80c8(a)[22]];
    void* m = func_001050d8(2544);
    func_001bf270(m, func_0016e920(e->id), b, a, e->f);
    return m;
}
}  // namespace n001bf620

// ---- 001bf6a8 from src/anon/batch_w49.cpp
namespace n001bf6a8 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
typedef void (*Fn1bf6a8)(u8*);
void func_001bf6a8(void) asm("func_001bf6a8");
void func_001bf6a8(void) {
    u8* n = 0;
    while ((n = YS__OBJ__Each(n)) != 0)
        if (*(u32*)(n + 1416) & 0x40000) (*(Fn1bf6a8*)(*(u8**)n + 40))(n);
}
}  // namespace n001bf6a8

// ---- 001bf710 gap
namespace n001bf710 {
extern u32 D_003638d0 asm("D_003638d0");
static inline f32 frand(void) {
    u32 s = D_003638d0 * 69069;
    D_003638d0 = s;
    return (f32)s * 2.3283064e-10f;
}
static inline f32 rrange(f32 lo, f32 hi) {
    return lo + frand() * (hi - lo);
}
void YS__ACTION_JUMP__start(u8*, u8*) asm("YS__ACTION_JUMP__start");
void func_001bf710(u8* a, u8* o) asm("func_001bf710");
void func_001bf710(u8* a, u8* o) {
    YS__ACTION_JUMP__start(a, o);
    *(f32*)(o + 32) = rrange(-5.0f, 5.0f);
    *(f32*)(o + 40) = rrange(-5.0f, 5.0f);
    *(f32*)(o + 36) = rrange(-15.0f, -10.0f);
}
}  // namespace n001bf710

// ---- 001bf890 gap
namespace n001bf890 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
extern f32 D_00349e10 asm("D_00349e10");
QV func_001bf890(u32, u8* o) asm("func_001bf890");
QV func_001bf890(u32, u8* o) {
    f32 v = *(f32*)(o + 36);
    if (0.0f < v) *(u32*)(o + 264) &= ~2;
    f32 y = v + 1.5f;
    *(f32*)(o + 36) = (y < 25.0f) ? y : 25.0f;
    *(f32*)(o + 32) *= 0.97f;
    *(f32*)(o + 40) *= 0.97f;
    return ScaleQ(*(QV*)(o + 32), D_00349e10);
}
#undef QCOPY
}  // namespace n001bf890

// ---- 001bf930 from src/anon/batch_w66.cpp
namespace n001bf930 {
u32 YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_002bc188(s32, u32) asm("func_002bc188");
void func_001bf930(u32, u8* p) asm("func_001bf930");
void func_001bf930(u32, u8* p) {
    f32 v = *(f32*)(p + 36);
    if (2.5f < v) {
        *(f32*)(p + 36) = v * -0.8f;
        s32 c = *(s32*)(p + 2532);
        if (c < 2) {
            func_002bc188(14, YS__OBJ__get_pos(p));
            c = *(s32*)(p + 2532);
        }
        *(s32*)(p + 2532) = c + 1;
    } else {
        *(u32*)(p + 2528) |= 1;
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(p + 32) : "memory");
    }
    *(u32*)(p + 264) |= 0x8000000;
}
}  // namespace n001bf930

// ---- 001bf9d8 gap
namespace n001bf9d8 {
u32 YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_002bc188(s32, u32) asm("func_002bc188");
void func_001bf9d8(u32, u8* p) asm("func_001bf9d8");
void func_001bf9d8(u32, u8* p) {
    *(u32*)(p + 264) |= 3;
    func_002bc188(18, YS__OBJ__get_pos(p));
}
}  // namespace n001bf9d8

// ---- 001bfa08 from src/anon/batch_w293.cpp
namespace n001bfa08 {
inline void* operator new[](unsigned int, void* p) { return p; }
inline void* operator new(unsigned int, void* p) { return p; }
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void ScaleTo(QWord* r, const QWord& a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "f"(k) : "$8", "memory");
}
static inline void AddTo(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
extern f32 D_00349e10 asm("D_00349e10");
s32 YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
f32 sinf(f32) asm("sinf");
void YS__OBJ__get_dir(QWord*, u8*) asm("YS__OBJ__get_dir");
void func_0016aeb8(u8*, f32) asm("func_0016aeb8");
void func_0016be98(QWord*, u32) asm("func_0016be98");
void func_0016ace0(u8*, QWord*) asm("func_0016ace0");
u32 func_001a37e8(u32, s32) asm("func_001a37e8");
void dk__TREASURE_INFO__openPrizeInfo(u32) asm("dk__TREASURE_INFO__openPrizeInfo");
typedef void (*VF8)(u8*);
void YS__ACTION_PRIZEBOX_GET__control(u8* a0, u8* p) asm("YS__ACTION_PRIZEBOX_GET__control");
void YS__ACTION_PRIZEBOX_GET__control(u8* a0, u8* p)
{
    *(f32*)(p + 2492) -= D_00349e10;
    f32 r;
    if (YS__OBJ__is_exist(*(u32*)(p + 2536)) && 0.0f < (r = *(f32*)(p + 2492))) {
        f32 t = r / *(f32*)(p + 2496);
        f32 one = 1.0f;
        f32 pi = 3.14159274f;
        t = one - sinf((one - t) * pi * 0.5f);
        QWord v, s, w;
        ScaleTo(&s, *(QWord*)(p + 2512), t);
        v = s;
        v.v[1] -= sinf(t * pi) * 50.0f;
        YS__OBJ__get_dir(&s, p);
        func_0016aeb8(p, s.v[3] + (one - t) * 0.52359873f);
        func_0016be98(&w, *(u32*)(p + 2536));
        AddTo(&s, w, v);
        func_0016ace0(p, &s);
        if (t < 0.1f) {
            t *= 9.99999905f;
            *(f32*)(p + 60) = *(f32*)(p + 2488) * t;
        }
        return;
    }
    u32 h = *(u32*)(p + 2484);
    if (h) dk__TREASURE_INFO__openPrizeInfo(func_001a37e8(h, -1));
    ((VF8)(*(void***)p)[8])(p);
}
}  // namespace n001bfa08

// .rodata 0x36dcf8: (model id, scale) table, read by 0x1bf620.
struct R_EntW55 { u32 id; f32 f; };
extern const R_EntW55 R_0036dcf8[12] asm("D_0036dcf8") = {
    { 0x3b9, 1.6f }, { 0x3b9, 2.3f }, { 0x3b9, 3.2f },
    { 0x3bb, 1.6f }, { 0x3bb, 2.3f }, { 0x3bb, 3.2f },
    { 0x3ba, 1.6f }, { 0x3ba, 2.3f }, { 0x3ba, 3.2f },
    { 0x3b8, 1.6f }, { 0x3b8, 2.3f }, { 0x3b8, 3.2f },
};

// ---- 001bfbd8 from src/anon/batch_w60.cpp
namespace n001bfbd8 {
void YS__OBJENTRY__ReadRequest(s32, s32, s32) asm("YS__OBJENTRY__ReadRequest");
void YS__PRIZEBOX__Read(void) asm("YS__PRIZEBOX__Read");
void YS__PRIZEBOX__Read(void) {
    YS__OBJENTRY__ReadRequest(952, -1, 30);
    YS__OBJENTRY__ReadRequest(953, -1, 30);
    YS__OBJENTRY__ReadRequest(954, -1, 30);
    YS__OBJENTRY__ReadRequest(955, -1, 30);
}
}  // namespace n001bfbd8

// ---- 001bfc28 from src/anon/batch_w49.cpp
namespace n001bfc28 {
void ttarget0_001bfc28(void) asm("_Z17ttarget0_001bfc28v");
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
extern u32 D_0034e948 asm("D_0034e948");
void func_001bf378(u8*, u32) asm("func_001bf378");
void ttarget0_001bfc28(void) {
    u32 v = D_0034e948;
    u8* n = 0;
    while ((n = YS__OBJ__Each(n)) != 0)
        if (*(u32*)(n + 1416) & 0x40000) func_001bf378(n, v);
}
}  // namespace n001bfc28

// ---- 001bfca0 from src/anon/tiny_jal_wrappers.cpp
namespace n001bfca0 {
u32 func_0016a020(u32, u32, u32, u32) asm("_Z13func_0016a020jjjj");
u32 func_001bfca0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001bfca0jjjj");
u32 func_001bfca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0016a020(r4, r5, r6, r7);
    r2 = (u32)(r2 ^ 0x0883u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n001bfca0

// ---- 001bfcc8 from src/anon/batch_w60.cpp
namespace n001bfcc8 {
void YS__OBJ__get_target_pos(void*, void*) asm("YS__OBJ__get_target_pos");
void func_0016f000(s32, void*, f32) asm("func_0016f000");
void func_001991a8(s32, s32) asm("func_001991a8");
void YS__PRIZEBOX__DropNmPresent(u8* p, s32 n) asm("YS__PRIZEBOX__DropNmPresent");
void YS__PRIZEBOX__DropNmPresent(u8* p, s32 n) {
    u8 buf[16];
    s32 i;
    if (!n) return;
    YS__OBJ__get_target_pos(buf, p);
    if (*(s32*)(p + 2764) < n) n = *(s32*)(p + 2764);
    for (i = 0; i < n; i++) func_0016f000(2179, buf, 0.0f);
    *(s32*)(p + 2764) -= n;
    if (*(u32*)(p + 1416) & 0x80) func_001991a8(80, n);
}
}  // namespace n001bfcc8

// ---- 001bfd60 from src/anon/batch_w1734.cpp
namespace n001bfd60 {
struct Slot_1bfd60 { int id; int pad[3]; };
Slot_1bfd60* func_001bfd60(Slot_1bfd60* p, int v) asm("func_001bfd60");
Slot_1bfd60* func_001bfd60(Slot_1bfd60* p, int v) {
    Slot_1bfd60* empty = 0;
    for (int i = 0; i < 8; i++) {
        if (p[i].id == v) return &p[i];
        if (p[i].id == 0) empty = &p[i];
    }
    empty->id = v;
    return empty;
}
}  // namespace n001bfd60

