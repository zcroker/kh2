/* libkernl_00308b30.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifrpc (init and packet pool), 0x308b30-0x308e30.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);

/* ---- 0x308b30: sceSifInitRpc */
typedef struct { int pid; void *pkt; int pktlen; int u0c; int u10; void *rdata; int rdlen; void *client; int cllen; int u24; } RD;
extern RD D_01e37200;
extern char D_01e35a00[], D_01e36200[], D_01e36a00[];
extern char D_00308e30[], D_00309208[], D_00309428[], D_00308f40[];
extern int D_003660dc;
extern void func_003083d0(void);
extern int func_003086b8(int, void *, void *);
extern int func_00305a30(int);
extern int func_00305a20(int, int);
extern int sceSifSendCmd(int, void *, int, void *, void *, int);
extern int func_00308200(int);
#define UC(p) ((void *)((unsigned int)(p) | 0x20000000))
void func_00308b30(void)
{
    int *cmd;
    DIntr();
    if (D_003660dc) {
        EIntr();
        return;
    }
    D_003660dc = 1;
    EIntr();
    func_003083d0();
    DIntr();
    D_01e37200.pkt = UC(D_01e35a00);
    D_01e37200.pktlen = 32;
    D_01e37200.u0c = 0;
    D_01e37200.u10 = 0;
    D_01e37200.rdata = UC(D_01e36200);
    D_01e37200.rdlen = 32;
    D_01e37200.client = UC(D_01e36a00);
    D_01e37200.cllen = 32;
    D_01e37200.u24 = 0;
    D_01e37200.pid = 1;
    func_003086b8(0x80000008, D_00308e30, &D_01e37200);
    func_003086b8(0x80000009, D_00309208, &D_01e37200);
    func_003086b8(0x8000000a, D_00309428, &D_01e37200);
    func_003086b8(0x8000000c, D_00308f40, &D_01e37200);
    EIntr();
    if (func_00305a30(0x80000002))
        return;
    cmd = (int *)(D_01e35a00 + 64);
    cmd[3] = 1;
    sceSifSendCmd(0x80000002, cmd, 16, 0, 0, 0);
    while (!func_00308200(0))
        ;
    func_00305a20(0x80000002, 1);
}

/* ---- 0x308cd0 */
extern void func_00308650(void);
void func_00308cd0(void) { func_00308650(); D_003660dc = 0; }

/* ---- 0x308cf8 */
typedef struct { int x0, x4, x8, xc; int flags; void *self; int id; int pad[9]; } Ent_w1898;
typedef struct { int seq; Ent_w1898 *ents; int n; } Pool_w1898;
Ent_w1898* func_00308cf8(Pool_w1898 *p)
{
    int i, n, v;
    Ent_w1898 *e;
    DIntr();
    n = p->n;
    e = p->ents;
    for (i = 0; i < n; i++, e++) {
        if (!(e->flags & 1)) {
            e->flags = (i << 16) | 5;
            { int id; v = p->seq + 1;
            p->seq = v;
            if (v == 1) {
                p->seq++;
                id = v;
            } else id = v;
            e->self = e;
            e->id = id; }
            EIntr();
            return e;
        }
    }
    EIntr();
    return 0;
}

/* ---- 0x308da0 */
typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int p18; } Sem;
void func_00308da0(Sem *s) { s->p18 = 0; s->flags &= ~1; }

/* ---- 0x308dc0 */
typedef struct { char d[64]; } Entry;
typedef struct { char pad0[0x14]; Entry *base; int n; char pad1[8]; int idx; } EntryRing;
Entry* func_00308dc0(EntryRing *q) { int i = q->idx % q->n; Entry *e = &q->base[i]; q->idx = i + 1; return e; }

/* ---- 0x308df0 */
typedef struct { char pad[0x1c]; char *tab; int n; } Tbl;
extern void* func_00308dc0_t(Tbl *, int) asm("func_00308dc0");
void* func_00308df0(Tbl *t, int i)
{
    if (i < 0 || i >= t->n) return func_00308dc0_t(t, i);
    return t->tab + i * 64;
}
