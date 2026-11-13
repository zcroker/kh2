#include "../../common/types.h"

// YS::PARTY (0x175670-0x177dc8): the party member object shared by the player and the friends:
// construction (C2/C1), the per-frame hooks of the PARTY vtable (retail data at 0x34e8b0), weapons,
// items, combos, MP and voices; incl. the never-written vtable entry 0x1767b8. Each function keeps the
// declarations of the source it was matched in (namespace pN); every symbol is bound by asm label.


// 00175670 (src/anon/batch_w8001_nsa.cpp)
namespace p0 {
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00185ed8");
s32 func_001d7ec8(u32) asm("func_001d7ec8");
void* func_0016a070(u8*) asm("func_0016a070");
s32 func_001afe30(void*) asm("func_001afe30");
extern u8 D_0034e8b8 asm("D_0034e8b8");
extern u8 D_00350e60 asm("D_00350e60");

// The s32 return keeps v live past its store to 2852, so sched1 keeps the
// original store order (v0 already holds v on every path).
s32 func_00175670(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00185ed8(p, a1, a2, a3);
    *(s32*)(p + 2788) = 0;
    *(s32*)(p + 2796) = 0;
    *(u32*)p = (u32)&D_0034e8b8;
    s32 v = func_001d7ec8(*(u16*)(*(u8**)(p + 8) + 78));
    *(u32*)(p + 2800) = v;
    *(u8*)(p + 2804) = 0;
    *(s32*)(p + 2816) = 0;
    *(u8*)(p + 2820) = 0;
    *(u8*)(p + 2821) = 0;
    u8* s = p + 2824;
    *(s32*)(s + 4) = 0;
    *(s32*)(s + 8) = -1;
    *(s32*)(s + 12) = 0;
    *(s32*)(s + 16) = 0;
    *(s32*)(s + 20) = 6144;
    *(u32*)(p + 2824) = (u32)&D_00350e60;
    *(u32*)(p + 1416) |= 4;
    *(u32*)(p + 1536) &= ~0x78;
    *(s32*)(p + 2856) = 0;
    *(s32*)(p + 944) = 1;
    *(s32*)(p + 2808) = 0;
    *(s32*)(p + 2812) = 0;
    if (*(s32*)(p + 2488) == 0) {
        v = func_001afe30(func_0016a070(p));
        if (v >= 0) {
            *(s32*)(s + 8) = -1;
            *(s32*)(s + 20) = 6144;
            *(s32*)(s + 12) = 0;
            *(s32*)(s + 16) = 0;
            *(s32*)(s + 28) = v;
            *(u32*)(p + 2824) = (u32)&D_00350e60;
            *(s32*)(s + 4) = 1;
            *(u8**)(p + 2488) = s;
        }
    }
    return v;
}
}  // namespace p0

// 00175790 (src/anon/batch_w8001_nsa.cpp)
namespace p1 {
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00185ed8");
s32 func_001d7ec8(u32) asm("func_001d7ec8");
void* func_0016a070(u8*) asm("func_0016a070");
s32 func_001afe30(void*) asm("func_001afe30");
extern u8 D_0034e8b8 asm("D_0034e8b8");
extern u8 D_00350e60 asm("D_00350e60");

s32 func_00175790(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00185ed8(p, a1, a2, a3);
    *(s32*)(p + 2788) = 0;
    *(s32*)(p + 2796) = 0;
    *(u32*)p = (u32)&D_0034e8b8;
    s32 v = func_001d7ec8(*(u16*)(*(u8**)(p + 8) + 78));
    *(u32*)(p + 2800) = v;
    *(u8*)(p + 2804) = 0;
    *(s32*)(p + 2816) = 0;
    *(u8*)(p + 2820) = 0;
    *(u8*)(p + 2821) = 0;
    u8* s = p + 2824;
    *(s32*)(s + 4) = 0;
    *(s32*)(s + 8) = -1;
    *(s32*)(s + 12) = 0;
    *(s32*)(s + 16) = 0;
    *(s32*)(s + 20) = 6144;
    *(u32*)(p + 2824) = (u32)&D_00350e60;
    *(u32*)(p + 1416) |= 4;
    *(u32*)(p + 1536) &= ~0x78;
    *(s32*)(p + 2856) = 0;
    *(s32*)(p + 944) = 1;
    *(s32*)(p + 2808) = 0;
    *(s32*)(p + 2812) = 0;
    if (*(s32*)(p + 2488) == 0) {
        v = func_001afe30(func_0016a070(p));
        if (v >= 0) {
            *(s32*)(s + 8) = -1;
            *(s32*)(s + 20) = 6144;
            *(s32*)(s + 12) = 0;
            *(s32*)(s + 16) = 0;
            *(s32*)(s + 28) = v;
            *(u32*)(p + 2824) = (u32)&D_00350e60;
            *(s32*)(s + 4) = 1;
            *(u8**)(p + 2488) = s;
        }
    }
    return v;
}
}  // namespace p1

// 001758b0 (src/anon/auto80_199_queue.cpp)
namespace p2 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_001bb9b0(u32) asm("func_001bb9b0");
void func_00180800(u32, u32) asm("func_00180800");
void func_00177540(u32) asm("func_00177540");
u32 func_0016a020(...) asm("func_0016a020");
u32 func_0016bd60(...) asm("func_0016bd60");
u32 func_00198450(...) asm("func_00198450");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
u32 fn(...) asm("fn");
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

u32 func_001758b0(u32 a0) {
    u32 s0 = a0;
    if (func_001bb9b0(a0) != 0) {
        func_00180800(s0 + 320, 0);
        func_00177540(s0);
    }

    u32 t6 = *(u32*)(s0 + 0);
    u32 fn = *(u32*)(t6 + 140);
    ((void(*)(u32))fn)(s0);

    u32 v0 = func_0016a020(s0);
    if (v0 == 1279) {
        func_0016bd60(s0, 10);
    }

    return func_00198450(s0);
}
}  // namespace p2

// 00175928 (src/anon/batch_w84.cpp)
namespace p3 {
typedef void (*VFn)(void*);
struct VObj { VFn* vt; };
s32 func_001c0cd8(void*) asm("func_001c0cd8");
void func_001c0e60(void*) asm("func_001c0e60");
void func_00177498(void*) asm("func_00177498");
void func_001a1840(void*) asm("func_001a1840");
void func_00186020(void*) asm("func_00186020");

void func_00175928(u8* p) {
    if (*(u32*)(p + 264) & 0x10000000) return;
    if (func_001c0cd8(p)) func_001c0e60(p);
    func_00177498(p);
    VObj** a = (VObj**)(p + 2808);
    for (s32 i = 1; i >= 0; i--) {
        VObj* o = *a++;
        if (o) o->vt[8](o);
    }
    if (*(void**)(p + 1164)) func_001a1840(*(void**)(p + 1164));
    func_00186020(p);
}
}  // namespace p3

// 001759f0 (src/anon/batch_w52.cpp)
namespace p4 {
struct Obj;
typedef void (*ObjFn)(Obj*, ...);
struct Obj {
    ObjFn* vt;
};
u32 func_00198510(u8*) asm("func_00198510");

u32 func_001759f0(u8* p) {
    if (!func_00198510(p)) return 0;
    u32** a = (u32**)(p + 2808);
    s32 i;
    for (i = 0; i < 2; i++) {
        u32* o = *a++;
        if (o && !((u32 (*)(void*))(((u32*)*o)[9]))(o)) return 0;
    }
    return 1;
}
}  // namespace p4

// 00175a70 (src/anon/batch_w58.cpp)
namespace p5 {
struct VObj { void** vt; };
typedef void (*VFn)(void*);
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
void func_0016b668(u8*) asm("func_0016b668");

void func_00175a70(u8* p) {
    if (!(*(u32*)(p + 264) & 0x10000000)) ((VFn)(*(VObj*)p).vt[8])(p);
    VObj** a = (VObj**)(p + 2808);
    for (s32 i = 1; i >= 0; i--) {
        VObj* o = *a++;
        if (o) ((VFn)o->vt[10])(o);
    }
    func_0016b668(p);
}
}  // namespace p5

