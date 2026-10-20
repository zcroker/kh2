#include "../common/types.h"
extern "C" {
struct U4 { u8 b[4]; };
extern U4 D_01c6cc48;

void func_001a9110(U4* p) { D_01c6cc48 = *p; }

struct PopStack { u8 pad[12]; union { U4* p; u32 u; u8 c; } sp; };
void func_001da3f8(PopStack* s, U4* out) { s->sp.u -= 4; *out = *s->sp.p; }

void func_001e5fd8(void) {
  *(volatile u32*)0x10000010 |= 0x83;
  *(volatile u32*)0x10000000 = 0;
}
}
