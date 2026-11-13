#include "../../common/types.h"
#include <stdarg.h>

// YS::AREADATA (0x181ad0-0x182780): the area data file (ard/<area>.ard): loading, the event
// code dispatcher, the area set-up and the magic cost pool, plus the file's static initialiser
// (the current area id starts as all -1). Each function keeps the declarations of the source it
// was matched in (namespace gN); every symbol is bound by asm label.

// ---- .data (0x34ecc0)
extern "C" {
u64 D_0034ecc0 = 0;
u64 D_0034ecc8 = 0;
s32 D_0034ecd0 = 0;
s32 D_0034ecd4 = 0;
s32 D_0034ecd8 = 0;
s32 D_0034ecdc = 0;
s32 D_0034ece0 = 0;
s32 D_0034ece4 = 0;
s32 D_0034ece8 = 0;
s32 D_0034ecec = 0;
s32 D_0034ecf0 = 0;
void* D_0034ecf4 = 0;
}

// ---- .bss (0x1c60530)
struct Flags3 { u8 a[3]; u8 pad; u16 h[3]; };
extern Flags3 D_01c60530_init asm("D_01c60530");
static inline void AreaIdReset(u16 b) {
    u16* h = D_01c60530_init.h;
    u8* c = D_01c60530_init.a;
    c[1] = b; c[0] = b; c[2] = b;
    h[0] = b; h[1] = b; h[2] = b;
}
struct AREA_ID {
    u8 a[3];
    u16 h[3];
    AREA_ID() { AreaIdReset(0xffff); }
};
static AREA_ID s_area asm("D_01c60530");
static f32 s_costMax asm("D_01c6053c");
static f32 s_cost asm("D_01c60540");
static u64 s_flagsOn asm("D_01c60548");
static u64 s_flagsOff asm("D_01c60550");
static s32 s_light asm("D_01c60558");
static char s_path[40] asm("D_01c60560");

// ---- .rodata
extern "C" const char D_0036c7b8[] = "ard/%s.ard";

// 181ad0
namespace g0 {
struct Name10 { u16 c[5]; };
extern Name10 D_01c60530 asm("D_01c60530");
extern void* D_0034ecf4 asm("D_0034ecf4");
extern char D_0036c7b8[] asm("D_0036c7b8");
s32 func_001051a0(void*, const char*) asm("func_001051a0");
void func_00170c00(void*) asm("func_00170c00");
s32 func_00105140(const char*, s32) asm("func_00105140");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
s32 func_001688c8(const char*) asm("func_001688c8");
void* func_00170b30(s32) asm("func_00170b30");  // alloc_align128
void func_001684c0(const char*, void*, s32, s32) asm("func_001684c0");

// Load a named file into a 2 KB-aligned buffer unless it is already loaded.
void func_00181ad0(const char* name) asm("func_00181ad0");
void func_00181ad0(const char* name) {
    char buf[48];
    if (func_001051a0(&D_01c60530, name)) return;
    if (D_0034ecf4) func_00170c00(D_0034ecf4);
    func_002fee78(buf, D_0036c7b8, func_00105140(name, 0));
    D_0034ecf4 = func_00170b30((func_001688c8(buf) + 2047) & ~2047);  // alloc_align128
    func_001684c0(buf, D_0034ecf4, 0, 0);
    D_01c60530 = *(const Name10*)name;
}
}  // namespace g0

extern "C" {
char* D_0034ecf8 = "menu/";
}

// 181ba0
namespace YS {
class AREADATA {
public:
    void Destroy() asm("_ZN2YS8AREADATA7DestroyEv");
};
void AREADATA::Destroy() {}
}  // namespace YS

// 181ba8 .. 181c28
namespace g1 {
u32 func_00168b88(...) asm("func_00168b88");  // find_entry16_by_half_word

u32 func_00181ba8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00181ba8");
u32 func_00181ba8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r6 = r4;
    r5 = (u32)((s32)0u + (12));
    r7 = 0u;
    r4 = *(volatile u32*)((u32)r15 + (s32)(-4876));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b88)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}

