#include "../common/types.h"

extern "C" {

// --------------------
// 0026b200: true if the current entry's id is found in the second id list but not the first.
u32 func_0028b040(u32);
u32 func_00257130(void);
u8* func_00281f20(u32);
u32 func_00257070(u32);
u8* func_00281180(u32, u32);
extern u32 D_0035f01c;
extern u32 D_0035f010;
struct E26b200 { u16 id; u8 pad; u8 on; u16 x; };
struct S26b200 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; };
s32 func_0026b200(void);  // 0x0026b200: definition moved into src/anon/unit_0026a900.cpp

}
