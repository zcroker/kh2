#include "../common/types.h"

extern "C" {

struct Slot_1bfd60 { int id; int pad[3]; };

Slot_1bfd60* func_001bfd60(Slot_1bfd60* p, int v) {
    Slot_1bfd60* empty = 0;
    for (int i = 0; i < 8; i++) {
        if (p[i].id == v) return &p[i];
        if (p[i].id == 0) empty = &p[i];
    }
    empty->id = v;
    return empty;
}

struct Node_18f070 { u8 pad[0xc0]; Node_18f070* next; };
extern Node_18f070* D_01c60cd8;

static inline Node_18f070* next_18f070(Node_18f070* p) {
    if (p == 0) return D_01c60cd8;
    return p->next;
}

int func_0018f070(Node_18f070* a) {
    if (!a) return 0;
    Node_18f070* p = 0;
    while ((p = next_18f070(p)) != 0)
        if (p == a) return 1;
    return 0;
}

}
