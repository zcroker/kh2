#include "../common/types.h"

// func_002d8910: VU0 macro-mode distance test (whole body asm).
asm(".section .text.func_002d8910,\"ax\",@progbits\n"
".align 3\n.globl func_002d8910\n.type func_002d8910,@function\nfunc_002d8910:\n"
".set noreorder\n.set noat\n"
"addiu $29,$29,-64\n addiu $14,$4,448\n sd $16,32($29)\n addiu $13,$29,16\n sd $31,40($29)\n swc1 $f20,48($29)\n"
"move $16,$5\n lw $15,108($5)\n lwc1 $f2,12($15)\n lwc1 $f0,4($15)\n lwc1 $f1,8($15)\n"
"swc1 $f0,16($29)\n swc1 $f1,20($29)\n swc1 $f2,24($29)\n sw $0,28($29)\n"
".word 0xd9c10000\n.word 0xd9a20000\n.word 0x4be2086c\n.word 0xfba10000\n.word 0xdba10000\n"
".word 0x4bc1086a\n.word 0x4b010841\n.word 0x4b010842\n.word 0x4a0103bd\n.word 0x4a0003bf\n.word 0x4848b000\n"
"mtc1 $8,$f20\n jal func_002d73f0\n nop\n lwc1 $f0,20($2)\n c.lt.s $f0,$f20\n bc1t 1f\n move $2,$0\n"
"lw $15,104($16)\n andi $2,$15,1\n"
"1: ld $16,32($29)\n ld $31,40($29)\n lwc1 $f20,48($29)\n jr $31\n addiu $29,$29,64\n"
".set reorder\n.set at\n.size func_002d8910,.-func_002d8910\n.text\n");

extern "C" {
struct S352130 { char p[0x24]; float f24; float f28; };
extern S352130* D_00352130;
extern u32 func_0018ca48(u32);
#define M asm volatile("" ::: "memory")
void func_0018cd28(char* a, float* x, float* y) {
    *x = D_00352130->f24;
    M;
    *y = D_00352130->f28;
    M;
    if (func_0018ca48(*(u8*)(a + 39)) == 4) {
        char* c = *(char**)(a + 32);
        if (c) {
            if (*(s32*)(c + 12)) {
                *x = (float)*(s16*)(c + 12);
                M;
                *y = (float)*(s16*)(*(char**)(a + 32) + 14);
            }
        }
    }
}
}
