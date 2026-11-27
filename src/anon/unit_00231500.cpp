// Linked unit 0x00231500-0x00232f08 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../sasa/event.hpp"
#include "../tozawa/menu_sound.hpp"

// 00231500 (was src/anon/batch_w2459.cpp)
namespace n00231500 {
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
s32 func_00162088(void) asm("func_00162088");
s32 func_00232328(void) asm("func_00232328");
void sa__EVENT__calcValue_enc(W1695Key* out, void* track, f32 t) asm("sa__EVENT__calcValue_enc");
void func_00231390(W1695Key* out, void* ctl, f32 t) asm("func_00231390");
void func_002314c0(W1695Key* key) asm("func_002314c0");
void func_0015d2e8(W1695Vec eye, W1695Vec target, f32 roll, f32 fov, s32 one, u8 a, u8 b, u8 c) asm("func_0015d2e8");
void* W1695_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
void W1695_setCameraNumber(s32) asm("_ZN2kn15setCameraNumberEi");
extern void** D_0035dce0 asm("D_0035dce0");
extern W1695Track* D_0035dce4 asm("D_0035dce4");
extern s32 D_0035de20 asm("D_0035de20");
extern f32 D_0035de1c asm("D_0035de1c");
extern u8 D_0035de0a asm("D_0035de0a");
extern u8 D_0035de0b asm("D_0035de0b");
extern s32 D_0035de10 asm("D_0035de10");
extern u8 D_0035de14 asm("D_0035de14");
extern u8 D_0035de15 asm("D_0035de15");
extern W1695Mtx* D_0035de18 asm("D_0035de18");
extern W1695Camera D_0035db20 asm("D_0035db20");
extern u8 D_0035de90[8][32] asm("D_0035de90");
static inline __attribute__((always_inline)) void W1695_Ctl(W1695Key* k, void* c, f32 t) { func_00231390(k, c, t); }
/*TARGET 00231500*/
void sa__EVENT__camera_ctrl(void) asm("sa__EVENT__camera_ctrl");
void sa__EVENT__camera_ctrl(void) {
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
        sa__EVENT__calcValue_enc(&key, D_0035dce0[id], t);
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
}  // namespace n00231500
#undef W1695_QCOPY

// 00231928 (was src/anon/tiny_leaf.cpp)
namespace n00231928 {
/*TARGET 00231928*/
// 00229830: moved to src/sasa/musical_score.cpp (linked unit)

void func_00231928(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00231928jjjj");
// 00229830: moved to src/sasa/musical_score.cpp (linked unit)

void func_00231928(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13 = 0u, r14 = 0u, r15 = 0u;
    r15 = (u32)(s32)(*(s16*)((u32)r4 + (s32)(4)));
    r14 = (u32)(0x0036u << 16);
    r13 = *(u32*)((u32)r14 + (s32)(-8992));
    r15 = (u32)(r15 << 2);
    r15 = (u32)(r15 + r13);
    *(u32*)((u32)r15 + (s32)(0)) = r4;
}
}  // namespace n00231928

// 00231948 (was src/anon/auto80_199_queue.cpp)
namespace n00231948 {
/*TARGET 00231948*/
void sa__EVENT__set_bin_seq_crossfade(u32 a0) asm("_Z32sa__EVENT__set_bin_seq_crossfadej");
void sa__EVENT__set_bin_seq_crossfade(u32 a0) {
    u32 s16v = a0;
    s32 t14;
    s32 a4;
    f32 f12;

    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (sa__EVENT__isJumpMode(*(s16*)(s16v + 4)) != 0) {  // flag_query_by_index
        return;
    }

    t14 = 0;
    a4 = *(s16*)(s16v + 6);
    if ((a4 & 0x8000) != 0) {
        a4 = a4 & 0x7fff;
        t14 = 1;
    }
    f12 = (f32)a4;
    func_00161f48(t14, f12);
}
}  // namespace n00231948

// 002319c0 (was src/anon/batch_w1696.cpp)
namespace n002319c0 {
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
extern W1696Chan D_0035de90[8] asm("D_0035de90");
extern s32 D_0035de28 asm("D_0035de28");
void func_00140f78(W1696Vec* eye, W1696Vec* at) asm("func_00140f78");
W1696Proj* kn__getProjection(s32) asm("kn__getProjection");
void* func_00106a60(s32) asm("func_00106a60");
f32 func_00106f40(W1696Proj*, f32) asm("func_00106f40");
void kn__Camera__getPosition(void* cam, W1696Vec*) asm("kn__Camera__getPosition");
void func_00107478(void* cam, W1696Vec*) asm("func_00107478");
f32 W1696_getFov(void) asm("_ZN2dk9ObjCamera6getFovEv");
W1696Player* W1696_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
f32 W1696_getRoll(void* cam) asm("_ZNK2kn6Camera7getRollEv");
f32 W1696_getFOV(const W1696Proj* p, s32 worh) asm("_ZNK2kn10Projection6getFOVENS0_4WorHE");
/*TARGET 002319c0*/
void sa__EVENT__set_objcamera_event_in(s32 frame) asm("sa__EVENT__set_objcamera_event_in");
void sa__EVENT__set_objcamera_event_in(s32 frame) {
    W1696Vec at;
    W1696Vec eye;
    func_00140f78(&eye, &at);
    W1696Proj* proj = kn__getProjection(1);
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
    kn__Camera__getPosition(cam, &eye);
    func_00107478(cam, &at);
    eye.w = 1.0f;
    at.w = 1.0f;
    f32 roll = W1696_getRoll(cam);
    *proj = *kn__getProjection(1);
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
}  // namespace n002319c0
#undef W1696_QCOPY

// 00232070 (was src/anon/batch_w52.cpp)
namespace n00232070 {
u32 sa__EVENT__checkStart(s16) asm("sa__EVENT__checkStart");
u32 func_002ba620(void) asm("func_002ba620");
void sa__EVENT__set_objcamera_event_in(s16) asm("sa__EVENT__set_objcamera_event_in");
extern u8 D_0035de0a[] asm("D_0035de0a");
extern u8 D_0035de0c[] asm("D_0035de0c");
extern s32 D_0035de10 asm("D_0035de10");
/*TARGET 00232070*/
void sa__EVENT__set_bin_seq_objcamera(s16* p) asm("sa__EVENT__set_bin_seq_objcamera");
void sa__EVENT__set_bin_seq_objcamera(s16* p) {
    if (sa__EVENT__checkStart(p[2])) return;
    D_0035de0a[0] = 1;
    s32 m = p[3];
    D_0035de10 = m;
    if (m != 0) {
        if (m == 1) sa__EVENT__set_objcamera_event_in(p[2]);
    } else if (!func_002ba620()) {
        D_0035de0c[0] = 1;
    }
}
}  // namespace n00232070

// 00232100 (was src/anon/tiny.cpp)
namespace n00232100 {
extern u32 D_0035de0b asm("D_0035de0b");
/*TARGET 00232100*/
void func_00232100(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00232100jjjj");
void func_00232100(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035de0b = (u8)v;
}
}  // namespace n00232100

// 00232110 (was src/anon/batch_w12.cpp)
namespace n00232110 {
extern s16 D_0035de14 asm("D_0035de14");
extern u8 D_0035de15 asm("D_0035de15");
/*TARGET 00232110*/
void func_00232110(s16* p) asm("func_00232110");
void func_00232110(s16* p) {
    *(u8*)&D_0035de14 = 1;
    switch (p[3]) {
    case 0: D_0035de15 = 0; break;
    case 1: D_0035de15 = 1; break;
    }
}
}  // namespace n00232110

// 00232150 (was src/anon/batch_w274.cpp)
namespace n00232150 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
struct OB { u8 pad[64]; M4 m; };
union UOB { OB* p; f32 f; };
struct OO { u8 pad[8]; UOB u; };
static inline V4 operator*(const M4& m, const V4& v) {
    V4 r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline V4 operator+(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// 0x001d0678: definition moved into src/anon/unit_001cf0b0.cpp
extern u8 D_0035de26 asm("D_0035de26");
s32 func_002283b0(void) asm("func_002283b0");
s32 func_002283c8(void) asm("func_002283c8");
OO* func_00227cd8(s32) asm("func_00227cd8");
void* func_00106a60(s32) asm("func_00106a60");
// buffer_get_by_index
void kn__Camera__getPosition(void*, V4*) asm("kn__Camera__getPosition");
// vec_copy_at80_if_diff
void func_00107478(void*, V4*) asm("func_00107478");
// vec_copy_at96_if_diff
s32 YS__OBJ__is_valid(u8*) asm("YS__OBJ__is_valid");
// list_contains_ptr
void kn__Camera__lookAt_2(void*, V4*, V4*) asm("kn__Camera__lookAt_2");
void func_001024a8(void*) asm("func_001024a8");
/*TARGET 00232150*/
void func_00232150(void* self) asm("func_00232150");
void func_00232150(void* self) {
    OO* o;
    if (func_002283b0()) o = func_00227cd8(1363);
    else if (func_002283c8()) o = func_00227cd8(1489);
    else o = func_00227cd8(572);
    if (D_0035de26 == 1) {
        V4 a, b;
        void* c = func_00106a60(1);  // buffer_get_by_index
        kn__Camera__getPosition(c, &a);  // vec_copy_at80_if_diff
        func_00107478(c, &b);  // vec_copy_at96_if_diff
        if (o) {
            if (YS__OBJ__is_valid((u8*)o->u.p)) {  // list_contains_ptr
                a.w = 1.0f;
                a = o->u.p->m * a;
                b.w = 1.0f;
                b = o->u.p->m * b;
                kn__Camera__lookAt_2(c, &a, &b);
            } else func_001024a8(self);
        } else func_001024a8(self);
    } else func_001024a8(self);
}
}  // namespace n00232150

// 002322b8 (was src/anon/batch_w47.cpp)
namespace n002322b8 {
// 0x001e7230: definition moved into src/anon/unit_001e0cb8.cpp

extern u8 D_0035de26 asm("D_0035de26");
extern u8 D_00232150[] asm("D_00232150");
void func_00102c18(s32, s32, void*) asm("func_00102c18");
s32 func_002282f0u(u16) asm("sa__EVENT__checkStart");
/*TARGET 002322b8*/
void func_002322b8(u8* p) asm("func_002322b8");
void func_002322b8(u8* p) {
    if (func_002282f0u(*(u16*)(p + 4))) return;
    if (!*(u16*)(p + 6)) {
        if (D_0035de26) return;
        func_00102c18(1, 29990, D_00232150);
        D_0035de26 = 1;
    } else D_0035de26 = 0;
}
}  // namespace n002322b8

// 00232328 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00232328 {
u32 func_00228378(u32, u32, u32, u32) asm("_ZN2sa5EVENT16isSceneEventExecEv");
/*TARGET 00232328*/
u32 func_00232328(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00232328jjjj");
u32 func_00232328(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00228378)(u32, u32, u32, u32) = func_00228378;
    r2 = fp_call4_00228378(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00232328

// 00232348 (was src/anon/batch_w63.cpp)
namespace n00232348 {
s32 func_00105c30(void) asm("func_00105c30");
s32 func_00242e48(void) asm("func_00242e48");
extern u32 D_0033caf0 asm("D_0033caf0");
extern u32 D_0033caf4 asm("D_0033caf4");
extern u8 D_003712d0 asm("D_003712d0");
/*TARGET 00232348*/
// 0x001e6b00: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00232348(void) asm("func_00232348");
// 0x001e6b00: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00232348(void) {
    u32 r;
    if (func_00105c30() == 8) {
        if (func_00242e48()) r = (u32)&D_003712d0;
        else r = D_0033caf0;
    } else r = D_0033caf4;
    return r;
}
}  // namespace n00232348

// 00232398 (was src/anon/batch_w1816_nsa.cpp)
namespace n00232398 {
// --- 00232398
struct W1816E { void* p; u16 pad; u8 flag; char name[25]; };
struct W1816M { u32 x; s16 count; s16 pad; W1816E e[1]; };
struct W1816O { s32 a; s32 b; s32 c; s32 d; s32 e; u8 pad[28]; char name[16]; };
// o->v = (object matrix) * (0,0,1,0), through a function-local static.
// 0016e3e0: moved to src/anon/unit_0016d2e0.cpp

extern W1816M* D_0035de4c asm("D_0035de4c");
void sa__EVENT__set_audio_data(void) asm("sa__EVENT__set_audio_data");
W1816O* func_00227a28(void) asm("func_00227a28");
void func_002feee8(char*, const char*) asm("func_002feee8");
/*TARGET 00232398*/
void func_00232398(W1816M* m) asm("func_00232398");
void func_00232398(W1816M* m) {
    s32 i;
    sa__EVENT__set_audio_data();
    D_0035de4c = m;
    for (i = 0; i < m->count; i++) { m->e[i].p = 0; m->e[i].flag = 0; }
    for (i = 0; i < m->count; i++) {
        W1816O* o = func_00227a28();
        o->a = 3; o->b = 1; o->d = -1; o->e = -1;
        o->name[0] = 0;
        func_002feee8(o->name, m->e[i].name);
        m->e[i].p = o;
    }
}
}  // namespace n00232398

// 00232498 (was src/anon/batch_w46.cpp)
namespace n00232498 {
// ---- 00232498: build "voice/<dir>/event/<name>.vag" in a static buffer
extern char D_01dadbb0[] asm("D_01dadbb0");
extern char D_003712d8[] asm("D_003712d8");
extern char D_003712e8[] asm("D_003712e8");
u32 func_00232348(char*) asm("func_00232348");
void func_002fee78(char*, char*, u32) asm("func_002fee78");
void func_002feee8(char*, char*) asm("func_002feee8");
void strlen(char*) asm("strlen");
/*TARGET 00232498*/
// strlen
char* func_00232498(char* name) asm("func_00232498");
// strlen
char* func_00232498(char* name) {
    D_01dadbb0[0] = 0;
    u32 v = func_00232348(name);
    func_002fee78(D_01dadbb0, D_003712d8, v);
    func_002feee8(D_01dadbb0, name);
    func_002feee8(D_01dadbb0, D_003712e8);
    strlen(D_01dadbb0);  // strlen
    return D_01dadbb0;
}
}  // namespace n00232498

// 00232510 (was src/anon/batch_w54.cpp)
namespace n00232510 {
// 0x001ee5d8: definition moved into src/anon/unit_001ec098.cpp

struct Obj232 {
    u8 pad[20];
    u32 id;
    u8 pad2[24];
    char name[16];
};
Obj232* func_00227a60(void*, s32) asm("func_00227a60");
char* func_00232498(void*) asm("func_00232498");
char* func_002ff2e8(char*, const char*) asm("func_002ff2e8");
u32 func_00227870(char*, void*, void*) asm("func_00227870");
void func_00226030(void) asm("func_00226030");
void YS__FILE__ReadBack(char*, u32, void*, void*) asm("YS__FILE__ReadBack");
/*TARGET 00232510*/
void sa__EVENT__audio_read_set(void* a0, void* a1) asm("sa__EVENT__audio_read_set");
void sa__EVENT__audio_read_set(void* a0, void* a1) {
    Obj232* s = func_00227a60(a0, 3);
    func_002ff2e8(s->name, func_00232498(a0));
    s->id = func_00227870(s->name, s, a1);
    YS__FILE__ReadBack(s->name, s->id, (void*)func_00226030, s);
}
}  // namespace n00232510

// 00232590 (was src/anon/batch_w36.cpp)
namespace n00232590 {
s32 func_002283e0(void) asm("func_002283e0");
u32 func_00227120(void) asm("func_00227120");
// get_data_1dbd8f8
s32 strncmp(u32, const char*, u32) asm("strncmp");
extern const char D_003712f0[] asm("D_003712f0");
extern u8 D_0035e359 asm("D_0035e359");
/*TARGET 00232590*/
// 0x001e7878: definition moved into src/anon/unit_001e0cb8.cpp

void sa__EVENT__set_audio_data(void) asm("sa__EVENT__set_audio_data");
// 0x001e7878: definition moved into src/anon/unit_001e0cb8.cpp

void sa__EVENT__set_audio_data(void) {
    D_0035e359 = 0;
    if (func_002283e0()) {
        if (strncmp(func_00227120(), D_003712f0, 12) == 0) D_0035e359 = 1;
    }
}
}  // namespace n00232590

// 002325f0 (was src/anon/batch_w78.cpp)
namespace n002325f0 {
extern u8 D_0035e359 asm("D_0035e359");
extern char D_00371300[] asm("D_00371300");
extern char D_00371320[] asm("D_00371320");
u32 func_00232348(void) asm("func_00232348");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
s32 strncmp(const char*, const char*, s32) asm("strncmp");
void func_002baa08(u32, u32, s32, s32) asm("func_002baa08");
/*TARGET 002325f0*/
// Plays the title voice lines when the event name matches.
s32 func_002325f0(u8* o) asm("func_002325f0");
// Plays the title voice lines when the event name matches.
s32 func_002325f0(u8* o) {
    char buf[64];
    s32 r = 0;
    if (D_0035e359 == 1) {
    func_002fee78(buf, D_00371300, func_00232348());
    if (!strncmp((char*)(o + 48), buf, 24)) {
        r = 1;
        func_002baa08(*(u32*)(o + 20), *(u32*)(o + 28), 16383, 0);
    }
    func_002fee78(buf, D_00371320, func_00232348());
    if (!strncmp((char*)(o + 48), buf, 24)) {
        r = 1;
        func_002baa08(*(u32*)(o + 20), *(u32*)(o + 28), 16383, 127);
    }
    }
    return r;
}
}  // namespace n002325f0

// 002326d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002326d0 {
u32 func_002325f0(...) asm("func_002325f0");
void func_002baa08(...) asm("func_002baa08");
/*TARGET 002326d0*/
void func_002326d0(u32* a0) asm("_Z13func_002326d0Pj");
void func_002326d0(u32* a0) {
    u32 s0 = (u32)a0;
    if (func_002325f0((u32)a0) != 0) {
        return;
    }
    func_002baa08(*(u32*)(s0 + 20), *(u32*)(s0 + 28), 16383, 64);
}
}  // namespace n002326d0

// 00232718 (was src/anon/auto200_999.cpp)
namespace n00232718 {
extern s32 D_0035de2c asm("D_0035de2c");
/*TARGET 00232718*/
// 0x0027dc20: definition moved into src/anon/unit_0027d2e8.cpp

void func_00232718() asm("_Z13func_00232718v");
// 0x0027dc20: definition moved into src/anon/unit_0027d2e8.cpp

void func_00232718() {  // decrement_global_clamped
    s32 v = D_0035de2c;
    v -= 1;
    if (v < 0) {
        v = 0;
    }
    D_0035de2c = v;
}
}  // namespace n00232718

// 00232738 (was src/anon/batch_w3720.cpp)
namespace n00232738 {
s32 sa__EVENT__isJumpMode(s16) asm("sa__EVENT__isJumpMode");
s32 func_00225b50(s16) asm("func_00225b50");
s32 func_00225e48(void) asm("func_00225e48");
void func_002278e0(void*) asm("func_002278e0");
void func_002326d0(void*) asm("func_002326d0");
void func_00232718(void) asm("func_00232718");
s32 func_002baa20(s32) asm("func_002baa20");
void func_002baa48(s32) asm("func_002baa48");
typedef struct Obj_w { s32 a; s32 type; u8 pad[0xc]; s32 h; } Obj_w;
typedef struct Ent_w { Obj_w* obj; s16 time; s8 state; u8 pad[0x19]; } Ent_w;
typedef struct Hdr_w { s32 a; s16 n; s16 b; Ent_w e[1]; } Hdr_w;
extern Hdr_w* D_0035de4c asm("D_0035de4c");
extern s32 D_0035de20 asm("D_0035de20");
/*TARGET 00232738*/
void sa__EVENT__audio_ctrl(void) asm("sa__EVENT__audio_ctrl");
void sa__EVENT__audio_ctrl(void)
{
    Hdr_w* h = D_0035de4c;
    if (h == 0) return;
    s32 now = D_0035de20;
    Ent_w* e = h->e;
    s16 n = h->n;
    for (s32 i = 0; i < n; i++, e++) {
        switch (e->state) {
        case 0:
            if (now >= e->time) {
                Obj_w* o = e->obj;
                if (o->type == 3) {
                    e->state = 1;
                    if (func_00225e48() == 0 && func_00225b50(e->time) == 0 && sa__EVENT__isJumpMode(e->time) == 0) {
                        func_002326d0(o);
                        { s32 a; register s32 b asm("$14"); asm volatile("lui %1,%%hi(D_0035de2c)\n\tlw %0,%%lo(D_0035de2c)(%1)\n\taddiu %0,%0,1\n\tsw %0,%%lo(D_0035de2c)(%1)" : "=&r"(a), "=&r"(b)); }
                    }
                }
            }
            break;
        case 1: {
            Obj_w* o = e->obj;
            if (func_00225e48() != 0) {
                if (func_002baa20(o->h) == 1) {
                    func_002baa48(o->h);
                    func_00232718();
                    func_002278e0(o);
                    e->state = 2;
                }
            } else {
                if (func_002baa20(o->h) == 0) {
                    func_00232718();
                    func_002278e0(o);
                    e->state = 2;
                }
            }
            break;
        }
        case 2: break;
        }
    }
}
}  // namespace n00232738

// 002328c0 (was src/anon/batch_w80.cpp)
namespace n002328c0 {
// ---- unit 7 (good232.cpp)
struct U7_SeEnt { u8* obj; u8 pad[2]; s8 state; u8 pad2[25]; };
struct U7_SeTbl { u8 pad[4]; s16 n; u8 pad2[2]; U7_SeEnt e[1]; };
struct U7_SeObj { u8 pad[20]; u32 h; };
struct U7_SeReq { u8 pad[4]; s16 id; s16 fade; };
extern U7_SeTbl* D_0035de4c asm("D_0035de4c");
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
s32 func_002baa20(u32) asm("func_002baa20");
void func_002b797c(u32, u32, s32) asm("func_002b797c");
/*TARGET 002328c0*/
void func_002328c0(U7_SeReq* r) asm("func_002328c0");
void func_002328c0(U7_SeReq* r) {
    U7_SeTbl* t;
    s32 sh, i;
    U7_SeEnt* e;
    if (sa__EVENT__checkStart(r->id)) return;
    sh = r->fade << 3;
    t = D_0035de4c;
    if (!t) return;
    e = t->e;
    s32 n = t->n;
    for (i = 0; i < n; i++, e++) {
        if (e->state == 1) {
            U7_SeObj* o = (U7_SeObj*)e->obj;
            if (func_002baa20(o->h) == 1) {
                func_002b797c(o->h, 0, sh);
                e->state = 2;
            }
        }
    }
}
}  // namespace n002328c0

// 00232988 (was src/anon/batch_w86.cpp)
namespace n00232988 {
struct Obj { s32 type; u8 p4[16]; s32 f20; };
struct Ent { Obj* obj; s16 f4; s8 kind; u8 p7[25]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
extern Tbl* D_0035de4c asm("D_0035de4c");
s32 func_002baa20(s32) asm("func_002baa20");
void func_002baa48(s32) asm("func_002baa48");
void func_00232718(void) asm("func_00232718");
// decrement_global_clamped
void func_002278e0(Obj*) asm("func_002278e0");
/*TARGET 00232988*/
void func_00232988(void) asm("func_00232988");
void func_00232988(void)
{
    Tbl* t = D_0035de4c;
    if (!t) return;
    Ent* e = t->e;
    s32 n = t->n;
    for (s32 i = 0; i < n; i++, e++) {
        if (e->kind != 2) continue;
        Obj* o = e->obj;
        if (o->type != 3) continue;
        if (func_002baa20(o->f20) == 1) {
            func_002baa48(o->f20);
            func_00232718();  // decrement_global_clamped
        }
        func_002278e0(o);
    }
}
}  // namespace n00232988

// 00232a48 (was src/anon/batch_w2045_nsa.cpp)
namespace n00232a48 {
void func_00226030(void*) asm("_Z13func_00226030Pv");
void func_00102448(void*, s32) asm("func_00102448");
void YS__FILE__ReadBack(char*, s32, void (*)(void*), void*) asm("YS__FILE__ReadBack");
s32 func_001688b8(void) asm("func_001688b8");
s32 func_001688c8(char*) asm("func_001688c8");
s32 func_00227870(char*, void*, s32) asm("func_00227870");
void func_002278e0(void*) asm("func_002278e0");
void* func_00227a28(void) asm("func_00227a28");
void func_002ba630(s32, s32, s32, s32) asm("func_002ba630");
void func_002ba7c8(void*) asm("func_002ba7c8");
s32 func_002fee78(char*, const char*, ...) asm("func_002fee78");
void strlen(char*) asm("strlen");
extern s32 D_0035e35c asm("D_0035e35c");
extern char D_00371340[] asm("D_00371340");
extern char D_00371350[] asm("D_00371350");
extern char D_00371358[] asm("D_00371358");
struct W2045_Ent { s32 type; u8 pad[16]; s32 h; u8 pad2[24]; char name[32]; };
struct W2045_Arg { u8 pad[6]; s16 a; s16 b; };
/*TARGET 00232a48*/
// ---- 0x232a48 ----
void sa__EVENT__read_se_data(W2045_Arg* p, void* q) asm("sa__EVENT__read_se_data");
// ---- 0x232a48 ----
void sa__EVENT__read_se_data(W2045_Arg* p, void* q) {
    char buf[48];
    char buf2[48];
    s32 r2 = 0;
    W2045_Ent* e1 = 0;
    s32 r1 = 0;
    W2045_Ent* e2 = 0;
    D_0035e35c = p->a;
    if (p->a) {
        e1 = (W2045_Ent*)func_00227a28();
        e1->type = 4;
        func_002fee78(e1->name, D_00371340, p->a);
        func_002fee78(buf, D_00371350, e1->name);
        strlen(buf);
        r1 = func_001688c8(buf);
        e1->h = func_00227870(buf, e1, 0);
        YS__FILE__ReadBack(buf, e1->h, func_00226030, e1);
        if (p->b) {
            e2 = (W2045_Ent*)func_00227a28();
            e1->type = 5;
            func_002fee78(e2->name, D_00371358, p->b);
            func_002fee78(buf2, D_00371350, e2->name);
            strlen(buf2);
            r2 = func_001688c8(buf2);
            e2->h = func_00227870(buf2, e2, 0);
            YS__FILE__ReadBack(buf2, e2->h, func_00226030, e2);
        }
        while (func_001688b8()) func_00102448(q, 0);
    }
    if (p->a) {
        if (p->b) func_002ba630(e1->h, r1, e2->h, r2);
        else func_002ba630(e1->h, r1, 0, 0);
        func_002ba7c8(q);
    }
    if (p->a) {
        func_002278e0(e1);
        if (p->b) func_002278e0(e2);
    }
}
}  // namespace n00232a48

// 00232c88 (was src/anon/batch_w78.cpp)
namespace n00232c88 {
s32 sa__EVENT__checkStart(s16) asm("sa__EVENT__checkStart");
s32 func_00227ca8(void*) asm("func_00227ca8");
s32 sa__EVENT__isJumpMode(s16) asm("sa__EVENT__isJumpMode");
// flag_query_by_index
u32 func_002bc238(s32) asm("func_002bc238");
void func_002bc358(u32, s32) asm("func_002bc358");
extern s32 D_0035e35c asm("D_0035e35c");
extern u32 D_0035db60[] asm("D_0035db60");
struct W78Snd2 { s16 x0, x2, slot, kind; u8 name[4]; s16 id; };
/*TARGET 00232c88*/
void sa__EVENT__set_se_seq(W78Snd2* o) asm("sa__EVENT__set_se_seq");
void sa__EVENT__set_se_seq(W78Snd2* o) {
    if (sa__EVENT__checkStart(o->id)) return;
    if (o->kind == 0) {
        s32 v = func_00227ca8(o->name);
        s32 r = v - 1000;
        if (v <= 1000) r = D_0035e35c * 1000 + v;
        if (sa__EVENT__isJumpMode(o->id)) return;
        D_0035db60[o->slot] = func_002bc238(r);
    } else {
        if (sa__EVENT__isJumpMode(o->id)) return;
        u32 h = D_0035db60[o->slot];
        func_002bc358(h, 240);
    }
}
}  // namespace n00232c88

// 00232d60 (was src/anon/tiny_auto80_queue.cpp)
namespace n00232d60 {
u32 sa__EVENT__checkStart(...) asm("sa__EVENT__checkStart");
void func_002bbed0(...) asm("func_002bbed0");
void SOUND__silentBgSeOff(...) asm("SOUND__silentBgSeOff");
/*TARGET 00232d60*/
void func_00232d60(u8* a0) asm("_Z13func_00232d60Ph");
void func_00232d60(u8* a0) {
    u8* s0 = a0;
    if (sa__EVENT__checkStart((u32)*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(u8*)(s0 + 6) == 0) {
        func_002bbed0();
    } else {
        SOUND__silentBgSeOff();
    }
}
}  // namespace n00232d60

// 00232db0 (was src/anon/batch_w48.cpp)
namespace n00232db0 {
struct E232 { s32 a; s32 b; s32 c; u8 pad[52]; };
union U232 { E232* p; s32 i; };
extern U232 D_0035dcf8 asm("D_0035dcf8");
/*TARGET 00232db0*/
/* release the slot owned by id */
void sa__EVENT__clearMotionCtrlWk(s32 id) asm("sa__EVENT__clearMotionCtrlWk");
/* release the slot owned by id */
void sa__EVENT__clearMotionCtrlWk(s32 id) {
    for (s32 i = 0; i < 64; i++) {
        if (D_0035dcf8.p[i].a != -1 && D_0035dcf8.p[i].b == id) {
            D_0035dcf8.p[i].a = -1;
            D_0035dcf8.p[i].b = -1;
            D_0035dcf8.p[i].c = 0;
            return;
        }
    }
}
}  // namespace n00232db0

// 00232e18 (was src/anon/tiny_auto80_queue.cpp)
namespace n00232e18 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00232e18*/
u32 func_00232e18(u32 a0) asm("_Z13func_00232e18j");
u32 func_00232e18(u32 a0) {
    s32 i = 0;
    u8* t6 = *(u8**)((u8*)&D_00360000 - 8968u);
    while (true) {
        if (*(s32*)(t6 + 0) != -1) {
            if (*(u32*)(t6 + 4) == a0) {
                return (u32)t6;
            }
        }
        i += 1;
        if (i < 64) {
            t6 += 64;
            continue;
        }
        return 0;
    }
}
}  // namespace n00232e18

// 00232e60 (was src/anon/batch_w13.cpp)
namespace n00232e60 {
extern u32* D_0035dcf8 asm("D_0035dcf8");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 00232e60*/
u32* func_00232e60(void) asm("func_00232e60");
u32* func_00232e60(void) {
    u32* p = D_0035dcf8;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (*p == (u32)-1) return p;
        p += 16;
    }
    return 0;
}
}  // namespace n00232e60

// 00232ea0 (was src/anon/batch_w220.cpp)
namespace n00232ea0 {
union U { u8 c; u16 h; s16 sh; u32 w; float f; };
/*TARGET 00232ea0*/
void func_00232ea0(U* a0, U* a1, U* a2, u32 a3) asm("func_00232ea0");
void func_00232ea0(U* a0, U* a1, U* a2, u32 a3) {
  a0[0].w = a2[0].w; a0[1].w = a2[1].w; a0[2].w = a2[2].w;
  a0[5].f = (float)a1[2].h * 2.0f;
  a0[6].h = ((U*)((u8*)a1+10))->h;
  ((U*)((u8*)a0+26))->h = ((U*)((u8*)a1+12))->h;
  float f0 = (float)(s32)(a1[2].h - ((U*)((u8*)a1+16))->sh) * 2.0f;
  a0[12].c = 1;
  a0[3].w = a3;
  a0[4].f = f0;
}
}  // namespace n00232ea0

