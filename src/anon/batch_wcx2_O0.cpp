#include "../common/types.h"

extern "C" {

struct Ctl78 { s32 on; s32 f4, f8, f12, f16, f20; s32 f24; u32 a, b, c, d; s32 f44, f48, f52; };
struct Obj78 { u8 pad[0x48000]; Ctl78 ctl; };
void func_002b8824(Obj78* o, u32 a, u32 b, u32 c, u32 d);  // 0x002b8824: definition moved into src/anon/unit_002b8274.cpp

// ---- 002b7440
struct Ent2b7 { s32 type; s32 a; s32 b; s32 c; u8 pad[48]; };
extern Ent2b7 D_01e22080[];
// The same table viewed from its a/b/c fields (how the original addresses them).
extern Ent2b7 D_01e22084[], D_01e22088[], D_01e2208c[];
s32 func_003058a0(s32 a);

// Count type-19/43 entries matching the given keys (negative key = wildcard).
s32 func_002b7440(s32 a, s32 b, s32 c);  // 0x002b7440: definition moved into src/anon/unit_002b6f28.cpp

// ---- 002b8c78
struct Hdr78 { u8 pad0[12]; s32 f12; u8 pad1[4]; s32 f20; s32 f24; u8 pad2; u8 f29; };
void memcpy(void*, void*, u32);
s32 func_002b8694(s32);
s32 func_002b6708(s32, s32, void*, s32, u32, u32, s32, s32);
void func_002b8c78(Obj78* o);  // 0x002b8c78: definition moved into src/anon/unit_002b8274.cpp

// ---- 002b6f28
s32 func_002b6708_6f28(s32, s32, u32, u32, u32) asm("func_002b6708");
s32 func_002b6f28(u32 a0, u32 a1, u32 a2);  // 0x002b6f28: definition moved into src/anon/unit_002b6f28.cpp

// ---- 002b70b8
s32 wt_002b70b8(u32 a0, u32 a1, u32 a2) asm("_Z16wtarget_002b70b8jjjj");
s32 wt_002b70b8(u32 a0, u32 a1, u32 a2);  // 0x002b70b8: definition moved into src/anon/unit_002b6f28.cpp

// ---- 002b8214
s32 func_002b8214(s32 a);  // 0x002b8214: definition moved into src/anon/unit_002b6f28.cpp

} // extern "C"
