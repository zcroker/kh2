#include "../common/types.h"

// 0x17a8f8-0x17bf40: the small file after YS::PLAYER: base-class methods used by the vtables at 0x34eb58/
// 0x34eb88 (0x17a8f8, 0x17a938) and helpers with a function-local static (guard 0x1c60500, object
// 0x1c60510, its __tcf_0 at 0x17bef8), then the 5 KB static initialiser 0x17aad0 (plain function, partial asm moved as
// is), __tcf_0 and the _GLOBAL__I_/_GLOBAL__D_ stubs.
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

// 0017aad0 (src/anon/batch_w3737.cpp): static init/destruct of the battle command objects. Partial asm: register
// pins plus empty asm in cmd_def and an empty asm input in cmd_set_t only steer scheduling (see asm_review.tsv).
namespace b5 {

// Static construction/destruction of the battle command table objects at 0x01c60030.
struct Flags { u32 v; };
struct Cmd { void* vt; u32 id; Flags f; u32 pad; };
struct Big { void* vt; };
struct NoTail { ~NoTail() {} };

extern "C" {
void func_0031e938(Flags*);
void func_002dfb10(Big*);
void func_002ea2d8(Big*);
void func_002dea00(Big*, f32, f32);
void func_002dea80(Big*);
extern void* D_0034eb00[];
extern void* D_0034eb30[];
extern void* D_0034eb60[];
extern void* D_0034eb90[];
extern void* D_003502a8[];
extern void* D_00350480[];
extern void* D_003504b0[];
extern void* D_003506c0[];
extern void* D_003506f0[];
extern void* D_00350720[];
extern void* D_00350fb0[];
extern void* D_00350fe0[];
extern void* D_00351010[];
extern void* D_00351040[];
extern void* D_00351190[];
extern void* D_00351288[];
extern void* D_003512b8[];
extern void* D_00351348[];
extern void* D_00351378[];
extern void* D_003514f0[];
extern void* D_00351520[];
extern void* D_00351550[];
extern void* D_00351ed8[];
extern void* D_00351f08[];
extern void* D_00351f40[];
extern void* D_003521a8[];
extern void* D_00352330[];
extern void* D_00352610[];
extern void* D_00352640[];
extern void* D_003526e0[];
extern void* D_00352710[];
extern void* D_00361950[];
extern void* D_00361ac0[];
extern void* D_00361af0[];
extern void* D_003624b8[];
extern void* D_003624e8[];
extern void* D_00362518[];
extern void* D_00362548[];
extern void* D_00362c18[];
extern void* D_00362c70[];
extern void* D_00362cc8[];
extern void* D_00362e00[];
extern void* D_00362e30[];
extern void* D_00362ef0[];
extern void* D_00362f20[];
extern void* D_003633d8[];
extern void* D_00363410[];
extern void* D_00363460[];
extern void* D_00363490[];
extern void* D_003634c0[];
extern void* D_00363510[];
extern void* D_00363578[];
extern void* D_003635a8[];
extern void* D_003635d8[];
extern void* D_00363608[];
extern void* D_00363660[];
extern void* D_00363690[];
extern void* D_003636c0[];
extern void* D_003636f0[];
extern void* D_00363928[];
extern void* D_00363958[];
extern void* D_00363988[];
extern void* D_003639b8[];
extern void* D_003639e8[];
extern void* D_00363a18[];
extern Cmd D_01c60030;
extern Cmd D_01c60040;
extern Cmd D_01c60050;
extern Cmd D_01c60060;
extern Cmd D_01c60070;
extern Cmd D_01c60080;
extern Cmd D_01c60090;
extern Cmd D_01c600a0;
extern Cmd D_01c600b0;
extern Cmd D_01c600c0;
extern Cmd D_01c600d0;
extern Cmd D_01c600e0;
extern Cmd D_01c600f0;
extern Cmd D_01c60100;
extern Cmd D_01c60110;
extern Cmd D_01c60120;
extern Cmd D_01c60130;
extern Cmd D_01c60140;
extern Cmd D_01c60150;
extern Cmd D_01c60160;
extern Cmd D_01c60170;
extern Cmd D_01c60180;
extern Cmd D_01c60190;
extern Cmd D_01c601a0;
extern Cmd D_01c601b0;
extern Cmd D_01c601c0;
extern Cmd D_01c601d0;
extern Cmd D_01c601e0;
extern Cmd D_01c601f0;
extern Cmd D_01c60200;
extern Cmd D_01c60210;
extern Big D_01c60220;
extern Cmd D_01c602a0;
extern Cmd D_01c602b0;
extern Big D_01c602c0;
extern Big D_01c60300;
extern Big D_01c60340;
extern Cmd D_01c60350;
extern Cmd D_01c60360;
extern Cmd D_01c60370;
extern Cmd D_01c60380;
extern Cmd D_01c60390;
extern Cmd D_01c603a0;
extern Cmd D_01c603b0;
extern Cmd D_01c603c0;
extern Cmd D_01c603d0;
extern Cmd D_01c603e0;
extern Cmd D_01c603f0;
extern Cmd D_01c60400;
extern Cmd D_01c60410;
extern Cmd D_01c60420;
extern Cmd D_01c60430;
extern Cmd D_01c60440;
extern Cmd D_01c60450;
extern Cmd D_01c60460;
extern Cmd D_01c60470;
extern Cmd D_01c60480;
extern Cmd D_01c60490;
extern Cmd D_01c604a0;
extern Cmd D_01c604b0;
extern Cmd D_01c604c0;
extern Cmd D_01c604d0;
extern Cmd D_01c604e0;
extern Cmd D_01c604f0;

static inline void cmd_set(Cmd* o, void** vt, u32 id, u32 fl) { *(u32*)&o->vt = (u32)vt; o->id = id; o->f.v = fl; }
#define cmd_def(O, VT, ID) do { register Cmd* o asm("$12") = (O); register u32 v asm("$15") = (u32)(VT); register u32 r asm("$14") = 0x100; o->f.v = r; r = (ID); asm volatile(""); *(u32*)&o->vt = v; o->id = r; } while (0)
static inline void cmd_set_t(Cmd* o, void** vt, u32 id, u32 fl) { *(u32*)&o->vt = (u32)vt; o->f.v = fl; o->id = id; asm("" : : "r"(fl)); }
static inline void cmd_base(Cmd* o, u32 id) { o->vt = D_0034eb00; o->id = id; func_0031e938(&o->f); }

void wt17aad0(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_0017aad0jjjj");
void wt17aad0(u32 init, u32 prio, u32, u32)
{
    NoTail keep;
    if (prio == 0xffff && init == 1) cmd_set_t(&D_01c60030, D_0034eb60, 0, 0x180);
    if (prio == 0xffff && init == 1) cmd_set_t(&D_01c60040, D_0034eb90, 1, 0x181);
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60050, D_003502a8, 2, 0x105);
    if (prio == 0xffff && init == 1) cmd_def(&D_01c60060, D_0034eb30, 3);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60070, 4);
        *(u32*)&D_01c60070.vt = (u32)D_00350480;
        D_01c60070.f.v |= 0x1c1;
    }
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60080, D_003504b0, 5, 0x102);
    if (prio == 0xffff && init == 1) cmd_def(&D_01c60090, D_003506c0, 6);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600a0, 7);
        *(u32*)&D_01c600a0.vt = (u32)D_003506f0;
        D_01c600a0.f.v |= 0x101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600b0, 8);
        *(u32*)&D_01c600b0.vt = (u32)D_00350720;
        D_01c600b0.f.v |= 0x142;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600c0, 9);
        *(u32*)&D_01c600c0.vt = (u32)D_00350fb0;
        D_01c600c0.f.v |= 0x101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600d0, 10);
        *(u32*)&D_01c600d0.vt = (u32)D_00351040;
        D_01c600d0.f.v |= 0x4012a;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600e0, 11);
        *(u32*)&D_01c600e0.vt = (u32)D_00351190;
        D_01c600e0.f.v |= 0x103;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c600f0, 12);
        *(u32*)&D_01c600f0.vt = (u32)D_003512b8;
        D_01c600f0.f.v |= 0x101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60100, 13);
        *(u32*)&D_01c60100.vt = (u32)D_00351288;
        D_01c60100.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60110, 14);
        *(u32*)&D_01c60110.vt = (u32)D_00351378;
        D_01c60110.f.v |= 0x311;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60120, 15);
        *(u32*)&D_01c60120.vt = (u32)D_00351348;
        D_01c60120.f.v |= 0x112;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60130, 16);
        *(u32*)&D_01c60130.vt = (u32)D_003514f0;
        D_01c60130.f.v |= 0x100;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60140, 17);
        *(u32*)&D_01c60140.vt = (u32)D_00351520;
        D_01c60140.f.v |= 0x4101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60150, 18);
        *(u32*)&D_01c60150.vt = (u32)D_00351550;
        D_01c60150.f.v |= 0x4101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60160, 19);
        *(u32*)&D_01c60160.vt = (u32)D_00350fe0;
        D_01c60160.f.v |= 0x902;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60170, 20);
        *(u32*)&D_01c60170.vt = (u32)D_00351010;
        D_01c60170.f.v |= 0x40123;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60180, 21);
        *(u32*)&D_01c60180.vt = (u32)D_00351ed8;
        D_01c60180.f.v |= 0x16b;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60190, 22);
        *(u32*)&D_01c60190.vt = (u32)D_00351f08;
        D_01c60190.f.v |= 0x100;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601a0, 23);
        *(u32*)&D_01c601a0.vt = (u32)D_00351f40;
        D_01c601a0.f.v &= ~0x100;
        D_01c601a0.f.v |= 0x20000;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601b0, 24);
        *(u32*)&D_01c601b0.vt = (u32)D_00362e30;
        D_01c601b0.f.v |= 0x12902;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601c0, 24);
        *(u32*)&D_01c601c0.vt = (u32)D_00362e00;
        D_01c601c0.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601d0, 26);
        *(u32*)&D_01c601d0.vt = (u32)D_003521a8;
        D_01c601d0.f.v |= 0x101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601e0, 31);
        *(u32*)&D_01c601e0.vt = (u32)D_00363928;
        D_01c601e0.f.v |= 0x502;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c601f0, 13);
        *(u32*)&D_01c601f0.vt = (u32)D_003633d8;
        D_01c601f0.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60200, 28);
        *(u32*)&D_01c60200.vt = (u32)D_00352330;
        D_01c60200.f.v &= ~0x100;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60210, 29);
        *(u32*)&D_01c60210.vt = (u32)D_00352610;
        D_01c60210.f.v |= 0x18a;
    }
    if (prio == 0xffff && init == 1) func_002dfb10(&D_01c60220);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c602a0, 32);
        *(u32*)&D_01c602a0.vt = (u32)D_00363958;
        D_01c602a0.f.v |= 0x502;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c602b0, 33);
        *(u32*)&D_01c602b0.vt = (u32)D_00363988;
        D_01c602b0.f.v |= 0x542;
    }
    if (prio == 0xffff && init == 1) {
        func_002dea00(&D_01c602c0, 100.0f, 0.0f);
        D_01c602c0.vt = D_00362cc8;
    }
    if (prio == 0xffff && init == 1) {
        func_002dea00(&D_01c60300, -100.0f, 0.0f);
        D_01c60300.vt = D_00362c70;
    }
    if (prio == 0xffff && init == 1) func_002ea2d8(&D_01c60340);
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60350, D_00362548, 37, 0x102);
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60360, D_003624b8, 38, 0x102);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60370, 39);
        *(u32*)&D_01c60370.vt = (u32)D_00352640;
        D_01c60370.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60380, 40);
        *(u32*)&D_01c60380.vt = (u32)D_00352710;
        D_01c60380.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60390, 41);
        *(u32*)&D_01c60390.vt = (u32)D_003526e0;
        D_01c60390.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c603a0, 42);
        *(u32*)&D_01c603a0.vt = (u32)D_00363660;
        D_01c603a0.f.v |= 0x100;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c603b0, 43);
        *(u32*)&D_01c603b0.vt = (u32)D_003634c0;
        D_01c603b0.f.v |= 0x1900;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c603c0, 44);
        *(u32*)&D_01c603c0.vt = (u32)D_00363490;
        D_01c603c0.f.v |= 0x1901;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c603d0, 45);
        *(u32*)&D_01c603d0.vt = (u32)D_00363460;
        D_01c603d0.f.v |= 0x1941;
    }
    if (prio == 0xffff && init == 1) cmd_set(&D_01c603e0, D_00363510, 46, 0x902);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c603f0, 47);
        *(u32*)&D_01c603f0.vt = (u32)D_00361950;
        D_01c603f0.f.v |= 0x900;
    }
    if (prio == 0xffff && init == 1) cmd_def(&D_01c60400, D_00363608, 48);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60410, 49);
        *(u32*)&D_01c60410.vt = (u32)D_003635d8;
        D_01c60410.f.v |= 0x101;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60420, 50);
        *(u32*)&D_01c60420.vt = (u32)D_003636f0;
        D_01c60420.f.v |= 0x10a;
    }
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60430, D_003635a8, 51, 0x101);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60440, 52);
        *(u32*)&D_01c60440.vt = (u32)D_00363690;
        D_01c60440.f.v |= 0x10a;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60450, 53);
        *(u32*)&D_01c60450.vt = (u32)D_00362f20;
        D_01c60450.f.v |= 0x10902;
        D_01c60450.f.v |= 0x40000;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60460, 24);
        *(u32*)&D_01c60460.vt = (u32)D_00362ef0;
        D_01c60460.f.v |= 0x102;
    }
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60470, D_00362518, 55, 0x102);
    if (prio == 0xffff && init == 1) cmd_set(&D_01c60480, D_003624e8, 56, 0x102);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c60490, 57);
        *(u32*)&D_01c60490.vt = (u32)D_003636c0;
        D_01c60490.f.v |= 0x10a;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c604a0, 58);
        *(u32*)&D_01c604a0.vt = (u32)D_00361ac0;
        D_01c604a0.f.v |= 0x902;
        D_01c604a0.f.v &= ~0x100;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c604b0, 59);
        *(u32*)&D_01c604b0.vt = (u32)D_00361af0;
        D_01c604b0.f.v |= 0x8900;
    }
    if (prio == 0xffff && init == 1) cmd_set(&D_01c604c0, D_003639b8, 60, 0x900);
    if (prio == 0xffff && init == 1) cmd_set(&D_01c604d0, D_00363578, 61, 0x2101);
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c604e0, 62);
        *(u32*)&D_01c604e0.vt = (u32)D_00363a18;
        D_01c604e0.f.v |= 0x900;
    }
    if (prio == 0xffff && init == 1) {
        cmd_base(&D_01c604f0, 63);
        *(u32*)&D_01c604f0.vt = (u32)D_003639e8;
        D_01c604f0.f.v |= 0x901;
    }
    if (prio == 0xffff && init == 0) D_01c60340.vt = D_00363410;
    if (prio == 0xffff && init == 0) {
        D_01c60300.vt = D_00362c70;
        func_002dea80(&D_01c60300);
    }
    if (prio == 0xffff && init == 0) {
        D_01c602c0.vt = D_00362cc8;
        func_002dea80(&D_01c602c0);
    }
    if (prio == 0xffff && init == 0) {
        D_01c60220.vt = D_00362c18;
        func_002dea80(&D_01c60220);
    }
}

}
}  // namespace b5

// 0017bef8: __tcf_0 of the function-local static in 0x17a968 (empty dtor).
namespace b6 {
void tcf0(void) asm("func_0017bef8");
void tcf0(void) {}

u32 wt17aad0(u32, u32, u32, u32) asm("_Z16wtarget_0017aad0jjjj");

// 0017bf00: _GLOBAL__I_ stub.
u32 gi(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0017bf00");
u32 gi(u32 a0, u32 a1, u32 a2, u32 a3) { return wt17aad0(1, 0xffff, a2, a3); }

// 0017bf20: _GLOBAL__D_ stub (never written before).
u32 gd(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0017bf20");
u32 gd(u32 a0, u32 a1, u32 a2, u32 a3) { return wt17aad0(0, 0xffff, a2, a3); }
}  // namespace b6
