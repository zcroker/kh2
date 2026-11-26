/* Sony PS2 Runtime Library 3.0.0: libgraph (libgraph.a), 0x2f2448-0x2f2d60: sceGsPutDispEnv .. sceGsExecLoadImage,
 * the part after the whole-asm sceGsSetDefDispEnv (0x2f20d0). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): compiled as one file. Its .rodata (the sceGsSyncPath messages and register
 * dump formats, the load/store image messages and the two psm jump tables) is at 0x376310. */
typedef unsigned long u_long;
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    u_long NLOOP:15; u_long EOP:1; u_long pad16:16; u_long id:14; u_long PRE:1; u_long PRIM:11; u_long FLG:2; u_long NREG:4;
    u_long REGS0:4; u_long REGS1:4; u_long REGS2:4; u_long REGS3:4; u_long REGS4:4; u_long REGS5:4; u_long REGS6:4; u_long REGS7:4;
    u_long REGS8:4; u_long REGS9:4; u_long REGS10:4; u_long REGS11:4; u_long REGS12:4; u_long REGS13:4; u_long REGS14:4; u_long REGS15:4;
} sceGifTag __attribute__((aligned(16)));

typedef struct {
    sceGifTag giftag0;
    u_long bitbltbuf; long bitbltbufaddr;
    u_long trxpos; long trxposaddr;
    u_long trxreg; long trxregaddr;
    u_long trxdir; long trxdiraddr;
    sceGifTag giftag1;
} sceGsLoadImage;

typedef struct {
    unsigned int vifcode[4];
    sceGifTag giftag;
    u_long bitbltbuf; long bitbltbufaddr;
    u_long trxpos; long trxposaddr;
    u_long trxreg; long trxregaddr;
    u_long finish; long finishaddr;
    u_long trxdir; long trxdiraddr;
} sceGsStoreImage;

typedef struct { u_long pmode, smode2, dispfb, display, bgcolor; } sceGsDispEnv;

/* sceGsGParam (0x2f1fa8 returns it): s0 = interlace, s6 = mode, f8 = vsync callback, fc = its handler id */
typedef struct { short s0; short s2; short s4; short mode; int f8; int fc; } sceGsGParam;
extern sceGsGParam *sceGsGetGParam(void);

extern int func_003080d0(const char *, ...);          /* scePrintf */
extern void func_00305ab0(void);
extern long func_00305b40(void);
extern int func_00305940(void);                       /* GsGetIMR */
extern int func_00305960(int);                        /* GsPutIMR */
extern void DisableIntc(int);
extern void EnableIntc(int);
extern void func_00305320(int, int);                  /* RemoveIntcHandler */
extern int func_00305300(int, int, int);              /* AddIntcHandler */
extern u_long128 D_00363c70;

#define GSR(x) (*(volatile u_long *)(x))
#define REG(a) (*(volatile unsigned int *)(a))

/* 0x2f2448 */
void sceGsPutDispEnv(sceGsDispEnv *e)
{
    if (sceGsGetGParam()->mode == 1) {
        GSR(0x12000000) = e->pmode;
        GSR(0x12000070) = e->dispfb;
        GSR(0x12000080) = e->display;
        GSR(0x120000c0) = e->bgcolor;
    } else {
        GSR(0x12000000) = e->pmode;
        GSR(0x12000020) = e->smode2;
        GSR(0x12000090) = e->dispfb;
        GSR(0x120000a0) = e->display;
        GSR(0x120000e0) = e->bgcolor;
    }
}

/* 0x2f2508 */
int sceGsSyncV(int x)
{
    sceGsGParam *p = sceGsGetGParam();
    long r;
    if (p->f8 == 0) {
        func_00305ab0();
        if (p->s0 != 1) return 1;
        return (*(volatile unsigned long *)0x12001000 >> 13) & 1;
    }
    r = (func_00305b40() >> 13) & 1;
    if (p->s0 != 1) return 1;
    return r;
}

