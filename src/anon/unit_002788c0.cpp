// Linked unit 0x002788c0-0x00278dd0 (menu sprite setup; was whole asm in src/anon/asm_002788c0.s).
#include "../common/types.h"

namespace n002788c0 {
struct Spr { u8 pad[24]; u8 sub[384]; void* link; u8 pad2[20]; s32 flag; };
struct Menu { u8 pad[1632]; Spr spr[60]; };
u8* func_00257770(void) asm("func_00257770");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
s32 Tz__CmAbility__Cur2AbiltyType(void) asm("Tz__CmAbility__Cur2AbiltyType");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
s32 func_0027c3b8(s32) asm("func_0027c3b8");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s32 func_00257140(s32) asm("func_00257140");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, u16*, u16*) asm("Tz__Select__SetItem");
u8* func_002891b8(s32, s32) asm("func_002891b8");
s32 func_0023aa78(void*) asm("func_0023aa78");
void Tz__Select__SetExOffset(s32, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_00138c78(void*, s32*, s32*) asm("func_00138c78");
u8* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void Tz__CmAbility__SetIndiAbilityDefaultPos(void) asm("Tz__CmAbility__SetIndiAbilityDefaultPos");
void func_0027aaa0(void) asm("func_0027aaa0");
s32 func_00283ab8(s32) asm("func_00283ab8");
s32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, s32) asm("func_0028af18");
void Tz__CmTop__CreatePadHelp(s32, s32, s32) asm("Tz__CmTop__CreatePadHelp");
void func_00287cc0(s32) asm("func_00287cc0");
void func_0027b960(void) asm("func_0027b960");
extern u16 D_01e21ee0[2][4] asm("D_01e21ee0");
extern const u16 D_00373e50[] asm("D_00373e50");
extern const s16 D_00373e48[] asm("D_00373e48");
extern const s16 D_00373e30[][3] asm("D_00373e30");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
extern u8* D_0035f230 asm("D_0035f230");

/*TARGET 002788c0*/
// Menu sprite setup: fills the two colour rows, creates the base sprite, the cursor sprites and one
// sprite per list entry (cnt is 4 or 2), then the window.
// The three tables at 0x373e30-0x373e58 are const (.rodata): a read of a const object cannot conflict
// with the 9th-argument store `sw zero,0(sp)`, so the scheduler is free to issue that store first.
void func_002788c0(void) asm("func_002788c0");
void func_002788c0(void) {
    u8* m;
    s32 i, j;
    s32 a, b, x, y;
    s32 id, cnt, v, k, f, r;
    s32 lay, img;
    u8* o;
    i = 0;
    m = func_00257770();
    Menu* M = (Menu*)m;
    func_0028f4d8(2, -1, 0);
    v = Tz__CmAbility__Cur2AbiltyType();
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) D_01e21ee0[i][j] = D_00373e50[v];
    }
    id = D_0035f3d4;
    func_0028d8c0(m, id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373e30[v][0], D_00373e30[v][2], 0);
    id++;
    func_0027aed8(func_002570a0(15), &a, &b);
    k = func_002570a0(16);
    f = *(s8*)(D_0035f230 + k * 8 + 16);
    if (a == 0 && b != 0 && v == 0 && f == 0) {
        cnt = 4;
        if (!func_0027c3b8(k)) goto done;
    }
    cnt = 2;
done:
    func_0028d980(&M->spr[0], id, D_0035ef68, D_0035ef64, D_0035f03c, D_00373e48[v], -1, -1, 0);
    i = 0;
    s32 id1 = id + 1;
    func_00139620(&M->spr[0]);
    func_0028dcc0(&M->spr[0], m);
    r = func_00257140(0);
    func_0028d980(&M->spr[52], id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
    func_0028dcc0(&M->spr[52], &M->spr[0]);
    func_00139620(&M->spr[52]);
    func_001395f8(&M->spr[52]);
    func_0028d980(&M->spr[1], id1, D_0035ef68, D_0035ef64, D_0035f03c, 152, -1, -1, 0);
    func_0028dcc0(&M->spr[1], &M->spr[0]);
    func_00139620(&M->spr[1]);
    func_001395f8(&M->spr[1]);
    x = func_0023aa18(M->spr[0].sub);
    y = func_0023aa38(M->spr[0].sub);
    func_00138c68(&M->spr[1], x, y);
    { Spr* s = &M->spr[1]; s->flag = 1; }
    r = func_00257140(0);
    for (; i < cnt; i++) {
        Tz__Select__SetItem(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, D_01e21ee0[0], D_01e21ee0[1]);
        o = func_002891b8(D_0035f01c, i);
        Tz__Select__SetExOffset(D_0035f01c, i, 0, func_0023aa78(o + 24));
        func_0028dcc0(o, m);
        func_00139620(o);
        if (a == 0 && b != 0 && v == 0 && f == 0 && func_0027c3b8(k) == 0) {
            *(void (**)(void))(o + 436) = func_0027b960;
        }
        func_0028d980(&M->spr[53 + i], id1, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, -1, 0);
        func_0028dcc0(&M->spr[53 + i], o);
        func_00138c78(func_002891b8(D_0035f01c, i), &x, &y);
        func_00139620(&M->spr[53 + i]);
        func_001395f8(&M->spr[53 + i]);
    }
    lay = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    img = func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    s32 t = func_002570f0();
    func_0028bae0(D_0035f04c, id, lay, img, t, cnt, cnt, m, 0);
    Tz__CmAbility__SetIndiAbilityDefaultPos();
    func_0027aaa0();
    if (func_00283ab8(2)) {
        func_0028af18(D_0035f01c, func_0028af88(D_0035f01c) | 0x400);
        Tz__CmTop__CreatePadHelp(0xcbdd, -1, -1);
    }
    func_00287cc0(0);
}
}
