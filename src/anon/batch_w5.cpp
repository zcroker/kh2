#include "../common/types.h"

// Batch w5: small leaf / wrapper functions.

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {

// Copy the quadword at src+0x60 to dst (unless they are the same).
// 00107478: moved to src/naka/libkn/camera.cpp

// Copy the quadword at src+0x40 to dst; returns dst.
void* func_0011a900(void* dst, u8* src);  // 0x0011a900: definition moved into src/anon/unit_0011a660.cpp

// Call the object's first virtual function.
typedef void (*VFn)(void*);
void func_0011f3b8(void** obj);  // 0x0011f3b8: definition moved into src/anon/unit_0011c128.cpp

// 00134d78: moved to src/anon/unit_00134668.cpp

void func_0013d750(void);
void func_00102c18(u32, u32, void (*)(void));
void func_0013d798(void);  // 0x0013d798: definition moved into src/anon/unit_0013a8b8.cpp

void func_0014ace8(void);
extern u32 D_003493a0;
void func_0014a988(void*);  // clear_fields_244_260
void func_0014acf8(void);  // 0x0014acf8: definition moved into src/harata/libdk/fade.cpp

void func_001398d0(u32);
void func_00139a38(u32);
void func_0015b7a0(void);  // 0x0015b7a0: definition moved into src/anon/unit_0015b100.cpp

// Copy the constant quadword D_004f37f0 to dst; returns dst.
extern Q16 D_004f37f0;
// 0015ceb8: moved to src/anon/unit_0015cdb0.cpp

u32* func_00102c80(void);
void func_00102688(u32, u32, u32);
void func_001619e8(void);  // 0x001619e8: definition moved into src/anon/unit_001614e8.cpp

u32 func_001b1448(u32);
void func_001d3390(u32);
extern u32 D_0034dc28;
void func_0016e8f8(void);  // 0x0016e8f8: definition moved into src/anon/unit_0016e8f8.cpp

extern u32 D_004f63a8[2];
extern u32 D_004f63a0;
void func_0016f7b0(void);  // 0x0016f7b0: definition moved into src/anon/unit_0016e8f8.cpp

// Pass a stack copy of the quadword *pp to func_00158920.
void func_00158920(Q16*);
void func_00174e10(Q16** pp);  // 0x00174e10: definition moved into src/anon/unit_00171e58.cpp

// 00177a38: moved to src/yasui/libys/party.cpp

struct Obj18f { u32 pad; s32 id; };
void func_001863a8(s32, s32, f32);
void func_0018f2a8(BD_VALUE* bd);  // 0x0018f2a8: definition moved into src/anon/unit_0018f140.cpp

extern u32 D_00350334;
extern u32 D_01c61b04;
void func_00196300(void);  // 0x00196300: definition moved into src/anon/unit_00195d00.cpp

void func_001d8fa8(u32, u32);
void func_001a04f8(BD_VALUE* bd);  // 0x001a04f8: definition moved into src/anon/unit_0019fb70.cpp

// Low five bits of table byte i.
u8 func_001a8bf8(u8* p, s32 i);  // 0x001a8bf8: definition moved into src/anon/unit_001a8618.cpp

void func_0017c660(u8*, u8*);
void func_001c3cd8(u8* a, u8* b);  // 0x001c3cd8: definition moved into src/anon/unit_001c2b58.cpp

void func_001c6460(void);
void func_001c6748(u8* p);  // 0x001c6748: definition moved into src/anon/unit_001c5b90.cpp

extern u32 D_01d49960[2];
extern u32 D_01d49968;
// 0x1c8a90: moved to src/yasui/libys/summon.cpp

void func_0021fe28(u8*);
void func_001facd0(u8* base, u8* o);  // 0x001facd0: definition moved into src/anon/unit_001fa1b8.cpp

extern u8 D_00359150[3];
void func_0020ea48(u8 a, u8 b, u8 c);  // 0x0020ea48: definition moved into src/anon/unit_0020e9f8.cpp

// VU0 macro code: dst.xyz = a.xyz + b.xyz (dst.w kept).
void func_00222750(void* dst, void* a, void* b);  // 0x00222750: definition moved into src/anon/unit_00222548.cpp

void func_0014a4b0(void);
void func_00138480(u32);
void func_00226d88(void);  // 0x00226d88: definition moved into src/anon/unit_00224780.cpp

struct Tri { u32 a, b, c; };
extern Tri D_0035db50;
void func_00226f90(void);  // 0x00226f90: definition moved into src/anon/unit_00224780.cpp

u8* func_00257770(void);
u8 func_00139d78(u8*);
u32 func_00256ef0(void);  // 0x00256ef0: definition moved into src/anon/unit_00254020.cpp

u32 func_00287dc0(void);
void func_0023d820(u32);
void func_0026c450(void);  // 0x0026c450: definition moved into src/anon/unit_0026c450.cpp

u8* func_002766d0(void);
void func_0028da70(u8*, u32);
void func_0029e148(void);  // 0x0029e148: definition moved into src/anon/unit_0029d008.cpp

struct S2dd { u8 pad[0x12]; u16 flags; };
u32 func_002ddbb8(u8* p);  // 0x002ddbb8: definition moved into src/anon/unit_002dd650.cpp

struct Pair { u32 a, b; };
extern Pair D_01e2bf00;
void func_002e7500(void);  // 0x002e7500: definition moved into src/anon/unit_002e5f70.cpp

void func_002e95a0(u32, f32, f32);
// 002e8c58: moved to src/anon/unit_002e8b50.cpp

extern u32 D_00363410;
void func_002ea2d8(u32* p);  // 002ea2d8: moved to src/anon/unit_002ea2b8.cpp

// VU0 macro code: dst = a x b (outer product), dst.w = 0.
void sceVu0OuterProduct(void* dst, void* a, void* b) {  // vec3_cross
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\tlqc2 $vf5, 0(%2)\n\t"
        "vopmula.xyz ACC, vf4, vf5\n\tvopmsub.xyz $vf6, $vf5, $vf4\n\t"
        "vsub.w $vf6, $vf6, $vf6\n\tsqc2 $vf6, 0(%0)"
        : : "r"(dst), "r"(a), "r"(b) : "memory");
}

