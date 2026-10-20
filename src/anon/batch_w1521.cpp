#include "../common/types.h"
extern "C" {

void* getSaveRam_w1521(void) asm("_Z10getSaveRamv");
void func_0014ca80(s32, s32, s32, s32, s32);
void func_0014cc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 idx) {
    u8* b = (u8*)getSaveRam_w1521() + 0x2444;
    asm("" : "+r"(b)); /* keeps base+0x2444 apart from the +8 field offset */
    func_0014ca80(((s32*)b)[idx + 2], a0, a1, a2, a3);
}

struct W1521Node { void* vt; u8 pad[0x78]; W1521Node* next; };
struct W1521NodeList { W1521Node* first; W1521Node* cur; };
extern W1521NodeList D_01c6ced0;
extern u8 D_00350c50;
void func_001ac5b8(W1521Node* p) {  // list_unlink_node_2
    W1521Node* prev;
    p->vt = &D_00350c50;
    if (p == D_01c6ced0.first) {
        prev = 0;
        D_01c6ced0.first = p->next;
    } else {
        W1521Node* q; W1521Node* n;
        prev = D_01c6ced0.first;
        q = prev->next;
        if (q != p) {
            do { n = q->next; prev = q; q = n; } while (n != p);
        }
        prev->next = p->next;
    }
    if (p == D_01c6ced0.cur) D_01c6ced0.cur = prev;
    p->next = 0;
}

s32 func_00287bc0(void);
void func_00276c50(s32, s32);
void func_0029ea30(void) {
    s32 v;
    switch (func_00287bc0()) {
    case 14: v = 0x48ee; break;
    case 15: v = 0x48ef; break;
    case 18: v = 0x48f0; break;
    default: v = 0x48f3; break;
    case 21: v = 0x48f1; break;
    case 16: case 19: case 22: v = 0x48f2; break;
    }
    func_00276c50(v, 0);
}

u32 func_001024a8(...);
struct W1521Pos { s32 x, y; W1521Pos(s32 a, s32 b) : x(a), y(b) {} };
struct W1521Col { u8 r, g, b, a; W1521Col(s32 a0, s32 a1, s32 a2, s32 a3) : r(a0), g(a1), b(a2), a(a3) {} };
struct W1521Holder { s32 a, b; u8 sub[4]; };
void func_002ee040(void*);
void func_002ee0b0(void*, W1521Pos, W1521Col);
extern W1521Holder* D_003617fc;
void func_002be428(void* a0) {
    if (D_003617fc == 0) {
        func_001024a8(a0);
        return;
    }
    func_002ee040(D_003617fc->sub);
    func_002ee0b0(D_003617fc->sub, W1521Pos(0, 0), W1521Col(128, 128, 128, 128));
}

}
