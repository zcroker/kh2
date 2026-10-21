#include "../common/types.h"

extern "C" {
struct VtM { u8 p[8]; s32 (*get)(void*); };
struct M6 { VtM* vt; };
struct R6 { u8 p[8]; M6* m; };
struct Q6 { u8 p[8]; s32 v; };
struct C6 { u8 p[0x10c]; u32 f10c; };
struct O6 {
    u8 p0[8];
    C6* p8;       // 8
    M6* fc;       // c
    s32 f10;      // 10
    s32 f14, f18; // 14, 18
    u8 p1c[4];
    u32 f20;      // 20
    u32 f24;      // 24
    u8 p28[4];
    f32 f2c;      // 2c
    f32 f30;      // 30
    s32 f34;      // 34
    u8 p38[0x104 - 0x38];
    u32 f104;     // 104
    u8 p108[0x148 - 0x108];
    s32* ref;     // 148
    u8 p14c[0x194 - 0x14c];
    s32 f194;     // 194
};
s32 func_0019c6f0(C6*);
void func_001d7a50(void*);
void func_00180ce0(O6*);
void func_00189258(O6*);
R6* func_00168b38(void*, s32, s32);
void func_00180800(O6*, s32);
void func_001807d0(O6*, f32);
void func_0017eee8(O6*, f32, f32);
void func_0017f938(O6*);
void func_001807a0(O6*, f32, f32);

s32 func_0017efa0(O6* o, void* r, f32 a, f32 b) {
    if (func_0019c6f0(o->p8)) func_001d7a50((u8*)o->p8 + 0x518);
    if (o->ref) {
        (*o->ref)--;
        o->ref = 0;
    }
    func_00180ce0(o);
    func_00189258(o);
    if (!r) {
        o->fc = 0;
        return 0;
    }
    R6* s = func_00168b38(r, 9, 0);
    o->f14 = -1;
    o->f18 = -1;
    func_00180800(o, -1);
    o->p8->f10c &= ~1;
    o->fc = s->m;
    o->f2c = (f32)o->fc->vt->get(o->fc);
    s = func_00168b38(r, 16, 0);
    o->f10 = ((Q6*)s)->v;
    u32 m = o->f20 & 0x80;
    s32 had = m != 0;
    o->f20 = 1;
    o->f194 = 0;
    u32 f = o->f24;
    o->f24 = 0;
    if (f & 4) o->f20 = 0x4001;
    func_001807d0(o, b);
    if (2.0f < a && (o->f104 & 1) == 1) {
        func_0017eee8(o, a, b);
    } else {
        o->f30 = b;
        o->f34 = 0;
        func_001807a0(o, b, -1.0f);
    }
    o->f20 |= 0x2000;
    if (had) func_0017f938(o);
    return 1;
}
}
