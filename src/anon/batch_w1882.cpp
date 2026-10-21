#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q1882V4 {
    f32 x, y, z, w;
    Q1882V4() {}
    Q1882V4& operator=(const Q1882V4& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Q1882Obj { Q1882V4 pos; u8 pad[48]; Q1882V4 vel; u8 b80; u8 pad2[3]; void* fn; };
struct Q1882Ent { Q1882Obj* p; u32 flags; u32 pad; };
extern "C" {
extern s32 D_00351600;
extern Q1882V4 D_00352a60;
extern Q1882Ent D_01d49658[];
s32 func_001c4170(void);
void func_001c4ff0(void);
void func_001c42c0(void) {
    s32 i;
    u32* fb = &D_01d49658[0].flags;
    for (i = 0; i < D_00351600; i++) {
        f32 k = 20.0f;
        u32* fp = fb + i * 3;
        u32 f = *fp;
        if ((f & 1) == 1) continue;
        *fp = f | 1;
        Q1882Obj* o = *(Q1882Obj**)(fp - 1);
        if (func_001c4170() > 100) {
            o->b80 = 0;
            asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&o->vel) : "memory");
        } else {
            o->b80 = 10;
            Q1882V4* d = &o->vel;
            Q1882V4 t;
            asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(&D_00352a60), "r"(&o->pos) : "memory");
            *d = t;
            o->vel.y += -1000.0f;
            f32 len;
            asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                : "=f"(len) : "r"(d) : "$8", "memory");
            asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(d), "f"(k) : "$8", "memory");
        }
        o->fn = (void*)func_001c4ff0;
        return;
    }
}

}
