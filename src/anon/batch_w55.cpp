#include "../common/types.h"

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct NoTail { ~NoTail() {} };

// 128-bit copy (lq/sq through t0).
static inline void copyQ(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// Random float in [0,1) from the VU0 R register.
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}

static inline bool isPos(f32 f) { return f > 0.0f; }

struct HeapW55;
struct ElemW55 { u8 d[64]; ElemW55() {} ~ElemW55() {} } __attribute__((aligned(16)));
void* operator new[](unsigned int, HeapW55*) asm("func_001063f0");

struct DeadRingW55 { void* e[4]; s32 idx; };
struct EntW55 { u32 id; f32 f; };
struct RingEW55 { u32 v; f32 f; };
struct RingW55 { s32 idx; s32 pad; RingEW55 e[3]; };
struct S1967 { u8 pad[7928]; u16 t[1]; };
struct PairW55 { u16 a; u16 x; u16 b; u16 v; };
struct SecW55 { u8 k; u8 type; u16 cnt; PairW55 p[1]; };
struct ItemW55 { u8 pad[12]; s16 on; u8 pad2[74]; };
struct BlkW55 { BlkW55* next; s32 count; ItemW55* items; };
struct FpW55 { s32 cls; u32 sign; s32 exp; u32 pad; u64 frac; } __attribute__((aligned(16)));
typedef void (*CbW55)(u8*, u32);

