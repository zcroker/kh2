/* func_00315500 / func_00315578: __cxa_throw / __cxa_rethrow from libsupc++ eh_throw.cc. */
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
W2374EhGlobals* func_00316af8(void);              // __cxa_get_globals
int func_003189e0(W2374UnwindException*);        // _Unwind_RaiseException
void* func_003166f0(void*);                       // __cxa_begin_catch
void func_00315440(void) __attribute__((noreturn)); // std::terminate

// 00315500: __cxa_throw
void func_00315500(void* obj, void* tinfo, void (*dest)(void*))
{
    W2374CxaException* header = (W2374CxaException*)obj - 1;
    header->exceptionType = tinfo;
    header->exceptionDestructor = dest;
    header->unexpectedHandler = D_003677ac;
    header->terminateHandler = D_003677a8;
    header->unwindHeader.exception_class = 0x474e5543432b2b00ULL; // "GNUCC++\0"
    header->unwindHeader.exception_cleanup = func_003154a8;

    W2374EhGlobals* globals = func_00316af8();
    globals->uncaughtExceptions += 1;

    func_003189e0(&header->unwindHeader);
    func_003166f0(&header->unwindHeader);
    func_00315440();
}

// 00315578: __cxa_rethrow (no layout row of its own; follows __cxa_throw in its section).
__attribute__((section(".text.func_00315500")))
void func_00315578(void)
{
    W2374EhGlobals* globals = func_00316af8();
    W2374CxaException* header = globals->caughtExceptions;
    if (header) {
        header->handlerCount = -header->handlerCount;
        func_003189e0(&header->unwindHeader);
        func_003166f0(&header->unwindHeader);
    }
    func_00315440();
}
}

