#include "../common/types.h"

extern "C" {

struct Obj { u8 pad[943]; u8 a; };
struct Ent { s32 id; s32 pad4; Obj* obj; s32 start; s32 end; u8 from; u8 to; u8 pad[18]; };
extern Ent* D_0035dcfc;
extern s32 D_0035de20;
void YS__OBJ__is_valid(Obj*);

// Fade each live entry's object value from 'from' to 'to' over [start, end).
// The FULL path is written in both arms so CSE shares one hi(D_0035dcfc) and
// cross-jumping merges the copies into the original's single out-of-line block.
void func_0022f3a8(void);  // 0x0022f3a8: definition moved into src/anon/unit_0022d358.cpp

}
