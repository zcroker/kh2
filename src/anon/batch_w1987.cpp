#include "../common/types.h"

// ---- 001ef8e0: pull a node toward another along the normalized offset (VU0 macro normalize, asm)
extern "C" {
struct Body1987 { f32 x, y, z, r; f32 f10, f14, f18; };
struct Nd1987 { u8 pad[160]; Body1987 b; };
struct Te1987 { s32 f0; s32 p; s32 f8, fc; };
struct Mgr1987 { u8 pad[128]; Te1987* tbl; };
struct Ent1987 { s32 f0; s32 idx1; s32 off1; s32 idx2; s32 off2; f32 f14; };
struct Ent21987 { u8 pad[12]; s32* offs; };
struct V41987 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern Mgr1987* D_01d9e6e0;
extern Body1987 D_01d9e360;
f32 func_002f3d70(Body1987*, V41987*);
void func_001ef8e0(u8* base, Ent1987* e, Ent21987* e2)
{
    Body1987* a = &((Nd1987*)(base + e2->offs[0]))->b;
    Body1987* b0;
    Body1987* b1;
    V41987 d;
    f32 len;
    if (e->idx1 != -1) b0 = &((Nd1987*)(D_01d9e6e0->tbl[e->idx1].p + e->off1))->b; else b0 = &D_01d9e360;
    if (e->idx2 != -1) b1 = &((Nd1987*)(D_01d9e6e0->tbl[e->idx2].p + e->off2))->b; else b1 = &D_01d9e360;
    d.x = a->x - b1->x;
    d.y = a->y - b1->y;
    d.z = a->z - b1->z;
    asm volatile("lqc2 $vf10, 0(%1)\n\tvadd.xyz $vf8, $vf0, $vf10\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvmove.xyz $vf9, $vf10\n\t"
                 "vaddx.y $vf9, $vf9, $vf9x\n\tvaddy.z $vf9, $vf9, $vf9y\n\tvsqrt Q, $vf9z\n\tvwaitq\n\t"
                 "vaddq.x $vf10, $vf0, Q\n\tqmfc2 %0, $vf10\n\tvdiv Q, $vf0w, $vf10x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf9, $vf8, Q\n\tsqc2 $vf9, 0(%1)"
                 : "=r"(len) : "r"(&d) : "memory");
    if (len < b0->r) {
        f32 t = func_002f3d70(b0, &d);
        if (b0->f14 < t) {
            Body1987* c = &((Nd1987*)(base + e2->offs[1]))->b;
            f32 k = b0->f18 * ((t - b0->f14) / (1.0f - b0->f14)) * ((b0->r - len) / b0->r) / e->f14;
            c->x += d.x * k;
            c->y += d.y * k;
            c->z += d.z * k;
        }
    }
}
}
