// Linked unit 0x2de010-0x2de028: pre_exec wrapper of the Ti::MGJump object whose jump set-up (0x2ddbf0) and
// jump move (0x2de028) sit on either side (vtable D_00362b74); never written as a separate match.
// The frame kept around the tail call comes from -g, as in unit_002de3c8 (0x2de3c8).
#include "../common/types.h"
namespace n002de010 {
void btlobj_pre_exec(u8*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
void func_002de010(u8* o) asm("func_002de010");
void func_002de010(u8* o) { btlobj_pre_exec(o); }
}  // namespace n002de010
