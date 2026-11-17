// Linked unit 0x001b87a0-0x001b9670: YS world flags + command queue, object list helpers (one namespace per old matched source).
// 0x1b9670 (object update task, never written; C draft is two s-registers off) stays outside; unit_001b9880.cpp follows it.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 001b87a0 (was src/anon/tiny.cpp)
namespace n001b87a0 {
void func_001b87a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b87a0jjjj");
void func_001b87a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-29296)) = (u32)a0;
}
}  // namespace n001b87a0

// 001b87b0 (was src/anon/batch_w24.cpp)
namespace n001b87b0 {
void u_tail0_001b87b0(void) asm("_Z16u_tail0_001b87b0v");
void func_001b8838(s32) asm("func_001b8838");
void func_001b8da0(void) asm("func_001b8da0");
struct B288 { u32 w[8]; u8 _20[255]; u8 flag; };
extern B288 D_0032fb68 asm("D_0032fb68");
void u_tail0_001b87b0(void) asm("_Z16u_tail0_001b87b0v");
void u_tail0_001b87b0(void) {
    B288* b = &D_0032fb68;
    u32* w = b->w;
    for (s32 i = 7; i >= 0;) {
        *w = 0;
        i--;
        w++;
    }
    b->flag = 0;
    func_001b8838(0);
    func_001b8da0();
}
}  // namespace n001b87b0

// 001b8800 (was src/anon/batch_w16.cpp)
namespace n001b8800 {
// scan_list_by_half
u8 func_002fd248(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u32* D_01d48d90 asm("D_01d48d90");
extern u8 D_00320448 asm("D_00320448");
u8 func_001b8800(u32 a) asm("func_001b8800");
u8 func_001b8800(u32 a) {
    u32* p = D_01d48d90;
    return func_002fd248(a, p + 2, p[1], 16, &D_00320448);
}
}  // namespace n001b8800

// 001b8838 (was src/anon/batch_wcx2.cpp)
namespace n001b8838 {
// 0x001ae0a0: definition moved into src/anon/unit_001ada38.cpp

struct Q18 { u32 bits[8]; u8 queue[255]; u8 count; };
extern Q18 D_0032fb68 asm("D_0032fb68");
s32 func_001b8958(s32) asm("func_001b8958");
u8* func_001b8800(s32) asm("func_001b8800");
s32 func_00181550(void) asm("func_00181550");
void func_001b8838(s32 code) asm("func_001b8838");
void func_001b8838(s32 code)
{
    Q18* q = &D_0032fb68;
    switch (code) {
    case 37:
        if (func_001b8958(115)) return;
        break;
    case 42:
        if (func_001b8958(86)) return;
        break;
    case 45:
        if (func_001b8958(84)) return;
        break;
    case 46:
        if (func_001b8958(114)) return;
        break;
    }
    u32* w = &D_0032fb68.bits[(u32)code >> 5];
    u32 v = *w;
    u32 m = 1 << (code & 31);
    if (v & m) return;
    *w = v | m;
    if (func_001b8800(code)[1] == 1 && func_00181550()) return;
    q->queue[q->count++] = code;
}
}  // namespace n001b8838

// 001b8958 (was src/anon/auto200_999.cpp)
namespace n001b8958 {
extern u8 D_0032fb68 asm("D_0032fb68");
u32 WORLDFLAG_Check(s32 a0) asm("_ZN2YS9WORLDFLAG5CheckEi");
u32 WORLDFLAG_Check(s32 a0) {
    u32 v = (u32)a0;
    u32 idx = v >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032fb68 + (idx << 2));
    u32 bit = v & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}
}  // namespace n001b8958

// 001b8988 (was src/anon/batch_w65.cpp)
namespace n001b8988 {
extern struct { u8 v; } D_01d48d94 asm("D_01d48d94");
extern u8* D_01d48d90 asm("D_01d48d90");
void func_001b89d0(void) asm("func_001b89d0");
void func_001db610(void*, void (*)(void), s32) asm("func_001db610");
void func_001b8988(u8* p, u8 v) asm("func_001b8988");
void func_001b8988(u8* p, u8 v) {
    D_01d48d94.v = v;
    s32 o = *(s32*)(p + 12);
    if (o) func_001db610(D_01d48d90 + o, func_001b89d0, 0);
}
}  // namespace n001b8988

