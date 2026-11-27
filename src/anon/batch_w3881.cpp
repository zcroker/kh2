#include "../common/types.h"

extern "C" {

u8* func_002a9d68();
extern u8* D_0035f610;
u8* func_001a82b0(u8*);
s32 Tz__Jiminy__AreaWorld2JmWorld(u8);

// Walks every entry and checks that each one selected (not hidden, kind not 0 or 0x800, matching key
// when key >= 0) whose bit is set in the global flag set is also set in the save data's flag set.
s32 func_002ab620(s32 key);  // 0x002ab620: definition moved into src/anon/unit_002a99c8.cpp

}