u32 func_00181be8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00181be8");
u32 func_00181be8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r6 = r4;
    r5 = (u32)((s32)0u + (3));
    r7 = 0u;
    r4 = *(volatile u32*)((u32)r15 + (s32)(-4876));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b88)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace g1

// 181c28
namespace g2 {
u32 func_00168b88(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00168b88");
extern u32 D_0034ecf4 asm("D_0034ecf4");

u32 func_00181c28(const s8 *a0) asm("func_00181c28");
u32 func_00181c28(const s8 *a0) {
    s32 c1 = (s32)a0[1];
    s32 d3 = (s32)a0[3];
    s32 e2 = (s32)a0[2];
    c1 <<= 8;
    s32 a2 = (s32)a0[0];
    d3 <<= 24;
    e2 <<= 16;
    a2 |= d3;
    u32 a0v = D_0034ecf4;
    e2 |= c1;
    u32 ret = func_00168b88(a0v, 22, (u32)(a2 | e2), 0);  // find_entry16_by_half_word
    return *(u32 *)(ret + 8);
}
}  // namespace g2

// 181c80 YS::AREADATA::GetEventData
namespace g3 {
u32 func_00168b88(...) asm("func_00168b88");  // find_entry16_by_half_word

u32 func_00181c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_ZN2YS8AREADATA12GetEventDataEj");
u32 func_00181c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r6 = r4;
    r5 = (u32)((s32)0u + (22));
    r7 = 0u;
    r4 = *(volatile u32*)((u32)r15 + (s32)(-4876));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b88)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace g3

// 181cc0 chunk_find
namespace g4 {
void func_00181d30(s16*, s16*, s16*) asm("_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_");

void func_00181cc0(s16* base, s32 id) asm("func_00181cc0");
void func_00181cc0(s16* base, s32 id) {  // chunk_find
    s16* p = base;
    while (*p != -1) {
        s16* n = (s16*)((u8*)p + p[1]);
        if (*p == id) { func_00181d30(base, p + 2, n); return; }
        p = n;
    }
}
}  // namespace g4

// 181d30 YS::AREADATA::SETINDEX::parse
namespace g5 {
u32 func_00181da0(u32 a0, u32 a1) asm("func_00181da0");

void func_00181d30(u32 a0, u32 a1, u32 a2) asm("_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_");
void func_00181d30(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a2;
    u32 s2 = a0;

    if (s0 < s1) {
        do {
            if (func_00181da0(s2, s0) == 0) {
                return;
            }
            s16 off = *(s16 *)(s0 + 2);
            s0 = s0 + ((s32)off << 2) + 4;
        } while (s0 < s1);
    }
}
}  // namespace g5

// 181da0: area event code dispatcher
namespace g6 {
struct W1639Code {
    u16 op;
    s16 n;
    s32 arg[1];
};
extern u64 D_0034ecc0 asm("D_0034ecc0");
extern u64 D_0034ecc8 asm("D_0034ecc8");
extern s32 D_0034ecd0 asm("D_0034ecd0");
extern s32 D_0034ecd4 asm("D_0034ecd4");
extern s32 D_0034ecd8 asm("D_0034ecd8");
extern s32 D_0034ecdc asm("D_0034ecdc");
extern s32 D_0034ece0 asm("D_0034ece0");
extern s32 D_0034ece4 asm("D_0034ece4");
extern s32 D_0034ece8 asm("D_0034ece8");
extern s32 D_0034ecec asm("D_0034ecec");
extern s32 D_0034ecf0 asm("D_0034ecf0");
extern s32 D_0034ecf4 asm("D_0034ecf4");
extern char* D_0034ecf8 asm("D_0034ecf8");
extern u32 D_0034f240 asm("D_0034f240");
extern u32 D_003638d0 asm("D_003638d0");
extern f32 D_01c6053c asm("D_01c6053c");
union W1639Bits { u64 v; s16 h; u8 c; };
extern W1639Bits D_01c60548 asm("D_01c60548");
extern W1639Bits D_01c60550 asm("D_01c60550");
extern s32 D_01c60558 asm("D_01c60558");
extern char D_01c60560[] asm("D_01c60560");
extern char* D_0033caf0 asm("D_0033caf0");
extern char* D_0033caf4 asm("D_0033caf4");
extern u8 D_0032bae0[] asm("D_0032bae0");
extern u8 D_0032bae2 asm("D_0032bae2");

void func_001829b0(s32, s32) asm("func_001829b0");
u64 func_00312db8(u64, u64) asm("func_00312db8");
u8* func_00168b38(s32, s32, s32) asm("func_00168b38");
void func_00182a78(s32) asm("func_00182a78");
void func_00182280(void) asm("func_00182280");
s32 func_001a8bd0(s32) asm("func_001a8bd0");
void func_001a8d40(s32, s32) asm("func_001a8d40");
void func_001a9110(s32*) asm("func_001a9110");
void func_001bb288(s32, s32*) asm("func_001bb288");
s32 strlen(const char*) asm("strlen");
s32 strncmp(const char*, const char*, s32) asm("strncmp");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void func_00170518(char*, s32, s32) asm("func_00170518");
s32 W1639_CheckFlag(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void W1639_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void W1639_ParseIndex(void*, s32*, W1639Code*) asm("_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_");
void func_001ada38(s32) asm("func_001ada38");
s32 func_001d9b40(u8*) asm("func_001d9b40");

s32 func_00181da0(void* self, W1639Code* code) asm("func_00181da0");
s32 func_00181da0(void* self, W1639Code* code)
{
    s32 i;
    switch (code->op) {
    case 0:
        for (i = 0; i < code->n; i++) func_001829b0(code->arg[i], 0);
        break;
    case 1:
        D_0034ecc0 = (u32)code->arg[0] | ((u64)(u32)code->arg[1] << 32);
        break;
    case 2: {
        u32 n = code->n;
        u32 r = D_003638d0 *= 0x10dcd;
        func_001829b0(code->arg[(s32)func_00312db8(r, func_00312db8((u64)(n - 1) + 0x100000000ULL, n))], 0);
        break;
    }
    case 3: {
        u32 r = D_003638d0 *= 0x10dcd;
        if ((u32)(s32)func_00312db8(r, 0x28f5c29) < (u32)code->arg[0]) {
            func_001829b0(code->arg[1], 0);
            return 0;
        }
        break;
    }
    case 4:
        D_01c6053c = (f32)(u32)code->arg[0];
        break;
    case 5:
        D_0034ecd0 = code->arg[0];
        break;
    case 6:
        D_0034ecd8 = code->arg[0];
        break;
    case 7:
        D_0034ecdc = code->arg[0];
        break;
    case 9:
        func_001829b0(code->arg[0], 1);
        break;
    case 10: {
        u8* p = func_00168b38(D_0034ecf4, -1, code->arg[0]);
        if (p && *(s32*)(p + 8)) func_00182a78(*(s32*)(p + 8));
        break;
    }
    case 11:
        D_0034ecc8 = (u32)code->arg[0] | ((u64)(u32)code->arg[1] << 32);
        break;
    case 12:
        func_00182280();
        break;
    case 14:
        D_0034ece0 = code->arg[0];
        break;
    case 15:
        func_001a8d40(func_001a8bd0(-1), code->arg[0]);
        break;
    case 16:
        func_001a9110(code->arg);
        break;
    case 17:
        D_0034ece4 = code->arg[0];
        break;
    case 18:
        D_0034ecd4 = code->arg[0];
        break;
    case 19:
        D_0034ece8 = code->arg[0];
        break;
    case 20:
        D_0034f240 |= 4;
        break;
    case 21:
        func_001bb288(code->arg[0], &code->arg[1]);
        break;
    case 22: {
        const char* s = (const char*)code->arg;
        if (strncmp(s, D_0034ecf8, strlen(D_0034ecf8)) == 0)
            func_002fee78(D_01c60560, s, D_0033caf0);
        else
            func_002fee78(D_01c60560, s, D_0033caf4);
        func_00170518(D_01c60560, 950, 0);
        break;
    }
    case 23:
        D_0034f240 |= 0x10;
        break;
    case 24:
        D_0034ecec = ((s32*)code)[1];
        D_0034ecf0 = ((s32*)code)[2];
        break;
    case 25:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            if (!W1639_CheckFlag(*(s32*)code)) W1639_SetFlag(*(s32*)code);
        }
        break;
    case 26:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            D_01c60548.v |= (u64)1 << *(s32*)code;
        }
        break;
    case 27:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            D_01c60550.v |= (u64)1 << *(s32*)code;
        }
        break;
    case 28:
        if (code->arg[0] == D_0032bae2)
            W1639_ParseIndex(self, &code->arg[1], (W1639Code*)&code->arg[code->n]);
        break;
    case 29:
        for (i = 0; i < code->n; i++) func_001ada38(code->arg[i]);
        break;
    case 30:
        D_01c60558 = code->arg[0];
        break;
    case 31:
        if (func_001d9b40(D_0032bae0)) {
            func_001829b0(code->arg[0], 0);
            return 0;
        }
        break;
    }
    return 1;
}
}  // namespace g6

