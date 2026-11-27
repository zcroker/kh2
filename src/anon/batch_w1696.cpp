#include "../common/types.h"
// Camera-curve setup: builds a two-key track for the eight camera channels
// (eye xyz, target xyz, roll, fov) in the player's local space.
#define W1696_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1696Vec {
    f32 x, y, z, w;
    W1696Vec() {}
    W1696Vec(const W1696Vec& o) { W1696_QCOPY(this, &o); }
    W1696Vec& operator=(const W1696Vec& o) { if (this != &o) W1696_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1696Mtx {
    W1696Vec r0, r1, r2, r3;
    W1696Mtx() {}
    W1696Mtx(const W1696Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1696Mtx& operator=(const W1696Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W1696Vec operator*(const W1696Vec& v) const {
        W1696Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// kn::Projection (256 bytes)
struct W1696Proj {
    W1696Mtx m0;
    f32 f40;
    f32 fov[2];     // indexed by WorH (getFOV)
    f32 size[3];    // 0x4c width, 0x50 height
    f32 f58[3];
    f32 f64, f68, f6c, f70, f74, f78;
    W1696Mtx m80;
    W1696Mtx mC0;
};
struct W1696Key {
    s32 time : 29;
    u32 type : 3;
    f32 value;
    f32 tanIn;
    f32 tanOut;
};
struct W1696Chan { W1696Key key[2]; };
struct W1696Player { u8 pad[0x40]; W1696Mtx mtx; };

extern "C" {
extern W1696Chan D_0035de90[8];
extern s32 D_0035de28;
void func_00140f78(W1696Vec* eye, W1696Vec* at);
W1696Proj* kn__getProjection(s32);
void* func_00106a60(s32);
f32 func_00106f40(W1696Proj*, f32);
void kn__Camera__getPosition(void* cam, W1696Vec*);
void func_00107478(void* cam, W1696Vec*);
f32 W1696_getFov(void) asm("_ZN2dk9ObjCamera6getFovEv");
W1696Player* W1696_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
f32 W1696_getRoll(void* cam) asm("_ZNK2kn6Camera7getRollEv");
f32 W1696_getFOV(const W1696Proj* p, s32 worh) asm("_ZNK2kn10Projection6getFOVENS0_4WorHE");

void sa__EVENT__set_objcamera_event_in(s32 frame);  // 0x002319c0: definition moved into src/anon/unit_00231500.cpp
}
