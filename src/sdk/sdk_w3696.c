/* Sony PS2 Runtime Library: libgraph. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef unsigned long u_long;
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u_long NLOOP:15;
    u_long EOP:1;
    u_long pad16:16;
    u_long id:14;
    u_long PRE:1;
    u_long PRIM:11;
    u_long FLG:2;
    u_long NREG:4;
    u_long REGS0:4;
    u_long REGS1:4;
    u_long REGS2:4;
    u_long REGS3:4;
    u_long REGS4:4;
    u_long REGS5:4;
    u_long REGS6:4;
    u_long REGS7:4;
    u_long REGS8:4;
    u_long REGS9:4;
    u_long REGS10:4;
    u_long REGS11:4;
    u_long REGS12:4;
    u_long REGS13:4;
    u_long REGS14:4;
    u_long REGS15:4;
} sceGifTag __attribute__((aligned(16)));
typedef struct {
    unsigned int vifcode[4];
    sceGifTag giftag;
    u_long bitbltbuf;
    long bitbltbufaddr;
    u_long trxpos;
    long trxposaddr;
    u_long trxreg;
    long trxregaddr;
    u_long finish;
    long finishaddr;
    u_long trxdir;
    long trxdiraddr;
} sceGsStoreImage;
extern void func_003080d0(const char *, ...);
extern int func_00305940(void);
extern int func_00305960(int);
extern u_long128 D_00363c70;
#define D1_CHCR ((volatile unsigned int *)0x10009000)
#define D1_MADR ((volatile unsigned int *)0x10009010)
#define D1_QWC  ((volatile unsigned int *)0x10009020)
#define GIF_CTRL ((volatile unsigned int *)0x10003000)
#define VIF1_STAT ((volatile unsigned int *)0x10003c00)
#define VIF1_FBRST ((volatile unsigned int *)0x10003c10)
#define VIF1_FIFO ((volatile u_long128 *)0x10005000)
#define GS_CSR ((volatile u_long *)0x12001000)
#define GS_BUSDIR ((volatile u_long *)0x12001040)
/* sceGsExecStoreImage: reads an image back from GS local memory into dstaddr over DMA Ch.1 (GS->MEM). */
int func_002f2d60(sceGsStoreImage *sp, u_long128 *dstaddr)
{
    int w, h, psm, hh;
    int bytes, qwc;
    int n8 = 0, nrem = 0, brem = 0, extra = 0;
    unsigned int i = 0;
    int imr, j;
    union { u_long128 q; unsigned char b[16]; } tmp;

    w = (int)(sp->trxreg & 0xfff);
    h = (int)((sp->trxreg >> 32) & 0xfff);
    psm = (int)((sp->bitbltbuf >> 24) & 0x3f);
    hh = 0;
    switch (psm) {
    case 0: case 48:
        bytes = w * h * 4;
        brem = bytes & 15;
        nrem = (bytes >> 4) & 7;
        n8 = (bytes >> 4) & ~7U;
        if (brem == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 3) & ~3;
            qwc = (w * hh) >> 2;
            extra = qwc - n8 - nrem - 1;
        }
        break;
    case 1: case 49:
        bytes = w * h * 3;
        brem = bytes & 15;
        nrem = (bytes >> 4) & 7;
        n8 = (bytes >> 4) & ~7U;
        if (brem == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 15) & ~15;
            qwc = (w * hh * 3) >> 4;
            extra = qwc - n8 - nrem - 1;
        }
        break;
    case 2: case 10: case 50: case 58:
        bytes = w * h * 2;
        brem = bytes & 15;
        nrem = (bytes >> 4) & 7;
        n8 = (bytes >> 4) & ~7U;
        if (brem == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & ~7U;
            qwc = (w * hh) >> 3;
            extra = qwc - n8 - nrem - 1;
        }
        break;
    case 19: case 27:
        bytes = w * h;
        brem = bytes & 15;
        nrem = (bytes >> 4) & 7;
        n8 = (bytes >> 4) & ~7U;
        if (brem == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & ~7U;
            qwc = (w * hh) >> 4;
            extra = qwc - n8 - nrem - 1;
        }
        break;
    case 20: case 36: case 44:
        bytes = (w * h) >> 1;
        brem = bytes & 15;
        nrem = (bytes >> 4) & 7;
        n8 = (bytes >> 4) & ~7U;
        if (brem == 0) {
            hh = h;
            extra = 0;
        } else {
            hh = (h + 7) & ~7U;
            qwc = (w * hh) >> 5;
            extra = qwc - n8 - nrem - 1;
        }
        break;
    }
    if (brem)
        *(u_long *)((unsigned int)&sp->trxreg | 0x20000000) = (u_long)(int)(sp->trxreg & 0xfff) | ((u_long)hh << 32);

    while (*D1_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err1;
    }
    imr = func_00305960(func_00305940() | 0x200);
    *GS_CSR = 2;
    *D1_QWC = 7;
    if (((unsigned int)sp & 0x70000000) == 0x70000000)
        *D1_MADR = ((unsigned int)sp & 0x0fffffff) | 0x80000000;
    else
        *D1_MADR = (unsigned int)sp & 0x0fffffff;
    *D1_CHCR = 0x101;
    while (*D1_CHCR & 0x100) {
        if (i++ > 0x1000000)
            goto err1;
    }
    while (!(*GS_CSR & 2)) {
        if (i++ > 0x1000000)
            goto err2;
    }
    *VIF1_STAT = 0x800000;
    *GS_BUSDIR = 1;
    if (n8) {
        *D1_QWC = n8;
        if (((unsigned int)dstaddr & 0x70000000) != 0x70000000)
            goto els;
        *D1_MADR = ((unsigned int)dstaddr & 0x0fffffff) | 0x80000000;
        goto done;
err1:
        func_003080d0("sceGsExecStoreImage: DMA Ch.1 does not terminate\r\n");
        return -1;
err2:
        func_003080d0("sceGsExecStoreImage: GS does not terminate\r\n");
        *VIF1_FIFO = D_00363c70;
        return -1;
err3:
        func_003080d0("sceGsExecStoreImage: DMA Ch.1 (GS->MEM) does not terminate\r\n");
        *GS_CSR = 0x100;
        *GS_BUSDIR = 0;
        *GIF_CTRL = 1;
        *VIF1_FBRST = 1;
        return -1;
err4:
        func_003080d0("sceGsExecStoreImage: Enough data does not reach VIF1\n");
        *GS_CSR = 0x100;
        *GS_BUSDIR = 0;
        *GIF_CTRL = 1;
        *VIF1_FBRST = 1;
        return -1;
els:
        *D1_MADR = (unsigned int)dstaddr & 0x0fffffff;
done:
        *D1_CHCR = 0x100;
        while (*D1_CHCR & 0x100) {
            if (i++ > 0x1000000)
                goto err3;
        }
    }
    for (j = 0; j < nrem; j++) {
        while (!(*VIF1_STAT & 0x1f000000)) {
            if (i++ > 0x1000000)
                goto err4;
        }
        dstaddr[n8 + j] = *VIF1_FIFO;
    }
    if (brem) {
        while (!(*VIF1_STAT & 0x1f000000)) {
            if (i++ > 0x1000000)
                goto err4;
        }
        tmp.q = *VIF1_FIFO;
        for (j = 0; j < brem; j++)
            ((unsigned char *)&dstaddr[n8 + nrem])[j] = tmp.b[j];
        for (j = 0; j < extra; j++) {
            while (!(*VIF1_STAT & 0x1f000000)) {
                if (i++ > 0x1000000)
                    goto err4;
            }
            tmp.q = *VIF1_FIFO;
        }
    }
    {
        /* Partial asm (no code emitted): a0 pinned and BUSDIR's address passed through an empty
         * volatile asm, so the last BUSDIR store is a plain store that reorg puts in the jal delay
         * slot like the original (a volatile store never fills a call slot in ee-gcc 2.9). */
        register int a0 asm("$4");
        u_long *busdir;
        *VIF1_STAT = 0;
        asm volatile("" : "=r"(busdir) : "0"(GS_BUSDIR));
        a0 = imr;
        *busdir = 0;
        func_00305960(a0);
    }
    {
        u_long128 v = D_00363c70;
        *GS_CSR = 2;
        *VIF1_FIFO = v;
    }
    return 0;
}
