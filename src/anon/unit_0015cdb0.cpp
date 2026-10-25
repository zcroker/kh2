#include "../common/types.h"

// dk::EventCamera (0x15cdb0-0x15d440): event camera state with spring-smoothed position,
// target and angles.

struct FVec {
    f32 x, y, z, w;
    FVec() {}
    ~FVec() {}
    FVec(const FVec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    FVec& operator=(const FVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

u8 D_0034af38 = 0;  // event camera active

static FVec D_004f3760;  // position (smoothed)
static FVec D_004f3770;  // target (smoothed)
static FVec D_004f3780;  // target goal
static FVec D_004f3790;  // target velocity
static FVec D_004f37a0;  // position goal
static FVec D_004f37b0;  // position velocity
static FVec D_004f37c0;  // angles (smoothed)
static FVec D_004f37d0;  // angle goal
static FVec D_004f37e0;  // angle velocity
static FVec D_004f37f0;  // saved target
static FVec D_004f3800;  // saved position
static f32 D_004f3810 __attribute__((aligned(4)));
static f32 D_004f3814 __attribute__((aligned(4)));

extern "C" {
void func_001069b8(u32);  // swap_global_word
void func_00141010(f32);
void func_00140f78(void*, void*);
void* func_00106a60(s32);  // buffer_get_by_index
void* func_00106a18(s32);  // buffer_get_256
void func_00107368(void*, void*);  // vec_copy_at80_if_diff
void func_00107478(void*, void*);  // vec_copy_at96_if_diff
f32 func_001074b8(void*);
f32 func_00106f30(void*, s32);
FVec* func_00140df0(void);  // dk::ObjCamera::getInstance
FVec func_0013f6e8(FVec, FVec, FVec, f32, f32, f32, f32);  // spring step
s32 func_001069e8(void);
f32 func_0017ce10(f32);
void func_0013f9e0(u8*, u8*, u8*, u8, s32);
void func_00107300(void*, u8*, u8*, f32);  // copy_blocks_and_store_float
void func_00106de8(void*, u8*, f32);

void func_0015ce90(void);
void func_0015cef0(void);
}

namespace dk {
struct EventCamera {
    static void start();
};

void EventCamera::start() {
    func_0015ce90();
    func_00141010(0.0f);
    func_001069b8(1);
    func_0015cef0();
}
}  // namespace dk

extern "C" {

void func_0015cde0(u8 a) {
    u8 b[16];
    u8 c[16];
    func_001069b8(0);
    func_00140f78(c, b);
    if (a == 1) {
        D_0034af38 = a;
        void* v = func_00106a60(1);
        func_00107368(v, &D_004f3800);
        func_00107478(v, &D_004f37f0);
        D_004f3814 = func_001074b8(v);
        D_004f3810 = func_00106f30(func_00106a18(1), 0);
    }
}

u8 func_0015ce80(void) { return D_0034af38; }
void func_0015ce90(void) { D_0034af38 = 0; }
FVec func_0015cea0(void) { return D_004f3800; }
FVec func_0015ceb8(void) { return D_004f37f0; }
f32 func_0015ced0(void) { return D_004f3810; }
f32 func_0015cee0(void) { return D_004f3814; }

void func_0015cef0(void) {
    FVec* v = func_00140df0();
    D_004f37b0 = D_004f37a0 = D_004f3760 = v[0];
    D_004f3790 = D_004f3780 = D_004f3770 = v[1];
    D_004f37e0 = D_004f37d0 = D_004f37c0 = v[2];
}

void func_0015cff0(void) {
    D_004f37b0 = D_004f37a0;
    D_004f3790 = D_004f3780;
    D_004f37e0 = D_004f37d0;
}

static inline void Spring(FVec& cur, FVec& goal, FVec& vel, f32 dt) { cur = func_0013f6e8(cur, goal, vel, dt, 2.5f, 0.5f, 1.0f); }

void func_0015d058(FVec* a, FVec* b) {
    D_004f37a0 = *b;
    D_004f3780 = *a;
    D_004f3760 = func_0013f6e8(D_004f3760, D_004f37a0, D_004f37b0, 0.099999994f, 2.5f, 0.5f, 1.0f);
    *b = D_004f3760;
    Spring(D_004f3770, D_004f3780, D_004f3790, 0.07f);
    *a = D_004f3770;
}

void func_0015d208(f32* a, f32* b) {
    D_004f37d0.x = *a;
    D_004f37d0.y = *b;
    D_004f37c0 = func_0013f6e8(D_004f37c0, D_004f37d0, D_004f37e0, 0.07f, 2.5f, 0.5f, 0.001f);
    *a = D_004f37c0.x;
    *b = D_004f37c0.y;
}

// Camera mode 1 update: fix the radian, smooth if asked, then apply to the camera.
void func_0015d2e8(u8* a0, u8* a1, u8* a2, u8 a3, u8 a4, u8 a5, f32 f0, f32 f1) {
    s32 m = func_001069e8();
    void* c;
    if (m != 1) return;
    func_0015cff0();
    f0 = func_0017ce10(f0);
    c = func_00106a60(1);
    if (a3 == m) func_0013f9e0(a0, a1, a0, a4, 0);
    if (a5 == m) {
        func_0015d058((FVec*)a0, (FVec*)a1);
        func_0015d208(&f1, &f0);
    }
    func_00107300(c, a0, a1, f0);
    func_00106de8(func_00106a18(1), a2, f1);
}

}
