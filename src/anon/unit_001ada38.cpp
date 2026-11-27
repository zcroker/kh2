// Linked unit 0x1ada38-0x1b0448 (YS game-over flow, voice loading, gumi/IDX helpers, static init + I stub).
// Gap functions written here: 0x1aec50 (C2 copy of 0x1aedf8), 0x1af190 (D2 copy of 0x1af210), 0x1af398,
// 0x1af638, 0x1af6f0, 0x1afdd0, 0x1b0390. .rodata 0x36d7a8-0x36d960 including strings read through .data tables.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001ada38 from src/anon/batch_wcx2.cpp
namespace n001ada38 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
extern u64 D_0032f050 asm("D_0032f050");
extern u8 D_0032bb30[] asm("D_0032bb30");
extern u32 D_0034f240 asm("D_0034f240");
void func_001c9770() asm("func_001c9770");
void func_001adbc0() asm("func_001adbc0");
s32 func_001a1658_x8414(s32, s32) asm("func_001a1658");
void func_001adb80(s32, s32) asm("func_001adb80");
void func_001a17c8_x8416(s32) asm("YS__SHEET__Free");
void YS__RECOV__Exec(s32 n) asm("YS__RECOV__Exec");
void YS__RECOV__Exec(s32 n) {
    s32 i;
    if (n == 0) return;
    switch (n) {
    case 1:
        if (!(D_0032f050 & 0xffff00000000ULL)) break;
    case 2: case 12:
        func_001c9770();
    case 10:
        func_001adbc0();
        break;
    case 5:
        D_0034f240 |= 0x40000;
    case 4:
        if (!(D_0032f050 & 0xffff00000000ULL)) return;
    case 6:
        func_001c9770();
        func_001adbc0();
        return;
    case 11:
        if (D_0032bb30[13604] == 6) {
            D_0032bb30[13604] = 0;
            func_001c9770();
        }
        return;
    }
    for (i = 1; i < 16; i++) {
        s32 o = func_001a1658_x8414(i, -1);
        func_001adb80(n, o);
        func_001a17c8_x8416(o);
    }
}
}  // namespace n001ada38

// ---- 001adb80 from src/anon/batch_w8002_nsa.cpp
namespace n001adb80 {
struct S1adb80 { s32 a; s32 b; };
u8 ys_max_mp_1adb80(void*, bool) asm("_ZN2YS5SHEET6max_mpEb");
u8 func_001a1910_u8(void*, s32, s32) asm("func_001a1910");
u8 func_001adb80(void* a0, S1adb80* a1) asm("func_001adb80");
u8 func_001adb80(void* a0, S1adb80* a1) {
    ys_max_mp_1adb80(a1, 0);
    s32 b = a1->b;
    return func_001a1910_u8(a1, b, 0);
}
}  // namespace n001adb80

// ---- 001adbc0 from src/anon/batch_w33.cpp
namespace n001adbc0 {
struct St32 { u8 pad[13604]; u8 a; u8 b; };
extern St32 D_0032bb30 asm("D_0032bb30");
void* func_001a15d0(s32, s32) asm("func_001a15d0");
void YS__SHEET__max_drive(void*) asm("YS__SHEET__max_drive");
void YS__SHEET__Free(void*) asm("YS__SHEET__Free");
void func_001adbc0(void) asm("func_001adbc0");
void func_001adbc0(void) {
    D_0032bb30.a = 0;
    D_0032bb30.b = 0;
    void* v = func_001a15d0(1, -1);
    YS__SHEET__max_drive(v);
    YS__SHEET__Free(v);
}
}  // namespace n001adbc0

// ---- 001adc08 from src/anon/tiny_auto80_queue.cpp
namespace n001adc08 {
void func_001adc08(u32* a0, u32* a1, u32* a2) asm("_Z13func_001adc08PjS_S_");
void func_001adc08(u32* a0, u32* a1, u32* a2) {
    (void)a1;
    s32 i = 0;
    if ((s32)a0[0] <= 0) {
        return;
    }
    u8* p = (u8*)a0;
    do {
        *(u32*)(p + 12) = *(u32*)(p + 12) + a2[0];
        i += 1;
        p += 16;
    } while (i < (s32)a0[0]);
}
}  // namespace n001adc08

// ---- 001adc48 from src/anon/batch_w1786_nsa.cpp
namespace n001adc48 {
struct W1786Q4 { u8 pad[8]; s32 x; };
struct W1786S350 { void (*fn)(s32, u32, s32); W1786Q4* p; s32 a; u32 b; s32 c; };
void FlushCache(s32) asm("FlushCache");
s32 func_002f7dc8() asm("func_002f7dc8");
extern W1786S350 D_00350cb0 asm("D_00350cb0");
void func_001adc48(s32 x) asm("func_001adc48");
void func_001adc48(s32 x) {
    if (x == 1 && D_00350cb0.fn) {
        FlushCache(0);
        if (func_002f7dc8()) {
            D_00350cb0.c = -1;
            D_00350cb0.fn(D_00350cb0.a, D_00350cb0.b, -1);
            D_00350cb0.fn = 0;
        } else {
            D_00350cb0.c = 0;
            D_00350cb0.fn(D_00350cb0.a, D_00350cb0.b, 0);
            D_00350cb0.fn = 0;
            D_00350cb0.p->x += (D_00350cb0.b + 0x7ff) >> 11;
        }
    }
}
}  // namespace n001adc48

// ---- .rodata 0x36d7e0-0x36d858: strings of this file (some read only through .data tables)
extern const char R_0036d7e0[16] asm("D_0036d7e0") = "\\KH2.IDX;1";
extern const char R_0036d7f0[16] asm("D_0036d7f0") = "\\KH2.IMG;1";
extern const char R_0036d800[16] asm("D_0036d800") = "\\OVL.IDX;1";
extern const char R_0036d810[16] asm("D_0036d810") = "\\OVL.IMG;1";
extern const char R_0036d820[16] asm("D_0036d820") = "000%s.idx";
extern const char R_0036d830[16] asm("D_0036d830") = "000gumi.idx";
extern const char R_0036d840[8] asm("D_0036d840") = "vas";
extern const char R_0036d848[8] asm("D_0036d848") = "pss";
extern const char* const R_0036d850[2] asm("D_0036d850") = { R_0036d840, R_0036d848 };

// ---- 001adcf8 from src/anon/batch_w8002_g.cpp
namespace n001adcf8 {
struct Info1ad { s32 a; s32 size; };
struct Ent1ad { s32 v; u8 pad[40]; };
void func_001adc48() asm("func_001adc48");
void func_001adc08(void*, s32, void*) asm("func_001adc08");
s32 func_00105ee8(s32) asm("func_00105ee8");
void YS__FILE__ReadBack(void*, u32, void (*)(void*, s32, void*), void*) asm("YS__FILE__ReadBack");
void func_001ae4c0(s32, u32, void*) asm("func_001ae4c0");
void func_001ae590(Info1ad*, s32) asm("func_001ae590");
void func_002f6698(void (*)()) asm("func_002f6698");
void func_002fee78(char*, const char*, s32) asm("func_002fee78");
extern s32 D_00350c8c asm("D_00350c8c");
extern s32 D_00350c90 asm("D_00350c90");
extern s32 D_00350c94 asm("D_00350c94");
extern s32 D_00350c98 asm("D_00350c98");
extern char D_0036d820[] asm("D_0036d820");
extern Ent1ad D_01c6cf00[4] asm("D_01c6cf00");
extern s32* D_01c6cfb0 asm("D_01c6cfb0");
extern s32* D_01c6cfb4 asm("D_01c6cfb4");
extern u32 D_01c6cfb8 asm("D_01c6cfb8");
extern s32 D_01c6cfc0[] asm("D_01c6cfc0");
extern u8 D_01c94000[] asm("D_01c94000");
void func_001adcf8(s32 arg0) asm("func_001adcf8");
void func_001adcf8(s32 arg0) {
    union { Info1ad info; char buf[48]; } u;
    if (arg0 == -1) {
        s32 sz;
        u32 n;
        func_002f6698(func_001adc48);
        func_001ae590(&u.info, D_00350c94);
        D_01c6cfb0 = D_01c6cfc0;
        n = (u32)(u.info.size + 0x7ff) >> 11;
        func_001ae4c0(u.info.a, n, D_01c6cfb0);
        sz = u.info.size;
        func_001ae590(&u.info, D_00350c98);
        func_001adc08(D_01c6cfb0, sz, &u.info);
        D_01c6cfb4 = (s32*)(((u32)D_01c6cfb0 + *D_01c6cfb0 * 16 + 0x43) & ~0x3f);
        func_001ae590(&u.info, D_00350c8c);
        n = (u32)(u.info.size + 0x7ff) >> 11;
        func_001ae4c0(u.info.a, n, D_01c6cfb4);
        sz = u.info.size;
        func_001ae590((Info1ad*)D_01c94000, D_00350c90);
        func_001adc08(D_01c6cfb4, sz, D_01c94000);
        for (s32 i = 0; i < 4; i++) D_01c6cf00[i].v = 0;
        D_01c6cfb8 = 0;
    } else {
        func_002fee78(u.buf, D_0036d820, func_00105ee8(arg0));
        D_01c6cfb8 = ((u32)D_01c6cfb4 + *D_01c6cfb4 * 16 + 0x43) & ~0x3f;
        YS__FILE__ReadBack(u.buf, D_01c6cfb8, func_001adc08, D_01c94000);
    }
}
}  // namespace n001adcf8

