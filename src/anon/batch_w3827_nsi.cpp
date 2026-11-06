// Built with -fno-sched-interblock (_nsi).
#include "../common/types.h"

extern "C" {
struct E1 { u32 p; u8 b[3]; u8 f; };
extern E1 D_003742c8[];
extern s8 D_00374268[];
extern char D_00374270[];
s32 func_00283a58(s32, s32);
void func_002fee78(char*, const char*, ...);

// Formats entry a1 of the D_003742c8 table into a0.
void func_00283eb8(char* a0, s32 a1) {
    register E1* e asm("$15") = &D_003742c8[a1]; // pin: entry address in t7
    u8 f = e->f;
    s32 v = func_00283a58((s32)a0, a1);
    if (f & 0xfb) {
        if (v != 1 || (f & 2)) goto T;
    }
    v = 2;
T:;
    s8* q = &D_00374268[v];
    u32 p = D_003742c8[a1].p;
    register char* r4 asm("$4") = a0; // pin: first argument
    // no code: one more reader of a0 so sched2 issues move a0 before the q address add
    asm("" : "+r"(p) : "r"(r4));
    func_002fee78(r4, D_00374270, p, *q);
}
}
