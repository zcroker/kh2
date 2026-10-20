#include "../common/types.h"
extern "C" {
struct W1821B38 { s64 d[7]; };
struct W1821In { s32 a; s32 b; };
struct W1821Ctx { s32 x; W1821In* in; };
struct W1821N { s32 a0; W1821Ctx* ctx; s32 a3; s32 a4; u8 pad[8]; W1821B38 b; };
W1821N* func_00109c30();
void func_00109cc0(s32, W1821N*);
extern s32 D_0033cca4;

W1821N* func_00109d00(s32 a0, W1821B38* b, W1821Ctx* c, s32 a3, s32 a4) {
    W1821N* n = func_00109c30();
    s32 m = 4;
    n->a0 = a0;
    n->b = *b;
    n->a3 = a3;
    n->a4 = a4;
    n->ctx = c;
    W1821In* in = c->in;
    if ((in->a ^ 2) == 0) {
        m = 2;
        if (in->b == 1) {
            if (D_0033cca4 == 0) func_00109cc0(0, n);
            else func_00109cc0(1, n);
            D_0033cca4++;
            return n;
        }
    }
    func_00109cc0(m, n);
    return n;
}
}
