/* libkernl (Sony PS2 Runtime Library 3.0.0): pooled entry alloc */
typedef struct { int x0, x4, x8, xc; int flags; void *self; int id; int pad[9]; } Ent_w1898;
typedef struct { int seq; Ent_w1898 *ents; int n; } Pool_w1898;
extern int func_0030edb0(void);
extern int func_0030ee00(void);

Ent_w1898* func_00308cf8(Pool_w1898 *p)
{
    int i, n, v;
    Ent_w1898 *e;
    func_0030edb0();
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
            func_0030ee00();
            return e;
        }
    }
    func_0030ee00();
    return 0;
}
