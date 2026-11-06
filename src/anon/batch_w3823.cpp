// func_00196028: walks four slots; for each live object either restarts it (1950/1a20, sets the dirty flag)
// or resets it (1a50/1910), then releases it (17c8).
// Partial asm: g pinned to s4; a1 pinned (r) so the call argument 1 is set before the full() test, which lets
// reorg redirect that branch past the second li a1,1; the empty asm volatile keeps that li after the andi so it
// fills the bnez delay slot. Closest pure C: 1 line (bnez slot left empty).
#include "../common/types.h"
struct Obj196 { s32 a0; s32 a4; u8 pad[0x178]; s32 c180; s32 c184; u8 pad2[0xd4]; s32 c25c;
  s32 ilt2() { return c180 < c184; } bool full() { return a0 >= a4; }
};
struct Self { u8 pad[0x9fc]; u8 f9fc; u8 f9fd; };
extern "C" {
Obj196* func_001a1658(s32, s32);
void func_001a17c8(Obj196*);
void func_001a1910(Obj196*, s32, s32);
void func_001a1950(Obj196*, s32, s32, s32);
void func_001a1a20(Obj196*, s32, s32);
void func_001a1a50(Obj196*, s32);
s32 func_001a1de0(Obj196*, s32);
s32 func_001a8bd0(s32);
s32 func_001a8c10(s32, s32);
void func_00196028(Self* self) {
    register s32 g asm("$20") = func_001a8bd0(-1);
    for (s32 i = 0; i < 4; i++) {
        s32 h = func_001a8c10(g, i);
        if (h == 0) continue;
        Obj196* o = func_001a1658(h, -1);
        if (o->c25c != 0) {
            register s32 r asm("$5") = 1;
            if (o->full()) { s32 b = 0; if (!func_001a1de0(o, r)) b = !o->ilt2(); u8 c = b; asm volatile(""); r = 1; if (c) goto done; }
            func_001a1950(o, r, 0, 0);
            func_001a1a20(o, 1, 0);
            self->f9fc = 1;
        } else {
            func_001a1a50(o, 0);
            s32 n = o->a4; func_001a1910(o, n, 0);
        }
    done:;
        func_001a17c8(o);
    }
    if (self->f9fd) {
        self->f9fd = 0;
        self->f9fc = 1;
    }
}
}
