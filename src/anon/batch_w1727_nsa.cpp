#include "../common/types.h"

// Built with -fno-strict-aliasing (see Makefile _nsa rule).
extern "C" {

extern u8 D_00373a98[];
extern u8 D_00373aa0[];

static inline void set_ptr_len(u8** out_p, s32* out_n, u8* p, s32 n) {
    *out_p = p;
    *out_n = n;
}

void func_002713a0(s32 a0, u8** a1, s32* a2);  // 0x002713a0: definition moved into src/anon/unit_0026f0a0.cpp

}
