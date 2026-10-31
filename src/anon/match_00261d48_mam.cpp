// 00261d48 w2502: 0 diffs (try harness) ONLY with -fmove-all-movables (-O2 -fmove-all-movables, with or without -fno-strict-aliasing, -g or -g0).
// Keys: func_00261fb8 takes NO argument (fixes jal nop), Slot261* s = &g->b[pos+j] local, pos += n; pos += n & 1;, pos declared before g.
#include "../common/types.h"
extern "C" {
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s16 D_00373240[];
struct Slot261 { u8 pad[408]; u8* ptr; u8 pad2[24]; };
struct G261 { u8 pad[13840]; Slot261 a[24]; Slot261 b[20]; };
struct E261d48 { u16 id; u8 a; u8 b; u16 pad; };
u8* func_00257770(void);
void func_00139d78(u8*);
s32 func_00257140(s32);
s32 func_00257130(void);
s32 func_00257158(u16, u8, s32);
void func_00138c10(u8*, s32);
s32 func_002891e8(s32);
s32 func_00289300(s32);
void func_00261fb8(void);
void func_00261ce8(s32);
s32 func_002827e0(s32, s32);
u8* func_00281f30(s32);
E261d48* func_00281f20(s32);
void func_00261d48(void) {
    s32 cnt[5];
    s32 pos;
    G261* g = (G261*)func_00257770();
    s32 i, j, n, k, sel, c;
    s16 col;
    u8* b;
    E261d48* l;
    func_00139d78((u8*)g);
    c = func_00257140(0);
    for (i = 0; i < 20; i++) {
        func_00138c10((u8*)&g->a[i], D_0035ef6c);
        func_00138c10((u8*)&g->b[i], c);
        g->b[i].ptr = 0;
    }
    sel = func_002891e8(D_0035f01c);
    if (sel >= func_00289300(D_0035f01c)) {
        func_00261fb8();
        return;
    }
    func_00261ce8(sel);
    for (i = 0; i < 5; i++) {
        cnt[i] = func_002827e0(func_00257130(), i);
    }
    pos = 0;
    b = func_00281f30(func_00257130());
    l = func_00281f20(func_00257130());
    k = 0;
    for (i = 0; i < 5; i++) {
        if (i == 1) continue;
        col = D_00373240[i];
        n = cnt[i];
        if (i == 0) n += cnt[1];
        for (j = 0; j < n; j++) {
            if (i == 0) col = (j == 0) ? col : 151;
            func_00138c10((u8*)&g->a[pos + j], col);
            c = func_00257140(0);
            if (i == 4) c = func_00257140(func_00257158(l[k].id, l[k].a, l[k].b != 0));
            Slot261* s = &g->b[pos + j];
            func_00138c10((u8*)s, c);
            s->ptr = b + 16 + k * 80;
            k++;
        }
        pos += n;
        pos += n & 1;
    }
}
}