// 00175af8 (src/anon/auto80_199_queue.cpp)
namespace p6 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_0013cb90(void) asm("_ZN2dk12COMMAND_DRAW15getShortCutTypeEv");
void func_0013edd0(u32 a0, f32 a1) asm("_ZN2dk7Ft4Base6setRotEf");
void func_0013ede0(u32 a0, u32 a1, u32 a2) asm("_ZN2dk7Ft4Base11setCenterXYEii");
void func_00138c40(u32, u32, u32) asm("_ZN2dk6Sprite6setPosEii");
extern "C" u32 func_002ba358() asm("_ZN5SOUND13isSeAlertPlayEv");
extern "C" u32 func_001917c0(...) asm("_ZN2YS6STATUS12IsBattleModeEv");
void func_00176a68(u32) asm("func_00176a68");
void func_00176c68(u32) asm("func_00176c68");
void func_00176f00(u32) asm("func_00176f00");
u32 func_00187750(...) asm("func_00187750");
extern "C" u32 func_002bc798(...) asm("_ZN5SOUND10SE3DEnableEv");
extern "C" u32 func_0016bff0(...) asm("_ZN2YS3OBJ10get_serialEv");
extern "C" u32 func_001dc9d0(u32 a0) asm("_ZN3ryj6EFFECT8is_aliveEv");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
extern "C" u32 func_00228378() asm("_ZN2sa5EVENT16isSceneEventExecEv");
extern "C" u32 func_0022d6d8() asm("_ZN2sa5EVENT7wide_onEv");
void func_001382b8(u32) asm("_ZN2dk13TREASURE_INFO13openEventInfoEi");
extern "C" void func_002400f8(u32 a0) asm("_ZN2Tz5MCard13SetSystemModeEi");
extern "C" u32 func_00241450(u32 a0) asm("_ZN2Tz5MCard6ChgDirEi");
extern "C" u32 func_002414c0(void) asm("_ZN2Tz5MCard7MakeDirEv");
extern "C" u32 func_00241ed8(u32 a0) asm("_ZN2Tz5MCard12ChgWorldNameEi");
extern "C" u32 func_00242790(void) asm("_ZN2Tz9MenuSound10ResetPauseEv");
u32 func_00246840(...) asm("_ZN2Tz7SubMenu13GetCallSignalEv");
u32 func_00258c48(void) asm("_ZN2Tz5Pause10isLoopFadeEv");
extern "C" u32 func_0028d620(...) asm("_ZN2Tz8LightCur5LeaveEv");
extern "C" u32 func_00263d28(...) asm("_ZN2Tz9CMenuHelp5LeaveEv");
extern "C" void func_00287da0(void) asm("_ZN2Tz8MenuBase7SetExitEv");
extern "C" u32 func_00256ea8(...) asm("_ZN2Tz5CmTop12LeavePadHelpEv");
extern "C" u32 func_0028be18(...) asm("_ZN2Tz9ScrollBar5LeaveEv");
void func_00138c68(u32 a0, u32 a1, u32 a2) asm("_ZN2dk6Sprite12setOffsetPosEii");
u32 func_002570a0(u32 a0) asm("_ZN2Tz5CmTop12GetSelectPosEi");
u32 func_002815b8() asm("_ZN2Tz9PartyInfo10GetNowFormEv");
extern "C" u32 func_00242618(...) asm("_ZN2Tz9MenuSound6PlaySEEib");
extern "C" u32 func_0028d6e8(...) asm("_ZN2Tz8LightCur7isExistEv");
extern "C" void func_0027f370(void) asm("_ZN2Tz9GumiPause8SetupTopEv");
u32 func_00281238(u32, u32) asm("_ZN2Tz9PartyInfo10GetEntryIdEi");
typedef void (*Fn1)(u32);
extern "C" u32 func_00293fb0(void) asm("_ZN2Tz6JmInfo6isInitEv");
extern "C" void func_00258bc0(u32) asm("_ZN2Tz5Pause7EndFadeEPFvvE");
u32 func_00258c18(void) asm("_ZN2Tz5Pause11isExistFadeEv");
typedef s32 (*Cb_0028d730)(u32);
typedef void (*Fn_0028e080)(u32, u32);
extern "C" u32 func_00293d80(...) asm("_ZN2Tz6JMData5ClearEi");
extern "C" void func_0028d5d0(u32 a0) asm("_ZN2Tz8LightCur7FadeOutEv");
extern "C" void func_00293eb0(void) asm("_ZN2Tz6JmInfo4ExitEv");
typedef void (*VFn)(u32);
extern "C" void func_00274ee8(u32) asm("_ZN2Tz6Jiminy6WMInitEP9ALLOCATOR");
extern "C" u32 func_00289310(u32) asm("_ZN2Tz6Select12isCursorMoveEv");
void func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);
void func_00242fc8(s32 a0) asm("_ZN2Tz7SubMenu4ExitEi");
void func_002430d8(const char* a0) asm("_ZN2Tz7SubMenu11SetLeadDataEPKc");
extern "C" u32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
extern "C" u32 func_001dc9d0(u32) asm("_ZN3ryj6EFFECT8is_aliveEv");
extern "C" void RECOM_FLAG_clear_0019f578(u32) asm("_ZN2YS10RECOM_FLAG5clearEv");

u32 func_00175af8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0x00100000;

    u32 t7 = *(u32*)(a0 + 264);
    if ((t7 & s1) == 0) {
        if (YS_STATUS_IsBattleMode() != 0) {
            t7 = *(u32*)(s0 + 264);
            t7 |= s1;
            *(u32*)(s0 + 264) = t7;
        }
    }

    func_00176a68(s0);
    func_00176c68(s0);
    func_00176f00(s0);
    return func_00187750(s0);
}
}  // namespace p6

// 00175b68 (src/anon/batch_w27.cpp)
namespace p7 {
void wtarget_00102c90(u32, u32, u32, u32) asm("_Z16wtarget_00102c90jjjj");
void wtarget_0016c640(u32, u32, u32, u32) asm("_Z16wtarget_0016c640jjjj");
void wtarget_001954a0(u32, u32, u32, u32) asm("_Z16wtarget_001954a0jjjj");
void u_call0_001d3b68(void) asm("_Z16u_call0_001d3b68v");
void u_call4_002908f0(u32, u32, u32, u32) asm("_Z16u_call4_002908f0jjjj");
struct S102c90 {
    void* vt;
    u32 f4;
    u8 f8;
    u8 pad9[11];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
    u32 f40;
};
extern S102c90 D_0032b968 asm("D_0032b968");
extern u32 D_0032b930 asm("D_0032b930");
void* func_001b9bc8(void*) asm("func_001b9bc8");
void func_0016c5a0(void*, u32) asm("func_0016c5a0");
void func_0016b010(void*, void*) asm("func_0016b010");  // obj_set_float1644_from_pair
void func_00198690(void*) asm("func_00198690");

void func_00175b68(void** o) {
    u32 t[4] __attribute__((aligned(16)));
    if ((*(s32 (**)(void*))(*(u8**)o + 132))(o)) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(t), "r"((u8*)o + 16) : "$8", "memory");
        func_0016b010(o, t);  // obj_set_float1644_from_pair
    }
    func_00198690(o);
}
}  // namespace p7

// 00175bb8 (src/anon/batch_w86.cpp)
namespace p8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Info { u8 p0[8]; u32 f8; };
struct Obj { u8 p0[12]; Info* info; QWord pos; u8 p32[320]; s32 f352; u8 p356[4]; u32 f360; };
static inline bool Flag(Obj* o)
{
    u32 f = o->f360;
    bool r = false;
    if (f & 4) {
        u32 m = f & 8;
        r = m == 0;
    }
    return r;
}
double func_00313b80(f32) asm("func_00313b80");  // float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");  // double_compare

s32 func_00175bb8(Obj* o)
{
    QWord v = o->pos;
    bool ok = false;
    if (0.0f < v.v[3] && (func_003142e0(func_00313b80(v.v[0]), 0.0) != 0 || v.v[2] != 0.0f)) ok = true;
    bool no = !ok;
    if (no) return 0;
    if (Flag(o)) return 1;
    if (!(o->info->f8 & 0x100)) return 0;
    s32 zero = 0;
    s32 neg = o->f352 < zero;
    return neg == 0;
}
}  // namespace p8

