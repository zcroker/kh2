#include "../common/types.h"

extern "C" {
void func_00237698(void* p);
void func_0019d518(void* p);
void func_002ef5c8(void* p);

void func_00237680(void* p) { func_00237698(p); }

void func_0019d4f8(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    func_0019d518(p);
}

void func_002ef5a8(u8* p) {
    *(u32*)(p + 812) = 0;
    *(u32*)(p + 816) = 0;
    func_002ef5c8(p);
}
}
