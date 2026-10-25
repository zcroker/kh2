#include "../common/types.h"


extern "C" {
void func_00135cc8(void*, u32, u32);
void func_00135ad0(void*);
u32 func_0016c3a8(u32, u32);
void func_00185278(u32, f32, u32);
u32 func_0016b800(u32);
u32 func_001d14a0(void);
void func_001b6bd8(u32, u32);
u8* func_0019b260(void*, s32);
u32 func_001d96c0(u32, u32);
void func_001a1a20(void*, u32, u32);
void func_001d48b0(void*);
void func_001bd668(void*);
void func_001bd2d0(void*);
void func_001bd5b0(void*, u32, u32);
void func_00176cd0(void*);
void func_001dc9e0(void*);
void func_001e6ce8(u32);
void func_001e72a8(void*);
void func_0022ac60(void*);
void func_001390f0(void*);
void func_00234348(u32, u32, u32, u32, u32, u32);
void func_002b4b00(void);
void func_0028f4d8(u32, u32, u32);
void func_00240be0(void);
u8* func_00257770(void);
void func_0028da70(void*, u32);
void func_00280148(void);
void func_002800d0(void);
void func_00287cc0(u32);
u8* func_00167f18(u32);
void func_00138d48(void*);
void func_001395f8(void*);
void func_00170950(u32);
u32 func_002bc0f0(s32);
void* func_001050d8(u32);
void func_002e0d28(void*, u32);
void func_0017f5f8(u32, u32, u32, f32, f32);
void func_003146c8(void*);
void func_00106420(void*);

extern u32 D_0034aa90;
extern u32 D_0034aa94;
extern void* D_0034dc98;
extern void* D_01d5bb00;
extern void* D_01d9e340;
extern u32 D_00350f18;
extern u32 D_00350f1c;
extern u8* D_01d48cb0;
extern u8* D_01d49320;
extern u32 D_00359810;
extern u32 D_00359788;
extern u32 D_00359808;
extern u32 D_00359780;
extern u8 D_0032b100[];
extern u8 D_0032a980[];
extern u8* D_0035ec94;
extern u16 D_00372eea;
extern u8 D_00348d58[];
extern u8 D_00348698[];

void bc_make(void) asm("_ZN2dk14BlindCollision4makeEv");
void trap_obj_search_by_part(u32* v) asm("_ZN2YS23trap_obj_search_by_partEP8BD_VALUE");
void trap_player_capture_form(u32* v) asm("_ZN2YS24trap_player_capture_formEP8BD_VALUE");
void reset_anmatr_flag(u8* m) asm("_ZN2YS6MOTION17reset_anmatr_flagEv");
void group_enable(void* g, s32 i) asm("_ZN2YS10UNIT_GROUP6EnableEi");
void reset_special_command(u8* c) asm("_ZN2YS14PLAYER_COMMAND21reset_special_commandEv");
void effect_angle(u8* e) asm("_ZN3ryj6EFFECT5angleEv");
void jm_unload(u8* j) asm("_ZN2Tz6JmInfo6UnloadEz");

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

void func_00107300(u8* p, u8* a, u8* b, f32 f) {  // copy_blocks_and_store_float
    u8* d = p + 80;
    if (d != a) QCOPY(d, a);
    d = p + 96;
    if (d != b) QCOPY(d, b);
    *(f32*)(p + 128) = f;
}

u32 func_001231f8(void* o, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) {
    return (*(u32 (**)(void*, u32, u32, u32, u32, u32, u32, u32))(*(u8**)o + 76))(o, a1, a2, a3, t0, 0, t1, t2);
}

void func_00135c50(void* p, u32 a) {
    func_00135cc8(p, a, 0);
    func_00135ad0(p);
}

void bc_make(void) {
    D_0034aa94 = func_0016c3a8(D_0034aa90, 64);
}

void func_0016fb00(u32 a) {
    void* o = D_0034dc98;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}

struct Args171690 { u32* obj; f32 f; u32 flag; };
void func_00171690(Args171690* p) {
    u32 x = p->obj[1];
    func_00185278(x, p->f, p->flag != 0);
}

void trap_obj_search_by_part(u32* v) {
    u8* out = (u8*)v[0];
    u32 r = func_0016b800(v[1]);
    *(u32*)(out + 4) = r;
}

void trap_player_capture_form(u32* v) {
    func_001b6bd8(func_001d14a0(), v[0]);
}

void reset_anmatr_flag(u8* m) {
    *(u32*)(m + 40) = 0;
    *(u32*)(m + 32) &= 0x7183;
    *(u32*)(m + 36) &= ~1;
    *(u32*)(m + 36) &= ~2;
}

void group_enable(void* g, s32 i) {
    u8* u = func_0019b260(g, i);
    *(u32*)(u + 4) &= ~1;
}

void func_001a06e0(u32* p) {
    p[0] = func_001d96c0(p[0], p[1]);
}

struct Obj1a1db8 { u8 pad[444]; f32 x, y; };
void func_001a1db8(Obj1a1db8* p) {
    p->x = p->y = 0.0f;
    func_001a1a20(p, *(u32*)((u8*)p + 388), 0);
}

u32 func_001b1fc8(u32 a) {
    return D_00350f18 == 0 && D_00350f1c == a;
}

u16 func_001b5af0(void) {
    u8* p = D_01d48cb0;
    if (p == 0 || (*(u32*)(p + 64) & 4)) return 0;
    return *(u16*)(*(u8**)p + 40);
}

u32 func_001bbb28(void) {
    u8* p = D_01d49320;
    if (p == 0) return 0;
    if (*(u16*)(*(u8**)(p + 8) + 4) & 0x400) return 1;
    return 0;
}

void reset_special_command(u8* c) {
    func_001d48b0(c + 2496);
    func_001bd668(c);
}

void func_001bdf38(u8* p) {
    func_001bd2d0(p);
    func_001bd5b0(p, *(u32*)(p + 2724), 0);
}

void func_001c0a80(u8* p) {
    s32 i;
    for (i = 0; i < 19; i++) p[i] = 0;
}

void func_001d14b8(u8* p) {
    if (*(s32*)(p + 2896) != 6) func_00176cd0(p);
}

void func_001dc4b8(u32 a) {
    void* o = D_01d5bb00;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}

void effect_angle(u8* e) {
    func_001dc9e0(e);
    func_001e6ce8(*(u32*)(e + 28));
}

void func_001de978(u32 a) {
    void* o = D_01d9e340;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}

void func_0020eac0(void) {
    D_00359788 = 0x70000000;
    D_00359810 = 0x70004000;
    D_00359780 = 0;
    D_00359808 = 0;
}

void func_0021cda0(s32 a) {
    if (a == 0) func_001e72a8(D_0032a980);
    else func_001e72a8(D_0032b100);
}

void func_0022acd0(void* p) {
    func_0022ac60(p);
    func_001390f0(p);
}

void func_00234670(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    func_00234348(a0, 0, a1, a2, a3, t0);
}

u8* func_0023e788(u8* d, u8* p, s32 i) {
    u8* s = p + *(u8*)(i + (u32)p + 2916) * 320 + 1632;
    QCOPY(d, s);
    return d;
}

u32 func_00241770(s32 i) {
    if (i < 0) i = (s8)D_0035ec94[1];
    return (*(s32*)(D_0035ec94 + i * 32 + 8) >> 4) & 1;
}

void func_0025a1d0(void) {
    func_002b4b00();
    func_0028f4d8(0, D_00372eea, 0);
    func_00240be0();
}

void func_002631b0(void) {
    func_0028da70(func_00257770() + 0xb350, 307);
}

void func_0027f9b0(void) {
    func_00280148();
    func_002800d0();
    func_00287cc0(0);
}

s32 func_00288088(void) {
    return *(u64*)(func_00167f18(0) + 8) != 0;
}

void func_0028d708(void* p) {
    func_00138d48(p);
    func_001395f8(p);
}

void jm_unload(u8* j) {
    func_00170950(*(u32*)(j + 4));
    *(u32*)(j + 4) = 0;
    j[16] = 0;
}

u32 func_002bc158(s32 a) {
    if (a == 0) return 0;
    if (a < 0) return 0;
    return func_002bc0f0(a);
}

void func_002e0bb0(u32 a) {
    func_002e0d28(func_001050d8(240), a);
}

struct Flags2e9fb8 { u32 lo : 16; u32 flag : 1; u32 hi : 15; };
void func_002e9fb8(u8* p, u8 b) {
    ((Flags2e9fb8*)(p + 4))->flag = b != 0;
}

void func_002f0a38(u32* p) {
    func_0017f5f8(p[0] + 320, p[1], 0, *(f32*)(p + 2), 0.0f);
}

// VU0 vector blend: d = a*t + b*(1-t).
void func_002f3ed0(f32* d, f32* a, f32* b, f32 t) {  // vec4_lerp
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\t"
        "mfc1 $8, %3\n\t"
        "qmtc2 $8, $vf6\n\t"
        "vaddw.x $vf7, $vf0, $vf0w\n\t"
        "vsub.x $vf8, $vf7, $vf6\n\t"
        "vmulax.xyzw ACC, $vf4, $vf6x\n\t"
        "vmaddx.xyzw $vf9, $vf5, $vf8x\n\t"
        "sqc2 $vf9, 0(%0)"
        : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}

struct Args314480 { u32 a, b, c; u64 d; };
void func_00314480(u32 a, u32 b, u32 c, u64 d) {
    Args314480 s;
    s.a = a; s.b = b; s.c = c; s.d = d;
    func_003146c8(&s);
}

void func_003197f8(u8* p) {
    void* o = *(void**)(p + 4);
    (*(void (**)(void*))(*(u8**)o + 4))(o);
}

void func_0031e068(u8* p) {
    *(u8**)(p + 416) = D_00348698;
    *(u8**)(p + 144) = D_00348698;
    *(u8**)(p + 0) = D_00348d58;
    func_00106420(p);
}
}

void wtarget_0016b070(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    u8* d = p + 1360;
    if (d != (u8*)a1) QCOPY(d, a1);
    *(f32*)(p + 1372) = *(f32*)(a1 + 4);
    *(u32*)(p + 2040) |= 8;
}

// 001d3350: moved to src/anon/unit_001d30b0.cpp