// ---- 001adea8 from src/anon/auto80_199_queue.cpp
namespace n001adea8 {
void func_001adea8() asm("_Z13func_001adea8v");
void func_001adea8() {
    u32* p = *(u32**)((u8*)D_01c70000 - 12364);
    u32 n = p[0];
    u32 v = ((u32)p + (n << 4) + 67) & (u32)-64;
    *(u32*)((u8*)D_01c70000 - 12360) = v;
    return YS__FILE__ReadBack((u32)D_0036d830, v, (u32)D_001adc08, (u32)D_01c94000);
}
}  // namespace n001adea8

// ---- 001adf00 from src/anon/batch_w100.cpp
namespace n001adf00 {
struct Ent17 { u32 f0; union { u32 flags; struct { u16 lo; u16 h6; }; }; u32 id; u32 dst; };
extern u8 D_00350ca0[] asm("D_00350ca0");
extern u32 D_00350c88 asm("D_00350c88");
Ent17* func_001ae460(u32) asm("func_001ae460");
s32 func_002f79c8(s32) asm("func_002f79c8");
s32 func_002f7be8(u32, s32, u32, u8*) asm("func_002f7be8");
void func_001ae620(void) asm("func_001ae620");
void func_001ae650(void) asm("func_001ae650");
void func_001ae678(void) asm("func_001ae678");
u32 func_002f7dc8(void) asm("func_002f7dc8");
void func_003058a0(s32) asm("func_003058a0");
void func_002efcc0(u32, u32, s32) asm("func_002efcc0");
u32 func_001adf00(u32 key, u32 buf) asm("func_001adf00");
u32 func_001adf00(u32 key, u32 buf) {
    Ent17* e = func_001ae460(key);
    if (!e) return 0;
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(e->id, (e->h6 & 0x3fff) + 1, buf, D_00350ca0) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        if (!(D_00350c88 = func_002f7dc8())) break;
        func_001ae650();
    }
    if (e->flags & 0x40000000) {
        func_003058a0(0);
        func_002efcc0(buf, e->dst, ((e->h6 & 0x3fff) << 11) + 2048);
    }
    return e->dst;
}
}  // namespace n001adf00

// ---- 001ae010 from src/anon/batch_w56.cpp
namespace n001ae010 {
struct P1ae { const char* a[2]; };
extern P1ae D_0036d850 asm("D_0036d850");
char* func_002ff8b0(const char*, s32) asm("func_002ff8b0");
s32 strcmp(const char*, const char*) asm("strcmp");
s32 func_001ae010(const char* s) asm("func_001ae010");
s32 func_001ae010(const char* s)
{
    P1ae t = D_0036d850;
    char* e = func_002ff8b0(s, '.');
    if (e) {
        e++;
        for (s32 i = 0; i < 2; i++)
            if (strcmp(e, t.a[i]) == 0) return 1;
    }
    return 0;
}
}  // namespace n001ae010

// ---- 001ae0a0 from src/anon/batch_wcx2.cpp
namespace n001ae0a0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
extern u8 D_00350ca8[] asm("D_00350ca8");
extern u8 D_00350ca0[] asm("D_00350ca0");
extern s32 D_00350c88 asm("D_00350c88");
u8* func_001ae460(u32) asm("func_001ae460");
s32 func_001ae010(u32) asm("func_001ae010");
s32 func_002f79c8(s32) asm("func_002f79c8");
s32 func_002f7be8(u32, u32, u32, u8*) asm("func_002f7be8");
void func_001ae620(void) asm("func_001ae620");
void func_001ae650(void) asm("func_001ae650");
void func_001ae678(void) asm("func_001ae678");
s32 func_002f7dc8(void) asm("func_002f7dc8");
u32 func_001ae0a0(u32 a0, u32 a1, u32 a2, u16 a3) asm("func_001ae0a0");
u32 func_001ae0a0(u32 a0, u32 a1, u32 a2, u16 a3)
{
    u8* h = func_001ae460(a0);
    if (!h) return 0;
    u8* tbl = func_001ae010(a0) ? D_00350ca8 : D_00350ca0;
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*(u32*)(h + 8) + a2, a3, a1, tbl) != 1) {
            func_001ae678();
        } else {
            func_001ae620();
            if ((D_00350c88 = func_002f7dc8()) == 0) return a3 << 11;
            func_001ae650();
        }
    }
}
}  // namespace n001ae0a0

// ---- 001ae1b0 from src/anon/tiny_auto80_queue.cpp
namespace n001ae1b0 {
u32 func_001ae460(...) asm("func_001ae460");
u32 func_001ae1b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001ae1b0jjjjjjjj");
u32 func_001ae1b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001ae460)();
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(12));
    }
    r2 = r15;
    return r2;
}
}  // namespace n001ae1b0

// ---- 001ae1e0 from src/anon/tiny_auto80_queue.cpp
namespace n001ae1e0 {
u32 func_001ae460(...) asm("func_001ae460");
u32 func_001ae1e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001ae1e0jjjjjjjj");
u32 func_001ae1e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001ae460)();
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace n001ae1e0

// ---- 001ae210 from src/anon/batch_w37.cpp
namespace n001ae210 {
u32 func_001ae210(const s8* s) asm("func_001ae210");
u32 func_001ae210(const s8* s) {
    u32 c = 0xffffffff;
    s32 ch;
    while ((ch = *s++) != 0) {
        c ^= ch << 24;
        for (s32 i = 7; i >= 0; i--) {
            if (c & 0x80000000) c = (c << 1) ^ 0x04c11db7;
            else c <<= 1;
        }
    }
    return ~c;
}
}  // namespace n001ae210

// ---- 001ae270 from src/anon/batch_w58.cpp
namespace n001ae270 {
u32 strlen(const char*) asm("strlen");
u16 func_001ae270(const char* s) asm("func_001ae270");
u16 func_001ae270(const char* s) {
    u16 crc = 0xffff;
    u32 n = strlen(s);
    const s8* p = (const s8*)s + n - 1;
    for (u32 i = 0; i < n; i++) {
        crc ^= *p-- << 8;
        for (s32 j = 7; j >= 0; j--) {
            if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
            else crc = crc << 1;
        }
    }
    crc = ~crc;
    return crc;
}
}  // namespace n001ae270

// ---- 001ae308 from src/anon/batch_wcx2.cpp
namespace n001ae308 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct VB36 {
    f32 x, y, z, w;
    VB36& operator=(const VB36& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB36 operator-(const Vec4& b) const
    {
        VB36 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Ent13 { u32 key; union { s32 v; u16 sub; }; u32 a, b; };
struct Tbl13 { s32 n; Ent13 e[1]; };
u32 func_001ae210(u32) asm("func_001ae210");
u16 func_001ae270(u32) asm("func_001ae270");
Ent13* func_001ae308(Tbl13* t, u32 name) asm("func_001ae308");
Ent13* func_001ae308(Tbl13* t, u32 name)
{
    if (!t) return 0;
    u32 key = func_001ae210(name);
    s32 n = t->n;
    if (n <= 0) return 0;
    s32 lo = 0, hi = n - 1;
    Ent13* e;
    do {
        s32 mid = (lo + hi) / 2;
        e = &t->e[mid];
        if (e->key == key) break;
        if (e->key < key) lo = mid + 1;
        else hi = mid - 1;
    } while (hi - lo >= 0);
    if (e->key != key) e = 0;
    if (!e || e->v >= 0) return e;
    u16 sub = func_001ae270(name);
    if (e != &t->e[0]) {
        while (e[-1].key == key) e--;
    }
    while (e->key == key && e->sub != sub) e++;
    if (e->key != key || e->sub != sub) e = 0;
    return e;
}
}  // namespace n001ae308

// ---- 001ae460 from src/anon/auto80_199_queue.cpp
namespace n001ae460 {
u32 func_001ae460(u32 a0) asm("_Z13func_001ae460j");
u32 func_001ae460(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12368), s0);
    if (v0 == 0) {
        v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12364), s0);
        if (v0 == 0) {
            v0 = func_001ae308(*(u32*)((u8*)D_01c70000 - 12360), s0);
        }
    }
    return v0;
}
}  // namespace n001ae460

// ---- 001ae4b8 from src/anon/batch_w1664.cpp
namespace n001ae4b8 {
void func_001ae4b8(void) asm("func_001ae4b8");
void func_001ae4b8(void) {}
}  // namespace n001ae4b8

// ---- 001ae4c0 from src/anon/batch_w79.cpp
namespace n001ae4c0 {
void func_001ae4c0(u32, u32, void*) asm("func_001ae4c0");
s32 func_002f79c8(s32) asm("func_002f79c8");
s32 func_002f7be8(u32, u32, void*, void*) asm("func_002f7be8");
void func_001ae678(void) asm("func_001ae678");
void func_001ae620(void) asm("func_001ae620");
s32 func_002f7dc8(void) asm("func_002f7dc8");
void func_001ae650(void) asm("func_001ae650");
extern u8 D_00350ca0[] asm("D_00350ca0");
extern s32 D_00350c88 asm("D_00350c88");
void func_001ae4c0(u32 a, u32 b, void* c) asm("func_001ae4c0");
void func_001ae4c0(u32 a, u32 b, void* c) {
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(a, b, c, D_00350ca0) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        if ((D_00350c88 = func_002f7dc8()) == 0) break;
        func_001ae650();
    }
}
}  // namespace n001ae4c0

