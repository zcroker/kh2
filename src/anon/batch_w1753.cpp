#include "../common/types.h"

struct W1753Pair { u32 a; u32 b; };
struct W1753Sub { u32 w[16]; };
struct W1753S1 { u32 x0; u32 x4; W1753Pair arr[8]; W1753Sub sub; };

extern "C" {
void func_001c0150(W1753Sub*, u32);

void func_0019f8f8(W1753S1* p, u32 v) {
    p->x0 = v;
    p->x4 = 0;
    func_001c0150(&p->sub, v);
    for (int i = 0; i < 8; i++) p->arr[i].b = 0;
}

void func_0019f950(W1753S1* p, u32 v) {
    p->x0 = v;
    p->x4 = 0;
    func_001c0150(&p->sub, v);
    for (int i = 0; i < 8; i++) p->arr[i].b = 0;
}
}
