#include "../common/types.h"

extern "C" {

struct Slot_1bfd60 { int id; int pad[3]; };

Slot_1bfd60* func_001bfd60(Slot_1bfd60* p, int v);  // 0x001bfd60: definition moved into src/anon/unit_001bc568.cpp

struct Node_18f070 { u8 pad[0xc0]; Node_18f070* next; };
extern Node_18f070* D_01c60cd8;

static inline Node_18f070* next_18f070(Node_18f070* p) {
    if (p == 0) return D_01c60cd8;
    return p->next;
}

int YS__ATTACK__is_exist(Node_18f070* a);  // 0x0018f070: definition moved into src/anon/unit_0018d050.cpp

}
