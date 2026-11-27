/* libkernl_00310048.c: Sony PS2 Runtime Library 3.0.0 libkernl: timer API, 0x310048-0x310958.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern void EIntr(void);
extern long func_0030ff08(void);
extern void func_0030fc28_c(void *) asm("func_0030fc28");
extern void func_0030fba0_c(void *) asm("func_0030fba0");
extern void func_0030fa10(long);
extern int func_0030ffd8(void);
extern void func_002fde18(void *, int, int);
extern unsigned long func_00312db8(unsigned long a, unsigned long b);

/* ---- 0x310048 */
int func_00310048(void)
{
    int s = DIntr();
    int r = func_0030ffd8();
    if (s) EIntr();
    return r;
}

/* ---- 0x310090 */
typedef struct Blk_w1260 { struct Blk_w1260 *next; int x4; volatile unsigned int id; int flags; } Blk_w1260;
typedef struct { int x0, x4, x8, xc; int count; Blk_w1260 *free; int x18; unsigned int cur; } Mgr_w1260;
extern Mgr_w1260 D_00367118_a asm("D_00367118");
int func_00310090(unsigned int id)
{
    Blk_w1260 *b = (Blk_w1260 *)((id >> 10) << 6);
    if ((int)id < 0 || (id & 0x3ff) != b->id)
        return 0x80008002;
    if (D_00367118_a.cur == id)
        return 0x80000010;
    if (b->flags & 2)
        func_0030fc28_c(b);
    b->id = 0;
    b->flags = 0;
    b->next = D_00367118_a.free;
    D_00367118_a.free = b;
    D_00367118_a.count--;
    return 0;
}

/* ---- 0x310130 */
int func_00310130(int a)
{
    int s = DIntr();
    int r = func_00310090(a);
    if (s) EIntr();
    return r;
}

/* ---- 0x310180 */
struct S7118 { int a, b, c, d, e; };
extern struct S7118 D_00367118_b asm("D_00367118");
int func_00310180(int *p, int *q)
{
    volatile struct S7118 *s = &D_00367118_b;
    if (s->c < 0) return 0x80008001;
    if (p) *p = s->e;
    if (q) *q = 128 - s->e;
    return 0;
}

/* ---- 0x3101d0 */
int func_003101d0(int *a, int *b)
{
    int s = DIntr();
    int r = func_00310180(a, b);
    if (s)
        EIntr();
    return r;
}

/* ---- 0x310230 */
typedef struct { int x0, x4, x8, xc; long x10; } T_c;
typedef struct { char pad[0x1c]; int x1c; } G_c;
extern G_c D_00367118_c asm("D_00367118");
int func_00310230(int id)
{
    T_c *p = (T_c *)(((unsigned int)id >> 10) << 6);
    long s;
    if (id < 0 || (id & 0x3ff) != p->x8)
        return 0x80008002;
    if (((volatile G_c *)&D_00367118_c)->x1c == id)
        return 0x80000010;
    if (p->xc & 1)
        return 1;
    s = func_0030ff08();
    p->x10 = s;
    p->xc |= 1;
    if (p->xc & 2) {
        func_0030fba0_c(p);
        func_0030fa10(s);
    }
    return 0;
}

/* ---- 0x3102e0 */
int func_003102e0(int a)
{
    int s = DIntr();
    int r = func_00310230(a);
    if (s) EIntr();
    return r;
}

/* ---- 0x310330 */
typedef struct { int x0, x4; unsigned int id; unsigned int flags; long start; long total; } Ctr;
typedef struct { int x0, x4, x8, xc; int count; Ctr *free; int x18; volatile unsigned int cur; } Mgr;
extern Mgr D_00367118_d asm("D_00367118");
int func_00310330(unsigned int id)
{
    Ctr *c = (Ctr *)((id >> 10) << 6);
    long now;
    unsigned int f;
    if ((int)id < 0 || (id & 0x3ff) != c->id)
        return 0x80008002;
    if (D_00367118_d.cur == id)
        return 0x80000010;
    if (!(c->flags & 1))
        return 0;
    now = func_0030ff08();
    f = c->flags;
    c->total += now - c->start;
    c->flags = f & ~1;
    if (f & 2) {
        func_0030fc28_c(c);
        func_0030fa10(now);
    }
    return 1;
}

/* ---- 0x3103f8 */
int func_003103f8(int a)
{
    int s = DIntr();
    int r = func_00310330(a);
    if (s) EIntr();
    return r;
}

