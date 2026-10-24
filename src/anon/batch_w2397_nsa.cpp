#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).

struct W2397Sub { s32 a; s32 b; u8 c8; u8 c9; u8 ca; u8 cb; u8 cc; void set9(u8 v) { c9 = v; } void setb(u8 v) { cb = v; } };
struct W2397Ent { s32 x0, x4; u32 fl; s32 xc; W2397Sub s; };
struct W2397Bits64 { u64 lo : 40; u64 hi : 24; };
struct W2397Obj {
    char p0[0xc]; u8 c0c; u8 c0d; char p1[0x2440 - 0xe];
    s32 v2440; s32 v2444; char p2[0x2498 - 0x2448]; u8 c2498; u32 : 0; u32 b249c : 1; u32 : 31;
    char p4[0x24f0 - 0x24a0]; char t24f0[0x4198 - 0x24f0]; u32 w4198; u8 c419c;
};
struct W2397Rec { char p[0xf]; u8 cf; };

extern "C" {
s32 func_001058d8(W2397Obj*);
W2397Rec* func_00188fe0(void*, s32);
s32 func_0019f880(u8, u8);
extern W2397Obj* D_0035ec90;
extern W2397Ent* D_0035ec94;

// Entry address written index-first (the original adds i*32 before the table base here).
#define W2397_ENT(i) ((W2397Ent*)(((i) << 5) + (u32)D_0035ec94))

// Copies state flags and properties of object o (default D_0035ec90) into entry i of the D_0035ec94 table.
void func_00240c08(s32 i, W2397Obj* o, u32 fl) {
    if (o == 0) o = D_0035ec90;
    if ((u8)(fl & 1)) D_0035ec94[i].fl |= 1;
    if (fl & 2) D_0035ec94[i].fl |= 2;
    if (fl & 0x10) {
        D_0035ec94[i].fl |= 0x10;
        D_0035ec94[i].xc = func_0019f880(o->c0d, o->c0c);
        D_0035ec94[i].s.a = o->v2444;
        D_0035ec94[i].s.b = o->v2440;
        D_0035ec94[i].s.c8 = o->c2498;
        if ((u8)o->b249c) W2397_ENT(i)->s.set9(func_00188fe0(o->t24f0, 14)->cf);
        else W2397_ENT(i)->s.set9(func_00188fe0(o->t24f0, 1)->cf);
        if (o->c0c >= 19) D_0035ec94[i].s.ca = 0xff;
        else D_0035ec94[i].s.ca = o->c0c;
        W2397_ENT(i)->s.setb(o->c419c);
        D_0035ec94[i].s.cc = ((W2397Bits64*)&o->w4198)->hi & 1;
        if (func_001058d8(o)) D_0035ec94[i].fl |= 0x10000000;
        else D_0035ec94[i].fl &= ~0x10000000;
    } else if (fl & 0x40) {
        D_0035ec94[i].fl |= 0x40;
    } else {
        D_0035ec94[i].fl |= 0x20;
    }
}
}
