/* Sony PS2 Runtime Library 3.0.0: libkernl / libcdvd / libmc helpers. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int p0, p4, p8, pc; volatile unsigned int p10; } Q;
extern int D_003767d0;
extern void func_003080d0(void *);
extern void func_002f3c28(Q *);
void func_002f3500(Q *q, unsigned int n, int t)
{
    int c = 0x01000000;
    if (t) c = t;
    while (q->p10 < n) {
        if (--c < 0) {
            func_003080d0(&D_003767d0);
            func_002f3c28(q);
        }
    }
}

typedef struct N { struct N *next; struct N *prev; int p8, pc; unsigned long long a; unsigned long long b; unsigned long long c; } N;
typedef struct { int pad[6]; N *head; } NL;
extern NL D_00367118;
void func_0030fba0(N *n)
{
    N *prev = 0;
    N *p = D_00367118.head;
    unsigned long long k = n->c + n->a - n->b;
    while (p && p->c + p->a - p->b <= k) {
        prev = p;
        p = p->next;
    }
    n->prev = prev;
    n->next = p;
    if (p) p->prev = n;
    if (prev) prev->next = n;
    else D_00367118.head = n;
}

extern int DIntr(void);
extern void EIntr();
extern unsigned char func_00308248(int, int, int);
extern unsigned char func_003059e0(int, int);
extern int D_003660d8;
int func_00308310(int a, int b)
{
    int s = DIntr();
    if (D_003660d8) {
        if (s) EIntr();
        return func_00308248(a, b, 0);
    } else {
        if (s) EIntr();
        return func_003059e0(a, b);
    }
}

extern char D_01e33a40[];
extern int D_00365950;
extern unsigned int strlen(char *);
extern char* memcpy(char *, char *, unsigned int);
extern void func_00305650(int);
void func_002fc7d8(char *buf)
{
    unsigned int n;
    if (buf) {
        if (strlen((char *)((int)D_01e33a40 | 0x20000000)) < 0x400) n = strlen((char *)((int)D_01e33a40 | 0x20000000));
        else n = 0x3ff;
        memcpy(buf, (char *)((int)D_01e33a40 | 0x20000000), n);
        buf[n] = 0;
    }
    func_00305650(D_00365950);
}

extern int memcmp(void *, void *, int);
extern char D_003660c4[];
extern char *D_00366178;
extern char D_01e389a8[];
int func_0030a600(void)
{
    int r = 0;
    char *q = D_003660c4; char *p = D_01e389a8;
    if (memcmp(p, q, 4) && memcmp(p, D_00366178, 4))
        r = memcmp(q, D_00366178, 4) != 0;
    return r;
}

extern char *D_00366184;
extern char D_01e38e68[];
int func_0030de70(void)
{
    int r = 0;
    char *q = D_003660c4; char *p = D_01e38e68;
    if (memcmp(p, q, 4) && memcmp(p, D_00366184, 4))
        r = memcmp(q, D_00366184, 4) != 0;
    return r;
}

typedef struct L { int pad[5]; struct L *next; } L;
typedef struct { int pad[10]; L *head; } LH;
extern LH D_01e37200;
L* func_003098f8(L *n)
{
    L *p;
    DIntr();
    p = D_01e37200.head;
    if (p == n) {
        D_01e37200.head = p->next;
    } else {
        while (p) {
            if (p->next == n) { p->next = n->next; break; }
            p = p->next;
        }
    }
    EIntr();
    return p;
}

extern int func_0030dd70(void);
extern int sceSifCallRpc(void *, int, int, int *, int, int *, int, int, int);
extern int D_01e38c40;
extern char D_01e38e40[];
int func_0030e348(int a)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40 = a;
    if (sceSifCallRpc(D_01e38e40, 8, 0, &D_01e38c40, 4, &D_01e38c40, 4, 0, 0) < 0) return 0xfffeffff;
    return D_01e38c40;
}
int func_0030e478(int a)
{
    if (func_0030dd70() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40 = a;
    if (sceSifCallRpc(D_01e38e40, 10, 0, &D_01e38c40, 4, &D_01e38c40, 4, 0, 0) < 0) return 0xfffeffff;
    return D_01e38c40;
}
