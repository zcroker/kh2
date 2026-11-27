#include "load_data.hpp"

extern void YS_CACHE_BUFF_Clear(s32) asm("_ZN2YS10CACHE_BUFF5ClearEi");
extern void YS_CACHE_BUFF_Flush(TASK*) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
extern void* YS_CACHE_BUFF_Alloc(char const*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");

namespace Tz {

extern "C" u32 YS__CACHE_BUFF__IsFlushing(...);
extern "C" void func_00170518(...);
extern u8 D_00360000 asm("D_00360000");

// 00292568: moved to src/anon/unit_00290f78.cpp

// 00292608: moved to src/anon/unit_00290f78.cpp
// 00292690: moved to src/anon/unit_00292620.cpp
// 002926a8: moved to src/anon/unit_00292620.cpp
}  // namespace Tz
