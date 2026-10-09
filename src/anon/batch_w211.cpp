#include "../common/types.h"

struct W211Node { W211Node* n0; W211Node* next; };
struct W211List { u32 a; u32 b; W211Node* head; };
struct W211Q { f32 a; f32 b; };
struct W211S28 { u8 p[4]; s16 n; u8 q[0x22]; u32* tbl; };
struct W211H { u8 c0, c1, c2, c3; f32 f; u32 z; u32 nx; };

extern "C" {
extern W211Q D_00359110;

void func_0011eea8(W211List* l, W211Node* x) {
    W211Node* h = l->head;
    if (h == x) { l->head = x->next; return; }
    W211Node* c = h->next; W211Node* p = h;
    if (c == 0) goto out;
    if (c == x) goto out;
    do { W211Node* n = c->next; p = c; c = n; if (!n) break; } while (c != x);
out:
    p->next = x->next;
}

void func_001e1df8(u8* p) {
    if (20.0f <= *(f32*)(p + 0xde4)) {
        *(u32*)(p + 0xde8) = 0;
        *(u32*)(p + 0xdfc) = 0;
        *(f32*)(p + 0xde4) = 0;
        *(f32*)(p + 0xdf4) = 10.0f;
        *(u32*)(p + 0xdc0) = 4;
        *(f32*)(p + 0xdf8) = 10.0f;
    }
}

void wtarget_0020e9f8(f32 a, f32 b) asm("_Z16wtarget_0020e9f8jjjj");
void wtarget_0020e9f8(f32 a, f32 b) {
    f32 x = b * 255.0f;
    b = b - a;
    D_00359110.a = -255.0f / b;
    D_00359110.b = x / b;
}

s32 func_0028b160(W211S28* s, u32 key) {
    s32 i = 0;
    s32 n = s->n;
    if (n > 0) {
        u32* p = s->tbl;
        do {
            if (key == *p) break;
            p++;
            i++;
        } while (i < n);
    }
    return i < s->n ? i : -1;
}

void func_0031e268(W211H* h) {
    h = (W211H*)((u8*)h + 4);
    s32 i = 7;
    do {
        *(u32*)((u8*)h - 4) = 0;
        u32 k = 128; h->c0 = k; h->c1 = k; h->c2 = k; h->c3 = k;
        h->f = 1.0f; h->z = 0; h++; i--;
    } while (i != -1);
}
}
