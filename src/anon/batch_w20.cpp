#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {
void dk_area_readData(void) asm("_ZN2dk4Area8readDataEv");
void trap_obj_voice(u32* v) asm("_ZN2YS14trap_obj_voiceEP8BD_VALUE");
u32 target_is_exist(const u8* t) asm("_ZNK2YS6TARGET8is_existEv");
void wtarget_002f0598(void* o, Q16* q) asm("_Z16wtarget_002f0598jjjj");
void trap_stitch_effect_kill(u32* v) asm("_ZN2kn23trap_stitch_effect_killEP8BD_VALUE");

void func_00102818(u32, u32, u32, u32, u32);
void func_00113668(void*);
void func_00105110(void*);
void func_00102c48(u32, u32, void*, u32);
void func_001384d0(void);
void func_0013a600(void);
void func_0013a4c8(void);
void func_001493b8(void*);
void func_00149428(void*);
void func_00138c10(void*, u32);
void func_00150be8(void*);
void func_00151d48(void*);
u8 func_00167e00(void*);
void func_00194108(void*, u32);
u32 func_001a4550(u32, u32);
u32 func_00190208(const u8*, u32);
u32 func_00239d10(u8*);
void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
u32 func_001bd418(u8*);
void func_001bd618(u8*, u32);
void func_001bc688(u8*);
void func_00190128(u8*);
void func_001ce378(void*);
extern void* D_01d5ba78[];
u8 func_002fd248(u32, u8*, u32, u32, void*);
void func_0021fa10(u8*);
void func_00236c38(void*);
void func_00106420(void*);
void func_00139d78(void*);
u8* func_001058e8(void);
void func_0028da70(void*, s32);
u32 func_00287bc0(void);
void func_00276c50(u32, u32);
u8* func_00294000(u32);
void func_0018a008(u32, void*, void*);
void func_002ef1b8(void);
u32 func_0010c7e8(u32);
void func_00117aa8(u32, u32);
void func_0016a358(void*);
u8 func_002cff98(void*);
void func_002e7328(void*);

extern u32 D_0033cb84;
extern void* D_003473c8[];
extern u32 D_00347e08;
extern u8 D_00348d68[];
extern u8 D_0034d6c0[];
extern s32 D_004f63a8[];
extern Q16 D_0034eef0;
extern Q16 D_0034ef00;
extern u16 D_0032bae0;
extern u32 D_0034f240;
extern u32 D_00350f18;
extern u32 D_01d44400;
extern u8 D_01d44440[];
extern void* D_00352780[];
extern u8* D_01d5ba9c;
extern u8 D_003218b8[];
extern u8* D_00352ae0;
extern void* D_0035eac8[];
extern u8* D_0035f244;
extern s8 D_0035f24c;
struct E374050 { u8 pad[4]; s16 v; };
extern E374050 D_00374050[];
extern u8* D_0035f34c;
extern u32 D_00374b44;
extern u32 D_00374b48;
extern void* D_00350388[];
extern void* D_00362398[];
extern void* D_00362908[];

void func_00105da8(u32 a, u32 b, u32 c, u32 d) {
    func_00102818(D_0033cb84, a, b, c, d);
}

// Returns the i-th 32-byte entry of the table hanging off p->f8, or 0 when out of range.
u8* func_00113808(u8* p, s32 i) {
    u8* h = *(u8**)(p + 8);
    if (!h) return 0;
    if (i < 0 || i >= *(s32*)(h + 0xa8)) return 0;
    return h + *(s32*)(h + 0xac) + i * 32;
}

void func_001156b8(void** p) {
    *p = D_003473c8;
    func_00113668(p);
    func_00105110(p);
}

// Index of v in the id list at p+16 (count at p+12), or -1.
s32 func_00135c88(u8* p, s32 v) {
    s32 n = *(s32*)(p + 12);
    for (s32 i = 0; i < n; i++) {
        if (((s32*)(p + 16))[i] == v) return i;
    }
    return -1;
}

void func_001385c0(void) {
    D_00347e08 = 0;
    func_00102c48(1, 0x4baf0, (void*)func_001384d0, 0x1000);
}

void dk_area_readData(void) {
    func_0013a600();
    func_0013a4c8();
    func_001493b8(D_00348d68);
    func_00149428(D_00348d68);
}

void func_001514e8(u8* p) {
    func_00138c10(p + 496, 3);
    func_00138c10(p + 904, 9);
    func_00150be8(p);
}

void func_001520c0(u8* p, s32 a) {
    *(s32*)(p + 0xb4c) += a;
    func_00138c10(p + 48, 17);
    func_00151d48(p);
}

s32 func_00167ea8(void) {
    func_00167e00(D_0034d6c0);
    return func_00167e00(D_0034d6c0 + 96);
}

s32 func_0016f930(s32 a) {
    for (s32 i = 0; i < 2; i++) {
        if (D_004f63a8[i] == a) return 2410 + i * 10;
    }
    return 2400;
}

