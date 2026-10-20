#include "../common/types.h"
extern "C" {
struct Bx;
struct BxVt { void* f[5]; void (*get)(Bx*, f32*, f32*); };
struct Bx { BxVt* vt; };
struct Ob {
    u8 pad0[0xc];
    Bx* box;
    u8 pad10[0x20];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0xd8 - 0x3c];
    f32 mn[3];
    f32 mx[3];
};
void func_0017eee8(Ob* o, f32 a, f32 b) {
    f32 lo[4];
    f32 hi[4];
    f32* ph = hi;
    s32 i;
    o->f34 = a;
    o->f38 = b;
    o->f30 = 2.0f;
    o->box->vt->get(o->box, lo, ph);
    f32* mn = o->mn; f32* mx = o->mx;
    for (i = 0; i < 3; i++) { s32 k = i * 4; if (*(f32*)((u8*)mn + k) > *(f32*)((u8*)lo + k)) *(f32*)((u8*)mn + k) = *(f32*)((u8*)lo + k);
      if (*(f32*)((u8*)ph + k) > *(f32*)((u8*)mx + k)) *(f32*)((u8*)mx + k) = *(f32*)((u8*)ph + k); }
}
}
