#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

/* func_001e6688 */
typedef struct { s32 a, b, c, d, e, f, g, h; } S8_01da8cd0;
typedef struct { s32 x, y; } S2_00354690;
extern S8_01da8cd0 D_01da8cd0;
extern S2_00354690 D_00354690;
void func_001e6648(void);
void func_001e2b68(void);
void func_001e6688(void);  // 0x001e6688: definition moved into src/anon/unit_001e0cb8.cpp

/* func_001e6ed8 */
void f3f98(void*, void*) asm("_Z16sceVu0CopyMatrixjjjj");
void f3d08(void*, void*, void*) asm("_Z15sceVu0MulMatrixjjjj");
void sceVu0InversMatrix(void*, void*);  // convert_vectors_to_scalar
extern u128 D_01d9e730, D_01d9e740, D_01d9e750, D_01d9e760;
extern u128 D_01d9e770[4];
extern u128 D_01d9e7b0[4];
extern u128 D_01d9e7f0, D_01d9e800, D_01d9e810, D_01d9e820;
typedef union { f32 f; u128 q; } FQ; extern FQ D_01d9e830;
extern u128 D_01d9e8c0, D_01d9e8d0, D_01d9e8e0, D_01d9e8f0;
extern u8 D_01d9ea00[];
void func_001e6ed8(u128* a, u128* b, u128* c, u128* d);  // 0x001e6ed8: definition moved into src/anon/unit_001e0cb8.cpp

/* partMng.c asserts (file name string D_0036e9d0) */
void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036e978[], D_0036e998[], D_0036e9d0[];
static inline void ryjAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);        /* "RyjAssertion failed: %s\n" */
    func_002fdfc8(D_0036e998, f, l);     /* "   File %s, Line %u\n" */
    asm volatile("break");
}
static inline void ryjAssert5(const char* f1, const char* e, const char* f2, const char* f, s32 l) {
    func_002fdfc8(f1, e);  // device_vprintf_va
    func_002fdfc8(f2, f, l);  // device_vprintf_va
    asm volatile("break");
}
#define ASSERT(c, e, l) if (!(c)) ryjAssert(e, D_0036e9d0, l)
#define ASSERT5(c, e, l) if (!(c)) ryjAssert5(D_0036e978, e, D_0036e998, D_0036e9d0, l)
void* func_001e3650(void*);  // ptr_add4
s32* func_001e3660(void*, s32) asm("_Z13func_001e3660ji");

/* func_001e5458 */
extern char D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ed60[];
void func_001e5220(u32, s32);
void func_001e5458(u32* p, u8* bits, s16 k);  // 0x001e5458: definition moved into src/anon/unit_001e0cb8.cpp

/* func_001e5718 */
void func_001e52b8(u32, s32);
void func_001e5718(u32* p, u8* bits, s16 k);  // 0x001e5718: definition moved into src/anon/unit_001e0cb8.cpp

/* func_001e5898 */
void func_001e5898(u32* p);  // 0x001e5898: definition moved into src/anon/unit_001e0cb8.cpp
