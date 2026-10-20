#include "../common/types.h"

struct W1746CallArg { void* obj; u32 v4; void* tbl; f32 f; void* sub; };
struct W1746Node { u8 pad[28]; W1746Node* next; u32 pad2; u32 flags; u8 pad3[9]; u8 type; };

extern "C" {
extern u8 D_01d9e8c0[];
extern W1746Node* D_01e2aa80;
void func_0021fa28(W1746CallArg*, s32);

void func_001fb508(u8* o) {
    W1746CallArg a;
    a.obj = o;
    a.v4 = *(u32*)(o + 36);
    a.tbl = D_01d9e8c0;
    a.f = *(f32*)(o + 32);
    a.sub = o + 16;
    func_0021fa28(&a, 0);
}

static inline W1746Node* w1746_next(W1746Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}

void func_002bbf18(void) {
    W1746Node* p = 0;
    while ((p = w1746_next(p)) != 0) {
        if (p->type == 2) p->flags &= ~8;
    }
}
}
