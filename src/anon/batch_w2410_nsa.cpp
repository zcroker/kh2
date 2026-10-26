#include "../common/types.h"
extern "C" {
struct Sub28d { u8 p0[0x148]; s32 x; s32 y; };
struct Obj28d {
    u8 p0[0xc]; u32 flags; u8 p10[8];
    Sub28d sub;
    u8 p168[0x170 - 0x168];
    s32 x; s32 y; s32 ox; s32 oy;
    u8 p180[0x18c - 0x180];
    Obj28d* parent; Sub28d* other;
    u8 p194[0x19c - 0x194];
    u8 started; u8 trig; u8 p19e[2];
    f32 t; s32 sx; s32 sy; s32 dx; s32 dy; s32 lx; s32 ly;
};
extern f32 D_00374448[];
s32 func_00139d78(Obj28d*);
s32 func_00239d20(Sub28d*);
void func_00138cd0(Obj28d*, s32*, s32*);
void func_00138c50(Obj28d*, s32*, s32*);
s32 func_0023aa18(Sub28d*);
s32 func_0023aa38(Sub28d*);
void func_0023a9c0(Sub28d*, s32*, s32*);
double func_00313b80(f32);
s32 func_003142e0(double, double);
f32 func_0028f1e0(f32*, f32*, f32);
void func_0023ade0(Sub28d*);
void func_0028d320(Obj28d* o)
{
    s32 dx, dy;
    if (o->flags & 0x800) {
        if (o->parent && !func_00139d78(o->parent)) return;
        if (o->other && !func_00239d20(o->other)) return;
    }
    if (o->parent) {
        func_00138cd0(o->parent, &dx, &dy);
        func_00138c50(o->parent, &o->x, &o->y);
        o->x += dx;
        o->y += dy;
        o->x += func_0023aa18(&o->parent->sub);
        o->y += func_0023aa38(&o->parent->sub);
    } else if (o->other) {
        func_0023a9c0(o->other, &dx, &dy);
        {
        Sub28d* ot = o->other;
        s32 nx = dx + ot->x;
        s32 ny = dy + ot->y;
        o->y = ny;
        o->x = nx;
        }
        o->x += func_0023aa18(o->other);
        o->y += func_0023aa38(o->other);
    }
    if (o->trig) {
        if (!o->started) {
            s32 x = o->x;
            s32 y = o->y;
            o->sx = x;
            o->sy = y;
            o->dx = x;
            o->dy = y;
            o->t = 30.0f;
            o->started = 1;
        } else {
            o->sx = o->lx;
            o->sy = o->ly;
            o->dx = o->x;
            o->dy = o->y;
            o->t = 0.0f;
        }
        o->trig = 0;
    }
    if (o->parent || o->other) {
        o->dx = o->x;
        o->dy = o->y;
    }
    {
        f32 t = o->t;
        f32 dur = 30.0f;
        if (func_003142e0(0.0, func_00313b80(dur - t)) <= 0) {
            f32 ex = o->dx - o->sx;
            f32 ey = o->dy - o->sy;
            f32 f = func_0028f1e0(D_00374448, D_00374448 + 4, t / dur);
            o->x = o->sx + (s32)(ex * f);
            o->y = o->sy + (s32)(ey * f);
        }
    }
    {
    Sub28d* s = &o->sub;
    s32 x = o->x, y = o->y;
    s32 b = y + o->oy, a = x + o->ox;
    o->ly = y;
    o->lx = x;
    s->x = a;
    s->y = b;

    func_0023ade0(s);
    }
}
}
