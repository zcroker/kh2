#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct W1530_C3 { u8 a, b, c; W1530_C3(u32 x, u32 y, u32 z) { a = x; b = y; c = z; } };
struct W1530_S3 { u16 a; s16 b; s16 c; W1530_S3(u32 x, s32 y, s32 z) { a = x; b = y; c = z; } };
struct W1530_C {
    s32 x0, x4; u32 x8; s32 xc, x10, x14, x18, x1c;
    u8 pad20[0xe]; union { s16 x2e; u8 x2e_c; }; union { u8 x30; u8 x30_c; }; u8 pad31[3]; u8 x34[4];
    u8 x38[3]; u8 pad3b; u16 x3c; s16 x3e; s16 x40; u8 pad42[0x12]; u8 x54[4];
};
extern "C" {
void func_0031cc28(void*);
void func_0019ef70(void*);
void func_00198dc0(W1530_C* p) {  // obj_reset_fields
    s32 m = -1;
    u32 f = 0xffff;
    p->x0 = m;
    p->x4 = m;
    p->x8 = f;
    p->xc = m;
    p->x10 = 0;
    p->x14 = m;
    p->x18 = 0;
    p->x1c = 0;
    p->x2e = 0;
    p->x30 = 0;
    new (p->x38) W1530_C3(f, m, m);
    new (&p->x3c) W1530_S3(f, m, m);
    void* q = p->x34;
    func_0031cc28(p->x54);
    func_0019ef70(q);
}
}
