#include "../common/types.h"

struct W1717Q { u8 v[16] __attribute__((aligned(16))); W1717Q() {} ~W1717Q() {} };
struct W1717Pad { u64 a, b, c, d; W1717Q q[2]; f32 f; W1717Pad() {} };

extern "C" {
struct W1717Obj {
    u8 p0[2]; s16 m2; s16 m4; u8 p6[0xc]; u16 m12; u16 m14; s16 m16;
    u8 p18[0xd]; u8 f25; u8 p26; u8 f27;
};

s16 func_0028b040(W1717Obj*);
void* func_00167f18(s32);
void func_00323af8(W1717Pad*, void*);
s32 func_00288040(void);
W1717Pad* func_00288008(void);
s32 func_002899e0(W1717Obj*, W1717Pad*);
s32 func_00289ef8(W1717Obj*, W1717Pad*);
s32 func_0028af78(W1717Obj*, s32);

s16 func_00289380(W1717Obj* o) {
    W1717Pad pad;
    s32 r;
    o->m2 = func_0028b040(o);
    o->m14 = o->m12;
    func_00323af8(&pad, func_00167f18(0));
    if (func_00288040()) {
        pad.a |= func_00288008()->a;
        pad.b |= func_00288008()->b;
        pad.c |= func_00288008()->c;
        pad.d |= func_00288008()->d;
    }
    r = 0;
    if (o->m16 != 0 && o->m4 != 0) {
        if (o->f25 != 0) r = func_00289ef8(o, &pad);
        else r = func_002899e0(o, &pad);
    }
    if (r) return -1;
    if (o->f25 == 0 && (pad.b & 0x40) && func_0028af78(o, 4)) return -12;
    if (o->f25 == 0 && (pad.b & 0x80) && func_0028af78(o, 8)) return -13;
    if (o->f25 == 0 && (pad.d & 0x40) && func_0028af78(o, 0x40000)) return -12;
    if (o->f25 == 0 && (pad.d & 0x80) && func_0028af78(o, 0x80000)) return -13;
    if (o->f25 == 0 && (pad.a & 0x40) && func_0028af78(o, 0x10000)) return -12;
    if (o->f25 == 0 && (pad.a & 0x80) && func_0028af78(o, 0x20000)) return -13;
    if ((pad.b & 4) && func_0028af78(o, 0x10)) return func_0028b040(o);
    if ((pad.b & 8) && func_0028af78(o, 0x20)) return -2;
    if ((pad.b & 0x100) && func_0028af78(o, 0x40)) return -4;
    if ((pad.b & 0x800) && func_0028af78(o, 0x100)) return -5;
    if ((pad.b & 0x1000) && func_0028af78(o, 0x200)) return -6;
    if ((pad.b & 0x2000) && func_0028af78(o, 0x400)) return -7;
    if ((pad.b & 0x4000) && func_0028af78(o, 0x1000) && o->f27 == 0) return -8;
    if ((pad.b & 0x8000) && func_0028af78(o, 0x2000) && o->f27 == 0) return -9;
    if ((pad.b & 0x10000) && func_0028af78(o, 0x4000)) return -10;
    if ((pad.b & 0x20000) && func_0028af78(o, 0x8000)) return -11;
    return -1;
}
}