// 182280: unit set-up codes
namespace g7 {
struct T182280 { u8 pad[72]; s32 a; s32 b; s32 c; u32 flags; };
T182280* func_00198c28(s32, s32) asm("func_00198c28");
void func_00198e50(T182280*, u32, s32) asm("func_00198e50");
void func_0019ef90_x8227(void*, u8*) asm("func_0019ef90");
void func_00198e40(T182280*, s32) asm("func_00198e40");
void func_00198e48(T182280*, s32) asm("func_00198e48");
void func_00198e60(T182280*, s32, u8*) asm("func_00198e60");

void func_00182280(void* unused, u8* p) asm("func_00182280");
void func_00182280(void* unused, u8* p) {
    u8* end = p + *(s16*)(p + 2) * 4 + 4;
    T182280* o = func_00198c28(*(s16*)(p + 4), *(s16*)(p + 6));
    p += 8;
    while (p < end) {
        switch (*(u16*)p) {
        case 0:
            func_00198e50(o, *(u32*)(p + 4), *(s16*)(p + 2));
            p += 8;
            break;
        case 1:
            func_0019ef90_x8227((u8*)o + 52, p + 4);
            p += 16;
            break;
        case 2:
            func_00198e40(o, *(s16*)(p + 2));
            p += 4;
            break;
        case 3:
            func_00198e48(o, *(s16*)(p + 2));
            p += 4;
            break;
        case 4:
            o->a = *(s16*)(p + 2);
            p += 4;
            break;
        case 5:
            o->b = *(s16*)(p + 2);
            p += 4;
            break;
        case 6:
            func_00198e60(o, *(s16*)(p + 2), p + 4);
            p = p + *(s16*)(p + 2) * 4 + 4;
            break;
        case 7:
            o->c = *(s16*)(p + 2);
            p += 4;
            break;
        case 8:
            o->flags |= 1;
            p += 4;
            break;
        }
    }
}
}  // namespace g7

