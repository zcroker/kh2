// 00164578: recursive bounding-box query step. res==0 keeps flag bit 34 by re-storing it through a bool (a plain self-assign folds away).
#include "../common/types.h"
extern "C" {
struct W3909V {
    f32 x, y, z, w;
    W3909V() {}
    W3909V(const W3909V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W3909V& operator=(const W3909V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W3909Box { u8 d[0x20]; };
struct W3909Node { u8 pad[0x30]; W3909V v; u8 pad2[0x30]; u64 lo:34; u64 f:1; u64 hi:29;
    void setF(u32 x) { f = x; }
    u32 getF() { return f; }
};
void func_00144490(W3909Box*, f32, f32, f32, f32, f32, f32);
s32 func_00163898(void*, u16, W3909V*, W3909Box*, W3909V*, W3909Node*);
void func_00164578(void* ctx, W3909Node* n, W3909V* v, u16 k, s32* cnt, W3909V t, f32 r) {
    W3909Box b;
    (*cnt)++;
    func_00144490(&b, v->x - r, v->y - r, v->z - r, v->x + r, v->y + r, v->z + r);
    s32 res = func_00163898(ctx, k, v, &b, &n->v, n);
    if (res != -1) {
        if (res == 0) { n->v = *v; bool x = n->f; n->setF(x); }
        else { if (*cnt >= 6) return; *v = n->v; func_00164578(ctx, n, v, k, cnt, t, r); n->setF(1); }
    } else { n->v = t; n->setF(1); }
}

}
