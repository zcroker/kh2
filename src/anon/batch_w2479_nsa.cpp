#include "../common/types.h"
extern "C" {
union BdVal { s32 i; u32 u; f32 f; };
struct BdOpF { u16 code : 4; u16 type : 2; u16 arg : 10; };
struct BdProg { u8 hdr[16]; u16 code[1]; };
union BdOp { u16 raw; BdOpF f; };
struct BdBytes4 { u8 b[4]; };
struct BdVM {
    BdProg* prog;
    s32 pc;
    s32* csp;
};
struct BdFunc { void (*fn)(BdVal*); u32 info; };
typedef void (*BdHook)(BdVM*, s32, void*);
void func_001da3d8(BdVM*, BdVal*);
void func_001da3f8(BdVM*, BdVal*);
u32 func_001da4d8(BdVM*, BdOpF);
void memcpy(void*, void*, u32); // memcpy
static inline void BdCopy(void* d, void* s, u32 n) { memcpy(d, s, n); }
f32 func_002f8b00(f32, f32); // fmodf
f32 sinf(f32);
f32 cosf(f32);
// Bytecode interpreter: fetch a 16-bit opcode (code:4 type:2 arg:10) and run it on the VM
// value stack (001da3d8 push, 001da3f8 pop, 001da4d8 operand address); hook runs after every op.
s32 BdExecVM(BdVM* vm, BdFunc** fns, BdHook hook, void* arg);  // 0x001da558: definition moved into src/anon/unit_001d9d00.cpp
}