extern "C" {
void func_0016bd60(u32, s32);
extern u64 D_0036a938;
void func_00138698(u32, u32);
u32 func_0013a800(void);
void func_0013d4c8(void);
u32 func_0013a810(void);
u32 func_0013cb80(void);  // get_global_358050
void func_001387f8(u32, u32, u32, u32);
void func_0013b2d8(f32);
extern u32 D_00348050;
extern u8* D_003484a0;
extern u32 D_00348578[2];
s32 func_0015ce80(void);
void func_0015ceb8(Q16*);
void func_0015cea0(Q16*);
f32 func_0015ced0(void);
f32 func_0015cee0(void);
void func_0015ce90(void);  // zero_global_byte_g
void func_0014fcd8(u8*);
s32 func_00139d78(void*);
void func_00151c70(u8*);
void func_00138c40(u8*, u32, u32);
void func_001519f8(u8*);
void func_001904a8(void*, void*);
extern u8 D_0034aa70[];
void func_0015a260(u8*, void*, f32);
u32 func_00167f18(s32);
void func_0015a158(u32, u8*);
void func_0015a528(u8*);
void func_0014c738(u8*);
void func_0014c350(u8*);
u32 func_001b9bc8(u32);
s32 func_0016a040(u32);
void func_0016c568(u32, u32, f32);
u32 func_0014aba8(void);
void func_0014aa80(u32, s32, s32);
void func_001ada38(s32);
void func_00177710(void);
extern u8 D_0032bb30[];
u8 func_0016c008(u32, s32);
s32 func_0016a070(u32);
s32 func_0016a020(u32);
void func_00253180(s32, s32);
extern s8 D_01c60500;
extern V4 D_01c60510;
void func_0017bef8(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
s32 func_00180cd0(u8*);
s32 func_00196618(u32, u32, s32);
u32 func_001d52c0(u32, u32);
s32 func_00192048(u32);
void func_00226da8(u8*);
void func_0014c9f0(s32);
void func_001c11a8(s32);
void func_001384a0(s32);
void func_002bc798(void);
void func_002ba610(void);  // zero_global_byte_1e3
extern u32 D_0035037c;
u8* func_0016e920(u32);
void func_001a78c0(u8*, u32, s32, f32, f32, f32, f32);
void func_001a7888(u8*, u32, s32, f32, f32, f32, f32);
extern DeadRingW55 D_01c6cb00;
void func_001dc978(void*, f32);
void func_001c79a0(u32, u32, s32);
void func_001a52a8(u32, u32, u32);
s32 func_001d22a8(u32);
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
extern u8 D_00350af0[];
extern u8* D_01d48c80;
void func_001b2488(u8*);
void func_00105110(void*);
extern u32 D_01d49320;
void func_001bbe18(u32);
void func_001d5518(u8*, u8*, s32);
void func_001bb890(void);
s32 func_001bb7f8(void);
void func_001bc0d0(u8*);
void func_001bbc30(void);
u8* func_001a80c8(u32);  // table24_find_by_id
extern EntW55 D_0036dcf8[];
void* func_001050d8(u32);
void func_001bf270(void*, u8*, u32, u32, f32);
s32 func_001bc010(void);
u32 func_0017df58(s32);
s32 func_0019ba60(u32);
s32 func_0017e3b8(u32);
extern void* D_01d5ba10[];
s32 func_001d3558(void*, void*);
void* func_001d3498(void*, void*);
extern u32 D_01d9eaa0;
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
void func_0024ec50(void);
extern u8* D_0035ee04;
extern void* D_0035ee08;
extern void* D_0035ee10;
void func_0024eb50(void);
void func_0024f2d0(void);
void func_001039f8(void);
u32 func_00259460(u32, u8);
void func_002595b8(u32, u32, u8);
s32 func_00287bc0(void);
s32 func_00253578(void);  // get_global_36ee90
s32 func_002637e8(s32);
bool func_002577b0(void);
bool func_0027b528(void);
s32 func_0028be58(void*);
extern void* D_0035f04c;
extern u8* D_0035f01c;
void func_0029df98(void);
void func_0029e050(void);
void func_0029e258(s32);
extern u8* D_0035f610;
void func_001bc778(u8*);
s32 func_00190140(u8*);
u8* func_001bc780(u8*, s32, s32, s32);
void func_00178888(u8*);
u32 func_002d1260(void);
s32 func_002d5c40(u32);
void func_002d3fa8(Q16*, u32, u32);
u32 func_002e64b0(u32);
HeapW55* func_001050c8(void);
void func_002edf28(u8*);  // obj_ctor_3637e0
void func_001ad330(u8*, s32);
extern u8 D_00363828[];
u32 func_0010c7e8(u32);
void func_0011a900(Q16*, u32);
extern Q16 D_01e2c0c0;
s32 func_002ff1a4(const char*, const char*);  // strcmp
extern char D_00377cf8[];
extern char D_00377cc0[];
void func_003147a0(void*, FpW55*);
FpW55* func_00313c58(FpW55*, FpW55*, FpW55*);
double func_003146c8(FpW55*);
extern u8 D_0034a800[];
extern u8 D_00348608[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_002361d0(u8*);
void func_00239870(u8*);
}

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

// Clears bit 14 of the flags word unless the target kind is 32.
void wtarget_0010f918(u32 a, u32, u32, u32) {
    u8* p = (u8*)a;
    if (*(s32*)(*(u8**)(p + 12) + 4) == 32) {
        func_0016bd60(a, 31);
        return;
    }
    *(u32*)(p + 2940) &= ~0x4000;
}

extern "C" {

// Shifts packed nibbles up: whole 64-bit words, then the leftover bytes.
void func_0011f120(void* o, u8* p) {
    s32 n = (*(s32 (**)(void*))(*(u8**)o + 48))(o);
    s32 rem = n & 7;
    n >>= 3;
    u64 m = D_0036a938;
    s32 i;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) {
        *q = (*q & m) << 4;
        q++;
    }
    p = (u8*)q;
    for (i = 0; i < rem; i++) {
        *p = (*p & 0xf) << 4;
        p++;
    }
}

// Wraps an angle into [-pi, pi].
f32 func_00127de8(f32 a) {  // clampf
    if (a > 0.0f) {
        while (a > 3.1415927f) a -= 6.2831855f;
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}

// Walks the list from a (up to b) and returns the first node whose virtual test accepts.
void* func_00132390(void* a, void* b, u32 c, u32 d, u32 e) {
    for (; a && a != b; a = *(void**)((u8*)a + 28)) {
        if ((*(s32 (**)(void*, u32, u32, u32))(*(u8**)a + 12))(a, c, d, e)) return a;
    }
    return 0;
}

void func_0013d620(void) {
    func_00138698(D_00348050, func_0013a800());
    *(u32*)(D_003484a0 + 672) = 0;
    func_0013d4c8();
    u32 s = func_0013a810();
    u32 v = func_0013cb80();  // get_global_358050
    func_001387f8((u32)(D_003484a0 + 260), s, v + 32, D_00348578[0]);
    *(u32*)(D_003484a0 + 652) = D_00348578[1];
    func_0013b2d8(0.0f);
}

void func_001407d0(u8* p) {
    if (!func_0015ce80()) return;
    Q16 t;
    func_0015ceb8(&t);
    if ((Q16*)p != &t) copyQ(p, &t);
    u8* q = p + 16;
    func_0015cea0(&t);
    if ((Q16*)q != &t) copyQ(q, &t);
    *(f32*)(p + 32) = func_0015ced0();
    *(f32*)(p + 36) = func_0015cee0();
    func_0015ce90();  // zero_global_byte_g
}

void func_00151aa8(u8* p) {
    func_0014fcd8(p);
    if (*(s32*)(p + 2896) == 1) {
        if (!func_00139d78(p + 840)) {
            func_00151c70(p);
        }
        return;
    }
    func_00138c40(p + 840, *(u32*)(p + 32), *(u32*)(p + 36));
    f32 f = **(f32**)(p + 2884);
    *(f32*)(p + 2888) = f;
    if (*(f32*)(p + 2892) != f) func_001519f8(p);
    *(f32*)(p + 2892) = *(f32*)(p + 2888);
}

void func_0015a5a8(u8* p) {
    u8 buf[16];
    func_001904a8(buf, D_0034aa70);
    func_0015a260(p, buf, 0.3f);
    u32 s = func_00167f18(0);
    void* o = *(void**)(p + 68);
    if ((*(s32 (**)(void*))(*(u8**)o + 64))(o)) func_0015a158(s, p);
    func_0015a528(p);
}

static inline void vcall8(u8* o) { (*(void (**)(void*))(*(u8**)o + 8))(o); }

void func_0015d828(u8* p) {
    func_0014c738(p + 16);
    vcall8(p + 544);
    u8* q = p;
    s32 i;
    for (i = 0; i < 6; i++) {
        vcall8(q + 2608);
        vcall8(q + 1072);
        q += 256;
    }
    func_0014c350(p + 4144);
}

}

void wtarget_0016c5b8(u32 a, u32 b, u32, u32) {
    u32 i = 0;
    while ((i = func_001b9bc8(i)) != 0) {
        if ((1 << func_0016a040(i)) & b) func_0016c568(i, a, 0.0f);
    }
}

extern "C" {

void func_0016df70(f32* p) {
    s32 n = (s32)(*p * 0.5f);
    func_0014aa80(func_0014aba8(), n, 1);
}

void func_00179648(u32 a, u32 b) {
    func_001ada38(7);
    func_00177710();
    u8* s = D_0032bb30;
    s[14] = func_0016c008(b, 1);
    if (func_0016a070(a) == 14) *(u32*)(s + 9372) |= 1;
    else *(u32*)(s + 9372) &= ~1;
    func_00253180(1, func_0016a020(b) == 0x239 ? 0 : 2);
}

}

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

extern "C" {

s32 func_001967f0(u32 a, u32 b, s32 c) {
    s32 i = func_00196618(a, b, c);
    if (i < 0) return 0;
    u32 v = ((S1967*)D_0032bb30)->t[i * 2 + c];
    if (!v) v = func_001d52c0(a, b);
    return func_00192048(v);
}

void func_00196d78(u8* p) {
    func_00226da8(p);
    func_0014c9f0(4);
    func_001c11a8(12);
    func_001384a0(1);
    if ((u8)((*(u16*)(*(u8**)(p + 60) + 2) >> 5) & 1) == 0) func_002bc798();
    u32 v = *(u16*)(*(u8**)(p + 60) + 2);
    if ((u8)(v & 1)) func_002ba610();  // zero_global_byte_1e3
    D_0035037c = 0;
}

u8* func_0019b0e8(u8* a, u32 b, u32 c, f32 f, f32 g) {
    u8* o = func_0016e920(b);
    if ((u8)((*(u16*)(o + 72) >> 3) & 1)) func_001a78c0(a, c, 2, 0.0f, f, -g, g);
    else func_001a7888(a, c, 1, 0.0f, f, -g, g);
    return a;
}

}

// Keeps the last four dead effects; the oldest is released when replaced.
void AddDeadEffect(void* e) {
    if (!e) return;
    DeadRingW55* r = &D_01c6cb00;
    void* old = r->e[r->idx];
    if (old) func_001dc978(old, 4.0f);
    r->e[r->idx] = e;
    r->idx = (r->idx + 1) % 4;
}

extern "C" {

void func_001a53d0(u32 a, u32 b, u32 c) {
    func_001c79a0(c, b, 1);
    func_001a52a8(a, b, c);
}

s32 func_001a8190(u8* p) {
    switch (p[2]) {
    case 2 ... 13: return func_001d22a8(*(u16*)(p + 6));
    case 14 ... 15: return func_001d22a8(*(u16*)(p + 4));
    }
    return 0;
}

void func_001ad228(u8* p, u32 b) {
    func_001ac970(p, 3, 4, b, 0, 256, 32, 3);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 100) = 2;
    *(u32*)p = (u32)D_00350af0;
}

// Destroys and frees every node of the list.
void func_001b24c8(void) {
    u8* n = D_01d48c80;
    while (n) {
        u8* next = *(u8**)(n + 24);
        if (n) {
            func_001b2488(n);
            func_00105110(n);
        }
        n = next;
    }
}

}

#define MISSION_W55 ((u8*)D_01d49320)
void MissionFailed(void) {
    func_001bbe18(*(u32*)(*(u8**)(MISSION_W55 + 8) + 24));
    *(u32*)(MISSION_W55 + 180) = 2;
    func_001d5518(MISSION_W55 + 160, MISSION_W55 + 12, 0);
    func_001bb890();
    if (func_001bb7f8()) {
        *(u32*)(MISSION_W55 + 732) = 8;
        *(s32*)(MISSION_W55 + 736) = -1;
        func_001bc0d0(MISSION_W55);
        return;
    }
    func_001bbc30();
}

extern "C" {

void* func_001bf620(u32 a, u32 b) {
    EntW55* e = &D_0036dcf8[func_001a80c8(a)[22]];
    void* m = func_001050d8(2544);
    func_001bf270(m, func_0016e920(e->id), b, a, e->f);
    return m;
}

s32 func_001c9ab8(void) {
    if (func_001bc010()) return 1;
    s32 i;
    for (i = 0; i < 2; i++) {
        u32 o = func_0017df58(i);
        if (!func_0019ba60(o)) return 0;
        if (!func_0017e3b8(o)) return 0;
    }
    return 1;
}

void func_001d2690(RingW55* r, u32 b, f32 f) {
    s32 i = r->idx;
    r->idx = (i + 1) % 3;
    RingEW55* e = &r->e[i];
    e->v = func_00192048(b);
    e->f = f * 60.0f;
}

// 001d34d0: moved to src/anon/unit_001d30b0.cpp

void func_001e9078(u8* a, u8* b, u8* c) {
    *(u32*)(a + **(s32**)(c + 12) + 160) = *(u32*)(b + 4);
    CbW55* t = (CbW55*)D_01d9eaa0;
    if (!t) return;
    CbW55 f = t[(*(u8**)(a + 8))[14]];
    if (f) f(a, *(u32*)(b + 4));
}

// Sum of two VU0 randoms, or twice one.
f32 func_001eeb90(u8 a) {
    f32 r = vu0Rand();
    if (a) return r + vu0Rand();
    return r + r;
}

s32 func_0024ebc0(void) {
    func_00287d68();  // copy_globals_3words
    if (func_00287db0()) {
        if (!Select_isCreated(D_0035ee04) && !func_00139d78(D_0035ee08) && !func_00139d78(D_0035ee10)) {
            func_0024eb50();
            func_0024f2d0();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    func_0024ec50();
    return 0;
}

void func_00259570(u32 a, u32 b, u8 c, u8 d) {
    func_002595b8(func_00259460(a, c), b, d);
}

s32 func_0025d620(s32 a) {
    s32 r = 1;
    switch (func_00287bc0()) {
    case 0:
        if (a && func_00253578()) r = 0;
        break;
    case 1:
    case 12:
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

s32 func_002638e0(s32 a) {
    s32 r = 0;
    switch (func_00287bc0()) {
    case 10: r = 1; break;
    case 1: r = 1; break;
    case 11: if (a >= 0) r = func_002637e8(a) >= 0; break;
    default: r = 1; break;
    }
    return r;
}

bool func_0027a908(u8 a) {
    bool r = func_002577b0();
    if (r) return r;
    if (a) r = func_0027b528();
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    if (r) return r;
    if (D_0035f01c) r = Select_isCreated(D_0035f01c) != 0;
    return r;
}

}

s32 Select_isCreated(u8* s) {
    s32 i;
    for (i = 0; i < *(s16*)(s + 4); i++) {
        void* o = (*(void***)(s + 40))[i];
        if (o && func_00139d78(o)) return 1;
    }
    return 0;
}

extern "C" {

void func_0029aa30(void) {
    NoTail keep_frame; // forces jal instead of a sibling call
    s32 m = func_00287bc0();
    if ((u32)(m - 14) < 2 || m == 18 || m == 21 || m == 16 || m == 19 || m == 22 || m == 17 || m == 20 || m == 23) {
        func_0029df98();
        func_0029e050();
        func_0029e258(0);
        func_0029e258(1);
    }
}

// Tests flag n, or whether any of the 96 flags is set when n is negative.
s32 func_002ab100(s32 n) {  // test_bit_global_c
    if (n < 0) {
        u32* bits = (u32*)(D_0035f610 + 136);
        s32 r;
        s32 i = 0;
        do {
            r = (bits[(u32)i >> 5] & (1 << (i & 31))) != 0;
            i++;
            if (r) break;
        } while (i < 96);
        return r;
    }
    u8* b = D_0035f610;
    u32 o = ((u32)n >> 5) * 4;
    b += o;
    return (*(u32*)(b + 136) & (1 << (n & 31))) != 0;
}

void func_002c5900(u8* p) {
    u8* s = *(u8**)(p + 2884) + 1196;
    func_001bc778(s);
    u8* r;
    if (func_00190140(*(u8**)(p + 2880) + 4)) r = func_001bc780(s, 582, 0, 1);
    else r = func_001bc780(s, 583, 0, 1);
    r[6] = 4;
    func_00178888(p);
}

Q16* func_002d2870(Q16* out, u8* b, u32 c) {
    f32* v = (f32*)out;
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    if (func_002d5c40(func_002d1260()) == 2) {
        Q16 t;
        func_002d3fa8(&t, *(u32*)(b + 324), c);
        if (out != &t) copyQ(out, &t);
    }
    return out;
}

}

// Looks up the value stored for the key pair (b, c) in the section of kind d.
s32 wtarget_002e3418(u32 a, u32 b, u32 c, u32 d) {
    u8* h = (u8*)a;
    s32 n = *(s32*)(h + 8);
    if (!n) return -1;
    SecW55* e = (SecW55*)(h + 16);
    s32 i;
    for (i = 0; i < n; i++) {
        if (e->type == d) {
            s32 j;
            for (j = 0; j < e->cnt; j++) {
                PairW55* pr = &e->p[j];
                if (pr->a == b && pr->b == c) return pr->v;
            }
        }
        e = (SecW55*)&e->p[e->cnt];
    }
    return -1;
}

extern "C" {

void func_002e6fc0(u32* p, u32 b) {
    p[0] = b;
    p[1] = 0;
    u32 n = func_002e64b0(b);
    p[2] = n;
    p[1] = (u32) new (func_001050c8()) ElemW55[n];
}

}

// 002ee5d8: moved to src/menu/tutorial_widget.cpp

extern "C" {

void func_002f07f8(u32* p) {
    Q16 t;
    func_0011a900(&t, func_0010c7e8(*(u32*)(p[0] + 4)));
    if (&D_01e2c0c0 != &t) copyQ(&D_01e2c0c0, &t);
    p[0] = (u32)&D_01e2c0c0;
}

// ORs fn() over every active item of every block in the chain.
u32 func_00303698(u8* p, u32 (*fn)(ItemW55*)) {
    u32 r = 0;
    BlkW55* b;
    for (b = (BlkW55*)(p + 472); b; b = b->next) {
        s32 i = b->count;
        ItemW55* it = b->items;
        while (--i >= 0) {
            if (it->on) r |= fn(it);
            it++;
        }
    }
    return r;
}

}

const char* wtarget_00303728(u32 a, u32 b, u32 c, u32) {
    const char* s = (const char*)c;
    if (s) {
        if (func_002ff1a4(s, D_00377cf8) && func_002ff1a4(s, D_00377cc0)) return 0;
        *(u32*)(a + 48) = b;
        *(u32*)(a + 52) = c;
    }
    return D_00377cf8;
}

extern "C" {

// Soft-float binary op: unpack both doubles, combine, pack.
double func_00313e80(double a, double b) {  // double_div
    FpW55 x, y, t;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_00313c58(&x, &y, &t));
}

void func_0031b5c8(u8* p) {
    *(u32*)p = (u32)D_00348608;
    *(u32*)(p + 64) = (u32)D_0034a800;
    func_002361d0(p + 480);
    *(u32*)(p + 64) = (u32)D_00347e60;
    func_00239870(p + 88);
    *(u32*)(p + 64) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* o = *(u8**)(D_00347f80 + 20);
    (*(void (**)(void*, u8*))(*(u8**)o + 4))(o, p);
}

}
