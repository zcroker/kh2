#include "../common/types.h"

extern "C" {
void func_00143b88(u32, u32, u32*, u32*, u32);
void func_00150e00(void*, u32, u32, u32, u32, s32);
void func_001399c0(s32);
void func_00139b28(s32);
void func_00179f10(void*);
void func_001781a8(void*);
void func_00186a90(void*, s32, f32);
void func_00186378(void*, s32, f32);
void func_001b0700(void*, f32);
void func_00188958(s32, s32);
void func_001a48c0(s32, s32);
u32* func_001a84b0(void);
void func_00138190(u32, u32);
void func_00220070(void*);
void* func_00257770(void);
void func_0028da70(void*, s32);
void* func_002766d0(void);
void func_0028dac8(void*, s32);
void* func_00281238(void);
void func_0016e920(void*);
void func_00076160(u32);
void func_0014e658(void*);
void func_00140f20(void*);

extern s32 D_00347f80;
extern s32 D_00347f84;
extern u8* D_0034b240;
extern s32 D_0034c768;
extern f32 D_01c60540;
extern f32 D_01c6053c;
extern struct { u32 a, b; } D_01c6ced0;
extern s32 D_00351eb8;
extern s32 D_00351ec0;
extern s32 D_00351ec8;
extern s32 D_0035db18;
extern s32 D_0035eb34;
extern s32 D_0035eb28;
extern s32 D_01dae680;
extern s32 D_0035f118;
extern s32 D_0035f11c;
extern u8 D_0035f120;
extern f32 D_00363440;
extern f32 D_00363448;
extern f32 D_0036344c;
extern f32 D_00363450;

// Virtual call: slot 6 of the object held at +0xb60.
void func_0010c828(u8* p) {
    void* o = *(void**)(p + 0xb60);
    (*(void (**)(void*))(*(u8**)o + 24))(o);
}

// 128-bit copy of *s into the quadword at d+0x40 (skipped on self-assignment).
void func_0011a918(u8* d, u8* s) {
    d += 64;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}

// Virtual call: slot 0.
void func_00127da0(void** o) {
    (*(void (**)(void*))*o)(o);
}

void func_0013a200(void) {
    D_00347f80 = D_00347f84;
    D_00347f84 = 0;
}

void func_00143b60(u32 a0, u32 a1, u32 a2) {
    u32 x;
    u32 y = 0;
    func_00143b88(a0, a1, &x, &y, a2);
}

void func_00150de0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    *(u32*)(p + 0x19a0) = a5;
    func_00150e00(p, a1, a2, a3, a4, -1);
}

void func_00154b18(u8* p) {
    p[0x3ce0] = 0;
    func_001399c0(6);
    func_00139b28(6);
}

// Clamp to [0, 128].
void func_00161a58(s32 v) {
    s32 r = (v < 0) ? 0 : (v > 128 ? 128 : v);
    D_0034c768 = r;
}

void func_001713f0(BD_VALUE* bd) {
    void* o = *(void**)((u8*)bd[0].p + 4);
    s32 i = bd[1].i;
    func_00186a90(o, i, bd[2].f);
}

void func_00172830(BD_VALUE* bd) {
    func_001b0700(*(u8**)((u8*)bd[0].p + 4) + 1184, bd[1].f);
}

// Decrement a byte counter, saturating at 0.
void func_00177a58(u8* p) {
    if (p[0xb04] != 0) p[0xb04]--;
}

void func_00179f58(void* p) {
    func_00179f10(p);
    func_001781a8(p);
}

void func_0018f2d0(BD_VALUE* bd) {
    void* o = *(void**)((u8*)bd[0].p + 4);
    s32 i = bd[1].i;
    func_00186378(o, i, bd[2].f);
}

void func_001a8548(void) {
    u32* v = func_001a84b0();
    func_00138190(v[0], v[2]);
}

void func_001ac778(void) {
    D_01c6ced0.a = 0;
    D_01c6ced0.b = 0;
}

void func_001c8de0(void) {
    D_00351eb8 = 0;
    D_00351ec0 = 0;
    D_00351ec8 = 0;
}

void func_001fae80(u8* p, u8* q) {
    func_00220070(p + **(s32**)(q + 12) + 160);
}

// VU0: return max(x, y).
f32 func_00222678(f32 x, f32 y) {
    f32 v[4] __attribute__((aligned(16)));
    v[0] = x;
    v[1] = y;
    asm volatile("lqc2 $vf1, %0\n\tvmaxy.x $vf1, $vf1, $vf1y\n\tsqc2 $vf1, %0" : "+m"(v));
    return v[0];
}

