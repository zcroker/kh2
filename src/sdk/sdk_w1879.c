/* Sony PS2 Runtime Library 3.0.0: libgraph (sceGsSetDefStoreImage). Built with ee-gcc 2.9-991111 -O2 -G0. */
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
int func_002f2aa0(sceGsStoreImage *sp, short sbp, short sbw, short spsm, short x, short y, short w, short h)
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
