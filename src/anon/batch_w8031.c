#include "../common/types.h"
typedef struct { s32 lvl; s32 id; } W1572_Cand;
extern u32 D_003638d0;
s32 YS__OBJ__is_exist(s32) __asm__("_Z17YS__OBJ__is_existjjjj");
u64 func_00312db8(u64, u64);
static inline u8 W1572_Invalid(s32 id) {
    u8 r = 0;
    if (id == 0 || YS__OBJ__is_exist(id) == 0) r = 1;
    return r;
}
// 001cd7a8: moved to src/anon/unit_001cd660.cpp
s32 func_001cd7a8(W1572_Cand* arg);
