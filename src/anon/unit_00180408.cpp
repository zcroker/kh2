#include "../common/types.h"

// YS::MOTION, second part (0x180408-0x180f28): the rest of src/yasui/libys/motion.cpp after the capture
// helper 0x180378 (a separate function: it needs strict aliasing, the first part does not). Effects
// linked to a motion, the anmatr flags, YS::VOICE::stop and the id tables; incl. the never-written
// 0x180d88. Each function keeps the declarations of the source it was matched in (namespace gN); every
// symbol is bound by asm label.

namespace YS {
class MOTION {
public:
    u32 is_no_motion() asm("_ZN2YS6MOTION12is_no_motionEv");
};
}  // namespace YS

// 00180408 (src/anon/batch_w13.cpp)
namespace g41 {
void* func_00168b38(void*, s32, s32) asm("func_00168b38");  // entry_array_find_nth
extern void (*D_0035e380[])(void);
typedef s32 (*VFn2)(void*, s32);

u32 func_00180408(void* a0, void* a1) {
    u8* v;
    if (a1 && (v = (u8*)func_00168b38(a1, 9, 0)) != 0) return *(u32*)(v + 8);  // entry_array_find_nth
    return 0;
}
}  // namespace g41

// 00180448 (src/anon/batch_w8026.c)
namespace g42 {
/* 00180448 */
struct VObj;
struct VObjVt { void* a; void* b; s32 (*get)(struct VObj*); };
struct VObj { struct VObjVt* vt; };
struct Obj180 { u8 pad[0x14]; s32 mode; u8 pad2[0x14]; f32 div; f32 base; };
extern f32 D_00349e10 asm("D_00349e10");
s32 func_0017ec98(struct Obj180*, s32) asm("func_0017ec98");
s32 func_0017edf0(struct Obj180*, s32) asm("func_0017edf0");
struct VObj* func_00180408(struct Obj180*, s32) asm("func_00180408");
f32 func_002f8b00(f32, f32) asm("func_002f8b00");

f32 func_00180448(struct Obj180* o, s32 n, f32 x, f32 y) {
    s32 ok = (u32)(n - 1) < 2;
    if ((u32)(o->mode - 1) < 2 && ok) {
        f32 t = (o->base + D_00349e10 + x) / o->div;
        struct VObj* v = func_00180408(o, func_0017edf0(o, func_0017ec98(o, n)));
        f32 c = v->vt->get(v);
        return func_002f8b00(c * t, c);
    }
    return y;
}
}  // namespace g42

// 00180510 (src/anon/auto80_199_queue.cpp)
namespace g43 {
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
u32 func_0017ec98(...) asm("func_0017ec98");
u32 func_0017edf0(u32 a0, u32 a1) asm("func_0017edf0");
u32 func_00180408(u32 a0, u32 a1) asm("func_00180408");
struct Vtbl_00180510 {
    u8 pad0[8];

s32 (*fn8)(void *);

u8 padC[16];

float (*fn28)(void *);

};
struct Obj_00180510 {
    Vtbl_00180510 *vt;

};
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
typedef s32 (*Cb_0028d730)(u32);
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

u32 func_00180510(u32 a0) {
    u32 s1 = 0;

    u32 v0 = func_0017ec98(a0);
    v0 = func_0017edf0(a0, v0);

    Obj_00180510 *s0 = (Obj_00180510 *)func_00180408(a0, v0);
    if (s0 != 0) {
        float f20 = s0->vt->fn28(s0);
        s32 v1 = s0->vt->fn8(s0);
        if (f20 < (float)v1) {
            s1 = 1;
        }
    }

    return s1;
}
}  // namespace g43

