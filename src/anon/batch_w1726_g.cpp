#include "../common/types.h"
extern "C" {
struct U4 { u8 b[4]; };
extern U4 D_01c6cc48;

void func_001a9110(U4* p);  // 0x001a9110: definition moved into src/anon/unit_001a9110.cpp

struct PopStack { u8 pad[12]; union { U4* p; u32 u; u8 c; } sp; };
void func_001da3f8(PopStack* s, U4* out) { s->sp.u -= 4; *out = *s->sp.p; }

void func_001e5fd8(void);  // 0x001e5fd8: definition moved into src/anon/unit_001e0cb8.cpp
}
