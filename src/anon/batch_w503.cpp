#include "../common/types.h"
extern "C" {
// 00104d30: copy the 3 ids, look up the cell's 3 defaults in the table, then apply overrides
struct Cell104d30 { u8 pad[16]; u16 x, y, z; };
extern u8 D_0032bb30[];
struct Ent104d30 { u8 a, b, c, pad; u16 v[3]; };
void func_00104cf0(u16* d, u16* s);
void func_00104d30(Ent104d30* d, Ent104d30* s)
{
    d->a = s->a;
    d->c = s->c;
    d->b = s->b;
    Cell104d30* t = (Cell104d30*)(D_0032bb30 + d->a * 384 + d->b * 6);
    u16 x = t->x, y = t->y, z = t->z;
    d->v[0] = x;
    d->v[1] = y;
    d->v[2] = z;
    func_00104cf0(d->v, s->v);
}
}
