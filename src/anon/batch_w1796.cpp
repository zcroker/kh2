#include "../common/types.h"

struct S24_w1796 { u8 pad[28]; s8 a[4]; s8 b[4]; };
struct Item_w1796 { u8 d[48]; };
struct Node_w1796 {
    Node_w1796* head; s32 pad4; Node_w1796* next; Node_w1796* prev;
    u8 pad10[0x24];
    u16 start2; u16 pad36; u16 cnt2; u16 pad3a; u16 cnt; u16 flags;
    Item_w1796 items[1];
};

extern "C" {
s32 func_001a6d08(s32);
extern S24_w1796 D_00371f30;
void func_00220088(Item_w1796*, u16);

s32 Tz__TRTE__GetSeqInfo(void);  // 0x0024ac88: definition moved into src/anon/unit_00249ef0.cpp

void func_00221ed0(Node_w1796* n);  // 0x00221ed0: definition moved into src/anon/unit_00221e28.cpp
}
