#include "../common/types.h"

struct Q1615 { u8 v[16] __attribute__((aligned(16))); Q1615() {} ~Q1615() {} };
struct B1615 { u64 a, b, c, d; Q1615 q[2]; f32 f; B1615() {} };

extern "C" {
struct P1615 { u64 a, b, c, d; };
struct G1615 {
    u8 p0[28];
    s16 y[2];
    s16 x[2];
    s16 ny;
    s16 nx;
    u8 p28[52 - 40];
    u32 p0b : 10;
    u32 moved : 1;
    u32 sel : 1;
    u32 p1b : 2;
    u32 mode : 4;
};
union GU1615 { G1615* p; s16 h; };
extern GU1615 D_0035f638;
void* func_00167f18(s32);
void func_00323af8(B1615*, void*);
s32 func_00288040(void);
P1615* func_00288008(void);
u32* func_002b23e0(s32);

s32 func_002b0950(void)
{
    B1615 b;
    s32 r = 0;
    func_00323af8(&b, func_00167f18(0));
    u32* fp = func_002b23e0(-1);
    if (func_00288040()) {
        b.a |= func_00288008()->a;
        b.b |= func_00288008()->b;
        b.c |= func_00288008()->c;
        b.d |= func_00288008()->d;
    }
    u32 f = *fp;
    s16 y = D_0035f638.p->y[D_0035f638.p->sel];
    s16 x = D_0035f638.p->x[D_0035f638.p->sel];
    if (!(f & 0x4000000) && ((b.d & 0x10) || (b.b & 0x10))) {
        if (x != 0) x = x - 1;
        else if (b.b & 0x10) x = D_0035f638.p->nx - 1;
        if (D_0035f638.p->x[D_0035f638.p->sel] != x) r = 16;
    } else if (!(f & 0x4000000) && ((b.d & 0x20) || (b.b & 0x20))) {
        if (x < D_0035f638.p->nx - 1) x = x + 1;
        else if (b.b & 0x20) x = 0;
        if (D_0035f638.p->x[D_0035f638.p->sel] != x) r |= 32;
    }
    if (!(f & 0x4000000) && ((b.d & 0x40) || (b.b & 0x40))) {
        if (y != 0) y = y - 1;
        else if (b.b & 0x40) y = D_0035f638.p->ny - 1;
        if (D_0035f638.p->y[D_0035f638.p->sel] != y) r |= 0x40;
    } else if (!(f & 0x4000000) && ((b.d & 0x80) || (b.b & 0x80))) {
        if (y < D_0035f638.p->ny - 1) y = y + 1;
        else if (b.b & 0x80) y = 0;
        if (D_0035f638.p->y[D_0035f638.p->sel] != y) r |= 0x80;
    }
    if (r) {
        D_0035f638.p->y[D_0035f638.p->sel] = y;
        D_0035f638.p->x[D_0035f638.p->sel] = x;
        D_0035f638.p->moved = 1;
        return r;
    }
    if (!(f & 0x4000000) && (b.b & 4)) r = 4;
    else if (b.b & 8) r = 8;
    else if (b.b & 0x100) r = 0x100;
    else if (b.b & 0x2000) r = 0x2000;
    else if ((b.b & 0x10000) && D_0035f638.p->mode >= 2) r = 0x10000;
    else if ((b.b & 0x20000) && D_0035f638.p->mode >= 2) r = 0x20000;
    else if (!(f & 0x4000000) && (b.b & 0x40000) && (f & 0x10000000)) r = 0x40000;
    else if (!(f & 0x4000000) && (b.b & 0x80000) && (f & 0x10000000)) r = 0x80000;
    return r;
}
}
