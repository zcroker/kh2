/* Sony PS2 Runtime Library 3.0.0: libkernl. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int* func_00316d08(void);
int func_00305ce0(void) { *func_00316d08() = 5; return -1; }

typedef struct { int size; int count; int pad8; char *wp; char buf[1]; } Ring;
void func_00306928(Ring *r)
{
    r->count++;
    r->wp++;
    if (r->wp == &r->buf[r->size])
        r->wp = r->buf;
}

extern int D_003660d8;
extern int func_00308248(int, int, int);
extern int func_003059f0(int, int);
int func_00308398(int a, int b)
{
    if (D_003660d8)
        return func_00308248(a, b, 1);
    return func_003059f0(a, b);
}

typedef struct Node { char pad[60]; struct Node *next; } Node;
typedef struct { int pad0; int ok; int pad8; Node *free; } Pool;
extern void func_0030edb0(void);
extern void func_0030ee00(void);
Node* func_00309988(Pool *q)
{
    Node *p;
    func_0030edb0();
    p = q->free;
    if (p == 0)
        q->ok = 0;
    else {
        q->ok = 1;
        q->free = p->next;
    }
    func_0030ee00();
    return p;
}