// ---- 001ae590 from src/anon/auto80_199_queue.cpp
namespace n001ae590 {
void func_001ae590(u32 a0, u32 a1) asm("_Z13func_001ae590jj");
void func_001ae590(u32 a0, u32 a1) {
    u32 s0 = a1;
    u32 s1 = a0;
    const u32 s2 = 2;
    const u32 s3 = 1;

    while (1) {
        if (func_002f79c8(1) == s2) {
            if (func_002f6fa0(s1, s0) == s3) {
                return;
            }
            *(u32*)(D_00350000 + 3208) = func_002f7dc8();
        }
        func_001ae690();
    }
}
}  // namespace n001ae590

// ---- 001ae620 from src/anon/batch_w21.cpp
namespace n001ae620 {
s32 func_002f71b0(s32) asm("func_002f71b0");
void func_001ae678(void) asm("func_001ae678");
void func_001ae620(void) asm("func_001ae620");
void func_001ae620(void) {
    while (func_002f71b0(1)) func_001ae678();
}
}  // namespace n001ae620

// ---- 001ae650 from src/anon/batch_w7.cpp
namespace n001ae650 {
void func_002f7e60(void) asm("func_002f7e60");
void func_002f71b0(u32) asm("func_002f71b0");
void func_002f79c8(u32) asm("func_002f79c8");
void func_001ae650(void) asm("func_001ae650");
void func_001ae650(void) {
    func_002f7e60();
    func_002f71b0(0);
    func_002f79c8(0);
}
}  // namespace n001ae650

// ---- 001ae678 from src/anon/tiny.cpp
namespace n001ae678 {
void func_00306698(s32) asm("_Z13func_00306698i");
void func_001ae678(BD_VALUE* bd) asm("_Z13func_001ae678P8BD_VALUE");
void func_001ae678(BD_VALUE* bd) { func_00306698(10); }
}  // namespace n001ae678

// ---- 001ae690 from src/anon/tiny.cpp
namespace n001ae690 {
void sceGsSyncV(s32) asm("_Z10sceGsSyncVi");
void func_001ae690(BD_VALUE* bd) asm("_Z13func_001ae690P8BD_VALUE");
void func_001ae690(BD_VALUE* bd) { sceGsSyncV(0); }
}  // namespace n001ae690

// ---- 001ae6a8 from src/anon/batch_w1805_nsa.cpp
namespace n001ae6a8 {
namespace w1805_a {
struct B;
struct A { s32 x; s32 y; B* b; s32 z; };
struct B { A* a; s32 p; s32 q; s32 r; u8 pad[28]; };
struct R { u8 pad[8]; s32 m8; s32 m12; };
}
extern w1805_a::A D_0034d800[] asm("D_0034d800");
extern w1805_a::B D_01c6cf00[] asm("D_01c6cf00");
w1805_a::R* func_001ae460() asm("func_001ae460");
w1805_a::A* func_001ae6a8() asm("func_001ae6a8");
w1805_a::A* func_001ae6a8() {
    using namespace w1805_a;
    int i;
    for (i = 0; i < 4; i++) if (!D_0034d800[i].b) break;
    int j;
    for (j = 0; j < 4; j++) if (!D_01c6cf00[j].a) break;
    R* r = func_001ae460();
    A* a = &D_0034d800[i];
    B* b = &D_01c6cf00[j];
    a->x = 0;
    a->y = b->r = r->m12;
    a->b = b;
    a->z = 0;
    b->a = a;
    b->p = b->q = r->m8;
    return a;
}
}  // namespace n001ae6a8

// ---- 001ae788 from src/anon/batch_w1670.cpp
namespace n001ae788 {
struct E2c_1c6cf00 { s32 a; u8 pad[0x28]; };
extern E2c_1c6cf00 D_01c6cf00[4] asm("D_01c6cf00");
void func_001ae788(u8* p) asm("func_001ae788");
void func_001ae788(u8* p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_01c6cf00[i].a == (s32)p) break;
    }
    D_01c6cf00[i].a = 0;
    *(u32*)(p + 8) = 0;
}
}  // namespace n001ae788

// ---- 001ae7d0 from src/anon/batch_w92.cpp
namespace n001ae7d0 {
inline void* operator new(unsigned int, void* p) { return p; }
struct S1ae { u32 pos; u32 f4; u8* f8; };
s32 func_002f79c8(s32) asm("func_002f79c8");
s32 func_002f7be8(u32, u32, u8*, void*) asm("func_002f7be8");
void func_001ae678(void) asm("func_001ae678");
void func_001ae620(void) asm("func_001ae620");
s32 func_002f7dc8(void) asm("func_002f7dc8");
void func_001ae650(void) asm("func_001ae650");
extern u8 D_00350ca8 asm("D_00350ca8");
extern s32 D_00350c88 asm("D_00350c88");
u32 func_001ae7d0(S1ae* s, u8* buf, u32 size) asm("func_001ae7d0");
u32 func_001ae7d0(S1ae* s, u8* buf, u32 size) {
    u32 n = (size + 2047) >> 11;
    u32* sec = (u32*)(s->f8 + 8);
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*sec, n, buf, &D_00350ca8) != 1) {
            func_001ae678();
            continue;
        }
        func_001ae620();
        D_00350c88 = func_002f7dc8();
        if (!D_00350c88) break;
        func_001ae650();
    }
    s->pos += n << 11;
    *sec += n;
    return size;
}
}  // namespace n001ae7d0

// ---- 001ae8d8 from src/anon/batch_wcx.cpp
namespace n001ae8d8 {
struct Rd { u32 a; u32 obj; u32 buf; u32 size; u32 e; };
extern Rd D_00350cb0 asm("D_00350cb0");
extern u8 D_00350ca8[] asm("D_00350ca8");
s32 func_002f79c8(s32) asm("func_002f79c8");
s32 func_002f7be8(u32, u32, u32, u8*) asm("func_002f7be8");
void func_001ae678(void) asm("func_001ae678");
void func_001ae8d8(u8* p, u32 buf, u32 size, u32 a, u32 e) asm("func_001ae8d8");
void func_001ae8d8(u8* p, u32 buf, u32 size, u32 a, u32 e)
{
    u32* f = (u32*)(*(u32*)(p + 8) + 8);
    D_00350cb0.a = a;
    D_00350cb0.obj = *(u32*)(p + 8);
    D_00350cb0.size = size;
    D_00350cb0.buf = buf;
    D_00350cb0.e = e;
    u32 n = (size + 2047) >> 11;
    for (;;) {
        if (func_002f79c8(1) == 2 && func_002f7be8(*f, n, buf, D_00350ca8) == 1) break;
        func_001ae678();
    }
}
}  // namespace n001ae8d8

// ---- 001ae990 from src/anon/tiny.cpp
namespace n001ae990 {
u32 func_001ae990(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ae990jjjj");
u32 func_001ae990(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (3208)));
}
}  // namespace n001ae990

// ---- 001ae9a0 from src/anon/batch_w218.cpp
namespace n001ae9a0 {
union UF218 { u32 u; f32 f; u8 c; };
void func_00185b00(void*) asm("func_00185b00");
extern u8 D_00350ce0[] asm("D_00350ce0");
void ctarget_001ae9a0(u8* p) asm("_Z16ctarget_001ae9a0jjjj");
void ctarget_001ae9a0(u8* p) {
    func_00185b00(p);
    *(u32*)p = (u32)D_00350ce0;
    *(u32*)(p + 1416) |= 0x400;
    UF218* q = (UF218*)(p + 1648);
    q[66].u = 0;
    q[65].f = 2000.0f;
    ((UF218*)(p + 2748))->u |= 0x8404;
}
}  // namespace n001ae9a0

// ---- 001aea00 from src/anon/batch_w39.cpp
namespace n001aea00 {
union Word { f32 f; u32 u; };
extern void* D_00350ce0[] asm("D_00350ce0");
void func_00185b00(u8*) asm("func_00185b00");
void func_001aea00(u8* p) asm("func_001aea00");
void func_001aea00(u8* p) {
    func_00185b00(p);
    *(u32*)p = (u32)D_00350ce0;
    *(u32*)(p + 1416) |= 0x400;
    u8* m = p + 1648;
    *(u32*)(m + 264) = 0;
    ((Word*)(m + 260))->f = 2000.0f;
    *(u32*)(p + 2748) |= 0x8404;
}
}  // namespace n001aea00

// ---- 001aea60 from src/anon/auto80_199_queue.cpp
namespace n001aea60 {
u32 func_001aea60(u32 a0) asm("_Z13func_001aea60j");
u32 func_001aea60(u32 a0) {
    u32 s0 = a0;
    func_00185d10(s0);

    *(u32*)(D_00350000 + 3272) = s0;

    u32 v0 = func_0016a020(s0);
    *(u32*)(D_00350000 + 3280) = v0;

    v0 = func_0016ac38(s0, 0, 1, 0, 0);
    *(u32*)(D_00350000 + 3276) = v0;
    if (v0 != 0) {
        *(u32*)(v0 + 4) = 3;
    }

    v0 = func_0016a020(s0);
    return func_001991a8(4, v0);
}
}  // namespace n001aea60

