#include "../common/types.h"
extern "C" {

struct W1715_Sub { u8 pad[0xb8]; u32 flags; };
struct W1715_Sprite {
    u8 pad0[0x18];
    W1715_Sub sub;          /* 0x18 */
    u8 pad1[0x195 - 0x18 - 0xbc];
    u8 visible;             /* 0x195 */
    u8 pad2[2];
    s32 text;               /* 0x198 */
    u8 pad3[0x1b0 - 0x19c];
    s32 mode;               /* 0x1b0 */
};
struct W1715_Menu {
    W1715_Sprite title;         /* 0x0 */
    W1715_Sprite frame;         /* 0x1b4 */
    W1715_Sprite icon[8];       /* 0x368 */
    W1715_Sprite label[8];      /* 0x1108 */
    char buf[8][64];            /* 0x1ea8: text lines */
};
struct W1715_Pos { s8 x; s8 pad; s8 y; };

extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_0035f2c4;
extern u8* D_0035f2c8;
extern W1715_Menu* D_0035f2cc;
extern u8 D_0035f2d0;
extern W1715_Pos D_00374360[];
extern u16 D_00374388[];
extern u16 D_00374398[];
extern u16 D_003743a0[];
extern u8 D_003743b0[];
extern u16 D_003743b8[];
extern char D_00374330[];
extern char D_00374338[];
extern char D_00374340[];
void func_002854b0(void);

u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
s32 func_002854c0(void);
s32 func_0023f948(void*, s32);
s32 func_0023f908(void*, s32);
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
void func_0028d980(W1715_Sprite*, s32, s32, s32, u8*, s32, s32, s32, s32);
void func_00139620(W1715_Sprite*);
void func_001395f8(W1715_Sprite*);
s32 func_00192048(u32);
void func_002fde18(void*, s32, s32);
s32 func_0023aa78(W1715_Sub*);
s32 func_0023aa18(W1715_Sub*);
s32 func_0023aa38(W1715_Sub*);
void func_00138c68(W1715_Sprite*, s32, s32);
void func_0028dcc0(W1715_Sprite*, W1715_Sprite*);
u8* func_001058e8(void);
s32 func_00105868(u8*);
void func_00192c90(s32, char*);
s32 func_00192c40(s32, char*);
char* func_00192cc0(char*, const char*, s32);
s32 func_00192b30(char*);
s32 func_00276fd0(void);
f32 func_001e09d0(u8*);
s32 func_002887c8(void);
void func_00284650(void);
void func_00288750(void (*)(void));

static inline void W1715_SetFlag(W1715_Sub* s) { s->flags |= 8; }

void func_002847e0(void)
{
    s32 i, n, best, bi;
    s32 off;
    u16* tbl;
    u8* o = func_0023ee30(0xa0);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    D_0035f2c8 = o;
    best = func_002854c0();
    s32 a = func_0023f948(D_0035f2c4, 0);
    s32 b = func_0023f908(D_0035f2c4, 0);
    func_0028d7f0(D_0035f2c8, 30002, 0, 0, D_00374360[best].x, D_00374360[best].y, a, b, 0);
    func_0023ef50(D_0035f2c8);

    W1715_Sprite* s = &D_0035f2cc->title;
    func_0028d980(s, 30011, 1, 1, D_0035f2c8, 1, 2, -1, 0);
    func_00139620(s);
    func_001395f8(s);
    s->mode = 2;
    s->text = func_00192048(0xcc24);
    s->visible = 1;
    W1715_SetFlag(&s->sub);

    s = &D_0035f2cc->frame;
    func_0028d980(s, 30011, 1, 1, D_0035f2c8, 7, 8, -1, 0);
    func_00139620(s);
    func_001395f8(s);
    s->mode = 2;
    s->text = func_00192048(0xcebf);
    s->visible = 1;
    W1715_SetFlag(&s->sub);

    func_002fde18(D_0035f2cc->buf, 0, 0x200);
    tbl = D_00374388;
    off = 0;
    for (i = 0; i < 8; i++) {
        s = (W1715_Sprite*)((u8*)D_0035f2cc->icon + off);
        func_0028d980(s, 30011, 1, 1, D_0035f2c8, 4, 5, -1, 0);
        s32 h = func_0023aa78(&s->sub);
        s32 x = func_0023aa18(&s->sub);
        s32 y = func_0023aa38(&s->sub);
        func_00138c68(s, 0, h * i);
        func_00139620(s);
        func_001395f8(s);
        s->text = func_00192048(*tbl++);
        s->visible = 1;
        W1715_SetFlag(&s->sub);

        s = (W1715_Sprite*)((u8*)D_0035f2cc->label + off);
        func_0028d980(s, 30012, 1, 1, D_0035f2c8, 10, -1, -1, 0);
        func_0028dcc0(s, (W1715_Sprite*)((u8*)D_0035f2cc->icon + off));
        off += sizeof(W1715_Sprite);
        func_00139620(s);
        func_001395f8(s);
        s->mode = 1;
        func_00138c68(s, x, y);
        s->text = (s32)D_0035f2cc->buf[i];
        s->visible = 1;
        W1715_SetFlag(&s->sub);
    }

    u8* sv = func_001058e8();
    u16* st = (u16*)(sv + 0x3fce);
    char* p = D_0035f2cc->buf[0];
    n = func_00105868(func_001058e8());
    func_00192c90(func_00192048(D_00374398[n]), p);
    p = D_0035f2cc->buf[1];
    func_00192cc0(p, D_00374330, func_00276fd0());
    p = D_0035f2cc->buf[2];
    func_00192cc0(p, D_00374330, (s32)func_001e09d0(func_001058e8() + 0x100e0));
    p = D_0035f2cc->buf[3];
    n = func_00192b30(func_00192cc0(p, D_00374338, st[1]));
    func_00192c90(func_00192048(0xcc20), p + n);
    p = D_0035f2cc->buf[4];
    n = func_00192b30(func_00192cc0(p, D_00374338, *(u16*)(func_001058e8() + 0x3db2)));
    func_00192c90(func_00192048(0xcc20), p + n);

    best = -1;
    bi = 0;
    p = D_0035f2cc->buf[5];
    for (i = 1; i < 7; i++) {
        if (best < st[3 + i]) {
            best = st[3 + i];
            bi = i;
        }
    }
    n = func_00192c40(func_00192048(D_003743a0[bi]), p);
    n += func_00192b30(func_00192cc0(p + n, D_00374340, best));
    func_00192c90(func_00192048(0xcc20), p + n);

    p = D_0035f2cc->buf[6];
    n = func_00192b30(func_00192cc0(p, D_00374338, st[9]));
    func_00192c90(func_00192048(0xcc20), p + n);

    best = -1;
    bi = 0;
    p = D_0035f2cc->buf[7];
    i = 0;
    do {
        u8 c = D_003743b0[i];
        if (best < st[10 + c]) {
            best = st[10 + c];
            bi = c;
        }
    } while (++i < 4);
    n = func_00192c40(func_00192048(D_003743b8[bi]), p);
    n += func_00192b30(func_00192cc0(p + n, D_00374340, best));
    func_00192c90(func_00192048(0xcc20), p + n);

    if (func_002887c8()) {
        func_00284650();
        D_0035f2d0 = 1;
        func_00288750(func_002854b0);
    }
}

}
