#include "../common/types.h"
struct W1624Mat {
    f32 m[4][4];
    W1624Mat() {}
    W1624Mat& operator=(const W1624Mat& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1624Vec {
    f32 x, y, z, w;
    W1624Vec() {}
    W1624Vec(const W1624Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1624Ft4 {
    u8 _pad0[4];
    u16 w;          /* 0x04 */
    u16 h;          /* 0x06 */
    s16 ofsX;       /* 0x08 */
    s16 ofsY;       /* 0x0a */
    u32 z;          /* 0x0c */
    u8 _pad10[0xd8 - 0x10];
    u64 xyz0;       /* 0xd8 */
    u64 _pad0e0;
    u64 xyz1;       /* 0xe8 */
    u64 _pad0f0;
    u64 xyz2;       /* 0xf8 */
    u64 _pad100;
    u64 xyz3;       /* 0x108 */
    f32 rot;        /* 0x110 */
    s32 cx;         /* 0x114 */
    s32 cy;         /* 0x118 */
};
#define W1624_GS_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
extern "C" {
void func_0011b6a8(W1624Mat*);
void func_002f40a0(f32, W1624Mat*, W1624Mat*);
void func_0013ea50(W1624Ft4*, W1624Mat*, W1624Vec, s32*, s32*);
void func_0013eb00(W1624Ft4* p)
{
    s32 left = p->cx - (p->w >> 1);
    s32 top = p->cy - (p->h >> 1);
    s32 right = p->cx + (p->w >> 1);
    s32 bottom = p->cy + (p->h >> 1);
    W1624Mat m;
    W1624Vec v;
    W1624Mat mc;
    s32 x, y;
    func_0011b6a8(&m);
    func_002f40a0(p->rot, &m, &m);
    v.x = left; v.y = top;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz0 = W1624_GS_XYZ(x, y, p->z);
    v.x = right; v.y = top;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz1 = W1624_GS_XYZ(x, y, p->z);
    v.x = left; v.y = bottom;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz2 = W1624_GS_XYZ(x, y, p->z);
    v.x = right; v.y = bottom;
    mc = m;
    func_0013ea50(p, &mc, v, &x, &y);
    p->xyz3 = W1624_GS_XYZ(x, y, p->z);
}
}
