/* Sony PS2 Runtime Library: libkernl kernel-mode alarm interrupt handler (0x366xxx). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct {
    unsigned short id;
    int bit;
    int arg;
    int arg2;
    int gp;
} Alarm;

extern int D_80076700;
extern unsigned long D_80076708;
extern Alarm D_80076740[];
extern void func_00076460(int id);
extern void func_00076680(int a0, int a1, int a2, int a3, int t0);

void func_00366df8(void)
{
    int i;
    int oldgp;
    Alarm e;

    for (i = 0; i < D_80076700; i++) {
        if (D_80076740[0].id != D_80076740[i].id) {
            func_00076460(D_80076740[i].id);
            break;
        }
    }
    do {
        e = D_80076740[0];
        D_80076700--;
        for (i = 0; i < D_80076700; i++)
            D_80076740[i] = D_80076740[i + 1];
        asm volatile("move %0,$gp" : "=r"(oldgp));
        asm volatile("move $gp,%0" : : "r"(e.gp));
        D_80076708 &= ~(1UL << e.bit);
        func_00076680(0x82000, e.arg, e.bit, e.id, e.arg2);
        asm volatile("move $gp,%0" : : "r"(oldgp));
    } while (D_80076700 > 0 && e.id == D_80076740[0].id);
    if (D_80076700 > 0)
        func_00076460(D_80076740[0].id);
    else
        *(volatile int *)0xb0001810 = 1155;
    asm volatile("sync; ei");
}
