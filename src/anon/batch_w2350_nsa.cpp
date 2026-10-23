#include "../common/types.h"
// Needs -fno-strict-aliasing: the s32 stores into the new data block reload p's s16 fields.

struct Obj_f;
struct VT_f { void* pad[8]; void (*f20)(Obj_f*, s32); };
struct Obj_f { VT_f* vt; };
struct Data_f { s32 type; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; Obj_f* f2c; s32 f30; s32 f34; u8 b38; u8 pad39[3]; s32 f3c; };
struct Task_f { u8 pad0[4]; Data_f* data; u8 pad8[0x30 - 8]; void (*f30)(Task_f*); };
struct Arg_f { u8 pad0[4]; s16 f4; s16 type; s16 f8; s16 fa; s16 fc; s16 fe; s16 f10; s16 f12; s16 f14; };

extern "C" {
Task_f* CreateTask_f(s32, s32, void (*)(Task_f*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* Alloc_f(u32) asm("_ZN4AREA5AllocEj");
Obj_f* ComboStart_f(s32) asm("_ZN2sa13MUSICAL_COMBO5startEi");
s32 func_002282f0(s32);
s32 func_002282d8(void);
s32 func_002247d8(void);
void func_00224f38(s32, Task_f**, Obj_f**, s32);
void func_00224f08(Task_f*);
void func_00229e58(Task_f*);

// Spawns a task for a grid cell: picks the task kind from p->type, then fills its data block
// with cell offsets (centre, up, left/right neighbours) relative to p->f4.
void func_00224fa0(Arg_f* p)
{
    if (func_002282f0(p->f4) != 0)
        return;
    s32 id = func_002282d8() + 1;
    s32 w = func_002247d8();
    Task_f* t = 0;
    Obj_f* b = 0;
    switch (p->type) {
    case 2: func_00224f38(id, &t, &b, 0); break;
    case 0: func_00224f38(id, &t, &b, 2); break;
    case 1: func_00224f38(id, &t, &b, 3); break;
    case 3: func_00224f38(id, &t, &b, 4); break;
    case 5: func_00224f38(id, &t, &b, 1); break;
    case 6: {
        t = CreateTask_f(1, id, func_00229e58);
        t->f30 = func_00224f08;
        s32 small = p->f8 < 4;
        b = ComboStart_f(small == 0);
        break;
    }
    }
    s32 x = p->f4 + p->fa;
    s32 c = p->fc;
    s32 m = x + p->f8 * w;
    s32 a = m - w;
    s32 e = m - c - 1;
    s32 f = m + c;
    Data_f* d = (Data_f*)Alloc_f(0x40);
    t->data = d;
    d->type = p->type;
    d->f4 = p->f8;
    d->f1c = 0;
    d->f20 = 0;
    d->f8 = x - p->f4;
    d->fc = a - p->f4;
    d->f10 = e - p->f4;
    d->f14 = m - p->f4;
    d->f18 = f - p->f4;
    d->f24 = p->f12;
    d->f28 = p->f14;
    d->f2c = b;
    d->f34 = p->f10;
    d->b38 = 0;
    d->f3c = 0;
    if (p->type == 1)
        d->f30 = -p->fe;
    else
        d->f30 = p->fe;
    b->vt->f20(b, d->f4);
}
}
