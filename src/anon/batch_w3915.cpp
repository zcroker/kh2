#include "../common/types.h"

// 002986e0: register pins (i in s0, a in s7, the loop count in t7)
// and one empty asm tie reproduce the original allocation; see coord/asm_review.tsv.
extern "C" {
struct Cnt { s32 n; s16 id[1]; };
u8* func_00276348(void);
u8* func_002766d0(void);
void func_00288e88(s32);
void func_00276690(s32);
void func_00298fe8(s32);
void func_00276e78(void);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_001395f8(u8*);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(s32, s32);
s32 func_002983d8(s32);
void func_00294348(s32);
s32 func_0028af88(s32);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
void func_00298e48(void);
void func_00299260(void);
void func_00287cc0(s32);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f200;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s8 D_0035f5a0;
extern Cnt* D_0035f598;

void func_002986e0(void) {
    struct { s16 arr[2][4]; u32 attr; } L;
    register s32 i asm("$16");
    register u8* a asm("$23"); u8* b;
    a = func_00276348();
    b = func_002766d0();
    func_00288e88(D_0035f200);
    func_00276690(1);
    func_00298fe8(D_0035f5a0);
    for (i = 0; i < 2; i++) {
        for (s32 j = 0; j < 4; j++) L.arr[i][j] = 87;
    }
    u8* c = b + 0xd30;
    i = D_0035f3d4 - 1; asm("" : "+r"(i));
    L.attr = 0x60000000;
    func_00276e78();
    func_0028d8c0(b, i, D_0035f14c, D_0035f148, D_0035f210, 86, -1, 0);
    L.attr |= 8;
    func_00139620(b);
    func_0028dcc0(b, a);
    func_0028d980(c, i, D_0035f14c, D_0035f148, D_0035f210, 88, -1, -1, 0);
    func_00139620(c);
    func_0028dcc0(c, a);
    *(s32*)(c + 0x1ac) = 3;
    *(u32*)(c + 0x1a4) = L.attr;
    func_001395f8(c);
    func_00288d80(D_0035f200, 0, D_0035f14c, D_0035f148, D_0035f210, -1, L.arr[0], L.arr[1]);
    func_00139620(func_002891b8(D_0035f200, 0));
    func_0028dcc0(func_002891b8(D_0035f200, 0), b);
    *(s32*)(func_002891b8(D_0035f200, 0) + 0x1ac) = 3;
    *(u32*)(func_002891b8(D_0035f200, 0) + 0x1a4) = L.attr;
    func_001395f8(func_002891b8(D_0035f200, 0));
    for (i = 0; ({ register s32 n asm("$15") = D_0035f598->n; i < n; }); i++) func_00294348(func_002983d8(D_0035f598->id[i]));
    func_0028af18(D_0035f200, func_0028af88(D_0035f200) | 0xc000);
    func_0028af28(D_0035f200, 16);
    func_00298e48();
    func_00299260();
    func_00287cc0(0);
}
}

extern "C" {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 pad11; u16 f12; u8 pad14[16]; };
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
Ent36* func_00246868(void);
s32 func_00246968(s32);
s32 func_00246840(void);
s32 func_002431d0(s32, s32);
void func_00288d80_b(void*, s32, s32, s32, u8*, s32, Ent36*, u8*) asm("func_00288d80");
u8* func_002891b8_b(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
s32 func_002892f8(void*);
void func_00138c68(u8*, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_002467f0(void);
s32 func_002891e8(void*);
s32 func_002469a0(s32);
s16* func_002468a0(s32);
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32);
s32 func_00246a08(void);
void func_0028af40(void*, s32);
void func_0028d980_b(u8*, s32, s32, s32, u8*, s32, s32, s32, s32) asm("func_0028d980");
void func_00246ab8(void);
void func_00247198(void);
void func_00247580(s32);
void func_00245968(void);
void func_00287bd0(s32, s32);
s32 func_002887c8(void);
void func_00245be8(void);
void func_00245dc0(void);
void func_00288750(void (*)(void));
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_0035ed20;
extern u8* D_0035ed28;
extern u8* D_0035ed2c;
extern u8* D_0035ed30;
extern void* D_0035ed38;
extern u8 D_0035ed3c;
extern u8* D_0035ed40;
extern u8 D_0035ed44;
extern u8 D_00371ad0[];
extern u8 D_00371b08[];
extern u8 D_00371b10[];
extern u8 D_00371b18[];
extern u8 D_00371b20[];
extern u8 D_00371b28[];

static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}

