#include "../common/types.h"

struct S6_1dad990 { s32 a, b, c, d, e, f; };
extern S6_1dad990 D_01dad990;
struct E6_347770 { s16 key; s16 val; s16 pad; };
extern E6_347770 D_00347770[6];
struct E12_1c608c0 { s32 a; s32 b; f32 c; };
extern E12_1c608c0 D_01c608c0[64];
extern f32 D_003634e8, D_003634ec, D_003634f0, D_003634f4, D_003634f8, D_003634fc, D_00363500;
struct F4_w1670 { f32 a, b, c, d; };
extern F4_w1670 D_01c61ae0;
extern F4_w1670 D_01d49520;
struct E2c_1c6cf00 { s32 a; u8 pad[0x28]; };
extern E2c_1c6cf00 D_01c6cf00[4];
struct S_348638 { s32 a, b, c; s32 d[3]; };
extern S_348638 D_00348638;

static inline void bitclr_w1670(u32* p, u32 n) { u32* w = &p[n >> 5]; *w &= ~(1 << (n & 0x1f)); }

extern "C" {
void func_001c79a0(u32, void*, u32);
void func_001991a8(u32, u32);
u8* ys_party_get_ability_w1670(u32) asm("_ZN2YS5PARTY11get_abilityEv");
void func_001d1da0(f32, u8*);
void func_00134408(void);
void func_00134428(u32, u64);
void func_00134450(u32);

void wtarget_0022d2e0(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0022d2e0jjjj");
void wtarget_0022d2e0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01dad990.a = 0;
        D_01dad990.b = 0;
        D_01dad990.c = 0;
        D_01dad990.d = 0;
        D_01dad990.e = 0;
        D_01dad990.f = 0;
    }
}

s32 func_00119f08(u8* p) {
    E6_347770* e = D_00347770;
    do {
        if (*(s32*)(p + 0x14) == e->key) return e->val;
        e++;
    } while ((s32)e < (s32)(D_00347770 + 6));
    return 0;
}

void func_00188490(s32 a, s32 b, f32 c) {
    s32 i = 0;
    E12_1c608c0* e = D_01c608c0;
    do {
        if (e->a == 0) { e->a = a; e->b = b; e->c = c; return; }
        i++; e++;
    } while (i < 64);
}

// 002eaea8: moved to src/anon/unit_002eae08.cpp

void wtarget_00194710(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00194710jjjj");
void wtarget_00194710(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        f32 z = 0.0f, o = 1.0f;
        D_01c61ae0.a = z;
        D_01c61ae0.b = o;
        D_01c61ae0.c = z;
        D_01c61ae0.d = o;
    }
}

void wtarget_001c2ad8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c2ad8jjjj");
void wtarget_001c2ad8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        f32 z = 0.0f, o = 1.0f;
        D_01d49520.a = z;
        D_01d49520.b = z;
        D_01d49520.c = z;
        D_01d49520.d = o;
    }
}

void func_0019f4e8(u32* p, u32 n) {
    bitclr_w1670(p, n);
    bitclr_w1670(p + 1, n);
}

void func_001ae788(u8* p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_01c6cf00[i].a == (s32)p) break;
    }
    D_01c6cf00[i].a = 0;
    *(u32*)(p + 8) = 0;
}

void func_001cc310(u8* o, u32 b) {
    func_001c79a0(b, o, 0);
    (*(s32*)(o + 0xac8))++;
    func_001991a8(0x11, 0);
}

void func_001b53b0(u8* o, f32 x) {
    u8* p = o + 0xa8;
    func_001d1da0(*(f32*)(p + 0x2c) + -x * *(f32*)(ys_party_get_ability_w1670(*(u32*)(o + 0xc)) + 0x60), p);
}

void func_00147e80(u8* o) {
    u64 v = (u64)(s32)(0x7000 - *(s16*)(o + 0x14)) | ((u64)(0x7300 - *(s16*)(o + 0x16)) << 32);
    func_00134408();
    func_00134428(0x18, v);
    func_00134450(1);
}

void wtarget_0013df48(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0013df48jjjj");
void wtarget_0013df48(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        S_348638* s = &D_00348638;
        s32* p = s->d;
        s32 i = 2;
        do { *p++ = 0; } while (--i != -1);
    }
}
}
