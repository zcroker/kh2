#include "../common/types.h"

// 001aa980: writes a two-word GIF tag header into the packet; built without sched1 (_nosched).
// p is pinned to t4 for the first store pointer.
void func_001b80d8(void*);
extern u64 D_0036d708;
typedef union UPv { u64* volatile p; u32 u; u8 c; } UPv;
typedef struct Pu { u32* p0; u32 n; u8 pad[0x40 - 8]; u8 sub[12]; UPv pk; } Pu;
void func_001aa980(Pu* a) {
 if ((*a->p0 ^ 4) == 0) {
  u64 t = a->n; t |= 0x8000; t |= 0xa0aa400000000000ULL;
  { register u64 *p asm("$12") = a->pk.p; p[0] = t; }
  { u64 *q = a->pk.p; q[1] = D_0036d708; }
 } else {
  u64 t = a->n; t |= 0x8000; t |= 0x60ab400000000000ULL; a->pk.p[0] = t; a->pk.p[1] = 0x43431e;
 }
 func_001b80d8(a->sub);
}
