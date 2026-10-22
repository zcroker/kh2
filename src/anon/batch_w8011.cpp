#include "../common/types.h"
extern "C" {

struct E27bb { u8 a; s8 f1; u8 q[6]; };
void func_00279ec8(void);
void func_0027b6b8(void);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
void func_0027a6d8(void);
void func_0027a208(void);
void func_0027b248(s32);
u32 func_0028af88(s32);
s32 func_0028b040(s32);
extern E27bb* D_0035f230;
s32 func_00283ab8(s32);
s32 func_00258068(s32);
void func_00256cc0(s32, s32, s32);
void func_0028af18(s32, u32);
void func_0027aaa0(void);

void func_0027bbe0(s32 a0, s32 a1) {
    if (a1 == 15) {
        func_00279ec8();
    } else if (a1 == 16) {
        s32 st0, st1;
        u32 f;
        s32 id;
        func_0027aed8(func_002570a0(15), &st0, &st1);
        func_0027a6d8();
        func_0027a208();
        if (st0 == 0) func_0027b248(1);
        f = func_0028af88(a0);
        if (st0 == 0) {
            E27bb* e;
            a1 = func_0028b040(a0);
            e = (E27bb*)((u32)(a1 << 3) + (u32)D_0035f230) + 2;
            if (!e->f1) f &= ~0x200;
            else f |= 0x200;
        }
        id = -1;
        if (func_00283ab8(2)) {
            f |= 0x400;
            id = 0xcbdd;
        } else {
            f &= ~0x400;
        }
        if (func_00258068(0)) {
            func_00256cc0(0xb373, 0xb61a, id);
        } else if (id >= 0) {
            func_00256cc0(0xb61a, id, -1);
        }
        func_0028af18(a0, f);
    } else {
        func_0027aaa0();
        func_0027b248(func_0028b040(a0) != 0);
    }
    func_0027b6b8();
}

struct Sub283790 { u8 pad[184]; u32 flags; };
struct Obj283790 { u8 pad[24]; Sub283790 sub; u8 pad2[392 - 24 - 188]; s32 mode; u8 pad3[405 - 396]; u8 on; u8 pad4[2]; };
struct Ent283790 { u8 pad[6]; u8 g; u8 pad7; };
struct St283790 { u8 pad[4]; s8 list[9]; s8 n; s8 cur; };
extern u8* D_0035f2b8;
extern St283790* D_0035f2b4;
extern u32 D_0035f03c;
extern Ent283790 D_003742c8[];
s32 func_00139d78(void*);
static inline void SetFlag283790(u8* p) { ((Sub283790*)p)->flags |= 8; }
u32 func_0023f1b0(u32);
u32 func_0023c4b8(u32, s32);
void func_001386e0(void*, s32, u32, u8*, s32, s32);
void func_00283790(void)
{
    s32 same = 0;
    u8* b;
    if (!func_00139d78(D_0035f2b8 + 1288)) {
        u32 v = func_0023c4b8(func_0023f1b0(D_0035f03c), 0);
        b = D_0035f2b8;
        Obj283790* o = (Obj283790*)(b + 1288);
        func_001386e0(o, 30022, v, b, 1, 0);
        o->mode = 2;
        o->on = 1;
        SetFlag283790(b + 1312);
    }
    St283790* s = D_0035f2b4;
    if (s->cur + 1 < s->n) same = D_003742c8[s->list[s->cur]].g == D_003742c8[s->list[s->cur + 1]].g;
    if (!func_00139d78(D_0035f2b8 + 1696) && same) {
        u32 v = func_0023c4b8(func_0023f1b0(D_0035f03c), 0);
        b = D_0035f2b8;
        Obj283790* o = (Obj283790*)(b + 1696);
        func_001386e0(o, 30022, v, b, 4, 0);
        o->mode = 5;
        o->on = 1;
        SetFlag283790(b + 1720);
    }
}
}
