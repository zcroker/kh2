#include "../common/types.h"
struct W324C4 { u8 r, g, b, a; };
struct W324Sub { u8 pad[4]; u8 kind; u8 id; };
struct W324Obj {
    u8 p0[0x108]; u32 b0:1; u32 b1:1; u32 b2:3; u32 b5:1; u32 b6:1; u32 brest:25;
    u8 p1[0x140 - 0x10c]; u8 mot[0x3ac - 0x140]; W324C4 col;
    u8 p2[0xae4 - 0x3b0]; W324C4 cur;
    u8 p3[0xaf8 - 0xae8]; W324Sub* sub; void* afc; void* b00; u8 p4[4]; u8 eff[4];
};
extern "C" {
extern u32 D_00375480[];
void func_002c2228(u8);  // to_15ee90_if_nonzero
void func_002c2248(u8);  // to_15ee10_if_nonzero
void func_0017f540(void*, s32, f32, f32);
void* func_0016abf8(W324Obj*, s32, s32, s32);
void* func_0016ac38(W324Obj*, s32, s32, s32, s32);
void func_001dc920(void*);
void func_002f1990(void*);
s32 func_00181500(s32);
void func_002f1900(void*, s32, W324Obj*);
static inline bool cf(W324C4* p) { if (p->r < 2) return false; u32 m = p->a & 2; u32 r = m == 0; return r; }
static inline bool big(W324C4* p) { return p->r >= 3; }
void func_002bf650(W324Obj* o, W324C4* p) {
    s32 m = 151;
    if (p->r != 0) {
        if (p->r != 1) {
            o->b1 = 0; o->b5 = 0;
            func_002c2228(o->sub->id);  // to_15ee90_if_nonzero
        } else {
            o->b1 = 0; o->b5 = 1;
            m = 161;
            func_002c2248(o->sub->id);  // to_15ee10_if_nonzero
        }
    } else {
        o->b1 = 1; o->b5 = 1;
        m = 161;
        func_002c2248(o->sub->id);  // to_15ee10_if_nonzero
    }
    func_0017f540(o->mot, m, 0.0f, 0.0f);
    if (cf(p)) o->b6 = 0;
    else o->b6 = 1;
    if (p->a & 1) {
        if (o->afc == 0) o->afc = func_0016abf8(o, 3, 1, 0);
    } else if (o->afc) {
        func_001dc920(o->afc);
        o->afc = 0;
    }
    if (big(p)) {
        if (o->b00 == 0) o->b00 = func_0016ac38(o, 5, 1, 0, 0);
    } else if (o->b00) {
        func_001dc920(o->b00);
        o->b00 = 0;
    }
    u32 cv = D_00375480[p->r];
    W324C4* d = &o->col; d->r = cv; d->g = cv >> 8; d->b = cv >> 16; d->a = cv >> 24;
    if (o->sub->kind == 18) {
        if (p->r < 2) func_002f1990(o->eff);
        else if (func_00181500(0x481c)) func_002f1900(o->eff, 8, o);
        else func_002f1900(o->eff, 6, o);
    }
    o->cur = *p;
}
}
