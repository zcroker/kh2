/* Sony PS2 Runtime Library 3.0.0: libcdvd sceCdRead. ee-gcc 2.9-991111 -O2 -G0. One empty asm memory barrier on the failure path keeps the original store order. */
typedef struct { unsigned char trycount, spindlctrl, datapattern, pad; } RMode;
typedef struct { unsigned int lsn, sec; void *buf; unsigned char t, s, d, p; void *ee; void *rd; } RArg;
extern int D_00363db8;
extern int D_00363d90;
extern int D_00363de0;
extern int D_00363db4;
extern int D_00363da8;
extern int D_00364f40;
extern RArg D_00363e80;
extern char D_00364e80[];
extern char D_00364f50[];
extern char D_00376d78[];
extern char D_00376d90[];
extern int func_002f7118(void);
extern int func_002f6fc0(int);
extern void func_00308a80(void *, int);
extern void func_003080d0(void *);
extern int func_00305640(int s);
extern void func_002f6910(void *);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
int func_002f7be8(unsigned int lsn, unsigned int sec, void *buf, RMode *mode)
{
    int size;
    RArg *p = &D_00363e80;
    if (!((*(volatile int*)&D_00363db8) & 1) && func_002f7118() == 6)
        return 0;
    if (!func_002f6fc0(4))
        return 0;
    p->lsn = lsn;
    p->sec = sec;
    p->buf = buf;
    p->t = mode->trycount;
    p->s = mode->spindlctrl;
    p->d = mode->datapattern;
    p->ee = D_00364e80;
    p->rd = &D_00364f40;
    switch (mode->datapattern) {
    case 1: size = sec * 2328; break;
    case 2: size = sec * 2340; break;
    case 0: default: size = sec << 11; break;
    }
    D_00364f40 = 0;
    if (!((*(volatile int*)&D_00363db8) & 2))
        func_00308a80(buf, size);
    func_00308a80(D_00364e80, 144);
    func_00308a80(p, 24);
    func_00308a80(&D_00364f40, 4);
    if (D_00363d90 > 0)
        func_003080d0(D_00376d78);
    (*(volatile int*)&D_00363de0) = 1;
    (*(volatile int*)&D_00363db4) = 1;
    if (func_003094b8(D_00364f50, 1, 1, p, 24, 0, 0, func_002f6910, D_00364e80) < 0) {
        (*(volatile int*)&D_00363de0) = 0;
        __asm__ volatile("" ::: "memory");
        (*(volatile int*)&D_00363db4) = 0;
        func_00305640(D_00363da8);
        return 0;
    }
    if (D_00363d90 > 0)
        func_003080d0(D_00376d90);
    return 1;
}
