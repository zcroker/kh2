#include "../common/types.h"

struct W2027Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct W2027Owner { u8 pad[0x24]; W2027Obj* obj; };
struct W2027Pair { s32 x, y; };
struct W2027Tag { u16 a; u8 b; };

struct W2027Node { u8 pad[0x9c]; W2027Node* next; };
struct W2027List {
    W2027Node* head;
    W2027Node* nx(W2027Node* n) { return !n ? head : n->next; }
};

extern "C" {

/* The two by-value struct parameters are unused, but gcc stores BLKmode
   parameters to their stack slots (sd a1,0 / sw a2,16). */
void func_002bef78(W2027Owner* p, W2027Pair v, W2027Tag w) {
    p->obj->m4();
}

/* Linked-list search: returns 1 when t is in the list at p+0x94. */
u8 func_0017fdc0(u8* p, W2027Node* t) {
    W2027List* l = (W2027List*)(p + 0x94);
    W2027Node* n = 0;
    s32 r;
    while ((n = l->nx(n)) != 0) {
        if (n == t) { r = 1; goto out; }
    }
    r = 0;
out:
    return r;
}

/* func_00253b30 is a (char*, const char*) copy. Declaring it as the strcpy
   builtin gives the original argument order (a0 set before a1). */
char* strcpy(char*, const char*) asm("func_00253b30");
char* func_002b64c8(void);
void func_00170518(char*, s32, s32);
void func_002a7588(void) {
    char buf[128];
    strcpy(buf, func_002b64c8());
    func_00170518(buf, 5102, 0);
}

}
