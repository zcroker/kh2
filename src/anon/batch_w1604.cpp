#include "../common/types.h"
extern "C" {
struct E36 { u8 b[36]; };
extern s32 D_0035ed4c;
extern s32 D_0035ed50;
extern s32 D_0035ed60;
extern E36 D_00371d90[];
extern s16 D_00371d18[];
s32 func_00287cd0(void);
s32 func_00289380(s32);
s32 func_0028acc8(s32);
s32 func_00289310(s32);
void func_0028abe0(s32);
s32 func_002891e8(s32);
void func_002b4388(s32, E36*, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28(s32, s32);
void func_0028ab20(s32);
void func_00287c90(s32);
void func_00287df0(s32, s32, s32, s32, s32);
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0(void);
void func_00248b38(void)
{
    s32 mode = func_00287cd0();
    s32 r = func_00289380(D_0035ed50);
    if (mode == 2) {
        if (func_0028acc8(D_0035ed50)) {
            if (r != -1 || func_00289310(D_0035ed50)) func_0028abe0(D_0035ed50);
        } else {
            func_002b4388(D_0035ed60, &D_00371d90[func_002891e8(D_0035ed4c)], 0);
            func_00287bd0(0, 0);
            func_00287cc0(1);
        }
    } else {
        if ((r != -1 || func_00289310(D_0035ed50)) && !func_0028ae28(D_0035ed50, 0))
            func_0028ab20(D_0035ed50);
        if (mode == 0 && func_0028ae28(D_0035ed50, 0)) func_00287c90(1);
        func_00287df0(r, func_00289310(D_0035ed50), 0, 0, 1);
        switch (r) {
        case -4:
        case -3:
        case -1:
            break;
        case -2:
        case 1:
            func_0028aa40(D_0035ed50);
            func_00287c90(1);
            break;
        case 0:
            func_00287b08(D_00371d18[func_002891e8(D_0035ed4c)]);
            func_00287da0();
            break;
        }
    }
}
extern s32 D_0035f654;
s32 func_0028db48(s32);
s32 func_00287cd0(void);
void func_00287cc0(s32);
s32 func_00240ba0(void);
u32 func_00287d30(void);
s32 func_00233e70(s32);
void func_002419d0(s32);
s32 func_00234888(s32, s32);
s32 func_002348a8(s32, s32);
s32 func_00234848(s32, s32);
s32 func_00234868(s32, s32);
void func_002b5108(s32, s32);
void func_00287d20(s32);
void func_00240bb0(s32);
void func_00287bd0(s32, s32);
void func_00241450(s32);
void func_002b4c88(s32);
void func_00234570(s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_0025a468(void)
{
    if (!func_0028db48(D_0035f654)) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    s32 h = func_00240ba0();
    switch (func_00287d30()) {
    case 0:
        if (func_00233e70(0) == 0) {
            s32 m;
            s32 r;
            func_002419d0(0);
            r = func_00234888(h, 0);
            switch (func_002348a8(h, 0)) {
            case 3:
                goto bad;
            case 4:
                func_002b5108(0x8aae, h);
                r = -1;
                m = 6;
                break;
            default:
                if (func_00234848(h, 0) != 2) {
                bad:
                    func_002b5108(0xb85d, h);
                    r = -1;
                    m = 2;
                } else if (!func_00234868(h, 0)) {
                    func_002419d0(1);
                    m = 5;
                } else {
                    func_002b5108(0x8a89, h);
                    m = 1;
                }
                break;
            }
            func_00287d20(m);
            func_00240bb0(r);
        }
        break;
    case 1:
        func_00287bd0(4, 0);
        func_00287d20(10);
        func_00241450(1);
        break;
    case 2:
        func_002b4c88(0);
        func_00287bd0(5, 0);
        func_00234570(h, 0);
        break;
    case 3:
        func_002b4c88(1);
        func_00287bd0(8, 0);
        func_00234570(h, 0);
        break;
    case 5:
        func_00287bd0(11, 0);
        break;
    case 6:
        func_002b4c88(0);
        func_00287bd0(7, 0);
        func_00234570(h, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}
struct Ent { u8 p0[276]; s32 f114; u8 p118[68]; s32 f15c; u8 f160; u8 p161[3]; f32 f164; u8 p168[8]; f32 f170; f32 f174; s32 f178; };
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[8]; u32 flags; u8 p10[8]; s32 n; u8 p1c[16]; f32 f2c; void* sub; u8 p34[4]; Ent* ents; };
s32 func_00139d78(void*);
s32 func_00239d10(s32);
void func_00139570(Obj*);
void func_00239f18(f32, Ent*);
void func_00239f78(f32, Ent*);
void func_00239eb8(f32, Ent*);
void func_0023acd8(Ent*);
s32 func_00239d30(Ent*, s32);
s32 func_00239d10e(Ent*) asm("func_00239d10");
void func_0028e438(Obj*, s32, s32, s32);
void func_0028ebf8(Obj* o)
{
    if (o->flags & 0x100) return;
    if (o->sub && !func_00139d78(o->sub)) {
        o->vt[5](o);
        return;
    }
    for (s32 i = 0; i < o->n; i++) {
        if (!func_00139d78(o)) return;
        if (o->ents[i].f178 && !func_00239d10(o->ents[i].f178)) {
            if (o->flags & 0x80) func_00139570(o);
            else o->vt[5](o);
            return;
        }
        { Ent* e = &o->ents[i]; func_00239f18(e->f170, e); }
        { Ent* e = &o->ents[i]; func_00239f78(e->f174, e); }
        { Ent* e = &o->ents[i]; func_00239eb8(e->f164 * o->f2c, e); }
        func_0023acd8(&o->ents[i]);
        if (o->ents[i].f160) o->ents[i].f160 = 0;
        if (!(u8)func_00239d30(&o->ents[i], o->ents[i].f114) && !func_00239d10e(&o->ents[i])) {
            if (o->ents[i].f15c != -1) {
                func_0028e438(o, i, o->ents[i].f15c, -1);
                func_0023acd8(&o->ents[i]);
                o->ents[i].f160 = 1;
            } else {
                if (o->flags & 0x80) func_00139570(o);
                else o->vt[5](o);
            }
        }
    }
}
}
