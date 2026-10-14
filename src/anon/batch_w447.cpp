#include "../common/types.h"
extern "C" {
struct W447E1a1 { u8 p0[600]; s32 cnt; u8 p604[8]; s32 key; };
struct W447P1a1 { W447E1a1 e[64]; s32 freel[64]; s32 nfree; };
extern W447P1a1 D_01c62fb8;
s32 func_001db5a8(u32);
W447E1a1* func_001a1018(u32);
static inline __attribute__((always_inline)) W447E1a1* w447_next1a1(W447E1a1* p)
{
    W447E1a1* q = D_01c62fb8.e;
    if (p) q = p + 1;
    while (q < D_01c62fb8.e + 64) {
        s32 idx = q - D_01c62fb8.e;
        s32 i;
        for (i = 0; i < D_01c62fb8.nfree; i++) {
            if (D_01c62fb8.freel[i] == idx) { q++; break; }
        }
        if (i == D_01c62fb8.nfree) return q;
    }
    return 0;
}
W447E1a1* func_001a1060(u32 a0)
{
    W447E1a1* p = 0;
    s32 v;
    v = func_001db5a8(a0);
    while ((p = w447_next1a1(p)) != 0) {
        if (p->key == v) {
            p->cnt++;
            return p;
        }
    }
    return func_001a1018(a0);
}
}