// 001b89d0 (was src/anon/batch_w2039.cpp)
namespace n001b89d0 {
struct Ent_b { u16 id; u16 pad; };
struct Cmd_b { u16 op; u16 n; Ent_b e[1]; };
struct Obj_b { u8 b0, b1, b2, b3; };
Obj_b* func_001b6d70(u16) asm("func_001b6d70");
void func_001b6d88(Obj_b*, s32) asm("func_001b6d88");
void func_001b8bf8(Cmd_b*, s32) asm("func_001b8bf8");
void func_001b8c70(Cmd_b*, s32) asm("func_001b8c70");
void func_001c3670(u16) asm("func_001c3670");
void func_001c36e8(u16) asm("func_001c36e8");
void func_001c8ec0(u16) asm("func_001c8ec0");
extern u8 D_0032fcc9 asm("D_0032fcc9");
extern u8 D_01d48d94 asm("D_01d48d94");
// 002e2a30: moved to src/anon/unit_002e1908.cpp

s32 func_001b89d0(Cmd_b* p) asm("func_001b89d0");
// 002e2a30: moved to src/anon/unit_002e1908.cpp

s32 func_001b89d0(Cmd_b* p)
{
    s32 i;
    Obj_b* o;
    switch (p->op) {
    case 1: func_001b8bf8(p, 0); break;
    case 2: func_001b8bf8(p, 1); break;
    case 3: func_001b8bf8(p, 2); break;
    case 4:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            func_001b6d88(o, 2);
            o->b3 &= ~2;
        }
        break;
    case 5:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            o->b3 |= 2;
        }
        break;
    case 6:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            o->b3 |= 1;
        }
        break;
    case 7: func_001b8bf8(p, 3); break;
    case 8: func_001b8c70(p, 0); break;
    case 9: func_001b8c70(p, 1); break;
    case 10: func_001b8c70(p, 2); break;
    case 11: func_001b8c70(p, 3); break;
    case 12:
        for (i = 0; i < p->n; i++)
            func_001c3670(p->e[i].id);
        break;
    case 13:
        for (i = 0; i < p->n; i++)
            func_001c36e8(p->e[i].id);
        break;
    case 15:
        if (D_01d48d94)
            func_001c8ec0(p->e[0].id);
        D_0032fcc9 = *(u8*)&p->e[0];
        break;
    }
    return 1;
}
}  // namespace n001b89d0

// 001b8bf8 (was src/anon/auto80_199_queue.cpp)
namespace n001b8bf8 {
// 001b8348 YS::LIBRETTO::Init: moved to src/anon/unit_001b82d8.cpp

// 001b8450: moved to src/anon/unit_001b82d8.cpp

// 001b8718: static initialiser, now made by gcc in src/anon/unit_001b82d8.cpp

void func_001b8bf8(u32 a0, u32 a1) asm("_Z13func_001b8bf8jj");
// 001b8348 YS::LIBRETTO::Init: moved to src/anon/unit_001b82d8.cpp

// 001b8450: moved to src/anon/unit_001b82d8.cpp

// 001b8718: static initialiser, now made by gcc in src/anon/unit_001b82d8.cpp

void func_001b8bf8(u32 a0, u32 a1) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s3 = a1;
    if (*(u16*)(a0 + 2) != 0) {
        u32 s0 = a0 + 4;
        do {
            u32 v0 = func_001b6d70(*(u16*)(s0 + 0));  // table_entry_ptr_b
            s1 = s1 + 1;
            s0 = s0 + 4;
            func_001b6d88(v0, s3);
        } while ((s32)s1 < (s32)*(u16*)(s2 + 2));
    }
}
}  // namespace n001b8bf8

// 001b8c70 (was src/anon/auto80_199_queue.cpp)
namespace n001b8c70 {
void func_001b8c70(u32 a0, u32 a1) asm("_Z13func_001b8c70jj");
void func_001b8c70(u32 a0, u32 a1) {
    u32 s1 = 0;
    u32 s2 = a0;
    u32 s3 = a1;
    if (*(u16*)(a0 + 2) != 0) {
        u32 s0 = a0 + 4;
        do {
            u32 v0 = func_001c2b58(*(u16*)(s0 + 0));
            s1 = s1 + 1;
            *(u8*)(v0 + 0) = (u8)s3;
            if (!((s32)s1 < (s32)*(u16*)(s2 + 2))) {
                break;
            }
            s0 = s0 + 4;
        } while (true);
    }
}
}  // namespace n001b8c70