// 001805a8 (src/anon/batch_w14.cpp)
namespace gX {
void func_0014d358(void*, s32, void (*)(void), s32) asm("func_0014d358");
s32 func_0017ec98(void*, s32) asm("func_0017ec98");
s32 func_0017edf0(void*, s32) asm("func_0017edf0");
s32 func_00180408(void*, s32) asm("func_00180408");
void* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void LOCKON_dtor(void*) asm("_ZN2YS6LOCKOND1Ev");
void TargetCamera_change(u32*) asm("_ZN2dk12TargetCamera6changeEPN2YS6TARGETE");
s32 MOTION_is_exist(void*, s32) asm("_ZN2YS6MOTION8is_existEi");
void INDICATION_disable(u8*) asm("_ZN2YS10INDICATION7disableEv");
void u_call4_001d2210(u32, u32, u32, u32) asm("_Z16u_call4_001d2210jjjj");
void u_call4_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

s32 MOTION_is_exist(void* m, s32 i) {
    return func_00180408(m, func_0017edf0(m, func_0017ec98(m, i))) != 0;
}
}  // namespace gX

// 001805e8 (src/anon/batch_w9.cpp)
namespace gX {
u32 func_0016c3a8(u32, u32) asm("func_0016c3a8");
u32 func_0016b800(u32) asm("func_0016b800");
u32 func_001d14a0(void) asm("func_001d14a0");
void func_001b6bd8(u32, u32) asm("func_001b6bd8");
extern u32 D_0034aa90 asm("D_0034aa90");
extern u32 D_0034aa94 asm("D_0034aa94");
void bc_make(void) asm("_ZN2dk14BlindCollision4makeEv");
void trap_obj_search_by_part(u32* v) asm("_ZN2YS23trap_obj_search_by_partEP8BD_VALUE");
void trap_player_capture_form(u32* v) asm("_ZN2YS24trap_player_capture_formEP8BD_VALUE");
void reset_anmatr_flag(u8* m) asm("_ZN2YS6MOTION17reset_anmatr_flagEv");
void group_enable(void* g, s32 i) asm("_ZN2YS10UNIT_GROUP6EnableEi");
void reset_special_command(u8* c) asm("_ZN2YS14PLAYER_COMMAND21reset_special_commandEv");
void effect_angle(u8* e) asm("_ZN3ryj6EFFECT5angleEv");
void jm_unload(u8* j) asm("_ZN2Tz6JmInfo6UnloadEz");

void reset_anmatr_flag(u8* m) {
    *(u32*)(m + 40) = 0;
    *(u32*)(m + 32) &= 0x7183;
    *(u32*)(m + 36) &= ~1;
    *(u32*)(m + 36) &= ~2;
}
}  // namespace gX

// 00180618 (src/anon/batch_w55.cpp)
namespace g46 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline bool isPos(f32 f) { return f > 0.0f; }
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
s32 func_00180cd0(u8*) asm("func_00180cd0");
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

u32 ctarget_00180618(u8* p) {
    u32 r = 0;
    if (!func_00180cd0(p)) {
        if (!isPos(*(f32*)(p + 52))) {
            u8* o = *(u8**)(p + 12);
            if ((*(f32 (**)(void*))(*(u8**)o + 28))(o) <= *(f32*)(p + 48)) r = 1;
        }
    }
    return r;
}
}  // namespace g46

// 00180698 (src/anon/auto80_199_queue.cpp)
namespace g47 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_0017ec98(...) asm("func_0017ec98");
u32 func_0017edf0(u32 a0, u32 a1) asm("func_0017edf0");
u32 func_00180408(u32 a0, u32 a1) asm("func_00180408");
u32 func_00180698(u32 a0, u32 a1) asm("func_00180698");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_00180698(u32 a0, s32 a1) {
    if (a1 >= 0) {
        if ((u32)a1 != *(u32 *)(a0 + 20)) {
            u32 v0 = func_0017ec98(a0, (u32)a1);
            v0 = func_0017edf0(a0, v0);
            return func_00180408(a0, v0);
        }
    }
    return *(u32 *)(a0 + 12);
}
}  // namespace g47

// 001806f8 (src/anon/auto80_199_queue.cpp)
namespace g48 {
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
u32 func_0017ec98(...) asm("func_0017ec98");
u32 func_0017edf0(u32 a0, u32 a1) asm("func_0017edf0");
u32 func_00180408(u32 a0, u32 a1) asm("func_00180408");
u32 func_00180698(u32 a0, u32 a1) asm("func_00180698");
struct Vtbl_001806f8 {
    u8 pad0[8];

s32 (*fn8)(void*);

};
struct Obj_001806f8 {
    Vtbl_001806f8 *vt;

};
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
typedef s32 (*Cb_0028d730)(u32);
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

float func_001806f8(u32 a0, s32 a1) {
    if (a1 < 0 || (u32)a1 == *(u32 *)(a0 + 20)) {
        return *(float *)(a0 + 44);
    }

    func_00180698(a0, (u32)a1);
    Obj_001806f8 *o = (Obj_001806f8 *)func_00180698(a0, (u32)a1);
    return (float)o->vt->fn8(o);
}
}  // namespace g48

