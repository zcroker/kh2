#include "../common/types.h"

struct u128 { u32 w[4]; } __attribute__((aligned(16)));
extern "C" {
void func_00135dc8(void*);
void func_00113668(void*);
void func_00105110(void*);
void func_0011e350(void*, u32);
void func_0011e450(void*, u32);
void func_0013efe8(void);
u8* func_00102c80(void);
void func_00102788(u32, u32, u32, void*);
void func_0013f428(void);
void func_0014b638(void*);
void func_0014a988(void*);  // clear_fields_244_260
void func_0014acf8(void);
void func_0014ac18(void);
void func_00167e28(void*);
void func_0019ba60(u32);
void func_0016c018(u32, u32, u32);
void func_00177a38(void*);
u32 func_001b58f0(u32, u32, u32, u32);
void func_001902a8(void*, void*);
void func_0018a970(void*, void*);
void func_001de450(void*);
void func_001dde40(void*);
void func_00170950(u32);
s32 func_002f71b0(s32);
void func_001ae678(void);  // to_306698_arg10
void func_001d2180(void*);
void func_001d20a8(void*);
void func_0017c4c8(void*, void*);
void func_001bc778(void*);
void func_001bc990(void*, void*);
void func_001dc920(u32);
void func_001db7d0(void*);
void func_001a4e30(void*);
void func_00190920(void*, s32, void*);
void func_00198450(void*);
void func_0023f8c8(void*);
void func_00106420(void*);
u8* func_001058e8(void);
void* func_00192048(s32);
void func_00263a90(void*, u8);
void func_0028da70(void*, s32);
s32 func_00287bc0(void);
u8* func_00294000(s32);
void func_002cff98(void*);
void func_002e7328(void*);  // to_2e7458
void* func_0010c7e8(u32);
void func_00118d10(void*, u32);
u32 func_00114438(void*, u32);
void func_0018d420(void*);
void func_002eec58(void*);

extern void** D_0032bb1c;
extern u32 D_0032b91c;
extern u32 D_00347550;
extern u32 D_00349b28;
extern void** D_0034a6f0;
extern u8 D_0034d6c0[];
extern u8 D_01c6cae0[];
extern u32 D_01c6cafc;
extern u8 D_00351248[];
extern u32 D_003527f0;
extern void* D_003527e4;
extern u32 D_0035ebd8;
extern u8* D_0035f264;
extern void** D_0035f34c;
extern u32 D_00362858;
extern u32 D_00362908;
extern u32 D_00350778;
extern u32 D_00361bf0;

void* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void YS_trap_obj_jump_direct(BD_VALUE*) asm("_ZN2YS20trap_obj_jump_directEP8BD_VALUE");
void YS_EFFECT_Ensure(void) asm("_ZN2YS6EFFECT6EnsureEv");
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
u32 YS_LIMIT_reset_hit_counter(u8*) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
void Tz_CMenuHelp_Create(s32, bool) asm("_ZN2Tz9CMenuHelp6CreateEib");
void kn_trap_friend_get_player_attacker(BD_VALUE*) asm("_ZN2kn31trap_friend_get_player_attackerEP8BD_VALUE");
void kn_trap_friend_get_action_param(BD_VALUE*) asm("_ZN2kn28trap_friend_get_action_paramEP8BD_VALUE");
void worldmap_ObjWidget_D0(void**) asm("_ZN8worldmap9ObjWidgetD0Ev");

void func_00104cf0(u16* d, u16* s) {
    if (s[0] != 0xffff) d[0] = s[0];
    if (s[1] != 0xffff) d[1] = s[1];
    if (s[2] != 0xffff) d[2] = s[2];
}

typedef void* (*AllocFn)(void*, u32, void*);
void* AREA_Alloc(u32 size) {
    void** h = D_0032bb1c;
    return (*(AllocFn*)*h)(h, size, __builtin_return_address(0));
}

u32 func_0010c7b0(u8* p) {  // obj_get_sub_lazy
    if (*(u32*)(p + 2908) == 0) func_00135dc8(p + 2908);
    return *(u32*)(p + 2908);
}

void func_001157d0(void** p) {
    *p = &D_00347550;
    func_00113668(p);
    func_00105110(p);
}

void func_0011e410(u8* p, u32 a) {
    func_0011e350(p, *(u32*)(p + 56));
    *(u32*)(p + 56) = 0;
    func_0011e450(p, a);
}

void func_0013f498(void) {
    func_0013efe8();
    func_00102788(*(u32*)(func_00102c80() + 4), 0, 300000, (void*)func_0013f428);
}

void func_0014a950(void** p) {
    func_0014b638(p);
    *p = &D_00349b28;
    func_0014a988(p);  // clear_fields_244_260
}

void func_0014ad20(void) {
    func_0014acf8();
    func_00102788(D_0032b91c, 0, 0x50910, (void*)func_0014ac18);
}

// Release the object held in D_0034a6f0 (virtual slot 4) and clear the pointer.
void func_00153100(void) {
    void** o = D_0034a6f0;
    if (o) {
        (*(void (**)(void*))((u8*)*o + 16))(o);
        D_0034a6f0 = 0;
    }
}

s32 func_00154288(u32, s32 a) {  // state_index_0_1_2
    switch (a) {
    case 0: return 3;
    case 1: return 0;
    case 2: return 2;
    }
    return 3;
}

// Run func_00167e28 on both 96-byte entries of D_0034d6c0.
void func_00167ee0(void) {
    u8* p = D_0034d6c0;
    for (s32 i = 0; i < 2; i++) {
        func_00167e28(p);
        p += 96;
    }
}

typedef void (*JumpFn)(void*, void*, s32);
void YS_trap_obj_jump_direct(BD_VALUE* bd) {
    u8* w = *(u8**)((u8*)bd[0].p + 4);
    void** o = *(void***)(w + 12);
    (*(JumpFn*)((u8*)*o + 8))(o, w, bd[1].i);
}

void func_00172a10(u32* p) {
    if (p[0]) func_0019ba60(*(u32*)(p[0] + 4));
    func_0016c018(*(u32*)(p[0] + 4), p[1], p[2]);
}

void func_00177a78(u8* p) {
    func_00177a38(p);
    if (p[2821] < 100) p[2821]++;
}

void func_0018fe48(u32* p) {
    p[0] = func_001b58f0(p[0], p[1], p[2], 0);
}

void func_001906f0(void* a, u128* v) {
    u32 buf[8];
    u128 t;
    buf[3] = 0;
    func_001902a8(a, buf);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(v) : "$8", "memory");
    func_0018a970(buf, &t);
}

