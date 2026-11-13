#include "../common/types.h"

// Last part of the PRIZE file before its static init (0x1cd078-0x1cd548): the HP-orb drop on hit,
// and the snapshot/restore of the game-state blocks around a retry. The static init at 0x1cd548
// (and its stubs) is still a separate function.

extern "C" {

// ---- 0x1cd078: drop orbs from the hit object
struct V1cd078 { f32 x, y, z, w; };
extern s32 D_003520c0;
s32 func_0018ca48_x8557(s32) asm("func_0018ca48");
s32 func_001d87b8(s32);
void func_001d86a0_x8559(s32, s32) asm("func_001d86a0");
void func_0016be98(V1cd078*, u8*);
void func_001ccf18(V1cd078*, s32, s32);
void func_001cd078(u8* p) {
    V1cd078 v;
    s32 n, a, b;
    if (D_003520c0 == 0) return;
    n = 0;
    if (*(u32*)(*(u8**)(p + 20) + 1416) & 0x80) {
        a = 0;
        b = 0;
    } else {
        a = 1;
        b = 2;
    }
    switch (func_0018ca48_x8557(p[38])) {
    case 0: case 2: case 3:
        n = 3;
        break;
    case 4: case 5: case 14:
        n = 15;
        break;
    }
    if (func_001d87b8(a) < n) n = func_001d87b8(a);
    if (n <= 0) return;
    func_001d86a0_x8559(-n, a);
    func_0016be98(&v, *(u8**)(p + 20));
    func_001ccf18(&v, b, n);
}

// ---- 0x1cd168: snapshot the live game state into the backup copies
struct A1cd { u16 h[5]; };
struct B1cd { u32 w[522]; };
struct Big1cd { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
struct Dst1cd { A1cd a; u16 pad; B1cd b; B1cd c; };
struct Src1cd { B1cd b; B1cd c; };
extern Big1cd D_0032bb30;
extern Big1cd D_01d499b0;
extern A1cd D_0032bae0;
extern Src1cd D_0034f250;
extern Dst1cd D_01d5a970;
s32 func_001cd4c0(void);
void func_001cd168(void) {
    if (func_001cd4c0()) {
        D_01d499b0 = D_0032bb30;
        D_01d5a970.a = D_0032bae0;
        D_01d5a970.b = D_0034f250.b;
        D_01d5a970.c = D_0034f250.c;
    }
}

// ---- 0x1cd2b8: restore the saved block and reset the id state
struct Ids81 {
    u16 a, b, c;
    void Fill81(s32 v) { a = v; b = v; c = v; }
};
struct S1cd { u8 a, b, c, pad; Ids81 q; u8 pad2[2]; u8 s1[2088]; u8 s2[16]; };
extern S1cd D_01d5a970s asm("D_01d5a970");
void func_00195558(u8*);
void func_001cd2b8(void) {
    D_01d499b0 = D_0032bb30;
    S1cd* s = &D_01d5a970s;
    u8* src = (u8*)&D_0032bb30;
    s->q.Fill81(0xffff);
    s->a = src[12];
    s->b = src[13];
    s->c = src[14];
    func_00195558(s->s1);
    func_00195558(s->s2);
}

// ---- 0x1cd388: restore the saved copies of the game-state blocks
struct SaveMid { u32 d[2088 / 4]; };
extern Big1cd D_01d499b0b asm("D_01d499b0");
extern SaveMid D_01d5a97c;
extern SaveMid D_0034f250m asm("D_0034f250");
extern SaveMid D_01d5b1a4;
extern SaveMid D_0034fa78;
void func_001ada38(u32);
void func_001ba138(void);  // to_2fd310_block
void func_00242908(void);
void func_00168fa8(void);
void func_001cd388(void) {
    D_0032bb30 = D_01d499b0b;
    D_0034f250m = D_01d5a97c;
    D_0034fa78 = D_01d5b1a4;
    func_001ada38(8);
    func_001ba138();  // to_2fd310_block
    func_00242908();
    func_00168fa8();
}

// ---- 0x1cd4c0
s32 func_001bbf00(void);
s32 func_001bb4a0(void);
extern u8 D_00350378;
extern u8 D_0032bae0b asm("D_0032bae0");
s32 func_001cd4c0(void) {
    s32 r;
    u8* g = &D_0032bae0b;
    if (func_001bbf00()) r = 1;
    else if (*(u16*)(g + 4) < 51 && !D_00350378 && !func_001bb4a0()) r = 1;
    else r = 0;
    return r;
}

// ---- 0x1cd520
struct Blob10 { u16 h[5]; };
extern Blob10 D_01d5a970b asm("D_01d5a970");
Blob10* func_001cd520(Blob10* p) {
    *p = D_01d5a970b;
    return p;
}
}