// 00180770 (src/anon/batch_w10.cpp)
namespace g49 {
typedef void (*VFn)(void*);
void* func_00180698(void) asm("func_00180698");

void func_00180770(void) {
    void* o = func_00180698();
    (*(VFn*)(*(u8**)o + 28))(o);
}
}  // namespace g49

// 001807a0 (src/anon/tiny_auto80_queue.cpp)
namespace g50 {
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
extern "C" u32 func_00189d18(...) asm("func_00189d18");

void func_001807a0(u32 a0) {
    u32 a1 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(16));
    if (t7 != 0u) {
        func_00189d18(t7, a1);
    }
}
}  // namespace g50

// 001807d0 (src/anon/tiny_auto80_queue.cpp)
namespace g51 {
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
extern "C" u32 func_001892b8(...) asm("func_001892b8");

void func_001807d0(u32 a0) {
    u32 a1 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(16));
    if (t7 != 0u) {
        func_001892b8(t7, a1);
    }
}
}  // namespace g51

// 00180800 (src/anon/tiny_auto80_fptr4.cpp)
namespace g52 {

void func_00180800(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13, r14, r15;
    *(u32*)((u32)r4 + (s32)(28)) = r5;
    if (r5 == 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(8));
        r13 = (u32)(0x0010u << 16);
        r14 = *(u32*)((u32)r15 + (s32)(264));
        r14 = (u32)(r14 | r13);
        *(u32*)((u32)r15 + (s32)(264)) = r14;
    }
}
}  // namespace g52

// target tables of 0x180828 (two rows of 5)
extern "C" const s32 D_0036c5b8[2][5] = { { 7, 6, 5, 4, -1 }, { 1, 0, -1, 0, 0 } };

// 00180828 (src/anon/batch_w51.cpp)
namespace g53 {
u32 wtarget_001339d0(u32, u32, u32, u32, u32) asm("_Z16wtarget_001339d0jjjj");
u32 wtarget_00180828(u32, u32, u32, u32) asm("_Z16wtarget_00180828jjjj");
u32 wtarget_001d9980(u32, u32, u32, u32) asm("_Z16wtarget_001d9980jjjj");
void wtarget_002cb188(u32, u32, u32, u32) asm("_Z16wtarget_002cb188jjjj");
void wtarget_002e1878(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");
typedef s32 (*VFnI)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, u32);
struct Pkt { u16 h0; u8 b2; u8 b3; u32 w4; u32 w8; u32 w12; };
union PktCursor { Pkt* p; u32 u; u16 h; };
s32 func_0017ebc8(void*) asm("func_0017ebc8");
u32 func_001a97b8(u32, s32) asm("func_001a97b8");
u32 func_00180408(void*, u32) asm("func_00180408");
extern s32 D_0036c5b8[] asm("D_0036c5b8");
extern s32 D_0036c5cc[] asm("D_0036c5cc");

u32 wtarget_00180828(u32 a0, u32, u32, u32) {
    u32* p = (u32*)a0;
    if (*p == 0) return 0;
    s32* t = func_0017ebc8(p) ? D_0036c5b8 : D_0036c5cc;
    s32 id;
    while ((id = *t++) >= 0) {
        u32 r = func_001a97b8(*p, id);
        if (r) return func_00180408(p, r);
    }
    return 0;
}
}  // namespace g53

