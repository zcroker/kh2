#include "../common/types.h"
extern "C" {

extern s32 D_003417b0;
s32 TARGET_is_exist_00190140(void*) asm("_ZNK2YS6TARGET8is_existEv");
typedef struct S0_0010ce78 { u8 pad[0x9f4]; s32 f; } S0_0010ce78;

static inline u8 h0_0010ce78(void) {
    u8 r = 0;
    if (TARGET_is_exist_00190140(&D_003417b0)) r = D_003417b0 != 0;
    return r;
}

/* empty asm barrier keeps gcc from folding the last test into xor/sltu */
s32 func_0010ce78(S0_0010ce78* p);  // 0x0010ce78: definition moved into src/anon/unit_0010ce78.cpp

}
