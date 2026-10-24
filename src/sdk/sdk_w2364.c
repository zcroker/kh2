/* Sony PS2 Runtime Library 3.0.0 lib helper next to func_002f6b50 (0x2f6xxx). Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int D_01e331c8;
extern int D_01e331cc;
extern int D_01e331d0;
extern int D_00363da4;

/* Runs the callback registered by func_002f6b50 with the $gp it saved. */
void func_002f6bd0(void)
{
    void (*cb)(int) = (void (*)(int))D_01e331c8;
    if (cb && !D_00363da4) {
        int old;
        /* switch to the callback's $gp; C has no way to read or set it */
        asm volatile("move %0,$28\n\tlw $28,%1" : "=r"(old) : "m"(D_01e331cc));
        cb(D_01e331d0);
        asm volatile("move $28,%0" : : "r"(old));
    }
}
