#include "../common/types.h"

extern "C" {

/* 002bbe38 / 002bbed0: walk the list at D_01e2aa80 and set a flag on type-2 nodes */
struct w1736_Node { u8 p0[0x1c]; w1736_Node* next; u8 p1[4]; u32 flags; u8 p2[9]; u8 type; };
extern w1736_Node* D_01e2aa80;

static inline w1736_Node* w1736_next(w1736_Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}

void func_002bbe38(void);  // 0x002bbe38: definition moved into src/anon/unit_002bb8b0.cpp

void func_002bbed0(void);  // 0x002bbed0: definition moved into src/anon/unit_002bb8b0.cpp

}