// 001808c0 (src/anon/batch_w98.cpp)
namespace g54 {
struct Ent180 { u8 pad[6]; u16 id; u8 pad2[10]; s16 val; };
struct Slot180 { u8 pad[32]; };
struct Obj180 { u8 pad[8]; u8* body; u8 pad2[248]; u32 active : 1; };
s32 func_0019bad8(u8*) asm("func_0019bad8");
Ent180* func_0016bba8(u8*, s32, Ent180*) asm("func_0016bba8");
void func_0011c148(Slot180*, u32, u16, s32, s32, f32) asm("func_0011c148");
void func_0011c210(Slot180*) asm("func_0011c210");

// Fills buf with one slot per type-10 then type-11 child of the body, then terminates the list.
void func_001808c0(Obj180* o, Slot180* buf) {
    if (!o->active || (*(u32*)(o->body + 264) & 0x40000000)
        || (!func_0019bad8(o->body) && !(*(u32*)(o->body + 1416) & 0x20))) {
        func_0011c210(buf);
        return;
    }
    s32 n = 0;
    Ent180* e = 0;
    while ((e = func_0016bba8(o->body, 10, e)) != 0) {
        func_0011c148(&buf[n], *(u32*)(o->body + 2224), e->id, 0, 1, e->val);
        n++;
    }
    while ((e = func_0016bba8(o->body, 11, e)) != 0) {
        func_0011c148(&buf[n], *(u32*)(o->body + 2224), e->id, 1, 1, e->val);
        n++;
    }
    func_0011c210(&buf[n]);
}
}  // namespace g54

// 00180a10 (src/anon/batch_w85.cpp)
namespace g55 {
u8* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_00102788(u32, s32, s32, void (*)(void)) asm("func_00102788");
typedef s32 (*PartFn)(void*);
void func_00178d28(u8*) asm("func_00178d28");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
#define TAIL     func_00178d28(o); \
        if (*(u8**)(o + 3096)) { f32 z = 0.0f; \
            func_0017f488(*(u8**)(o + 3096) + 320, 151, z, z); \
            func_0017f5e0(*(u8**)(o + 3096) + 320, 0, 0, z, z); }
static inline void vu_mcopy(f32 (*d)[4], const u8* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void vu_minv(f32 (*d)[4], f32 (*s)[4]) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%1)\n\t"
                 "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                 "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                 "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
struct Obj180 { u8 p0[8]; void* f8; u8 p12[396]; u16 ids[16]; s32 n; };
struct It180 { u8 p0[16]; u32 flags; u8 p20[12]; };
static inline u32 it180_on(It180* e) { return e->flags & 1; }
s32 func_0011c230(It180*) asm("func_0011c230");
u16 func_0011c228(It180*) asm("func_0011c228");
void func_0016c698(void*, u16, It180*) asm("func_0016c698");

void func_00180a10(Obj180* o, It180* it) {
    u16 old[16];
    s32 i, j, n = o->n;
    for (i = 0; i < n; i++) old[i] = o->ids[i];
    o->n = 0;
    while (!func_0011c230(it)) {
        if ((u8)it180_on(it)) {
            u16 id = func_0011c228(it);
            o->ids[o->n++] = id;
            for (j = 0; j < n; j++) if (old[j] == id) goto next;
            func_0016c698(o->f8, id, it);
        }
    next:
        it++;
    }
}
}  // namespace g55

// 00180b10 (src/anon/batch_w62.cpp)
namespace g56 {
struct VObj1246 { u32 (**vt)(...); };
typedef u32 (*Fn1246)(VObj1246*, u32, u32, u32, u32, u8, u32);
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
struct Slot180 { u32 obj; u32 key; };
u32 func_00198580(u32, u32) asm("func_00198580");  // check_div1000_500

// Ensures `key` has an object in the 8-slot table (filled into the last free slot).
void func_00180b10(u8* t, u32 key) {
    s32 slot = -1;
    s32 i = 0;
    Slot180* e = (Slot180*)(t + 256);
    for (; i < 8; i++, e++) {
        if (e[1].obj == 0) slot = i;
        else if (e[1].key == key) return;
    }
    Slot180* s = (Slot180*)((u8*)(slot * 8) + (u32)t + 256);
    u32 o = func_00198580(*(u32*)(t + 8), key);  // check_div1000_500
    s[1].obj = o;
    s[1].key = key;
}
}  // namespace g56

// 00180b98 (src/anon/batch_w3688.cpp)

