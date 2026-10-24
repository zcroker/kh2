/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
// 00272758: fills the list rows (436-byte entries at +24740) from the item list, skipping the scrolled-off part.
extern "C" {
struct Ent272 { u8 pad[408]; void* data; u8 pad2[24]; };
struct Base272 { u8 pad[24740]; Ent272 e[16]; };
struct Item272 { u16 id; u8 pad[4]; };
extern s32 D_0035f014;
extern s32 D_0035f01c;
Base272* func_00257770(void);
s32 func_0028b038(s32);
s32 func_00281f18(s32);
s32 func_00257140(s32);
void func_00138c10(Ent272*, s32);
void* func_00282d58(s32);
u8* func_00281f30(s32);
Item272* func_00281f20(s32);
s32 func_00257158(s32, s32, s32);
void func_00272758(void) {
    s32 k = 0;
    Base272* b = func_00257770();
    s32 skip = func_0028b038(D_0035f01c);
    s32 n = func_00281f18(D_0035f014);
    s32 max, i;
    u8* d;
    if (skip == 0) {
        Ent272* e = &b->e[0];
        k = 1;
        func_00138c10(e, func_00257140(0));
        n++;
        e->data = func_00282d58(D_0035f014);
    } else {
        skip--;
    }
    max = n < 9 ? n : 8;
    d = func_00281f30(D_0035f014);
    for (i = 0; i < n && k < max; i++) {
        if (i >= skip) {
            Item272* l = func_00281f20(D_0035f014);
            Ent272* e = &b->e[k];
            func_00138c10(e, func_00257140(func_00257158(l[i].id, 1, 0)));
            e->data = d + i * 80 + 16;
            k++;
        }
    }
}
}

// 00316af8 is libsupc++'s __cxa_get_globals (eh_globals.cc, gcc 3.2-ee-040921, EE gthreads),
// byte-identical to the toolchain's libsupc++.a eh_globals.o.
struct W2389EhGlobals { void* caughtExceptions; u32 uncaughtExceptions; };
extern "C" {
extern s32 D_00367920;                 // use_thread_key
extern W2389EhGlobals D_01e4c798;      // globals_static
extern s32 D_01e4c7a0;                 // globals_key
void func_003169d0(void);              // get_globals_init_once
void** func_00316e00(void);            // __gthread_get_ee_key_value
s32* func_00316e10(void);              // __gthread_get_ee_key_use
s32 func_003060f0(void);               // QueryIntrContext
s32 func_00305510(void);               // GetThreadId
void* func_002fd3e8(u32);              // malloc
void func_00315440(void) __attribute__((noreturn)); // std::terminate

static inline s32 w2389_tid(void)
{
    if (func_003060f0() == 1) return 0;
    return func_00305510();
}

static inline void* w2389_getspecific(s32 key)
{
    void** value = func_00316e00();
    s32* use = func_00316e10();
    if (key >= 9 || !use[key]) return 0;
    return value[w2389_tid() * 8 + key];
}

static inline s32 w2389_setspecific(s32 key, const void* ptr)
{
    void** value = func_00316e00();
    s32* use = func_00316e10();
    if (key >= 9 || !use[key]) return -1;
    value[w2389_tid() * 8 + key] = (void*)ptr;
    return 0;
}

W2389EhGlobals* func_00316af8(void)
{
    W2389EhGlobals* g;
    if (D_00367920 == 0) return &D_01e4c798;
    if (D_00367920 < 0) {
        func_003169d0();
        if (D_00367920 == 0) return &D_01e4c798;
    }
    g = (W2389EhGlobals*)w2389_getspecific(D_01e4c7a0);
    if (!g) {
        if ((g = (W2389EhGlobals*)func_002fd3e8(sizeof(W2389EhGlobals))) == 0
            || w2389_setspecific(D_01e4c7a0, (void*)g) != 0)
            func_00315440();
        g->caughtExceptions = 0;
        g->uncaughtExceptions = 0;
    }
    return g;
}
}
