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
s32 YS__SHEET__is_mpdrive(void*);
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
s32 dk__GAUGE_PLAYER__getDriveLoopSqNum(u8* p);

void func_001e0fe8(u8* p);  // 0x001e0fe8: definition moved into src/anon/unit_001e0cb8.cpp

void Tz__Select__SetExOffset(s32 p, s32 i, s32 a, s32 b);  // 0x00288e08: definition moved into src/anon/unit_00288b00.cpp

void func_003169d0(void);  // 0x003169d0: definition moved into src/libsupc++/eh_globals.cpp

}
