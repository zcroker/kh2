#include "../common/types.h"

// Built with -fno-strict-aliasing (needed for the original store/load order).

struct W1804C1 { u8 pad[0x1c]; s32 flags; };
struct W1804C2 { u8 pad[0x484]; W1804C1* p; };
struct W1804C3 { u8 pad[4]; W1804C2* p; };
struct W1804Desc { u16 m0, m2, m4; union { u16 m6; u8 b6; struct { u8 b0:1; } bf; }; u16 m8; u8 pad[0x16-0xa]; u16 m16; };
struct W1804Obj { u8 pad[0x88]; W1804C3* m88; u8 pad2[4]; W1804Desc* m90; s32 m94; s32 m98; s32 m9c; };
struct W1804Loc { W1804C3* p; u32 pad[3]; };

struct W1804CntS { u32 a; u32 b; u32 arr[19]; };
struct W1804CntP { u8 pad[0x2444]; W1804CntS s; };

extern "C" {
void func_00187b90(W1804Obj*);
s32 func_0016cf00(W1804C1*, s32, s32, W1804Loc*, s32);
void func_00188398(W1804Obj*, s32, W1804Loc*, s32);
W1804CntP* func_001058e8(void);
extern s32 D_0032b984;
extern u8 D_0032bae0;

void func_00187fd8(W1804Obj* o, W1804Desc* d)
{
    if (!(o->m88->p->p->flags & 2)) {
    func_00187b90(o);
    W1804Loc l;
    l.p = o->m88; o->m94 = func_0016cf00(l.p->p->p, 0, d->m8, &l, 1);
    o->m90 = d;
    o->m98 = d->m4;
    o->m9c = 0;
    if (d->m6 & 2) o->m9c = 1;
    if (!(d->b6 & 1)) o->m9c |= 4;
    o->m9c |= 2;
    func_00188398(o, d->m16, &l, 1);
    }
}

// Saturating counters (limit 0xCDFE5C3) kept in volatile locals.
void func_0014ccb8(void)
{
    W1804CntP* q = func_001058e8();
    volatile u32 a = q->s.a;
    volatile u32 b = q->s.b;
    if (a <= 0xCDFE5C3) a++;
    q->s.a = a;
    q->s.b = b;
    if (D_0032b984) {
        volatile s32 i = D_0032bae0;
        if (i >= 0 && i < 19) {
            W1804CntS* s = &q->s;
            volatile u32 c = s->arr[i];
            if (c <= 0xCDFE5C3) c++;
            s->arr[i] = c;
        }
    }
}
}