// ---- 001aeae0 from src/anon/batch_w3.cpp
namespace n001aeae0 {
extern u32 D_00350cc8 asm("D_00350cc8");
extern u32 D_00350cd0 asm("D_00350cd0");
extern u32 D_00350ccc asm("D_00350ccc");
void func_001aeae0() asm("func_001aeae0");
void func_001aeae0() {
    D_00350cc8 = 0;
    D_00350cd0 = 0;
    D_00350ccc = 0;
}
}  // namespace n001aeae0

// ---- 001aeb00 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001aeb00 {
u32 func_001ae9a0(u32, u32, u32, u32) asm("_Z13func_001ae9a0jjjj");
extern u8 D_00350d68 asm("D_00350d68");
u32 func_001aeb00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001aeb00jjjj");
u32 func_001aeb00(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001ae9a0(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(2748));
    r15 = (u32)&D_00350d68;
    r14 = (u32)(r14 | 0x0002u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(2748)) = r14;
    return r2;
}
}  // namespace n001aeb00

// ---- 001aeb40 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001aeb40 {
u32 func_001ae9a0(u32, u32, u32, u32) asm("_Z13func_001ae9a0jjjj");
extern u8 D_00350d68 asm("D_00350d68");
u32 func_001aeb40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001aeb40jjjj");
u32 func_001aeb40(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001ae9a0(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(2748));
    r15 = (u32)&D_00350d68;
    r14 = (u32)(r14 | 0x0002u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(2748)) = r14;
    return r2;
}
}  // namespace n001aeb40

// ---- 001aeb80 from src/anon/batch_w45.cpp
namespace n001aeb80 {
u32 YS__DATABUFF__ReadBar(u32) asm("YS__DATABUFF__ReadBar");
u8* func_00168b38(u32, u32, s32) asm("func_00168b38");
extern u32 D_00350de8 asm("D_00350de8");
extern u32 D_01c94040[] asm("D_01c94040");
void func_001aeb80(void) asm("func_001aeb80");
void func_001aeb80(void) {
    u32 v = YS__DATABUFF__ReadBar(D_00350de8);
    for (s32 i = 0; i < 19; i++) {
        D_01c94040[i] = *(u32*)(func_00168b38(v, 2, i) + 8);
    }
}
}  // namespace n001aeb80

// ---- 001aebf0 from src/anon/batch_w30.cpp
namespace n001aebf0 {
extern s32* D_01c94040[] asm("D_01c94040");
extern void* D_01c9408c asm("D_01c9408c");
void func_001aebf0(u8* a) asm("func_001aebf0");
void func_001aebf0(u8* a) {
    s32* t = D_01c94040[a[0]];
    if (a[1] >= *t) D_01c9408c = 0;
    else D_01c9408c = (u8*)t + a[1] * 24 + 4;
}
}  // namespace n001aebf0

// ---- 001aec40 from src/anon/tiny.cpp
namespace n001aec40 {
u32 func_001aec40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001aec40jjjj");
u32 func_001aec40(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01c9u << 16);
    return (u32)(*(u32*)((u32)b + (16524)));
}
}  // namespace n001aec40

// ---- 001aedf8 from src/anon/batch_w3734_nsa.cpp
namespace n001aedf8 {
struct Sub {
    s32 a; s32 b; u8 c; s32 d; s32 e; s32 f; s32 g;
};
struct Word { s32 v; };
struct Byte { u8 v; };
#define CLEAR_WORD(base, off) (((Word*)((u8*)(base) + (off)))->v = 0)
#define CLEAR_BYTE(base, off) (((Byte*)((u8*)(base) + (off)))->v = 0)
struct Tmr { u8 pad[0x30]; void* f30; };
struct Mgr {
    s32 mode; s32 f4; s32 f8; u8 fc; u8 pad[7];
    Sub s1; Sub s2;
    Tmr* f4c;
};
extern Mgr* D_00350df0 asm("D_00350df0");
extern u32 D_0034f240 asm("D_0034f240");
extern u8 D_00351ec8[] asm("D_00351ec8");
s32 func_001bb9f0(void) asm("func_001bb9f0");
void func_001aefa0(Mgr*) asm("func_001aefa0");
void func_001c8d80(void*, s32) asm("func_001c8d80");
void func_001af0c0(Mgr*) asm("func_001af0c0");
void func_001373a0(void) asm("func_001373a0");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
s32 func_00195328(s32) asm("func_00195328");
void* func_001050d8(s32) asm("func_001050d8");
void YS__EVENT__EVENT(void*, s32, s32) asm("YS__EVENT__EVENT");
void YS__EVENT__set_camera_target(void*, s32) asm("YS__EVENT__set_camera_target");
void YS__EVENT__start(void*) asm("YS__EVENT__start");
void func_00138480(s32) asm("func_00138480");
Tmr* func_00102c18(s32, s32, void*) asm("func_00102c18");
void func_001af398(void) asm("func_001af398");
void func_001af3e0(void) asm("func_001af3e0");
// 0x001aec50: unwritten C2/D2 copy, same body
void func_001aec50(Mgr* m, s32 arg1, s32 mode) asm("func_001aec50");
void func_001aec50(Mgr* m, s32 arg1, s32 mode) {
    m->mode = mode;
    m->f4 = 0;
    m->f8 = 0;
    m->fc = 0;
    {
        Sub* p = &m->s1;
        Sub* q = &m->s2;
        m->s1.a = 0;
        p->b = 0;
        q->a = 0;
        CLEAR_BYTE(m, 28); CLEAR_WORD(m, 32); CLEAR_WORD(m, 36); CLEAR_WORD(m, 40);
        p->g = 0;
        q->b = 0;
        CLEAR_BYTE(m, 56); CLEAR_WORD(m, 60); CLEAR_WORD(m, 64); CLEAR_WORD(m, 68);
        q->g = 0;
    }
    D_00350df0 = m;
    if (m->mode == 0) {
        if (func_001bb9f0()) func_001aefa0(m);
    }
    D_0034f240 |= 2;
    if (m->mode != 2) {
        func_001c8d80(D_00351ec8, 1);
        func_001af0c0(m);
    }
    func_001373a0();
    switch (m->mode) {
    case 0: case 2: case 3:
        func_002ba2e8(19, 0);
        break;
    case 1:
        func_002ba2e8(51, 0);
        break;
    }
    if (arg1 != 0) {
        s32 r = func_00195328(0);
        void* o = func_001050d8(0xb0);
        YS__EVENT__EVENT(o, 15, r);
        YS__EVENT__set_camera_target(o, arg1);
        YS__EVENT__start(o);
    }
    func_00138480(2);
    m->f4c = func_00102c18(1, 15000, (void*)func_001af398);
    m->f4c->f30 = (void*)func_001af3e0;
}

void YS__GAMEOVER__GAMEOVER(Mgr* m, s32 arg1, s32 mode) asm("YS__GAMEOVER__GAMEOVER");
void YS__GAMEOVER__GAMEOVER(Mgr* m, s32 arg1, s32 mode) {
    m->mode = mode;
    m->f4 = 0;
    m->f8 = 0;
    m->fc = 0;
    {
        Sub* p = &m->s1;
        Sub* q = &m->s2;
        m->s1.a = 0;
        p->b = 0;
        q->a = 0;
        CLEAR_BYTE(m, 28); CLEAR_WORD(m, 32); CLEAR_WORD(m, 36); CLEAR_WORD(m, 40);
        p->g = 0;
        q->b = 0;
        CLEAR_BYTE(m, 56); CLEAR_WORD(m, 60); CLEAR_WORD(m, 64); CLEAR_WORD(m, 68);
        q->g = 0;
    }
    D_00350df0 = m;
    if (m->mode == 0) {
        if (func_001bb9f0()) func_001aefa0(m);
    }
    D_0034f240 |= 2;
    if (m->mode != 2) {
        func_001c8d80(D_00351ec8, 1);
        func_001af0c0(m);
    }
    func_001373a0();
    switch (m->mode) {
    case 0: case 2: case 3:
        func_002ba2e8(19, 0);
        break;
    case 1:
        func_002ba2e8(51, 0);
        break;
    }
    if (arg1 != 0) {
        s32 r = func_00195328(0);
        void* o = func_001050d8(0xb0);
        YS__EVENT__EVENT(o, 15, r);
        YS__EVENT__set_camera_target(o, arg1);
        YS__EVENT__start(o);
    }
    func_00138480(2);
    m->f4c = func_00102c18(1, 15000, (void*)func_001af398);
    m->f4c->f30 = (void*)func_001af3e0;
}
}  // namespace n001aedf8

// ---- .rodata 0x36d860-0x36d884: file names read through .data (0x350de8)
extern const char R_0036d860[16] asm("D_0036d860") = "12soundinfo.bar";
extern const char R_0036d870[20] asm("D_0036d870") = "obj/GAMEOVER.mset";

