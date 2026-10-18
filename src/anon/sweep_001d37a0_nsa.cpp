#include "../common/types.h"
extern "C" {
struct Node { u32 pos[4]; u32 f10, f14; f32 f18, f1c, f20; u32 f24; f32 f28, f2c; Node* next; };
struct NodeList { Node* head; Node* tail; };
extern NodeList D_01d5ba20;
void func_001d37a0(Node* n, u32* pos, f32 f)
{
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(n), "r"(pos) : "$8", "memory");
    n->f10 = 0; n->f14 = 0; n->f18 = f; n->f1c = f; n->f20 = f; n->f24 = 0; n->f28 = 100.0f; n->f2c = 0.01f;
    if (!D_01d5ba20.tail) {
        D_01d5ba20.tail = n;
        D_01d5ba20.head = n;
        n->next = 0;
    } else {
        D_01d5ba20.tail->next = n;
        n->next = 0;
        D_01d5ba20.tail = n;
    }
}
}
