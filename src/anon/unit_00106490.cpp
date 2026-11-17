#include "../common/types.h"

// Random number helpers (0x106490-0x1065d8): srand wrapper, integer and float ranges.

// ---- 00106490 (from src/anon/tiny_wrappers_more.cpp)
namespace n00106490 {
u32 srand(u32, u32, u32, u32) asm("srand");
u32 func_00106490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106490");
u32 func_00106490(u32 a0, u32 a1, u32 a2, u32 a3) {
    return srand(a0, a1, a2, a3);
}
}  // namespace n00106490

// ---- 001064a8 (from src/anon/batch_w38.cpp)
namespace n001064a8 {
struct NoTail { ~NoTail() {} };
s32 func_002fea18(void) asm("func_002fea18");
void __fixunssfsi(f32) asm("__fixunssfsi");
void func_001064a8(void* n) asm("func_001064a8");
void func_001064a8(void* n) {  
    NoTail g;
    f32 x = (f32)(u32)n;
    s32 r = func_002fea18();
    __fixunssfsi(x * (f32)r / 2147483520.0f);
}
}  // namespace n001064a8

// ---- 00106520 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00106520 {
u32 func_001064a8(u32, u32, u32, u32) asm("func_001064a8");
u32 func_00106520(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106520");
u32 func_00106520(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r5 = (u32)(r5 - r4);
    r16 = r4;
    r4 = r5;
    r2 = func_001064a8(r4, r5, r6, r7);  
    r16 = (u32)(r16 + r2);
    r2 = r16;
    return r2;
}
}  // namespace n00106520

// ---- 00106558 (from src/anon/batch_w63.cpp)
namespace n00106558 {
s32 func_002fea18(void) asm("func_002fea18");
f32 func_00106558(f32 x) asm("func_00106558");
f32 func_00106558(f32 x) {
    return x * (f32)func_002fea18() / 2147483520.0f;
}
}  // namespace n00106558

// ---- 001065a8 (from src/anon/batch_w7.cpp)
namespace n001065a8 {
f32 func_00106558(f32) asm("func_00106558");
f32 func_001065a8(f32 a, f32 b) asm("func_001065a8");
f32 func_001065a8(f32 a, f32 b) {
    return a + func_00106558(b - a);
}
}  // namespace n001065a8

