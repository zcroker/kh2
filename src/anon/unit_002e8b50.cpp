#include "../common/types.h"

// Ts traps (0x2e8b50-0x2e9248): script traps for attacks, flares, friends and Trinity shots, with
// one static work vector (0x1e2bf90) that some traps return a pointer to. The 128-bit lq/sq
// copies are inline asm, as in the original (see src/sugi/flare.cpp).

// gcc's soft-float double libcalls; the routines live in the game.
asm("fptodp = func_00313b80");
asm("dpmul = func_00313f40");
asm("dpcmp = func_003142e0");
asm("dptofp = __truncdfsf2");

struct VEC {
    f32 x, y, z, w;
    VEC() {}
    ~VEC() {}
    VEC(const VEC& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    VEC& operator=(const VEC& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct OBJ {
    u32 f0;
    void* f4;
};

struct HIT {
    u32 f0;
    u32 f4;
    f32 f8;
    s32 n;
    VEC pos;
};

static VEC D_01e2bf90;

extern VEC D_0034eef0;

extern "C" {
void func_00185e20(void*);
void func_002e98b0(void*);
void func_002e9610(void*, VEC);
void func_002e95a0(u32, f32, f32);
s32 func_002e9850(void);
void* func_0016c028(void*);
void func_0018a818(HIT*, void*, void*);
f32 func_0010f338(void*);
s32 func_00112760(void*, s32);
s32 func_00112780(void*, s32);
void func_0010f8f0(void*);
void func_0010f908(void*);
s32 func_001b5af0(void);
s32 func_002ed4b8(void*, s32, VEC, VEC);
double func_002f8a88(double);  // sqrt
}
void* EachCollision(void*, s32, void*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void wtarget_0016c640(void*) asm("_Z16wtarget_0016c640jjjj");
void wtarget_002ed268(void*) asm("_Z16wtarget_002ed268jjjj");
void wtarget_002ed478(void) asm("_Z16wtarget_002ed478jjjj");
s32 ctarget_0010e130(void*, s32) asm("_Z16ctarget_0010e130jjjj");
s32 ctarget_002ed8e0(void*) asm("_Z16ctarget_002ed8e0jjjj");
s32 Friend_getToScript(void*) asm("_ZN2kn6Friend11getToScriptEv");
s32 SUMMON_GetMode(void) asm("_ZN2YS6SUMMON7GetModeEv");
s32 LIMIT_reset_hit_counter(void*) asm("_ZN2YS5LIMIT17reset_hit_counterEv");

namespace Ts {
class FLARE {
public:
    static void Init();
    static s32 IsEmpty();
};
class TRINITY_SHOT_OBJ {
public:
    static void Init();
};
}

extern "C" void func_002e8b50(BD_VALUE* bd) {
    func_00185e20(bd[0].p);
}

namespace Ts {

void trap_attack_hit_mark_pos(BD_VALUE* bd) {
    wtarget_0016c640(bd[0].p);
}

}  // namespace Ts

extern "C" void func_002e8b80(BD_VALUE* bd) {
    const VEC& s = D_0034eef0;
    D_01e2bf90 = s;
    bd[0].p = &D_01e2bf90;
}

extern "C" void func_002e8ba8(BD_VALUE* bd) {
    *(VEC*)((u8*)bd[0].p + 304) = *(VEC*)bd[1].p;
}

namespace Ts {

void trap_attack_set_reaction_offset(BD_VALUE*) {
    FLARE::Init();
}

}  // namespace Ts

extern "C" void func_002e8be8(BD_VALUE* bd) {
    bd[0].i = func_002e9850();
}

namespace Ts {

void trap_flare_free(BD_VALUE* bd) {
    func_002e98b0(bd[0].p);
}

}  // namespace Ts

extern "C" void func_002e8c28(BD_VALUE* bd) {
    func_002e9610(bd[0].p, *(VEC*)bd[1].p);
}

extern "C" void func_002e8c58(BD_VALUE* bd) {
    func_002e95a0(bd[0].u, bd[1].f, bd[2].f);
}

extern "C" void func_002e8c80(BD_VALUE* bd) {
    *(s32*)((u8*)bd[0].p + 60) = bd[1].i;
}

extern "C" void func_002e8c90(BD_VALUE* bd) {
    *(void**)((u8*)bd[0].p + 48) = ((OBJ*)bd[1].p)->f4;
}

extern "C" void func_002e8ca8(BD_VALUE* bd) {
    VEC t(*(VEC*)bd[0].p);
    D_01e2bf90 = t;
    bd[0].p = &D_01e2bf90;
}

namespace Ts {

void trap_flare_is_empty(BD_VALUE* bd) {
    bd[0].i = FLARE::IsEmpty();
}

}  // namespace Ts

extern "C" void func_002e8d08(BD_VALUE* bd) {
    HIT h;
    void* nd;
    void* e = ((OBJ*)bd[0].p)->f4;
    h.n = 0;
    nd = EachCollision(e, 0, 0);
    if (nd || (nd = EachCollision(e, 1, 0)) != 0) {
        func_0018a818(&h, e, nd);
        D_01e2bf90 = h.pos;
        D_01e2bf90.y -= h.f8 + 30.0f;
    } else {
        D_01e2bf90 = *(VEC*)func_0016c028(e);
    }
    bd[0].p = &D_01e2bf90;
}

extern "C" void func_002e8de8(BD_VALUE* bd) {
    f32 b = bd[0].f + bd[0].f;
    f32 a = bd[1].f;
    f32 c = (bd[2].f - bd[3].f) * -2.0;
    if (c < 0.0) {
        if (a != 0.0f) {
            f32 d = b * b - a * c * 4.0f;
            if (0.0f < d) {
                f32 s = func_002f8a88(d);
                f32 t1 = (s - b) / a;
                f32 t2 = (-b - s) / a;
                if (t2 < t1) {
                    t1 = bd[0].f + bd[1].f * t2;
                } else {
                    t1 = bd[0].f + bd[1].f * t1;
                }
                bd[0].f = t1;
            }
        }
    }
}

extern "C" void func_002e8f08(BD_VALUE* bd) {
    bd[0].f = func_0010f338(((OBJ*)bd[0].p)->f4);
}

extern "C" void func_002e8f38(BD_VALUE* bd) {
    u8* p = *(u8**)((u8*)((OBJ*)bd[0].p)->f4 + 12);
    s32 r = -1;
    if (p) r = *(s32*)(p + 4);
    bd[0].i = r;
}

namespace Ts {

void trap_friend_get_current_action(BD_VALUE* bd) {
    bd[0].i = func_00112760(((OBJ*)bd[0].p)->f4, bd[1].i);
}

void trap_friend_get_main_status(BD_VALUE* bd) {
    bd[0].i = Friend_getToScript(((OBJ*)bd[0].p)->f4);
}

void trap_friend_update_target(BD_VALUE* bd) {
    bd[0].i = ctarget_0010e130(((OBJ*)bd[0].p)->f4, bd[1].i != 0);
}

void trap_obj_limit_hover_set_spec(BD_VALUE* bd) {
    wtarget_002ed268(bd[0].p);
}

void trap_trinity_shot_init(BD_VALUE*) {
    TRINITY_SHOT_OBJ::Init();
}

}  // namespace Ts

extern "C" void func_002e9028(BD_VALUE* bd) {
    bd[0].i = func_002ed4b8(((OBJ*)bd[0].p)->f4, bd[1].i, *(VEC*)bd[2].p, *(VEC*)bd[3].p);
}

namespace Ts {

void trap_trinity_shot_ensure(BD_VALUE*) {
    wtarget_002ed478();
}

}  // namespace Ts

struct OBJ84 {
    u8 pad[84];
    u8 f84;
};

extern "C" void func_002e9098(BD_VALUE* bd) {
    OBJ84* o = (OBJ84*)bd[0].p;
    s32 v = bd[1].i;
    o->f84 = v;
}

namespace Ts {

void trap_friend_disable_system_wishdir(BD_VALUE* bd) {
    func_0010f8f0(((OBJ*)bd[0].p)->f4);
}

}  // namespace Ts

extern "C" void func_002e90c8(BD_VALUE* bd) {
    func_0010f908(((OBJ*)bd[0].p)->f4);
}

extern "C" void func_002e90e8(BD_VALUE* bd) {
    bd[0].i = func_00112780(((OBJ*)bd[0].p)->f4, bd[1].i);
}

namespace Ts {

void trap_friend_call(BD_VALUE* bd) {
    bd[0].i = func_001b5af0();
}

}  // namespace Ts

extern "C" void func_002e9148(BD_VALUE* bd) {
    *(f32*)((u8*)bd[0].p + 20) = bd[1].f;
}

namespace Ts {

void trap_enemy_summon_entry(BD_VALUE* bd) {
    bd[0].i = ctarget_002ed8e0(((OBJ*)bd[0].p)->f4);
}

}  // namespace Ts

extern "C" void func_002e9188(BD_VALUE* bd) {
    *(void**)((u8*)bd[0].p + 276) = ((OBJ*)bd[1].p)->f4;
}

namespace Ts {

void trap_attack_set_rc_owner(BD_VALUE* bd) {
    bd[0].i = (SUMMON_GetMode() != 0);
}

void trap_limit_reset_hit_counter(BD_VALUE* bd) {
    bd[0].i = LIMIT_reset_hit_counter(bd[0].p);
}

}  // namespace Ts
