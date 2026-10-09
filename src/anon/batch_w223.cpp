#include "../common/types.h"

extern "C" {

struct Nd223 { u8 p[0x38]; Nd223* next; Nd223* prev; };
struct Ls223 { Nd223* head; Nd223* tail; };
struct Ow223 { u32 f0; u32 f4; Ls223 l; u8 q[0x110 - 16]; Nd223* cur; };
extern void func_001022e8(Nd223*);

void func_001025f8(Ow223* o, Nd223* n) asm("_Z13func_001025f8Pv");
void func_001025f8(Ow223* o, Nd223* n) {
    if (n == o->cur) o->cur = n == 0 ? o->l.head : n->next;
    Ls223* l = &o->l;
    if (n->prev == 0) l->head = n->next; else n->prev->next = n->next;
    asm volatile("" ::: "memory");
    if (n->next == 0) l->tail = n->prev; else n->next->prev = n->prev;
    n->prev = 0; n->next = 0;
    func_001022e8(n);
}

// hand-written VU0 code: 5 planes x 8 points dot-product test (whole body in asm)
void func_00146cb0(void) __attribute__((noreturn));
void func_00146cb0(void) {
    asm volatile(
        ".set push\n\t.set noreorder\n\t.set noat\n\t"
        "mtc1 $0,$f2\n\t"
        "move $11,$0\n"
        "1:\n\t"
        "lwc1 $f1,12($4)\n\t"
        "move $13,$0\n\t"
        "move $12,$4\n\t"
        "move $15,$5\n"
        "2:\n\t"
        "lqc2 $vf1,0($15)\n\t"
        "lqc2 $vf2,0($12)\n\t"
        "vmul.xyz $vf1,$vf1,$vf2\n\t"
        "vaddy.x $vf1,$vf1,$vf1y\n\t"
        "vaddz.x $vf1,$vf1,$vf1z\n\t"
        "qmfc2 $8,$vf1\n\t"
        "mtc1 $8,$f0\n\t"
        "add.s $f0,$f0,$f1\n\t"
        "addiu $13,$13,1\n\t"
        "addiu $15,$15,16\n\t"
        "slti $14,$13,8\n\t"
        "c.le.s $f2,$f0\n\t"
        "bc1t 4f\n\t"
        "move $2,$0\n\t"
        "bnez $14,2b\n\t"
        "nop\n\t"
        "addiu $11,$11,1\n\t"
        "slti $15,$11,5\n\t"
        "bnez $15,1b\n\t"
        "addiu $4,$4,16\n\t"
        "li $2,1\n"
        "4:\n\t"
        "jr $31\n\t"
        "nop\n\t"
        ".set pop\n\t");
}

}