// 00180b98: walks 8 attached slots, dropping dead ones and updating live ones with the owner's position.
// a1 (the vector) is pinned so it is set before the branch like the original.
namespace n00180b98 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec(const Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Slot { void* p; u32 a; };
struct Grp { u32 a, b; Slot slots[8]; };
struct Obj6 { u8 pad[8]; s32 id; u8 pad2[0x100 - 12]; Grp g; };
extern "C" {
Vec* func_0016c028(s32);
s32 func_0019c6f0(s32);
void func_002bc398(void*, Vec*);
void func_002bc3f0(void*, Vec*);
s32 func_002bc420(void*);
void func_00180b98(Obj6* o) {
    Vec v;
    v = *func_0016c028(o->id);
    Grp* g = &o->g;
    for (s32 i = 0; i < 8; i++) {
        Slot* s = &g->slots[i];
        if (s->p != 0) {
            if (func_002bc420(s->p)) {
                s32 c = func_0019c6f0(o->id);
                register Vec* pv asm("$5") = &v;
                if (c) {
                    func_002bc3f0(s->p, pv);
                } else {
                    func_002bc398(s->p, pv);
                }
            } else {
                s->p = 0;
            }
        }
    }
}
}
}

// 00180c38 (src/anon/tiny_auto80_queue.cpp)
namespace g58 {
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
extern "C" u32 func_002bc358(...) asm("func_002bc358");

void func_00180c38(u32 a0) {
    u32 s0 = (u32)((s32)a0 + (256));
    s32 s1 = 7;
    do {
        u32 t7 = *(u32*)((u32)s0 + (s32)(8));
        if (t7 != 0u) {
            func_002bc358(t7, 10u);
            *(u32*)((u32)s0 + (s32)(8)) = 0u;
        }
        s1 = (s32)(s1 - 1);
        s0 = (u32)((s32)s0 + (8));
    } while (s1 >= 0);
}
}  // namespace g58

// 00180c88 (src/anon/batch_w34.cpp)
namespace g59 {
void u_tail0_0014d008(void) asm("_Z16u_tail0_0014d008v");
void f17f488(s32, s32, f32, f32) asm("_Z13func_0017f488iiff");
void MISSION_Activate2d(void*) asm("_ZN2YS7MISSION10Activate2dEv");
void EFFECT_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
u32 wtarget_002342f0(u32, u32, u32, u32) asm("_Z16wtarget_002342f0jjjj");
void Layout_setNum(void*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
void u_tail4_002e2d88(u32, u32, u32, u32) asm("_Z16u_tail4_002e2d88jjjj");
void func_001802d8(u32, u32, u32, u32, u32, u32) asm("func_001802d8");

void func_00180c88(u8* p, u32 a, f32 x) {
    u32 t = *(u32*)(p + 256);
    if (!t) f17f488((s32)p, a, x, 0.0f);
    else func_001802d8(*(u32*)(p + 252), t, *(u32*)(p + 240), *(u32*)(p + 8), a, 0);
}
}  // namespace g59

// 00180cd0 YS::MOTION::is_no_motion (src/yasui/libys/motion.cpp)
namespace YS {
u32 MOTION::is_no_motion() {
    u32 v = *(u32*)((u32)this + 12);
    return (v < 1u);
}
}  // namespace YS

// 00180ce0 (src/anon/batch_w38.cpp)
namespace g61 {
void func_00180c38(void*) asm("func_00180c38");
void func_00180ef0(void*) asm("func_00180ef0");
typedef void (*Fn1)(void*);

void func_00180ce0(u8* p) {
    s32* r = *(s32**)(p + 328);
    if (r) {
        (*r)--;
        *(s32*)(p + 328) = 0;
    }
    func_00180c38(p);
    func_00180ef0(p);
    Fn1 f = *(Fn1*)(p + 404);
    if (f) {
        f(*(void**)(p + 8));
        *(Fn1*)(p + 404) = 0;
    }
}
}  // namespace g61

// 00180d40 (src/anon/batch_w59.cpp)
namespace g62 {
void* create_task(void* self, int a, int b, void* fn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void setHideGroup(u32 g) asm("_ZN2dk3Map12setHideGroupEj");
void wtarget_00180d40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00180d40jjjj");
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002eda40jjjj");
typedef void (*VFn)(void);
void func_001022c0(void*, void*, int, int, void*) asm("func_001022c0");
void func_00102528(void*, void*) asm("func_00102528");
void* func_001b9bc8p(void*) asm("func_001b9bc8");
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
struct T180 { u8 pad[332]; s32 t[16]; };

void wtarget_00180d40(u32 a, u32 b, u32 c, u32 d) {
    T180* o = (T180*)a;
    s32 idx = -1;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (o->t[i] == (s32)b) return;
        if (o->t[i] < 0) idx = i;
    }
    o->t[idx] = b;
}
}  // namespace g62

// 00180d88: drop an id from the 16-entry table (never written before)
namespace g_d88 {
struct Ids { u8 pad[12]; s32 t[16]; };
struct T180 { u8 pad[320]; Ids ids; };
void func_00180d88(T180* o, s32 b) asm("func_00180d88");
void func_00180d88(T180* o, s32 b) {
    Ids* p = &o->ids;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (p->t[i] == b) {
            p->t[i] = -1;
            return;
        }
    }
}
}  // namespace g_d88

