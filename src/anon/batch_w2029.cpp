#include "../common/types.h"
struct W2029_Q { int a, b; int n; int base; u32* arr; u32 div; };
extern "C" {
extern s32 D_00347ff8;
void func_001dd208(s32);

void func_001db8b8(W2029_Q* q, int v) {
    int n = q->n;
    u32 r = (u32)(v - q->base) / q->div;
    q->arr[n] = r;
    q->n = n + 1;
}

s32 func_0013aa38(s32 a) {
    s32 old = D_00347ff8;
    D_00347ff8 = a;
    if (a == 1) func_001dd208(a); else func_001dd208(0);
    return old;
}
}