// 00175c88 (src/anon/batch_w2414_nsa.cpp)
namespace p9 {
struct W1621Rec20 { u32 w[5]; };
struct W1621Msg { u16 id; u16 arg; u32 flags; W1621Rec20 rec; };
struct W1621Obj;
struct W1621Ent { u16 a; u16 kind; };
typedef s32 (*W1621Fn)(...);
typedef void (*W1621VFn)(...);
struct W1621Obj { W1621Fn* vt; };
s32 func_00176868(u8*, W1621Msg*) asm("func_00176868");
void func_00176dd8(u8*, W1621Ent*, W1621Rec20*, s32) asm("func_00176dd8");
u8* p175c88_get_ability(u8*) asm("_ZN2YS5PARTY11get_abilityEv");
s32 func_00177ab8(u8*, u8) asm("func_00177ab8");
void func_00178a50(u8*, W1621Ent*) asm("func_00178a50");
void func_0017a590(u8*, u16) asm("func_0017a590");
W1621Ent* p175c88_lookup(u16) asm("_Z16u_call4_001b8e88jjjj");
static inline u32 W1621A(u8* p) { return *(u32*)(p + 0x160) & 4; }
static inline u32 W1621B(u8* p) { return *(u32*)(p + 0x160) & 8; }
static inline u32 W1621C(u8* p) { return *(u32*)(p + 0x160) & 0x10; }
static inline bool W1621Any(u8* p) { return W1621A(p) || W1621B(p) || W1621C(p); }

W1621Ent* func_00175c88(u8* p, W1621Msg* m)
{
    u8 buf[16];  /* unused local: the original frame has 16 bytes of locals (debug buffer?) */
    *(u32*)(p + 0x10c) &= ~0x40000;
    if (m->flags & 2) {
        if (W1621Any(p) || *(s32*)(p + 0x154) == 5) {
            W1621Obj* o = *(W1621Obj**)(p + 12);
            ((W1621VFn)o->vt[8])(o, p, 1);
        }
    }
    if (*(u32*)(p + 0x108) & 0x20000) {
        if ((m->flags & 1) == 0)
            *(u32*)(p + 0x108) = (*(u32*)(p + 0x108) & ~0x20000) | 0x40000;
    }
    if (*(u32*)(p + 0x10c) & 4) {
        if (!(m->flags & 4))
            *(u32*)(p + 0x10c) &= ~4;
    }
    if (func_00176868(p, m)) return 0;
    if (m->flags & 8) {
        if (((W1621Obj*)p)->vt[32](p)) return 0;
    }
    W1621Ent* r = p175c88_lookup(m->id);
    if (r->kind == 0) return 0;
    *(W1621Rec20*)(p + 0x9f4) = m->rec;
    if (*(u32*)(p + 0x588) & 0x80) func_00178a50(p, r);
    switch (r->kind) {
    case 1: {
        u8 x = (*(u32*)(p + 0x108) & 0x2000000) || (*(u32*)(p175c88_get_ability(p) + 0x14) & 0x2000);
        if (func_00177ab8(p, x)) { ((W1621VFn)((W1621Obj*)p)->vt[31])(p); break; }
        return 0;
    }
    case 0x16d:
        if (func_00177ab8(p, 1)) { ((W1621VFn)((W1621Obj*)p)->vt[31])(p); break; }
        return 0;
    case 3:
        func_00176dd8(p, r, &m->rec, 1);
        break;
    case 2:
        if (!func_00177ab8(p, 1)) return 0;
        *(u32*)(p + 0x490) = m->arg;
        p[0xaf4] = ((u8*)m)[5];
        func_0017a590(p, m->id);
        break;
    default:
        ((W1621VFn)((W1621Obj*)p)->vt[38])(p, r);
        break;
    }
    *(u32*)(p + 0x108) &= ~0x2000000;
    return r;
}
}  // namespace p9

