#include "../common/types.h"

struct W1778Item { u8 pad[0x80]; s32 key; u8 pad2[0x90 - 0x84]; };
struct W1778Tbl { u32 a; s32 n; };
struct W1778Grp { u8 pad[0x800]; W1778Tbl* t; W1778Item* items; };
struct W1778Res { W1778Grp* g; W1778Item* it; };

extern "C" {
W1778Grp* func_001b9bc8(W1778Grp*);

void func_001b3388(W1778Res* r, s32 key) {
    W1778Grp* g = 0;
    while ((g = func_001b9bc8(g)) != 0) {
        if (g->t == 0) continue;
        for (s32 i = 0; i < g->t->n; i++) {
            if (g->items[i].key == key) {
                r->g = g;
                r->it = &g->items[i];
                return;
            }
        }
    }
    r->g = 0;
}
}
