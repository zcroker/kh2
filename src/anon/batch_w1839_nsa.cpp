#include "../common/types.h"
struct Obj {
    u8 pad0[0x10c]; u32 f10c;
    u8 pad1[0x768 - 0x110]; u32 f768;
    u8 pad2[0x9ac - 0x76c]; u8 mode;
};
static inline void setSub(Obj* p, s32 s) {
    switch (s) {
    case 0: p->f768 &= ~0x200; p->f768 &= ~0x400; break;
    case 1: p->f768 |= 0x200; p->f768 &= ~0x400; break;
    case 2: p->f768 &= ~0x200; p->f768 |= 0x400; break;
    }
}
struct Ent { s32 a; s32 b; s32 c; };
struct Dst {
    Ent e[32];
    u8 pad0[0x188 - 0x180]; u16 h188; u16 pad18a; u16 h18c; u16 pad18e;
    u8 pad1[0x198 - 0x190]; s32 w198; s32 w19c; s32 w1a0; s32 w1a4;
    u8 b1a8[7];
    u8 pad2[0x1c4 - 0x1af]; f32 f1c4;
    u8 pad3[0x264 - 0x1c8]; struct Src* src;
};
struct Src { u16 h0; u16 id; u16 v[32]; u16 m44; u16 m46; u16 k[7]; };
struct G { u8 pad[300]; f32 f; };
extern G* D_00352130;
extern "C" {
u16* func_001c0c80(u16);
u16* func_001c0cc8(void);
void wtarget_00194468(Obj* p, u32, u32, u32) asm("_Z16wtarget_00194468jjjj");
void wtarget_00194468(Obj* p, u32, u32, u32);  // 0x00194468: definition moved into src/anon/unit_00193be8.cpp
void func_001a0ee0(Dst* d, Src* s);  // 0x001a0ee0: definition moved into src/anon/unit_0019fb70.cpp
}