// chunk ids of the three area parts
extern "C" const char D_0036c878[8] = "map";
extern "C" const char D_0036c880[8] = "btl";
extern "C" const char D_0036c888[8] = "evt";

// 1823d0: area set-up
namespace g8 {
extern s32 D_0034ecd0 asm("D_0034ecd0");
extern s32 D_0034ecd4 asm("D_0034ecd4");
extern s32 D_0034ecec asm("D_0034ecec");
extern s32 D_0034ecf0 asm("D_0034ecf0");
extern s32 D_0034ece4 asm("D_0034ece4");
extern s64 D_0034ecc0 asm("D_0034ecc0");
extern s64 D_0034ecc8 asm("D_0034ecc8");
extern s32 D_0034ecdc asm("D_0034ecdc");
extern s32 D_0034ecd8 asm("D_0034ecd8");
extern s32 D_0034ece8 asm("D_0034ece8");
extern s32 D_0034ece0 asm("D_0034ece0");
extern u32 D_0034ecf4 asm("D_0034ecf4");
extern f32 D_01c6053c asm("D_01c6053c");
extern s32 D_01c60540 asm("D_01c60540");
extern s64 D_01c60548 asm("D_01c60548");
extern s64 D_01c60550 asm("D_01c60550");
extern s32 D_01c60558 asm("D_01c60558");
extern const char D_0036c878[] asm("D_0036c878");
extern const char D_0036c880[] asm("D_0036c880");
extern const char D_0036c888[] asm("D_0036c888");
extern u8 D_0034f250[] asm("D_0034f250");
extern u8 D_0034fa78[] asm("D_0034fa78");
void func_00182df0(void) asm("func_00182df0");
u8* func_00168b88(u32, s32, u32, s32) asm("func_00168b88");  // find_entry16_by_half_word
void func_00181cc0(u32, u16) asm("func_00181cc0");
void func_001955a8(void*, s32) asm("func_001955a8");
void func_001c0a00(s32) asm("func_001c0a00");
#define FCC_3d0(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
void func_001823d0(u16* p) asm("func_001823d0");
void func_001823d0(u16* p)
{
    u8* e;
    D_0034ecd0 = 0;
    D_01c6053c = 10000.0f;
    D_0034ecd4 = 0;
    D_0034ecec = 0;
    D_0034ecf0 = 0;
    D_0034ece4 = -1;
    D_0034ecc0 = -1;
    D_0034ecc8 = 0;
    D_01c60540 = 0;
    D_0034ecd8 = 3;
    D_0034ecdc = 4;
    D_0034ece0 = 0;
    D_0034ece8 = 0;
    D_01c60548 = 0;
    D_01c60550 = 0;
    D_01c60558 = 0;
    func_00182df0();
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c878), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[0]); }
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c880), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[1]); }
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c888), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[2]); }
    if (!D_0034ecd0) D_0034ecd0 = 0x280000;
    if (!D_0034ecd4) D_0034ecd4 = 0x100000;
    if (!D_0034ecec) D_0034ecec = 0x80000;
    if (!D_0034ecf0) D_0034ecf0 = 0x20000;
    bool big = p[0] >= 51;
    if (big) {
        D_0034ecd8 = 0;
        D_0034ecdc = 0;
    }
    func_001955a8(D_0034f250, D_0034ecd8);
    func_001955a8(D_0034fa78, D_0034ecdc);
    func_001c0a00(D_01c60558);
    D_0034ecc0 = (D_0034ecc0 | D_01c60548) & ~D_01c60550;
}
#undef FCC_3d0
}  // namespace g8

