#include "../common/types.h"
// w2459: matched func_00231500 (hoisted D_0035de90 high part via an always_inline call wrapper).
// Camera event playback: evaluate the active camera key tracks for the current frame.
#define W1695_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1695Vec {
    f32 x, y, z, w;
    W1695Vec() {}
    W1695Vec(const W1695Vec& o) { W1695_QCOPY(this, &o); }
    W1695Vec& operator=(const W1695Vec& o) { if (this != &o) W1695_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1695Mtx {
    W1695Vec r0, r1, r2, r3;
    // VU0 matrix * column vector.
    W1695Vec operator*(const W1695Vec& v) const {
        W1695Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1695Camera {
    W1695Vec eye;
    W1695Vec target;
    f32 roll;
    f32 fov;
};
struct W1695Track { s32 id; s16 start; s16 end; };
// One camera key: eye xyz, target xyz, roll, fov.
struct W1695Key { f32 eye[3]; f32 target[3]; f32 roll; f32 fov; };

extern "C" {
s32 func_00162088(void);
s32 func_00232328(void);
void func_002311c0(W1695Key* out, void* track, f32 t);
void func_00231390(W1695Key* out, void* ctl, f32 t);
void func_002314c0(W1695Key* key);
void func_0015d2e8(W1695Vec eye, W1695Vec target, f32 roll, f32 fov, s32 one, u8 a, u8 b, u8 c);
void* W1695_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
void W1695_setCameraNumber(s32) asm("_ZN2kn15setCameraNumberEi");
extern void** D_0035dce0;
extern W1695Track* D_0035dce4;
extern s32 D_0035de20;
extern f32 D_0035de1c;
extern u8 D_0035de0a;
extern u8 D_0035de0b;
extern s32 D_0035de10;
extern u8 D_0035de14;
extern u8 D_0035de15;
extern W1695Mtx* D_0035de18;
extern W1695Camera D_0035db20;
extern u8 D_0035de90[8][32];
static inline __attribute__((always_inline)) void W1695_Ctl(W1695Key* k, void* c, f32 t) { func_00231390(k, c, t); }

void func_00231500(void);  // 0x00231500: definition moved into src/anon/unit_00231500.cpp
}
