#include "../common/types.h"
extern "C" {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 pad11; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
struct VObj { struct VT { u8 pad[24]; void (*f18)(VObj*, s32, u32, s32, s32, s32, s32); }* vt; };
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
s32 func_00244938(s32);
s32 func_002431d0(s32, s32);
void func_00288d80(void*, s32, s32, s32, u8*, s32, u8*, u8*);
u8* func_002891b8(void*, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_001395f8(u8*);
void func_00139620(u8*);
s32 func_002892f8(void*);
void func_00138c68(u8*, s32, s32);
void func_002891f0(void*, s32, s32, s32, s32);
void func_002449c0(void);
s32 func_002891e8(void*);
s32 func_00244ee8(s32);
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32);
s32 func_00249480(s32);
void func_00249180(void);
void func_00248720(void);
s32 func_001a6d08(s32);
s32 func_00244a10(void);
void func_0028af40(void*, s32);
void func_0028d980(u8*, s32, s32, s32, u8*, s32, s32, s32, s32);
void func_00244a60(void);
VObj* func_00287dc0(void);
void func_0023d808(VObj*, s32);
void func_0023e858(VObj*, s32, f32);
void func_0023e8b8(VObj*, s32, f32);
void func_0023e8d8(VObj*, s32, f32);
s32 func_00139d78(s32);
void func_0023e9b0(VObj*, s32, s32);
void func_0023e690(VObj*, s32, s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_002887c8(void);
void func_00243e30(void);
void func_002488f0(void);
void func_00288750(void (*)(void));
void func_00244058(void);
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ed0c;
extern u8 D_0035ed14;
extern u8* D_0035ecf0;
extern u8* D_0035ecf4;
extern u8* D_0035ecf8;
extern u8* D_0035ecfc;
extern u8* D_0035ed08;
extern void* D_0035ece8;
extern Ent36 D_003719a0[];
extern s16 D_00371968[][3];
extern u8 D_00371960[], D_00371978[], D_00371980[], D_00371988[], D_00371990[], D_00371998[];

static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}

extern u8 D_0035ed68, D_0035ed69;
extern u8* D_0035ed54;
extern u8* D_0035ed58;
extern u8* D_0035ed5c;
extern u8* D_0035ed60;
extern void* D_0035ed4c;
extern Ent36 D_00371d90[];
extern u8 D_00371d80[];
extern s16 D_00371d40[][3];
extern u8 D_00371d38[], D_00371d58[], D_00371d60[], D_00371d68[], D_00371d70[], D_00371d78[];

void func_00248060(void) {
    s32 i, j, ok;
    s32 sel;
    s32 n, w, half;
    u8* o;
    u8* nm;
    u8* nm2;
    VObj* p;
    sel = 0;
    D_0035ed68 = 0;
    D_0035ed54 = NewLayout();
    func_0028d7f0(D_0035ed54, 30002, 0, 0, 30, 32, 0, 0, 0);
    func_0023ef50(D_0035ed54);
    for (i = 0; i < 3; i++) {
        Ent36* e = &D_00371d90[i];
        s8* r;
        ok = 1;
        for (j = 0, r = e->req; j < 4; j++) {
            s32 t = *r++;
            if (t < 0) break;
            if (!func_001a6d08(t)) { ok = 0; break; }
        }
        if (ok) {
            if (func_002431d0(5, i) == 0) D_0035ed69 |= 1 << i;
            if (D_00371d90[i].f10) sel = i;
            nm = (u8*)&D_00371d90[i];
            nm2 = D_00371d90[i].name;
            if (func_00249480(i) == 0) {
                nm = D_00371d80;
                nm2 = D_00371d80 + 8;
            }
            func_00288d80(D_0035ed4c, i, 0, 0, D_0035ed54, D_00371d90[i].f12, nm, nm2);
            o = func_002891b8(D_0035ed4c, i);
            p = (VObj*)func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90((s32)p);
            *(s32*)(o + 428) = func_0028ddd8((s32)p);
            func_001395f8(o);
        }
    }
    i = 0;
    n = func_002892f8(D_0035ed4c);
    w = func_0023aa78(func_002891b8(D_0035ed4c, 0) + 24);
    half = (w * n) / 2;
    for (; i < n; i++) {
        func_00138c68(func_002891b8(D_0035ed4c, i), 0, -half + w * i);
    }
    func_002891f0(D_0035ed4c, sel, 0, -1, -1);
    func_00249180();
    sel = func_002891e8(D_0035ed4c);
    func_002891f0(D_0035ed4c, sel, 1, 0, 2);
    func_002b4070(D_0035ed60, 30003, D_0035ed54, D_00371d38, D_00371d58, D_00371d60, D_00371d68, D_00371d70, D_00371d78, 4585, &D_00371d90[sel], 0, 0);
    D_0035ed5c = NewLayout();
    func_0028d7f0(D_0035ed5c, 30002, 0, 0, D_00371d40[sel][0], D_00371d40[sel][2], 0, 0, 0);
    func_0023ef50(D_0035ed5c);
    D_0035ed58 = NewLayout();
    func_0028d7f0(D_0035ed58, 30019, 0, 0, 33, 35, 0, 0, 0);
    func_0023ef50(D_0035ed58);
    p = func_00287dc0();
    func_0023d808(p, 30008);
    p->vt->f18(p, 0, 0x2000043f, 134, 2, 184, 441);
    func_0023e858(p, 0, -345.0f);
    func_0023e8b8(p, 0, 8.0f);
    func_0023e8d8(p, 0, 32.0f);
    {
        u8* s = D_0035ed60;
        func_00139d78(*(s32*)(s + 8));
        s32 x = *(s32*)(s + 8);
        func_0023e9b0(p, 0, x);
    }
    func_0023e690(p, 0, 135, 136);
    func_00287bd0(0, 0);
    func_00287cc0(0);
    if (func_002887c8()) {
        func_00248720();
        D_0035ed68 = 1;
        func_00288750(func_002488f0);
    }
}
}
