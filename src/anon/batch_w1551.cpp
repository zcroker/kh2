#include "../common/types.h"

extern "C" {
extern u8 D_00361a60[];
extern u8 D_00361da8[];
void func_00105110(void*);
}

struct E324a30 { u8 pad[16]; ~E324a30() {} } __attribute__((aligned(16)));
struct B324a30 { u32 vt; ~B324a30() { vt = (u32)D_00361da8; } };
struct O324a30 : B324a30 {
    u8 pad[0x6c];
    E324a30 a[4];
    E324a30 b[2];
    ~O324a30() { vt = (u32)D_00361a60; }
};

extern "C" {

struct N2cb678 { u8 pad[0x80]; void* buf; u8 pad2[0x10]; N2cb678* next; };
struct L2cb678 { N2cb678* head; N2cb678* tail; };
extern L2cb678 D_01e2be18;

// Unlink a node from the global list and free its buffer.
void func_002cb678(N2cb678* n) {
    func_00105110(n->buf);
    N2cb678* prev;
    if (n == D_01e2be18.head) {
        D_01e2be18.head = n->next;
        prev = 0;
    } else {
        prev = D_01e2be18.head;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_01e2be18.tail) D_01e2be18.tail = prev;
    n->next = 0;
}

// Deleting destructor.
void func_00324a30(O324a30* p) {
    p->~O324a30();
    func_00105110(p);
}

}
