/* Sony PS2 Runtime Library 3.0.0: libdma (libdma.a), 0x2f3490-0x2f3cd4. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): the whole object is compiled as one file. Its .rodata (the sync
 * timeout string and the channel/env tables) is at 0x3767d0; its globals (channel table 0x363c90,
 * saved env 0x1e2d960) stay retail data and are declared extern. */
typedef unsigned int u32;
typedef unsigned int u_int;

extern int DIntr(void);
extern void EIntr(void);
extern int func_003080d0(const char *, ...);

extern void func_002f3c28_v(void *) asm("func_002f3c28");
extern void func_002f3490_2(void *, int) asm("func_002f3490");

/* 0x2f3490 wait until the channel stops (CHCR.STR), reset it on timeout */
void func_002f3490(volatile int *d)
{
    int i = 0x1000000;
    while (*d & 0x100) {
        if (--i < 0) {
            func_003080d0("libdma: sync timeout\n");
            func_002f3c28_v(d);
        }
    }
}

/* 0x2f3500 wait until the channel's QWC is at least n */
typedef struct { int p0, p4, p8, pc; volatile unsigned int p10; } Q_3500;
void func_002f3500(Q_3500 *q, unsigned int n, int t)
{
    int c = 0x01000000;
    if (t) c = t;
    while (q->p10 < n) {
        if (--c < 0) {
            func_003080d0("libdma: sync timeout\n");
            func_002f3c28_v(q);
        }
    }
}

/* 0x2f3588 map a scratchpad address (0x7xxxxxxx) to its DMA form */
unsigned int func_002f3588(unsigned int a)
{
    if ((a >> 28) == 7) {
        a &= 0x0fffffff;
        a |= 0x80000000;
    }
    return a;
}

/* 0x2f35b0 */
void func_002f35b0(char *p, int n)
{
    while (n--)
        *p++ = 0;
}

/* 0x2f35e8 sceDmaGetChan */
extern int D_00363c90[];
int func_002f35e8(unsigned int a) asm("_Z16ctarget_002f35e8jjjj");
int func_002f35e8(unsigned int a)
{
    if (a < 10)
        return D_00363c90[a];
    return 0;
}

/* channels with tag address/save registers */
const int D_003767e8[10] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 };

/* 0x2f3610 sceDmaReset */
typedef struct { int x0; int p0[3]; int x10; int p1[7]; int x30; int p2[3]; int x40; int p3[3]; int x50; int p4[11]; int x80; } Ch_3610;
extern Ch_3610 *D_00363c90_c[] asm("D_00363c90");
extern int func_002f36f0_v(void *) asm("func_002f36f0");
int func_002f3610(int mode)
{
    int buf[8];
    int r;
    int i;
    r = *(volatile u_int *)0x1000e000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_003767e8[i]) {
            D_00363c90_c[i]->x0 = 0;
            D_00363c90_c[i]->x30 = 0;
            D_00363c90_c[i]->x10 = 0;
            D_00363c90_c[i]->x50 = 0;
            D_00363c90_c[i]->x40 = 0;
            D_00363c90_c[i]->x80 = 0;
        }
    }
    *(u_int *)0x1000e010 = 0xff1f;
    *(u_int *)0x1000e010 = *(volatile u_int *)0x1000e010 & 0xff1f0000;
    func_002f35b0((char *)buf, 20);
    func_002f36f0_v(buf);
    if (mode == 1)
        *(u_int *)0x1000e000 = *(u_int *)0x1000e000 | 1;
    return r;
}

/* 0x2f36f0 sceDmaPutEnv */
typedef struct {
    unsigned char sts, std, mfd, rcyc;
    unsigned short express, notify;
    unsigned short sqwc, tqwc;
    void *rbadr;
    unsigned int rbsz;
} DmaEnv;

