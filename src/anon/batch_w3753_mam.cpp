// w2458: 0 diffs (c.sh, branch offsets checked) with OPT='-O2 -fmove-all-movables'; 18 diffs at plain -O2/-g/nsa.
// Only blocker: loop.c rejects hoisting HIGH(D_0035f0e4) out of loop 1 (life 1, 83 insns, 'not desirable'); the
// original hoisted+spilled it, which shifts reload's spill-reg rotation (t5/t6/t7). Needs a *_mam build rule (-fmove-all-movables).
#include "../common/types.h"
extern "C" {
struct Info28 { u8 pad[28]; u16 mask; };
extern Info28* D_0035f0e4;
extern u8 D_0035f0e8;
extern s32 D_0035f3d4;
extern u32 D_0035f01c;
extern u32 D_0035f03c;
extern u32 D_0035ef64;
extern u32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_003734f8;
extern s32 D_003734fc;
u8* func_00257770(void);
void func_00267320(void);
void func_0028f4d8(s32, s32, s32);
void func_00266c90(void);
s32 func_00257100(s32);
s32 func_00257118(s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s32, s32);
u8* func_002891b8(u32, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00138c68(u8*, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
s32 func_0028afa8(u32);
s32 func_00267408(s32);
s32 func_002670a0(s32);
s32 func_00286418(s32);
s32 func_002864f8(s32);
s32 func_00192048(s32);
void func_00138c10(u8*, s32);
s32 func_00257070(s32);
s32 func_002670f8(s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002653a0(void);
void func_002657a8(void);
void func_00266988(void);
void func_002666a8(void);
void func_00287cc0(s32);
void func_002644a0(u8 flag)
{
    s32 saved;
    u8* base = func_00257770();
    if (flag) func_00267320();
    func_0028f4d8(0, -1, 0);
    s32 y = 0;
    s32 n = 0;
    s32 f;
    func_00266c90();
    s32 i;
    u8* o;
    saved = D_0035f3d4;
    u8* w = base + 0x87d0;
    D_0035f3d4 = 30015;
    for (i = 0; i < 10; i++) {
        if (((D_0035f0e4->mask >> i) ^ 1) & 1) continue;
        s32 t, b;
        if (i == 0 || i >= 7) {
            t = func_00257100(0);
            b = func_00257100(1);
        } else {
            t = func_00257118(0);
            b = func_00257118(1);
        }
        func_00288d80(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, -1, t, b);
        o = func_002891b8(D_0035f01c, n);
        n++;
        s32 h = func_0023aa98(o + 24);
        func_00138c68(o, 0, y);
        y += h;
        func_00139620(o);
        func_001395f8(o);
        func_0028d8c0(w, 30017, D_0035ef68, D_0035ef64, D_0035f03c, D_0035ef6c, -1, 0);
        func_0028dcc0(w, o);
        s32 x = func_0023aa18(o + 24);
        func_00138c68(w, x, func_0023aa38(o + 24));
        w += 408;
    }
    D_0035f3d4 = saved;
    n = func_0028afa8(D_0035f01c);
    for (i = 0; i < n; i++) {
        o = func_002891b8(D_0035f01c, i);
        s32 r = -1;
        s32 id = func_00267408(i);
        switch (func_002670a0(i)) {
        case 1:
            if (func_00286418(0)) r = func_002864f8(0) ? D_003734fc : D_003734f8;
            break;
        case 2:
            if (func_00286418(1)) r = func_002864f8(1) ? D_003734fc : D_003734f8;
            break;
        case 3:
            if (func_00286418(2)) r = func_002864f8(2) ? D_003734fc : D_003734f8;
            break;
        case 4:
            if (func_00286418(3)) r = func_002864f8(3) ? D_003734fc : D_003734f8;
            break;
        case 5:
            if (func_00286418(4)) r = func_002864f8(4) ? D_003734fc : D_003734f8;
            break;
        case 6: {
            s32 t;
            f = 0;
            for (t = 5; t < 9; t++) {
                if (func_00286418(t)) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                f = 0;
                for (t = 5; t < 9; t++) {
                    if (func_00286418(t) && !func_002864f8(t)) {
                        f = 1;
                        break;
                    }
                }
                r = f ? D_003734f8 : D_003734fc;
            }
            break;
        }
        case 9:
            break;
        }
        *(s32*)(o + 408) = func_00192048(id);
        if (r >= 0) func_00138c10(base + i * 408 + 0x87d0, r);
    }
    s32 v = func_002670f8(func_00257070(23));
    if (v < 0) v = 0;
    func_002891f0(D_0035f01c, v, 1, 0, 2);
    func_002653a0();
    func_002657a8();
    func_00266988();
    func_002666a8();
    D_0035f0e8 = 0;
    func_00287cc0(0);
}
}
