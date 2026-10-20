#include "../common/types.h"

extern "C" {

void func_00158f90(void*);

void func_00195c58(void* a0, u8* a1) {
    if (*(u32*)(a1 + 0x588) & 0x80) func_00158f90(a0);
}

}
