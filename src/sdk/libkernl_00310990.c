/* libkernl_00310990.c: Sony PS2 Runtime Library 3.0.0 libkernl: timer alarms and semaphore helpers, 0x310990-0x310f34.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit.
 * Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern void EIntr(void);
extern int func_0030ffd8(void);
extern void func_002fde18(void *, int, int);

/* ---- 0x310990 */
typedef struct E { struct E *next; int a, b, c; } E;
extern E D_01e3af00[64];
extern E *D_01e3b300_e asm("D_01e3b300");
int func_00310990(void)
{
    int i;
    D_01e3b300_e = D_01e3af00;
    for (i = 0; i < 64; i++)
        D_01e3af00[i].next = &D_01e3af00[i + 1];
    D_01e3af00[63].next = 0;
    return 0;
}

/* ---- 0x3109e0 */
typedef struct Node { struct Node *next; int x4; int (*fn)(unsigned int, int, int, int); int arg; } Node;
extern int D_01e3b300_i asm("D_01e3b300");
int func_003109e0(unsigned int a, int b, int c, Node* n)
{
    int r = n->fn(((unsigned int)n << 4) | (a & 0xfe) | 1, b, c, n->arg);
    if (r == 0) {
        asm volatile("");
        n->next = (Node *)D_01e3b300_i;
        D_01e3b300_i = (int)n;
        n->x4 = 0;
        return -1;
    }
    return r;
}

/* ---- 0x310a40 */
typedef struct Alarm { struct Alarm *next; volatile int id; void *handler; void *arg; } Alarm;
extern Alarm *D_01e3b300_a asm("D_01e3b300");
extern void func_00310768_v(int, long, void *, void *) asm("func_00310768");
extern void func_003102e0_v(int) asm("func_003102e0");
static inline Alarm *alloc_alarm(void)
{
    Alarm *a = D_01e3b300_a;
    if (a)
        D_01e3b300_a = a->next;
    return a;
}
static inline void free_alarm(Alarm *a)
{
    a->next = D_01e3b300_a;
    D_01e3b300_a = a;
}
int func_00310a40(long time, void *handler, void *arg)
{
    Alarm *a;
    int st;
    int id;
    if (handler == 0)
        return 0x80000016;
    st = DIntr();
    a = alloc_alarm();
    if (a == 0) {
        if (st)
            EIntr();
        return 0x80008005;
    }
    id = func_00310048();
    if (id < 0) {
        free_alarm(a);
        a->id = 0;
        if (st)
            EIntr();
        return id;
    } else {
        a->handler = handler;
        a->arg = arg;
        a->id = id;
        func_00310768_v(id, time, func_003109e0, a);
        func_003102e0_v(id);
        if (st)
            EIntr();
    }
    return ((int)a << 4) | (id & 0xfe) | 1;
}

/* ---- 0x310b70 */
struct MC { struct MC *next; volatile int id; int a; int b; };
extern struct MC *D_01e3b300_m asm("D_01e3b300");
extern int func_00310670_m(int, int, void *, void *) asm("func_00310670");
static __inline__ struct MC *mc_alloc(void)
{
    struct MC *p = D_01e3b300_m;
    if (p)
        D_01e3b300_m = p->next;
    return p;
}
static __inline__ void mc_free(struct MC *p)
{
    struct MC *h = D_01e3b300_m;
    D_01e3b300_m = p;
    p->next = h;
    p->id = 0;
}
int func_00310b70(int a0, int a1, int a2)
{
    struct MC *p;
    int id;
    if (a1 == 0)
        return 0x80000016;
    p = mc_alloc();
    if (p == 0)
        return 0x80008005;
    id = func_0030ffd8();
    if (id < 0) {
        mc_free(p);
        return id;
    }
    p->a = a1;
    p->b = a2;
    p->id = id;
    func_00310670_m(id, a0, func_003109e0, p);
    func_00310230(id);
    return ((int)p << 4) | (id & 0xfe) | 1;
}

/* ---- 0x310c60 */
typedef struct Sem_w8025 { struct Sem_w8025 *next; volatile int id; } Sem_w8025;
extern Sem_w8025 *D_01e3b300_s asm("D_01e3b300");
int func_00310c60(unsigned int id)
{
    int s, t;
    Sem_w8025 *p = (Sem_w8025 *)((id >> 8) << 4);
    s = DIntr();
    if ((int)id < 0 || ((id ^ p->id) & 0xff)) {
        if (s)
            EIntr();
        return 0x80008002;
    }
    t = func_00310130(p->id);
    p->next = D_01e3b300_s;
    D_01e3b300_s = p;
    p->id = 0;
    if (s)
        EIntr();
    return 0;
}

/* ---- 0x310d08 */
typedef struct { int next; volatile int id; } Sem_w1055;
int func_00310d08(unsigned int id)
{
    Sem_w1055 *s = (Sem_w1055 *)((id >> 8) << 4);
    int r, t;
    if ((int)id < 0 || ((id ^ s->id) & 0xff))
        return 0x80008002;
    r = func_00310090(s->id);
    if (r == 0) {
        t = D_01e3b300_i;
        D_01e3b300_i = (int)s;
        s->next = t;
        s->id = 0;
    }
    return r;
}

/* ---- 0x310d80 */
extern int D_00367138_i asm("D_00367138");
extern int D_0036713c_i asm("D_0036713c");
extern char D_01e3b308_c[] asm("D_01e3b308");
void func_00310d80(void) { D_00367138_i = 0; D_0036713c_i = 0; func_002fde18(D_01e3b308_c, 0, 512); }

/* ---- 0x310da8 (gap) */
struct E1324 { int a; int b; int gp; int pad; };
extern struct E1324 *D_00367138;
extern unsigned int D_0036713c;
extern struct E1324 D_01e3b308[];
struct E1324 *func_00310da8(struct E1324 *tbl, unsigned int n)
{
    int s = DIntr();
    struct E1324 *old = D_00367138;
    D_00367138 = tbl;
    D_0036713c = n;
    func_002fde18(tbl, 0, n << 4);
    if (s)
        EIntr();
    return old;
}

/* ---- 0x310e28 */
int func_00310e28(int id, int a, int b)
{
    struct E1324 *t, *p;
    unsigned int n;
    int s;
    if (id < 0) {
        t = D_01e3b308;
        id &= 0x7fffffff;
        n = 32;
    } else {
        t = D_00367138;
        n = D_0036713c;
    }
    if ((unsigned int)id >= n)
        return 0x80000069;
    s = DIntr();
    p = (struct E1324 *)((id << 4) + (int)t);
    p->a = a;
    p->b = b;
    { int g; asm volatile("move %0,$gp" : "=r"(g)); p->gp = g; }
    if (s)
        EIntr();
    return 0;
}

/* ---- 0x310ee0 (gap) */
int func_00310ee0(int id)
{
    struct E1324 *t;
    unsigned int n;
    if (id < 0) {
        t = D_01e3b308;
        id &= 0x7fffffff;
        n = 32;
    } else {
        t = D_00367138;
        n = D_0036713c;
    }
    if ((unsigned int)id >= n)
        return -105;
    ((struct E1324 *)((id << 4) + (int)t))->a = 0;
    return 0;
}
