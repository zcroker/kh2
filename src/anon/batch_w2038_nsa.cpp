// Built with -fno-strict-aliasing (see Makefile *_nsa rule).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
struct BPkt { u32 a, b; u128* p; };
struct BObj {
    u8 pad0[4];
    u16 w, h;
    s16 x, y;
    u32 z;
    u8 r, g, b, a;
    u8 pad14[0xc];
    u128 q20[13];
    u8 padf0[0x10];
    u128 q100[2];
    u128 q120[2];
    s16 sx, sy;
    u16 sw, sh;
};
extern "C" {
void func_001b7e68(BPkt*, s32);
void func_001b80d8(BPkt*);
void func_001b7f30(BPkt*);

void func_0014bb30(BObj* o) {
    BPkt k1, k2, k3;
    s32 i;
    *(u64*)((u8*)o + 0x110) = (u64)(s16)o->sx | ((u64)(o->sx + o->sw - 1) << 16) | ((u64)o->sy << 32) | ((u64)(o->sy + o->sh - 1) << 48);
    *(u64*)((u8*)o + 0xc8) = (u64)o->r | ((u64)o->g << 8) | ((u64)o->b << 16) | ((u64)o->a << 24) | (1ULL << 32);
    u64 z = (u64)o->z << 32;
    *(u64*)((u8*)o + 0xd8) = (u64)(o->x * 16 + 0x7000) | ((u64)(o->y * 16 + 0x7300) << 16) | z;
    *(u64*)((u8*)o + 0xe8) = (u64)((o->x + o->w) * 16 + 0x7000) | ((u64)((o->y + o->h) * 16 + 0x7300) << 16) | z;
    {
        k1.p = 0; k1.b = 0; k1.a = 0;
        func_001b7e68(&k1, 32);
        BPkt* q = &k1;
        u128* s = o->q100;
        s32 j;
        for (j = 1; j >= 0; j--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k1);
    }
    {
        k2.p = 0; k2.b = 0; k2.a = 0;
        func_001b7e68(&k2, 0xd0);
        BPkt* q = &k2;
        u128* s = o->q20;
        for (i = 12; i >= 0; i--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k2);
    }
    {
        k3.p = 0; k3.b = 0; k3.a = 0;
        func_001b7e68(&k3, 32);
        BPkt* q = &k3;
        u128* s = o->q120;
        s32 j;
        for (j = 1; j >= 0; j--) {
            *q->p = *s++;
            q->p++;
        }
        func_001b80d8(&k3);
    }
    func_001b7f30(&k3);
    func_001b7f30(&k2);
    func_001b7f30(&k1);
}
}
