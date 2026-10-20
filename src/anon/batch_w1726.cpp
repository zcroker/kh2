#include "../common/types.h"
extern "C" {
void func_00188490(void*, void*);
void func_00136840(void);
void func_001369d0(void);
void func_00136a40(void);

void func_00188470(void* a, void* b) { func_00188490(b, *(void**)((u8*)a + 0x88)); }

void func_00136a18(void) { func_00136840(); func_001369d0(); func_00136a40(); }
}
