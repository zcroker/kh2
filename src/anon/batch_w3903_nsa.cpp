#include "../common/types.h"
extern "C" {
struct Tgt10ff08;
void func_00190128(Tgt10ff08*);
struct Tgt10ff08 {
    s32 f0, f4, f8, f12, f16;
    Tgt10ff08() { func_00190128(this); }
};
struct V10ff08 {
    f32 x, y, z, w;
    V10ff08() {}
    V10ff08(const V10ff08& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Pt10ff08 { f32 x, y, z, w, r; };
struct Q10ff08 { u8 pad[8]; s32 n; };
struct Other10ff08 { u8 pad[384]; s32 level; };
struct Ent10ff08;
struct Who10ff08 { s32 dummy; };
typedef s32 (Who10ff08::*Pick10ff08)(Ent10ff08*, Tgt10ff08*, s32*, s32);
struct Ent10ff08 {
    u32 flags;
    Pick10ff08 pick;
    u8 pad[4];
    Q10ff08* q;
    u8 pad2[8];
    s32 slot;
    u8 pad3[4];
};
struct Cand10ff08 {
    Ent10ff08* e;
    Tgt10ff08 t;
    s32 score;
};
struct Cam10ff08 {
    u8 pad0[1164];
    Other10ff08* other;
    u8 pad1[2548 - 1168];
    Tgt10ff08 tgt;
    u8 pad1b[2912 - 2568];
    Who10ff08* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3072 - 2944];
    V10ff08 dir;
    u8 pad3b[3168 - 3088];
    Ent10ff08* cur;
    s32 score;
    u8 pad4[3304 - 3176];
    s32 count;
};
extern s8 D_003a9618;
extern Cand10ff08 D_003a9620[32];
s32 func_0010fb10(Cam10ff08*);
s32 func_0010f8d0(Cam10ff08*);
s32 func_001137e0(Who10ff08*);
Ent10ff08* func_001137e8(Who10ff08*);
s32 func_001a1de0(Other10ff08*);
s32 func_0010f648(s32);
s32 func_0010f600(Cam10ff08*);
f32 func_0010f660(void);
f32 func_001142b0(Who10ff08*);
s32 func_001137f0(Who10ff08*);
Pt10ff08* func_00113808(Who10ff08*, s32);
void func_0010c9f8(Cam10ff08*, f32, f32, f32, f32, f32);
void func_0010ef28(Cam10ff08*, Ent10ff08*);
void func_0010eed8(Cam10ff08*, Ent10ff08*, s32);
void func_00110630(Cam10ff08*);
Ent10ff08* func_0010fea0(Cam10ff08*);
u8* func_00112570(Cam10ff08*);
void func_0016b010(Cam10ff08*, V10ff08*);
// func_0010ff08: camera target choice. Collects candidate entities whose pick callback accepts them
// (pass 0 skips kind 2 and entities refused by func_001a1de0, pass 1 takes only kind 2), then picks one at random.
void func_0010ff08(Cam10ff08* c)
{
    if (func_0010fb10(c)) return;
    if (func_0010f8d0(c)) return;
    s32 n = func_001137e0(c->who);
    Ent10ff08* ents = func_001137e8(c->who);
    if (!D_003a9618) {
        Cand10ff08* p = D_003a9620;
        for (s32 k = 31; k != -1; k--) {
            func_00190128(&p->t);
            p++;
        }
        D_003a9618 = 1;
    }
    Tgt10ff08 t;
    V10ff08* dp;
    s32 score;
    if (c->cur) {
        if (c->cur->flags & 0x200) {
            c->flags |= 4;
            t = c->tgt;
            score = c->score;
            if ((c->who->*c->cur->pick)(c->cur, &t, &score, 1)) {
                (c->who->*c->cur->pick)(c->cur, &t, &score, 0);
                return;
            }
        }
    }
    if (c->cur && (c->cur->flags & 2) && func_0010f600(c) && func_0010f660() < func_001142b0(c->who)) {
        s32 k = func_001137f0(c->who);
        if (k > 0) {
            Pt10ff08* v = func_00113808(c->who, func_0010f648(k));
            func_0010c9f8(c, v->x, v->y, v->z, v->w, v->r);
            c->count = 0;
            func_0010eed8(c, 0, 0);
            return;
        }
    }
    if (!(c->flags & 0x800) && c->count >= 2) {
        func_00110630(c);
        c->count = 0;
        func_0010eed8(c, 0, 0);
        return;
    }
    Ent10ff08* prev;
    s32 refused = 0;
    c->flags &= ~4;
    Cand10ff08* pick = 0;
    s32 pass = 0;
    prev = func_0010fea0(c);
    do {
        s32 cnt = 0;
        for (s32 i = 0; i < n; i++) {
            if (!ents[i].pick) continue;
            u8 kind;
            if (ents[i].slot == -1) kind = 0;
            else kind = func_00112570(c)[ents[i].slot + 1];
            bool skip = false;
            if (!pass) {
                if (kind == 2) {
                    skip = true;
                } else if (ents[i].q && ents[i].q->n > 0) {
                    if (c->other) skip = func_001a1de0(c->other) != 0;
                    if (kind == 1 && c->other && c->other->level < ents[i].q->n) skip = true;
                }
            } else {
                skip = kind != 2;
            }
            if (skip) continue;
            func_00190128(&t);
            if ((c->who->*ents[i].pick)(&ents[i], &t, &score, 1) && cnt < 32) {
                D_003a9620[cnt].e = &ents[i];
                D_003a9620[cnt].t = t;
                D_003a9620[cnt].score = score;
                cnt++;
            }
        }
        asm("" :: "r"(cnt)); // allocation tie: one more use of cnt gives it s5 before ents
        if (cnt > 0) {
            pick = &D_003a9620[func_0010f648(cnt)];
            if (pick->e == prev) {
                pick = 0;
                refused = 1;
            }
        }
        if (pick) goto found;
        pass++;
    } while (refused && pass < 2);
    dp = &c->dir;
    func_00110630(c);
    c->dir.w = 0.0f;
    c->count = 0;
    func_0010eed8(c, 0, 0);
    {
        V10ff08 d = *dp;
        func_0016b010(c, &d);
    }
    return;
found:
    (c->who->*pick->e->pick)(pick->e, &pick->t, &pick->score, 0);
    u32 f = pick->e->flags & 1;
    if (f == 0) {
        func_0010ef28(c, pick->e);
        c->count++;
    } else {
        c->count = 0;
    }
    func_0010eed8(c, pick->e, pick->score);
}
}
