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

void func_00108098(W1897Pkt* p);  // 00108098: moved to src/anon/unit_00108068.cpp
}
