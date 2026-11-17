#include "../common/types.h"

/* 00124c48: walk a table of variable-length entries (id, count, then count 16-byte items)
   ending at id -1; return the entry whose id matches, or 0.
   Partial asm: register pins (h/nx in t6, cur in t4, it in t5) reproduce the original's
   allocation (cur kept apart from the reloaded id, copied with move t4,t6). */
typedef struct Hdr00124c48 { u32 x0; u32 x4; s32 off; s32 cnt; } Hdr00124c48;
typedef struct Item00124c48 { u32 a, b, c, d; } Item00124c48;
typedef struct Ent00124c48 { s32 id; s32 n; u32 x8, xc; } Ent00124c48;
typedef struct Obj00124c48 { u32 x0; Hdr00124c48* h; } Obj00124c48;

/* 0019ee28: wtarget handler; on (1, 0xffff) clears D_00350448 and D_00350464.
   Partial asm: an empty asm volatile barrier keeps the +0x20 store before the +0 store. */
struct S00350448 { s32 a; u8 pad[0x1c]; f32 c; };
extern "C" {
extern S00350448 D_00350448;
extern f32 D_00350464;

Ent00124c48* func_00124c48(Obj00124c48* o, s32 id);  // 0x00124c48: definition moved into src/anon/unit_00123990.cpp

void wtarget_0019ee28(u32, u32, u32, u32) asm("_Z16wtarget_0019ee28jjjj");
void wtarget_0019ee28(u32 a, u32 b, u32, u32);  // 0x0019ee28: definition moved into src/anon/unit_0019ea10.cpp
}
