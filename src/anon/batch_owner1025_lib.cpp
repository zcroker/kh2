/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"
extern "C" {
/* libsupc++ eh_terminate.cc (gcc 3.2): __cxxabiv1::__unexpected, std::unexpected and
 * std::set_terminate. func_00315440 is std::terminate. */
typedef void (*W2361Handler)(void);
extern W2361Handler D_003677a8;  // __terminate_handler
extern W2361Handler D_003677ac;  // __unexpected_handler
__attribute__((noreturn)) void func_00315440(void);
__attribute__((noreturn)) void func_00315418(W2361Handler);  // __cxxabiv1::__terminate
__attribute__((noreturn)) void func_00315458(W2361Handler handler);
__attribute__((noreturn)) void func_00315470(void);

/* std::terminate: calls __terminate with the current handler. */
void func_00315440(void) {
    func_00315418(D_003677a8);
}

void func_00315458(W2361Handler handler) {
    handler();
    func_00315440();
}

void func_00315470(void) {
    func_00315458(D_003677ac);
}

W2361Handler func_00315488(W2361Handler func) throw() {
    W2361Handler old = D_003677a8;
    D_003677a8 = func;
    return old;
}
}
