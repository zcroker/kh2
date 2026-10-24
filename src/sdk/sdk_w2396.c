/* Sony PS2 Runtime Library: libgraph sceGsSetDefLoadImage (002f28b8) and the libkernl kernel-mode ExecPS2 body (00366640). ee-gcc 2.9-991111 -O2 -G0. */
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
extern int func_003080d0(const char *, ...);
int func_002f28b8(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h)
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

typedef struct {
    int f0, f4, status, entry, f16, gp;
    short f24, f26;
    int f28, f32, f36, f40, f44, entry2, argc, args, f60, f64, f68, f72;
} KThread;
extern int *D_80074728;
extern int *D_8007472c;
extern int (*D_80074730)(int);
extern int (*D_80074734)(int, int);
extern int (*D_80074738)(void);
extern int (*D_8007473c)(void);
extern int (*D_80074740)(int);
extern int (*D_80074744)(int);
extern KThread *D_80074748;
extern void (*D_80074768)(void);
extern void (*D_8007476c)(void);
extern char *(*D_80074770)(char *, char *);
extern char *D_80074778;
extern void func_000743c8(void);
int func_00366640(int entry, int gp, int argc, char **argv)
{
    int i;
    int tid = *D_80074728;
    char *p;
    D_80074730(tid);
    D_80074734(tid, 0);
    for (i = 1; i < 256; i++) {
        int st = D_80074748[i].status;
        if (st == 0 || i == tid)
            continue;
        if (st == 16) {
            D_80074740(i);
        } else {
            D_80074744(i);
            D_80074740(i);
        }
    }
    D_8007473c();
    D_80074738();
    *D_8007472c = 0;
    func_000743c8();
    p = D_80074778;
    for (i = 0; i < argc; i++)
        p = D_80074770(p, argv[i]);
    D_80074748[tid].args = (int)D_80074778;
    D_80074748[tid].entry = entry;
    D_80074748[tid].entry2 = entry;
    D_80074748[tid].gp = gp;
    D_80074748[tid].argc = argc;
    D_80074748[tid].f24 = 0;
    D_80074748[tid].f36 = 0;
    D_80074748[tid].f28 = 0;
    D_80074748[tid].f32 = 0;
    D_80074748[tid].f26 = 0;
    D_8007476c();
    D_80074768();
    return entry;
}