void trap_obj_voice(u32* v) {
    u8* o = *(u8**)(v[0] + 4);
    (*(void (**)(u8*, u32, u32))(*(u8**)o + 84))(o, v[1], v[2]);
}

void func_00177638(void* p) {
    func_00194108(p, 2);
    func_00194108(p, 12);
    func_00194108(p, 22);
}

void func_0018e108(Q16* a, Q16* b) {
    if (a != &D_0034eef0) QCOPY(&D_0034eef0, a);
    if (b != &D_0034ef00) QCOPY(&D_0034ef00, b);
}

void func_0018f858(u32* p) {
    p[0] = func_001a4550(p[0], p[1]);
}

u32 target_is_exist(const u8* t) {
    u32 r = 0;
    if (*(u32*)(t + 8) != 0 || func_00190208(t, 0)) r = 1;
    return r;
}

u32 func_00191c50(void) {
    u32 r = 0;
    if (D_0032bae0 == 5906 || (D_0034f240 & 0x2000)) r = 1;
    return r;
}

u32 func_001ac1d0(u8* p) {
    if (!p[0]) return 0;
    return func_00239d10(p + 4) != 0;
}

u8* func_001b1ff0(s32 a) {
    if (a == -1) return 0;
    D_00350f18 = 2;
    D_01d44400++;
    return D_01d44440;
}

void func_001b2780(void* a0, void* a1, Q16* a2) {
    Q16 t;
    QCOPY(&t, a2);
    func_0017c4c8(a1, &t);
    func_0016bd60(a1, 20);
}

u32 func_001bd3e0(u8* p) {
    if (*(u32*)(*(u8**)(p + 0x9e0) + 0x588) & 0x2000000) return 0;
    return func_001bd418(p);
}

void func_001bd668(u8* p) {
    while (*(u32*)(p + 0x8c0)) func_001bd618(p, 0);
}

void func_001bde58(u8* p) {
    func_001bc688(p);
    func_00190128(p + 12);
}

void func_001d6538(void** p) {
    func_001ce378(p);
    *p = D_00352780;
    *(void**)((u8*)p + 0x9f8) = D_01d5ba78;
}

u8 func_001d7980(u32 a) {
    u8* t = D_01d5ba9c;
    return func_002fd248(a, t + 8, *(u32*)(t + 4), 4, D_003218b8);
}

// Clears flag 0x4000000 on every node of the list at D_00352ae0 (next at +0x28).
void func_001ddc48(void) {
    for (u8* n = D_00352ae0; n; n = *(u8**)(n + 40))
        *(u32*)(n + 8) &= ~0x4000000;
}

void func_001fb870(u8* a, u8* b) {
    u8* s = a + **(s32**)(b + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}

void func_00236a18(void** p) {
    *p = D_0035eac8;
    func_00236c38(p);
    func_00106420(p);
}

void func_0023f740(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x44) = a;
}

// The pair is read as 16-bit bitfields: plain s16 loads get hoisted above the first store.
struct Pair16 { s32 x : 16; s32 y : 16; };
void func_00242980(s32* a, s32* b) {
    Pair16* v = (Pair16*)(func_001058e8() + 16800);
    *a = v->x;
    *b = v->y;
}

void func_0027ead0(void) {
    func_0028da70(D_0035f244, D_00374050[D_0035f24c].v);
}

// Dispatches through slot 0 of the object at D_0035f34c, passing the caller's return address.
u32 func_00288be8(u32 a) {
    u8* o = D_0035f34c;
    return (*(u32 (**)(u8*, u32, void*))(*(u8**)o))(o, a, __builtin_return_address(0));
}

void func_002a1f40(void) {
    u32 a;
    if (func_00287bc0() == 6) a = D_00374b44; else a = D_00374b48;
    func_00276c50(a, 0);
}

u8* func_002a7f20(s32 i) {
    u8* b = func_00294000(7) + 16;
    return b + i * 8;
}

void func_002d6af0(void** p) {
    *p = D_00362398;
    func_002cff98(p);
    func_00105110(p);
}

s32 func_002db8a8(void** p) {
    *p = D_00362908;
    func_002e7328((u8*)p + 2976);
    return func_002cff98(p);
}

void func_002ef180(u8* p) {
    u32 c = *(u32*)(p + 12);
    if (c) func_0018a008(c, (void*)func_002ef1b8, p);
}

void wtarget_002f0598(void* o, Q16* q) {
    Q16 t;
    QCOPY(&t, q);
    func_0017c4c8(o, &t);
    func_0016bd60(o, 63);
}

void trap_stitch_effect_kill(u32* v) {
    func_00117aa8(func_0010c7e8(*(u32*)(v[0] + 4)), v[1]);
}

void func_0031f008(void** p) {
    *p = D_00350388;
    func_0016a358(p);
    func_00105110(p);
}

// 1 if v is in the list headed at *p (next at +0x1c).
u32 func_00324718(u8** p, u8* v) {
    u8* n = 0;
    while ((n = !n ? *p : *(u8**)(n + 0x1c)) != 0) {
        if (n == v) return 1;
    }
    return 0;
}
}
