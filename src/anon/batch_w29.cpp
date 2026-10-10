#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

typedef void (*VFnF)(void*, f32);
typedef u32 (*VFn4)(void*, u32, u32, u32);

struct E16 { u32 w[4]; ~E16() {} } __attribute__((aligned(16)));
struct LimitEntry { u8 pad[40]; u16 id; u8 pad2[22]; };
struct LimitTbl { u32 f0; s32 count; LimitEntry e[1]; };
struct Flag250 { u8 pad[592]; u32 on:1; u32 rest:31; };
struct Tri { u32 a, b, c; };
struct W3 { u32 w[3]; };
struct FPParts { u32 w[8]; };

extern "C" {
void createTask(void) asm("_ZN2dk9ObjCamera10createTaskEv");
void camera_task(void) asm("_ZN2dk11camera_taskEP4TASK");
u32 isManual(u64* pad) asm("_ZN2dk12CameraConfig8isManualEPN2YS3PADE");
u32 isCameraAuto(void) asm("_ZN2Tz6Config12isCameraAutoEv");
void* anim_getNext(void* w) asm("_ZNK2kn13AnimationWork7getNextEv");
u32* party_get_ability(u32 p) asm("_ZN2YS5PARTY11get_abilityEv");
u32 trap_obj_add_hp(u32* v) asm("_ZN2YS15trap_obj_add_hpEP8BD_VALUE");
void wtarget_00146730(u32 a, u32 b) asm("_Z16wtarget_00146730jjjj");
u32 progress_CheckFlag(s32 f) asm("_ZN2YS8PROGRESS9CheckFlagEi");
u8* ctarget_00198bd0(s32 a, s32 b) asm("_Z16ctarget_00198bd0jjjj");
LimitEntry* GetLimitEntry(s32 id) asm("_ZN2Tz6JmInfo13GetLimitEntryEz");
u32 ctarget_001d9228(s32 i) asm("_Z16ctarget_001d9228jjjj");
void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) asm("_Z16ctarget_001db8f8jjjj");
void ItemStat_ctor(u32* p) asm("_ZN2Tz8ItemStatC1Ev");
s32 SelCheck(s32 i) asm("_ZN2Tz10JmWorldSel8SelCheckEi");
void ctarget_002cf3f8(void) asm("_Z16ctarget_002cf3f8jjjj");
void wtarget_002eb460(u8* o, Q16* q) asm("_Z16wtarget_002eb460jjjj");