// 00175f68 (src/anon/batch_w1986_nsa.cpp)
namespace p10 {
struct W1986Ob;
struct W1986Vt {
    void* f[15];
    s32 (*get)(W1986Ob*);
    void* g[2];
    void (*act)(W1986Ob*);
};
struct W1986Ob {
    W1986Vt* vt;
    u8 pad4[0x9b0];
    s16* p9b4;
};
struct W1986Ch { u8 pad[0x4e]; u16 id; };
struct W1986Tg {
    u8 pad0[8];
    W1986Ch* ch;
    u8 padc[0x57c];
    u32 flags;
    u8 pad58c[0x56c];
    W1986Ob* obj[4];
};
W1986Tg* func_00176b58(u32) asm("func_00176b58");
s32 func_0019c5d0(W1986Ob*) asm("func_0019c5d0");
void func_00185a28(W1986Ob*) asm("func_00185a28");
void* func_001d1438(s32) asm("func_001d1438");
W1986Ch* func_0016e920(void*) asm("func_0016e920");
void func_001703a8(s32) asm("func_001703a8");
s32 func_00185890(u32, u32) asm("func_00185890");
void func_0016ef58(u32, u32, s32, s32, s32) asm("func_0016ef58");
void func_00170888(u32) asm("func_00170888");
void func_00176168(W1986Tg*, s32, u32) asm("func_00176168");
s32 func_00103b38(void) asm("func_00103b38");
void func_001617d8(void) asm("func_001617d8");
void* func_001a90f0(u32) asm("func_001a90f0");
s32 func_0016f930(void*) asm("func_0016f930");
static inline s32 W1986_hid(W1986Ob* o) { return o->p9b4 ? *o->p9b4 : -1; }

void wtarget_00175f68(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00175f68jjjj");
void wtarget_00175f68(u32 a, u32 b, u32 c, u32 d)
{
    s32 nb = 0;
    W1986Tg* t = func_00176b58(b);
    s32 r;
    s32 h;
    u32 id;
    s32 q;
    if (t != 0) {
        W1986Ob* o = t->obj[c];
        r = o->vt->get(o);
        h = W1986_hid(o);
        nb = func_0019c5d0(o);
        func_00185a28(o);
        *(u32*)&t->obj[c] = 0;
        id = t->ch->id;
        if (id != 53 && (t->flags & 0x1000000) && c == 0) {
            id = func_0016e920(func_001d1438(0))->id;
        }
    } else {
        q = (s32)func_001a90f0(b);
        r = func_0016f930((void*)q);
        switch (r) {
        case 2410:
            h = 5;
            break;
        case 2420:
            h = 6;
            break;
        default:
            return;
        }
        r++;
        id = func_0016e920((void*)q)->id;
    }
    func_001703a8(r);
    q = func_00185890(id, d);
    func_0016ef58(id, c, q, r, h);
    func_00170888(a);
    if (t == 0) return;
    func_00176168(t, q, c);
    if (nb == 0) t->obj[c]->vt->act(t->obj[c]);
    if (func_00103b38()) func_001617d8();
}
}  // namespace p10

// 00176168 (src/anon/batch_w1810_nsa.cpp)
namespace p11 {
/* Built with -fno-strict-aliasing (the _nsa rule in the Makefile). */

void func_0017f488(int, int, float, float) asm("func_0017f488");
void* w1810_area_alloc(u32) asm("_ZN4AREA5AllocEj");
int w1810_getcharadata(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void w1810_set_mode(void*, int) asm("_ZN2YS6MOTION8set_modeEi");
int func_0017a538(void*) asm("func_0017a538");
void func_00185468(void*, int, void*, u32, int, int) asm("func_00185468");
struct W1810S8 { u8 pad[0x4e]; u16 h; };
struct W1810Sub { u8 pad[0x14]; int a; u8 p2[4]; int b; u8 p3[0x10]; float f; };
struct W1810Obj;
struct W1810VT { void* p[15]; int (*f3c)(W1810Obj*); };
struct W1810Obj { W1810VT* vt; u8 pad[4]; W1810S8* s8; };

void func_00176168(W1810Obj* o, u32 id, int n)
{
    W1810Sub* s = (W1810Sub*)((u8*)o + 0x140);
    int k;
    if ((*(u32*)((u8*)o + 0x588) & 0x80) && func_0017a538(o) != 0 && n == 0) {
        k = 2301;
    } else {
        k = o->vt->f3c(o);
        k += n + 1;
    }
    u8* p = (u8*)w1810_area_alloc(0xa10);
    func_00185468(p, w1810_getcharadata(id), o, o->s8->h, n, k);
    ((u8**)((u8*)o + 0xaf8))[n] = p;
    w1810_set_mode(p + 0x140, s->b);
    func_0017f488((int)(p + 0x140), s->a, 0.0f, s->f);
}
}  // namespace p11

// 00176258 (src/anon/batch_w44.cpp)
namespace p12 {
typedef s32 (*IFn)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, u32, u32);
typedef u32 (*AllocFn)(void*, u32, s32);
s32 func_0019c5d0(void*) asm("func_0019c5d0");

s32 func_00176258(u8* o) {
    void** p = (void**)(o + 2808);
    for (s32 i = 0; i < 2; i++) {
        void* e = *p++;
        if (e && !func_0019c5d0(e)) return 1;
    }
    return 0;
}
}  // namespace p12

// 001762c0 (src/anon/tiny_auto80_solver.cpp)
namespace p13 {
u32 func_0016a080(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0016a080");
u32 func_001762c0(u32, u32) asm("func_001762c0");
u32 func_001c2d48(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001c2d48");

u32 func_001762c0(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 v0 = ((u32(*)(u32))func_0016a080)(a0);
    s0 <<= 1;
    v0 = ((u32(*)(u32))func_001c2d48)(v0);
    return (u32)(s32)*(s16*)(s0 + v0 + 4);
}
}  // namespace p13

// 001762f8 (src/anon/batch_w95.cpp)
namespace p14 {
struct TaskB { u8 pad0[4]; f32 t; u8 pad8[8]; u32 mode; u8 pad20[28]; void* fn; };
struct EvInfo { u8 pad[4]; u8 kind; };
struct HitEv { u8 pad0[32]; EvInfo* info; u8 pad36[2]; u8 type; u8 pad39; s32 power; };
struct ActObj;
struct ActVt { u8 pad[96]; s32 (*canHit)(ActObj*); void* slot100; void (*onHit)(ActObj*, HitEv*); };
struct ActMask { u32 a, b, c; };
struct ActObj { ActVt* vt; u8 pad4[2036]; u32 flags; u8 pad2044[704]; ActMask mask; };
static inline u8 IsGuardKind(HitEv* e) { return (u32)(e->info->kind - 5) < 2; }
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
TaskB* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_001c20e8(u32, HitEv*, ActObj*) asm("func_001c20e8");
void func_00186d48(ActObj*, HitEv*) asm("func_00186d48");
s32 func_0018ca48(u8) asm("func_0018ca48");
void func_0013de08(ActObj*) asm("func_0013de08");
void func_0013de58(ActObj*) asm("func_0013de58");
void func_0013dea8(ActObj*) asm("func_0013dea8");
void func_00186148(ActObj*, HitEv*) asm("func_00186148");

void func_001762f8(ActObj* o, HitEv* e) {
    if ((o->flags & 4) || o->vt->canHit(o)) {
        if (!IsGuardKind(e)) return;
    }
    ActMask* m = &o->mask;
    func_001c20e8((o->mask.a | m->b) & ~m->c, e, o);
    func_00186d48(o, e);
    if (!IsGuardKind(e)) {
        if (o->flags & 4) func_0013dea8(o);
        else switch (func_0018ca48(e->type)) {
        case 3: func_0013de58(o); break;
        case 4: func_0013dea8(o); break;
        case 0: if (e->power > 0) func_0013de08(o); break;
        default: func_0013de08(o); break;
        }
    }
    o->vt->onHit(o, e);
    func_00186148(o, e);
}
}  // namespace p14

// 00176458 (src/anon/batch_w291.cpp)
namespace p15 {
struct W291C17 { u8 pad[19]; u8 b19; u8 b20; };
struct W291B17 { u8 pad[4]; u32 f4; u8 pad8[32]; W291C17* p40; };
struct W291D17 { u8 pad[8]; u32 f8; };
struct W291A17 { u8 pad[12]; W291D17* p12; u8 pad16[248]; union { u32 f264; W291B17* f264p; }; u8 pad268[84]; u32 f352; u8 pad356[1060]; u32 f1416; };
s32 func_001a3a78() asm("func_001a3a78"); void func_0018e8f0(W291B17**, s32, s32, W291B17**) asm("func_0018e8f0"); s32 func_0019c090() asm("func_0019c090");  // obj_is_enabled
void func_00187018(W291A17*, W291B17*, W291B17*, s32, f32) asm("func_00187018"); void func_00177a58(W291A17*) asm("func_00177a58");
void func_00176680(W291A17*, W291B17*, W291B17*) asm("func_00176680");
static inline bool w291_h1(W291A17* s) { return (s->p12->f8 & 2) || (s->f352 & 0x40); }
static inline bool w291_h2(W291A17* s) { return func_0019c090() || w291_h1(s); }

void func_00176458(W291A17* s, W291B17** b, W291B17** c)
{
    s->f264 |= 0x2000000;
    u8 x = (*b)->p40->b19;
    u8 y = (*c)->p40->b20;
    if (x == 2 || y == 2) {
        func_0018e8f0(b, func_001a3a78(), 13, c);
        return;
    }
    bool r = w291_h2(s);
    if (r || (x == 0 && y == 0)) {
        func_0018e8f0(b, func_001a3a78(), 13, c);
        func_00187018(s, *b, *c, -1, -1.0f);
        func_00177a58(s);
        return;
    }
    s32 k = (s->f1416 & 0x80) ? 11 : 12;
    func_0018e8f0(b, func_001a3a78(), k, c);
    func_00176680(s, *b, *c);
    (*b)->f4 |= 0x40;
}
}  // namespace p15

// 00176620 (src/anon/batch_w217.cpp)
namespace p16 {
void func_00177a58(u32*) asm("func_00177a58");
void func_00187018(u32*, u32, f32, u32, u32) asm("func_00187018");

void func_00176620(u32* a, u32 b) {
    a[66] |= 0x2000000;
    func_00177a58(a);
    return func_00187018(a, b, -1.0f, 0, -1);
}
}  // namespace p16

// 00176680 (src/anon/batch_w245.cpp)
namespace p17 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QW {
    f32 x, y, z, w;
    QW() {}
    QW(const QW& o) { QCOPY(this, &o); }
    QW& operator=(const QW& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline QW Scale(const QW& a, f32 s) {
    QW r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct Obj { u8 pad[320]; u8 sub[16]; };
QW func_0018df90() asm("func_0018df90");
void func_0016aef0(Obj*, QW*) asm("func_0016aef0");
void func_00186a90(Obj*, QW*, f32) asm("func_00186a90");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_00176a60(Obj*, f32) asm("func_00176a60");

void func_00176680(Obj* s) {
    QW v;
    v = func_0018df90();
    QW t = Scale(v, -1.0f);
    func_0016aef0(s, &t);
    func_00186a90(s, &v, 200.0f);
    func_0017f488(s->sub, 42, 0.0f, 0.0f);
    func_0017f5e0(s->sub, 0, 0, 0.0f, 0.0f);
    func_00176a60(s, 80.0f);
}
}  // namespace p17

// 00176760 (src/anon/auto80_199_queue.cpp)
namespace p18 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_0017f488(...) asm("func_0017f488");
u32 func_0017f5e0(...) asm("func_0017f5e0");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_00176760(u32 a0) {
    u32 s0 = a0 + 320;
    f32 f20 = 0.0f;

    ((u32(*)(u32, u32, f32, f32))func_0017f488)(s0, 151, f20, f20);
    return ((u32(*)(u32, u32, u32, f32, f32))func_0017f5e0)(s0, 0, 0, f20, f20);
}
}  // namespace p18

// 001767b8: virtual (PARTY vtable): reset the motion (never written before)
namespace p_67b8 {
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void motion_push(u8*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");

s32 func_001767b8(u8* o) asm("func_001767b8");
s32 func_001767b8(u8* o) {
    u8* m = o + 320;
    f32 z = 0.0f;
    func_0017f488(m, 151, z, z);
    motion_push(m, 0, z, z, 0);
    return 1;
}
}  // namespace p_67b8

// 00176818 (src/anon/batch_wcx2.cpp)
namespace p_6818 {
void func_0017f540(u8*, u32, f32, f32) asm("func_0017f540");
void func_001842c0(u8*) asm("func_001842c0");
void func_00176818(u8* p) asm("func_00176818");
void func_00176818(u8* p) {
    if (!(*(u32*)(p + 360) & 0x10)) func_0017f540(p + 320, 4, 16.0f, 0.0f);
    func_001842c0(p);
}
}  // namespace p_6818

// 00176868 (src/anon/batch_wcx2.cpp)
namespace p20 {
typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
u8* func_00177860(u8*) asm("func_00177860");
void func_00176970(u8*) asm("func_00176970");
void func_00177a28(u8*) asm("func_00177a28");  // set_bytes_2820_2821
u8* func_00176fb0(u8*, s32) asm("func_00176fb0");
s32 func_001a0920(u8*, u8*) asm("func_001a0920");
void func_00177008(u8*, u8*, u32) asm("func_00177008");

s32 func_00176868(u8* p, u8* a1)
{
    u32 f = *(u32*)(*(u8**)(p + 12) + 8);
    u8* t = *(u8**)(p + 304);
    if (f & 0x40) {
        if (f & 0x800) return 0;
        if (*(f32*)(p + 248) < *(f32*)(t + 88)) return 0;
        if (*(u32*)(p + 2040) & 4) return 0;
        if (*(u32*)(a1 + 4) & 2) {
            if (*(u32*)func_00177860(p) & 0x100000) {
                func_00176970(p);
                return 1;
            }
        }
        if (!(*(u32*)(a1 + 4) & 8)) return 0;
        func_00177a28(p);  // set_bytes_2820_2821
        u8* q = func_00176fb0(p, 40);
        if (q) {
            if (func_001a0920(q, p)) {
                func_00177008(p, q, *(u32*)(p + 2880) + 4);
                return 1;
            }
        }
    }
    return 0;
}
}  // namespace p20

// 00176970 (src/anon/batch_w1809_nsa.cpp)
namespace p21 {
struct W1809V4 {
    f32 x, y, z, w;
    W1809V4() {}
    W1809V4& operator=(const W1809V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1809O76;
struct W1809C76 { virtual void m0(); virtual void m1(); virtual void fn(W1809O76*, W1809V4*); };
struct W1809S76 { u8 pad[0x50]; f32 f50; f32 f54; };
struct W1809O76 {
    u8 pad0[12]; W1809C76* p0c; W1809V4 v10; u8 pad20[0x110]; W1809S76* p130; u8 pad134[0xc]; u8 x140[0x10];
};
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_0016aef0(W1809O76*, W1809V4*) asm("func_0016aef0");

void func_00176970(W1809O76* o) {
    W1809S76* s = o->p130;
    func_0017f488(o->x140, 40, 0.0f, 0.0f);
    func_0017f5e0(o->x140, 4, 0, 0.0f, 0.0f);
    W1809V4 t;
    if (o->v10.w > 0.0f) {
        t = o->v10;
        t.w = s->f54;
        func_0016aef0(o, &o->v10);
    } else {
        t.zero();
    }
    t.y = s->f50;
    o->p0c->fn(o, &t);
    o->v10.zero();
}
}  // namespace p21

// 00176a60 (src/anon/tiny_auto80_queue.cpp)
namespace p22 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);

void func_00176a60(u32 a0, u32 a1, u32 a2, f32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    *(volatile f32*)((u32)a0 + (s32)(2816)) = a3;
}
}  // namespace p22

// 00176a68 (src/anon/tiny_auto80_queue.cpp)
namespace p23 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern f32 D_00349e10 asm("D_00349e10");

void func_00176a68(u32 a0) {
    f32 f1 = *(f32*)((u32)a0 + (s32)(2816));
    if (0.0f < f1) {
        f32 f0 = *(f32*)((u32)&D_00349e10 + (s32)(0));
        f0 = (f32)(f1 - f0);
        *(f32*)((u32)a0 + (s32)(2816)) = f0;
    }
}
}  // namespace p23

// 00176a90 (src/anon/batch_w60.cpp)
namespace p24 {
extern u32 D_0034f240 asm("D_0034f240");
s32 func_00187920(void*) asm("func_00187920");
s32 func_00197e40(void) asm("func_00197e40");
void func_00102818(u32, s32, u32, void (*)(), s32) asm("func_00102818");
u8* func_00102788(u32, s32, u32, void (*)()) asm("func_00102788");

s32 func_00176a90(u8* p) {
    s32 r = 0;
    if (func_00187920(p) || (*(u32*)(p + 268) & 0x10000) || 0.0f < *(f32*)(p + 2816) || (D_0034f240 & 2) || func_00197e40()) r = 1;
    return r;
}
}  // namespace p24

// 00176b20 (src/anon/tiny_auto80_queue.cpp)
namespace p25 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern u8 D_0034e948 asm("D_0034e948");
extern "C" u32 func_0017df58(...) asm("func_0017df58");

u32 func_00176b20(u32 a0) {
    if (a0 != 0u) {
        return func_0017df58((u32)((s32)a0 + (-1)));
    }
    return *(u32*)&D_0034e948;
}
}  // namespace p25

// 00176b58 (src/anon/batch_w59.cpp)
namespace p26 {
typedef void (*VFn)(void);
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
u32 func_00176b20(s32) asm("func_00176b20");
s32 func_0016a070(u32) asm("func_0016a070");
u32 func_001d14a0(void) asm("func_001d14a0");

u32 func_00176b58(s32 id) {
    s32 i;
    for (i = 0; i < 3; i++) {
        u32 o = func_00176b20(i);
        if (o && func_0016a070(o) == id) return o;
    }
    if (id == 1) return func_001d14a0();
    return 0;
}
}  // namespace p26

// 00176be0 (src/anon/batch_w60.cpp)
namespace p27 {
void* func_001a3a78(void) asm("func_001a3a78");
s32 func_001de168(void*, s32, s32, s32, s32, void*) asm("func_001de168");  // scan_list_by_half
void func_00102818(u32, s32, u32, void (*)(), s32) asm("func_00102818");
u8* func_00102788(u32, s32, u32, void (*)()) asm("func_00102788");

void func_00176be0(u8* p, f32 v) {
    if (*(s32*)(p + 2788) == 0 && !(*(u32*)(p + 352) & 0x4000)) {
        s32 h = func_001de168(func_001a3a78(), 6, 0, 1, 10004, p);  // scan_list_by_half
        *(s32*)(p + 2788) = h;
        *(f32*)(p + 2792) = v;
    } else if (*(f32*)(p + 2792) < v) {
        *(f32*)(p + 2792) = v;
    }
}
}  // namespace p27

// 00176c68 (src/anon/batch_w45.cpp)
namespace p28 {
typedef void (*VFn)(u8*);
typedef void (*VFn3)(u8*, u32, u32);
void func_001dc840(u32) asm("func_001dc840");
extern f32 D_00349e10 asm("D_00349e10");

// count down a timer; release the handle when it expires (or when forced by flag 0x4000)
void func_00176c68(u8* a0) {
    u32 h = *(u32*)(a0 + 2788);
    if (h) {
        f32 t = *(f32*)(a0 + 2792) - D_00349e10;
        *(f32*)(a0 + 2792) = t;
        if ((*(u32*)(a0 + 352) & 0x4000) || t <= 0.0f) {
            func_001dc840(h);
            *(u32*)(a0 + 2788) = 0;
        }
    }
}
}  // namespace p28

// 00176cd0 (src/anon/batch_w51.cpp)
namespace p29 {
typedef s32 (*VFnI)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, u32);
s32 func_0019ba60(u32) asm("func_0019ba60");
u32 func_0016a070(void*) asm("func_0016a070");
s32 func_001afe70(u32, u32, u32, u32*) asm("func_001afe70");
void func_00198630(void*, s32, u32) asm("func_00198630");

void func_00176cd0(u8* p, u32 a1, u32 a2) {
    if (*(u32*)(p + 2488) == 0) return;
    u32 s2;
    if (func_0019ba60(*(u32*)(p + 2548)) && *(u8**)(p + 2548) != p) s2 = func_0016a070(*(u8**)(p + 2548));
    else s2 = 0;
    s32 r = func_001afe70(func_0016a070(p), a1, s2, &a2);
    if (r >= 0) func_00198630(p, r, a2);
}
}  // namespace p29

// 00176d68 (src/anon/batch_w31.cpp)
namespace p30 {
typedef void (*VFn)(void*);
u8* func_00102818(u32, s32, u32, void*, s32) asm("func_00102818");
void func_0014a0a0(void) asm("func_0014a0a0");
extern u32 D_0032b96c asm("D_0032b96c");
void TitleStart(bool) asm("_ZN2dk5Field10TitleStartEb");
void* func_0016a070(void*) asm("func_0016a070");
u32 func_001afee8(void*, int) asm("func_001afee8");
void func_00198630(void*, u32, int) asm("func_00198630");
void voice_part(void*, int) asm("_ZN2YS5PARTY10voice_partEi");

// YS PARTY: play a party member's voice.
void voice_part(void* self, int n) {
    func_00198630(self, func_001afee8(func_0016a070(self), n), 0);
}
}  // namespace p30

// 00176db0 (src/anon/tiny_auto80_fptr4.cpp)
namespace p31 {
u32 func_0016b558(u32, u32, u32, u32) asm("func_0016b558");

u32 func_00176db0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)(r5 << 2);
    r15 = (u32)(r15 + r4);
    r5 = r6;
    r4 = *(u32*)((u32)r15 + (s32)(2808));
    return func_0016b558(r4, r5, r6, r7);
}
}  // namespace p31

