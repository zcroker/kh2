/* Sony PS2 Runtime Library 3.0.0: libkernl iopreset (IOP reset/reboot over SIF), 0x30ead0-0x30edb0:
 * reset request, alive/sync checks, reboot with rom0:UDNL. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv). .rodata 0x3783c0; the reset packet (0x1e38e80) stays retail data.
 * Each function keeps the declarations its old matched file used, with a _ADDR suffix and an asm
 * label to the real symbol, so their types do not clash. */
/* 0030ead0 func_0030ead0 (was src/sdk/sdk_w1331.c) */
typedef struct { unsigned int src; unsigned int dest; int size; unsigned int attr; } Dma_0ead0;
typedef struct { unsigned int psize:8; unsigned int dsize:24; unsigned int dest; unsigned int cid; unsigned int opt; } RHdr_0ead0;
typedef struct { RHdr_0ead0 hdr; int arglen; int mode; char arg[80]; } ResetPkt_0ead0;
extern ResetPkt_0ead0 D_01e38e80_0ead0 asm("D_01e38e80") __attribute__((aligned(64)));
extern void func_00308a80_0ead0(void *, int) asm("func_00308a80");
extern int func_003059e0_0ead0(Dma_0ead0 *, int) asm("func_003059e0");
extern void func_00310f38_0ead0(int, int) asm("func_00310f38");
extern void func_003058f0_0ead0(void) asm("func_003058f0");
extern unsigned int func_00305a30_0ead0(int) asm("func_00305a30");
extern void func_00305a20_0ead0(unsigned int, unsigned int) asm("func_00305a20");
int func_0030ead0(char *arg, int mode)
{
    Dma_0ead0 dma;
    unsigned int dest;
    int i;

    func_00310f38_0ead0(0, 0);
    func_00310f38_0ead0(1, 0);
    func_003058f0_0ead0();
    dest = func_00305a30_0ead0(0x80000000);
    D_01e38e80_0ead0.mode = mode;
    for (i = 0; arg[i]; i++)
        D_01e38e80_0ead0.arg[i] = arg[i];
    D_01e38e80_0ead0.hdr.dest = 0;
    D_01e38e80_0ead0.arglen = i;
    D_01e38e80_0ead0.hdr.cid = 0x80000003;
    D_01e38e80_0ead0.hdr.dsize = 0;
    D_01e38e80_0ead0.hdr.psize = 104;
    dma.src = (unsigned int)&D_01e38e80_0ead0;
    dma.dest = dest;
    dma.size = 104;
    dma.attr = 0x44;
    func_00308a80_0ead0(&D_01e38e80_0ead0, 104);
    func_00305a20_0ead0(4, 0x40000);
    if (func_003059e0_0ead0(&dma, 1) != 0) {
        func_00305a20_0ead0(4, 0x10000);
        func_00305a20_0ead0(4, 0x20000);
        func_00305a20_0ead0(0x80000002, 0);
        func_00305a20_0ead0(0x80000000, 0);
        return 1;
    }
    return 0;
}

/* 0030ec28 func_0030ec28 (was src/sdk/sdk_w508.c) */
extern int func_00305a30_0ec28(int) asm("func_00305a30");
int func_0030ec28(void) { int r = func_00305a30_0ec28(4); if (r & 0x10000) return 1; return 0; }

/* 0030ec50 func_0030ec50 (was src/sdk/sdk_w515.c) */
extern int func_00305a30_0ec50(int) asm("func_00305a30");
extern int func_00305aa0_0ec50(void) asm("func_00305aa0");
extern int func_00310f38_0ec50(int, int) asm("func_00310f38");
int func_0030ec50(void)
{
    if (!(func_00305a30_0ec50(4) & 0x40000)) return 0;
    func_00305aa0_0ec50();
    func_00310f38_0ec50(1, 1);
    func_00310f38_0ec50(0, 1);
    return 1;
}

/* 0030eca0 func_0030eca0 (was src/sdk/sdk_w1330.c) */
extern void func_003080d0_0eca0(const char *, ...) asm("func_003080d0");
extern void func_00308b30_0eca0(int) asm("func_00308b30");
extern void func_00308cd0_0eca0(void) asm("func_00308cd0");
extern int func_0030ead0_0eca0(char *, int) asm("func_0030ead0");
int func_0030eca0(char *img)
{
    char param[80];
    char *s = "rom0:UDNL ";
    char *d;
    char *p;
    p = img;
    while (*p) p++;
    if ((unsigned int)(p + 11 - img) > 80) {
        func_003080d0_0eca0("too long parameter '%s'\n", img);
        return 0;
    }
    func_00308b30_0eca0(0);
    func_00308cd0_0eca0();
    d = param;
    while (*s) *d++ = *s++;
    while (*img) *d++ = *img++;
    *d = 0;
    return func_0030ead0_0eca0(param, 0);
}