// ---- 001aefa0 from src/anon/batch_w257.cpp
namespace n001aefa0 {
#define QCOPY257(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV257 {
    f32 x, y, z, w;
    QV257() {}
    QV257(const QV257& o) { QCOPY257(this, &o); }
} __attribute__((aligned(16)));
static inline QV257 operator*(const QV257& a, f32 k) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QV257 operator+(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV257 operator-(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern u8* D_00352130 asm("D_00352130");
struct S32bb { u8 pad[0x3db0]; u16 h; };
extern S32bb D_0032bb30 asm("D_0032bb30");
extern u32 D_003638d0 asm("D_003638d0");
u8* func_0017df58(s32) asm("func_0017df58");
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
s32 YS__FRIEND__can_sacrifice_leave(u8*) asm("YS__FRIEND__can_sacrifice_leave");
f32 func_002f8b30(f32, f32) asm("func_002f8b30");
#define MAX257(a, b) ((a) > (b) ? (a) : (b))
void func_001aefa0(u8* a0) asm("func_001aefa0");
void func_001aefa0(u8* a0) {
    for (s32 i = 0; i < 2; i++) {
        u8* p = func_0017df58(i);
        if (YS__OBJ__is_exist(p)) {
            if (!YS__FRIEND__can_sacrifice_leave(p)) return;
        }
    }
    f32 m = MAX257(func_002f8b30(*(f32*)(D_00352130 + 0xd8), (f32)D_0032bb30.h), *(f32*)(D_00352130 + 0xdc));
    D_003638d0 *= 0x10dcd;
    if ((f32)D_003638d0 * 2.3283064365386963e-10f < m) a0[0xc] = 1;
}
}  // namespace n001aefa0

// ---- 001af0c0 from src/anon/batch_w76.cpp
namespace n001af0c0 {
extern u32 D_0034e948 asm("D_0034e948");
void func_001af638(void) asm("func_001af638");
void func_001af6f0(void) asm("func_001af6f0");
void func_001bb468(u8*) asm("func_001bb468");
u32 func_001c10f8(s32) asm("func_001c10f8");
s32 YS__PLAYER__is_changing(u8*) asm("YS__PLAYER__is_changing");
u32 func_001d1438(s32) asm("func_001d1438");
u32 func_0016a020(u8*) asm("func_0016a020");
static inline bool Is12(u8* p) { return *(s32*)(p + 2896) == 12; }
void func_001af0c0(u8* o) asm("func_001af0c0");
void func_001af0c0(u8* o)
{
    if (*(u8*)(o + 12) == 0) func_001bb468(o);
    else *(void**)(o + 44) = (void*)func_001af638;
    if (*(s32*)o == 3) {
        *(u32*)(o + 16) = func_001c10f8(33);
    } else {
        *(u32*)(o + 16) = func_001c10f8(1);
        *(void**)(o + 72) = (void*)func_001af6f0;
    }
    u8* p = (u8*)D_0034e948;
    if (p) {
        u32 v;
        if (YS__PLAYER__is_changing(p) || Is12(p)) v = func_001d1438(0);
        else v = func_0016a020(p) | 0x20000000;
        *(u32*)(o + 48) = v;
    } else {
        *(u32*)(o + 48) = 0;
    }
}
}  // namespace n001af0c0

// ---- 001af210 from src/anon/auto80_199_queue.cpp
namespace n001af210 {
// 0x001af190: unwritten C2/D2 copy, same body
void func_001af190(u32 a0) asm("func_001af190");
void func_001af190(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 4);
    if (t7 != 0) {
        func_00170950(t7);
        func_00170320(5000);
    }

    u32 t7b = *(u32*)(D_00350000 - 3520);
    t7b &= (u32)-3;
    *(u32*)(D_00350000 - 3520) = t7b;

    u32 t6 = *(u32*)(s0 + 0);
    if (t6 != 2) {
        func_001c8d98((u32)(D_00350000 + 7880), 1);
    }

    func_001384a0(2);
    *(u32*)(D_00350000 + 3568) = 0;
}

void func_001af210(u32 a0) asm("_Z13func_001af210j");
void func_001af210(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)(a0 + 4);
    if (t7 != 0) {
        func_00170950(t7);
        func_00170320(5000);
    }

    u32 t7b = *(u32*)(D_00350000 - 3520);
    t7b &= (u32)-3;
    *(u32*)(D_00350000 - 3520) = t7b;

    u32 t6 = *(u32*)(s0 + 0);
    if (t6 != 2) {
        func_001c8d98((u32)(D_00350000 + 7880), 1);
    }

    func_001384a0(2);
    *(u32*)(D_00350000 + 3568) = 0;
}
}  // namespace n001af210

// ---- 001af290 from src/anon/auto80_199_queue.cpp
namespace n001af290 {
void func_001af290(u32 a0) asm("_Z13func_001af290j");
void func_001af290(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(D_00350000 + 3568) != 0) {
        return;
    }
    u32 v0 = func_001050d8(80);
    return YS__GAMEOVER__GAMEOVER(v0, s0, 0);
}
}  // namespace n001af290

// ---- 001af2e8 from src/anon/tiny_auto80_queue.cpp
namespace n001af2e8 {
void YS__GAMEOVER__GAMEOVER(...) asm("YS__GAMEOVER__GAMEOVER");
u32 func_001050d8(...) asm("func_001050d8");
void func_001af2e8() asm("_Z13func_001af2e8v");
void func_001af2e8() {
    u32* b = (u32*)0x00350000;
    if (b[892] != 0) {
        return;
    }
    u32 p = func_001050d8(80);
    YS__GAMEOVER__GAMEOVER(p, 0, 1);
}
}  // namespace n001af2e8

// ---- 001af328 from src/anon/batch_w22.cpp
namespace n001af328 {
void* func_001050d8(u32) asm("func_001050d8");
void YS__GAMEOVER__GAMEOVER(void*, u32, u32) asm("YS__GAMEOVER__GAMEOVER");
void func_001af328(u32 a) asm("func_001af328");
void func_001af328(u32 a) {
    YS__GAMEOVER__GAMEOVER(func_001050d8(80), a, 2);
}
}  // namespace n001af328

// ---- 001af360 from src/anon/batch_w23.cpp
namespace n001af360 {
void* func_001050d8(u32) asm("func_001050d8");
void YS__GAMEOVER__GAMEOVER(void*, void*, s32) asm("YS__GAMEOVER__GAMEOVER");
void func_001af360(void* a) asm("func_001af360");
void func_001af360(void* a) {
    YS__GAMEOVER__GAMEOVER(func_001050d8(80), a, 3);
}
}  // namespace n001af360

// ---- 001af398 (gap: GAMEOVER task step callback)
namespace n001af398 {
extern u8* D_00350df0 asm("D_00350df0");
s32 func_001af420(u8*) asm("func_001af420");
void func_001024a8(void*) asm("func_001024a8");
void func_001af398(void* t) asm("func_001af398");
void func_001af398(void* t) {
    if (func_001af420(D_00350df0)) return;
    func_001024a8(t);
}
}  // namespace n001af398

// ---- 001af3e0 from src/anon/tiny_auto80_queue.cpp
namespace n001af3e0 {
u32 func_00105110(...) asm("func_00105110");
u32 func_001af210(...) asm("func_001af210");
void func_001af3e0(u32 a0) asm("_Z13func_001af3e0j");
void func_001af3e0(u32 a0) {
    u32 r4 = a0, r15, r16;
    r15 = (u32)(0x0035u << 16);
    r16 = *(u32*)((u32)r15 + (s32)(3568));
    r4 = r16;
    if (r16 != 0u) {
    u32 (*fp_call4_001af210)(u32) = (u32(*)(u32))func_001af210;
        ((void(*)(u32))fp_call4_001af210)(r4);
        r4 = r16;
    u32 (*fp_call4_00105110)(u32) = (u32(*)(u32))func_00105110;
        ((void(*)(u32))fp_call4_00105110)(r4);
    }
}
}  // namespace n001af3e0

// ---- 001af420 from src/anon/batch_w2024_g.cpp
namespace n001af420 {
struct W2024d_St { s32 mode; s32 f4; s32 step; u8 flag; u8 pad[3]; s32 f10; u8 f14[0x1c]; u8 f30[4]; };
struct W2024d_Pl { u8 pad[0xfc]; s32 fc; };
extern s32 D_0034e948 asm("D_0034e948");
extern u8 D_00351eb8[] asm("D_00351eb8");
extern u8 D_00351ec0[] asm("D_00351ec0");
void func_002bc788(void) asm("func_002bc788");
s32 func_00197920(void) asm("func_00197920");
W2024d_Pl* func_0014ac08(void) asm("func_0014ac08");
void func_002bc798(void) asm("func_002bc798");
void func_001852b8(s32) asm("func_001852b8");
void YS__GAMEOVER__Reraise(void) asm("YS__GAMEOVER__Reraise");
void YS__PRIZE__ClearAll(void) asm("YS__PRIZE__ClearAll");
void func_00197738(void) asm("func_00197738");
void func_001c8948(void) asm("func_001c8948");
s32 func_001c8db8(void*, s32) asm("func_001c8db8");
s32 YS__CACHE_BUFF__IsFlushing(void) asm("YS__CACHE_BUFF__IsFlushing");
void func_001c8d80(void*, s32) asm("func_001c8d80");
void func_001c98f0(f32) asm("func_001c98f0");
void YS__MICKEY__ReadRequest(void) asm("YS__MICKEY__ReadRequest");
void func_001af8d8(W2024d_St*) asm("func_001af8d8");
void func_00170888(s32) asm("func_00170888");
s32 func_001c9df8(void) asm("func_001c9df8");
s32 func_001c10f8(s32) asm("func_001c10f8");
void func_00253410(s32, void*) asm("func_00253410");
void func_001af778(W2024d_St*) asm("func_001af778");
void dk__BGM__Continue(void) asm("dk__BGM__Continue");
void func_001d00a8(void) asm("func_001d00a8");
s32 func_001af420(W2024d_St* self) asm("func_001af420");
s32 func_001af420(W2024d_St* self) {
    switch (self->step) {
    case 1:
        func_002bc788();
        self->step++;
    case 2:
        if (func_00197920() != 0) break;
        if ((func_0014ac08()->fc ^ 4) != 0) break;
        func_002bc798();
        if (self->mode != 1) func_001852b8(D_0034e948);
        if (self->mode == 2) {
            YS__GAMEOVER__Reraise();
            return 0;
        }
        if (self->flag) {
            YS__PRIZE__ClearAll();
        } else {
            func_00197738();
            func_001c8948();
        }
        self->step++;
        break;
    case 0:
    case 3:
        self->step++;
        break;
    case 4:
        if (func_001c8db8(D_00351eb8, 0) != 0) break;
        if (func_001c8db8(D_00351ec0, 0) != 0) break;
        if (YS__CACHE_BUFF__IsFlushing() != 0) break;
        func_001c8d80(D_00351eb8, 0);
        if (self->flag) {
            func_001c98f0(0.0f);
            YS__MICKEY__ReadRequest();
        } else {
            func_001af8d8(self);
        }
        func_00170888(0);
        self->step++;
        break;
    case 5:
        if (self->flag) {
            if (func_001c9df8() != 0) break;
            func_00253410(func_001c10f8(10), self->f14);
        } else {
            if (YS__CACHE_BUFF__IsFlushing() != 0) break;
            func_001af778(self);
            func_00253410(self->f10, self->f30);
        }
        self->step++;
        break;
    case 7:
        dk__BGM__Continue();
        func_001d00a8();
        return 0;
    case 8:
        return 0;
    }
    return 1;
}
}  // namespace n001af420

