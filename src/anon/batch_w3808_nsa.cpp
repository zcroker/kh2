#include "../common/types.h"
extern "C" {
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
u8* func_002a9d68(void);
H3440* func_00294000(s32);
E3440* func_001d9e30(E3440*);
s32 func_001d9d48(E3440*);
s32 func_002b3ac8(s32);
u32 func_001064a8(s32);

void func_002b3440(void);  // 0x002b3440: definition moved into src/anon/unit_002b3440.cpp
}
