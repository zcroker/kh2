#include "../common/types.h"
extern "C" {
struct E1a8 { u32 w0, w4; s32 w8; s32 w12; u16 h[18]; };
struct T1a8 { u32 w0; s32 n; E1a8 e[1]; };
struct G1a8 { u8 pad[16]; u16 h[18]; };
extern T1a8* D_01c6cc08;
extern G1a8 D_01c6cc10;
extern u8 D_0032bae0[];
s32 func_001a8930(E1a8*, u8, u8);
void func_0016fab0(s32, s32);
void func_001a89f0(void);  // 0x001a89f0: definition moved into src/anon/unit_001a8618.cpp
}
