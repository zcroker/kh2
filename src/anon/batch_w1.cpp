#include "../common/types.h"

extern "C" {
void dk__Octree__intersectLine(u32, u32, u32*, u32*, u32);
void func_00150e00(void*, u32, u32, u32, u32, s32);
void func_001399c0(s32);
void func_00139b28(s32);
void func_00179f10(void*);
void func_001781a8(void*);
void YS__BTLOBJ__set_hitback(void*, s32, f32);
void func_00186378(void*, s32, f32);
void func_001b0700(void*, f32);
void YS__PARTRAM__set_item_max(s32, s32);
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
void func_0010c828(u8* p);  // 0x0010c828: definition moved into src/anon/unit_0010b978.cpp

// 128-bit copy of *s into the quadword at d+0x40 (skipped on self-assignment).
void func_0011a918(u8* d, u8* s);  // 0x0011a918: definition moved into src/anon/unit_0011a660.cpp

// Virtual call: slot 0.
void func_00127da0(void** o);  // 0x00127da0: definition moved into src/anon/unit_00127a88.cpp

void func_0013a200(void);  // 0x0013a200: definition moved into src/anon/unit_001393c8.cpp

void func_00143b60(u32 a0, u32 a1, u32 a2);  // 0x00143b60: definition moved into src/anon/unit_00142c90.cpp

void func_00150de0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);  // 0x00150de0: definition moved into src/anon/unit_0014ecb8.cpp

// 00154b18: moved to src/anon/unit_00153ea0.cpp
void func_00154b18(u8* p);

// Clamp to [0, 128].
void func_00161a58(s32 v);  // 0x00161a58: definition moved into src/anon/unit_001614e8.cpp

void func_001713f0(BD_VALUE* bd);  // 0x001713f0: definition moved into src/anon/unit_00170f58.cpp

void func_00172830(BD_VALUE* bd);  // 0x00172830: definition moved into src/anon/unit_00171e58.cpp

// 00177a58: moved to src/yasui/libys/party.cpp

// 00179f58: moved to src/yasui/libys/player.cpp

void func_0018f2d0(BD_VALUE* bd);  // 0x0018f2d0: definition moved into src/anon/unit_0018f140.cpp

// 001a8548: moved to src/anon/unit_001a82f0.cpp

// 001ac778: moved to src/anon/unit_001abb28.cpp

// 001c8de0 func_001c8de0: moved to src/yasui/libys/mutex.cpp (linked unit).

void func_001fae80(u8* p, u8* q);  // 0x001fae80: definition moved into src/anon/unit_001fa1b8.cpp

// VU0: return max(x, y).
f32 func_00222678(f32 x, f32 y);  // 0x00222678: definition moved into src/anon/unit_00222548.cpp

// VU0: meant to copy xy of s into d, but stores vf31 (bug in the original).
void func_002226a0(f32* d, f32* s);  // 0x002226a0: definition moved into src/anon/unit_00222548.cpp

// VU0: d.xy = a.xy - b.xy (zw kept).
void func_00222770(f32* d, f32* a, f32* b);  // 0x00222770: definition moved into src/anon/unit_00222548.cpp

s32 sa__EVENT__getEventPriority(void);  // 0x002282d8: definition moved into src/anon/unit_00224780.cpp

void func_0023cdb8(void);  // 0x0023cdb8: definition moved into src/anon/unit_0023c968.cpp

void func_00263188(void);  // 0x00263188: definition moved into src/anon/unit_0025f6b8.cpp

void func_0026dd18(s32 a0, s32 a1, s32 a2);  // 0x0026dd18: definition moved into src/anon/unit_0026c450.cpp

void func_00281108(void);  // 0x00281108: definition moved into src/anon/unit_0027f2b0.cpp

void func_00299238(void);  // 0x00299238: definition moved into src/anon/unit_002982f0.cpp

void func_002eac70(f32 a, f32 b, f32 c, f32 d);  // 002eac70: moved to src/anon/unit_002eaa68.cpp

// VU0: d = a / s.
void sceVu0DivVector(f32* d, f32* a, f32 s);  // 0x002f3e90: definition moved into src/sdk/libvu0_002f3cd8.s

// VU0: d = a + b.
void sceVu0AddVector(f32* d, f32* a, f32* b);  // 0x002f3ef8: definition moved into src/sdk/libvu0_002f3cd8.s

// VU0: float vector -> 12.4 fixed-point ints.
void sceVu0FTOI4Vector(s32* d, f32* a);  // 0x002f3fc0: definition moved into src/sdk/libvu0_002f3cd8.s

// VU0: d = clamp(a, lo, hi) per component.
void sceVu0ClampVector(f32* d, f32* a, f32 lo, f32 hi);  // 0x002f42e8: definition moved into src/sdk/libvu0_002f42e8.s

// fabsf by clearing the sign bit.
f32 fabsf(f32 f);  // 0x002f8870: definition moved into src/newlib/libm/sf_fabs.c

void func_00366db0(u32 a0) {
    func_00076160(a0 & 0xffff);
    asm volatile("sync");
}
}

// 001826f8: moved to src/yasui/libys/areadata.cpp

// 0015e038: moved to src/anon/unit_0015d828.cpp

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

// 00149ca0: moved to src/harata/libdk/area.cpp
// 0014ec20: moved to src/harata/libdk/fpscamera.cpp
} // namespace dk

// YS OBJ ControlOn(int), declared by asm label (no qualified name in this file)
// so the layout resolver does not attribute it to this file.
void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");

namespace YS {
class EVENT {
  public:
    static void ControlOn();
};

// 0016e688: moved to src/anon/unit_0016d2e0.cpp
void trap_attack_set_pos(BD_VALUE* bd);  // 0x0018f770: definition moved into src/anon/unit_0018f140.cpp
void trap_camera_reset(BD_VALUE*);  // 0x00174bc8: definition moved into src/anon/unit_00171e58.cpp
// 0x00197780 YS::EVENT::ControlOn: definition moved into src/anon/unit_00195d00.cpp
} // namespace YS
