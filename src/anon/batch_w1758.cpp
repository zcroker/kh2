/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

// GCC library code: libsupc++ eh_throw.cc __gxx_exception_cleanup
// (byte-identical to the toolchain's libsupc++.a eh_throw.o).
typedef void (*w1758_th_t)();
struct W1758CxaExc {
    void* exceptionType;
    void (*exceptionDestructor)(void*);
    void* unexpectedHandler;
    w1758_th_t terminateHandler;
    u8 pad[48 - 16];
    u8 ue[32]; /* _Unwind_Exception */
};

extern "C" {
void func_00315418(w1758_th_t) __attribute__((noreturn)); /* __cxxabiv1::__terminate */
void func_00316658(void*);                                /* __cxa_free_exception */

void func_003154a8(int code, u8* exc) {
    W1758CxaExc* h = (W1758CxaExc*)(exc - 48);
    if (code != 1)
        func_00315418(h->terminateHandler);
    if (h->exceptionDestructor)
        h->exceptionDestructor(h + 1);
    func_00316658(h + 1);
}
}
