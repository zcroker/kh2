#include "../common/types.h"

struct S24_w1796 { u8 pad[28]; s8 a[4]; s8 b[4]; };
struct Item_w1796 { u8 d[48]; };
struct Node_w1796 {
    Node_w1796* head; s32 pad4; Node_w1796* next; Node_w1796* prev;
    u8 pad10[0x24];
    u16 start2; u16 pad36; u16 cnt2; u16 pad3a; u16 cnt; u16 flags;
    Item_w1796 items[1];
};

extern "C" {
s32 func_001a6d08(s32);
extern S24_w1796 D_00371f30;
void func_00220088(Item_w1796*, u16);

s32 func_0024ac88(void) {
    s32 r = 1;
    s32 i;
    S24_w1796* d = &D_00371f30;
    s8* p = d->a;
    for (i = 0; i < 4; i++) {
        s32 c = *p++;
        if (c < 0) break;
        if (!func_001a6d08(c)) { r = 0; break; }
    }
    if (r) {
        for (i = 0; i < 4; i++) {
            s32 c = D_00371f30.b[i];
            if (c < 0) break;
            if (func_001a6d08(c)) { r = 0; break; }
        }
    }
    return r;
}

void func_00221ed0(Node_w1796* n) {
    u16 f = n->flags & 0x20;
    Item_w1796* it = n->items;
    s32 i = n->cnt;
    while (i > 0) { func_00220088(it, f); it++; i--; }
    it = &n->items[n->start2];
    i = n->cnt2;
    while (i > 0) { func_00220088(it, f); it++; i--; }
    if (n->prev) {
        if (n->next) n->next->prev = n->prev;
        n->prev->head = n->next;
    }
}
}
