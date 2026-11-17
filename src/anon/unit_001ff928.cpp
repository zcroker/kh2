// Linked unit 0x1ff928-0x1ff958: a ppp init (never written as a separate match, no layout.tsv row),
// alone between two files that are not linked yet. Stores rotated: gcc emits the last zero store first.
#include "../common/types.h"
namespace n001ff928 {
struct S { u8 a, b; u16 c, d, e; };
void func_001ff928(u8* o, u8* t) asm("func_001ff928");
void func_001ff928(u8* o, u8* t) {
    S* s = (S*)(o + (*(s32**)(t + 12))[0] + 160);
    s->a = 31;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->b = 0;
}
}  // namespace n001ff928
