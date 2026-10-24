// try.sh: 3 diffs at -O0 as C (_O0.c); the 3 are gp-relative string addresses (addiu a0,gp,N). Instruction shapes all match.
// Needs a build change: link defines no _gp (original _gp = 0x37a800, from crt0) and the .sdata strings must sit at 0x378ab0/0x378ab8/0x378ac0; full build fails with "relocation truncated: R_MIPS_GPREL16".
#include "../common/types.h"
void func_002fdfc8(const char*, ...);

/* hex dump: per row print the address, 16 bytes in hex, then the printable text */
void func_002b6550(u8* p, s32 rows) {
    char text[17];
    s32 j;
    s32 i;
    for (i = 0; i < rows; i++) {
        func_002fdfc8("%08x : ", p);
        for (j = 0; j < 16; j++) {
            if (*p < 32 || *p >= 127) {
                text[j] = '.';
            } else {
                text[j] = *p;
            }
            func_002fdfc8("%02x ", *p++);
        }
        text[16] = 0;
        func_002fdfc8(" : %s\n", text);
    }
}
