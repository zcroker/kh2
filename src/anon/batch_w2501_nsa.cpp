// w2501: matches only with -fno-strict-aliasing.
#include "../common/types.h"
struct Item { u8 a[6]; s8 on; u8 b; };
struct Grp { u16 id; u16 x; s8 sel; s8 cnt; s8 flag; u8 pad; s32 off; };
struct Tab { u8 pad[8]; s32 n; u8 pad2[4]; Grp g[1]; };
struct Dst { s8 count; u8 p1; s8 sel; u8 pad[77]; Item items[1]; };
extern "C" {
s8* func_00276568(void);
Tab* func_00294000(s32);
s32 func_00294408(Grp*);
extern Dst* D_0035f5d4;
}
extern "C" {
void func_002a18d0(s32 all, s32 sel) {
    if (!all) {
        if (sel < 0) sel = *func_00276568();
    } else sel = 16;
    D_0035f5d4->sel = sel;
    s32 found = 0;
    s32 idx = -1;
    s32 i = 0;
    s32 j;
    s32 n;
    Item* it;
    Tab* t = func_00294000(5);
    Grp* g = t->g;
    for (; i < t->n; i++) {
        if (g[i].sel != sel) {
            if (found) break;
            continue;
        }
        if (!found) found = 1;
        if (g[i].flag) continue;
        if (!func_00294408(&g[i])) break;
        idx = i;
    }
    n = 0;
    Grp* q = (Grp*)(idx * 12 + (u32)g);
    it = (Item*)((u8*)t + q->off);
    for (j = 0; j < g[idx].cnt; j++) {
        if (it[j].on) D_0035f5d4->items[n++] = it[j];
    }
    found = 0;
    for (i = 0; i < t->n; i++) {
        if (g[i].sel != sel) {
            if (found) break;
            continue;
        }
        if (!found) found = 1;
        if (!g[i].flag) continue;
        if (!func_00294408(&g[i])) continue;
        it = (Item*)((u8*)t + g[i].off);
        for (j = 0; j < g[i].cnt; j++) {
            if (it[j].on) D_0035f5d4->items[n++] = it[j];
        }
    }
    D_0035f5d4->count = n;
}
}
