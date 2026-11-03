// 002bbf98: walks the active list, moves state-4 nodes to a kill list, then unlinks them and returns them to the pool.
#include "../common/types.h"
extern "C" {
struct LNode { u8 pad[0x1c]; LNode* next; LNode* next2; u8 pad24[0xc]; u8 state; u8 pad31[0xf]; };
struct LList { LNode* head; LNode* tail; };
struct LPool { LNode nodes[64]; s32 free[64]; s32 count; };
extern LList D_01e2aa80;
extern LList D_01e2aa88;
extern LPool D_01e2aa90;
extern s32 D_003616f4;
void func_002bbd58(LNode*);
static inline LNode* nextA(LNode* n) { return !n ? D_01e2aa80.head : n->next; }
static inline LNode* nextB(LNode* n) { return !n ? D_01e2aa88.head : n->next2; }



void func_002bbf98(void) {
    LNode* n = 0;
    while ((n = nextA(n)) != 0) {
        func_002bbd58(n);
        if (n->state == 4) {
            if (!D_01e2aa88.tail) {
                D_01e2aa88.tail = n;
                D_01e2aa88.head = n;
                n->next2 = 0;
            } else {
                D_01e2aa88.tail->next2 = n;
                n->next2 = 0;
                D_01e2aa88.tail = n;
            }
        }
    }
    while ((n = nextB(n)) != 0) {
        LNode* p = D_01e2aa80.head;
        LNode* prev;
        if (n == p) {
            prev = 0;
            D_01e2aa80.head = n->next;
        } else {
            prev = p;
            LNode* h = p->next;
            LNode* c = h;
            p = h;
            while (p != n) { p = c->next; prev = c; c = p; }
            prev->next = n->next;
        }
        if (n == D_01e2aa80.tail) D_01e2aa80.tail = prev;
        n->next = 0;
        D_01e2aa90.free[D_01e2aa90.count++] = n - D_01e2aa90.nodes;
    }
    LList* l = &D_01e2aa88;
    l->head = 0;
    l->tail = 0;
    D_003616f4 = 0;
}
}
