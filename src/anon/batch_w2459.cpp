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

void func_00231500(void) {
    s32 count = 0;
    s32 n = 0;
    s32 i;
    s32 start;
    s32 end;
    W1695Key key;
    key.eye[0] = 0.0f; key.eye[1] = 0.0f; key.eye[2] = 0.0f;
    key.target[0] = 0.0f; key.target[1] = 0.0f; key.target[2] = 0.0f;
    key.roll = 0.0f;
    key.fov = 1.0f;
    if (func_00162088() == 1) {
        s32 j;
        for (j = 0; j < 128; j++) {
            W1695Track* tr = &D_0035dce4[j];
            if (tr->id != -1) {
                start = tr->start;
                end = tr->end;
                if (D_0035de20 >= start) count += D_0035de20 < end;
            }
        }
    }
    for (i = 0; i < 128; i++) {
        W1695Camera* cam = &D_0035db20;
        s32 id = D_0035dce4[i].id;
        if (id == -1) continue;
        start = D_0035dce4[i].start;
        end = D_0035dce4[i].end;
        if (func_00232328()) end--;
        if (D_0035de20 < start || end < D_0035de20) continue;
        f32 t = 0.0f;
        if (func_00232328()) t = 0.5f;
        t = D_0035de1c * 0.5f + t - start;
        if (!func_00232328()) {
            f32 len = end - start;
            if (len < t) t = len;
        }
        func_002311c0(&key, D_0035dce0[id], t);
        if (func_00162088() == 1 && n == count - 1) W1695_setCameraNumber(1);
        else W1695_setCameraNumber(0);
        if (D_0035de0a == 1 && D_0035de10 == 1) {
            W1695_Ctl(&key, D_0035de90, t);
            func_002314c0(&key);
            D_0035db20.fov = key.fov;
            D_0035db20.roll = -key.roll;
            W1695Mtx* m = (W1695Mtx*)((u8*)W1695_GetPlayer() + 0x40);
            D_0035db20.eye.w = 1.0f;
            D_0035db20.eye = *m * D_0035db20.eye;
            D_0035db20.target.w = 1.0f;
            D_0035db20.target = *m * D_0035db20.target;
        } else {
            func_002314c0(&key);
            D_0035db20.roll = key.roll;
            D_0035db20.fov = key.fov;
            D_0035db20.eye.w = 1.0f;
            D_0035db20.eye = *D_0035de18 * D_0035db20.eye;
            D_0035db20.target.w = 1.0f;
            D_0035db20.target = *D_0035de18 * D_0035db20.target;
        }
        f32 fov = cam->fov * 0.0174532924f;
        func_0015d2e8(cam->eye, cam->target, cam->roll, fov, 1, D_0035de14, D_0035de15, D_0035de0b);
        n++;
        W1695_setCameraNumber(0);
    }
}
}
