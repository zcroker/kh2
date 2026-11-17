/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* __cxa_throw / func_00315578: __cxa_throw / __cxa_rethrow from libsupc++ eh_throw.cc. */
#include "../common/types.h"
// libsupc++ exception header (unwind-cxx.h, GCC 3.2).
typedef unsigned int W2374UDI __attribute__((mode(DI)));
struct W2374UnwindException {
    W2374UDI exception_class;
    void (*exception_cleanup)(int, W2374UnwindException*);
    u32 private_1;
    u32 private_2;
} __attribute__((__aligned__));
struct W2374CxaException {
    void* exceptionType;
    void (*exceptionDestructor)(void*);
    void (*unexpectedHandler)();
    void (*terminateHandler)();
    W2374CxaException* nextException;
    int handlerCount;
    int handlerSwitchValue;
    const u8* actionRecord;
    const u8* languageSpecificData;
    void* catchTemp;
    void* adjustedPtr;
    W2374UnwindException unwindHeader;
};
struct W2374EhGlobals {
    W2374CxaException* caughtExceptions;
    u32 uncaughtExceptions;
};

extern "C" {
extern void (*D_003677ac)();    // __unexpected_handler
extern void (*D_003677a8)();    // __terminate_handler
void func_003154a8(int, W2374UnwindException*);   // __gxx_exception_cleanup
W2374EhGlobals* __cxa_get_globals(void);              // __cxa_get_globals
int func_003189e0(W2374UnwindException*);        // _Unwind_RaiseException
void* __cxa_begin_catch(void*);                       // __cxa_begin_catch
__attribute__((noreturn)) void func_00315440(void); // std::terminate

// 00315500: __cxa_throw
void __cxa_throw(void* obj, void* tinfo, void (*dest)(void*));  // 0x00315500: definition moved into src/libsupc++/eh_throw.cpp

// 00315578: __cxa_rethrow (no layout row of its own; follows __cxa_throw in its section).
__attribute__((section(".text.func_00315500")))
void func_00315578(void);  // 0x00315578: definition moved into src/libsupc++/eh_throw.cpp
}