// 00176dd8 (src/anon/batch_w230.cpp)
namespace p32 {
/* 00176dd8 */
union W230U16 { u16 h; u8 c; };
struct W230T { char p[0xb2c]; W230U16 h2c; u16 h2e; void* w30; };
struct W230A { char p[4]; u16 h4; };
void* func_0016a070(void*) asm("func_0016a070");
void func_0017f488(void*, int, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, int, int, f32, f32) asm("func_0017f5e0");

void func_00176dd8(W230T* t, W230A* a1, void** a2, u32 a3) {
  t->h2c.h = a1->h4;
  if (*a2) t->w30 = func_0016a070(*a2); else t->w30 = 0;
  t->h2e = a3;
  func_0017f488((char*)t + 320, 9, 8.0f, 0.0f);
  func_0017f5e0((char*)t + 320, 0, 0, 0.0f, 0.0f);
}
}  // namespace p32

// 00176e78 (src/anon/tiny_auto80_queue.cpp)
namespace p33 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_0016a070(...) asm("func_0016a070");
extern "C" u32 func_001a3458(...) asm("func_001a3458");

u32 func_00176e78(u32 a0, u32 a1, u32 a2) {
    u32 v0 = 1u;
    u32 t6 = *(u32*)((u32)a0 + (s32)(1416));
    t6 = (u32)(t6 & 0x00400000u);
    if (t6 == 0u) {
        u32 s0 = a1;
        if (a2 != 0u) {
            v0 = func_001a3458(s0, func_0016a070());
        }
    }
    return v0;
}
}  // namespace p33

