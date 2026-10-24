#include "../common/types.h"

/* partMng (C module): three copies of one hand-written VU0 routine that solves a
 * tridiagonal system for curve tangents (vdiv/vwaitq, trapping add/addi, blezl+nop:
 * hand-written assembly, kept as asm). Only the frame, the s-reg saves and the
 * operand set-up are compiler output: the work buffer is a stack array (sp) or the
 * scratchpad (0x70002000), the constant row a per-copy table. */
typedef unsigned int u128 __attribute__((mode(TI)));

#define SPLINE_SOLVE(in, n, out, tab, work) \
    asm volatile( \
        ".set noreorder\n\t" \
        "addi $9,%1,-1\n\t" \
        "addi $10,%1,-2\n\t" \
        "lqc2 $vf1,0(%3)\n\t" \
        "sqc2 $vf0,0(%2)\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sqc2 $vf0,0($11)\n\t" \
        "move $8,$9\n\t" \
        "move $11,$0\n\t" \
        ".Lspl%=_delta_loop:\n\t" \
        "blez $8,.Lspl%=_delta_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $14,$12,%0\n\t" \
        "add $15,$13,%0\n\t" \
        "add $16,$13,%4\n\t" \
        "lqc2 $vf10,0($14)\n\t" \
        "lqc2 $vf11,0($15)\n\t" \
        "vsub.xyzw $vf10,$vf11,$vf10\n\t" \
        "sqc2 $vf10,0($16)\n\t" \
        "b .Lspl%=_delta_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_delta_done:\n\t" \
        "lqc2 $vf10,32(%4)\n\t" \
        "lqc2 $vf11,16(%4)\n\t" \
        "lqc2 $vf12,0(%2)\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf11\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf12\n\t" \
        "sqc2 $vf10,16(%2)\n\t" \
        "vaddx.xyzw $vf11,$vf0,$vf1x\n\t" \
        "sqc2 $vf11,16(%4)\n\t" \
        "move $8,$10\n\t" \
        "addi $8,$8,-1\n\t" \
        "addi $11,$0,1\n\t" \
        ".Lspl%=_fwd_loop:\n\t" \
        "blez $8,.Lspl%=_fwd_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "addi $14,$13,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$13,%4\n\t" \
        "add $17,$14,%4\n\t" \
        "add $18,$13,%2\n\t" \
        "add $19,$12,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "lqc2 $vf13,0($19)\n\t" \
        "vdiv Q,$vf0w,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "vsub.xyzw $vf16,$vf12,$vf11\n\t" \
        "vmul.xyzw $vf17,$vf13,$vf15\n\t" \
        "vsub.xyzw $vf17,$vf16,$vf17\n\t" \
        "sqc2 $vf17,0($18)\n\t" \
        "vmuly.xyzw $vf18,$vf15,$vf1y\n\t" \
        "vaddx.xyzw $vf18,$vf18,$vf1x\n\t" \
        "sqc2 $vf18,0($16)\n\t" \
        "b .Lspl%=_fwd_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_fwd_done:\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sll $12,$10,0x4\n\t" \
        "add $12,$12,%2\n\t" \
        "lqc2 $vf10,0($11)\n\t" \
        "lqc2 $vf11,0($12)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf10\n\t" \
        "sqc2 $vf11,0($12)\n\t" \
        "move $11,$10\n\t" \
        ".Lspl%=_back_loop:\n\t" \
        "blezl $11,.Lspl%=_done\n\t" \
        "nop\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$12,%2\n\t" \
        "add $17,$13,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf12\n\t" \
        "vdiv Q,$vf11x,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11y,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11z,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "sqc2 $vf15,0($16)\n\t" \
        "b .Lspl%=_back_loop\n\t" \
        "addi $11,$11,-1\n\t" \
        ".Lspl%=_done:\n\t" \
        ".set reorder" \
        : : "r"(in), "r"(n), "r"(out), "r"(tab), "r"(work) \
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19", "memory")

extern u8 D_003590c0[];
extern u8 D_003590e0[];
extern u8 D_00359090[];

void func_001f1248(void* in, s32 n, void* out)
{
    SPLINE_SOLVE(in, n, out, D_00359090, (u128*)0x70002000);
}

void func_00201978(void* in, s32 n, void* out)
{
    u128 work[32];
    SPLINE_SOLVE(in, n, out, D_003590c0, work);
}

void func_002029e8(void* in, s32 n, void* out)
{
    u128 work[128];
    SPLINE_SOLVE(in, n, out, D_003590e0, work);
}
