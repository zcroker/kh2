#include "../common/types.h"
extern "C" {
// 00104d30: copy the 3 ids, look up the cell's 3 defaults in the table, then apply overrides
struct Cell104d30 { u8 pad[16]; u16 x, y, z; };
extern u8 D_0032bb30[];
struct Ent104d30 { u8 a, b, c, pad; u16 v[3]; };
void func_00104cf0(u16* d, u16* s);
// 00104d30: moved to src/common/area.cpp
}
