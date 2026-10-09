#include "../common/types.h"
extern "C" {
extern void* func_002b6708(int, int, void*);
void* func_002b6b84(void*) asm("_Z13func_002b6b84Pv");
void* func_002b6b84(void* a) { return func_002b6708(2, 8, a); }
void* func_002b6c04(void* a) { return func_002b6708(2, 10, a); }
void* func_002b7108(void*) asm("_Z13func_002b7108Pv");
void* func_002b7108(void* a) { return func_002b6708(2, 18, a); }
void* func_002b7ebc(void* a) { return func_002b6708(2, 46, a); }
void* func_002b7efc(void* a) { return func_002b6708(2, 47, a); }
}
