#include "../common/types.h"
extern "C" {
struct W1779Node {
    u8 m0; u8 p1[3];
    s32 m4, m8, mc;
    u8 m10; u8 p11[3];
    f32 m14;
    s32 m18;
    f32 m1c, m20, m24;
    u8 p28[0x80 - 0x28];
    s32 m80;
    u8 m84, m85, m86, m87;
    s32 m88, m8c, m90;
    W1779Node* next;
};
struct W1779List { W1779Node* head; W1779Node* tail; };
extern W1779List D_01e2be18;
void func_002cb5d8(W1779Node* p, f32 f) {
    p->m0 = 0; p->m4 = 0; p->m8 = 0; p->mc = 0; p->m10 = 0;
    p->m14 = f; p->m18 = 0;
    p->m1c = -2.0f; p->m20 = 0.5f; p->m24 = 20.0f;
    p->m80 = 0; p->m84 = 1; p->m85 = 0; p->m87 = 0;
    p->m88 = 0; p->m8c = -1; p->m90 = 0;
    if (D_01e2be18.tail == 0) {
        D_01e2be18.tail = p;
        D_01e2be18.head = p;
        p->next = 0;
    } else {
        D_01e2be18.tail->next = p;
        p->next = 0;
        D_01e2be18.tail = p;
    }
}

struct W1779V4 {
    f32 x, y, z, w;
    W1779V4() {}
    W1779V4(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W1779V4& operator=(const W1779V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1779Obj { u8 pad[0x7c]; s32 m7c; u8 p80[4]; u8 m84; u8 p85[0xd0 - 0x85]; W1779V4 md0; W1779V4 me0; };
void func_002e0fa0(W1779Obj*, s32);
void func_002e1020(W1779Obj* p) {
    p->m7c = 100;
    p->m84 = 0;
    p->md0 = W1779V4(80.0f, 155.0f, 0.0f, 0.0f);
    p->me0 = W1779V4(100.0f, 85.0f, 0.0f, 0.0f);
    func_002e0fa0(p, 0);
}
}
