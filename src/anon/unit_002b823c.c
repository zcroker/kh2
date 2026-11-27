// Linked unit (see linked_units.tsv); built with -G8 so the driver word is gp-relative.
#include "../common/types.h"

// 002b823c (was whole asm: src/anon/asm_002b823c.s)
// Returns the sound driver word kept at gp-7460 (set by 0x2b691c) after command 33.
extern s32 func_002b6708(s32, ...);
extern s32 D_00378adc;
/* size note for the assembler: lets -G8 make the access gp-relative */
__asm__(".extern D_00378adc, 4");
s32 func_002b823c(void) asm("func_002b823c");
s32 func_002b823c(void) {
    func_002b6708(1, 33);
    return D_00378adc;
}