// VU0 macro code: dst.xyz = v.xyz * s.
void func_002f4870(void* dst, void* v, f32 s) {  // vec3_scale_by_f12
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf5\n\t"
        "vmulx.xyz $vf4, $vf4, $vf5x\n\tsqc2 $vf4, 0(%0)"
        : : "r"(dst), "r"(v), "f"(s) : "$8", "memory");
}

void func_003053f0(void);
void iDisableDmac(void) {
    func_003053f0();
    asm volatile("sync");
}

} // extern "C"

namespace dk {
class Timer {
public:
    static void start();
};
}
extern u32 D_00349de8;
extern u32 D_00349df0;
extern u32 D_00349dfc;
// 0x0014c9b8: definition moved into src/anon/unit_0014c7f0.cpp

extern "C" void func_00188b68(s32, s32, u32);
extern "C" u32 func_00140df0(void);
extern "C" void func_00140f10(u32);
extern "C" void func_001c9770(void);
extern "C" void func_001b9c28(u32);
extern u32 D_01c60528[2];
namespace YS {
// 0016e718: moved to src/anon/unit_0016d2e0.cpp
void trap_camera_warp(BD_VALUE* bd);  // 0x00174ba8: definition moved into src/anon/unit_00171e58.cpp
class FRIEND { public: static void Init(); };
// 0017dec0: moved to src/yasui/libys/friend.cpp
// 0x00197760 YS::EVENT::ControlOff: definition moved into src/anon/unit_00195d00.cpp
}  // namespace YS

extern "C" void func_0026bc10(void);
extern "C" void func_00257708(u32);
extern "C" void func_0026ceb0(void);
extern "C" u32 func_002953c8(s32);
extern "C" u8 func_002941a8(u32);
namespace Tz {
class CmParty { public: static void CreateInfo(); };
// 0x0026c9c8: definition moved into src/anon/unit_0026c450.cpp
class JmWorldSel { public: static u32 isWorldOpen(s32); };
// 0x002954e0: definition moved into src/anon/unit_00292e60.cpp
}  // namespace Tz

extern "C" u32 func_002c6218(void);
extern "C" void func_002c6280(u32, u32);
// CloseUpCamera end() (worldmap), bound by asm label so the build does not also
// assign that class's start() to this file (which defines Timer start()).
extern "C" {
void worldmap_closeup_end(void) asm("_ZN8worldmap13CloseUpCamera3endEv");
// worldmap_closeup_end (0x2cb160): moved to src/anon/unit_002cac58.cpp

}

// 64-byte (matrix) copy through four quadword registers.
void sceVu0CopyMatrix(u32 dst, u32 src, u32 a2, u32 a3) {
    asm volatile(
        "lq $6, 0(%1)\n\tlq $7, 16(%1)\n\tlq $8, 32(%1)\n\tlq $9, 48(%1)\n\t"
        "sq $6, 0(%0)\n\tsq $7, 16(%0)\n\tsq $8, 32(%0)\n\tsq $9, 48(%0)"
        : : "r"(dst), "r"(src) : "$6", "$7", "$8", "$9", "memory");
}
