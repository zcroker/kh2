#include "../common/types.h"

extern "C" {

struct W1814Obj { u32 pad0; f32 f4; f32 f8; f32 fc; s32 m10; u8 pad[0x1c]; void* cb30; };
struct W1814Arg { u32 pad0; f32 f4; u32 pad8; u32 padc; s32 m10; };
struct W1814Cur { u32 pad0; s32 id; };
extern W1814Obj* D_0034c774;
void func_001024a8(void*);
void func_00102670(s32, W1814Obj*);
W1814Obj* func_00102c18(s32, s32, void*);
W1814Cur* func_00102c80(void);
void func_001619e8(void);
void func_001620a8(void);
void func_001623b0(void);
void func_00161c88(void);
void func_00161d48(void);
void func_00161de0(void);

void func_00161df0(W1814Arg* a);  // 0x00161df0: definition moved into src/anon/unit_001614e8.cpp

}
