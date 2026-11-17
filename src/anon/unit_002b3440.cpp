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

