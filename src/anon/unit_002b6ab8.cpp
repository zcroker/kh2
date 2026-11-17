// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"

// 002b6ab8 (was src/anon/batch_w200_O0.cpp)
namespace n002b6ab8 {
/*TARGET 002b6ab8*/
u32 func_002b6ab8() asm("func_002b6ab8");
u32 func_002b6ab8() { return 0; }
}  // namespace n002b6ab8

// 002b6adc (was src/anon/batch_w210_O0.cpp)
namespace n002b6adc {
u32 func_002b6708(u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b6adc*/
u32 func_002b6adc(u32 a, u32 b) asm("func_002b6adc");
u32 func_002b6adc(u32 a, u32 b) { return func_002b6708(3, 6, b, a); }
}  // namespace n002b6adc

// 002b6b24 (was src/anon/batch_w37_O0.cpp)
namespace n002b6b24 {
s32 func_002b6708(s32, s32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b6b24*/
s32 func_002b6b24(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002b6b24");
s32 func_002b6b24(u32 a, u32 b, u32 c, u32 d, u32 e) {
    return func_002b6708(6, 7, a, b, c, d, e);
}
}  // namespace n002b6b24

// 002b6b84 (was src/anon/batch_w208_O0.cpp)
namespace n002b6b84 {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
void* func_002b6b84(void*) asm("_Z13func_002b6b84Pv");
/*TARGET 002b6b84*/
void* func_002b6b84(void* a) asm("_Z13func_002b6b84Pv");
void* func_002b6b84(void* a) { return func_002b6708(2, 8, a); }
}  // namespace n002b6b84

// 002b6bc4 (was src/anon/batch_w206_O0.cpp)
namespace n002b6bc4 {
s32 func_002b6708(s32, s32, s32) asm("func_002b6708");
/*TARGET 002b6bc4*/
s32 func_002b6bc4(s32 a) asm("func_002b6bc4");
s32 func_002b6bc4(s32 a) { return func_002b6708(2, 9, a); }
}  // namespace n002b6bc4

// 002b6c04 (was src/anon/batch_w208_O0.cpp)
namespace n002b6c04 {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
/*TARGET 002b6c04*/
void* func_002b6c04(void* a) asm("func_002b6c04");
void* func_002b6c04(void* a) { return func_002b6708(2, 10, a); }
}  // namespace n002b6c04

