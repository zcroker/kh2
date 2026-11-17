#include "../common/types.h"

extern "C" {

struct Nd223 { u8 p[0x38]; Nd223* next; Nd223* prev; };
struct Ls223 { Nd223* head; Nd223* tail; };
struct Ow223 { u32 f0; u32 f4; Ls223 l; u8 q[0x110 - 16]; Nd223* cur; };
extern void func_001022e8(Nd223*);

void func_001025f8(Ow223* o, Nd223* n) asm("_Z13func_001025f8Pv");
// 001025f8: moved to src/global/unit_001022c0.cpp

// hand-written VU0 code: 5 planes x 8 points dot-product test (whole body in asm)
void func_00146cb0(void) __attribute__((noreturn));
void func_00146cb0(void);  // 0x00146cb0: definition moved into src/anon/unit_00145600.cpp

}
