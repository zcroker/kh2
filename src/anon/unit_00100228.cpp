// Linked unit 0x00100228-0x001002a0.
#include "../common/types.h"

// 00100228 (was src/anon/batch_w39.cpp)
namespace n00100228 {
/*TARGET 00100228*/
// --- 00100228
// crt0 helper: zero [v0, v1) (bytes up to 16-byte alignment, then quadwords,
// then the tail). Hand-written assembly: register inputs v0/v1, sq loop.
void func_00100228(void) asm("func_00100228");
// --- 00100228
// crt0 helper: zero [v0, v1) (bytes up to 16-byte alignment, then quadwords,
// then the tail). Hand-written assembly: register inputs v0/v1, sq loop.
void func_00100228(void) {  // align_and_zero_fill
    asm volatile(
        ".set noreorder\n"
        "1:\n\t"
        "andi $4, $2, 0xf\n\t"
        "beqz $4, 2f\n\t"
        "nop\n\t"
        "sb $0, 0($2)\n\t"
        "addiu $2, $2, 1\n\t"
        "nop\n\t"
        "j 1b\n\t"
        "nop\n"
        "2:\n\t"
        "lui $4, 0xffff\n\t"
        "ori $4, $4, 0xfff0\n\t"
        "and $4, $3, $4\n"
        "3:\n\t"
        "beq $2, $4, 4f\n\t"
        "nop\n\t"
        "sq $0, 0($2)\n\t"
        "addiu $2, $2, 16\n\t"
        "nop\n\t"
        "nop\n\t"
        "j 3b\n\t"
        "nop\n"
        "4:\n\t"
        "beq $2, $3, 5f\n\t"
        "nop\n\t"
        "sb $0, 0($2)\n\t"
        "addiu $2, $2, 1\n\t"
        "nop\n\t"
        "nop\n\t"
        "j 4b\n\t"
        "nop\n"
        "5:\n"
        ".set reorder"
        ::: "$4", "memory");
}
}  // namespace n00100228

