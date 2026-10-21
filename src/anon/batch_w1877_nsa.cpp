#include "../common/types.h"
// VU0 vector/matrix helpers (inline asm: the original uses the VU0 macro library).
#define QCOPY1877(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1877 {
    f32 x, y, z, w;
    QV1877() {}
    QV1877(const QV1877& o) { QCOPY1877(this, &o); }
    QV1877& operator=(const QV1877& o) { if (this != &o) QCOPY1877(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1877 {
    QV1877 r[4];
    QV1877 operator*(const QV1877& v) const {
        QV1877 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Box1877 { u8 pad[0x90]; QV1877 c[8]; u8 pad2[0x290 - 0x110]; u8 box[1]; };

// GS register packets: GIF tag (A+D, 7 regs) then data/address pairs.
struct GsPkt1877 {
    u64 dma[2];
    u64 tag0, tag1;
    u64 frame, frameAddr;
    u64 zbuf, zbufAddr;
    u64 test, testAddr;
    u64 r50, r58;
    u64 texa, texaAddr;
    u64 clamp, clampAddr;
    u64 fogcol, fogcolAddr;
};
extern GsPkt1877 D_01da8bb0;
extern GsPkt1877 D_01da8c40;
extern u64 D_00352c00;
extern u32 D_00352bf4;

extern "C" {
void func_001447e0(void*, QV1877*, QV1877*);

// Transform the 8 box corners in place and compute their min/max.
void func_001605a0(Box1877* self, QM1877* m) {
    QV1877 mn, mx, p;
    for (s32 i = 0; i < 8; i++) {
        self->c[i] = *m * self->c[i];
        p = self->c[i];
        if (i == 0) {
            mn = mx = p;
        } else {
            if (p.x < mn.x) mn.x = p.x; else if (mx.x < p.x) mx.x = p.x;
            if (p.y < mn.y) mn.y = p.y; else if (mx.y < p.y) mx.y = p.y;
            if (p.z < mn.z) mn.z = p.z; else if (mx.z < p.z) mx.z = p.z;
        }
    }
    func_001447e0(self->box, &mn, &mx);
}

void u_call0_0020de30() asm("_Z16u_call0_0020de30v");
void u_call0_0020de30() {
    GsPkt1877* p = &D_01da8bb0;
    p->tag0 = (7ULL << 60) | 0x8001;
    p->tag1 = 0xeeeeeee;
    p->frame = D_00352c00;
    p->frameAddr = 0x4c;
    p->zbuf = (u64)(s32)(D_00352bf4 | 0x31000000) | (1ULL << 32);
    p->zbufAddr = 0x4e;
    p->test = 0x7000d;
    p->testAddr = 0x47;
    p->r50 = 0x21;
    p->r58 = 0x14;
    p->clamp = 0;
    p->clampAddr = 8;
    p->texa = 1ULL << 39;
    p->texaAddr = 0x3b;
    p->fogcol = 0x808080;
    p->fogcolAddr = 0x3d;
    p = &D_01da8c40;
    p->tag0 = (7ULL << 60) | 0x8001;
    p->tag1 = 0xeeeeeee;
    p->frame = D_00352c00;
    p->frameAddr = 0x4c;
    p->zbuf = (u64)(s32)(D_00352bf4 | 0x31000000);
    p->zbufAddr = 0x4e;
    p->test = 0x7000d;
    p->testAddr = 0x47;
    p->r50 = 0x21;
    p->r58 = 0x14;
    p->clamp = 0;
    p->clampAddr = 8;
    p->texa = 1ULL << 39;
    p->texaAddr = 0x3b;
    p->fogcol = 0x808080;
    p->fogcolAddr = 0x3d;
}
}
