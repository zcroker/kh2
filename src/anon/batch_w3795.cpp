#include "../common/types.h"
extern u8* D_0035f2e4;
extern "C" {
u8* func_002859a0(void);
s32 func_002813b8(void);
s32 func_0027aa78(void);

// Returns 0 if any bit that is set in D_0035f2e4's 48-bit-per-slot table (slots 1..7, 6 skipped,
// filtered by a0/a1 when >= 0) is clear in func_002859a0()'s table; 1 otherwise.
s32 func_00287218(s32 a0, s32 a1);  // 0x00287218: definition moved into src/anon/unit_00286d28.cpp
}
