#include "../common/types.h"

struct D18_1792 { u8 pad[0x18]; s32 off18; };
struct O4_1792 { u32 pad; D18_1792* d; };

struct QW1792 {
    f32 x, y, z, w;
    QW1792& operator=(const QW1792& o) {
        /* lq/sq quadword copy */
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj1792 {
    u8 pad[0x590];
    QW1792 pos;      /* 0x590 */
    QW1792 rot;      /* 0x5a0 */
    u8 pad2[0x10];
    QW1792 tgt;      /* 0x5c0 */
    u8 pad3[0x30];
    u64 flags;       /* 0x600 */
};

extern "C" {
void func_0011efe8(void*);
void func_0011f6e8(O4_1792* o, u8* bits, s16* list) {
    D18_1792* d = o->d;
    func_0011efe8(o);
    if (*list != -1) {
        s32* tbl = (s32*)((u8*)d + d->off18);
        s16 v;
        while ((v = *list++) != -1) {
            s16* q = (s16*)((u8*)d + tbl[v & 0x7fff]);
            u8 flag = (v & ~0x7fff) ? 2 : 1;
            for (; *q >= 0; q++) bits[*q] |= flag;
        }
    }
}

extern s8 D_004f3590;
extern f32 D_004f3598;
f32 func_0017ce10(f32);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s32, s32);
void func_00155bf0(u8* p, s32 a)
{
    if (D_004f3590 == 0) {
        D_004f3590 = 1;
        D_004f3598 = 0.00401425688f;
    }
    f32 x;
    if (a == 100) x = 200.0f * D_004f3598;
    else x = (f32)a * D_004f3598;
    x = func_0017ce10(x);
    u_call4_00139d78(p + 12896);
    func_0013edd0(p + 12928, x);
    u_call4_00139d78(p + 12896);
    func_0014b1e0(p + 12928, 50, 100);
}

void func_00185118(Obj1792*, QW1792*);
void func_00143928(QW1792*);
s32 func_0019bfd0(Obj1792* self, QW1792* v)
{
    func_00185118(self, v);
    self->pos = *v;
    self->pos.w = 1.0f;
    /* VU0: store vf0 (0,0,0,1) */
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&self->rot) : "memory");
    self->flags |= 1;
    func_00143928(&self->pos);
    QW1792 d;
    f32 len;
    /* VU0 vector subtract and length */
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&self->tgt), "r"(v), "r"(&d) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(len) : "r"(&d) : "$8", "memory");
    return len < 5.0f;
}
}
