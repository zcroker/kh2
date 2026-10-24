/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

// libsupc++ exception object (unwind-cxx.h, GCC 3.2) and per-thread globals.
struct W2367UnwindException { u32 w[8]; } __attribute__((aligned(16)));
struct W2367CxaException {
    void* exceptionType;
    void (*exceptionDestructor)(void*);
    void (*unexpectedHandler)();
    void (*terminateHandler)();
    W2367CxaException* nextException;
    int handlerCount;
    int handlerSwitchValue;
    const u8* actionRecord;
    const u8* languageSpecificData;
    void* catchTemp;
    void* adjustedPtr;
    W2367UnwindException unwindHeader;
};
struct W2367CxaEhGlobals {
    W2367CxaException* caughtExceptions;
    unsigned int uncaughtExceptions;
};

struct W2367Entry { u32 a; u8 id; u8 pad[15]; };
struct W2367Table { s32 n; u8 pad[60]; W2367Entry e[1]; };
struct W2367Vec3 { f32 x, y, z; };

extern "C" {
s32 func_001094e0(s32, s32);
void func_00133c60(s32, s32, s32, s32, s32);
s32 func_00109788(s32 a, s32 b) {
    if (func_001094e0(b, b) == 0) {
        func_00133c60(a, b, 0, 0, 0);
        return 1;
    }
    return 0;
}

// Next entry after p (or the first one) whose id matches; id 22 matches any entry.
W2367Entry* func_0018a100(W2367Table* t, s32 id, W2367Entry* p) {
    W2367Entry* end;
    p = p == 0 ? t->e : p + 1;
    end = t->e + t->n;
    while (p < end) {
        if (id == 22 || p->id == id) return p;
        p++;
    }
    return 0;
}

// Yaw that faces from a towards b, written as (0, yaw, 0).
f32 f_atan2f(f32, f32);
f32 FixRadian_w2367(f32) asm("_ZN2YS4MATH9FixRadianEf");
void func_00230260(W2367Vec3* a, W2367Vec3* b, W2367Vec3* out) {
    f32 t = f_atan2f(b->x - a->x, b->z - a->z);
    t = 3.14159274f - t;
    t = FixRadian_w2367(t);
    out->x = 0; out->y = t; out->z = 0;
}

// libsupc++ __cxa_end_catch (eh_catch.cc, GCC 3.2).
W2367CxaEhGlobals* func_00316a50(void);              // __cxa_get_globals_fast
void func_00319190(W2367UnwindException*);           // _Unwind_DeleteException
void func_002fd160(void) __attribute__((noreturn));  // std::terminate
void func_00316750(void) {
    W2367CxaEhGlobals* globals = func_00316a50();
    W2367CxaException* header = globals->caughtExceptions;
    int count = header->handlerCount;

    if (count < 0) {
        // This exception was rethrown. Decrement the (inverted) catch
        // count and remove it from the chain when it reaches zero.
        if (++count == 0) {
            globals->uncaughtExceptions += 1;
            globals->caughtExceptions = header->nextException;
        }
    } else if (--count == 0) {
        // Handling for this exception is complete. Destroy the object.
        globals->caughtExceptions = header->nextException;
        func_00319190(&header->unwindHeader);
        return;
    } else if (count < 0)
        // A bug in the exception handling library or compiler.
        func_002fd160();

    header->handlerCount = count;
}
}