// ---- 001af638 (gap: GAMEOVER callbacks)
namespace n001af638 {
extern u8* D_00350df0 asm("D_00350df0");
void* func_0014ac08(void) asm("func_0014ac08");
void func_0014aa58(void*, s32, s32) asm("func_0014aa58");
void func_0014e118(void) asm("func_0014e118");
void func_001af8d8(u8*) asm("func_001af8d8");
void func_00170888(s32) asm("func_00170888");
void func_001af778(u8*) asm("func_001af778");
void func_00253480(s32, u8*) asm("func_00253480");
void func_001af638(s32 ev, s32 arg) asm("func_001af638");
void func_001af638(s32 ev, s32 arg) {
    switch (ev) {
    case 9:
        func_00170888(arg);
        *(s32*)(D_00350df0 + 8) = 7;
        break;
    case 8:
        func_0014aa58(func_0014ac08(), 0, 0);
        func_0014e118();
        func_001af8d8(D_00350df0);
        func_00170888(arg);
        func_001af778(D_00350df0);
        func_00253480(*(s32*)(D_00350df0 + 16), D_00350df0 + 48);
        *(s32*)(D_00350df0 + 8) = ev;
        break;
    }
}

struct Ids1af6f0 { u16 x, y, z; };
struct Loc1af6f0 {
    u8 a, b, c, pad;
    Ids1af6f0 ids;
    Loc1af6f0() { Fill(0xffff); }
    void Fill(s32 v) { a = v; b = v; c = v; ids.x = v; ids.y = v; ids.z = v; }
};
void func_00136a98(void) asm("func_00136a98");
Loc1af6f0 func_001cd520(void) asm("func_001cd520");
void AREA__MapJump(Loc1af6f0*, s32, s32, s32, s32) asm("AREA__MapJump");
void func_001af6f0(s32 ev) asm("func_001af6f0");
void func_001af6f0(s32 ev) {
    Loc1af6f0 l;
    switch (ev) {
    case 1:
        break;
    case 2:
        func_00136a98();
        l = func_001cd520();
        AREA__MapJump(&l, 0x80000001, 1, 1, 0);
        break;
    }
}
}  // namespace n001af638

// ---- 001af778 from src/anon/batch_w33.cpp
namespace n001af778 {
extern void* D_00350dec asm("D_00350dec");
void* func_001708f8(void*, s32) asm("func_001708f8");
void* func_001af7c0(void*, void*) asm("func_001af7c0");
struct Obj1af { u8 pad[4]; void* a; u8 pad2[40]; void* b; void* c; };
void func_001af778(Obj1af* o) asm("func_001af778");
void func_001af778(Obj1af* o) {
    o->a = func_001708f8(D_00350dec, -1);
    o->c = func_001af7c0(o, o->b);
}
}  // namespace n001af778

// ---- 001af7c0 from src/anon/batch_w8008.cpp
namespace n001af7c0 {
struct W8008Ent { u8 pad[8]; s32 f8; };
struct W8008Arg { s32 type; void* f4; };
struct W8008CD { u8 pad[7]; u8 num; };
static inline bool w8008_ok(W8008Ent* e) { return e && e->f8; }
extern char D_0036d8b0[] asm("D_0036d8b0");
W8008CD* w8008_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 w8008_sprintf(char*, const char*, u32) asm("_Z16wtarget_002fee78jjjj");
W8008Ent* func_00168b38(void*, s32, s32) asm("func_00168b38");
W8008Ent* func_00168b88(s32, s32, s32, s32) asm("func_00168b88");
s32 func_001af7c0(W8008Arg* a, u32 id) asm("func_001af7c0");
s32 func_001af7c0(W8008Arg* a, u32 id)
{
    W8008CD* cd = w8008_GetCharaData(id);
    s32 k = 0;
    switch (a->type) {
    case 0: k = 0xfc; break;
    case 1: case 3: k = 0xfd; break;
    }
    W8008Ent* e = func_00168b38(a->f4, -1, k);
    if (!w8008_ok(e)) return 0;
    char buf[16];
    const char* fmt = D_0036d8b0;
    u8 num = cd->num;
    s32 h = e->f8;
    w8008_sprintf(buf, fmt, num);
    e = func_00168b88(h, -1, buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24), 2);
    if (!w8008_ok(e)) return 0;
    return func_00168b38((void*)e->f8, 9, 0)->f8;
}
}  // namespace n001af7c0

// ---- 001af8d8 from src/anon/auto80_199_queue.cpp
namespace n001af8d8 {
u32 func_001af8d8(u32 a0) asm("_Z13func_001af8d8j");
u32 func_001af8d8(u32 a0) {
    u32 s0 = a0;
    func_00170320(5000);
    u32 v0 = func_00170518(*(u32*)((u8*)D_00350000 + 3564), 5000, 0);

    u32 t7 = *(u32*)(s0 + 48);
    if (t7 != 0) {
        return YS__OBJENTRY__ReadRequest(t7, (u32)-1, 30);
    }
    return v0;
}
}  // namespace n001af8d8

// ---- 001af938 from src/anon/batch_w1578_g.cpp
namespace n001af938 {
void* W1578_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void* W1578_JmInfo_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void W1578_YS_SUMMON_LeaveTink(void) asm("_ZN2YS6SUMMON9LeaveTinkEv");
s32 YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
f32 W1578_ObjCamera_getObjBackDirection(u32) asm("_ZN2dk9ObjCamera19getObjBackDirectionEv");
void YS__SUMMON__SUMMON(f32, u8*, void*, s32) asm("YS__SUMMON__SUMMON");
void W1578_YS_ACT_push(u8*, char*) asm("_ZN2YS3ACT4pushEPc");
void dk__BGM__Continue(void) asm("dk__BGM__Continue");
extern u32 D_0034e948 asm("D_0034e948");
extern u32 D_0034f240 asm("D_0034f240");
extern char D_0036d8b8[] asm("D_0036d8b8");
void YS__GAMEOVER__Reraise(void) asm("YS__GAMEOVER__Reraise");
void YS__GAMEOVER__Reraise(void) {
    W1578_YS_SUMMON_LeaveTink();
    u32 obj = D_0034e948;
    u8* p = (u8*)W1578_AREA_Alloc(0xd00);
    void* cd = W1578_JmInfo_GetCharaData(0x4f4);
    s32 r = YS__OBJ__get_pos(obj);
    YS__SUMMON__SUMMON(W1578_ObjCamera_getObjBackDirection(obj), p, cd, r);
    W1578_YS_ACT_push(p + 0x300, D_0036d8b8);
    D_0034f240 &= ~2;
    dk__BGM__Continue();
}
}  // namespace n001af938

// ---- 001af9e8 from src/anon/tiny.cpp
namespace n001af9e8 {
extern u32 D_00350df0 asm("D_00350df0");
u32 func_001af9e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001af9e8jjjj");
u32 func_001af9e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_00350df0 != 0);
}
}  // namespace n001af9e8

// ---- 001af9f8 from src/anon/tiny_auto80_queue.cpp
namespace n001af9f8 {
void func_00102670(...) asm("func_00102670");
void func_001af9f8() asm("_Z13func_001af9f8v");
void func_001af9f8() {
    u32* b = (u32*)0x00350000;
    u32 p = b[892];
    if (p == 0) {
        return;
    }
    u32 a1 = *(u32*)(p + 76);
    u32* g = (u32*)0x00330000;
    func_00102670(g[-4517], a1);
}
}  // namespace n001af9f8

// ---- 001afa30 from src/anon/tiny_wrappers_imp.cpp
namespace n001afa30 {
u32 func_001afa50(u32, u32, u32, u32) asm("_Z13func_001afa50jjjj");
u32 func_001afa30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001afa30jjjj");
u32 func_001afa30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x01c9u << 16);
    *(u32*)((u32)r15 + (s32)(16564)) = r4;
    return func_001afa50(r4, r5, r6, r7);
}
}  // namespace n001afa30

