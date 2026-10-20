#include "../common/types.h"

struct Node1762 { Node1762* next; s32 a; s32 b; u8* p; f32 x; f32 y; s32 c; };
struct List1762 { Node1762* head; Node1762* tail; };
extern List1762 D_01e2bf00;

typedef struct Key1762 { s32 a; s32 b; } Key1762;
typedef struct E1762 { s32 x; s32 a; s32 b; u8 pad[24]; } E1762;
typedef struct T1762 { u8 pad[12]; s32 n; E1762* e; } T1762;

extern "C" {
void func_002e73a8(Node1762*);

void func_002e7340(Node1762* n, s32 a, s32 b, u8* p, f32 x, f32 y) {
    n->a = a;
    n->p = p + 1;
    n->b = b - 1;
    n->x = x;
    n->y = y;
    n->c = *p;
    if (D_01e2bf00.tail == 0) {
        D_01e2bf00.tail = n;
        D_01e2bf00.head = n;
        n->next = 0;
    } else {
        D_01e2bf00.tail->next = n;
        n->next = 0;
        D_01e2bf00.tail = n;
    }
    func_002e73a8(n);
}

E1762* func_001144e8(T1762* p, Key1762 k) {
    s32 i;
    if (p->e == 0) return 0;
    for (i = 0; i < p->n; i++) {
        E1762* e = &p->e[i];
        if (e->a == k.a && (e->b == k.b || e->a == 0)) return e;
    }
    return 0;
}
}
