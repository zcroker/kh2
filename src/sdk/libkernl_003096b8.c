/* libkernl_003096b8.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifrpc (server side), 0x3096b8-0x30978c.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int DIntr(void);
extern int EIntr(void);

/* ---- 0x3096b8 */
typedef struct { int p0, p4, p8, pc; unsigned int flags; int p14; int id; } Sem2;
typedef struct { Sem2 *s; int id; } Ref;
int func_003096b8(Ref *r)
{
    Sem2 *s = r->s;
    if (s == 0 || r->id != s->id || !(s->flags & 1)) return 0;
    return 1;
}

/* ---- 0x3096f8 */
typedef struct L { int f0, f4, f8, fc, f10; struct L *next; } L;
typedef struct { char pad[0x28]; L *head; } LH;
extern LH D_01e37200_l asm("D_01e37200");
void func_003096f8(L *a, int b)
{
    L *p;
    DIntr();
    a->f0 = b; a->f4 = 0; a->f8 = 0; a->fc = 0; a->f10 = 0; a->next = 0;
    if (D_01e37200_l.head == 0) {
        D_01e37200_l.head = a;
    } else {
        p = D_01e37200_l.head;
        while (p->next) p = p->next;
        p->next = a;
    }
    EIntr();
}