// 00245488: pure C++ (-O2). Loop 1 keeps the func_0023aa98 result in its own pointer p, and
// the tail block uses its own local, which gives the original register copies before loop 2.
void func_00245488(void) {
    s32 i;
    s32 n;
    s32 sel;
    s32 w;
    s32 half;
    s32 k;
    u8* o;
    u8* p;
    Ent36* tbl;

    sel = 0;
    k = 0;
    tbl = func_00246868();
    D_0035ed3c = 0;
    D_0035ed28 = NewLayout();
    func_0028d7f0(D_0035ed28, 30002, 0, 0, 30, 32, 0, 0, 0);
    func_0023ef50(D_0035ed28);
    for (i = 0; i < 4; i++) {
        if (func_00246968(i)) {
            if (func_002431d0(4, func_00246840() ? i + 4 : i) == 0) D_0035ed44 |= 1 << i;
            if (tbl[i].f10) sel = i;
            func_00288d80_b(D_0035ed20, k, 0, 0, D_0035ed28, tbl[i].f12, &tbl[i], tbl[i].name);
            o = func_002891b8_b(D_0035ed20, k++);
            p = (u8*)func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90((s32)p);
            *(s32*)(o + 428) = func_0028ddd8((s32)p);
            func_001395f8(o);
        }
    }
    func_002892f8(D_0035ed20);
    n = func_002892f8(D_0035ed20);
    w = func_0023aa78(func_002891b8_b(D_0035ed20, 0) + 24);
    half = (w * n) / 2;
    for (i = 0; i < n; i++) {
        func_00138c68(func_002891b8_b(D_0035ed20, i), 0, i * w - half);
    }
    func_002891f0(D_0035ed20, sel, 0, -1, -1);
    func_002467f0();
    sel = func_002891e8(D_0035ed20);
    func_002891f0(D_0035ed20, sel, 1, 0, 2);
    half = func_002469a0(sel);
    func_002b4070(D_0035ed38, 30003, D_0035ed28, D_00371ad0, D_00371b08, D_00371b10, D_00371b18, D_00371b20, D_00371b28, 0xcb96, &tbl[half], 0, 0);
    D_0035ed30 = NewLayout();
    {
        s16* pp = func_002468a0(half);
        func_0028d7f0(D_0035ed30, 30002, 0, 0, pp[0], pp[2], 0, 0, 0);
    }
    func_0023ef50(D_0035ed30);
    D_0035ed2c = NewLayout();
    func_0028d7f0(D_0035ed2c, 30019, 0, 0, 33, 35, 0, 0, 0);
    func_0023ef50(D_0035ed2c);
    if (func_00246a08()) {
        func_0028af40(D_0035ed20, 512);
        u8* t = D_0035ed40;
        func_0028d980_b(t, 30011, 0, 0, D_0035ed28, 77, 78, 3971, 0);
        func_00139620(t);
        func_001395f8(t);
        t[405] = 1;
        {
            u8* q = t + 24;
            *(u32*)(q + 184) |= 8;
        }
    }
    func_00246ab8();
    func_00247198();
    func_00247580(1);
    func_00245968();
    func_00287bd0(0, 0);
    func_00287cc0(0);
    n = func_002887c8();
    if (n) {
        func_00245be8();
        D_0035ed3c = 1;
        func_00288750(func_00245dc0);
    }
}
}
