// Linked unit 0x002d9588-0x002d96d8 (Hachimitsu minigame: bump a gopher's hit counters, play the sound once all three counts add up;
// was whole asm in src/anon/asm_002d9588.s, never written in C before).
#include "../common/types.h"

namespace n002d9588 {
s32 func_002cf308(s32) asm("func_002cf308");
struct Snd2d9588 { void** vt; };
Snd2d9588* func_0016b740(s32) asm("func_0016b740");
void func_001d86a0(s32, s32) asm("func_001d86a0");
struct Cnt2d9588 { s32 v0, v4, v8; };
struct Obj2d9588 {
    u8 p0[108]; s32 m6c[3]; s32 m78[3]; s32 m84[3]; u8 p90[152 - 144]; s32 f152; u8 p156[12]; s32 f168;
};
/*TARGET 002d9588*/
// Both counters are reached through pointers into the same Cnt struct type, so the scheduler sees different fields
// (no alias dependence between the two read-modify-writes) and issues both loads first.
void func_002d9588(Obj2d9588* o, s32 k, s32 i) asm("func_002d9588");
void func_002d9588(Obj2d9588* o, s32 k, s32 i) {
    s32 p = i * 4 + (s32)o;
    Cnt2d9588* a = (Cnt2d9588*)(p + 112);
    Cnt2d9588* b = (Cnt2d9588*)(p + 128);
    a->v8++;
    b->v4++;
    s32 tab[3] = { 10, 5, 1 };
    s32 r0, r1, r2;
    r0 = func_002cf308(0);
    r1 = func_002cf308(1);
    r2 = func_002cf308(2);
    if (r0 + r1 + r2 == o->m84[0] + o->m84[1] + o->m84[2]) {
        u8 ids[8] = { 0x18, 0, 0x19, 0x1a, 0, 0, 0x17, 0 };
        if (ids[o->f168]) {
            Snd2d9588* s = func_0016b740(1630);
            ((void (*)(Snd2d9588*, s32, s32))s->vt[21])(s, ids[o->f168], 4);
        }
    }
    if (o->f152 == 2) func_001d86a0(tab[i] * k, 0);
}
}  // namespace n002d9588
