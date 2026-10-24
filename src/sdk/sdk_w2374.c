/* Sony PS2 Runtime Library: libkernl kernel-patch helper. ee-gcc 2.9-991111 -O2 -G0. */
/* 64-bit kernel config word at 0x80074700 (bitfields). */
typedef struct {
    unsigned long f0 : 6;
    unsigned long f6 : 3;
    unsigned long f9 : 31;
    unsigned long f40 : 1;
    unsigned long f41 : 1;
    unsigned long f42 : 2;
    unsigned long f44 : 4;
    unsigned long f48 : 16;
} KCfg;
extern KCfg D_80074700;
/* 00366390: copy the 38-byte block the IOP publishes at 0xbc0003c0 (+15) into the kernel config,
 * then clear fields 40/42/44 when field 6 is zero. */
void func_00366390(void)
{
    unsigned char *dst;
    int i;
    unsigned char *p = *(unsigned char **)0xbc0003c0;
    if (p) {
        p += 0xbc000000;
        p += 15;
        dst = (unsigned char *)&D_80074700;
        for (i = 0; i < 38; i++)
            dst[i] = p[i];
    }
    if (((int)(*(unsigned long *)&D_80074700 >> 6) & 7) == 0) {
        D_80074700.f40 = 0;
        D_80074700.f42 = 0;
        D_80074700.f44 = 0;
    }
}