// 00176ec8 (src/anon/tiny_auto80_solver.cpp)
namespace p34 {
u32 func_00176ec8(u32) asm("func_00176ec8");
u32 func_00187850(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00187850");

u32 func_00176ec8(u32 a0) {
    u32 s0 = a0;
    void (**vt)() = *(void (***)())a0;
    ((void (*)(u32, u32, u32))vt[21])(a0, 2, 0);
    return ((u32(*)(u32))func_00187850)(s0);
}
}  // namespace p34

// 00176f00 (src/anon/batch_wcx2.cpp)
namespace p_6f00 {
s32 func_001a1de0(u32) asm("func_001a1de0");
s32 func_001b58a8() asm("func_001b58a8");
u8* func_00177860(u8*) asm("_ZN2YS5PARTY11get_abilityEv");
void func_001a1d50(u32, f32) asm("func_001a1d50");
extern f32 D_00349e10 asm("D_00349e10");
void func_00176f00(u8* p) asm("func_00176f00");
void func_00176f00(u8* p) {
    if (!*(u32*)(p + 1164)) return;
    if (!func_001a1de0(*(u32*)(p + 1164))) return;
    if (*(u32*)(p + 2040) & 4) return;
    if ((*(u32*)(p + 1416) & 0x80) && func_001b58a8()) return;
    f32 k = -D_00349e10;
    u8* r = func_00177860(p);
    func_001a1d50(*(u32*)(p + 1164), k * *(f32*)(r + 56));
}
}  // namespace p_6f00

// 00176fb0 (src/anon/auto80_199_queue.cpp)
namespace p36 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
s32 func_001d7f40(u32) asm("func_001d7f40");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_00176fb0(u32 a0) {
    u32 t6 = 0;
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 2800);

    if (t7 == 0) {
        return t6;
    }

    a0 = t7;
    s32 v0 = func_001d7f40(a0);  // find_slot_by_byte
    if (v0 < 0) {
        return t6;
    }

    u32 t7b = *(u32*)(s0 + 2800);
    a0 = (u32)(v0 * 68);
    t7b += a0;
    t6 = t7b + 4;
    return t6;
}
}  // namespace p36

