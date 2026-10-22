/* Sony PS2 Runtime Library 3.0.0: libkernl semaphore code (00310c60). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct Sem_w8025 { struct Sem_w8025 *next; volatile int id; } Sem_w8025;
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern int func_00310130(int);
extern Sem_w8025 *D_01e3b300;

int func_00310c60(unsigned int id)
{
    int s, t;
    Sem_w8025 *p = (Sem_w8025 *)((id >> 8) << 4);
    s = func_0030edb0();
    if ((int)id < 0 || ((id ^ p->id) & 0xff)) {
        if (s)
            func_0030ee00();
        return 0x80008002;
    }
    t = func_00310130(p->id);
    p->next = D_01e3b300;
    D_01e3b300 = p;
    p->id = 0;
    if (s)
        func_0030ee00();
    return 0;
}
