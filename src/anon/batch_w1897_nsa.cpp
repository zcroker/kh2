#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" {
struct W1897GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct W1897AD { u64 data; u64 addr; };
struct W1897Pkt { W1897GifTag tag; W1897AD ad[13]; };

void func_00108098(W1897Pkt* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 13;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x4c;
    p->ad[2].addr = 0x4e;
    p->ad[3].addr = 0x34;
    p->ad[4].addr = 0x36;
    p->ad[5].addr = 0x16;
    p->ad[6].addr = 0x14;
    p->ad[7].addr = 6;
    p->ad[8].addr = 0x47;
    p->ad[9].addr = 0x42;
    p->ad[10].addr = 8;
    p->ad[11].addr = 0x3d;
    p->ad[12].addr = 1;
    p->ad[0].data = 0;
    p->ad[1].data = 0x800d8;
    p->ad[2].data = 0x31000070;
    p->ad[3].data = 0;
    p->ad[4].data = 0;
    p->ad[5].data = 0x2000000001300000ULL;
    p->ad[6].data = 0x60;
    p->ad[7].data = 0x2000000664023500ULL;
    p->ad[8].data = 0x5000d;
    p->ad[9].data = 0x44;
    p->ad[10].data = 5;
    p->ad[11].data = 0x808080;
    p->ad[12].data = 0x3f80000080808080ULL;
}
}
