// func_0024ce18: smenu layout init (w3968, from coord best w3951/w3937 _mam drafts).
// Compiled with -fmove-all-movables (_mam). Notes:
//  - n is one function-scope variable used for the D_0035edf4 index, the loop-2 half width and a final 0 arg:
//    its later uses make it cse's canonical register, so the copy n = i survives and gives move a1,s4 + movn.
//  - the loop-1 entry pointer is &tbl[i] (giv), so its init sits after the blez guard.
//  - two empty asms in loop 1 and one register pin (0xcb96 in a1 for the stack arg) remain.
#include "../common/types.h"
extern "C" {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; bool on; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
s32 func_002431d0(s32, s32);
void func_00288d80(void*, s32, s32, s32, u8*, s32, void*, u8*);
u8* func_002891b8(void*, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_001395f8(u8*);
void func_00139620(u8*);
void func_00139570(u8*);
s32 func_002892f8(void*);
void func_00138c68(u8*, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
s32 func_002891e8(void*);
void func_002b4070(u8*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32);
s32 func_001a6d08(s32);
void func_0028af40(void*, s32);
void func_0028d980(u8*, s32, s32, s32, u8*, s32, s32, s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_002887c8(void);
void func_00288750(void (*)(void));
s32 func_0024dfe0(void);
Ent36* func_0024e058(void);
void func_0024df90(void);
s16* func_0024e008(s32);
s32 func_0024e080(void);
void func_0024e158(void);
void func_0024d4a0(void);
void func_0024d6b8(void);
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035edf0;
extern s32 D_0035edf4;
extern u8 D_0035edfc;
extern u8* D_0035edd4;
extern u8* D_0035edd8;
extern u8* D_0035eddc;
extern u8* D_0035ede0;
extern u8* D_0035edec;
extern void* D_0035edcc;
extern u8 D_00372158[], D_00372190[], D_00372198[], D_003721a0[], D_003721a8[], D_003721b0[];

static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}
void func_0024ce18(void) {
    s32 i, j, ok;
    s32 sel;
    s32 n, w, half;
    s32 cnt;
    u8* o;
    Ent36* e;
    Ent36* tbl;
    s32 p;
    sel = 0;
    i = 0;
    D_0035edf0 = 0;
    D_0035edd4 = NewLayout();
    func_0028d7f0(D_0035edd4, 30002, 0, 0, 30, 32, 0, 0, 0);
    func_0023ef50(D_0035edd4);
    cnt = func_0024dfe0();
    tbl = func_0024e058();
    for (; i < cnt; i++) {
        s8* r;
        e = &tbl[i];
        o = 0;
        asm("" :: "r"(e));
        asm("" : "+r"(o));
        ok = 1;
        for (j = 0, r = e->req; j < 4; j++) {
            s32 t = *r++;
            if (t < 0) break;
            if (!func_001a6d08(t)) { ok = 0; break; }
        }
        if (ok) {
            n = i; if (D_0035edf4) n = i + 3; if (func_002431d0(0, n) == 0) D_0035edfc |= 1 << i;
            if (e->f10) sel = i;
            func_00288d80(D_0035edcc, i, 0, 0, D_0035edd4, e->f12, e, e->name);
            o = func_002891b8(D_0035edcc, i);
            p = func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90(p);
            *(s32*)(o + 428) = func_0028ddd8(p);
            func_001395f8(o);
        }
        if (!(*(u8*)&e->on & 1)) func_00139570(o);
    }
    i = 0;
    cnt = func_002892f8(D_0035edcc);
    w = func_0023aa78(func_002891b8(D_0035edcc, 0) + 24);
    half = (w * cnt) / 2; n = half;
    for (; i < cnt; i++) {
        func_00138c68(func_002891b8(D_0035edcc, i), 0, w * i - n);
    }
    func_002891f0(D_0035edcc, sel, 0, -1, -1);
    func_0024df90();
    sel = func_002891e8(D_0035edcc);
    func_002891f0(D_0035edcc, sel, 1, 0, 2);
    { register s32 k asm("$5") = 0xcb96; func_002b4070(D_0035edec, 30003, D_0035edd4, D_00372158, D_00372190, D_00372198, D_003721a0, D_003721a8, D_003721b0, k, &tbl[sel], 0, 0); }
    D_0035eddc = NewLayout();
    {
        s16* r = func_0024e008(sel);
        func_0028d7f0(D_0035eddc, 30002, 0, 0, r[0], r[2], 0, 0, 0);
    }
    func_0023ef50(D_0035eddc);
    D_0035edd8 = NewLayout();
    func_0028d7f0(D_0035edd8, 30019, 0, 0, 33, 35, 0, 0, 0);
    func_0023ef50(D_0035edd8);
    if (func_001a6d08(7) && func_0024e080()) {
        func_0028af40(D_0035edcc, 512);
        func_0028d980(D_0035ede0, 30011, 0, 0, D_0035edd4, 31, 33, 2887, 0);
        func_00139620(D_0035ede0);
        func_001395f8(D_0035ede0);
        *(u8*)(D_0035ede0 + 405) = 1;
        { u8* a = D_0035ede0 + 24; *(u32*)(a + 184) |= 8; }
    }
    func_0024e158();
    func_00287bd0(0, 0);
    n = 0;
    func_00287cc0(n);
    if (func_002887c8()) {
        func_0024d4a0();
        D_0035edf0 = 1;
        func_00288750(func_0024d6b8);
    }
}
}
