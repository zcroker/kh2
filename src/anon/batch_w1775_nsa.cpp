#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1775Q { u128 q; W1775Q& operator=(const W1775Q& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
struct W1775B { s32 a; f32 y; f32 z; s32 w; W1775B& operator=(const W1775B& o) { a = o.a; y = o.y; z = o.z; w = o.w; return *this; } } __attribute__((aligned(16)));
struct W1775Ent { s32 id; W1775B b; W1775Q v; };
struct W1775List { s32 n; u8 pad[0xc]; W1775Ent e[256]; };
extern "C" {
void func_0018eb98(W1775List*, W1775Ent*);
s32 func_0018eaf8(W1775List* l, W1775Ent* e) {
    func_0018eb98(l, e);
    if (l->n >= 256) return 0;
    l->e[l->n++] = *e;
    return 1;
}
}
