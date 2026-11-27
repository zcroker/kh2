// Linked unit 0x0010fb10-0x0010fea0: func_0010fb10 (camera target pick), was whole asm (src/anon/asm_0010fb10.s).
// Byte-identical with -G0 -fno-strict-aliasing -fno-gcse. No asm, pins or volatile, but the source is a reconstruction of
// what loop.c / reload did, not the original text (the sibling 0x10ff08 in unit_0010fea0.cpp is plain ents[i] / D[cnt] code):
//  - elem(p, i, sz): the element size as an inline PARAMETER gives the `li 28` life 2, so loop.c hoists it at plain -O2
//    and reduces &tab[cnt] / cnt*28 (s2 / s7); in the post-loop it lets `T + 4` issue before the mult.
//  - `tab` is set twice (dead `tab = 0` at the pass top): it stays an inner-preheader pseudo (not hoisted out of the pass
//    loop, not folded into the giv init), cse2 derives the hoisted D+4 from it and the giv init is a copy (move s2,t7).
//  - `one`: set at the inner loop top, cse1 makes the switch's `li 1` use it, loop.c hoists it, it is spilled and reload
//    rematerialises `li t7,1` (advances the spill-register ring so the in-loop D+4 lands in t6); `c->count += one` is its
//    second use (reload folds it back to addiu 1).
//  - `cap = 32` in the preheader: a spilled constant whose insn takes the sched1 slot next to `tab = D`, which puts the
//    giv copy before `f = e` (move s2,t7; move s1,s0); reload folds it back into slti 32.
//  - member-pointer calls written out by hand (delta re-read in the loop, kept in the post-loop call).
#include "../common/types.h"
extern "C" {
struct Tgt10fb10;
void func_00190128(Tgt10fb10*);
struct Tgt10fb10 {
    s32 f0, f4, f8, f12, f16;
    Tgt10fb10() { func_00190128(this); }
};
struct Q10fb10 { u8 pad[8]; s32 n; };
struct Ent10fb10;
struct Who10fb10 { s32 dummy; };
typedef s32 (Who10fb10::*Pick10fb10)(Ent10fb10*, Tgt10fb10*, s32*, s32);
struct Ent10fb10 {
    u32 flags;
    Pick10fb10 pick;
    u8 pad[4];
    Q10fb10* q;
    u8 pad2[16];
};
struct Cand10fb10 {
    Ent10fb10* e;
    Tgt10fb10 t;
    s32 score;
};
struct Cam10fb10 {
    u8 pad0[1164];
    void* f1164;
    u8 pad1[2912 - 1168];
    Who10fb10* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3168 - 2944];
    s32 f3168;
    s32 f3172;
    u8 pad4[3300 - 3176];
    s32 f3300;
    s32 count;
};


s32 func_0010f8d0(Cam10fb10*);
void func_0010eee8(Cam10fb10*);
s32 func_001137e0(Who10fb10*);
Ent10fb10* func_001137e8(Who10fb10*);
s32 YS__SHEET__is_mpdrive(void*);
s32 func_0010f648(s32);
void func_0010ef28(Cam10fb10*, Ent10fb10*);
void func_0010eed8(Cam10fb10*, Ent10fb10*, s32);
static inline s32 pick10fb10(Cam10fb10* c, Ent10fb10* e, Tgt10fb10* t, s32* s, s32 f)
{
    return (c->who->*e->pick)(e, t, s, f);
}
}



typedef s32 (*PF10fb10)(void*, Ent10fb10*, Tgt10fb10*, s32*, s32);
static inline void* elem10fb10(void* p, s32 i, s32 sz) { return (void*)(i * sz + (u32)p); }
extern "C" s32 func_0010fb10(Cam10fb10* c)
{
    if (!c->f3300) return 0;
    if (func_0010f8d0(c)) return 0;
    s32 save0 = c->f3168;
    s32 save1 = c->f3172;
    c->flags |= 0x20;
    func_0010eee8(c);
    c->count = 0;
    s32 n = func_001137e0(c->who);
    Ent10fb10* ents = func_001137e8(c->who);
    static Cand10fb10 D_003a9298[32];
    Tgt10fb10 t;
    s32 score;
    Cand10fb10* T = D_003a9298;
    s32 pass = 0; s32 one;
    do {
        s32 i = 0;
        s32 cnt = 0;
        Ent10fb10* e; Ent10fb10* f; u32 off; Cand10fb10* tab = 0;
        if (n > 0) { s32 cap = 32; tab = D_003a9298; e = ents; f = e; off = 0; do {
            one = 1;
            if (!f->pick) continue;
            switch (pass) {
            case 0:
                if (!(f->flags & 0x10)) continue;
                break;
            case 1:
                if (!(f->flags & 0x20)) continue;
                break;
            }
            if (f->q && f->q->n > 0 && c->f1164 && YS__SHEET__is_mpdrive(c->f1164)) continue;
            func_00190128(&t);
            s32 r;
            {
                s32 d = *(s32*)((u8*)e + 8);
                u8* w;
                PF10fb10 fn;
                if (d & 1) { w = (u8*)c->who; u32 ix = *(u32*)((u8*)e + 4) >> 2; PF10fb10* vt = *(PF10fb10**)(w + (d >> 1)); fn = vt[ix]; }
                else { fn = *(PF10fb10*)((u8*)e + 4); w = (u8*)c->who; }
                r = fn(w + (*(s32*)((u8*)e + 8) >> 1), e, &t, &score, 1);
            }
            if (r && cnt < cap) {
                { Cand10fb10* p = (Cand10fb10*)elem10fb10(tab, cnt, sizeof(Cand10fb10)); p->e = e; *(Tgt10fb10*)((u8*)&D_003a9298[0].t + off) = t; p->score = score; } cnt++; off += 28;
            }
        } while (f++, e++, ++i < n); }
        if (cnt > 0) {
            s32 k = func_0010f648(cnt);
            Ent10fb10* e = T[k].e;
            Tgt10fb10* tp = (Tgt10fb10*)elem10fb10(&T->t, k, sizeof(Cand10fb10));
            s32* ps = &D_003a9298[k].score;
            {
                s32 d = *(s32*)((u8*)e + 8);
                u8* w;
                PF10fb10 fn;
                if (d & 1) { w = (u8*)c->who; u32 ix = *(u32*)((u8*)e + 4) >> 2; PF10fb10* vt = *(PF10fb10**)(w + (d >> 1)); fn = vt[ix]; }
                else { fn = *(PF10fb10*)((u8*)e + 4); w = (u8*)c->who; }
                fn(w + (d >> 1), e, tp, ps, 0);
            }
            if ((e->flags & 1) == 0) {
                func_0010ef28(c, e);
                c->count += one;
            } else {
                c->count = 0;
            }
            func_0010eed8(c, e, *ps);
            return 1;
        }
    } while (++pass < 2);
    c->f3168 = save0;
    c->f3172 = save1;
    return 0;
}

