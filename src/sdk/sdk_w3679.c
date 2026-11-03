/* libkernl (Sony PS2 Runtime Library): kernel-mode ReleaseAlarm, built with ee-gcc 2.9-991111 -O2 -G0.
 * Partial asm (no instructions): the T3_COUNT address goes through an empty asm so the load is a plain
 * (non-volatile) lw that reorg can put in the jal delay slot, as in the original. */
typedef struct { unsigned short target; unsigned short time; int id; void *callback; void *common; void *gp; } Alarm;
extern int D_80076700;
extern unsigned long D_80076708;
extern Alarm D_80076740[];
extern int func_00076038(int, int);
extern void func_00076460(int);

int func_00366c10(int id)
{
    int i, j;
    int ret = -1;
    unsigned short time;

    if (D_80076700 > 0) {
        for (i = 0; i < D_80076700; i++) {
            if (id == D_80076740[i].id) {
                if (D_80076740[i].target == *(volatile int *)0xb0001820) {
                    if (*(volatile int *)0x1000f000 & 0x1000)
                        return -1;
                }
                time = D_80076740[i].time;
                for (j = i; j < D_80076700 - 1; j++)
                    D_80076740[j] = D_80076740[j + 1];
                D_80076700--;
                D_80076708 &= ~(1UL << id);
                if (i == 0)
                    func_00076460(D_80076740[0].target);
                if (D_80076700 == 0)
                    *(volatile int *)0xb0001810 = 0x83;
                {
                    int *t3c = (int *)0xb0001800; /* T3_COUNT */
                    __asm__("" : "+r"(t3c));
                    ret = func_00076038(time, *t3c) - time;
                }
                break;
            }
        }
    }
    __asm__ volatile("sync");
    return ret;
}
