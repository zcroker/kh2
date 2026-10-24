#include "../common/types.h"

struct WT324750 { u8 pad[10]; u16 count; u8 pad2[4]; s32 offs[1]; };

extern "C" {
s32 wt_00324750(WT324750* p, s32 idx) asm("_Z16wtarget_00324750jjjj");

/* 00324750: return the 16-bit value of entry idx (for idx == -1, of the first valid entry), or -1.
   Needs -fno-gcse: the original re-extends the u16 count on every loop test. */
s32 wt_00324750(WT324750* p, s32 idx) {
    if (idx == -1) {
        u16 n = p->count;
        s32 i = 0;
        while (i < (s16)n) {
            s32 r;
            s32 off = p->offs[i];
            if (off >= 0) { u8* q = (u8*)p + (s16)n * 4 + off; r = (q[0x12] << 8) + q[0x11]; }
            else r = -1;
            if (r != -1) return r;
            i++;
        }
        return -1;
    }
    s32 off = p->offs[idx];
    if (off >= 0) { u8* q = (u8*)p + (s16)p->count * 4 + off; return (q[0x12] << 8) + q[0x11]; }
    return -1;
}
}