// ---- 001afa50 from src/anon/batch_w19.cpp
namespace n001afa50 {
struct Trio { s32 a, b, c; };
extern Trio D_01c94090[3] asm("D_01c94090");
void wtarget_001afa50(u32, u32, u32, u32) asm("_Z16wtarget_001afa50jjjj");
void wtarget_001afa50(u32, u32, u32, u32) {
    Trio* p;
    for (p = D_01c94090; (s32)p < (s32)(D_01c94090 + 3); p++) {
        p->a = 0;
        p->b = -1;
        p->c = -1;
    }
}
}  // namespace n001afa50

// ---- 001afa88 from src/anon/auto80_199_queue.cpp
namespace n001afa88 {
void func_001afa88(u32 a0) asm("_Z13func_001afa88j");
void func_001afa88(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(D_00350000 + 3576) != 0) {
        do {
            func_00102448(s0, 0);
        } while (*(u32*)(D_00350000 + 3576) != 0);
    }
    *(u32*)(D_00350000 + 3576) = s0;
}
}  // namespace n001afa88

// ---- 001afae0 from src/anon/tiny.cpp
namespace n001afae0 {
void func_001afae0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001afae0jjjj");
void func_001afae0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u32*)((u32)b + (3576)) = (u32)0;
}
}  // namespace n001afae0

// ---- 001afaf0 from src/anon/auto80_199_queue.cpp
namespace n001afaf0 {
void func_001afa88(u32 a0) asm("_Z13func_001afa88j");
void func_001afaf0(u32 a0) asm("_Z13func_001afaf0j");
void func_001afaf0(u32 a0) {
    func_001afa88(a0);

    u32* p = (u32*)(D_01c90000 + 16528);
    u32* end = (u32*)(D_01c90000 + 16564);
    do {
        *p &= (u32)-2;
        p = (u32*)((u8*)p + 12);
    } while ((s32)(u32)p < (s32)(u32)end);

    u32 s0 = func_00170b30(0x00080000);
    YS__VOICE__ReadEntryId(566, s0);
    YS__VOICE__ReadEntryId(567, s0);
    YS__VOICE__ReadEntryId(568, s0);
    func_00170c00(s0);
    return func_001afae0();
}
}  // namespace n001afaf0

// ---- 001afb80 from src/anon/auto80_199_queue.cpp
namespace n001afb80 {
void func_001afa88(u32 a0) asm("_Z13func_001afa88j");
void func_001afb80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001afb80jjjj");
void func_001afb80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a2;
    u32 s1 = a1;
    u32 s2 = a3;

    func_001afa88(a0);

    s32 idx = func_001afe30(s0);
    if (idx >= 0) {
        u32* p = (u32*)(D_01c90000 + 16528 + idx * 12);
        *p &= (u32)-2;
    }

    YS__VOICE__ReadEntryId(s2, s1);
    return func_001afae0();
}
}  // namespace n001afb80

// ---- 001afc00 from src/anon/batch_w2394_nsa.cpp
namespace n001afc00 {
struct VT { u8 pad[76]; u16 id; };
struct VO { u8 pad[48]; u16 sub; };
struct Slot { u32 flags; u32 id; u32 sub; };
extern Slot D_01c94090[3] asm("D_01c94090");
extern char* D_0033caf4 asm("D_0033caf4");
extern char D_0036d938[] asm("D_0036d938");
extern char D_0036d940[] asm("D_0036d940");
extern u8 D_0032bae0 asm("D_0032bae0");
extern u32 D_00350e00[] asm("D_00350e00");
extern u8* D_00350df8 asm("D_00350df8");
VT* func_0016e920(u32) asm("func_0016e920");
VO* func_001947c0(s32, s32) asm("func_001947c0");
s32 func_00105c30(void) asm("func_00105c30");
u32 func_00105ee8(u8) asm("func_00105ee8");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void YS__FILE__ReadBack(char*, void*, void (*)(void), s32) asm("YS__FILE__ReadBack");
void func_001afdd0(void) asm("func_001afdd0");
void func_00102448(u8*, s32) asm("func_00102448");
static inline bool same(Slot* e, u32 id, u32 sub) { return e->id == id && e->sub == sub; }
void YS__VOICE__ReadEntryId(u32 a, void* b) asm("YS__VOICE__ReadEntryId");
void YS__VOICE__ReadEntryId(u32 a, void* b)
{
    char buf[48];
    if ((a == 0)) return;
    VT* v = func_0016e920(a);
    if ((v == 0)) return;
    u32 id = v->id;
    if ((id - 1 >= 15)) return;
    u32 sub = func_001947c0(-1, -1)->sub;
    s32 i;
    for (i = 0; i < 3; i++) {
        if (same(&D_01c94090[i], id, sub)) {
            D_01c94090[i].flags |= 1;
            return;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((D_01c94090[i].flags & 1) == 0) break;
    }
    char* lang = D_0033caf4;
    D_01c94090[i].flags |= 1;
    D_01c94090[i].id = id;
    D_01c94090[i].sub = sub;
    if (func_00105c30() == 8) lang = D_0036d938;
    func_002fee78(buf, D_0036d940, lang, func_00105ee8(D_0032bae0), sub, D_00350e00[id]);
    YS__FILE__ReadBack(buf, b, func_001afdd0, i);
    *(u32*)(D_00350df8 + 4) = 1;
    while (*(u32*)(D_00350df8 + 4)) func_00102448(D_00350df8, 0);
}
}  // namespace n001afc00

// ---- 001afdd0 (gap: load-done callback passed by 0x1afc00)
namespace n001afdd0 {
void func_001afe18_cb(s32, s32, s32) asm("func_001afe18");
void func_001afe18_cb1(s32) asm("func_001afe18");
void func_002bb070(s32, s32, s32, void (*)(s32, s32, s32), s32) asm("func_002bb070");
void func_001afdd0(s32 a, s32 b, s32 c) asm("func_001afdd0");
void func_001afdd0(s32 a, s32 b, s32 c) {
    if (b) func_002bb070(c, a, b, func_001afe18_cb, 0);
    else func_001afe18_cb1(0);
}
}  // namespace n001afdd0

// ---- 001afe18 from src/anon/batch_w1667.cpp
namespace n001afe18 {
extern u8* D_00350df8 asm("D_00350df8");
void func_001afe18(void) asm("func_001afe18");
void func_001afe18(void) {
    u8* p = D_00350df8;
    if (p) *(u32*)(p + 4) = 0;
}
}  // namespace n001afe18

// ---- 001afe30 from src/anon/batch_w11.cpp
namespace n001afe30 {
struct E1af { u32 a; s32 key; u32 c; };
extern E1af D_01c94090[3] asm("D_01c94090");
s32 func_001afe30(s32 key) asm("func_001afe30");
s32 func_001afe30(s32 key) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_01c94090[i].key == key) return i;
    }
    return -1;
}
}  // namespace n001afe30

// ---- 001afe70 from src/anon/batch_w39.cpp
namespace n001afe70 {
u8* func_001aff90(u32, u32, u32) asm("func_001aff90");
int func_001affe0(u8*, u32, u32) asm("func_001affe0");
int func_001afe70(u32 a, u32 b, u32 c, u32* out) asm("func_001afe70");
int func_001afe70(u32 a, u32 b, u32 c, u32* out) {
    u8* r = func_001aff90(a, b, c);
    if (!r) return -1;
    *out = r[2];
    return func_001affe0(r, a, c);
}
}  // namespace n001afe70

// ---- 001afee8 from src/anon/batch_wcx.cpp
namespace n001afee8 {
s32 func_00181500(s32) asm("func_00181500");
s32 func_001afee8(s32 a, s32 b) asm("func_001afee8");
s32 func_001afee8(s32 a, s32 b)
{
    if (a == b) return -1;
    if (!func_00181500(6220) && !func_00181500(6156) && !func_00181500(6190)) {
        if (a == 5 || b == 5) return -1;
    }
    if ((u32)(b - 1) >= 15) return -1;
    if ((u32)(b - 1) < 3) return b - 1;
    return b == 15 ? 4 : 3;
}
}  // namespace n001afee8

// ---- 001aff90 from src/anon/batch_w1749.cpp
namespace n001aff90 {
struct E14 { u8 a; u8 b; u8 pad[12]; };
struct Tbl { s32 x; s32 n; E14 e[1]; };
extern Tbl* D_01c940b4 asm("D_01c940b4");
E14* func_001aff90(s32 a, s32 b) asm("func_001aff90");
E14* func_001aff90(s32 a, s32 b)
{
    E14* e = D_01c940b4->e;
    for (s32 i = 0; i < D_01c940b4->n; i++, e++) {
        if (e->a == a && e->b == b) return e;
    }
    return 0;
}
}  // namespace n001aff90