const unsigned char D_00376810[10] = { 0, 0, 0, 3, 0, 1, 0, 0, 2, 0 };
const unsigned char D_00376820[10] = { 0, 1, 2, 0, 0, 0, 3, 0, 0, 0 };
const unsigned char D_00376830[10] = { 0, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
extern DmaEnv D_01e2d960;

int func_002f36f0(DmaEnv *env)
{
    unsigned int ctrl = *(volatile unsigned int *)0x1000e000;
    unsigned int pcr = *(volatile unsigned int *)0x1000e020;
    unsigned int sqwc = *(volatile unsigned int *)0x1000e030;
    unsigned int rbor = *(volatile unsigned int *)0x1000e050;
    unsigned int rbsr = *(volatile unsigned int *)0x1000e040;

    if (env->sts >= 10) return -1;
    if (env->std >= 10) return -2;
    if (env->mfd >= 10) return -3;
    if (env->rcyc >= 7) return -4;
    ctrl = (ctrl & ~0x30) | (D_00376810[env->sts] << 4);
    ctrl = (ctrl & ~0xc0) | (D_00376820[env->std] << 6);
    ctrl = (ctrl & ~0x0c) | (D_00376830[env->mfd] << 2);
    if (env->rcyc) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (unsigned int)env->rbadr;
    rbsr = env->rbsz;
    *(volatile unsigned int *)0x1000e000 = ctrl;
    *(volatile unsigned int *)0x1000e020 = pcr;
    *(volatile unsigned int *)0x1000e030 = sqwc;
    *(volatile unsigned int *)0x1000e050 = rbor;
    *(volatile unsigned int *)0x1000e040 = rbsr;
    D_01e2d960 = *env;
    return 0;
}

/* 0x2f38c8 (gap) sceDmaGetEnv: the env last set by sceDmaPutEnv */
DmaEnv *func_002f38c8(DmaEnv *env)
{
    *env = D_01e2d960;
    return env;
}

/* 0x2f3900 (gap) sceDmaPutStallAddr: set D_STADR, return the old value */
u_int func_002f3900(u_int addr)
{
    u_int *p = (u_int *)0x1000e060;
    u_int old = *p;
    *p = addr;
    return old;
}

/* 0x2f3918 sceDmaSend (normal mode) */
void func_002f3918(int *p, int b)
{
    int r = func_002f3588(b);
    func_002f3490(p);
    if ((unsigned int)p[12] != 0xffffffff)
        p[12] = r;
    p[8] = 0;
    p[0] = (p[0] & ~0xc) | 0x105;
}

/* 0x2f3980 / 0x2f39f8 */
typedef struct { int flags; int pad[3]; unsigned int x10; int pad2[3]; int x20; } Ch_w1055;
void func_002f3980(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    func_002f3490((int *)c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    c->flags = (c->flags & ~0xc) | 0x101;
}

void func_002f39f8(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    func_002f3490((int *)c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    c->flags = (c->flags & ~0xc) | 0x109;
}

/* 0x2f3a70 */
typedef struct { int f0; int f4, f8, fc, f10, f14, f18, f1c, f20; } Q_3a70;
void func_002f3a70(Q_3a70 *q)
{
    func_002f3490((int *)q);
    q->f20 = 0;
    q->f0 = (((q->f0 & ~0xc) | 4) & ~1) | 0x100;
}

/* 0x2f3ab8 */
void func_002f3ab8(Ch_w1055 *c, int a, int b)
{
    int v = func_002f3588(a);
    unsigned int f;
    func_002f3490((int *)c);
    if (c->x10 != 0xffffffff)
        c->x10 = v;
    c->x20 = b;
    f = c->flags & ~0xc;
    c->flags = f;
    c->flags = (c->flags & ~1) | 0x100;
}

/* 0x2f3b38 */
typedef struct { int flags; int p4, p8, pc; u32 x10; int p14, p18, p1c; int x20; } Fd;
void func_002f3b38(Fd *f, int a, int b)
{
    int r = func_002f3588(a);
    func_002f3490((int *)f);
    if (f->x10 != 0xffffffff)
        f->x10 = r;
    f->x20 = b;
    f->flags = (((f->flags & ~0xc) | 8) & ~1) | 0x100;
}

/* 0x2f3bb8 sceDmaSync */
int func_002f3bb8(unsigned int *p, int a)
{
    if (a == 1)
        return (*p >> 8) & 1;
    func_002f3490_2(p, a);
    return 0;
}

/* 0x2f3bf0 sceDmaSyncN */
int func_002f3bf0(int *p, unsigned int a, int b, int c)
{
    if (b == 1)
        return (unsigned int)p[4] < a;
    func_002f3500((Q_3500 *)p, a, c);
    return 0;
}

/* 0x2f3c28 stop a channel (CHCR.STR off) with the DMA suspended */
int func_002f3c28(volatile u32 *p)
{
    int st; u32 v, old, c, m;
    st = DIntr();
    v = *(volatile u32 *)0x1000f520;
    if (!(v & 0x10000)) *(volatile u32 *)0x1000f590 = v | 0x10000;
    m = 0xfffffeff;
    c = *(volatile u32 *)0x1000e000;
    old = *p;
    *p = old & m;
    *(volatile u32 *)0x1000f590 = v;
    if (st) EIntr();
    return old;
}

/* 0x2f3cc0 (gap) write CHCR, return the old STR bit */
int func_002f3cc0(u32 *chcr, u32 v)
{
    u32 old = *chcr;
    *chcr = v;
    return (old >> 8) & 1;
}
