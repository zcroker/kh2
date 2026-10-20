#include "../common/types.h"

struct W1786Flags { u8 pad[0xc]; s32 fl;
  u8 bd(s32 n) { return fl >> n; } };
struct W1786Tg;
struct W1786Ob2 { u8 pad[0x7f8]; u32 f7f8; };
struct W1786Ob { u8 pad[0x108]; u32 f108; u8 pad2[0xaec - 0x10c]; W1786Ob2* faec; };
struct W1786V4 { f32 x, y, z, w;
  W1786V4& operator=(const W1786V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1786VC { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(void*); };

extern "C" {
s32 func_0019c090(s32);
s32 W1786_IsBattleMode() asm("_ZN2YS6STATUS12IsBattleModeEv");
extern s32 D_0034f240;
s32 func_001b8ff8(W1786Flags* o, s32 a1) {
    s32 r = 0;
    if (((o->bd(1) & 1) && func_0019c090(a1)) || ((o->bd(16) & 1) && !W1786_IsBattleMode()) || ((o->bd(5) & 1) == 0 && (D_0034f240 & 2))) r = 1;
    return r;
}

W1786Ob2* func_001cd7a8(void*);
s32 func_0016a090(W1786Ob*);
s32 W1786_ctarget(W1786Ob2*) asm("_Z16ctarget_0019ba60jjjj");
void W1786_set_obj(W1786Tg*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
extern u8 D_01c60d10;
extern W1786Ob2* D_0034e948;
void func_00190a80(W1786Tg* t, W1786Ob* o) {
    W1786Ob2* r = 0;
    u32 fl = o->f108;
    u32 m2 = fl & 0x800;
    u32 m1 = fl & 0x1000;
    if (!m2 && !m1) r = func_001cd7a8(&D_01c60d10);
    if (!r) {
        if (func_0016a090(o) != 1 && o->faec && W1786_ctarget(o->faec) && !(o->faec->f7f8 & 4))
            r = o->faec;
        else
            r = D_0034e948;
    }
    W1786_set_obj(t, r, 0);
}

W1786V4 func_0017c870(f32, f32);
s32 func_001b2d10(void*, W1786V4*);
W1786V4 func_001b2c48(W1786VC* c, void* x) {
    W1786V4 d;
    W1786V4 r;
    r = func_0017c870(0.9f, 0.95f);
    if (r.y > 0.0f && func_001b2d10(x, &r)) c->f5(x);
    return r;
}
}
