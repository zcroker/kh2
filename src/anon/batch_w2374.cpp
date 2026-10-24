#include "../common/types.h"

// Intrusive singly linked list: the removal walks a generic link type, the owner loop uses the object type
// (different alias sets keep gcse from reusing the cached next pointer after the search loop).
struct W2374Link { void* vt; W2374Link* next; };
struct W2374Obj;
typedef void (*W2374Fn)(W2374Obj*);
struct W2374Obj { W2374Fn* vt; W2374Obj* next; s32 pad8; u32 flags; s32 pad10; s32 id; };
struct W2374List {
    W2374Link* head;
    W2374Link* tail;
    __attribute__((always_inline)) void Remove(W2374Link* n) {
        W2374Link* prev;
        if (n == head) {
            head = n->next;
            prev = 0;
        } else {
            prev = head;
            while (prev->next != n) prev = prev->next;
            prev->next = n->next;
        }
        if (n == tail) tail = prev;
        n->next = 0;
    }
};
// h shares the link pointer type, so its load stays after the n->next = 0 store.
struct W2374Owner { W2374Link* h; W2374List list; };

extern "C" {
void func_00102670(W2374Link*, s32);
}

// 001393f8: destroy every object in the owner's list that has flag bit 0 set.
void func_001393f8(int a)
{
    W2374Owner* o = (W2374Owner*)a;
    W2374Obj* n = (W2374Obj*)o->list.head;
    while (n) {
        W2374Obj* next = n->next;
        s32 m = n->flags & 1;
        if (m) {
            o->list.Remove((W2374Link*)n);
            func_00102670(o->h, n->id);
            (*n->vt[0])(n);
        }
        n = next;
    }
}
