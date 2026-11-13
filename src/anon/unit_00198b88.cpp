// Event slots, part 1 (0x198b88-0x198d50): reset, lookup and allocation of the 16 event slots.
// The slot constructor (0x198d50 C2, 0x198dc0 C1) stays outside the units: its C1 copy calls an
// out-of-line linkonce member constructor (0x31cc28). Part 2 is unit_00198e40.cpp.
#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }

// Event slots (16 x 88 bytes at 0x1c61b48): a sound, a flag, resources and entries to run, and a
// YS::JUMPER at +52.
struct Ent198 {
    u16 type : 2;
    u16 id : 13;
};
struct JUMPER88 { u8 w[36]; };
struct EVENT88 {
    s32 a;          // 0x00
    s32 b;          // 0x04
    u32 se;         // 0x08
    s32 bgm;        // 0x0c
    u32 f10;        // 0x10
    s32 f14;        // 0x14
    s32 nres;       // 0x18
    u32* res;       // 0x1c
    Ent198 ents[7]; // 0x20
    s16 nents;      // 0x2e
    u8 f30;         // 0x30
    u8 pad31[3];
    JUMPER88 jmp;   // 0x34
    EVENT88();
} __attribute__((aligned(8)));

extern "C" {
extern EVENT88 D_01c61b48[16];
void func_00198ee8(EVENT88*);
s32 func_00199030(EVENT88*);

void func_00198b88(void) {
    EVENT88* p;
    for (p = D_01c61b48; (s32)p < (s32)(D_01c61b48 + 16); p++) new (p) EVENT88;
}
}

EVENT88* ctarget_00198bd0(s32 a, s32 b) asm("_Z16ctarget_00198bd0jjjj");
EVENT88* ctarget_00198bd0(s32 a, s32 b) {
    EVENT88* best = 0;
    EVENT88* e;
    for (e = D_01c61b48; (s32)e < (s32)(D_01c61b48 + 16); e++) {
        if (e->a == a) {
            s32 k = e->b;
            if (k == b) return e;
            if (b < 0 || k < 0) best = e;
        }
    }
    return best;
}

extern "C" {
EVENT88* func_00198c28(s32 a, s32 b) {
    EVENT88* fr = 0;
    for (s32 i = 0; i < 16; i++) {
        EVENT88* e = &D_01c61b48[i];
        if (e->a == a && e->b == b) return e;
        if (D_01c61b48[i].a < 0) fr = &D_01c61b48[i];
    }
    new (fr) EVENT88;
    fr->a = a;
    fr->b = b;
    return fr;
}

s32 func_00198cb8(s32 a, s32 b) {
    EVENT88* e = ctarget_00198bd0(a, b);
    s32 r;
    if (e != 0) {
        func_00198ee8(e);
        r = func_00199030(e);
    } else {
        r = 0;
    }
    return r;
}

bool func_00198d00(s32 a, s32 b) {
    return ctarget_00198bd0(a, b) != 0;
}

s32 func_00198d20(s32 a) {
    EVENT88* e = ctarget_00198bd0(a, -1);
    s32 r = -1;
    if (e) r = e->f14;
    return r;
}
}