void func_001940b8(u8* p, u32 a, u32 b, u32 c, f32 x, f32 y) {  // obj_set_bytes_and_lerp
    p[1664] = a;
    p[1665] = b;
    p[1666] = c;
    func_001ad990((u32)(p + 2240), *(f32*)(p + 2240), x, y);
}

void YS_EFFECT_Ensure(void) {
    func_001de450(D_01c6cae0);
    func_001dde40(D_01c6cae0);
    func_00170950(D_01c6cafc);
}

void func_001ad990(u32 p, f32 a, f32 b, f32 t) {
    f32* o = (f32*)p;
    if (0.0f < t) {
        o[0] = a;
        o[1] = (b - a) / t;
    } else {
        o[0] = b;
        o[1] = 0.0f;
    }
}

void func_001ae620(void) {
    while (func_002f71b0(1)) func_001ae678();
}

u32 YS_LIMIT_reset_hit_counter(u8* self) {
    u8* h = self + 104;
    u32 n = *(u32*)(h + 44);
    func_001d2180(h);
    func_001d20a8(h);
    return n;
}

void func_001b6dd0(u8* p, u128* v) {
    u128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(v) : "$8", "memory");
    func_0017c4c8(p, &t);
    p[1300] = 3;
}

void func_001be900(u8* p) {
    func_001bc778(p + 152);
    func_001bc990(p + 152, p + 2628);
}

void func_001bf0c8(u8* p) {
    func_001bc778(p + 1428);
    func_001bc990(p + 1428, D_00351248);
}

