/* Sony PS2 Runtime Library 3.0.0: libdma (sceDmaPutEnv). */
typedef struct {
    unsigned char sts, std, mfd, rcyc;
    unsigned short express, notify;
    unsigned short sqwc, tqwc;
    void *rbadr;
    unsigned int rbsz;
} DmaEnv;

extern unsigned char D_00376810[];
extern unsigned char D_00376820[];
extern unsigned char D_00376830[];
extern DmaEnv D_01e2d960;

int func_002f36f0(DmaEnv *env)
{
    unsigned int ctrl = *(volatile unsigned int *)0x1000e000;
    unsigned int pcr = *(volatile unsigned int *)0x1000e020;
    unsigned int sqwc = *(volatile unsigned int *)0x1000e030;
    unsigned int rbor = *(volatile unsigned int *)0x1000e050;
    unsigned int rbsr = *(volatile unsigned int *)0x1000e040;

    if (env->sts >= 10) return -1;
    if (env->std >= 10) return -2;
    if (env->mfd >= 10) return -3;
    if (env->rcyc >= 7) return -4;
    ctrl = (ctrl & ~0x30) | (D_00376810[env->sts] << 4);
    ctrl = (ctrl & ~0xc0) | (D_00376820[env->std] << 6);
    ctrl = (ctrl & ~0x0c) | (D_00376830[env->mfd] << 2);
    if (env->rcyc) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (unsigned int)env->rbadr;
    rbsr = env->rbsz;
    *(volatile unsigned int *)0x1000e000 = ctrl;
    *(volatile unsigned int *)0x1000e020 = pcr;
    *(volatile unsigned int *)0x1000e030 = sqwc;
    *(volatile unsigned int *)0x1000e050 = rbor;
    *(volatile unsigned int *)0x1000e040 = rbsr;
    D_01e2d960 = *env;
    return 0;
}
