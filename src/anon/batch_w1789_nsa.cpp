#include "../common/types.h"

struct W1789Ctx { u32 v; };
struct W1789Node { u8 pad[0x24]; W1789Node* next; };
struct W1789List { u8 pad[0xc]; W1789Node* head; u8 pad2[0x30 - 0x10]; W1789Ctx ctx; s32 count; };
struct W1789Vec { u8 b[16]; };
struct W1789Obj { u8 pad[0x7f8]; u32 flags; u8 pad2[0xb70 - 0x7fc]; s32 state; };

extern "C" {
s32 func_001c18d0(W1789Node*);
void func_001c1a30(W1789Node*, W1789Ctx*);
void func_001c1890(W1789Node*);
void func_001c16a0(W1789List*, s32);

void func_001c1428(W1789List* l) {
    W1789Node* n = l->head;
    W1789Ctx c = l->ctx;
    W1789Node* it = n;
    l->count = 0;
    while (n) {
        W1789Node* next = !it ? l->head : it->next;
        it = next;
        if (func_001c18d0(n)) { func_001c1a30(n, &c); l->count++; }
        else if (n) func_001c1890(n);
        n = next;
    }
    func_001c16a0(l, l->count);
}

void func_0016af58(W1789Vec*, W1789Obj*);
void func_0017d538(W1789Vec*, W1789Vec*, f32);
void func_0016aef0(W1789Obj*, W1789Vec*);
void func_001788b8(W1789Obj*);

void func_001ceef8(W1789Obj* p) {
    if (p->flags & 4) return;
    s32 s = p->state;
    if (s != 0) {
        switch (s) {
        case 1: { W1789Vec b; W1789Vec a; func_0016af58(&a, p); func_0017d538(&b, &a, -1.57079637f); func_0016aef0(p, &b); } break;
        case 2: { W1789Vec b; W1789Vec a; func_0016af58(&a, p); func_0017d538(&b, &a, 1.57079637f); func_0016aef0(p, &b); } break;
        }
        p->state = 0;
    }
    func_001788b8(p);
}
}
