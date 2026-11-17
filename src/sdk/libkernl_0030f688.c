/* libkernl_0030f688.c: Sony PS2 Runtime Library 3.0.0 libkernl: timer, 0x30f688-0x30fc60.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern void EIntr(void);
extern void func_002fde18(void *, int, int);
extern void func_0030f620(unsigned int, int);

/* ---- 0x30f688 (gap) */
void func_0030f688(void)
{
}

/* ---- 0x30f690 */
void func_0030f690(int a) { func_0030f620(0xb0001000, a); }
void func_0030f6a0(int a) { func_0030f620(0xb0001010, a); }
void func_0030f6b0(int a) { func_0030f620(0xb0001020, a); }

/* ---- 0x30f6c0 */
typedef struct TBlk { struct TBlk *next; int pad[15]; } TBlk;
typedef struct { unsigned long long x0; int handler; int xc; int count; TBlk *free; int x18; } TMgr;
extern TMgr D_00367118_t asm("D_00367118");
extern TBlk D_01e38f00[128];
extern void func_00310990(void);
extern int func_00305310(int, void *, int, void *);
extern int func_0030fc60();
extern void EnableIntc(int);
int func_0030f6c0(int mode)
{
    TMgr *m = &D_00367118_t;
    int i;
    int h;
    int intr;
    unsigned int t;

    if (m->handler >= 0)
        return 0x80008001;
    D_00367118_t.x0 = 0;
    m->count = 0;
    func_002fde18(D_01e38f00, 0, 8192);
    m->free = D_01e38f00;
    for (i = 127; i >= 0; i--)
        D_01e38f00[i].next = &D_01e38f00[i + 1];
    D_01e38f00[127].next = 0;
    func_00310990();
    h = func_00305310(11, func_0030fc60, 0, 0);
    if (h < 0)
        return 0x80009021;
    D_00367118_t.handler = h;
    intr = DIntr();
    t = *(volatile unsigned int *)0x10001010;
    t = (t & ~3) | mode;
    t |= 0x300;
    if (!(t & 0x80)) {
        func_0030f690(0);
        t |= 0xc80;
        func_0030f6b0(0xffff);
    }
    func_0030f6a0(t);
    EnableIntc(11);
    if (intr)
        EIntr();
    return 0;
}

/* ---- 0x30f818 */
extern int func_00305320(int, int);
extern void DisableIntc(int);
struct S1324 { long long a; int b; int pad; volatile int c; };
extern struct S1324 D_00367118_s asm("D_00367118");
int func_0030f818(void)
{
    int s;
    struct S1324 *p = &D_00367118_s;
    if (p->b < 0)
        return 0x80008001;
    if (p->c != 0)
        return 0x80000010;
    s = DIntr();
    if (func_00305320(11, p->b) == 0) {
        DisableIntc(11);
        func_0030f6a0(0xc00);
        func_0030f690(0);
    }
    D_00367118_s.a = 0;
    p->b = -1;
    if (s)
        EIntr();
    return 0;
}

/* ---- 0x30f8d0 (gap) */
int func_0030f8d0(void)
{
    if (D_00367118_t.handler < 0)
        return 0x80008001;
    return *(volatile unsigned int *)0x10001010 & 3;
}

/* ---- 0x30f900 */
extern long func_0030ff08(void);
extern void func_0030fa10(unsigned long now);
int func_0030f900(void)
{
    int st = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (v & 0x80) {
        if (st) EIntr();
        return 1;
    }
    func_0030f6a0((v & ~0xc00) | 0x80);
    func_0030fa10(func_0030ff08());
    if (st) EIntr();
    return 0;
}

/* ---- 0x30f990 */
int func_0030f990(void)
{
    int s = DIntr();
    unsigned int v = *(volatile unsigned int *)0x10001010;
    if (!(v & 0x80)) {
        if (s) EIntr();
        return 0;
    }
    func_0030f6a0(v & 0xfffff37f);
    if (s) EIntr();
    return 1;
}

/* ---- 0x30fa10 */
typedef unsigned long u_long;
typedef struct Al { struct Al *next; int pad[3]; u_long a; u_long b; u_long c; } Al;
typedef struct { int pad[6]; Al *head; int x1c; } AG;
extern AG D_00367118_g asm("D_00367118");
void func_0030fa10(u_long now)
{
    AG *g = &D_00367118_g;
    Al *a;
    unsigned int mode; int sh;
    u_long best, t;
    a = g->head;
    if (g->x1c >= 0) return;
    mode = *(volatile unsigned int *)0x10001010;
    if (a == 0) {
        func_0030f6b0(0);
        func_0030f6a0(mode & ~0x800);
        return;
    }
    best = a->c + a->a - a->b;
    a = a->next;
    if (a) {
        t = a->c + a->a - a->b;
        if (t < best + 0x7333) {
            best = t;
            for (;;) {
                a = a->next;
                if (!a) goto done;
                t = a->c + a->a - a->b;
                if (t >= best + 0x7333) goto done;
                best = t;
            }
        }
    }
done:
    sh = mode & 3;
    if ((long)(best - now) < 0x7333) {
        func_0030f6b0(*(volatile int *)0x10001000 + (int)(0x7333UL >> (sh * 4)));
        func_0030f6a0(mode & ~0x800);
        return;
    }
    func_0030f6a0(mode & ~0x800);
    func_0030f6b0((int)(best >> (sh * 4)));
}

/* ---- 0x30fba0 */
typedef struct N { struct N *next; struct N *prev; int p8, pc; unsigned long long a; unsigned long long b; unsigned long long c; } N;
typedef struct { int pad[6]; N *head; } NL;
extern NL D_00367118_n asm("D_00367118");
void func_0030fba0(N *n)
{
    N *prev = 0;
    N *p = D_00367118_n.head;
    unsigned long long k = n->c + n->a - n->b;
    while (p && p->c + p->a - p->b <= k) {
        prev = p;
        p = p->next;
    }
    n->prev = prev;
    n->next = p;
    if (p) p->prev = n;
    if (prev) prev->next = n;
    else D_00367118_n.head = n;
}

/* ---- 0x30fc28 */
typedef struct Lnk { struct Lnk *next; struct Lnk *prev; } Lnk;
extern Lnk *D_00367130;
Lnk* func_0030fc28(Lnk *n)
{
    Lnk *nx = n->next;
    if (n->prev) n->prev->next = nx;
    else D_00367130 = nx;
    if (nx) nx->prev = n->prev;
    n->prev = 0;
    return nx;
}
