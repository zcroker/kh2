#include "../common/types.h"
namespace w1606_27eb10 {
struct Ent { u8 pad0[0x694]; u8 g0[0x82c - 0x694]; u8 g1[0x13e4 - 0x82c]; char s0[8]; char s1[8]; char s2[8]; };
struct Sub { u8 pad[0xf]; u8 lv; };
struct Obj {
    s32 hp; s32 hpmax; u8 pad8[0x180 - 8]; s32 mp; s32 mpmax;
    u16 a188; u16 a18a; u16 a18c; u16 a18e; u8 pad190[0x1b0 - 0x190]; u8 b1b0; u8 b1b1;
    u8 pad1b2[0x244 - 0x1b2]; Sub* sub;
};
}
using namespace w1606_27eb10;
extern "C" {
s32 func_00281100(s32);
Obj* func_00281180(s32, s32);
void func_00192cc0(char*, const char*, ...);
void func_00239f18(f32, u8*);
extern s32 D_0035f010;
extern Ent* D_0035f248;
extern u8 D_0035f24d;
extern s8 D_0035f24e;
extern char D_00373fd8[];
extern char D_00373fe0[];

void func_0027eb10(void) {
    s32 n = D_0035f24e == 4 ? func_00281100(D_0035f010) : 1;
    s32 i;
    for (i = 0; i < n; i++) {
        s32 k = D_0035f24e;
        if (k == 4) k = i;
        Obj* o = func_00281180(D_0035f010, k);
        switch (D_0035f24d) {
        case 0:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->sub->lv);
            { s32 hm = o->hpmax; func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13ec), D_00373fe0, o->hp, hm); }
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13f4), D_00373fe0, o->mp, o->mpmax);
            func_00239f18((f32)o->hp / (f32)o->hpmax, D_0035f248[i].g0);
            func_00239f18((f32)o->mp / (f32)o->mpmax, D_0035f248[i].g1);
            break;
        case 1:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a188);
            break;
        case 2:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18c);
            break;
        case 3:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18a);
            break;
        case 4:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->a18e);
            break;
        case 5:
            func_00192cc0((char*)(i * 5116 + (u32)D_0035f248 + 0x13e4), D_00373fd8, o->b1b1);
            func_00239f18((f32)o->b1b0 / 100.0f, D_0035f248[i].g0);
            break;
        }
    }
}

void func_00288d80(s32, s32, s32, s32, s32, s32, u16*, u16*);
u8* func_002891b8(s32, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa98(u8*);
void func_00288e08(s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028af28(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028af90(s32, s32);
extern s32 D_0035f3d4;
extern u16 D_0035f098[2][4];
extern u16 D_0035f0a8[];

void func_00259108(s32 o, s32 id, s32 a2, s32 a3, s32 a4, s32 two, u16* src) {
    u32 vals[2];
    s32 sid = id;
    s32 b2 = a2;
    s32 b3 = a3;
    s32 save = D_0035f3d4;
    D_0035f3d4 = id < 0 ? save : id;
    s32 kind = 64;
    s32 n;
    s32 i;
    if (two == 0) {
        n = 1;
        vals[0] = D_0035f0a8[0];
        kind = 67;
    } else {
        n = 2;
        vals[0] = D_0035f0a8[2];
        vals[1] = D_0035f0a8[1];
    }
    for (i = 0; i < 2; i++) {
        s32 k;
        for (k = 0; k < 3; k++) D_0035f098[i][k] = src[k];
        D_0035f098[i][3] = 0xffff;
        if (i + 1 >= 2) D_0035f098[i][2] = src[3];
    }
    for (i = 0; i < n; i++) {
        func_00288d80(o, i, b2, b3, a4, vals[i] | 0x8000, D_0035f098[0], D_0035f098[1]);
        s32 x = func_0023aa78(func_002891b8(o, i) + 24);
        s32 y = func_0023aa98(func_002891b8(o, i) + 24);
        func_00288e08(o, i, x, 0);
        func_00139620(func_002891b8(o, i));
        *(s32*)(func_002891b8(o, i) + 432) = 2;
        u8* p = func_002891b8(o, i);
        *(s32*)(p + 412) = y;
        *(s32*)(p + 416) = 0;
    }
    func_0028af28(o, kind);
    func_002891f0(o, 0, 1, 0, 2);
    func_0028af90(o, -1);
    if (sid >= 0) D_0035f3d4 = save;
}
}
