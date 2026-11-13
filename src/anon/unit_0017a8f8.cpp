#include "../common/types.h"

// 0x17a8f8-0x17aad0: the small file after YS::PLAYER: base-class methods used by the vtables at 0x34eb58/
// 0x34eb88 (0x17a8f8, 0x17a938) and helpers with a function-local static (guard 0x1c60500, object
// 0x1c60510, its __tcf_0 at 0x17bef8). Its 5 KB static initialiser 0x17aad0 and the stubs stay outside.
// Each function keeps the declarations of the source it was matched in (namespace bN); every symbol is
// bound by asm label.

// 0017a8f8 (src/anon/batch_w11.cpp)
namespace b0 {
extern u32 D_004574b8 asm("D_004574b8");
extern u32 D_0032b91c asm("D_0032b91c");
void func_0014f030(void*, f32, f32, f32) asm("func_0014f030");  // obj_set_lerp_params
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
void func_0014cd98(void) asm("func_0014cd98");
void Vsync_setGameSpeed(f32, f32, f32) asm("_ZN2dk5Vsync12setGameSpeedEfff");
void GAUGE_FRIEND_reload(u8*) asm("_ZN2dk12GAUGE_FRIEND6reloadEv");
struct RadarS { u8 pad[2928]; void* data; s32 n; };
void func_0015b7f8(void*) asm("func_0015b7f8");
void func_0015bab8(void*) asm("func_0015bab8");
void Radar_create(RadarS*, void*) asm("_ZN2dk5Radar6createEPv");
extern u32 D_0032e020 asm("D_0032e020");
void* func_00189200(void*, u32) asm("func_00189200");
void func_001891b8(void*, u32) asm("func_001891b8");
void trap_saveram_set_form_ability(u32*) asm("_ZN2YS29trap_saveram_set_form_abilityEP8BD_VALUE");
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_0017c4c8(void*, Q16*) asm("func_0017c4c8");
void func_0016bd60(void*, s32) asm("func_0016bd60");

void f17a8f8(void*, void*, Q16*) asm("_Z13func_0017a8f8Pv");
void f17a8f8(void*, void* o, Q16* q) {
    Q16 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(q) : "$8", "memory");
    func_0017c4c8(o, &t);
    func_0016bd60(o, 1);
}
}  // namespace b0

// 0017a938 (src/anon/batch_w8.cpp)
namespace b1 {
typedef void (*VFn)(void*);
typedef void (*VF3)(void*, u32, u32);
typedef u32 (*VR3)(void*, u32, u32);
void func_0017c430(void*) asm("func_0017c430");
void func_0016bd60(void*, u32) asm("func_0016bd60");

void func_0017a938(void*, void* o) {
    func_0017c430(o);
    func_0016bd60(o, 1);
}
}  // namespace b1

// 0017a968 (src/anon/batch_w55.cpp)
namespace b2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct HeapW55;
void* operator new[](unsigned int, HeapW55*) asm("func_001063f0");
typedef void (*CbW55)(u8*, u32);
void func_0016bd60(u32, s32) asm("func_0016bd60");
u32 func_001b9bc8(u32) asm("func_001b9bc8");
s32 func_0016a040(u32) asm("func_0016a040");
void func_0016c568(u32, u32, f32) asm("func_0016c568");
extern s8 D_01c60500 asm("D_01c60500");
extern V4 D_01c60510 asm("D_01c60510");
void func_0017bef8(void) asm("func_0017bef8");
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
void wtarget_0010f918(u32, u32, u32, u32) asm("_Z16wtarget_0010f918jjjj");
void wtarget_0016c5b8(u32, u32, u32, u32) asm("_Z16wtarget_0016c5b8jjjj");
Q16* ctarget_0017a968(Q16*) asm("_Z16ctarget_0017a968jjjj");
u32 ctarget_00180618(u8*) asm("_Z16ctarget_00180618jjjj");
void AddDeadEffect(void*) asm("_ZN2YS6EFFECT13AddDeadEffectEPN3ryj6EFFECTE");
void MissionFailed(void) asm("_ZN2YS7MISSION6FailedEv");
s32 Select_isCreated(u8*) asm("_ZN2Tz6Select9isCreatedEz");
s32 wtarget_002e3418(u32, u32, u32, u32) asm("_Z16wtarget_002e3418jjjj");
void TutorialWidgetCtor(u8*, s32) asm("_ZN4menu14TutorialWidgetC1Ei");
const char* wtarget_00303728(u32, u32, u32, u32) asm("_Z16wtarget_00303728jjjj");
void wtarget_0010f918(u32 a, u32, u32, u32) asm("func_0010f918");
void wtarget_0016c5b8(u32 a, u32 b, u32, u32) asm("func_0016c5b8");

// Function-local static zero vector, returned by value.
Q16* ctarget_0017a968(Q16* out) {
    if (!D_01c60500) {
        D_01c60510.w = D_01c60510.z = D_01c60510.y = D_01c60510.x = 0.0f;
        D_01c60500 = 1;
        func_002fd188(func_0017bef8);  // pool_alloc_block
    }
    copyQ(out, &D_01c60510);
    return out;
}
}  // namespace b2

// 0017a9e8 (src/anon/batch_w82.cpp)
namespace b3 {
extern u8* D_00352130 asm("D_00352130");
union FU82 { f32 f; u32 u; };
void func_0016bd60(u8*, s32) asm("func_0016bd60");
static inline bool Reacts0017(u8* a1) { return (*(u32*)(*(u8**)(a1 + 12) + 8) & 2) || (*(u32*)(a1 + 352) & 0x40); }

// Picks the reaction motion for the hit described by a0.
void func_0017a9e8(u8* a0, u8* a1)
{
    u32 f = *(u32*)(a0 + 8);
    if (f & 0x20) {
        func_0016bd60(a1, 21);
    } else if (f & 0x1000) {
        func_0016bd60(a1, 45);
    } else {
        bool x = Reacts0017(a1);
        if (x) {
            ((FU82*)(a1 + 36))->f *= *(f32*)(D_00352130 + 68);
            if (*(u32*)(a0 + 8) & 0x400) func_0016bd60(a1, 33);
            else func_0016bd60(a1, 8);
        } else {
            func_0016bd60(a1, 4);
        }
    }
    *(u32*)(a1 + 252) = *(u32*)(a1 + 340);
}
}  // namespace b3

// 0017aab8 (src/anon/tiny_more2.cpp)
namespace b4 {
extern u32 D_0034e9f8 asm("D_0034e9f8");

u32 func_0017aab8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_0034e9f8 + ((u32)a0 << 2) + (0)); }
}  // namespace b4
