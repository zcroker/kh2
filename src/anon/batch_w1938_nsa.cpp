#include "../common/types.h"
struct W1938Info { u8 a; u8 b; u8 c[6]; s16 d; };
struct W1938Slot { s32 x0; s32 x4; s32 x8; u8 pad[0x1b0 - 12]; u32 flags; W1938Info info; u8 pad2[2]; };
struct W1938Mgr { W1938Slot slots[8]; s32 max; };
struct W1938Entry { u8 id; u8 type; u8 slot; u8 pad; };
struct W1938List { s32 x0; s32 count; W1938Entry e[1]; };
extern "C" {
W1938List* func_002f1888(void);
s32 func_00196430(u8);
W1938Info func_00196328(u8);
s32 func_0019f880(u8, s32);
s32 func_002f18c8(W1938Entry*);
s32 func_001964d8(u8);
s32 func_002cb200(W1938Mgr* m, s32 type, s32* out) {
    s32 n;
    s32 i;
    W1938List* l = func_002f1888();
    n = 0;
    m->max = 0;
    for (i = 0; i < l->count; i++) {
        W1938Entry* e = &l->e[i];
        if (e->type == type) {
            s32 r = func_00196430(e->id);
            if (r) {
                if (m->max < e->slot) m->max = e->slot;
                W1938Slot* s = &m->slots[e->slot - 1];
                W1938Slot* t = &m->slots[e->slot];
                t[-1].flags |= 2;
                t[-1].info = func_00196328(e->id);
                t[-1].x0 = func_0019f880(s->info.b, type);
                s->x8 = func_002f18c8(e);
                if (r == 2) {
                    t[-1].flags |= 1;
                    s->x4 = func_001964d8(e->id);
                }
                n++;
            }
        }
    }
    *out = m->max;
    return n;
}
}
