/* Sony PS2 Runtime Library 3.0.0: libkernl (0x3050xx-0x311xxx) and libc/libdbc helpers (0x2f5c70). ee-gcc 2.9-991111 -O2 -G0. */
extern int D_00366180;
extern char D_01e38e68[];
extern int func_002fde18(void *, int, int);
int func_0030df00(void)
{
    D_00366180 = -1;
    func_002fde18(D_01e38e68, 0, 4);
    return 0;
}

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

typedef struct { int size; int count; char *rd; int pad; char buf[1]; } Ring;
void func_00306968(Ring *r)
{
    r->count--;
    r->rd++;
    if (r->rd == r->buf + r->size) r->rd = r->buf;
}

extern int func_00308780(int, int, int, int, int, int, int);
int func_003088b8(int a, int b, int c, int d, int e, int f)
{
    return func_00308780(a, 0, b, c, d, e, f);
}
int func_003088f8(int a, int b, int c, int d, int e, int f)
{
    return func_00308780(a, 1, b, c, d, e, f);
}

typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int id; } Sem2;
typedef struct { Sem2 *s; int id; } Ref;
int func_003096b8(Ref *r)
{
    Sem2 *s = r->s;
    if (s == 0 || r->id != s->id || !(s->flags & 1)) return 0;
    return 1;
}

typedef struct { int a, b, c, d; char pad[804]; } Ent;
extern int D_00363d28;
extern Ent D_01e2fe48[16];
int func_002f5c70(void)
{
    int i;
    D_00363d28 = 1;
    for (i = 0; i < 16; i++) {
        D_01e2fe48[i].a = 0;
        D_01e2fe48[i].b = 0;
        D_01e2fe48[i].c = 0;
        D_01e2fe48[i].d = 0;
    }
    return 1;
}

typedef struct { char pad[0x1c]; char *tab; int n; } Tbl;
extern void* func_00308dc0(Tbl *, int);
void* func_00308df0(Tbl *t, int i)
{
    if (i < 0 || i >= t->n) return func_00308dc0(t, i);
    return t->tab + i * 64;
}

typedef struct { char pad[0x24]; int x, y, z; } Arg;
int func_00308f00(int a, int b, int c, Arg *d)
{
    if (func_003088f8(0x80000008, (int)d, 64, d->x, d->y, d->z)) return 0;
    return 0x800;
}
int func_003091c8(int a, int b, int c, int d)
{
    if (func_003088f8(0x80000008, d, 64, 0, 0, 0)) return 0;
    return 0x800;
}

extern int func_00309988(int);
extern void func_003099e0(int);
extern void func_00305540(void);
void func_00309ba8(int a)
{
    int r;
    for (;;) {
        while ((r = func_00309988(a)) != 0) func_003099e0(r);
        func_00305540();
    }
}

extern int func_00305a80(void);
extern int func_00311530(void);
extern int func_00305a90(void);
int func_003114f0(void)
{
    if (func_00305a80() == 0x2000000) return func_00311530();
    return func_00305a90();
}
