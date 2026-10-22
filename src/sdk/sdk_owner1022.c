/* Sony PS2 Runtime Library 3.0.0: libkernl (sifcmd). Built with ee-gcc 2.9-991111 -O2 -G0. */

/* sifcmd/sifrpc (libkernl) */
struct H1324 { unsigned short a; unsigned short b; unsigned short size; unsigned char c; unsigned char d; int e; };
struct D1324 { volatile int id; volatile int a; volatile int b; volatile int c; struct H1324 *h; void *buf; int x; };
extern struct D1324 D_01e353d0;
extern char D_01e35400[];
extern char D_01e35540[];
extern void func_003058a0(int);
extern int func_00310fe0(int, void *, void *);
extern int func_00306900(int);
extern void func_003069a8(void);
int func_00306d88(void)
{
    struct D1324 *d = &D_01e353d0;
    struct H1324 *h;
    func_003058a0(0);
    D_01e353d0.id = func_00310fe0(0x210, d, func_003069a8);
    if (D_01e353d0.id < 0)
        return 0;
    d->c = 0;
    d->a = 0;
    d->b = 0;
    d->buf = (void *)((int)D_01e35540 | 0x20000000);
    h = (struct H1324 *)((int)D_01e35400 | 0x20000000);
    d->h = h;
    h->size = 0x210;
    h->c = 0x45;
    h->d = 0x48;
    h->b = 0;
    h->e = 0;
    d->x = func_00306900(256);
    return 1;
}
