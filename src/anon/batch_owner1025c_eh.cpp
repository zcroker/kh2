/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

/* Built with -fexceptions (Makefile rule for *_eh.cpp): libsupc++ itself was, and the catch(...)
 * landing pad (__cxa_begin_catch, then abort) only exists with exception support. */
extern "C" {
__attribute__((noreturn)) void func_002fd160(void) throw();   // abort
void* __cxa_begin_catch(void*) throw() asm("func_003166f0"); // the game's __cxa_begin_catch

// libsupc++ eh_terminate.cc (gcc 3.2): __cxxabiv1::__terminate.
void func_00315418(void (*handler)(void)) {
    try {
        handler();
        func_002fd160();
    } catch (...) {
        func_002fd160();
    }
}
}
