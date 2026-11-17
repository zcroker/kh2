#include "../common/types.h"

void func_001e7798(u32* h, u32 q);  // 0x001e7798: definition moved into src/anon/unit_001e0cb8.cpp

typedef union W { s32 w; u8 c; } W;
typedef struct E { s32 x, y; W a; W b; } E;
void func_001e8288(u8* p, s32 d);  // 0x001e8288: definition moved into src/anon/unit_001e0cb8.cpp

void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ecb0[], D_0036ecc8[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
static inline void ryjTail(const char* f, s32 l) {
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERTM(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); ryjTail(D_0036e9d0, l); }
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
void func_001e2ad8(const char*, const char*, s32, const char*);
typedef union { s32 a; u8* p; u8 c; } U;
typedef struct { U a, b, c, d, e; U f; U g; U h; U k; } T;
extern T D_00352c48[];
u32* func_001e3e48(s32* p, u8* bits);  // 0x001e3e48: definition moved into src/anon/unit_001e0cb8.cpp

