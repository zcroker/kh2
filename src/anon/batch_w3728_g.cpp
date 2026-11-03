#include "../common/types.h"
extern "C" {
u32 func_00257770();
u32 func_00257070(s32);
u32 func_002891b8(u32, s32);
s32 func_00192048(u32);
void func_00288f60(u32, s32, s16*, s16*);
void func_00138c10(u32, s32);
void func_00138c68(u32, s32, s32);
s32 func_0023aa78(u32);
s32 func_0023aa98(u32);
void func_0028dcc0(u32, u32);
s32 func_00286418(s32);
s32 func_002864f8(s32);
enum Slot { SLOT0 };
struct Item6 { u16 id; u16 pad; s16 c; };
struct Col4 { u16 a; u16 v; };
extern Item6 D_00373530[];
extern Item6 D_003735a8[];
extern Item6 D_00373620[];
extern Col4 D_00373500[];
extern u32 D_0035f01c, D_0035f020, D_0035f0e4;
extern s32 D_0035ef6c;
extern s32 D_003734f8, D_003734fc;

void func_00266248(void) {
    s16 cols[4];
    u32 tbl[2];
    u32 kind;
    u32 base;
    u32* pt;
    s32 i;
    base = func_00257770();
    *(u64*)tbl = 0;
    kind = func_00257070(23);
    switch (kind) {
    case 0: case 7: case 8: case 9:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_00373530 + i * 10);
        break;
    case 1: case 2: case 3: case 4: case 5:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_003735a8 + i * 10);
        break;
    case 6:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_00373620 + i * 10);
        break;
    }
    pt = tbl;
    for (i = 0; i < 2; i++, pt++) {
        u32 sel = i ? D_0035f020 : D_0035f01c;
        s32 n = 0;
        s32 j;
        for (j = 0; j < 10; j++) {
            s32 idx = i * 10 + j;
            if (*(u32*)(D_0035f0e4 + 0x18) & (1 << idx)) {
                u32 item = func_002891b8(sel, n);
                *(u32*)(item + 0x198) = func_00192048(((Item6*)*pt)[j].id);
                // colour table base: lui before the store above, addiu after it, as in the original
                register u32 hi asm("$15");
                asm ("lui %0,%%hi(D_00373500)" : "=r"(hi));
                register Col4* ctab asm("$11");
                asm volatile("addiu %0,%1,%%lo(D_00373500)" : "=r"(ctab) : "r"(hi));
                // cursor pinned to t4 and fenced so its init issues before the pt reload, as in the original
                register s16* cp asm("$12") = cols;
                asm volatile("" : "+r"(cp));
                s32 k;
                for (k = 3; k >= 0; k--) { *cp = ctab[((Item6*)*pt)[j].c].v; cp++; }
                func_00288f60(sel, n, cols, cols);
                func_00138c10(item, cols[0]);
                s32 y = func_0023aa98(item + 0x18);
                func_00138c68(item, i * y, n * func_0023aa78(item + 0x18));
                func_0028dcc0(base + idx * 0x1B4 + 0x5EF0, item);
                u32 fade = base + idx * 0x198 + 0x87D0;
                func_0028dcc0(fade, item);
                func_00138c10(fade, D_0035ef6c);
                if (i != 0 && kind == 6) {
                    register s32 m asm("$17");   // s1 in the original
                    switch ((Slot)idx) {
                    case 10: m = 5; break;
                    case 11: m = 6; break;
                    case 12: m = 7; break;
                    default: m = 8; break;
                    }
                    if (func_00286418(m)) {
                        func_00138c10(base + idx * 0x198 + 0x87D0, func_002864f8(m) ? D_003734fc : D_003734f8);
                    }
                }
                n++;
            }
        }
        for (j = n; j < 10; j++) {
            u32 item = func_002891b8(sel, j);
            func_00138c10(item, D_0035ef6c);
            *(u32*)(item + 0x198) = 0;
        }
        for (j = 0; j < 10; j++) {
            if (!(*(u32*)(D_0035f0e4 + 0x18) & (1 << (i * 10 + j)))) {
                u32 p1 = base + (i * 10 + j) * 0x1B4 + 0x5EF0;
                u32 p2 = base + (i * 10 + j) * 0x198 + 0x87D0;
                func_00138c10(p1, D_0035ef6c);
                *(u32*)(p1 + 0x198) = 0;
                u32 item = func_002891b8(sel, j);
                func_0028dcc0(p1, item);
                func_0028dcc0(p2, item);
            }
        }
    }
}
}
