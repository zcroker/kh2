#include "../common/types.h"

// 00147ca0: recursive node walk. num/cur volatile reproduce the original's store/load order
// (the list store stays ahead of the count store, the cur load after both). Built -fno-strict-aliasing.
struct NodeW2378 { u8 pad[0xec]; NodeW2378* next; NodeW2378* child; NodeW2378* pad2; u32 flags; u8 pad3[0x11c - 0xfc]; u16 idx; };
struct TblW2378 { u32 on:1; u32 rest:31; u32 pad; };
struct MgrW2378 {
    u8 pad[0x770]; s32 hdr[3]; s32 cnt[3]; u8 pad1[0x794 - 0x788]; f32 time;
    NodeW2378* list[(0xc40 - 0x798) / 4]; volatile s32 num;
    u8 pad2[0x4364 - 0xc44]; TblW2378 tbl[(0x536c - 0x4364) / 8]; volatile s32 cur;
};
extern "C" {
void func_00147c78(MgrW2378*, NodeW2378*, f32);  // copy_bytes_232_to_12

// Queues every enabled node of the tree (flag 4 + table bit) and counts it for the current slot.
void func_00147ca0(MgrW2378* m, NodeW2378* n, f32 t)
{
    u16 idx = n->idx;
    if ((n->flags & 4) && ((TblW2378*)((u32)m + (idx << 3) + 0x4364))->on) {
        func_00147c78(m, n, t);
        m->time = t;
        s32 i = m->num;
        s32 k = i * 4;
        *(NodeW2378**)((u8*)m + k + 0x798) = n;
        m->num = i + 1;
        s32* p = (s32*)(m->cur * 4 + (u32)m + 0x770);
        p[3]++;
    }
    NodeW2378* c = 0;
    while ((c = !c ? n->child : c->next) != 0) func_00147ca0(m, c, t);
}
}