/* sceGsSyncPath's messages in their retail .rodata order: the first timeout message, the register
 * dump formats, then the other four timeout messages (strings are 8-aligned under ee-gcc 2.9). */
#define STR8 static const char __attribute__((aligned(8)))
STR8 s_d1[] = "sceGsSyncPath: DMA Ch.1 does not terminate\r\n";
STR8 s_d1chcr[] = "\t<D1_CHCR=%08x:";
STR8 s_d1tadr[] = "D1_TADR=%08x:";
STR8 s_d1madr[] = "D1_MADR=%08x:";
STR8 s_d1qwc[] = "D1_QWC=%08x>\r\n";
STR8 s_d2chcr[] = "\t<D2_CHCR=%08x:";
STR8 s_d2tadr[] = "D2_TADR=%08x:";
STR8 s_d2madr[] = "D2_MADR=%08x:";
STR8 s_d2qwc[] = "D2_QWC=%08x>\r\n";
STR8 s_vif1stat[] = "\t<VIF1_STAT=%08x:";
STR8 s_gifstat[] = "GIF_STAT=%08x>\r\n";
STR8 s_d2[] = "sceGsSyncPath: DMA Ch.2 does not terminate\r\n";
STR8 s_vif1[] = "sceGsSyncPath: VIF1 does not terminate\r\n";
STR8 s_vu1[] = "sceGsSyncPath: VU1 does not terminate\r\n";
STR8 s_gif[] = "sceGsSyncPath: GIF does not terminate\r\n";

#define vu_stat() ({ asm volatile(".set noreorder\n\tcfc2 %0, $vi29\n\t.set reorder" : "=r"(stat)); stat; })

/* printf(f, *a) with the register read in the jal delay slot. The original has this at
 * every site, but ee-gcc 2.9 never fills a delay slot with a load, so jal/lw are written by
 * hand. The empty asm only ranks the address above the format string in the scheduler. */
#define PR(f, a) { const char *a0_ = (f); register unsigned int *v0_ asm("$2") = (unsigned int *)(a); asm("" : "+r"(v0_)); \
    asm volatile(".set noreorder\n\tjal func_003080d0\n\tlw $5,0(%0)\n\t.set reorder" : "+r"(v0_), "+r"(a0_) : : "$3","$5","$6","$7","$8","$9","$10","$11","$12","$13","$14","$15","$24","$25","$31","memory"); }

/* 0x2f25a0 */
int sceGsSyncPath(int mode, unsigned short timeout)
{
    unsigned int cnt = 0;
    int ret;
    int stat;
    register const char *msg asm("$4");

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
        msg = s_d1;
        goto pr;
    err2:
        msg = s_d2;
        goto pr;
    err3:
        msg = s_vif1;
        goto pr;
    err4:
        msg = s_vu1;
        goto pr;
    err5:
        msg = s_gif;
    pr:
        func_003080d0(msg);
        PR(s_d1chcr, 0x10009000);
        PR(s_d1tadr, 0x10009030);
        PR(s_d1madr, 0x10009010);
        PR(s_d1qwc, 0x10009020);
        PR(s_d2chcr, 0x1000a000);
        PR(s_d2tadr, 0x1000a030);
        PR(s_d2madr, 0x1000a010);
        PR(s_d2qwc, 0x1000a020);
        PR(s_vif1stat, 0x10003c00);
        PR(s_gifstat, 0x10003020);
        return -1;
    }
    ret = (REG(0x10009000) & 0x100); if (ret) ret = 1;
    if (REG(0x1000a000) & 0x100) ret |= 2;
    if (REG(0x10003c00) & 0x1f000003) ret |= 4;
    if (vu_stat() & 0x100) ret |= 8;
    if (REG(0x10003020) & 0xc00) ret |= 0x10;
    return ret;
}

