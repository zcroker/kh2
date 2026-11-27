/* Sony PS2 Runtime Library 3.0.0: libgraph (libgraph.a), 0x2f1e18-0x2f20c0: sceGsResetGraph, sceGsGetGParam,
 * sceGsResetPath and the ROM version check, the C run between the whole-asm functions (0x2f1b48-0x2f1e00) and the
 * syscall stub 0x2f20c0. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): a part of the object, compiled as one file. Its .rodata (the ROM version
 * path) is at 0x3762c8; the GParam block (0x363c40) and the VIF1 init quadwords (0x363c50) stay with the
 * object's .data, reached by name. */
typedef unsigned int u32;
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct { short inter; short omode; short ffmode; short version; int f8; int fc; } GP;
extern GP D_00363c40;
extern unsigned int D_00363c50[];

extern void SetGsCrt(short, short, short);
extern int RemoveIntcHandler(int, int);
extern int GsPutIMR(int);
extern int DisableIntc(int);
extern int sceOpen(const char *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(const char *);

GP *sceGsGetGParam(void);

#define CSR ((volatile unsigned long *)0x12001000)
void sceGsResetGraph(short mode, short inter, short omode, short ffmode)
{
    GP *p;
    switch (mode) {
    case 0:
        p = sceGsGetGParam();
        *CSR = 0x200;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        GsPutIMR(0xff00);
        p->ffmode = ffmode != 0;
        if (p->f8) {
            DisableIntc(2);
            RemoveIntcHandler(2, p->fc);
            p->f8 = 0;
            p->fc = 0;
        }
        SetGsCrt(inter & 1, omode & 0xff, ffmode & 1);
        break;
    case 1:
        *CSR = 0x100;
        break;
    case 5:
        p = sceGsGetGParam();
        p->ffmode = ffmode != 0;
        p->inter = inter;
        p->omode = omode;
        p->version = (*CSR >> 16) & 0xff;
        SetGsCrt(inter & 1, omode & 0xff, ffmode & 1);
        break;
    }
}

GP *sceGsGetGParam(void)
{
    return &D_00363c40;
}

/* sceGsResetPath: resets VIF1 (FBRST, ERR), sets the VU1 reset bit in vi28 (FBRST via cfc2/ctc2),
 * sends the two init quadwords to the VIF1 FIFO and resets GIF (GIF_CTRL = 1). */
void sceGsResetPath(void)
{
    *(volatile unsigned int *)0x10003c10 = 1;
    *(volatile unsigned int *)0x10003c20 = 2;
    __asm__ __volatile__(".set noreorder\n\tsync.l\n\tcfc2 %0,$vi28\n\tori %0,%0,0x0200\n\tctc2 %0,$vi28\n\tsync.p\n\t.set reorder" : : "r"(0));
    *(u_long128 *)0x10005000 = *(u_long128 *)&D_00363c50[0];
    *(volatile u_long128 *)0x10005000 = *(u_long128 *)&D_00363c50[4];
    *(volatile unsigned int *)0x10003000 = 1;
}

/* Reads the ROM version string and checks its date part against 20010608 (0x1315670). */
int func_002f2020(void)
{
    char buf[256];
    char *p;
    u32 i;
    int fd;
    fd = sceOpen("rom0:ROMVER", 1);
    if (fd < 0) return -1;
    for (i = 0, p = buf; i < 256; i++) {
        sceRead(fd, p, 1);
        if (*p++ == 0) break;
    }
    sceClose(fd);
    return atoi(&buf[i - 9]) > 0x1315670;
}
