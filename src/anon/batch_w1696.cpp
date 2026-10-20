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
W1696Proj* func_00106a18(s32);
void* func_00106a60(s32);
f32 func_00106f40(W1696Proj*, f32);
void func_00107368(void* cam, W1696Vec*);
void func_00107478(void* cam, W1696Vec*);
f32 W1696_getFov(void) asm("_ZN2dk9ObjCamera6getFovEv");
W1696Player* W1696_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
f32 W1696_getRoll(void* cam) asm("_ZNK2kn6Camera7getRollEv");
f32 W1696_getFOV(const W1696Proj* p, s32 worh) asm("_ZNK2kn10Projection6getFOVENS0_4WorHE");

void func_002319c0(s32 frame) {
    W1696Vec at;
    W1696Vec eye;
    func_00140f78(&eye, &at);
    W1696Proj* proj = func_00106a18(1);
    f32 fov = func_00106f40(proj, W1696_getFov()) * 57.2957763671875f;
    eye.w = 1.0f;
    at.w = 1.0f;
    W1696Mtx m(W1696_GetPlayer()->mtx);
    m.invOrtho();
    eye = m * eye;
    at = m * at;
    for (s32 i = 0; i < 2; i++) {
        D_0035de90[0].key[i].type = D_0035de90[1].key[i].type = D_0035de90[2].key[i].type = D_0035de90[3].key[i].type = D_0035de90[4].key[i].type = D_0035de90[5].key[i].type = D_0035de90[6].key[i].type = D_0035de90[7].key[i].type = 2;
        D_0035de90[0].key[i].tanIn = D_0035de90[1].key[i].tanIn = D_0035de90[2].key[i].tanIn = D_0035de90[4].key[i].tanIn = D_0035de90[3].key[i].tanIn = D_0035de90[5].key[i].tanIn = D_0035de90[6].key[i].tanIn = D_0035de90[7].key[i].tanIn = 0.0f;
    }
    D_0035de90[0].key[1].tanOut = D_0035de90[1].key[1].tanOut = D_0035de90[2].key[1].tanOut =
        D_0035de90[3].key[1].tanOut = D_0035de90[4].key[1].tanOut = D_0035de90[5].key[1].tanOut =
        D_0035de90[6].key[1].tanOut = D_0035de90[7].key[1].tanOut = 0.0f;
    D_0035de90[0].key[0].time = D_0035de90[1].key[0].time = D_0035de90[2].key[0].time =
        D_0035de90[3].key[0].time = D_0035de90[4].key[0].time = D_0035de90[5].key[0].time =
        D_0035de90[6].key[0].time = D_0035de90[7].key[0].time = (frame << 9) / 30;
    D_0035de90[0].key[1].time = D_0035de90[1].key[1].time = D_0035de90[2].key[1].time =
        D_0035de90[3].key[1].time = D_0035de90[4].key[1].time = D_0035de90[5].key[1].time =
        D_0035de90[6].key[1].time = D_0035de90[7].key[1].time = (D_0035de28 << 9) / 30;
    D_0035de90[0].key[1].value = eye.x;
    D_0035de90[1].key[1].value = -eye.y;
    D_0035de90[2].key[1].value = -eye.z;
    D_0035de90[3].key[1].value = at.x;
    D_0035de90[4].key[1].value = -at.y;
    D_0035de90[5].key[1].value = -at.z;
    D_0035de90[6].key[1].value = 0.0f;
    D_0035de90[7].key[1].value = fov;

    void* cam = func_00106a60(1);
    func_00107368(cam, &eye);
    func_00107478(cam, &at);
    eye.w = 1.0f;
    at.w = 1.0f;
    f32 roll = W1696_getRoll(cam);
    *proj = *func_00106a18(1);
    f32 fov2 = func_00106f40(proj, W1696_getFOV(proj, 0)) * 57.2957763671875f;
    eye = m * eye;
    at = m * at;
    D_0035de90[0].key[0].value = eye.x;
    D_0035de90[1].key[0].value = -eye.y;
    D_0035de90[2].key[0].value = -eye.z;
    D_0035de90[3].key[0].value = at.x;
    D_0035de90[4].key[0].value = -at.y;
    D_0035de90[5].key[0].value = -at.z;
    D_0035de90[6].key[0].value = roll * 180.0f / 3.14159274f;
    D_0035de90[7].key[0].value = fov2;
}
}
