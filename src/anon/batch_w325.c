#include "../common/types.h"

extern s32 D_01da8cd0[8];
extern s32 D_00352c40, D_01d9e6c4;
extern char D_01d9e5b0[], D_0036eef0[];
u64 func_00313b80(f32);  // float_to_double
s32 wsprintf_002fee78(char*, const char*, ...) asm("_Z16wtarget_002fee78jjjj");

char* func_001e6188(void);  // 0x001e6188: definition moved into src/anon/unit_001e0cb8.cpp

typedef unsigned int u128 __attribute__((mode(TI)));
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;

Q128* func_0021c810(Q128* p, s32 a, s32 b);  // 0x0021c810: definition moved into src/anon/unit_0021aee8.cpp

void func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_001e2ad8(const char*, const char*, s32, const char*);
extern char D_0036e978[], D_0036e998[], D_0036e9d0[];
extern char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ec80[], D_0036ec98[];
typedef struct { u32 a; u32 b; } W325E8;
extern W325E8 D_00353e48[];

/* RyjAssert: "RyjAssertion failed: %s\n" then "   File %s, Line %u\n", break. */
static inline void ryjAssert5(const char* a, const char* e, const char* b, const char* f, s32 l) {
    func_002fdfc8(a, e);  // device_vprintf_va
    func_002fdfc8(b, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define RYJ_ASSERT(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)

u32* func_001e3c98(s32* p, u8* bits);  // 0x001e3c98: definition moved into src/anon/unit_001e0cb8.cpp
