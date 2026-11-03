#include "../common/types.h"
extern "C" {

/* Table entry whose byte at +3 is read as a one-byte struct: the value stays in QImode, so the
 * 0xff test keeps its andi and the s8 conversions keep their sll/sra like the original. */
struct Ent27a6d8Byte { u8 v; };
struct Ent27a6d8 { u8 pad[3]; Ent27a6d8Byte v; u8 pad2[4]; };
struct Tbl27a6d8 { u8 pad[16]; Ent27a6d8 e[1]; };
extern s32 D_0035f01c;
extern Tbl27a6d8* D_0035f230;
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
s32 func_0028b040(s32);
s32 func_00286d28(s32, s32);
s32 func_0027ae78(s32);
s32 func_00286ec8(s32, s8);
void func_00287358(s32, s8);
void func_00287430(s32, s8);

void func_0027a6d8(void) {
    s32 mode;
    s32 h;
    func_0027aed8(func_002570a0(15), &mode, &h);
    s32 i = func_0028b040(D_0035f01c);
    Ent27a6d8Byte c = D_0035f230->e[i].v;
    s8 k;
    if (c.v == 0xff) return;
    if (mode == 0) {
        k = c.v & 0x7f;
        if (func_00286d28(h, k)) func_00287358(h, k);
    } else {
        k = c.v & 0x7f;
        if ((s8)c.v & 0x80) {
            if (func_00286ec8(func_0027ae78(h), k)) func_00287430(func_0027ae78(h), k);
        } else {
            /* register pin: puts the a1 copy before the a0 zero so reorg can share it with the
               branch delay slot like the original */
            register s32 r5 asm("$5") = k;
            if (func_00286d28(0, r5)) func_00287358(0, k);
        }
    }
}

}
