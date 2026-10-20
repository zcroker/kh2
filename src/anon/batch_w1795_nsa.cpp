#include "../common/types.h"
#include <stdarg.h>

struct W1795AD { u64 data, addr; };
struct W1795Pkt { u32 f0, f4; W1795AD* ptr; };

extern "C" {
// Appends A+D register writes (reg, value pairs ending with 0xffff) after a GIF tag.
void func_001b8010(W1795Pkt* p, s32 eop, ...) {
    va_list ap;
    W1795AD* tag = p->ptr;
    p->ptr++;
    va_start(ap, eop);
    u64 reg;
    while ((reg = va_arg(ap, u64)) != 0xffff) {
        p->ptr->data = va_arg(ap, u64);
        p->ptr->addr = reg;
        p->ptr++;
    }
    va_end(ap);
    s32 n = p->ptr - tag;
    tag->addr = 14;
    tag->data = (n - 1) | ((u64)eop << 15) | (1ull << 60);
}
}
