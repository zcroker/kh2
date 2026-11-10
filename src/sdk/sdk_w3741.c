/* Sony PS2 Runtime Library: libkernl alarm timer (T2) reprogramming. ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned long u_long;
typedef struct Al { struct Al *next; int pad[3]; u_long a; u_long b; u_long c; } Al;
typedef struct { int pad[6]; Al *head; int x1c; } AG;
extern AG D_00367118;
extern void func_0030f6a0(int);
extern void func_0030f6b0(int);

void func_0030fa10(u_long now)
{
    AG *g = &D_00367118;
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

/* 002f25a0 sceGsSyncPath (libgraph). */
extern void func_003080d0(const char *, ...);
extern char D_00376310[], D_00376340[], D_00376350[], D_00376360[], D_00376370[], D_00376380[];
extern char D_00376390[], D_003763a0[], D_003763b0[], D_003763c0[], D_003763d8[];
extern char D_003763f0[], D_00376420[], D_00376450[], D_00376478[];

#define REG(a) (*(volatile unsigned int *)(a))
#define vu_stat() ({ asm volatile(".set noreorder\n\tcfc2 %0, $vi29\n\t.set reorder" : "=r"(stat)); stat; })

/* printf(f, *a) with the volatile register read in the jal delay slot. The original has this at
 * every site, but ee-gcc 2.9 never fills a delay slot with a volatile load, so jal/lw are written by
 * hand. The empty asm only ranks the address above the format string in the scheduler. */
#define PR(f, a) { register char *a0_ asm("$4") = (f); register unsigned int *v0_ asm("$2") = (unsigned int *)(a); asm("" : "+r"(v0_)); \
    asm volatile(".set noreorder\n\tjal func_003080d0\n\tlw $5,0(%0)\n\t.set reorder" : "+r"(v0_), "+r"(a0_) : : "$3","$5","$6","$7","$8","$9","$10","$11","$12","$13","$14","$15","$24","$25","$31","memory"); }

int sceGsSyncPath(int mode, unsigned short timeout)
{
    unsigned int cnt = 0;
    int ret;
    int stat;
    register char *msg asm("$4");

    if (mode == 0) {
        while (REG(0x10009000) & 0x100)
            if (cnt++ > 0x1000000) goto err1;
        while (REG(0x1000a000) & 0x100)
            if (cnt++ > 0x1000000) goto err2;
        while (REG(0x10003c00) & 0x1f000003)
            if (cnt++ > 0x1000000) goto err3;
        asm volatile(".set noreorder\n\tcfc2 %0, $vi29\n\t.set reorder" : "=r"(stat));
        while (stat & 0x100) {
            if (cnt++ > 0x1000000) goto err4;
            asm volatile(".set noreorder\n\tcfc2 %0, $vi29\n\t.set reorder" : "=r"(stat));
        }
        while (REG(0x10003020) & 0xc00)
            if (cnt++ > 0x1000000) goto err5;
        return 0;
    err1:
        msg = D_00376310;
        goto pr;
    err2:
        msg = D_003763f0;
        goto pr;
    err3:
        msg = D_00376420;
        goto pr;
    err4:
        msg = D_00376450;
        goto pr;
    err5:
        msg = D_00376478;
    pr:
        func_003080d0(msg);
        PR(D_00376340, 0x10009000);
        PR(D_00376350, 0x10009030);
        PR(D_00376360, 0x10009010);
        PR(D_00376370, 0x10009020);
        PR(D_00376380, 0x1000a000);
        PR(D_00376390, 0x1000a030);
        PR(D_003763a0, 0x1000a010);
        PR(D_003763b0, 0x1000a020);
        PR(D_003763c0, 0x10003c00);
        PR(D_003763d8, 0x10003020);
        return -1;
    }
    ret = (REG(0x10009000) & 0x100); if (ret) ret = 1;
    if (REG(0x1000a000) & 0x100) ret |= 2;
    if (REG(0x10003c00) & 0x1f000003) ret |= 4;
    if (vu_stat() & 0x100) ret |= 8;
    if (REG(0x10003020) & 0xc00) ret |= 0x10;
    return ret;
}
