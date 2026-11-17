#include "../common/types.h"
extern "C" {
struct BBuf_w { u64 SBP:14, :2, SBW:6, :2, SPSM:6, :2, DBP:14, :2, DBW:6, :2, DPSM:6, :2; };
struct TReg_w { u64 RRW:12, :20, RRH:12, :20; };
struct DTag_w { u16 qwc; u8 mark; u8 id; u32 addr; u32 pad[2]; };
struct Pkt_w { u8 pad[0x20]; BBuf_w bb; u64 p1; u8 pad2[0x10]; TReg_w tr; u64 p2; u8 pad3[0x30]; DTag_w tag; };
struct NoTail_w { ~NoTail_w() {} };
void func_00109450(s32, s32, s32);
void func_001094e0(Pkt_w* p, s32 arg);  // 001094e0: moved to src/anon/unit_001085a8.cpp
}
