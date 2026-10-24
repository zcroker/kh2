#include "../common/types.h"
extern "C" {
/* libsupc++ eh_terminate.cc (gcc 3.2): __cxxabiv1::__unexpected, std::unexpected and
 * std::set_terminate. func_00315440 is std::terminate. */
typedef void (*W2361Handler)(void);
extern W2361Handler D_003677a8;  // __terminate_handler
extern W2361Handler D_003677ac;  // __unexpected_handler
void func_00315440(void) __attribute__((noreturn));
void func_00315458(W2361Handler handler) __attribute__((noreturn));
void func_00315470(void) __attribute__((noreturn));

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