// 001b8ce0 (was src/anon/batch_w52.cpp)
namespace n001b8ce0 {
// 0x0019ead0: definition moved into src/anon/unit_0019ea10.cpp

struct E1b8 {
    u8 id;
    u8 pad[3];
    u32 key;
    u32 c, d;
};
struct T1b8 {
    u32 a;
    s32 n;
    E1b8 e[1];
};
extern T1b8* D_01d48d90 asm("D_01d48d90");
void func_001b8838(u8) asm("func_001b8838");
void func_001b8ce0(u32 key) asm("func_001b8ce0");
void func_001b8ce0(u32 key) {
    E1b8* e = D_01d48d90->e;
    s32 i;
    for (i = 0; i < D_01d48d90->n; i++, e++) {
        if (e->key == key) func_001b8838(e->id);
    }
}
}  // namespace n001b8ce0

// 001b8d60 (was src/anon/batch_w12.cpp)
namespace n001b8d60 {
extern u8 D_0032fb68[] asm("D_0032fb68");
u8 func_001b8d60(u8* dst) asm("func_001b8d60");
u8 func_001b8d60(u8* dst) {
    s32 i;
    u8 n = D_0032fb68[287];
    D_0032fb68[287] = 0;
    for (i = 0; i < n; i++) dst[i] = D_0032fb68[32 + i];
    return n;
}
}  // namespace n001b8d60

// 001b8da0 (was src/anon/auto80_199_queue.cpp)
namespace n001b8da0 {
void func_001b8da0() asm("_Z13func_001b8da0v");
void func_001b8da0() {
    u8 buf[256];
    u32 s0 = 0;
    u32 s1 = func_001b8d60(buf);
    if ((s32)s1 > 0) {
        do {
            u32 v0 = func_001b8800(buf[s0]);
            s0 = s0 + 1;
            func_001b8988(v0, 0);
        } while ((s32)s0 < (s32)s1);
    }
}
}  // namespace n001b8da0

// 001b8e00 (was src/anon/batch_w48.cpp)
namespace n001b8e00 {
// 001ac310: moved to src/anon/unit_001abb28.cpp

s32 func_00181550(s32) asm("func_00181550");
s32 func_001b8958(s32) asm("func_001b8958");
void func_001b8838(s32) asm("func_001b8838");
extern s16 D_0036dbb0[][2] asm("D_0036dbb0");
void func_001b8e00(s32 i) asm("func_001b8e00");
void func_001b8e00(s32 i) {
    s32 v;
    if (func_00181550(i)) v = D_0036dbb0[i][1];
    else v = D_0036dbb0[i][0];
    if (v < 0) return;
    if (func_001b8958(v)) return;
    func_001b8838(v);
}
}  // namespace n001b8e00

// 001b8e78 (was src/anon/tiny.cpp)
namespace n001b8e78 {
void func_001b8e78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b8e78jjjj");
void func_001b8e78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-29288)) = (u32)a0;
}
}  // namespace n001b8e78

// 001b8e88 (was src/anon/batch_w62.cpp)
namespace n001b8e88 {
// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
struct Tbl1d5 { u32 f0; u32 n; u8 data[1]; };
extern Tbl1d5* D_01d48d98 asm("D_01d48d98");
extern u8 D_00320458[] asm("D_00320458");
struct R1b8 { u16 h0; u16 h2; s16 h4; };
R1b8* func_002fd248(u32, u8*, u32, u32, u8*) asm("func_002fd248");
u32 func_001a67b0(s32) asm("func_001a67b0");
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b8e88jjjj");
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b8e88jjjj");
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) {
    NoTail g;
    R1b8* r = func_002fd248(a0, D_01d48d98->data, D_01d48d98->n, 48, D_00320458);
    if (r->h2 != 2) return;
    if (r->h0 == r->h2) return;
    Tbl1d5* t = D_01d48d98;
    func_002fd248(func_001a67b0(r->h4), t->data, t->n, 48, D_00320458);
}
}  // namespace n001b8e88

