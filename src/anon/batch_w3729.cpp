#include "../common/types.h"
struct NodeW { u8 p0[0xf]; s8 b0f; u8 p10[0xeb - 0x10]; u8 beb; NodeW* next; NodeW* child; NodeW* pad2; u32 flags; u8 pfc[0x10e - 0xfc]; u8 st[0xe]; u16 idx; };
struct TblW { u32 on:1; u32 rest:31; u32 pad; };
struct GrpW { u32 a; f32 time; NodeW* list[(0x360 - 8) / 4]; union { s32 n; f32 f; } num; u8 pad[0x370 - 0x364]; };
struct MgrW {
    u8 pad[0xc50]; s32 map[4]; GrpW grp[15]; u8 pad1[0x4364 - 0xc60 - 15 * 0x370];
    TblW tbl[(0x536c - 0x4364) / 8]; s32 cur;
};
union NumW { s32 n; f32 f; };
struct Sub2W { u8 p[14]; u8 st; void set(u8 v) { st = v; } };
extern "C" {
// Adds node n (and recursively its children) to the manager's current group when it is flagged and enabled.
// Register pins and one empty asm (w3729) fix the t6/t7 choice and the count-block order.
void func_00147c78(MgrW*, NodeW*);
void func_00147d80(MgrW* m, NodeW* n, f32 t)
{
    u16 idx = n->idx;
    if ((n->flags & 4) && ((TblW*)((u32)m + (idx << 3) + 0x4364))->on) {
        if (n->beb) {
            s32 k = m->map[m->cur];
            func_00147c78(m, n);
            n->b0f = -128;
            u32 o = k * 0x370 + (u32)m; GrpW* g = (GrpW*)(o + 0xc60); g->time = t; NumW* c = (NumW*)(o + 0xfc0); s32 i = c->n;
            u32 a = (i << 2) + (u32)g;
            s32 j = i + 1;
            asm("" : "+r"(j) : "r"(a));
            c->n = j; *(NodeW**)(a + 8) = n;
        }
        register s32 cur asm("$14") = m->cur;
        register s32 two asm("$15") = 2;
        ((Sub2W*)(cur + (u32)n + 0x100))->set(two);
    }
    NodeW* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_00147d80(m, c, t);
}
}