// Destructor-shaped: the member at +20 is destroyed last (as a cleanup, so no tail call).
struct Member20Dtor { u32* self; ~Member20Dtor() { func_001db7d0(self + 5); } };
void func_001c13a8(u32* p) {
    Member20Dtor g = { p };
    func_001dc920(p[0]);
    func_00105110((void*)p[12]);
}

void func_001d74f8(void** p) {
    *p = &D_003527f0;
    D_003527e4 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

void func_001d7e00(u8* p) {
    func_00190920(p + 2548, 2, p);
    func_00198450(p);
}

// Fill the index table with 0..n-1 and reset the count.
void func_001db850(u8* p) {
    s32 i;
    for (i = 0; i < *(s32*)(p + 24); i++) ((s32*)*(u32*)(p + 16))[i] = i;
    *(s32*)(p + 8) = *(s32*)(p + 24);
}

void func_0023f870(void** p) {
    *p = &D_0035ebd8;
    func_0023f8c8(p);
    func_00106420(p);
}

struct Flags { u32 a; u32 on : 1; };
void func_00242a28(u8 on) {
    Flags* f = (Flags*)(func_001058e8() + 16800);
    f->on = on != 0;
}

void Tz_CMenuHelp_Create(s32 i, bool b) {
    void* p = 0;
    if (i >= 0) p = func_00192048(i);
    func_00263a90(p, b);
}

void func_002803e0(void) {
    func_0028da70(D_0035f264 + 24, 8);
    func_0028da70(D_0035f264 + 460, 11);
}

typedef void (*Slot1Fn)(void*, void*);
void func_00288c20(void* a) {
    if (a) {
        void** o = D_0035f34c;
        (*(Slot1Fn*)((u8*)*o + 4))(o, a);
    }
}

s32 func_002a43f0(void) {
    s32 v = func_00287bc0();
    s32 r = 0;
    if (v == 7 || v == 26) r = 1;
    return r;
}

u8* func_002a92a0(s32 i) {
    u8* b = func_00294000(8) + 16;
    return b + i * 16;
}

void func_002dab30(void** p) {
    *p = &D_00362858;
    func_002cff98(p);
    func_00105110(p);
}

// Destructor-shaped: base teardown runs last as a cleanup (no tail call).
struct BaseDtor { void** self; ~BaseDtor() { func_002cff98(self); } };
void func_002db8e8(void** p) {
    BaseDtor g = { p };
    *p = &D_00362908;
    func_002e7328((u8*)p + 2976);  // to_2e7458
}

void func_002df160(f32* p) {
    p[8] = 0.0f;
    f32 a = p[6];
    f32 b = p[8];
    ((u8*)p)[48] = 0;
    ((u8*)p)[49] = 0;
    p[7] = a;
    p[10] = b;
    p[9] = a;
    p[11] = b;
}

void kn_trap_friend_get_player_attacker(BD_VALUE* bd) {
    void* o = func_0010c7e8(*(u32*)((u8*)bd[0].p + 4));
    func_00118d10(o, bd[1].u);
}

void kn_trap_friend_get_action_param(BD_VALUE* bd) {
    void* o = func_0010c7e8(*(u32*)((u8*)bd[0].p + 4));
    bd[0].u = func_00114438(o, bd[1].u);
}

void func_0031f238(void** p) {
    *p = &D_00350778;
    func_0018d420(p);
    func_00105110(p);
}

void worldmap_ObjWidget_D0(void** p) {
    *p = &D_00361bf0;
    func_002eec58(p);
    func_00105110(p);
}

struct E24 { u8 a; u32 b; u32 pad[4]; };
extern E24 D_0035e440[64];
// Clear the 64-entry table at D_0035e440.
void func_00236d60(void) {  // clear_64_entries_24
    E24* e;
    for (e = D_0035e440; (s32)e < (s32)(D_0035e440 + 64); e++) {
        e->a = 0;
        e->b = 0;
    }
}

struct E64 { u8 pad[24]; u8 a; u8 b; u8 pad2[38]; };
// Number a 9x3 grid of 64-byte cells: row index and 1-based column.
void func_001e0958(E64* p) {
    s32 i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            p->a = i;
            p->b = j + 1;
            p++;
        }
    }
}
}
