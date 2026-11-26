#include "../common/types.h"

extern "C" {

struct Save { u8 p0[80]; u32 a[3]; u32 b[1]; };
extern Save* D_0035f2e4;
Save* func_002859a0(void);
void* func_00258108(void);
void* func_002811b0(void*, s32);
s32 func_001b7818(void*);

static inline s32 bit(const u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }

// 00287028: checks that every flag set in D_0035f2e4's bitsets is also set in the
// save data (first set: 80 bits or the one bit 'id'; second: 48 bits per entry
// for entries 1..3 or just entry 'mode'). Returns 1 when all are set, else 0.
s32 Tz__CmNewFlg__isAbilityHistMember(s32 mode_, s32 id);  // 0x00287028: definition moved into src/anon/unit_00286d28.cpp

}
