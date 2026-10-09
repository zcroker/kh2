#include "../common/types.h"

// func_001e7470, func_002f1fb8: hand-written MMIO/VU0-control asm (whole body).
extern u8 D_00363c50[];
asm(".section .text.func_001e7470,\"ax\",@progbits\n"
".align 3\n.globl func_001e7470\n.type func_001e7470,@function\nfunc_001e7470:\n"
".set noreorder\n.set noat\n"
"lui $14,0x1000\n ori $14,$14,0xa000\n"
"1: lw $15,0($14)\n andi $15,$15,0x100\n nop\n nop\n nop\n bnez $15,1b\n lui $15,0x1000\n"
"lui $12,0x1000\n ori $15,$15,0xa020\n lui $14,0x8000\n sw $0,0($15)\n or $14,$4,$14\n ori $12,$12,0xa030\n"
"lui $13,0x1000\n sw $14,0($12)\n li $15,2\n ori $13,$13,0xe010\n sw $15,0($13)\n"
"lui $14,0x1000\n ori $14,$14,0xa000\n li $15,325\n sw $15,0($14)\n jr $31\n nop\n"
".set reorder\n.set at\n.size func_001e7470,.-func_001e7470\n.text\n");
asm(".section .text.func_002f1fb8,\"ax\",@progbits\n"
".align 3\n.globl func_002f1fb8\n.type func_002f1fb8,@function\nfunc_002f1fb8:\n"
".set noreorder\n.set noat\n"
"lui $2,0x1000\n li $7,1\n ori $2,$2,0x3c10\n lui $3,0x1000\n sw $7,0($2)\n ori $3,$3,0x3c20\n li $2,2\n move $4,$0\n sw $2,0($3)\n"
"sync\n cfc2.ni $4,$28\n ori $4,$4,0x200\n ctc2.ni $4,$28\n sync.p\n"
"lui $5,%hi(D_00363c50)\n lui $6,0x1000\n addiu $5,$5,%lo(D_00363c50)\n ori $6,$6,0x5000\n lq $4,0($5)\n lui $3,0x1000\n ori $3,$3,0x3000\n sq $4,0($6)\n lq $2,16($5)\n sq $2,0($6)\n jr $31\n sw $7,0($3)\n"
".set reorder\n.set at\n.size func_002f1fb8,.-func_002f1fb8\n.text\n");

extern "C" {
extern u8 D_0022b108[];
void* func_00102c18(int, void*, void*);
void* func_0022a368(void*);
void func_00224f08();
void func_00224f38(void* a0, u32* a1, u32* a2, void* a3) {
  u32* r = (u32*)func_00102c18(1, a0, D_0022b108);
  *a1 = (u32)r;
  r[12] = (u32)func_00224f08;
  *a2 = (u32)func_0022a368(a3);
}
union U { u8 c; u16 h; s16 sh; u32 w; float f; };
void func_00232ea0(U* a0, U* a1, U* a2, u32 a3) {
  a0[0].w = a2[0].w; a0[1].w = a2[1].w; a0[2].w = a2[2].w;
  a0[5].f = (float)a1[2].h * 2.0f;
  a0[6].h = ((U*)((u8*)a1+10))->h;
  ((U*)((u8*)a0+26))->h = ((U*)((u8*)a1+12))->h;
  float f0 = (float)(s32)(a1[2].h - ((U*)((u8*)a1+16))->sh) * 2.0f;
  a0[12].c = 1;
  a0[3].w = a3;
  a0[4].f = f0;
}
}
