/* libkernl (Sony PS2 Runtime Library): kernel-mode SetAlarm patch (T3_COUNT 0xb0001800, alarm table at 0x80076740),
 * built with ee-gcc 2.9-991111 -O2 -G0. The field types of Alarm matter for scheduling: id/gp are int,
 * callback is a function pointer, common a data pointer (different alias sets in sched1/sched2).
 * Partial asm (one instruction): $gp is read through `move` as in libkernl_00310048.c. */
typedef void (*Fn)();
typedef struct { unsigned short target; unsigned short time; int id; Fn callback; void *common; int gp; } Alarm;
extern int D_80076700;
extern unsigned long D_80076708;
extern Alarm D_80076740[];
extern int func_00076058(int, int);
extern void func_00076460(int);

static __inline__ int alloc_id(void)
{
    int i;
    for (i = 0; i < 64; i++) {
        if (!((D_80076708 >> i) & 1)) {
            D_80076708 |= 1UL << i;
            return i;
        }
    }
    return -1;
}

int func_00366ad0(unsigned short time, Fn callback, void *common)
{
    int target, now;
    int id, pos;
    int gp;

    target = time;
    now = *(volatile int *)0xb0001800;
    target += now;
    if (D_80076700 >= 64)
        return -1;
    id = alloc_id();
    if (id < 0)
        return id;
    __asm__ volatile("move %0, $gp" : "=r"(gp));
    pos = func_00076058(now, target);
    D_80076740[pos].callback = callback;
    D_80076740[pos].target = target;
    D_80076740[pos].time = now;
    D_80076740[pos].common = common;
    D_80076740[pos].id = id;
    D_80076740[pos].gp = gp;
    D_80076700++;
    func_00076460(D_80076740[0].target);
    return D_80076740[pos].id;
}
