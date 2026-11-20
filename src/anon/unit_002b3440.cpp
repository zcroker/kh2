// Linked unit (see linked_units.tsv).
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002b3440 (was src/anon/batch_w3808_nsa.cpp)
namespace n002b3440 {
// 002b3440: per-row bitsets of slots taken by entries; frees slots the data already uses,
// then shuffles the free slots (rand) and assigns them to the row's entries.
struct B3440 {
    u32 w[2];
    B3440() { w[0] = 0; w[1] = 0; }
    void clear() { w[0] = 0; w[1] = 0; }
    u32 test(s32 b) { return w[(u32)b >> 5] & (1 << (b & 31)); }
    void set(s32 b) { u32* p = &w[(u32)b >> 5]; *p |= 1 << (b & 31); }
    void reset(s32 b) { w[(u32)b >> 5] &= ~(1 << (b & 31)); }
};
struct E3440 { u8 b0; u8 b1; };
struct H3440 { u8 pad[8]; s32 n; };
u8* func_002a9d68(void) asm("func_002a9d68");
H3440* func_00294000(s32) asm("func_00294000");
E3440* func_001d9e30(E3440*) asm("func_001d9e30");
s32 func_001d9d48(E3440*) asm("func_001d9d48");
s32 func_002b3ac8(s32) asm("func_002b3ac8");
u32 func_001064a8(s32) asm("func_001064a8");
/*TARGET 002b3440*/
void func_002b3440(void) asm("func_002b3440");
void func_002b3440(void) {
    B3440 rows[10];
    B3440 used;
    s32 list[48];
    E3440* ptrs[48];
    u8* data;
    H3440* h;
    u8* q;
    E3440* e;
    s32 i;
    s32 j;
    s32 cnt;
    s32 n;
    s32 m;
    s32 lt2;
    s32 t;
    B3440* u;

    data = func_002a9d68();
    h = func_00294000(9);
    q = (u8*)h + 16;
    for (i = 0; i < 10; i++) rows[i].clear();
    e = 0;
    while ((e = func_001d9e30(e)) != 0) {
        if (func_001d9d48(e)) rows[e->b0].set(e->b1);
    }
    for (i = 0; i < h->n; i++) {
        s8* p = (s8*)(data + i * 192 + 488);
        for (j = 0; j < 48; j++) {
            t = *p;
            p += 4;
            if (t >= 0 && rows[i].test(t)) rows[i].reset(t);
        }
    }
    for (i = 0; i < h->n; i++, q += 16) {
        u = &used;
        u->clear();
        cnt = 0;
        for (j = 0; j < 48; j++) {
            if (rows[i].test(j)) cnt++;
        }
        if (cnt == 0) continue;
        j = 0;
        e = 0;
        while ((e = func_001d9e30(e)) != 0) {
            if (e->b0 != i) continue;
            u = &used;
            if (u->test(e->b1)) continue;
            if (!rows[i].test(e->b1)) continue;
            u->set(e->b1);
            ptrs[j] = e;
            j++;
            if (j >= cnt) break;
        }
        for (j = 0; j < 48; j++) list[j] = 0;
        n = 0;
        t = (s8)(q[1] & 0xf);
        m = func_002b3ac8(t);
        for (j = 0; j < m; j++) {
            if (*(s8*)(i * 192 + (u32)data + 488 + j * 4) < 0) { list[n] = j; n++; }
        }
        lt2 = n < 2;
        for (j = 0; !lt2 && j < 256; j++) {
            u32 a = func_001064a8(-1) % n;
            s32 b = j % n;
            t = list[a];
            list[a] = list[b];
            list[b] = t;
        }
        if (!(q[1] & 0xf0)) {
            for (j = 0; !lt2 && j < cnt; j++) {
                if (list[j] == ptrs[j]->b1) {
                    s32 k;
                    for (k = 0; k < n; k++) {
                        if (j == k) continue;
                        if (list[k] == ptrs[j]->b1) continue;
                        {
                            t = list[j];
                            list[j] = list[k];
                            list[k] = t;
                        }
                        break;
                    }
                }
            }
        }
        for (j = 0; j < cnt; j++) {
            u8* s = (u8*)((i * 48 + list[j]) * 4 + (u32)data + 480);
            s[8] = ptrs[j]->b1;
            if (q[1] & ~0xf) {
                u32 v = func_001064a8(8) & 3;
                s[9] = v;
                if ((s8)s[8] == j && v == 0) s[9] = func_001064a8(8) % 3 + 1;
            } else {
                s[9] = 0;
            }
        }
    }
}
}  // namespace n002b3440

// 002b3908 (puzzle shuffle, was whole asm; matched by L143)
namespace n002b3908 {
u8* func_00294000(s32) asm("func_00294000");
u8* func_002a9d68(void) asm("func_002a9d68");
u32 func_002b3ac8(s32) asm("_ZN2Tz8JmPuzzle12CalcMaxPieceEi");
u32 func_001064a8(s32) asm("func_001064a8");
struct PzEnt { s8 id; u8 kind; u8 pad[14]; };
struct PzTbl { u8 pad[8]; s32 count; u8 pad2[4]; PzEnt e[1]; };
void func_002b3908(s32 sel) asm("func_002b3908");
void func_002b3908(s32 sel)
{
    s32 arr[48];
    PzTbl* t = (PzTbl*)func_00294000(9);
    u8* base = (u8*)func_002a9d68();
    u8* sv;
    PzEnt* e = t->e;
    s32 i;
    PzTbl* t2;
    s32 j;
    t2 = t;
    i = 0;
    // sv is copied from the call result only after the loop guard (do-while inside the if)
    if (0 < t2->count) {
        sv = base;
        do {
            s8 k = e->kind & 0xf;
            if (sel < 0 || e->id == sel) {
                s32 n = func_002b3ac8(k);
                for (j = 0; j < n; j++) arr[j] = n - 1 - j;
                for (j = 0; j < 256; j++) {
                    u32 a = func_001064a8(-1) % n;
                    s32 b = j % n;
                    s32 x = arr[a];
                    arr[a] = arr[b];
                    arr[b] = x;
                }
                // second counter jj (stepped before j) keeps loop.c from sharing j*4 between the arr and piece addresses
                s32 jj = 0;
                for (j = 0; j < n; jj++, j++) {
                    u8* p = sv + 480 + jj * 4;
                    u8 r;
                    p[8] = arr[j];
                    r = (p[9] = func_001064a8(8) & 3);
                    if ((s8)p[8] == j && r == 0) p[9] = func_001064a8(8) % 3 + 1;
                }
            }
            i++;
            sv += 192;
            e++;
        } while (i < t2->count);
    }
}
}  // namespace n002b3908
