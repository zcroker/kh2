/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

extern s32 D_00367924;
extern s32 D_00367920;
extern s32 D_00352bd0;

extern "C" {
s32 func_001a1de0(void*);
s32 func_0023aa98(s32);
void func_00138c68(s32, s32, s32);
s32 DIntr(void);
void EIntr(void);
void func_00316998(void);
void* func_001e2760(s32, s32);
}

/* libsupc++ (eh_globals.cc style): __gthread_once with the game's lock helpers. */
static inline s32 w1766_once(s32* o, void (*f)(void)) {
    s32 first = 0;
    s32 r = DIntr();
    if (*o == 0) { *o = 1; first = 1; }
    if (r) EIntr();
    if (first) f();
    return 0;
}

extern "C" {

// 00155f40: moved to src/anon/unit_00153ea0.cpp
s32 func_00155f40(u8* p);

void func_001e0fe8(u8* p) {
    u8* r = (u8*)func_001e2760(D_00352bd0, *(s32*)(p + 0x20));
    if ((s8)r[0] < 0) { *(s32*)(p + 0x24) = 2; return; }
    r[0] += 10;
    r[0] = (s8)r[0] < 0 ? 0x80 : r[0];
    r[1] = 0;
    r[2] = 0;
    r[3] = 10;
}

void func_00288e08(s32 p, s32 i, s32 a, s32 b) {
    p = (*(s32**)(p + 0x28))[i];
    s32 v = func_0023aa98(p + 0x18);
    if (b == -1) b = v;
    s32 aa = a;
    if (a == -1) aa = v;
    func_00138c68(p, aa * i, b * i);
}

void func_003169d0(void) {
    if (w1766_once(&D_00367924, func_00316998) != 0 || D_00367920 < 0) D_00367920 = 0;
}

}
