#include "../common/types.h"

// 128-byte entries in a table that sits behind a header (count + byte offset pairs).
struct Ent2364 { s32 id; u8 pad[124]; };
struct Tbl2364 {
    u8 pad[0xa0];
    s32 n;       // 0xa0: entry count, first list
    s32 off;     // 0xa4: byte offset of the first list
    u8 pad2[8];
    s32 n2;      // 0xb0: entry count, second list
    s32 off2;    // 0xb4: byte offset of the second list
};
struct Own2364 { u8 pad[8]; Tbl2364* t; };

extern "C" {

// Finds the entry with this id in the first list (0 if none).
Ent2364* func_00114438(Own2364* o, s32 id);  // 0x00114438: definition moved into src/anon/unit_001142a0.cpp

// Finds the entry with this id in the second list (0 if none).
Ent2364* func_00114490(Own2364* o, s32 id);  // 0x00114490: definition moved into src/anon/unit_001142a0.cpp

}
