/* Built with -fno-strict-aliasing (_nsa).
   Static GS/DMA packet setup: GIF tags and GS register blocks, two DMA tags with a VIF DIRECT code.
   D_00352bf4 is read through a local pointer: the load then counts as possibly aliasing the stack
   slot of vif, which gives sched2 the original lw/lui order. */
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;

typedef struct { u16 qwc; u8 mark; u8 id; u32 next; u32 p[2]; } DmaTag;

extern u64 D_0032afc0[8];
extern u64 D_0032b000[6];
extern u64 D_0032b040[6];
extern u64 D_0032b080[6];
extern DmaTag D_0032b0d0;
extern u64 D_0032b7c0[8];
extern u64 D_0032b800[6];
extern u64 D_0032b840[6];
extern u64 D_0032b880[6];
extern f32 D_0032b8c0[4];
extern DmaTag D_0032b8e0;
extern f32 D_00359110[4];
extern s32 D_00352bf4;
extern u64 D_01da9010[];
extern u64 D_01daa930[];
Q128* func_0021c810(Q128* p, s32 a, s32 b);
Q128* func_0021c8c8(Q128* p, s32 a, s32 b);
void func_003058a0(s32);


void func_0021c9b0(void) {
    s32* zbp = &D_00352bf4;
    u32 vif;
    DmaTag* t;
    u64* p;
    Q128* q;

    p = D_0032afc0;
    p[0] = 0x702b400000000001ULL;
    p[1] = 0x042412e6;
    p[2] = 0x702b400000008001ULL;
    p[3] = 0x042412e6;
    p[4] = 0xe02a400000000001ULL;
    p[5] = 0x00412412412412e6ULL;
    p[6] = 0xe02a400000008001ULL;
    p[7] = 0x00412412412412e6ULL;
    p = D_0032b000;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    vif = 0x51000000;
    vif |= 2;
    p = D_0032b040;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x3000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b080;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (0ULL << 32);
    p[5] = 0x4e;
    t = &D_0032b0d0;
    t->id = 0x30;
    t->next = (u32)D_01da9010;
    t->qwc = 374;
    t->p[0] = 0;
    t->p[1] = vif;
    p = D_01da9010;
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 5;
    p[3] = 8;
    p += 4;
    q = func_0021c810((Q128*)p, 0, 0);
    q = func_0021c810(q, 1, 0);
    q = func_0021c8c8(q, 0, 0);
    q = func_0021c8c8(q, 1, 0);

    p = D_0032b7c0;
    p[0] = 0x703b400000000001ULL;
    p[1] = 0x042412e6;
    p[2] = 0x703b400000008001ULL;
    p[3] = 0x042412e6;
    p[4] = 0xe03a400000000001ULL;
    p[5] = 0x00412412412412e6ULL;
    p[6] = 0xe03a400000008001ULL;
    p[7] = 0x00412412412412e6ULL;
    p = D_0032b800;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b840;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x3000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b880;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (0ULL << 32);
    p[5] = 0x4e;
    p = (u64*)D_0032b8c0;
    ((f32*)p)[0] = D_00359110[0];
    ((f32*)p)[1] = D_00359110[1];
    ((f32*)p)[2] = D_00359110[2];
    ((f32*)p)[3] = D_00359110[3];
    D_0032b8e0.qwc = 374;
    D_0032b8e0.id = 0x30;
    D_0032b8e0.next = (u32)D_01daa930;
    D_0032b8e0.p[0] = 0;
    D_0032b8e0.p[1] = vif;
    p = D_01daa930;
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 5;
    p[3] = 8;
    p += 4;
    q = func_0021c810((Q128*)p, 0, 1);
    q = func_0021c810(q, 1, 1);
    q = func_0021c8c8(q, 0, 1);
    q = func_0021c8c8(q, 1, 1);
    func_003058a0(0);
}
