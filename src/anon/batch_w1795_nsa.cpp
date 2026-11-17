#include "../common/types.h"
#include <stdarg.h>

struct W1795AD { u64 data, addr; };
struct W1795Pkt { u32 f0, f4; W1795AD* ptr; };

extern "C" {
// Appends A+D register writes (reg, value pairs ending with 0xffff) after a GIF tag.
void func_001b8010(W1795Pkt* p, s32 eop, ...);  // 0x001b8010: definition moved into src/anon/unit_001b6a50.cpp
}
