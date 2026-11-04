#include "../common/types.h"
extern "C" {
struct BBuf_w { u64 SBP:14, :2, SBW:6, :2, SPSM:6, :2, DBP:14, :2, DBW:6, :2, DPSM:6, :2; };
struct TReg_w { u64 RRW:12, :20, RRH:12, :20; };
struct DTag_w { u16 qwc; u8 mark; u8 id; u32 addr; u32 pad[2]; };
struct Pkt_w { u8 pad[0x20]; BBuf_w bb; u64 p1; u8 pad2[0x10]; TReg_w tr; u64 p2; u8 pad3[0x30]; DTag_w tag; };
struct NoTail_w { ~NoTail_w() {} };
void func_00109450(s32, s32, s32);
void func_001094e0(Pkt_w* p, s32 arg)
{
    s32 lo = 0x4000;
    s32 hi = 0;
    for (;; p++) {
        s32 n = 0;
        s32 dbp = p->bb.DBP;
        s32 rrw = p->tr.RRW;
        s32 rrh = p->tr.RRH;
        s32 psm = p->bb.DPSM;
        if (dbp < lo) lo = dbp;
        switch (psm) {
        case 0: case 1: case 0x1b: case 0x24: case 0x2c: case 0x30: case 0x31:
            n = ((rrw + 63) >> 6) * ((rrh + 31) >> 5);
            break;
        case 0x13:
            n = ((rrw + 127) >> 7) * ((rrh + 63) >> 6);
            break;
        case 0x14:
            n = ((rrw + 127) >> 7) * ((rrh + 127) >> 7);
            break;
        case 2: case 0xa: case 0x32: case 0x3a:
            n = ((rrw + 63) >> 6) * ((rrh + 63) >> 6);
            break;
        }
        DTag_w* t = &p->tag;
        void* next;
        s32 end = dbp + n * 32;
        if (hi < end) hi = end;
        switch (t->id & 0x70) {
        case 0x10: next = (u8*)t + t->qwc * 16 + 16; break;
        case 0x20: next = (void*)t->addr; break;
        case 0x30: case 0x40: next = t + 1; break;
        case 0x50: next = (void*)t->addr; break;
        default: next = 0; break;
        }
        if (next == 0) break;
    }
    NoTail_w nt;
    s32 start = lo / 32;
    func_00109450(start, (hi - start * 32 + 31) / 32, arg);
}
}
