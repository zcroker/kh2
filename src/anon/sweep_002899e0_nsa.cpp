#include "../common/types.h"
extern "C" {
typedef struct S2899 S2899;
typedef struct M2899 M2899;
struct S2899 { u16 x; s16 pad2; s16 pad4; s16 m6; s16 m8; s16 pad[4]; u16 y; s16 p20; s16 h22; };
struct M2899 { u64 a; u64 b; u64 c; u64 d; };
s32 func_0028af78(S2899*, s32);
s32 func_00289d28(S2899*, u16*, u16*);
s32 func_00289b30(S2899*, u16*, u16*);
s32 func_0028a5a8(S2899*, M2899*);
s32 func_002899e0(S2899* a0, M2899* a1);  // 0x002899e0: definition moved into src/anon/unit_00288b00.cpp
}
