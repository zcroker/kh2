/* libkernl_00306698.c: Sony PS2 Runtime Library 3.0.0 libkernl: DelayThread, thread start, Deci2 TTY, 0x306698-0x306e44.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);
typedef struct { int count, max_count, init_count, wait_threads; unsigned int attr; unsigned int option; } SemaParam;
extern int func_00305620(SemaParam *);
extern int func_00305630(int);
extern int func_00305660(int);
extern long func_00310890(int, int);
extern int func_00310a40(long, void *, int);
extern void func_003068d8_v(void) asm("func_003068d8");

int func_00306698(int usec) asm("_Z13func_00306698i");
int func_00306698(int usec)
{
    SemaParam p;
    int st, s, r;
    asm volatile("mfc0 %0, $12" : "=r"(st));
    if (!(st & 0x10000))
        return 0x80008008;
    p.max_count = 1;
    p.option = (unsigned int)"SceKernelDelayThread";
    p.init_count = 0;
    s = func_00305620(&p);
    if (s < 0)
        return 0x80008003;
    r = func_00310a40(func_00310890(0, usec), func_003068d8_v, s);
    if (r < 0) {
        func_00305630(s);
        return r;
    }
    func_00305660(s);
    func_00305630(s);
    return 0;
}

typedef struct { int status; int f4; char *stack; int stackSize; int pad[8]; } ThreadStat;
extern int func_003060f0(void);
extern int func_00305520(int, ThreadStat *);
extern int func_00305440(int, int);
int func_00306760(int tid, int arg)
{
    ThreadStat st;
    int r;
    char *p;
    if (func_003060f0())
        return -1;
    if (!DIntr())
        return -1;
    r = func_00305520(tid, &st);
    if (r < 0) {
        EIntr();
        return r;
    }
    if (st.status != 16) {
        EIntr();
        return -1;
    }
    p = st.stack + st.stackSize - 0x2a0;
    /* hand-written: clear the new thread's saved context with 128-bit stores */
    asm volatile(
        "sq $0,0(%0)\n\t"
        "sq $0,16(%0)\n\t"
        "sq $0,32(%0)\n\t"
        "sq $0,48(%0)\n\t"
        "sq $0,64(%0)\n\t"
        "sq $0,80(%0)\n\t"
        "sq $0,96(%0)\n\t"
        "sq $0,112(%0)\n\t"
        "sq $0,128(%0)\n\t"
        "sq $0,144(%0)\n\t"
        "sq $0,160(%0)\n\t"
        "sq $0,176(%0)\n\t"
        "sq $0,192(%0)\n\t"
        "sq $0,208(%0)\n\t"
        "sq $0,224(%0)\n\t"
        "sq $0,240(%0)\n\t"
        "sq $0,256(%0)\n\t"
        "sq $0,272(%0)\n\t"
        "sq $0,288(%0)\n\t"
        "sq $0,304(%0)\n\t"
        "sq $0,320(%0)\n\t"
        "sq $0,336(%0)\n\t"
        "sq $0,352(%0)\n\t"
        "sq $0,368(%0)\n\t"
        "sq $0,384(%0)\n\t"
        "sq $0,400(%0)\n\t"
        "sq $0,416(%0)\n\t"
        "sq $0,432(%0)\n\t"
        "sq $0,512(%0)\n\t"
        "sq $0,528(%0)\n\t"
        "sq $0,544(%0)\n\t"
        "sq $0,560(%0)\n\t"
        "sq $0,576(%0)\n\t"
        "sq $0,592(%0)\n\t"
        "sq $0,608(%0)\n\t"
        "sq $0,624(%0)\n\t"
        "sll $8,%1,0\n\t"
        "sd $8,64(%0)\n\t"
        "lw $8,448(%0)\n\t"
        "sd $8,448(%0)\n\t"
        "sd $0,456(%0)\n\t"
        "lw $8,464(%0)\n\t"
        "sd $8,464(%0)\n\t"
        "sd $0,472(%0)\n\t"
        "lw $8,480(%0)\n\t"
        "sd $8,480(%0)\n\t"
        "sd $0,488(%0)\n\t"
        "lw $8,496(%0)\n\t"
        "sd $8,496(%0)\n\t"
        "sd $0,504(%0)\n\t"
        : : "r"(p), "r"(arg) : "$8", "memory");
    EIntr();
    return func_00305440(tid, arg);
}

