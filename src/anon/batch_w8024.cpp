#include "../common/types.h"

extern "C" {
s32 func_001050c8(void);
void* func_001063f0(u32, s32);
void func_002cf268(void*, s32);
}
struct SubQ_w8024 { s32 x; SubQ_w8024() { func_002cf268(this, 0); } };
struct ElemQ_w8024 { s32 a; SubQ_w8024 b; s32 c[8]; ElemQ_w8024() : a(0) { c[0]=0; c[1]=0; c[2]=0; c[3]=0; c[4]=0; c[5]=0; c[6]=0; c[7]=0; } };
inline void* operator new[](unsigned int sz, s32 h) { return func_001063f0(sz, h); }

struct V4_w8024 { f32 x, y, z, w; V4_w8024(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {} };

struct R2e_w8024 { s32 i0; u8 pad[4]; u8 b8; };
struct P2d_w8024 { u8 pad[0x20]; f32 f20; f32 f24; };
struct O2d_w8024 {
    u8 pad0[0x6c]; s32 m6c; s32 m70; s32 m74; u8 p78[0x84-0x78]; s32 a84[3];
    u8 p90[0xa4-0x90]; s32 ma4; s32 ma8; f32 fac; f32 fb0; s8 bb4; u8 pb5[3]; R2e_w8024* rb8; u8 bc[0x1d0-0xbc];
    s8 b1d0; u8 p1d1[0x1e0-0x1d1]; s8 b1e0;
};

extern "C" {
extern s32 D_00361fa0;
extern ElemQ_w8024* D_00361fa4;
extern s32 D_00361fa8;

void func_0016ace0(s32, V4_w8024*);
void func_0016b070(s32, V4_w8024*);
void func_0016bd60(s32, s32);
s32 func_001c0d38(s32, s32, s32, s32);
void func_002d00a0(s32);
s32 func_002d1260();

R2e_w8024* func_002e34d8(void*);
void func_002d0a78();
void func_001a58f8();
void func_002d7420(O2d_w8024*);
void func_002da040(s32);
void func_002cf2d8();
void func_002cf938(s32);
s32 func_002cf308(s32);
void func_002d9220(O2d_w8024*, s32);
P2d_w8024* func_002d73f0(O2d_w8024*);
void func_001ca8f8(f32, f32);

void func_002cf320(s32 n)
{
    D_00361fa0 = n;
    D_00361fa8 = 0;
    D_00361fa4 = 0;
    if (n > 0) D_00361fa4 = new (func_001050c8()) ElemQ_w8024[n];
    else D_00361fa4 = 0;
}

void func_002d6a00(s32 a0)
{
    func_002d00a0(a0);
    func_0016bd60(a0, 3);
    func_001c0d38(a0, func_002d1260(), 0x55, 0);
    V4_w8024 r(-1.57079625f, -1.57079625f, 0.0f, 0.0f);
    func_0016b070(a0, &r);
    V4_w8024 t(0.0f, 0.0f, 0.0f, 0.0f);
    func_0016ace0(a0, &t);
}

void func_002d74c8(O2d_w8024* o, s32 a1, u8 a2)
{
    R2e_w8024* r;
    s32 i;
    o->bb4 = 0;
    o->ma8 = a1;
    o->b1e0 = 0;
    r = func_002e34d8(o->bc);
    o->rb8 = r;
    o->ma4 = r->b8;
    o->fac = (f32)r->i0;
    if (a2) {
        func_002d0a78();
        func_001a58f8();
    }
    func_002d7420(o);
    a1 = func_002d1260();
    func_002da040(a1);
    func_002cf2d8();
    func_002cf938(1);
    o->m6c += func_002cf308(0);
    o->m70 += func_002cf308(1);
    o->m74 += func_002cf308(2);
    for (i = 0; i < 3; i++) o->a84[i] = 0;
    o->b1d0 = 1;
    if (o->ma4 == 5) func_002d9220(o, 0);
    else if (o->ma4 == 6) func_002d9220(o, 1);
    o->fb0 = o->fac - 1.0f;
    P2d_w8024* p = func_002d73f0(o);
    func_001ca8f8(p->f24, func_002d73f0(o)->f20);
}
}