/* 0x2f28b8 */
int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h)
{
    int qwc = 0;
    switch (dpsm) {
    case 0: case 48: qwc = (w * h) >> 2; break;
    case 1: case 49: qwc = (w * h * 3) >> 4; break;
    case 2: case 10: case 50: case 58: qwc = (w * h) >> 3; break;
    case 19: case 27: qwc = (w * h) >> 4; break;
    case 20: case 36: case 44: qwc = (w * h) >> 5; break;
    }
    if (qwc > 32767) {
        func_003080d0("sceGsSetDefLoadImage: too big size\r\n");
        return 0;
    }
    *(u_long128 *)&lp->giftag0 = 0;
    lp->giftag0.NLOOP = 4;
    lp->giftag0.NREG = 1;
    lp->giftag0.REGS0 = 0xe;
    lp->bitbltbuf = ((u_long)dbp << 32) | ((u_long)dbw << 48) | ((u_long)dpsm << 56);
    lp->bitbltbufaddr = 0x50;
    lp->trxpos = ((u_long)x << 32) | ((u_long)y << 48);
    lp->trxposaddr = 0x51;
    lp->trxreg = (u_long)w | ((u_long)h << 32);
    lp->trxregaddr = 0x52;
    lp->trxdir = 0;
    lp->trxdiraddr = 0x53;
    *(u_long128 *)&lp->giftag1 = 0;
    lp->giftag1.NLOOP = qwc;
    lp->giftag1.EOP = 1;
    lp->giftag1.FLG = 2;
    __asm__ __volatile__("sync.l");
    return sizeof(sceGsLoadImage) >> 4;
}

/* 0x2f2aa0 */
int sceGsSetDefStoreImage(sceGsStoreImage *sp, short sbp, short sbw, short spsm, short x, short y, short w, short h)
{
    sp->vifcode[0] = 0;
    sp->vifcode[1] = 0x06008000;
    sp->vifcode[2] = 0x13000000;
    sp->vifcode[3] = 0x50000006;
    *(u_long128 *)&sp->giftag = 0;
    sp->giftag.NLOOP = 5;
    sp->giftag.EOP = 1;
    sp->giftag.NREG = 1;
    sp->giftag.REGS0 = 0xe;
    sp->bitbltbuf = (u_long)sbp | ((u_long)sbw << 16) | ((u_long)spsm << 24);
    sp->bitbltbufaddr = 0x50;
    sp->trxpos = (u_long)x | ((u_long)y << 16);
    sp->trxposaddr = 0x51;
    sp->trxreg = (u_long)w | ((u_long)h << 32);
    sp->trxregaddr = 0x52;
    sp->finish = 0;
    sp->finishaddr = 0x61;
    sp->trxdir = 1;
    sp->trxdiraddr = 0x53;
    __asm__ __volatile__("sync.l"); /* sync.l: no C equivalent */
    return sizeof(sceGsStoreImage) >> 4;
}

#define D2_CHCR ((volatile unsigned int *)0x1000a000)
#define D2_MADR ((volatile unsigned int *)0x1000a010)
#define D2_QWC  ((volatile unsigned int *)0x1000a020)
/* 0x2f2be0 */
int sceGsExecLoadImage(sceGsLoadImage *lp, void *src)
{
    unsigned int i = 0;
    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err;
    }
    *D2_QWC = 6;
    if (((unsigned int)lp & 0x70000000) == 0x70000000)
        *D2_MADR = ((unsigned int)lp & 0x0fffffff) | 0x80000000;
    else
        *D2_MADR = (unsigned int)lp & 0x0fffffff;
    *D2_CHCR = 0x101;
    while (*D2_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err;
    }
    *D2_QWC = (int)(*(u_long *)&lp->giftag1 & 0x7fff);
    if (((unsigned int)src & 0x70000000) != 0x70000000)
        goto els;
    *D2_MADR = ((unsigned int)src & 0x0fffffff) | 0x80000000;
    goto done;
err:
    func_003080d0("sceGsExecLoadImage: DMA Ch.2 does not terminate\r\n");
    return -1;
els:
    *D2_MADR = (unsigned int)src & 0x0fffffff;
done:
    *D2_CHCR = 0x101;
    return 0;
}