// 182690 YS::AREADATA::CanAddCost
namespace g9 {
f32 func_001826e0() asm("func_001826e0");

u32 func_00182690(f32 f12) asm("_ZN2YS8AREADATA10CanAddCostEf");
u32 func_00182690(f32 f12) {
    f32 f20 = f12;
    if (f20 <= func_001826e0()) {  // global_float_diff
        return 1u;
    }
    return 0u;
}
}  // namespace g9

// 1826c8 YS::AREADATA::AddCost
namespace g10 {
extern u8 D_01c60540 asm("D_01c60540");

void func_001826c8(f32 f12) asm("_ZN2YS8AREADATA7AddCostEf");
void func_001826c8(f32 f12) {
    f32 f0 = *(f32*)((u32)&D_01c60540 + (s32)(0));
    f0 = (f32)(f0 + f12);
    *(f32*)((u32)&D_01c60540 + (s32)(0)) = f0;
}
}  // namespace g10

// 1826e0: cost left
namespace g11 {
extern f32 D_01c6053c asm("D_01c6053c");
extern f32 D_01c60540 asm("D_01c60540");

f32 func_001826e0() asm("func_001826e0");
f32 func_001826e0() {  // global_float_diff
    return D_01c6053c - D_01c60540;
}

// 1826f8: cost used / cost max
f32 func_001826f8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001826f8");
f32 func_001826f8(u32, u32, u32, u32, u32, u32, u32, u32) {
    return D_01c60540 / D_01c6053c;
}
}  // namespace g11