// 00180dc0 (src/anon/batch_w15.cpp)
namespace g63 {

int func_00180dc0(u8* p, u32 v) {
    u32* a = (u32*)(p + 332);
    for (int i = 0; i < 16; i++) {
        if (a[i] == v) return 1;
    }
    return 0;
}
}  // namespace g63

// 00180df8 (src/anon/tiny_auto80_queue.cpp)
namespace g64 {
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

void func_00180df8(u32 a0, u32 a1) {
    u32 t7 = (u32)((s32)a0 + (396));
    u32 t6 = *(u32*)((u32)t7 + (s32)(4));
    if (t6 == 0u) {
        *(u32*)((u32)t7 + (s32)(4)) = a1;
        *(u32*)((u32)a0 + (s32)(396)) = a1;
        *(u32*)((u32)a1 + (s32)(44)) = 0u;
        return;
    }
    *(u32*)((u32)t6 + (s32)(44)) = a1;
    *(u32*)((u32)a1 + (s32)(44)) = 0u;
    *(u32*)((u32)t7 + (s32)(4)) = a1;
}
}  // namespace g64

// 00180e28 (src/anon/batch_w84.cpp)
namespace g65 {
typedef void (*VFn)(void*);
struct LNode { u8 _0[44]; LNode* next; };
struct LList {
    LNode* head;
    LNode* tail;
};
struct LOwner { u8 _0[396]; LList list; };
static inline __attribute__((always_inline)) void LRemove(LList* l, LNode* n) {
    LNode* prev;
    if (n == l->head) {
        prev = 0;
        l->head = n->next;
    } else {
        for (prev = l->head; prev->next != n; prev = prev->next) {}
        prev->next = n->next;
    }
    if (n == l->tail) l->tail = prev;
    n->next = 0;
}
static inline __attribute__((always_inline)) LNode* LNext(LOwner* o, LNode* n) {
    if (!n) return o->list.head;
    return n->next;
}
s32 func_001dc9d0(void*) asm("func_001dc9d0");

void func_00180e28(LOwner* p) {
    LNode* n = p->list.head;
    LNode* it = n;
    while (n) {
        it = LNext(p, it);
        if (!func_001dc9d0(n)) LRemove(&p->list, n);
        n = it;
    }
}
}  // namespace g65

// 00180ef0 (src/anon/batch_w15.cpp)
namespace g66 {
struct Node2c { u32 _0; u32 _4; u32 flags; u8 _c[32]; Node2c* next; };

void func_00180ef0(u8* p) {
    Node2c* n = 0;
    while ((n = !n ? *(Node2c**)(p + 396) : n->next) != 0) {
        n->flags |= 0x2000000;
    }
    *(u32*)(p + 400) = 0;
    *(u32*)(p + 396) = 0;
}
}  // namespace g66

// permutation table used by 0x17ec98
extern "C" const u8 D_0036c5e0[4][4] = { { 0, 1, 3, 2 }, { 1, 0, 2, 3 }, { 2, 3, 1, 0 }, { 3, 2, 0, 1 } };