void func_0015ce90(void);  // zero_global_byte_g
void func_001069b8(u32);  // swap_global_word
void func_0013f558(void*);
u8* func_00102c80(void);
void func_00102788(u32, u32, u32, void*);
void func_00139858(u32);
void func_00139ab0(u32);
void func_00144b38(u32, E16*);
void func_001466b0(u32, E16*);  // mat4_transform_vecs
void func_0016bda8(Q16*, u32);
void func_0013dad0(void*);
void func_00192f78(void*);  // obj_init_float_const
void func_001ab750(u32, void*);
u8 func_001aafe8(u32, u32*, u32, u32, u32, u32, f32, f32);
void func_001acdc0(void*, u32, u32, u32, u32, u32);
void func_001ac310(void*);
u32 func_001dc9d0(u32);
void func_001d7cd0(void*);
u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001c23a8(u8*, u32, u32, u32, u32, u32, u32);
void func_00223e98(u32, u8*, u32, u32, f32, f32, u32);
u32 func_0022b688(u32);
void func_001391a8(u32, Q16*);  // vec_copy_at416_if_diff
void func_002251c8(u32);
u32 func_00139d78(u32);
void func_00239700(void*);
void func_0028d188(void*);
u8* func_00294000(u32);
s32 func_00295158(s32);
u8 func_002941a8(u8*);
void func_00292630(void);
void func_0029e430(void);
void func_00293c40(s32, u32);
void func_002925c0(void);
u8* func_002a9d68(void);
void func_002be340(u32);
u32 func_002be4a0(void);
void func_00102448(u32, u32);
void func_00106450(u32);
void func_001d86a0(u32, u32);
void func_002cfeb0(u32*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002cf280(void*, u32, u32);
void func_002e70b0(void*);
void func_00106420(void*);
u8 func_002cea28(void*);
void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
u32 func_003032d0(u32, u32*);
void func_003147a0(void*, void*);
void* func_003141e8(void*, void*);
u64 func_003146c8(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);

extern u8 D_00348710[];
extern Q16 D_01c5f480;
extern u32 D_0032d7c0[][8];
extern u8 D_01c61b48[];
extern u32 D_01d49530[];
extern u8 D_00351468[];
extern LimitTbl* D_01d5ba28;
extern u8 D_00352a78[];
extern u32 D_00354688;
extern s32 D_0035468c;
extern u8* D_0035ec94;
extern u16 D_0035ef70;
extern u32 D_0035f07c;
extern u32 D_0035f078;
extern u8 D_00347e60[];
extern u8 D_0035f420[];
extern s8 D_0035f228;
extern s16 D_0035f5b6;
extern u32 D_00361fa4;
extern u32 D_00361fa0;
extern W3 D_00375a40;
extern u8 D_00362858[];
extern u8 D_00362dc8[];
extern u8 D_0034ee08[];

// Calls a virtual method (slot 5) with t on every animation work in o's list.
void func_0011ea40(u8* o, f32 t) {
    void* p = *(void**)(o + 56);
    while (p) {
        (*(VFnF*)((*(u8**)p) + 20))(p, t);
        p = anim_getNext(p);
    }
}

void createTask(void) {
    func_0015ce90();  // zero_global_byte_g
    func_001069b8(0);  // swap_global_word
    func_0013f558(D_00348710);
    func_00102788(*(u32*)(func_00102c80() + 4), 1, 26000, (void*)camera_task);
}

void wtarget_00146730(u32 a, u32 b) {
    E16 buf[8];
    func_00144b38(b, buf);
    func_001466b0(a, buf);  // mat4_transform_vecs
}

void func_0014f4d8(void) {
    func_00139858(7);
    func_00139858(9);
    func_00139858(8);
    func_00139858(10);
    func_00139ab0(7);
    func_00139ab0(9);
    func_00139ab0(8);
    func_00139ab0(10);
}

u32 func_00154ee8(u8* p) {  // field24_state_code
    switch (*(s32*)(p + 24)) {
    case 1: return 67;
    case 0: case 2: return 72;
    default: return 72;
    }
}

u32 isManual(u64* pad) {
    u32 r = 1;
    if (!(*pad & 0x100000000ULL)) r = 0;
    if (!isCameraAuto()) r = !r;
    return r;
}

// Ability bit test: v[0] = party's ability bit v[1] is set.
void func_00171a70(u32* v) {
    u32* bits = party_get_ability(*(u32*)(v[0] + 4));
    u32 n = v[1];
    v[0] = (bits[n >> 5] & (1 << (n & 31))) != 0;
}

u32 trap_obj_add_hp(u32* v) {
    void* o = *(void**)(v[0] + 4);
    return v[0] = (*(VFn4*)((*(u8**)o) + 120))(o, v[1], v[2], v[3] != 0);
}

void func_00173dc0(u32* v) {
    Q16 t;
    func_0016bda8(&t, *(u32*)(v[0] + 4));
    Q16* d = &D_01c5f480;
    if (d != &t) QCOPY(d, &t);
    v[0] = (u32)d;
}

// Story progress flag test (0xffff = none).
u32 progress_CheckFlag(s32 f) {
    u32 r = 0;
    if (f != 0xffff) {
        u32* row = D_0032d7c0[f >> 10];
        f &= 0x3ff;
        r = (row[(u32)f >> 5] & (1 << (f & 31))) != 0;
    }
    return r;
}

// Finds the 88-byte entry (of 16) matching (a, b); falls back to a wildcard match.
u8* ctarget_00198bd0(s32 a, s32 b) {
    u8* best = 0;
    u8* e;
    for (e = D_01c61b48; (s32)e < (s32)(D_01c61b48 + 1408); e += 88) {
        if (*(s32*)e == a) {
            s32 k = *(s32*)(e + 4);
            if (k == b) return e;
            if (b < 0 || k < 0) best = e;
        }
    }
    return best;
}

void func_001a2710(Flag250* p) {
    if (p->on) {
        func_0013dad0(p);
        p->on = 0;
    }
}

void func_001aa790(u32* p, u32 a) {
    p[0] = a;
    p[5] = 0x60000000;
    p[1] = 0;
    func_00192f78(p + 8);  // obj_init_float_const
    p[14] = 0;
    p[15] = 0;
    Tri* q = (Tri*)(p + 16);
    q->a = 0;
    q->c = 0;
    q->b = 0;
    p[19] = 0;
    func_001ab750(p[0], q);
}

u8 func_001aa8a8(u32* p, u32 a, u32 b, u32 c, u32 d) {
    return func_001aafe8(p[0], p + 16, a, b, c, d, *(f32*)(p + 9), *(f32*)(p + 10));
}

void func_001ad3e0(u32* p) {
    func_001acdc0(p, p[1], p[2], p[1] + (p[23] >> 1), p[2] + (p[24] >> 1), 432);
    func_001ac310((u8*)p + 2924);
}

void func_001c2ba8(void) {
    u32* p = D_01d49530;
    for (s32 i = 7; i >= 0; i--) {
        if (*p && !func_001dc9d0(*p)) *p = 0;
        p++;
    }
}

void func_001c2ce8(u8* p) {
    func_001d7cd0(p);
    *(void**)p = D_00351468;
    *(u32*)(p + 1416) |= 0x200000;
    *(u32*)(p + 2748) |= 4;
}

LimitEntry* GetLimitEntry(s32 id) {
    for (s32 i = 0; i < D_01d5ba28->count; i++) {
        if (D_01d5ba28->e[i].id == id) return &D_01d5ba28->e[i];
    }
    return 0;
}

u32 ctarget_001d9228(s32 i) {
    s32 o = i * 64;
    if (func_001bb4a0()) {
        u32 f = *(u32*)(o + func_001bbcb0() + 620);
        if ((u8)(f & 1))
            return *(u32*)(o + func_001bbcb0() + 652);
    }
    return 0;
}

void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, b, 0, 0, 96, c);
    *(u32*)(p + 1416) |= 0x10000000;
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_00352a78;
}

