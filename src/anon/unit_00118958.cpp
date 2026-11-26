// Linked unit 0x00117778-0x00119bf8.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 00118958 (was src/anon/tiny_auto80_queue.cpp)
namespace n00118958 {
u32 func_0010f6f8(...) asm("func_0010f6f8");
// count_reached_threshold_b
extern "C" u32 func_00111e38(...) asm("func_00111e38");
/*TARGET 00118958*/
u32 func_00118958(u32 a0) asm("_Z13func_00118958j");
u32 func_00118958(u32 a0) {
    u32 s0 = a0;
    u32 r2 = func_00111e38(0u);
    u32 t7 = *(volatile u32*)((u32)s0 + (s32)(20));
    u32 v0 = ((u32(*)(u32, f32))func_0010f6f8)(r2, *(volatile f32*)((u32)t7 + (s32)(12)));
    return (u32)(0u < v0);
}
}  // namespace n00118958

// 00118998 (was src/anon/batch_w2424.cpp)
namespace n00118998 {
struct Tgt118998;
struct V118998b {
    f32 x, y, z, w;
    V118998b() {}
    V118998b& operator=(const V118998b& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998b operator-(const V118998b& b) const
    {
        V118998b r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct V118998 {
    f32 x, y, z, w;
    V118998() {}
    V118998& operator=(const V118998b& o)
    {
        if ((void*)this != (void*)&o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998b sub(const V118998& b) const
    {
        V118998b r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V118998& operator=(const V118998& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V118998 operator-(const V118998& b) const
    {
        V118998 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
void func_00190128(Tgt118998*) asm("func_00190128");
struct Tgt118998 {
    s32 f0, f4, f8, f12, f16;
    Tgt118998() { func_00190128(this); }
};
struct Model118998 { u8 pad0[268]; u32 f268; u8 pad1[352 - 272]; u32 f352; };
struct Lead118998 { u8 pad[1164]; void* f1164; };
struct Who118998 {
    u8 pad0[4];
    Model118998* model;
    u8 pad1[1576 - 8];
    f32 maxSpeed;
    u8 pad2[4];
    s32 f1584;
    s32 state;
    u8 pad3[1600 - 1592];
    V118998 from;
    V118998 to;
    V118998 dir;
};
struct Ent118998;
extern f32 D_00349e18 asm("D_00349e18");
Lead118998* func_00111e38(s32) asm("func_00111e38");
void func_00190878(Tgt118998*, s32, s32) asm("func_00190878");
s32 func_001b58a8(void) asm("func_001b58a8");
s32 func_0010f8c0(Model118998*) asm("func_0010f8c0");
s32 func_00118958(Who118998*) asm("func_00118958");
void kn__Stitch__calc_move_target(Who118998*, s32) asm("kn__Stitch__calc_move_target");
void func_001168c0(Who118998*) asm("func_001168c0");
s32 func_00116d08(Who118998*) asm("func_00116d08");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, f32, f32, void*) asm("func_0017f5e0");
void func_001a1a50(void*, s32) asm("func_001a1a50");
void func_0016ac38(Model118998*, s32, s32, s32, Lead118998*) asm("func_0016ac38");
void* kn__Stitch__startEffect(Who118998*, s32, Model118998*, s32, s32, s32, s32, s32) asm("kn__Stitch__startEffect");
/*TARGET 00118998*/
s32 func_00118998(Who118998* w, Ent118998* e, Tgt118998* t, s32* score, u8 check) asm("func_00118998");
s32 func_00118998(Who118998* w, Ent118998* e, Tgt118998* t, s32* score, u8 check)
{
    Lead118998* lead = func_00111e38(0);
    if (check) {
        *score = 0;
        Tgt118998 tmp;
        func_00190878(&tmp, 0, 0);
        *t = tmp;
        if (func_001b58a8()) return 0;
        if (w->model->f268 & 0x800) return 0;
        if (w->model->f352 & 0x40000000) return 0;
        if (!func_0010f8c0(w->model)) {
            if (!func_00118958(w)) return 0;
        ret1:
            return 1;
        }
        switch (w->state) {
        case 0: case 1: case 2: return 1;
        case 3: return 0;
        }
        goto ret1;
    }
    if (!func_0010f8c0(w->model)) {
        w->state = 0;
        kn__Stitch__calc_move_target(w, 7);
    }
    switch (w->state) {
    case 0: {
        w->dir = w->to - w->from;
        f32 len = w->dir.normalize();
        f32 sp = len * D_00349e18;
        w->dir.w = sp;
        if (w->maxSpeed < sp) w->dir.w = w->maxSpeed;
        func_001168c0(w);
        if (len < 100.0f) {
            w->to.w = 0.0f;
            w->state++;
        }
        break;
    }
    case 1: {
        w->dir = w->to.sub(w->from);
        f32 sp = w->dir.normalize() * D_00349e18;
        w->dir.w = sp;
        if (w->maxSpeed < sp) w->dir.w = w->maxSpeed;
        if (func_00116d08(w)) w->state++;
        break;
    }
    case 2: {
        w->dir.zero();
        w->from = w->to;
        func_0017f488((u8*)w->model + 320, 204, 0.0f, 0.0f);
        func_0017f5e0((u8*)w->model + 320, 0, 0.0f, 0.0f, 0);
        func_001a1a50(lead->f1164, 0);
        func_0016ac38(w->model, 10, 1, 0, lead);
        kn__Stitch__startEffect(w, 11, w->model, -1, 204, 0, 1, 0);
        w->state++;
        break;
    }
    }
    return 1;
}
}  // namespace n00118998

// 0036a840: the member-function pointer constant {0x118108, 0} (an unlisted method) that 0x118d10 passes on; it
// sits between 0x118998's literal and 0x118d10's in .rodata.
extern const u32 R_0036a840[2] asm("D_0036a840") __attribute__((aligned(4))) = { 0x118108, 0 };

// 00118d10 (was src/anon/batch_w60.cpp)
namespace n00118d10 {
void kn__Stitch__calc_move_target(void*) asm("kn__Stitch__calc_move_target");
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
void* func_001144e8(void*, u64) asm("func_001144e8");
void func_0010eed8(void*, void*, s32) asm("func_0010eed8");
u32 kn__Friend__getFlag(void*) asm("kn__Friend__getFlag");
// get_field2940
void func_00112730(void*, u32) asm("func_00112730");
// 0x00111060: definition moved into src/anon/unit_00110b00.cpp

// 8-byte constant (a member-function pointer) passed by value.
struct Pmf8 { u64 v; } __attribute__((packed));
extern const Pmf8 D_0036a840 asm("D_0036a840");
/*TARGET 00118d10*/
void func_00118d10(u8* p) asm("func_00118d10");
void func_00118d10(u8* p) {
    kn__Stitch__calc_move_target(p);
    func_0017f540(*(u8**)(p + 4) + 320, 161, 4.0f, 0.0f);
    void* r = func_001144e8(p, D_0036a840.v);
    if (r) {
        func_0010eed8(*(void**)(p + 4), r, 0);
        func_00112730(*(void**)(p + 4), kn__Friend__getFlag(*(void**)(p + 4)) | 4);
    }
}
}  // namespace n00118d10

// 00118da0 (was src/anon/batch_w2404.cpp)
namespace n00118da0 {
struct W2404Obj { u8 pad[0x588]; u32 flags; };
struct W2404Tgt {
    W2404Obj* obj; s32 a, b, c, d;
};
void func_00190128(W2404Tgt*) asm("func_00190128");
s32 w2404_is_exist(W2404Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 w2404_can_attack(W2404Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 YS__TARGET__each(W2404Tgt*, s32) asm("YS__TARGET__each");
s32 func_00135c88(void*, W2404Obj*) asm("func_00135c88");
void func_00135bd0(void*, W2404Obj*) asm("func_00135bd0");
s32 w2404_entry_num(void*) asm("_ZN2kn11ObjObserver11getEntryNumEv");
W2404Obj* func_00135d00(void*, s32) asm("func_00135d00");
s32 w2404_is_culling(W2404Obj*) asm("_ZN2YS3OBJ10is_cullingEv");
void kn__Friend__setAttackTarget(W2404Obj*, W2404Tgt*, s32, f32) asm("kn__Friend__setAttackTarget");
struct W2404Party { u8 pad[0xb40]; struct W2404PC* pc; };
struct W2404PC { s32 x; W2404Tgt tgt; };
struct W2404Friend { u8 pad[0x9f4]; W2404Tgt tgt; };
W2404Party* w2404_party(s32) asm("_ZN2kn6Friend13getPartyCharaEi");
void* w2404_obs(W2404Friend*) asm("_ZN2kn6Friend14getObjObserverEv");
struct W2404Self { s32 x; W2404Friend* fr; };
static inline bool w2404_valid(W2404Tgt* t) {
    bool r = false;
    if (w2404_is_exist(t)) r = t->obj != 0;
    return r;
}
static inline s32 w2404_first(void* obs, W2404Obj* cur) {
    s32 v = 0;
    if (cur) {
        v = func_00135c88(obs, cur);
        if (v >= 0) v++; else v = 0;
    }
    return v;
}
/*TARGET 00118da0*/
void kn__Stitch__set_target(W2404Self* self) asm("kn__Stitch__set_target");
void kn__Stitch__set_target(W2404Self* self) {
    W2404Party* party = w2404_party(0);
    void* obs;
    obs = w2404_obs(self->fr);
    W2404Tgt* ft = &self->fr->tgt;
    W2404Obj* cur = ft->obj;
    func_00190128(ft);
    W2404Tgt t;
    func_00190128(&t);
    func_00190128(&t);
    W2404PC* pc = party->pc;
    bool ok; W2404Tgt* src;
    if (pc) {
        src = &pc->tgt;
        t = *src;
        ok = w2404_valid(&t);
        if (ok && (t.obj->flags & 0x10) && w2404_can_attack(&t) && func_00135c88(obs, t.obj) < 0) {
            func_00135bd0(obs, t.obj);
        set:
            self->fr->tgt = t;
            return;
        }
    }
    {
        func_00190128(&t);
        s32 i = 0;
        while ((i = YS__TARGET__each(&t, i)) != 0) {
            if (w2404_can_attack(&t) && !w2404_is_culling(t.obj)) {
                if (func_00135c88(obs, t.obj) < 0) { func_00135bd0(obs, t.obj); self->fr->tgt = t; return; }
            }
        }
        func_00190128(&t);
        s32 n = w2404_entry_num(obs);
        s32 k = w2404_first(obs, cur);
        for (s32 j = k; j < k + n; j++) {
            W2404Obj* o = func_00135d00(obs, j);
            if (!w2404_is_culling(o)) {
                kn__Friend__setAttackTarget(o, &t, 0, 0.0f);
                ok = w2404_valid(&t);
                if (ok && w2404_can_attack(&t)) goto set;
            }
        }
    }
}
}  // namespace n00118da0


// 00119000, 00119108, 001192b0, 001193f0: never-written friend limit actions.
namespace n00119000 {
struct Obj119000 {
    u8 pad0[268]; u32 f268;
    u8 pad1[340 - 272]; s32 f340;
    u8 pad2[1688 - 344]; union { f32 f; } f1688;
    u8 pad3[2808 - 1692]; Obj119000* member[2];
};
struct Who119000 {
    u8 pad0[4];
    Obj119000* model;
    u8 pad1[1856 - 8];
    u8 cam[64];
    u8 hidden[3];
};
struct V119000 { f32 x, y, z, w; };
extern V119000 D_003a99d0 asm("D_003a99d0");
extern V119000 D_003a99e0 asm("D_003a99e0");
s32 func_0010f8c0(Obj119000*) asm("func_0010f8c0");
void kn__Stitch__set_target(Who119000*) asm("kn__Stitch__set_target");
Obj119000* func_00111e38(s32) asm("_ZN2kn6Friend13getPartyCharaEi");
void func_00117808(Who119000*, V119000*) asm("func_00117808");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 YS__MOTION__capture(void*, Obj119000*, s32, f32) asm("YS__MOTION__capture");
void func_0017f5f8(void*, s32, s32, f32, f32) asm("func_0017f5f8");
void YS__ENEMY__StopStartAll(s32) asm("YS__ENEMY__StopStartAll");
void* kn__Stitch__startEffect(Who119000*, s32, Obj119000*, s32, s32, s32, s32, s32) asm("kn__Stitch__startEffect");
void func_00117b20(Who119000*, void*) asm("func_00117b20");
void func_00118378(Who119000*, s32) asm("func_00118378");
void* func_0010c778(Obj119000*) asm("_ZN2kn6Friend14getObjObserverEv");
void func_00135aa0(void*) asm("_ZN2kn11ObjObserver5clearEv");
void func_001143d8(Who119000*) asm("_ZN2kn17FriendPersonality11start_limitEv");
void func_00194648(Obj119000*, void*) asm("_ZN2YS3OBJ13attach_cameraEPN2kn7FMatrixE");
s32 func_001c0cd8(Obj119000*) asm("_ZN2YS3OBJ9is_attachEv");
void func_001c0e60(Obj119000*) asm("_ZN2YS3OBJ6detachEv");
void YS__OBJ__attach(Obj119000*, Obj119000*, s32, s32) asm("_Z15YS__OBJ__attachjjjj");
void func_0016bd60(Obj119000*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
s32 func_001196d0(void*, s32) asm("func_001196d0");
void func_00112778(Obj119000*, s32 (*)(void*, s32)) asm("_ZN2kn6Friend17setCallFromScriptEPFiPS0_iE");
void func_00198860(Obj119000*, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void func_00117588(Who119000*) asm("_ZN2kn6Stitch14update_obj_posEv");

s32 func_00119000(Who119000* w, void* e, void* t, s32* score, u8 check) asm("func_00119000");
s32 func_00119000(Who119000* w, void* e, void* t, s32* score, u8 check)
{
    if (check) {
        if (!func_0010f8c0(w->model)) return 0;
        if (w->model->f340 != 201) return 0;
    } else if (!func_0010f8c0(w->model)) {
        kn__Stitch__set_target(w);
        Obj119000* pc = func_00111e38(0);
        func_00117808(w, &D_003a99d0);
        func_0017f488((u8*)w->model + 320, 201, 0.0f, 0.0f);
        func_0017f5e0((u8*)w->model + 320, 0, 0.0f, 0.0f, 0);
        YS__MOTION__capture((u8*)w->model + 320, pc, 257, 0.0f);
        func_0017f5f8((u8*)pc + 320, 254, 0, 0.0f, 0.0f);
    }
    return 1;
}

s32 func_00119108(Who119000* w, void* e, void* t, s32* score, u8 check) asm("func_00119108");
s32 func_00119108(Who119000* w, void* e, void* t, s32* score, u8 check)
{
    if (check) {
        if (!func_0010f8c0(w->model)) return 0;
        if (w->model->f340 != 205) {
            YS__ENEMY__StopStartAll(17);
            return 0;
        }
    } else {
    if (!func_0010f8c0(w->model)) {
        Obj119000* pc = func_00111e38(0);
        func_00117808(w, &D_003a99d0);
        func_0017f488((u8*)w->model + 320, 205, 0.0f, 0.0f);
        func_0017f5e0((u8*)w->model + 320, 0, 0.0f, 0.0f, 0);
        s32 r = YS__MOTION__capture((u8*)w->model + 320, pc, 255, 0.0f);
        func_0017f5f8((u8*)pc + 320, 254, 0, 0.0f, 0.0f);
        kn__Stitch__startEffect(w, 3, 0, -1, 205, 0, 1, 0);
        func_00117b20(w, kn__Stitch__startEffect(w, 4, w->model, 19, 205, 0, 1, 0));
        func_00117b20(w, kn__Stitch__startEffect(w, 4, pc, 65, -r, 0, 1, 0));
    }
    func_00118378(w, 205);
    }
    return 1;
}

s32 func_001192b0(Who119000* w, void* e, void* t, s32* score, u8 check) asm("func_001192b0");
s32 func_001192b0(Who119000* w, void* e, void* t, s32* score, u8 check)
{
    if (check) {
        if (!func_0010f8c0(w->model)) return 0;
        if (w->model->f340 != 242) return 0;
    } else {
        if (!func_0010f8c0(w->model)) {
            kn__Stitch__set_target(w);
            Obj119000* pc = func_00111e38(0);
            func_00117808(w, &D_003a99e0);
            func_0017f488((u8*)w->model + 320, 242, 0.0f, 0.0f);
            s32 r = YS__MOTION__capture((u8*)w->model + 320, pc, 256, 0.0f);
            kn__Stitch__startEffect(w, 12, 0, -1, 242, 0, 1, 0);
            func_00117b20(w, kn__Stitch__startEffect(w, 13, pc, 65, -r, 0, 1, 0));
        }
        func_00118378(w, 242);
    }
    return 1;
}

void func_001193f0(Who119000* w) asm("func_001193f0");
void func_001193f0(Who119000* w)
{
    func_00135aa0(func_0010c778(w->model));
    func_001143d8(w);
    Obj119000* pc = func_00111e38(0);
    func_00117808(w, &D_003a99d0);
    func_0017f488((u8*)w->model + 320, 0, 0.0f, 0.0f);
    YS__MOTION__capture((u8*)w->model + 320, pc, 254, 0.0f);
    func_00194648(pc, w->cam);
    u32 m = pc->f268 & 0x200;
    w->hidden[0] = m == 0;
    pc->f268 |= 0x200;
    for (s32 i = 0; i < 2; i++) {
        Obj119000* o = pc->member[i];
        if (!o) continue;
        if (func_001c0cd8(o)) func_001c0e60(o);
        YS__OBJ__attach(o, pc, 0x4000, 0);
        func_00194648(o, w->cam);
        o->f1688.f = 1e7f;
        u32 k = o->f268 & 0x200;
        w->hidden[i + 1] = k == 0;
        o->f268 |= 0x200;
    }
    func_0016bd60(pc, 60);
    pc->f1688.f = 1e7f;
    func_00112778(w->model, func_001196d0);
    func_00198860(w->model, 4);
    func_00117588(w);
}
}  // namespace n00119000