// 00177008 (src/anon/batch_w1621.cpp)
namespace p_7008 {
struct W1621Rec20 { u32 w[5]; };
// 16-byte vector; the u8 member makes stores to it alias like the original (no strict aliasing).
struct W1621V4 {
    union { struct { f32 x, y, z, w; }; u8 b[16]; };
    W1621V4& operator=(const W1621V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// VU0: normalize xyz in place, return the old length.
static inline f32 W1621Norm(W1621V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
// VU0: all four lanes times s.
static inline W1621V4 operator*(const W1621V4& a, f32 s) {
    W1621V4 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct W1621Flags { u32 b0:1; u32 b1:1; u32 rest:30; };
// Reaction parameters (second argument).
struct W1621Act {
    u8 pad0[4];
    W1621Flags fl;   // 0x04
    union { u16 motion; u8 mb[2]; };  // 0x08 (union: load must not move above the record copy)
    u16 motion2;     // 0x0a
    f32 speed;       // 0x0c
    f32 f10;         // 0x10
    f32 f14;         // 0x14
    f32 lo;          // 0x18
    f32 hi;          // 0x1c
    u8 pad20[0x18];
    f32 f38;         // 0x38
    f32 f3c;         // 0x3c
};
struct W1621Ctl;
struct W1621CtlVt { void* f0; void* f4; void (*set)(W1621Ctl*, u8*, W1621V4*); };
struct W1621Ctl { W1621CtlVt* vt; };
struct W1621Pl { u8 pad0[0xc]; W1621Ctl* ctl; u8 pad10[0x9f4 - 0x10]; W1621Rec20 rec; };
extern u8* D_00352130 asm("D_00352130");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
u32 func_00112ab8(s32, W1621Rec20*) asm("func_00112ab8");
W1621V4 func_0016af58(u8*) asm("func_0016af58");
f32 func_0016c4e8(u8*) asm("func_0016c4e8");
f32 func_001773b8(u8*, W1621Rec20*, W1621V4*) asm("func_001773b8");
void func_00177a28(u8*) asm("func_00177a28");
f32 func_0017d130(f32) asm("func_0017d130");
s32 func_00190140(W1621Rec20*) asm("func_00190140");
s32 func_0019c090(u8*) asm("func_0019c090");

#define W1621CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((hi) < (x) ? (hi) : (x)))

static inline bool W1621Valid(W1621Rec20* r) { return func_00190140(r) && r->w[0]; }
static inline bool W1621Bit1(W1621Act* e) { return e->fl.b1; }
static inline u32 W1621Busy(u8* p) { return *(u32*)(*(u8**)(p + 12) + 8) & 2; }
static inline u32 W1621Hold(u8* p) { return *(u32*)(p + 0x160) & 0x40; }
static inline bool W1621Any2(u8* p) { return W1621Busy(p) || W1621Hold(p); }
void func_00177008(u8* p, W1621Act* e, W1621Rec20* r) asm("func_00177008");
void func_00177008(u8* p, W1621Act* e, W1621Rec20* r)
{
    W1621V4 v;
    u8* mot = p + 320;
    ((W1621Pl*)p)->rec = *r;
    f32 a = 0.0f;
    func_0017f488(mot, e->motion, a, a);
    if (a < e->speed) {
        if (!func_0019c090(p)) func_00177a28(p);
        f32 lo = e->lo;
        f32 hi = e->hi;
        f32 w;
        if (W1621Valid(r)) {
            w = e->f10;
            if (W1621Bit1(e)) w += func_0016c4e8(p);
            f32 base = func_001773b8(p, r, &v);
            a = W1621CLAMP(-v.y, e->f14, w);
            v.y = 0.0f;
            f32 d = W1621Norm(&v) - base + e->f3c;
            w = W1621CLAMP(d / func_0017d130(a), lo, hi);
        } else {
            w = hi;
            a = e->speed;
            v = func_0016af58(p);
        }
        v.w = w;
        v.y = a;
        W1621Ctl* o = ((W1621Pl*)p)->ctl;
        o->vt->set(o, p, &v);
        *(s32*)(p + 0x104) = 5;
    } else if (W1621Any2(p)) {
        if (W1621Valid(r)) {
            f32 base = func_001773b8(p, r, &v);
            f32 d = (W1621Norm(&v) - base + e->f3c) * *(f32*)(D_00352130 + 0xa8);
            *(W1621V4*)(p + 0x20) = v * W1621CLAMP(d, e->lo, e->hi);
        }
    }
    func_0017f5e0(mot, e->motion2, 0, e->f38, 0.0f);
    func_00112ab8(1, r);
    *(u32*)(p + 0x108) &= ~0x2000000;
}
}  // namespace p_7008

// 001773b8 (src/anon/batch_w3688.cpp)
namespace p_73b8 {
struct __attribute__((aligned(16))) Vec {
    f32 x, y, z, w;
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline Vec vsub(const Vec& a, const Vec& b) {
    Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct P { f32 x, y, z; u32 k; Vec b; };
void func_001902a8(u32, P*) asm("func_001902a8");
s32 func_0016bc20(u32, s32, s32) asm("func_0016bc20");
void func_0018a818(P*, u32, s32) asm("func_0018a818");

f32 func_001773b8(u32 a0, u32 a1, Vec* out) asm("func_001773b8");
f32 func_001773b8(u32 a0, u32 a1, Vec* out) {
    P p[2];
    Vec* b1 = &p[0].b;
    Vec* b2 = &p[1].b;
    p[0].k = 0;
    func_001902a8(a1, &p[0]);
    s32 c = func_0016bc20(a0, 3, -1); P* q = &p[1]; asm("" : "+r"(q)); func_0018a818(q, a0, c);
    *out = vsub(*b1, *b2);
    return p[0].y + p[1].y;
}
}  // namespace p_73b8

// 00177460 (src/anon/batch_w12.cpp)
namespace p39 {
void func_002362b0(void*, void*) asm("func_002362b0");
void func_002367c8(void*) asm("func_002367c8");  // obj_dispatch_bitfield64
void func_00138c10(void*, s32) asm("func_00138c10");
void func_001ba028(u32) asm("func_001ba028");  // list_contains_ptr
void func_0016bd60(u32, s32) asm("func_0016bd60");
void func_00177498(void*) asm("func_00177498");
void SpriteImage_change(void*, void*) asm("_ZN2dk11SpriteImage6changeEPv");
void COUNTER_alertLoop(u8*) asm("_ZN2dk7COUNTER9alertLoopEv");
void TalkCamera_ensureTask(void*, void*) asm("_ZN2dk10TalkCamera10ensureTaskEP4TASK");
void trap_obj_idle(u32**) asm("_ZN2YS13trap_obj_idleEP8BD_VALUE");
void PARTY_hook(u8*, void*) asm("_ZN2YS5PARTY4hookEPNS_2VME");
void ctarget_001b1328(u32, u32, u32, u32) asm("_Z16ctarget_001b1328jjjj");
bool EFFECT_is_waiting(u8*) asm("_ZN3ryj6EFFECT10is_waitingEv");
s32 JmReport_GetData(s16*) asm("_ZN2Tz8JmReport7GetDataEj");
void ScisSpriteMessage_draw(u8*) asm("_ZN2dk17ScisSpriteMessage4drawEv");

void PARTY_hook(u8* self, void* vm) {
    func_00177498(self);
    *(void**)(self + 2796) = vm;
}
}  // namespace p39

// 00177498 (src/anon/tiny_auto80_queue.cpp)
namespace p40 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_0016c7d8(...) asm("func_0016c7d8");
extern "C" u32 func_0016cab8(...) asm("func_0016cab8");

void func_00177498(u32 a0) {
    u32 r4 = a0, r16, r17;
    r17 = r4;
    r16 = *(volatile u32*)((u32)r4 + (s32)(2796));
    r4 = r16;
    if (r16 != 0u) {
        ((void(*)(u32))func_0016cab8)(r4);
        r4 = r16;
        ((void(*)(u32))func_0016c7d8)(r4);
        *(volatile u32*)((u32)r17 + (s32)(2796)) = 0u;
    }
}
}  // namespace p40

// 001774e0 (src/anon/auto80_199_queue.cpp)
namespace p41 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_0016cd48(u32, u32) asm("func_0016cd48");
void func_00177498(u32) asm("func_00177498");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

u32 func_001774e0(u32 a0) {
    u32 s0 = a0;
    u32 a0v = *(u32*)(a0 + 2796);
    if (a0v == 0) {
        return 0;
    }

    u32 t7 = *(u32*)(s0 + 352);
    if ((t7 & 0x00040000u) != 0) {
        return 1;
    }

    if (func_0016cd48(a0v, 0) == 1) {
        func_00177498(s0);
    }

    return 1;
}
}  // namespace p41

// 00177540 (src/anon/batch_w44.cpp)
namespace p42 {
typedef s32 (*IFn)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, u32, u32);
typedef u32 (*AllocFn)(void*, u32, s32);
void func_00177638(void*) asm("func_00177638");

void func_00177540(u8* o) {
    void** p = (void**)(o + 2808);
    for (s32 i = 0; i < 2; i++) {
        void* e = *p++;
        if (e) (*(VFn*)(*(u8**)e + 72))(e);
    }
    func_00177638(o);
}
}  // namespace p42

// 001775a8 (src/anon/tiny_auto80_queue.cpp)
namespace p43 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_00185770(...) asm("func_00185770");

void func_001775a8(u32 a0) {
    u32* s0 = (u32*)((u32)a0 + (s32)(2808));
    for (s32 s1 = 1; s1 >= 0; --s1, ++s0) {
        u32 t7 = s0[0];
        if (t7 != 0u) {
            func_00185770(t7);
        }
    }
}
}  // namespace p43

// 001775f8 (src/anon/batch_w19.cpp)
namespace p44 {
void func_001940f0(void*, s32) asm("func_001940f0");

void func_001775f8(void* p) {
    func_001940f0(p, 2);
    func_001940f0(p, 12);
    func_001940f0(p, 22);
}
}  // namespace p44

// 00177638 (src/anon/batch_w20.cpp)
namespace p45 {
void func_00194108(void*, u32) asm("func_00194108");

void func_00177638(void* p) {
    func_00194108(p, 2);
    func_00194108(p, 12);
    func_00194108(p, 22);
}
}  // namespace p45

// 00177678 (src/anon/batch_w1669.cpp)
namespace p46 {
struct W1669Pair { u32 a, b; };
struct W1669Tri { u32 a, b; f32 c; };
extern W1669Pair D_01e2be18 asm("D_01e2be18");
extern W1669Pair D_01e2bf00 asm("D_01e2bf00");
extern W1669Pair D_01e2c080 asm("D_01e2c080");
extern W1669Tri D_004574b8 asm("D_004574b8");
void func_001a1460(u32) asm("_ZN2YS5SHEET6reloadEv");
void func_001bc688(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
f32 func_001065a8(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
void wtarget_002ce910(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ce910jjjj");
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002e7610jjjj");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0014d240jjjj");
void func_00149f30(int a0, int a1) asm("_Z13func_00149f30ii");

void func_00177678(u8* p) {
    u32 x = *(u32*)(p + 0x48c);
    if (x) func_001a1460(x);
}
}  // namespace p46

// 001776a8 (src/anon/tiny_auto80_queue.cpp)
namespace p47 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern u8 D_0034e948 asm("D_0034e948");
extern "C" u32 func_0017df58(...) asm("func_0017df58");
extern "C" u32 func_00176b20(...) asm("func_00176b20");

void func_001776a8(void) {
    u32 s0 = 0u;
    do {
        u32 v0 = func_00176b20(s0);
        s0 = (u32)(s0 + 1u);
        if (v0 != 0u) {
            u32 t7 = *(u32*)((u32)v0 + (s32)(0));
            u32 t6 = *(u32*)((u32)t7 + (s32)(140));
            ((void(*)(u32))(u32)t6)(v0);
        }
    } while ((s32)s0 < 3);
}
}  // namespace p47

// 001776f8 (src/anon/tiny_wrappers_more.cpp)
namespace p48 {
u32 func_001a1840(u32, u32, u32, u32) asm("func_001a1840");

u32 func_001776f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a1840(((u32)(*(u32*)((u32)(a0) + 1164u))), a1, a2, a3);
}
}  // namespace p48

// 00177710 (src/anon/tiny_auto80_queue.cpp)
namespace p49 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern u8 D_0034e948 asm("D_0034e948");
extern "C" u32 func_0017df58(...) asm("func_0017df58");
extern "C" u32 func_00176b20(...) asm("func_00176b20");

void func_00177710(void) {
    u32 s0 = 0u;
    do {
        u32 v0 = func_00176b20(s0);
        s0 = (u32)(s0 + 1u);
        if (v0 != 0u) {
            u32 t7 = *(u32*)((u32)v0 + (s32)(0));
            u32 t6 = *(u32*)((u32)t7 + (s32)(136));
            ((void(*)(u32))(u32)t6)(v0);
        }
    } while ((s32)s0 < 3);
}
}  // namespace p49

// 00177760 (src/anon/batch_w76.cpp)
namespace p50 {
typedef void (*VFn)(void*);
typedef void (*VFn2)(void*, u32);
s32 func_001b58a8(u8*, u32, u32, u32) asm("func_001b58a8");
void func_001b59c0(u8*, u32, u32, u32) asm("func_001b59c0");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_0016cce8(u32, s32, u32*, s32, s32) asm("func_0016cce8");
typedef void (*VFn4)(void*, u32, u32, u32);

void func_00177760(u8* o, u32 a, u32 b, u32 c)
{
    s32 r = func_001b58a8(o, a, b, c);
    u8* sub = o + 320;
    if (r) {
        func_001b59c0(o, a, b, c);
    } else if (*(u32*)(o + 352) & 0x4000) {
        u8* t = *(u8**)(sub + 252);
        if (func_0019ba60(t) && (*(u32*)(t + 1416) & 2))
            (*(VFn4*)(*(u8**)t + 116))(t, a, b, c);
    }
    if (*(u32*)(o + 1156)) {
        u32 buf[2];
        buf[0] = a;
        buf[1] = b;
        func_0016cce8(*(u32*)(o + 1156), 15, buf, 2, 0);
    }
}
}  // namespace p50

// 00177850 .. 00177860 YS::PARTY::get_partram / get_ability (src/yasui/libys/party.cpp)
namespace p_party {
u32 PARTY_get_partram(u8* self) asm("_ZN2YS5PARTY11get_partramEv");
u32 PARTY_get_partram(u8* self) {
    u32 p = *(u32*)((u32)self + 1164);
    return *(u32*)((u32)p + 580);
}

u32 PARTY_get_ability(u8* self) asm("_ZN2YS5PARTY11get_abilityEv");
u32 PARTY_get_ability(u8* self) {
    u32 v = *(u32*)((u32)self + 1164);
    return (u32)((s32)v + 460);
}
}  // namespace p_party

// 00177870 (src/anon/tiny_auto80_queue.cpp)
namespace p51 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_00177860(...) asm("func_00177860");
extern "C" u32 func_001a1de0(...) asm("func_001a1de0");

u32 func_00177870(u32 a0) {
    u32 s0 = a0;
    u32 s1 = 0u;
    u32 t7 = *(u32*)((u32)func_00177860() + (s32)(12));
    t7 = (u32)(t7 & 0x0800u);
    if (t7 != 0u) {
        s1 = (u32)(0u < func_001a1de0(*(u32*)((u32)s0 + (s32)(1164))));
    }
    return s1;
}
}  // namespace p51