// ---- 001affe0 from src/anon/batch_w273.cpp
namespace n001affe0 {
typedef unsigned long long u64_273 __attribute__((mode(DI)));
struct Ent273 { s8 id; s8 w; };
struct Tbl273 { u8 pad[4]; Ent273 e[5]; };
extern u32 D_003638d0 asm("D_003638d0");
u64_273 func_00312db8(u64_273, u64_273) asm("func_00312db8");
s32 func_001b0148(void*, s32, s32, s32) asm("func_001b0148");
static inline u32 rnd273(void) {
  D_003638d0 = D_003638d0 * 0x10dcd;
  return D_003638d0;
}
s32 func_001affe0(Tbl273* t, s32 a1, s32 a2) asm("func_001affe0");
s32 func_001affe0(Tbl273* t, s32 a1, s32 a2) {
  s32 out[5];
  s32 cnt = 0;
  s32 i = 0;
  s32 pct = func_00312db8(rnd273(), 0x28f5c29);
  u8* e = (u8*)t;
  s32* o = out;
  for (; i < 5; i++, e += 2) {
    s32 r = func_001b0148(t, a1, (s8)e[4], a2);
    if (r >= 0) {
      if ((s8)e[5] > 0) {
        pct -= (s8)e[5];
        if (pct < 0) return r;
      } else {
        *o++ = r;
        cnt++;
      }
    }
  }
  if (cnt > 0) {
    u32 s = rnd273();
    u64_273 d = func_00312db8((u64_273)(u32)(cnt - 1) + 0x100000000ULL, (u32)cnt);
    return out[(s32)func_00312db8(s, d)];
  }
  return -1;
}
}  // namespace n001affe0

// ---- 001b0148 from src/anon/batch_w12.cpp
namespace n001b0148 {
s32 func_001afee8(s32, s32) asm("func_001afee8");
s32 func_001b0148(s32 x, s32 a, s32 v, s32 b) asm("func_001b0148");
s32 func_001b0148(s32 x, s32 a, s32 v, s32 b) {
    if (v < 0) {
        if (v == -3) return func_001afee8(a, b);
        return -1;
    }
    return v;
}
}  // namespace n001b0148

// ---- 001b0188 from src/anon/tiny_auto80_fptr4.cpp
namespace n001b0188 {
u32 func_001b0188(u32, u32, u32, u32) asm("_Z13func_001b0188jjjj");
u32 func_001b0330(u32, u32, u32, u32) asm("_Z13func_001b0330jjjj");
extern u8 D_00350e78 asm("D_00350e78");
u32 func_001b0188(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0188jjjj");
u32 func_001b0188(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350e78;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001b0330)(u32, u32, u32, u32) = func_001b0330;
    r2 = fp_call4_001b0330(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001b0188

// ---- 001b01b0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001b01b0 {
u32 func_001b0330(u32, u32, u32, u32) asm("_Z13func_001b0330jjjj");
extern u8 D_00350e78 asm("D_00350e78");
u32 func_001b01b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b01b0jjjj");
u32 func_001b01b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00350e78;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_001b0330)(u32, u32, u32, u32) = func_001b0330;
    r2 = fp_call4_001b0330(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001b01b0

// ---- 001b01d8 from src/anon/batch_w11.cpp
namespace n001b01d8 {
extern u32 D_00350e78 asm("D_00350e78");
void func_001b0330(void*) asm("func_001b0330");
void func_00106420(void*) asm("func_00106420");
void func_001b01d8(void** p) asm("func_001b01d8");
void func_001b01d8(void** p) {
    *p = &D_00350e78;
    func_001b0330(p);
    func_00106420(p);
}
}  // namespace n001b01d8

// ---- 001b0210 from src/anon/batch_w13.cpp
namespace n001b0210 {
void func_001b0210(u8* p, s32 a1, s32 a2, s32 a3) asm("func_001b0210");
void func_001b0210(u8* p, s32 a1, s32 a2, s32 a3) {
    if ((*(s32*)(p + 8) < 0 && *(s32*)(p + 16) == 0) || a2 >= *(s32*)(p + 12)) {
        *(s32*)(p + 8) = a1;
        *(s32*)(p + 12) = a2;
        *(s32*)(p + 24) = a3;
    }
}
}  // namespace n001b0210

// ---- 001b0250 from src/anon/batch_w77.cpp
namespace n001b0250 {
struct Obj;
typedef u32 (*MkFn)(Obj*, s32, u32);
struct Obj { void** vt; u32 f4; s32 id; u32 f12; u32 h16; u32 f20; u32 h24; };
void func_001b0330(Obj*) asm("func_001b0330");
s32 func_001b0320(Obj*) asm("func_001b0320");
u32 YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
s32 func_002bc420(u32) asm("func_002bc420");
s32 YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
void func_002bc398(u32, u32) asm("func_002bc398");
void YS__VOICE__exec(Obj* o) asm("YS__VOICE__exec");
void YS__VOICE__exec(Obj* o)
{
    s32 id = o->id;
    if (id >= 0) {
        func_001b0330(o);
        o->h16 = ((MkFn)o->vt[2])(o, id, YS__OBJ__get_pos(o->h24));
        return;
    }
    if (!func_001b0320(o)) return;
    if (func_002bc420(o->h16)) {
        if (o->h24 && YS__OBJ__is_exist(o->h24)) {
            func_002bc398(o->h16, YS__OBJ__get_pos(o->h24));
            return;
        }
        o->h24 = 0;
    } else {
        o->h16 = 0;
        o->h24 = 0;
    }
}
}  // namespace n001b0250

// ---- 001b0320 from src/anon/tiny.cpp
namespace n001b0320 {
u32 func_001b0320(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0320jjjj");
u32 func_001b0320(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (*(u32*)((u32)a0 + (16)) != 0);
}
}  // namespace n001b0320

// ---- 001b0330 from src/anon/batch_w18.cpp
namespace n001b0330 {
u32 func_001b0320(u32, u32, u32, u32) asm("func_001b0320");
void func_002bc358(u32, u32) asm("func_002bc358");
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b0330jjjj");
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32* p = (u32*)a0;
    if (func_001b0320(a0, a1, a2, a3)) {
        func_002bc358(p[4], 0);
        p[4] = 0;
    }
    p[2] = (u32)-1;
}
}  // namespace n001b0330

// ---- 001b0370 from src/anon/tiny_wrappers_more.cpp
namespace n001b0370 {
u32 func_002bc588(u32, u32, u32, u32) asm("_Z13func_002bc588jjjj");
u32 func_001b0370(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0370jjjj");
u32 func_001b0370(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc588(((u32)(*(u32*)((u32)(a0) + 28u))), a1, a2, ((u32)(*(u32*)((u32)(a0) + 20u))));
}
}  // namespace n001b0370

// ---- 001b0390 (gap: wrapper like 0x1b0370)
namespace n001b0390 {
u32 func_002bc688(u32, u32, u32, u32) asm("func_002bc688");
u32 func_001b0390(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b0390");
u32 func_001b0390(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc688(((u32)(*(u32*)((u32)(a0) + 28u))), a1, a2, ((u32)(*(u32*)((u32)(a0) + 20u))));
}
}  // namespace n001b0390

// ---- 001b03b0 from src/anon/auto80_199_queue.cpp
namespace n001b03b0 {
void func_001b03b0(s32 a0, s32 a1) asm("_Z13func_001b03b0ii");
void func_001b03b0(s32 a0, s32 a1) {
    if ((u32)a1 == 0xffffu && a0 == 1) {
        u32* s0 = (u32*)(D_01c90000 + 16528);
        s32 s2 = 2;
        const s32 s1 = -1;
        do {
            s0[0] = 0;
            s2 -= 1;
            func_0031cc28((u32)s0);
            s0[1] = (u32)-1;
            s0[2] = (u32)-1;
            s0 = (u32*)((u8*)s0 + 12);
        } while (s2 != s1);
    }
}
}  // namespace n001b03b0

// ---- 001b0428 from src/anon/tiny_wrappers_more.cpp
namespace n001b0428 {
u32 func_001b03b0(u32, u32, u32, u32) asm("_Z13func_001b03b0jjjj");
u32 func_001b0428(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b0428jjjj");
u32 func_001b0428(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001b03b0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001b0428

// ---- .rodata 0x36d8b0-0x36d960: formats and voice folder names (0x350e04 table)
extern const char R_0036d8b0[8] asm("D_0036d8b0") = "%03d0";
extern const char R_0036d8b8[8] asm("D_0036d8b8") = "reraise";
extern const char R_0036d8c0[8] asm("D_0036d8c0") = "sora";
extern const char R_0036d8c8[8] asm("D_0036d8c8") = "donald";
extern const char R_0036d8d0[8] asm("D_0036d8d0") = "goofy";
extern const char R_0036d8d8[8] asm("D_0036d8d8") = "micky";
extern const char R_0036d8e0[8] asm("D_0036d8e0") = "auron";
extern const char R_0036d8e8[8] asm("D_0036d8e8") = "mulan";
extern const char R_0036d8f0[8] asm("D_0036d8f0") = "aladdin";
extern const char R_0036d8f8[8] asm("D_0036d8f8") = "sparrow";
extern const char R_0036d900[8] asm("D_0036d900") = "beast";
extern const char R_0036d908[8] asm("D_0036d908") = "jack";
extern const char R_0036d910[8] asm("D_0036d910") = "simba";
extern const char R_0036d918[8] asm("D_0036d918") = "tron";
extern const char R_0036d920[8] asm("D_0036d920") = "riku";
extern const char R_0036d928[8] asm("D_0036d928") = "roxas";
extern const char R_0036d930[8] asm("D_0036d930") = "pin";
extern const char R_0036d938[8] asm("D_0036d938") = "us";
extern const char R_0036d940[32] asm("D_0036d940") = "voice/%s/battle/%s%d_%s.vsb";

