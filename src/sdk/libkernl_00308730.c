/* libkernl_00308730.c: Sony PS2 Runtime Library 3.0.0 libkernl: sifcmd (send), 0x308730-0x308934.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x308730 */
typedef struct { int a, b, c; } E;
extern E *D_01e357e4;
extern E *D_01e357ec;
void func_00308730(int x)
{
    if (x < 0) D_01e357e4[x & 0x7fffffff].a = 0;
    else D_01e357ec[x].a = 0;
}

/* ---- 0x308780 */
typedef struct { unsigned int src; unsigned int dest; int size; unsigned int attr; } Dma;
typedef struct { unsigned int size; unsigned int dest; int cid; unsigned int opt; } Hdr;
extern void func_00308a80(void *, int);
extern int func_003059f0(Dma *, int);
extern int func_003059e0(Dma *, int);
extern unsigned int D_01e357e0;
unsigned int func_00308780(int cid, int mode, Hdr *pkt, unsigned int pktsize, void *src, void *dest, int size)
{
    Dma dma[2];
    int count;
    if (pktsize - 16 > 96)
        return 0;
    count = 0;
    if (size > 0) {
        pkt->size = (pkt->size & 0xff) | (size << 8);
        dma[count].src = (unsigned int)src;
        dma[count].dest = (unsigned int)dest;
        dma[count].size = size;
        dma[count].attr = 0;
        pkt->dest = (unsigned int)dest;
        count++;
        if (mode & 4)
            func_00308a80(src, size);
    } else {
        pkt->size = pkt->size & 0xff;
        pkt->dest = 0;
    }
    dma[count].src = (unsigned int)pkt;
    dma[count].dest = D_01e357e0;
    dma[count].size = pktsize;
    pkt->cid = cid;
    *(unsigned char *)pkt = pktsize;
    dma[count].attr = 0x44;
    count++;
    func_00308a80(pkt, pktsize);
    if (mode & 1)
        return func_003059f0(dma, count);
    else
        return func_003059e0(dma, count);
}

/* ---- 0x3088b8 */
extern int func_00308780_i(int, int, int, int, int, int, int) asm("func_00308780");
int sceSifSendCmd(int a, int b, int c, int d, int e, int f)
{
    return func_00308780_i(a, 0, b, c, d, e, f);
}
int isceSifSendCmd(int a, int b, int c, int d, int e, int f)
{
    return func_00308780_i(a, 1, b, c, d, e, f);
}
