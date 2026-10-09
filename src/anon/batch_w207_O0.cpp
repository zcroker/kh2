#include "../common/types.h"

extern "C" {
u32 func_002b6708(u32, u32, u32);

u32 w_002b7078(u32 a) asm("_Z16wtarget_002b7078jjjj");
u32 w_002b7078(u32 a) { return func_002b6708(2, 16, a); }

u32 w_002b78ec(u32 a) asm("_Z16wtarget_002b78ecjjjj");
u32 w_002b78ec(u32 a) { return func_002b6708(2, 26, a); }

u32 func_002b7e34(u32 a) { return func_002b6708(2, 44, a); }

u32 func_002b7fbc(u32 a) { return func_002b6708(2, 50, a); }

u32 func_002b7ffc(u32 a) { return func_002b6708(2, 51, a); }

u32 func_002b8374(u32 a) { return func_002b6708(2, 36, a); }

u32 func_002b9a38(u32 a) { return func_002b6708(2, 53, a); }

u32 func_002b9a78(u32 a) { return func_002b6708(2, 54, a); }

}
