/* libmc (Sony PS2 Runtime Library 3.0.0) */
struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; };
struct CD { int pad[9]; int serve; int rest[26]; };
extern int func_00305620(struct SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern int func_003080d0(const char *, ...);
extern void func_00308b30(int);
extern int func_003092d8(struct CD *, unsigned int, int);
extern int func_003094b8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern void func_002fc378(int, int, int);
extern int D_0036594c;
extern int D_00365950;
extern struct CD D_01e33480;
extern int D_01e33500[];
extern int D_01e34a40[];
int func_002fb928(void)
{
    struct SemaParam sp;
    int i, j, r;
    i = 0;
    if (D_0036594c < 0) {
        sp.initCount = 1;
        sp.maxCount = 1;
        sp.option = (unsigned int)"sceMc_sema_regs";
        D_0036594c = func_00305620(&sp);
        if (D_0036594c == -1)
            return -101;
        sp.maxCount = 1;
        sp.initCount = 0;
        sp.option = (unsigned int)"sceMc_sema_timer";
        r = func_00305620(&sp);
        D_00365950 = r;
        if (r == -1) {
            func_00305630(D_0036594c);
            D_0036594c = r;
            return -101;
        }
    }
    func_002fc378(0, 0, 0);
    func_00305660(D_0036594c);
    func_00308b30(0);
    for (;;) {
        if (func_003092d8(&D_01e33480, 0x80000400, 0) < 0) {
            func_003080d0("bind error libmc \n");
            while (1)
                ;
        }
        if (D_01e33480.serve != 0)
            break;
        for (j = 0; j < 0x100000; j++)
            ;
        i++;
        if (i >= 512) {
            func_003080d0("bind error libmc \n");
            return -91;
        }
    }
    r = func_003094b8(&D_01e33480, 254, 0, D_01e33500, 48, D_01e34a40, 12, 0, 0);
    func_00305640(D_0036594c);
    if (r < 0) {
        D_01e33480.serve = 0;
        return -91;
    }
    if (D_01e34a40[1] < 522) {
        func_003080d0("libmc: too old release of mcserv.irx\n");
        D_01e33480.serve = 0;
        return -120;
    }
    if (D_01e34a40[2] < 526) {
        func_003080d0("libmc: too old release of mcman.irx\n");
        D_01e33480.serve = 0;
        return -121;
    }
    return D_01e34a40[0];
}
