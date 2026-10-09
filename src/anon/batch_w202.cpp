#include "../common/types.h"
extern "C" {
extern void func_001d1d68(u8*);
extern float func_002e50f8(u8*);
void YS_LIMIT_close_gauge(u8* a) asm("_ZN2YS5LIMIT11close_gaugeEv");
void YS_LIMIT_close_gauge(u8* a) { u32 f = *(u32*)(a+180) & 4; u8* p = a+168; if (f) func_001d1d68(p); }
float func_002dd218(u8* a) { return -(func_002e50f8(a+256) + 300.0f); }
}
