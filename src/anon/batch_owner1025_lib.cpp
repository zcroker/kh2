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
void func_00315440(void);  // 0x00315440: definition moved into src/libsupc++/eh_terminate.cpp

void func_00315458(W2361Handler handler);  // 0x00315458: definition moved into src/libsupc++/eh_terminate.cpp

void func_00315470(void);  // 0x00315470: definition moved into src/libsupc++/eh_terminate.cpp

W2361Handler func_00315488(W2361Handler func) throw();  // 0x00315488: definition moved into src/libsupc++/eh_terminate.cpp
}
