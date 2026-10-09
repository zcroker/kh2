#include "../common/types.h"
struct V { f32 x, y, z; u32 w; };
struct E { E* next; u32 idx; u32 mask; u32 z12; u32 z16; };
struct O { u8 pad[76]; E** tbl; };
extern "C" {
extern V D_003a99d0;
extern V D_003a99e0;
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00119b10jjjj");
void func_wt119b10(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff) {
        if (a0 == 1) {
            D_003a99d0.x = -218.0f;
            D_003a99d0.w = 0;
            D_003a99d0.z = 1024.0f;
            D_003a99d0.y = 55.0f;
        }
    }
    if (a1 == 0xffff) {
        if (a0 == 1) {
            D_003a99e0.x = 185.0f;
            D_003a99e0.w = 0;
            D_003a99e0.z = 1024.0f;
            D_003a99e0.y = 125.0f;
        }
    }
}
void* func_00304fb0(void*, u32, u32);
E* f303b70(O* o, u32 idx) asm("_Z16ctarget_00303b70jjjj");
E* f303b70(O* o, u32 idx) {
    E** t = o->tbl;
    if (!t) {
        E** n = (E**)func_00304fb0(o, 4, 16);
        o->tbl = n;
        if (!n) return 0;
        t = n;
    }
    E* e = t[idx];
    if (e) {
        t[idx] = e->next;
    } else {
        u32 m = 1 << idx;
        e = (E*)func_00304fb0(o, 1, (m << 2) + 20);
        if (!e) return 0;
        e->idx = idx;
        e->mask = m;
    }
    e->z16 = 0;
    e->z12 = 0;
    return e;
}
}