// 001b8f10 (was src/anon/batch_w1795.cpp)
namespace n001b8f10 {
struct W1795V4 { f32 x, y, z, w;
  W1795V4() {}
  W1795V4& operator=(const W1795V4& o) { if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
// VU0 helpers: vector subtract, multiply and 3-component dot product.
static inline W1795V4 operator-(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1795V4 operator*(const W1795V4& a, const W1795V4& b) {
    W1795V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct W1795Ob2 { u8 pad[0x1f]; u8 kind; };
// 0x0018a250: definition moved into src/anon/unit_00189d38.cpp

s32 func_0019c218(s32, W1795Ob2*) asm("func_0019c218");
s32 W1795_ctarget(s32) asm("_Z16ctarget_0019ba60jjjj");
s32 func_001b8f10(W1795Ob2* o, s32 a, s32* p) asm("func_001b8f10");
s32 func_001b8f10(W1795Ob2* o, s32 a, s32* p) {
    switch (o->kind) {
    case 0: if (func_0019c218(a, o)) return 1; break;
    case 1: if (p) W1795_ctarget(*p); if (func_0019c218(*p, o)) return 1; break;
    case 2: if (p) W1795_ctarget(*p); if (func_0019c218(a, o) && func_0019c218(*p, o)) return 1; break;
    }
    return 0;
}
}  // namespace n001b8f10

// 001b8fd8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001b8fd8 {
u32 func_001b8fd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001b8fd8jjjjjjjj");
u32 func_001b8fd8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = (u32)(s32)(*(s8*)((u32)r4 + (s32)(6)));
    r15 = (u32)((s32)0u + (-1));
    r2 = 0u;
    if (r14 != r15) {
        r15 = (u32)(r14 ^ 0x0004u);
        r2 = ((u32)0u < (u32)r15);
    }
    return r2;
}
}  // namespace n001b8fd8

// 001b8ff8 (was src/anon/batch_w1786.cpp)
namespace n001b8ff8 {
struct W1786Flags { u8 pad[0xc]; s32 fl;
  u8 bd(s32 n) { return fl >> n; } };
s32 func_0019c090(s32) asm("func_0019c090");
s32 W1786_IsBattleMode() asm("_ZN2YS6STATUS12IsBattleModeEv");
extern s32 D_0034f240 asm("D_0034f240");
s32 func_001b8ff8(W1786Flags* o, s32 a1) asm("func_001b8ff8");
s32 func_001b8ff8(W1786Flags* o, s32 a1) {
    s32 r = 0;
    if (((o->bd(1) & 1) && func_0019c090(a1)) || ((o->bd(16) & 1) && !W1786_IsBattleMode()) || ((o->bd(5) & 1) == 0 && (D_0034f240 & 2))) r = 1;
    return r;
}
}  // namespace n001b8ff8

// 001b90a8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001b90a8 {
extern u8 D_0032bb30 asm("D_0032bb30");
u32 func_001b90a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b90a8jjjj");
u32 func_001b90a8(u32 a0, u32 a1, u32 a2, u32 a3) {  // halfword_table_3948
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = (u32)(*(u16*)((u32)r4 + (s32)(38)));
    r15 = (u32)&D_0032bb30;
    r14 = (u32)(r14 << 1);
    r14 = (u32)(r14 + r15);
    r2 = (u32)(*(u16*)((u32)r14 + (s32)(14664)));
    return r2;
}
}  // namespace n001b90a8

// 001b90c8 (was src/anon/batch_w7.cpp)
namespace n001b90c8 {
u32 func_001a36e0(u32) asm("func_001a36e0");
u32 func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
void func_001b8e88(u32) asm("func_001b8e88");
// COMMAND_ELEM GetForm
void command_elem_get_form(u32 a0) asm("_ZN2YS12COMMAND_ELEM7GetFormEi");
void command_elem_get_form(u32 a0) asm("_ZN2YS12COMMAND_ELEM7GetFormEi");
void command_elem_get_form(u32 a0) {
    u32 p = func_001a80c8(func_001a36e0(a0));  // table24_find_by_id
    func_001b8e88(*(u16*)(p + 16));
}
}  // namespace n001b90c8

// 001b90f0 (was src/anon/batch_w87.cpp)
namespace n001b90f0 {
// 0x00196540: definition moved into src/anon/unit_00195d00.cpp

// ---- 0x1b90f0 ----
s32 func_0016a080(void*) asm("func_0016a080");
s32 func_001b90f0(u8* o, u8* p) asm("func_001b90f0");
s32 func_001b90f0(u8* o, u8* p) {
    if (*(s32*)(p + 2896) == 12) return 0;
    if ((*(u32*)(p + 1416) & 0x1000000) && *(s32*)(p + 2928)) {
        if (*(u32*)(o + 12) & 0x8000) return 0;
    } else {
        switch (func_0016a080(p)) {
        case 1: if (*(u32*)(o + 12) & 0x400) return 0; break;
        case 14: if (*(u32*)(o + 12) & 0x800) return 0; break;
        case 20: if (*(u32*)(o + 12) & 0x1000) return 0; break;
        case 27: if (*(u32*)(o + 12) & 0x2000) return 0; break;
        }
    }
    return 1;
}
}  // namespace n001b90f0

// 001b91d0 (was src/anon/auto80_199_queue.cpp)
namespace n001b91d0 {
u32 func_001b91d0(u32 a0, u32 a1) asm("_Z13func_001b91d0jj");
u32 func_001b91d0(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 t5 = a0;
    u16 t6 = *(u16*)(a0 + 2);
    u16 t7 = *(u16*)(a0 + 0);
    if (t7 != t6) {
        u32 v0 = func_001b8e88(t6);
        u32 (*rec)(u32, u32) = func_001b91d0;
        u32 out = rec(v0, s0);
        return out;
    }
    s32 bits = (u32)*(u16*)(t5 + 0x2c);
    bits = bits >> s0;
    bits = bits & 1;
    u32 v = (u8)bits;
    return v;
}
}  // namespace n001b91d0

// 001b9230 (was src/anon/auto80_199_queue.cpp)
namespace n001b9230 {
void func_001b9230() asm("_Z13func_001b9230v");
void func_001b9230() {
    D_01d48db8 = 0;
    D_00351210 = 0;

    u32 v0 = func_00102c18(1, 20000, (u32)&D_001b92d0);
    *(u32*)(v0 + 0x30) = (u32)&D_001b92f8;
    v0 = func_001050c8();
    v0 = func_001024b0(v0);

    D_00351214 = v0;
    func_00102788(v0, 0, 5, (u32)&D_001b9670);
    func_001123f0();

    v0 = func_00102c18(1, 0x00016378, (u32)&D_001b9880);
    *(u32*)(v0 + 0x30) = (u32)&D_001b99b0;
    func_00188670();
    return func_001b2f10();
}
}  // namespace n001b9230

// 001b92d0 (was src/anon/batch_w8.cpp)
namespace n001b92d0 {
void func_001a3c88(void) asm("func_001a3c88");
u8 func_001029e8(u32) asm("func_001029e8");
extern u32 D_00351214 asm("D_00351214");
u32 func_001b92d0(void) asm("func_001b92d0");
u32 func_001b92d0(void) {
    func_001a3c88();
    return func_001029e8(D_00351214);
}
}  // namespace n001b92d0

// 001b92f8 (was src/anon/batch_w63.cpp)
namespace n001b92f8 {
typedef void (*VFn)(void*);
void func_001c1060(void) asm("func_001c1060");
void func_001b5400(void) asm("func_001b5400");
void func_00102750(u32) asm("func_00102750");
extern u8* D_01d48da0 asm("D_01d48da0");
extern u32 D_00351214 asm("D_00351214");
static inline u8* b9next(u8* n) {
    if (!n) return D_01d48da0;
    return *(u8**)(n + 2228);
}
void func_001b92f8(void) asm("func_001b92f8");
void func_001b92f8(void) {
    func_001c1060();
    func_001b5400();
    u8* n = 0;
    while ((n = b9next(n))) {
        if (!(*(u32*)(n + 264) & 0x80000)) (*(VFn*)(*(u8**)n + 40))(n);
    }
    func_00102750(D_00351214);
}
}  // namespace n001b92f8

// 001b9380 (was src/anon/batch_w66.cpp)
namespace n001b9380 {
// 001b1ab8: moved to src/anon/unit_001b14d8.cpp
// ---- 001b9380
struct O1b9 { u8 pad[2228]; O1b9* next; u8 pad2[245]; u8 prio; };
struct List1b9 { O1b9* head; O1b9* tail; };
extern List1b9 D_01d48da0 asm("D_01d48da0");
static inline O1b9* Next1b9(O1b9* n) { if (!n) return D_01d48da0.head; return n->next; }
void func_001b9380(O1b9* o) asm("func_001b9380");
void func_001b9380(O1b9* o) {
    O1b9* prev = 0;
    O1b9* n = 0;
    while ((n = Next1b9(n))) {
        if (o->prio <= n->prio) break;
        prev = n;
    }
    if (!prev) {
        if (!D_01d48da0.head) {
            D_01d48da0.tail = o;
            D_01d48da0.head = o;
            o->next = 0;
        } else {
            o->next = D_01d48da0.head;
            D_01d48da0.head = o;
        }
    } else if (prev == D_01d48da0.tail) {
        prev->next = o;
        o->next = 0;
        D_01d48da0.tail = o;
    } else {
        o->next = prev->next;
        prev->next = o;
    }
}
}  // namespace n001b9380

// 001b9420 (was src/anon/batch_w323.cpp)
namespace n001b9420 {
#define FLD(T, o) (*(T*)((u8*)self + (o)))
typedef s32 (*VF)(void*);
#define VC(o) ((VF)((*(void***)self)[(o) / 4]))(self)
typedef void (*VV_)(void*);
#define VV(o) ((VV_)((*(void***)self)[(o) / 4]))(self)
extern f32 D_00349e10 asm("D_00349e10");
extern u32 D_0034f240 asm("D_0034f240");
struct List1d4 { u8* head; u8* tail; };
extern List1d4 D_01d48db0 asm("D_01d48db0");
s32 objIsLeave(void*) asm("_ZN2YS3OBJ8is_leaveEv");
s32 objIsDummy(void*) asm("_ZN2YS3OBJ11is_dummyobjEv");
s32 ctarget(void*) asm("_Z16ctarget_0019c6f0jjjj");
void func_001d7a88(void*) asm("func_001d7a88");
void func_00194010(void*) asm("func_00194010");
void func_0017f620(void*, f32) asm("func_0017f620");
void func_0017f938(void*) asm("func_0017f938");
void func_00183088(void*) asm("func_00183088");
void func_0011ea40(u32, f32) asm("func_0011ea40");
void func_001b9420(u8* self) asm("func_001b9420");
void func_001b9420(u8* self) {
    f32 dt = D_00349e10;
    if (FLD(u32, 264) & 0x10000000) {
        if (VC(36)) VV(40);
    }
    if (objIsLeave(self)) {
        FLD(u32, 2040) |= 0x100;
    } else {
        if (!(FLD(u32, 2040) & 0x80)) VV(8);
        func_001d7a88(self + 1304);
        if (!ctarget(self) && !(D_0034f240 & 0x20)) {
            if (objIsDummy(self)) {
                VV(20);
            } else {
                VV(12);
                if (!(FLD(u32, 268) & 0x400000)) {
                    func_0017f620(self + 320, dt);
                    if (FLD(u32, 2040) & 2) func_0011ea40(FLD(u32, 1648), dt);
                }
                VV(16);
                if (VC(64)) VV(20);
                VV(24);
                func_0017f938(self + 320);
                func_00183088(self);
            }
            func_00194010(self);
            if ((FLD(f32, 2092) == 0.0f && (FLD(u32, 2040) & 0x10)) || FLD(f32, 2256) == 0.0f) VV(32);
        } else {
            if (!objIsDummy(self)) func_0017f938(self + 320);
        }
        if (!objIsLeave(self)) {
            if (!D_01d48db0.tail) {
                D_01d48db0.tail = self;
                D_01d48db0.head = self;
                FLD(u8*, 2232) = 0;
            } else {
                *(u8**)(D_01d48db0.tail + 2232) = self;
                FLD(u8*, 2232) = 0;
                D_01d48db0.tail = self;
            }
        }
    }
    FLD(u32, 2040) |= 0x800;
    FLD(u32, 2040) &= ~0x2000;
}
}  // namespace n001b9420