// VU0: meant to copy xy of s into d, but stores vf31 (bug in the original).
void func_002226a0(f32* d, f32* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmove.xy $vf1, $vf2\n\tsqc2 $vf31, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(s) : "memory");
}

// VU0: d.xy = a.xy - b.xy (zw kept).
void func_00222770(f32* d, f32* a, f32* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\tvsub.xy $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}

s32 func_002282d8(void) {  // limit_15000_or_25000
    return D_0035db18 == 0 ? 25000 : 15000;
}

void func_0023cdb8(void) {
    D_0035eb34 = 1;
    D_0035eb28 = 0;
    D_01dae680 = 0;
}

void func_00263188(void) {
    func_0028da70((u8*)func_00257770() + 408, 300);
}

void func_0026dd18(s32 a0, s32 a1, s32 a2) {  // store_session_globals
    D_0035f118 = a0;
    D_0035f11c = a1;
    if (a2 >= 0) D_0035f120 = a2;
}

void func_00281108(void) {
    func_0016e920(func_00281238());
}

void func_00299238(void) {
    func_0028dac8((u8*)func_002766d0() + 17304, 3);
}

void func_002eac70(f32 a, f32 b, f32 c, f32 d) {
    D_00363440 = a;
    D_00363448 = b;
    D_0036344c = c;
    D_00363450 = d;
}

// VU0: d = a / s.
void func_002f3e90(f32* d, f32* a, f32 s) {  // vec4_scale_by_1_f12
    asm volatile("lqc2 $vf4, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf5\n\tvdiv Q, $vf0w, $vf5x\n\tvwaitq\n\tvmulq.xyzw $vf4, $vf4, Q\n\tsqc2 $vf4, 0(%0)"
                 : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}

// VU0: d = a + b.
void func_002f3ef8(f32* d, f32* a, f32* b) {  // vec4_add
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf5, 0(%2)\n\tvadd.xyzw $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}

// VU0: float vector -> 12.4 fixed-point ints.
void func_002f3fc0(s32* d, f32* a) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tvftoi4.xyzw $vf5, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(a) : "memory");
}

// VU0: d = clamp(a, lo, hi) per component.
void func_002f42e8(f32* d, f32* a, f32 lo, f32 hi) {  // vec4_clamp_to_range
    asm volatile("mfc1 $8, %2\n\tmfc1 $9, %3\n\tlqc2 $vf6, 0(%1)\n\tqmtc2 $8, $vf4\n\tqmtc2 $9, $vf5\n\tvmaxx.xyzw $vf6, $vf6, $vf4x\n\tvminix.xyzw $vf6, $vf6, $vf5x\n\tsqc2 $vf6, 0(%0)"
                 : : "r"(d), "r"(a), "f"(lo), "f"(hi) : "$8", "$9", "memory");
}

// fabsf by clearing the sign bit.
f32 func_002f8870(f32 f) {  // fabsf
    *(u32*)&f &= 0x7fffffff;
    return f;
}

void func_00366db0(u32 a0) {
    func_00076160(a0 & 0xffff);
    asm volatile("sync");
}
}

f32 func_001826f8(u32, u32, u32, u32, u32, u32, u32, u32) {
    return D_01c60540 / D_01c6053c;
}

void u_tail0_0015e038() {
    u8* p = D_0034b240;
    if (p) p[4] = 0;
}

namespace dk {
class GAUGE {
  public:
    static void init();
};
class ObjCamera {
  public:
    static ObjCamera* getInstance();
};
class Area {
  public:
    static void init();
};
class FPSCamera {
  public:
    static void adjust();
};

void Area::init() { GAUGE::init(); }
void FPSCamera::adjust() { func_0014e658(ObjCamera::getInstance()); }
} // namespace dk

// YS OBJ ControlOn(int), declared by asm label (no qualified name in this file)
// so the layout resolver does not attribute it to this file.
void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");

namespace YS {
class EVENT {
  public:
    static void ControlOn();
};

void trap_assert(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_00188958(a, bd[1].i);
}
void trap_attack_set_pos(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_001a48c0(a, bd[1].i);
}
void trap_camera_reset(BD_VALUE*) { func_00140f20(dk::ObjCamera::getInstance()); }
void EVENT::ControlOn() {
    YS_OBJ_ControlOn(0);
    YS_OBJ_ControlOn(1);
}
} // namespace YS
