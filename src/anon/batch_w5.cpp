#include "../common/types.h"

// Batch w5: small leaf / wrapper functions.

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {

// Copy the quadword at src+0x60 to dst (unless they are the same).
void func_00107478(u8* src, u8* dst) {  // vec_copy_at96_if_diff
    src += 0x60;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

// Copy the quadword at src+0x40 to dst; returns dst.
void* func_0011a900(void* dst, u8* src) {
    src += 0x40;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    return dst;
}

// Call the object's first virtual function.
typedef void (*VFn)(void*);
void func_0011f3b8(void** obj) {
    (*(VFn**)obj)[0](obj);
}

// Copy one quadword src -> dst (unless they are the same).
void func_00134d78(u8* src, u8* dst) {
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

void func_0013d750(void);
void func_00102c18(u32, u32, void (*)(void));
void func_0013d798(void) {
    func_00102c18(1, 100000, func_0013d750);
}

void func_0014ace8(void);
extern u32 D_003493a0;
void func_0014a988(void*);  // clear_fields_244_260
void func_0014acf8(void) {
    func_0014ace8();
    func_0014a988(&D_003493a0);  // clear_fields_244_260
}

void func_001398d0(u32);
void func_00139a38(u32);
void func_0015b7a0(void) {
    func_001398d0(15);
    func_00139a38(15);
}

// Copy the constant quadword D_004f37f0 to dst; returns dst.
extern Q16 D_004f37f0;
// 0015ceb8: moved to src/anon/unit_0015cdb0.cpp

u32* func_00102c80(void);
void func_00102688(u32, u32, u32);
void func_001619e8(void) {
    func_00102688(func_00102c80()[1], 3, 3);
}

u32 func_001b1448(u32);
void func_001d3390(u32);
extern u32 D_0034dc28;
void func_0016e8f8(void) {
    func_001d3390(func_001b1448(D_0034dc28));
}

extern u32 D_004f63a8[2];
extern u32 D_004f63a0;
void func_0016f7b0(void) {
    D_004f63a8[0] = 0;
    D_004f63a0 = 0;
    D_004f63a8[1] = 0;
}

// Pass a stack copy of the quadword *pp to func_00158920.
void func_00158920(Q16*);
void func_00174e10(Q16** pp) {
    Q16 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(*pp) : "$8", "memory");
    func_00158920(&tmp);
}

// Increment a saturating (max 100) byte counter.
void func_00177a38(u8* p) {  // obj_inc_counter
    if (p[0xb04] < 100) p[0xb04]++;
}

struct Obj18f { u32 pad; s32 id; };
void func_001863a8(s32, s32, f32);
void func_0018f2a8(BD_VALUE* bd) {
    Obj18f* o = (Obj18f*)bd[0].p;
    s32 i = bd[1].i;
    s32 id = o->id;
    func_001863a8(id, i, bd[2].f);
}

extern u32 D_00350334;
extern u32 D_01c61b04;
void func_00196300(void) {
    D_01c61b04 = func_001b1448(D_00350334);
}

void func_001d8fa8(u32, u32);
void func_001a04f8(BD_VALUE* bd) {
    func_001d8fa8(bd[0].i != 0, bd[1].u);
}

// Low five bits of table byte i.
u8 func_001a8bf8(u8* p, s32 i) {  // get_bits5_at
    return p[i] & 0x1f;
}

void func_0017c660(u8*, u8*);
void func_001c3cd8(u8* a, u8* b) {
    *(f32*)(b + 0x11c) = *(f32*)(*(u8**)(b + 0x12c) + 12);
    func_0017c660(a, b);
}

void func_001c6460(void);
void func_001c6748(u8* p) {
    p[0x50] = 2;
    *(void (**)(void))(p + 0x54) = func_001c6460;
}

extern u32 D_01d49960[2];
extern u32 D_01d49968;
void func_001c8a90(void) {
    D_01d49960[0] = 0;
    D_01d49960[1] = 0;
    D_01d49968 = 0;
}

void func_0021fe28(u8*);
void func_001facd0(u8* base, u8* o) {
    func_0021fe28(base + **(s32**)(o + 12) + 160);
}

extern u8 D_00359150[3];
void func_0020ea48(u8 a, u8 b, u8 c) {
    D_00359150[0] = a;
    D_00359150[1] = b;
    D_00359150[2] = c;
}

// VU0 macro code: dst.xyz = a.xyz + b.xyz (dst.w kept).
void func_00222750(void* dst, void* a, void* b) {
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\t"
        "vadd.xyz $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
        : : "r"(dst), "r"(a), "r"(b) : "memory");
}

void func_0014a4b0(void);
void func_00138480(u32);
void func_00226d88(void) {
    func_0014a4b0();
    func_00138480(0);
}

struct Tri { u32 a, b, c; };
extern Tri D_0035db50;
void func_00226f90(void) {
    D_0035db50.a = 0;
    D_0035db50.b = 0;
    D_0035db50.c = 0;
}

u8* func_00257770(void);
u8 func_00139d78(u8*);
u32 func_00256ef0(void) {
    return func_00139d78(func_00257770() + 2940);
}

u32 func_00287dc0(void);
void func_0023d820(u32);
void func_0026c450(void) {
    func_0023d820(func_00287dc0());
}

u8* func_002766d0(void);
void func_0028da70(u8*, u32);
void func_0029e148(void) {
    func_0028da70(func_002766d0() + 18528, 5);
}

struct S2dd { u8 pad[0x12]; u16 flags; };
u32 func_002ddbb8(u8* p) {  // get_bit0_of_field2808
    S2dd* s = *(S2dd**)(p + 0xaf8);
    if (s) return (s->flags & 1) != 0;
    return 0;
}

struct Pair { u32 a, b; };
extern Pair D_01e2bf00;
void func_002e7500(void) {
    D_01e2bf00.a = 0;
    D_01e2bf00.b = 0;
}

void func_002e95a0(u32, f32, f32);
void func_002e8c58(BD_VALUE* bd) {
    func_002e95a0(bd[0].u, bd[1].f, bd[2].f);
}

extern u32 D_00363410;
void func_002ea2d8(u32* p) {
    p[1] = 1;
    p[2] = 385;
    p[0] = (u32)&D_00363410;
}

// VU0 macro code: dst = a x b (outer product), dst.w = 0.
void func_002f3d50(void* dst, void* a, void* b) {  // vec3_cross
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
void func_00306300(void) {
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
void dk::Timer::start() {
    D_00349df0 = D_00349de8;
    D_00349dfc = 1;
}

extern "C" void func_00188b68(s32, s32, u32);
extern "C" u32 func_00140df0(void);
extern "C" void func_00140f10(u32);
extern "C" void func_001c9770(void);
extern "C" void func_001b9c28(u32);
extern u32 D_01c60528[2];
namespace YS {
void trap_partram_add_ability(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_00188b68(a, bd[1].i, bd[2].i != 0);
}
void trap_camera_warp(BD_VALUE* bd) {
    func_00140f10(func_00140df0());
}
class FRIEND { public: static void Init(); };
void FRIEND::Init() {
    D_01c60528[0] = 0;
    D_01c60528[1] = 0;
    func_001c9770();
}
class EVENT { public: static void ControlOff(); };
void EVENT::ControlOff() {
    func_001b9c28(0);
    func_001b9c28(1);
}
}  // namespace YS

extern "C" void func_0026bc10(void);
extern "C" void func_00257708(u32);
extern "C" void func_0026ceb0(void);
extern "C" u32 func_002953c8(s32);
extern "C" u8 func_002941a8(u32);
namespace Tz {
class CmParty { public: static void CreateInfo(); };
void CmParty::CreateInfo() {
    func_0026bc10();
    func_00257708(0);
    func_0026ceb0();
}
class JmWorldSel { public: static u32 isWorldOpen(s32); };
u32 JmWorldSel::isWorldOpen(s32 world) {
    return func_002941a8(func_002953c8(world));
}
}  // namespace Tz

extern "C" u32 func_002c6218(void);
extern "C" void func_002c6280(u32, u32);
// CloseUpCamera end() (worldmap), bound by asm label so the build does not also
// assign that class's start() to this file (which defines Timer start()).
extern "C" {
void worldmap_closeup_end(void) asm("_ZN8worldmap13CloseUpCamera3endEv");
void worldmap_closeup_end(void) {
    func_002c6280(func_002c6218(), 2);
}
}

// 64-byte (matrix) copy through four quadword registers.
void u_call4_002f3f98(u32 dst, u32 src, u32 a2, u32 a3) {
    asm volatile(
        "lq $6, 0(%1)\n\tlq $7, 16(%1)\n\tlq $8, 32(%1)\n\tlq $9, 48(%1)\n\t"
        "sq $6, 0(%0)\n\tsq $7, 16(%0)\n\tsq $8, 32(%0)\n\tsq $9, 48(%0)"
        : : "r"(dst), "r"(src) : "$6", "$7", "$8", "$9", "memory");
}
