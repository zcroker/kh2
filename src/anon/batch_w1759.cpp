#include "../common/types.h"

struct W1759Entry { u8 pad[4]; u8 a, b, c; u8 pad2[3]; };
struct W1759Table { u32 x0; s32 n; W1759Entry e[1]; };
extern W1759Table* D_01d5baa8;

extern "C" {

W1759Entry* func_001d9dd0(s32 a, s32 b, s32 c);  // 0x001d9dd0: definition moved into src/anon/unit_001d9d00.cpp

}