// 001778c0 (src/anon/auto80_199_queue.cpp)
namespace p52 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_00177870(u32) asm("func_00177870");
u32 func_00177860(...) asm("func_00177860");
u32 func_0019c090(...) asm("func_0019c090");
u32 func_001778c0(u32, u32) asm("func_001778c0");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_001778c0(u32 a0, u32 a1) {
    u32 s17 = a0;
    u32 s18 = a1;

    if (func_00177870(s17) != 0) {
        return 0;
    }

    if ((*(u32*)(s17 + 360) & 0x20) != 0) {
        return 1;
    }

    if (func_0019c090(s17) != 0) {  // obj_is_enabled
        u32 s16 = *(u8*)(s17 + 2820);
        u32 v0 = func_00177860(s17);
        s16 += s18;
        s8 t7 = *(s8*)(v0 + 45);
        return (u32)(((s32)s16 < (s32)t7) ^ 1);
    }

    u32 s16 = *(u8*)(s17 + 2820);
    u32 v0 = func_00177860(s17);
    s16 += s18;
    s8 t7 = *(s8*)(v0 + 44);
    return (u32)(((s32)s16 < (s32)t7) ^ 1);
}
}  // namespace p52

// 00177958 (src/anon/tiny_auto80_queue.cpp)
namespace p53 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_001778c0(...) asm("func_001778c0");

u32 func_00177958(u32 a0) {
    u32 s0 = a0;
    u32 r = 0u;
    if (func_001778c0(a0, 0u) != 0u) {
        u32 t7 = *(u8*)((u32)s0 + (s32)(2821));
        t7 = (u32)(t7 < 2u);
        r = (u32)(t7 < 1u);
    }
    return r;
}
}  // namespace p53

// 00177998 (src/anon/tiny_jal_wrappers_flex.cpp)
namespace p54 {
u32 func_00187650(u32, u32, u32, u32) asm("func_00187650");

u32 func_00177998(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r6 = 0u;
    r16 = r4;
    r5 = (u32)(*(u8*)((u32)r4 + (s32)(2804)));
    r5 = (u32)(0u - r5);
    r2 = func_00187650(r4, r5, r6, r7);
    *(u8*)((u32)r16 + (s32)(2804)) = (u8)0u;
    return r2;
}
}  // namespace p54

// 001779d0 (src/anon/auto80_199_queue.cpp)
namespace p55 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_001b9c90() asm("func_001b9c90");
u32 func_001ad938() asm("func_001ad938");
extern u32 D_0034f240 asm("D_0034f240");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_001779d0() {
    u32 s0 = 0;

    if (func_001b9c90() != 0) {
        if (func_001ad938() == 0) {
            u32 t13 = D_0034f240;
            t13 &= 0x00100000;
            s0 = (u32)(t13 < 1);
        }
    }

    return s0;
}
}  // namespace p55

// 00177a28 (src/anon/tiny_auto80.cpp)
namespace p56 {

void func_00177a28(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_bytes_2820_2821
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)((s32)0u + (1));
    *(volatile u8*)((u32)r4 + (s32)(2821)) = (u8)r15;
    *(volatile u8*)((u32)r4 + (s32)(2820)) = (u8)r15;
}
}  // namespace p56

// 00177a38 (src/anon/batch_w5.cpp)
namespace p57 {
typedef void (*VFn)(void*);
void func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");

// Increment a saturating (max 100) byte counter.
void func_00177a38(u8* p) {  // obj_inc_counter
    if (p[0xb04] < 100) p[0xb04]++;
}
}  // namespace p57

// 00177a58 (src/anon/batch_w1.cpp)
namespace p58 {

// Decrement a byte counter, saturating at 0.
void func_00177a58(u8* p) {
    if (p[0xb04] != 0) p[0xb04]--;
}
}  // namespace p58

// 00177a78 (src/anon/batch_w21.cpp)
namespace p59 {
void func_00177a38(void*) asm("func_00177a38");
typedef void (*JumpFn)(void*, void*, s32);

void func_00177a78(u8* p) {
    func_00177a38(p);
    if (p[2821] < 100) p[2821]++;
}
}  // namespace p59

// 00177ab8 (src/anon/batch_w91.cpp)
namespace p60 {
u8* func_00177860(u8*) asm("func_00177860");
void func_00177a78(u8*) asm("func_00177a78");
void func_00177a38(u8*) asm("func_00177a38");
void func_00177a28(u8*) asm("func_00177a28");  // set_bytes_2820_2821

u8 func_00177ab8(u8* p, u8 force) {
    u32 f;
    if ((*(u32*)(p + 360) & 0x20) && force) {
        u8 lv = p[2821];
        if (lv < func_00177860(p)[46]) {
            func_00177a78(p);
            goto done;
        }
    }
    f = *(u32*)(p + 352);
    if ((f & 0x400) && force) {
        func_00177a38(p);
        goto done;
    }
    {
        s32 b = 0;
        if (f & 4) goto one;
        if (f & 8) goto one;
        if (f & 0x10) one: b = 1;
        if (!(u8)b) return 0;
    }
    func_00177a28(p);  // set_bytes_2820_2821
done:
    *(u32*)(p + 264) &= ~0x02000000;
    return 1;
}
}  // namespace p60

// 00177ba0 (src/anon/batch_w32.cpp)
namespace p61 {
struct Info2c { s8 pad[0x2c]; s8 limit; };
Info2c* func_00177860(void*) asm("func_00177860");

// min(count, limit) with the limit re-fetched.
s32 func_00177ba0(u8* p) {
    u8 v = p[0xb04];
    if (v < func_00177860(p)->limit) return p[0xb04];
    return func_00177860(p)->limit;
}
}  // namespace p61

// 00177bf8 (src/anon/batch_w33.cpp)
namespace p62 {
struct Lim177 { u8 pad[45]; s8 max; };
struct Obj177 { u8 pad[2820]; u8 n; };
Lim177* func_00177860(Obj177*) asm("func_00177860");

s32 func_00177bf8(Obj177* p) {
    if (p->n < func_00177860(p)->max) return p->n;
    return func_00177860(p)->max;
}
}  // namespace p62

// 00177c50 (src/anon/batch_w78.cpp)
namespace p63 {
s32 func_001a1de0(u32) asm("func_001a1de0");
u8* func_00177860(void*) asm("func_00177860");
void func_00187650(void*, s32, s32) asm("func_00187650");
void func_00187520(void*, s32, u32, u8) asm("func_00187520");

void func_00177c50(u8* o, s32 dmg, u32 c, u8 flag) {
    u32 st = *(u32*)(o + 1164);
    if (st && !func_001a1de0(st) && dmg < 0) {
        f32 r = (f32)(-dmg) / (f32)*(s32*)(*(u8**)(o + 1164) + 4);
        r *= *(f32*)(func_00177860(o) + 88);
        s32 n = (s32)r;
        if (n > 0) func_00187650(o, n, 0);
    }
    if (*(u32*)(o + 352) & 0x4000) flag = 0;
    func_00187520(o, dmg, c, flag);
}
}  // namespace p63

// 00177d30 (src/anon/auto80_199_queue.cpp)
namespace p64 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_00177860(...) asm("func_00177860");
u32 func_00186ce8(u32) asm("func_00186ce8");
u32 func_00186ec0(u32, u32) asm("func_00186ec0");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_00177d30(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 v0 = func_00177860(s0);
    u32 t6;
    s32 t7 = *(s32*)(v0 + 12);

    if (t7 < 0) {
        u32 t14 = *(u32*)(s0 + 1164);
        t7 = *(u32*)(t14 + 8);
        if (t7 == 0) {
            t7 = *(u32*)(t14 + 0);
            t7 = (u32)((s32)t7 < 2);
            if (t7 == 0) {
                t6 = 1;
                goto done;
            }
        }
    }

    t7 = *(u32*)(v0 + 16);
    t7 = t7 & 1;
    t7 = (u8)t7;
    if (t7 != 0) {
        if (func_00186ce8(s0) != 0) {
            t6 = 1;
            goto done;
        }
    }

    t6 = func_00186ec0(s0, s1);

done:
    return t6;
}
}  // namespace p64
