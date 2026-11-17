// 00241160: scans the entry table for flagged entries whose name matches one of the known names
// and returns a mask of which matched (0x10 marks unknown entries). The byte offset written as
// (i * 5) << 3 is a shift giv that loop.c strength-reduces; the else part keeps e[i] (a mult).
#include "../common/types.h"
struct Ent { u32 flags; s32 id; char name[32]; };
struct EntX { u32 pad[2]; u32 flags; s32 id; char name[32]; };
struct Tbl { s32 count; s32 pad; Ent e[1]; };
extern "C" {
s32 func_00240108();
s32 func_002416d8(s32);
s32 strcmp(const char*, const char*);
s32 strlen(const char*);
extern char* D_0035ebf8;
extern char* D_0035ebfc;
extern char* D_0035ec00;
extern char* D_0035ec88;
extern Tbl* D_0035ec98;
s32 func_00241160(void);  // 0x00241160: definition moved into src/anon/unit_0023f5b8.cpp
}