// Replaces value a with b on every list node not flagged 0x200.
void func_001e01e8(u8* list, u32 a, u32 b) {
    u8* p = *(u8**)(list + 12);
    while (p) {
        if (!(*(u32*)(*(u8**)(p + 68) + 16) & 0x200)) {
            if (*(u32*)(p + 72) == a) *(u32*)(p + 72) = b;
        }
        p = !p ? (u8*)*(u32*)(list + 12) : *(u8**)(p + 96);
    }
}

void func_0020cf60(u32 a, u8* e) {
    if (D_00354688 && D_0035468c > 0)
        func_00223e98(*(u32*)(e + 4), e + 8, e[28], e[29], *(f32*)(e + 12), *(f32*)(e + 16), *(u32*)(e + 20));
}

u32 func_0022aef0(Q16* q) {
    u32 v = func_0022b688(141);
    Q16 t;
    QCOPY(&t, q);
    func_001391a8(v, &t);  // vec_copy_at416_if_diff
    func_002251c8(12102);
    return v;
}

// Any of the 99 32-byte entries has flag 0x10 set.
u32 func_00241a00(void) {
    u32 r = 0;
    u32* p = (u32*)(D_0035ec94 + 8);
    for (s32 i = 0; i < 99; i++) {
        if (*p & 0x10) { r = 1; break; }
        p += 8;
    }
    return r;
}

// Rank of bit n among the set bits of D_0035ef70 (-1 if not set).
s32 func_00257ff8(s32 n) {
    s32 r = -1;
    s32 m = D_0035ef70;
    s32 k = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((u8)((m >> i) & 1)) {
            if (i == n) { r = k; break; }
            k++;
        }
    }
    return r;
}

u32 func_00258a30(void) {
    u32 r = 0;
    if (D_0035f07c) r = func_00139d78(D_0035f07c) != 0;
    if (!r && D_0035f078) r = func_00139d78(D_0035f078) != 0;
    return r;
}

void ItemStat_ctor(u32* p) {
    p[3] = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 6);
    *(void**)p = D_0035f420;
    func_0028d188(p);
}

s32 SelCheck(s32 i) {
    u8* b = func_00294000(0) + 16;
    return func_002941a8(b + func_00295158(i) * 16);
}

void func_0029e3e0(u32 a) {
    func_00292630();
    func_0029e430();
    D_0035f5b6 = a;
    func_00293c40((s16)a, D_0035f228 == 1);
    func_002925c0();
}

// Sets bit n in the bitset at +136 (only if not already set).
void func_002ab258(u32 n) {
    u8* b = func_002a9d68();
    u32* w = (u32*)((n >> 5) * 4 + (u32)(b + 136));
    u32 bit = 1 << (n & 31);
    if (!(*w & bit)) *w |= bit;
}

void func_002bfd48(u32* p, u32 a) {
    func_002be340(a);
    while (func_002be4a0()) func_00102448(p[0], 0);
}

void ctarget_002cf3f8(void) {
    if (D_00361fa4) func_00106450(D_00361fa4);
    D_00361fa4 = 0;
    D_00361fa0 = 0;
}

void func_002d28f8(u32 x, u32 m, s32 i) {
    W3 t = D_00375a40;
    func_001d86a0(t.w[i] * m, 0);
}

void func_002daa50(u32* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(void**)p = D_00362858;
    func_002cf280((u8*)p + 2800, 1, 0);
}

u8 func_002e0ec8(u8* p) {
    *(void**)p = D_00362dc8;
    void* q = *(void**)(p + 112);
    if (q) {
        func_002e70b0(q);
        func_00106420(q);
    }
    return func_002cea28(p);
}

void wtarget_002eb460(u8* o, Q16* q) {
    Q16 t;
    QCOPY(&t, q);
    func_0017c4c8(o, &t);
    *(u32*)(o + 256) = 256;
    *(u32*)(o + 260) = 257;
    func_0016bd60(o, 49);
}

u32 func_002ffc08(u32 a, u32* p) {
    if (p[2] == 0) {
        p[1] = 0;
        return 0;
    }
    u32 r = func_003032d0(a, p);
    p[2] = 0;
    p[1] = 0;
    return r;
}

// Soft-float double binary op (libgcc dp-bit style): unpack both, combine, pack.
u64 func_00314190(u64 a, u64 b) {  // double_add
    FPParts x, y;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_003141e8(&x, &y));
}

void func_00320290(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}
