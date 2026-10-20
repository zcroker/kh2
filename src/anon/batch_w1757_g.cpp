#include "../common/types.h"

struct W1757Msg { s16 h[5]; };

extern "C" {
extern W1757Msg D_0032bae0;
void func_00195750(void);
void func_00104f58(W1757Msg*, s32, s32, s32, s32);

void func_002dd140(void) {
    W1757Msg m = D_0032bae0;
    func_00195750();
    func_00104f58(&m, 1, 0, 0, 0);
}
}
