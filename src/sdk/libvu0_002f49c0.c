/* libvu0_002f49c0.c: Sony PS2 Runtime Library 3.0.0 libvu0: VPU0 reset, 0x2f49c0-0x2f4a1c.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (the end of the original libvu0 object; libdbc follows).
 * Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef int u128 __attribute__((mode(TI)));
extern u128 D_00363ce0[2];

/* ---- 0x2f49c0: VIF0 MARK/ERR cleared, FBRST reset, VU0 FBRST (vi28) bit 1 via cfc2/ctc2 (partial asm:
 * the COP2 control-register access; .set noreorder keeps gas from adding a hazard nop), then the two
 * initial VIF0 qwords go to the VIF0 FIFO. The last store is written without so 2.9 puts it in
 * the jr delay slot as the original does. */
void func_002f49c0(void)
{
    *(volatile int *)0x10003830 = 0;
    *(volatile int *)0x10003820 = 0;
    *(volatile int *)0x10003810 = 1;
    __asm__ __volatile__(".set noreorder\n\tcfc2.ni $8, $vi28\n\tori $8, $8, 2\n\tctc2.ni $8, $vi28\n\tsync.p\n\t.set reorder" : : : "$8");
    *(volatile u128 *)0x10004000 = D_00363ce0[0];
    *(u128 *)0x10004000 = D_00363ce0[1];
}