/* ---- 0x310448 */
long func_00310448(unsigned int id, long val)
{
    Ctr *c = (Ctr *)((id >> 10) << 6);
    int st = DIntr();
    long old, now;
    if ((int)id < 0 || (id & 0x3ff) != c->id || D_00367118_d.cur == id) {
        if (st)
            EIntr();
        return -1;
    }
    old = c->total;
    if (c->flags & 1) {
        now = func_0030ff08();
        old += now - c->start;
        c->start = now;
        c->total = val;
    } else
        c->total = val;
    if (st)
        EIntr();
    return old;
}

/* ---- 0x310518 */
typedef struct { int f0, f4, f8, fc; long f10, f18; } T_e;
long func_00310518(int id)
{
    T_e *t = (T_e *)(((unsigned)id >> 10) << 6);
    if (id < 0 || (id & 0x3ff) != t->f8) return -1;
    if (t->fc & 1) return t->f10 - t->f18;
    return 0;
}

/* ---- 0x310560 */
extern int func_00310518_i(int) asm("func_00310518");
int func_00310560(int a)
{
    int s = DIntr();
    int r = func_00310518_i(a);
    if (s) EIntr();
    return r;
}

/* ---- 0x3105b0 */
typedef struct { int p0, p4; int id; int flags; long start; long acc; } Tm;
long func_003105b0(int id)
{
    Tm *t = (Tm *)(((unsigned int)id >> 10) << 6);
    long r;
    if (id < 0 || (id & 0x3ff) != t->id)
        return -1;
    r = t->acc;
    if (t->flags & 1)
        r += func_0030ff08() - t->start;
    return r;
}

/* ---- 0x310620 */
extern int func_003105b0_i(int) asm("func_003105b0");
int func_00310620(int a)
{
    int s = DIntr();
    int r = func_003105b0_i(a);
    if (s) EIntr();
    return r;
}

/* ---- 0x310670 */
struct AL { int pad0[2]; int id; unsigned int flags; int pad1[4]; long long time; void (*handler)(); void *gp; void *arg; };
extern int func_0030fa10_i(int) asm("func_0030fa10");
extern int func_0030ff08_i(void) asm("func_0030ff08");
struct KS { int pad[7]; int cur; };
extern struct KS D_00367118_f asm("D_00367118");
int func_00310670(int id, long long time, void (*handler)(), void *arg)
{
    struct AL *p = (struct AL *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3ff) != p->id)
        return 0x80008002;
    if (((volatile struct KS *)&D_00367118_f)->cur == id)
        return 0x80000010;
    if (p->flags & 2)
        func_0030fc28_c(p);
    p->handler = handler;
    if (handler == 0) {
        p->flags &= ~2U;
    } else {
        p->time = time;
        p->flags |= 2;
        asm volatile("sw $gp,%0" : "=m"(p->gp) : : "memory");
        p->arg = arg;
        if (p->flags & 1)
            func_0030fba0_c(p);
    }
    func_0030fa10_i(func_0030ff08_i());
    return 0;
}

/* ---- 0x310768 */
extern int func_00310670_i(int, int, int, int) asm("func_00310670");
int func_00310768(int a, int b, int c, int d)
{
    int s = DIntr();
    int r = func_00310670_i(a, b, c, d);
    if (s) EIntr();
    return r;
}

/* ---- 0x3107e8 */
void func_003107e8(unsigned long clock, int *sec, int *usec)
{
    int s = func_00312db8(clock, 147456000);
    if (sec)
        *sec = s;
    if (usec)
        *usec = func_00312db8((clock - (unsigned long)(unsigned int)s * 147456000) * 1000000, 147456000);
}

/* ---- 0x310890 */
unsigned long func_00310890(unsigned int s, unsigned int u)
{
    unsigned long x = (unsigned long)s * 147456000;
    return x + func_00312db8((unsigned long)u * 147456000, 1000000);
}

/* ---- 0x310900 */
extern float __floatdisf(long);
float func_00310900(unsigned long x)
{
    float d;
    float n = 147456000.0f;
    float r;
    if ((long)x >= 0)
        d = __floatdisf(x);
    else {
        d = __floatdisf((x & 1) | (x >> 1));
        d = d + d;
    }
    __asm__(".set noreorder\n\tnop\n\tnop\n\tdiv.s %0,%1,%2\n\t.set reorder" : "=f"(r) : "f"(n), "f"(d));
    return r;
}
