#include "../common/types.h"
// batch w1760 functions that need -fno-strict-aliasing

inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
extern u8* D_01c61b04;
void func_002223e0(void*);

struct W1760Q6 {
    u16 x, y, z;
    W1760Q6(int v) : x(v), y(v), z(v) {}
};
struct W1760C3 {
    u8 r, g, b, a;
    W1760Q6 q;
    W1760C3(int v) : r(v), g(v), b(v), q(v) {}
};

W1760C3* func_00196328(W1760C3* p, s32 i) {
    new (p) W1760C3(0xffff);
    p->r = D_01c61b04[i * 4 + 0];
    p->g = D_01c61b04[i * 4 + 1];
    p->b = D_01c61b04[i * 4 + 2];
    return p;
}

struct W1760S2 { u8 pad[0x6c]; s32 a; u64 b, c, d, e; };
struct W1760S3 { u8 pad[0xc]; s32 a; u8 p2[0x24 - 0x10]; s32 b; u8 p3[4]; s32 c; };

void func_001f4e18(u8* self, u8* t) {
    u8* q = self + **(s32**)(t + 12);
    W1760S2* s = (W1760S2*)(q + 0xa0);
    W1760S3* r = (W1760S3*)(q + 0xb0);
    func_002223e0(s);
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->a = 0;
    r->a = 0;
    r->b = 0;
    r->c = 0;
}
}
