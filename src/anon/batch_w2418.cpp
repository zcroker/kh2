#include "../common/types.h"
extern "C" {
struct W2418M2b4 { u8 pad[0x4c]; };
struct W2418O2b4 { W2418M2b4* a; W2418M2b4* b; W2418M2b4* c; };
struct W2418P2b4 { u8 pad[0x14]; u16 h[4]; };
void func_0023f1e0(W2418M2b4*, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023f7d8(W2418M2b4*);
s32 func_0023aa98(s32);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_0023f6c0(W2418M2b4*, s32);
void func_0023f688(W2418M2b4*, s32);
void func_001395f8(W2418M2b4*);

void func_002b4070(W2418O2b4* o, s32 a1, s32 a2, s32 a3, s32 e0, s32 e1, s32 e2, s32 e3, s32 e4, s32 c0, W2418P2b4* p, s32 x, s32 y) {
    s32 v;
    if (e0) {
        func_0023f1e0(o->a, a1, a2, a3, e0, c0, x, y);
        v = func_0023aa98(func_0023f7d8(o->a));
        func_0023f6c0(o->a, func_0028dd90(v));
        func_0023f688(o->a, func_0028ddd8(v));
        func_001395f8(o->a);
    }
    if (e1) {
        func_0023f1e0(o->b, a1, a2, a3, e1, p->h[0], x, y);
        v = func_0023aa98(func_0023f7d8(o->b));
        func_0023f6c0(o->b, func_0028dd90(v));
        func_0023f688(o->b, func_0028ddd8(v));
        func_001395f8(o->b);
    }
    if (e2) {
        func_0023f1e0(&o->b[1], a1, a2, a3, e2, p->h[1], x, y);
        v = func_0023aa98(func_0023f7d8(&o->b[1]));
        func_0023f6c0(&o->b[1], func_0028dd90(v));
        func_0023f688(&o->b[1], func_0028ddd8(v));
        func_001395f8(&o->b[1]);
    }
    if (e3) {
        func_0023f1e0(&o->b[2], a1, a2, a3, e3, p->h[2], x, y);
        v = func_0023aa98(func_0023f7d8(&o->b[2]));
        func_0023f6c0(&o->b[2], func_0028dd90(v));
        func_0023f688(&o->b[2], func_0028ddd8(v));
        func_001395f8(&o->b[2]);
    }
    if (__builtin_expect(e4, 1)) {
        func_0023f1e0(o->c, a1, a2, a3, e4, p->h[3], x, y);
        v = func_0023aa98(func_0023f7d8(o->c));
        func_0023f6c0(o->c, func_0028dd90(v));
        func_0023f688(o->c, func_0028ddd8(v));
        func_001395f8(o->c);
    }
}
}