/* Sony PS2 Runtime Library 3.0.0: libkernl (EE kernel wrappers). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned int u32;

extern int* func_00316d08(void);

extern void func_00305650(int);
int func_003068d8(int a, int b, int c, int d) { func_00305650(d); asm volatile("sync.l; ei"); return 0; }

/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int p18; } Sem;


typedef struct { int a; int b; int *c; int *d; int buf[1]; } Hdr;
extern Hdr D_01e352c0;
Hdr* func_00306900(int x)
{
    Hdr *h = &D_01e352c0;
    h->a = x;
    h->b = 0;
    h->d = h->buf;
    h->c = h->buf;
    return h;
}

/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int* func_00316d08(void);

typedef struct { int size; int count; int pad8; char *wp; char buf[1]; } Ring;
void func_00306928(Ring *r)
{
    r->count++;
    r->wp++;
    if (r->wp == &r->buf[r->size])
        r->wp = r->buf;
}

typedef struct { int size; int count; char *rd; int pad; char buf[1]; } RingR;
void func_00306968(RingR *r)
{
    r->count--;
    r->rd++;
    if (r->rd == r->buf + r->size) r->rd = r->buf;
}


typedef struct { int sock; volatile int wlen; volatile int rlen; volatile int busy; char *wbuf; char *rbuf; Ring *ring; } TI;

extern void func_00308150(const char *fmt, ...);
extern int func_00311100(int, char *, unsigned short);
extern int func_00311138(int, char *, unsigned short);
void func_003069a8(int ev, int param, TI *ti)
{
    int i;
    unsigned short *hdr;
    int n, k;
    switch (ev) {
    case 1:
    case 2:
        if (param) {
            if ((unsigned)(ti->rlen + param) > 320)
                func_00308150("TTY: packet size larger than expect\n");
            k = ti->rlen;
            i = func_00311100(ti->sock, ti->rbuf + k, param);
            if (i < 0)
                func_00308150("TTY: receive error");
            ti->rlen += i;
        } else {
            hdr = (unsigned short *)ti->rbuf;
            for (i = 12; i < *hdr; i++) {
                *ti->ring->wp = ti->rbuf[i];
                func_00306928(ti->ring);
            }
            ti->rlen = 0;
        }
        break;
    case 3:
        n = func_00311138(ti->sock, ti->wbuf, ti->wlen);
        if (n < 0) {
            func_00308150("TTY: send err %d\n", n);
            ti->busy = 0;
        } else {
            ti->wbuf += n;
            ti->wlen -= n;
        }
        break;
    case 4:
        if (ti->wlen)
            func_00308150("TTY: err ti->wlen=%08x\n", ti->wlen);
        ti->busy = 0;
        break;
    }
}

/* Sony PS2 Runtime Library 3.0.0: libkernl (deci2 kputs). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { volatile int id; volatile int size; int x8; volatile int busy; char *buf; } Kp;
extern Kp D_01e353d0_k asm("D_01e353d0");
extern char D_01e35400[];
extern int DIntr(void);

extern int func_00311050(int, char);
extern void func_00311080(int);
int func_00306b40(const char *src, int n)
{
    int cnt = 0;
    int i = 0;
    int s;
    char *buf;
    char *d;
    if (D_01e353d0_k.busy != 0)
        return -1;
    s = DIntr();
    D_01e353d0_k.busy = 1;
    buf = (char *)((unsigned int)D_01e35400 | 0x20000000);
    D_01e353d0_k.buf = buf;
    d = buf + 12;
    while (--n != -1) {
        if (*src == '\n') {
            *d++ = '\r';
            i++;
            if (i >= 256)
                break;
        }
        *d++ = *src++;
        i++;
        cnt++;
        if (i >= 256)
            break;
    }
    D_01e353d0_k.size = i + 12;
    *(short *)buf = D_01e353d0_k.size;
    if (func_00311050(D_01e353d0_k.id, buf[7]) < 0) {
        D_01e353d0_k.busy = 0;
        if (s)
            EIntr();
        return -1;
    }
    while (D_01e353d0_k.busy)
        func_00311080(D_01e353d0_k.id);
    if (s)
        EIntr();
    return cnt;
}

typedef struct { int x0; volatile int x4; unsigned char *x8; } Q1328;
typedef struct { int pad[6]; Q1328 *x18; } S1328;
extern S1328 D_01e353d0_q asm("D_01e353d0");
extern void func_00306968_q(Q1328 *) asm("func_00306968");
int func_00306cb8(char *buf, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        while (D_01e353d0_q.x18->x4 == 0)
            ;
        buf[i] = *D_01e353d0_q.x18->x8;
        func_00306968_q(D_01e353d0_q.x18);
        if (buf[i] == '\n' || buf[i] == '\r')
            return i + 1;
    }
    return i;
}

/* Sony PS2 Runtime Library 3.0.0: libkernl (sifcmd). Built with ee-gcc 2.9-991111 -O2 -G0. */

/* sifcmd/sifrpc (libkernl) */
struct H1324 { unsigned short a; unsigned short b; unsigned short size; unsigned char c; unsigned char d; int e; };
struct D1324 { volatile int id; volatile int a; volatile int b; volatile int c; struct H1324 *h; void *buf; int x; };
extern struct D1324 D_01e353d0_d asm("D_01e353d0");
extern char D_01e35400[];
extern char D_01e35540[];
extern void func_003058a0(int);
extern int func_00310fe0(int, void *, void *);


int func_00306d88(void)
{
    struct D1324 *d = &D_01e353d0_d;
    struct H1324 *h;
    func_003058a0(0);
    D_01e353d0_d.id = func_00310fe0(0x210, d, (void *)func_003069a8);
    if (D_01e353d0_d.id < 0)
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
    d->x = (int)func_00306900(256);
    return 1;
}

