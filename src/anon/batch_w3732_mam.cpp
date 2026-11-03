// 002823b0: fills the entry table (id/a/b/c per slot) from five item lists; list 0 picks the k-th set bit of a mask.
// Built with -fmove-all-movables (_mam). Partial asm: one empty asm("" : "+r"(a)) (no code) adds refs to 'a' so
// global alloc gives it s0 before the items+2j giv (otherwise s0/s2 swap). 'total' read through a union so its
// store keeps the original's dependence on the stack spills (the original looks like -fno-strict-aliasing here).
#include "../common/types.h"
struct Ent2823 { u16 id; u8 a; u8 b; s16 c; };
struct Obj2823 { u8 pad[580]; u16* items; };
union Tot2823 { s32 i; u8 c; };
struct Self2823 { Tot2823 total; Ent2823 ent[682]; u8 pad[4]; s32 f1004; s32 f1008; s32 f100c; s32 cnt[5]; };
extern "C" {
s32 func_002811f8(s32, s32);
Obj2823* func_00281180(s32, s32);
s32 func_002826f8(Self2823*, s32, s32);
s32 func_00281480(s32, s32);
s32 func_002813b8(void);
s32 func_00281420(void);
u16 func_002814b0(s32);
void func_002823b0(Self2823* self, s32 b, s32 r) {
    u16* items;
    s32 total;
    s32 mask;
    s32 i, j, n;
    Ent2823* e = self->ent;
    self->f1008 = 1;
    self->f100c = func_002811f8(self->f1004, b - 5);
    items = func_00281180(self->f1004, self->f100c)->items;
    for (i = 0; i < 5; i++) {
        self->cnt[i] = func_002826f8(self, self->f100c, i);
    }
    mask = 0;
    if (func_00281480(self->f1004, self->f100c)) {
        s32 m = func_002813b8();
        mask = m & func_00281420();
    }
    self->total.i = 0;
    total = 0;
    for (i = 0; i < 5; i++) {
        if (i == 1) continue;
        n = self->cnt[i];
        if (i == 0) n += self->cnt[1];
        for (j = 0; j < n; j++) {
            u16 id = 0;
            s32 eq = 0;
            u8 a = 1;
            switch (i) {
            case 0:
                id = items[0];
                if (j != 0) {
                    s32 c = 0;
                    s32 k;
                    for (k = 0; k < 7; k++) {
                        bool on = (mask >> k) & 1;
                        if ((u8)on) {
                            if (c + 1 == j) {
                                id = func_002814b0(k);
                                break;
                            }
                            c++;
                        }
                    }
                }
                break;
            case 4:
                id = items[j + 26];
                if (id == 0) {
                    u16 t = items[j + 34];
                    if (t != 0) {
                        id = t;
                        a = 0;
                    }
                }
                eq = items[j + 34] == id;
                break;
            case 3:
                id = items[j + 18];
                break;
            case 2:
                id = items[j + 10];
                break;
            }
            if (!id) a = 0;
            asm("" : "+r"(a));
            e->id = id;
            e->b = eq != 0;
            e->a = a;
            e->c = 999;
            e++;
        }
        total += n;
    }
    self->total.i = total;
}
}
