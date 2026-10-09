#include "../common/types.h"

extern "C" {

struct Ctl78 { s32 on; s32 f4, f8, f12, f16, f20; s32 f24; u32 a, b, c, d; s32 f44, f48, f52; };
struct Obj78 { u8 pad[0x48000]; Ctl78 ctl; };
void func_002b8824(Obj78* o, u32 a, u32 b, u32 c, u32 d)
{
    o->ctl.f4 = o->ctl.f8 = o->ctl.f12 = o->ctl.f16 = o->ctl.f20 = 0;
    o->ctl.f24 = 0x8000;
    o->ctl.a = a;
    o->ctl.b = b;
    o->ctl.c = c;
    o->ctl.d = d;
    o->ctl.on = 1;
    o->ctl.f44 = o->ctl.f48 = o->ctl.f52 = 0;
}

// ---- 002b7440
struct Ent2b7 { s32 type; s32 a; s32 b; s32 c; u8 pad[48]; };
extern Ent2b7 D_01e22080[];
// The same table viewed from its a/b/c fields (how the original addresses them).
extern Ent2b7 D_01e22084[], D_01e22088[], D_01e2208c[];
s32 func_003058a0(s32 a);

// Count type-19/43 entries matching the given keys (negative key = wildcard).
s32 func_002b7440(s32 a, s32 b, s32 c) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    if (a < -99) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19) n++;
            if (D_01e22080[i].type == 43) n++;
        }
    } else if (b < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a) n++;
        }
    } else if (c < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a && D_01e22088[i].type == b) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a && D_01e22088[i].type == b) n++;
        }
    } else {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a && D_01e22088[i].type == b && D_01e2208c[i].type == c) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a && D_01e22088[i].type == b && D_01e2208c[i].type == c) n++;
        }
    }
    return n;
}

// ---- 002b8c78
struct Hdr78 { u8 pad0[12]; s32 f12; u8 pad1[4]; s32 f20; s32 f24; u8 pad2; u8 f29; };
void func_002fdd68(void*, void*, u32);
s32 func_002b8694(s32);
s32 func_002b6708(s32, s32, void*, s32, u32, u32, s32, s32);
void func_002b8c78(Obj78* o)
{
    s32 i;
    if (o->ctl.on != 0) {
        switch (o->ctl.on) {
        case 1:
            if (o->ctl.f44 == 0) {
                Hdr78* h = (Hdr78*)o;
                o->ctl.f20 = h->f29;
                if (h->f20 == 0) o->ctl.f8 = 0;
                else o->ctl.f8 = func_002b8694(h->f20) / 28 * o->ctl.f20 * 16 + 128;
                if (h->f24 == 0) o->ctl.f12 = func_002b8694(h->f12);
                else o->ctl.f12 = func_002b8694(h->f24) / 28 * o->ctl.f20 * 16 + 128;
                o->ctl.f48 = o->ctl.f8 & -0x8000;
            }
            func_002fdd68((u8*)o + o->ctl.f4 + 0x8000, o, 0x8000);
            o->ctl.f4 = (o->ctl.f4 + 0x8000) % 0x40000;
            o->ctl.f44 += o->ctl.f24 / 2048;
            break;
        case 2:
            for (i = 0; i < o->ctl.f24 / 16; i++) {
                func_002fdd68((u8*)o + o->ctl.f4 + 0x8000, (u8*)o + (o->ctl.f52 + i * 16), 16);
                o->ctl.f4 = (o->ctl.f4 + 16) % 0x40000;
            }
            o->ctl.f44 += 16;
            break;
        }
        o->ctl.f16 += o->ctl.f24;
        o->ctl.f24 = 0x8000;
        o->ctl.f52 = 0;
        if (o->ctl.f8 != 0 && o->ctl.f16 >= o->ctl.f12) {
            o->ctl.f4 -= o->ctl.f16 - o->ctl.f12;
            if (o->ctl.f4 < 0) o->ctl.f4 += 0x40000;
            o->ctl.f16 = o->ctl.f8;
            o->ctl.f44 = o->ctl.f48 / 2048;
            o->ctl.f52 = o->ctl.f8 - o->ctl.f48;
            o->ctl.f24 = 0x8000 - o->ctl.f52;
        }
        if (o->ctl.on == 1 && o->ctl.f44 * 2048 > 0x1ffff) {
            func_002b6708(7, 25, (u8*)o + 0x8000, 0x40000, o->ctl.a, o->ctl.b, 2, 2);
            o->ctl.on = 2;
        }
    }
}

} // extern "C"
